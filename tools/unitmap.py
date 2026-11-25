"""Which translation unit uses which stretch of each section, for both executables.

    uv run tools/build.py --map          (once, writes build/<target>.map)
    uv run tools/unitmap.py [--target SLPS_252.33] [--json build/unitmap/<target>.json]
    uv run tools/unitmap.py --runs .data  (address runs of one section with the units that reference them)
    uv run tools/unitmap.py --unit shared/bomb

Reads the link map (symbol addresses, where each object's sections went) and the relocations of every compiled
unit and of the assembly data. For every symbol of a data section it records which units' code refers to it and
which data words point at it. A unit owns one contiguous stretch of each section, so the stretches that only one
unit refers to, in address order, are the evidence for where units begin and end.
"""
import argparse
import bisect
import json
import re
import struct

import yaml

from common import ROOT

TARGETS = ("SLPS_252.33", "DEATH.ELF")
SECTION_ORDER = (".text", ".data", ".rodata", ".sdata", ".sbss", ".bss")
SYMBOL_LINE = re.compile(r"^\s+0x([0-9a-f]{8,16})\s+([A-Za-z_.$][\w.$]*)(?:\s*=.*)?$")
SECTION_LINE = re.compile(r"^\s(\.\w+)\s+0x([0-9a-f]{8,16})\s+0x([0-9a-f]+)\s+(\S+\.o)$")
BOUND_LINE = re.compile(r"^\s+0x([0-9a-f]{8,16})\s+main_(\w+)_(START|END) = \.$")


def read_map(target):
    """(symbols {name: address}, placements [(section, start, size, object path)], bounds {section: (start, end)})."""
    symbols, placements, bounds = {}, [], {}
    started = False
    pending = None
    for line in (ROOT / "build" / f"{target}.map").read_text(encoding="utf-8").splitlines():
        if line.startswith("Linker script and memory map"):
            started = True
            continue
        if not started:
            continue
        if pending and line.startswith("                0x"):
            line = " " + pending + line
        pending = None
        match = SECTION_LINE.match(line)
        if match:
            size = int(match.group(3), 16)
            if size:
                placements.append((match.group(1), int(match.group(2), 16), size, match.group(4)))
            continue
        if re.match(r"^ \.\w+$", line):
            pending = line.strip() + " "
            continue
        match = BOUND_LINE.match(line)
        if match:
            key = "." + match.group(2).lower()
            start, end = bounds.get(key, (None, None))
            value = int(match.group(1), 16)
            bounds[key] = (value, end) if match.group(3) == "START" else (start, value)
            continue
        match = SYMBOL_LINE.match(line)
        if match:
            symbols.setdefault(match.group(2), int(match.group(1), 16))
    return symbols, placements, bounds


