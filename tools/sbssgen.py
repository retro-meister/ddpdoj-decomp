#!/usr/bin/env python3
"""Define a unit's small zero-initialised variables (.sbss) in its C file, for both game executables.

    uv run tools/sbssgen.py [--dry] [--section .sbss|.bss] UNIT START END [UNIT START END ...]

UNIT is the unit's file name without `.c` (found under src/game or src/death). START and END are Main
addresses; every label in the range becomes a definition appended to the unit, from the highest address
down, because the compiler emits them in reverse. The type is the one the unit itself declares the name
with, else one another unit declares, else one chosen by size. The Death Label block is found through
the names and must have the same layout. The yaml of both executables gets the unit's entry, and the
names leave both symbols.txt files.

Run after `uv run tools/build.py --map` (it reads the split assembly). Nothing is written when a block
cannot be laid out as the executable has it.
"""
import json
import re
import sys
from pathlib import Path

R = Path(__file__).resolve().parent.parent
TARGETS = ('SLPS_252.33', 'DEATH.ELF')
SIZES = {'s8': 1, 'u8': 1, 'char': 1, 's16': 2, 'u16': 2, 'short': 2, 's32': 4, 'u32': 4, 'int': 4, 'f32': 4,
         'float': 4, 'long': 4, 's64': 8, 'u64': 8}

args = sys.argv[1:]
dry = '--dry' in args
if dry: args.remove('--dry')
section = '.sbss'
if '--section' in args:
    i = args.index('--section'); section = args[i + 1]; del args[i:i + 2]
assert section in ('.sbss', '.bss') and args and len(args) % 3 == 0, __doc__
kind = section[1:]
jobs = [(args[i], int(args[i + 1], 16), int(args[i + 2], 16)) for i in range(0, len(args), 3)]


def read_labels(target):
    """{address: (name, bytes to the next label)} of the section's split assembly."""
    out = {}
    for path in sorted((R / f'build/split/{target}/asm/data').glob(f'{kind}_*.{kind}.s')):
        name = None; address = None; size = 0
        for line in path.read_text().split('\n'):
            m = re.match(r'dlabel (\w+)', line)
            if m:
                if name: out[address] = (name, size)
                name, address, size = m.group(1), None, 0
                continue
            m = re.match(r'\s+/\* ([0-9A-F]{8}) \*/ \.space 0x([0-9A-Fa-f]+)', line)
            if m and name:
                if address is None: address = int(m.group(1), 16)
                size += int(m.group(2), 16)
        if name: out[address] = (name, size)
    # a block that has moved to C has no assembly any more: remember what was read
    cache = R / f'build/sbssgen_{kind}_{target}.json'
    known = {int(k): tuple(v) for k, v in json.loads(cache.read_text()).items()} if cache.is_file() else {}
    known.update(out)
    cache.write_text(json.dumps({str(k): v for k, v in sorted(known.items())}))
    return known


def unit_path(unit):
    found = [p for p in list((R / 'src/game').rglob(unit + '.c')) + list((R / 'src/death').rglob(unit + '.c'))]
    assert len(found) == 1, (unit, found)
    return found[0]


DECL = re.compile(r'^extern\s+((?:const\s+|volatile\s+|struct\s+|unsigned\s+|signed\s+)*\w+(?:\s*\*+\s*|\s+))(\w+)\s*((?:\[[^\]]*\])*)\s*;', re.M)
sources = {p: p.read_text() for p in list((R / 'src').rglob('*.c')) + list((R / 'include').rglob('*.h')) if 'gallery' not in str(p)}
declared = {}
for p, text in sources.items():
    for m in DECL.finditer(text):
        declared.setdefault(m.group(2), []).append((p, ' '.join(m.group(1).split()), m.group(3)))


def measure(base, dims):
    """(element size, count, known) of a declaration; count None when a dimension is left open."""
    if '*' in base: element = 4
    else: element = SIZES.get(base.replace('unsigned ', '').replace('signed ', '').replace('volatile ', '').strip())
    count = 1
    for d in re.findall(r'\[([^\]]*)\]', dims):
        if not d.strip(): return element, None
        if not re.fullmatch(r'\s*(0x[0-9A-Fa-f]+|\d+)\s*', d): return element, None
        count *= int(d, 0)
    return element, count


def by_size(gap):
    if gap == 1: return 'u8', ''
    if gap == 2: return 's16', ''
    if gap == 4: return 's32', ''
    if gap == 8: return 's32', '[2]'
    return 'u8', '[%d]' % gap


