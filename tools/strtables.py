#!/usr/bin/env python3
"""Write a unit's tables of text as tables of string literals, inside the unit.

A PS2-native unit that has tables of messages was compiled from definitions like
`char *messages[] = { "...", "..." };`: the pointers are in `.data` (or `.sdata` for objects of up to
eight bytes) and the literals in `.rodata`, in the order the source mentions them, with the literals
and jump tables of the code that stands between the definitions in between.  Identical literals are
one literal.  The first pass left such a unit with generated files beside it (`<unit>_data.c`,
`<unit>_small_data.c`, `<unit>_text.c`).  This tool reads those files for the shape of the objects
and both retail executables for their contents, rebuilds the definitions in source order and puts
them into the unit:

    uv run tools/strtables.py [--dry] UNIT [--data BLOCK] [--sdata BLOCK] --text BLOCK[@ANCHOR] ...

UNIT is the path below `src/` without `.c` (`game/memcard`).  The block names are the generated files
(default `<UNIT>_data`, `<UNIT>_small_data`, `<UNIT>_text`).  A unit can have several text blocks, with
code between them: `--text 'game/menu_text_b@/* The replay slot screens. */'` says that the tables
which first mention that block's text are defined in front of the line given (the first block's
tables go after the unit's includes, or at the line `/* Tables. */` if there is one).  The two
executables are decoded separately; an object that differs is written once per executable under
`#ifdef DEATH_LABEL`.  The tool stops without writing when the literals, taken in order of first use,
would not reproduce the text blocks.
"""
import argparse
import difflib
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TARGETS = ("SLPS_252.33", "DEATH.ELF")
LOAD = 0x100000 - 0x80          # vram of file offset 0
INT_TYPES = {"s32": 4, "u32": 4, "int": 4, "s16": 2, "u16": 2, "s8": 1, "u8": 1, "char": 1, "float": 4}
PACK = {1: "B", 2: "H", 4: "I"}


class Image:
    def __init__(self, target):
        self.target = target
        self.death = target == "DEATH.ELF"
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

    def name(self, address):
        names = self.names.get(address)
        if not names:
            return None
        return ([n for n in names if "_as_" not in n] or names)[0]


def view(text, death):
    """The lines of a source one executable sees (DEATH_LABEL conditionals only)."""
    out, stack = [], []
    for line in text.split("\n"):
        s = line.strip()
        if s == "#ifdef DEATH_LABEL":
            stack.append(death)
        elif s == "#ifndef DEATH_LABEL":
            stack.append(not death)
        elif s == "#else" and stack:
            stack[-1] = not stack[-1]
        elif s == "#endif" and stack:
            stack.pop()
        elif all(stack):
            out.append(line)
    return "\n".join(out)


def old_shapes(path, death):
    """name -> [(kind, count)] from a generated data file; kind is 'p' or an integer type."""
    text = view(path.read_text(), death)
    structs = {}
    for m in re.finditer(r"^struct (\w+) \{([^}]*)\};", text, re.M):
        members = []
        for mm in re.finditer(r"(void \*|\w+ )(\w+)(?:\[(\d+)\])?;", m.group(2)):
            members.append(("p" if mm.group(1).startswith("void") else mm.group(1).strip(), int(mm.group(3) or 1)))
        structs[m.group(1)] = members
    shapes = {}
    for m in re.finditer(r"^(?:const )?(struct \w+ |void \*|\w+ )(\w+)(?:\[(\d+)\])? = ", text, re.M):
        kind, name, count = m.group(1).strip(), m.group(2), int(m.group(3) or 1)
        if kind.startswith("struct"):
            shapes[name] = list(structs[kind.split()[1]])
        elif kind == "void *":
            shapes[name] = [("p", count)]
        elif kind in INT_TYPES:
            shapes[name] = [(kind, count)]
    return shapes


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


def string_align(size):
    # every piece of .rodata is on a multiple of 8 at least (the build raises the compiler's 4)
    return 16 if size >= 16 else 8


def cell_width(kind):
    return 4 if kind == "p" else INT_TYPES[kind]


