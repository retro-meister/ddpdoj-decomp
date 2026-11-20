import argparse
import hashlib
import os
from pathlib import Path
import shutil
from tempfile import NamedTemporaryFile

from common import ROOT, TARGETS, read_json, verify

SECTOR = 2048


def read_at(file, offset, size):
    file.seek(offset)
    data = file.read(size)
    if len(data) != size:
        raise ValueError("ISO extent exceeds the image size")
    return data


def dual_endian(data, offset, size):
    little = int.from_bytes(data[offset:offset + size], "little")
    big = int.from_bytes(data[offset + size:offset + size * 2], "big")
    if little != big:
        raise ValueError("Inconsistent ISO9660 record")
    return little


def root_directory(file):
    for sector in range(16, 256):
        descriptor = read_at(file, sector * SECTOR, SECTOR)
        if descriptor[1:7] != b"CD001\x01" or descriptor[0] == 255:
            break
        if descriptor[0] == 1:
            if dual_endian(descriptor, 128, 2) != SECTOR:
                raise ValueError("Expected a 2048-byte ISO9660 logical block")
            record = descriptor[156:]
            return read_at(file, dual_endian(record, 2, 4) * SECTOR,
                           dual_endian(record, 10, 4))
    raise ValueError("ISO9660 primary volume descriptor not found")


def directory_entries(directory):
    cursor = 0
    while cursor < len(directory):
        length = directory[cursor]
        if length == 0:
            cursor = (cursor // SECTOR + 1) * SECTOR
            continue
        record = directory[cursor:cursor + length]
        cursor += length
        if len(record) < 34 or len(record) < 33 + record[32]:
            raise ValueError("Invalid ISO9660 directory entry")
        identifier = record[33:33 + record[32]]
        if identifier not in (b"\x00", b"\x01"):
            name = identifier.decode("ascii").split(";", 1)[0].rstrip(".")
            yield name, record


def find_extent(file, directory, path):
    name, _, remaining = path.partition("/")
    records = [record for entry, record in directory_entries(directory)
               if entry == name]
    if len(records) != 1:
        raise ValueError(f"Expected one ISO9660 entry for {path}")
    record = records[0]
    is_directory = bool(record[25] & 2)
    if is_directory != bool(remaining) or record[25] & 0x80 or any(record[i] for i in (1, 26, 27)):
        raise ValueError(f"{path}: expected a contiguous ISO9660 extent")
    offset = dual_endian(record, 2, 4) * SECTOR
    size = dual_endian(record, 10, 4)
    if remaining:
        return find_extent(file, read_at(file, offset, size), remaining)
    return offset, size


def executable_extents(file):
    directory = root_directory(file)
    return {name: find_extent(file, directory, name) for name in TARGETS}


def repackage(iso, output, elf_dir):
    if iso.resolve() == output.resolve() or output.exists():
        raise ValueError("Choose a new output path")
    with iso.open("rb") as source:
        extents = executable_extents(source)
        patches = []
        hashes = {}
        for name, target in TARGETS.items():
            offset, size = extents[name]
            original = verify(read_at(source, offset, size), target["sha256"], name)
            replacement = (elf_dir / name).read_bytes()
            if len(replacement) != size or replacement[:20] != original[:20]:
                raise ValueError(f"{name}: expected a same-size PS2 executable")
            patches.append((offset, replacement))
            hashes[name] = hashlib.sha256(replacement).hexdigest()
        retail_hashes = {name: target["sha256"] for name, target in TARGETS.items()}
        receipt = elf_dir / "build-set.json"
        if hashes != retail_hashes and (not receipt.is_file() or read_json(receipt) != hashes):
            raise ValueError("Modified executables must come from one full build. Run tools/build.py --mod.")
        output.parent.mkdir(parents=True, exist_ok=True)
        with NamedTemporaryFile(dir=output.parent, prefix=".test-iso-", delete=False) as temp:
            temporary = Path(temp.name)
        try:
            source.seek(0)
            with temporary.open("wb") as image:
                shutil.copyfileobj(source, image, 1024 * 1024)
                for offset, contents in patches:
                    image.seek(offset)
                    image.write(contents)
            if output.exists():
                raise ValueError("Output path already exists")
            os.replace(temporary, output)
        finally:
            temporary.unlink(missing_ok=True)


def main():
    parser = argparse.ArgumentParser(description="Create a PCSX2 test ISO from same-size rebuilt executables.")
    parser.add_argument("--iso", type=Path, required=True)
    parser.add_argument("--output", type=Path, default=ROOT / "build" / "test.iso")
    parser.add_argument("--elf-dir", type=Path, default=ROOT / "build")
    args = parser.parse_args()
    repackage(args.iso, args.output, args.elf_dir)
    print(args.output)


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError) as error:
        raise SystemExit(f"ISO repackaging failed: {error}")
