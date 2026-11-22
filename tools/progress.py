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
GRAPH = ROOT / "docs/progress.svg"
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
    fig, axes = plt.subplots(1, len(TARGETS), figsize=(13, 4.4), layout="constrained", sharey=True)
    fig.suptitle("DaiOuJou PS2 decompilation progress", fontsize=18, fontweight="bold")
    handles = []
    for axis, (target, label) in zip(axes, LABELS.items()):
        points = [snapshot for snapshot in history if target in snapshot["targets"]]
        dates = [date.fromisoformat(snapshot["date"]) for snapshot in points]
        lines = []
        for key in ("functions", "bytes"):
            total_key = f"total_{key}"
            total = next((s["targets"][target][total_key] for s in reversed(points) if total_key in s["targets"][target]), None)
            values = [min(snapshot["targets"][target][key] / total * 100, 100) if total else 0 for snapshot in points]
            line, = axis.step(dates, values, where="post", color=colors[key], linewidth=2, label=names[key], clip_on=False)
            if axis is axes[0]:
                handles.append(line)
            matched = points[-1]["targets"][target][key]
            lines.append(f"{names[key]} {values[-1]:.1f}% ({matched:,}/{total or 0:,})")
        axis.set_title(label + "\n" + "\n".join(lines), loc="left", fontsize=10, fontweight="bold")
        axis.set_ylim(0, 100)
        axis.yaxis.set_major_formatter(PercentFormatter(decimals=0))
        axis.grid(alpha=.22)
        if len(dates) == 1:
            center = mdates.date2num(dates[0])
            axis.set_xlim(center - 1, center + 1)
            axis.set_xticks([center], [dates[0].isoformat()])
        else:
            locator = mdates.AutoDateLocator(minticks=2, maxticks=5)
            axis.xaxis.set_major_locator(locator)
            axis.xaxis.set_major_formatter(mdates.ConciseDateFormatter(locator))
        for spine in axis.spines.values():
            spine.set_color("#cbd5df")
    axes[0].set_ylabel("Decompilation progress")
    axes[0].legend(handles=handles, loc="upper left", bbox_to_anchor=(0.01, 0.99), frameon=True)
    GRAPH.parent.mkdir(exist_ok=True)
    fig.savefig(GRAPH, facecolor="white", metadata={"Date": None, "Creator": "tools/progress.py"})
    plt.close(fig)


def main():
    parser = argparse.ArgumentParser(description="Record matching progress history and optionally plot a chart.")
    parser.add_argument("--record", action="store_true", help="build and record a verified snapshot")
    parser.add_argument("--plot", action="store_true", help="render the progress chart SVG (docs/progress.svg)")
    args = parser.parse_args()
    history = read_json(HISTORY) if HISTORY.is_file() else []
    if args.record:
        record_snapshot(history)
        print(HISTORY.relative_to(ROOT))
    if args.plot or not args.record:
        if not history:
            raise ValueError("No snapshots. Run with --record after setup.")
        plot_history(history)
        print(GRAPH.relative_to(ROOT))


if __name__ == "__main__":
    try:
        main()
    except (ImportError, OSError, ValueError, subprocess.CalledProcessError) as error:
        raise SystemExit(f"Progress graph failed: {error}")
