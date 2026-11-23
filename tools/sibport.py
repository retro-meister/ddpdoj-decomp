"""Port a matched SLPS_252.33 function's C source to an unmatched near-clone.

The symbol map comes from aligning the two functions' asm (see tools/galport.py); every global, callee and
the function name are renamed in the matched source, which is then scored.

    uv run tools/sibport.py func_MATCHED func_TARGET [--out build/sibport]
    uv run tools/sibport.py --pairs pairs.txt [--jobs 6]      # lines: "func_MATCHED func_TARGET"
"""

import argparse
from concurrent.futures import ThreadPoolExecutor
import difflib
from pathlib import Path
import re
import subprocess
import sys

from common import ROOT
from galport import asm_body, parse


def symbol_map(matched, target):
    ma, ta = parse(asm_body("SLPS_252.33", matched)), parse(asm_body("SLPS_252.33", target))
    sm = difflib.SequenceMatcher(None, [i[0] for i in ma], [i[0] for i in ta], autojunk=False)
    votes = {}
    for block in sm.get_matching_blocks():
        for k in range(block.size):
            (_, a, ka), (_, b, kb) = ma[block.a + k], ta[block.b + k]
            if a and b and ka == kb:
                votes.setdefault(a, {}).setdefault(b, 0)
                votes[a][b] += 1
    mapping, owner = {}, {}
    for a, c in sorted(votes.items(), key=lambda kv: -max(kv[1].values())):
        for b in sorted(c, key=c.get, reverse=True):
            if b not in owner:
                mapping[a], owner[b] = b, a
                break
    for kind in ("hi", "gp_rel", "jal"):
        left_a = list(dict.fromkeys(a for _, a, k in ma if a and k == kind and a not in mapping))
        left_b = list(dict.fromkeys(b for _, b, k in ta if b and k == kind and b not in owner))
        for a, b in zip(left_a, left_b):
            mapping[a], owner[b] = b, a
    mapping[matched] = target
    return mapping, sm.ratio()


def port(matched, target, out):
    mapping, ratio = symbol_map(matched, target)
    code = (ROOT / "src/main" / f"{matched}.c").read_text()
    # rename through placeholders so swapped names do not collide
    keys = sorted(mapping, key=len, reverse=True)
    for i, a in enumerate(keys):
        code = re.sub(rf"\b{a}\b", f"@@{i}@@", code)
    for i, a in enumerate(keys):
        code = code.replace(f"@@{i}@@", mapping[a])
    out.mkdir(parents=True, exist_ok=True)
    dest = out / f"{target}.c"
    dest.write_text(code)
    res = subprocess.run(["uv", "run", "tools/diff.py", "SLPS_252.33", target, "--source", str(dest), "--compact",
                          "--max-diffs", "2000", "--tag", "sib"], cwd=ROOT, capture_output=True, text=True).stdout
    status = re.search(r"^(MATCH|DIFFERENT)\s+\S+\s+([\d.]+)%", res, re.M)
    ndiff = len(re.findall(r"^  [~<>+-]", res, re.M))
    return target, matched, ratio, (status.group(1), float(status.group(2))) if status else ("FAIL", 0.0), ndiff


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("matched", nargs="?")
    parser.add_argument("target", nargs="?")
    parser.add_argument("--pairs", type=Path)
    parser.add_argument("--out", type=Path, default=ROOT / "build/sibport")
    parser.add_argument("--jobs", type=int, default=6)
    args = parser.parse_args()
    pairs = [l.split()[:2] for l in args.pairs.read_text().splitlines() if l.strip()] if args.pairs else [(args.matched, args.target)]
    with ThreadPoolExecutor(args.jobs) as pool:
        for target, matched, ratio, (status, pct), ndiff in pool.map(lambda p: port(p[0], p[1], args.out), pairs):
            print(f"{status:9} {pct:6.2f}% {ndiff:4d}  {target} <- {matched} (asm {ratio:.2f})", flush=True)
    return 0


if __name__ == "__main__":
    sys.exit(main())
