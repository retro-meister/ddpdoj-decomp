"""Clean matched drafts for integration, re-verify them, and optionally integrate them in one batch.

Cleanup: drop `#pragma mpwc_relax on`, unused local/extern/prototype declarations, and repeated blank
lines. The cleaned file must still match retail; drafts that only match with the pragma are reported
and skipped.

    uv run tools/stage.py func_A func_B --src-dir build/work            # clean + verify into build/staged
    uv run tools/stage.py func_A func_B --src-dir build/work --integrate  # ...then integrate + build
"""

import argparse
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
import re
import subprocess
import sys

from common import ROOT

PRAGMA_RE = re.compile(r"^#pragma\s+mpwc_relax\s+on\s*\n", re.M)
# `type name;`, `type *name;`, `extern type name[];`, `type name();` (one declarator per line)
DECL_RE = re.compile(
    r"^[ \t]*(?:extern[ \t]+|static[ \t]+)?(?:const[ \t]+|volatile[ \t]+|unsigned[ \t]+|signed[ \t]+)*"
    r"[A-Za-z_]\w*(?:[ \t]*\*)*[ \t]+\**[ \t]*([A-Za-z_]\w*)[ \t]*(?:\[[^\]\n]*\])*(?:\(\s*(?:void)?\s*\))?[ \t]*;[ \t]*\n",
    re.M,
)
KEYWORDS = {"return", "goto", "break", "continue", "else", "do"}


def clean(code, func_name):
    code = PRAGMA_RE.sub("", code)
    # Without mpwc_relax, pointer assignments from typed tables need an explicit cast (codegen-neutral).
    types = dict((name, ty) for ty, name in re.findall(r"^extern (\w+) \*(reg_a[0-6]);$", code, flags=re.M))
    code = re.sub(r"\b(reg_a[0-6]) = (D_[0-9A-F]{8})\b(?!\[)", lambda m: f"{m[1]} = ({types.get(m[1], 'u8')} *){m[2]}", code)
    while True:
        removed = False
        # struct/union members are layout, never "unused"
        aggregates = [m.span() for m in re.finditer(r"\b(?:struct|union)\b[^;{()]*\{[^{}]*\}", code)]
        for match in DECL_RE.finditer(code):
            name = match.group(1)
            first = match.group(0).split()[0]
            if name == func_name or first in KEYWORDS:
                continue
            if any(start <= match.start() < end for start, end in aggregates):
                continue
            if len(re.findall(rf"\b{re.escape(name)}\b", code)) == 1:
                code = code[:match.start()] + code[match.end():]
                removed = True
                break
        if not removed:
            break
    code = re.sub(r"\n{3,}", "\n\n", code)
    code = re.sub(r"(\{\n)\n+", r"\1", code)
    return code


def score(func_name, source):
    out = subprocess.run(
        ["uv", "run", "tools/diff.py", "SLPS_252.33", func_name, "--source", str(source), "--compact", "--max-diffs", "0"],
        cwd=ROOT, capture_output=True, text=True,
    ).stdout
    for line in out.splitlines():
        if line.startswith(("MATCH", "DIFFERENT")):
            parts = line.split()
            return parts[0], parts[2] if len(parts) > 2 else ""
    return "FAIL", ""


def stage_one(func_name, src_dir, out_dir):
    src = src_dir / f"{func_name}.c"
    if not src.exists():
        src = src_dir / f"{func_name}.fix.c"
    if not src.exists():
        return func_name, "NOFILE", None
    dest = out_dir / f"{func_name}.c"
    dest.write_text(clean(src.read_text(encoding="utf-8"), func_name), encoding="utf-8")
    status, pct = score(func_name, dest)
    if status == "MATCH":
        return func_name, "MATCH", dest
    raw_status, _ = score(func_name, src)
    note = "needs pragma/unused decl" if raw_status == "MATCH" else f"{status} {pct}"
    dest.unlink(missing_ok=True)
    return func_name, note, None


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("functions", nargs="+")
    parser.add_argument("--src-dir", type=Path, default=ROOT / "build/work")
    parser.add_argument("--out", type=Path, default=ROOT / "build/staged")
    parser.add_argument("--jobs", type=int, default=6)
    parser.add_argument("--integrate", action="store_true", help="integrate every staged match (one build per ELF)")
    args = parser.parse_args()
    args.out.mkdir(parents=True, exist_ok=True)

    with ThreadPoolExecutor(args.jobs) as pool:
        results = list(pool.map(lambda f: stage_one(f, args.src_dir, args.out), args.functions))
    staged = []
    for func_name, status, dest in results:
        print(f"{status:<10} {func_name}" + (f"  -> {dest.relative_to(ROOT)}" if dest else ""))
        if dest:
            staged.append((func_name, dest))
    if not args.integrate or not staged:
        return 0 if len(staged) == len(results) else 1

    from integrate import integrate_many, prepare_integration
    plans = []
    for func_name, dest in staged:
        try:
            plans.append(prepare_integration("SLPS_252.33", func_name, dest))
        except (ValueError, OSError) as error:
            print(f"SKIP       {func_name}: {error}")
    applied, failed = integrate_many(plans)
    for plan, error in failed:
        print(f"FAILED     {plan['func_name']}: {error}")
    print(f"integrated {len(applied)} / {len(results)}")
    return 0 if not failed and len(applied) == len(results) else 1


if __name__ == "__main__":
    sys.exit(main())
