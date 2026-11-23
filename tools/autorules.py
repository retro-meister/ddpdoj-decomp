"""Greedy per-function rule search over every unmatched game function.

For each function, start from its current best draft (build/work/<fn>.c, else build/arc/ or build/all/
fix drafts), try every rule in tools/rules.py, keep the best improvement, and repeat until no rule helps.
Improvements are written to build/work/<fn>.c; matches are listed at the end.

    uv run tools/autorules.py [--min 80] [--jobs 6] [func_X ...]
"""

import argparse
from concurrent.futures import ThreadPoolExecutor
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys

from common import ROOT
import rules
from split import scan_asm_functions, split

SOURCES = ("build/work/{}.c", "build/arc/{}.fix.c", "build/all/{}.fix.c")


def current(fn):
    for pattern in SOURCES:
        path = ROOT / pattern.format(fn)
        if path.exists():
            return path
    return None


def score(fn, source, tag):
    out = subprocess.run(
        ["uv", "run", "tools/diff.py", "SLPS_252.33", fn, "--source", str(source), "--compact", "--max-diffs", "2000", "--tag", tag],
        cwd=ROOT, capture_output=True, text=True,
    ).stdout
    if re.search(r"^(MATCH|RODATA_LAYOUT)", out, re.M):
        return (100.0, 0)
    m = re.search(r"^DIFFERENT\s+\S+\s+([\d.]+)%", out, re.M)
    return (float(m.group(1)), -len(re.findall(r"^  [~<>+-]", out, re.M))) if m else (-1.0, -10**6)


def search(fn, min_score):
    src = current(fn)
    if src is None:
        return fn, None, None
    work = ROOT / "build" / "autorules" / fn
    work.mkdir(parents=True, exist_ok=True)
    code = src.read_text(encoding="utf-8")
    (work / "base.c").write_text(code, encoding="utf-8")
    best = start = score(fn, work / "base.c", "ar")
    if best[0] < min_score or best[0] == 100.0:
        return fn, start, None
    improved = False
    while best[0] < 100.0:
        trials = []
        for rule in rules.RULES:
            new = rule(code)
            if new != code:
                path = work / f"{rule.__name__}.c"
                path.write_text(new, encoding="utf-8")
                trials.append((score(fn, path, "ar"), new, rule.__name__))
        better = [t for t in trials if t[0] > best]
        if not better:
            break
        best, code, _ = max(better, key=lambda t: t[0])
        improved = True
    if improved:
        dest = ROOT / "build" / "work" / f"{fn}.c"
        if not dest.exists() or score(fn, dest, "ar") < best:
            dest.write_text(code, encoding="utf-8")
    return fn, start, best if improved else None


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("functions", nargs="*")
    parser.add_argument("--min", type=float, default=80.0, help="skip drafts scoring below this")
    parser.add_argument("--jobs", type=int, default=6)
    args = parser.parse_args()
    fns = args.functions
    if not fns:
        done = {p.stem for p in (ROOT / "src/main").glob("*.c")}
        funcs = scan_asm_functions(split("SLPS_252.33") / "asm")
        fns = [n for n, (a, _) in sorted(funcs.items(), key=lambda kv: kv[1][0]) if a >= 0x119B10 and n not in done]
    matches = []
    with ThreadPoolExecutor(args.jobs) as pool:
        for fn, start, end in pool.map(lambda f: search(f, args.min), fns):
            if end is not None:
                print(f"{'MATCH' if end[0] == 100.0 else 'UP   '} {fn} {start[0]:.2f}% -> {end[0]:.2f}%", flush=True)
                if end[0] == 100.0:
                    matches.append(fn)
    shutil.rmtree(ROOT / "build" / "autorules", ignore_errors=True)
    for folder in (ROOT / "build/diff/SLPS_252.33").glob("*@ar"):
        shutil.rmtree(folder, ignore_errors=True)
    print(f"matches: {' '.join(matches)}")
    return 0


if __name__ == "__main__":
    sys.path.insert(0, str(ROOT / "tools"))
    sys.exit(main())
