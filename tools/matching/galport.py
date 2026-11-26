"""Port a GALLERY C function to its SLPS_252.33 twin by renaming globals and callees.

The symbol map comes from aligning the two functions' instructions (mnemonic sequence) and pairing the
symbol each aligned instruction references (`%gp_rel(x)`, `%hi(x)`/`%lo(x)`, `jal x`).

    uv run tools/galport.py sprite_build_rect_packet func_00214230 [--out build/galport]

Writes `<out>/<target>.c` (GALLERY includes plus `extern` placeholders the port needs) and prints the map.
SLPS externs are emitted with the GALLERY declaration's type; adjust layouts by hand where SLPS differs.
"""

import argparse
import difflib
import re
import subprocess
import sys
from pathlib import Path

import sys as _sys
from pathlib import Path as _Path
if str(_Path(__file__).resolve().parent.parent) not in _sys.path:
    _sys.path.insert(0, str(_Path(__file__).resolve().parent.parent))
from common import ROOT

# gallery.h macros that name an offset into another object: name -> (object, byte offset, element type)
MACROS = {"g_glyph_cache": ("g_glyph_cache_storage", 0x18, "GlyphCacheEntry")}

SYM = re.compile(r"%(gp_rel|hi|lo)\((\w+)\)|\b(jal)\s+(\w+)")


def asm_body(elf, name):
    for path in (ROOT / "build/split" / elf / "asm").rglob("*.s"):
        text = path.read_text(errors="replace")
        start = text.find(f"glabel {name}\n")
        if start >= 0:
            end = text.find(f"endlabel {name}", start)
            return text[start:end if end > 0 else None]
    raise SystemExit(f"{name}: no asm in {elf}")


def parse(body):
    out = []
    for line in body.splitlines():
        m = re.match(r"\s*/\*.*?\*/\s+(\S+)\s*(.*)", line)
        if not m:
            continue
        syms = [(kind or jal, a or b) for kind, a, jal, b in SYM.findall(m.group(2))]
        if m.group(1) == "jal" and re.fullmatch(r"\w+", m.group(2).strip()):
            syms = [("jal", m.group(2).strip())]
        kind, sym = syms[0] if syms else (None, None)
        out.append((m.group(1), sym, {"lo": "hi"}.get(kind, kind)))
    return out


def gallery_names():
    """GALLERY address -> C name, from the link map (the split asm only knows `D_<addr>`)."""
    names = {}
    for line in (ROOT / "build/GALLERY.ELF.map").read_text().splitlines():
        m = re.match(r"^\s+0x([0-9a-f]{8})\s+([A-Za-z_]\w*)\s*$", line)
        if m and not m.group(2).startswith(("D_", "func_", "jtbl_")):
            names.setdefault(f"D_{int(m.group(1), 16):08X}", m.group(2))
    names.update(static_names())
    for macro, (base, offset, _) in MACROS.items():
        for addr, name in list(names.items()):
            if name == base:
                names[f"D_{int(addr[2:], 16) + offset:08X}"] = macro
    return names


def static_names():
    """File-local GALLERY data (`static` tables) is not in the map; place it via each object's sections."""
    readelf = next((ROOT / ".tools/binutils").rglob("*-readelf"))
    bases = {}
    for line in (ROOT / "build/GALLERY.ELF.map").read_text().splitlines():
        m = re.match(r"^ (\.\w+)\s+0x([0-9a-f]{8})\s+0x[0-9a-f]+ (build/split/GALLERY\.ELF/objects/src/gallery/\S+\.c\.o)$", line)
        if m:
            bases.setdefault(m.group(3), {}).setdefault(m.group(1), []).append(int(m.group(2), 16))
    names = {}
    for obj, sections in bases.items():
        out = subprocess.run([readelf, "-SWs", ROOT / obj], capture_output=True, text=True).stdout
        index = {}  # section number -> address
        seen = {}
        for m in re.finditer(r"^\s*\[\s*(\d+)\] (\.\w+)\s+(?:PROGBITS|NOBITS)", out, re.M):
            n, name = int(m.group(1)), m.group(2)
            k = seen.get(name, 0)
            seen[name] = k + 1
            if name in sections and k < len(sections[name]):
                index[n] = sections[name][k]
        for m in re.finditer(r"^\s*\d+: ([0-9a-f]{8})\s+\d+ OBJECT\s+LOCAL\s+\w+\s+(\d+) (\w+)$", out, re.M):
            if int(m.group(2)) in index:
                names[f"D_{index[int(m.group(2))] + int(m.group(1), 16):08X}"] = m.group(3)
    return names


