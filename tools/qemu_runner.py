import base64
import fcntl
import io
import json
import os
from pathlib import Path
import shlex
import shutil
import signal
import socket
import subprocess
import sys
import tarfile
from tempfile import TemporaryDirectory
import time

from common import ROOT, TOOLS, TOOLCHAINS, download, resolve_tool, run, verify
from iso import find_extent, read_at, root_directory

GUEST = TOOLS / "qemu"
GUEST_CONFIG = TOOLCHAINS["qemu_guest"]
ALPINE = GUEST_CONFIG["base_url"]
ISO = GUEST_CONFIG["iso"]
ROOTFS = GUEST_CONFIG["rootfs"]
KERNEL_HASH = GUEST_CONFIG["kernel_sha256"]
RUNTIME = GUEST_CONFIG["runtime"]

DAEMON_SOCK = GUEST / "daemon.sock"
DAEMON_LOCK = GUEST / "daemon.lock"
DAEMON_IDLE_TIMEOUT = 600  # seconds


def install_guest():
    resolve_tool("qemu-system-x86_64")
    resolve_tool("cpio")
    GUEST.mkdir(parents=True, exist_ok=True)
    with TemporaryDirectory(dir=GUEST) as temporary:
        work = Path(temporary)
        if not (GUEST / "vmlinuz").is_file():
            image = io.BytesIO(download(ALPINE + ISO[0], ISO[1]))
            extent = find_extent(image, root_directory(image), "BOOT/VMLINUZ_VIRT")
            kernel = read_at(image, *extent)
            verify(kernel, KERNEL_HASH, "Alpine guest kernel")
            path = work / "vmlinuz"
            path.write_bytes(kernel)
            path.replace(GUEST / "vmlinuz")
        if any(not (GUEST / name).is_file() for name in RUNTIME):
            archive = download(ALPINE + ROOTFS[0], ROOTFS[1])
            with tarfile.open(fileobj=io.BytesIO(archive), mode="r:gz") as rootfs:
                for name in RUNTIME:
                    target = GUEST / name
                    target.parent.mkdir(exist_ok=True)
                    path = work / target.name
                    path.write_bytes(verify(rootfs.extractfile("./" + name).read(), RUNTIME[name], name))
                    path.chmod(0o755)
                    path.replace(target)
        asset, checksum = TOOLCHAINS["wibo"]["linux-x86_64"]
        wibo = GUEST / "wibo"
        if not wibo.is_file():
            version = TOOLCHAINS["wibo"]["version"]
            path = work / "wibo"
            path.write_bytes(download(f"https://github.com/decompals/wibo/releases/download/{version}/{asset}", checksum))
            path.chmod(0o755)
            path.replace(wibo)
        verify(wibo.read_bytes(), checksum, asset)
        verify((GUEST / "vmlinuz").read_bytes(), KERNEL_HASH, "Alpine guest kernel")
        for name, expected in RUNTIME.items():
            verify((GUEST / name).read_bytes(), expected, name)
    return Path(__file__).resolve()


