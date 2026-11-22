from contextlib import contextmanager
import hashlib
import json
from pathlib import Path
import platform
import shutil
import subprocess
import sys
import urllib.request

ROOT = Path(__file__).resolve().parent.parent
BASEROM = ROOT / "baserom"
TOOLS = ROOT / ".tools"
LOCAL = ROOT / "local.json"


@contextmanager
def matching_lock(shared=False, name="matching.lock"):
    """Keep matching tools from reading Splat state during integration.

    Readers such as diffs take the lock shared so they can run side by side; integration takes it exclusively.
    """
    import fcntl

    path = ROOT / "build" / name
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("a+b") as lock:
        fcntl.flock(lock, fcntl.LOCK_SH if shared else fcntl.LOCK_EX)
        yield


def read_json(path):
    return json.loads(path.read_text(encoding="utf-8"))


TARGETS = read_json(ROOT / "config/targets.json")
TOOLCHAINS = read_json(ROOT / "config/toolchains.json")
TARGET_SUBDIRS = {
    "GALLERY.ELF": "gallery",
    "DEATH.ELF": "death",
    "SLPS_252.33": "main",
}


def nonmatching_dir(target_name):
    return ROOT / "src" / "nonmatchings" / TARGET_SUBDIRS.get(target_name, target_name.lower())


def require_local():
    if not LOCAL.is_file():
        raise ValueError("Run python tools/setup.py with your disc image first.")
    return read_json(LOCAL)


def host_machine():
    machine = platform.machine().lower()
    return {"amd64": "x86_64", "aarch64": "arm64"}.get(machine, machine)


def verify(data, expected, label):
    actual = hashlib.sha256(data).hexdigest()
    if actual != expected:
        raise ValueError(f"{label}: expected SHA-256 {expected}, got {actual}")
    return data


def resolve_tool(value):
    path = shutil.which(str(value))
    if path is None:
        raise ValueError(f"Executable unavailable: {value}")
    return str(Path(path).resolve())


def run(*args, cwd=ROOT, **kwargs):
    return subprocess.run(list(map(str, args)), cwd=cwd, check=True, **kwargs)


def target_compiler(name, local=None, override=None):
    if override:
        return override
    if local and local.get("compiler"):
        return local["compiler"]
    return TARGETS[name]["compiler"]


def required_compilers():
    return sorted({target["compiler"] for target in TARGETS.values()})


def compiler_path(version):
    return TOOLS / "compilers" / version / "mwccps2.exe"


def verify_compiler(version):
    compiler = compiler_path(version)
    record = TOOLCHAINS["compilers"][version]
    verify(compiler.read_bytes(), record["sha256"], str(compiler))
    dll = compiler.with_name("LMGR326B.dll")
    verify(dll.read_bytes(), record.get("dll_sha256", TOOLCHAINS["compiler_dll_sha256"]), str(dll))


def download(url, sha256):
    with urllib.request.urlopen(url, timeout=60) as response:
        return verify(response.read(), sha256, url)
