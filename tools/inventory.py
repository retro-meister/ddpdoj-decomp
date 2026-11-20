import argparse
from collections import defaultdict
import hashlib
import json
from pathlib import Path
import re
import subprocess

from common import BASEROM, ROOT, TARGETS, verify
from split import split, target_layout, target_units

INSN_RE = re.compile(r"/\*\s*[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\s+([0-9A-Fa-f]{8})\s*\*/\s*(.+?)\s*$")
SYM_RE = re.compile(r"\b(?:func|D|L|jtbl|str)_[0-9A-Fa-f]{8}\b")
LOCAL_RE = re.compile(r"\.L[0-9A-Fa-f]{8}\b")
BRANCH_OPS = {
    "b", "beq", "bne", "beqz", "bnez", "blez", "bgtz", "bltz", "bgez",
    "beql", "bnel", "beqzl", "bnezl", "blezl", "bgtzl", "bltzl", "bgezl",
    "bc1f", "bc1t", "bc1fl", "bc1tl",
}
FP_RE = re.compile(r"\$f\d+|\.s\b|\.w\b|mtc1|mfc1|lwc1|swc1|bc1")
BIT64_OPS = {"ld", "sd", "daddu", "dsubu", "daddiu", "dsll", "dsrl", "dsra", "dsll32", "dsrl32", "dsra32", "dsllv", "dsrlv", "dsrav"}


def normalize_insn(text):
    text = text.split("/*", 1)[0].strip()
    text = SYM_RE.sub("<SYM>", text)
    text = LOCAL_RE.sub("<LBL>", text)
    text = re.sub(r"%(?:hi|lo|gp_rel)\([^)]+\)", "<REL>", text)
    return re.sub(r"\s+", " ", text)


def classify_tier(size, calls, branches, uses_float, uses_jtbl):
    if size <= 48 and calls == 0 and not uses_float and not uses_jtbl:
        return "trivial"
    if size <= 128 and branches <= 3 and not uses_float and not uses_jtbl:
        return "easy"
    if size <= 384 and not uses_jtbl:
        return "medium"
    return "hard"


def scan_game_asm(target_name, split_folder):
    asm_dir = split_folder / "asm"
    functions = []
    for asm in sorted(asm_dir.glob("game_*.s")):
        current = None
        first_addr = None
        last_addr = None
        norm_lines = []
        calls = 0
        branches = 0
        uses_float = False
        uses_64bit = False
        uses_jtbl = False
        for line in asm.read_text(encoding="utf-8").splitlines():
            stripped = line.strip()
            if stripped.startswith("glabel "):
                current = stripped.split()[1]
                first_addr = None
                last_addr = None
                norm_lines = []
                calls = 0
                branches = 0
                uses_float = False
                uses_64bit = False
                uses_jtbl = False
            elif stripped.startswith("endlabel ") and current is not None:
                if first_addr is not None and last_addr is not None:
                    size = last_addr - first_addr + 4
                    digest = hashlib.sha1("\n".join(norm_lines).encode("utf-8")).hexdigest()[:16]
                    functions.append({
                        "target": target_name,
                        "name": current,
                        "address": first_addr,
                        "size": size,
                        "insns": len(norm_lines),
                        "calls": calls,
                        "branches": branches,
                        "is_leaf": calls == 0,
                        "uses_float": uses_float,
                        "uses_64bit": uses_64bit,
                        "uses_jtbl": uses_jtbl,
                        "tier": classify_tier(size, calls, branches, uses_float, uses_jtbl),
                        "matched": False,
                        "hash": digest,
                    })
                current = None
            elif current is not None:
                match = INSN_RE.search(line)
                if match:
                    addr = int(match.group(1), 16)
                    insn = match.group(3)
                    if first_addr is None:
                        first_addr = addr
                    last_addr = addr
                    norm = normalize_insn(insn)
                    norm_lines.append(norm)
                    op = norm.split(" ", 1)[0]
                    if op in ("jal", "jalr"):
                        calls += 1
                    elif op in BRANCH_OPS:
                        branches += 1
                    elif op == "jr" and "$ra" not in norm:
                        uses_jtbl = True
                    if op in BIT64_OPS:
                        uses_64bit = True
                    if FP_RE.search(norm):
                        uses_float = True
    return functions


