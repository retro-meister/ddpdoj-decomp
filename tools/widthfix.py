"""Fix load/store width mismatches in near-matching drafts.

For each `retail: lhu a0,4(a1) | cand: lh a0,4(a1)` style diff (same offset, different width or sign),
try retyping every `*(T *)((u8 *)(reg) + (off))` source access with that offset to the retail width,
keep the best score, and repeat. Improvements are written to build/work/<fn>.c.

    uv run tools/widthfix.py func_A func_B [--jobs 6]
"""

import argparse
from concurrent.futures import ThreadPoolExecutor
import re
import subprocess
import sys

from common import ROOT

SOURCES = ("build/work/{}.c", "build/arc/{}.fix.c", "build/all/{}.fix.c")
DIFF_RE = re.compile(r"^  ~\w+\s+retail: ([ls][bhw]u?) \w+,(-?\d+)\(\w+\)\s+\| cand: ([ls][bhw]u?) \w+,(-?\d+)\(\w+\)", re.M)
WIDTH = {"b": "8", "h": "16", "w": "32"}
ACCESS_RE = r"\*\((?:volatile )?([us](?:8|16|32)) \*\)\(\(u8 \*\)\((\w+)\) \+ \((0x[0-9A-Fa-f]+|\d+)\)\)"


def source(fn):
    for pattern in SOURCES:
        path = ROOT / pattern.format(fn)
        if path.exists():
            return path


def score(fn, code, tag):
    path = ROOT / "build/widthfix" / f"{fn}.{tag}.c"
    path.write_text(code, encoding="utf-8")
    out = subprocess.run(
        ["uv", "run", "tools/diff.py", "SLPS_252.33", fn, "--source", str(path), "--compact", "--max-diffs", "400", "--tag", "wf"],
        cwd=ROOT, capture_output=True, text=True,
    ).stdout
    path.unlink(missing_ok=True)
    if re.search(r"^(MATCH|RODATA_LAYOUT)", out, re.M):
        return (100.0, 0), out
    m = re.search(r"^DIFFERENT\s+\S+\s+([\d.]+)%", out, re.M)
    if not m:
        return (-1.0, 0), out
    return (float(m.group(1)), -len(re.findall(r"^  [~<>+-]", out, re.M))), out


def wanted_type(op):
    width = WIDTH[op[1]]
    if width == "32":
        return ["u32", "s32"]
    if op[0] == "l":
        return [("u" if op.endswith("u") else "s") + width]
    return ["u" + width, "s" + width]


def variants(code, out):
    seen = set()
    for retail_op, r_off, cand_op, c_off in DIFF_RE.findall(out):
        if r_off != c_off or retail_op == cand_op or retail_op[0] != cand_op[0]:
            continue
        off = int(r_off)
        for m in re.finditer(ACCESS_RE, code):
            if int(m.group(3), 0) != off:
                continue
            for ty in wanted_type(retail_op):
                if ty == m.group(1):
                    continue
                new = code[:m.start(1)] + ty + code[m.end(1):]
                if new not in seen:
                    seen.add(new)
                    yield new


def one(fn):
    path = source(fn)
    if path is None:
        return fn, None, None
    code = path.read_text(encoding="utf-8")
    best, out = score(fn, code, "base")
    base = best
    for _ in range(6):
        if best[0] == 100:
            break
        improved = False
        for i, cand in enumerate(variants(code, out)):
            sc, cand_out = score(fn, cand, f"v{i}")
            if sc > best:
                best, code, out, improved = sc, cand, cand_out, True
                break
        if not improved:
            break
    if best > base:
        (ROOT / f"build/work/{fn}.c").write_text(code, encoding="utf-8")
    return fn, base, best


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("functions", nargs="+")
    ap.add_argument("--jobs", type=int, default=6)
    a = ap.parse_args()
    (ROOT / "build/widthfix").mkdir(parents=True, exist_ok=True)
    matches = []
    with ThreadPoolExecutor(a.jobs) as pool:
        for fn, base, best in pool.map(one, a.functions):
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
