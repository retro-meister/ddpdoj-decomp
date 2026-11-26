"""Compare two MWCCPS2 backend captures across PCode, regalloc, and scheduling."""
import difflib
from pathlib import Path

from mwcc_profiles.ir import diff_ir
from mwcc_profiles.records import pcode_text


def _stage_lines(function, stage_name):
    for stage in function["pcode_stages"]:
        if stage["stage"] == stage_name:
            return pcode_text([{"symbol": function["symbol"], "pcode_stages": [stage]}]).splitlines()
    return []


def _find_function(report, name=None):
    functions = report["functions"]
    if not functions:
        raise ValueError("Capture contains no functions")
    if name is None:
        return functions[0]
    for fn in functions:
        if fn["symbol"] == name:
            return fn
    raise ValueError(f"Function {name!r} not found in capture (available: {[f['symbol'] for f in functions]})")


def diff_reports(report_a, report_b, function_name=None):
    fn_a = _find_function(report_a, function_name)
    fn_b = _find_function(report_b, function_name)

    stages_a = [s["stage"] for s in fn_a["pcode_stages"]]
    stages_b = [s["stage"] for s in fn_b["pcode_stages"]]
    common_stages = [s for s in stages_a if s in stages_b]

    first_diverging_stage = None
    first_stage_diff = []
    stage_summaries = []
    for stage_name in common_stages:
        lines_a = _stage_lines(fn_a, stage_name)
        lines_b = _stage_lines(fn_b, stage_name)
        equal = lines_a == lines_b
        stage_summaries.append({"stage": stage_name, "equal": equal})
        if not equal and first_diverging_stage is None:
            first_diverging_stage = stage_name
            first_stage_diff = list(
                difflib.unified_diff(lines_a, lines_b, fromfile=f"A:{stage_name}", tofile=f"B:{stage_name}", lineterm="")
            )

    alloc_diff = None
    frames_a = fn_a.get("allocation_frames", [])
    frames_b = fn_b.get("allocation_frames", [])
    for idx in range(min(len(frames_a), len(frames_b))):
        fa, fb = frames_a[idx], frames_b[idx]
        simp_a, simp_b = fa["simplification"], fb["simplification"]
        first_simp = None
        for step_idx in range(min(len(simp_a), len(simp_b))):
            if simp_a[step_idx] != simp_b[step_idx]:
                first_simp = {"step": step_idx, "a": simp_a[step_idx], "b": simp_b[step_idx]}
                break
        choices_a, choices_b = fa["choices"], fb["choices"]
        first_choice = None
        for c_idx in range(min(len(choices_a), len(choices_b))):
            ca, cb = choices_a[c_idx], choices_b[c_idx]
            if (ca["node"], ca["selected"], ca.get("enabled_for_retry")) != (
                cb["node"], cb["selected"], cb.get("enabled_for_retry")
            ):
                first_choice = {
                    "index": c_idx,
                    "a": {"node": ca["node"], "selected": ca["selected"], "retry": ca.get("enabled_for_retry")},
                    "b": {"node": cb["node"], "selected": cb["selected"], "retry": cb.get("enabled_for_retry")},
                }
                break
        if first_simp is not None or first_choice is not None or len(simp_a) != len(simp_b):
            alloc_diff = {
                "frame_index": idx,
                "register_class": fa["register_class"],
                "first_simplification_diff": first_simp,
                "first_choice_diff": first_choice,
                "node_counts": [len(fa["nodes"]), len(fb["nodes"])],
                "edge_counts": [len(fa["edges"]), len(fb["edges"])],
            }
            break

    sched_diffs = []
    for sa, sb in zip(fn_a.get("schedules", []), fn_b.get("schedules", [])):
        decs_a = sa.get("decisions", [])
        decs_b = sb.get("decisions", [])
        first_dec = None
        for idx in range(min(len(decs_a), len(decs_b))):
            da, db = decs_a[idx], decs_b[idx]
            if (da["cycle"], da["slot"], da["selected"]) != (db["cycle"], db["slot"], db["selected"]):
                first_dec = {
                    "index": idx,
                    "a": {"cycle": da["cycle"], "slot": da["slot"], "selected": da["selected"], "ready_len": len(da["ready_list"])},
                    "b": {"cycle": db["cycle"], "slot": db["slot"], "selected": db["selected"], "ready_len": len(db["ready_list"])},
                }
                break
        if first_dec is not None or len(decs_a) != len(decs_b):
            sched_diffs.append({
                "pass": sa["pass"],
                "stalls": [sum(1 for d in decs_a if d["stalled"]), sum(1 for d in decs_b if d["stalled"])],
                "issues": [len(sa["issues"]), len(sb["issues"])],
                "first_decision_diff": first_dec,
            })

    ir = diff_ir(fn_a, fn_b) if (fn_a.get("ir_stages") or fn_a.get("iro_phases")) else {
        "first_diverging_ir_stage": None, "ir_stage_diff": [], "ir_stage_summaries": [],
    }

    return {
        **ir,
        "symbol": fn_a["symbol"],
        "objects_identical": report_a["object_sha256"] == report_b["object_sha256"],
        "object_sha256": [report_a["object_sha256"], report_b["object_sha256"]],
        "first_diverging_stage": first_diverging_stage,
        "first_stage_diff": first_stage_diff,
        "stage_summaries": stage_summaries,
        "allocation_diff": alloc_diff,
        "schedule_diffs": sched_diffs,
    }


