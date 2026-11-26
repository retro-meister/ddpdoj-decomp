"""Greedy mutation hill-climb for near-miss drafts.

Each round generates single-site mutations (local temp types, pointer-deref widths/signedness, Reg32
member signedness, compare forms, cast removal, adjacent statement swaps), scores them in parallel with
tools/matching/diff.py, and keeps the best improvement. Stops at a match, when no mutation helps, or when the
evaluation budget runs out.

    uv run tools/climb.py func_X --source build/arc/func_X.fix.c [--budget 60] [--out build/work]
"""

import argparse
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
import random
import re
import shutil
import subprocess
import sys
import tempfile

import sys as _sys
from pathlib import Path as _Path
if str(_Path(__file__).resolve().parent.parent) not in _sys.path:
    _sys.path.insert(0, str(_Path(__file__).resolve().parent.parent))
from common import ROOT

INT_TYPES = ["u8", "s8", "u16", "s16", "u32", "s32"]
WIDTH_TYPES = {
    "lb": ("s8",), "lbu": ("u8",), "lh": ("s16",), "lhu": ("u16",), "lw": ("u32", "s32"),
    "sb": ("u8", "s8"), "sh": ("u16", "s16"), "sw": ("u32", "s32"),
}
CHUNK = 12
LOCAL_RE = re.compile(r"^(    )(u8|s8|u16|s16|u32|s32)( [a-z_]\w*;)$", re.M)
DEREF_RE = re.compile(r"\*\((u8|s8|u16|s16|u32|s32) \*\)")
MEMBER_SWAP = {".b[": ".sb[", ".sb[": ".b[", ".h[": ".sh[", ".sh[": ".h[", ".w": ".sw", ".sw": ".w"}
MEMBER_RE = re.compile(r"\.(sb|b|sh|h)\[|\.(sw|w)\b")
CMP_RE = re.compile(r"(>=|<=|<|>) (-?(?:0x[0-9A-Fa-f]+|\d+))\b")
SWAP_CMP_RE = re.compile(r"(if \()([^()]*(?:\([^()]*\)[^()]*)*?) (<=|>=|<|>|==|!=) (-?(?:0x[0-9A-Fa-f]+|\d+))(?=\) \{)")
CAST_RE = re.compile(r"\((?:u8|s8|u16|s16|u32|s32|s64)\) ?")
COMPOUND_RE = re.compile(r"^( +)(\w+) = (.+?) (\+|-|&|\||\^|\*|<<|>>) ([^;]+);\n\1\3 = \2;$", re.M)
STMT_RE = re.compile(r"^( +)([^\n{}]*;)\n\1([^\n{}]*;)$", re.M)


def parse_int(text):
    return int(text, 0)


def fmt_int(value, like):
    if like.lower().startswith(("0x", "-0x")):
        return f"-0x{-value:X}" if value < 0 else f"0x{value:X}"
    return str(value)


def mutations(code):
    out = []
    for m in LOCAL_RE.finditer(code):
        for t in INT_TYPES:
            if t != m.group(2):
                out.append(("local:" + t, code[:m.start(2)] + t + code[m.end(2):]))
    for m in DEREF_RE.finditer(code):
        for t in INT_TYPES:
            if t == m.group(1):
                continue
            out.append(("deref:" + t, code[:m.start(1)] + t + code[m.end(1):]))
    for m in COMPOUND_RE.finditer(code):
        indent, _, lhs, op, rhs = m.groups()
        out.append(("compound", code[:m.start()] + f"{indent}{lhs} {op}= {rhs};" + code[m.end():]))
    rest = []
    for m in MEMBER_RE.finditer(code):
        token = m.group(0)
        rest.append(("member", code[:m.start()] + MEMBER_SWAP[token] + code[m.end():]))
    for m in CMP_RE.finditer(code):
        op, num = m.group(1), m.group(2)
        k = parse_int(num)
        alt = {">=": ("> ", k - 1), ">": (">= ", k + 1), "<": ("<= ", k - 1), "<=": ("< ", k + 1)}[op]
        rest.append(("cmp", code[:m.start()] + alt[0] + fmt_int(alt[1], num) + code[m.end():]))
    for m in SWAP_CMP_RE.finditer(code):
        lhs, op, rhs = m.group(2), m.group(3), m.group(4)
        flip = {"<": ">", ">": "<", "<=": ">=", ">=": "<=", "==": "==", "!=": "!="}[op]
        rest.append(("cmp", code[:m.start(2)] + f"{rhs} {flip} {lhs}" + code[m.end(4):]))
    for m in CAST_RE.finditer(code):
        rest.append(("cast", code[:m.start()] + code[m.end():]))
    for m in STMT_RE.finditer(code):
        a, b = m.group(2), m.group(3)
        if a.startswith(("return", "goto", "break", "continue")) or b.startswith(("return", "goto")):
            continue
        rest.append(("swap", code[:m.start(2)] + b + "\n" + m.group(1) + a + code[m.end(3):]))
    return out + rest


