"""Define stretches of assembly data as C, for both game executables.

    uv run tools/tablegen.py FILE [--desc TEXT] [--dry] SECTION:START:END[:DEATH_START[:DEATH_END]] ...
    uv run tools/tablegen.py FILE ... SECTION:START:END:-          (a stretch Death Label does not have)
    uv run tools/tablegen.py FILE --separate SECTION:START:END:DEATH_START:DEATH_END ...
                                     (the stretch is laid out differently: each executable gets its own
                                      definitions, from its own labels, under `#ifdef DEATH_LABEL`)
    options: --main-only START:END   objects inside a stretch that Death Label does not have (repeatable)
             --at MAIN=DEATH         the Death Label address of the object at MAIN (repeatable)
             --redo                  write the file again (its splat.yaml entries stay as they are)

Addresses that the split assembly shows as plain numbers in both executables are taken from the last
`tools/shiftcheck.py` run of each executable (build/shiftcheck/addresses_<target>.txt).

Writes the data-only file src/shared/FILE.c with the bytes of the stretches (.data / .sdata, main executable
addresses, hex) and gives the file those stretches in both splat.yaml files. Run after
`uv run tools/build.py --map` and `uv run tools/tablegen.py --refresh` (which reads the symbol references of
the split assembly and keeps them for the runs that follow); build afterwards (the change re-splits).

Objects start at the labels the link map knows in the stretch. A label that cannot start an object under the
compiler's layout rules stays a name inside the object before it and is kept in symbols.txt at its address.
Layout rules: .data takes objects of 9 bytes and more (on 8, from 16 bytes on 16); .sdata 8 bytes and less
(on 4, over 4 bytes on 8).

Words that are addresses are written as symbols. Which words those are comes from the symbol references in the
split assembly of both executables: a word counts as an address when it is one in both, pointing at the same
thing; a word that holds the same number in the other executable where that is not an address is a number.
An object that differs between the executables (contents, size or pointers) gets both definitions under
`#ifdef DEATH_LABEL`. The script stops instead of guessing when Death Label cannot be lined up; pass the Death
Label start (and end) of the stretch then.
"""
import json, re, sys
from pathlib import Path
from common import ROOT as R

OFF = 0xFFF80
args = sys.argv[1:]
dry = '--dry' in args
if dry: args.remove('--dry')
refresh = '--refresh' in args
redo = '--redo' in args
if redo: args.remove('--redo')
separate = '--separate' in args
if separate: args.remove('--separate')
desc = None
if '--desc' in args:
    i = args.index('--desc'); desc = args[i + 1]; del args[i:i + 2]
only_ranges = []; pins = {}
while '--main-only' in args:
    i = args.index('--main-only'); a_, b_ = args[i + 1].split(':'); only_ranges.append((int(a_, 16), int(b_, 16))); del args[i:i + 2]
while '--at' in args:
    i = args.index('--at'); a_, b_ = args[i + 1].split('='); pins[int(a_, 16)] = int(b_, 16); del args[i:i + 2]
confirmed = set(); numbers = set()
for flag in ('--address', '--number'):
    while flag in args:
        i = args.index(flag); confirmed.add(args[i + 1].lower())
        if flag == '--number': numbers.add(args[i + 1].lower())
        del args[i:i + 2]
forced = {x for r in only_ranges for x in r} | set(pins)
def is_main_only(a): return any(s_ <= a < e_ for s_, e_ in only_ranges)
name = args[0]
stretches = []
dstart_given = {}
main_only = set()
for a in args[1:]:
    parts = a.split(':'); sec, s, e = parts[:3]; stretches.append((sec, int(s, 16), int(e, 16)))
    if len(parts) > 3 and parts[3] == '-': main_only.add((sec, int(s, 16)))
    elif len(parts) > 3: dstart_given[(sec, int(s, 16))] = int(parts[3], 16)
def symbol_references(target):
    """{address of a data word: (symbol, addend)} for every symbol reference in the target's split assembly data."""
    found = {}
    # the split assembly changes under a batch (every config change re-splits), so it is read once, with
    # --refresh after a `tools/build.py --map`, and kept
    cache = R / 'build' / ('tablegen_refs_%s.json' % target)
    if not refresh:
        assert cache.exists(), 'run tools/build.py --map and then tools/tablegen.py --refresh'
        return {int(k): v for k, v in json.loads(cache.read_text()).items()}
    assert any((R / 'build/split' / target / 'asm/data').glob('*.s')), 'no split assembly: run tools/build.py --map first'
    covered = set()
    for path in (R / 'build/split' / target / 'asm/data').glob('*.s'):
        for line in path.read_text().splitlines():
            c = re.match(r'\s*/\* [0-9A-F]+ ([0-9A-F]{8}) ', line)
            if c: covered.add(int(c.group(1), 16))
            m = re.match(r'\s*/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/\s+\.word\s+([A-Za-z_][\w.]*)(?:\s*\+\s*(0x[0-9A-Fa-f]+|\d+))?\s*$', line)
            if m: found[int(m.group(1), 16)] = [m.group(2), int(m.group(3), 0) if m.group(3) else 0]
    # what was read earlier for data that has since left the assembly stays (for --redo)
    if cache.exists():
        for k, v in json.loads(cache.read_text()).items():
            if int(k) not in covered: found.setdefault(int(k), v)
    cache.write_text(json.dumps(found))
    print(target, len(found), 'symbol references in the split data')
    return found
from common import matching_lock
with matching_lock(shared=True, name='split.lock'):   # not while a re-split is writing it
    main_rel = symbol_references('SLPS_252.33'); death_rel = symbol_references('DEATH.ELF')
if refresh: sys.exit()
main_rel = {k: v for k, v in main_rel.items() if not re.fullmatch(r'D_[0-9A-F]{1,7}', v[0])}
death_rel = {k: v for k, v in death_rel.items() if not re.fullmatch(r'D_[0-9A-F]{1,7}', v[0])}
TEXT_END = 0x23DC80

