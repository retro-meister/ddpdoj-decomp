"""Merge a run of consecutive units into one named translation unit, for SLPS_252.33 and DEATH.ELF together.

    uv run tools/tu.py font --from func_00212720 --to func_00212F90     # merge, then compile and compare
    uv run tools/tu.py --check src/shared/font.c                        # compare an existing unit again
    uv run tools/tu.py --rodata src/shared/font.c --main 286ec0:286ed8 --death 281fe0:281ff8
                                                                        # the unit now owns these .rodata bytes
    uv run tools/tu.py --strings src/shared/system.c                    # its string references become literals
    uv run tools/tu.py --move src/shared/a.c src/shared/b.c             # rename a unit (file and splat.yaml)

`--from`/`--to` name the first and last unit of the run in SLPS_252.33 (a unit is named after its file). The
same code in DEATH.ELF is found through the shared units of the run; Death Label units lying between them are
merged too. The pieces keep their link order. A piece only one executable has is wrapped in
`#ifdef DEATH_LABEL` / `#ifndef DEATH_LABEL`, and a function with a different body in each gets both bodies
under `#ifdef DEATH_LABEL ... #else ... #endif`. Identical top-level declarations are kept once, and a piece
that began with file-level pragmas gets them inside `#pragma push` / `#pragma pop`. Local prototypes of SDK
functions give way to `sdk/ps2sdk.h`, and prototypes of functions the unit itself defines are dropped (one
forward declaration is written where a call comes first). An object the pieces declared with different types
gets no file-scope declaration: each function declares it in its own body with the type it was matched with,
which the compiler accepts and which marks the type as still to be settled. Names left with two different declarations are listed, to be settled by hand.

The merged file goes to `src/shared/<name>.c` (`src/main/<name>.c` when Death Label has none of it). Both
splat.yaml files get one `c` entry (and one `.rodata` entry) for the run. Afterwards every function of the
new unit is compiled and compared with the retail code, relocated fields masked, so that a declaration clash
or a changed function shows up by name. Run `uv run tools/build.py` for the SHA-256 check.
"""
import argparse
from pathlib import Path
import re
import struct
import subprocess

from build import compile_source, target_defines, unit_object
from common import ROOT, require_local, target_compiler
from split import load_symbols

MAIN, DEATH = "SLPS_252.33", "DEATH.ELF"
FILE_ADDRESS = 0x100000 - 0x80
ENTRY_RE = re.compile(r"^(\s*-\s*\[)(0x[0-9a-fA-F]+),\s*(\.?[a-zA-Z0-9_]+)(?:,\s*([^\]]+))?\]\s*$")


def yaml_entries(target):
    path = ROOT / "config" / target / "splat.yaml"
    lines = path.read_text(encoding="utf-8").splitlines()
    entries = []
    for index, line in enumerate(lines):
        match = ENTRY_RE.match(line)
        if match:
            entries.append({"line": index, "prefix": match.group(1), "offset": int(match.group(2), 16),
                            "kind": match.group(3), "stub": (match.group(4) or "").strip()})
    return path, lines, entries


def stem(stub):
    return stub.rsplit("/", 1)[-1]


def find_runs(first, last):
    """Entries of the run in each yaml: (main code entries, death code entries)."""
    _, _, main_entries = yaml_entries(MAIN)
    code = [e for e in main_entries if e["kind"] == "c"]
    names = [stem(e["stub"]) for e in code]
    if first not in names or last not in names:
        raise ValueError(f"{first}..{last}: not units of {MAIN}")
    main_run = code[names.index(first):names.index(last) + 1]
    if not main_run:
        raise ValueError("empty run")
    _, _, death_entries = yaml_entries(DEATH)
    death_code = [e for e in death_entries if e["kind"] == "c"]
    by_stub = {e["stub"]: i for i, e in enumerate(death_code)}
    wanted = []
    for entry in main_run:
        stub = entry["stub"]
        if stub.startswith("shared/"):
            if stub not in by_stub:
                raise ValueError(f"{stub}: shared unit missing from {DEATH}")
            wanted.append(by_stub[stub])
        elif f"death/{stem(stub)}" in by_stub:
            wanted.append(by_stub[f"death/{stem(stub)}"])
    if not wanted:
        return main_run, []
    if wanted != sorted(wanted):
        raise ValueError(f"the run is in a different order in {DEATH}")
    death_run = death_code[wanted[0]:wanted[-1] + 1]
    main_stubs = {e["stub"] for e in main_run}
    for entry in death_run:
        if entry["stub"].startswith("shared/") and entry["stub"] not in main_stubs:
            raise ValueError(f"{entry['stub']} lies inside the run in {DEATH} but outside it in {MAIN}")
    return main_run, death_run