class PersistentGuest:
    def __init__(self):
        self.tmpdir = None
        self.proc = None
        self.compiler_map = {}
        self.synced_files = {}  # guest_relpath -> (mtime_ns, size)

    def start(self):
        self.stop()
        self.tmpdir = TemporaryDirectory(prefix="ddpdoj-qemu-")
        work = Path(self.tmpdir.name)
        fs = work / "root"
        for name in ("job", "dev", "proc", "tmp", "bin", "lib", "cc"):
            (fs / name).mkdir(parents=True, exist_ok=True)
        for name in (*RUNTIME, "wibo"):
            shutil.copy2(GUEST / name, fs / name)

        self.compiler_map = {}
        compilers_root = TOOLS / "compilers"
        if compilers_root.is_dir():
            for cc_dir in sorted(compilers_root.iterdir()):
                exe = cc_dir / "mwccps2.exe"
                if exe.is_file():
                    dest_dir = fs / "cc" / cc_dir.name
                    dest_dir.mkdir(parents=True, exist_ok=True)
                    for binary in ("mwccps2.exe", "LMGR326B.dll"):
                        src_bin = cc_dir / binary
                        if src_bin.is_file():
                            shutil.copy2(src_bin, dest_dir / binary)
                    self.compiler_map[str(exe.resolve())] = f"/cc/{cc_dir.name}/mwccps2.exe"

        self.synced_files = {}
        include_dir = ROOT / "include"
        if include_dir.is_dir():
            shutil.copytree(include_dir, fs / "job" / "include")
            for p in include_dir.rglob("*"):
                if p.is_file():
                    rel = p.relative_to(ROOT).as_posix()
                    st = p.stat()
                    self.synced_files[rel] = (st.st_mtime_ns, st.st_size)

        init_script = """#!/bin/busybox sh
/bin/busybox mount -t proc proc /proc
/bin/busybox mount -t devtmpfs devtmpfs /dev
/bin/busybox stty -echo raw 2>/dev/null || true
cd /job
echo "@@READY@@"
while IFS= read -r line; do
  case "$line" in
    PING)
      echo "@@PONG@@"
      ;;
    PUT\\ *)
      rel="${line#PUT }"
      dir="${rel%/*}"
      if [ "$dir" != "$rel" ]; then
        /bin/busybox mkdir -p "$dir"
      fi
      : > /tmp/b64
      while IFS= read -r chunk; do
        [ "$chunk" = "@@EOF@@" ] && break
        printf '%s' "$chunk" >> /tmp/b64
      done
      /bin/busybox base64 -d /tmp/b64 > "$rel"
      echo "@@PUT_OK@@"
      ;;
    COMPILE\\ *)
      rest="${line#COMPILE }"
      out="${rest%% *}"
      cmd="${rest#* }"
      /bin/busybox rm -f "$out" /tmp/cc.log
      if eval "$cmd" > /tmp/cc.log 2>&1 && [ -s "$out" ]; then
        echo "@@OK_BEGIN@@"
        /bin/busybox base64 "$out"
        echo "@@OK_END@@"
      else
        echo "@@ERR_BEGIN@@"
        /bin/busybox base64 /tmp/cc.log
        echo "@@ERR_END@@"
      fi
      ;;
    QUIT)
      /bin/busybox poweroff -f
      exit 0
      ;;
  esac
done
/bin/busybox poweroff -f
"""
        init = fs / "init"
        init.write_text(init_script, encoding="utf-8")
        init.chmod(0o755)
        initrd = work / "guest.cpio"
        members = sorted(p.relative_to(fs).as_posix() for p in fs.rglob("*"))
        with initrd.open("wb") as archive:
            run(
                "cpio", "-o", "-0", "-H", "newc",
                cwd=fs, stdout=archive, stderr=subprocess.PIPE,
                input=("\0".join(members) + "\0").encode("utf-8"),
            )

        self.proc = subprocess.Popen(
            [
                "qemu-system-x86_64", "-accel", "tcg", "-cpu", "max", "-m", "256",
                "-display", "none", "-serial", "stdio", "-monitor", "none", "-nic", "none",
                "-no-reboot", "-kernel", str(GUEST / "vmlinuz"), "-initrd", str(initrd),
                "-append", "console=ttyS0 quiet loglevel=0 panic=1 rdinit=/init",
            ],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.DEVNULL,
        )
        deadline = time.monotonic() + 30
        while time.monotonic() < deadline:
            raw = self.proc.stdout.readline()
            if not raw:
                raise RuntimeError("QEMU guest exited during boot")
            if raw.decode("utf-8", "replace").strip() == "@@READY@@":
                return
        raise RuntimeError("QEMU guest timed out during boot")

    def is_alive(self):
        return self.proc is not None and self.proc.poll() is None

    def put_file(self, guest_rel, data):
        b64 = base64.b64encode(data).decode("ascii")
        self.proc.stdin.write(f"PUT {guest_rel}\n".encode("utf-8"))
        for i in range(0, len(b64), 1024):
            self.proc.stdin.write((b64[i : i + 1024] + "\n").encode("ascii"))
        self.proc.stdin.write(b"@@EOF@@\n")
        self.proc.stdin.flush()
        while True:
            raw = self.proc.stdout.readline()
            if not raw:
                raise RuntimeError("QEMU guest died during PUT")
            if raw.decode("utf-8", "replace").strip() == "@@PUT_OK@@":
                return

    def sync_headers(self):
        include_dir = ROOT / "include"
        if not include_dir.is_dir():
            return
        for p in include_dir.rglob("*"):
            if not p.is_file():
                continue
            rel = p.relative_to(ROOT).as_posix()
            st = p.stat()
            sig = (st.st_mtime_ns, st.st_size)
            if self.synced_files.get(rel) != sig:
                self.put_file(rel, p.read_bytes())
                self.synced_files[rel] = sig

    def compile_job(self, compiler, flags, source):
        if not self.is_alive():
            self.start()
        self.sync_headers()

        compiler_key = str(Path(compiler).resolve())
        guest_cc = self.compiler_map.get(compiler_key)
        if not guest_cc:
            # Dynamically stage an unknown compiler path
            cc_path = Path(compiler_key)
            guest_cc = f"/tmp/cc_{abs(hash(compiler_key)) & 0xffffffff}/{cc_path.name}"
            for binary in (cc_path.name, "LMGR326B.dll"):
                src_bin = cc_path.parent / binary
                if src_bin.is_file():
                    self.put_file(f"{guest_cc.rsplit('/', 1)[0]}/{binary}", src_bin.read_bytes())
            self.compiler_map[compiler_key] = guest_cc

        src_path = Path(source).resolve()
        if src_path.is_relative_to(ROOT):
            guest_src = src_path.relative_to(ROOT).as_posix()
        else:
            guest_src = f"draft/{src_path.name}"
            for header in src_path.parent.glob("*.h"):
                h_rel = f"draft/{header.name}"
                st = header.stat()
                sig = (st.st_mtime_ns, st.st_size)
                if self.synced_files.get(h_rel) != sig:
                    self.put_file(h_rel, header.read_bytes())
                    self.synced_files[h_rel] = sig

        st = src_path.stat()
        sig = (st.st_mtime_ns, st.st_size)
        if self.synced_files.get(guest_src) != sig:
            self.put_file(guest_src, src_path.read_bytes())
            self.synced_files[guest_src] = sig

        out_name = "out.o"
        cmd = shlex.join(["/wibo", guest_cc, *flags, "-o", out_name, guest_src])
        self.proc.stdin.write(f"COMPILE {out_name} {cmd}\n".encode("utf-8"))
        self.proc.stdin.flush()

        mode = None
        chunks = []
        while True:
            raw = self.proc.stdout.readline()
            if not raw:
                raise RuntimeError("QEMU guest died during COMPILE")
            line = raw.decode("utf-8", "replace").strip()
            if mode is None:
                if line == "@@OK_BEGIN@@":
                    mode = "ok"
                elif line == "@@ERR_BEGIN@@":
                    mode = "err"
            elif mode == "ok":
                if line == "@@OK_END@@":
                    return True, base64.b64decode("".join(chunks))
                chunks.append(line)
            elif mode == "err":
                if line == "@@ERR_END@@":
                    return False, base64.b64decode("".join(chunks)).decode("utf-8", "replace")
                chunks.append(line)

    def stop(self):
        if self.proc is not None:
            try:
                if self.proc.poll() is None:
                    self.proc.stdin.write(b"QUIT\n")
                    self.proc.stdin.flush()
                    self.proc.wait(timeout=3)
            except Exception:
                try:
                    self.proc.kill()
                except Exception:
                    pass
            self.proc = None
        if self.tmpdir is not None:
            try:
                self.tmpdir.cleanup()
            except Exception:
                pass
            self.tmpdir = None


