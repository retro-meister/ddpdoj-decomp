"""Mechanical clean-up of m2c drafts for large arcade-ported SLPS_252.33 functions.

Drafts each function with draft.draft_function, applies the rewrite rules in fix(),
writes build/big/<func>.fix.c and scores it with tools/diff.py.

    uv run tools/fixdraft.py func_00204A20 func_0015F290 [--jobs 4]

Every rule here has helped at least one match; none of them change semantics.
"""

import argparse
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
import re
import subprocess
import sys

from common import ROOT
from draft import draft_function

PS2_NATIVE_START = 0x212640

# One indexed 16-bit lookup (`reg + ((s16)(x + 2) & ~1)`, or `*reg` when x + 2 == 0) as m2c renders it.
LOOKUP = r"\(\(\(s64\) \(\2 << 0x30\) >> 0x30\) & ~1\)"
TERNARY_LOOKUP = re.compile(
    rf"^(\s*)(temp_\w+) = ([^;\n]+?) \+ 2;\n\s*([^\n=]+?) = \(\2 != 0\) \? \*\(\(?(?:\w+ \*\))?(reg_a\d) \+ {LOOKUP}\) : "
    r"(?:\(\*\(u16 \*\)\(\(u8 \*\)\(\5\) \+ \(0\)\)\)|\*\5);",
    re.M,
)
IF_LOOKUP = re.compile(
    rf"^(\s*)(temp_\w+) = ([^;\n]+?) \+ 2;\n\s*if \(\2 != 0\) \{{\n\s*(\w+) = \*\((\w+) \+ {LOOKUP}\);\n"
    r"\s*\} else \{\n\s*\4 = \*\(u16 \*\)\5;\n\s*\}\n",
    re.M,
)
# `a = x; ... b = a OP y; ... x = b;` with single-use temps -> `x OP= y;`
TRIPLE_TEMP = re.compile(
    r"^(\s*)(temp_\w+) = ([^;\n]+);\n((?:\1[^\n]*\n){0,3}?)\1(temp_\w+) = \2 ([+\-|&^]) ([^;\n]+);\n"
    r"((?:\1[^\n]*\n){0,3}?)\1\3 = \5;\n",
    re.M,
)


def lookup_expr(dest, index, reg):
    return f"{dest} = (({index} + 2) != 0) ? *(u16 *)((u8 *){reg} + ((s16)({index} + 2) & ~1)) : *(u16 *){reg};"


def uses(code, name):
    return len(re.findall(rf"\b{name}\b", code))


def fix_function_pointers(code):
    for name in re.findall(r"^extern \w+ \(\*(\w+)\)\(.*\);$", code, flags=re.M):
        if re.search(rf"^\s*{name}\(", code, flags=re.M):
            code = re.sub(rf"^extern \w+ \(\*{name}\)\(.*\);$", f"extern void (*{name})();", code, flags=re.M)
            code = re.sub(rf"^(\s*){name} = ([^;\n]+);$", rf"\1{name} = (Fn)(\2);", code, flags=re.M)
            code = re.sub(rf"^(\s*){name}\([^;\n]*\);", rf"\1{name}();", code, flags=re.M)
        else:
            code = re.sub(rf"^extern \w+ \(\*{name}\)\(.*\);$", f"extern u8 *{name};", code, flags=re.M)
    code = re.sub(r"^(?:extern )?\w+ (D_[0-9A-F]{8})\([^;\n]*\);", r"extern u8 \1[];", code, flags=re.M)
    code = re.sub(r"^(\s+)\w+ \(\*(\w+)\)\([^;\n]*\);", r"\1u8 *\2;", code, flags=re.M)
    code = re.sub(r"\(\w+ \(\*\)\([^()]*\)\)", "(u8 *)", code)
    code = re.sub(r"^(?:extern )?(\w+) (func_[0-9A-F]{8})\(.*\);$", r"\1 \2();", code, flags=re.M)
    code = re.sub(r"= (func_[0-9A-F]{8});", r"= (u8 *)\1;", code)
    # Calls through a table of code pointers: `*(TABLE + idx)(args);` -> `((Fn)*(u32 *)((u8 *)TABLE + idx))();`
    code = re.sub(
        r"^(\s*)\*\((\w+) \+ ([^;\n]+?)\)\([^;\n]*\);$",
        r"\1((Fn)*(u32 *)((u8 *)\2 + \3))();",
        code,
        flags=re.M,
    )
    # Indirect calls m2c casts to a data pointer: `((u8 *) x)(args);` -> `((Fn)x)();`
    code = re.sub(r"^(\s*)\(\(u8 \*\) (\w+)\)\([^;\n]*\);$", r"\1((Fn)\2)();", code, flags=re.M)
    return code