def sequence(main_run, death_run):
    """[(main stub or None, death stub or None)] in link order."""
    pieces, i, j = [], 0, 0
    later_main = lambda k: {stem(e["stub"]) for e in main_run[k:] if e["stub"].startswith("main/")}
    while i < len(main_run) or j < len(death_run):
        m = main_run[i]["stub"] if i < len(main_run) else None
        d = death_run[j]["stub"] if j < len(death_run) else None
        if m and d and m == d:
            pieces.append((m, d)); i += 1; j += 1
        elif m and m.startswith("main/"):
            if d and d == f"death/{stem(m)}":
                pieces.append((m, d)); j += 1
            else:
                pieces.append((m, None))
            i += 1
        elif d and d.startswith("death/"):
            if stem(d) in later_main(i):
                raise ValueError(f"{d}: its Main counterpart comes later in the run")
            pieces.append((None, d)); j += 1
        else:
            raise ValueError(f"cannot line up {m} with {d}")
    return pieces


DECL_START = re.compile(r"^(typedef\s+)?(struct|union|enum)\b[^;]*\{\s*$")


def blocks(text):
    """Split a source into (kind, text) blocks: include, pragma, decl (a top-level declaration) or code."""
    out, lines, i = [], text.splitlines(), 0
    while i < len(lines):
        line = lines[i]
        if line.startswith("#include"):
            out.append(("include", line)); i += 1
        elif re.match(r"^#\s*pragma\b", line):
            out.append(("pragma", line.strip())); i += 1
        elif DECL_START.match(line) or (re.match(r"^(typedef\s+)?(struct|union|enum)\b[^;{(]*$", line)
                                        and i + 1 < len(lines) and lines[i + 1].rstrip() == "{"):
            j = i
            while j < len(lines) and not lines[j].startswith("}"):
                j += 1
            out.append(("decl", "\n".join(lines[i:j + 1]))); i = j + 1
        else:
            flat = re.sub(r"\s+", " ", re.sub(r"\s*(/\*.*?\*/|//.*)\s*$", "", line).strip())   # a trailing comment
            top = line[:1] not in (" ", "\t", "}", "#", "") and not line.startswith("//")
            if top and flat.endswith(";") and "=" not in flat and "{" not in flat:
                out.append(("decl", line))
            else:
                out.append(("code", line))
            i += 1
    return out


DATA_RE = re.compile(r"^extern\s+((?:const\s+|volatile\s+)*[A-Za-z_]\w*(?:\s+\w+)*?[\s\*]+)(\w+)\s*((?:\[[^\]]*\]\s*)*);\s*(?:/\*.*\*/\s*)?$")


def data_declaration(text):
    """(name, base type, dimensions) of a one-line `extern` object declaration, else None."""
    match = DATA_RE.match(text.strip())
    if not match or "(" in text:
        return None
    base = re.sub(r"\s+", " ", match.group(1)).strip().replace(" *", "*").replace("* ", "*")
    return match.group(2), base, re.sub(r"\s+", "", match.group(3))


def type_name(text):
    """Name a `typedef struct { ... } Name;` block defines, or the tag of a plain `struct Tag { ... };`,
    else None."""
    if "\n" not in text:
        return None
    if not text.startswith("typedef"):
        match = re.match(r"^(?:struct|union|enum)\s+(\w+)\s*\{", text)
        return match.group(1) if match and re.search(r"^\}\s*;\s*$", text, re.M) else None
    match = re.search(r"^\}\s*(\w+)\s*;\s*$", text, re.M)
    return match.group(1) if match else None


SOURCES = {}


def piece_source(stub):
    """Text of one unit. A type name that the pieces of the run define with different bodies is renamed in
    the later pieces (`Name2`, `Name3`, ...), see `rename_clashing_types`."""
    if stub not in SOURCES:
        SOURCES[stub] = (ROOT / "src" / f"{stub}.c").read_text(encoding="utf-8")
    return SOURCES[stub]


