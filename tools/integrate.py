import argparse
import json
from pathlib import Path
import re
import subprocess
import sys

from build import build, compile_source
from common import BASEROM, ROOT, TARGETS, nonmatching_dir, require_local, run, target_compiler, verify, verify_compiler
from diff import collect_provide_symbols
from objects import find_function
from split import load_splat_config, scan_asm_functions, split, splat_yaml_path, symbols_path, target_layout

SUBSEG_LINE_RE = re.compile(r"^(\s*-\s*\[)(0x[0-9a-fA-F]+|\d+)(,\s*([a-zA-Z0-9_]+),\s*([^\]]+))(\]\s*)$")
INLINE_ASM_RE = re.compile(r"\b(?:asm|__asm|__asm__)\s*(?:volatile\b|__volatile__\b)?\s*[\({]")


def verify_match(local, target_name, function_name, source_path, address, size):
    target = TARGETS[target_name]
    version = target_compiler(target_name, local)
    verify_compiler(version)
    split_folder = split(target_name)
    asm_functions = scan_asm_functions(split_folder / "asm")
    original = verify((BASEROM / target_name).read_bytes(), target["sha256"], target_name)
    file_address, load_offset, code_end = target_layout(target_name)
    if address % 4 or size <= 0 or size % 4 or not file_address + load_offset <= address < address + size <= code_end:
        raise ValueError(f"{target_name}: invalid range {address:#x}..{address + size:#x}")
    retail = original[address - file_address : address - file_address + size]

    folder = ROOT / "build" / "integrate" / target_name / function_name
    folder.mkdir(parents=True, exist_ok=True)
    obj = folder / "compiled.o"
    compile_source(local, str(source_path), obj, version)
    fn_offset, fn_size = find_function(obj, function_name)
    provided = collect_provide_symbols(target_name, split_folder, asm_functions)
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
    binutils = local["binutils"]
    run(binutils["ld"], "-EL", "-T", "layout.ld", "-o", "compiled.elf", "compiled.o", cwd=folder)
    run(binutils["objcopy"], "-O", "binary", "-j", ".text", "compiled.elf", "text.bin", cwd=folder)
    candidate = (folder / "text.bin").read_bytes()[fn_offset : fn_offset + fn_size]
    return retail == candidate


def patch_splat_yaml(target_name, address, size, stub):
    yaml_file = splat_yaml_path(target_name)
    original = (BASEROM / target_name).read_bytes()
    file_address, _, code_end = target_layout(target_name)
    offset = address - file_address
    end = offset + size
    code_end_off = code_end - file_address
    padded = (end + 15) & ~15
    if padded <= code_end_off and all(b == 0 for b in original[end:padded]):
        end = padded

    lines = yaml_file.read_text(encoding="utf-8").splitlines()
    subsegs = []
    for idx, line in enumerate(lines):
        m = SUBSEG_LINE_RE.match(line)
        if m:
            subsegs.append((idx, int(m.group(2), 0), m.group(4).strip(), m.group(5).strip(), m.group(1)))

    existing_names = {name for _, _, _, name, _ in subsegs}
    for i, (line_idx, seg_off, seg_type, seg_name, prefix) in enumerate(subsegs):
        next_off = subsegs[i + 1][1] if i + 1 < len(subsegs) else code_end_off
        if seg_type == "asm" and seg_off <= offset and end <= next_off:
            replacement = []
            if offset > seg_off:
                replacement.append(f"{prefix}{seg_off:#x}, asm, {seg_name}]")
            replacement.append(f"{prefix}{offset:#x}, c, {stub}]")
            if end < next_off:
                counter = 0
                new_name = f"game_{end:06x}"
                while new_name in existing_names:
                    counter += 1
                    new_name = f"game_{end:06x}_{counter}"
                replacement.append(f"{prefix}{end:#x}, asm, {new_name}]")
            new_lines = lines[:line_idx] + replacement + lines[line_idx + 1:]
            yaml_file.write_text("\n".join(new_lines) + "\n", encoding="utf-8")
            return
    raise ValueError(f"{target_name}: no asm subsegment contains {address:#x}..{address + size:#x}")


def append_symbol(target_name, sym_name, address, size):
    sym_file = symbols_path(target_name)
    text = sym_file.read_text(encoding="utf-8")
    addr_hex = f"{address:#x}"
    for line in text.splitlines():
        if re.match(rf"^\s*{re.escape(sym_name)}\s*=", line):
            return
        if re.search(rf"=\s*{re.escape(addr_hex)}\s*;", line, re.IGNORECASE):
            raise ValueError(f"{target_name}: address {addr_hex} already named in symbols.txt")
    if text and not text.endswith("\n"):
        text += "\n"
    text += f"{sym_name} = {addr_hex}; // type:func size:{size:#x}\n"
    sym_file.write_text(text, encoding="utf-8")


