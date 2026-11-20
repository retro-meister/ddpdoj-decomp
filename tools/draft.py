import argparse
from pathlib import Path
import subprocess
import sys
from tempfile import TemporaryDirectory

from common import TARGETS, run
from split import split


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


def main():
    parser = argparse.ArgumentParser(description="Print a C draft for a function disassembled by Splat.")
    parser.add_argument("target", choices=TARGETS)
    parser.add_argument("function")
    parser.add_argument("--context", type=Path)
    args = parser.parse_args()
    if not args.function.isascii() or not args.function.isidentifier():
        raise ValueError("Expected a Splat function name")
    folder = split(args.target)
    snippet = extract_function(folder / "asm", args.function)
    with TemporaryDirectory(prefix="m2c-") as temporary:
        path = Path(temporary) / f"{args.function}.s"
        path.write_text(snippet, encoding="utf-8")
        command = [sys.executable, "-m", "m2c.main", "-t", "mipsee-mwcc-c", "--no-cache"]
        if args.context:
            command += ["--context", args.context.resolve()]
        run(*command, path)


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError, subprocess.CalledProcessError) as error:
        raise SystemExit(f"Draft failed: {error}")
