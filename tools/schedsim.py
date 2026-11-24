"""Replay MWCCPS2's list-scheduler choices from a trace and test what-ifs.

Ported from the mweppc decompilation of the PS2 backend Scheduler.c (fn_004C0740 picks
the next instruction, fn_004C11F0 is the register-pressure score, fn_004C13B0 and
fn_004C14A0 keep the live-register counts). The dependence graph is recovered from the
trace itself: a node's successors are the nodes whose unscheduled-predecessor count
drops right after it issues.

    uv run tools/schedsim.py CAPTURE [--pass early] [--block N] [--k K]
        replay every decision; prints the agreement rate and the mismatches
    uv run tools/schedsim.py CAPTURE --block N --cycle C --drop REG [REG ...]
        what-if: re-run the decision at cycle C of block N with the given virtual
        registers treated as not live (one fewer value), and show the new pick

The pressure test (`live >= K`) needs K, the allocator's register count for the class;
by default it is fitted to the trace (the value that explains the most decisions).
"""
import argparse
from collections import defaultdict
import json
from pathlib import Path

USE, DEF = 1, 2
RESERVED = {0, 26, 27, 28, 29, 31}


def counted(r):
    return r[1] >= 32 or (r[0] == 0 and r[1] not in RESERVED)


def load(path, pass_name):
    capture = json.loads(Path(path).read_text())
    function = capture["functions"][0]
    stage = "before_schedule" if pass_name == "early" else "before_late_schedule"
    pcode = next(s for s in function["pcode_stages"] if s["stage"] == stage)["pcode"]
    schedule = next(s for s in function["schedules"] if s["pass"] == pass_name)
    blocks = defaultdict(list)
    for index, instr in enumerate(pcode):
        instr["ordinal"] = index
        blocks[instr["block"]].append(instr)
    return function["symbol"], blocks, schedule, pcode


def regs(instr, effect):
    out = []
    for op in instr["operands"]:
        if op["kind"] == 0 and op["flags"] & effect:
            out.append((op["class"], op["register"]))
    return out


def liveness(blocks):
    """Per-block live-in/live-out sets of virtual registers (>= 32)."""
    order = sorted(blocks)
    succ = {}
    for i, b in enumerate(order):
        last = blocks[b][-1] if blocks[b] else None
        targets = [op["target_block"] for ins in blocks[b] for op in ins["operands"] if op["kind"] == 6]
        mnem = last["mnemonic"] if last else ""
        out = set(targets)
        if mnem == "jr":
            out = set(order)  # switch: over-approximate
        elif mnem not in ("b", ".end") and i + 1 < len(order):
            out.add(order[i + 1])
        succ[b] = out
    use, kill = {}, {}
    for b in order:
        u, k = set(), set()
        for ins in blocks[b]:
            for r in regs(ins, USE):
                if r[1] >= 32 and r not in k:
                    u.add(r)
            for r in regs(ins, DEF):
                if r[1] >= 32:
                    k.add(r)
        use[b], kill[b] = u, k
    live_in = {b: set() for b in order}
    live_out = {b: set() for b in order}
    changed = True
    while changed:
        changed = False
        for b in reversed(order):
            out = set().union(*(live_in[s] for s in succ[b] if s in live_in)) if succ[b] else set()
            inn = use[b] | (out - kill[b])
            if out != live_out[b] or inn != live_in[b]:
                live_out[b], live_in[b] = out, inn
                changed = True
    return live_in, live_out


