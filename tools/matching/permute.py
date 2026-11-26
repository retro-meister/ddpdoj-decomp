import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
import io
import json
from pathlib import Path
import re
import shlex
import shutil
import subprocess
import sys
import tarfile
import threading
import urllib.request

import sys as _sys
from pathlib import Path as _Path
if str(_Path(__file__).resolve().parent.parent) not in _sys.path:
    _sys.path.insert(0, str(_Path(__file__).resolve().parent.parent))
from common import BASEROM, ROOT, TARGETS, TOOLCHAINS, TOOLS, nonmatching_dir
from common import compiler_path, require_local, run, target_compiler, verify, verify_compiler
from diff import JUMP_TABLE_RE, collect_provide_symbols, extract_function, function_object, resolve_range
from integrate import integrate
from inventory import build_inventory
from split import load_symbols, scan_asm_functions, split, target_layout, target_units

INTEGRATE_LOCK = threading.Lock()
DIFF_STATUS_RE = re.compile(r"^(MATCH|DIFFERENT)\s+\S+\s+([0-9.]+)%", re.MULTILINE)
DIFF_MORE_RE = re.compile(r"\.\.\.\s*\((\d+)\s+more differing instructions\)")

PERMUTER_COMMIT = "860b6d95b5350c2677c89b0c195c7bf3bb6bad0b"
PERMUTER_URL = f"https://github.com/simonlindholm/decomp-permuter/archive/{PERMUTER_COMMIT}.tar.gz"


def install_permuter():
    dest = TOOLS / "permuter" / PERMUTER_COMMIT[:12]
    script = dest / "permuter.py"
    if script.is_file():
        return script
    with urllib.request.urlopen(PERMUTER_URL, timeout=60) as resp:
        archive = resp.read()
    dest.parent.mkdir(parents=True, exist_ok=True)
    tmp = dest.with_name(dest.name + ".tmp")
    if tmp.exists():
        shutil.rmtree(tmp)
    tmp.mkdir(parents=True)
    with tarfile.open(fileobj=io.BytesIO(archive), mode="r:gz") as tf:
        prefix = f"decomp-permuter-{PERMUTER_COMMIT}/"
        for member in tf.getmembers():
            if not member.name.startswith(prefix):
                continue
            rel = member.name[len(prefix):]
            if not rel:
                continue
            target = tmp / rel
            if member.isdir():
                target.mkdir(parents=True, exist_ok=True)
            elif member.isfile():
                target.parent.mkdir(parents=True, exist_ok=True)
                target.write_bytes(tf.extractfile(member).read())
    tmp.replace(dest)
    return script


def fast_runner(local, override=None):
    if override:
        return [override]
    if sys.platform == "win32":
        return []
    wibo_cfg = TOOLCHAINS["wibo"]
    if sys.platform == "darwin":
        wibo_mac = TOOLS / "wibo" / wibo_cfg["version"] / wibo_cfg["darwin"][0]
        if wibo_mac.is_file():
            return [str(wibo_mac)]
    runner = local.get("runner")
    if not runner:
        return []
    return [runner] if isinstance(runner, str) else list(runner)


def inline_local_headers(source_text):
    out = []
    seen = set()

    def expand(text, is_header=False):
        lines = text.splitlines()
        if is_header and len(lines) >= 3 and lines[0].strip().startswith("#ifndef ") and lines[1].strip().startswith("#define ") and lines[-1].strip().startswith("#endif"):
            lines = lines[2:-1]
        for line in lines:
            stripped = line.strip()
            if stripped.startswith('#include "') and stripped.endswith('"'):
                header = stripped[10:-1]
                path = ROOT / "include" / header
                if path.is_file():
                    if header not in seen:
                        seen.add(header)
                        expand(path.read_text(encoding="utf-8"), is_header=True)
                    continue
            out.append(line)

    expand(source_text)
    return "\n".join(out) + "\n"


