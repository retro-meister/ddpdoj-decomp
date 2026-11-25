import argparse
import copy
import functools
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import yaml

from common import BASEROM, ROOT, TARGETS, matching_lock, run, verify

SYMBOL_RE = re.compile(r"^\s*([A-Za-z_][A-Za-z0-9_]*)\s*=\s*(0x[0-9a-fA-F]+|\d+)\s*;(.*)$")
SIZE_RE = re.compile(r"\bsize:(0x[0-9a-fA-F]+|\d+)\b")
INSN_ADDR_RE = re.compile(r"/\*\s*[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\s+[0-9A-Fa-f]{8}\s*\*/")


def scan_asm_functions(asm_dir):
    """{name: (address, size)} for every glabel in asm_dir, cached on disk per file version (name, mtime, size)."""
    if not asm_dir.is_dir():
        return {}
    files = sorted(asm_dir.glob("*.s"))
    key = hashlib.sha256("\n".join(f"{f.name}:{f.stat().st_mtime_ns}:{f.stat().st_size}" for f in files).encode()).hexdigest()
    cache = asm_dir.parent / "asm-functions-cache.json"
    try:
        data = json.loads(cache.read_text(encoding="utf-8"))
        if data.get("key") == key:
            return {name: tuple(value) for name, value in data["functions"].items()}
    except (OSError, ValueError):
        pass
    functions = _scan_asm_functions(files)
    tmp = cache.with_suffix(f".{os.getpid()}.tmp")
    tmp.write_text(json.dumps({"key": key, "functions": functions}), encoding="utf-8")
    tmp.replace(cache)
    return functions


def _scan_asm_functions(files):
    functions = {}
    asm_dir = None
    for asm in files:
        current = None
        first_addr = None
        last_addr = None
        for line in asm.read_text(encoding="utf-8").splitlines():
            stripped = line.strip()
            if stripped.startswith("glabel "):
                current = stripped.split()[1]
                first_addr = None
                last_addr = None
            elif stripped.startswith("endlabel ") and current is not None:
                if first_addr is not None and last_addr is not None:
                    functions[current] = (first_addr, last_addr - first_addr + 4)
                current = None
            elif current is not None:
                match = INSN_ADDR_RE.search(line)
                if match:
                    addr = int(match.group(1), 16)
                    if first_addr is None:
                        first_addr = addr
                    last_addr = addr
    return functions


def splat_versions():
    import spimdisasm
    import splat
    return f"{splat.__version__}:{spimdisasm.__version__}"


def config_dir(name):
    return ROOT / "config" / name


def splat_yaml_path(name):
    return config_dir(name) / "splat.yaml"


def symbols_path(name):
    return config_dir(name) / "symbols.txt"


def split_dir(name):
    return ROOT / "build" / "split" / name


@functools.lru_cache(maxsize=8)
def _parse_splat_config(path, mtime_ns, size):
    # libyaml's C loader is ~10x faster than the pure-Python one on the large target configs.
    return yaml.load(Path(path).read_text(encoding="utf-8"), Loader=yaml.CSafeLoader)


def load_splat_config(name):
    """Parsed splat YAML, cached per file version (integrate.py rewrites it mid-process). Returns a private copy."""
    path = splat_yaml_path(name)
    stat = path.stat()
    return copy.deepcopy(_parse_splat_config(str(path), stat.st_mtime_ns, stat.st_size))


def load_symbols(name):
    config = load_splat_config(name)
    symbols = {"_gp": (int(config["options"]["gp_value"]), None)}
    for line in symbols_path(name).read_text(encoding="utf-8").splitlines():
        match = SYMBOL_RE.match(line)
        if not match:
            continue
        sym_name, addr_str, rest = match.groups()
        size_match = SIZE_RE.search(rest)
        size = int(size_match.group(1), 0) if size_match else None
        symbols[sym_name] = (int(addr_str, 0), size)
    return symbols


def target_layout(name):
    config = load_splat_config(name)
    main = next(seg for seg in config["segments"] if isinstance(seg, dict) and seg.get("name") == "main")
    load_offset = int(main["start"])
    load_address = int(main["vram"])
    file_address = load_address - load_offset
    code_end = None
    for sub in main["subsegments"]:
        if isinstance(sub, list) and len(sub) >= 2 and sub[1] in ("data", ".data", "rodata", ".rodata", "sdata", ".sdata"):
            code_end = file_address + int(sub[0])
            break
    return file_address, load_offset, code_end


