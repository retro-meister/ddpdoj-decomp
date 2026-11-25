"""Define stretches of assembly data as C, for both game executables.

    uv run tools/tablegen.py FILE [--desc TEXT] [--dry] SECTION:START:END[:DEATH_START[:DEATH_END]] ...

Writes the data-only file src/shared/FILE.c with the bytes of the stretches (.data / .sdata, main executable
addresses, hex) and gives the file those stretches in both splat.yaml files. Run after
`uv run tools/build.py --map`; build afterwards (the change re-splits).

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
import re, sys
from pathlib import Path
from common import ROOT as R

OFF = 0xFFF80
args = sys.argv[1:]
dry = '--dry' in args
if dry: args.remove('--dry')
desc = None
if '--desc' in args:
    i = args.index('--desc'); desc = args[i + 1]; del args[i:i + 2]
name = args[0]
stretches = []
dstart_given = {}
for a in args[1:]:
    parts = a.split(':'); sec, s, e = parts[:3]; stretches.append((sec, int(s, 16), int(e, 16)))
    if len(parts) > 3: dstart_given[(sec, int(s, 16))] = int(parts[3], 16)
def symbol_references(target):
    """{address of a data word: (symbol, addend)} for every symbol reference in the target's split assembly data."""
    found = {}
    for path in (R / 'build/split' / target / 'asm/data').glob('*.s'):
        for line in path.read_text().splitlines():
            m = re.match(r'\s*/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/\s+\.word\s+([A-Za-z_][\w.]*)(?:\s*\+\s*(0x[0-9A-Fa-f]+|\d+))?\s*$', line)
            if m: found[int(m.group(1), 16)] = [m.group(2), int(m.group(3), 0) if m.group(3) else 0]
    return found
main_rel = symbol_references('SLPS_252.33'); death_rel = symbol_references('DEATH.ELF')
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
def pick(a):
    ns = labels[a]
    named = sorted(n for n in ns if n in main_named and not re.fullmatch(r'D_[0-9A-F]{8}', n))
    if named: return named[0]
    return 'D_%08X' % a
rom = (R / 'baserom/SLPS_252.33').read_bytes(); drom = (R / 'baserom/DEATH.ELF').read_bytes()
alltext = ''.join(p.read_text() for p in (R / 'src').rglob('*.c') if 'gallery' not in str(p)) + \
          ''.join(p.read_text() for p in (R / 'include').rglob('*.h'))
used = set(re.findall(r'\b[A-Za-z_]\w*\b', alltext))

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
    cands = sorted(a for a in labels if start <= a < end and a % 8 == 0)
    if start not in cands: cands.insert(0, start)
    cands.append(end)
    n = len(cands)
    def valid(i, j):
        a, L = cands[i], cands[j] - cands[i]
        if a % 16 == 8:
            return L in (16, 24) and not any(rom[a - OFF + 15:a - OFF + L])
        return L >= 16
    INF = float('inf')
    best = [INF] * n; back = [None] * n
    best[n - 1] = 0
    for i in range(n - 2, -1, -1):
        own = -1 if is_named(cands[i]) or i == 0 else 1000
        for j in range(i + 1, n):
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

death_add = {}; death_alias = {}
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
objects = []   # (sec, a, size, nxt, da, dsize, dn, name)
for sec, start, end in stretches:
    objs = partition_data(start, end) if sec == '.data' else partition_sdata(start, end)
    dstarts = []
    for i, (a, size, nxt) in enumerate(objs):
        n = pick(a) if a in labels else 'D_%08X' % a
        if n in death_named and (not re.fullmatch(PLACE, n) or True) and not (re.fullmatch(r'D_[0-9A-F]{8}', n) and death_named[n] == a and i):
            dstarts.append(death_named[n])
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
    dend = dend_given.get((sec, start), dstarts[-1] + end - objs[-1][0])
    plan.append((sec, start, end, dstarts[0], dend, objs))
    pos = dstarts[0]
    for i, (a, size, nxt) in enumerate(objs):
        da = dstarts[i]; dn = dstarts[i + 1] if i + 1 < len(objs) else dend
        assert dn > da, 'Death Label order differs at %x' % a
        same = dn - da == nxt - a
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
obj_by_main = [(a, a + size, da - a, n) for sec, a, size, nxt, da, dsize, dn, n in objects]
def carray(n, raw, size):
    ctype = 'u16' if size % 2 == 0 else 'u8'
    count = size // 2 if size % 2 == 0 else size
    return ctype, count, '%s %s[%d] = {\n%s\n};\n' % (ctype, n, count, fmt(raw, size))
