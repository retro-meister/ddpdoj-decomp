"""Replay and perturb MWCCPS2's graph-colouring register allocator from a trace.

Reads a `tools/trace_mwcc.py` capture (capture.json), rebuilds the final interference
graph of an allocation frame, and re-runs the compiler's colouring (ported from the
mweppc decompilation of `Coloring.c`: pop the simplification stack, take the lowest free
colour, enable the next non-volatile register when none is free).

    uv run tools/regsim.py CAPTURE [--frame -1] --check
        replay the frame and confirm every colour matches the compiler's own choice
    uv run tools/regsim.py CAPTURE --want 33=8 381=13 [--keep]
        search single perturbations (move one node in the colouring order, add one
        interference edge) that give the wanted colours; --keep also requires every other
        virtual node to keep its colour

Colours are MIPS register numbers (2=v0, 4=a0, 8=t0, 16=s0, 24=t8, 30=fp). Nodes are the
virtual register numbers shown in the trace (regalloc.txt / pcode.txt).
"""
import argparse
import json
from pathlib import Path
import sys

REG_NAMES = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
             "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"]


def reg(color):
    return REG_NAMES[color] if 0 <= color < 32 else str(color)


class Frame:
    def __init__(self, frame):
        self.nodes = {n["slot"]: n for n in frame["nodes"]}
        self.physical = sum(1 for n in frame["nodes"] if n["physical"])
        self.adj = {slot: set() for slot in self.nodes}
        for low, high in frame["edges"]:
            self.adj[low].add(high)
            self.adj[high].add(low)
        choices = frame["choices"]
        self.initial_mask = choices[0]["initial_mask"] if choices else 0
        self.nonvolatile = [c["enabled_for_retry"] for c in choices if "enabled_for_retry" in c]
        # Colouring order = the order of the compiler's own final choices.
        self.order = [c["node"] for c in choices if c["selected"] != -1]
        self.actual = {c["node"]: c["selected"] for c in choices if c["selected"] != -1}
        self.pairs = {slot for slot, n in self.nodes.items() if n["flags"] & 0x200}

    def color(self, order=None, extra_edges=()):
        """Run colorgraph() over `order`; returns {node: colour} or None if it fails."""
        order = self.order if order is None else order
        adj = self.adj
        if extra_edges:
            adj = {k: set(v) for k, v in self.adj.items()}
            for a, b in extra_edges:
                adj[a].add(b)
                adj[b].add(a)
        colors = {slot: slot for slot in range(self.physical)}
        mask = self.initial_mask
        spare = list(self.nonvolatile)
        for node in order:
            while True:
                working = mask
                for other in adj.get(node, ()):
                    c = colors.get(other, -1)
                    if c != -1:
                        working &= ~((3 if other in self.pairs else 1) << c)
                chosen = -1
                if node in self.pairs:
                    for i in range(0, 32, 2):
                        if working & (3 << i) == (3 << i):
                            chosen = i
                            break
                else:
                    for i in range(32):
                        if working & (1 << i):
                            chosen = i
                            break
                if chosen == -1 and spare:
                    mask |= 1 << spare.pop(0)
                    continue
                break
            if chosen == -1:
                return None
            colors[node] = chosen
        return colors


def load_frame(path, index, register_class=0):
    capture = json.loads(Path(path).read_text())
    function = capture["functions"][0]
    frames = [f for f in function["allocation_frames"] if f["register_class"] == register_class]
    return function["symbol"], Frame(frames[index])


def check(frame):
    colors = frame.color()
    bad = [(n, frame.actual[n], colors.get(n)) for n in frame.order if colors.get(n) != frame.actual[n]]
    return colors, bad


def search(frame, want, keep):
    base = frame.color()
    virtual = [n for n in frame.order]

    def ok(colors):
        if colors is None or any(colors.get(n) != c for n, c in want.items()):
            return False
        if keep:
            return all(colors[n] == base[n] for n in virtual if n not in want)
        return True

    def changed(colors):
        return sum(1 for n in virtual if colors[n] != base[n])

    results = []
    order = frame.order
    for node in want:
        if node not in order:
            print(f"node {node} is not coloured in this frame", file=sys.stderr)
            continue
    # 1) move one node to another position in the colouring order
    for i, node in enumerate(order):
        rest = order[:i] + order[i + 1:]
        for j in range(len(rest) + 1):
            if j == i:
                continue
            trial = rest[:j] + [node] + rest[j:]
            colors = frame.color(trial)
            if ok(colors):
                results.append((changed(colors), f"move {node} from position {i} to {j}"
                                f" (now before {rest[j] if j < len(rest) else 'end'})"))
    # 2) add one interference edge
    for a in virtual:
        for b in list(range(frame.physical)) + virtual:
            if a == b or b in frame.adj[a]:
                continue
            if b >= frame.physical and b < a:
                continue
            colors = frame.color(extra_edges=[(a, b)])
            if ok(colors):
                results.append((changed(colors), f"add edge {a}-{b} ({reg(base.get(b, b)) if b < frame.physical else 'node ' + str(b)})"))
    results.sort()
    return results


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("capture", type=Path, help="capture.json or the trace output folder")
    parser.add_argument("--frame", type=int, default=-1, help="allocation frame index (default: last, the successful one)")
    parser.add_argument("--check", action="store_true")
    parser.add_argument("--want", nargs="*", default=[], help="NODE=COLOUR (number or register name)")
    parser.add_argument("--keep", action="store_true", help="other nodes must keep their colours")
    parser.add_argument("--limit", type=int, default=30)
    args = parser.parse_args()
    path = args.capture / "capture.json" if args.capture.is_dir() else args.capture
    symbol, frame = load_frame(path, args.frame)
    colors, bad = check(frame)
    print(f"{symbol}: {len(frame.order)} coloured nodes, {sum(map(len, frame.adj.values())) // 2} edges, "
          f"replay {'exact' if not bad else f'MISMATCH on {len(bad)} node(s)'}")
    for n, actual, sim in bad[:10]:
        print(f"  node {n}: compiler {reg(actual)}, simulator {reg(sim) if sim is not None else '-'}")
    if args.want:
        want = {}
        for item in args.want:
            node, color = item.split("=")
            want[int(node)] = REG_NAMES.index(color) if color in REG_NAMES else int(color)
        print("current: " + ", ".join(f"{n}={reg(colors[n])}" for n in want))
        results = search(frame, want, args.keep)
        print(f"{len(results)} single perturbation(s) give the wanted colours")
        for nchanged, text in results[:args.limit]:
            print(f"  {text}  [{nchanged} node(s) change colour]")


if __name__ == "__main__":
    main()