def symfile(t):
    named, ignored = {}, set()
    for l in open(R / f'config/{t}/symbols.txt'):
        m = re.match(r'(\w+)\s*=\s*0x([0-9A-Fa-f]+);', l)
        if m:
            if 'ignore:true' in l: ignored.add(m.group(1))
            else: named[m.group(1)] = int(m.group(2), 16)
    return named, ignored
main_named, main_ignored = symfile('SLPS_252.33'); death_named, death_ignored = symfile('DEATH.ELF')
new_syms = {'SLPS_252.33': {}, 'DEATH.ELF': {}}
def invent(target, v):
    """A placeholder name for an address nothing names yet; it gets a line in the target's symbols.txt."""
    n = 'D_%08X' % v
    if target == 'DEATH.ELF' and (death_named.get(n, v) != v or n in main_named or n in used): n = 'death_' + n
    new_syms[target][n] = v
    return n
def target_name(target, names, v):
    """The name for an address a word points at: a known one, unless it is a Death Label placeholder that spells
    a name the shared code uses for something else."""
    if names and not (target == 'DEATH.ELF' and names[0] == 'D_%08X' % v and (names[0] in used or death_named.get(names[0], v) != v)):
        return names[0]
    return invent(target, v)
def add_checked_addresses(target, rel, named):
    """Words the shift check found to be addresses although nothing marks them."""
    path = R / 'build/shiftcheck' / ('addresses_%s.txt' % target)
    if not path.exists(): return
    at = {}
    for v, ks in named.items(): at[v] = [k for k in ks if not k.startswith('alabel')]
    for line in path.read_text().split('\n'):
        if not line: continue
        site, value = (int(x, 16) for x in line.split())
        if site in rel: continue
        names = sorted(at.get(value, ()), key=lambda q: (bool(re.fullmatch(r'(?:death_)?D_[0-9A-F]{8}', q)), q))
        rel[site] = [target_name(target, names, value), 0]
aliases = set()
for t in ('SLPS_252.33', 'DEATH.ELF'):
    for l in open(R / f'config/{t}/aliases.txt'):
        m = re.match(r'(\w+)\s*=', l)
        if m: aliases.add(m.group(1))
# labels of the Main link map
labels = {}
started = False
for l in open(R / 'build/SLPS_252.33.map'):
    if l.startswith('Linker script and memory map'): started = True
    if not started: continue
    m = re.match(r'^\s+0x([0-9a-f]{8,16})\s+([A-Za-z_][\w]*)(?:\s*=.*)?$', l)
    if not m: continue
    n = m.group(2); a = int(m.group(1), 16)
    if n in aliases or n in main_ignored or n.startswith(('main_', 'jtbl_')) or '_as_' in n: continue
    labels.setdefault(a, set()).add(n)
def read_labels(target, ignored):
    out = {}; on = False
    for l in open(R / f'build/{target}.map'):
        if l.startswith('Linker script and memory map'): on = True
        if not on: continue
        m = re.match(r'^\s+0x([0-9a-f]{8,16})\s+([A-Za-z_][\w]*)(?:\s*=.*)?$', l)
        if not m: continue
        n = m.group(2); a = int(m.group(1), 16)
        if n in aliases or n in ignored or n.startswith(('main_', 'jtbl_')) or '_as_' in n: continue
        out.setdefault(a, set()).add(n)
    return out
death_labels = read_labels('DEATH.ELF', death_ignored)
def pick(a):
    ns = labels[a]
    named = sorted(n for n in ns if n in main_named and not re.fullmatch(r'D_[0-9A-F]{8}', n))
    if named: return named[0]
    listed = sorted(n for n in ns if n in main_named)
    if listed: return listed[0]
    return 'D_%08X' % a
rom = (R / 'baserom/SLPS_252.33').read_bytes(); drom = (R / 'baserom/DEATH.ELF').read_bytes()
alltext = ''.join(p.read_text() for p in (R / 'src').rglob('*.c') if 'gallery' not in str(p)) + \
          ''.join(p.read_text() for p in (R / 'include').rglob('*.h'))
used = set(re.findall(r'\b[A-Za-z_]\w*\b', alltext))
# a Death Label placeholder read from an earlier split may since have become a Main name for something else
for site_, ref_ in death_rel.items():
    m = re.fullmatch(r'D_([0-9A-F]{8})', ref_[0])
    if m and int(m.group(1), 16) + ref_[1] == int.from_bytes(drom[site_ - OFF:site_ - OFF + 4], 'little') \
            and death_named.get(ref_[0], int(m.group(1), 16)) != int(m.group(1), 16):
        ref_[0] = 'death_' + ref_[0]; new_syms['DEATH.ELF'][ref_[0]] = int(m.group(1), 16)
add_checked_addresses('SLPS_252.33', main_rel, labels); add_checked_addresses('DEATH.ELF', death_rel, death_labels)
# element types the code already declares its tables with: {name: (type, count or None)}
WIDTH = {'s8': 1, 'u8': 1, 's16': 2, 'u16': 2, 's32': 4, 'u32': 4}
declared = {}
for m in re.finditer(r'^extern\s+(s8|u8|s16|u16|s32|u32)\s+(\w+)\[(\d*)\];', alltext, re.M):
    declared.setdefault(m.group(2), set()).add((m.group(1), int(m.group(3)) if m.group(3) else None))
def declared_as(n):
    """(type, count) when every declaration of the name agrees on the element type."""
    ds_ = declared.get(n, ())
    types = {t for t, _ in ds_}
    if len(types) != 1: return None
    counts = {c for _, c in ds_ if c}
    return next(iter(types)), (next(iter(counts)) if len(counts) == 1 else None)
def split_declared(objs):
    """An object the code declares shorter than its slot ends there when the layout allows it; the rest is an
    object of its own."""
    out = []
    for a, size, nxt in objs:
        n = pick(a) if a in labels else None
        d = declared_as(n) if n else None
        if d and d[1]:
            b = WIDTH[d[0]] * d[1]
            if 16 <= b < size and (a + b) % 16 == 0 and size - b >= 16:
                out += [(a, b, a + b), (a + b, size - b, nxt)]; continue
        out.append((a, size, nxt))
    return out

