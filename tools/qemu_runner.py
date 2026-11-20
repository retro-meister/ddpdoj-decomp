import base64
import io
from pathlib import Path
import shlex
import shutil
import subprocess
import sys
import tarfile
from tempfile import TemporaryDirectory

from common import ROOT, TOOLS, TOOLCHAINS, download, resolve_tool, run, verify
from iso import find_extent, read_at, root_directory

GUEST = TOOLS / "qemu"
GUEST_CONFIG = TOOLCHAINS["qemu_guest"]
ALPINE = GUEST_CONFIG["base_url"]
ISO = GUEST_CONFIG["iso"]
ROOTFS = GUEST_CONFIG["rootfs"]
KERNEL_HASH = GUEST_CONFIG["kernel_sha256"]
RUNTIME = GUEST_CONFIG["runtime"]


def install_guest():
    resolve_tool("qemu-system-x86_64")
    resolve_tool("cpio")
    GUEST.mkdir(parents=True, exist_ok=True)
    with TemporaryDirectory(dir=GUEST) as temporary:
        work = Path(temporary)
        if not (GUEST / "vmlinuz").is_file():
            image = io.BytesIO(download(ALPINE + ISO[0], ISO[1]))
            extent = find_extent(image, root_directory(image), "BOOT/VMLINUZ_VIRT")
            kernel = read_at(image, *extent)
            verify(kernel, KERNEL_HASH, "Alpine guest kernel")
            path = work / "vmlinuz"
            path.write_bytes(kernel)
            path.replace(GUEST / "vmlinuz")
        if any(not (GUEST / name).is_file() for name in RUNTIME):
            archive = download(ALPINE + ROOTFS[0], ROOTFS[1])
            with tarfile.open(fileobj=io.BytesIO(archive), mode="r:gz") as rootfs:
                for name in RUNTIME:
                    target = GUEST / name
                    target.parent.mkdir(exist_ok=True)
                    path = work / target.name
                    path.write_bytes(verify(rootfs.extractfile("./" + name).read(), RUNTIME[name], name))
                    path.chmod(0o755)
                    path.replace(target)
        asset, checksum = TOOLCHAINS["wibo"]["linux-x86_64"]
        wibo = GUEST / "wibo"
        if not wibo.is_file():
            version = TOOLCHAINS["wibo"]["version"]
            path = work / "wibo"
            path.write_bytes(download(f"https://github.com/decompals/wibo/releases/download/{version}/{asset}", checksum))
            path.chmod(0o755)
            path.replace(wibo)
        verify(wibo.read_bytes(), checksum, asset)
        verify((GUEST / "vmlinuz").read_bytes(), KERNEL_HASH, "Alpine guest kernel")
        for name, expected in RUNTIME.items():
            verify((GUEST / name).read_bytes(), expected, name)
    return Path(__file__).resolve()


def stage_source(guest, source, copied_roots, draft_index):
    if source.is_relative_to(ROOT):
        name = source.relative_to(ROOT)
        path = guest / name
        if any(source.is_relative_to(root) for root in copied_roots):
            return name.as_posix()
    else:
        name = Path(f"draft_{draft_index}") / source.name
        path = guest / name
        path.parent.mkdir(parents=True, exist_ok=True)
        for header in source.parent.glob("*.h"):
            shutil.copy2(header, path.parent / header.name)
    path.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(source, path)
    return name.as_posix()


