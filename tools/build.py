import argparse
import hashlib
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess
from tempfile import TemporaryDirectory

from common import BASEROM, ROOT, TARGETS, TOOLCHAINS
from common import compiler_path, require_local, run, target_compiler, verify, verify_compiler
from gallery_da import sync_gallery_iso
from objects import validate_object
from qemu_runner import compile_batch
from split import split, target_units

BUILD = ROOT / "build"
OBJ_CACHE = BUILD / "obj"
QEMU_RUNNER = (Path(__file__).resolve().parent / "qemu_runner.py").resolve()


SJIS_CALL_RE = re.compile(r'\bSJIS\s*\(((?:\s*"(?:[^"\\]|\\.)*")+\s*)\)')
C_STRING_RE = re.compile(r'"((?:[^"\\]|\\.)*)"')


def _expand_sjis_match(match):
    inner = match.group(1)
    parts = []
    for s_match in C_STRING_RE.finditer(inner):
        raw = s_match.group(1)
        # Decode standard C escapes like \n, \t, \\, \" while keeping UTF-8 chars intact
        decoded = bytes(raw, "utf-8").decode("unicode_escape").encode("latin1").decode("utf-8")
        parts.append(decoded)
    encoded = "".join(parts).encode("cp932")
    escaped = "".join(f"\\x{b:02X}" for b in encoded)
    newlines = "\n" * inner.count("\n")
    return f'"{escaped}"{newlines}'


def prepare_compile_source(source, output):
    src_path = ROOT / source
    text = src_path.read_text(encoding="utf-8")
    if "SJIS(" not in text:
        return source
    expanded = SJIS_CALL_RE.sub(_expand_sjis_match, text)
    output.parent.mkdir(parents=True, exist_ok=True)
    staged = output.with_suffix(".sjis.c")
    staged.write_text(expanded, encoding="utf-8")
    return staged.relative_to(ROOT).as_posix()


DEATH_DEFINE = "DEATH_LABEL"


def target_defines(target_name, source):
    """Extra compiler flags for a unit: Death Label sees DEATH_LABEL, in sources that test it."""
    if target_name != "DEATH.ELF":
        return ()
    try:
        text = (ROOT / source).read_text(encoding="utf-8")
    except OSError:
        return ()
    return (f"-D{DEATH_DEFINE}",) if DEATH_DEFINE in text else ()


def draft_defines(target_name):
    return (f"-D{DEATH_DEFINE}",) if target_name == "DEATH.ELF" else ()


def unit_object(version, target_name, source):
    """Cached object of a unit as linked into target_name."""
    suffix = "".join("." + flag[2:].lower() for flag in target_defines(target_name, source))
    return OBJ_CACHE / version / f"{source}{suffix}.o"


def compile_source(local, source, output, version, defines=()):
    compiler = compiler_path(version)
    runner = local["runner"]
    if isinstance(runner, str):
        runner = [runner]
    output.parent.mkdir(parents=True, exist_ok=True)
    compile_input = prepare_compile_source(source, output)
    run(*(runner or []), compiler, *TOOLCHAINS["compiler_flags"], *defines, "-o", output.relative_to(ROOT), compile_input)


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


def unit_stamp(version, source, include_hash, defines=()):
    record = TOOLCHAINS["compilers"][version]
    hasher = hashlib.sha256()
    hasher.update(record["sha256"].encode("ascii"))
    hasher.update(b"\0")
    hasher.update("\0".join([*TOOLCHAINS["compiler_flags"], *defines]).encode("utf-8"))
    hasher.update(b"\0")
    hasher.update(include_hash.encode("ascii"))
    hasher.update(b"\0")
    hasher.update((ROOT / source).read_bytes())
    return hasher.hexdigest()


