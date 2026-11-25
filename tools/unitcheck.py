"""Check a whole C unit (one or many functions) against a run of Death Label code.

    uv run tools/unitcheck.py src/main/func_00227310.c --at 0x1bf700            # per-function verdicts + diffs
    uv run tools/unitcheck.py src/main/func_00227310.c --at 0x1bf700 --apply    # integrate when everything matches

The unit is compiled as Death Label sees it (-DDEATH_LABEL). Its functions are laid out the way the linker
will and compared with retail DEATH.ELF with only relocated fields masked. --apply moves a `src/main` unit to
`src/game` (or integrates a draft as `src/death/<name>.c`), patches the Splat configs and names the symbols.
"""
import argparse
from collections import Counter, defaultdict
import difflib
import os
from pathlib import Path
import re
import struct
import subprocess
from tempfile import TemporaryDirectory

from build import build, compile_source, draft_defines, unit_object
from common import ROOT, require_local, target_compiler
from pairdeath import AUTO_RE, DEATH, MAIN, coarse, death_image, masked_equal, patch_death_text, read_object, site_values
from split import load_symbols, scan_asm_functions, split, target_units


def disassemble(binutils, data, address):
    with TemporaryDirectory(prefix="unitcheck-") as tmp:
        path = Path(tmp) / "code.bin"
        path.write_bytes(data)
        out = subprocess.run(
            [binutils["objdump"], "-D", "-b", "binary", "-m", "mips:5900", "-EL", "--no-show-raw-insn",
             f"--adjust-vma={address:#x}", str(path)],
            check=True, capture_output=True, text=True).stdout
    rows = []
    for line in out.splitlines():
        match = re.match(r"\s*([0-9a-f]+):\s+(.*)$", line)
        if match:
            rows.append(re.sub(r"\s+", " ", match.group(2)).strip())
    return rows


def neutral(data, relocs, start, size):
    """Bytes of one function with every relocated field zeroed."""
    out = bytearray(data[start:start + size])
    for offset, kind, _ in relocs:
        if start <= offset < start + size:
            word, = struct.unpack_from("<I", out, offset - start)
            mask = {2: 0xffffffff, 4: 0x03ffffff}.get(kind, 0xffff)
            struct.pack_into("<I", out, offset - start, word & ~mask & 0xffffffff)
    return bytes(out)


def load_unit(local, source, workdir):
    obj = workdir / "unit.o"
    compile_source(local, str(source), obj, target_compiler(DEATH, local), draft_defines(DEATH))
    sections, symbols = read_object(obj)
    text = next(index for index, section in sections.items() if section["name"] == ".text")
    functions = sorted((s for s in symbols if s["type"] == 2 and s["shndx"] == text), key=lambda s: s["value"])
    return sections, symbols, text, functions


def check(local, source, base, show=40):
    image, file_address, code_end, gp = death_image()
    death_sizes = {address: size for address, size in scan_asm_functions(split(DEATH) / "asm").values()}
    with TemporaryDirectory(prefix="unitcheck-", dir=ROOT / "build") as tmp:
        sections, symbols, text, functions = load_unit(local, source.relative_to(ROOT), Path(tmp))
    section = sections[text]
    position, results, shifted = base, [], False
    for index, function in enumerate(functions):
        size = function["size"] or ((functions[index + 1]["value"] if index + 1 < len(functions) else len(section["data"])) - function["value"])
        theirs_size = death_sizes.get(position, size)
        ours = section["data"][function["value"]:function["value"] + size]
        theirs = image[position - file_address:position - file_address + theirs_size]
        relocs = [(o - function["value"], k, s) for o, k, s in section["relocs"] if function["value"] <= o < function["value"] + size]
        same = size == theirs_size and masked_equal(ours, theirs, relocs)
        results.append((function["name"], position, size, theirs_size, same))
        if not same:
            mine = disassemble(local["binutils"], neutral(section["data"], section["relocs"], function["value"], size), 0)
            fake = [(o, k, s) for o, k, s in relocs] if size == theirs_size else []
            other = disassemble(local["binutils"], neutral(theirs, fake, 0, theirs_size) if fake else coarse(theirs), 0)
            if not fake:
                mine = disassemble(local["binutils"], coarse(ours), 0)
            print(f"DIFF  {function['name']} at {position:#x}: ours {size:#x} B, Death Label {theirs_size:#x} B")
            shown = 0
            for line in difflib.unified_diff(other, mine, "death", "ours", n=int(os.environ.get("UNITCHECK_CONTEXT", "2")), lineterm=""):
                print("   ", line)
                shown += 1
                if shown >= show:
                    print("    ...")
                    break
        if position + ((size + 15) & ~15) != position + ((theirs_size + 15) & ~15):
            shifted = True
        position += (theirs_size + 15) & ~15
    good = sum(1 for result in results if result[4])
    print(f"{good} / {len(results)} functions match from {base:#x} to {position:#x}")
    return sections, symbols, text, functions, results, shifted


