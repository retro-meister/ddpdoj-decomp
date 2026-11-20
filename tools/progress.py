import argparse
from datetime import date
import json
import subprocess
import sys

from common import ROOT, TARGETS, read_json, run
from split import target_units

HISTORY = ROOT / "config/progress-history.json"
GRAPH = ROOT / "build/progress.png"
LABELS = {"SLPS_252.33": "Main game", "DEATH.ELF": "Death Label", "GALLERY.ELF": "Gallery"}


def record_snapshot(history):
    run(sys.executable, str(ROOT / "tools/build.py"))
    targets = {
        name: {
            "functions": len(units),
            "bytes": sum(unit["size"] for unit in units),
        }
        for name in TARGETS
        for units in (target_units(name),)
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
    import matplotlib.dates as mdates
    import matplotlib.pyplot as plt
    from matplotlib.ticker import MaxNLocator, StrMethodFormatter

    blue, orange = "#1766af", "#b94723"
    series = [target for snapshot in history for target in snapshot["targets"].values()]
    max_functions = max(max(point["functions"] for point in series) * 1.15, 1)
    max_bytes = max(max(point["bytes"] for point in series) * 1.15, 1)
    fig, axes = plt.subplots(1, len(TARGETS), figsize=(12, 4), layout="constrained")
    fig.get_layout_engine().set(rect=(0, 0, 1, .81), wspace=.08)
    fig.suptitle("DaiOuJou PS2 matching progress", fontsize=16, fontweight="bold")
    for axis, (name, label) in zip(axes, LABELS.items()):
        points = [snapshot for snapshot in history if name in snapshot["targets"]]
        dates = [date.fromisoformat(snapshot["date"]) for snapshot in points]
        values = [snapshot["targets"][name] for snapshot in points]
        other = axis.twinx()
        functions, = axis.step(
            dates, [point["functions"] for point in values], where="post",
            color=blue, linewidth=2, marker="o", markersize=7, markerfacecolor="white",
            label="Matched functions", clip_on=False,
        )
        code, = other.step(
            dates, [point["bytes"] for point in values], where="post",
            color=orange, linewidth=2, marker="s", markersize=4,
            label="Matched code bytes", clip_on=False,
        )
        latest = values[-1]
        count = latest["functions"]
        noun = "function" if count == 1 else "functions"
        axis.set_title(f"{label}\n{count:,} {noun} · {latest['bytes']:,} B",
                       loc="left", fontsize=11, fontweight="bold")
        axis.set_ylim(0, max_functions)
        other.set_ylim(0, max_bytes)
        axis.yaxis.set_major_locator(MaxNLocator(nbins=4, integer=True))
        other.yaxis.set_major_locator(MaxNLocator(nbins=4, integer=True))
        other.yaxis.set_major_formatter(StrMethodFormatter("{x:,.0f}"))
        axis.tick_params(axis="y", colors=blue)
        other.tick_params(axis="y", colors=orange)
        axis.grid(axis="y", alpha=.22)
        if len(dates) == 1:
            center = mdates.date2num(dates[0])
            axis.set_xlim(center - 1, center + 1)
            axis.set_xticks([center], [dates[0].isoformat()])
        else:
            locator = mdates.AutoDateLocator(minticks=2, maxticks=4)
            axis.xaxis.set_major_locator(locator)
            axis.xaxis.set_major_formatter(mdates.ConciseDateFormatter(locator))
        for spine in (*axis.spines.values(), *other.spines.values()):
            spine.set_color("#cbd5df")
    fig.legend(handles=[functions, code], loc="upper center", bbox_to_anchor=(.5, .90),
               ncols=2, frameon=False)
    GRAPH.parent.mkdir(exist_ok=True)
    fig.savefig(GRAPH, dpi=150, facecolor="white")
    plt.close(fig)


def main():
    parser = argparse.ArgumentParser(description="Record matching progress history and optionally plot a chart.")
    parser.add_argument("--record", action="store_true", help="build and record a verified snapshot")
    parser.add_argument("--plot", action="store_true", help="render the progress chart PNG")
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