def fix_arrays(code):
    arrays = set(re.findall(r"^extern \w+ (D_[0-9A-F]{8})\[\];", code, flags=re.M))
    for name, sym in re.findall(r"^\s+(\w+) = (D_[0-9A-F]{8});$", code, flags=re.M):
        if sym in arrays:
            code = re.sub(rf"^    [us](?:8|16|32) {name};$", f"    u8 *{name};", code, flags=re.M)
    return code


def fix_address_registers(code):
    """Emulated address registers are byte pointers; scale m2c's typed arithmetic back to bytes."""
    code = re.sub(r"^extern [^;\n]*\(\*(reg_a[0-6])\)\([^;\n]*\);", r"extern u8 *\1;", code, flags=re.M)
    for rt, rn in re.findall(r"^extern ([us](?:16|32)) \*(reg_a[0-6]);$", code, flags=re.M):
        size = 2 if "16" in rt else 4
        code = re.sub(rf"^extern {rt} \*{rn};$", f"extern u8 *{rn};", code, flags=re.M)
        code = re.sub(rf"\b{rn} ([+-])= (\d+);", lambda m: f"{rn} {m[1]}= {int(m[2]) * size};", code)
        code = "\n".join(
            l if l.startswith("extern") else re.sub(rf"(?<![\w)])\*{rn}\b", f"*({rt} *){rn}", l) for l in code.split("\n")
        )
        code = re.sub(rf"^(\s*){rn} = \({rt} \*\)", rf"\1{rn} = (u8 *)", code, flags=re.M)
        code = re.sub(rf"^(\s*){rn} = (?!\(u8 \*\))([^;\n]+);$", rf"\1{rn} = (u8 *)(\2);", code, flags=re.M)
    return code


def fix_pointer_assignments(code):
    decls = dict((n, t) for t, n in re.findall(r"^    ((?:[us](?:8|16|32)|void) \*)(\w+);$", code, flags=re.M))
    for n, ty in decls.items():
        code = re.sub(rf"^(\s*){n} = (?!\({re.escape(ty)}\))([^;\n]+);$", rf"\1{n} = ({ty})(\2);", code, flags=re.M)
    for gt, gn in re.findall(r"^extern ([us](?:8|16|32)) \*(D_[0-9A-F]{8});$", code, flags=re.M):
        code = re.sub(rf"^(\s*){gn} = (?!\({gt} \*\))([^;\n]+);$", rf"\1{gn} = ({gt} *)(\2);", code, flags=re.M)
    return code


