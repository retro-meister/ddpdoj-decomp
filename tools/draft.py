import argparse
from pathlib import Path
import re
import struct
import subprocess
import sys
from tempfile import TemporaryDirectory

from common import BASEROM, ROOT, TARGETS
from split import split, target_layout


COMMON_SYMS = frozenset({
    "reg_d0", "reg_d1", "reg_d2", "reg_d3", "reg_d4", "reg_d5", "reg_d6", "reg_d7",
    "reg_tmp", "rng_cursor", "rng_values",
    "D_0028E4AA", "D_0028E4A6", "D_0028E4A2", "D_0028E49E",
    "D_0028E49A", "D_0028E496", "D_0028E492", "D_0028E48E", "D_0028E48A",
})
REG_HI16_MAP = {
    "D_0028E4AA": "reg_d0.h[1]",
    "D_0028E4A6": "reg_d1.h[1]",
    "D_0028E4A2": "reg_d2.h[1]",
    "D_0028E49E": "reg_d3.h[1]",
    "D_0028E49A": "reg_d4.h[1]",
    "D_0028E496": "reg_d5.h[1]",
    "D_0028E492": "reg_d6.h[1]",
    "D_0028E48E": "reg_d7.h[1]",
    "D_0028E48A": "reg_tmp.h[1]",
}
HI_SYM_RE = re.compile(r"%hi\((D_[0-9A-Fa-f]{8})\)")
EXTERN_SCALAR_RE = re.compile(r"^(extern\s+[^;]*?)\b(D_[0-9A-Fa-f]{8})\s*;\s*$", re.M)
EXTERN_FUNC_RE = re.compile(r"^extern\s+(?:s32|u32|int|M2C_UNK|\?\s*)\s+(func_[0-9A-Fa-f]{8})\s*;\s*$", re.M)
PROTO_RE = re.compile(
    r"^((?:extern\s+)?[A-Za-z_][A-Za-z0-9_\s\*]*?\b(?:func_[0-9A-Fa-f]{8}|[a-z][a-z0-9_]+))\([^)]*\);\s*$",
    re.M,
)
M2C_FIELD_RE = re.compile(r"M2C_FIELD\(([^,]+),\s*([^,]+),\s*([^)]+)\)")
ORI_HI16_RE = re.compile(r"\bori\s+\$\w+,\s*\$zero,\s*0x[89a-fA-F][0-9a-fA-F]{3}\b")
ADDIU_HI8_RE = re.compile(r"\baddiu\s+\$\w+,\s*\$zero,\s*0x[89a-fA-F][0-9a-fA-F]\b")
COMPOUND_CAST_RE = re.compile(
    r"^(\s*)([^\n;=]+?)\s*=\s*\((?:u8|u16|s8|s16)\)\s*\(\2\s*([+\-*|&^])\s*([^\n;]+)\)\s*;\s*$",
    re.M,
)
COMPOUND_SHIFT_RE = re.compile(
    r"^(\s*)([^\n;=]+?)\s*=\s*\((?:u8|u16)\)\s*\(\((?:u8|u16)\)\s*\2\s*(>>|<<)\s*([^\n;]+)\)\s*;\s*$",
    re.M,
)
COMPOUND_PLAIN_RE = re.compile(
    r"^(\s*)(\(\*\((?:u8|u16) \*\)\([^\n;=]+\)\))\s*=\s*\2\s*([+\-*|&^])\s*([^\n;]+)\s*;\s*$",
    re.M,
)
MUL2_RE = re.compile(r"^(\s*)([^\n;=]+?)\s*\*=\s*2\s*;\s*$", re.M)
TAIL_JUMP_RE = re.compile(
    r"^([ \t]*/\*[^*]*\*/[ \t]+j[ \t]+[^\n]+\n)([ \t]*/\*[^*]*\*/[ \t]+(?!nop\b)[^\n]+\n)",
    re.M,
)
JTBL_REF_RE = re.compile(r"%(?:hi|lo)\(jtbl_([0-9A-Fa-f]{8})\)")
INSN_ADDR_RE = re.compile(r"^[ \t]*/\*\s*[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\s+[0-9A-Fa-f]{8}\s*\*/", re.M)


def _strip_preprocessor(text):
    return "\n".join(line for line in text.splitlines() if not line.lstrip().startswith("#")) + "\n"


