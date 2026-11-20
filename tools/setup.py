import argparse
import io
import json
from pathlib import Path
import shutil
import subprocess
import sys
import tarfile
import zipfile
from tempfile import TemporaryDirectory

from build import build, compile_source
from common import BASEROM, LOCAL, TARGETS, TOOLCHAINS, TOOLS
from common import compiler_path, download, host_machine, required_compilers, resolve_tool, run, verify, verify_compiler
from iso import executable_extents, read_at
from qemu_runner import install_guest

COMPILER_URL = "https://github.com/decompme/compilers/releases/download/compilers/"
WIBO_URL = "https://github.com/decompals/wibo/releases/download/"


def extract_originals(args):
    if args.originals is not None:
        originals = {name: (args.originals / name).read_bytes() for name in TARGETS}
    elif args.seven_zip:
        originals = {
            name: run(args.seven_zip, "x", "-so", args.iso.resolve(), name,
                      stdout=subprocess.PIPE).stdout
            for name in TARGETS
        }
    else:
        with args.iso.open("rb") as image:
            originals = {name: read_at(image, *extent)
                         for name, extent in executable_extents(image).items()}
    for name, contents in originals.items():
        verify(contents, TARGETS[name]["sha256"], name)
    BASEROM.mkdir(exist_ok=True)
    for name, contents in originals.items():
        (BASEROM / name).write_bytes(contents)


def install_compiler(version):
    record = TOOLCHAINS["compilers"][version]
    compiler = compiler_path(version)
    dll = compiler.with_name("LMGR326B.dll")
    if compiler.is_file() and dll.is_file():
        verify_compiler(version)
        return
    archive = download(COMPILER_URL + record["archive"], record["archive_sha256"])
    with tarfile.open(fileobj=io.BytesIO(archive), mode="r:*") as bundle:
        prefix = record["member_prefix"]
        binary = bundle.extractfile(prefix + compiler.name).read()
        dependency = bundle.extractfile(prefix + dll.name).read()
    verify(binary, record["sha256"], compiler.name)
    verify(dependency, TOOLCHAINS["compiler_dll_sha256"], dll.name)
    compiler.parent.mkdir(parents=True, exist_ok=True)
    compiler.write_bytes(binary)
    dll.write_bytes(dependency)


def install_runner(override):
    if override:
        return resolve_tool(override)
    if sys.platform == "win32":
        return None
    key = sys.platform
    if key == "linux" and host_machine() == "x86_64":
        key = "linux-x86_64"
    wibo = TOOLCHAINS["wibo"]
    if key not in wibo:
        raise ValueError("Pass --runner with a compatible local compiler wrapper on this host.")
    asset, checksum = wibo[key]
    path = TOOLS / "wibo" / wibo["version"] / asset
    if not path.exists():
        data = download(WIBO_URL + wibo["version"] + "/" + asset, checksum)
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(data)
        path.chmod(0o755)
    verify(path.read_bytes(), checksum, asset)
    return str(path)


def check_binutils(paths):
    with TemporaryDirectory() as directory:
        work = Path(directory)
        (work / "probe.s").write_text(".text\n.set noreorder\njr $ra\nnop\n", encoding="ascii")
        (work / "probe.ld").write_text(
            "SECTIONS { .text 0x100000 : { probe.o(.text) } /DISCARD/ : { *(*) } }", encoding="ascii"
        )
        run(paths["as"], "-EL", "-march=r5900", "-mabi=eabi", "-no-pad-sections",
            "-o", "probe.o", "probe.s", cwd=work, capture_output=True, text=True)
        run(paths["ld"], "-EL", "-T", "probe.ld", "-o", "probe.elf", "probe.o",
            cwd=work, capture_output=True, text=True)
        run(paths["objcopy"], "-O", "binary", "-j", ".text", "probe.elf", "probe.bin",
            cwd=work, capture_output=True, text=True)
        if (work / "probe.bin").read_bytes() != bytes.fromhex("0800e00300000000"):
            raise ValueError("R5900 binutils smoke test produced unexpected bytes")
    return paths