def fix_halfwords(code):
    # Compares on (s16) values: retail uses the `> N-1` branch form.
    code = "\n".join(
        re.sub(r">= (0x[0-9A-F]+)\)", lambda m: f"> 0x{int(m[1], 16) - 1:X})", l) if "(s16)" in l else l
        for l in code.split("\n")
    )
    code = re.sub(r"(\.h\[\d\] = )\(u16\) \(\*\(u8 \*\)", r"\1(*(u16 *)", code)
    code = re.sub(
        r"\(\*\(u8 \*\)(\(\(u8 \*\)\(\w+\) \+ \(\w+\)\))\) = \(s16\) \(\(u16\) \(\*\(u8 \*\)\1\) & (0x[0-9A-F]+)\);",
        r"(*(u16 *)\1) &= \2;",
        code,
    )
    code = re.sub(r"\(u16\) \(\*\(s16 \*\)\(\(u8 \*\)\(([^)]+)\) \+ \(([^)]+)\)\)\)", r"(*(u16 *)((u8 *)(\1) + (\2)))", code)
    code = re.sub(r"\(\*\(s16 \*\)(\([^;=]+\))\) = (0x[89A-F][0-9A-F]{3});", r"(*(u16 *)\1) = \2;", code)
    # Byte stores m2c typed from a halfword load, or of a constant wider than a byte, are halfword stores.
    code = re.sub(r"\(\*\(u8 \*\)(\([^;=]+\))\) = \(u16\) (\*\(u16 \*\)[^;\n]+);", r"(*(u16 *)\1) = \2;", code)
    code = re.sub(
        r"\(\*\(u8 \*\)(\([^;=]+\))\) = (0x[0-9A-F]{3,4});",
        lambda m: f"(*(u16 *){m[1]}) = {m[2]};" if int(m[2], 16) > 0xFF else m[0],
        code,
    )
    return code


def fix_arithmetic(code):
    code = re.sub(r"^(\s*)([^=\n]+?) = \2 \+ (0x7FFF \+ 0x[0-9A-F]+);", r"\1\2 += \3;", code, flags=re.M)
    for tmp in re.findall(r"^\s*\S[^\n=]* = (temp_\w+) \+ 0x7FFF \+ 0x[0-9A-F]+;", code, flags=re.M):
        code = re.sub(rf"^    [us]\d+ {tmp};$", f"    u16 {tmp};", code, flags=re.M)
        code = re.sub(rf"= {tmp} \+ 0x7FFF \+", f"= (u32){tmp} + 0x7FFF +", code)
    for tmp in set(re.findall(r"^\s*((?:temp|var)_\w+) = reg_d\d\.h\[\d\];", code, flags=re.M)):
        code = re.sub(rf"(\.h\[\d\] = ){tmp} \+ (0x[0-9A-F]+);", rf"\1(u32){tmp} + \2;", code)
    code = re.sub(r"^(\s*(?:temp|var)_\w+ = )(reg_d\d\.h\[\d\]) \+ (0x[0-9A-F]+);", r"\1(u32)\2 + \3;", code, flags=re.M)
    # `t = x; x = t OP y;` -> `x OP= y;`
    code = re.sub(
        r"^(\s*)(temp_\w+) = ([^;\n]+);\n\1\3 = \2 ([+\-|&^]) ([^;\n]+);\n",
        lambda m: f"{m[1]}{m[3]} {m[4]}= {m[5]};\n" if uses(code, m[2]) == 3 else m[0],
        code,
        flags=re.M,
    )
    for _ in range(40):
        m = TRIPLE_TEMP.search(code)
        if not m:
            break
        a, b = m[2], m[5]
        if uses(code, a) != 3 or uses(code, b) != 3 or re.search(rf"\b{re.escape(m[3])}\b", m[4] + m[8]):
            break
        code = code[: m.start()] + m[4] + f"{m[1]}{m[3]} {m[6]}= {m[7]};\n" + m[8] + code[m.end() :]
    for t in re.findall(r"^\s*(temp_\w+) = [^;\n]+ & 0xFFFF;$", code, flags=re.M):
        code = re.sub(rf"^(\s*)s32 {t};$", rf"\1u16 {t};", code, flags=re.M)
    return code


def fix_globals(code):
    if re.search(r"^extern s32 D_0028E484;$", code, flags=re.M) and "D_0028E486" not in code:
        code = code.replace("extern s32 D_0028E484;", "extern Reg32 D_0028E484;")
        code = re.sub(r"\bD_0028E484 = 0;", "D_0028E484.w = 0;", code)
        code = re.sub(r"\bD_0028E484 = (0x[0-9A-F]+|\d+);", r"D_0028E484.h[0] = \1;", code)
        code = re.sub(r"\(u16\) D_0028E484\b", "D_0028E484.h[0]", code)
        code = re.sub(r"(?<![.\w])D_0028E484\b(?![.\w\[])", "D_0028E484.w", code)
        code = code.replace("extern Reg32 D_0028E484.w;", "extern Reg32 D_0028E484;")
    code = re.sub(r"^extern u8 D_0028E408;$", "extern s8 D_0028E408;", code, flags=re.M)
    return code