# Types m2c cannot infer well on its own. Only m2c sees these; matched sources keep their own declarations.
# Do not add the address registers (reg_aN): m2c's per-function guess (u16 *, s16 *) carries the access width,
# and a u8 * declaration turns halfword loads into byte loads.
M2C_PROJECT_CONTEXT = """
extern s8 D_0028E408;
"""


def build_m2c_context(dest_path):
    """Write a pycparser-friendly context header inlining include/types.h and include/common.h."""
    types_h = _strip_preprocessor((ROOT / "include/types.h").read_text(encoding="utf-8"))
    common_h = _strip_preprocessor((ROOT / "include/common.h").read_text(encoding="utf-8"))
    dest_path.write_text(types_h + "\n" + common_h + M2C_PROJECT_CONTEXT, encoding="utf-8")
    return dest_path


def clean_m2c(raw_code, asm_chunk="", relax_protos=False):
    """Apply MWCCPS2 + DDPDOJ post-processing rules to raw m2c output."""
    code = re.sub(r"\s*/\*\s*extern\s*\*/", "", raw_code)

    out_lines = []
    for line in code.splitlines():
        if line.strip().startswith("extern ") and any(re.search(rf"\b{sym}\b", line) for sym in COMMON_SYMS):
            continue
        out_lines.append(line)
    code = "\n".join(out_lines) + "\n"

    for hi_sym, reg_expr in REG_HI16_MAP.items():
        if hi_sym in code:
            code = re.sub(rf"\b{hi_sym}\b", reg_expr, code)

    # Alias D_0028E484 / D_0028E486 (68k swap scratch Reg32) so MWCCPS2 respects aliasing
    if "D_0028E484" in code and "D_0028E486" in code:
        code = re.sub(r"^extern\s+\w+\s+D_0028E484\s*;\s*$", "extern Reg32 D_0028E484;", code, flags=re.M)
        code = re.sub(r"^extern\s+\w+\s+D_0028E486\s*;\s*\n?", "", code, flags=re.M)
        code = re.sub(r"\(\s*u16\s*\)\s*D_0028E484\b", "D_0028E484.h[0]", code)
        code = re.sub(r"\bD_0028E486\b", "D_0028E484.h[1]", code)
        code = re.sub(r"(?<!Reg32 )\bD_0028E484\b(?!\.)", "D_0028E484.w", code)

    # 68k dbra loop idiom: temp = reg_dN.h[0] - 1; reg_dN.h[0] = temp; ... while (((s64)((temp & 0xFFFF) << 0x30) >> 0x30) >= 0);
    for dm in list(re.finditer(
        r"([ \t]*)(temp_\w+)\s*=\s*(reg_d[0-7]\.h\[0\])\s*-\s*1;\n\1\3\s*=\s*\2;\n((?:.*?\n){0,4})([ \t]*)\}\s*while\s*\(\(\(s64\)\s*\(\(\2\s*&\s*0xFFFF\)\s*<<\s*0x30\)\s*>>\s*0x30\)\s*>=\s*0\);",
        code,
    )):
        tvar, reg_expr, mid, ind = dm.group(2), dm.group(3), dm.group(4), dm.group(5)
        if not re.search(rf"\b{tvar}\b", mid):
            code = code.replace(dm.group(0), f"{mid}{ind}}} while ((s16)(--{reg_expr}) >= 0);", 1)
            code = re.sub(rf"^[ \t]*u16\s+{tvar}\s*;\s*\n", "", code, flags=re.M)

    # 68k indexed word table lookup: *(reg_aN + (((s64) ((s64) X << 0x30) >> 0x30) & ~1))
    if "((s64) ((s64) " in code and "& ~1)" in code:
        idx_re = re.compile(
            r"\*\((reg_a[0-6])\s*\+\s*\(\(\(s64\)\s*\(\(s64\)\s*([^<]+?)\s*<<\s*0x30\)\s*>>\s*0x30\)\s*&\s*~1\)\)"
        )
        code = idx_re.sub(r"*(u16 *)((u8 *)\1 + ((s16)\2 & ~1))", code)
        # Collapse simple if (cond) { var = A; } else { var = B; } DST = var; into ternary
        tern_re = re.compile(
            r"([ \t]*)if\s*\(([^\n]+)\)\s*\{\n[ \t]*(var_\w+)\s*=\s*([^;]+);\n\1\}\s*else\s*\{\n[ \t]*\3\s*=\s*([^;]+);\n\1\}\n\1([^\n;=]+?)\s*=\s*\3;",
        )
        for tm in list(tern_re.finditer(code)):
            ind, cond, vname, a_expr, b_expr, dst = tm.groups()
            code = code.replace(tm.group(0), f"{ind}{dst} = ({cond}) ? {a_expr} : {b_expr};", 1)
            code = re.sub(rf"^[ \t]*[us](?:8|16|32)\s+{vname}\s*;\s*\n", "", code, flags=re.M)

    # RNG byte-increment idiom: lbu %gp_rel(rng_cursor) -> *(u8 *)&rng_cursor += 1
    if asm_chunk and re.search(r"\blbu\s+\$\w+,\s*%gp_rel\(rng_cursor\)", asm_chunk):
        code = re.sub(r"\brng_cursor\s*\+=\s*1\s*;", "*(u8 *)&rng_cursor += 1;", code)
        if re.search(r"\blb\s+\$\w+,\s*0x0\(\$\w+\)", asm_chunk):
            code = re.sub(r"^(extern\s+)u8(\s+D_00266[0-9A-Fa-f]{3}(?:\[\])?)", r"\1s8\2", code, flags=re.M)

    # Treat unknown pointers as byte pointers (u8 *) to avoid unintended *4 scaling
    code = re.sub(r"\bM2C_UNK\s*\*", "u8 *", code)
    code = re.sub(r"\bextern\s+M2C_UNK\s+(D_[0-9A-Fa-f]{8})\s*;", r"extern u8 \1;", code)

    func_syms = set(EXTERN_FUNC_RE.findall(code))
    if func_syms:
        code = EXTERN_FUNC_RE.sub(r"extern void \1();", code)
        for fsym in func_syms:
            code = re.sub(rf"&{fsym}\b", f"(void *){fsym}", code)

    code = re.sub(r"\bM2C_UNK\b", "s32", code)

    if asm_chunk:
        if ORI_HI16_RE.search(asm_chunk):
            code = re.sub(r"^(extern\s+)s16(\s+D_[0-9A-Fa-f]{8})", r"\1u16\2", code, flags=re.M)
        if ADDIU_HI8_RE.search(asm_chunk):
            code = re.sub(r"^(extern\s+)s8(\s+D_[0-9A-Fa-f]{8})", r"\1u8\2", code, flags=re.M)
            code = re.sub(r"=\s*-1;", "= 0xFF;", code)

    while "M2C_FIELD(" in code:
        new_code = M2C_FIELD_RE.sub(r"(*(\2)((u8 *)(\1) + (\3)))", code)
        if new_code == code:
            break
        code = new_code

    # Compound assignments trigger lbu/lhu and srl instead of lb/lh and sra in MWCCPS2
    code = COMPOUND_CAST_RE.sub(r"\1\2 \3= \4;", code)
    code = COMPOUND_SHIFT_RE.sub(r"\1\2 \3= \4;", code)
    code = COMPOUND_PLAIN_RE.sub(r"\1\2 \3= \4;", code)

    if asm_chunk and re.search(r"\baddu\s+(\$\w+),\s*\1,\s*\1\b", asm_chunk):
        code = MUL2_RE.sub(r"\1\2 += \2;", code)

    # Convert %hi(D_XXXXXXXX) scalar externs to arrays so MWCCPS2 emits lui/addiu instead of %gp_rel
    if asm_chunk:
        hi_syms = set(HI_SYM_RE.findall(asm_chunk)) - COMMON_SYMS
        if hi_syms:
            converted = set()

            def repl_ext(m):
                prefix, sym = m.group(1), m.group(2)
                if sym in hi_syms and "[" not in prefix:
                    converted.add(sym)
                    return f"{prefix}{sym}[];"
                return m.group(0)

            code = EXTERN_SCALAR_RE.sub(repl_ext, code)
            if converted:
                lines2 = []
                for line in code.splitlines():
                    if line.lstrip().startswith("extern "):
                        lines2.append(line)
                    else:
                        for sym in converted:
                            line = re.sub(rf"(?<!&)\b{sym}\b(?!\s*\[)", f"{sym}[0]", line)
                            line = re.sub(rf"&{sym}\b", sym, line)
                        lines2.append(line)
                code = "\n".join(lines2) + "\n"

    code = re.sub(r"\bvoid\s*\*\s*(reg_a[0-6]|arg\d+|temp_\w+|var_\w+)\b", r"u8 *\1", code)

    for m in list(re.finditer(r"^extern\s+(u32|s32)\s+(reg_a[0-6])\s*;$", code, re.M)):
        t, rn = m.group(1), m.group(2)
        if re.search(rf"\*{rn}\b", code):
            code = re.sub(rf"^extern\s+{t}\s+{rn}\s*;$", f"extern {t} *{rn};", code, flags=re.M)
            code = re.sub(rf"^(\s*){rn}\s*=\s*([^;]+);$", rf"\1{rn} = ({t} *)(\2);", code, flags=re.M)

    reg_types = {
        rname: rtype
        for rtype, rname in re.findall(r"extern\s+([us](?:8|16|32)\s*\*)\s*(reg_a[0-6])\s*;", code)
    }
    for rname, rtype in reg_types.items():
        if "16" in rtype:
            code = re.sub(rf"\b{rname}\s*([+-])=\s*2\s*;", rf"{rname} \1= 1;", code)
            code = re.sub(rf"\b{rname}\s*([+-])=\s*4\s*;", rf"{rname} \1= 2;", code)
        elif "32" in rtype:
            code = re.sub(rf"\b{rname}\s*([+-])=\s*4\s*;", rf"{rname} \1= 1;", code)
        if "8" not in rtype:
            code = re.sub(rf"\b{rname}\s*=\s*(reg_a[0-6]\s*[+-]\s*[^;]+);", rf"{rname} = ({rtype})(\1);", code)

    if relax_protos:
        code = PROTO_RE.sub(r"\1();", code)

    # Simplify leftover m2c 64-bit shift-sign-extension idioms to (s8)/(s16) casts
    code = re.sub(r"\(\(s64\)\s*\(\(s64\)\s*([^<]+?)\s*<<\s*0x38\)\s*>>\s*0x38\)", r"(s8)(\1)", code)
    code = re.sub(r"\(\(s64\)\s*\(\(s64\)\s*([^<]+?)\s*<<\s*0x30\)\s*>>\s*0x30\)", r"(s16)(\1)", code)

    # Emit missing forward declarations for called func_XXXXXXXX symbols
    defined_funcs = set(re.findall(r"^\s*(?:void|s32|u32|s16|u16|s8|u8|int|f32|f64|[^;\n]*\*)\s+(func_[0-9A-Fa-f]{8})\s*\([^)]*\)\s*\{", code, re.M))
    declared_funcs = set(re.findall(r"^(?:extern\s+)?[^;\n]*\b(func_[0-9A-Fa-f]{8})\s*\([^)]*\)\s*;", code, re.M))
    called_funcs = sorted(set(re.findall(r"\b(func_[0-9A-Fa-f]{8})\s*\(", code)) - defined_funcs - declared_funcs)
    if called_funcs:
        decls = "\n".join(f"void {fn}();" for fn in called_funcs) + "\n"
        code = decls + code

    if '#include "common.h"' not in code:
        code = '#include "common.h"\n\n' + code
    return code