def death_delta(start, end):
    deltas = {}
    for a in sorted(labels):
        if start <= a < end:
            for n in labels[a]:
                if n in death_named and not re.fullmatch(r'D_[0-9A-F]{8}', n):
                    deltas.setdefault(death_named[n] - a, []).append(n)
    if not deltas:
        for a in sorted(labels):
            if start <= a < end:
                for n in labels[a]:
                    if n in death_named: deltas.setdefault(death_named[n] - a, []).append(n)
    assert deltas, 'no Death Label symbol in %x..%x' % (start, end)
    if len(deltas) > 1:
        best = max(deltas, key=lambda d: len(deltas[d]))
        odd = {d: v[:5] for d, v in deltas.items() if d != best}
        raise SystemExit('Death Label layout differs inside %x..%x: %s' % (start, end, odd))
    return next(iter(deltas))

def is_named(a):
    return a in labels and any(n in main_named and not re.fullmatch(r'D_[0-9A-F]{8}', n) for n in labels[a])

def partition_data(start, end):
    """Cheapest valid way to cut the stretch into objects: named labels are starts wherever the layout rules
    allow it, placeholder labels only where an object must start."""
    cands = sorted({a for a in labels if start <= a < end and a % 8 == 0} | {a for a in forced if start < a < end})
    if start not in cands: cands.insert(0, start)
    cands.append(end)
    n = len(cands)
    def valid(i, j):
        a, L = cands[i], cands[j] - cands[i]
        if a % 16 == 8:
            if any(x in main_rel for x in range(a, a + 16, 4)) and any(rom[a - OFF + 12:a - OFF + 16]):
                return False   # addresses fill it up to 16 bytes: it cannot sit on an odd 8
            return L in (16, 24) and not any(rom[a - OFF + 15:a - OFF + L])
        return L >= 16
    # a label where Death Label's distance from Main changes starts an object too
    moved = {a for a in forced if start < a < end}; last = None
    for a in cands[:-1]:
        ds_ = [death_named[q] - a for q in labels.get(a, ()) if q in death_named]
        if ds_:
            if last is not None and ds_[0] != last: moved.add(a)
            last = ds_[0]
    INF = float('inf')
    best = [INF] * n; back = [None] * n
    best[n - 1] = 0
    for i in range(n - 2, -1, -1):
        own = -1 if is_named(cands[i]) or i == 0 or cands[i] in moved else 1000
        if own > 0 and (separate or is_main_only(cands[i])) and any(q in used for q in labels.get(cands[i], ())):
            own = -1   # nothing to line up with: a label the code uses starts an object
        for j in range(i + 1, n):
            if j > i + 1 and cands[j - 1] in moved and cands[j - 1] in forced: break   # never across a given cut
            if cands[i] % 16 == 8 and cands[j] - cands[i] > 24: break
            if best[j] is INF or not valid(i, j): continue
            c = own + best[j]
            if c < best[i]: best[i] = c; back[i] = j
    assert best[0] is not INF, 'no valid layout for %x..%x' % (start, end)
    out = []; i = 0
    while i != n - 1:
        j = back[i]; a = cands[i]; nxt = cands[j]
        if a % 16 == 8:
            size = 14 if not rom[a - OFF + 14] else 15
            if any(x in main_rel for x in range(a, a + 16, 4)):
                # with addresses in it the object is whole words: three of them at most, to stay under 16 bytes
                assert not any(rom[a - OFF + 12:a - OFF + 16]), 'no object can start at %x' % a
                size = 12
        else:
            size = nxt - a
        out.append((a, size, nxt)); i = j
    return out

def partition_sdata(start, end):
    cands = sorted(a for a in labels if start <= a < end and a % 4 == 0)
    if start not in cands: cands.insert(0, start)
    out = []
    for i, a in enumerate(cands):
        nxt = cands[i + 1] if i + 1 < len(cands) else end
        p = a
        while p < nxt:
            size = 8 if (p % 8 == 0 and nxt - p >= 8) else 4
            size = min(size, nxt - p)
            out.append((p, size, p + size))
            p += size
    return out

def words(raw):
    return [int.from_bytes(raw[j:j + 2], 'little') for j in range(0, len(raw), 2)]
def fmt(raw, size):
    if size % 2 == 0:
        w = words(raw[:size])
        return '\n'.join('    ' + ', '.join('0x%04X' % x for x in w[j:j + 8]) + ',' for j in range(0, len(w), 8))
    return '\n'.join('    ' + ', '.join('0x%02X' % x for x in raw[j:j + 12]) + ',' for j in range(0, size, 12))

death_add = {}; death_alias = {}; main_numbers = set()
defs = []; defined = {}; plan = []; decls = []; kinds = {}; externs = {}; dexterns = {}
dend_given = {}
for arg in args[1:]:
    parts = arg.split(':')
    if len(parts) > 4: dend_given[(parts[0], int(parts[1], 16))] = int(parts[4], 16)
def sym_addr(sym, named):
    if sym in named: return named[sym]
    m = re.fullmatch(r'(?:death_)?(?:D|func)_([0-9A-F]{8})', sym)
    assert m, 'no address for ' + sym
    return int(m.group(1), 16)
PLACE = r'(?:death_)?(?:D|func)_[0-9A-F]{8}'
sep_stretches = []
if separate:
    for arg in args[1:]:
        q = arg.split(':'); assert len(q) == 5, 'a separate stretch is SECTION:START:END:DEATH_START:DEATH_END'
        sep_stretches.append((q[0], int(q[1], 16), int(q[2], 16), int(q[3], 16), int(q[4], 16)))
    stretches = []