def fix_u8_register_halfwords(code):
    u8regs = set(re.findall(r"^extern u8 \*(reg_a[0-6]);$", code, flags=re.M))
    for r in u8regs:
        code = re.sub(rf"^(\s*)\*{r} = \((u16|s16)\) ", rf"\1*(\2 *){r} = ", code, flags=re.M)

    def h16(line):
        if not re.search(r"(\*\(u16 \*\)|\*\(s16 \*\)|\.h\[\d\]|\(u16\))[^=]*=", line) and "? *(u16 *)" not in line:
            return line
        for r in u8regs:
            line = re.sub(rf"(?<![\w)])\*{r}\b(?!\s*\+)", f"*(u16 *){r}", line)
        return line

    return "\n".join(l if l.startswith("extern") else h16(l) for l in code.split("\n"))


def fix_lookups(code):
    pat = re.compile(
        rf"^(\s*)(temp_\w+) = (reg_d\d)\.h\[0\] \+ 2;\n\s*\3\.h\[0\] = \(\2 != 0\) \? \*\(reg_a(\d) \+ {LOOKUP}\) : "
        r"\(\*\(u16 \*\)\(\(u8 \*\)\(reg_a\4\) \+ \(0\)\)\);",
        re.M,
    )
    code = pat.sub(lambda m: m[1] + lookup_expr(f"{m[3]}.h[0]", f"{m[3]}.h[0]", f"reg_a{m[4]}"), code)
    code = TERNARY_LOOKUP.sub(lambda m: m[1] + lookup_expr(m[4], m[3], m[5]), code)
    return code


def fix_integer_derefs(code):
    """m2c sometimes types a local as an integer and then dereferences it; make it a byte pointer."""
    for ty, name in re.findall(r"^    ([us](?:8|16|32)) ((?:var|temp)_\w+);$", code, flags=re.M):
        if re.search(rf"(?<![\w)])\*{name}\b", code):
            code = re.sub(rf"^    {ty} {name};$", f"    u8 *{name};", code, flags=re.M)
    return code


POINTER_RHS = re.compile(r"^(?:\((?:u16|s16|u32|s32)\) )?(\(?reg_a\d\b[^;]*|\(u8 \*\)[^;]+|&\w+)$")


def split_pointer_locals(code):
    """m2c merges an integer and a pointer that shared a register into one integer local.

    From each pointer-valued assignment until the next reassignment, use a separate `u8 *` local instead.
    """
    for ty, name in re.findall(r"^    ([us](?:8|16|32)) ((?:var|temp)_\w+);$", code, flags=re.M):
        if not re.search(rf"(?<![\w)])\*{name}\b", code):
            continue
        ptr = f"{name}_p"
        lines, active = code.split("\n"), False
        for i, line in enumerate(lines):
            m = re.match(rf"^(\s*){name} = ([^;\n]+);$", line)
            if m:
                pm = POINTER_RHS.match(m[2])
                active = bool(pm)
                if active:
                    lines[i] = f"{m[1]}{ptr} = (u8 *)({pm[1]});"
                    continue
            if active:
                lines[i] = re.sub(rf"\b{name}\b", ptr, line)
        new = "\n".join(lines)
        if ptr in new:
            code = re.sub(rf"^(    {ty} {name};)$", rf"\1\n    u8 *{ptr};", new, count=1, flags=re.M)
    # The reverse: a pointer local loaded with a halfword value and compared as an integer.
    for name in re.findall(r"^    u8 \*((?:var|temp)_\w+);$", code, flags=re.M):
        half = f"{name}_h"
        lines, active = code.split("\n"), False
        for i, line in enumerate(lines):
            m = re.match(rf"^(\s*){name} = ([^;\n]+);$", line)
            if m:
                hm = re.match(r"^\(u8 \*\) (\(\*\(u16 \*\)[^;]+\)|reg_d\d\.h\[\d\])$", m[2])
                active = bool(hm)
                if active:
                    lines[i] = f"{m[1]}{half} = {hm[1]};"
                    continue
            if active:
                lines[i] = re.sub(rf"\b{name}\b", half, line)
        new = "\n".join(lines)
        if half in new:
            code = re.sub(rf"^(    u8 \*{name};)$", rf"\1\n    u16 {half};", new, count=1, flags=re.M)
    return code


