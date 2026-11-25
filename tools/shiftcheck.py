"""Check that an executable builds correctly when its contents move.

    uv run tools/shiftcheck.py [--target SLPS_252.33] [--shift 0x40] [--list]

Links the target three ways with the shiftable (`--mod`) script: unshifted, and with the game code and each
later section pushed down by a multiple of --shift. Then it reports:

1. whether the unshifted link is byte-identical to retail in the loaded image;
2. bytes of the shifted image that differ from retail somewhere no relocation applies (must be none);
3. values in the retail image that look like addresses of the image but carry no relocation: a word of data,
   a `lui` + low-half pair, or a jump. Each one is either a number that only looks like an address or an
   address that would not follow a shift; --list prints them for review.
4. for the two game executables, the same data words sorted by what the other executable holds in the same
   place: an address differs between the two, a number does not.
"""
import argparse
import bisect
from pathlib import Path
import struct

from build import BUILD, build
from common import BASEROM, ROOT, require_local

R_MIPS_32, R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16, R_MIPS_GPREL16 = 2, 4, 5, 6, 7


class Elf:
    def __init__(self, path):
        self.data = Path(path).read_bytes()
        data = self.data
        phoff, shoff = struct.unpack_from("<II", data, 0x1C)
        phentsize, phnum, shentsize, shnum, shstrndx = struct.unpack_from("<HHHHH", data, 0x2A)
        self.load = None
        for i in range(phnum):
            kind, offset, vaddr, _, filesz, memsz, _, _ = struct.unpack_from("<8I", data, phoff + i * phentsize)
            if kind == 1 and self.load is None:
                self.load = (offset, vaddr, filesz, memsz)
        self.headers = [struct.unpack_from("<10I", data, shoff + i * shentsize) for i in range(shnum)] if shoff else []
        self.symbols = {}
        self.relocations = {}
        for header in self.headers:
            if header[1] == 2:
                strtab = self.headers[header[6]][4]
                table = data[header[4]:header[4] + header[5]]
                self.symbol_table = []
                for name, value, _, info, _, shndx in struct.iter_unpack("<IIIBBH", table):
                    end = data.index(0, strtab + name)
                    text = data[strtab + name:end].decode("ascii", "replace")
                    self.symbol_table.append((text, value, shndx))
                    if (info >> 4 and shndx and shndx < 0xFF00 and not text.endswith(".NON_MATCHING")
                            and (text.endswith("_START") or not text.startswith(("main_", "_gp")))):
                        self.symbols[text] = value
        for header in self.headers:
            if header[1] == 9:
                for offset, info in struct.iter_unpack("<II", data[header[4]:header[4] + header[5]]):
                    self.relocations[offset] = (info & 0xFF, self.symbol_table[info >> 8][0])

    def image(self):
        offset, vaddr, filesz, memsz = self.load
        return vaddr, self.data[offset:offset + filesz], vaddr + memsz


def retail_image(target):
    data = (BASEROM / target).read_bytes()
    phoff, = struct.unpack_from("<I", data, 0x1C)
    phentsize, phnum = struct.unpack_from("<HH", data, 0x2A)
    for i in range(phnum):
        kind, offset, vaddr, _, filesz, memsz, _, _ = struct.unpack_from("<8I", data, phoff + i * phentsize)
        if kind == 1:
            return vaddr, data[offset:offset + filesz], vaddr + memsz
    raise ValueError("no loadable segment")


def link(target, shift, folder):
    build(require_local(), target, mod=True, shift=shift, emit_relocs=True, output=folder)
    return Elf(folder / target)


def compare_shifted(base, moved):
    """Bytes outside relocation sites that changed between the unshifted and the shifted image."""
    start, image, _ = base.image()
    moved_start, moved_image, _ = moved.image()
    names = sorted((value, name) for name, value in base.symbols.items()
                   if name in moved.symbols and start <= value < start + len(image))
    addresses = [value for value, _ in names]
    covered = set()
    for site, (kind, _) in base.relocations.items():
        covered.update(range(site, site + 4))
    bad = []
    for index, (address, name) in enumerate(names):
        end = addresses[index + 1] if index + 1 < len(names) else start + len(image)
        delta = moved.symbols[name] - address
        for position in range(address, end):
            if position in covered:
                continue
            other = position + delta - moved_start
            if not 0 <= other < len(moved_image) or image[position - start] != moved_image[other]:
                bad.append((position, name))
                break
    return bad


def unrelocated(target, base, text_end):
    """Address-like values of the retail image that no relocation covers."""
    start, image, memory_end = retail_image(target)
    sites = base.relocations
    words = struct.unpack_from(f"<{len(image) // 4}I", image)
    data, pairs, jumps = [], [], []
    text_words = (text_end - start) // 4
    for index in range(text_words, len(words)):
        value = words[index]
        if start <= value < memory_end and start + index * 4 not in sites:
            data.append((start + index * 4, value))
    upper = {}
    for index in range(text_words):
        word = words[index]
        address = start + index * 4
        opcode = word >> 26
        rs, rt, immediate = (word >> 21) & 31, (word >> 16) & 31, word & 0xFFFF
        if opcode in (2, 3):
            if address not in sites and start <= ((address & 0xF0000000) | ((word & 0x3FFFFFF) << 2)) < text_end and word != 0:
                jumps.append((address, (word & 0x3FFFFFF) << 2))
            upper = {}
            continue
        if opcode == 15:
            upper[rt] = (address, immediate)
            continue
        if rs in upper and (opcode in (9, 13) or 32 <= opcode <= 63):
            site, high = upper[rs]
            low = immediate if opcode == 13 else immediate - 0x10000 if immediate & 0x8000 else immediate
            value = (high << 16) + low
            if start <= value < memory_end and site not in sites:
                pairs.append((site, value))
        if opcode in (4, 5, 1, 6, 7, 20, 21) or (opcode == 0 and (word & 0x3F) in (8, 9)):
            upper = {}
        elif opcode == 0 and ((word >> 11) & 31) in upper:
            upper.pop((word >> 11) & 31)
        elif opcode not in (0, 43, 41, 40, 63, 57, 49) and rt in upper and rs != rt and opcode != 15:
            upper.pop(rt, None)
    return data, sorted(set(pairs)), jumps


