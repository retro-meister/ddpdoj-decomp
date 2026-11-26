"""Repair common MWCC compile errors in m2c drafts, then score them.

Fixes (codegen-neutral casts only):
  - `illegal implicit conversion from 'A' to 'B'` on `LHS = RHS;` -> `LHS = (B)RHS;` (drops an existing leading cast)
  - `pointer/array required` on a scalar extern -> declare it `u8 *`
  - `illegal operand` on a compare whose operand is an extern array used as a value -> `(u32)ARRAY`

    uv run tools/errfix.py func_A func_B --out build/errfix
"""

import argparse
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
import re
import subprocess
import sys

import sys as _sys
from pathlib import Path as _Path
if str(_Path(__file__).resolve().parent.parent) not in _sys.path:
    _sys.path.insert(0, str(_Path(__file__).resolve().parent.parent))
from common import ROOT

SEARCH = ("build/work/{f}.c", "build/arc/{f}.fix.c", "build/all/{f}.fix.c")
ERR_RE = re.compile(r"^#\s+(\d+): .*\n#\s+Error:.*\n((?:#   .*\n)+)", re.M)
ASSIGN_RE = re.compile(r"^(\s*)(.+?[^=!<>+\-*/&|^%])= (.+);(\s*)$")
CAST_RE = re.compile(r"^\((?:const )?(?:unsigned |signed )?\w+(?: \*+)?\)\s*(?=[\w(\-*&])")


def run(func, src, tag):
    return subprocess.run(
        ["uv", "run", "tools/matching/diff.py", "SLPS_252.33", func, "--source", str(src), "--compact", "--max-diffs", "0", "--tag", tag],
        cwd=ROOT, capture_output=True, text=True,
    ).stdout


def status(out):
    if re.search(r"^(MATCH|RODATA_LAYOUT)", out, re.M):
        return 100.0
    m = re.search(r"^DIFFERENT\s+\S+\s+([\d.]+)%", out, re.M)
    return float(m.group(1)) if m else None


def errors(out):
    for m in ERR_RE.finditer(out):
        msg = " ".join(l[1:].strip() for l in m.group(2).splitlines())
        yield int(m.group(1)), msg


def fix_line(line, msg, arrays):
    conv = re.match(r"illegal implicit conversion from '([^']+)' to '([^']+)'", msg)
    if conv:
        to = conv.group(2)
        if "[" in to or "(" in to:
            return None
        m = ASSIGN_RE.match(line)
        if not m:
            return None
        rhs = CAST_RE.sub("", m.group(3), count=1)
        if re.fullmatch(r"[\w.\[\]]+|-?\d+|0x[0-9A-Fa-f]+", rhs):
            new_rhs = f"({to}){rhs}"
        else:
            new_rhs = f"({to})({rhs})"
        return f"{m.group(1)}{m.group(2)}= {new_rhs};{m.group(4)}"
    if msg.startswith("illegal operand"):
        new = re.sub(r"(?<![\w(&])\b(" + "|".join(map(re.escape, arrays)) + r")\b(?!\s*\[)", r"(u32)\1", line) if arrays else line
        return new if new != line else None
    return None


def repair(func, out_dir, rounds=8):
    src = next((ROOT / p.format(f=func) for p in SEARCH if (ROOT / p.format(f=func)).exists()), None)
    if src is None:
        return func, "NOFILE", None
    code = src.read_text(encoding="utf-8")
    dest = out_dir / f"{func}.c"
    for _ in range(rounds):
        dest.write_text(code, encoding="utf-8")
        out = run(func, dest, "ef")
        score = status(out)
        if score is not None:
            return func, f"{score:.2f}", dest
        arrays = re.findall(r"^extern \w+ (D_[0-9A-F]{8})\[\];", code, re.M)
        lines = code.split("\n")
        changed = False
        for lineno, msg in errors(out):
            idx = lineno - 1
            if msg.startswith("pointer/array required") and 0 <= idx < len(lines):
                for name in re.findall(r"\b(D_[0-9A-F]{8})\b", lines[idx]):
                    decl = re.compile(rf"^extern (?:s32|u32|s16|u16|s8|u8) {name};$", re.M)
                    for j, l in enumerate(lines):
                        if decl.match(l):
                            lines[j] = f"extern u8 *{name};"
                            changed = True
                continue
            if 0 <= idx < len(lines):
                new = fix_line(lines[idx], msg, arrays)
                if new is not None and new != lines[idx]:
                    lines[idx] = new
                    changed = True
        if not changed:
            first = next(errors(out), (0, "unknown"))
            dest.unlink(missing_ok=True)
            return func, f"FAIL {first[0]}: {first[1][:70]}", None
        code = "\n".join(lines)
    dest.unlink(missing_ok=True)
    return func, "FAIL rounds", None


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("functions", nargs="+")
    ap.add_argument("--out", type=Path, default=ROOT / "build/errfix")
    ap.add_argument("--jobs", type=int, default=6)
    a = ap.parse_args()
    a.out.mkdir(parents=True, exist_ok=True)
    with ThreadPoolExecutor(a.jobs) as pool:
        for func, st, _ in pool.map(lambda f: repair(f, a.out), a.functions):
            print(f"{func} {st}", flush=True)
    return 0


if __name__ == "__main__":
    sys.exit(main())