def fix_stray_cases(code):
    """m2c can emit `case N:` after its switch has closed; make it a label the switch jumps to."""
    lines, stack, last_switch, out_adds = code.split("\n"), [], None, {}
    for i, line in enumerate(lines):
        s = line.strip()
        m = re.match(r"case (\w+):$", s)
        if m and "switch" not in stack:
            label = f"case_{m[1]}"
            lines[i] = line.replace(s, f"{label}:")
            if last_switch is not None:
                out_adds.setdefault(last_switch, []).append(f"case {m[1]}: goto {label};")
        for _ in range(s.count("}")):
            if stack:
                stack.pop()
        if s.endswith("{"):
            stack.append("switch" if s.startswith("switch") else "block")
            if s.startswith("switch"):
                last_switch = i
    for i in sorted(out_adds, reverse=True):
        indent = re.match(r"\s*", lines[i])[0]
        lines[i + 1 : i + 1] = [f"{indent}{a}" for a in out_adds[i]]
    return "\n".join(lines)


def fix_address_register_assignments(code):
    """Address registers hold pointers: type them as byte pointers and cast where they meet other types."""
    code = re.sub(r"^extern [us](?:8|16|32) (reg_a[0-6]);$", r"extern u8 *\1;", code, flags=re.M)
    decls = {name: ty.strip() for ty, name in re.findall(r"^extern ([\w ]+?\s*\**)\s*((?:D|jtbl)_[0-9A-F]{8});$", code, flags=re.M)}
    def cast_global(m):
        ty = decls.get(m[2])
        return f"{m[1]}{m[2]} = ({ty}){m[3]};" if ty and ty != "u8 *" else m[0]
    code = re.sub(r"^(\s*)((?:D|jtbl)_[0-9A-F]{8}) = (reg_a[0-6]);$", cast_global, code, flags=re.M)
    code = re.sub(r"^(\s*reg_(?:d\d|tmp)\.w = )(reg_a[0-6]);$", r"\1(u32)\2;", code, flags=re.M)
    code = re.sub(r"^(\s*reg_a[0-6] = )\*\((&?\w+) \+ ([^;\n]+)\);$", r"\1*(u8 **)((u8 *)\2 + \3);", code, flags=re.M)
    code = re.sub(r"^(\s*reg_a[0-6] = )\*(reg_a[0-6]);$", r"\1*(u8 **)\2;", code, flags=re.M)
    code = re.sub(r"^(\s*reg_a[0-6] = )(reg_(?:d\d|tmp)\.w);$", r"\1(u8 *)\2;", code, flags=re.M)
    scalars = {n for t, n in re.findall(r"^extern ([us](?:8|16|32)) ((?:D|jtbl)_[0-9A-F]{8});$", code, flags=re.M)}
    code = re.sub(r"^(\s*reg_a[0-6] = )((?:D|jtbl)_[0-9A-F]{8});$",
                  lambda m: f"{m[1]}(u8 *){m[2]};" if m[2] in scalars else m[0], code, flags=re.M)
    locals_ = {n: t for t, n in re.findall(r"^    ([us](?:8|16|32)) (\w+);$", code, flags=re.M)}
    code = re.sub(r"^(\s*reg_a[0-6] = )((?:temp|var)_\w+|sp[0-9A-F]+);$",
                  lambda m: f"{m[1]}(u8 *){m[2]};" if m[2] in locals_ else m[0], code, flags=re.M)
    code = re.sub(r"^(\s*)((?:temp|var)_\w+|sp[0-9A-F]+) = (reg_a[0-6]);$",
                  lambda m: f"{m[1]}{m[2]} = ({locals_[m[2]]}){m[3]};" if m[2] in locals_ else m[0], code, flags=re.M)
    return code


