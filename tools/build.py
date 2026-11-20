import argparse
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
from tempfile import TemporaryDirectory

from common import BASEROM, ROOT, TARGETS, TOOLCHAINS
from common import compiler_path, require_local, run, target_compiler, verify, verify_compiler
from objects import validate_object
from qemu_runner import compile_batch
from split import split, target_units

BUILD = ROOT / "build"
OBJ_CACHE = BUILD / "obj"
QEMU_RUNNER = (Path(__file__).resolve().parent / "qemu_runner.py").resolve()


def compile_source(local, source, output, version):
    compiler = compiler_path(version)
    runner = local["runner"]
    if isinstance(runner, str):
        runner = [runner]
    output.parent.mkdir(parents=True, exist_ok=True)
    run(*(runner or []), compiler, *TOOLCHAINS["compiler_flags"], "-o", output.relative_to(ROOT), source)


def uses_qemu_runner(local):
    runner = local.get("runner")
    if not runner:
        return False
    parts = [runner] if isinstance(runner, str) else runner
    return any(Path(part).resolve() == QEMU_RUNNER for part in parts if Path(part).exists())


def headers_digest():
    hasher = hashlib.sha256()
    include_dir = ROOT / "include"
    if include_dir.is_dir():
        for header in sorted(include_dir.rglob("*.h")):
            hasher.update(header.relative_to(ROOT).as_posix().encode("utf-8"))
            hasher.update(b"\0")
            hasher.update(header.read_bytes())
            hasher.update(b"\0")
    return hasher.hexdigest()


def unit_stamp(version, source, include_hash):
    record = TOOLCHAINS["compilers"][version]
    hasher = hashlib.sha256()
    hasher.update(record["sha256"].encode("ascii"))
    hasher.update(b"\0")
    hasher.update("\0".join(TOOLCHAINS["compiler_flags"]).encode("utf-8"))
    hasher.update(b"\0")
    hasher.update(include_hash.encode("ascii"))
    hasher.update(b"\0")
    hasher.update((ROOT / source).read_bytes())
    return hasher.hexdigest()


def compile_units(local, jobs):
    include_hash = headers_digest()
    objects = {}
    dirty = []
    for version, source in jobs:
        obj = OBJ_CACHE / version / f"{source}.o"
        stamp_file = obj.with_suffix(".stamp")
        expected = unit_stamp(version, source, include_hash)
        objects[(version, source)] = obj
        if obj.is_file() and stamp_file.is_file():
            try:
                if stamp_file.read_text(encoding="ascii").strip() == expected:
                    continue
            except OSError:
                pass
        dirty.append((version, source, obj, stamp_file, expected))

    if dirty:
        if len(dirty) > 1 and uses_qemu_runner(local):
            batch = [
                (compiler_path(version), TOOLCHAINS["compiler_flags"], obj, ROOT / source)
                for version, source, obj, _, _ in dirty
            ]
            compile_batch(batch)
        else:
            for version, source, obj, _, _ in dirty:
                compile_source(local, source, obj, version)
        for _, _, obj, stamp_file, expected in dirty:
            validate_object(obj)
            stamp_file.write_text(expected + "\n", encoding="ascii")
    return objects


def is_fresh(output, source):
    return output.is_file() and output.stat().st_mtime >= source.stat().st_mtime


def assemble_split(folder, binutils):
    objects_root = folder / "objects"
    for asset in ("assets/elf_header.bin", "assets/elf_tail.bin"):
        source = folder / asset
        rel_from_root = source.relative_to(ROOT)
        obj = objects_root / f"{rel_from_root.as_posix()}.o"
        if is_fresh(obj, source):
            continue
        obj.parent.mkdir(parents=True, exist_ok=True)
        stub = obj.with_suffix(".s")
        stub.write_text(f'.section .data\n.incbin "{rel_from_root.as_posix()}"\n', encoding="ascii")
        run(binutils["as"], "-EL", "-march=r5900", "-mabi=eabi", "-no-pad-sections",
            "-o", obj.relative_to(ROOT), stub.relative_to(ROOT), cwd=ROOT)

    for asm in sorted((folder / "asm").rglob("*.s")):
        rel_in_asm = asm.relative_to(folder / "asm")
        if len(rel_in_asm.parts) > 1 and rel_in_asm.parts[0] in ("nonmatchings", "matchings"):
            continue
        rel_from_root = asm.relative_to(ROOT)
        obj = objects_root / f"{rel_from_root.as_posix()}.o"
        if is_fresh(obj, asm):
            continue
        obj.parent.mkdir(parents=True, exist_ok=True)
        run(binutils["as"], "-EL", "-march=r5900", "-mabi=eabi", "-Iinclude", "-no-pad-sections",
            "-o", obj.relative_to(ROOT), rel_from_root.as_posix(), cwd=ROOT)