class BlockReplay:
    def __init__(self, block, instrs, decisions, live_in, live_out, pcode):
        self.block = block
        self.block_instrs = instrs
        self.instrs = pcode
        self.decisions = decisions
        self.live_in = live_in
        self.live_out = live_out
        self.succ = self.recover_successors()
        self.always_pressure = False

    def recover_successors(self):
        succ = defaultdict(set)
        for cur, nxt in zip(self.decisions, self.decisions[1:]):
            chosen = cur["selected"]
            if chosen is None:
                continue
            before = {r["input_ordinal"]: r["unscheduled_preds"] for r in cur["ready_list"]}
            after = {r["input_ordinal"]: r["unscheduled_preds"] for r in nxt["ready_list"]}
            for node, preds in after.items():
                if node in before and preds < before[node]:
                    succ[chosen["input_ordinal"]].add(node)
        return succ

    def counts_at(self, issued, dropped=()):
        """(available, counts) after the given issued ordinals (fn_004C14A0 + fn_004C13B0)."""
        counts = defaultdict(int)
        for r in self.live_out:
            if r not in dropped:
                counts[r] = 1
        for ins in self.block_instrs:
            for r in regs(ins, USE):
                if counted(r) and r not in dropped:
                    counts[r] += 1
        available = sum(1 for r in self.live_in if r not in dropped)
        for ordinal in issued:
            ins = self.instrs[ordinal]
            for r in regs(ins, USE):
                if counted(r) and r not in dropped:
                    counts[r] -= 1
                    if counts[r] == 0:
                        available -= 1
            for r in regs(ins, DEF):
                if counted(r) and r not in dropped and counts[r] and r not in regs(ins, USE):
                    available += 1
        return available, counts

    def pressure_score(self, ordinal, available, k, counts):
        ins = self.instrs[ordinal]
        score = 16
        used = [r for r in regs(ins, USE) if counted(r)]
        for r in used:
            counts[r] -= 1
        extra = max(available - k, 1) if available - k >= 2 else 1
        for r in used:
            if counts[r] == 0:
                score -= 1 + extra
        for r in regs(ins, DEF):
            if counted(r) and counts[r] and r not in regs(ins, USE):
                score += extra
        for r in used:
            counts[r] += 1
        return score

    def is_mem(self, ordinal):
        return bool(self.instrs[ordinal]["flags"] & 0x6)

    def pick(self, decision, issued, k, dropped=(), same_cycle=()):
        cycle = decision["cycle"]
        mem_busy = any(self.is_mem(o) for o in same_cycle)
        ready = sorted(decision["ready_list"], key=lambda r: r["input_ordinal"])
        info = {r["input_ordinal"]: r for r in ready}
        eligible = [r["input_ordinal"] for r in ready
                    if r["unscheduled_preds"] == 0 and r["earliest_cycle"] <= cycle
                    and not (mem_busy and self.is_mem(r["input_ordinal"]))]
        if not eligible:
            return None, False
        available, counts = self.counts_at(issued, dropped)
        if self.always_pressure or available >= k:
            best = eligible[0]
            best_score = self.pressure_score(best, available, k, counts)
            for cand in eligible[1:]:
                s = self.pressure_score(cand, available, k, counts)
                if s < best_score:
                    best, best_score = cand, s
            return best, True
        preds = {r["input_ordinal"]: r["unscheduled_preds"] for r in ready}

        def freed(node):
            return sum(1 for s in self.succ.get(node, ()) if preds.get(s) == 1)

        best = eligible[0]
        for cand in eligible[1:]:
            b, c = info[best], info[cand]
            if b["preferred_cycle"] <= cycle and c["preferred_cycle"] > cycle:
                continue
            if b["preferred_cycle"] > cycle and c["preferred_cycle"] <= cycle:
                best = cand
                continue
            fb, fc = freed(best), freed(cand)
            if fb < fc:
                best = cand
            elif fb == fc:
                if b["priority"] < c["priority"]:
                    best = cand
                elif b["priority"] == c["priority"] and b["earliest_cycle"] > c["earliest_cycle"]:
                    best = cand
        return best, False

    def replay(self, k):
        issued, results, cycles = [], [], {}
        for d in self.decisions:
            if d["selected"] is None:
                continue
            actual = d["selected"]["input_ordinal"]
            same = [o for o in issued if cycles[o] == d["cycle"]]
            predicted, pressure = self.pick(d, issued, k, same_cycle=same)
            results.append((d["cycle"], d["slot"], actual, predicted, pressure))
            issued.append(actual)
            cycles[actual] = d["cycle"]
        return results