def run_permuter(target_name, func_name, source_path, threads=4, timeout=60, runner_override=None, on_progress=None):
    local = require_local()
    binutils = local["binutils"]
    permuter_py = install_permuter()

    split_folder = split(target_name)
    units = target_units(target_name)
    symbols = load_symbols(target_name)
    asm_functions = scan_asm_functions(split_folder / "asm")

    ns = argparse.Namespace(
        target=target_name, function=func_name,
        address=None, size=None, source=Path(source_path),
    )
    address, size, resolved_source = resolve_range(ns, units, symbols, asm_functions)
    version = target_compiler(target_name, local)
    verify_compiler(version)

    original = verify((BASEROM / target_name).read_bytes(), TARGETS[target_name]["sha256"], target_name)
    file_address, _, _ = target_layout(target_name)
    retail = original[address - file_address : address - file_address + size]

    work = ROOT / "build" / "permute" / target_name / func_name
    if work.exists():
        shutil.rmtree(work)
    work.mkdir(parents=True, exist_ok=True)

    (work / "retail.bin").write_bytes(retail)
    function_object(work, binutils, "retail", func_name)
    (work / "retail.o").replace(work / "target.o")

    base_code = inline_local_headers(Path(resolved_source).read_text(encoding="utf-8"))
    (work / "base.c").write_text(base_code, encoding="utf-8")

    provided = collect_provide_symbols(target_name, split_folder, asm_functions)
    gp = provided.pop("_gp")
    defs = [f"_gp = {gp:#x};", *(f"PROVIDE({name} = {addr:#x});" for name, addr in provided.items())]
    unit = next((u for u in units if u["name"] == func_name), {})
    rodata_addr = unit.get("rodata_address")
    if rodata_addr is None:
        try:
            assembly = extract_function(split_folder / "asm", func_name)
            tables = {int(m, 16) for m in JUMP_TABLE_RE.findall(assembly)}
            if tables:
                rodata_addr = min(tables)
        except ValueError:
            pass
    rodata_sec = f"  .rodata {rodata_addr:#x} : {{ *(.rodata*) }}" if rodata_addr is not None else "  .rodata : { *(.rodata*) }"
    layout = [
        *defs,
        "SECTIONS {",
        f"  .text {address:#x} : SUBALIGN(1) {{ *(.text) }}",
        rodata_sec,
        "  .data : { *(.data*) }",
        "  .sdata : { *(.sdata*) }",
        "  .bss : { *(.sbss*) *(.bss*) }",
        "  /DISCARD/ : { *(*) }",
        "}",
    ]
    (work / "layout.ld").write_text("\n".join(layout) + "\n", encoding="ascii")

    runner = fast_runner(local, runner_override)
    cc_cmd = shlex.join([*runner, str(compiler_path(version)), *TOOLCHAINS["compiler_flags"]])
    ld_bin = shlex.quote(binutils["ld"])
    objcopy_bin = shlex.quote(binutils["objcopy"])
    as_bin = shlex.quote(binutils["as"])
    compile_sh = work / "compile.sh"
    compile_sh.write_text(
        "#!/bin/sh\n"
        "set -e\n"
        'INPUT="$1"\n'
        'OUTPUT="$3"\n'
        'TMPDIR=$(mktemp -d)\n'
        'trap \'rm -rf "$TMPDIR"\' EXIT\n'
        f'cd {shlex.quote(str(ROOT))}\n'
        f'{cc_cmd} -o "$TMPDIR/raw.o" "$INPUT" >/dev/null 2>&1\n'
        f'{ld_bin} -EL -T {shlex.quote(str(work / "layout.ld"))} -o "$TMPDIR/linked.elf" "$TMPDIR/raw.o" >/dev/null 2>&1\n'
        f'{objcopy_bin} -O binary -j .text "$TMPDIR/linked.elf" "$TMPDIR/text.bin"\n'
        f'printf \'.text\\n.globl {func_name}\\n.type {func_name}, @function\\n{func_name}:\\n.incbin "%s"\\n.size {func_name}, . - {func_name}\\n\' "$TMPDIR/text.bin" > "$TMPDIR/wrap.s"\n'
        f'{as_bin} -EL -march=r5900 -mabi=eabi -no-pad-sections -o "$OUTPUT" "$TMPDIR/wrap.s"\n',
        encoding="utf-8",
    )
    compile_sh.chmod(0o755)
    (work / "settings.toml").write_text(
        f'func_name = "{func_name}"\ncompiler_type = "mwcc"\n',
        encoding="utf-8",
    )

    objdump_dir = str(Path(binutils["objdump"]).parent)
    env_prefix = f"{objdump_dir}:{shutil.which('sh') and ''}"
    cmd = [
        "uvx", "--with", "pycparser", "--with", "toml",
        "python", str(permuter_py), str(work),
        "-j", str(threads), "--stop-on-zero",
    ]
    env = dict(**__import__("os").environ)
    env["PATH"] = objdump_dir + __import__("os").pathsep + env.get("PATH", "")
    # Provide mips-linux-gnu-objdump symlink alias if permuter looks for it
    alias_dir = work / "bin"
    alias_dir.mkdir(exist_ok=True)
    for alias in ("mips-linux-gnu-objdump", "mipsel-linux-gnu-objdump", "mips-elf-objdump"):
        link = alias_dir / alias
        if not link.exists():
            link.symlink_to(binutils["objdump"])
    env["PATH"] = str(alias_dir) + __import__("os").pathsep + env["PATH"]

    if on_progress is None:
        try:
            subprocess.run(cmd, cwd=ROOT, env=env, timeout=timeout)
        except subprocess.TimeoutExpired:
            pass
    else:
        import select, time
        proc = subprocess.Popen(
            cmd, cwd=ROOT, env=env,
            stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
            bufsize=0,
        )
        deadline = time.monotonic() + timeout
        buf = b""
        try:
            while True:
                remaining = deadline - time.monotonic()
                if remaining <= 0:
                    proc.terminate()
                    break
                rlist, _, _ = select.select([proc.stdout], [], [], min(0.2, remaining))
                if rlist:
                    chunk = proc.stdout.read(4096)
                    if not chunk:
                        break
                    buf += chunk
                    while b"\r" in buf or b"\n" in buf:
                        idx_r = buf.find(b"\r")
                        idx_n = buf.find(b"\n")
                        idxs = [i for i in (idx_r, idx_n) if i >= 0]
                        idx = min(idxs)
                        line = buf[:idx].decode("utf-8", "replace").strip()
                        buf = buf[idx + 1 :]
                        if line:
                            on_progress(line)
                elif proc.poll() is not None:
                    break
        finally:
            try:
                proc.wait(timeout=3)
            except subprocess.TimeoutExpired:
                proc.kill()

    winners = sorted(work.glob("output-0-*/source.c"))
    if winners:
        orig_text = Path(source_path).read_text(encoding="utf-8") if Path(source_path).is_file() else ""
        cleaned = _restore_common_include(winners[0].read_text(encoding="utf-8"), orig_text)
        cleaned_winner = work / "winner_clean.c"
        cleaned_winner.write_text(cleaned, encoding="utf-8")
        with INTEGRATE_LOCK:
            st, _, _ = _compact_diff(target_name, func_name, cleaned_winner)
        chosen = cleaned_winner if st == "MATCH" else winners[0]
        if on_progress is None:
            print(f"PERMUTER MATCH: {chosen.relative_to(ROOT)}")
        else:
            on_progress(f"MATCH: {chosen.relative_to(ROOT)}")
        return chosen

    promoted_match = _promote_improved_draft(target_name, func_name, work, source_path, on_progress=on_progress)
    if promoted_match is not None:
        return promoted_match

    if on_progress is None:
        print(f"Permuter finished without score-0 match ({work.relative_to(ROOT)})")
    else:
        on_progress("finished without score-0 match")
    return None