def alignment(element, dims, size):
    """What the compiler aligns a small variable to: a scalar to its size, an array to 4, or to 8 past 4 bytes."""
    if dims: return 8 if size > 4 else 4
    return min(element or 4, 8)


def bound(name, path):
    """The declarations the definition has to agree with: the unit's own and the headers'."""
    return [d for d in declared.get(name, ()) if d[0] == path or d[0].suffix == '.h']


def choose(name, gap, path):
    """(type, dimensions, size, alignment) for a name with `gap` bytes to the next variable."""
    others = [d for d in declared.get(name, ()) if d not in bound(name, path)]
    for group, binding in ((bound(name, path), True), (others, False)):
        for _, base, dims in group:
            element, count = measure(base, dims)
            if element is None:
                if binding: return base, dims, gap, alignment(None, dims, gap)
                continue
            if count is None:
                if gap % element:
                    assert not binding, (name, base, dims, gap)
                    continue
                dims = '[%d]' % (gap // element)
                if not binding and (gap > 4 and (gap % 8 or gap > 8)): continue
                return base, dims, gap, alignment(element, dims, gap)
            if element * count > gap and not binding:
                continue
            return base, dims, element * count, alignment(element, dims, element * count)
    base, dims = by_size(gap)
    element, count = measure(base, dims)
    return base, dims, gap, alignment(element, dims, gap)


def lay_out(labels, start, end, path):
    """([(address, name, type, dims, attribute)] ascending, [(address, name)] of labels inside a variable), or
    raise when the block cannot be reproduced."""
    rows = []
    interior = []
    position = start
    inside = sorted(a for a in labels if start <= a < end)
    assert inside and inside[0] == start, f'no label at {start:#x}'
    # a label declared as an array cannot start off a word: it is a view into the variable before it
    views = {a for a in inside if a % 4 and any(d[2] for d in declared.get(labels[a][0], ()))}
    assert start not in views
    for n, a in enumerate(inside):
        name, gap = labels[a]
        if a < position or a in views:
            interior.append((a, name)); continue
        following = [b for b in inside[n + 1:] if b not in views]
        gap = (following[0] if following else end) - a
        if following: gap = min(gap, sum(labels[b][1] for b in inside[n:] if b < following[0]))
        base, dims, size, align = choose(name, gap, path)
        attribute = ''
        if not rows and align < 4 and a % 4 == 0:
            attribute = ' __attribute__((aligned(4)))'
        elif a % align or (position + align - 1) // align * align != a:
            for wider in (4, 8, 16):
                if wider > align and a % wider == 0 and (position + wider - 1) // wider * wider == a:
                    attribute = ' __attribute__((aligned(%d)))' % wider; break
            else:
                raise AssertionError(f'{name} at {a:#x} ({base}{dims}): cannot follow a variable ending at {position:#x}')
        rows.append((a, name, base, dims, attribute))
        position = a + size
    assert position <= end and end - position < 4, f'{end - position:#x} bytes unexplained before {end:#x}'
    return rows, interior


def claim(text, target, start, end, stub):
    """The yaml with the unit's entry cut out of the assembly slice that holds the range."""
    lines = text.split('\n')
    pattern = re.compile(r'^(\s+)- \{type: (\.?%s), vram: (0x[0-9a-f]+), name: ([\w/]+)\}$' % kind)
    entries = [(i, pattern.match(l)) for i, l in enumerate(lines)]
    entries = [(i, m.group(2), int(m.group(3), 16), m.group(4), m.group(1)) for i, m in entries if m]
    assert entries, target
    assert not any(e[3] == stub and e[1] == section for e in entries), f'{stub} already has a {section} entry in {target}'
    for n, (i, typ, vram, name, indent) in enumerate(entries):
        stop = entries[n + 1][2] if n + 1 < len(entries) else None
        if vram <= start and (stop is None or start < stop):
            assert typ == kind, f'{target}: {start:#x} is inside {name}'
            assert stop is None or end <= stop, f'{target}: {start:#x}..{end:#x} runs past {stop:#x}'
            new = []
            if vram < start: new.append(lines[i])
            new.append('%s- {type: %s, vram: 0x%x, name: %s}' % (indent, section, start, stub))
            if stop is None or end < stop: new.append('%s- {type: %s, vram: 0x%x, name: %s_%x}' % (indent, kind, end, kind, end))
            lines[i:i + 1] = new
            return '\n'.join(lines)
    raise AssertionError((target, hex(start)))


main_labels, death_labels = read_labels(TARGETS[0]), read_labels(TARGETS[1])
death_at = {name: a for a, (name, _) in death_labels.items()}
yamls = {t: (R / f'config/{t}/splat.yaml').read_text() for t in TARGETS}
symbols = {t: (R / f'config/{t}/symbols.txt').read_text() for t in TARGETS}
used = set(re.findall(r'\b[A-Za-z_]\w*\b', ''.join(sources.values())))
main_names = set(re.findall(r'^(\w+)\s*=', symbols[TARGETS[0]], re.M)) | {n for n, _ in main_labels.values()}
# names Death Label's remaining assembly refers to keep their line there, or the split would spell the address
death_asm = set()
for p in (R / f'build/split/{TARGETS[1]}/asm').rglob('*.s'):
    if p.parent.name != 'data': death_asm |= set(re.findall(r'\b[A-Za-z_]\w*\b', p.read_text()))
appended = {}
failed = []
for unit, start, end in jobs:
    try:
        path = unit_path(unit)
        stub = str(path.relative_to(R / 'src'))[:-2]
        rows, interior = lay_out(main_labels, start, end, path)
        missing = [r[1] for r in rows if r[1] not in death_at]
        assert not missing, f'Death Label has no {missing[:4]}'
        death_start = death_at[rows[0][1]]
        death_end = death_at[rows[-1][1]] + end - rows[-1][0]
        death_rows, death_interior = lay_out(death_labels, death_start, death_end, path)
        shared = {r[1] for r in rows}
        assert [r[1:] for r in death_rows if r[1] in shared] == [r[1:] for r in rows], 'Death Label needs different definitions'
        death_only = {r[1] for r in death_rows} - shared
        clash = sorted(n for n in death_only if n in main_names or (n in used and n not in declared))
        assert not clash, f'Death Label only {clash[:4]} spell names of Main'
        delta = death_start - start
        text = appended.get(path, sources[path])
        for r in rows:
            assert not re.search(r'^(?!extern\b)\w[\w \*]*\b%s\b(\[[^\]]*\])*( __attribute__\(\(aligned\(\d+\)\)\))?;' % r[1], text, re.M), f'{r[1]} is already defined'
        body = '\n/* %s (the compiler lays these out in reverse) */\n' % section
        for _, name, base, dims, attribute in reversed(death_rows):
            line = '%s%s%s%s%s;\n' % (base, '' if base.endswith('*') else ' ', name, dims, attribute)
            body += '#ifdef DEATH_LABEL\n%s#endif\n' % line if name in death_only else line
        body = body.replace('#endif\n#ifdef DEATH_LABEL\n', '')
        yamls[TARGETS[0]] = claim(yamls[TARGETS[0]], TARGETS[0], start, end, stub)
        yamls[TARGETS[1]] = claim(yamls[TARGETS[1]], TARGETS[1], death_start, death_end, stub)
        appended[path] = text.rstrip('\n') + '\n' + body
        for t in TARGETS:
            names = shared | (death_only if t == TARGETS[1] else set())
            kept = []
            for line in symbols[t].split('\n'):
                m = re.match(r'(\w+)\s*=\s*0x', line)
                if m and m.group(1) in names and 'ignore:true' not in line and not (t == TARGETS[1] and m.group(1) in death_asm): continue
                kept.append(line)
            symbols[t] = '\n'.join(kept)
        for t, inner in ((TARGETS[0], interior), (TARGETS[1], death_interior)):
            lines = ['%s = 0x%x;' % (n, a) for a, n in inner if not re.search(r'^%s\s*=' % n, symbols[t], re.M)]
            if lines: symbols[t] = symbols[t].rstrip('\n') + '\n' + '\n'.join(lines) + '\n'
        # what Death Label's assembly would now call the address must not spell a name the shared code uses
        add = []
        for a, name, *_ in death_rows:
            auto = 'D_%08X' % a
            if auto != name and (auto in used or auto in main_names) and not re.search(r'^death_%s\s*=' % auto, symbols[TARGETS[1]], re.M):
                add.append('death_%s = 0x%x;' % (auto, a))
        if add: symbols[TARGETS[1]] = symbols[TARGETS[1]].rstrip('\n') + '\n' + '\n'.join(add) + '\n'
        print('OK   %-22s %x..%x (Death Label %x..%x) %d variables, %d more in Death Label' % (unit, start, end, death_start, death_end, len(rows), len(death_only)))
        if dry: print(body)
    except AssertionError as error:
        failed.append(unit)
        print('FAIL %-22s %x..%x: %s' % (unit, start, end, error))
if not dry:
    for path, text in appended.items(): path.write_text(text)
    for t in TARGETS:
        (R / f'config/{t}/splat.yaml').write_text(yamls[t])
        (R / f'config/{t}/symbols.txt').write_text(symbols[t])
sys.exit(1 if failed else 0)