def compile_units(local, jobs):
    include_hash = headers_digest()
    objects = {}
    dirty = []
    for version, source, defines in jobs:
        suffix = "".join("." + flag[2:].lower() for flag in defines)
        obj = OBJ_CACHE / version / f"{source}{suffix}.o"
        stamp_file = obj.with_suffix(".stamp")
        expected = unit_stamp(version, source, include_hash, defines)
        objects[(version, source, defines)] = obj
        if obj.is_file() and stamp_file.is_file():
            try:
                if stamp_file.read_text(encoding="ascii").strip() == expected:
                    continue
            except OSError:
                pass
        dirty.append((version, source, defines, obj, stamp_file, expected))

    if dirty:
        if len(dirty) > 1 and uses_qemu_runner(local):
            batch = [
                (compiler_path(version), [*TOOLCHAINS["compiler_flags"], *defines], obj,
                 ROOT / prepare_compile_source(source, obj))
                for version, source, defines, obj, _, _ in dirty
            ]
            compile_batch(batch)
        else:
            for version, source, defines, obj, _, _ in dirty:
                compile_source(local, source, obj, version, defines)
        for _, _, _, obj, stamp_file, expected in dirty:
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


SYM_ASSIGN_RE = re.compile(r"^\s*([A-Za-z_][A-Za-z0-9_]*)\s*=\s*(0x[0-9A-Fa-f]+)\s*;\s*$")
DLABEL_RE = re.compile(r"^\s*dlabel\s+([A-Za-z_][A-Za-z0-9_]*)\s*$")
ADDR_COMMENT_RE = re.compile(r"/\*\s*[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\b")


def _parse_elf_layout(original):
    e_entry, e_phoff = struct.unpack_from("<II", original, 0x18)
    e_phentsize, e_phnum = struct.unpack_from("<HH", original, 0x2A)
    for i in range(e_phnum):
        p_type, p_off, p_vaddr, _, p_filesz, p_memsz, _, _ = struct.unpack_from(
            "<8I", original, e_phoff + i * e_phentsize
        )
        if p_type == 1:
            return e_entry, p_vaddr, p_vaddr + p_filesz, p_vaddr + p_memsz
    raise ValueError("No PT_LOAD program header found in retail ELF")


def _scan_data_dlabels(folder):
    labels = []
    data_dir = folder / "asm" / "data"
    if not data_dir.is_dir():
        return labels
    for asm_file in sorted(data_dir.glob("*.s")):
        lines = asm_file.read_text(encoding="utf-8").splitlines()
        pending = None
        for line in lines:
            m = DLABEL_RE.match(line)
            if m:
                pending = m.group(1)
                continue
            if pending is not None:
                am = ADDR_COMMENT_RE.search(line)
                if am:
                    labels.append((int(am.group(1), 16), pending))
                    pending = None
    labels.sort()
    return labels


