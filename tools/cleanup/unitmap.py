"""Which translation unit uses which stretch of each section, for both executables.

    uv run tools/build.py --map          (once, writes build/<target>.map)
    uv run tools/unitmap.py [--target SLPS_252.33] [--json build/unitmap/<target>.json]
    uv run tools/unitmap.py --runs .data  (address runs of one section with the units that reference them)
    uv run tools/unitmap.py --unit game/bomb

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

import sys as _sys
from pathlib import Path as _Path
if str(_Path(__file__).resolve().parent.parent) not in _sys.path:
    _sys.path.insert(0, str(_Path(__file__).resolve().parent.parent))
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
            placements.append((match.group(1), int(match.group(2), 16), int(match.group(3), 16), match.group(4)))
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
    return out, {index: sorted(items) for index, items in functions.items()}, names, headers


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
            if unit and size and start:
                spans = self.placed.setdefault(unit, {}).setdefault(section, [])
                if spans and spans[-1][1] == start:
                    spans[-1] = (spans[-1][0], start + size)
                else:
                    spans.append((start, start + size))
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
        # an object can have several sections of one name (the compiler makes one .text per function); the map
        # lists them in the object's own order
        listed = {}
        for section, start, size, path in self.placements:
            if start:
                listed.setdefault((path, section), []).append(start)
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
            relocations, functions, names, headers = object_relocations(full)
            unit = self.object_unit.get(path)
            placed_at, seen_count = {}, {}
            for index, header in enumerate(headers):
                if not header[2] & 2 or not header[5]:
                    continue
                starts = listed.get((path, names[index]), [])
                position = seen_count.get(names[index], 0)
                seen_count[names[index]] = position + 1
                if position < len(starts):
                    placed_at[index] = starts[position]
            for index, items in functions.items():
                if unit is None:
                    continue
                for offset, name in items:
                    self.function_unit[name] = unit
            for index, section_name, offset, kind, symbol, shndx, value in relocations:
                if shndx == 0 or shndx >= 0xFF00:
                    address = self.symbols.get(symbol)
                else:
                    base = placed_at.get(shndx)
                    address = None if base is None else base + value
                    if symbol in self.symbols:
                        address = self.symbols[symbol]
                if address is None:
                    continue
                base = placed_at.get(index)
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


FUNC_LINE = re.compile(r"(\w+)\s*=\s*0x([0-9a-fA-F]+);.*type:func")
GAME_START = 0x119B10


def game_functions(target):
    out = []
    for line in (ROOT / "config" / target / "symbols.txt").read_text(encoding="utf-8").splitlines():
        match = FUNC_LINE.match(line)
        if match and int(match.group(2), 16) >= GAME_START:
            out.append((int(match.group(2), 16), match.group(1)))
    return sorted(out)


def run_starts():
    """Main addresses where a run begins: the function before is not the function before in Death Label."""
    main, death = game_functions(TARGETS[0]), game_functions(TARGETS[1])
    position = {name: i for i, (_, name) in enumerate(death)}
    shared = {name for _, name in main}
    starts = {main[0][0]}
    previous = None
    for address, name in main:
        if name not in position:
            continue
        if previous is not None:
            i = position[previous] + 1
            while i < len(death) and death[i][1] not in shared:
                i += 1
            if i >= len(death) or death[i][1] != name:
                starts.add(address)
        previous = name
    return starts


def read_evidence(evidence_path=None):
    """{unit: (status, reason)} from an optional notes file: `unit | proven or assumed | reason`."""
    out = {}
    if evidence_path and evidence_path.is_file():
        for line in evidence_path.read_text(encoding="utf-8").splitlines():
            parts = [part.strip() for part in line.split("|")]
            if len(parts) >= 3 and not line.startswith("#"):
                out[parts[0]] = (parts[1], parts[2])
    return out


def span_text(spans):
    if not spans:
        return ""
    return f"{min(a for a, _ in spans):06X}..{max(b for _, b in spans):06X}"


def coverage(target):
    """{section: (bytes placed from C objects, section size)}."""
    out = {}
    for section in SECTION_ORDER:
        start, end = target.bounds[section]
        # a C object places every variable as a piece of its own: count from its first piece to its last,
        # so that the alignment fill between two short variables is not taken for bytes left in assembly
        spans = {}
        for kind, address, size, path in target.placements:
            if kind == section and address and "/objects/src/" in path:
                low, high = spans.get(path, (address, address + size))
                spans[path] = (min(low, address), max(high, address + size))
        owned = sum(high - low for low, high in spans.values())
        if section == ".text":
            owned = end - GAME_START
        out[section] = (owned, end - start)
    return out


def write_doc(path):
    main, death = Target(TARGETS[0]), Target(TARGETS[1])
    starts = run_starts()
    evidence = read_evidence()
    functions = game_functions(TARGETS[0])
    addresses = [a for a, _ in functions]
    death_text = {unit["name"]: unit["text"] for unit in death.units}
    rows, counts = [], {"proven": 0, "assumed": 0}
    by_address = sorted(main.units, key=lambda unit: unit["text"])
    # a unit whose own table of routines starts with the unit's first function
    function_address = {main.symbols[n]: u for n, u in main.function_unit.items() if n in main.symbols}
    table_first = {}
    for site, address, _ in main.data_refs:
        owner = main.owner_of(site)
        if owner and function_address.get(address) == owner:
            table_first[owner] = min(table_first.get(owner, address), address)
    for index, unit in enumerate(by_address):
        name = unit["name"]
        short = name.split("/")[-1]
        end = by_address[index + 1]["text"] if index + 1 < len(by_address) else main.bounds[".text"][1]
        count = bisect.bisect_left(addresses, end) - bisect.bisect_left(addresses, unit["text"])
        if unit["text"] in starts:
            status, reason = "proven", "run boundary"
            if short in evidence and evidence[short][0] == "proven":
                reason += "; " + evidence[short][1]
        elif short in evidence:
            status, reason = evidence[short]
        elif table_first.get(name) == unit["text"]:
            status, reason = "proven", "first routine of the routine table at the start of its data"
        else:
            status, reason = "assumed", ""
        counts[status] = counts.get(status, 0) + 1
        placed = main.placed.get(name, {})
        cells = [span_text(placed.get(section)) for section in SECTION_ORDER[1:]]
        rows.append(f"| `{short}` | {unit['text']:06X}..{end:06X} | {death_text.get(name, 0):06X} | {count} | "
                    f"{status} | {reason} | " + " | ".join(cells) + " |")
    death_only = [unit for unit in death.units if unit["name"] not in {u["name"] for u in main.units}]
    data_only = sorted(set(main.placed) - {unit["name"] for unit in main.units})
    lines = [
        "# Translation Unit Map (`SLPS_252.33` / `DEATH.ELF`)",
        "",
        "Generated by `uv run tools/unitmap.py --doc <path>` from the link maps (`uv run tools/build.py --map`)",
        "and the two `splat.yaml` files. Do not edit by hand: regenerate after changing units.",
        "",
        "## How to read it",
        "",
        "- **text**: the unit's code in the main executable; **Death text**: where the same unit starts in Death Label.",
        "- **start**: how sure the unit's first function is. `proven` means binary evidence: a *run boundary* (the function",
        "  before it in the main executable is not the function before it in Death Label, so the two cannot be one object),",
        "  or the reason given. `assumed` means the cut was placed from weaker evidence and may be off by a routine.",
        "- **.rodata .data .sdata .sbss .bss**: the stretch of each section the unit defines in C today (main executable",
        "  addresses). Empty means the unit has nothing there or its data is still assembly.",
        "",
        "## Counts",
        "",
        f"- Units: {len(main.units)} in the main executable, {len(death.units)} in Death Label "
        f"({len(death_only)} only there).",
        f"- Unit starts proven: {counts.get('proven', 0)}; assumed: {counts.get('assumed', 0)}.",
        f"- Files still named by address: "
        f"{sum(1 for u in death.units + main.units if re.search(r'(unit|func)_[0-9A-F]{8}$', u['name'])) and len({u['name'] for u in death.units + main.units if re.search(r'(unit|func)_[0-9A-F]{8}$', u['name'])})}.",
        "",
        "Bytes of each section defined in C:",
        "",
        "| Section | Main in C | Main size | | Death Label in C | Death Label size | |",
        "| --- | ---: | ---: | ---: | ---: | ---: | ---: |",
    ]
    cover_main, cover_death = coverage(main), coverage(death)
    for section in SECTION_ORDER:
        a, b = cover_main[section]
        c, d = cover_death[section]
        lines.append(f"| `{section}` | {a:,} | {b:,} | {100 * a / b:.1f}% | {c:,} | {d:,} | {100 * c / d:.1f}% |")
    lines += [
        "",
        "`.text` includes the SDK libraries (assembly, `0x100000..0x119B10`); all game code is C.",
        "",
        "## Units in link order of the main executable",
        "",
        "| Unit | text | Death text | functions | start | evidence | .data | .rodata | .sdata | .sbss | .bss |",
        "| --- | --- | --- | ---: | --- | --- | --- | --- | --- | --- | --- |",
    ] + rows
    if data_only:
        lines += ["", "## Table files (no code)", "", "| File | .data | .rodata | .sdata |", "| --- | --- | --- | --- |"]
        for name in data_only:
            placed = main.placed[name]
            lines.append(f"| `{name.split('/')[-1]}` | " + " | ".join(span_text(placed.get(s)) for s in (".data", ".rodata", ".sdata")) + " |")
    if death_only:
        lines += ["", "## Units only Death Label has", "", "| Unit | Death text |", "| --- | --- |"]
        lines += [f"| `{unit['name'].split('/')[-1]}` | {unit['text']:06X} |" for unit in death_only]
    (ROOT / path).write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(f"{path}: {len(rows)} units, {counts}")


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--target", default="SLPS_252.33")
    parser.add_argument("--doc")
    parser.add_argument("--runs")
    parser.add_argument("--unit")
    parser.add_argument("--json")
    args = parser.parse_args()
    if args.doc:
        write_doc(args.doc)
        return
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
