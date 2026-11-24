"""Count what is left to clean up in the Main and Death Label sources.

    uv run tools/cleanup_stats.py
"""
from pathlib import Path
import re

from common import ROOT

PATTERNS = {
    "func_ names": r"\b(?:death_)?func_[0-9A-F]{8}\b",
    "D_ names": r"\b(?:death_)?D_[0-9A-F]{8}\b",
    "unk fields": r"\bunk[0-9A-Za-z_]*\b",
}


def main():
    files = [p for d in ("main", "shared", "death") for p in sorted((ROOT / "src" / d).glob("*.c"))]
    text = "\n".join(p.read_text(encoding="utf-8") for p in files)
    print(f"{'source files':<16}{len(files):>8,}")
    print(f"{'lines':<16}{text.count(chr(10)):>8,}")
    for label, pattern in PATTERNS.items():
        found = re.findall(pattern, text)
        print(f"{label:<16}{len(set(found)):>8,} distinct {len(found):>9,} uses")
    print(f"{'goto':<16}{len(re.findall(r'\bgoto\b', text)):>8,}")
    print(f"{'raw casts':<16}{len(re.findall(r'\*\((?:[us](?:8|16|32|64)|f32) \*\)', text)):>8,}")


if __name__ == "__main__":
    main()
