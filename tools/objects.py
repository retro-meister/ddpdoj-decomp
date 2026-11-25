import struct

ALLOWED_ALLOC_SECTIONS = {
    ".text", ".rodata", ".data", ".sdata", ".sbss", ".bss", ".lit4", ".lit8", ".unused"}  # ".unused": objects the retail link dropped; the link script discards it


def parse_object(path):
    data = path.read_bytes()
    if data[:7] != b"\x7fELF\x01\x01\x01" or data[16:20] != b"\x01\x00\x08\x00":
        raise ValueError(f"{path.name}: expected a relocatable PS2 ELF object")
    offset, = struct.unpack_from("<I", data, 0x20)
    entry_size, count, names_index = struct.unpack_from("<HHH", data, 0x2e)
    sections = [struct.unpack_from("<10I", data, offset + i * entry_size) for i in range(count)]
    names = sections[names_index][4]

    def string_at(index):
        return data[index:data.index(0, index)].decode("ascii")

    named = {string_at(names + section[0]): i for i, section in enumerate(sections)}
    text_index = named.get(".text")
    if text_index is None:
        raise ValueError(f"{path.name}: missing .text")
    if ".symtab" not in named:
        raise ValueError(f"{path.name}: missing symbol table")
    symtab = sections[named[".symtab"]]
    strings = sections[symtab[6]][4]
    functions = {}
    for record in struct.iter_unpack("<IIIBBH", data[symtab[4]:symtab[4] + symtab[5]]):
        name, value, size, info, _, index = record
        if index == text_index and info & 15 == 2:
            functions[string_at(strings + name)] = (value, size)
    return sections, named, functions


def validate_object(path, code=True):
    """Check a compiled unit; code=False is a unit that defines data only."""
    if not code:
        data = path.read_bytes()
        if data[:7] != b"\x7fELF\x01\x01\x01" or data[16:20] != b"\x01\x00\x08\x00":
            raise ValueError(f"{path.name}: expected a relocatable PS2 ELF object")
        return {}
    sections, named, functions = parse_object(path)
    unsupported = [
        name for name, i in named.items()
        if name not in ALLOWED_ALLOC_SECTIONS and sections[i][2] & 2 and sections[i][5]
    ]
    if unsupported:
        raise ValueError(f"{path.name}: unsupported allocated sections: {', '.join(unsupported)}")
    if not functions:
        raise ValueError(f"{path.name}: .text contains no function symbols")
    return functions


def defined_function_count(path):
    data = path.read_bytes()
    sections, named, _ = parse_object(path)
    symtab = sections[named[".symtab"]]
    return sum(
        1 for _, _, _, info, _, index in struct.iter_unpack("<IIIBBH", data[symtab[4]:symtab[4] + symtab[5]])
        if index != 0 and info & 15 == 2
    )


def undefined_symbols(path):
    data = path.read_bytes()
    sections, named, _ = parse_object(path)
    symtab = sections[named[".symtab"]]
    strings = sections[symtab[6]][4]
    names = set()
    for name, _, _, info, _, index in struct.iter_unpack("<IIIBBH", data[symtab[4]:symtab[4] + symtab[5]]):
        if index == 0 and name and info >> 4 in (1, 2):
            names.add(data[strings + name:data.index(0, strings + name)].decode("ascii"))
    return names


def find_function(path, function):
    functions = validate_object(path)
    if function not in functions:
        found = ", ".join(sorted(functions)) or "none"
        raise ValueError(f"{path.name}: missing function {function}; found {found}")
    return functions[function]