def bundled_binutils():
    machine = host_machine()
    if sys.platform == "win32" and machine == "arm64":
        machine = "x86_64"
    host = f"{sys.platform}-{machine}"
    config = TOOLCHAINS["binutils"]
    if host not in config["hosts"]:
        return None
    suffix, digest = config["hosts"][host]
    version = config["version"]
    asset = f"binutils-mips-ps2-decompals-{suffix}"
    folder = TOOLS / "binutils" / version / host
    extension = ".exe" if sys.platform == "win32" else ""
    paths = {name: folder / f"mips-ps2-decompals-{name}{extension}"
             for name in ("as", "ld", "objcopy", "objdump", "readelf")}
    if not all(path.is_file() for path in paths.values()):
        archive = download(
            f"https://github.com/decompals/binutils-mips-ps2-decompals/releases/download/{version}/{asset}",
            digest,
        )
        folder.mkdir(parents=True, exist_ok=True)
        stream = io.BytesIO(archive)
        bundle = zipfile.ZipFile(stream) if extension else tarfile.open(fileobj=stream, mode="r:gz")
        with bundle, TemporaryDirectory(dir=folder) as directory:
            work = Path(directory)
            for path in paths.values():
                data = bundle.read(path.name) if extension else bundle.extractfile(path.name).read()
                staged = work / path.name
                staged.write_bytes(data)
                staged.chmod(0o755)
                staged.replace(path)
    return {name: str(path) for name, path in paths.items()}


def find_binutils(prefix):
    failures = []
    if not prefix:
        try:
            paths = bundled_binutils()
            if paths:
                return check_binutils(paths)
        except (OSError, ValueError, subprocess.CalledProcessError) as error:
            failures.append(error)
    prefixes = [prefix] if prefix else [
        "mips64-elf-", "mips64r5900el-ps2-elf-", "mips-ps2-decompals-",
        "mipsel-none-elf-", "mipsel-linux-gnu-", "mips64el-linux-gnuabi64-",
    ]
    for candidate in prefixes:
        try:
            paths = {tool: resolve_tool(candidate + tool) for tool in ("as", "ld", "objcopy")}
        except ValueError:
            continue
        for extra in ("objdump", "readelf"):
            try:
                paths[extra] = resolve_tool(candidate + extra)
            except ValueError:
                pass
        try:
            return check_binutils(paths)
        except (OSError, ValueError, subprocess.CalledProcessError) as error:
            failures.append(error)
    details = ""
    if failures:
        error = failures[0]
        details = (getattr(error, "stderr", None) or str(error)).strip()
    if sys.platform == "darwin":
        details += " Apple Silicon packages may require Homebrew zstd."
    elif sys.platform == "linux":
        details += " The x86-64 package requires glibc 2.38 and libzstd.so.1."
    raise ValueError(f"Could not run R5900 binutils. Use --binutils-prefix to select compatible tools. {details}")


def main():
    parser = argparse.ArgumentParser(description="Extract verified inputs and configure a local compiler runner.")
    source = parser.add_mutually_exclusive_group(required=True)
    source.add_argument("--iso", type=Path, help="Japanese SLPS-25233 disc image")
    source.add_argument("--originals", type=Path, help="directory containing the three extracted ELFs")
    parser.add_argument("--seven-zip", help="path to 7z or 7zz")
    parser.add_argument("--compiler", choices=TOOLCHAINS["compilers"], help="override the target compiler")
    runners = parser.add_mutually_exclusive_group()
    runners.add_argument("--runner", help="wrapper executable that runs the original compiler")
    runners.add_argument("--qemu", action="store_true", help="run CodeWarrior in a local x86 QEMU guest")
    runners.add_argument("--wibo", action="store_true", help="use the host Wibo runner")
    parser.add_argument("--build", action="store_true", help="also run the full matching build")
    parser.add_argument("--binutils-prefix", help="GNU tool prefix, optionally including its directory")
    args = parser.parse_args()
    if args.wibo and sys.platform == "win32":
        parser.error("CodeWarrior runs directly on Windows. Omit --wibo.")
    binutils = find_binutils(args.binutils_prefix)
    extract_originals(args)
    compilers = [args.compiler] if args.compiler else required_compilers()
    for version in compilers:
        install_compiler(version)
    use_qemu = args.qemu or (
        not args.runner and not args.wibo and sys.platform in ("darwin", "linux")
        and host_machine() == "arm64"
        and shutil.which("qemu-system-x86_64")
    )
    runner = [sys.executable, str(install_guest())] if use_qemu else install_runner(args.runner)
    local = {"runner": runner, "binutils": binutils}
    if args.compiler:
        local["compiler"] = args.compiler
    if args.build:
        build(local)
    else:
        with TemporaryDirectory(prefix="setup-", dir=TOOLS) as directory:
            compile_source(local, "src/shared/rng_step.c", Path(directory) / "rng_step.o", compilers[0])
    pending = LOCAL.with_suffix(".tmp")
    pending.write_text(json.dumps(local, indent=2) + "\n", encoding="utf-8")
    pending.replace(LOCAL)
    if args.build:
        print("Setup and matching build complete.")
    else:
        print("Setup complete. Run python tools/build.py.")


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError, subprocess.CalledProcessError) as error:
        raise SystemExit(f"Setup failed: {error}")
