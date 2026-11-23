"""Draft rewrite rules that help some functions and hurt others.

Every rule is `fix(code) -> code`. They are applied per function and kept only when the score improves
(`tools/autorules.py`, `tools/ruletest.py`). Rules that always help live in `tools/fixdraft.py` instead.
"""

import re

PTR = r"\(\(u8 \*\)\(\w+\) \+ \([0-9A-Fx]+\)\)"


def u32_temps(code):
    """`u16 temp_x` locals load with lh; u32 gives lhu."""
    return re.sub(r"^(    )u16( temp_\w+;)$", r"\1u32\2", code, flags=re.M)


def table_before_constant(code):
    """`reg_dN = K; reg_aM = D_x;` -> table load first (68k lea before moveq)."""
    pat = re.compile(r"\n(\s+)(reg_d\d\.(?:h\[0\]|w|b\[0\]) = (?:0x[0-9A-F]+|\d+);)\n\s+(reg_a\d = (?:\(u8 \*\))?\(?D_[0-9A-F]{8}\)?;)")
    code = pat.sub(lambda m: f"\n{m[1]}{m[3]}\n{m[1]}{m[2]}", code)
    return re.sub(r"(reg_d\d\.(?:h\[0\]|w|b\[0\]) = (?:0x[0-9A-F]+|\d+)), (reg_a\d = (?:\(u8 \*\))?\(?D_[0-9A-F]{8}\)?)([,;)])",
                  r"\2, \1\3", code)


def table_before_index(code):
    """`dN &= K; dN += dN; aM = D_x;` -> table load first."""
    pat = re.compile(r"\n(\s+)(reg_d(\d)\.h\[0\] &= [^;]+;)\n\s+(reg_d\3\.h\[0\] \+= reg_d\3\.h\[0\];)\n\s+(reg_a\d = (?:\(u8 \*\))?\(?D_[0-9A-F]+\)?;)")
    return pat.sub(lambda m: f"\n{m[1]}{m[5]}\n{m[1]}{m[2]}\n{m[1]}{m[4]}", code)


def index_before_table(code):
    """`aM = D_x; dN *= 2;` -> `dN += dN; aM = D_x;` (68k add.w before lea)."""
    pat = re.compile(r"\n(\s+)(reg_a\d = (?:\(u8 \*\))?\(?D_[0-9A-F]+\)?;)\n\s+(reg_d(\d)\.h\[0\]) \*= 2;")
    return pat.sub(lambda m: f"\n{m[1]}{m[3]} += {m[3]};\n{m[1]}{m[2]}", code)


def sort_address_loads(code):
    """Consecutive `reg_aN = D_x;` loads in ascending N."""
    line = re.compile(r"^(\s+)reg_a([0-6]) = [^;]*\bD_[0-9A-F]+\)?;$")
    lines, out, i = code.split("\n"), [], 0
    while i < len(lines):
        j = i
        while j < len(lines) and line.match(lines[j]):
            j += 1
        if j - i >= 2:
            out += sorted(lines[i:j], key=lambda l: line.match(l).group(2))
            i = j
        else:
            out.append(lines[i])
            i += 1
    return "\n".join(out)


def natural_save_order(code):
    """Register save/restore blocks (`D_x = reg_dN.w;` runs) in d0..d7, a0..a6 order."""
    save = re.compile(r"^(\s+)D_[0-9A-F]{8} = (?:\(u8 \*\)\()?reg_([da])(\d)(?:\.w)?\)?;$")
    rest = re.compile(r"^(\s+)reg_([da])(\d)(?:\.w)? = (?:\(u8 \*\)\()?D_[0-9A-F]{8}\)?;$")
    key = lambda m: (0 if m.group(2) == "d" else 1, int(m.group(3)))
    lines, out, i = code.split("\n"), [], 0
    while i < len(lines):
        for pat in (save, rest):
            j = i
            while j < len(lines) and pat.match(lines[j]):
                j += 1
            if j - i >= 3:
                out += sorted(lines[i:j], key=lambda l: key(pat.match(l)))
                i = j
                break
        else:
            out.append(lines[i])
            i += 1
    return "\n".join(out)


def sign_test_slt(code):
    """`if (x < 0)` -> `if (0 > x)` (slt at,v,zero instead of bgez)."""
    code = re.sub(r"if \(\(s8\) (reg_d\d)\.b\[0\] < 0\) \{", r"if (0 > \1.sb[0]) {", code)
    return re.sub(r"if \(([^()]+|\([^()]*\) [^()]+|\(s16\) \(\*\(u16 \*\)" + PTR + r"\)) < 0\) \{", r"if (0 > \1) {", code)


def u16_table_reads(code):
    """`(u8) D_x[i]` from a u16 table is a halfword read; widen the receiving variable."""
    for name in re.findall(r"^extern u16 (D_[0-9A-F]{8})\[\];$", code, flags=re.M):
        for var in re.findall(rf"(\w+) = \(u8\) {name}\[", code):
            code = re.sub(rf"^(    )u8 {var};$", rf"\1u16 {var};", code, flags=re.M)
        code = re.sub(rf"\(u8\) ({name}\[)", r"\1", code)
    return code


