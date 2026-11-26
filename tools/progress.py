import argparse
from datetime import datetime
import json
from pathlib import Path
import re
import subprocess
import sys
import yaml

from build import OBJ_CACHE, unit_object
from common import ROOT, TARGETS, nonmatching_dir, read_json, require_local, run, target_compiler
from objects import defined_function_count
from inventory import build_inventory
from split import SIZE_RE, SYMBOL_RE, target_units

HISTORY = ROOT / "config/progress-history.json"
GRAPH_DIR = ROOT / "docs"
GRAPH_NAME = "progress.svg"
MAP_NAMES = {"SLPS_252.33": "progress-map-main.svg", "DEATH.ELF": "progress-map-death.svg", "GALLERY.ELF": "progress-map-gallery.svg"}
LABELS = {"GALLERY.ELF": "Gallery", "SLPS_252.33": "Main game", "DEATH.ELF": "Death Label"}
GALLERY_ALL_FUNCTIONS_COMMIT = "76951158"


def matched_function_count(name, local):
    version = target_compiler(name, local)
    return sum(
        defined_function_count(unit_object(version, name, unit["source"]))
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


def missing_cached_objects(local):
    for name in TARGETS:
        version = target_compiler(name, local)
        for unit in target_units(name):
            obj = unit_object(version, name, unit["source"])
            src = ROOT / unit["source"]
            if not obj.is_file() or (src.is_file() and obj.stat().st_mtime < src.stat().st_mtime):
                return True
    return False


def record_snapshot(history, skip_build=False):
    local = require_local()
    if not skip_build and missing_cached_objects(local):
        run(sys.executable, str(ROOT / "tools/build.py"))
    inventory, _ = build_inventory()
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
    snapshot = {"timestamp": now, "targets": targets}
    history.append(snapshot)
    pending = HISTORY.with_suffix(".tmp")
    pending.write_text(json.dumps(history, indent=2) + "\n", encoding="utf-8")
    pending.replace(HISTORY)


def squarify(items, x, y, w, h):
    """Bruls-Huizing-van Wijk squarified treemap layout.

    items: list of (value, payload) sorted descending by value (> 0).
    Returns list of (rx, ry, rw, rh, payload).
    """
    if not items or w <= 0 or h <= 0:
        return []
    total = sum(v for v, _ in items)
    if total <= 0:
        return []
    scale = (w * h) / total
    areas = [(v * scale, p) for v, p in items]
    rects = []

    def worst(row, side):
        s = sum(a for a, _ in row)
        if s <= 0 or side <= 0:
            return float("inf")
        rmax = max(a for a, _ in row)
        rmin = min(a for a, _ in row)
        s2 = s * s
        side2 = side * side
        return max((side2 * rmax) / s2, s2 / (side2 * rmin))

    def layout_row(row, rx, ry, rw, rh):
        s = sum(a for a, _ in row)
        if rw >= rh:
            col_w = s / rh if rh > 0 else 0
            cy = ry
            for a, p in row:
                ch = a / col_w if col_w > 0 else 0
                rects.append((rx, cy, col_w, ch, p))
                cy += ch
            return rx + col_w, ry, rw - col_w, rh
        else:
            row_h = s / rw if rw > 0 else 0
            cx = rx
            for a, p in row:
                cw = a / row_h if row_h > 0 else 0
                rects.append((cx, ry, cw, row_h, p))
                cx += cw
            return rx, ry + row_h, rw, rh - row_h

    rx, ry, rw, rh = x, y, w, h
    row = []
    for item in areas:
        side = min(rw, rh)
        if not row or worst(row + [item], side) <= worst(row, side):
            row.append(item)
        else:
            rx, ry, rw, rh = layout_row(row, rx, ry, rw, rh)
            row = [item]
    if row:
        layout_row(row, rx, ry, rw, rh)
    return rects


def collect_map_functions():
    """The functions each map shows. Death Label's map leaves out what it shares with the main game."""
    inventory, _ = build_inventory()
    by_target = {}
    for name in TARGETS:
        funcs = []
        for fn in inventory[name]:
            if name == "DEATH.ELF" and "paired_main" in fn:
                continue
            status = "matched" if fn["matched"] else "asm"
            funcs.append({"name": fn["name"], "size": fn["size"], "status": status})
        funcs.sort(key=lambda f: f["size"], reverse=True)
        by_target[name] = funcs
    return by_target


def render_progress_map(target, funcs):
    """One treemap SVG for a single executable; its header shows only that executable's totals."""
    from xml.sax.saxutils import escape

    width = 1200
    pad_x = 14
    inner_w = width - 2 * pad_x
    header_h = 84
    bottom_pad = 14
    titles = {
        "DEATH.ELF": "Death Label (DEATH.ELF, unique functions)",
        "SLPS_252.33": "Main game (SLPS_252.33)",
        "GALLERY.ELF": "Gallery (GALLERY.ELF)",
    }
    colors = {"matched": "#3fb950", "asm": "#da3633"}

    total_bytes = sum(f["size"] for f in funcs)
    matched_bytes = sum(f["size"] for f in funcs if f["status"] == "matched")
    matched_fns = sum(1 for f in funcs if f["status"] == "matched")
    pct = (matched_bytes / total_bytes * 100.0) if total_bytes else 0.0
    # Tile area per byte scales with the function count so small executables stay readable.
    tile_h = 440.0 if len(funcs) > 500 else 160.0
    total_h = int(round(header_h + tile_h + bottom_pad))
    # 20px bold monospace is ~12.1px per character; leave a gap after the percentage label.
    stats_x = pad_x + round(len(f"{pct:.2f}% matched") * 12.1) + 14

    out = [
        f'<svg xmlns="http://www.w3.org/2000/svg" width="{width}" height="{total_h}" viewBox="0 0 {width} {total_h}" font-family="ui-monospace,Menlo,Consolas,monospace">',
        f'<rect width="{width}" height="{total_h}" fill="#0d1117"/>',
        f'<text x="{pad_x}" y="34" fill="#e6edf3" font-size="24" font-weight="700">{escape(titles[target])}</text>',
        f'<text x="{pad_x}" y="62" fill="#3fb950" font-size="20" font-weight="700">{pct:.2f}% matched</text>',
        f'<text x="{stats_x}" y="62" fill="#8b949e" font-size="14">{matched_bytes:,} / {total_bytes:,} bytes · {matched_fns:,} / {len(funcs):,} functions</text>',
    ]
    for lname, lcol, lx in (("matched", "#3fb950", 980), ("asm", "#da3633", 1090)):
        out.append(f'<rect x="{lx}" y="48" width="14" height="14" rx="2" fill="{lcol}"/>')
        out.append(f'<text x="{lx + 20}" y="60" fill="#e6edf3" font-size="13">{lname}</text>')

    out.append(f'<rect x="{pad_x}" y="{header_h}" width="{inner_w}" height="{tile_h:.2f}" fill="none" stroke="#30363d" stroke-width="1"/>')
    rects = squarify([(f["size"], f) for f in funcs if f["size"] > 0], pad_x, header_h, inner_w, tile_h)
    for rx, ry, rw, rh, fn in rects:
        title = escape(f"{fn['name']}  ·  {fn['size']:,} bytes  ·  {fn['status']}")
        col = colors[fn["status"]]
        out.append(
            f'<rect x="{rx:.2f}" y="{ry:.2f}" width="{rw:.2f}" height="{rh:.2f}" '
            f'fill="{col}" stroke="#0d1117" stroke-width="0.5"><title>{title}</title></rect>'
        )
    out.append("</svg>\n")
    path = GRAPH_DIR / MAP_NAMES[target]
    path.write_text("\n".join(out), encoding="utf-8")
    return path


def plot_progress_maps():
    by_target = collect_map_functions()
    GRAPH_DIR.mkdir(exist_ok=True)
    return [render_progress_map(target, by_target[target]) for target in MAP_NAMES]


def plot_history(history):
    import matplotlib
    matplotlib.use("Agg")
    matplotlib.rcParams["svg.fonttype"] = "path"
    matplotlib.rcParams["svg.hashsalt"] = "ddpdoj"
    import matplotlib.dates as mdates
    import matplotlib.pyplot as plt
    from matplotlib.ticker import PercentFormatter

    colors = {"SLPS_252.33": "#1766af", "DEATH.ELF": "#c8321e", "GALLERY.ELF": "#2e8540"}
    by_target = collect_map_functions()
    death_unique_matched = sum(1 for f in by_target["DEATH.ELF"] if f["status"] == "matched")
    GRAPH_DIR.mkdir(exist_ok=True)
    fig, axis = plt.subplots(figsize=(10, 6), layout="constrained")
    all_dates = []
    for target, label in LABELS.items():
        points = [snapshot for snapshot in history if target in snapshot["targets"]]
        counts = [s["targets"][target]["functions"] for s in points]
        if not counts:
            continue
        lowest = min(counts)
        points = points[max(i for i, count in enumerate(counts) if count == lowest):]
        dates = [parse_timestamp(snapshot) for snapshot in points]
        all_dates.extend(dates)
        last = points[-1]["targets"][target]
        for key, style, width in (("functions", "-", 2.5), ("bytes", "--", 1.5)):
            total_key = f"total_{key}"
            total = next((s["targets"][target][total_key] for s in reversed(points) if total_key in s["targets"][target]), None)
            values = [min(snapshot["targets"][target][key] / total * 100, 100) if total else 0 for snapshot in points]
            if key == "functions":
                if target == "DEATH.ELF":
                    name = f"{label}: {values[-1]:.1f}% ({death_unique_matched:,} unique functions)"
                else:
                    name = f"{label}: {values[-1]:.1f}% ({last['functions']:,} functions)"
            else:
                name = f"{label}, bytes"
            axis.step(dates, values, where="post", color=colors[target], linewidth=width, linestyle=style, label=name, clip_on=False)
    fig.suptitle("DaiOuJou PS2 decompilation progress", fontsize=16, fontweight="bold")
    axis.set_title("Share of each executable's functions (solid) and bytes (dashed) matched in C", fontsize=12)
    axis.set_ylim(0, 100)
    axis.set_ylabel("Decompilation progress")
    axis.set_xlabel("Date")
    axis.yaxis.set_major_formatter(PercentFormatter(decimals=0))
    axis.grid(alpha=.3)
    fig.legend(loc="outside lower center", ncol=3, frameon=True)
    if len(set(all_dates)) == 1:
        center = mdates.date2num(all_dates[0])
        axis.set_xlim(center - 1, center + 1)
        axis.set_xticks([center], [all_dates[0].isoformat(timespec="minutes")])
    else:
        start_day = min(all_dates).replace(hour=0, minute=0, second=0, microsecond=0)
        end_date = max(all_dates)
        span_days = (end_date - start_day).days
        if span_days <= 14:
            from matplotlib.ticker import FuncFormatter
            axis.set_xlim(left=start_day)
            axis.xaxis.set_major_locator(mdates.DayLocator())
            axis.xaxis.set_major_formatter(FuncFormatter(lambda x, _: f"{mdates.num2date(x).day} {mdates.num2date(x).strftime('%b')}"))
            years = f"{start_day.year}" if start_day.year == end_date.year else f"{start_day.year}–{end_date.year}"
            axis.set_xlabel(f"Date ({years})")
        else:
            locator = mdates.AutoDateLocator(minticks=3, maxticks=6)
            axis.xaxis.set_major_locator(locator)
            axis.xaxis.set_major_formatter(mdates.ConciseDateFormatter(locator))
    path = GRAPH_DIR / GRAPH_NAME
    fig.savefig(path, facecolor="white", metadata={"Date": None, "Creator": "tools/progress.py"})
    plt.close(fig)
    written = [path]
    written.extend(plot_progress_maps())
    return written


def main():
    parser = argparse.ArgumentParser(description="Record matching progress history and optionally plot a chart.")
    parser.add_argument("--record", action="store_true", help="record a snapshot (skips full rebuild when object cache is fresh)")
    parser.add_argument("--skip-build", action="store_true", help="never invoke tools/build.py during --record")
    parser.add_argument("--backfill", action="store_true", help="rebuild history from git commits touching splat.yaml")
    parser.add_argument("--plot", action="store_true", help="render the progress chart SVGs (docs/progress-*.svg)")
    args = parser.parse_args()
    if args.backfill:
        history = backfill_from_git()
        print(HISTORY.relative_to(ROOT))
    else:
        history = read_json(HISTORY) if HISTORY.is_file() else []
    if args.record:
        record_snapshot(history, skip_build=args.skip_build)
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
