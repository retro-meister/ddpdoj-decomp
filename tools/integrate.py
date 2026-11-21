import argparse
import json
import os
from pathlib import Path
import re
import subprocess
import sys

from build import build, compile_source
from common import BASEROM, ROOT, TARGETS, matching_lock, nonmatching_dir, require_local, target_compiler, verify, verify_compiler
from diff import candidate_layout, collect_provide_symbols, link_text, verify_jump_table_layout
from objects import find_function
from split import load_splat_config, scan_asm_functions, split, splat_yaml_path, symbols_path, target_layout

SUBSEG_LINE_RE = re.compile(r"^(\s*-\s*\[)(0x[0-9a-fA-F]+|\d+)(,\s*(\.?[a-zA-Z0-9_]+),\s*([^\]]+))(\]\s*)$")
INLINE_ASM_RE = re.compile(r"\b(?:asm|__asm|__asm__)\s*(?:volatile\b|__volatile__\b)?\s*[\({]")


def verify_match(local, target_name, function_name, source_path, address, size, *, asm_function=None):
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
    layout = candidate_layout(provided, address - fn_offset)
    binutils = local["binutils"]
    candidate = link_text(binutils, folder, layout)[fn_offset:fn_offset + fn_size]
    if retail == candidate:
        return True, None
    if asm_function is not None and len(candidate) == size:
        proof = verify_jump_table_layout(
            binutils, folder, split_folder / "asm", asm_function, layout,
            fn_offset, retail, original[code_end - file_address:], code_end,
        )
        if proof is not None:
            table_address, table_size = proof
            return True, (table_address - file_address, table_size)
    return False, None


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


def patch_splat_rodata(target_name, offset, size, stub):
    config = load_splat_config(target_name)
    main = next(seg for seg in config["segments"] if isinstance(seg, dict) and seg.get("name") == "main")
    options = config["options"]
    alignment = main.get("subalign", options.get("subalign", 16))
    if not isinstance(alignment, int) or alignment <= 0 or offset % alignment or not options.get("emit_subalign", True):
        raise ValueError(f"{target_name}: unsupported Splat alignment for .rodata at {offset:#x}")
    end = offset + size
    padded_end = ((end + alignment - 1) // alignment) * alignment
    original = (BASEROM / target_name).read_bytes()
    subsegments = main["subsegments"]
    for index, (sub, following) in enumerate(zip(subsegments, subsegments[1:])):
        if not (isinstance(sub, list) and len(sub) == 3 and isinstance(sub[0], int)
                and sub[1] in ("data", "rodata") and sub[0] <= offset):
            continue
        if not (isinstance(following, list) and following and isinstance(following[0], int)
                and offset < following[0]):
            continue
        if padded_end > following[0] or padded_end > len(original) or any(original[end:padded_end]):
            raise ValueError(f"{target_name}: .rodata at {offset:#x} has no verified alignment padding")
        if sub[1] == "data" and any(
            isinstance(later, list) and len(later) > 1 and later[1] in ("data", ".data")
            for later in subsegments[index + 1:]
        ):
            raise ValueError(f"{target_name}: splitting .rodata at {offset:#x} would reorder later .data")
        break
    else:
        raise ValueError(f"{target_name}: no plain data or rodata subsegment contains .rodata at {offset:#x}")

    yaml_file = splat_yaml_path(target_name)
    lines = yaml_file.read_text(encoding="utf-8").splitlines(keepends=True)
    matches = []
    for index, line in enumerate(lines):
        match = SUBSEG_LINE_RE.match(line)
        if match and (int(match[2], 0), match[4], match[5].strip()) == tuple(sub):
            matches.append((index, match[1]))
    if len(matches) != 1:
        raise ValueError(f"{target_name}: ambiguous Splat subsegment for .rodata at {offset:#x}")
    line_index, prefix = matches[0]
    start, kind, name = sub
    replacement = []
    if offset > start:
        replacement.append(f"{prefix}{start:#x}, {kind}, {name}]\n")
    replacement.append(f"{prefix}{offset:#x}, .rodata, {stub}]\n")
    if padded_end < following[0]:
        suffix = f"rodata_{padded_end:06x}"
        if any(isinstance(other, list) and len(other) > 2 and other[2] == suffix for other in subsegments):
            raise ValueError(f"{target_name}: Splat subsegment {suffix} already exists")
        replacement.append(f"{prefix}{padded_end:#x}, rodata, {suffix}]\n")
    lines[line_index:line_index + 1] = replacement
    yaml_file.write_text("".join(lines), encoding="utf-8")


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


@matching_lock()
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
        matched, rodata = verify_match(
            local, t_name, c_name, staging, t_addr, t_size,
            asm_function=func_name if t_name == target_name else None,
        )
        if matched:
            verified_targets.append((t_name, t_addr, t_size, rodata))
        elif t_name == target_name:
            raise ValueError(f"{t_name}:{c_name} does not match retail bytes; aborting integration")

    backups = {}
    for t_name, _, _, _ in verified_targets:
        for path in (splat_yaml_path(t_name), symbols_path(t_name)):
            backups[path] = path.read_bytes()

    try:
        dest_file.parent.mkdir(parents=True, exist_ok=True)
        dest_file.write_text(code, encoding="utf-8")
        for t_name, t_addr, t_size, rodata in verified_targets:
            append_symbol(t_name, c_name, t_addr, t_size)
            patch_splat_yaml(t_name, t_addr, t_size, stub)
            if rodata is not None:
                table_offset, table_size = rodata
                patch_splat_rodata(t_name, table_offset, table_size, stub)
        for t_name, _, _, _ in verified_targets:
            build(local, target=t_name)
    except BaseException:
        dest_file.unlink(missing_ok=True)
        for path, old_bytes in backups.items():
            path.write_bytes(old_bytes)
        for t_name, _, _, _ in verified_targets:
            (ROOT / "build" / "split" / t_name / "split-state.json").unlink(missing_ok=True)
        raise

    for t_name, _, _, _ in verified_targets:
        (nonmatching_dir(t_name, shared=False) / f"{func_name}.c").unlink(missing_ok=True)
        (nonmatching_dir(t_name, shared=True) / f"{func_name}.c").unlink(missing_ok=True)
        (ROOT / "build" / "wip" / t_name / f"{func_name}.best.c").unlink(missing_ok=True)
    targets = [t for t, _, _, _ in verified_targets]
    names = ", ".join(targets)
    print(f"INTEGRATED  {dest_file.relative_to(ROOT)}  ({names})")
    return dest_file, targets


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