def run_daemon():
    GUEST.mkdir(parents=True, exist_ok=True)
    if DAEMON_SOCK.exists():
        try:
            DAEMON_SOCK.unlink()
        except OSError:
            pass

    guest = PersistentGuest()
    guest.start()

    srv = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    srv.bind(str(DAEMON_SOCK))
    srv.listen(16)
    srv.settimeout(DAEMON_IDLE_TIMEOUT)

    stop_flag = [False]

    def handle_sig(_signum, _frame):
        stop_flag[0] = True

    signal.signal(signal.SIGTERM, handle_sig)
    signal.signal(signal.SIGINT, handle_sig)

    try:
        while not stop_flag[0]:
            try:
                conn, _ = srv.accept()
            except socket.timeout:
                break
            except OSError:
                break
            with conn:
                try:
                    f = conn.makefile("rwb")
                    line = f.readline()
                    if not line:
                        continue
                    req = json.loads(line.decode("utf-8"))
                    action = req.get("action", "compile")
                    if action == "stop":
                        f.write(b'{"ok":true}\n')
                        f.flush()
                        break
                    if action == "ping":
                        f.write(b'{"ok":true}\n')
                        f.flush()
                        continue
                    results = []
                    for job in req["jobs"]:
                        ok, payload = guest.compile_job(job["compiler"], job["flags"], job["source"])
                        if ok:
                            out_path = Path(job["output"])
                            out_path.parent.mkdir(parents=True, exist_ok=True)
                            out_path.write_bytes(payload)
                            results.append({"ok": True})
                        else:
                            results.append({"ok": False, "error": payload})
                            break
                    f.write((json.dumps({"ok": all(r["ok"] for r in results), "results": results}) + "\n").encode("utf-8"))
                    f.flush()
                except Exception as exc:
                    try:
                        conn.sendall((json.dumps({"ok": False, "error": str(exc)}) + "\n").encode("utf-8"))
                    except Exception:
                        pass
    finally:
        srv.close()
        guest.stop()
        try:
            DAEMON_SOCK.unlink()
        except OSError:
            pass


