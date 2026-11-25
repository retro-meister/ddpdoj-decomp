"""Give every global one declared type across the Main and Death Label sources.

    uv run tools/typealias.py            # report
    uv run tools/typealias.py --apply    # rewrite the sources and add the alias symbols

The matched functions were written one per file, and some files declare the same object with different types
(`s8` here, `u8` there, an array in a third). That stops the files from being merged into translation units.
This tool picks each object's commonest declaration as the canonical one. A file that declared the object
differently gets an alias name instead, `<name>_as_<type>`, declared with the type that file was matched
with and defined at the same address in `config/<target>/aliases.txt`. The code compiles to the same bytes, every
plain name has one type everywhere, and each alias marks a place where the types still have to be reconciled
(`uv run tools/cleanup_stats.py` counts them).

Only one-line file-scope `extern` declarations are handled. A file that declares one name in two ways itself
(for example under `#ifdef DEATH_LABEL`) is reported and left alone.
"""
import argparse
from collections import Counter, defaultdict
import re

from common import ROOT
from split import aliases_path, load_symbols
from tu import blocks, data_declaration

MAIN, DEATH = "SLPS_252.33", "DEATH.ELF"
AUTO = re.compile(r"(?:D|jtbl)_([0-9A-F]{8})$")
ALIAS = re.compile(r"_as_\w+$")


def sources():
    return [path for folder in ("game", "main", "death") for path in sorted((ROOT / "src" / folder).rglob("*.c"))]


def code(base, dims):
    """Short name of a declared type: `u8`, `s16_a` (array), `PadInfo_a3`, `u8_p` (pointer)."""
    if base.startswith("fn "):
        return "fn" + "".join("_a" + re.sub(r"\W", "", size) for size in re.findall(r"\[([^\]]*)\]", dims))
    text = base.replace("const ", "").replace("volatile ", "").replace("unsigned ", "u").replace("struct ", "")
    text = re.sub(r"\s+", "_", text.strip()).replace("*", "_p")
    for size in re.findall(r"\[([^\]]*)\]", dims):
        text += "_a" + re.sub(r"\W", "", size)
    return re.sub(r"_+", "_", text)


FUNCTION_POINTER = re.compile(r"^extern\s+(.+?)\(\s*\*\s*(\w+)\s*((?:\[[^\]]*\])*)\s*\)\s*\((.*)\)\s*;")


def declarations(text):
    """[(name, base, dims, line)] for the file-scope object declarations of a source. A pointer to function
    has the base `fn <return type>(<parameters>)`."""
    out = []
    for kind, block in blocks(text):
        if kind != "decl" or "\n" in block:
            continue
        parsed = data_declaration(block)
        pointer = FUNCTION_POINTER.match(block.strip())
        if pointer:
            signature = re.sub(r"\s+", " ", f"{pointer.group(1).strip()}({pointer.group(4).strip()})")
            parsed = (pointer.group(2), "fn " + signature, pointer.group(3))
        if parsed:
            out.append((*parsed, block))
    return out


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--apply", action="store_true")
    args = parser.parse_args()

    files = {path: path.read_text(encoding="utf-8") for path in sources()}
    forms = defaultdict(Counter)
    for text in files.values():
        for name, base, dims, _ in declarations(text):
            if not ALIAS.search(name):
                forms[name][(base, dims)] += 1
    canonical = {name: max(found, key=lambda form: (found[form], form)) for name, found in forms.items()}
    clashing = {name for name, found in forms.items() if len(found) > 1}
    print(f"{len(forms):,} objects, {len(clashing):,} declared in more than one way")
    if not args.apply:
        for name in sorted(clashing, key=lambda n: -sum(forms[n].values()))[:20]:
            print(f"  {name}: " + ", ".join(f"{base} {dims} x{count}".replace("  ", " ")
                                             for (base, dims), count in forms[name].most_common()))
        return

    aliases, skipped, changed = {}, [], 0
    for path, text in files.items():
        own = defaultdict(set)
        for name, base, dims, _ in declarations(text):
            own[name].add((base, dims))
        renames = {}
        for name, found in own.items():
            if name not in clashing:
                continue
            if len(found) > 1:
                skipped.append(f"{path.relative_to(ROOT)}: {name}")
                continue
            form = next(iter(found))
            if form != canonical[name]:
                renames[name] = f"{name}_as_{code(*form)}"
                aliases[renames[name]] = name
        if not renames:
            continue
        pattern = re.compile(r"\b(" + "|".join(map(re.escape, renames)) + r")\b")
        path.write_text(pattern.sub(lambda m: renames[m.group(1)], text), encoding="utf-8")
        changed += 1

    for target in (MAIN, DEATH):
        symbols = load_symbols(target)
        path = aliases_path(target)
        lines = path.read_text(encoding="utf-8").splitlines() if path.is_file() else []
        known = {line.split(" ", 1)[0] for line in lines}
        added = 0
        for alias, name in sorted(aliases.items()):
            if alias in known:
                continue
            if name in symbols:
                address = symbols[name][0]
            elif target == MAIN and AUTO.match(name):
                address = int(AUTO.match(name).group(1), 16)
            elif target == DEATH and name.startswith("death_") and AUTO.match(name[6:]):
                address = int(AUTO.match(name[6:]).group(1), 16)
            else:
                continue
            lines.append(f"{alias} = {address:#x}; // alias of {name}")
            added += 1
        path.write_text("\n".join(sorted(lines)) + "\n", encoding="utf-8")
        print(f"{target}: {added} alias symbols")
    print(f"{changed} files rewritten, {len(aliases)} aliases")
    for line in skipped:
        print(f"  left alone: {line}")


if __name__ == "__main__":
    main()
