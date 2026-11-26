"""Fast compile-and-score for one function, without the link/objcopy/objdump chain.

Compiles each C file with the target's compiler, reads the function's .text bytes and
relocations straight from the object, masks relocated fields on both sides, and counts
differing instructions against retail (a difflib alignment, so inserts/deletes count).

    uv run tools/fastscore.py SLPS_252.33 func_XXXXXXXX a.c [b.c ...] [-j 8]

A score of 0 means the masked words agree; confirm with tools/matching/diff.py before integrating
(relocation targets are not compared here).
"""
import argparse
from concurrent.futures import ThreadPoolExecutor
import difflib
import os
from pathlib import Path
import struct
import subprocess
import sys
from tempfile import TemporaryDirectory
import time

import sys as _sys
from pathlib import Path as _Path
if str(_Path(__file__).resolve().parent.parent) not in _sys.path:
    _sys.path.insert(0, str(_Path(__file__).resolve().parent.parent))
from build import draft_defines
from common import BASEROM, ROOT, TARGETS, TOOLCHAINS, TOOLS
from common import compiler_path, require_local, target_compiler, verify, verify_compiler

CACHE = ROOT / "build" / "fastscore"

# R_MIPS_* types -> mask of the field the linker fills in.
RELOC_MASKS = {2: 0xFFFFFFFF, 4: 0x03FFFFFF, 5: 0xFFFF, 6: 0xFFFF, 7: 0xFFFF}


def runner():
    if sys.platform == "win32":
        return []
    cfg = TOOLCHAINS["wibo"]
    key = "darwin" if sys.platform == "darwin" else "linux-x86_64"
    path = TOOLS / "wibo" / cfg["version"] / cfg[key][0]
    if path.is_file():
        return [str(path)]
    local = require_local().get("runner")
    if not local:
        return []
    return [local] if isinstance(local, str) else list(local)


def retail_bytes(target, function):
    """Retail bytes of the function, cached under build/fastscore/."""
    cached = CACHE / target / f"{function}.bin"
    if cached.is_file():
        return cached.read_bytes()
    from split import scan_asm_functions, split, target_layout, target_units, load_symbols
    folder = split(target)
    units = target_units(target)
    unit = next((u for u in units if u["name"] == function), None)
    if unit is not None:
        address, size = unit["address"], unit["size"]
    else:
        symbols = load_symbols(target)
        sym = symbols.get(function)
        if sym is not None and sym[1] is not None:
            address, size = sym
        else:
            address, size = scan_asm_functions(folder / "asm")[function]
    rom = verify((BASEROM / target).read_bytes(), TARGETS[target]["sha256"], target)
    file_address, _, _ = target_layout(target)
    data = rom[address - file_address:address - file_address + size]
    cached.parent.mkdir(parents=True, exist_ok=True)
    cached.write_bytes(data)
    return data


def read_function(obj, function):
    """(code bytes, {offset: mask}) for `function` in a relocatable object."""
    data = obj.read_bytes()
    shoff, = struct.unpack_from("<I", data, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", data, 0x2E)
    sections = [struct.unpack_from("<10I", data, shoff + i * shentsize) for i in range(shnum)]
    names_off = sections[shstrndx][4]

    def cstr(offset):
        return data[offset:data.index(0, offset)].decode("ascii")

    named = {cstr(names_off + s[0]): i for i, s in enumerate(sections)}
    text_index = named[".text"]
    text = sections[text_index]
    symtab = sections[named[".symtab"]]
    strtab_off = sections[symtab[6]][4]
    start = size = None
    for name, value, sz, info, _, shndx in struct.iter_unpack("<IIIBBH", data[symtab[4]:symtab[4] + symtab[5]]):
        if shndx == text_index and cstr(strtab_off + name) == function:
            start, size = value, sz
            break
    if start is None:
        raise ValueError(f"{function} not found in {obj}")
    code = data[text[4] + start:text[4] + start + size]
    masks = {}
    for sec in sections:
        if sec[1] == 9 and sec[7] == text_index:  # SHT_REL for .text
            for r_offset, r_info in struct.iter_unpack("<II", data[sec[4]:sec[4] + sec[5]]):
                mask = RELOC_MASKS.get(r_info & 0xFF)
                if mask and start <= r_offset < start + size:
                    masks[r_offset - start] = masks.get(r_offset - start, 0) | mask
    return code, masks


def score(retail, code, masks):
    """Number of differing instructions after masking relocated fields."""
    def words(blob):
        return list(struct.unpack(f"<{len(blob) // 4}I", blob[:len(blob) // 4 * 4]))
    cand, ret = words(code), words(retail)
    for offset, mask in masks.items():
        i = offset // 4
        cand[i] &= ~mask
        if i < len(ret):
            ret[i] &= ~mask
    if cand == ret:
        return 0
    total = 0
    for tag, i1, i2, j1, j2 in difflib.SequenceMatcher(None, ret, cand, autojunk=False).get_opcodes():
        if tag != "equal":
            total += max(i2 - i1, j2 - j1)
    return total


class Scorer:
    def __init__(self, target, function):
        version = target_compiler(target, require_local())
        verify_compiler(version)
        self.cmd = [*runner(), str(compiler_path(version)), *TOOLCHAINS["compiler_flags"], *draft_defines(target)]
        self.function = function
        self.retail = retail_bytes(target, function)

    def __call__(self, source):
        with TemporaryDirectory(prefix="fastscore-") as tmp:
            out = Path(tmp) / "out.o"
            proc = subprocess.run([*self.cmd, "-o", str(out), str(Path(source).resolve())],
                                  cwd=ROOT, capture_output=True, timeout=120)
            if proc.returncode != 0 or not out.is_file():
                return None
            code, masks = read_function(out, self.function)
            return score(self.retail, code, masks)


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("target", choices=TARGETS)
    parser.add_argument("function")
    parser.add_argument("sources", nargs="+", type=Path)
    parser.add_argument("-j", "--jobs", type=int, default=os.cpu_count())
    args = parser.parse_args()
    scorer = Scorer(args.target, args.function)
    began = time.perf_counter()
    with ThreadPoolExecutor(args.jobs) as pool:
        results = list(pool.map(scorer, args.sources))
    elapsed = time.perf_counter() - began
    for source, result in zip(args.sources, results):
        print(f"{'ERROR' if result is None else result:>6}  {source}")
    print(f"{len(args.sources)} file(s) in {elapsed:.2f}s ({elapsed / len(args.sources) * 1000:.0f} ms each, {args.jobs} jobs)",
          file=sys.stderr)


if __name__ == "__main__":
    main()