def rename_clashing_types(pieces):
    bodies = {}
    for pair in pieces:
        for stub in dict.fromkeys(pair):
            if not stub:
                continue
            renames = {}
            for kind, text in blocks(piece_source(stub)):
                name = type_name(text) if kind == "decl" else None
                if not name:
                    continue
                body = re.sub(r"\s+", " ", text[:text.rindex("}")])
                known = bodies.setdefault(name, [])
                if body not in known:
                    known.append(body)
                if known.index(body):
                    renames[name] = f"{name}{known.index(body) + 1}"
            if renames:
                pattern = re.compile(r"\b(" + "|".join(map(re.escape, renames)) + r")\b")
                SOURCES[stub] = pattern.sub(lambda m: renames[m.group(1)], piece_source(stub))


def canonical_types(pieces):
    """Names of the objects the pieces declare in more than one way."""
    rename_clashing_types(pieces)
    found = {}
    for pair in pieces:
        for stub in dict.fromkeys(pair):
            if not stub:
                continue
            for kind, text in blocks(piece_source(stub)):
                parsed = data_declaration(text) if kind == "decl" and "\n" not in text else None
                if parsed:
                    found.setdefault(parsed[0], set()).add(parsed[1:])
                prototype = PROTOTYPE_RE.match(text) if kind == "decl" and "\n" not in text else None
                if prototype:
                    flat = re.sub(r"\s+", " ", re.sub(r"/\*.*?\*/", "", text)).strip()
                    found.setdefault(prototype.group(1), set()).add(re.sub(r"^extern ", "", flat))
    # Prototypes of SDK functions and of the run's own functions are settled by `tidy_prototypes`.
    settled = sdk_functions()
    loose = set()
    for pair in pieces:
        for stub in dict.fromkeys(pair):
            if stub:
                settled |= set(definitions(ROOT / "src" / f"{stub}.c"))
                loose |= set(re.findall(r"^(?!typedef|extern)[A-Za-z_][\w \t\*]*?[ \*](\w+)\s*\(\)\s*\{?\s*$",
                                        piece_source(stub), re.M))
    # A function defined as `f()` takes whatever its callers pass; a caller that declared parameters keeps
    # its own prototype (in its own scope), because the argument conversions depend on it.
    typed = {name for name, forms in found.items()
             if name in loose and any(not re.search(r"\(\s*(void)?\s*\)", form) for form in forms)}
    return {name for name, forms in found.items() if (len(forms) > 1 and name not in settled) or name in typed}


def declaration(name, base, dims):
    stars = len(base) - len(base.rstrip("*"))
    return f"extern {base.rstrip('*')} {'*' * stars}{name}{dims};"


def localize(lines, local):
    """Insert the declarations of `local` ({name: declaration}) at the top of each function that uses them."""
    out, index = [], 0
    while index < len(lines):
        line = lines[index]
        out.append(line)
        opens = line[:1] not in (" ", "\t", "#", "}", "") and line.rstrip().endswith("{") and "(" in line and "=" not in line
        if not opens and line.rstrip() == "{" and index and out[-2][:1] not in ("", "#"):
            opens = True
        if opens:
            end = index + 1
            while end < len(lines) and not lines[end].startswith("}"):
                end += 1
            text = "\n".join(lines[index + 1:end])
            for name, declared in local.items():
                if re.search(rf"\b{re.escape(name)}\b", text):
                    out.extend(part if part.startswith("#") else "    " + part.strip() for part in declared.splitlines())
        index += 1
    return out


def unbalanced_pragma(text):
    """True when a pragma other than push/pop stands outside every push/pop pair of `text`."""
    depth = 0
    for kind, line in blocks(text):
        if kind == "pragma":
            word = line.split()[-1] if len(line.split()) == 2 else ""
            if word == "push":
                depth += 1
            elif word == "pop":
                depth -= 1
            elif depth <= 0:
                return True
    return False