def against_twin(base, other, twin, data):
    """Sort the unrelocated address-like data words by what the twin executable holds in the same place.

    The two game executables share their data but place nearly all of it at different addresses, so a word
    that is an address differs between them and a word that is a number does not."""
    _, other_image, _ = retail_image(twin)
    other_start = other.image()[0]
    common = sorted((value, name) for name, value in base.symbols.items() if name in other.symbols)
    keys = [value for value, _ in common]

    def moved(address):
        index = bisect.bisect_right(keys, address) - 1
        if index < 0:
            return None
        return other.symbols[common[index][1]] + address - common[index][0]

    numbers, unmoved, differ, unplaced, follow = [], [], [], [], []
    for address, value in data:
        place = moved(address)
        if place is None or not 0 <= place - other_start <= len(other_image) - 4:
            unplaced.append((address, value, 0))
            continue
        there, = struct.unpack_from("<I", other_image, place - other_start)
        if there != value:
            (follow if there == moved(value) else differ).append((address, value, there))
        elif moved(value) == value:
            unmoved.append((address, value, there))
        else:
            numbers.append((address, value, there))
    return numbers, unmoved, differ, unplaced, follow


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--target", default="SLPS_252.33")
    parser.add_argument("--shift", type=lambda v: int(v, 0), default=0x40)
    parser.add_argument("--list", action="store_true")
    parser.add_argument("--no-twin", action="store_true", help="skip the comparison with the other game executable")
    args = parser.parse_args()
    work = BUILD / "shiftcheck"
    base = link(args.target, 0, work / "base")
    start, image, memory_end = retail_image(args.target)
    base_start, base_image, base_end = base.image()
    same = (start, image, memory_end) == (base_start, base_image, base_end)
    print(f"unshifted link identical to retail image: {'yes' if same else 'NO'}")
    if not same and len(image) == len(base_image):
        first = next(i for i in range(len(image)) if image[i] != base_image[i])
        print(f"  first difference at {start + first:#x}")
    moved = link(args.target, args.shift, work / "moved")
    print(f"shifted link: image {moved.image()[0]:#x}..{moved.image()[2]:#x} (retail ..{memory_end:#x}), "
          f"{len(base.relocations):,} relocation sites")
    bad = compare_shifted(base, moved)
    print(f"labels whose contents changed outside relocation sites: {len(bad)}")
    for position, name in bad[:40 if not args.list else None]:
        print(f"  {position:#x} in {name}")
    text_end = next(value for name, value, _ in base.symbol_table if name == "main_DATA_START")
    data, pairs, jumps = unrelocated(args.target, base, text_end)
    print(f"address-like values with no relocation: {len(data)} data words, {len(pairs)} lui pairs, {len(jumps)} jumps")
    ignored = {line.split("=")[0].strip() for line in
               (ROOT / "config" / args.target / "symbols.txt").read_text(encoding="utf-8").splitlines()
               if "ignore:true" in line}
    # a label made only because some word looked like a pointer to it says nothing; keep named ones and code
    exact = {value for name, value in base.symbols.items()
             if name not in ignored and not (name.startswith("D_") and value >= text_end)}
    hits = [(address, value) for address, value in data + pairs if value in exact]
    print(f"of those, values that are exactly the address of a label: {len(hits)}")
    twin = {"SLPS_252.33": "DEATH.ELF", "DEATH.ELF": "SLPS_252.33"}.get(args.target)
    if twin and not args.no_twin:
        numbers, unmoved, differ, unplaced, follow = against_twin(base, link(twin, 0, work / "twin"), twin, data)
        print(f"data words checked against {twin}: {len(numbers)} hold the same value there although what they "
              f"would point at moved (numbers), {len(unmoved)} the same value and the target did not move, "
              f"{len(differ)} an unrelated value, {len(unplaced)} with no counterpart")
        print(f"data words that follow the move like an address but carry no relocation: {len(follow)}")
        for address, value, there in follow[:None if args.list else 20]:
            print(f"  {address:#x} -> {value:#x} (twin {there:#x})")
        if args.list:
            for title, rows in (("unrelated value in the twin", differ), ("target did not move", unmoved)):
                print(title)
                for address, value, other in rows:
                    print(f"  {address:#x} -> {value:#x} (twin {other:#x})")
    if args.list:
        labels = sorted((value, name) for name, value in base.symbols.items())
        keys = [value for value, _ in labels]

        def where(address):
            index = bisect.bisect_right(keys, address) - 1
            return f"{labels[index][1]}+{address - labels[index][0]:#x}" if index >= 0 else "?"

        for title, rows in (("exact label addresses", hits), ("data words", data), ("lui pairs", pairs), ("jumps", jumps)):
            print(title)
            for address, value in rows:
                print(f"  {address:#x} ({where(address)}) -> {value:#x} ({where(value)})")


if __name__ == "__main__":
    main()