objects = []   # (sec, a, size, nxt, da, dsize, dn, name)
for sec, start, end in stretches:
    objs = split_declared(partition_data(start, end)) if sec == '.data' else partition_sdata(start, end)
    if (sec, start) in main_only:
        plan.append((sec, start, end, None, None, objs))
        for a, size, nxt in objs:
            n = pick(a) if a in labels else 'D_%08X' % a
            assert n not in defined, n
            defined[n] = a
            objects.append((sec, a, size, nxt, None, size, None, n))
        continue
    dstarts = []
    for i, (a, size, nxt) in enumerate(objs):
        n = pick(a) if a in labels else 'D_%08X' % a
        if is_main_only(a): dstarts.append(None)
        elif a in pins: dstarts.append(pins[a])
        elif n in death_named and (not re.fullmatch(PLACE, n) or True) and not (re.fullmatch(r'D_[0-9A-F]{8}', n) and death_named[n] == a and i):
            dstarts.append(death_named[n])
        elif i and dstarts[-1] is None:
            raise SystemExit('give the Death Label address of %x with --at' % a)
        elif i == 0:
            if (sec, start) in dstart_given: dstarts.append(dstart_given[(sec, start)])
            else:
                first = [(x, sorted(q for q in labels[x] if q in death_named)) for x in sorted(labels) if start <= x < end]
                first = [(x, q[0]) for x, q in first if q]
                assert first, 'no Death Label symbol in %x..%x' % (start, end)
                dstarts.append(death_named[first[0][1]] - (first[0][0] - start))
        else:
            dstarts.append(dstarts[-1] + a - objs[i - 1][0])
    if (sec, start) in dstart_given: assert dstarts[0] == dstart_given[(sec, start)], 'Death Label start disagrees'
    if sec == '.sdata':
        # an 8-byte object that Death Label has off an 8-byte boundary is two 4-byte objects
        o2 = []; d2 = []
        for (a, size, nxt), da in zip(objs, dstarts):
            if size == 8 and da is not None and dend_given.get((sec, start)) == da + 4 \
                    and not any(rom[a - OFF + 4:a - OFF + 8]):
                o2.append((a, 4, nxt)); d2.append(da)   # 4 bytes; Main pads before an object on 8
            elif size == 8 and da is not None and da % 8:
                o2 += [(a, 4, a + 4), (a + 4, 4, nxt)]; d2 += [da, da + 4]
            else:
                o2.append((a, size, nxt)); d2.append(da)
        objs, dstarts = o2, d2
    there = [i for i, d in enumerate(dstarts) if d is not None]
    assert there, 'nothing of the stretch is in Death Label: use SECTION:START:END:-'
    dend = dend_given.get((sec, start), dstarts[there[-1]] + objs[there[-1]][2] - objs[there[-1]][0])
    plan.append((sec, start, end, dstarts[there[0]], dend, objs))
    pos = dstarts[there[0]]
    for i, (a, size, nxt) in enumerate(objs):
        da = dstarts[i]
        if da is None:
            n = pick(a) if a in labels else 'D_%08X' % a
            assert n not in defined, n
            defined[n] = a
            objects.append((sec, a, size, nxt, None, size, None, n)); continue
        later = [j for j in there if j > i]
        dn = dstarts[later[0]] if later else dend
        assert dn > da, 'Death Label order differs at %x' % a
        same = dn - da == nxt - a
        if sec == '.data' and not same and nxt - a == 16 and a % 16 == 0 and da % 16 == 8 and dn - da == 24 \
                and not any(rom[a - OFF + 14:a - OFF + 16]):
            # under 16 bytes: on 8 in Death Label, with the next object on 16 in both
            size = 12 if not any(rom[a - OFF + 12:a - OFF + 14]) else 14
            assert not any(drom[da - OFF + size:dn - OFF]), 'padding not zero at %x' % a
            same = True
        if sec == '.sdata' and size == 4 and nxt - a == 8 and dn - da == 4: same = True
        dsize = size if same else dn - da
        if not same: assert sec == '.data' and dsize >= 16 and da % 16 == 0, 'Death Label object at %x cannot be laid out' % a
        al = (16 if dsize >= 16 else 8) if sec == '.data' else (8 if dsize > 4 else 4)
        pos = (pos + al - 1) // al * al
        assert pos == da, 'Death Label lays %x out differently (%x, expected %x)' % (a, pos, da)
        pos += dsize
        n = pick(a) if a in labels else 'D_%08X' % a
        assert n not in defined, n
        defined[n] = a
        objects.append((sec, a, size, nxt, da, dsize, dn, n))
    al_end = 16 if sec == '.data' else 4
    assert (pos + al_end - 1) // al_end * al_end == (dend + al_end - 1) // al_end * al_end, 'Death Label stretch ends elsewhere'
obj_by_main = [(a, a + size, None if da is None else da - a, n) for sec, a, size, nxt, da, dsize, dn, n in objects]
def carray(n, raw, size):
    d = declared_as(n)
    if d and size % WIDTH[d[0]] == 0 and (d[1] is None or d[1] * WIDTH[d[0]] == size):
        ctype, w = d[0], WIDTH[d[0]]; count = size // w
        vals = [int.from_bytes(raw[j:j + w], 'little', signed=ctype[0] == 's') for j in range(0, size, w)]
        if ctype[0] == 's': text = ['%d' % v for v in vals]
        else: text = [('0x%%0%dX' % (2 * w)) % v for v in vals]
        per = 16 if w == 1 else 8
        body = '\n'.join('    ' + ', '.join(text[j:j + per]) + ',' for j in range(0, count, per))
        return ctype, count, '%s %s[%d] = {\n%s\n};\n' % (ctype, n, count, body)
    ctype = 'u16' if size % 2 == 0 else 'u8'
    count = size // 2 if size % 2 == 0 else size
    return ctype, count, '%s %s[%d] = {\n%s\n};\n' % (ctype, n, count, fmt(raw, size))
def main_target(x):
    sym, add = main_rel[x]
    if sym in defined:
        base = sym if kinds.get(sym) != 'record' else '&' + sym
    elif re.fullmatch(r'D_[0-9A-F]{8}', sym) and sym not in used and any(s_ <= int(sym[2:], 16) < e_ for s_, e_, d_, _ in obj_by_main):
        # a placeholder inside an object of this file: the object plus the distance
        addr = int(sym[2:], 16)
        s_, o_ = [(s_, n_) for s_, e_, d_, n_ in obj_by_main if s_ <= addr < e_][0]
        base = o_ if kinds.get(o_) != 'record' else '&' + o_
        add += addr - s_
    else:
        addr = sym_addr(sym, main_named)
        is_code = sym.startswith('func_') or addr < TEXT_END
        externs[sym] = 'void %s();' % sym if is_code else 'extern u8 %s[];' % sym
        base = sym
    return '(u8 *)%s + %d' % (base, add) if add else base
