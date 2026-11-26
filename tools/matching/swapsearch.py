"""Statement-swap search localized by MWCC line info.

Compiles the draft with `-g` (same code; adds a DWARF1 `.line` table), maps every differing instruction
to its source line, and tries moving each such statement up or down by up to three simple statements, and swapping
adjacent runs of 2-4 statements near it. The best improvement
is kept greedily. Improvements go to build/work/<fn>.c.

    uv run tools/swapsearch.py func_A func_B [--jobs 6] [--rounds 4]
"""

import argparse
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
import re
import struct
import subprocess
import sys

import sys as _sys
from pathlib import Path as _Path
if str(_Path(__file__).resolve().parent.parent) not in _sys.path:
    _sys.path.insert(0, str(_Path(__file__).resolve().parent.parent))
from build import compiler_path
from common import ROOT, TOOLCHAINS
from diff import require_local, target_compiler
from objects import parse_object

SOURCES = ("build/work/{}.c", "build/arc/{}.fix.c", "build/all/{}.fix.c")
WORK = ROOT / "build/swapsearch"
DIFF_LINE_RE = re.compile(r"^  [~+<>-]([0-9a-f]+)\s", re.M)
SIMPLE_RE = re.compile(r"^\s+[^\s{}][^{}]*;\s*$")
LOCAL = require_local()
VERSION = target_compiler("SLPS_252.33", LOCAL, None)


def source(fn):
    for pattern in SOURCES:
        path = ROOT / pattern.format(fn)
        if path.exists():
            return path


def line_table(c_path, obj):
    runner = LOCAL["runner"]
    runner = [runner] if isinstance(runner, str) else (runner or [])
    subprocess.run([*runner, str(compiler_path(VERSION)), *TOOLCHAINS["compiler_flags"], "-g", "-o", str(obj), str(c_path)],
                   cwd=ROOT, capture_output=True, check=True)
    data = obj.read_bytes()
    sections, named, functions = parse_object(obj)
    sec = sections[named[".line"]]
    blob = data[sec[4]:sec[4] + sec[5]]
    total, _ = struct.unpack_from("<II", blob, 0)
    return [(addr, line) for line, _, addr in (struct.unpack_from("<IHI", blob, o) for o in range(8, total, 10))], functions


def score(fn, code, tag):
    path = WORK / f"{fn}.{tag}.c"
    path.write_text(code, encoding="utf-8")
    out = subprocess.run(
        ["uv", "run", "tools/matching/diff.py", "SLPS_252.33", fn, "--source", str(path), "--compact", "--max-diffs", "400", "--tag", "sw"],
        cwd=ROOT, capture_output=True, text=True,
    ).stdout
    path.unlink(missing_ok=True)
    if re.search(r"^(MATCH|RODATA_LAYOUT)", out, re.M):
        return (100.0, 0), out
    m = re.search(r"^DIFFERENT\s+\S+\s+([\d.]+)%", out, re.M)
    if not m:
        return (-1.0, 0), out
    return (float(m.group(1)), -len(re.findall(r"^  [~<>+-]", out, re.M))), out


def diff_lines(fn, code, out):
    path = WORK / f"{fn}.g.c"
    path.write_text(code, encoding="utf-8")
    try:
        table, functions = line_table(path, WORK / f"{fn}.g.o")
    except (subprocess.CalledProcessError, KeyError, ValueError):
        return set()
    start = functions.get(fn, (0, 0))[0]
    table = sorted((a - start, l) for a, l in table if l)
    lines = set()
    for off in {int(x, 16) for x in DIFF_LINE_RE.findall(out)}:
        best = None
        for addr, line in table:
            if addr <= off:
                best = line
        if best:
            lines.add(best)
    return lines


def movable(line):
    return (SIMPLE_RE.match(line) and not any(k in line for k in ("return", "goto", "break", "case ", "default:"))
            and not re.search(r"\w+\([^)]*\);", line))


def variants(code, lines, reach=3):
    """Move each diff-line statement up or down by 1..reach lines within a run of simple statements."""
    src = code.split("\n")
    seen = set()
    for line in sorted(lines):
        i = line - 1
        if not (0 <= i < len(src)) or not movable(src[i]):
            continue
        indent = len(src[i]) - len(src[i].lstrip())
        for step in (-1, 1):
            for dist in range(1, reach + 1):
                j = i + step * dist
                if not (0 <= j < len(src)) or not movable(src[j]) or len(src[j]) - len(src[j].lstrip()) != indent:
                    break
                new = src[:i] + src[i + 1:]
                new.insert(j, src[i])
                text = "\n".join(new)
                if text not in seen:
                    seen.add(text)
                    yield text
    # swap two adjacent runs of 2..4 statements near each diff line
    for line in sorted(lines):
        for k in (2, 3, 4):
            for start in range(line - 1 - 2 * k + 1, line):
                end = start + 2 * k
                if start < 0 or end > len(src):
                    continue
                block = src[start:end]
                indent = len(block[0]) - len(block[0].lstrip())
                if not all(movable(l) and len(l) - len(l.lstrip()) == indent for l in block):
                    continue
                text = "\n".join(src[:start] + block[k:] + block[:k] + src[end:])
                if text not in seen:
                    seen.add(text)
                    yield text


def one(fn, rounds):
    path = source(fn)
    if path is None:
        return fn, None, None
    code = path.read_text(encoding="utf-8")
    best, out = score(fn, code, "base")
    base = best
    for _ in range(rounds):
        if best[0] in (100.0, -1.0):
            break
        lines = diff_lines(fn, code, out)
        improved = None
        for i, cand in enumerate(variants(code, lines)):
            sc, cand_out = score(fn, cand, f"v{i}")
            if sc > best and (improved is None or sc > improved[0]):
                improved = (sc, cand, cand_out)
                if sc[0] == 100:
                    break
        if improved is None:
            break
        best, code, out = improved
    if best > base:
        (ROOT / f"build/work/{fn}.c").write_text(code, encoding="utf-8")
    return fn, base, best


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("functions", nargs="+")
    ap.add_argument("--jobs", type=int, default=6)
    ap.add_argument("--rounds", type=int, default=4)
    a = ap.parse_args()
    WORK.mkdir(parents=True, exist_ok=True)
    matches = []
    with ThreadPoolExecutor(a.jobs) as pool:
        for fn, base, best in pool.map(lambda f: one(f, a.rounds), a.functions):
            if base is None or best <= base:
                continue
            tag = "MATCH" if best[0] == 100 else "UP"
            print(f"{tag:5} {fn} {base[0]:.2f}% -> {best[0]:.2f}%", flush=True)
            if best[0] == 100:
                matches.append(fn)
    print("matches:", " ".join(matches))
    return 0


if __name__ == "__main__":
    sys.exit(main())
