import argparse
import difflib
import json
from pathlib import Path
import re
import subprocess
import sys

from build import compile_source
from common import BASEROM, ROOT, TARGETS, TOOLCHAINS, TOOLS
from common import download, host_machine, require_local, resolve_tool, run, target_compiler, verify, verify_compiler
from objects import find_function
from split import load_symbols, scan_asm_functions, split, target_layout, target_units

ASSIGN_RE = re.compile(r"^\s*([A-Za-z_][A-Za-z0-9_]*)\s*=\s*(0x[0-9a-fA-F]+|\d+)\s*;")
DLABEL_RE = re.compile(r"^\s*(?:dlabel|glabel)\s+([A-Za-z_][A-Za-z0-9_]*)")
HEX_ADDR_SUFFIX_RE = re.compile(r"^(?:D|L|jtbl|str)_([0-9A-Fa-f]{8})$")


def objdiff_path(override):
    if override:
        return resolve_tool(override)
    machine = host_machine()
    if sys.platform == "linux" and machine == "arm64":
        machine = "aarch64"
    tools = TOOLCHAINS["objdiff"]
    host = f"{sys.platform}-{machine}"
    if host not in tools["hosts"]:
        raise ValueError("Pass --objdiff with a compatible objdiff-cli executable.")
    suffix, checksum = tools["hosts"][host]
    asset = f"objdiff-cli-{suffix}"
    version = tools["version"]
    path = TOOLS / "objdiff" / version / asset
    if not path.exists():
        url = f"https://github.com/encounter/objdiff/releases/download/v{version}/{asset}"
        data = download(url, checksum)
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(data)
        path.chmod(0o755)
    verify(path.read_bytes(), checksum, asset)
    return path


def function_object(folder, binutils, side, name):
    asm = (
        f'.text\n.globl {name}\n.type {name}, @function\n{name}:\n'
        f'.incbin "{side}.bin"\n.size {name}, . - {name}\n'
    )
    (folder / f"{side}.s").write_text(asm, encoding="ascii")
    run(binutils["as"], "-EL", "-march=r5900", "-mabi=eabi", "-no-pad-sections",
        "-o", f"{side}.o", f"{side}.s", cwd=folder)


def collect_provide_symbols(target_name, split_folder, asm_functions):
    provided = {}
    for sym, (addr, _) in load_symbols(target_name).items():
        provided[sym] = addr
    for sym, (addr, _) in asm_functions.items():
        provided.setdefault(sym, addr)
    data_dir = split_folder / "asm" / "data"
    if data_dir.is_dir():
        for asm in sorted(data_dir.glob("*.s")):
            for line in asm.read_text(encoding="utf-8").splitlines():
                match = DLABEL_RE.match(line)
                if match:
                    sym = match.group(1)
                    addr_match = HEX_ADDR_SUFFIX_RE.match(sym)
                    if addr_match:
                        provided.setdefault(sym, int(addr_match.group(1), 16))
    for filename in ("undefined_funcs.txt", "undefined_syms.txt"):
        path = split_folder / filename
        if not path.is_file():
            continue
        for line in path.read_text(encoding="utf-8").splitlines():
            match = ASSIGN_RE.match(line)
            if match:
                provided.setdefault(match.group(1), int(match.group(2), 0))
    return provided


def resolve_range(args, units, symbols, asm_functions):
    unit = next((entry for entry in units if entry["name"] == args.function), None)
    if args.address is not None or args.size is not None:
        if args.address is None or args.size is None or args.source is None:
            raise ValueError("Pass --address, --size, and --source together")
        return args.address, args.size, str(args.source.resolve())
    if unit is not None:
        source = str(args.source.resolve()) if args.source else unit["source"]
        return unit["address"], unit["size"], source
    if args.source is None:
        raise ValueError("For an unmatched function, pass --source (address and size are looked up from Splat)")
    sym = symbols.get(args.function)
    if sym is not None and sym[1] is not None:
        return sym[0], sym[1], str(args.source.resolve())
    if args.function in asm_functions:
        address, size = asm_functions[args.function]
        return address, size, str(args.source.resolve())
    raise ValueError(f"Could not find {args.function} in Splat disassembly; pass --address and --size")


def disassemble_bin(binutils, path, address):
    objdump = binutils.get("objdump")
    if not objdump:
        return []
    out = run(
        objdump, "-D", "-b", "binary", "-m", "mips:5900", "-EL",
        f"--adjust-vma={address:#x}", str(path),
        stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True,
    ).stdout
    lines = []
    for line in out.splitlines():
        if ":\t" in line:
            parts = line.split("\t", 2)
            if len(parts) == 3:
                off = int(parts[0].strip().rstrip(":"), 16) - address
                insn = re.sub(r"\s+", " ", parts[2].strip())
                lines.append((off, parts[1].strip(), insn))
    return lines


def read_match_percent(report_path):
    try:
        data = json.loads(report_path.read_text(encoding="utf-8"))
        for section in data.get("left", {}).get("sections", []):
            if section.get("name") == ".text" and "match_percent" in section:
                return float(section["match_percent"])
    except (OSError, ValueError, TypeError):
        pass
    return 0.0


