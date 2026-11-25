"""Pair compiled Main units with their exact Death Label twins.

Works from the compiled objects of every matched SLPS_252.33 unit: a unit's `.text` is looked up in the
retail DEATH.ELF with only its relocated fields masked, and each relocation then tells which Death Label
address the referenced Main symbol has. Writes build/pair/plan.json; nothing tracked is modified.
"""
import argparse
from collections import Counter, defaultdict
import json
import re
import struct
import subprocess

from common import BASEROM, ROOT, TARGETS, require_local, target_compiler
from build import OBJ_CACHE, unit_object
from split import load_splat_config, load_symbols, scan_asm_functions, split, target_layout, target_units

MAIN, DEATH = "SLPS_252.33", "DEATH.ELF"
R_32, R_26, R_HI16, R_LO16, R_GPREL16 = 2, 4, 5, 6, 7
PLAN = ROOT / "build" / "pair" / "plan.json"


def sext16(value):
    return value - 0x10000 if value & 0x8000 else value


def read_object(path):
    data = path.read_bytes()
    shoff, = struct.unpack_from("<I", data, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", data, 0x2e)
    headers = [struct.unpack_from("<10I", data, shoff + i * shentsize) for i in range(shnum)]

    def cstr(base, index):
        start = base + index
        return data[start:data.index(0, start)].decode("ascii")

    shstr = headers[shstrndx][4]
    names = [cstr(shstr, header[0]) for header in headers]
    sections = {}
    for index, (header, name) in enumerate(zip(headers, names)):
        if header[2] & 2 and header[5]:
            body = bytes(header[5]) if header[1] == 8 else data[header[4]:header[4] + header[5]]
            sections[index] = {"name": name, "data": body, "align": header[8], "nobits": header[1] == 8, "relocs": []}
    symtab = headers[names.index(".symtab")]
    strtab = headers[symtab[6]][4]
    symbols = []
    for name, value, size, info, _, shndx in struct.iter_unpack("<IIIBBH", data[symtab[4]:symtab[4] + symtab[5]]):
        symbols.append({"name": cstr(strtab, name), "value": value, "size": size, "type": info & 15,
                        "bind": info >> 4, "shndx": shndx})
    for header, name in zip(headers, names):
        if header[1] != 9 or header[7] not in sections:
            continue
        for offset, info in struct.iter_unpack("<II", data[header[4]:header[4] + header[5]]):
            sections[header[7]]["relocs"].append((offset, info & 0xff, info >> 8))
    # MWCC emits one .text per function; lay same-named sections out the way the linker will.
    first, moved = {}, {}
    for index in sorted(sections):
        section = sections[index]
        home = first.setdefault(section["name"], index)
        if home == index:
            continue
        target = sections[home]
        align = max(section["align"], 1)
        start = (len(target["data"]) + align - 1) // align * align
        target["data"] = target["data"] + bytes(start - len(target["data"])) + section["data"]
        target["relocs"] += [(offset + start, kind, sym) for offset, kind, sym in section["relocs"]]
        target["align"] = max(target["align"], section["align"])
        moved[index] = (home, start)
    for index in moved:
        del sections[index]
    for symbol in symbols:
        if symbol["shndx"] in moved:
            home, start = moved[symbol["shndx"]]
            symbol["shndx"], symbol["value"] = home, symbol["value"] + start
    for section in sections.values():
        section["relocs"].sort()
    return sections, symbols


def coarse(data):
    """Zero every field a relocation could touch, so both ELFs can be searched with one key."""
    out = bytearray(data)
    for i in range(0, len(out) - 3, 4):
        op = out[i + 3] >> 2
        if op in (2, 3):
            out[i] = out[i + 1] = out[i + 2] = 0
            out[i + 3] &= 0xfc
        elif op not in (0, 1, 4, 5, 6, 7, 16, 17, 18, 20, 21, 22, 23, 28):
            out[i] = out[i + 1] = 0
    return bytes(out)


RELOC_MASK = {R_32: 0xffffffff, R_26: 0x03ffffff, R_HI16: 0xffff, R_LO16: 0xffff, R_GPREL16: 0xffff}


def masked_equal(ours, theirs, relocs):
    if len(ours) != len(theirs):
        return False
    a, b = bytearray(ours), bytearray(theirs)
    for offset, kind, _ in relocs:
        mask = RELOC_MASK.get(kind)
        if mask is None:
            return False
        keep = struct.pack("<I", ~mask & 0xffffffff)
        for i in range(4):
            a[offset + i] &= keep[i]
            b[offset + i] &= keep[i]
    return a == b


def site_values(ours, theirs, relocs, gp):
    """[(symbol index, S_death + addend_free value)] : the Death Label address each relocation implies."""
    word = lambda buf, off: struct.unpack_from("<I", buf, off)[0]
    out = []
    lows = [(offset, sym) for offset, kind, sym in relocs if kind == R_LO16]
    for offset, kind, sym in relocs:
        m, d = word(ours, offset), word(theirs, offset)
        if kind == R_26:
            out.append((sym, ((d & 0x3ffffff) << 2) - ((m & 0x3ffffff) << 2)))
        elif kind == R_32:
            out.append((sym, (d - m) & 0xffffffff))
        elif kind == R_GPREL16:
            out.append((sym, sext16(d & 0xffff) + gp - sext16(m & 0xffff)))
        elif kind == R_HI16:
            low = next((o for o, s in lows if s == sym and o > offset), None)
            if low is None:
                low = next((o for o, s in reversed(lows) if s == sym), None)
            if low is None:
                continue
            m_ahl = ((m & 0xffff) << 16) + sext16(word(ours, low) & 0xffff)
            d_ahl = ((d & 0xffff) << 16) + sext16(word(theirs, low) & 0xffff)
            out.append((sym, d_ahl - m_ahl))
    return out


def load_main_units(local):
    version = target_compiler(MAIN, local)
    units = []
    for unit in target_units(MAIN):
        obj = unit_object(version, MAIN, unit["source"])
        sections, symbols = read_object(obj)
        unit = dict(unit, sections=sections, symbols=symbols)
        by_name = {section["name"]: index for index, section in sections.items()}
        unit["text"] = by_name[".text"]
        unit["other"] = {name: index for name, index in by_name.items() if name != ".text"}
        units.append(unit)
    return units


def death_image():
    data = (BASEROM / DEATH).read_bytes()
    file_address, load_offset, code_end = target_layout(DEATH)
    config = load_splat_config(DEATH)
    return data, file_address, code_end, int(config["options"]["gp_value"])


def find_candidates(unit, image, coarse_text, file_address, text_start, code_end):
    text = unit["sections"][unit["text"]]
    key = coarse(text["data"])
    hits = []
    start = text_start - file_address
    while True:
        pos = coarse_text.find(key, start)
        if pos < 0 or pos + file_address >= code_end:
            break
        if pos % 16 == 0 and masked_equal(text["data"], image[pos:pos + len(key)], text["relocs"]):
            hits.append(pos + file_address)
        start = pos + 4
    return hits


def unit_constraints(unit, base, image, file_address, gp):
    """Symbol values this placement implies: ({name: {value: sites}}, {section name: {base: sites}})."""
    text = unit["sections"][unit["text"]]
    theirs = image[base - file_address:base - file_address + len(text["data"])]
    externs, locals_ = defaultdict(Counter), defaultdict(Counter)
    for sym_index, value in site_values(text["data"], theirs, text["relocs"], gp):
        symbol = unit["symbols"][sym_index]
        if symbol["shndx"] == 0:
            externs[symbol["name"]][value] += 1
        elif symbol["shndx"] == unit["text"]:
            if value - symbol["value"] != base:
                externs["@text"][value] += 1
        elif symbol["shndx"] in unit["sections"]:
            locals_[unit["sections"][symbol["shndx"]]["name"]][value - symbol["value"]] += 1
    return externs, locals_


def verify_sections(unit, placement, image, file_address, gp, bss_start):
    """Check a unit's non-.text sections at their implied Death Label addresses; returns (bases, problems, externs)."""
    bases, problems, externs = {}, [], defaultdict(Counter)
    for name, index in unit["other"].items():
        section = unit["sections"][index]
        votes = placement["locals"].get(name)
        if not votes:
            problems.append(f"{name}: unreferenced, address unknown")
            continue
        if len(votes) > 1:
            problems.append(f"{name}: {len(votes)} different addresses")
            continue
        base = next(iter(votes))
        bases[name] = base
        if section["nobits"]:
            if base < bss_start and name in (".bss", ".sbss"):
                problems.append(f"{name}: {base:#x} is not in bss")
            continue
        theirs = image[base - file_address:base - file_address + len(section["data"])]
        if not masked_equal(section["data"], theirs, section["relocs"]):
            problems.append(f"{name}: contents differ at {base:#x}")
            continue
        end = base - file_address + len(section["data"])
        if base % 16 or any(image[end:(end + 15) & ~15]):
            problems.append(f"{name}: shares its 16-byte block at {base:#x} with another unit's data")
            continue
        for sym_index, value in site_values(section["data"], theirs, section["relocs"], gp):
            symbol = unit["symbols"][sym_index]
            if symbol["shndx"] == 0:
                externs[symbol["name"]][value] += 1
            elif symbol["shndx"] == unit["text"]:
                if value - symbol["value"] != placement["base"]:
                    problems.append(f"{name}: jump table points outside the unit")
            elif unit["sections"][symbol["shndx"]]["name"] != name or value != base:
                problems.append(f"{name}: unexpected local reference")
    return bases, problems, externs


def pair(local):
    units = load_main_units(local)
    image, file_address, code_end, gp = death_image()
    death_units_start = 0x119B10
    coarse_text = coarse(image[:code_end - file_address])
    main_symbols = load_symbols(MAIN)
    config = load_splat_config(DEATH)
    main_seg = next(seg for seg in config["segments"] if isinstance(seg, dict) and seg.get("name") == "main")
    bss_start = file_address + len(image) - 0  # refined below from the last subsegment
    for sub in main_seg["subsegments"]:
        if isinstance(sub, list) and len(sub) >= 2 and sub[1] in ("bss", ".bss", "sbss", ".sbss"):
            bss_start = file_address + int(sub[0])
            break

    starts = {address for address, _ in scan_asm_functions(split(DEATH) / "asm").values()}
    starts.update(unit["address"] for unit in target_units(DEATH))
    candidates = {}
    for unit in units:
        hits = find_candidates(unit, image, coarse_text, file_address, death_units_start, code_end)
        candidates[unit["stub"]] = [hit for hit in hits if hit in starts]

    by_stub = {unit["stub"]: unit for unit in units}
    func_owner = {}
    for unit in units:
        for symbol in unit["symbols"]:
            if symbol["type"] == 2 and symbol["shndx"] == unit["text"] and symbol["bind"] == 1:
                func_owner[symbol["name"]] = (unit["stub"], symbol["value"])

    def unit_functions(unit):
        return [s for s in unit["symbols"] if s["type"] == 2 and s["shndx"] == unit["text"] and s["bind"] == 1]

    placed, reject_reason = {}, {}

    def tally():
        """Addresses the relocations of every placed unit ask for; a unit's own definitions only count unopposed."""
        votes = defaultdict(Counter)
        for placement in placed.values():
            for name, sites in placement["externs"].items():
                if name != "@text":
                    votes[name].update(sites)
        for stub, placement in placed.items():
            for symbol in unit_functions(by_stub[stub]):
                if symbol["name"] not in votes:
                    votes[symbol["name"]][placement["base"] + symbol["value"]] += 1
        return votes

    def place(stub, base):
        externs, locals_ = unit_constraints(by_stub[stub], base, image, file_address, gp)
        placed[stub] = {"base": base, "externs": externs, "locals": locals_}

    def fits(stub, base, votes):
        unit = by_stub[stub]
        for symbol in unit_functions(unit):
            known = votes.get(symbol["name"])
            if known and known.most_common(1)[0][0] != base + symbol["value"]:
                return f"callers expect {symbol['name']} at {known.most_common(1)[0][0]:#x}"
        externs, _ = unit_constraints(unit, base, image, file_address, gp)
        for name, sites in externs.items():
            known = votes.get(name)
            if name != "@text" and known and known.most_common(1)[0][0] not in sites:
                return f"{name}: {next(iter(sites)):#x} here, {known.most_common(1)[0][0]:#x} elsewhere"
        return None

    pending = {}
    for stub, hits in candidates.items():
        if len(hits) == 1:
            place(stub, hits[0])
        elif hits:
            pending[stub] = list(hits)

    order = sorted(units, key=lambda u: u["address"])
    for _ in range(50):
        changed = False
        votes = tally()
        # A placed unit that the rest of the program disagrees with is not a twin after all.
        for stub in list(placed):
            reason = fits(stub, placed[stub]["base"], votes)
            if reason is not None:
                del placed[stub]
                reject_reason[stub] = reason
                changed = True
        votes = tally()
        taken = {placement["base"] for placement in placed.values()}
        for stub in sorted(pending, key=lambda s: by_stub[s]["address"]):
            hits = [hit for hit in pending[stub] if hit not in taken and fits(stub, hit, votes) is None]
            wanted = [hit for hit in hits
                      if any(votes.get(s["name"]) for s in unit_functions(by_stub[stub]))]
            if len(hits) == 1 or len(wanted) == 1:
                base = (wanted or hits)[0]
                place(stub, base)
                taken.add(base)
                del pending[stub]
                changed = True
            elif not hits:
                reject_reason[stub] = "every candidate conflicts"
                del pending[stub]
                changed = True
            else:
                pending[stub] = hits
        if not changed:
            break

    # Whatever is still ambiguous (runs of identical stubs) keeps its distance to a placed link-order neighbour.
    taken = {placement["base"] for placement in placed.values()}
    for sequence in (order, order[::-1]):
        for i, unit in enumerate(sequence):
            stub = unit["stub"]
            if stub not in pending or i == 0 or sequence[i - 1]["stub"] not in placed:
                continue
            neighbour = sequence[i - 1]
            base = placed[neighbour["stub"]]["base"] + unit["address"] - neighbour["address"]
            if base in pending[stub] and base not in taken:
                place(stub, base)
                taken.add(base)
                del pending[stub]
    for stub in pending:
        reject_reason[stub] = "ambiguous"

    # Two Main units cannot share Death Label bytes: the earlier claim in link order keeps them.
    end = 0
    for stub, placement in sorted(placed.items(), key=lambda kv: (kv[1]["base"], by_stub[kv[0]]["address"])):
        if placement["base"] < end:
            del placed[stub]
            reject_reason[stub] = "overlaps another twin"
        else:
            end = placement["base"] + len(by_stub[stub]["sections"][by_stub[stub]["text"]]["data"])

    values = tally()
    resolved = {name: votes.most_common(1)[0][0] for name, votes in values.items()}
    plan_units, rejected = [], []
    for unit in order:
        stub = unit["stub"]
        entry = {"stub": stub, "source": unit["source"], "main_address": unit["address"], "span": unit["span"]}
        if stub not in placed:
            entry["reason"] = "no exact twin" if not candidates[stub] else reject_reason.get(stub, "ambiguous")
            entry["candidates"] = candidates[stub][:8]
            rejected.append(entry)
            continue
        placement = placed[stub]
        bases, problems, extra = verify_sections(unit, placement, image, file_address, gp, bss_start)
        for name, votes in list(placement["externs"].items()) + list(extra.items()):
            if name == "@text":
                problems.append("text: local reference resolves outside the unit")
            elif len(votes) > 1:
                problems.append(f"{name}: {len(votes)} addresses inside the unit")
            elif next(iter(votes)) != resolved.get(name, next(iter(votes))):
                problems.append(f"{name}: {next(iter(votes)):#x} here, {resolved[name]:#x} elsewhere")
        for name, votes in extra.items():
            if name not in resolved and len(votes) == 1:
                resolved[name] = next(iter(votes))
        entry.update(death_address=placement["base"], size=len(unit["sections"][unit["text"]]["data"]),
                     sections={name: base for name, base in bases.items()},
                     section_sizes={name: len(unit["sections"][index]["data"]) for name, index in unit["other"].items()},
                     functions={s["name"]: placement["base"] + s["value"] for s in unit["symbols"]
                                if s["type"] == 2 and s["shndx"] == unit["text"]},
                     function_sizes={s["name"]: s["size"] for s in unit["symbols"]
                                     if s["type"] == 2 and s["shndx"] == unit["text"] and s["size"]},
                     externs=sorted(n for n in placement["externs"] if n != "@text") + sorted(extra))
        if problems:
            entry["reason"] = "; ".join(sorted(set(problems)))
            rejected.append(entry)
        else:
            plan_units.append(entry)

    splits = {name: sorted(votes.items(), key=lambda kv: -kv[1]) for name, votes in values.items() if len(votes) > 1}
    return {
        "units": plan_units,
        "rejected": rejected,
        "symbols": {name: resolved[name] for name in sorted(resolved)},
        "conflicts": {name: [[value, count] for value, count in votes] for name, votes in sorted(splits.items())},
        "main_symbols": {name: main_symbols[name][0] for name in resolved if name in main_symbols},
    }


SUBSEG_RE = re.compile(r"^(\s*-\s*\[)(0x[0-9a-fA-F]+|\d+),\s*(\.?[a-zA-Z0-9_]+)(?:,\s*([^\]]+))?\]\s*$")
AUTO_RE = re.compile(r"(func|D)_[0-9A-F]{8}")
LABEL_RE = re.compile(r"^(?:glabel|dlabel|jlabel|alabel|nonmatching)\s+(\w+)", re.M)


def death_auto_labels():
    """Placeholder names Splat gave Death Label addresses it has no symbol for."""
    names = set()
    for path in (split(DEATH) / "asm").rglob("*.s"):
        names.update(name for name in LABEL_RE.findall(path.read_text(encoding="utf-8")) if AUTO_RE.fullmatch(name))
    return names


def shared_stub(stub):
    return "game/" + stub.split("/", 1)[1]


def patch_death_text(lines, units, image, file_address, code_end):
    rows = [(i, SUBSEG_RE.match(line)) for i, line in enumerate(lines)]
    rows = [(i, m) for i, m in rows if m]
    first, last = rows[0][0], rows[-1][0]
    if last - first + 1 != len(rows):
        raise ValueError("DEATH.ELF splat.yaml: subsegment list is not contiguous")
    prefix = rows[0][1].group(1)
    # A subsegment without a name (`[offset, pad]`) is kept as it is.
    subs = [[int(m.group(2), 0), m.group(3), (m.group(4) or "").strip()] for _, m in rows]
    names = {sub[2] for sub in subs if sub[2]}
    code_end_off = code_end - file_address
    for unit in sorted(units, key=lambda u: u["death_address"]):
        offset = unit["death_address"] - file_address
        end = offset + unit["size"]
        padded = (end + 15) & ~15
        if padded <= code_end_off and not any(image[end:padded]):
            end = padded
        for index, (seg_off, seg_type, seg_name) in enumerate(subs):
            next_off = subs[index + 1][0] if index + 1 < len(subs) else code_end_off
            if seg_type == "asm" and seg_off <= offset and end <= next_off:
                break
        else:
            raise ValueError(f"DEATH.ELF: no asm subsegment contains {unit['death_address']:#x}")
        replacement = []
        if offset > seg_off:
            replacement.append([seg_off, "asm", seg_name])
        replacement.append([offset, "c", shared_stub(unit["stub"])])
        if end < next_off:
            name, counter = f"game_{end:06x}", 0
            while name in names:
                counter += 1
                name = f"game_{end:06x}_{counter}"
            names.add(name)
            replacement.append([end, "asm", name])
        subs[index:index + 1] = replacement
    lines[first:last + 1] = [f"{prefix}{off:#x}, {kind}, {name}]" if name else f"{prefix}{off:#x}, {kind}]"
                             for off, kind, name in subs]


def apply(local, only=None):
    from integrate import patch_splat_rodata
    plan = pair(local)
    units = [u for u in plan["units"] if u["stub"].startswith("main/") and (only is None or u["stub"] in only)]
    image, file_address, code_end, _ = death_image()
    death_symbols = load_symbols(DEATH)
    by_address = defaultdict(list)
    for name, (address, _) in death_symbols.items():
        by_address[address].append(name)

    needed = {}
    for unit in units:
        for name, address in unit["functions"].items():
            needed[name] = (address, True)
        for name in unit["externs"]:
            needed.setdefault(name, (plan["symbols"][name], False))
    function_names = set(load_symbols(MAIN)) | {n for u in plan["units"] + plan["rejected"] for n in u.get("functions", {})}
    sizes = {}
    for unit in units:
        obj_unit = None
        sizes.update(unit.get("function_sizes", {}))
    additions, clashes, claimed = [], [], {}
    for name, (address, defined) in sorted(needed.items(), key=lambda kv: (kv[1][0], not kv[1][1], kv[0])):
        if name in death_symbols:
            if death_symbols[name][0] != address:
                clashes.append(f"{name}: symbols.txt has {death_symbols[name][0]:#x}, the twins need {address:#x}")
            claimed.setdefault(address, name)
            continue
        size = sizes.get(name)
        is_func = defined or address < code_end
        notes = [f"type:func size:{size:#x}" if size else "type:func"] if is_func else []
        if address in claimed:
            notes.append("ignore:true")
        claimed.setdefault(address, name)
        additions.append(f"{name} = {address:#x};" + (" // " + " ".join(notes) if notes else ""))
    if clashes:
        raise ValueError("\n".join(clashes))

    # A Death Label placeholder spelled like a Main name for another address would be mistaken for it.
    stale, renames = set(), []
    for name, (address, _) in death_symbols.items():
        if AUTO_RE.fullmatch(name) and int(name.split("_")[1], 16) == address and claimed.get(address, name) != name:
            stale.add(name)
    for name in sorted(death_auto_labels()):
        address = int(name.split("_")[1], 16)
        if name in needed and needed[name][0] != address and address not in claimed and not by_address.get(address):
            kind = " // type:func" if name.startswith("func_") else ""
            renames.append(f"death_{name} = {address:#x};{kind}")

    death_yaml = ROOT / "config" / DEATH / "splat.yaml"
    lines = death_yaml.read_text(encoding="utf-8").splitlines()
    patch_death_text(lines, units, image, file_address, code_end)
    death_yaml.write_text("\n".join(lines) + "\n", encoding="utf-8")
    for unit in units:
        for name, base in unit["sections"].items():
            if name != ".rodata":
                raise ValueError(f"{unit['stub']}: {name} is not handled")
            patch_splat_rodata(DEATH, base - file_address, unit["section_sizes"][name], shared_stub(unit["stub"]))

    sym_file = ROOT / "config" / DEATH / "symbols.txt"
    kept = [line for line in sym_file.read_text(encoding="utf-8").splitlines()
            if not ((match := re.match(r"\s*(\w+)\s*=", line)) and match.group(1) in stale)]
    sym_file.write_text("\n".join(kept + additions + renames) + "\n", encoding="utf-8")

    main_yaml = ROOT / "config" / MAIN / "splat.yaml"
    text = main_yaml.read_text(encoding="utf-8")
    (ROOT / "src" / "game").mkdir(parents=True, exist_ok=True)
    for unit in units:
        stub = unit["stub"]
        text, count = re.subn(rf"(, (?:c|\.rodata), ){re.escape(stub)}\]", rf"\g<1>{shared_stub(stub)}]", text)
        if not count:
            raise ValueError(f"{stub}: not in the Main splat.yaml")
        subprocess.run(["git", "mv", f"src/{stub}.c", f"src/{shared_stub(stub)}.c"], cwd=ROOT, check=True)
    main_yaml.write_text(text, encoding="utf-8")
    print(f"moved {len(units)} units to src/game, {len(additions)} symbols added, {len(renames)} Death Label placeholders renamed")


def main():
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--output", default=str(PLAN))
    parser.add_argument("--apply", action="store_true", help="move the paired units to src/game and patch both configs")
    parser.add_argument("--only", help="with --apply, comma-separated Main stubs (e.g. main/func_00119B10)")
    args = parser.parse_args()
    if args.apply:
        apply(require_local(), set(args.only.split(",")) if args.only else None)
        return
    plan = pair(require_local())
    out = ROOT / args.output if not args.output.startswith("/") else __import__("pathlib").Path(args.output)
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(plan, indent=1) + "\n", encoding="utf-8")
    reasons = Counter(entry["reason"] if entry["reason"] in ("no exact twin", "ambiguous") else "conflict"
                      for entry in plan["rejected"])
    functions = sum(len(entry["functions"]) for entry in plan["units"])
    print(f"paired units: {len(plan['units'])} ({functions} functions, {sum(e['size'] for e in plan['units'])} B)")
    print(f"rejected: {dict(reasons)}")
    print(f"symbols: {len(plan['symbols'])}, with conflicting sites: {len(plan['conflicts'])}")
    print(out.relative_to(ROOT))


if __name__ == "__main__":
    main()