def fix_pointer_globals(code):
    """Integer globals assigned an address register hold pointers."""
    for ty, name in re.findall(r"^extern ([us](?:8|16|32)) ((?:D|jtbl)_[0-9A-F]{8});$", code, flags=re.M):
        if re.search(rf"^\s*{name} = reg_a\d;$", code, flags=re.M):
            code = re.sub(rf"^extern {ty} {name};$", f"extern u8 *{name};", code, flags=re.M)
    return code


def fix_byte_patterns(code):
    """m2c byte/pointer-width artifacts that are always safe to rewrite."""
    # Byte RMW through a halfword pointer: (*(u16 *)p) = (s8) ((u8) (*(u16 *)p) op x)  ->  (*(u8 *)p) op= x
    ptr = r"\(\(u8 \*\)\(\w+\) \+ \([0-9A-Fx]+\)\)"
    code = re.sub(
        rf"\(\*\(u16 \*\)({ptr})\) = \(s8\) \(\(u8\) \(\*\(u16 \*\)\1\) (\+|-|&|\||\^) ([^;]+)\);",
        r"(*(u8 *)\1) \2= \3;", code,
    )
    # (u8)(*(s16 *)p): little-endian low byte of a halfword is a plain byte load (lbu, not lb).
    code = re.sub(
        r"\(u8\) \(\*\([su]16 \*\)(\(\(u8 \*\)\([\w]+\) \+ \([0-9A-Fx]+\)\))\)", r"(*(u8 *)\1)", code,
    )
    # (u8 *)(*(TABLE + i)) on a u8[] table reads a whole pointer: *(u8 **)(TABLE + i) (lw, not lbu).
    out, i = [], 0
    pat = re.compile(r"\(u8 \*\)\(\*\((D_[0-9A-F]{8}) \+ ")
    while (m := pat.search(code, i)):
        j, depth = m.end(), 2
        while depth and j < len(code):
            depth += (code[j] == "(") - (code[j] == ")")
            j += 1
        out.append(code[i:m.start()] + f"*(u8 **)({m[1]} + {code[m.end():j - 2]})")
        i = j
    code = "".join(out) + code[i:]
    # Byte negation: m2c prints *= -1 on a u8 as *= 0xFF (retail li -1; mult).
    code = re.sub(r"(\.b\[\d\]|\(\*\(u8 \*\)[^;=\n]+\)) \*= 0xFF;", r"\1 *= -1;", code)
    return code


def fix_branch_byte_adds(code):
    """m2c merges per-branch `addq.b #k,dN` into `var_v0 = d + k; goto L; ... L: d = var_v0; goto M;`.
    Retail does lbu/addiu/sb in every branch, so give each branch its own `d += k; goto M;`."""
    m = re.search(r"\nblock_(\d+):\n\s+reg_d\d\.b\[0\] = var_v0;\n\s+goto (block_\d+);\n", code)
    if not m:
        return code
    label, target = m.group(1), m.group(2)
    new = code.replace(m.group(0), "\n")
    new = re.sub(rf"var_v0 = (reg_d\d\.b\[0\]) \+ (0x[0-9A-F]+|\d+);\n(\s+)goto block_{label};", rf"\1 += \2;\n\3goto {target};", new)
    new = re.sub(r"var_v0 = (reg_d\d\.b\[0\]) \+ (0x[0-9A-F]+|\d+);\n(\s+)", rf"\1 += \2;\n\3goto {target};\n\3", new)
    if "var_v0" in new.replace("u8 var_v0;", ""):
        return code
    return re.sub(r"\n\s+u8 var_v0;\n", "\n", new)


