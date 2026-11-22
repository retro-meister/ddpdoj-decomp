import argparse
from pathlib import Path
import re
import subprocess
import sys
from tempfile import TemporaryDirectory

from common import ROOT, TARGETS
from split import split


COMMON_SYMS = frozenset({
    "reg_d0", "reg_d1", "reg_d2", "reg_d3", "reg_d4", "reg_d5", "reg_d6", "reg_d7",
    "reg_tmp", "rng_cursor", "rng_values", "D_0028E48A",
})
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
    r"^(\s*)([^\n;=]+?)\s*=\s*\((?:u8|u16|s8|s16)\)\s*\(\2\s*([+\-|&^])\s*([^\n;]+)\)\s*;\s*$",
    re.M,
)
COMPOUND_PLAIN_RE = re.compile(
    r"^(\s*)(\(\*\((?:u8|u16) \*\)\([^\n;=]+\)\))\s*=\s*\2\s*([+\-|&^])\s*([^\n;]+)\s*;\s*$",
    re.M,
)
MUL2_RE = re.compile(r"^(\s*)([^\n;=]+?)\s*\*=\s*2\s*;\s*$", re.M)


def _strip_preprocessor(text):
    return "\n".join(line for line in text.splitlines() if not line.lstrip().startswith("#")) + "\n"


def build_m2c_context(dest_path):
    """Write a pycparser-friendly context header inlining include/types.h and include/common.h."""
    types_h = _strip_preprocessor((ROOT / "include/types.h").read_text(encoding="utf-8"))
    common_h = _strip_preprocessor((ROOT / "include/common.h").read_text(encoding="utf-8"))
    dest_path.write_text(types_h + "\n" + common_h, encoding="utf-8")
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

    code = code.replace("D_0028E48A", "reg_tmp.h[1]")

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

    # Compound assignments trigger lbu/lhu instead of lb/lh in MWCCPS2
    code = COMPOUND_CAST_RE.sub(r"\1\2 \3= \4;", code)
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

    reg_types = dict(re.findall(r"extern\s+([us](?:8|16|32)\s*\*)\s*(reg_a[0-6])\s*;", code))
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


def draft_function(target, function, context=None, raw=False, relax_protos=False):
    folder = split(target)
    snippet = extract_function(folder / "asm", function)
    with TemporaryDirectory(prefix="m2c-") as temporary:
        tmp = Path(temporary)
        path = tmp / f"{function}.s"
        path.write_text(".set noat\n.set noreorder\n\n" + snippet, encoding="utf-8")
        ctx_path = context.resolve() if context else build_m2c_context(tmp / "context.h")
        command = [
            sys.executable, "-m", "m2c.main", "-t", "mipsee-mwcc-c",
            "--valid-syntax", "--no-cache", "--context", str(ctx_path), str(path),
        ]
        result = subprocess.run(command, cwd=ROOT, capture_output=True, text=True, check=True)
        output = result.stdout
        if raw:
            return output
        return clean_m2c(output, snippet, relax_protos=relax_protos)


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