def _prepare_shiftable_mod_link(folder, work_target, original, binutils):
    """Build a shiftable real-ELF linker script + relocatable .bss object for --mod builds."""
    e_entry, load_vaddr, bss_start, bss_end = _parse_elf_layout(original)
    main_ld = (folder / "main.ld").read_text(encoding="utf-8")
    gp_match = re.search(r"_gp\s*=\s*(0x[0-9A-Fa-f]+)\s*;", main_ld)
    retail_gp = int(gp_match.group(1), 16) if gp_match else None

    has_explicit_sbss = "main_SBSS_START" in main_ld

    # Parse undefined_syms.txt + symbols.ld to classify relocatable vs fixed symbols.
    undef_syms = []
    for line in (folder / "undefined_syms.txt").read_text(encoding="utf-8").splitlines():
        m = SYM_ASSIGN_RE.match(line)
        if m:
            undef_syms.append((m.group(1), int(m.group(2), 16)))

    fixed_syms = []
    bss_syms = []
    bss_end_syms = []
    interior_data_syms = []
    gp_sym_names = []

    dlabels = _scan_data_dlabels(folder)
    data_start = dlabels[0][0] if dlabels else bss_start

    for name, addr in undef_syms:
        if retail_gp is not None and addr == retail_gp:
            gp_sym_names.append(name)
        elif addr == bss_end:
            bss_end_syms.append(name)
        elif bss_start <= addr < bss_end:
            if has_explicit_sbss:
                fixed_syms.append((name, addr))
            else:
                bss_syms.append((addr, name))
        elif data_start <= addr < bss_start:
            interior_data_syms.append((addr, name))
        else:
            fixed_syms.append((name, addr))

    # Include any symbols from symbols.ld that live in .sbss/.bss (e.g. gallery_slot_0_state).
    # Compiled .c.o and split .s.o objects already define all relocatable .text/.data symbols.
    defined_bss_names = {name for _, name in bss_syms} | set(bss_end_syms)
    extra_syms_ld = []
    for line in (folder / "symbols.ld").read_text(encoding="utf-8").splitlines():
        m = SYM_ASSIGN_RE.match(line)
        if m:
            name, addr = m.group(1), int(m.group(2), 16)
            if retail_gp is not None and addr == retail_gp:
                if name not in gp_sym_names:
                    gp_sym_names.append(name)
            elif addr == bss_end and name not in defined_bss_names:
                bss_end_syms.append(name)
                defined_bss_names.add(name)
            elif bss_start <= addr < bss_end and not has_explicit_sbss and name not in defined_bss_names:
                bss_syms.append((addr, name))
                defined_bss_names.add(name)
            elif has_explicit_sbss and bss_start < addr < bss_end:
                extra_syms_ld.append((name, addr))
            elif addr < load_vaddr or addr > bss_end:
                extra_syms_ld.append((name, addr))

    mod_bss_o = work_target / "mod_bss.o"
    if not has_explicit_sbss:
        # Build relocatable mod_bss.s placing every .sbss/.bss symbol at its exact offset from bss_start.
        bss_syms.sort(key=lambda item: (item[0], item[1]))
        bss_lines = ['.section .bss, "wa", @nobits', ".align 4"]
        cur = bss_start
        for addr, name in bss_syms:
            if addr > cur:
                bss_lines.append(f".space {addr - cur:#x}")
                cur = addr
            bss_lines.append(f".globl {name}")
            bss_lines.append(f"{name}:")
        if bss_end > cur:
            bss_lines.append(f".space {bss_end - cur:#x}")
        mod_bss_s = work_target / "mod_bss.s"
        mod_bss_s.write_text("\n".join(bss_lines) + "\n", encoding="ascii")
        run(
            binutils["as"], "-EL", "-march=r5900", "-mabi=eabi", "-no-pad-sections",
            "-o", str(mod_bss_o), str(mod_bss_s), cwd=ROOT,
        )

    # Build mod_syms.ld: _gp aliases, _end aliases, interior data offsets, and fixed constants.
    sym_lines = []
    for name in gp_sym_names:
        sym_lines.append(f"{name} = _gp;")
    for name in bss_end_syms:
        sym_lines.append(f"{name} = main_BSS_END;")
    for addr, name in interior_data_syms:
        base = None
        for d_addr, d_name in dlabels:
            if d_addr <= addr:
                base = (d_addr, d_name)
            else:
                break
        if base is not None:
            delta = addr - base[0]
            sym_lines.append(f"{name} = {base[1]} + {delta:#x};")
        else:
            sym_lines.append(f"{name} = {addr:#x};")
    for name, addr in fixed_syms:
        sym_lines.append(f"{name} = {addr:#x};")
    for name, addr in extra_syms_ld:
        if name not in defined_bss_names and name not in gp_sym_names:
            sym_lines.append(f"{name} = {addr:#x};")
    mod_syms_ld = work_target / "mod_syms.ld"
    mod_syms_ld.write_text("\n".join(sym_lines) + "\n", encoding="ascii")

    # Derive mod.ld from main.ld: real PS2 ELF PHDR, no elf_header/elf_tail, dynamic _gp + relocatable .bss.
    out_lines = [
        "PHDRS",
        "{",
        "    main PT_LOAD FLAGS(7);",
        "}",
        "SECTIONS",
        "{",
    ]
    in_main = False
    inserted_sdata_start = False
    for line in main_ld.splitlines():
        stripped = line.strip()
        if stripped.startswith(".main "):
            in_main = True
            out_lines.append(f"    .main {load_vaddr:#x} :")
            continue
        if not in_main:
            continue
        if stripped == "}":
            # Before closing .main, include any newly added mod .text/.data/.rodata/.sdata sections.
            out_lines.append("        *(.text .text.*);")
            out_lines.append("        *(.data .data.*);")
            out_lines.append("        *(.rodata .rodata.*);")
            out_lines.append("        *(.sdata .sdata.*);")
            out_lines.append("        . = ALIGN(., 16);")
            out_lines.append("    } :main")
            in_main = False
            continue
        if "(.bss);" in stripped or "main_BSS_" in stripped:
            continue
        if "(.sdata);" in stripped and not inserted_sdata_start:
            out_lines.append("        main_SDATA_START = .;")
            if retail_gp is not None:
                out_lines.append("        _gp = main_SDATA_START + 0x8000;")
            inserted_sdata_start = True
        out_lines.append(line)

    if not inserted_sdata_start and retail_gp is not None:
        out_lines.append(f"    _gp = {retail_gp:#x};")

    if has_explicit_sbss:
        in_bss = False
        out_lines.append("    .bss (NOLOAD) :")
        out_lines.append("    {")
        for line in main_ld.splitlines():
            stripped = line.strip()
            if stripped.startswith(".main_bss"):
                in_bss = True
                continue
            if not in_bss:
                continue
            if stripped == "{":
                continue
            if stripped == "}":
                out_lines.append("    } :main")
                break
            if stripped == "main_SBSS_END = .;":
                out_lines.append("        *(.sbss .sbss.*);")
            elif stripped == "main_BSS_END = .;":
                out_lines.append("        *(.bss .bss.* COMMON);")
            out_lines.append(line)
        out_lines += [
            "    /DISCARD/ : { *(*); }",
            "}",
        ]
    else:
        out_lines += [
            "    .bss (NOLOAD) :",
            "    {",
            "        main_BSS_START = .;",
            f"        {mod_bss_o.as_posix()}(.bss);",
            "        *(.sbss .sbss.* .bss .bss.* COMMON);",
            "        . = ALIGN(., 16);",
            "        main_BSS_END = .;",
            "    } :main",
            "    /DISCARD/ : { *(*); }",
            "}",
        ]
    mod_ld = work_target / "mod.ld"
    mod_ld.write_text("\n".join(out_lines) + "\n", encoding="utf-8")
    return e_entry, mod_ld, mod_syms_ld


