"""Diff-driven compare-form fixer.

For every open mapped draft, read its diff; each `slti` that differs only in `at` vs a real register is a
compare-form mismatch (`x > k-1` gives `slti at`, `x >= k` gives `slti vN`). Flip the C compare with that
constant and keep the result in build/work/ when the score improves.

    uv run tools/sltifix.py
"""
import os, re, subprocess, sys
from concurrent.futures import ThreadPoolExecutor
os.chdir(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
os.makedirs("build/rule", exist_ok=True)
LINE = re.compile(r"^  ~\w+\s+retail: slti (\w+),\w+,(-?\d+)\s*\| cand: slti (\w+),\w+,(-?\d+)", re.M)
def open_functions():
    """Every unmatched game function (address >= 0x119B10) in SLPS_252.33."""
    sys.path.insert(0, "tools")
    from split import split, scan_asm_functions
    done = {f[:-2] for f in os.listdir("src/main")}
    funcs = scan_asm_functions(split("SLPS_252.33") / "asm")
    return [n for n, (a, s) in sorted(funcs.items(), key=lambda kv: kv[1][0]) if a >= 0x119B10 and n not in done]


def diff(fn, src, tag):
    return subprocess.run(["uv","run","tools/matching/diff.py","SLPS_252.33",fn,"--source",src,"--compact","--max-diffs","2000","--tag",tag],capture_output=True,text=True).stdout
def metric(out):
    if re.search(r"^MATCH", out, re.M): return (100.0, 0)
    m = re.search(r"^DIFFERENT\s+\S+\s+([\d.]+)%", out, re.M)
    return (float(m.group(1)), -len(re.findall(r"^  [~<>+-]", out, re.M))) if m else (-1, -10**6)
def hexs(k): return f"0x{k:X}" if k >= 10 else str(k)
def variants(k):  # textual spellings of constant k
    return {str(k), f"0x{k:X}", f"0x{k:x}"} if k >= 0 else {str(k), f"-0x{-k:X}"}
def one(fn):
    src = f"build/work/{fn}.c" if os.path.exists(f"build/work/{fn}.c") else f"build/arc/{fn}.fix.c"
    if not os.path.exists(src) or os.path.exists(f"src/main/{fn}.c"): return None
    out = diff(fn, src, "sf0"); before = metric(out)
    code = open(src).read(); new = code
    for r_dst, k, c_dst, k2 in LINE.findall(out):
        if k != k2: continue
        k = int(k); want_at = r_dst == "at"
        if (c_dst == "at") == want_at: continue
        if want_at:   # x >= k -> x > k-1 ; x < k -> x <= k-1
            for v in variants(k):
                new = re.sub(rf">= {re.escape(v)}\b", f"> {hexs(k-1)}", new); new = re.sub(rf"< {re.escape(v)}\b(?!=)", f"<= {hexs(k-1)}", new)
        else:         # x > k-1 -> x >= k ; x <= k-1 -> x < k
            for v in variants(k - 1):
                new = re.sub(rf"> {re.escape(v)}\b", f">= {hexs(k)}", new); new = re.sub(rf"<= {re.escape(v)}\b", f"< {hexs(k)}", new)
    if new == code: return None
    dst = f"build/rule/{fn}.c"; open(dst, "w").write(new)
    after = metric(diff(fn, dst, "sf1"))
    if after > before: open(f"build/work/{fn}.c", "w").write(new)
    return fn, before, after
fns = open_functions()
res = [r for r in ThreadPoolExecutor(6).map(one, fns) if r]
for fn, b, a in res:
    print(("MATCH" if a[0] == 100 else "UP" if a > b else "DOWN" if a < b else "same"), fn, b, "->", a)
subprocess.run("rm -rf build/diff/SLPS_252.33/*@sf*", shell=True)