def death_target(x):
    sym, add = death_rel[x]
    assert sym not in defined and sym not in main_named or (sym in main_named and sym in death_named), 'Death Label name %s means something else in the shared file' % sym
    addr = sym_addr(sym, death_named)
    is_code = sym.startswith('func_') or addr < 0x241700
    if sym in defined: base = sym if kinds.get(sym) != 'record' else '&' + sym
    else:
        dexterns[sym] = 'void %s();' % sym if is_code else 'extern u8 %s[];' % sym
        base = sym
    return '(u8 *)%s + %d' % (base, add) if add else base
def fields_of(a, size, raw, rel, target):
    fields = []; vals = []; p = 0; k = 0
    while p < size:
        if a + p in rel:
            q = p; run = []
            while q < size and (a + q) in rel: run.append(target(a + q)); q += 4
            if len(run) == 1:
                fields.append('void *p%d;' % k); vals.append(run[0])
            else:
                fields.append('void *p%d[%d];' % (k, len(run)))
                vals.append('{\n' + '\n'.join('        %s,' % v for v in run) + '\n    }')
            p = q
        else:
            q = p
            while q < size and (a + q) not in rel: q += 2
            w = words(raw[p:q])
            fields.append('u16 w%d[%d];' % (k, len(w))); vals.append('{ ' + ', '.join('0x%04X' % x for x in w) + ' }'); p = q
        k += 1
    return fields, vals
def corresponds(a, size, da):
    """True when every pointer of the object has its counterpart in Death Label; fills death_add."""
    ms = [x for x in range(a, a + size - 3) if x in main_rel]; ds = [x for x in range(da, da + size - 3) if x in death_rel]
    if ds != [x - a + da for x in ms]: return False
    pend = {}; pal = {}
    for x in ms:
        msym, madd = main_rel[x]; dsym, dadd = death_rel[x - a + da]
        ma = sym_addr(msym, main_named) + madd; dta = sym_addr(dsym, death_named) + dadd
        inside = [d_ for s_, e_, d_, _ in obj_by_main if s_ <= ma < e_]
        if inside:
            if inside[0] is None or dta != ma + inside[0]: return False
            if msym not in defined: pend[msym] = sym_addr(msym, main_named) + inside[0]
            continue
        if msym == dsym and madd == dadd: continue
        if madd != dadd: return False
        if msym in death_named: return False
        if dsym in death_named: pal[msym] = (sym_addr(dsym, death_named), dsym)
        else: pend[msym] = sym_addr(dsym, death_named)
    death_add.update(pend); death_alias.update(pal)
    return True
# decide kinds first (a pointer to a record needs &)
info = {}
for sec, a, size, nxt, da, dsize, dn, n in objects:
    raw = rom[a - OFF:a - OFF + size]
    if da is None:
        assert not any(rom[a - OFF + size:nxt - OFF]), 'padding not zero at %x' % a
        ms = [x for x in range(a, a + size - 3) if x in main_rel]
        for x in list(ms):
            q = main_rel[x][0]
            if re.fullmatch(r'D_[0-9A-F]{8}', q) and q not in used and q not in defined \
                    and not any(s_ <= int(q[2:], 16) < e_ for s_, e_, d_, _ in obj_by_main):
                # nothing to check it against: only a placeholder past the data sections is taken for a number
                assert int(q[2:], 16) >= 0x28F000, 'unverified pointer %s in %s (not in Death Label, nothing else uses the target)' % (q, n)
                main_numbers.add(q); main_rel.pop(x); ms.remove(x)
        assert all((x - a) % 4 == 0 for x in ms), 'odd pointer position in %s' % n
        mk = 'plain' if not ms else ('table' if len(ms) * 4 == size else 'record')
        kinds[n] = 'record' if mk == 'record' else 'array'
        info[n] = (raw, None, ms, [], mk, None)
        continue
    draw = drom[da - OFF:da - OFF + dsize]
    assert not any(rom[a - OFF + size:nxt - OFF]), 'padding not zero at %x' % a
    if dn - da == nxt - a or dsize == size:
        assert not any(rom[a - OFF + size:nxt - OFF]) and not any(drom[da - OFF + size:dn - OFF]), 'padding not zero at %x' % a
    ms = [x for x in range(a, a + size - 3) if x in main_rel]; ds = [x for x in range(da, da + dsize - 3) if x in death_rel]
    if size == dsize:
        # a word that is a number in one executable and holds the same value in the other is a number in both
        ms2 = [x for x in ms if not ((x - a + da) not in death_rel and raw[x - a:x - a + 4] == draw[x - a:x - a + 4])]
        ds2 = [x for x in ds if not ((x - da + a) not in main_rel and raw[x - da:x - da + 4] == draw[x - da:x - da + 4])]
        for x in set(ms) - set(ms2): main_rel.pop(x)
        for x in set(ds) - set(ds2): death_rel.pop(x)
        ms, ds = ms2, ds2
        # a word that is an address in one executable and differs in the other is an address there too, also
        # where the split assembly shows it as something else (a short string, say)
        for x in ms:
            y = x - a + da
            if y not in death_rel:
                v = int.from_bytes(draw[x - a:x - a + 4], 'little')
                if not v: continue
                q = sorted(k for k, val in death_named.items() if val == v)
                death_rel[y] = [q[0] if q else 'D_%08X' % v, 0]; ds.append(y)
                print('Death Label %x: 0x%x taken for an address (it is one in Main)' % (y, v))
        for y in list(ds):
            x = y - da + a
            if x not in main_rel:
                v = int.from_bytes(raw[y - da:y - da + 4], 'little')
                if not v: continue
                q = sorted(k for k, val in main_named.items() if val == v)
                main_rel[x] = [q[0] if q else 'D_%08X' % v, 0]; ms.append(x)
                print('Main %x: 0x%x taken for an address (it is one in Death Label)' % (x, v))
        # neither split marks it, but the two words differ and point into their images at the same contents
        for x in range(a, a + size - 3, 4):
            y = x - a + da
            if x in main_rel or y in death_rel: continue
            v = int.from_bytes(raw[x - a:x - a + 4], 'little'); w = int.from_bytes(draw[x - a:x - a + 4], 'little')
            if v == w or not (0x100000 <= v < 0x6F0000 and 0x100000 <= w < 0x6F0000): continue
            left = rom[v - OFF:v - OFF + 16]
            if len(left) == 16 and any(left) and left == drom[w - OFF:w - OFF + 16]:
                for t_, rel_, val_, labs_, site_, lst_ in (('SLPS_252.33', main_rel, v, labels, x, ms), ('DEATH.ELF', death_rel, w, death_labels, y, ds)):
                    names = sorted((q for q in labs_.get(val_, ()) if not q.startswith('alabel')),
                                   key=lambda q: (bool(re.fullmatch(r'(?:death_)?D_[0-9A-F]{8}', q)), q))
                    rel_[site_] = [target_name(t_, names, val_), 0]; lst_.append(site_)
            else:
                print('%s: 0x%x / 0x%x at %x differ and look like addresses, left as numbers' % (n, v, w, x))
        ms.sort(); ds.sort()
    assert all((x - a) % 4 == 0 for x in ms) and all((x - da) % 4 == 0 for x in ds), 'odd pointer position in %s' % n
    if ms or ds: assert size % 2 == 0 and dsize % 2 == 0
    mk = 'plain' if not ms else ('table' if len(ms) * 4 == size else 'record')
    dk = 'plain' if not ds else ('table' if len(ds) * 4 == dsize else 'record')
    kinds[n] = 'record' if 'record' in (mk, dk) else 'array'
    info[n] = (raw, draw, ms, ds, mk, dk)