def piece_text(path, seen, scopes, canonical):
    """Body of one unit with declarations already seen in `scopes` removed; returns (includes, text).

    An object the pieces of the run declare with different types gets no file-scope declaration at all.
    Each function that uses it declares it at the top of its own body instead, with the type it was matched
    with (the compiler accepts differing block-scope declarations, not differing file-scope ones)."""
    includes, body, leading, local = [], [], [], {}
    started = False
    depth = 0
    for kind, text in blocks(piece_source(path.relative_to(ROOT / "src").with_suffix("").as_posix())):
        if kind == "include":
            includes.append(text)
            continue
        if kind == "pragma" and not started:
            leading.append(text)
            continue
        if kind == "code" and re.match(r"\s*#\s*if", text):
            depth += 1
            opener = text.strip()
        elif kind == "code" and re.match(r"\s*#\s*endif", text):
            depth -= 1
        if kind == "decl" and depth:
            parsed = data_declaration(text) if "\n" not in text else None
            if parsed and parsed[0] in canonical and depth == 1:
                # a clashing declaration under a conditional goes into the functions with its conditional
                local[parsed[0]] = f"{opener}\n    {declaration(*parsed)}\n#endif"
            else:
                body.append(text)   # otherwise leave it exactly where it is
            continue
        if kind == "decl":
            parsed = data_declaration(text) if "\n" not in text else None
            if parsed and parsed[0] in canonical:
                local[parsed[0]] = declaration(*parsed)
                continue
            prototype = PROTOTYPE_RE.match(text) if "\n" not in text else None
            if prototype and prototype.group(1) in canonical:
                local[prototype.group(1)] = re.sub(r"\s*/\*.*?\*/\s*$", "", text.strip())
                continue
            key = re.sub(r"\s+", " ", text.strip())
            if any(key in seen[scope] for scope in scopes):
                continue
            seen[scopes[0]].add(key)
        if kind == "code" and text.strip():
            started = True
        body.append(text)
    if local:
        body = localize(body, local)
    text = "\n".join(body).strip("\n")
    # a pragma in the middle of a piece lasted to the end of its file, so the whole piece is bracketed
    if leading or unbalanced_pragma(text):
        text = "#pragma push\n" + "\n".join(leading + [text]) + "\n#pragma pop"
    return includes, text


DEFINITION_RE = re.compile(r"^(?!typedef|extern|static\s+inline|#|//|/\*)([A-Za-z_][\w \t\*]*?[ \*])(\w+)\s*\(([^;{]*)\)\s*\{?\s*$")
# (a `(` followed by `*` declares a function pointer, not a function)
PROTOTYPE_RE = re.compile(r"^(?:extern\s+)?[A-Za-z_][\w \t\*]*?[ \*](\w+)\s*\((?!\s*\*)[^;{]*\)\s*;")


def sdk_functions():
    names = set()
    for header in (ROOT / "include" / "sdk").glob("*.h"):
        names.update(PROTOTYPE_RE.findall(header.read_text(encoding="utf-8")))
        for line in header.read_text(encoding="utf-8").splitlines():
            match = PROTOTYPE_RE.match(line)
            if match:
                names.add(match.group(1))
    return names


def definitions(path):
    """{function name: prototype text} for the functions a source defines."""
    out, lines = {}, path.read_text(encoding="utf-8").splitlines()
    for index, line in enumerate(lines):
        match = DEFINITION_RE.match(line)
        if match and (line.rstrip().endswith("{") or (index + 1 < len(lines) and lines[index + 1].startswith("{"))):
            out[match.group(2)] = f"{match.group(1).strip()} {match.group(2)}({match.group(3).strip() or 'void'});"
    return out


def tidy_prototypes(text, pieces):
    """Drop local prototypes of SDK functions and of functions the unit defines; declare the latter up front
    only where a call comes before the definition."""
    defined = {}
    for pair in pieces:
        for stub in dict.fromkeys(pair):
            if stub:
                defined.update(definitions(ROOT / "src" / f"{stub}.c"))
    sdk = sdk_functions()
    kept, order, uses_sdk = [], [], False
    for line in text.splitlines():
        match = PROTOTYPE_RE.match(line)
        if match and line[:1] not in (" ", "\t"):
            if match.group(1) in sdk:
                uses_sdk = True
                continue
            if match.group(1) in defined:
                continue
        kept.append(line)
    body = "\n".join(kept)
    for name, prototype in list(defined.items()):
        if not prototype.endswith(f"{name}(void);"):
            continue
        if re.search(rf"\b{name}\s*\(\s*(?!void\s*\))[^)\s]", body):
            body = re.sub(rf"^([A-Za-z_][\w \t\*]*?[ \*]{name})\s*\(\s*void\s*\)", r"\1()", body, flags=re.M)
            defined[name] = prototype.replace(f"{name}(void);", f"{name}();")
    forward = []
    for name, prototype in defined.items():
        definition = re.search(rf"^[A-Za-z_][\w \t\*]*?[ \*]{name}\s*\([^;{{]*\)\s*\{{?\s*$", body, re.M)
        call = re.search(rf"\b{name}\b", body)
        if definition and call and call.start() < definition.start() + definition.group(0).rfind(name):
            forward.append(prototype)
    head, _, rest = body.partition("\n\n")
    if uses_sdk and '#include "sdk/ps2sdk.h"' not in head:
        head += '\n#include "sdk/ps2sdk.h"'
    if forward:
        head += "\n\n" + "\n".join(forward)
    return head + "\n\n" + rest + "\n"


