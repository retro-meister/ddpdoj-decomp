import argparse
import json
import os
from pathlib import Path
import re
import subprocess
import sys

from build import build, compile_source, draft_defines
from common import BASEROM, ROOT, TARGETS, matching_lock, nonmatching_dir, require_local, target_compiler, verify, verify_compiler
from diff import candidate_layout, collect_provide_symbols, link_text, verify_jump_table_layout
from draft import extract_function
from inventory import INSN_RE, pair_main_and_death, scan_game_asm
from objects import find_function, undefined_symbols
from split import load_splat_config, load_symbols, scan_asm_functions, split, splat_yaml_path, symbols_path, target_layout

SUBSEG_LINE_RE = re.compile(r"^(\s*-\s*\[)(0x[0-9a-fA-F]+|\d+)(,\s*(\.?[a-zA-Z0-9_]+),\s*([^\]]+))(\]\s*)$")
INLINE_ASM_RE = re.compile(r"\b(?:asm|__asm|__asm__)\s*(?:volatile\b|__volatile__\b)?\s*[\({]")
OPERAND_SYM_RE = re.compile(r"(?<![%$.\w])[A-Za-z_][A-Za-z0-9_]*")
MAIN, DEATH = "SLPS_252.33", "DEATH.ELF"


def verify_match(local, target_name, function_name, source_path, address, size, *, asm_function=None, extra_symbols=None):
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
    compile_source(local, str(source_path), obj, version, draft_defines(target_name))
    fn_offset, fn_size = find_function(obj, function_name)
    provided = collect_provide_symbols(target_name, split_folder, asm_functions)
    provided.update(extra_symbols or {})
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
    """Pair a Main asm function with its exact normalized Death Label twin, from the current split."""
    main_funcs = scan_game_asm(MAIN, split(MAIN))
    death_funcs = scan_game_asm(DEATH, split(DEATH))
    pair_main_and_death(main_funcs, death_funcs)
    entry = next((fn for fn in main_funcs if fn["name"] == func_name), None)
    return entry.get("paired_death") if entry else None


def asm_operand_symbols(text):
    rows = []
    for line in text.splitlines():
        match = INSN_RE.search(line)
        if match:
            operands = match.group(3).split("/*", 1)[0].strip().split(None, 1)
            rows.append(OPERAND_SYM_RE.findall(operands[1]) if len(operands) > 1 else [])
    return rows


def death_symbol_aliases(object_path, main_func, death_func):
    """Map every symbol the compiled C references to its Death Label address.

    Names follow Main (the reference ELF). Addresses come from lining up the operands of the
    two twin asm functions, which are identical apart from symbol addresses.
    Returns {name: death_address} for names Death Label does not already define.
    """
    main_split, death_split = split(MAIN), split(DEATH)
    main_asm, death_asm = scan_asm_functions(main_split / "asm"), scan_asm_functions(death_split / "asm")
    main_syms = collect_provide_symbols(MAIN, main_split, main_asm)
    death_syms = collect_provide_symbols(DEATH, death_split, death_asm)
    main_rows = asm_operand_symbols(extract_function(main_split / "asm", main_func))
    death_rows = asm_operand_symbols(extract_function(death_split / "asm", death_func))
    if len(main_rows) != len(death_rows):
        raise ValueError(f"{main_func}/{death_func}: twin asm has different instruction counts")

    address_map = {main_syms[main_func]: death_syms[death_func]}
    for main_row, death_row in zip(main_rows, death_rows):
        if len(main_row) != len(death_row):
            raise ValueError(f"{main_func}/{death_func}: twin asm operands differ")
        for main_name, death_name in zip(main_row, death_row):
            if main_name in main_syms and death_name in death_syms:
                main_address, death_address = main_syms[main_name], death_syms[death_name]
                if address_map.setdefault(main_address, death_address) != death_address:
                    raise ValueError(f"{main_func}: {main_name} maps to two Death Label addresses")

    aliases = {}
    for name in sorted(undefined_symbols(object_path) - {"_gp"}):
        if name not in main_syms:
            raise ValueError(f"{name}: not defined in {MAIN}")
        death_address = address_map.get(main_syms[name])
        if death_address is None:
            raise ValueError(f"{name}: no Death Label address (not referenced by {main_func}'s asm)")
        if name in death_syms:
            if death_syms[name] != death_address:
                raise ValueError(
                    f"{name}: names {death_syms[name]:#x} in Death Label but the twin needs {death_address:#x}; "
                    f"give it a real name in both symbols.txt files"
                )
            continue
        aliases[name] = death_address
    return aliases


