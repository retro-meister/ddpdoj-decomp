"""Capture MWCCPS2 code generation, verify the resulting object, and diff captures."""
from argparse import ArgumentParser
import hashlib
import json
from pathlib import Path
import shutil
from subprocess import SubprocessError
import sys
from tempfile import TemporaryDirectory

from common import ROOT, TOOLCHAINS, TOOLS, compiler_path, read_json, resolve_tool, run, verify_compiler
from mwcc_profiles.ir import ir_text, parse_iro_log, structure_stage, summarize_iro
from mwcc_profiles.diff_trace import diff_reports, format_diff_report
from mwcc_profiles.pe import instrument
from mwcc_profiles.records import decode, fallthrough_text, pcode_text, regalloc_text, scheduler_text


PROFILES_DIR = Path(__file__).with_name("mwcc_profiles")


def load_profiles():
    profiles = {}
    for path in sorted(PROFILES_DIR.glob("*.json")):
        profile = read_json(path)
        profiles.update({compiler: profile for compiler in profile["compilers"]})
    return profiles


def capture_source(source, output, compiler_name, profiles=None, wibo=None, assembler=None, objcopy=None):
    if profiles is None:
        profiles = load_profiles()
    native_windows = sys.platform == "win32"
    binutils_prefix = "" if native_windows else "x86_64-w64-mingw32-"
    assembler_name = assembler or f"{binutils_prefix}as"
    objcopy_name = objcopy or f"{binutils_prefix}objcopy"

    runner = []
    if not native_windows:
        wibo_config = TOOLCHAINS["wibo"]
        wibo_host = "darwin" if sys.platform == "darwin" else "linux-x86_64"
        default_wibo = TOOLS / "wibo" / wibo_config["version"] / wibo_config[wibo_host][0]
        runner = [resolve_tool(wibo or default_wibo)]

    profile = profiles[compiler_name]
    source = Path(source).resolve(strict=True)
    output = Path(output).resolve()
    verify_compiler(compiler_name)
    compiler = compiler_path(compiler_name)
    assembler_path = resolve_tool(assembler_name)
    objcopy_path = resolve_tool(objcopy_name)
    flags = TOOLCHAINS["compiler_flags"]
    stage_names = [hook[side] for hook in profile["hooks"] for side in ("before", "after") if side in hook]
    stages = {name: index for index, name in enumerate(stage_names, 1)}

    output.mkdir(parents=True, exist_ok=True)
    # The Windows loader or scanner can briefly hold the compiler DLL after exit.
    with TemporaryDirectory(prefix="ddpdoj-mwcc-", ignore_cleanup_errors=native_windows) as scratch:
        traced = Path(scratch) / compiler.name
        shutil.copy2(compiler.with_name("LMGR326B.dll"), traced.parent)
        iro_log = output / "iro.log"
        iro_log.unlink(missing_ok=True)
        instrument(compiler, traced, profile, stages, assembler_path, objcopy_path, iro_log)
        for label, executable in (("normal", compiler), ("trace", traced)):
            try:
                with (output / f"{label}.stdout").open("wb") as stdout, (output / f"{label}.stderr").open("wb") as stderr:
                    run(*runner, executable, *flags, "-o", output / f"{label}.o", source,
                        cwd=ROOT, stdout=stdout, stderr=stderr, timeout=120)
            except SubprocessError as error:
                raise ValueError(f"{label} compile failed. See {output / f'{label}.stdout'} and "
                                 f"{output / f'{label}.stderr'}. {error}") from error
    normal = (output / "normal.o").read_bytes()
    if normal != (output / "trace.o").read_bytes():
        raise ValueError("Instrumented and normal objects differ")
    functions = decode(
        (output / "trace.stderr").read_bytes(),
        {value: name for name, value in stages.items()},
        profile["layout"],
        profile.get("ir", {}).get("layout"),
    )
    attach_ir(functions, profile, output / "iro.log")
    report = {
        "format": 1,
        "compiler": compiler_name,
        "compiler_sha256": TOOLCHAINS["compilers"][compiler_name]["sha256"],
        "source": str(source),
        "flags": flags,
        "object_sha256": hashlib.sha256(normal).hexdigest(),
        "instrumented_object_identical": True,
        "functions": functions,
    }
    report_path = output / "capture.json"
    report_path.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    (output / "pcode.txt").write_text(pcode_text(functions), encoding="utf-8")
    (output / "regalloc.txt").write_text(regalloc_text(functions), encoding="utf-8")
    (output / "scheduler.txt").write_text(scheduler_text(functions), encoding="utf-8")
    (output / "fallthrough.txt").write_text(fallthrough_text(functions), encoding="utf-8")
    if "ir" in profile:
        (output / "ir.txt").write_text(ir_text(functions), encoding="utf-8")
    return report, report_path