SEC_RULE_RE = re.compile(r"^(\s*)(\S+\.o)\(([^)]+)\);\s*$")
ALIGN_RULE_RE = re.compile(r"^\s*\.\s*=\s*ALIGN\(.*\);\s*$")
ALLOC_SECS = frozenset({".text", ".data", ".rodata", ".sdata", ".sbss", ".bss"})


def _nonempty_elf_sections(obj_path):
    data = obj_path.read_bytes()
    e_shoff, = struct.unpack_from("<I", data, 0x20)
    e_shentsize, e_shnum, e_shstrndx = struct.unpack_from("<HHH", data, 0x2E)
    str_off, = struct.unpack_from("<I", data, e_shoff + e_shstrndx * e_shentsize + 16)
    sections = set()
    for i in range(e_shnum):
        sh_name, _, _, _, _, sh_size = struct.unpack_from("<6I", data, e_shoff + i * e_shentsize)
        if sh_size == 0:
            continue
        end = data.index(b"\x00", str_off + sh_name)
        sections.add(data[str_off + sh_name : end].decode("ascii", "ignore"))
    return sections


def _prepare_compact_link(folder, work_target, binutils, chunk_size=64):
    """Drop empty section rules from main.ld and partial-link contiguous .text-only runs."""
    main_ld = (folder / "main.ld").read_text(encoding="utf-8")
    sec_cache = {}
    filtered = []
    for line in main_ld.splitlines():
        m = SEC_RULE_RE.match(line)
        if m:
            obj_rel, sec = m.group(2), m.group(3)
            if obj_rel not in sec_cache:
                sec_cache[obj_rel] = _nonempty_elf_sections(ROOT / obj_rel)
            if sec not in sec_cache[obj_rel]:
                continue
        filtered.append(line)

    final_lines = []
    run_items = []
    chunk_idx = 0

    def emit_chunk(clines):
        nonlocal chunk_idx
        trailing = []
        while clines and clines[-1][1] is None:
            trailing.append(clines.pop()[0])
        leading = []
        while clines and clines[0][1] is None:
            leading.append(clines.pop(0)[0])
        final_lines.extend(leading)
        if clines:
            c_ld = work_target / f"chunk_{chunk_idx}.ld"
            c_o = work_target / f"chunk_{chunk_idx}.o"
            chunk_idx += 1
            body = "\n".join(line for line, _ in clines)
            c_ld.write_text(f"SECTIONS {{\n  .text : {{\n{body}\n  }}\n}}\n", encoding="utf-8")
            run(binutils["ld"], "-EL", "-r", "-T", str(c_ld), "-o", str(c_o), cwd=ROOT)
            final_lines.append(f"        {c_o.relative_to(ROOT).as_posix()}(.text);")
        final_lines.extend(reversed(trailing))

    def flush_run():
        nonlocal run_items
        objs = sum(1 for _, o in run_items if o is not None)
        if objs < 8:
            final_lines.extend(line for line, _ in run_items)
            run_items = []
            return
        cur = []
        cur_objs = 0
        for item in run_items:
            if item[1] is not None and cur_objs >= chunk_size:
                emit_chunk(cur)
                cur = []
                cur_objs = 0
            cur.append(item)
            if item[1] is not None:
                cur_objs += 1
        if cur:
            emit_chunk(cur)
        run_items = []

    for line in filtered:
        m = SEC_RULE_RE.match(line)
        if m and m.group(3) == ".text":
            obj_rel = m.group(2)
            if (sec_cache[obj_rel] & ALLOC_SECS) == {".text"}:
                run_items.append((line, obj_rel))
                continue
        elif ALIGN_RULE_RE.match(line) and run_items:
            run_items.append((line, None))
            continue
        flush_run()
        final_lines.append(line)
    flush_run()

    compact_ld = work_target / "main.compact.ld"
    compact_ld.write_text("\n".join(final_lines) + "\n", encoding="utf-8")
    return compact_ld