def append_alias(target_name, sym_name, address):
    sym_file = symbols_path(target_name)
    text = sym_file.read_text(encoding="utf-8")
    for other, (other_address, _) in load_symbols(target_name).items():
        if other == sym_name and other_address == address:
            return
        if other_address == address and other != "_gp":
            raise ValueError(
                f"{target_name}: {address:#x} is already named {other}, but Main calls it {sym_name}; "
                f"use one name in both symbols.txt files"
            )
    funcs = scan_asm_functions(split(target_name) / "asm")
    info = next((f"type:func size:{size:#x}" for name, (addr, size) in funcs.items() if addr == address), None)
    if text and not text.endswith("\n"):
        text += "\n"
    text += f"{sym_name} = {address:#x};" + (f" // {info}" if info else "") + "\n"
    sym_file.write_text(text, encoding="utf-8")


def prepare_integration(target_name, func_name, source_path, out_name=None, subdir=None, pair_death=False):
    """Verify a matched draft against retail bytes without touching the config or the build."""
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

    staging = ROOT / "build" / "integrate" / f"{c_name}.c"
    staging.parent.mkdir(parents=True, exist_ok=True)
    staging.write_text(code, encoding="utf-8")

    matched, rodata = verify_match(local, target_name, c_name, staging, address, size, asm_function=func_name)
    if not matched:
        raise ValueError(f"{target_name}:{c_name} does not match retail bytes; aborting integration")
    verified_targets = [(target_name, func_name, address, size, rodata)]

    death_aliases = {}
    if target_name == MAIN and pair_death:
        paired = find_paired_death(func_name)
        if paired is None:
            print(f"NOTE  {func_name} has no exact Death Label twin; integrating into Main only")
        else:
            try:
                death_funcs = scan_asm_functions(split(DEATH) / "asm")
                d_address, d_size = death_funcs[paired["name"]]
                if d_size != size:
                    raise ValueError(f"twin {paired['name']} is {d_size:#x} bytes, Main is {size:#x}")
                death_aliases = death_symbol_aliases(
                    ROOT / "build" / "integrate" / target_name / c_name / "compiled.o", func_name, paired["name"],
                )
                d_matched, d_rodata = verify_match(
                    local, DEATH, c_name, staging, d_address, d_size,
                    asm_function=paired["name"], extra_symbols=death_aliases,
                )
                if not d_matched:
                    raise ValueError(f"does not match twin {paired['name']} at {d_address:#x}")
                verified_targets.append((DEATH, paired["name"], d_address, d_size, d_rodata))
            except (KeyError, ValueError) as error:
                death_aliases = {}
                print(f"WARNING  Death Label twin of {func_name} not integrated ({error}); integrating into Main only")

    if subdir is None:
        if len(verified_targets) > 1:
            subdir = "shared"
        elif target_name == "GALLERY.ELF":
            subdir = "gallery"
        elif target_name == DEATH:
            subdir = "death"
        else:
            subdir = "main"

    dest_file = ROOT / "src" / subdir / f"{c_name}.c"
    if dest_file.exists():
        raise ValueError(f"Destination already exists: {dest_file.relative_to(ROOT)}")
    return {
        "func_name": func_name, "c_name": c_name, "code": code, "stub": f"{subdir}/{c_name}",
        "dest_file": dest_file, "verified_targets": verified_targets, "death_aliases": death_aliases,
    }