def one(n, a, size, raw, sites, kind, rel, target):
    """(declaration, definition) of the object for one executable."""
    if kind == 'plain':
        ctype, count, text = carray(n, raw, size)
        return 'extern %s %s[%d];' % (ctype, n, count), text
    if kind == 'table' and kinds[n] == 'array':
        vals = [target(a + q) for q in range(0, size, 4)]; fields = vals
        return 'extern void *%s[%d];' % (n, len(fields)), 'void *%s[%d] = {\n%s\n};\n' % (n, len(fields), '\n'.join('    %s,' % v for v in vals))
    fields, vals = fields_of(a, size, raw, rel, target)
    tname = ''.join(w.capitalize() for w in n.split('_')) + 'Record'
    return ('struct %s { %s };\nextern struct %s %s;' % (tname, ' '.join(fields), tname, n),
            'struct %s %s = {\n%s\n};\n' % (tname, n, '\n'.join('    %s,' % v for v in vals)))
for sec, a, size, nxt, da, dsize, dn, n in objects:
    raw, draw, ms, ds, mk, dk = info[n]
    if da is None:
        md, mt = one(n, a, size, raw, ms, mk, main_rel, main_target)
        decls.append('#ifndef DEATH_LABEL\n%s\n#endif' % md)
        defs.append((sec, '#ifndef DEATH_LABEL\n%s#endif\n' % mt)); continue
    shared = False
    if size == dsize and mk == dk:
        if not ms: shared = raw == draw
        else:
            mask = bytearray(raw); dmask = bytearray(draw)
            for x in ms: mask[x - a:x - a + 4] = b'\0\0\0\0'; dmask[x - a:x - a + 4] = b'\0\0\0\0'
            shared = mask == dmask and corresponds(a, size, da)
    md, mt = one(n, a, size, raw, ms, mk, main_rel, main_target)
    if shared:
        decls.append(md); defs.append((sec, mt)); continue
    for x in ms:
        q = main_rel[x][0]
        qa = sym_addr(q, main_named)
        twin = size == dsize and (x - a + da) in death_rel   # an address at the same place in Death Label
        assert twin or q in defined or q in used or any(s_ <= qa < e_ for s_, e_, d_, _ in obj_by_main) or not re.fullmatch(r'D_[0-9A-F]{8}', q), \
            'unverified pointer %s in %s (differs from Death Label, nothing else uses the target)' % (q, n)
    for x in ds:
        q = death_rel[x][0]
        twin = size == dsize and (x - da + a) in main_rel
        assert twin or not (re.fullmatch(r'D_[0-9A-F]{8}', q) and int(q[2:], 16) >= 0x28FF00), 'unverified Death Label pointer %s in %s' % (q, n)
    dd, dt = one(n, da, dsize, draw, ds, dk, death_rel, death_target)
    decls.append(md if md == dd else '#ifdef DEATH_LABEL\n%s\n#else\n%s\n#endif' % (dd, md))
    defs.append((sec, '#ifdef DEATH_LABEL\n%s#else\n%s#endif\n' % (dt, mt)))