def matched_entries(target_name):
    entries = []
    for unit in target_units(target_name):
        entries.append({
            "target": target_name,
            "name": unit["name"],
            "address": unit["address"],
            "size": unit["size"],
            "insns": unit["size"] // 4,
            "calls": 0,
            "branches": 0,
            "is_leaf": True,
            "uses_float": False,
            "uses_64bit": False,
            "uses_jtbl": False,
            "tier": "matched",
            "matched": True,
            "source": unit["source"],
            "hash": f"matched:{unit['source']}:{unit['name']}",
        })
    return entries


def pair_main_and_death(main_funcs, death_funcs):
    by_hash_main = defaultdict(list)
    by_hash_death = defaultdict(list)
    for fn in main_funcs:
        by_hash_main[fn["hash"]].append(fn)
    for fn in death_funcs:
        by_hash_death[fn["hash"]].append(fn)

    pairs = 0
    for digest, m_list in by_hash_main.items():
        d_list = by_hash_death.get(digest)
        if not d_list:
            continue
        for m_fn, d_fn in zip(m_list, d_list):
            m_fn["paired_death"] = {"name": d_fn["name"], "address": d_fn["address"]}
            d_fn["paired_main"] = {"name": m_fn["name"], "address": m_fn["address"]}
            pairs += 1
    return pairs


def build_inventory():
    per_target = {}
    for name in TARGETS:
        folder = split(name)
        funcs = scan_game_asm(name, folder) + matched_entries(name)
        funcs.sort(key=lambda fn: fn["address"])
        per_target[name] = funcs
    pairs = pair_main_and_death(per_target["SLPS_252.33"], per_target["DEATH.ELF"])
    return per_target, pairs


def print_summary(per_target, pairs):
    print("Target        | Game Funcs | Game Bytes | Matched | Trivial | Easy | Medium | Hard")
    print("-" * 82)
    for name, funcs in per_target.items():
        total_bytes = sum(fn["size"] for fn in funcs)
        counts = defaultdict(int)
        for fn in funcs:
            counts[fn["tier"]] += 1
        print(
            f"{name:13s} | {len(funcs):10,d} | {total_bytes:10,d} | "
            f"{counts['matched']:7d} | {counts['trivial']:7d} | {counts['easy']:4d} | "
            f"{counts['medium']:6d} | {counts['hard']:4d}"
        )
    main_unmatched = [fn for fn in per_target["SLPS_252.33"] if not fn["matched"]]
    shared_unmatched = [fn for fn in main_unmatched if "paired_death" in fn]
    shared_bytes = sum(fn["size"] for fn in shared_unmatched)
    print(f"\nMain <-> Death Label exact normalized pairs: {pairs:,d} functions ({len(shared_unmatched):,d} unmatched, {shared_bytes:,d} B)")


def main():
    parser = argparse.ArgumentParser(description="Build Arika game-code function inventory and Main <-> Death Label pairing.")
    parser.add_argument("--next", type=int, default=0, help="show the next N easiest unmatched functions")
    parser.add_argument("--target", choices=TARGETS, default="SLPS_252.33")
    parser.add_argument("--tier", choices=("trivial", "easy", "medium", "hard"))
    parser.add_argument("--shared-only", action="store_true")
    args = parser.parse_args()

    per_target, pairs = build_inventory()
    out = ROOT / "build" / "inventory.json"
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps({"pairs": pairs, "targets": per_target}, indent=2) + "\n", encoding="utf-8")
    print_summary(per_target, pairs)
    print(f"Wrote {out.relative_to(ROOT)}")

    if args.next > 0:
        tier_order = {"trivial": 0, "easy": 1, "medium": 2, "hard": 3}
        candidates = [fn for fn in per_target[args.target] if not fn["matched"]]
        if args.tier:
            candidates = [fn for fn in candidates if fn["tier"] == args.tier]
        if args.shared_only:
            candidates = [fn for fn in candidates if "paired_death" in fn or "paired_main" in fn]
        candidates.sort(key=lambda fn: (tier_order[fn["tier"]], 0 if "paired_death" in fn else 1, fn["size"], fn["address"]))
        print(f"\nNext {min(args.next, len(candidates))} candidates in {args.target}:")
        for fn in candidates[:args.next]:
            pair = f" -> DEATH {fn['paired_death']['address']:#x}" if "paired_death" in fn else ""
            print(f"  {fn['name']}  {fn['address']:#08x}  {fn['size']:4d}B  {fn['tier']:7s}  calls={fn['calls']} br={fn['branches']}{pair}")


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError, subprocess.CalledProcessError) as error:
        raise SystemExit(f"Inventory failed: {error}")
