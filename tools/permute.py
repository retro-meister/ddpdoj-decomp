import argparse
import io
from pathlib import Path
import shlex
import shutil
import subprocess
import sys
import tarfile
import urllib.request

from common import BASEROM, ROOT, TARGETS, TOOLCHAINS, TOOLS
from common import compiler_path, require_local, run, target_compiler, verify, verify_compiler
from diff import collect_provide_symbols, function_object, resolve_range
from split import load_symbols, scan_asm_functions, split, target_layout, target_units

PERMUTER_COMMIT = "860b6d95b5350c2677c89b0c195c7bf3bb6bad0b"
PERMUTER_URL = f"https://github.com/simonlindholm/decomp-permuter/archive/{PERMUTER_COMMIT}.tar.gz"


def install_permuter():
    dest = TOOLS / "permuter" / PERMUTER_COMMIT[:12]
    script = dest / "permuter.py"
    if script.is_file():
        return script
    with urllib.request.urlopen(PERMUTER_URL, timeout=60) as resp:
        archive = resp.read()
    dest.parent.mkdir(parents=True, exist_ok=True)
    tmp = dest.with_name(dest.name + ".tmp")
    if tmp.exists():
        shutil.rmtree(tmp)
    tmp.mkdir(parents=True)
    with tarfile.open(fileobj=io.BytesIO(archive), mode="r:gz") as tf:
        prefix = f"decomp-permuter-{PERMUTER_COMMIT}/"
        for member in tf.getmembers():
            if not member.name.startswith(prefix):
                continue
            rel = member.name[len(prefix):]
            if not rel:
                continue
            target = tmp / rel
            if member.isdir():
                target.mkdir(parents=True, exist_ok=True)
            elif member.isfile():
                target.parent.mkdir(parents=True, exist_ok=True)
                target.write_bytes(tf.extractfile(member).read())
    tmp.replace(dest)
    return script


def fast_runner(local, override=None):
    if override:
        return [override]
    if sys.platform == "win32":
        return []
    wibo_cfg = TOOLCHAINS["wibo"]
    if sys.platform == "darwin":
        wibo_mac = TOOLS / "wibo" / wibo_cfg["version"] / wibo_cfg["darwin"][0]
        if wibo_mac.is_file():
            return [str(wibo_mac)]
    runner = local.get("runner")
    if not runner:
        return []
    return [runner] if isinstance(runner, str) else list(runner)


def inline_local_headers(source_text):
    out = []
    seen = set()

    def expand(text, is_header=False):
        lines = text.splitlines()
        if is_header and len(lines) >= 3 and lines[0].strip().startswith("#ifndef ") and lines[1].strip().startswith("#define ") and lines[-1].strip().startswith("#endif"):
            lines = lines[2:-1]
        for line in lines:
            stripped = line.strip()
            if stripped.startswith('#include "') and stripped.endswith('"'):
                header = stripped[10:-1]
                path = ROOT / "include" / header
                if path.is_file():
                    if header not in seen:
                        seen.add(header)
                        expand(path.read_text(encoding="utf-8"), is_header=True)
                    continue
            out.append(line)

    expand(source_text)
    return "\n".join(out) + "\n"