def main_target(x):
    sym, add = main_rel[x]
    if sym in defined:
        base = sym if kinds.get(sym) != 'record' else '&' + sym
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
            fields.append('void *p%d;' % k); vals.append(target(a + p)); p += 4
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
            if dta != ma + inside[0]: return False
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
    raw = rom[a - OFF:a - OFF + size]; draw = drom[da - OFF:da - OFF + dsize]
    if dn - da == nxt - a:
        assert not any(rom[a - OFF + size:nxt - OFF]) and not any(drom[da - OFF + size:dn - OFF]), 'padding not zero at %x' % a
    ms = [x for x in range(a, a + size - 3) if x in main_rel]; ds = [x for x in range(da, da + dsize - 3) if x in death_rel]
    if size == dsize:
        # a word that is a number in one executable and holds the same value in the other is a number in both
        ms2 = [x for x in ms if not ((x - a + da) not in death_rel and raw[x - a:x - a + 4] == draw[x - a:x - a + 4])]
        ds2 = [x for x in ds if not ((x - da + a) not in main_rel and raw[x - da:x - da + 4] == draw[x - da:x - da + 4])]
        for x in set(ms) - set(ms2): main_rel.pop(x)
        for x in set(ds) - set(ds2): death_rel.pop(x)
        ms, ds = ms2, ds2
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
    fields, vals = fields_of(a, size, raw, rel, target)
    if kind == 'table' and kinds[n] == 'array':
        return 'extern void *%s[%d];' % (n, len(fields)), 'void *%s[%d] = {\n%s\n};\n' % (n, len(fields), '\n'.join('    %s,' % v for v in vals))
    tname = ''.join(w.capitalize() for w in n.split('_')) + 'Record'
    return ('struct %s { %s };\nextern struct %s %s;' % (tname, ' '.join(fields), tname, n),
            'struct %s %s = {\n%s\n};\n' % (tname, n, '\n'.join('    %s,' % v for v in vals)))
for sec, a, size, nxt, da, dsize, dn, n in objects:
    raw, draw, ms, ds, mk, dk = info[n]
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
        assert q in defined or q in used or any(s_ <= qa < e_ for s_, e_, d_, _ in obj_by_main) or not re.fullmatch(r'D_[0-9A-F]{8}', q), \
            'unverified pointer %s in %s (differs from Death Label, nothing else uses the target)' % (q, n)
    for x in ds:
        q = death_rel[x][0]
        assert not (re.fullmatch(r'D_[0-9A-F]{8}', q) and int(q[2:], 16) >= 0x28FF00), 'unverified Death Label pointer %s in %s' % (q, n)
    dd, dt = one(n, da, dsize, draw, ds, dk, death_rel, death_target)
    decls.append(md if md == dd else '#ifdef DEATH_LABEL\n%s\n#else\n%s\n#endif' % (dd, md))
    defs.append((sec, '#ifdef DEATH_LABEL\n%s#else\n%s#endif\n' % (dt, mt)))
pointer_objs = [n for n in info if info[n][2] or info[n][3]]
# targets inside this file whose kind was decided late
total = sum(e - s for _, s, e in stretches)
print('%s: %d objects, %d bytes' % (name, len(defs), total))
if dry:
    for sec, start, end, ds_, de_, objs in plan:
        print(sec, '%x..%x' % (start, end), 'death %x..%x' % (ds_, de_), len(objs), 'objects', len(pointer_objs), 'with pointers')
    sys.exit()

yaml_out = {}
for t in ('SLPS_252.33', 'DEATH.ELF'):
    p = R / f'config/{t}/splat.yaml'; lines = p.read_text().split('\n')
    for sec, start, end, ds_, de_, objs in plan:
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
assert not path.exists(), path
head = '#include "common.h"\n\n'
if desc: head = '/* %s */\n' % desc + head
if pointer_objs:
    only = sorted(v for k, v in dexterns.items() if k not in externs)
    head += '\n'.join(sorted(externs.values())) + '\n' + ('#ifdef DEATH_LABEL\n%s\n#endif\n' % '\n'.join(only) if only else '') + '\n' + '\n'.join(decls) + '\n\n'
path.write_text(head + '\n'.join(d for _, d in defs))

# symbols: names now defined in C leave both files; labels inside objects that code uses stay as addresses
for t, named in (('SLPS_252.33', main_named), ('DEATH.ELF', death_named)):
    sp = R / f'config/{t}/symbols.txt'; out = []
    have = set()
    for l in open(sp):
        m = re.match(r'(\w+)\s*=\s*0x', l)
        if m and m.group(1) in defined and 'ignore:true' not in l: continue
        if m: have.add(m.group(1))
        out.append(l)
    text = ''.join(out)
    if not text.endswith('\n'): text += '\n'
    add = []
    for s_, e_, d_, n_o in obj_by_main:
        for a_ in sorted(labels):
            if s_ < a_ < e_:
                for n_ in labels[a_]:
                    if n_ in used and n_ not in have:
                        add.append('%s = 0x%x;\n' % (n_, a_ + (d_ if t == 'DEATH.ELF' else 0)))
    if t == 'DEATH.ELF':
        for n_, a_ in sorted(death_add.items()):
            if n_ not in defined and not re.search(r'^%s = ' % n_, text, re.M): add.append('%s = 0x%x;\n' % (n_, a_))
        ap = R / 'config/DEATH.ELF/aliases.txt'; at = ap.read_text()
        for n_, (a_, other) in sorted(death_alias.items()):
            if not re.search(r'^%s = ' % n_, at, re.M): at = at.rstrip('\n') + '\n%s = 0x%x; // alias of %s\n' % (n_, a_, other)
        ap.write_text(at)
    else:
        for n_ in sorted(set(death_add) | set(death_alias)):
            if n_ not in defined and n_ not in have and re.fullmatch(r'D_[0-9A-F]{8}', n_):
                add.append('%s = 0x%x;\n' % (n_, int(n_[2:], 16)))
    sp.write_text(text + ''.join(add))
    if add: print(t, 'kept', len(add), 'inside names as addresses')

for t in yaml_out:
    (R / f'config/{t}/splat.yaml').write_text(yaml_out[t])
print('wrote', path)
