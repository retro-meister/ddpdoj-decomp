"""Evidence-guided deterministic BFS solver over lossless C-source transforms."""
from argparse import ArgumentParser
from collections import deque
import json
from pathlib import Path
import re
import subprocess
import sys
from tempfile import TemporaryDirectory

from common import ROOT, TARGETS, target_compiler
from trace_mwcc import capture_source, load_profiles


DECL_RE = re.compile(r"^([ \t]+)((?:const\s+|unsigned\s+|signed\s+|struct\s+\w+\s+)?(?:s8|u8|s16|u16|s32|u32|s64|u64|f32|f64|int|char|short|long|void|\w+_t|[A-Z]\w*)\s+\*?\w+(?:\[\d+\])?;[ \t]*)$")
TERNARY_RE = re.compile(r"^([ \t]*)(\w+)\s*=\s*\(([^?;]+)\)\s*\?\s*\(([^:;]+)\)\s*:\s*\(([^;]+)\);[ \t]*$")
TERNARY_SIMPLE_RE = re.compile(r"^([ \t]*)(\w+)\s*=\s*([^?;]+?)\s*\?\s*([^:;]+?)\s*:\s*([^;]+?);[ \t]*$")
COMMUTATIVE_RE = re.compile(r"\b(\w+)\s*(\+|==|!=|\||&)\s*(\w+)\b")
CMP_FLIP = {">": "<", "<": ">", ">=": "<=", "<=": ">="}
CMP_RE = re.compile(r"\b(\w+)\s*(>=|<=|>|<)\s*(\w+|0x[0-9a-fA-F]+|\d+)\b")
SIMPLE_ASSIGN_RE = re.compile(r"^([ \t]*)(\w+)\s*(=|\+=|-=)\s*([^;]+);[ \t]*$")
MATCH_RE = re.compile(r"^(MATCH|DIFFERENT)\s+\S+\s+([0-9.]+)%")


def _identifiers(expr):
    return set(re.findall(r"\b[A-Za-z_]\w*\b", expr))


def generate_transforms(source_text):
    """Yield (description, transformed_source) pairs for lossless C transforms."""
    lines = source_text.splitlines(keepends=True)
    seen = {source_text}

    def emit(desc, new_text):
        if new_text not in seen:
            seen.add(new_text)
            return (desc, new_text)
        return None

    results = []

    # 1. Adjacent local declaration swaps (uninitialized declarations at same indent).
    for i in range(len(lines) - 1):
        m1 = DECL_RE.match(lines[i].rstrip("\r\n"))
        m2 = DECL_RE.match(lines[i + 1].rstrip("\r\n"))
        if m1 and m2 and m1.group(1) == m2.group(1):
            swapped = lines[:]
            swapped[i], swapped[i + 1] = swapped[i + 1], swapped[i]
            item = emit(f"swap_decl@{i + 1}", "".join(swapped))
            if item:
                results.append(item)

    # 2. Ternary -> if/else.
    for i, line in enumerate(lines):
        stripped = line.rstrip("\r\n")
        m = TERNARY_RE.match(stripped) or TERNARY_SIMPLE_RE.match(stripped)
        if m and "?" in stripped and ":" in stripped and "case " not in stripped:
            indent, lhs, cond, t_expr, f_expr = m.groups()
            replacement = (
                f"{indent}if ({cond.strip()}) {{\n"
                f"{indent}    {lhs} = {t_expr.strip()};\n"
                f"{indent}}} else {{\n"
                f"{indent}    {lhs} = {f_expr.strip()};\n"
                f"{indent}}}\n"
            )
            new_lines = lines[:i] + [replacement] + lines[i + 1:]
            item = emit(f"ternary_to_if@{i + 1}", "".join(new_lines))
            if item:
                results.append(item)

    # 3. Adjacent independent simple assignments (no shared lhs/rhs identifiers and no function calls).
    for i in range(len(lines) - 1):
        m1 = SIMPLE_ASSIGN_RE.match(lines[i].rstrip("\r\n"))
        m2 = SIMPLE_ASSIGN_RE.match(lines[i + 1].rstrip("\r\n"))
        if m1 and m2 and m1.group(1) == m2.group(1):
            lhs1, rhs1 = m1.group(2), m1.group(4)
            lhs2, rhs2 = m2.group(2), m2.group(4)
            if "(" in rhs1 or "(" in rhs2 or "[" in rhs1 or "[" in rhs2 or "->" in rhs1 or "->" in rhs2:
                continue
            if lhs1 != lhs2 and lhs1 not in _identifiers(rhs2) and lhs2 not in _identifiers(rhs1):
                swapped = lines[:]
                swapped[i], swapped[i + 1] = swapped[i + 1], swapped[i]
                item = emit(f"swap_assign@{i + 1}", "".join(swapped))
                if item:
                    results.append(item)

    # 4. Commutative binary operand swaps on single lines (excluding declarations/includes/labels).
    for i, line in enumerate(lines):
        if line.lstrip().startswith(("#", "//", "/*", "extern ", "typedef ")):
            continue
        for m in COMMUTATIVE_RE.finditer(line):
            a, op, b = m.groups()
            if a == b:
                continue
            new_line = line[:m.start()] + f"{b} {op} {a}" + line[m.end():]
            new_lines = lines[:i] + [new_line] + lines[i + 1:]
            item = emit(f"commute({a}{op}{b})@{i + 1}", "".join(new_lines))
            if item:
                results.append(item)

    # 5. Comparison flips (a > b <-> b < a).
    for i, line in enumerate(lines):
        if "if (" not in line and "while (" not in line and "?" not in line:
            continue
        for m in CMP_RE.finditer(line):
            a, op, b = m.groups()
            flipped = CMP_FLIP[op]
            new_line = line[:m.start()] + f"{b} {flipped} {a}" + line[m.end():]
            new_lines = lines[:i] + [new_line] + lines[i + 1:]
            item = emit(f"flip_cmp({a}{op}{b})@{i + 1}", "".join(new_lines))
            if item:
                results.append(item)

    return results


