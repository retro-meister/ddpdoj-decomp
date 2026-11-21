import argparse
import json
from pathlib import Path
import subprocess

from build import OBJ_CACHE
from common import BASEROM, ROOT, TARGETS, require_local, run, target_compiler, verify
from split import target_layout, target_units


def build_retail_object(folder, binutils, original, file_address, unit):
    start = unit["address"] - file_address
    retail = original[start:start + unit["size"]]
    folder.mkdir(parents=True, exist_ok=True)
    bin_path = folder / f"{unit['name']}.bin"
    asm_path = folder / f"{unit['name']}.s"
    obj_path = folder / f"{unit['name']}.o"
    bin_path.write_bytes(retail)
    asm = (
        f'.text\n.globl {unit["name"]}\n.type {unit["name"]}, @function\n'
        f'{unit["name"]}:\n.incbin "{bin_path.name}"\n.size {unit["name"]}, . - {unit["name"]}\n'
    )
    asm_path.write_text(asm, encoding="ascii")
    run(binutils["as"], "-EL", "-march=r5900", "-mabi=eabi", "-no-pad-sections",
        "-o", obj_path.name, asm_path.name, cwd=folder)
    return obj_path


def main():
    parser = argparse.ArgumentParser(description="Generate objdiff.json and retail target objects for objdiff GUI.")
    parser.add_argument("--output", type=Path, default=ROOT / "objdiff.json")
    args = parser.parse_args()

    local = require_local()
    binutils = local["binutils"]
    units_json = []
    for name, target in TARGETS.items():
        original = verify((BASEROM / name).read_bytes(), target["sha256"], name)
        file_address, _, _ = target_layout(name)
        retail_dir = ROOT / "build" / "objdiff" / name
        version = target_compiler(name, local)
        for unit in target_units(name):
            retail_obj = build_retail_object(retail_dir, binutils, original, file_address, unit)
            base_obj = OBJ_CACHE / version / f"{unit['source']}.o"
            units_json.append({
                "name": f"{name}/{unit['name']}",
                "target_path": retail_obj.relative_to(ROOT).as_posix(),
                "base_path": base_obj.relative_to(ROOT).as_posix(),
                "metadata": {"complete": True},
            })

    config = {
        "$schema": "https://raw.githubusercontent.com/encounter/objdiff/main/config.schema.json",
        "custom_make": "uv",
        "custom_args": ["run", "tools/build.py"],
        "build_target": False,
        "build_base": True,
        "watch_patterns": ["src/**/*.c", "include/**/*.h", "config/**/*"],
        "units": units_json,
    }
    args.output.write_text(json.dumps(config, indent=2) + "\n", encoding="utf-8")
    print(f"Wrote {args.output.relative_to(ROOT)} ({len(units_json)} unit(s))")


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError, subprocess.CalledProcessError) as error:
        raise SystemExit(f"objdiff config failed: {error}")
