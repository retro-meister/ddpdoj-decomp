import argparse
from datetime import datetime
import json
from pathlib import Path
import re
import subprocess
import sys
import yaml

from build import OBJ_CACHE
from common import ROOT, TARGETS, read_json, require_local, run, target_compiler
from objects import defined_function_count
from inventory import build_inventory
from split import SIZE_RE, SYMBOL_RE, target_units

HISTORY = ROOT / "config/progress-history.json"
GRAPH_DIR = ROOT / "docs"
GRAPH_NAMES = {"SLPS_252.33": "progress-main.svg", "DEATH.ELF": "progress-death.svg", "GALLERY.ELF": "progress-gallery.svg"}
LABELS = {"SLPS_252.33": "Main game", "DEATH.ELF": "Death Label", "GALLERY.ELF": "Gallery"}
GALLERY_ALL_FUNCTIONS_COMMIT = "80efe77"


def matched_function_count(name, local):
    version = target_compiler(name, local)
    return sum(
        defined_function_count(OBJ_CACHE / version / f"{unit['source']}.o")
        for unit in target_units(name)
    )


def parse_timestamp(snapshot):
    raw = snapshot.get("timestamp") or snapshot["date"]
    dt = datetime.fromisoformat(raw)
    if dt.tzinfo is not None:
        dt = dt.astimezone().replace(tzinfo=None)
    return dt


def git_output(*args):
    result = subprocess.run(
        ["git", *args], cwd=ROOT, capture_output=True, text=True, check=False
    )
    if result.returncode != 0:
        return None
    return result.stdout


def parse_units_from_text(yaml_text, sym_text):
    config = yaml.safe_load(yaml_text)
    symbols = {}
    if sym_text:
        for line in sym_text.splitlines():
            match = SYMBOL_RE.match(line)
            if not match:
                continue
            sym_name, addr_str, rest = match.groups()
            size_match = SIZE_RE.search(rest)
            size = int(size_match.group(1), 0) if size_match else None
            symbols[int(addr_str, 0)] = (sym_name, size)
    main = next(
        (seg for seg in config.get("segments", []) if isinstance(seg, dict) and seg.get("name") == "main"),
        None,
    )
    if main is None:
        return []
    file_address = int(main["vram"]) - int(main["start"])
    subsegments = main.get("subsegments", [])
    units = []
    for index, sub in enumerate(subsegments):
        if not (isinstance(sub, list) and len(sub) >= 3 and sub[1] == "c"):
            continue
        offset = int(sub[0])
        address = file_address + offset
        _, sym_size = symbols.get(address, (None, None))
        next_offset = int(subsegments[index + 1][0]) if index + 1 < len(subsegments) else offset
        span = next_offset - offset
        size = sym_size if sym_size is not None else span
        units.append((address, address + max(size, span), size))
    return units


def known_functions(inventory):
    """Map target -> sorted list of (address, size) for all game functions."""
    result = {}
    for name in TARGETS:
        if name == "GALLERY.ELF":
            y = git_output("show", f"{GALLERY_ALL_FUNCTIONS_COMMIT}:config/GALLERY.ELF/splat.yaml")
            s = git_output("show", f"{GALLERY_ALL_FUNCTIONS_COMMIT}:config/GALLERY.ELF/symbols.txt")
            if y:
                result[name] = sorted((start, size) for start, _, size in parse_units_from_text(y, s))
                continue
        result[name] = sorted((fn["address"], fn["size"]) for fn in inventory[name])
    return result


def count_matched_from_units(units, known):
    matched_fns = 0
    matched_bytes = 0
    for start, end, size in units:
        inside = [(a, sz) for a, sz in known if start <= a < end]
        if len(inside) > 1:
            matched_fns += len(inside)
            matched_bytes += sum(sz for _, sz in inside)
        elif len(inside) == 1:
            matched_fns += 1
            matched_bytes += inside[0][1]
        else:
            matched_fns += 1
            matched_bytes += size
    return matched_fns, matched_bytes


def backfill_from_git():
    inventory, _ = build_inventory()
    local = require_local()
    fn_map = known_functions(inventory)
    totals = {}
    for name in TARGETS:
        matched_fns = matched_function_count(name, local)
        unmatched = sum(1 for fn in inventory[name] if not fn["matched"])
        totals[name] = {
            "total_functions": matched_fns + unmatched,
            "total_bytes": sum(sz for _, sz in fn_map[name]),
        }

    log = git_output("log", "--reverse", "--format=%h %aI", "--", "config/*/splat.yaml")
    if not log:
        raise ValueError("No git history found for config/*/splat.yaml")

    history = []
    for line in log.splitlines():
        if not line.strip():
            continue
        commit, timestamp = line.split(" ", 1)
        targets = {}
        for name in TARGETS:
            yaml_text = git_output("show", f"{commit}:config/{name}/splat.yaml")
            if not yaml_text:
                targets[name] = {
                    "functions": 0,
                    "total_functions": totals[name]["total_functions"],
                    "bytes": 0,
                    "total_bytes": totals[name]["total_bytes"],
                }
                continue
            sym_text = git_output("show", f"{commit}:config/{name}/symbols.txt") or ""
            units = parse_units_from_text(yaml_text, sym_text)
            matched_fns, matched_bytes = count_matched_from_units(units, fn_map[name])
            targets[name] = {
                "functions": matched_fns,
                "total_functions": totals[name]["total_functions"],
                "bytes": matched_bytes,
                "total_bytes": totals[name]["total_bytes"],
            }
        if history and history[-1]["targets"] == targets:
            continue
        history.append({"timestamp": timestamp, "commit": commit, "targets": targets})

    pending = HISTORY.with_suffix(".tmp")
    pending.write_text(json.dumps(history, indent=2) + "\n", encoding="utf-8")
    pending.replace(HISTORY)
    return history