def halfword_store_of_byte(code):
    """`*(s16 *)p = (u8)x;` -> `*(u8 *)p = x;`."""
    return re.sub(rf"\(\*\(s16 \*\)({PTR})\) = \(u8\) ", r"(*(u8 *)\1) = ", code)


def reg32_scratch_global(code):
    """`D_0028E480`/`D_0028E482` written as halfwords and read as a word: a Reg32 union."""
    if "D_0028E482" not in code:
        return code
    code = re.sub(r"^extern \w+ D_0028E480;\n", "extern Reg32 D_0028E480;\n", code, flags=re.M)
    code = re.sub(r"^extern \w+ D_0028E482;\n", "", code, flags=re.M)
    code = re.sub(r"\bD_0028E482\b(?!\.)", "D_0028E480.h[1]", code)
    code = re.sub(r"\bD_0028E480 = ", "D_0028E480.h[0] = ", code)
    code = re.sub(r"\(u32\) D_0028E480\b(?!\.)", "D_0028E480.w", code)
    return code


def swap_register_compare(code):
    """`(s16) dA < (s16)(dB)` -> `(s16)(dB) > (s16) dA`: retail loads the right operand first (lh/lhu order)."""
    flip = {"<": ">", ">": "<", "<=": ">=", ">=": "<="}
    return re.sub(r"\(s16\) (reg_d\d\.h\[0\]) (<=|>=|<|>) \(s16\)\((reg_d\d\.h\[0\])\)",
                  lambda m: f"(s16)({m[3]}) {flip[m[2]]} (s16) {m[1]}", code)


def halve_typed_steps(code):
    """Undo old fixdraft scaling of `*(u16 *)reg_aN -= 2` (should be 1; u32: /4)."""
    size = {"u16": 2, "s16": 2, "u32": 4, "s32": 4}

    def repl(m):
        k, n = int(m[4], 0), size[m[2]]
        return m[0] if k % n else f"{m[1]}{m[3]}= {k // n};"
    return re.sub(r"(\*\((u16|s16|u32|s32) \*\)reg_a\d )([+-])= (\d+);", repl, code)


def compound_through_temp(code):
    """`t = X; X = t op K;` -> `X op= K;` (lhu/op/sh instead of a signed temp load)."""
    lv = r"(?:reg_d\d\.(?:h|b)\[[01]\]|\(\*\((?:u8|u16) \*\)\(\(u8 \*\)\(\w+\) \+ \([0-9A-Fx]+\)\)\))"
    return re.sub(rf"^(\s+)((?:temp|var)_\w+) = ({lv});\n\s+\3 = (?:\(u(?:8|16)\) )?\(?\2 (\+|-|\*|&|\||\^|<<|>>) ([^;]+?)\)?;$",
                  lambda m: f"{m[1]}{m[3]} {m[4]}= {m[5]};", code, flags=re.M)


def u16_stride(code):
    """Halfword reads through a pointer m2c typed `u32 *` (`*(u32 *)reg_aN; reg_aN += 8;`) step by 2."""
    for reg in set(re.findall(r"\*\(u32 \*\)(reg_a\d)\b", code)):
        if re.search(rf"\b{reg} \+= 8;", code):
            code = re.sub(rf"\*\(u32 \*\){reg}\b", f"*(u16 *){reg}", code)
            code = re.sub(rf"\b{reg} \+= 8;", f"{reg} += 2;", code)
    return code


def halfword_rmw(code):
    """`*(s16 *)p = (s16)((*(u16 *)p) op k);` -> `(*(u16 *)p) op= k;` (lhu/op/sh)."""
    return re.sub(rf"\(\*\((?:s16|u16) \*\)({PTR})\) = \((?:s16|u16)\) \(\(\*\((?:u16|s16) \*\)\1\) (\+|-|&|\||\^) ([^;]+)\);",
                  r"(*(u16 *)\1) \2= \3;", code)


def decls_by_register(code):
    """Order local declarations by the register in their m2c name (s0.. first); MWCC's allocator follows
    declaration order, and m2c sorts them by type instead."""
    decl = re.compile(r"^    [\w ]+?\**\s*((?:temp|var)_(\w+?)(?:_\d+)?);$")
    order = {"s": 0, "fp": 1, "v": 2, "a": 3, "t": 4}

    def key(name):
        m = re.match(r"(?:temp|var)_([a-z]+)(\d*)", name)
        return (order.get(m.group(1), 9), int(m.group(2) or 0), name) if m else (9, 0, name)
    lines, out, i = code.split("\n"), [], 0
    while i < len(lines):
        j = i
        while j < len(lines) and decl.match(lines[j]):
            j += 1
        if j - i >= 2:
            out += sorted(lines[i:j], key=lambda l: key(decl.match(l).group(1)))
            i = j
        else:
            out.append(lines[i])
            i += 1
    return "\n".join(out)


RULES = [
    u32_temps, table_before_constant, table_before_index, index_before_table, sort_address_loads,
    natural_save_order, sign_test_slt, u16_table_reads, halfword_store_of_byte, reg32_scratch_global,
    swap_register_compare, halve_typed_steps, compound_through_temp, u16_stride, halfword_rmw, decls_by_register,
]