def find_paired_death(func_name):
    inv_path = ROOT / "build" / "inventory.json"
    if not inv_path.is_file():
        return None
    try:
        data = json.loads(inv_path.read_text(encoding="utf-8"))
        for entry in data.get("targets", {}).get("SLPS_252.33", []):
            if entry["name"] == func_name and "paired_death" in entry:
                return entry["paired_death"]
    except (OSError, ValueError):
        return None
    return None


def integrate(target_name, func_name, source_path, out_name=None, subdir=None, pair_death=True):
    local = require_local()
    source_path = Path(source_path).resolve()
    split_folder = split(target_name)
    asm_funcs = scan_asm_functions(split_folder / "asm")
    if func_name not in asm_funcs:
        raise ValueError(f"{target_name}: {func_name} not found in Splat asm")
    address, size = asm_funcs[func_name]

    code = source_path.read_text(encoding="utf-8")
    if INLINE_ASM_RE.search(code):
        raise ValueError(f"{source_path}: inline assembly (asm/__asm) is forbidden; write pure C")
    c_name = out_name or func_name
    if c_name != func_name:
        code = re.sub(rf"\b{re.escape(func_name)}\b", c_name, code)

    targets_to_update = [(target_name, address, size)]
    if target_name == "SLPS_252.33" and pair_death:
        paired = find_paired_death(func_name)
        if paired:
            d_folder = split("DEATH.ELF")
            d_funcs = scan_asm_functions(d_folder / "asm")
            d_info = d_funcs.get(paired["name"])
            if d_info and d_info[1] == size:
                targets_to_update.append(("DEATH.ELF", d_info[0], d_info[1]))

    if subdir is None:
        if len(targets_to_update) > 1:
            subdir = "shared"
        elif target_name == "GALLERY.ELF":
            subdir = "gallery"
        elif target_name == "DEATH.ELF":
            subdir = "death"
        else:
            subdir = "main"

    dest_file = ROOT / "src" / subdir / f"{c_name}.c"
    if dest_file.exists():
        raise ValueError(f"Destination already exists: {dest_file.relative_to(ROOT)}")
    stub = f"{subdir}/{c_name}"

    staging = ROOT / "build" / "integrate" / f"{c_name}.c"
    staging.parent.mkdir(parents=True, exist_ok=True)
    staging.write_text(code, encoding="utf-8")

    verified_targets = []
    for t_name, t_addr, t_size in targets_to_update:
        if verify_match(local, t_name, c_name, staging, t_addr, t_size):
            verified_targets.append((t_name, t_addr, t_size))
        elif t_name == target_name:
            raise ValueError(f"{t_name}:{c_name} does not match retail bytes; aborting integration")

    backups = {}
    for t_name, _, _ in verified_targets:
        for path in (splat_yaml_path(t_name), symbols_path(t_name)):
            backups[path] = path.read_text(encoding="utf-8")

    try:
        dest_file.parent.mkdir(parents=True, exist_ok=True)
        dest_file.write_text(code, encoding="utf-8")
        for t_name, t_addr, t_size in verified_targets:
            append_symbol(t_name, c_name, t_addr, t_size)
            patch_splat_yaml(t_name, t_addr, t_size, stub)
        for t_name, _, _ in verified_targets:
            build(local, target=t_name)
    except Exception:
        dest_file.unlink(missing_ok=True)
        for path, old_text in backups.items():
            path.write_text(old_text, encoding="utf-8")
        raise

    for t_name, _, _ in verified_targets:
        (nonmatching_dir(t_name, shared=False) / f"{func_name}.c").unlink(missing_ok=True)
        (nonmatching_dir(t_name, shared=True) / f"{func_name}.c").unlink(missing_ok=True)
        (ROOT / "build" / "wip" / t_name / f"{func_name}.best.c").unlink(missing_ok=True)
    names = ", ".join(t for t, _, _ in verified_targets)
    print(f"INTEGRATED  {dest_file.relative_to(ROOT)}  ({names})")
    return dest_file, [t for t, _, _ in verified_targets]


def main():
    parser = argparse.ArgumentParser(description="Verify and integrate a matched C function into src/ and splat.yaml.")
    parser.add_argument("target", choices=TARGETS)
    parser.add_argument("function")
    parser.add_argument("--source", type=Path, required=True)
    parser.add_argument("--name", help="C function name (defaults to original label)")
    parser.add_argument("--subdir", help="subdirectory under src/ (defaults to shared/gallery/main/death)")
    parser.add_argument("--no-pair", action="store_true", help="do not auto-integrate into paired DEATH.ELF")
    args = parser.parse_args()
    integrate(args.target, args.function, args.source, args.name, args.subdir, pair_death=not args.no_pair)


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError, subprocess.CalledProcessError) as error:
        raise SystemExit(f"Integrate failed: {error}")
