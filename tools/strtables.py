#!/usr/bin/env python3
"""Write a unit's tables of text as tables of string literals, inside the unit.

A PS2-native unit that has tables of messages was compiled from definitions like
`char *messages[] = { "...", "..." };`: the pointers are in `.data` (or `.sdata` for objects of up to
eight bytes) and the literals in `.rodata`, in the order the source mentions them, in front of the
literals of the unit's code.  The first pass left such a unit with three generated files beside it
(`<unit>_data.c`, `<unit>_small_data.c`, `<unit>_text.c`).  This tool reads both retail executables,
rebuilds the definitions in source order and puts them at the top of the unit:

    uv run tools/strtables.py [--dry] UNIT [--data NAME] [--sdata NAME] [--text NAME]

UNIT is the path below `src/` without `.c` (`game/memcard`).  The three block names default to
`<UNIT>_data`, `<UNIT>_small_data` and `<UNIT>_text`.  The tool stops without writing when the
literals, taken in order of first use, would not reproduce the text block of both executables.
"""
import argparse
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TARGETS = ("SLPS_252.33", "DEATH.ELF")
LOAD = 0x100000 - 0x80          # vram of file offset 0
INT_TYPES = {"s32": 4, "u32": 4, "int": 4, "s16": 2, "u16": 2, "s8": 1, "u8": 1, "char": 1}


class Image:
    def __init__(self, target):
        self.target = target
        self.rom = (ROOT / "baserom" / target).read_bytes()
        self.yaml = (ROOT / "config" / target / "splat.yaml").read_text()
        self.entries = [(int(m.group(1), 16), m.group(2), m.group(3))
                        for m in re.finditer(r"- \[0x([0-9a-f]+), ([.\w]+)(?:, ([\w/]+))?\]", self.yaml)]
        self.names = {}          # address -> [names]
        self.address = {}
        for line in (ROOT / "build" / f"{target}.map").read_text().splitlines():
            m = re.match(r"^\s+0x([0-9a-f]{8,16})\s+([A-Za-z_]\w*)(?: = 0x[0-9a-f]+)?$", line)
            if m and m.group(2) not in self.address:
                self.address[m.group(2)] = int(m.group(1), 16)
                self.names.setdefault(int(m.group(1), 16), []).append(m.group(2))

    def block(self, kind, name):
        for i, (off, k, n) in enumerate(self.entries):
            if k == kind and n == name:
                return off + LOAD, self.entries[i + 1][0] + LOAD
        return None

    def word(self, address):
        return struct.unpack_from("<I", self.rom, address - LOAD)[0]

    def data(self, address, size):
        return self.rom[address - LOAD:address - LOAD + size]

    def string(self, address):
        end = self.rom.index(b"\0", address - LOAD)
        return self.rom[address - LOAD:end]


def literal(raw, zeros=0):
    """C spelling of the bytes of a string, with `zeros` more zero bytes written out after it."""
    if zeros:
        text = literal(raw)
        return text[:text.rindex('"')] + "\\0" * zeros + text[text.rindex('"'):]
    if re.fullmatch(rb"[\x20-\x7e\n]*", raw):
        return '"%s"' % raw.decode("ascii").replace("\\", "\\\\").replace('"', '\\"').replace("\n", "\\n")
    try:
        text = raw.decode("cp932")
        if text.encode("cp932") == raw and not any(ord(c) < 0x20 and c != "\n" for c in text) \
                and not any(0xFF61 <= ord(c) <= 0xFF9F for c in text):
            return 'SJIS("%s")' % text.replace("\\", "\\\\").replace('"', '\\"').replace("\n", "\\n")
    except UnicodeError:
        pass
    return '"%s"' % "".join("\\x%02X" % b for b in raw)


def float_text(raw):
    value = struct.unpack("<f", raw)[0]
    for digits in range(1, 10):
        text = "%.*g" % (digits, value)
        if struct.pack("<f", float(text)) == raw:
            break
    if "." not in text and "e" not in text:
        text += ".0"
    return text + "f"