def conflicts(text):
    """Names declared at top level more than once with different declarations."""
    seen = {}
    for kind, block in blocks(text):
        if kind != "decl" or "\n" in block:
            continue
        match = re.search(r"(\w+)\s*(?:\[[^\]]*\]\s*)*(?:\([^)]*\)\s*)?;", block)
        if match:
            seen.setdefault(match.group(1), set()).add(re.sub(r"\s+", " ", block.strip()))
    return {name: sorted(found) for name, found in seen.items() if len(found) > 1}


def merge_text(pieces):
    seen = {"all": set(), "main": set(), "death": set()}
    includes, parts = [], []
    canonical = canonical_types(pieces)
    for main_stub, death_stub in pieces:
        if main_stub and main_stub == death_stub:
            inc, text = piece_text(ROOT / "src" / f"{main_stub}.c", seen, ["all"], canonical)
            includes += inc
            parts.append(text)
            continue
        chunk = []
        if death_stub:
            inc, text = piece_text(ROOT / "src" / f"{death_stub}.c", seen, ["death", "all"], canonical)
            includes += inc
            chunk += ["#ifdef DEATH_LABEL", text]
        if main_stub:
            inc, text = piece_text(ROOT / "src" / f"{main_stub}.c", seen, ["main", "all"], canonical)
            includes += inc
            chunk += ["#else" if death_stub else "#ifndef DEATH_LABEL", text]
        chunk.append("#endif")
        parts.append("\n".join(chunk))
    ordered = []
    for line in includes:
        if line not in ordered:
            ordered.append(line)
    text = "\n".join(ordered) + "\n\n" + "\n\n".join(part for part in parts if part.strip()) + "\n"
    return tidy_prototypes(text, pieces)


def patch_yaml(target, run, new_stub):
    path, lines, entries = yaml_entries(target)
    stubs = {e["stub"] for e in run}
    drop = {e["line"] for e in run[1:]}
    first = run[0]
    lines[first["line"]] = f"{first['prefix']}{first['offset']:#x}, c, {new_stub}]"
    # The members' .rodata (jump tables, strings) becomes the unit's. Entries that touch are joined; where
    # assembly slices still lie between them (strings not yet inlined) several entries stay for now, and
    # `--strings` joins them when it gives the unit the strings in between.
    rodata = [e for e in entries if e["kind"] == ".rodata" and e["stub"] in stubs]
    previous = None
    for entry in rodata:
        index = entries.index(entry)
        if previous is not None and entries[index - 1] is previous:
            drop.add(entry["line"])
        else:
            lines[entry["line"]] = f"{entry['prefix']}{entry['offset']:#x}, .rodata, {new_stub}]"
        previous = entry
    path.write_text("\n".join(line for i, line in enumerate(lines) if i not in drop) + "\n", encoding="utf-8")


def carve_rodata(target, stub, start, end, section="rodata"):
    """Give `stub` the .rodata (or .data) bytes [start, end) (addresses) plus whatever it already has of that
    section, as one entry. The bytes come out of assembly slices, which are cut where needed."""
    path, lines, entries = yaml_entries(target)
    start, end = start - FILE_ADDRESS, end - FILE_ADDRESS
    ours = "." + section
    area = [i for i, e in enumerate(entries) if e["kind"] in (section, ours)]
    first, last = area[0], area[-1]
    spans = [(entries[i], entries[i + 1]["offset"]) for i in range(first, last + 1)]
    for entry, stop in spans:
        if entry["kind"] == ours and entry["stub"] == stub:
            start, end = min(start, entry["offset"]), max(end, stop)
    prefix = entries[first]["prefix"]
    own = f"{prefix}{start:#x}, {ours}, {stub}]"
    new, placed = [], False
    for entry, stop in spans:
        if stop <= start or entry["offset"] >= end:
            if entry["offset"] >= end and not placed:
                new.append(own)
                placed = True
            new.append(lines[entry["line"]])
            continue
        if entry["kind"] == ours and entry["stub"] != stub:
            raise ValueError(f"{target}: {start:#x}..{end:#x} runs into the {ours} of {entry['stub']}")
        if entry["offset"] < start:
            new.append(lines[entry["line"]])
        if not placed:
            new.append(own)
            placed = True
        if stop > end:
            new.append(f"{prefix}{end:#x}, {section}, {section}_{end:x}]")
    if not placed:
        new.append(own)
    lines[entries[first]["line"]:entries[last]["line"] + 1] = new
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")