def integrate_unit(local, source, base, sections, symbols, text, functions, do_build=True):
    """Everything matched: derive symbol addresses, then move/patch/build."""
    from integrate import patch_splat_rodata
    image, file_address, code_end, gp = death_image()
    section = sections[text]
    theirs = image[base - file_address:base - file_address + len(section["data"])]
    death_symbols = load_symbols(DEATH)
    wanted, local_bases = defaultdict(Counter), defaultdict(Counter)

    def collect(data, their_data, relocs):
        for sym_index, value in site_values(data, their_data, relocs, gp):
            symbol = symbols[sym_index]
            if symbol["shndx"] == 0:
                wanted[symbol["name"]][value] += 1
            elif symbol["shndx"] != text and symbol["shndx"] in sections:
                local_bases[sections[symbol["shndx"]]["name"]][value - symbol["value"]] += 1

    collect(section["data"], theirs, section["relocs"])
    rodata = []
    for index, other in sections.items():
        if index == text:
            continue
        name = other["name"]
        if name != ".rodata" or len(local_bases[name]) != 1:
            raise ValueError(f"{name}: needs exactly one address, got {dict(local_bases[name])}")
        address = next(iter(local_bases[name]))
        their_data = image[address - file_address:address - file_address + len(other["data"])]
        if not masked_equal(other["data"], their_data, other["relocs"]):
            raise ValueError(f"{name}: contents differ at {address:#x}")
        collect(other["data"], their_data, other["relocs"])
        rodata.append((address, len(other["data"])))

    names = {}
    for function in functions:
        if function["bind"] == 1:
            names[function["name"]] = (base + function["value"], f"type:func size:{function['size']:#x}")
    for name, votes in wanted.items():
        if len(votes) != 1:
            raise ValueError(f"{name}: used at {len(votes)} different addresses: {[hex(v) for v in votes]}")
        names.setdefault(name, (next(iter(votes)), "type:func" if next(iter(votes)) < code_end else ""))
    shared_addresses = {}
    for name, (address, _) in names.items():
        shared_addresses.setdefault(address, []).append(name)
    doubles = [f"{address:#x} is used under {len(group)} names: {', '.join(sorted(group))}"
               for address, group in sorted(shared_addresses.items()) if len(group) > 1]
    if doubles:
        raise ValueError("\n".join(doubles))
    problems = [f"{name}: symbols.txt has {death_symbols[name][0]:#x}, this unit needs {address:#x}"
                for name, (address, _) in names.items() if name in death_symbols and death_symbols[name][0] != address]
    if problems:
        raise ValueError("\n".join(problems))

    rel = source.relative_to(ROOT)
    in_main = rel.parts[:2] == ("src", "main")
    in_shared = rel.parts[:2] == ("src", "game")
    inner = "/".join(rel.parts[2:-1] + (source.stem,))
    stub = ("game/" if in_main or in_shared else "death/") + inner
    dest = ROOT / "src" / f"{stub}.c"
    if dest.exists() and dest != source:
        raise ValueError(f"{dest.relative_to(ROOT)} already exists")

    backups = {path: path.read_bytes() for path in (
        ROOT / "config" / DEATH / "splat.yaml", ROOT / "config" / DEATH / "symbols.txt", ROOT / "config" / MAIN / "splat.yaml")}
    try:
        sym_file = ROOT / "config" / DEATH / "symbols.txt"
        claimed = {address: name for name, (address, _) in names.items()}
        kept = []
        for line in sym_file.read_text(encoding="utf-8").splitlines():
            match = re.match(r"\s*(\w+)\s*=\s*(0x[0-9a-fA-F]+)", line)
            if match and int(match.group(2), 16) in claimed and match.group(1) not in names:
                old = match.group(1)
                if old.startswith("death_") or (AUTO_RE.fullmatch(old) and int(old.split("_")[1], 16) == int(match.group(2), 16)):
                    continue
                if "ignore:true" not in line:
                    raise ValueError(f"{int(match.group(2), 16):#x} is already named {old}; this unit calls it {claimed[int(match.group(2), 16)]}")
            kept.append(line)
        for name, (address, note) in sorted(names.items(), key=lambda kv: kv[1][0]):
            if name not in death_symbols:
                kept.append(f"{name} = {address:#x};" + (f" // {note}" if note else ""))
        sym_file.write_text("\n".join(kept) + "\n", encoding="utf-8")

        yaml_file = ROOT / "config" / DEATH / "splat.yaml"
        lines = yaml_file.read_text(encoding="utf-8").splitlines()
        patch_death_text(lines, [{"death_address": base, "size": len(section["data"]), "stub": "x/" + inner}], image,
                         file_address, code_end)
        text_yaml = "\n".join(lines) + "\n"
        yaml_file.write_text(text_yaml.replace(f", c, game/{inner}]", f", c, {stub}]"), encoding="utf-8")
        for address, size in rodata:
            patch_splat_rodata(DEATH, address - file_address, size, stub)
        if in_main:
            main_yaml = ROOT / "config" / MAIN / "splat.yaml"
            main_yaml.write_text(re.sub(rf"(, (?:c|\.rodata), )main/{re.escape(source.stem)}\]", rf"\g<1>{stub}]",
                                        main_yaml.read_text(encoding="utf-8")), encoding="utf-8")
            subprocess.run(["git", "mv", str(rel), f"src/{stub}.c"], cwd=ROOT, check=True)
        elif not in_shared:
            dest.parent.mkdir(parents=True, exist_ok=True)
            dest.write_text(source.read_text(encoding="utf-8"), encoding="utf-8")
        if do_build:
            build(local)
            if sync_function_symbols(local):
                build(local, target=DEATH)
    except BaseException:
        for path, data in backups.items():
            path.write_bytes(data)
        if in_main and dest.exists() and not source.exists():
            subprocess.run(["git", "mv", f"src/{stub}.c", str(rel)], cwd=ROOT, check=True)
        elif not in_main and not in_shared:
            dest.unlink(missing_ok=True)
        raise
    if not in_main and not in_shared and "nonmatchings" in rel.parts:
        source.unlink()
    print(f"INTEGRATED  src/{stub}.c at {base:#x} ({len(functions)} function(s))")


