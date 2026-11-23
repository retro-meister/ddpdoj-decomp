"""Reorder `switch` cases to retail's block order (compare-chain switches).

MWCC lays out the case blocks of a compare-chain switch in source order (and emits the compares in reverse),
while m2c prints cases sorted by value. This reads `li vY,K; beq vX,vY,.L` / `beqz vX,.L` pairs from the
retail asm, sorts each switch's case groups by their target address, and keeps the rewrite when it scores
better than the current draft.

    uv run tools/switchorder.py [func_X ...] [--jobs 6]     # default: every open draft with a switch
"""

import argparse
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
import re
import subprocess
import sys

from common import ROOT
from galport import asm_body

SOURCES = ("build/work/{}.c", "build/arc/{}.fix.c", "build/all/{}.fix.c")


def case_targets(fn):
    """case value -> retail target address."""
    lines = asm_body("SLPS_252.33", fn).splitlines()
    regs, targets = {}, {}
    for line in lines:
        m = re.search(r"\*/\s+(\S+)\s+(.*)$", line)
        if not m:
            continue
        op, args = m.group(1), [a.strip() for a in m.group(2).split(",")]
        if op == "addiu" and len(args) == 3 and args[1] == "$zero":
            regs[args[0]] = int(args[2], 0)
        elif op in ("ori",) and len(args) == 3 and args[1] == "$zero":
            regs[args[0]] = int(args[2], 0)
        elif op == "beq" and len(args) == 3:
            k = regs.get(args[1], regs.get(args[0]))
            t = re.match(r"\.L([0-9A-F]{8})", args[2])
            if k is not None and t:
                targets.setdefault(k if k < 0x8000 else k - 0x10000, int(t.group(1), 16))
        elif op == "beqz" and len(args) == 2:
            t = re.match(r"\.L([0-9A-F]{8})", args[1])
            if t:
                targets.setdefault(0, int(t.group(1), 16))
    return targets


def reorder(code, targets):
    out, pos = [], 0
    for m in re.finditer(r"^(\s*)switch \(.*\) \{[^\n]*\n", code, re.M):
        indent = m.group(1)
        start = m.end()
        # find matching close brace
        depth, i = 1, start
        while depth and i < len(code):
            depth += {"{": 1, "}": -1}.get(code[i], 0)
            i += 1
        end = code.rfind("\n", start, i) + 1  # line with the closing brace
        body = code[start:end]
        if re.search(rf"^{indent}\s+switch", body, re.M):
            continue
        heads = list(re.finditer(rf"^{indent}(?:case (-?(?:0x[0-9A-Fa-f]+|\d+)):|default:)[^\n]*\n", body, re.M))
        if len(heads) < 2:
            continue
        groups, cur = [], None
        for j, h in enumerate(heads):
            seg_end = heads[j + 1].start() if j + 1 < len(heads) else len(body)
            seg = body[h.start():seg_end]
            label_only = seg.strip().count("\n") == 0 and seg.strip().endswith(":") or re.fullmatch(r"[^\n]*:[^\n]*\n", seg)
            value = int(h.group(1), 0) if h.group(1) else None
            if cur is None:
                cur = {"text": "", "values": []}
            cur["text"] += seg
            cur["values"].append(value)
            if not label_only:
                groups.append(cur)
                cur = None
        if cur:
            groups.append(cur)
        prefix = body[:heads[0].start()]

        def key(g):
            addrs = [targets[v] for v in g["values"] if v is not None and v in targets]
            return min(addrs) if addrs else float("inf")
        if not all(key(g) != float("inf") for g in groups if None not in g["values"]):
            continue
        new = sorted(groups, key=key)
        if new == groups:
            continue
        # a group that falls through into the next must stay before it
        if any(not re.search(r"\b(?:break|return|goto)\b[^\n]*;\s*(?:/\*[^\n]*\*/)?\s*$", g["text"].rstrip()) for g in groups[:-1]):
            continue
        out.append(code[pos:start] + prefix + "".join(g["text"] for g in new))
        pos = end
    out.append(code[pos:])
    return "".join(out)


def score(fn, src, tag):
    res = subprocess.run(["uv", "run", "tools/diff.py", "SLPS_252.33", fn, "--source", str(src), "--compact",
                          "--max-diffs", "2000", "--tag", tag], cwd=ROOT, capture_output=True, text=True).stdout
    if re.search(r"^MATCH", res, re.M):
        return (100.0, 0)
    m = re.search(r"^DIFFERENT\s+\S+\s+([\d.]+)%", res, re.M)
    return (float(m.group(1)), -len(re.findall(r"^  [~<>+-]", res, re.M))) if m else (-1.0, -10**6)


def one(fn):
    src = next((ROOT / p.format(fn) for p in SOURCES if (ROOT / p.format(fn)).exists()), None)
    if src is None:
        return fn, None, None
    code = src.read_text()
    try:
        new = reorder(code, case_targets(fn))
    except SystemExit:
        return fn, None, None
    if new == code:
        return fn, None, None
    trial = ROOT / "build/switchorder" / f"{fn}.c"
    trial.parent.mkdir(parents=True, exist_ok=True)
    trial.write_text(new)
    before, after = score(fn, src, "so0"), score(fn, trial, "so1")
    if after > before:
        (ROOT / "build/work" / f"{fn}.c").write_text(new)
    return fn, before, after


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("functions", nargs="*")
    parser.add_argument("--jobs", type=int, default=6)
    args = parser.parse_args()
    fns = args.functions
    if not fns:
        done = {p.stem for p in (ROOT / "src/main").glob("*.c")}
        fns = sorted({Path(p).name.split(".")[0] for pat in SOURCES for p in (ROOT).glob(pat.format("*"))
                      if "switch (" in Path(p).read_text(errors="replace")} - done)
    matches = []
    with ThreadPoolExecutor(args.jobs) as pool:
        for fn, before, after in pool.map(one, fns):
            if before is None:
                continue
            tag = "MATCH" if after[0] == 100.0 else "UP" if after > before else "same"
            print(f"{tag:5} {fn} {before[0]:.2f}% -> {after[0]:.2f}%", flush=True)
            if tag == "MATCH":
                matches.append(fn)
    for folder in (ROOT / "build/diff/SLPS_252.33").glob("*@so*"):
        subprocess.run(["rm", "-rf", str(folder)])
    print(f"matches: {' '.join(matches)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