def format_diff_report(diff, max_diff_lines=60):
    lines = [
        f"Function: {diff['symbol']}",
        f"Objects identical: {diff['objects_identical']} (A={diff['object_sha256'][0][:12]} B={diff['object_sha256'][1][:12]})",
    ]
    if diff.get("ir_stage_summaries"):
        lines.append(f"First diverging frontend IR stage: {diff['first_diverging_ir_stage'] or 'NONE'}")
        for side in ("a", "b"):
            if diff.get(f"ir_stages_only_in_{side}"):
                lines.append(f"  IR phases only in {side.upper()}: {', '.join(diff[f'ir_stages_only_in_{side}'])}")
    lines.append(f"First diverging PCode stage: {diff['first_diverging_stage'] or 'NONE'}")
    if diff["allocation_diff"]:
        ad = diff["allocation_diff"]
        lines.append(
            f"Regalloc diff (frame {ad['frame_index']}, class {ad['register_class']}, "
            f"nodes {ad['node_counts'][0]} vs {ad['node_counts'][1]}, edges {ad['edge_counts'][0]} vs {ad['edge_counts'][1]}):"
        )
        if ad["first_simplification_diff"]:
            s = ad["first_simplification_diff"]
            lines.append(f"  first simplify diff @ step {s['step']}: A={s['a']} | B={s['b']}")
        if ad["first_choice_diff"]:
            c = ad["first_choice_diff"]
            lines.append(f"  first color diff @ #{c['index']}: A={c['a']} | B={c['b']}")
    if diff["schedule_diffs"]:
        lines.append("Schedule diffs:")
        for sd in diff["schedule_diffs"]:
            lines.append(
                f"  pass={sd['pass']} issues={sd['issues'][0]} vs {sd['issues'][1]} "
                f"stalls={sd['stalls'][0]} vs {sd['stalls'][1]}"
            )
            if sd["first_decision_diff"]:
                fd = sd["first_decision_diff"]
                lines.append(f"    first decision diff @ #{fd['index']}: A={fd['a']} | B={fd['b']}")
    if diff.get("ir_stage_diff"):
        lines.append("")
        lines.append(f"Frontend IR diff at {diff['first_diverging_ir_stage']}:")
        shown = diff["ir_stage_diff"][:max_diff_lines]
        lines.extend("  " + l for l in shown)
        if len(diff["ir_stage_diff"]) > max_diff_lines:
            lines.append(f"  ... ({len(diff['ir_stage_diff']) - max_diff_lines} more lines)")
    if diff["first_stage_diff"]:
        lines.append("")
        lines.append(f"PCode diff at {diff['first_diverging_stage']}:")
        shown = diff["first_stage_diff"][:max_diff_lines]
        lines.extend("  " + l for l in shown)
        if len(diff["first_stage_diff"]) > max_diff_lines:
            lines.append(f"  ... ({len(diff['first_stage_diff']) - max_diff_lines} more lines)")
    return "\n".join(lines)