def run_permuter(target_name, func_name, source_path, threads=4, timeout=60, runner_override=None):
    local = require_local()
    binutils = local["binutils"]
    version = target_compiler(target_name, local)
    verify_compiler(version)
    permuter_py = install_permuter()

    split_folder = split(target_name)
    units = target_units(target_name)
    symbols = load_symbols(target_name)
    asm_functions = scan_asm_functions(split_folder / "asm")

    ns = argparse.Namespace(
        target=target_name, function=func_name,
        address=None, size=None, source=Path(source_path),
    )
    address, size, resolved_source = resolve_range(ns, units, symbols, asm_functions)

    original = verify((BASEROM / target_name).read_bytes(), TARGETS[target_name]["sha256"], target_name)
    file_address, _, _ = target_layout(target_name)
    retail = original[address - file_address : address - file_address + size]

    work = ROOT / "build" / "permute" / target_name / func_name
    if work.exists():
        shutil.rmtree(work)
    work.mkdir(parents=True, exist_ok=True)

    (work / "retail.bin").write_bytes(retail)
    function_object(work, binutils, "retail", func_name)
    (work / "retail.o").replace(work / "target.o")

    base_code = inline_local_headers(Path(resolved_source).read_text(encoding="utf-8"))
    (work / "base.c").write_text(base_code, encoding="utf-8")

    provided = collect_provide_symbols(target_name, split_folder, asm_functions)
    gp = provided.pop("_gp")
    defs = [f"_gp = {gp:#x};", *(f"PROVIDE({name} = {addr:#x});" for name, addr in provided.items())]
    layout = [
        *defs,
        "SECTIONS {",
        f"  .text {address:#x} : SUBALIGN(1) {{ *(.text) }}",
        "  .rodata : { *(.rodata*) }",
        "  .data : { *(.data*) }",
        "  .sdata : { *(.sdata*) }",
        "  .bss : { *(.sbss*) *(.bss*) }",
        "  /DISCARD/ : { *(*) }",
        "}",
    ]
    (work / "layout.ld").write_text("\n".join(layout) + "\n", encoding="ascii")

    runner = fast_runner(local, runner_override)
    cc_cmd = shlex.join([*runner, str(compiler_path(version)), *TOOLCHAINS["compiler_flags"]])
    ld_bin = shlex.quote(binutils["ld"])
    objcopy_bin = shlex.quote(binutils["objcopy"])
    as_bin = shlex.quote(binutils["as"])
    compile_sh = work / "compile.sh"
    compile_sh.write_text(
        "#!/bin/sh\n"
        "set -e\n"
        'INPUT="$1"\n'
        'OUTPUT="$3"\n'
        'TMPDIR=$(mktemp -d)\n'
        'trap \'rm -rf "$TMPDIR"\' EXIT\n'
        f'cd {shlex.quote(str(ROOT))}\n'
        f'{cc_cmd} -o "$TMPDIR/raw.o" "$INPUT" >/dev/null 2>&1\n'
        f'{ld_bin} -EL -T {shlex.quote(str(work / "layout.ld"))} -o "$TMPDIR/linked.elf" "$TMPDIR/raw.o" >/dev/null 2>&1\n'
        f'{objcopy_bin} -O binary -j .text "$TMPDIR/linked.elf" "$TMPDIR/text.bin"\n'
        f'printf \'.text\\n.globl {func_name}\\n.type {func_name}, @function\\n{func_name}:\\n.incbin "%s"\\n.size {func_name}, . - {func_name}\\n\' "$TMPDIR/text.bin" > "$TMPDIR/wrap.s"\n'
        f'{as_bin} -EL -march=r5900 -mabi=eabi -no-pad-sections -o "$OUTPUT" "$TMPDIR/wrap.s"\n',
        encoding="utf-8",
    )
    compile_sh.chmod(0o755)
    (work / "settings.toml").write_text(
        f'func_name = "{func_name}"\ncompiler_type = "mwcc"\n',
        encoding="utf-8",
    )

    objdump_dir = str(Path(binutils["objdump"]).parent)
    env_prefix = f"{objdump_dir}:{shutil.which('sh') and ''}"
    cmd = [
        "uvx", "--with", "pycparser", "--with", "toml",
        "python", str(permuter_py), str(work),
        "-j", str(threads), "--stop-on-zero",
    ]
    env = dict(**__import__("os").environ)
    env["PATH"] = objdump_dir + __import__("os").pathsep + env.get("PATH", "")
    # Provide mips-linux-gnu-objdump symlink alias if permuter looks for it
    alias_dir = work / "bin"
    alias_dir.mkdir(exist_ok=True)
    for alias in ("mips-linux-gnu-objdump", "mipsel-linux-gnu-objdump", "mips-elf-objdump"):
        link = alias_dir / alias
        if not link.exists():
            link.symlink_to(binutils["objdump"])
    env["PATH"] = str(alias_dir) + __import__("os").pathsep + env["PATH"]

    try:
        subprocess.run(cmd, cwd=ROOT, env=env, timeout=timeout)
    except subprocess.TimeoutExpired:
        pass

    winners = sorted(work.glob("output-0-*/source.c"))
    if winners:
        print(f"PERMUTER MATCH: {winners[0].relative_to(ROOT)}")
        return winners[0]
    print(f"Permuter finished without score-0 match ({work.relative_to(ROOT)})")
    return None


def main():
    parser = argparse.ArgumentParser(description="Run bounded decomp-permuter search on a close C draft.")
    parser.add_argument("target", choices=TARGETS)
    parser.add_argument("function")
    parser.add_argument("--source", type=Path, required=True)
    parser.add_argument("-j", "--threads", type=int, default=4)
    parser.add_argument("--timeout", type=int, default=60)
    parser.add_argument("--runner", help="override compiler runner for permuter")
    args = parser.parse_args()
    winner = run_permuter(args.target, args.function, args.source, args.threads, args.timeout, args.runner)
    if winner is None:
        raise SystemExit(1)


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError, subprocess.CalledProcessError) as error:
        raise SystemExit(f"Permute failed: {error}")
