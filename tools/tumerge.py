"""Merge consecutive single-function units into one translation unit.

    uv run tools/tumerge.py func_0021EFB0 func_0021F180 ... [--death-end 0x1b7280]

The units must be consecutive in SLPS_252.33. Their sources are concatenated into `src/game/<first>.c`
(includes once, identical declaration lines once). Both splat.yaml files get one `c` entry for the run; in
DEATH.ELF the run is turned back into asm so that `tools/unitcheck.py src/game/<first>.c --at ADDR --apply`
can integrate the merged unit there. Nothing is built; run the build (or unitcheck --apply) afterwards.
"""
import argparse
from pathlib import Path
import re
import subprocess

from common import ROOT
from split import load_symbols

MAIN, DEATH = "SLPS_252.33", "DEATH.ELF"
SUBSEG_RE = re.compile(r"^(\s*-\s*\[)(0x[0-9a-fA-F]+|\d+),\s*(\.?[a-zA-Z0-9_]+),\s*([^\]]+)\]\s*$")


def find_source(stem):
    for folder in ("game", "main"):
        path = ROOT / "src" / folder / f"{stem}.c"
        if path.is_file():
            return path
    raise ValueError(f"{stem}: no source in src/game or src/main")


def merge_sources(paths):
    includes, seen, bodies = [], set(), []
    for path in paths:
        kept = []
        for line in path.read_text(encoding="utf-8").splitlines():
            if line.startswith("#include"):
                if line not in includes:
                    includes.append(line)
                continue
            flat = re.sub(r"\s+", " ", line.strip())
            is_decl = flat.endswith(";") and not line.startswith((" ", "\t", "}")) and "=" not in flat and "{" not in flat
            if is_decl:
                if flat in seen:
                    continue
                seen.add(flat)
            kept.append(line)
        bodies.append("\n".join(kept).strip("\n"))
    return "\n".join(includes) + "\n\n" + "\n\n".join(bodies) + "\n"


def patch_yaml(target, stems, first_stub, end_offset, make_asm):
    path = ROOT / "config" / target / "splat.yaml"
    lines = path.read_text(encoding="utf-8").splitlines()
    members = {f"{folder}/{stem}" for stem in stems for folder in ("game", "main")}
    out, start, rodata_done = [], None, False
    rows = [(i, SUBSEG_RE.match(line)) for i, line in enumerate(lines)]
    code = [(i, m) for i, m in rows if m and m.group(3) in ("c", "asm")]
    for i, m in rows:
        if not m:
            out.append(lines[i])
            continue
        offset, kind, name = int(m.group(2), 0), m.group(3), m.group(4).strip()
        if kind == "c" and name in members and start is None:
            start = offset
            out.append(f"{m.group(1)}{offset:#x}, asm, game_{offset:06x}_tu]" if make_asm else f"{m.group(1)}{offset:#x}, c, {first_stub}]")
            continue
        if kind in ("c", "asm") and start is not None and start < offset < end_offset:
            following = next((int(n.group(2), 0) for j, n in code if j > i), None)
            if kind == "asm" and (following is None or following > end_offset):
                out.append(f"{m.group(1)}{end_offset:#x}, asm, game_{end_offset:06x}_x]")
            continue
        if kind == ".rodata" and name in members:
            if make_asm:
                out.append(f"{m.group(1)}{offset:#x}, rodata, rodata_{offset:06x}_tu]")
            elif not rodata_done:
                out.append(f"{m.group(1)}{offset:#x}, .rodata, {first_stub}]")
                rodata_done = True
            continue
        out.append(lines[i])
    if start is None:
        raise ValueError(f"{target}: none of the units is a c subsegment")
    path.write_text("\n".join(out) + "\n", encoding="utf-8")


def main():
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("units", nargs="+")
    parser.add_argument("--death-end", type=lambda v: int(v, 0), required=True, help="Death Label address just past the run")
    args = parser.parse_args()
    stems = args.units
    paths = [find_source(stem) for stem in stems]
    main_symbols = load_symbols(MAIN)
    last_address, last_size = main_symbols[stems[-1]]
    file_address = 0x100000 - 0x80
    main_end = ((last_address + last_size + 15) & ~15) - file_address
    merged = merge_sources(paths)
    first_stub = f"game/{stems[0]}"
    patch_yaml(MAIN, stems, first_stub, main_end, make_asm=False)
    patch_yaml(DEATH, stems, first_stub, args.death_end - file_address, make_asm=True)
    dest = ROOT / "src" / "game" / f"{stems[0]}.c"
    if paths[0] != dest:
        subprocess.run(["git", "mv", str(paths[0].relative_to(ROOT)), str(dest.relative_to(ROOT))], cwd=ROOT, check=True)
    for path in paths[1:]:
        subprocess.run(["git", "rm", "-q", "-f", str(path.relative_to(ROOT))], cwd=ROOT, check=True)
    dest.write_text(merged, encoding="utf-8")
    print(f"merged {len(stems)} units into {dest.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
