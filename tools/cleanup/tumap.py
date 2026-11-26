"""Per-function data references of SLPS_252.33, for finding translation unit boundaries.

    uv run tools/tumap.py [--from 0x212640] [--to 0x23dc30] [--json build/tumap.json]

Reads every compiled Main unit's relocations and prints, for each function in address order, the lowest and
highest address it references in .data, .rodata, .sdata, .sbss and .bss. A translation unit owns one
contiguous run of each section, laid out in link order, so a unit boundary can only fall where the ranges of
the functions before it lie below the ranges of the functions after it. `|` in the last column marks those
places for the sections given with --by (default: sbss and bss).
"""
import argparse
import json
import re
import struct

import sys as _sys
from pathlib import Path as _Path
if str(_Path(__file__).resolve().parent.parent) not in _sys.path:
    _sys.path.insert(0, str(_Path(__file__).resolve().parent.parent))
from build import unit_object
from common import ROOT, target_compiler
from split import load_symbols, target_units

MAIN = "SLPS_252.33"
SECTIONS = [(".data", 0x23DC80, 0x273EC0), (".rodata", 0x273EC0, 0x28C070), (".sdata", 0x28C070, 0x28DE80),
            (".sbss", 0x28DE80, 0x28F000), (".bss", 0x28F000, 0x6E5E00)]
AUTO = re.compile(r"(?:death_)?(?:D|func)_([0-9A-F]{8})$")


def section_of(address):
    for name, start, end in SECTIONS:
        if start <= address < end:
            return name
    return None


def references(path, addresses):
    """{function name: set of referenced data addresses} for one object."""
    data = path.read_bytes()
    shoff, = struct.unpack_from("<I", data, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", data, 0x2E)
    headers = [struct.unpack_from("<10I", data, shoff + i * shentsize) for i in range(shnum)]

    def cstr(base, index):
        start = base + index
        return data[start:data.index(0, start)].decode("ascii")

    names = [cstr(headers[shstrndx][4], header[0]) for header in headers]
    symtab = headers[names.index(".symtab")]
    strtab = headers[symtab[6]][4]
    symbols = [(cstr(strtab, name), value, info & 15, shndx)
               for name, value, _, info, _, shndx in struct.iter_unpack("<IIIBBH", data[symtab[4]:symtab[4] + symtab[5]])]
    owner = {}
    for name, value, kind, shndx in symbols:
        if kind == 2 and shndx and shndx < len(headers) and headers[shndx][2] & 4:
            owner.setdefault(shndx, []).append((value, name))
    out = {}
    for header in headers:
        if header[1] != 9 or header[7] not in owner:
            continue
        functions = sorted(owner[header[7]])
        for offset, info in struct.iter_unpack("<II", data[header[4]:header[4] + header[5]]):
            name = symbols[info >> 8][0]
            address = addresses.get(name)
            if address is None:
                match = AUTO.match(name)
                address = int(match.group(1), 16) if match and not name.startswith("death_") else None
            if address is None or section_of(address) is None:
                continue
            function = [n for v, n in functions if v <= offset][-1]
            out.setdefault(function, set()).add(address)
    return out


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--from", dest="start", type=lambda v: int(v, 0), default=0x119B10)
    parser.add_argument("--to", dest="end", type=lambda v: int(v, 0), default=0x23DC80)
    parser.add_argument("--by", default="sbss,bss")
    parser.add_argument("--json")
    args = parser.parse_args()

    symbols = load_symbols(MAIN)
    addresses = {name: value[0] for name, value in symbols.items()}
    version = target_compiler(MAIN)
    refs = {}
    for unit in target_units(MAIN):
        obj = unit_object(version, MAIN, unit["source"])
        if obj.is_file():
            refs.update(references(obj, addresses))
    functions = sorted((addresses[name], name) for name in refs if name in addresses)
    functions += [(a, n) for n, a in addresses.items() if n not in refs and AUTO.match(n) and n.startswith("func_")]
    functions = sorted(set(f for f in functions if args.start <= f[0] < args.end))
    by = ["." + name for name in args.by.split(",")]
    rows = []
    for address, name in functions:
        spans = {}
        for ref in refs.get(name, ()):
            section = section_of(ref)
            low, high = spans.get(section, (ref, ref))
            spans[section] = (min(low, ref), max(high, ref))
        rows.append({"address": address, "name": name, "spans": spans})
    # A boundary before row i is possible when, in every --by section, max(before) < min(after).
    for i, row in enumerate(rows):
        ok = True
        for section in by:
            before = [r["spans"][section][1] for r in rows[:i] if section in r["spans"]]
            after = [r["spans"][section][0] for r in rows[i:] if section in r["spans"]]
            if before and after and max(before) >= min(after):
                ok = False
        row["boundary"] = ok
    for row in rows:
        cells = []
        for section, _, _ in SECTIONS:
            span = row["spans"].get(section)
            cells.append(f"{span[0]:06x}-{span[1]:06x}" if span else " " * 13)
        print(f"{'|' if row['boundary'] else ' '} {row['address']:#x} {row['name']:<28} " + "  ".join(cells))
    if args.json:
        (ROOT / args.json).write_text(json.dumps(
            [{"address": r["address"], "name": r["name"], "boundary": r["boundary"],
              "spans": {k: list(v) for k, v in r["spans"].items()}} for r in rows], indent=1), encoding="utf-8")


if __name__ == "__main__":
    main()