def build(path, pass_name):
    symbol, blocks, schedule, pcode = load(path, pass_name)
    live_in, live_out = liveness(blocks)
    per_block = defaultdict(list)
    for d in schedule["decisions"]:
        block = (d["selected"] or (d["ready_list"][0] if d["ready_list"] else {})).get("block")
        if block is not None:
            per_block[block].append(d)
    replays = {b: BlockReplay(b, blocks[b], ds, live_in[b], live_out[b], pcode) for b, ds in per_block.items()}
    return symbol, blocks, replays


def describe(instr):
    parts = []
    for op in instr["operands"]:
        if op["kind"] == 0:
            parts.append(f"r{op['register']}")
        elif op["kind"] == 4:
            parts.append(op.get("symbol") or "imm")
    return f"{instr['mnemonic']} {', '.join(parts)}"


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("capture", type=Path)
    parser.add_argument("--pass", dest="pass_name", default="early", choices=("early", "late"))
    parser.add_argument("--block", type=int)
    parser.add_argument("--k", type=int, help="register count for the pressure test (default: fitted)")
    parser.add_argument("--cycle", type=int)
    parser.add_argument("--slot", type=int)
    parser.add_argument("--drop", nargs="*", type=int, default=[], help="virtual registers to treat as not live")
    parser.add_argument("--show", type=int, default=15)
    parser.add_argument("--normal-test", action="store_true", help="use the live>=K test instead of always-on pressure mode")
    args = parser.parse_args()
    path = args.capture / "capture.json" if args.capture.is_dir() else args.capture
    symbol, blocks, replays = build(path, args.pass_name)
    targets = [args.block] if args.block is not None else sorted(replays)
    for rep in replays.values():
        rep.always_pressure = not args.normal_test

    def agreement(k):
        total = good = 0
        for b in targets:
            for _, _, actual, predicted, _ in replays[b].replay(k):
                total += 1
                good += actual == predicted
        return good, total

    k = args.k
    if k is None:
        k = max(range(1, 40), key=lambda kk: agreement(kk)[0])
    good, total = agreement(k)
    print(f"{symbol} ({args.pass_name} pass): K={k}, replay agrees on {good}/{total} decisions")

    if args.cycle is not None and args.block is not None:
        rep = replays[args.block]
        issued, cycles = [], {}
        for d in rep.decisions:
            if d["selected"] is None:
                continue
            same = [o for o in issued if cycles[o] == d["cycle"]]
            if d["cycle"] == args.cycle and (args.slot is None or d["slot"] == args.slot):
                base, pb = rep.pick(d, issued, k, same_cycle=same)
                dropped = {(0, r) for r in args.drop}
                new, pn = rep.pick(d, issued, k, dropped, same_cycle=same)
                print(f"block {args.block} cycle {args.cycle} slot {d['slot']}: compiler picked "
                      f"#{d['selected']['input_ordinal']} {describe(rep.instrs[d['selected']['input_ordinal']])}")
                print(f"  replay: #{base} {describe(rep.instrs[base])} ({'pressure' if pb else 'normal'} mode)")
                print(f"  with r{args.drop} not live: #{new} {describe(rep.instrs[new])} ({'pressure' if pn else 'normal'} mode)")
                break
            issued.append(d["selected"]["input_ordinal"])
            cycles[d["selected"]["input_ordinal"]] = d["cycle"]
        return

    shown = 0
    for b in targets:
        for cycle, slot, actual, predicted, pressure in replays[b].replay(k):
            if actual != predicted and shown < args.show:
                ins = replays[b].instrs
                print(f"  block {b} cycle {cycle}/{slot}: compiler #{actual} {describe(ins[actual])}, "
                      f"replay #{predicted} {describe(ins[predicted]) if predicted is not None else '-'}"
                      f" ({'pressure' if pressure else 'normal'})")
                shown += 1


if __name__ == "__main__":
    main()