def elf_sections(data):
    shoff, = struct.unpack_from("<I", data, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", data, 0x2E)
    headers = [struct.unpack_from("<10I", data, shoff + i * shentsize) for i in range(shnum)]

    def cstr(base, index):
        start = base + index
        return data[start:data.index(0, start)].decode("ascii", "replace")

    names = [cstr(headers[shstrndx][4], header[0]) for header in headers]
    symtab = headers[names.index(".symtab")]
    strtab = headers[symtab[6]][4]
    symbols = [(cstr(strtab, name), value, info & 15, shndx)
               for name, value, _, info, _, shndx in struct.iter_unpack("<IIIBBH", data[symtab[4]:symtab[4] + symtab[5]])]
    return headers, names, symbols


def object_relocations(path):
    """[(section name, offset in section, kind, symbol name, symbol section index, symbol value)] and the
    function symbols [(offset, name)] of every executable section."""
    data = path.read_bytes()
    headers, names, symbols = elf_sections(data)
    functions = {}
    for name, value, kind, shndx in symbols:
        if kind == 2 and shndx and shndx < len(headers) and headers[shndx][2] & 4:
            functions.setdefault(shndx, []).append((value, name))
    out = []
    for header in headers:
        if header[1] != 9:
            continue
        target = header[7]
        for offset, info in struct.iter_unpack("<II", data[header[4]:header[4] + header[5]]):
            name, value, kind, shndx = symbols[info >> 8]
            out.append((target, names[target], offset, info & 0xFF, name, shndx, value))
    return out, {index: sorted(items) for index, items in functions.items()}, names


def load_units(target):
    """Units in link order: [{name, kind ('c' or 'asm'), object}] from the target's splat.yaml."""
    config = yaml.safe_load((ROOT / "config" / target / "splat.yaml").read_text(encoding="utf-8"))
    units, owned = [], {}
    for segment in config["segments"]:
        if not isinstance(segment, dict) or segment.get("name") != "main":
            continue
        for sub in segment["subsegments"]:
            if isinstance(sub, dict):
                kind, name, start = sub["type"], sub.get("name"), sub.get("vram")
            else:
                kind, name = sub[1], (sub[2] if len(sub) > 2 else None)
                start = sub[0] + segment["vram"] - segment["start"]
            if kind == "c":
                units.append({"name": name, "text": start})
            elif kind.startswith(".") and name:
                owned.setdefault(name, []).append((kind, start))
    return units, owned


class Target:
    def __init__(self, name):
        self.name = name
        self.symbols, self.placements, self.bounds = read_map(name)
        self.units, self.owned_entries = load_units(name)
        self.by_address = {}
        for symbol, address in self.symbols.items():
            self.by_address.setdefault(address, []).append(symbol)
        self.sections = sorted((start, end, section) for section, (start, end) in self.bounds.items()
                               if start is not None and end is not None)
        self.object_unit = {}
        self.placed = {}
        for section, start, size, path in self.placements:
            match = re.search(r"objects/src/(.+)\.c\.o$", path)
            unit = match.group(1) if match else None
            if unit:
                self.placed.setdefault(unit, {}).setdefault(section, []).append((start, start + size))
            self.object_unit[path] = unit
        self.function_unit = {}
        self.refs = {}
        self.data_refs = []
        self._scan()

    def section_of(self, address):
        for start, end, section in self.sections:
            if start <= address < end:
                return section
        return None

    def owner_of(self, address):
        """The C unit whose placed section holds this address, if any."""
        for unit, sections in self.placed.items():
            for section, spans in sections.items():
                if section == ".text":
                    continue
                for start, end in spans:
                    if start <= address < end:
                        return unit
        return None

    def _scan(self):
        placed_at = {}
        for section, start, size, path in self.placements:
            placed_at[(path, section)] = start
        paths = [f"build/split/{self.name}/objects/src/{unit['name']}.c.o" for unit in self.units]
        for path in paths:
            self.object_unit[path] = path.split("/objects/src/")[1][:-4]
        seen = set()
        for path in paths + [p[3] for p in self.placements]:
            if path in seen:
                continue
            seen.add(path)
            full = ROOT / path
            if not full.is_file():
                continue
            relocations, functions, names = object_relocations(full)
            unit = self.object_unit.get(path)
            for index, items in functions.items():
                if unit is None:
                    continue
                for offset, name in items:
                    self.function_unit[name] = unit
            for index, section_name, offset, kind, symbol, shndx, value in relocations:
                if shndx == 0 or shndx >= 0xFF00:
                    address = self.symbols.get(symbol)
                else:
                    base = placed_at.get((path, names[shndx]))
                    address = None if base is None else base + value
                    if symbol in self.symbols:
                        address = self.symbols[symbol]
                if address is None:
                    continue
                base = placed_at.get((path, section_name))
                site = None if base is None else base + offset
                if section_name == ".text" and unit:
                    items = functions.get(index, [])
                    position = bisect.bisect_right(items, (offset, "\x7f")) - 1
                    function = items[position][1] if position >= 0 else None
                    self.refs.setdefault(unit, []).append((function, address, kind))
                elif section_name in (".data", ".rodata", ".sdata") and site is not None and kind == 2:
                    self.data_refs.append((site, address, unit))

    def unit_spans(self):
        """{unit: {section: sorted referenced addresses}} from code relocations."""
        out = {}
        for unit, refs in self.refs.items():
            for function, address, kind in refs:
                section = self.section_of(address)
                if section and section != ".text":
                    out.setdefault(unit, {}).setdefault(section, set()).add(address)
        return out

    def users(self):
        """{address: set of units whose code refers to it}."""
        out = {}
        for unit, refs in self.refs.items():
            for function, address, kind in refs:
                out.setdefault(address, set()).add(unit)
        return out

    def objects(self, section):
        """Sorted start addresses of the symbols in a section (the smallest pieces a unit can own)."""
        start, end = self.bounds[section]
        return sorted(a for a in self.by_address if start <= a < end), end


def runs(target, section):
    """[(start, end, users tuple, owner)] : consecutive objects of a section with the same users."""
    addresses, end = target.objects(section)
    users = target.users()
    pointed = {}
    for site, address, unit in target.data_refs:
        pointed.setdefault(address, set()).add(site)
    rows = []
    for i, address in enumerate(addresses):
        stop = addresses[i + 1] if i + 1 < len(addresses) else end
        key = tuple(sorted(users.get(address, ())))
        owner = target.owner_of(address)
        if rows and rows[-1][2] == key and rows[-1][3] == owner:
            rows[-1] = (rows[-1][0], stop, key, owner)
        else:
            rows.append((address, stop, key, owner))
    return rows


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--target", default="SLPS_252.33")
    parser.add_argument("--runs")
    parser.add_argument("--unit")
    parser.add_argument("--json")
    args = parser.parse_args()
    target = Target(args.target)
    if args.runs:
        for start, end, users, owner in runs(target, args.runs):
            label = ", ".join(u.split("/")[-1] for u in users) or "-"
            print(f"{start:06x}-{end:06x} {end - start:6x} {'C:' + owner.split('/')[-1] if owner else 'asm':<28} {label}")
        return
    spans = target.unit_spans()
    users = target.users()
    if args.unit:
        for section, addresses in sorted(spans.get(args.unit, {}).items()):
            print(section)
            for address in sorted(addresses):
                others = sorted(u.split("/")[-1] for u in users[address] if u != args.unit)
                names = "/".join(target.by_address.get(address, ["?"])[:2])
                print(f"  {address:06x} {names:<40} {' '.join(others[:6])}{' ...' if len(others) > 6 else ''}")
        return
    out = []
    for unit in target.units:
        name = unit["name"]
        row = {"unit": name, "text": unit["text"], "placed": target.placed.get(name, {}), "sections": {}}
        for section, addresses in sorted(spans.get(name, {}).items()):
            own = sorted(a for a in addresses if users[a] == {name})
            row["sections"][section] = {"all": [min(addresses), max(addresses)], "count": len(addresses),
                                        "own": [own[0], own[-1]] if own else None, "own_count": len(own)}
        out.append(row)
    if args.json:
        path = ROOT / args.json
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(json.dumps(out, indent=1), encoding="utf-8")
    for row in out:
        cells = []
        for section in SECTION_ORDER[1:]:
            info = row["sections"].get(section)
            cells.append(f"{info['own'][0]:06x}-{info['own'][1]:06x}/{info['own_count']:<4}" if info and info["own"] else " " * 18)
        print(f"{row['text']:06x} {row['unit'].split('/')[-1]:<24} " + " ".join(cells))


if __name__ == "__main__":
    main()