def attach_ir(functions, profile, iro_log):
    """Replace raw frontend IR records with statement trees and add the optimizer log phases."""
    for function in functions:
        raw = function.pop("ir_raw", [])
        if raw:
            if any(stage["symbol"] != function["symbol"] for stage in raw):
                raise ValueError(f"Frontend IR stages do not belong to {function['symbol']}")
            function["ir_stages"] = [structure_stage(stage, profile["ir"]["layout"], profile["ir"]["enode_names"]) for stage in raw]
    if not iro_log.exists():
        return
    logged = parse_iro_log(iro_log.read_text(encoding="latin-1"))
    remaining = list(functions)
    for entry in logged:
        for index, function in enumerate(remaining):
            if function["symbol"] == entry["symbol"]:
                function["iro_phases"] = summarize_iro(entry)
                del remaining[:index + 1]
                break


def _load_or_capture(target, compiler_name, profiles, wibo, assembler, objcopy, scratch_dir, label):
    path = Path(target)
    if path.is_dir():
        path = path / "capture.json"
    if path.suffix == ".json":
        return read_json(path)
    report, _ = capture_source(path, scratch_dir / label, compiler_name, profiles, wibo, assembler, objcopy)
    return report


def main():
    profiles = load_profiles()
    native_windows = sys.platform == "win32"
    binutils_prefix = "" if native_windows else "x86_64-w64-mingw32-"
    parser = ArgumentParser(description=__doc__)
    parser.add_argument("source", type=Path, nargs="?", help="C source file to capture")
    parser.add_argument("--output", type=Path, help="new directory for the trace and objects")
    parser.add_argument("--diff", nargs=2, metavar=("A", "B"), help="compare two captures (.json/dir) or C sources")
    parser.add_argument("--function", help="function symbol to compare in --diff mode (defaults to first)")
    parser.add_argument("--json", type=Path, help="optional JSON output path for --diff mode")
    parser.add_argument("--compiler", choices=profiles, default="3.0.3-020716")
    parser.add_argument("--wibo", help="override the Wibo executable on macOS or Linux")
    parser.add_argument("--assembler", default=f"{binutils_prefix}as")
    parser.add_argument("--objcopy", default=f"{binutils_prefix}objcopy")
    options = parser.parse_args()

    if native_windows and options.wibo:
        parser.error("Windows runs MWCCPS2 directly. Omit --wibo.")

    if options.diff:
        with TemporaryDirectory(prefix="ddpdoj-diff-", ignore_cleanup_errors=native_windows) as scratch:
            scratch_dir = Path(scratch)
            report_a = _load_or_capture(
                options.diff[0], options.compiler, profiles, options.wibo, options.assembler, options.objcopy, scratch_dir, "a"
            )
            report_b = _load_or_capture(
                options.diff[1], options.compiler, profiles, options.wibo, options.assembler, options.objcopy, scratch_dir, "b"
            )
        diff = diff_reports(report_a, report_b, options.function)
        if options.json:
            options.json.parent.mkdir(parents=True, exist_ok=True)
            options.json.write_text(json.dumps(diff, indent=2) + "\n", encoding="utf-8")
        print(format_diff_report(diff))
        return

    if not options.source or not options.output:
        parser.error("Pass SOURCE and --output DIR, or use --diff A B.")
    if options.output.exists():
        parser.error(f"Output directory already exists: {options.output}")

    report, report_path = capture_source(
        options.source, options.output, options.compiler, profiles, options.wibo, options.assembler, options.objcopy
    )
    print(f"Verified identical objects. Captured {len(report['functions'])} function(s).")
    print(report_path)


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError, SubprocessError) as error:
        sys.exit(f"MWCC trace failed: {error}")