def apply_plans(local, plans):
    """Write sources and patch Splat/symbols for every plan, then build each touched ELF once."""
    touched = sorted({t[0] for plan in plans for t in plan["verified_targets"]})
    backups = {}
    for t_name in touched:
        for path in (splat_yaml_path(t_name), symbols_path(t_name)):
            backups[path] = path.read_bytes()
    written = []
    try:
        for plan in plans:
            plan["dest_file"].parent.mkdir(parents=True, exist_ok=True)
            plan["dest_file"].write_text(plan["code"], encoding="utf-8")
            written.append(plan["dest_file"])
            for alias, alias_address in plan["death_aliases"].items():
                append_alias(DEATH, alias, alias_address)
            for t_name, _, t_addr, t_size, rodata in plan["verified_targets"]:
                append_symbol(t_name, plan["c_name"], t_addr, t_size)
                patch_splat_yaml(t_name, t_addr, t_size, plan["stub"])
                if rodata is not None:
                    table_offset, table_size = rodata
                    patch_splat_rodata(t_name, table_offset, table_size, plan["stub"])
        for t_name in touched:
            build(local, target=t_name)
    except BaseException:
        for path in written:
            path.unlink(missing_ok=True)
        for path, old_bytes in backups.items():
            path.write_bytes(old_bytes)
        for t_name in touched:
            (ROOT / "build" / "split" / t_name / "split-state.json").unlink(missing_ok=True)
        raise
    for plan in plans:
        for t_name, asm_name, _, _, _ in plan["verified_targets"]:
            (nonmatching_dir(t_name) / f"{asm_name}.c").unlink(missing_ok=True)
            (ROOT / "build" / "wip" / t_name / f"{asm_name}.best.c").unlink(missing_ok=True)


@matching_lock()
def integrate_many(plans):
    """Apply prepared plans with one split+build per ELF. If the combined build fails, retry one by one.

    Returns (applied, failed) where failed is a list of (plan, error).
    """
    if not plans:
        return [], []
    local = require_local()
    try:
        apply_plans(local, plans)
        applied = list(plans)
    except (OSError, ValueError, subprocess.CalledProcessError, SystemExit) as error:
        if len(plans) == 1:
            return [], [(plans[0], error)]
        print(f"WARNING  batched integration failed ({error}); retrying {len(plans)} functions one at a time")
        applied, failed = [], []
        for plan in plans:
            try:
                apply_plans(local, [plan])
                applied.append(plan)
            except (OSError, ValueError, subprocess.CalledProcessError, SystemExit) as one_error:
                failed.append((plan, one_error))
        for plan in applied:
            report_integrated(plan)
        return applied, failed
    for plan in applied:
        report_integrated(plan)
    return applied, []


def report_integrated(plan):
    names = ", ".join(t[0] for t in plan["verified_targets"])
    print(f"INTEGRATED  {plan['dest_file'].relative_to(ROOT)}  ({names})")


def integrate(target_name, func_name, source_path, out_name=None, subdir=None, pair_death=False):
    plan = prepare_integration(target_name, func_name, source_path, out_name, subdir, pair_death)
    applied, failed = integrate_many([plan])
    if failed:
        raise failed[0][1]
    return plan["dest_file"], [t[0] for t in plan["verified_targets"]]


def main():
    parser = argparse.ArgumentParser(description="Verify and integrate a matched C function into src/ and splat.yaml.")
    parser.add_argument("target", choices=TARGETS)
    parser.add_argument("function")
    parser.add_argument("--source", type=Path, required=True)
    parser.add_argument("--name", help="C function name (defaults to original label)")
    parser.add_argument("--subdir", help="subdirectory under src/ (defaults to shared/gallery/main/death)")
    parser.add_argument("--pair-death", action="store_true", help="also integrate the exact Death Label twin (off by default; Main-first)")
    args = parser.parse_args()
    integrate(args.target, args.function, args.source, args.name, args.subdir, pair_death=args.pair_death)


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError, subprocess.CalledProcessError) as error:
        raise SystemExit(f"Integrate failed: {error}")