def link_target(folder, work_target, filename, original, target, units, version, objects, binutils, matching):
    assemble_split(folder, binutils)
    objects_root = folder / "objects"
    for unit in units:
        dest = objects_root / f"{unit['source']}.o"
        dest.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(objects[(version, unit["source"])], dest)
    work_target.mkdir(parents=True, exist_ok=True)
    elf = work_target / "image.elf"
    link_map = work_target / "image.map"
    out = work_target / filename
    rel = folder.relative_to(ROOT)
    run(
        binutils["ld"], "-EL",
        "-T", rel / "main.ld",
        "-T", rel / "undefined_funcs.txt",
        "-T", rel / "undefined_syms.txt",
        "-T", rel / "symbols.ld",
        "-Map", str(link_map),
        "-o", str(elf),
        cwd=ROOT,
    )
    run(binutils["objcopy"], "-O", "binary", str(elf), str(out), cwd=ROOT)
    executable = out.read_bytes()
    if matching:
        if len(executable) != len(original):
            raise ValueError(f"{filename}: size changed from {len(original)} to {len(executable)}")
        verify(executable, target["sha256"], filename)


def build(local, target=None, mod=False, compiler=None):
    names = [target] if target else list(TARGETS)
    originals = {
        name: verify((BASEROM / name).read_bytes(), TARGETS[name]["sha256"], f"baserom/{name}")
        for name in names
    }
    units_by_target = {name: target_units(name) for name in names}
    versions = {name: target_compiler(name, local, compiler) for name in names}
    jobs = sorted({
        (versions[name], unit["source"])
        for name in names
        for unit in units_by_target[name]
    })
    for version in sorted({version for version, _ in jobs}):
        verify_compiler(version)

    split_folders = {name: split(name) for name in names}
    objects = compile_units(local, jobs)

    output = BUILD / "mod" if mod else BUILD
    output.mkdir(parents=True, exist_ok=True)
    with TemporaryDirectory(prefix=".link-", dir=output) as temporary:
        work = Path(temporary)
        for name in names:
            version = versions[name]
            link_target(split_folders[name], work / name, name, originals[name], TARGETS[name],
                        units_by_target[name], version, objects, local["binutils"], matching=not mod)
        full_mod = mod and target is None
        if full_mod:
            hashes = {name: hashlib.sha256((work / name / name).read_bytes()).hexdigest()
                      for name in names}
            receipt = work / "build-set.json"
            receipt.write_text(json.dumps(hashes, indent=2) + "\n", encoding="utf-8")
        for name in names:
            (work / name / name).replace(output / name)
            (work / name / "image.map").replace(output / f"{name}.map")
            count = len(units_by_target[name])
            detail = f"{count} compiled C unit(s)" if count else "Splat asm only"
            if mod:
                print(f"MOD  {output.relative_to(ROOT) / name}  ({detail})")
            else:
                print(f"MATCH  {name}  {TARGETS[name]['sha256']}  ({detail})")
        if full_mod:
            receipt.replace(output / "build-set.json")
        elif mod:
            (output / "build-set.json").unlink(missing_ok=True)


def main():
    parser = argparse.ArgumentParser(description="Build and verify all three matching PS2 executables.")
    parser.add_argument("--target", choices=TARGETS, help="build one executable")
    parser.add_argument("--mod", action="store_true", help="build edits into build/mod")
    parser.add_argument("--compiler", choices=TOOLCHAINS["compilers"], help="override the target compiler")
    args = parser.parse_args()
    build(require_local(), args.target, args.mod, args.compiler)


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError, subprocess.CalledProcessError) as error:
        raise SystemExit(f"Build failed: {error}")