def _connect_daemon():
    sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    sock.settimeout(120)
    sock.connect(str(DAEMON_SOCK))
    return sock


def _ensure_daemon():
    try:
        return _connect_daemon()
    except PermissionError:
        raise
    except OSError:
        pass

    GUEST.mkdir(parents=True, exist_ok=True)
    with DAEMON_LOCK.open("w") as lock_file:
        fcntl.flock(lock_file, fcntl.LOCK_EX)
        try:
            return _connect_daemon()
        except OSError:
            pass
        if DAEMON_SOCK.exists():
            try:
                DAEMON_SOCK.unlink()
            except OSError:
                pass
        subprocess.Popen(
            [sys.executable, str(Path(__file__).resolve()), "--daemon"],
            cwd=ROOT,
            stdin=subprocess.DEVNULL,
            stdout=subprocess.DEVNULL,
            stderr=subprocess.DEVNULL,
            start_new_session=True,
        )
        deadline = time.monotonic() + 30
        while time.monotonic() < deadline:
            try:
                return _connect_daemon()
            except OSError:
                time.sleep(0.05)
        raise RuntimeError("Timed out waiting for QEMU compiler daemon to start")


def stop_daemon():
    try:
        with _connect_daemon() as sock:
            sock.sendall(b'{"action":"stop"}\n')
            sock.recv(1024)
    except OSError:
        pass


def compile_batch(jobs):
    if not jobs:
        return
    try:
        req = {
            "action": "compile",
            "jobs": [
                {
                    "compiler": str(Path(compiler).resolve()),
                    "flags": list(flags),
                    "output": str(Path(output).resolve()),
                    "source": str(Path(source).resolve()),
                }
                for compiler, flags, output, source in jobs
            ],
        }
        with _ensure_daemon() as sock:
            f = sock.makefile("rwb")
            f.write((json.dumps(req) + "\n").encode("utf-8"))
            f.flush()
            resp_line = f.readline()
        if not resp_line:
            raise ValueError("QEMU compiler daemon closed connection unexpectedly")
        resp = json.loads(resp_line.decode("utf-8"))
        if not resp.get("ok"):
            err = resp.get("error")
            if not err:
                for r in resp.get("results", []):
                    if not r.get("ok"):
                        err = r.get("error")
                        break
            raise ValueError(f"Guest compiler failed:\n{(err or 'unknown error')[-4000:]}")
    except (OSError, RuntimeError):
        guest = PersistentGuest()
        guest.start()
        try:
            for compiler, flags, output, source in jobs:
                ok, payload = guest.compile_job(compiler, flags, source)
                if ok:
                    out_path = Path(output)
                    out_path.parent.mkdir(parents=True, exist_ok=True)
                    out_path.write_bytes(payload)
                else:
                    raise ValueError(f"Guest compiler failed:\n{payload[-4000:]}")
        finally:
            guest.stop()


def compile_in_guest(compiler, flags, output, source):
    compile_batch([(compiler, flags, output, source)])


def main():
    if len(sys.argv) == 2 and sys.argv[1] == "--daemon":
        run_daemon()
        return
    if len(sys.argv) == 2 and sys.argv[1] == "--stop-daemon":
        stop_daemon()
        return
    compiler, *flags, output_flag, output, source = sys.argv[1:]
    if output_flag != "-o":
        raise ValueError("Expected compiler arguments ending in -o OUTPUT SOURCE")
    compile_in_guest(Path(compiler), flags, Path(output), Path(source).resolve())


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError, RuntimeError, subprocess.SubprocessError) as error:
        raise SystemExit(f"QEMU compiler failed: {error}")