def target_units(name):
    config = load_splat_config(name)
    symbols = load_symbols(name)
    by_addr = {addr: (sym, size) for sym, (addr, size) in symbols.items() if sym != "_gp"}
    main = next(seg for seg in config["segments"] if isinstance(seg, dict) and seg.get("name") == "main")
    file_address = int(main["vram"]) - int(main["start"])
    src_path = Path(config["options"].get("src_path", "src"))
    subsegments = main["subsegments"]
    rodata_addresses = {
        sub[2]: file_address + int(sub[0])
        for sub in subsegments
        if isinstance(sub, list) and len(sub) >= 3 and sub[1] == ".rodata"
    }
    units = []
    for index, sub in enumerate(subsegments):
        if not (isinstance(sub, list) and len(sub) >= 3 and sub[1] == "c"):
            continue
        offset = int(sub[0])
        address = file_address + offset
        stub = sub[2]
        source = (src_path / f"{stub}.c").as_posix()
        sym_name, sym_size = by_addr.get(address, (Path(stub).stem, None))
        if sym_size is None:
            next_offset = int(subsegments[index + 1][0])
            sym_size = next_offset - offset
        span = int(subsegments[index + 1][0]) - offset if index + 1 < len(subsegments) else sym_size
        unit = {"name": sym_name, "stub": stub, "source": source, "address": address, "size": sym_size, "span": span}
        if stub in rodata_addresses:
            unit["rodata_address"] = rodata_addresses[stub]
        units.append(unit)
    return units


def data_units(name):
    """Sources that define data only: named in a `.data`-style entry of the splat config with no `c` entry.
    Splat links such an entry from `src/<name>.c` like any other unit's section."""
    config = load_splat_config(name)
    main = next(seg for seg in config["segments"] if isinstance(seg, dict) and seg.get("name") == "main")
    src_path = Path(config["options"].get("src_path", "src"))
    code, data = set(), []
    for sub in main["subsegments"]:
        if isinstance(sub, dict):
            kind, stub = sub.get("type", ""), sub.get("name")
        else:
            kind, stub = (sub[1], sub[2]) if len(sub) >= 3 else ("", None)
        if kind == "c":
            code.add(stub)
        elif kind.startswith(".") and stub and stub not in data:
            data.append(stub)
    return [{"stub": stub, "source": (src_path / f"{stub}.c").as_posix()} for stub in data if stub not in code]


def aliases_path(name):
    """Second names for objects that some sources still declare with another type (tools/typealias.py).
    Splat allows one name per address, so these are kept out of symbols.txt and only reach the linker."""
    return symbols_path(name).with_name("aliases.txt")


def aliases_text(name):
    path = aliases_path(name)
    return path.read_text(encoding="utf-8") if path.is_file() else ""


def write_symbols_ld(name, folder):
    lines = []
    for line in (symbols_path(name).read_text(encoding="utf-8") + aliases_text(name)).splitlines():
        match = SYMBOL_RE.match(line)
        if match:
            sym_name, addr_str, _ = match.groups()
            lines.append(f"{sym_name} = {int(addr_str, 0):#x};")
    out = folder / "symbols.ld"
    out.write_text("\n".join(lines) + "\n", encoding="ascii")
    return out


def align_rodata_subsegments(folder):
    """Give each split `rodata_<offset>` file the alignment its start offset has (up to 16).

    spimdisasm only emits `.align 2` for string-only rodata, so a subsegment that follows a
    C unit's shorter .rodata (e.g. a 0x2C-byte jump table) would be linked 4 bytes early.
    Vaddr and file offset share their low four bits, so on a contiguous layout this adds no
    padding; it only restores the gap the original unit's own alignment produced.
    """
    data_dir = folder / "asm" / "data"
    for path in list(data_dir.glob("*data_*.*data.s")) + list(data_dir.glob("bss_*.bss.s")) + list(data_dir.glob("sbss_*.sbss.s")):
        # the same holds for a `data_<offset>` slice that follows a C unit's .data, and for a
        # `bss_<address>` / `sbss_<address>` slice that follows a C unit's .bss / .sbss
        match = re.fullmatch(r"(?:(?:ro|s)?data|s?bss)_([0-9a-f]+)\.(?:(?:ro|s)?data|s?bss)\.s", path.name)
        if not match:
            continue
        offset = int(match.group(1), 16)
        power = 4 if offset % 16 == 0 else 3 if offset % 8 == 0 else 0
        if path.name.startswith("bss_") and offset % 64 == 0:
            # a C unit's last object may end short of the 64 the next object here is aligned to
            power = 6
        if path.name.startswith(("sbss_", "sdata_")):
            # a C unit's last small variable may be 2 bytes long; the next slice still starts on a word
            power = max(power, 2) if offset % 4 == 0 else 0
        elif power <= 2:
            continue
        if power < 2:
            continue
        text = path.read_text(encoding="utf-8")
        lines = text.split("\n")
        for i, line in enumerate(lines):
            stripped = line.strip()
            if stripped.startswith(".align"):
                if int(stripped.split()[1]) < power:
                    lines[i] = f".align {power}"
                break
            if stripped.startswith(("nonmatching", "dlabel", "glabel")):
                lines.insert(i, f".align {power}")
                break
        path.write_text("\n".join(lines), encoding="utf-8")


def numbers_path(name):
    return config_dir(name) / "numbers.txt"


def numbers_text(name):
    path = numbers_path(name)
    return path.read_text(encoding="utf-8") if path.is_file() else ""