def align_of(size, small):
    if small:
        return 8 if size > 4 else 4
    return 16 if size >= 16 else 8


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("unit")
    ap.add_argument("--data")
    ap.add_argument("--sdata")
    ap.add_argument("--text")
    ap.add_argument("--split", action="append", default=[], help="label that starts an object of its own")
    ap.add_argument("--join", action="append", default=[], help="label that lies inside the object before it")
    ap.add_argument("--type", action="append", default=[], help="NAME:TYPE[:COUNT] for an object of numbers")
    ap.add_argument("--dry", action="store_true")
    args = ap.parse_args()
    unit = args.unit
    forced = {}
    for spec in args.type:
        parts = spec.split(":")
        forced[parts[0]] = (parts[1], int(parts[2], 0) if len(parts) > 2 else None)
    interior = {}                # label inside an object -> (object, byte offset)
    blocks = {".data": args.data or unit + "_data", ".sdata": args.sdata or unit + "_small_data",
              ".rodata": args.text or unit + "_text"}
    images = [Image(t) for t in TARGETS]
    main_image, death = images
    source_path = ROOT / "src" / (unit + ".c")
    source = source_path.read_text()

    text_range = [im.block(".rodata", blocks[".rodata"]) for im in images]
    if None in text_range:
        sys.exit("no text block " + blocks[".rodata"])

    # The objects of each section, by the labels of the main executable.
    objects = {}
    for kind in (".data", ".sdata"):
        rng = main_image.block(kind, blocks[kind])
        if rng is None:
            objects[kind] = []
            continue
        death_rng = death.block(kind, blocks[kind])
        labels = sorted(a for a in main_image.names if rng[0] <= a < rng[1])
        if not labels or labels[0] != rng[0]:
            sys.exit("%s block does not start on a label" % kind)
        # In .data a label with room for eight bytes or less is not an object of its own (those are in
        # .sdata): a run of such labels is one object, with the later labels inside it.
        def label_name(a):
            return ([n for n in main_image.names[a] if "_as_" not in n] or main_image.names[a])[0]
        bounds = labels + [rng[1]]
        starts = []
        for i, a in enumerate(labels):
            small = kind == ".data" and bounds[i + 1] - a <= 8
            name = label_name(a)
            inside = name in args.join or (small and i > 0 and bounds[i] - labels[i - 1] <= 8 and name not in args.split)
            if inside and starts:
                interior[name] = (label_name(starts[-1]), a - starts[-1])
            else:
                starts.append(a)
        labels = starts
        items = []
        for i, a in enumerate(labels):
            names = [n for n in main_image.names[a] if "_as_" not in n] or main_image.names[a]
            name = names[0]
            if name not in death.address:
                sys.exit("%s has no address in Death Label" % name)
            items.append({"name": name, "kind": kind, "addr": (a, death.address[name]),
                          "room": (labels[i + 1] if i + 1 < len(labels) else rng[1]) - a})
        for i, it in enumerate(items):
            nxt = items[i + 1]["addr"][1] if i + 1 < len(items) else death_rng[1]
            if nxt - it["addr"][1] != it["room"]:
                sys.exit("%s: room differs between the executables" % it["name"])
        objects[kind] = items

    # Decode every object.
    for kind, items in objects.items():
        for it in items:
            words = []
            whole = it["room"] % 4 == 0
            for k in range(0, it["room"] - it["room"] % 4, 4):
                v = [im.word(it["addr"][j] + k) for j, im in enumerate(images)]
                if all(text_range[j][0] <= v[j] < text_range[j][1] for j in range(2)):
                    s = [im.string(v[j]) for j, im in enumerate(images)]
                    if s[0] != s[1]:
                        sys.exit("%s+%#x: the two executables point at different text" % (it["name"], k))
                    words.append(("str", v[0], s[0], v[1]))
                elif v[0] == v[1]:
                    words.append(("num", v[0]))
                else:
                    target = [n for n in main_image.names.get(v[0], []) if "_as_" not in n]
                    if not target or death.address.get(target[0]) != v[1]:
                        sys.exit("%s+%#x: words %#x / %#x are neither text nor the same number" % (it["name"], k, v[0], v[1]))
                    words.append(("sym", target[0]))
            it["words"] = words
            it["raw"] = main_image.data(it["addr"][0], it["room"])
            if it["raw"] != death.data(it["addr"][1], it["room"]) and not any(w[0] != "num" for w in words):
                sys.exit("%s differs between the executables" % it["name"])
            it["has_ptr"] = any(w[0] != "num" for w in words)
            if it["has_ptr"] and not whole:
                sys.exit("%s: pointers in an object of odd size" % it["name"])

    # Sizes: trailing zeros are dropped where the alignment of the next object puts them back.
    for kind, items in objects.items():
        small = kind == ".sdata"
        for i in range(len(items) - 1, -1, -1):
            it = items[i]
            if i + 1 < len(items):
                next_align = align_of(items[i + 1]["size"], small)
            else:
                next_align = 4 if small else 8
            if it["has_ptr"]:
                unit_size = 4
            elif it["name"] in forced:
                it["ctype"], count = forced[it["name"]]
                unit_size = 4 if it["ctype"] == "float" else INT_TYPES[it["ctype"]]
                if count is not None:
                    it["size"] = count * unit_size
                    continue
            else:
                m = re.search(r"extern (\w+) (?:\*)?%s(?:_as_\w+)?\b" % it["name"], source)
                it["ctype"] = m.group(1) if m and m.group(1) in INT_TYPES else "u8"
                unit_size = INT_TYPES[it["ctype"]]
                body = it["raw"].rstrip(b"\0")
                if len(body) >= 3 and re.fullmatch(rb"[\x20-\x7e]+", body):
                    it["ctype"] = "string"
                    unit_size = 1
            size = it["room"]
            end = it["addr"][0] + it["room"]
            while size > unit_size:
                smaller = size - unit_size
                if any(it["raw"][smaller:size]):
                    break
                if it.get("ctype") == "string" and smaller < len(it["raw"].rstrip(b"\0")) + 1:
                    break
                start = it["addr"][0] + smaller
                if (start + next_align - 1) // next_align * next_align != end:
                    break
                # the object's own alignment must not change where it starts
                size = smaller
            if align_of(size, small) != align_of(it["room"], small) and it["addr"][0] % align_of(it["room"], small) == 0 \
                    and it["addr"][0] % align_of(size, small) != 0:
                size = it["room"]
            it["size"] = size

    # Source order: the two sections interleave by the text they mention first.
    queues = {k: list(v) for k, v in objects.items()}
    order = []

    def key(it):
        strs = [w[1] for w in it["words"] if w[0] == "str"]
        return min(strs) if strs else None

    while queues[".data"] or queues[".sdata"]:
        heads = [q[0] for q in (queues[".data"], queues[".sdata"]) if q]
        free = [h for h in heads if key(h) is None]
        pick = free[0] if free else min(heads, key=key)
        queues[pick["kind"]].remove(pick)
        order.append(pick)

    seen = {}
    sequence = []
    for it in order:
        for w in it["words"][:it["size"] // 4] if it["has_ptr"] else []:
            if w[0] == "str" and w[1] not in seen:
                seen[w[1]] = w
                sequence.append(w)
    problems = []
    padded = {}
    for j in range(2):
        pos = text_range[j][0]
        for w in sequence:
            address = w[1] if j == 0 else w[3]
            size = len(w[2]) + 1
            al = 16 if size >= 16 else 8 if size > 4 else 4
            expect = (pos + al - 1) // al * al
            if expect != address and size <= 4 and (pos + 7) // 8 * 8 == address:
                # A literal of up to four bytes is aligned to 4; this one is on 8, so it was longer:
                # it is written with zeros after it up to five bytes.
                padded[w[2]] = 5 - size
                expect = address
                size = 5
            if expect != address:
                problems.append("%s: text at %#x, expected at %#x" % (TARGETS[j], address, expect))
                break
            pos = address + size
        else:
            if (pos + 7) // 8 * 8 > text_range[j][1] or text_range[j][1] - pos >= 16:
                problems.append("%s: text ends at %#x, block at %#x" % (TARGETS[j], pos, text_range[j][1]))
    contents = {}
    for w in sequence:
        if w[2] in contents:
            problems.append("the text at %#x is repeated at %#x" % (contents[w[2]], w[1]))
        contents[w[2]] = w[1]
    for p in problems:
        print("problem:", p)

    # The definitions.
    out = []
    for it in order:
        name = it["name"]
        if it["has_ptr"]:
            count = it["size"] // 4
            lines = []
            for w in it["words"][:count]:
                if w[0] == "str":
                    lines.append("    %s," % literal(w[2], padded.get(w[2], 0)))
                elif w[0] == "sym":
                    lines.append("    (char *)%s," % w[1])
                elif w[1] == 0:
                    lines.append("    NULL,")
                else:
                    sys.exit("%s: a number among the pointers (%#x)" % (name, w[1]))
            if count == 1:
                out.append("char *%s = %s;\n" % (name, lines[0].strip().rstrip(",")))
            else:
                out.append("char *%s[%d] = {\n%s\n};\n" % (name, count, "\n".join(lines)))
        elif it["ctype"] == "string":
            body = it["raw"].rstrip(b"\0")
            out.append("char %s[%d] = %s;\n" % (name, it["size"], literal(body)))
        elif it["ctype"] == "float":
            values = [float_text(it["raw"][k:k + 4]) for k in range(0, it["size"], 4)]
            rows = ["    " + ", ".join(values[k:k + 4]) + "," for k in range(0, len(values), 4)]
            out.append("float %s[%d] = {\n%s\n};\n" % (name, len(values), "\n".join(rows)))
        else:
            width = INT_TYPES[it["ctype"]]
            fmt = {1: "B", 2: "H", 4: "I"}[width]
            values = struct.unpack_from("<%d%s" % (it["size"] // width, fmt), it["raw"])
            per = 16 if width == 1 else 8
            rows = ["    " + ", ".join(("0x%0*X" % (2 if width == 1 or v < 256 else width * 2, v)) if v > 9 else str(v) for v in values[k:k + per]) + ","
                    for k in range(0, len(values), per)]
            out.append("%s %s[%d] = {\n%s\n};\n" % (it["ctype"], name, len(values), "\n".join(rows)))
    block = "\n".join(out)
    if args.dry or problems:
        print(block)
        print("objects: %d in .data, %d in .sdata; %d strings" % (len(objects[".data"]), len(objects[".sdata"]), len(sequence)))
        if problems:
            sys.exit(1)
        return

    # Write: the definitions after the unit's includes, the unit's own declarations of them removed.
    defined = [it["name"] for it in order]
    lines = source.split("\n")
    last_include = max(i for i, l in enumerate(lines[:80]) if l.startswith("#include"))
    kept = []
    for i, l in enumerate(lines):
        m = re.match(r"^\s*extern [^;(]*?\b(\w+)(?:\[[^\]]*\])*;", l)
        if m and m.group(1) in defined:
            continue
        kept.append(l)
        if i == last_include:
            kept.append("")
            kept.extend(block.rstrip("\n").split("\n"))
    text = "\n".join(kept)
    for name, (base, offset) in interior.items():
        text = re.sub(r"^\s*extern [^;(]*?\b%s(?:\[[^\]]*\])*;\n" % name, "", text, flags=re.M)
        text, n = re.subn(r"\b%s\[0\]" % name, "%s[%d]" % (base, offset // 4), text)
        if re.search(r"\b%s\b" % name, text):
            print("note: %s (inside %s) is still used by name" % (name, base))
    source_path.write_text(text)
    defined += [n for n in interior if not re.search(r"\b%s\b" % n, text)]

    for im in images:
        y = im.yaml
        for kind in (".data", ".sdata", ".rodata"):
            old = "%s, %s]" % (kind, blocks[kind])
            if old not in y:
                continue
            own = re.search(r"\n *- \[0x[0-9a-f]+, %s, %s\]" % (re.escape(kind), re.escape(unit)), y)
            if own:
                y = y.replace(own.group(0), "", 1)
            y = y.replace(old, "%s, %s]" % (kind, unit), 1)
        (ROOT / "config" / im.target / "splat.yaml").write_text(y)
        sym_path = ROOT / "config" / im.target / "symbols.txt"
        sym = sym_path.read_text().split("\n")
        sym = [l for l in sym if not (re.match(r"(\w+)\s*=", l) and re.match(r"(\w+)\s*=", l).group(1) in defined)]
        sym_path.write_text("\n".join(sym))
    for kind in blocks:
        p = ROOT / "src" / (blocks[kind] + ".c")
        if p.exists():
            p.unlink()
    print("wrote %d definitions into %s" % (len(order), source_path.relative_to(ROOT)))


if __name__ == "__main__":
    main()
