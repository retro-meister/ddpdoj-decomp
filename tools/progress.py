import argparse
from datetime import date
import json
import subprocess
import sys

from build import OBJ_CACHE
from common import ROOT, TARGETS, read_json, require_local, run, target_compiler
from objects import defined_function_count
from inventory import build_inventory
from split import target_units

HISTORY = ROOT / "config/progress-history.json"
GRAPH_DIR = ROOT / "docs"
GRAPH_NAMES = {"SLPS_252.33": "progress-main.svg", "DEATH.ELF": "progress-death.svg", "GALLERY.ELF": "progress-gallery.svg"}
LABELS = {"SLPS_252.33": "Main game", "DEATH.ELF": "Death Label", "GALLERY.ELF": "Gallery"}


def matched_function_count(name, local):
    version = target_compiler(name, local)
    return sum(
        defined_function_count(OBJ_CACHE / version / f"{unit['source']}.o")
        for unit in target_units(name)
    )


def record_snapshot(history):
    run(sys.executable, str(ROOT / "tools/build.py"))
    inventory, _ = build_inventory()
    local = require_local()
    targets = {}
    for name in TARGETS:
        units = target_units(name)
        matched_functions = matched_function_count(name, local)
        unmatched = sum(1 for fn in inventory[name] if not fn["matched"])
        targets[name] = {
            "functions": matched_functions,
            "total_functions": matched_functions + unmatched,
            "bytes": sum(unit["size"] for unit in units),
            "total_bytes": sum(fn["size"] for fn in inventory[name]),
        }
    if history and history[-1]["targets"] == targets:
        return
    today = date.today().isoformat()
    if history and history[-1]["date"] > today:
        raise ValueError("The latest snapshot is later than today's date.")
    snapshot = {"date": today, "targets": targets}
    if history and history[-1]["date"] == today:
        history[-1] = snapshot
    else:
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
        dates = [date.fromisoformat(snapshot["date"]) for snapshot in points]
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
            axis.set_xticks([center], [dates[0].isoformat()])
        else:
            locator = mdates.AutoDateLocator(minticks=2, maxticks=6)
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
    parser.add_argument("--plot", action="store_true", help="render the progress chart SVGs (docs/progress-*.svg)")
    args = parser.parse_args()
    history = read_json(HISTORY) if HISTORY.is_file() else []
    if args.record:
        record_snapshot(history)
        print(HISTORY.relative_to(ROOT))
    if args.plot or not args.record:
        if not history:
            raise ValueError("No snapshots. Run with --record after setup.")
        for path in plot_history(history):
            print(path.relative_to(ROOT))


if __name__ == "__main__":
    try:
        main()
    except (ImportError, OSError, ValueError, subprocess.CalledProcessError) as error:
        raise SystemExit(f"Progress graph failed: {error}")