def _restore_common_include(permuted_text, orig_text):
    if '#include "common.h"' not in orig_text:
        return permuted_text
    marker = "extern u8 bcd_digits[4];"
    idx = permuted_text.find(marker)
    if idx != -1:
        rest = permuted_text[idx + len(marker) :].lstrip("\r\n")
        return '#include "common.h"\n\n' + rest
    return permuted_text


def _compact_diff(target_name, func_name, source_path):
    proc = subprocess.run(
        [sys.executable, str(ROOT / "tools/matching/diff.py"), target_name, func_name, "--source", str(source_path), "--compact"],
        cwd=ROOT, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True,
    )
    out = (proc.stdout or "") + (proc.stderr or "")
    m = DIFF_STATUS_RE.search(out)
    if not m:
        return "ERROR", 0.0, 999999
    status, pct = m.group(1), float(m.group(2))
    if status == "MATCH":
        return "MATCH", 100.0, 0
    shown = sum(1 for ln in out.splitlines() if ln.startswith(("  ~", "  +", "  -")))
    more = DIFF_MORE_RE.search(out)
    diffs = shown + (int(more.group(1)) if more else 0)
    return "DIFFERENT", pct, diffs


def _best_nonzero_output(work):
    scored = []
    for p in work.glob("output-*-*/source.c"):
        parts = p.parent.name.split("-")
        if len(parts) >= 3 and parts[1].isdigit():
            score = int(parts[1])
            if score > 0:
                scored.append((score, p))
    scored.sort(key=lambda x: x[0])
    return scored[0] if scored else (None, None)


