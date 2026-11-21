"""Build a temporary instrumented compiler from the checked profile."""
from pathlib import Path
import struct

from common import run


def align(value, multiple):
    return (value + multiple - 1) // multiple * multiple


def instrument(source, output, profile, stages, assembler, objcopy):
    image = bytearray(source.read_bytes())

    def read(fmt, offset):
        return struct.unpack_from("<" + fmt, image, offset)[0]

    def u16(offset):
        return read("H", offset)

    def u32(offset):
        return read("I", offset)

    pe = u32(0x3C)
    optional = pe + 24
    if image[pe:pe + 4] != b"PE\0\0" or u16(pe + 4) != 0x14C or u16(optional) != 0x10B:
        raise ValueError("Expected an x86 PE32 compiler")
    image_base, section_align, file_align = struct.unpack_from("<III", image, optional + 28)
    count = u16(pe + 6)
    section_base = optional + u16(pe + 20)
    sections = [
        struct.unpack_from("<IIII", image, section_base + 40 * index + 8)
        for index in range(count)
    ]
    header = section_base + 40 * count
    if header + 40 > u32(optional + 60) or any(image[header:header + 40]):
        raise ValueError("PE headers lack space for a trace section")
    rva = align(max(addr + max(size, raw) for size, addr, raw, _ in sections), section_align)
    va = image_base + rva

    hooks = profile["hooks"]
    definitions = [f".set trace_base, {va:#x}"]
    definitions += [f".set {name}, {addr}" for name, addr in profile["symbols"].items()]
    definitions += [f".set {name}, {value}" for name, value in profile["layout"].items()]
    dispatch = [".text", "trace_start:"]
    wrappers = []
    for hook in hooks:
        name = hook["name"]
        dispatch += [".byte 0xe9", f".long {name} - (. + 4)"]
        if "target" in hook:
            definitions.append(f".set {name}_target, {hook['target']}")
        if "args" in hook:
            before = stages.get(hook.get("before"), 0)
            after = stages.get(hook.get("after"), 0)
            wrappers.append(f"stage_hook {name}, {name}_target, {hook['args']}, {before}, {after}")
    assembly = output.with_suffix(".s")
    thunk_source = Path(__file__).with_name("trace.s").read_text(encoding="utf-8")
    assembly.write_text("\n".join([*definitions, *dispatch, thunk_source, *wrappers, ""]), encoding="utf-8")
    obj = output.with_suffix(".obj")
    blob = output.with_suffix(".bin")
    run(assembler, "--32", "-o", obj, assembly)
    run(objcopy, "-O", "binary", "-j", ".text", obj, blob)

    payload = blob.read_bytes()
    raw_at = align(len(image), file_align)
    raw_size = align(len(payload), file_align)
    image.extend(bytes(raw_at - len(image)))
    image.extend(payload.ljust(raw_size, b"\0"))
    struct.pack_into(
        "<8sIIIIIIHHI", image, header, b".trcb38", len(payload), rva, raw_size, raw_at,
        0, 0, 0, 0, 0x60000020,
    )
    struct.pack_into("<H", image, pe + 6, count + 1)
    struct.pack_into("<I", image, optional + 4, u32(optional + 4) + raw_size)
    struct.pack_into("<I", image, optional + 56, align(rva + len(payload), section_align))
    struct.pack_into("<I", image, optional + 64, 0)

    for slot, hook in enumerate(hooks):
        site = int(hook["address"], 16)
        expected = bytes.fromhex(hook["bytes"])
        site_rva = site - image_base
        for _, address, raw, offset in sections:
            if address <= site_rva and site_rva + len(expected) <= address + raw:
                site_offset = offset + site_rva - address
                break
        else:
            raise ValueError(f"Hook address outside PE sections ({site:#x})")
        if image[site_offset:site_offset + len(expected)] != expected:
            raise ValueError(f"Hook bytes disagree at {site:#x}")
        patch = struct.pack("<Bi", 0xE8, va + 5 * slot - (site + 5))
        image[site_offset:site_offset + len(expected)] = patch.ljust(len(expected), b"\x90")
    output.write_bytes(image)