def extract_function(asm_dir, function):
    nonmatchings = asm_dir / "nonmatchings"
    if nonmatchings.is_dir():
        files = sorted(nonmatchings.rglob(f"{function}.s"))
        if len(files) == 1:
            return files[0].read_text(encoding="utf-8")
    start_marker = f"glabel {function}"
    end_marker = f"endlabel {function}"
    for asm in sorted(asm_dir.glob("*.s")):
        lines = asm.read_text(encoding="utf-8").splitlines()
        for index, line in enumerate(lines):
            if line.strip() == start_marker:
                for end in range(index + 1, len(lines)):
                    if lines[end].strip() == end_marker:
                        return "\n".join(lines[index:end + 1]) + "\n"
    raise ValueError(f"Function {function} not found in {asm_dir}")


def _hoist_tail_jump_delay_slots(snippet):
    """Move non-nop delay-slot instructions before tail-call `j` so m2c does not drop them."""
    return TAIL_JUMP_RE.sub(lambda m: m.group(2) + m.group(1) + "    nop\n", snippet)


def _synthesize_jump_tables(target, snippet):
    """Extract retail .rodata jump tables referenced by %hi/%lo(jtbl_*) and ensure target labels exist."""
    table_addrs = sorted({int(m, 16) for m in JTBL_REF_RE.findall(snippet)})
    if not table_addrs:
        return snippet, None
    insn_addrs = [int(m, 16) for m in INSN_ADDR_RE.findall(snippet)]
    if not insn_addrs:
        return snippet, None
    fn_start, fn_end = min(insn_addrs), max(insn_addrs) + 4
    file_address, _, _ = target_layout(target)
    binary = (BASEROM / target).read_bytes()

    rodata_lines = [".section .rodata"]
    needed_labels = set()
    for table_addr in table_addrs:
        offset = table_addr - file_address
        if not 0 <= offset < len(binary):
            continue
        entries = []
        while offset + 4 <= len(binary) and len(entries) < 512:
            word, = struct.unpack_from("<I", binary, offset)
            if not (fn_start <= word < fn_end and word % 4 == 0):
                break
            entries.append(word)
            offset += 4
        if not entries:
            continue
        rodata_lines.append(f"glabel jtbl_{table_addr:08X}")
        for target_addr in entries:
            label = f".L{target_addr:08X}"
            needed_labels.add((target_addr, label))
            rodata_lines.append(f"    .word {label}")
    if not needed_labels:
        return snippet, None

    existing = set(re.findall(r"^\s*(\.L[0-9A-Fa-f]{8}):", snippet, re.M))
    missing = {addr: lbl for addr, lbl in needed_labels if lbl not in existing}
    if missing:
        patched = []
        for line in snippet.splitlines(keepends=True):
            m = INSN_ADDR_RE.match(line)
            if m:
                addr = int(m.group(1), 16)
                lbl = missing.pop(addr, None)
                if lbl is not None:
                    patched.append(f"{lbl}:\n")
            patched.append(line)
        snippet = "".join(patched)
    return snippet, "\n".join(rodata_lines) + "\n"