def write_number_words(name, folder):
    """Write the data words listed in config/<target>/numbers.txt as numbers.

    Splat writes a word as a symbol when its value is the address of something it knows. Where the value is
    also the address of a function or of a label the code uses, an `ignore:true` line cannot stop that, and a
    shifted link would then change a word that is a number (a page address in the SDK's memory-map table, a
    pair of 16-bit values). The file lists the addresses of such words, one per line, `#` for comments."""
    wanted = set()
    for line in numbers_text(name).splitlines():
        line = line.split("#")[0].strip()
        if line:
            wanted.add(int(line, 16))
    if not wanted:
        return
    pattern = re.compile(r"^(\s*/\* [0-9A-F]+ ([0-9A-F]{8}) ([0-9A-F]{8}) \*/\s+\.word\s+)[A-Za-z_][\w.]*(?:\s*\+\s*\w+)?\s*$")
    done = set()
    for path in sorted((folder / "asm" / "data").glob("*.s")):
        lines = path.read_text(encoding="utf-8").split("\n")
        changed = False
        for i, line in enumerate(lines):
            m = pattern.match(line)
            if m and int(m.group(2), 16) in wanted:
                value = int.from_bytes(bytes.fromhex(m.group(3)), "little")
                lines[i] = f"{m.group(1)}0x{value:08X}"
                done.add(int(m.group(2), 16))
                changed = True
        if changed:
            path.write_text("\n".join(lines), encoding="utf-8")
    missing = sorted(wanted - done)
    if missing:
        raise SystemExit(f"{numbers_path(name)}: no symbol word at " + ", ".join(f"{a:#x}" for a in missing))


def split(name, force=False):
    # Diffs run in parallel under a shared matching lock; only one of them may refresh a stale split at a time.
    with matching_lock(name="split.lock"):
        return _split(name, force)


def _split(name, force=False):
    target = TARGETS[name]
    verify((BASEROM / name).read_bytes(), target["sha256"], name)
    yaml_text = splat_yaml_path(name).read_text(encoding="utf-8")
    sym_text = symbols_path(name).read_text(encoding="utf-8")
    fingerprint = hashlib.sha256(
        (splat_versions() + "\n" + yaml_text + "\n" + sym_text + aliases_text(name) + numbers_text(name)
         + Path(__file__).read_text(encoding="utf-8")).encode("utf-8")  # post-processing lives in this file
    ).hexdigest()
    folder = split_dir(name)
    state_file = folder / "split-state.json"
    if not force and state_file.is_file() and (folder / "main.ld").is_file() and (folder / "symbols.ld").is_file():
        try:
            if json.loads(state_file.read_text(encoding="utf-8")).get("fingerprint") == fingerprint:
                return folder
        except (OSError, ValueError):
            pass
    folder.mkdir(parents=True, exist_ok=True)
    for stale in ("asm", "assets", "objects", ".splat_cache"):
        path = folder / stale
        if path.is_dir():
            shutil.rmtree(path)
        elif path.is_file():
            path.unlink()
    run(sys.executable, "-m", "splat", "split", splat_yaml_path(name).relative_to(ROOT), cwd=ROOT)
    # Splat applies a single SUBALIGN(16) to the entire .main output section, which
    # over-aligns .rodata subsegments (e.g. 8-byte aligned strings following a 24-byte
    # jump table). Replace section-wide SUBALIGN(16) on .main with explicit 16-byte
    # alignment before each asm .text input section so .c.o natural alignments apply.
    ld_path = folder / "main.ld"
    ld_text = ld_path.read_text(encoding="utf-8")
    if ".main " in ld_text and " SUBALIGN(16)" in ld_text:
        patched_lines = []
        in_main = False
        for line in ld_text.splitlines():
            if line.lstrip().startswith(".main_bss "):
                line = line.replace(" SUBALIGN(16)", "")     # C units own parts of .sbss/.bss too
            if line.lstrip().startswith(".main "):
                in_main = True
                line = line.replace(" SUBALIGN(16)", "")
            elif in_main and line.lstrip().startswith("}"):
                in_main = False
            elif in_main and ".s.o(.text);" in line:
                patched_lines.append("        . = ALIGN(., 16);")
            patched_lines.append(line)
        ld_path.write_text("\n".join(patched_lines) + "\n", encoding="utf-8")
    align_rodata_subsegments(folder)
    write_number_words(name, folder)
    write_symbols_ld(name, folder)
    state_file.write_text(json.dumps({"fingerprint": fingerprint}, indent=2) + "\n", encoding="utf-8")
    return folder


def main():
    parser = argparse.ArgumentParser(description="Disassemble verified PS2 executables with Splat.")
    parser.add_argument("--target", choices=TARGETS)
    parser.add_argument("--force", action="store_true")
    args = parser.parse_args()
    for name in [args.target] if args.target else TARGETS:
        folder = split(name, force=args.force)
        print(folder.relative_to(ROOT))


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError, subprocess.CalledProcessError) as error:
        raise SystemExit(f"Split failed: {error}")