RODATA = (0x273EC0, 0x28C070)
AUTO_DATA = re.compile(r"\b(death_)?D_([0-9A-F]{8})(?:_as_\w+)?\b")


def literal(data):
    """C source for a NUL-terminated string, or None when the bytes are not text."""
    try:
        text = data.decode("cp932")
    except UnicodeDecodeError:
        return None
    if not text or any(ord(ch) < 0x20 and ch not in "\n\t\r" for ch in text):
        return None
    escaped = (text.replace("\\", "\\\\").replace('"', '\\"').replace("\n", "\\n").replace("\t", "\\t")
               .replace("\r", "\\r"))
    if text.isascii():
        return f'"{escaped}"'
    if text.encode("cp932") != data:
        return None
    return f'SJIS("{escaped}")'


def death_rodata():
    _, _, entries = yaml_entries(DEATH)
    area = [i for i, e in enumerate(entries) if e["kind"] in ("rodata", ".rodata")]
    return entries[area[0]]["offset"] + FILE_ADDRESS, entries[area[-1] + 1]["offset"] + FILE_ADDRESS


def inline_strings(source):
    """Replace the unit's references to read-only strings with string literals, and give it that .rodata.

    `D_XXXXXXXX` is a SLPS_252.33 address (DEATH.ELF has the same string where its symbols.txt puts the
    name); `death_D_XXXXXXXX` is a DEATH.ELF address."""
    path = ROOT / source
    text = path.read_text(encoding="utf-8")
    images = {MAIN: (ROOT / "build" / MAIN).read_bytes(), DEATH: (ROOT / "build" / DEATH).read_bytes()}
    death_symbols = load_symbols(DEATH)
    areas = {MAIN: RODATA, DEATH: death_rodata()}
    found, where, spans = {}, {}, {MAIN: [], DEATH: []}
    for match in AUTO_DATA.finditer(text):
        name = match.group(0)
        if name in found:
            continue
        own = DEATH if match.group(1) else MAIN
        address = int(match.group(2), 16)
        if not areas[own][0] <= address < areas[own][1]:
            continue
        rest = re.sub(rf"^\s*extern.*\b{name}\b.*$", "", text, flags=re.M)
        if re.search(rf"\b{name}\s*\[|&\s*{name}\b|\b{name}\s*[-+]|[-+]\s*{name}\b", rest):
            continue
        offset = address - FILE_ADDRESS
        raw = images[own][offset:images[own].index(0, offset)]
        if literal(raw) is None:
            continue
        # {MAIN: literal, DEATH: literal}: what the name stands for in each executable
        found[name] = {own: literal(raw)}
        where[name] = {own: (address, address + len(raw) + 1)}
        if own == MAIN and name in death_symbols:
            other = death_symbols[name][0] - FILE_ADDRESS
            other_raw = images[DEATH][other:images[DEATH].index(0, other)]
            if literal(other_raw) is not None:
                found[name][DEATH] = literal(other_raw)
                where[name][DEATH] = (other + FILE_ADDRESS, other + FILE_ADDRESS + len(other_raw) + 1)
    # The compiler aligns a string longer than 16 bytes to 16 within the unit's .rodata, so a unit that has
    # one cannot start at an address that is only 8-aligned: its leading strings stay references until the
    # data before them is in the unit too.
    stub = Path(source).relative_to("src").with_suffix("").as_posix()
    while True:
        late = set()
        for target in (MAIN, DEATH):
            placed = [span[target] for span in where.values() if target in span]
            placed += [(e["offset"] + FILE_ADDRESS, e["offset"] + FILE_ADDRESS + 32)
                       for e in yaml_entries(target)[2] if e["kind"] == ".rodata" and e["stub"] == stub]
            if not placed or not any(high - low > 16 for low, high in placed):
                continue
            start = min(low for low, _ in placed)
            if start % 16:
                late |= {name for name, span in where.items() if target in span and span[target][0] < start + 8}
        if not late:
            break
        for name in late:
            print(f"  {name} stays a reference: the unit's .rodata has to start 16-aligned")
            del found[name], where[name]
    for span in where.values():
        for target, pair in span.items():
            spans[target].append(pair)
    if not found:
        print("no string references")
        return
    # Which executable compiles each line: both, or the one a DEATH_LABEL conditional selects.
    out, scope, stack = [], None, []
    for line in text.splitlines():
        directive = line.strip()
        if directive.startswith("#if"):
            stack.append(scope)
            if directive in ("#ifdef DEATH_LABEL", "#if defined(DEATH_LABEL)"):
                scope = DEATH
            elif directive == "#ifndef DEATH_LABEL":
                scope = MAIN
        elif directive.startswith("#else") and scope in (MAIN, DEATH):
            scope = MAIN if scope == DEATH else DEATH
        elif directive.startswith("#endif") and stack:
            scope = stack.pop()
        elif re.match(r"\s*extern\b", line) and any(re.search(rf"\b{name}\b", line) for name in found):
            continue

        def replace(match):
            forms = found[match.group(0)]
            if scope:
                return forms.get(scope, match.group(0))
            if len(set(forms.values())) == 1 and (len(forms) == 2 or match.group(0).startswith("death_")):
                return next(iter(forms.values()))
            if len(forms) == 1:
                return next(iter(forms.values()))
            print(f"  {match.group(0)} is a different string in each executable; left as it is")
            return match.group(0)

        out.append(re.sub(r"\b(" + "|".join(map(re.escape, found)) + r")\b", replace, line))
    path.write_text("\n".join(out) + "\n", encoding="utf-8")
    for target in (MAIN, DEATH):
        if spans[target]:
            start = min(low for low, _ in spans[target])
            end = (max(high for _, high in spans[target]) + 7) & ~7     # the next string may start 8-aligned
            print(f"{len(spans[target])} strings, {target} .rodata {start:#x}..{end:#x}")
            carve_rodata(target, stub, start, end)