def draft_function(target, function, context=None, raw=False, relax_protos=False, m2c_args=()):
    folder = split(target)
    snippet = extract_function(folder / "asm", function)
    m2c_snippet = snippet if raw else _hoist_tail_jump_delay_slots(snippet)
    m2c_snippet, rodata_asm = _synthesize_jump_tables(target, m2c_snippet)
    with TemporaryDirectory(prefix="m2c-") as temporary:
        tmp = Path(temporary)
        path = tmp / f"{function}.s"
        path.write_text(".set noat\n.set noreorder\n\n" + m2c_snippet, encoding="utf-8")
        inputs = [str(path)]
        if rodata_asm is not None:
            rodata_path = tmp / f"{function}_rodata.s"
            rodata_path.write_text(rodata_asm, encoding="utf-8")
            inputs.append(str(rodata_path))
        ctx_path = context.resolve() if context else build_m2c_context(tmp / "context.h")
        command = [
            sys.executable, "-m", "m2c.main", "-t", "mipsee-mwcc-c",
            "--valid-syntax", "--no-cache", *m2c_args, "--context", str(ctx_path), *inputs,
        ]
        result = subprocess.run(command, cwd=ROOT, capture_output=True, text=True, check=True)
        output = result.stdout
        if raw:
            return output
        return _declare_project_context(clean_m2c(output, snippet, relax_protos=relax_protos))