def evaluate_candidate(target, function_name, source_path, compiler_name):
    cmd = [
        sys.executable, str(ROOT / "tools/diff.py"),
        target, function_name,
        "--source", str(source_path),
        "--compiler", compiler_name,
        "--compact",
    ]
    proc = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
    output = proc.stdout + proc.stderr
    matched = False
    pct = 0.0
    for line in output.splitlines():
        m = MATCH_RE.match(line.strip())
        if m:
            matched = m.group(1) == "MATCH"
            pct = float(m.group(2))
            break
    diff_lines = sum(1 for l in output.splitlines() if l.lstrip().startswith(("~", "+", "-")))
    return matched, pct, diff_lines, output


def trace_signature(source_path, scratch_dir, compiler_name, profiles):
    report, _ = capture_source(source_path, scratch_dir, compiler_name, profiles)
    fn = report["functions"][0]
    alloc_sig = tuple(
        (f["register_class"], tuple((c["node"], c["selected"]) for c in f["choices"]))
        for f in fn.get("allocation_frames", [])
    )
    sched_sig = tuple(
        (s["pass"], len(s["issues"]), sum(1 for d in s.get("decisions", []) if d["stalled"]))
        for s in fn.get("schedules", [])
    )
    return (report["object_sha256"], alloc_sig, sched_sig)


def main():
    profiles = load_profiles()
    parser = ArgumentParser(description=__doc__)
    parser.add_argument("target", choices=TARGETS)
    parser.add_argument("function")
    parser.add_argument("--source", type=Path, required=True)
    parser.add_argument("--compiler", choices=profiles, help="override the target's configured compiler")
    parser.add_argument("--max-depth", type=int, default=2)
    parser.add_argument("--max-candidates", type=int, default=40)
    parser.add_argument("--trace", action="store_true", help="deduplicate and record compiler-internal trace signatures")
    parser.add_argument("--out", type=Path, help="write the best or matched C source to this path")
    options = parser.parse_args()
    options.compiler = target_compiler(options.target, override=options.compiler)

    baseline_text = options.source.resolve(strict=True).read_text(encoding="utf-8")

    with TemporaryDirectory(prefix="ddpdoj-solve-") as scratch:
        scratch_dir = Path(scratch)
        base_file = scratch_dir / "cand_0.c"
        base_file.write_text(baseline_text, encoding="utf-8")
        matched, base_pct, base_diffs, _ = evaluate_candidate(
            options.target, options.function, base_file, options.compiler
        )
        print(f"Baseline: {'MATCH' if matched else 'DIFFERENT'} {base_pct:.2f}% ({base_diffs} diff lines)")
        if matched:
            if options.out:
                options.out.write_text(baseline_text, encoding="utf-8")
            return

        seen_sources = {baseline_text}
        seen_sigs = set()
        if options.trace:
            seen_sigs.add(trace_signature(base_file, scratch_dir / "trace_0", options.compiler, profiles))

        best = (matched, base_pct, -base_diffs, [], baseline_text)
        queue = deque([(0, [], baseline_text)])
        evaluated = 0

        while queue and evaluated < options.max_candidates:
            depth, path, current_text = queue.popleft()
            if depth >= options.max_depth:
                continue
            for desc, cand_text in generate_transforms(current_text):
                if cand_text in seen_sources or evaluated >= options.max_candidates:
                    continue
                seen_sources.add(cand_text)
                evaluated += 1
                cand_file = scratch_dir / f"cand_{evaluated}.c"
                cand_file.write_text(cand_text, encoding="utf-8")
                c_matched, c_pct, c_diffs, _ = evaluate_candidate(
                    options.target, options.function, cand_file, options.compiler
                )
                sig_note = ""
                if options.trace:
                    try:
                        sig = trace_signature(cand_file, scratch_dir / f"trace_{evaluated}", options.compiler, profiles)
                        if sig in seen_sigs and not c_matched:
                            continue
                        seen_sigs.add(sig)
                        sig_note = f" obj={sig[0][:8]}"
                    except Exception:
                        pass

                new_path = [*path, desc]
                score = (c_matched, c_pct, -c_diffs)
                if score > best[:3]:
                    best = (c_matched, c_pct, -c_diffs, new_path, cand_text)
                    print(
                        f"[{evaluated}/{options.max_candidates}] NEW BEST: "
                        f"{'MATCH' if c_matched else 'DIFFERENT'} {c_pct:.2f}% ({c_diffs} diffs){sig_note} via {' -> '.join(new_path)}"
                    )
                if c_matched:
                    if options.out:
                        options.out.write_text(cand_text, encoding="utf-8")
                    print(f"Solved in {evaluated} candidate(s): {' -> '.join(new_path)}")
                    return
                if depth + 1 < options.max_depth:
                    queue.append((depth + 1, new_path, cand_text))

        print(
            f"Finished {evaluated} candidate(s). Best: {best[1]:.2f}% ({-best[2]} diffs)"
            + (f" via {' -> '.join(best[3])}" if best[3] else " (baseline)")
        )
        if options.out and best[3]:
            options.out.write_text(best[4], encoding="utf-8")


if __name__ == "__main__":
    main()