def sync_function_symbols(local):
    """Give every function a Death Label C unit defines (statics too) a sized entry in symbols.txt."""
    version = target_compiler(DEATH, local)
    wanted = {}
    for unit in target_units(DEATH):
        obj = unit_object(version, DEATH, unit["source"])
        if not obj.is_file():
            continue
        sections, symbols = read_object(obj)
        text = next(index for index, section in sections.items() if section["name"] == ".text")
        for symbol in symbols:
            if symbol["type"] == 2 and symbol["shndx"] == text and symbol["size"]:
                wanted[symbol["name"]] = (unit["address"] + symbol["value"], symbol["size"])
    sym_file = ROOT / "config" / DEATH / "symbols.txt"
    lines, seen, changed = [], set(), 0
    for line in sym_file.read_text(encoding="utf-8").splitlines():
        match = re.match(r"\s*(\w+)\s*=\s*(0x[0-9a-fA-F]+)\s*;(.*)$", line)
        if match and match.group(1) in wanted:
            name = match.group(1)
            address, size = wanted[name]
            seen.add(name)
            if int(match.group(2), 16) != address:
                raise ValueError(f"{name}: symbols.txt has {match.group(2)}, its unit defines it at {address:#x}")
            fixed = f"{name} = {address:#x}; // type:func size:{size:#x}" + (" ignore:true" if "ignore:true" in match.group(3) else "")
            changed += fixed != line
            line = fixed
        lines.append(line)
    for name, (address, size) in sorted(wanted.items(), key=lambda kv: kv[1][0]):
        if name not in seen:
            lines.append(f"{name} = {address:#x}; // type:func size:{size:#x}")
            changed += 1
    if changed:
        sym_file.write_text("\n".join(lines) + "\n", encoding="utf-8")
    return changed


def main():
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("source", nargs="?")
    parser.add_argument("--sync-symbols", action="store_true", help="only refresh the sized function entries in symbols.txt")
    parser.add_argument("--batch", help="file of '<source> <address>' lines to integrate with one build")
    parser.add_argument("--at", type=lambda value: int(value, 0), help="Death Label address of the first function")
    parser.add_argument("--apply", action="store_true")
    parser.add_argument("--max-diffs", type=int, default=40)
    args = parser.parse_args()
    local = require_local()
    if args.sync_symbols:
        print(f"{sync_function_symbols(local)} symbols.txt entries updated")
        return
    if args.batch:
        done = []
        for line in Path(args.batch).read_text(encoding="utf-8").split("\n"):
            if not line.strip():
                continue
            name, address = line.split()
            source = (ROOT / name).resolve()
            sections, symbols, text, functions, results, _ = check(local, source, int(address, 0), 0)
            if not all(result[4] for result in results):
                print(f"SKIP  {name}: does not match")
                continue
            try:
                integrate_unit(local, source, int(address, 0), sections, symbols, text, functions, do_build=False)
                done.append(name)
            except ValueError as error:
                print(f"SKIP  {name}: {error}")
        build(local)
        if sync_function_symbols(local):
            build(local, target=DEATH)
        print(f"batch of {len(done)} integrated")
        return
    source = (ROOT / args.source).resolve()
    sections, symbols, text, functions, results, shifted = check(local, source, args.at, args.max_diffs)
    if args.apply:
        if not all(result[4] for result in results):
            raise SystemExit("not applied: the unit does not match")
        integrate_unit(local, source, args.at, sections, symbols, text, functions)


if __name__ == "__main__":
    main()