def link_target(folder, work_target, filename, original, target, units, version, objects, binutils, matching, write_map=False):
    name = filename
    assemble_split(folder, binutils)
    objects_root = folder / "objects"
    for unit in units:
        dest = objects_root / f"{unit['source']}.o"
        dest.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(objects[(version, unit["source"], target_defines(name, unit["source"]))], dest)
    work_target.mkdir(parents=True, exist_ok=True)
    elf = work_target / "image.elf"
    link_map = work_target / "image.map"
    out = work_target / filename
    rel = folder.relative_to(ROOT)
    map_args = ["-Map", str(link_map)] if write_map else []
    if matching:
        compact_ld = _prepare_compact_link(folder, work_target, binutils)
        run(
            binutils["ld"], "-EL",
            "-T", str(compact_ld.relative_to(ROOT)),
            "-T", rel / "undefined_funcs.txt",
            "-T", rel / "undefined_syms.txt",
            "-T", rel / "symbols.ld",
            *map_args,
            "-o", str(elf),
            cwd=ROOT,
        )
        run(binutils["objcopy"], "-O", "binary", str(elf), str(out), cwd=ROOT)
        executable = out.read_bytes()
        if hashlib.sha256(executable).hexdigest() != target["sha256"]:
            # keep what was linked, so the first different byte can be looked up
            failed = BUILD / "failed"
            failed.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(out, failed / filename)
            if link_map.is_file():
                shutil.copyfile(link_map, failed / f"{filename}.map")
        if len(executable) != len(original):
            raise ValueError(f"{filename}: size changed from {len(original)} to {len(executable)}")
        verify(executable, target["sha256"], filename)
    else:
        e_entry, mod_ld, mod_syms_ld = _prepare_shiftable_mod_link(folder, work_target, original, binutils)
        run(
            binutils["ld"], "-EL",
            "-e", f"{e_entry:#x}",
            "-T", str(mod_ld),
            "-T", rel / "undefined_funcs.txt",
            "-T", str(mod_syms_ld),
            *map_args,
            "-o", str(out),
            cwd=ROOT,
        )