def record_snapshot(history):
    run(sys.executable, str(ROOT / "tools/build.py"))
    inventory, _ = build_inventory()
    local = require_local()
    fn_map = known_functions(inventory)
    targets = {}
    for name in TARGETS:
        yaml_text = (ROOT / "config" / name / "splat.yaml").read_text(encoding="utf-8")
        sym_text = (ROOT / "config" / name / "symbols.txt").read_text(encoding="utf-8")
        units = parse_units_from_text(yaml_text, sym_text)
        _, matched_bytes = count_matched_from_units(units, fn_map[name])
        matched_functions = matched_function_count(name, local)
        unmatched = sum(1 for fn in inventory[name] if not fn["matched"])
        targets[name] = {
            "functions": matched_functions,
            "total_functions": matched_functions + unmatched,
            "bytes": matched_bytes,
            "total_bytes": sum(sz for _, sz in fn_map[name]),
        }
    if history and history[-1]["targets"] == targets:
        return
    now = datetime.now().astimezone().isoformat(timespec="seconds")
    commit = (git_output("rev-parse", "--short", "HEAD") or "").strip()
    snapshot = {"timestamp": now, "targets": targets}
    if commit:
        snapshot["commit"] = commit
    history.append(snapshot)
    pending = HISTORY.with_suffix(".tmp")
    pending.write_text(json.dumps(history, indent=2) + "\n", encoding="utf-8")
    pending.replace(HISTORY)


def plot_history(history):
    import matplotlib
    matplotlib.use("Agg")
    matplotlib.rcParams["svg.fonttype"] = "path"
    matplotlib.rcParams["svg.hashsalt"] = "ddpdoj"
    import matplotlib.dates as mdates
    import matplotlib.pyplot as plt
    from matplotlib.ticker import PercentFormatter

    colors = {"functions": "#1766af", "bytes": "#c8321e"}
    names = {"functions": "Functions", "bytes": "Bytes"}
    GRAPH_DIR.mkdir(exist_ok=True)
    written = []
    for target, label in LABELS.items():
        points = [snapshot for snapshot in history if target in snapshot["targets"]]
        for i, snapshot in enumerate(points):
            data = snapshot["targets"][target]
            tot_f = data.get("total_functions")
            tot_b = data.get("total_bytes")
            if tot_f and tot_b and data["functions"] >= tot_f and data["bytes"] >= tot_b:
                points = points[: i + 1]
                break
        dates = [parse_timestamp(snapshot) for snapshot in points]
        fig, axis = plt.subplots(figsize=(10, 6), layout="constrained")
        summary = []
        for key in ("functions", "bytes"):
            total_key = f"total_{key}"
            total = next((s["targets"][target][total_key] for s in reversed(points) if total_key in s["targets"][target]), None)
            values = [min(snapshot["targets"][target][key] / total * 100, 100) if total else 0 for snapshot in points]
            axis.step(dates, values, where="post", color=colors[key], linewidth=2.5, label=names[key], clip_on=False)
            matched = points[-1]["targets"][target][key]
            summary.append(f"{names[key]}: {values[-1]:.1f}% ({matched:,}/{total or 0:,})")
        fig.suptitle(f"DaiOuJou PS2 {label} decompilation progress", fontsize=16, fontweight="bold")
        axis.set_title(" | ".join(summary), fontsize=12)
        axis.set_ylim(0, 100)
        axis.set_ylabel("Decompilation progress")
        axis.set_xlabel("Date")
        axis.yaxis.set_major_formatter(PercentFormatter(decimals=0))
        axis.grid(alpha=.3)
        axis.legend(loc="upper left")
        if len(dates) == 1:
            center = mdates.date2num(dates[0])
            axis.set_xlim(center - 1, center + 1)
            axis.set_xticks([center], [dates[0].isoformat(timespec="minutes")])
        else:
            locator = mdates.AutoDateLocator(minticks=3, maxticks=6)
            axis.xaxis.set_major_locator(locator)
            axis.xaxis.set_major_formatter(mdates.ConciseDateFormatter(locator))
        path = GRAPH_DIR / GRAPH_NAMES[target]
        fig.savefig(path, facecolor="white", metadata={"Date": None, "Creator": "tools/progress.py"})
        plt.close(fig)
        written.append(path)
    return written


def main():
    parser = argparse.ArgumentParser(description="Record matching progress history and optionally plot a chart.")
    parser.add_argument("--record", action="store_true", help="build and record a verified snapshot")
    parser.add_argument("--backfill", action="store_true", help="rebuild history from git commits touching splat.yaml")
    parser.add_argument("--plot", action="store_true", help="render the progress chart SVGs (docs/progress-*.svg)")
    args = parser.parse_args()
    if args.backfill:
        history = backfill_from_git()
        print(HISTORY.relative_to(ROOT))
    else:
        history = read_json(HISTORY) if HISTORY.is_file() else []
    if args.record:
        record_snapshot(history)
        print(HISTORY.relative_to(ROOT))
    if args.plot or (not args.record and not args.backfill):
        if not history:
            raise ValueError("No snapshots. Run with --record after setup.")
        for path in plot_history(history):
            print(path.relative_to(ROOT))


if __name__ == "__main__":
    try:
        main()
    except (ImportError, OSError, ValueError, subprocess.CalledProcessError) as error:
        raise SystemExit(f"Progress graph failed: {error}")