def _promote_improved_draft(target_name, func_name, work, source_path, on_progress=None):
    score, cand = _best_nonzero_output(work)
    if cand is None:
        return None
    orig_path = Path(source_path)
    orig_text = orig_path.read_text(encoding="utf-8") if orig_path.is_file() else ""
    cleaned = _restore_common_include(cand.read_text(encoding="utf-8"), orig_text)
    cleaned_path = work / "best_clean.c"
    cleaned_path.write_text(cleaned, encoding="utf-8")

    with INTEGRATE_LOCK:
        cur_status, cur_pct, cur_diffs = _compact_diff(target_name, func_name, orig_path) if orig_path.is_file() else ("ERROR", 0.0, 999999)
        new_status, new_pct, new_diffs = _compact_diff(target_name, func_name, cleaned_path)
        if new_status == "ERROR":
            cleaned_path = cand
            new_status, new_pct, new_diffs = _compact_diff(target_name, func_name, cand)
        if new_status == "MATCH":
            msg = f"PROMOTED MATCH (100.00%, score={score})"
            if on_progress:
                on_progress(msg)
            else:
                print(f"  [{func_name}] {msg}")
            return cleaned_path
        improved = (new_status == "DIFFERENT") and (
            (new_pct > cur_pct + 1e-6) or (abs(new_pct - cur_pct) <= 1e-6 and new_diffs < cur_diffs)
        )
        if improved:
            target_cand = nonmatching_dir(target_name) / f"{func_name}.c"
            wip_best = orig_path if orig_path.parent == target_cand.parent else target_cand
            wip_best.parent.mkdir(parents=True, exist_ok=True)
            wip_best.write_text(cleaned_path.read_text(encoding="utf-8"), encoding="utf-8")
            msg = f"saved new best: {cur_pct:.2f}% ({cur_diffs}) -> {new_pct:.2f}% ({new_diffs} diffs)"
            if on_progress:
                on_progress(msg)
            else:
                print(f"  [{func_name}] {msg}")
    return None


def find_top_unsolved(target_name, top_n):
    per_target, _ = build_inventory()
    unmatched = {fn["name"]: fn for fn in per_target[target_name] if not fn["matched"]}

    scores = {}
    queue_file = ROOT / "build" / "queue.json"
    if queue_file.is_file():
        try:
            q = json.loads(queue_file.read_text(encoding="utf-8"))
            for k, v in q.items():
                if k.startswith(f"{target_name}:"):
                    fn = k.split(":", 1)[1]
                    pct = float(v.get("best_pct", 0.0) or 0.0)
                    diffs = int(v.get("best_diffs", 999999) or 999999)
                    scores[fn] = (pct, diffs)
        except Exception:
            pass

    for log_name in ("ai-iterations.jsonl", "ai-log.jsonl"):
        p = ROOT / "knowledge" / log_name
        if not p.is_file():
            continue
        for line in p.read_text(encoding="utf-8").splitlines():
            if not line.strip():
                continue
            try:
                row = json.loads(line)
            except Exception:
                continue
            if row.get("target") != target_name:
                continue
            fn = row.get("func")
            pct = row.get("match_pct") if "match_pct" in row else row.get("best_pct")
            if fn and pct is not None:
                pct = float(pct)
                diffs = int(row.get("diffs", 999999) or 999999)
                prev = scores.get(fn)
                if prev is None or pct > prev[0] or (abs(pct - prev[0]) < 1e-6 and diffs < prev[1]):
                    scores[fn] = (pct, diffs)

    search_dirs = [nonmatching_dir(target_name)]
    candidates = []
    seen_fns = set()
    for wip_dir in search_dirs:
        if not wip_dir.is_dir():
            continue
        for best_file in sorted(wip_dir.glob("*.c")):
            fn = best_file.stem
            if fn in seen_fns or fn not in unmatched:
                continue
            seen_fns.add(fn)
            info = unmatched[fn]
            pct, diffs = scores.get(fn, (0.0, 999999))
            candidates.append((pct, -diffs, fn, best_file, info["size"], info["tier"], diffs))

    candidates.sort(key=lambda x: (x[0], x[1]), reverse=True)
    return [
        {"func": fn, "source": bf, "size": size, "tier": tier, "pct": pct, "diffs": diffs}
        for pct, _, fn, bf, size, tier, diffs in candidates[:top_n]
    ]


