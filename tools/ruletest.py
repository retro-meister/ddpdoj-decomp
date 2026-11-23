"""Test a draft rewrite rule across every open mapped draft and keep only the improvements.

    uv run tools/ruletest.py RULE.py [--keep]

RULE.py defines `fix(code) -> code`. Each open function's current best draft (build/work/<fn>.c, else
build/arc/<fn>.fix.c) is rewritten, both versions are scored with tools/diff.py, and with --keep every
improvement is written back to build/work/. Covers every unmatched game function.
"""
import sys, os, re, subprocess, importlib.util, glob
from concurrent.futures import ThreadPoolExecutor
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__))); os.chdir(ROOT)
os.makedirs("build/rule", exist_ok=True)
spec = importlib.util.spec_from_file_location("rule", sys.argv[1]); rule = importlib.util.module_from_spec(spec); spec.loader.exec_module(rule)
def open_functions():
    """Every unmatched game function (address >= 0x119B10) in SLPS_252.33."""
    sys.path.insert(0, "tools")
    from split import split, scan_asm_functions
    done = {f[:-2] for f in os.listdir("src/main")}
    funcs = scan_asm_functions(split("SLPS_252.33") / "asm")
    return [n for n, (a, s) in sorted(funcs.items(), key=lambda kv: kv[1][0]) if a >= 0x119B10 and n not in done]


keep = "--keep" in sys.argv
done = {f[:-2] for f in os.listdir("src/main")}
fns = open_functions()
def cur(fn):
    for p in (f"build/work/{fn}.c", f"build/arc/{fn}.fix.c"):
        if os.path.exists(p): return p
def score(fn, src, tag):
    out = subprocess.run(["uv","run","tools/diff.py","SLPS_252.33",fn,"--source",src,"--compact","--max-diffs","2000","--tag",tag],capture_output=True,text=True).stdout
    if re.search(r"^MATCH", out, re.M): return (100.0, 0)
    m = re.search(r"^DIFFERENT\s+\S+\s+([\d.]+)%", out, re.M)
    if not m: return (-1.0, 10**6)
    return (float(m.group(1)), -len(re.findall(r"^  [~<>+-]", out, re.M)))
def one(fn):
    src = cur(fn)
    if fn in done or not src: return None
    code = open(src).read(); new = rule.fix(code)
    if new == code: return None
    dst = f"build/rule/{fn}.c"; open(dst, "w").write(new)
    a = score(fn, src, "rtA"); b = score(fn, dst, "rtB")
    return fn, a, b, dst
res = [r for r in ThreadPoolExecutor(6).map(one, fns) if r]
up = [r for r in res if r[2] > r[1]]; down = [r for r in res if r[2] < r[1]]
for fn, a, b, dst in sorted(res, key=lambda r: -r[2][0]):
    tag = "MATCH" if b[0] == 100 else "UP" if b > a else "DOWN" if b < a else "same"
    print(f"{tag:5} {fn} {a[0]:.2f}%/{-a[1]} -> {b[0]:.2f}%/{-b[1]}")
print(f"applied {len(res)}  up {len(up)}  down {len(down)}  match {sum(1 for r in res if r[2][0]==100)}")
if keep:
    for fn, a, b, dst in up:
        open(f"build/work/{fn}.c", "w").write(open(dst).read())
    print(f"kept {len(up)}")
for d in glob.glob("build/diff/SLPS_252.33/*@rt*"):
    subprocess.run(["rm","-rf",d])