def build(local, target=None, mod=False, compiler=None, iso=None, write_map=False):
    names = [target] if target else list(TARGETS)
    originals = {
        name: verify((BASEROM / name).read_bytes(), TARGETS[name]["sha256"], f"baserom/{name}")
        for name in names
    }
    units_by_target = {name: target_units(name) for name in names}
    versions = {name: target_compiler(name, local, compiler) for name in names}
    jobs = sorted({
        (versions[name], unit["source"], target_defines(name, unit["source"]))
        for name in names
        for unit in units_by_target[name]
    })
    for version in sorted({version for version, _, _ in jobs}):
        verify_compiler(version)

    split_folders = {name: split(name) for name in names}
    objects = compile_units(local, jobs)

    output = BUILD / "mod" if mod else BUILD
    output.mkdir(parents=True, exist_ok=True)
    with TemporaryDirectory(prefix=".link-", dir=output) as temporary:
        work = Path(temporary)
        for name in names:
            link_target(split_folders[name], work / name, name, originals[name], TARGETS[name],
                        units_by_target[name], versions[name], objects, local["binutils"],
                        matching=not mod, write_map=write_map)
        full_mod = mod and target is None
        if full_mod:
            hashes = {name: hashlib.sha256((work / name / name).read_bytes()).hexdigest()
                      for name in names}
            receipt = work / "build-set.json"
            receipt.write_text(json.dumps(hashes, indent=2) + "\n", encoding="utf-8")
        for name in names:
            (work / name / name).replace(output / name)
            if write_map:
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
    if mod and iso is not None and "GALLERY.ELF" in names:
        iso_path = Path(iso) if iso else (Path(local["iso"]) if local.get("iso") else None)
        if iso_path is None:
            raise ValueError("Pass --iso PATH or run tools/setup.py --iso PATH first.")
        out_iso, changed_ids, wrote = sync_gallery_iso(iso_path)
        summary = f"modified entries {changed_ids}" if changed_ids else "retail assets"
        action = "UPDATED" if wrote else "UP-TO-DATE"
        print(f"ISO  {out_iso.relative_to(ROOT)}  ({action}, {summary})")


def main():
    parser = argparse.ArgumentParser(description="Build and verify all three matching PS2 executables.")
    parser.add_argument("--target", choices=TARGETS, help="build one executable")
    parser.add_argument("--mod", action="store_true", help="build edits into build/mod")
    parser.add_argument("--iso", nargs="?", const="", help="with --mod, incrementally sync assets/ into build/mod/ddpdoj.iso")
    parser.add_argument("--compiler", choices=TOOLCHAINS["compilers"], help="override the target compiler")
    parser.add_argument("--map", action="store_true", help="emit linker .map files into build/")
    args = parser.parse_args()
    build(require_local(), args.target, args.mod, args.compiler, args.iso, write_map=args.map)


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError, subprocess.CalledProcessError) as error:
        raise SystemExit(f"Build failed: {error}")