def compile_batch(jobs):
    if not jobs:
        return
    with TemporaryDirectory() as directory:
        work = Path(directory)
        fs = work / "root"
        guest = fs / "job"
        for name in ("job", "dev", "proc", "tmp", "bin", "lib", "cc"):
            (fs / name).mkdir(parents=True, exist_ok=True)
        for name in (*RUNTIME, "wibo"):
            shutil.copy2(GUEST / name, fs / name)

        copied_roots = []
        for name in ("src", "include"):
            if (ROOT / name).is_dir():
                shutil.copytree(ROOT / name, guest / name)
                copied_roots.append(ROOT / name)

        compiler_map = {}
        script_lines = [
            "#!/bin/busybox sh",
            "/bin/busybox mount -t proc proc /proc",
            "/bin/busybox mount -t devtmpfs devtmpfs /dev",
            "cd /job",
        ]
        for index, (compiler, flags, _output, source) in enumerate(jobs):
            compiler = Path(compiler).resolve()
            source = Path(source).resolve()
            if compiler not in compiler_map:
                cc_dir = fs / "cc" / f"c{len(compiler_map)}"
                cc_dir.mkdir(parents=True, exist_ok=True)
                for binary in (compiler.name, "LMGR326B.dll"):
                    shutil.copy2(compiler.parent / binary, cc_dir / binary)
                compiler_map[compiler] = f"/cc/{cc_dir.name}/{compiler.name}"
            source_name = stage_source(guest, source, copied_roots, index)
            obj_name = f"out_{index}.o"
            cmd = shlex.join(["/wibo", compiler_map[compiler], *flags, "-o", obj_name, source_name])
            script_lines.extend([
                f"if {cmd} && [ -s {obj_name} ]; then",
                f"  echo DDPDOJ_OBJ_BEGIN_{index}",
                f"  /bin/busybox base64 {obj_name}",
                f"  echo DDPDOJ_OBJ_END_{index}",
                "else",
                "  /bin/busybox poweroff -f",
                "fi",
            ])
        script_lines.append("/bin/busybox poweroff -f")

        init = fs / "init"
        init.write_text("\n".join(script_lines) + "\n", encoding="utf-8")
        init.chmod(0o755)
        initrd = work / "guest.cpio"
        members = sorted(path.relative_to(fs).as_posix() for path in fs.rglob("*"))
        with initrd.open("wb") as archive:
            run("cpio", "-o", "-0", "-H", "newc", cwd=fs, stdout=archive,
                stderr=subprocess.PIPE, input=("\0".join(members) + "\0").encode("utf-8"))
        timeout = max(90, 30 + 15 * len(jobs))
        guest_run = run(
            "qemu-system-x86_64", "-accel", "tcg", "-cpu", "max", "-m", "256",
            "-display", "none", "-serial", "stdio", "-monitor", "none", "-nic", "none",
            "-no-reboot", "-kernel", GUEST / "vmlinuz", "-initrd", initrd,
            "-append", "console=ttyS0 quiet panic=1 rdinit=/init",
            stdin=subprocess.DEVNULL, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, timeout=timeout,
        )
        raw = guest_run.stdout
        for index, (_compiler, _flags, output, source) in enumerate(jobs):
            begin_tag = f"DDPDOJ_OBJ_BEGIN_{index}".encode("ascii")
            end_tag = f"DDPDOJ_OBJ_END_{index}".encode("ascii")
            before, begin, rest = raw.partition(begin_tag)
            payload, end, _ = rest.partition(end_tag)
            if not (begin and end):
                raise ValueError(
                    f"Guest did not produce an object for {source}:\n"
                    + before.decode("utf-8", "replace")[-4000:]
                )
            output = Path(output)
            output.parent.mkdir(parents=True, exist_ok=True)
            output.write_bytes(base64.b64decode(b"".join(payload.split()), validate=True))


def compile_in_guest(compiler, flags, output, source):
    compile_batch([(compiler, flags, output, source)])


def main():
    compiler, *flags, output_flag, output, source = sys.argv[1:]
    if output_flag != "-o":
        raise ValueError("Expected compiler arguments ending in -o OUTPUT SOURCE")
    compile_in_guest(Path(compiler), flags, Path(output), Path(source).resolve())


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError, subprocess.SubprocessError) as error:
        raise SystemExit(f"QEMU compiler failed: {error}")
