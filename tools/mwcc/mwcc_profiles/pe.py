"""Build a temporary instrumented compiler from the checked profile."""
from pathlib import Path
import struct

from common import run


def align(value, multiple):
    return (value + multiple - 1) // multiple * multiple


def ir_definitions(profile):
    """Layout constants and the per-ENodeType child table for the frontend IR walker."""
    ir = profile.get("ir")
    if not ir:
        return [], []
    definitions = [f".set ir_{name}, {value}" for name, value in ir["layout"].items()]
    table = [0] * 128
    for first, last, mask in ir["children"]:
        for kind in range(first, last + 1):
            table[kind] = mask
    data = ["ir_child_table:", *(f".byte {', '.join(map(str, table[i:i + 16]))}" for i in range(0, 128, 16))]
    return definitions, data


def instrument(source, output, profile, stages, assembler, objcopy, iro_log=None):
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
    ir_defs, ir_data = ir_definitions(profile)
    definitions += ir_defs
    wrappers = []
    for hook in hooks:
        name = hook["name"]
        dispatch += [".byte 0xe9", f".long {name} - (. + 4)"]
        if "target" in hook:
            definitions.append(f".set {name}_target, {hook['target']}")
        if "iro_dump" in hook:
            wrappers.append(f'iro_dump_hook {name}, {name}_target, "{hook["iro_dump"]}"')
        elif "ir" in hook:
            before = stages.get(hook.get("before"), 0)
            after = stages.get(hook.get("after"), 0)
            result = int(hook["ir"] == "result")
            wrappers.append(f"ir_hook {name}, {name}_target, {hook['args']}, {before}, {after}, {result}")
        elif "args" in hook:
            before = stages.get(hook.get("before"), 0)
            after = stages.get(hook.get("after"), 0)
            wrappers.append(f"stage_hook {name}, {name}_target, {hook['args']}, {before}, {after}")
    assembly = output.with_suffix(".s")
    thunk_source = Path(__file__).with_name("trace.s").read_text(encoding="utf-8")
    if "iro_log_flag" in profile["symbols"]:
        if iro_log is None:
            raise ValueError("The profile's IR optimizer log needs a log path")
        quoted = str(iro_log).replace("\\", "\\\\").replace('"', '\\"')
        ir_data += ["iro_log_path:", f'.asciz "{quoted}"']
    assembly.write_text("\n".join([*definitions, *dispatch, thunk_source, *wrappers, *ir_data, ""]), encoding="utf-8")
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