def object_functions(path):
    """[(name, code bytes, mask bytes)] for every function of an object, relocated fields masked out."""
    data = path.read_bytes()
    shoff, = struct.unpack_from("<I", data, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", data, 0x2E)
    headers = [struct.unpack_from("<10I", data, shoff + i * shentsize) for i in range(shnum)]

    def cstr(base, index):
        start = base + index
        return data[start:data.index(0, start)].decode("ascii")

    names = [cstr(headers[shstrndx][4], header[0]) for header in headers]
    symtab = headers[names.index(".symtab")]
    strtab = headers[symtab[6]][4]
    out = []
    for name, value, size, info, _, shndx in struct.iter_unpack("<IIIBBH", data[symtab[4]:symtab[4] + symtab[5]]):
        if info & 15 != 2 or not shndx or shndx >= len(headers):
            continue
        header = headers[shndx]
        code = bytearray(data[header[4] + value:header[4] + value + size])
        mask = bytearray(b"\xff" * len(code))
        for rel in headers:
            if rel[1] == 9 and rel[7] == shndx:
                for offset, rinfo in struct.iter_unpack("<II", data[rel[4]:rel[4] + rel[5]]):
                    offset -= value
                    if 0 <= offset <= len(code) - 4:
                        keep = {4: 0xFC000000, 5: 0xFFFF0000, 6: 0xFFFF0000, 7: 0xFFFF0000}.get(rinfo & 0xFF, 0)
                        struct.pack_into("<I", mask, offset, keep)
        out.append((cstr(strtab, name), bytes(code), bytes(mask)))
    return out


def show_difference(local, name, code, retail, mask):
    """Print the differing instructions of one function, ours against retail (relocated fields zeroed)."""
    import difflib
    import tempfile

    def listing(data):
        masked = bytes(a & m for a, m in zip(data, mask))
        with tempfile.NamedTemporaryFile(suffix=".bin") as handle:
            handle.write(masked)
            handle.flush()
            out = subprocess.run([local["binutils"]["objdump"], "-D", "-b", "binary", "-m", "mips:5900", "-EL",
                                  "--no-show-raw-insn", handle.name], capture_output=True, text=True).stdout
        return [re.sub(r"\s+", " ", line.split(":", 1)[1]).strip() for line in out.splitlines()
                if re.match(r"\s*[0-9a-f]+:", line)]

    diff = list(difflib.unified_diff(listing(retail), listing(code), "retail", name, n=2, lineterm=""))
    print("\n".join("    " + line for line in diff[:60]))


def check(source):
    """Compile `source` for each executable that links it and compare every function with the retail code."""
    local = require_local()
    ok = True
    for target in (MAIN, DEATH):
        _, _, entries = yaml_entries(target)
        stub = Path(source).relative_to("src").with_suffix("").as_posix()
        if not any(e["kind"] == "c" and e["stub"] == stub for e in entries):
            continue
        version = target_compiler(target)
        obj = unit_object(version, target, source)
        try:
            compile_source(local, source, obj, version, target_defines(target, source))
        except subprocess.CalledProcessError:
            print(f"{target}: does not compile")
            return False
        image = (ROOT / "build" / target).read_bytes()
        symbols = load_symbols(target)
        bad = []
        for name, code, mask in object_functions(obj):
            if name not in symbols:
                bad.append(f"{name} (no symbol)")
                continue
            offset = symbols[name][0] - FILE_ADDRESS
            retail = image[offset:offset + len(code)]
            if any((a ^ b) & m for a, b, m in zip(code, retail, mask)):
                bad.append(name)
                show_difference(local, name, code, retail, mask)
        print(f"{target}: {'all functions match' if not bad else 'DIFFERENT: ' + ', '.join(bad)}")
        ok &= not bad
    return ok


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("name", nargs="?", help="name of the new unit, e.g. font")
    parser.add_argument("--from", dest="first")
    parser.add_argument("--to", dest="last")
    parser.add_argument("--check", metavar="SOURCE")
    parser.add_argument("--rodata", metavar="SOURCE", help="give a unit a .rodata range; use with --main and/or --death")
    parser.add_argument("--data", metavar="SOURCE", help="give a unit a .data range; use with --main and/or --death")
    parser.add_argument("--main", metavar="START:END", help="address range in SLPS_252.33")
    parser.add_argument("--death", metavar="START:END", help="address range in DEATH.ELF")
    parser.add_argument("--strings", metavar="SOURCE", help="turn the unit's string references into literals")
    parser.add_argument("--move", nargs=2, metavar=("SOURCE", "NEW"), help="rename or move a unit, e.g. src/shared/a.c src/engine/b.c")
    args = parser.parse_args()
    if args.move:
        old, new = (Path(value).relative_to("src").with_suffix("").as_posix() for value in args.move)
        for target in (MAIN, DEATH):
            path, lines, entries = yaml_entries(target)
            for entry in entries:
                if entry["stub"] == old:
                    lines[entry["line"]] = f"{entry['prefix']}{entry['offset']:#x}, {entry['kind']}, {new}]"
            path.write_text("\n".join(lines) + "\n", encoding="utf-8")
        (ROOT / args.move[1]).parent.mkdir(parents=True, exist_ok=True)
        subprocess.run(["git", "mv", args.move[0], args.move[1]], cwd=ROOT, check=True)
        return
    if args.strings:
        inline_strings(args.strings)
        return
    if args.rodata or args.data:
        stub = Path(args.rodata or args.data).relative_to("src").with_suffix("").as_posix()
        for target, span in ((MAIN, args.main), (DEATH, args.death)):
            if span:
                start, end = (int(v, 16) for v in span.split(":"))
                carve_rodata(target, stub, start, end, "rodata" if args.rodata else "data")
        return
    if args.check:
        raise SystemExit(0 if check(args.check) else 1)
    if not (args.name and args.first and args.last):
        parser.error("give a name with --from and --to, or --check SOURCE")

    main_run, death_run = find_runs(args.first, args.last)
    pieces = sequence(main_run, death_run)
    folder = "shared" if death_run else "main"
    new_stub = f"{folder}/{args.name}"
    dest = ROOT / "src" / f"{new_stub}.c"
    old = [ROOT / "src" / f"{stub}.c" for pair in pieces for stub in dict.fromkeys(pair) if stub]
    if dest.exists() and dest not in old:
        raise ValueError(f"{dest.relative_to(ROOT)} already exists")
    text = merge_text(pieces)
    patch_yaml(MAIN, main_run, new_stub)
    if death_run:
        patch_yaml(DEATH, death_run, new_stub)
    subprocess.run(["git", "mv", str(old[0].relative_to(ROOT)), str(dest.relative_to(ROOT))], cwd=ROOT, check=True)
    for path in old[1:]:
        subprocess.run(["git", "rm", "-q", "-f", str(path.relative_to(ROOT))], cwd=ROOT, check=True)
    dest.write_text(text, encoding="utf-8")
    print(f"merged {len(old)} files into {dest.relative_to(ROOT)}")
    for name, found in conflicts(text).items():
        print(f"  declared differently: {name}")
        for declaration in found:
            print(f"      {declaration}")
    check(dest.relative_to(ROOT).as_posix())


if __name__ == "__main__":
    main()