def score(func_name, source):
    out = subprocess.run(
        ["uv", "run", "tools/matching/diff.py", "SLPS_252.33", func_name, "--source", str(source), "--compact", "--max-diffs", "1000",
         "--tag", f"climb{Path(source).stem}"],
        cwd=ROOT, capture_output=True, text=True,
    ).stdout
    pct, ndiff, wanted = -1.0, 10**6, set()
    for line in out.splitlines():
        if line.startswith(("MATCH", "RODATA_LAYOUT")):
            return 100.0, 0, wanted
        mm = re.match(r"^  [~-]\w+\s+retail: (\w+) ", line)
        if mm:
            wanted.update(WIDTH_TYPES.get(mm.group(1), ()))
        if line.startswith("DIFFERENT"):
            pct = float(line.split()[2].rstrip("%"))
        if re.match(r"^  [~<>+-]", line):
            ndiff = ndiff + 1 if ndiff < 10**6 else 1
    return pct, (ndiff if pct >= 0 else 10**6), wanted


def better(a, b):
    return (a[0], -a[1]) > (b[0], -b[1])


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("function")
    parser.add_argument("--source", type=Path, required=True)
    parser.add_argument("--out", type=Path, default=ROOT / "build/work")
    parser.add_argument("--budget", type=int, default=60)
    parser.add_argument("--jobs", type=int, default=6)
    parser.add_argument("--seed", type=int, default=0)
    parser.add_argument("--kinds", default="", help="comma list: local,deref,compound,member,cmp,cast,swap (default all)")
    args = parser.parse_args()
    rng = random.Random(args.seed)
    kinds = set(filter(None, args.kinds.split(",")))
    args.out.mkdir(parents=True, exist_ok=True)
    dest = args.out / f"{args.function}.c"

    best_code = args.source.read_text(encoding="utf-8")
    tmp = Path(tempfile.mkdtemp(prefix="climb_", dir=ROOT / "build"))
    try:
        (tmp / "base.c").write_text(best_code, encoding="utf-8")
        best = score(args.function, tmp / "base.c")
        print(f"start  {best[0]:.2f}% ({best[1]} diffs)")
        used, seen = 1, {best_code}
        while best[0] < 100.0 and used < args.budget:
            muts = [(t, c) for t, c in dict.fromkeys(mutations(best_code)) if c not in seen]
            rng.shuffle(muts)
            muts = [tc for tc in muts if not kinds or tc[0].split(":")[0] in kinds]
            muts.sort(key=lambda tc: 0 if tc[0] == "compound" else 1 if tc[0].split(":")[-1] in best[2] else 2)
            cands = [c for _, c in muts][: args.budget - used]
            if not cands:
                break
            improved = False
            for lo in range(0, len(cands), CHUNK):
                chunk = cands[lo:lo + CHUNK]
                seen.update(chunk)
                paths = []
                for i, code in enumerate(chunk):
                    p = tmp / f"c{used + i}.c"
                    p.write_text(code, encoding="utf-8")
                    paths.append(p)
                with ThreadPoolExecutor(args.jobs) as pool:
                    scores = list(pool.map(lambda p: score(args.function, p), paths))
                used += len(chunk)
                top = max(range(len(chunk)), key=lambda i: (scores[i][0], -scores[i][1]))
                if better(scores[top], best):
                    best, best_code, improved = scores[top], chunk[top], True
                    print(f"step   {best[0]:.2f}% ({best[1]} diffs)  [{used} evals]")
                    break
            if not improved:
                print(f"no improvement after {used} evals")
                break
        current = score(args.function, dest) if dest.exists() else score(args.function, tmp / "base.c")
        if better(best, current):
            dest.write_text(best_code, encoding="utf-8")
            print(f"{'MATCH' if best[0] == 100.0 else 'BEST '}  {args.function} {best[0]:.2f}% -> {dest}")
        else:
            print(f"NOCHANGE {args.function} {best[0]:.2f}%")
    finally:
        shutil.rmtree(tmp, ignore_errors=True)
        for folder in (ROOT / "build/diff/SLPS_252.33").glob(f"{args.function}@climb*"):
            shutil.rmtree(folder, ignore_errors=True)
    return 0 if best[0] == 100.0 else 1


if __name__ == "__main__":
    sys.exit(main())