def _declare_project_context(code):
    """m2c omits declarations for symbols it found in the context; re-add the project-only ones the draft uses."""
    decls = []
    for decl in M2C_PROJECT_CONTEXT.strip().splitlines():
        name = re.search(r"(\w+);$", decl)[1]
        if re.search(rf"\b{name}\b", code) and not re.search(rf"^extern [^;\n]*\b{name};", code, flags=re.M):
            decls.append(decl)
    if not decls:
        return code
    m = re.search(r"^(?:void|s32|u32|s16|u16|s8|u8|\w+) \**func_\w+\(", code, flags=re.M)
    at = m.start() if m else 0
    return code[:at] + "\n".join(decls) + "\n\n" + code[at:]


def main():
    parser = argparse.ArgumentParser(description="Print a C draft for a function disassembled by Splat.")
    parser.add_argument("target", choices=TARGETS)
    parser.add_argument("function")
    parser.add_argument("--context", type=Path, help="override auto-inlined common.h m2c context")
    parser.add_argument("--raw", action="store_true", help="skip MWCCPS2/DDPDOJ clean_m2c post-processing")
    parser.add_argument("--relax-protos", action="store_true", help="relax extern function prototypes to K&R ()")
    args = parser.parse_args()
    if not args.function.isascii() or not args.function.isidentifier():
        raise ValueError("Expected a Splat function name")
    sys.stdout.write(draft_function(args.target, args.function, args.context, args.raw, args.relax_protos))


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError, subprocess.CalledProcessError) as error:
        raise SystemExit(f"Draft failed: {error}")