sep_text = None; sep_death_lines = []; sep_defined = {}
if separate:
    def side(target, t_labels, t_rom, t_named, t_rel, pieces):
        """Definitions of the stretches for one executable: (externs, declarations, definitions, names)."""
        global labels, rom, main_named, main_rel, obj_by_main, externs, kinds, defined
        labels, rom, main_named, main_rel = t_labels, t_rom, t_named, t_rel
        externs = {}; kinds = {}; defined = {}; obj_by_main = []
        objs_all = []
        other = drom if target == 'SLPS_252.33' else keep[1]
        for sec, start, end in pieces:
            # words neither split marks: a value inside the data of the image whose contents the other
            # executable has too is an address
            for x in range(start, end - 3, 4):
                if x in main_rel: continue
                v = int.from_bytes(rom[x - OFF:x - OFF + 4], 'little')
                if not (0x241700 <= v < 0x291000): continue
                there = rom[v - OFF:v - OFF + 16]
                if any(there) and (other.find(there, 0x241700 - OFF, 0x291000 - OFF) >= 0 or (v >= 0x261000 and v % 4 == 0)):
                    names = sorted((q for q in labels.get(v, ()) if not q.startswith('alabel')),
                                   key=lambda q: (bool(re.fullmatch(r'(?:death_)?D_[0-9A-F]{8}', q)), q))
                    main_rel[x] = [target_name(target, names, v), 0]
                else:
                    print('0x%x at %x looks like an address, left as a number' % (v, x))
            objs = split_declared(partition_data(start, end)) if sec == '.data' else partition_sdata(start, end)
            for a, size, nxt in objs:
                n = pick(a) if a in labels else 'D_%08X' % a
                # a Death Label placeholder that spells a name the shared code uses for something else
                if target == 'DEATH.ELF' and n == 'D_%08X' % a and n in used: n = 'death_' + n
                assert n not in defined, n
                assert not any(rom[a - OFF + size:nxt - OFF]), 'padding not zero at %x' % a
                defined[n] = a; objs_all.append((sec, a, size, n))
        obj_by_main = [(a, a + size, None, n) for sec, a, size, n in objs_all]
        sites = {}
        for sec, a, size, n in objs_all:
            ms = [x for x in range(a, a + size - 3) if x in main_rel]
            for x in list(ms):
                q = main_rel[x][0]; qa = sym_addr(q, main_named)
                known = q in defined or q in used or any(s_ <= qa < e_ for s_, e_, d_, _ in obj_by_main) \
                    or not re.fullmatch(PLACE, q) or qa < TEXT_END \
                    or (0x270000 <= qa < 0x291000 and qa % 4 == 0)   # the PS2 part's strings and tables
                # nothing to check an address against here: a placeholder nothing else uses must be confirmed
                assert known or ('%x' % x) in confirmed, 'unverified pointer %s at %x in %s: pass --address %x or --number %x' % (q, x, n, x, x)
                if ('%x' % x) in numbers: main_rel.pop(x); ms.remove(x)
            assert all((x - a) % 4 == 0 for x in ms), 'odd pointer position in %s' % n
            mk = 'plain' if not ms else ('table' if len(ms) * 4 == size else 'record')
            kinds[n] = 'record' if mk == 'record' else 'array'
            sites[n] = (ms, mk)
        ds_, fs_ = [], []
        for sec, a, size, n in objs_all:
            ms, mk = sites[n]
            d_, t_ = one(n, a, size, rom[a - OFF:a - OFF + size], ms, mk, main_rel, main_target)
            ds_.append(d_); fs_.append(t_)
        inside = []
        for s_, e_, d_, n_o in obj_by_main:
            for a_ in sorted(labels):
                if s_ < a_ < e_:
                    for n_ in labels[a_]:
                        if n_ in used: inside.append((n_, a_))
        return dict(externs), ds_, fs_, dict(defined), inside, any(sites[n][0] for n in sites), len(objs_all)
    keep = (labels, rom, main_named, main_rel)
    m_ext, m_decl, m_def, m_names, m_inside, m_ptr, m_count = side('SLPS_252.33', labels, rom, main_named, main_rel, [(q[0], q[1], q[2]) for q in sep_stretches])
    d_ext, d_decl, d_def, d_names, d_inside, d_ptr, d_count = side('DEATH.ELF', death_labels, drom, death_named, death_rel, [(q[0], q[3], q[4]) for q in sep_stretches])
    labels, rom, main_named, main_rel = keep
    def block(ext, decl, defs_, ptr):
        head_ = ('\n'.join(sorted(ext.values())) + '\n\n' + '\n'.join(decl) + '\n\n') if ptr else ''
        return head_ + '\n'.join(defs_)
    sep_text = '#ifdef DEATH_LABEL\n%s#else\n%s#endif\n' % (block(d_ext, d_decl, d_def, d_ptr), block(m_ext, m_decl, m_def, m_ptr))
    defined = dict(m_names); sep_defined = d_names
    obj_by_main = []
    main_inside = m_inside; sep_death_lines = d_inside
    plan = [(q[0], q[1], q[2], q[3], q[4], []) for q in sep_stretches]
    defs = [None] * (m_count + d_count); stretches = [(q[0], q[1], q[2]) for q in sep_stretches]
pointer_objs = [n for n in info if info[n][2] or info[n][3]]
# targets inside this file whose kind was decided late
total = sum(e - s for _, s, e in stretches)
print('%s: %d objects, %d bytes' % (name, len(defs), total))
if dry:
    for sec, start, end, ds_, de_, objs in plan:
        print(sec, '%x..%x' % (start, end), 'not in Death Label' if ds_ is None else 'death %x..%x' % (ds_, de_), len(objs), 'objects')
    sys.exit()

yaml_out = {}
for t in () if redo else ('SLPS_252.33', 'DEATH.ELF'):
    p = R / f'config/{t}/splat.yaml'; lines = p.read_text().split('\n')
    for sec, start, end, ds_, de_, objs in plan:
        if t == 'DEATH.ELF' and ds_ is None: continue
        s, e = (start, end) if t == 'SLPS_252.33' else (ds_, de_)
        plain = sec[1:]
        ents = [(i, int(m.group(1), 16), m.group(2), m.group(3)) for i, l in enumerate(lines)
                for m in [re.match(r'\s*- \[0x([0-9a-f]+), (\.?\w+)(?:, ([\w/\.]+))?\]', l)] if m]
        rs, re_ = s - OFF, e - OFF
        k = max(j for j, (i, a, kind, nm) in enumerate(ents) if a <= rs)
        i, a, kind, nm = ents[k]
        assert kind == plain, (t, sec, lines[i])
        nxt = ents[k + 1][1] if k + 1 < len(ents) else 1 << 40
        assert re_ <= nxt, (t, hex(re_), hex(nxt))
        indent = re.match(r'\s*', lines[i]).group(0)
        new = []
        if a < rs: new.append(lines[i])
        new.append('%s- [0x%x, %s, shared/%s]' % (indent, rs, sec, name))
        if re_ < nxt: new.append('%s- [0x%x, %s, %s_%x]' % (indent, re_, plain, plain, re_))
        lines[i:i + 1] = new
    yaml_out[t] = '\n'.join(lines)