def run_batch_permuter(target_name, top_n, jobs=2, threads=4, timeout=300, runner_override=None):
    items = find_top_unsolved(target_name, top_n)
    if not items:
        print(f"No unsolved .best.c drafts found for {target_name}.")
        return []

    def worker(item):
        fn = item["func"]
        print(f"=== Permuting {target_name}:{fn} ({item['pct']:.2f}%, {item['diffs']} diffs) ===", flush=True)

        winner = run_permuter(
            target_name, fn, item["source"],
            threads=threads, timeout=timeout,
            runner_override=runner_override,
        )
        if winner is not None:
            with INTEGRATE_LOCK:
                st, pct, diffs = _compact_diff(target_name, fn, winner)
                if st == "MATCH":
                    integrate(target_name, fn, winner)
                    Path(item["source"]).unlink(missing_ok=True)
                elif st == "DIFFERENT" and (pct > item["pct"] + 1e-6 or diffs < item["diffs"]):
                    Path(item["source"]).write_text(winner.read_text(encoding="utf-8"), encoding="utf-8")
        return fn, winner

    winners = []
    try:
        with ThreadPoolExecutor(max_workers=jobs) as pool:
            futs = [pool.submit(worker, it) for it in items]
            for fut in as_completed(futs):
                fn, w = fut.result()
                if w is not None:
                    winners.append((fn, w))
    except KeyboardInterrupt:
        print("\nPermuter batch interrupted.")

    if winners:
        print(f"\nPermuter matches ({len(winners)}):")
        for fn, w in winners:
            print(f"  {fn}: {w.relative_to(ROOT)}")
    else:
        print("\nPermuter batch complete: no score-0 matches.")
    return winners


def main():
    parser = argparse.ArgumentParser(description="Run bounded decomp-permuter search on a close C draft (or top N unsolved drafts).")
    parser.add_argument("target", choices=TARGETS)
    parser.add_argument("function", nargs="?", help="single function name (omit when using --top)")
    parser.add_argument("--source", type=Path, help="source C file for single-function mode")
    parser.add_argument("--top", type=int, help="run permuter on the top N closest unsolved .best.c drafts")
    parser.add_argument("--jobs", type=int, default=2, help="parallel functions in --top mode (default: 2)")
    parser.add_argument("-j", "--threads", type=int, default=4, help="permuter worker threads per function")
    parser.add_argument("--timeout", type=int, default=60)
    parser.add_argument("--runner", help="override compiler runner for permuter")
    args = parser.parse_args()
    if args.top:
        winners = run_batch_permuter(
            args.target, args.top,
            jobs=args.jobs, threads=args.threads,
            timeout=args.timeout, runner_override=args.runner,
        )
        if not winners:
            raise SystemExit(1)
        return
    if not args.function or not args.source:
        parser.error("Provide <function> --source <file>, or use --top N.")
    winner = run_permuter(args.target, args.function, args.source, args.threads, args.timeout, args.runner)
    if winner is None:
        raise SystemExit(1)


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError, subprocess.CalledProcessError) as error:
        raise SystemExit(f"Permute failed: {error}")