def symbol_map(gal, slps):
    names = gallery_names()
    ga = [(m, names.get(s, s) if s else s, k) for m, s, k in parse(asm_body("GALLERY.ELF", gal))]
    sa = parse(asm_body("SLPS_252.33", slps))
    sm = difflib.SequenceMatcher(None, [i[0] for i in ga], [i[0] for i in sa], autojunk=False)
    votes = {}
    for block in sm.get_matching_blocks():
        for k in range(block.size):
            g, s = ga[block.a + k][1], sa[block.b + k][1]
            if ga[block.a + k][2] != sa[block.b + k][2]:
                continue
            if g and s:
                votes.setdefault(g, {}).setdefault(s, 0)
                votes[g][s] += 1
    mapping, owner = {}, {}
    for g, c in sorted(votes.items(), key=lambda kv: -max(kv[1].values())):
        for s in sorted(c, key=c.get, reverse=True):
            if s not in owner:  # one GALLERY symbol per SLPS symbol
                mapping[g], owner[s] = s, g
                break
    # fallback: pair the remaining symbols of each kind in order of first reference
    used = set(mapping.values())
    for kind in ("hi", "gp_rel", "jal"):
        left_g = list(dict.fromkeys(g for _, g, k in ga if g and k == kind and g not in mapping))
        left_s = list(dict.fromkeys(s for _, s, k in sa if s and k == kind and s not in used))
        for g, s in zip(left_g, left_s):
            mapping[g] = s
    unmapped = sorted({g for _, g, _ in ga if g and g not in mapping})
    return mapping, unmapped, sm.ratio()


def gallery_source(name):
    for path in (ROOT / "src/gallery").glob("*.c"):
        text = path.read_text()
        m = re.search(rf"^[A-Za-z_][\w \*]*\b{name}\([^;{{]*\)(?:\s*[^{{}}();]+;)*\s*\{{", text, re.M)  # ANSI or K&R
        if m:
            depth, i = 0, text.index("{", m.end() - 1)
            for j in range(i, len(text)):
                depth += {"{": 1, "}": -1}.get(text[j], 0)
                if depth == 0:
                    return text[m.start():j + 1], text
    raise SystemExit(f"{name}: not found in src/gallery")


def declaration(gname, sname, file_text):
    if gname in MACROS:
        return f"extern {MACROS[gname][2]} {sname}[];"
    header = (ROOT / "include/gallery/gallery.h").read_text()
    for text in (file_text, header):
        m = re.search(rf"^(?:extern |static )?(?![ \t])([^\n;(]*?)\b{gname}\b((?:\s*\[[^\]]*\])*)\s*(=[^;]*)?;", text, re.M)
        if m and "(" not in m.group(0).split("=")[0]:
            ty = m.group(1).replace("static ", "").replace("const ", "").strip()
            dims = re.sub(r"\[[^\]]*\]", "[]", m.group(2) or "", count=1) if m.group(2) else ""
            return f"extern {ty} {sname}{dims};"
        m = re.search(rf"^(?![ \t])([A-Za-z_][\w \*]*?)\b{gname}\(([^)]*)\)\s*[;{{]", text, re.M)
        if m:
            return f"{m.group(1).strip()} {sname}({m.group(2).strip() or 'void'});"
    return f"/* TODO declare {sname} (GALLERY {gname}) */"


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("gallery")
    parser.add_argument("target")
    parser.add_argument("--out", type=Path, default=ROOT / "build/galport")
    args = parser.parse_args()
    mapping, unmapped, ratio = symbol_map(args.gallery, args.target)
    body, file_text = gallery_source(args.gallery)
    mapping[args.gallery] = args.target
    decls = []
    for g, s in sorted(mapping.items()):
        if g == args.gallery or g.startswith("sce") and g == s:
            continue
        if re.search(rf"\b{g}\b", body):
            decls.append(declaration(g, s, file_text))
    for g, s in sorted(mapping.items(), key=lambda kv: -len(kv[0])):
        body = re.sub(rf"\b{g}\b", s, body)
    args.out.mkdir(parents=True, exist_ok=True)
    dest = args.out / f"{args.target}.c"
    types = [m.group(0) for m in re.finditer(r"^typedef[^;{]*(?:\{[^{}]*\})?\s*(\w+);", file_text, re.M)
             if re.search(rf"\b{m.group(1)}\b", body + "\n".join(decls))]
    dest.write_text('#include "gallery/gallery.h"\n\n' + "".join(t + "\n\n" for t in types)
                    + "\n".join(decls) + "\n\n" + body + "\n")
    print(f"ratio {ratio:.3f} -> {dest}")
    for g, s in sorted(mapping.items()):
        print(f"  {g} -> {s}")
    for g in unmapped:
        print(f"  {g} -> ?  (unmapped)")


if __name__ == "__main__":
    sys.exit(main())
