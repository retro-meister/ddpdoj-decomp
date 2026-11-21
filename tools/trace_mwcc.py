"""Capture MWCCPS2 code generation and verify the resulting object."""
from argparse import ArgumentParser
import hashlib
import json
from pathlib import Path
import shutil
from subprocess import SubprocessError
import sys
from tempfile import TemporaryDirectory

from common import ROOT, TOOLCHAINS, TOOLS, compiler_path, read_json, resolve_tool, run, verify_compiler
from mwcc_profiles.pe import instrument
from mwcc_profiles.records import decode, pcode_text


PROFILES_DIR = Path(__file__).with_name("mwcc_profiles")


def main():
    profiles = {}
    for path in sorted(PROFILES_DIR.glob("*.json")):
        profile = read_json(path)
        profiles.update({compiler: profile for compiler in profile["compilers"]})
    native_windows = sys.platform == "win32"
    binutils_prefix = "" if native_windows else "x86_64-w64-mingw32-"
    parser = ArgumentParser(description=__doc__)
    parser.add_argument("source", type=Path)
    parser.add_argument("--output", type=Path, required=True, help="new directory for the trace and objects")
    parser.add_argument("--compiler", choices=profiles, default="3.0b38-030307-gallery")
    parser.add_argument("--wibo", help="override the Wibo executable on macOS or Linux")
    parser.add_argument("--assembler", default=f"{binutils_prefix}as")
    parser.add_argument("--objcopy", default=f"{binutils_prefix}objcopy")
    options = parser.parse_args()

    runner = []
    if native_windows:
        if options.wibo:
            parser.error("Windows runs MWCCPS2 directly. Omit --wibo.")
    else:
        wibo_config = TOOLCHAINS["wibo"]
        wibo_host = "darwin" if sys.platform == "darwin" else "linux-x86_64"
        default_wibo = TOOLS / "wibo" / wibo_config["version"] / wibo_config[wibo_host][0]
        runner = [resolve_tool(options.wibo or default_wibo)]

    profile = profiles[options.compiler]
    source = options.source.resolve(strict=True)
    output = options.output.resolve()
    verify_compiler(options.compiler)
    compiler = compiler_path(options.compiler)
    assembler = resolve_tool(options.assembler)
    objcopy = resolve_tool(options.objcopy)
    flags = TOOLCHAINS["compiler_flags"]
    stage_names = [hook[side] for hook in profile["hooks"] for side in ("before", "after") if side in hook]
    stages = {name: index for index, name in enumerate(stage_names, 1)}

    output.mkdir(parents=True)
    # The Windows loader or scanner can briefly hold the compiler DLL after exit.
    with TemporaryDirectory(prefix="ddpdoj-mwcc-", ignore_cleanup_errors=native_windows) as scratch:
        traced = Path(scratch) / compiler.name
        shutil.copy2(compiler.with_name("LMGR326B.dll"), traced.parent)
        instrument(compiler, traced, profile, stages, assembler, objcopy)
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
    )
    report = {
        "format": 1,
        "compiler": options.compiler,
        "compiler_sha256": TOOLCHAINS["compilers"][options.compiler]["sha256"],
        "source": str(source),
        "flags": flags,
        "object_sha256": hashlib.sha256(normal).hexdigest(),
        "instrumented_object_identical": True,
        "functions": functions,
    }
    report_path = output / "capture.json"
    report_path.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    (output / "pcode.txt").write_text(pcode_text(functions), encoding="utf-8")
    print(f"Verified identical objects. Captured {len(functions)} function(s).")
    print(report_path)


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError, SubprocessError) as error:
        sys.exit(f"MWCC trace failed: {error}")