def print_compact_diff(binutils, folder, address, retail_bytes, candidate_bytes, max_diffs=40):
    if retail_bytes == candidate_bytes:
        return
    r_insns = disassemble_bin(binutils, folder / "retail.bin", address)
    c_insns = disassemble_bin(binutils, folder / "candidate.bin", address)
    print(f"Size: retail={len(retail_bytes)}B ({len(r_insns)} insns)  candidate={len(candidate_bytes)}B ({len(c_insns)} insns)")
    r_keys = [x[2] for x in r_insns]
    c_keys = [x[2] for x in c_insns]
    matcher = difflib.SequenceMatcher(None, r_keys, c_keys, autojunk=False)
    shown = 0
    hidden = 0
    for tag, i1, i2, j1, j2 in matcher.get_opcodes():
        if tag == "equal":
            continue
        if i1 > 0 and shown < max_diffs:
            r = r_insns[i1 - 1]
            print(f"  ={r[0]:03x}  {r[2]}")
        if tag == "replace":
            span = max(i2 - i1, j2 - j1)
            for k in range(span):
                r = r_insns[i1 + k] if i1 + k < i2 else None
                c = c_insns[j1 + k] if j1 + k < j2 else None
                if shown < max_diffs:
                    off = r[0] if r else c[0]
                    r_txt = r[2] if r else "<missing>"
                    c_txt = c[2] if c else "<missing>"
                    print(f"  ~{off:03x}  retail: {r_txt:<28s} | cand: {c_txt}")
                    shown += 1
                else:
                    hidden += 1
        elif tag == "delete":
            for k in range(i1, i2):
                if shown < max_diffs:
                    r = r_insns[k]
                    print(f"  -{r[0]:03x}  retail: {r[2]:<28s} | cand: <missing>")
                    shown += 1
                else:
                    hidden += 1
        elif tag == "insert":
            for k in range(j1, j2):
                if shown < max_diffs:
                    c = c_insns[k]
                    print(f"  +{c[0]:03x}  retail: {'<extra>':<28s} | cand: {c[2]}")
                    shown += 1
                else:
                    hidden += 1
    if hidden:
        print(f"  ... ({hidden} more differing instructions)")


def diff(args):
    if not args.function.isascii() or not args.function.isidentifier():
        raise ValueError("Expected a C function name")
    target = TARGETS[args.target]
    split_folder = split(args.target)
    units = target_units(args.target)
    symbols = load_symbols(args.target)
    asm_functions = scan_asm_functions(split_folder / "asm")
    address, size, source = resolve_range(args, units, symbols, asm_functions)

    local = require_local()
    binutils = local["binutils"]
    version = target_compiler(args.target, local, args.compiler)
    verify_compiler(version)
    original = verify((BASEROM / args.target).read_bytes(), target["sha256"], args.target)
    file_address, load_offset, code_end = target_layout(args.target)
    if address % 4 or size <= 0 or size % 4 or not file_address + load_offset <= address < address + size <= code_end:
        raise ValueError("The comparison range must be aligned and inside the executable code")
    start = address - file_address
    retail = original[start:start + size]
    folder = ROOT / "build" / "diff" / args.target / args.function
    folder.mkdir(parents=True, exist_ok=True)
    (folder / "retail.bin").write_bytes(retail)
    compile_source(local, source, folder / "compiled.o", version)
    fn_offset, fn_size = find_function(folder / "compiled.o", args.function)
    provided = collect_provide_symbols(args.target, split_folder, asm_functions)
    gp = provided.pop("_gp")
    defs = [f"_gp = {gp:#x};", *(f"PROVIDE({name} = {addr:#x});" for name, addr in provided.items())]
    layout = [
        *defs,
        "SECTIONS {",
        f"  .text {address - fn_offset:#x} : SUBALIGN(1) {{ compiled.o(.text) }}",
        "  .rodata : { compiled.o(.rodata*) }",
        "  .data : { compiled.o(.data*) }",
        "  .sdata : { compiled.o(.sdata*) }",
        "  .bss : { compiled.o(.sbss*) compiled.o(.bss*) }",
        "  /DISCARD/ : { *(*) }",
        "}",
    ]
    (folder / "layout.ld").write_text("\n".join(layout) + "\n", encoding="ascii")
    run(binutils["ld"], "-EL", "-T", "layout.ld", "-o", "compiled.elf", "compiled.o", cwd=folder)
    run(binutils["objcopy"], "-O", "binary", "-j", ".text",
        "compiled.elf", "text.bin", cwd=folder)
    candidate = (folder / "text.bin").read_bytes()[fn_offset:fn_offset + fn_size]
    (folder / "candidate.bin").write_bytes(candidate)
    for side in ("retail", "candidate"):
        function_object(folder, binutils, side, args.function)
    command = [objdiff_path(args.objdiff), "diff", "-1", "retail.o", "-2", "candidate.o"]
    if not args.interactive:
        command += ["-o", "report.json", "--format", "json-pretty"]
    run(*command, args.function, cwd=folder)
    if not args.interactive:
        status = "MATCH" if retail == candidate else "DIFFERENT"
        pct = 100.0 if status == "MATCH" else read_match_percent(folder / "report.json")
        print(f"{status}  {args.target}:{args.function}  {pct:.2f}%  {folder.relative_to(ROOT) / 'report.json'}")
        if args.compact and status != "MATCH":
            print_compact_diff(binutils, folder, address, retail, candidate)


def main():
    parser = argparse.ArgumentParser(description="Compare a compiled PS2 function with the retail instructions.")
    parser.add_argument("target", choices=TARGETS)
    parser.add_argument("function")
    parser.add_argument("--address", type=lambda value: int(value, 0))
    parser.add_argument("--size", type=lambda value: int(value, 0))
    parser.add_argument("--source", type=Path, help="try an alternate C source file")
    parser.add_argument("--compiler", choices=TOOLCHAINS["compilers"], help="override the target compiler")
    parser.add_argument("--objdiff", help="use an existing objdiff-cli executable")
    parser.add_argument("--interactive", action="store_true")
    parser.add_argument("--compact", action="store_true", help="print compact side-by-side instruction diffs")
    diff(parser.parse_args())


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError, subprocess.CalledProcessError) as error:
        raise SystemExit(f"Diff failed: {error}")