class Decoder:
    """The data objects of the unit in one executable."""

    def __init__(self, image, args, blocks, source):
        self.im = image
        self.args = args
        self.problems = []
        self.texts = [image.block(".rodata", name) for name, _ in blocks["text"]]
        if None in self.texts:
            sys.exit("%s: a text block is missing" % image.target)
        self.source = view(source, image.death)
        self.ranges = {}
        self.objects = {".data": [], ".sdata": []}
        self.interior = {}       # label inside an object -> (object name, byte offset)
        forced = {}
        for spec in args.type:
            parts = spec.split(":")
            forced[parts[0]] = (parts[1], int(parts[2], 0) if len(parts) > 2 else None)
        for kind in (".data", ".sdata"):
            rng = None
            shapes = {}
            for name in blocks[kind]:
                r = image.block(kind, name)
                if r is None:
                    continue
                rng = r if rng is None else (min(rng[0], r[0]), max(rng[1], r[1]))
                shapes.update(old_shapes(ROOT / "src" / (name + ".c"), image.death))
            if rng is None:
                continue
            self.ranges[kind] = rng
            labels = sorted((image.address[n], n) for n in shapes if n in image.address and rng[0] <= image.address[n] < rng[1])
            missing = [n for n in shapes if n not in image.address]
            if missing:
                self.problems.append("no address for %s" % ", ".join(missing[:5]))
            # In .data a label with room for eight bytes or less is not an object of its own (those
            # are in .sdata): it lies inside the object before it.
            bounds = [a for a, _ in labels] + [rng[1]]
            merged = []
            for i, (a, n) in enumerate(labels):
                small = kind == ".data" and bounds[i + 1] - a <= 8
                inside = n in args.join or (small and i > 0 and n not in args.split)
                if inside and merged:
                    self.interior[n] = (merged[-1]["name"], a - merged[-1]["addr"])
                    merged[-1]["shape"] += shapes[n]
                else:
                    merged.append({"name": n, "addr": a, "shape": list(shapes[n]), "kind": kind})
            for i, it in enumerate(merged):
                it["room"] = (merged[i + 1]["addr"] if i + 1 < len(merged) else rng[1]) - it["addr"]
                if it["name"] in forced:
                    ctype, count = forced[it["name"]]
                    it["shape"] = [(ctype, count if count is not None else it["room"] // INT_TYPES[ctype])]
                size = sum(cell_width(k) * c for k, c in it["shape"])
                if size > it["room"]:
                    self.problems.append("%s: shape of %d bytes in a room of %d" % (it["name"], size, it["room"]))
            self.objects[kind] = merged
        self.decode()

    def in_unit(self, value):
        for kind, (a, b) in self.ranges.items():
            if a <= value < b:
                return kind
        return None

    def decode(self):
        im = self.im
        # A pointer into the unit's own tables may name a place inside what the labels make one
        # object: that place starts a table of its own, which only tables refer to.
        cuts = set()
        for items in self.objects.values():
            for it in items:
                cells = []
                off = 0
                for k, count in it["shape"]:
                    for _ in range(count):
                        cells.append((off, k))
                        off += cell_width(k)
                if any(k == "p" for _, k in cells):
                    # zero words between the pointers of a table are null pointers, not numbers
                    fixed, skip = [], 0
                    for o, k in cells:
                        if o < skip:
                            continue
                        if k != "p" and o % 4 == 0 and o + 4 <= off and im.word(it["addr"] + o) == 0 \
                                and not any(kk == "p" for oo, kk in cells if o <= oo < o + 4):
                            fixed.append((o, "p"))
                            skip = o + 4
                        else:
                            fixed.append((o, k))
                    cells = fixed
                it["cells"] = cells
                for off, k in cells:
                    if k == "p":
                        v = im.word(it["addr"] + off)
                        if v and self.in_unit(v):
                            cuts.add(v)
        for kind, items in self.objects.items():
            out = []
            for it in items:
                starts = sorted({it["addr"]} | {c for c in cuts if it["addr"] < c < it["addr"] + it["room"]})
                for j, a in enumerate(starts):
                    end = starts[j + 1] if j + 1 < len(starts) else it["addr"] + it["room"]
                    base = a - it["addr"]
                    cells = [(o - base, k) for o, k in it["cells"] if base <= o < end - it["addr"]]
                    if j and (not cells or cells[0] != (0, "p")):
                        # a pointer into a table of numbers: no cut there
                        shift = a - out[-1]["addr"]
                        out[-1]["room"] += end - a
                        out[-1]["cells"] += [(o + shift, k) for o, k in cells]
                        continue
                    out.append({"name": it["name"] if j == 0 else None, "addr": a, "room": end - a,
                                "cells": cells, "kind": kind})
            self.objects[kind] = out
        self.by_addr = {it["addr"]: it for items in self.objects.values() for it in items}
        for kind, items in self.objects.items():
            small = kind == ".sdata"
            for it in items:
                elems = []
                for off, k in it["cells"]:
                    a = it["addr"] + off
                    if k != "p":
                        elems.append(("num", k, im.data(a, INT_TYPES[k])))
                        continue
                    v = im.word(a)
                    block = next((i for i, (x, y) in enumerate(self.texts) if x <= v < y), None)
                    if v == 0:
                        elems.append(("null",))
                    elif block is not None:
                        elems.append(("str", v, im.string(v), block))
                    elif self.in_unit(v):
                        elems.append(("obj", v))
                    elif im.name(v):
                        elems.append(("sym", im.name(v)))
                    else:
                        self.problems.append("%s+%#x: pointer %#x has no name" % (it["name"], off, v))
                        elems.append(("null",))
                it["elems"] = elems
            # Sizes: zeros at the end are dropped where the alignment of the next object puts them back.
            for i in range(len(items) - 1, -1, -1):
                it = items[i]
                next_align = align_of(items[i + 1]["size"], small) if i + 1 < len(items) else (4 if small else 8)
                elems = it["elems"]
                end = it["addr"] + it["room"]
                n = len(elems)
                size = it["cells"][-1][0] + cell_width(it["cells"][-1][1]) if elems else 0
                if any(e[0] != "num" for e in elems):
                    while n > 1:
                        e = elems[n - 1]
                        if not (e[0] == "null" or (e[0] == "num" and not any(e[2]))):
                            break
                        start = it["addr"] + it["cells"][n - 1][0]
                        if (start + next_align - 1) // next_align * next_align != end:
                            break
                        n -= 1
                        size = it["cells"][n][0]
                it["elems"] = elems[:n]
                it["size"] = size
                if i + 1 < len(items) and (it["addr"] + size + next_align - 1) // next_align * next_align != end:
                    self.problems.append("%s: %d bytes do not reach the next object at %#x" % (it["name"] or hex(it["addr"]), size, end))

    def ordered(self):
        """The objects in source order: the two sections interleave by the text they mention first."""
        queues = {k: list(v) for k, v in self.objects.items()}

        mentioned = set()

        def key(it):
            # the first text the object would be the first to mention
            # (text below what has been mentioned so far was mentioned by a table the link dropped)
            frontier = max(mentioned, default=0)
            strs = [e[1] for e in it["elems"] if e[0] == "str" and e[1] > frontier]
            return min(strs) if strs else None

        order = []
        while queues[".data"] or queues[".sdata"]:
            heads = [q[0] for q in (queues[".data"], queues[".sdata"]) if q]
            free = [h for h in heads if key(h) is None]
            pick = free[0] if free else min(heads, key=key)
            queues[pick["kind"]].remove(pick)
            mentioned.update(e[1] for e in pick["elems"] if e[0] == "str")
            order.append(pick)
        seen = set()
        group = 0
        for it in order:
            for e in it["elems"]:
                if e[0] == "str" and e[1] not in seen:
                    seen.add(e[1])
                    group = max(group, e[3])
            it["group"] = group
        return order


def element_type(it, decoder):
    kinds = {e[0] for e in it["elems"]}
    if kinds <= {"num"}:
        types = {e[1] for e in it["elems"]}
        return types.pop() if len(types) == 1 else None
    if kinds <= {"str", "null"} and "str" in kinds:
        return "char *"
    if kinds <= {"obj", "null"}:
        targets = {decoder.by_addr[e[1]].get("ctype") if e[1] in decoder.by_addr else None for e in it["elems"] if e[0] == "obj"}
        if len(targets) == 1 and None not in targets:
            return targets.pop() + "*"
    return "void *"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("unit")
    ap.add_argument("--data", action="append", default=[])
    ap.add_argument("--sdata", action="append", default=[])
    ap.add_argument("--text", action="append", default=[])
    ap.add_argument("--split", action="append", default=[], help="label that starts an object of its own")
    ap.add_argument("--join", action="append", default=[], help="label that lies inside the object before it")
    ap.add_argument("--type", action="append", default=[], help="NAME:TYPE[:COUNT] for an object of numbers")
    ap.add_argument("--const", action="append", default=[], help="NAME:TYPE:COUNT, a constant object at the start of the last text block")
    ap.add_argument("--also-code", action="append", default=[], help="another .rodata block of the unit, to merge in the yaml")
    ap.add_argument("--record", action="append", default=[], help="NAME:TYPE:FIELDS, a table of records; FIELDS like s32,p")
    ap.add_argument("--dry", action="store_true")
    args = ap.parse_args()
    unit = args.unit
    blocks = {".data": args.data or [unit + "_data"], ".sdata": args.sdata or [unit + "_small_data"], "text": []}
    for spec in args.text or [unit + "_text"]:
        name, _, anchor = spec.partition("@")
        blocks["text"].append((name, anchor))
    source_path = ROOT / "src" / (unit + ".c")
    source = source_path.read_text()
    images = [Image(t) for t in TARGETS]
    decoders = [Decoder(im, args, blocks, source) for im in images]
    problems = []
    for d in decoders:
        problems += ["%s: %s" % (d.im.target, p) for p in d.problems]
    orders = [d.ordered() for d in decoders]

    # Names. An object both executables have under one name is the same object; objects without a
    # shared name are paired by position between those.
    def shape(it):
        return (it["kind"], len(it["elems"]), tuple(e[0] for e in it["elems"]))

    for d, order in zip(decoders, orders):
        for it in order:
            if it["name"] is None:
                it["name"] = ("death_D_%08X" if d.im.death else "D_%08X") % it["addr"]
    renames = {}                 # Death Label name -> the main executable's name
    for kind in (".data", ".sdata"):
        seqs = [[it for it in o if it["kind"] == kind] for o in orders]
        shared = {it["name"] for it in seqs[0]} & {it["name"] for it in seqs[1]}
        keys = [[it["name"] if it["name"] in shared else shape(it) for it in seq] for seq in seqs]
        sm = difflib.SequenceMatcher(None, keys[1], keys[0], autojunk=False)
        for tag, i1, i2, j1, j2 in sm.get_opcodes():
            if tag == "equal" or (tag == "replace" and i2 - i1 == j2 - j1):
                for a, b in zip(seqs[1][i1:i2], seqs[0][j1:j2]):
                    # (a name the main executable also has, for something else, is left alone)
                    if a["name"] != b["name"] and a["name"] not in shared and b["name"] not in shared \
                            and a["name"] not in images[0].address:
                        renames[a["name"]] = b["name"]
                        a["name"] = b["name"]

    for d, order in zip(decoders, orders):
        for _ in range(4):
            for it in order:
                it["ctype"] = element_type(it, d)

    # The text blocks: literals in order of first use must tile them.
    padded = [{}, {}]
    phantoms = [[], []]          # per executable: (name of the object it stands in front of, text)
    constants = []
    code_labels = {}
    for j, (d, order) in enumerate(zip(decoders, orders)):
        im = d.im
        last = len(d.texts) - 1
        bare = re.sub(r"extern [^;\n]*;", lambda x: " " * len(x.group(0)), d.source)
        for b, (start, end) in enumerate(d.texts):
            pos = start
            if b == last:
                for spec in args.const:
                    name, ctype, count = spec.split(":")
                    size = INT_TYPES[ctype] * int(count, 0)
                    if j == 0:
                        constants.append((name, ctype, im.data(pos, size)))
                    elif im.data(pos, size) != [c for c in constants if c[0] == name][0][2]:
                        problems.append("constant %s differs between the executables" % name)
                    pos += size
            seq = []
            seen = set()
            for it in order:
                for e in it["elems"]:
                    if e[0] == "str" and e[3] == b and e[1] not in seen:
                        seen.add(e[1])
                        seq.append((e[1], e[2], it))
            if b == last:
                uses = []
                for a in sorted(im.names):
                    if pos <= a < end and a not in seen:
                        for n in im.names[a]:
                            m = re.search(r"(?<![\w\"])%s\b" % n, bare)
                            if m:
                                uses.append((m.start(), a, n))
                for _, a, n in sorted(uses):
                    code_labels[n] = im.string(a)
                    if a not in seen:
                        seen.add(a)
                        seq.append((a, im.string(a), None))
            contents = {}
            later = {a: raw for a, raw, _ in seq}
            placed = set()
            for a, raw, owner in seq:
                if a in placed:
                    continue
                size = len(raw) + 1
                al = string_align(size)
                expect = (pos + al - 1) // al * al
                while expect != a and expect in later and expect not in placed and owner is not None:
                    # Text that lies here although the first table to mention it comes later: a table
                    # in between mentioned it first and was left out of the retail link as unused.
                    phantoms[j].append((owner["name"], later[expect]))
                    placed.add(expect)
                    contents[later[expect]] = expect
                    pos = expect + len(later[expect]) + 1
                    expect = (pos + al - 1) // al * al
                if expect != a and size <= 4 and (pos + 7) // 8 * 8 == a:
                    # A literal of up to four bytes is aligned to 4; this one is on 8, so it was longer:
                    # it is written with zeros after it up to five bytes.
                    padded[j][raw] = 5 - size
                    expect, size = a, 5
                if expect != a:
                    problems.append("%s: text block %d: %r at %#x, expected at %#x" % (im.target, b, raw[:16], a, expect))
                    break
                if raw in contents:
                    problems.append("%s: the text at %#x is repeated at %#x" % (im.target, contents[raw], a))
                contents[raw] = a
                pos = a + size
            else:
                if end - pos >= 16 or pos > end:
                    problems.append("%s: text block %d ends at %#x, the literals at %#x" % (im.target, b, end, pos))

    records = {spec.split(":")[0]: spec.split(":")[1:] for spec in args.record}

    def define(it, d, j):
        name = it["name"]
        elems = it["elems"]
        ctype = it["ctype"]
        if name in records:
            rtype, fields = records[name][0], records[name][1].split(",")
            size = sum(cell_width(f) for f in fields)
            rows = []
            for k in range(it["size"] // size):
                a = it["addr"] + k * size
                vals = []
                for f in fields:
                    if f == "p":
                        v = d.im.word(a)
                        vals.append("(void *)%s" % d.im.name(v) if v else "NULL")
                    else:
                        vals.append("%#x" % struct.unpack("<" + PACK[INT_TYPES[f]], d.im.data(a, INT_TYPES[f]))[0])
                    a += cell_width(f)
                rows.append("    { %s }," % ", ".join(vals))
            return "%s %s[%d] = {\n%s\n};\n" % (rtype, name, len(rows), "\n".join(rows))
        if ctype is None:
            problems.append("%s: no type for %s" % (d.im.target, name))
            ctype = "void *"
        if "*" in ctype:
            cast = "(%s)" % ctype
            lines = []
            for e in elems:
                if e[0] == "str":
                    lines.append(literal(e[2], padded[j].get(e[2], 0)))
                elif e[0] == "null":
                    lines.append("NULL")
                elif e[0] == "obj":
                    target = d.by_addr.get(e[1])
                    if target is None:
                        owner = max((o for o in d.by_addr.values() if o["addr"] <= e[1]), key=lambda o: o["addr"])
                        lines.append("%s((u8 *)%s + %d)" % (cast, owner["name"], e[1] - owner["addr"]))
                    else:
                        ref = target["name"] if len(target["elems"]) > 1 else "&" + target["name"]
                        lines.append(ref if (target["ctype"] or "") + "*" == ctype else cast + ref)
                elif e[0] == "sym":
                    lines.append(cast + e[1])
                else:
                    value = struct.unpack("<" + PACK[INT_TYPES[e[1]]], e[2])[0]
                    lines.append("%s%#x" % (cast, value) if value else "NULL")
                    if value and name not in records:
                        problems.append("%s: %s holds a number among its pointers" % (d.im.target, name))
            sep = "" if ctype.endswith("*") else " "
            if len(lines) == 1:
                return "%s%s%s = %s;\n" % (ctype, sep, name, lines[0])
            return "%s%s%s[%d] = {\n%s\n};\n" % (ctype, sep, name, len(lines), "\n".join("    %s," % l for l in lines))
        raw = b"".join(e[2] for e in elems)
        width = INT_TYPES[ctype]
        body = raw.rstrip(b"\0")
        if width == 1 and len(body) >= 3 and re.fullmatch(rb"[\x20-\x7e]+", body) and len(body) < len(raw):
            return "char %s[%d] = %s;\n" % (name, len(raw), literal(body))
        if ctype == "float":
            values = [float_text(raw[k:k + 4]) for k in range(0, len(raw), 4)]
            per = 4
        else:
            signed = ctype in ("s8", "s16", "s32", "int")
            values = []
            for k in range(0, len(raw), width):
                v = struct.unpack("<" + (PACK[width].lower() if signed else PACK[width]), raw[k:k + width])[0]
                values.append(str(v) if -10 < v < 10 else ("%#x" % v if v > 0 else str(v)))
            per = 16 if width == 1 else 8
        if len(values) == 1:
            return "%s %s = %s;\n" % (ctype, name, values[0])
        rows = ["    " + ", ".join(values[k:k + per]) + "," for k in range(0, len(values), per)]
        return "%s %s[%d] = {\n%s\n};\n" % (ctype, name, len(values), "\n".join(rows))

    texts = []
    for j, (d, order) in enumerate(zip(decoders, orders)):
        rows = []
        for it in order:
            mine = [(k, raw) for k, (before, raw) in enumerate(phantoms[j]) if before == it["name"]]
            if mine:
                k = mine[0][0]
                body = ("char *unused_text_%d = %s;" % (k, literal(mine[0][1])) if len(mine) == 1 else
                        "char *unused_text_%d[%d] = {\n%s\n};" % (k, len(mine), "\n".join("    %s," % literal(raw) for _, raw in mine)))
                rows.append(("unused_text_%d" % k, it["group"],
                             "/* A table nothing uses was defined here: the retail link left it out, and the text it was\n"
                             "   the first to mention kept its place. */\n"
                             "#pragma define_section unused \".unused\"\n#pragma section unused begin\n"
                             "%s\n#pragma section unused end\n" % body))
            rows.append((it["name"], it["group"], define(it, d, j)))
        texts.append(rows)

    # One sequence for both executables.
    groups = [[] for _ in blocks["text"]]
    declared = []
    sm = difflib.SequenceMatcher(None, [t[0] for t in texts[0]], [t[0] for t in texts[1]], autojunk=False)
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == "equal":
            for a, b in zip(texts[0][i1:i2], texts[1][j1:j2]):
                g = max(a[1], b[1])
                if a[2] == b[2]:
                    groups[g].append(a[2])
                else:
                    groups[g].append("#ifdef DEATH_LABEL\n%s#else\n%s#endif\n" % (b[2], a[2]))
                declared.append((a[0], a[2], b[2]))
        else:
            if i2 > i1:
                groups[texts[0][i1][1]].append("#ifndef DEATH_LABEL\n%s#endif\n" % "\n".join(t[2] for t in texts[0][i1:i2]))
                declared += [(t[0], t[2], None) for t in texts[0][i1:i2]]
            if j2 > j1:
                groups[texts[1][j1][1]].append("#ifdef DEATH_LABEL\n%s#endif\n" % "\n".join(t[2] for t in texts[1][j1:j2]))
                declared += [(t[0], None, t[2]) for t in texts[1][j1:j2]]
    const_text = ""
    for name, ctype, raw in constants:
        width = INT_TYPES[ctype]
        values = struct.unpack_from("<%d%s" % (len(raw) // width, PACK[width]), raw)
        const_text += "const %s %s[%d] = {\n    %s,\n};\n\n" % (ctype, name, len(values), ", ".join(str(v) for v in values))

    def declaration(text):
        if text.startswith("/*"):
            return ""
        return "extern %s;" % text.split(" = ", 1)[0]

    for p in problems:
        print("problem:", p)
    counts = [(len(d.objects[".data"]), len(d.objects[".sdata"])) for d in decoders]
    print("objects (.data, .sdata): main %s, Death Label %s; %d paired by position; text named by the code: %d" %
          (counts[0], counts[1], len(renames), len(code_labels)))
    if args.dry or problems:
        for g, parts in enumerate(groups):
            print("/* ---- group %d: %d definitions ---- */" % (g, len(parts)))
            if g == len(groups) - 1:
                print(const_text, end="")
            print("\n".join(parts))
        if problems:
            sys.exit(1)
        return

    # Write.  Declarations of everything in front; each group of definitions at its anchor.
    defined = {n for n, _, _ in declared} | {c[0] for c in constants}
    interior = {}
    for d in decoders:
        interior.update(d.interior)
    lines = []
    for l in source.split("\n"):
        m = re.match(r"^\s*extern [^;(]*?\b(\w+)(?:\[[^\]]*\])*;", l)
        if m and (m.group(1) in defined or m.group(1) in interior or m.group(1) in code_labels or m.group(1) in renames):
            continue
        lines.append(l)
    text = "\n".join(lines)
    for old, new in renames.items():
        text = re.sub(r"\b%s\b" % old, new, text)
    for n, raw in code_labels.items():
        text = re.sub(r"\b%s\b" % n, lambda m: literal(raw), text)
    for name, (base, offset) in interior.items():
        text = re.sub(r"\b%s\[0\]" % name, "%s[%d]" % (base, offset // 4), text)
        if re.search(r"\b%s\b" % name, text):
            print("note: %s (inside %s) is still used by name" % (name, base))
    decls = []
    for name, a, b in declared:
        da, db = (declaration(a) if a else None), (declaration(b) if b else None)
        if da == db:
            if da:
                decls.append(da)
        elif da and db:
            decls.append("#ifdef DEATH_LABEL\n%s\n#else\n%s\n#endif" % (db, da))
        elif da:
            decls.append("#ifndef DEATH_LABEL\n%s\n#endif" % da)
        else:
            decls.append("#ifdef DEATH_LABEL\n%s\n#endif" % db)
    outside = sorted({e[1] for order in orders for it in order for e in it["elems"] if e[0] == "sym"} |
                     {d.im.name(d.im.word(it["addr"] + o)) for d, order in zip(decoders, orders) for it in order
                      if it["name"] in records for o in range(0, it["size"], 4)
                      if d.im.word(it["addr"] + o) >= 0x100000 and d.im.name(d.im.word(it["addr"] + o))})
    decls = ["extern u8 %s[];" % n for n in outside if n not in defined] + decls
    for g, parts in enumerate(groups):
        body = "\n".join(parts)
        if g == len(groups) - 1:
            body = const_text + body
        anchor = blocks["text"][g][1]
        if g == 0:
            body = "/* Tables. */\n" + "\n".join(decls) + "\n\n" + body
            if "/* Tables. */\n" in text:
                text = text.replace("/* Tables. */\n", body + "\n", 1)
            else:
                tl = text.split("\n")
                last_include = max(i for i, l in enumerate(tl[:80]) if l.startswith("#include"))
                tl[last_include + 1:last_include + 1] = [""] + body.rstrip("\n").split("\n")
                text = "\n".join(tl)
        else:
            if text.count(anchor) != 1:
                sys.exit("anchor %r is not there exactly once" % anchor)
            text = text.replace(anchor, body + "\n" + anchor, 1)
    source_path.write_text(text)

    for im in images:
        y = im.yaml
        for kind, names in ((".data", blocks[".data"]), (".sdata", blocks[".sdata"]),
                            (".rodata", [n for n, _ in blocks["text"]] + args.also_code)):
            present = [n for n in names if "%s, %s]" % (kind, n) in y]
            if not present:
                continue
            own = re.search(r"\n *- \[0x[0-9a-f]+, %s, %s\]" % (re.escape(kind), re.escape(unit)), y)
            first = True
            if own and y.index(own.group(0)) < y.index("%s, %s]" % (kind, present[0])):
                first = False
            elif own:
                y = y.replace(own.group(0), "", 1)
            for n in present:
                line = re.search(r"\n *- \[0x[0-9a-f]+, %s, %s\]" % (re.escape(kind), re.escape(n)), y).group(0)
                if first:
                    y = y.replace(line, line.replace(n + "]", unit + "]"), 1)
                    first = False
                else:
                    y = y.replace(line, "", 1)
        (ROOT / "config" / im.target / "splat.yaml").write_text(y)
        sym_path = ROOT / "config" / im.target / "symbols.txt"
        gone = defined | set(code_labels) | set(renames)
        for d in decoders:
            for a, b in d.texts:
                gone |= {n for x in d.im.names if a <= x < b for n in d.im.names[x]}
        gone |= {n for n in interior if not re.search(r"\b%s\b" % n, text)}
        sym = [l for l in sym_path.read_text().split("\n")
               if not (re.match(r"(\w+)\s*=", l) and re.match(r"(\w+)\s*=", l).group(1) in gone)]
        sym_path.write_text("\n".join(sym))
    for names in (blocks[".data"], blocks[".sdata"], [n for n, _ in blocks["text"]]):
        for n in names:
            p = ROOT / "src" / (n + ".c")
            if p.exists():
                p.unlink()
    print("wrote %d definitions into %s" % (len(declared), source_path.relative_to(ROOT)))


if __name__ == "__main__":
    main()
