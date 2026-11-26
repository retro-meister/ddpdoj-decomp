"""Stage UTF-8 C sources that use SJIS literals as explicit CP932 bytes."""

from pathlib import Path
import re
import sys


SJIS_CALL_RE = re.compile(r'\bSJIS\s*\(((?:\s*"(?:[^"\\]|\\.)*")+\s*)\)')
C_STRING_RE = re.compile(r'"((?:[^"\\]|\\.)*)"')


def _expand_sjis_match(match):
    inner = match.group(1)
    parts = []
    for s_match in C_STRING_RE.finditer(inner):
        raw = s_match.group(1)
        # Decode standard C escapes like \n, \t, \\, \" while keeping UTF-8 chars intact
        decoded = bytes(raw, "utf-8").decode("unicode_escape").encode("latin1").decode("utf-8")
        parts.append(decoded)
    encoded = "".join(parts).encode("cp932")
    escaped = "".join(f"\\x{b:02X}" for b in encoded)
    newlines = "\n" * inner.count("\n")
    return f'"{escaped}"{newlines}'


def expand_sjis(text):
    return SJIS_CALL_RE.sub(_expand_sjis_match, text)


if __name__ == "__main__":
    source, destination = map(Path, sys.argv[1:])
    destination.parent.mkdir(parents=True, exist_ok=True)
    destination.write_text(expand_sjis(source.read_text(encoding="utf-8")), encoding="utf-8")