path = R / 'src/shared' / (name + '.c')
assert redo or not path.exists(), path
head = '#include "common.h"\n\n'
if desc: head = '/* %s */\n' % desc + head
if separate:
    head += sep_text
elif pointer_objs:
    only = sorted(v for k, v in dexterns.items() if k not in externs)
    head += '\n'.join(sorted(externs.values())) + '\n' + ('#ifdef DEATH_LABEL\n%s\n#endif\n' % '\n'.join(only) if only else '') + '\n' + '\n'.join(decls) + '\n\n'
path.write_text(head + ('' if separate else '\n'.join(d for _, d in defs)))

# symbols: names now defined in C leave both files; labels inside objects that code uses stay as addresses
for t, named in (('SLPS_252.33', main_named), ('DEATH.ELF', death_named)):
    sp = R / f'config/{t}/symbols.txt'; out = []
    have = set()
    for l in open(sp):
        m = re.match(r'(\w+)\s*=\s*0x', l)
        # Death Label's own definitions keep their lines: a Main name at a Death Label address is only known there
        gone = {} if separate and t == 'DEATH.ELF' else defined
        if m and m.group(1) in gone and 'ignore:true' not in l: continue
        if m: have.add(m.group(1))
        out.append(l)
    text = ''.join(out)
    if not text.endswith('\n'): text += '\n'
    add = []
    # a placeholder the file points at keeps existing only while the assembly refers to it: give it a line
    ext_ = (m_ext if t == 'SLPS_252.33' else d_ext) if separate else (externs if t == 'SLPS_252.33' else dexterns)
    for n_ in sorted(ext_):
        m = re.fullmatch(r'(?:death_)?D_([0-9A-F]{8})', n_)
        if m and n_ not in have and n_ not in defined and n_ not in sep_defined and n_ not in death_add and n_ not in death_alias:
            new_syms[t].setdefault(n_, int(m.group(1), 16))
    for n_, a_ in sorted(new_syms[t].items()):
        if n_ not in have and n_ not in defined and n_ not in sep_defined: add.append('%s = 0x%x;\n' % (n_, a_)); have.add(n_)
    if separate:
        for n_, a_ in (sep_death_lines if t == 'DEATH.ELF' else main_inside):
            if n_ not in have: add.append('%s = 0x%x;\n' % (n_, a_)); have.add(n_)
        if t == 'DEATH.ELF':
            named_at = {int(m.group(2), 16) for m in re.finditer(r'^(\w+)\s*=\s*0x([0-9A-Fa-f]+);(?!.*ignore)', text, re.M)}
            for n_, a_ in sorted(sep_defined.items()):
                if n_ not in have: add.append('%s = 0x%x;\n' % (n_, a_)); have.add(n_)
                m = re.fullmatch(r'D_([0-9A-F]{8})', n_)
                # what Death Label has at the address the name spells needs its own name
                if m and int(m.group(1), 16) != a_ and int(m.group(1), 16) not in named_at and 0x100000 <= int(m.group(1), 16) < 0x700000 \
                        and 'death_' + n_ not in have:
                    add.append('death_%s = 0x%x;\n' % (n_, int(m.group(1), 16))); have.add('death_' + n_)
    for s_, e_, d_, n_o in obj_by_main:
        for a_ in sorted(labels):
            if s_ < a_ < e_ and not (t == 'DEATH.ELF' and d_ is None):
                for n_ in labels[a_]:
                    if n_ in used and n_ not in have:
                        add.append('%s = 0x%x;\n' % (n_, a_ + (d_ if t == 'DEATH.ELF' else 0)))
    if t == 'DEATH.ELF':
        for n_, a_ in sorted(death_add.items()):
            if n_ not in defined and not re.search(r'^%s = ' % n_, text, re.M): add.append('%s = 0x%x;\n' % (n_, a_))
        # an address Death Label already names takes the new name as an alias
        taken = {}
        for l in text.split('\n'):
            m = re.match(r'(\w+)\s*=\s*0x([0-9A-Fa-f]+);', l)
            if m and 'ignore:true' not in l: taken.setdefault(int(m.group(2), 16), m.group(1))
        keep = []
        for l in add:
            n_, a_ = l.split(' = '); a_ = int(a_.rstrip(';\n'), 16)
            if a_ in taken and taken[a_] != n_: death_alias[n_] = (a_, taken[a_])
            else: keep.append(l); taken[a_] = n_
        # a Main placeholder name given a Death Label address: whatever Death Label has at the address the
        # name spells needs a name of its own, or the split would call it the same
        for l in list(keep):
            n_, a_ = l.split(' = '); a_ = int(a_.rstrip(';\n'), 16)
            m = re.fullmatch(r'D_([0-9A-F]{8})', n_)
            if m and int(m.group(1), 16) != a_ and int(m.group(1), 16) not in taken and 0x100000 <= int(m.group(1), 16) < 0x700000:
                keep.append('death_%s = 0x%x;\n' % (n_, int(m.group(1), 16))); taken[int(m.group(1), 16)] = 'death_' + n_
        add = keep
        ap = R / 'config/DEATH.ELF/aliases.txt'; at = ap.read_text()
        for n_, (a_, other) in sorted(death_alias.items()):
            if not re.search(r'^%s = ' % n_, at, re.M): at = at.rstrip('\n') + '\n%s = 0x%x; // alias of %s\n' % (n_, a_, other)
        ap.write_text(at)
    else:
        for n_ in sorted(main_numbers):
            if n_ not in have: add.append('%s = 0x%x; // ignore:true\n' % (n_, int(n_[2:], 16)))
        for n_ in sorted(set(death_add) | set(death_alias)):
            if n_ not in defined and n_ not in have and re.fullmatch(r'D_[0-9A-F]{8}', n_):
                add.append('%s = 0x%x;\n' % (n_, int(n_[2:], 16)))
    sp.write_text(text + ''.join(add))
    if add: print(t, 'kept', len(add), 'inside names as addresses')

for t in yaml_out:
    (R / f'config/{t}/splat.yaml').write_text(yaml_out[t])
print('wrote', path)