def fix_wide_constant_adds(code):
    """m2c sinks `reg_dN.w += 0xXXXXXXXX;` below unrelated stores; the 68k `addi.l` follows the dN load directly,
    and that order decides which register gets the lui/ori constant. Move it back up to the last write of dN."""
    add = re.compile(r"^(\s+)reg_d(\d)\.w (\+|-)= 0x[0-9A-F]{8};$")
    lines = code.split("\n")
    for i in range(len(lines)):
        m = add.match(lines[i])
        if not m:
            continue
        reg, j = f"reg_d{m.group(2)}", i - 1
        while j >= 0 and lines[j].startswith(m.group(1) + "r") and lines[j].endswith(";") and reg not in lines[j] \
                and not re.search(r"\w+\(", lines[j]):
            j -= 1
        if j < i - 1 and j >= 0 and re.search(rf"{reg}\.(h\[[01]\]|w|b\[0\]) = ", lines[j]):
            lines.insert(j + 1, lines.pop(i))
    return "\n".join(lines)


def fix(code):
    code = fix_function_pointers(code)
    code = fix_arrays(code)
    code = re.sub(r"^(\s*)(func_([0-9A-F]{8}))\([^;\n]*\);", lambda m: f"{m[1]}{m[2]}();" if int(m[3], 16) < PS2_NATIVE_START else m[0], code, flags=re.M)
    code = fix_lookups(code)
    code = fix_halfwords(code)
    code = fix_address_registers(code)
    code = fix_pointer_assignments(code)
    code = fix_arithmetic(code)
    code = fix_globals(code)
    code = fix_u8_register_halfwords(code)
    code = TERNARY_LOOKUP.sub(lambda m: m[1] + lookup_expr(m[4], m[3], m[5]), code)
    code = IF_LOOKUP.sub(lambda m: m[1] + lookup_expr(m[4], m[3], m[5]) + "\n", code)
    code = split_pointer_locals(code)
    code = fix_integer_derefs(code)
    code = fix_byte_patterns(code)
    code = fix_branch_byte_adds(code)
    code = fix_wide_constant_adds(code)
    code = fix_stray_cases(code)
    code = fix_pointer_globals(code)
    code = fix_address_register_assignments(code)
    code = re.sub(r"\bNULL\b", "0", code)
    header = '#include "common.h"\n'
    # mpwc_relax permits implicit pointer conversions (common inside m2c comma expressions); it does not affect codegen.
    extra = "\n#pragma mpwc_relax on\n"
    if "(Fn)" in code:
        extra += "\ntypedef void (*Fn)();\n"
    return code.replace(header, header + extra, 1)


def score(target, name, out_dir, m2c_args=()):
    try:
        code = fix(draft_function(target, name, relax_protos=True, m2c_args=m2c_args))
    except Exception as error:  # noqa: BLE001 - report and keep going
        return name, "draft_fail", str(error)[-150:]
    path = out_dir / f"{name}.fix.c"
    path.write_text(code, encoding="utf-8")
    result = subprocess.run(
        [sys.executable, str(ROOT / "tools/diff.py"), target, name, "--source", str(path), "--compact"],
        capture_output=True,
        text=True,
        cwd=ROOT,
    )
    out = result.stdout + result.stderr
    if f"MATCH  {target}" in out:
        return name, "MATCH", ""
    m = re.search(r"DIFFERENT\s+\S+\s+([0-9.]+)%", out)
    if m:
        return name, m[1], ""
    lines = out.splitlines()
    errors = [lines[i - 1].strip()[:110] + " :: " + (lines[i + 1].strip() if i + 1 < len(lines) else "") for i, l in enumerate(lines) if "Error:" in l and i >= 1]
    return name, "compile_fail", " || ".join(errors[:2])


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("functions", nargs="+")
    parser.add_argument("--target", default="SLPS_252.33")
    parser.add_argument("--jobs", type=int, default=4)
    parser.add_argument("--out", type=Path, default=ROOT / "build/big")
    parser.add_argument("--m2c-arg", action="append", default=[], help="extra m2c flag, e.g. --m2c-arg=--no-andor")
    args = parser.parse_args()
    args.out.mkdir(parents=True, exist_ok=True)
    with ThreadPoolExecutor(args.jobs) as pool:
        for name, status, detail in pool.map(lambda n: score(args.target, n, args.out, args.m2c_arg), args.functions):
            print(name, status, detail, flush=True)


if __name__ == "__main__":
    main()
