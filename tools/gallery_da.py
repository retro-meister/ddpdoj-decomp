"""Unpack, compress, and replace BMP artworks in GALLERY/GALLERY.DA on the PS2 ISO."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import struct
from tempfile import NamedTemporaryFile

from common import ROOT, require_local
from iso import SECTOR, find_extent, read_at, root_directory


def delta_decode(raw):
    buf = bytearray(raw)
    if len(buf) > 10:
        prev = buf[4]
        for i in range(5, len(buf) - 5):
            cur = buf[i]
            buf[i] = (cur - prev) & 0xFF
            prev = cur
    return bytes(buf)


def delta_encode(raw):
    buf = bytearray(raw)
    if len(buf) > 10:
        prev = buf[4]
        for i in range(5, len(buf) - 5):
            buf[i] = (buf[i] + prev) & 0xFF
            prev = buf[i]
    return bytes(buf)


def lzss_decompress(src):
    dst_size, src_size, flag_size = struct.unpack_from("<III", src, 0)
    flags = src[12:12 + flag_size]
    dst = bytearray()
    fbyte, fbit = 0, 7
    spos = 12 + flag_size
    while spos < src_size:
        bit = (flags[fbyte] >> fbit) & 1
        fbit -= 1
        if fbit < 0:
            fbit = 7
            fbyte += 1
        if bit:
            b0, b1 = src[spos], src[spos + 1]
            copy_len = (b1 & 0x1F) + 3
            back_off = (b0 << 3) | ((b1 >> 5) & 7)
            for _ in range(copy_len):
                dst.append(dst[-back_off])
            spos += 2
        else:
            dst.append(src[spos])
            spos += 1
    return bytes(dst[:dst_size])


def lzss_compress(data):
    """Fast hash-chain LZSS compressor matching GALLERY.ELF func_00124820."""
    n = len(data)
    flags = bytearray()
    tokens = bytearray()
    cur_flag = 0
    bit_pos = 7
    head = {}
    pos = 0

    def push_bit(b):
        nonlocal cur_flag, bit_pos
        if b:
            cur_flag |= (1 << bit_pos)
        bit_pos -= 1
        if bit_pos < 0:
            flags.append(cur_flag)
            cur_flag = 0
            bit_pos = 7

    while pos < n:
        best_len = 0
        best_off = 0
        if pos + 3 <= n:
            key = data[pos:pos + 3]
            cand_list = head.get(key)
            if cand_list:
                min_pos = max(0, pos - 2047)
                # Check up to 16 most recent matching 3-byte prefixes.
                for prev in reversed(cand_list[-16:]):
                    if prev < min_pos:
                        break
                    off = pos - prev
                    if off < 1 or off > 2047:
                        continue
                    max_l = min(34, n - pos)
                    l = 3
                    while l < max_l and data[prev + l] == data[pos + l]:
                        l += 1
                    if l > best_len:
                        best_len = l
                        best_off = off
                        if l == 34:
                            break
            if cand_list is None:
                head[key] = [pos]
            else:
                cand_list.append(pos)
                if len(cand_list) > 32:
                    del cand_list[:-16]

        if best_len >= 3:
            push_bit(1)
            b0 = (best_off >> 3) & 0xFF
            b1 = ((best_off & 7) << 5) | ((best_len - 3) & 0x1F)
            tokens.append(b0)
            tokens.append(b1)
            for step in range(1, best_len):
                p = pos + step
                if p + 3 <= n:
                    k = data[p:p + 3]
                    cl = head.get(k)
                    if cl is None:
                        head[k] = [p]
                    else:
                        cl.append(p)
            pos += best_len
        else:
            push_bit(0)
            tokens.append(data[pos])
            pos += 1

    if bit_pos != 7:
        flags.append(cur_flag)

    src_size = 12 + len(flags) + len(tokens)
    header = struct.pack("<III", n, src_size, len(flags))
    return header + bytes(flags) + bytes(tokens)


def image_to_8bpp_bmp(image_path, width, height):
    """Convert any PNG/JPG/BMP to an 8-bit paletted bottom-up Windows BMP of (width, height)."""
    image_path = Path(image_path)
    raw = image_path.read_bytes()
    if raw[:2] == b"BM":
        w, h, planes, bpp = struct.unpack_from("<IIHH", raw, 18)
        if w == width and h == height and bpp == 8:
            return raw

    from PIL import Image

    img = Image.open(image_path).convert("RGB")
    if img.size != (width, height):
        img = img.resize((width, height), Image.Resampling.LANCZOS)
    pal_img = img.quantize(colors=256, method=Image.Quantize.MEDIANCUT)
    palette = pal_img.getpalette() or []
    palette = list(palette) + [0] * (768 - len(palette))

    # Build standard 54-byte BITMAPFILEHEADER + BITMAPINFOHEADER + 1024-byte BGRA palette + bottom-up pixels.
    pal_bytes = bytearray()
    for i in range(256):
        r, g, b = palette[3 * i], palette[3 * i + 1], palette[3 * i + 2]
        pal_bytes.extend((b, g, r, 0))

    stride = (width + 3) & ~3
    raw_px = pal_img.tobytes()
    pixels = bytearray()
    pad = bytes(stride - width)
    for y in range(height - 1, -1, -1):
        row = raw_px[y * width:(y + 1) * width]
        pixels.extend(row)
        if pad:
            pixels.extend(pad)

    off_bits = 14 + 40 + 1024
    file_size = off_bits + len(pixels)
    bfh = struct.pack("<2sIHHI", b"BM", file_size, 0, 0, off_bits)
    bih = struct.pack("<IIIHHIIIIII", 40, width, height, 1, 8, 0, len(pixels), 0, 0, 256, 256)
    return bfh + bih + bytes(pal_bytes) + bytes(pixels)


def read_gallery_da(iso_path):
    with Path(iso_path).open("rb") as f:
        off, size = find_extent(f, root_directory(f), "GALLERY/GALLERY.DA")
        return off, size, read_at(f, off, size)


def parse_entries(da):
    count = struct.unpack_from("<I", da, 0)[0]
    offsets = list(struct.unpack_from(f"<{count}I", da, 4))
    entries = []
    for fid in range(1, count):
        start, end = offsets[fid - 1], offsets[fid]
        entries.append((fid, da[start:end]))
    return count, entries


def build_gallery_da(count, entries, target_size):
    header_sector = bytearray(SECTOR)
    struct.pack_into("<I", header_sector, 0, count)
    body = bytearray()
    cur = SECTOR
    offsets = []
    for _, payload in entries:
        offsets.append(cur)
        aligned = (len(payload) + SECTOR - 1) // SECTOR * SECTOR
        body.extend(payload)
        if aligned > len(payload):
            body.extend(bytes(aligned - len(payload)))
        cur += aligned
    offsets.append(cur)
    for idx, off in enumerate(offsets):
        struct.pack_into("<I", header_sector, 4 + idx * 4, off)
    out = bytes(header_sector) + bytes(body)
    if len(out) > target_size:
        raise ValueError(f"Repacked GALLERY.DA ({len(out):,} B) exceeds retail ISO extent ({target_size:,} B)")
    if len(out) < target_size:
        out += bytes(target_size - len(out))
    return out


def extract_gallery_assets(iso_path, assets_dir=None, force=False):
    """Extract editable GALLERY.DA BMPs into assets/gallery/ with a retail manifest."""
    assets_dir = Path(assets_dir or (ROOT / "assets" / "gallery"))
    manifest_path = assets_dir / ".manifest.json"
    if not force and manifest_path.is_file():
        return manifest_path
    _, da_size, da = read_gallery_da(iso_path)
    count, entries = parse_entries(da)
    assets_dir.mkdir(parents=True, exist_ok=True)
    manifest = {"count": count, "da_size": da_size, "entries": {}}
    for fid, raw in entries:
        try:
            bmp = lzss_decompress(delta_decode(raw))
            if bmp[:2] == b"BM":
                w, h, _, bpp = struct.unpack_from("<IIHH", bmp, 18)
                filename = f"gallery_{fid:02d}.bmp"
                (assets_dir / filename).write_bytes(bmp)
                manifest["entries"][str(fid)] = {
                    "kind": "bmp",
                    "file": filename,
                    "width": w,
                    "height": h,
                    "bpp": bpp,
                    "retail_sha256": hashlib.sha256(bmp).hexdigest(),
                }
                continue
        except Exception:
            pass
        filename = f"entry_{fid:02d}.bin"
        (assets_dir / filename).write_bytes(raw)
        manifest["entries"][str(fid)] = {
            "kind": "raw",
            "file": filename,
            "retail_sha256": hashlib.sha256(raw).hexdigest(),
        }
    manifest_path.write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")
    return manifest_path


def sync_gallery_iso(iso_path, assets_dir=None, out_iso=None, cache_dir=None):
    """Incrementally repack edited assets/gallery/* files into build/mod/ddpdoj.iso."""
    iso_path = Path(iso_path).resolve(strict=True)
    assets_dir = Path(assets_dir or (ROOT / "assets" / "gallery"))
    out_iso = Path(out_iso or (ROOT / "build" / "mod" / "ddpdoj.iso")).resolve()
    cache_dir = Path(cache_dir or (ROOT / "build" / "mod" / ".asset_cache" / "gallery"))
    if out_iso == iso_path:
        raise ValueError("Mod ISO path must not overwrite the retail ISO")

    manifest_path = extract_gallery_assets(iso_path, assets_dir)
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    da_off, da_size, retail_da = read_gallery_da(iso_path)
    count, retail_entries = parse_entries(retail_da)
    cache_dir.mkdir(parents=True, exist_ok=True)

    repacked_entries = []
    changed_ids = []
    for fid, retail_raw in retail_entries:
        info = manifest["entries"][str(fid)]
        if info["kind"] != "bmp":
            raw_path = assets_dir / info["file"]
            if raw_path.is_file():
                data = raw_path.read_bytes()
                if hashlib.sha256(data).hexdigest() != info["retail_sha256"]:
                    repacked_entries.append((fid, data))
                    changed_ids.append(fid)
                    continue
            repacked_entries.append((fid, retail_raw))
            continue

        # Allow a .png/.jpg with the same stem (e.g. gallery_03.png) to override gallery_03.bmp.
        stem = Path(info["file"]).stem
        source_file = assets_dir / info["file"]
        for ext in (".png", ".jpg", ".jpeg"):
            override = assets_dir / f"{stem}{ext}"
            if override.is_file():
                source_file = override
                break

        if not source_file.is_file():
            repacked_entries.append((fid, retail_raw))
            continue

        src_bytes = source_file.read_bytes()
        src_hash = hashlib.sha256(src_bytes).hexdigest()
        if source_file.name == info["file"] and src_hash == info["retail_sha256"]:
            repacked_entries.append((fid, retail_raw))
            continue

        changed_ids.append(fid)
        cached = cache_dir / f"{fid:02d}_{src_hash[:16]}.bin"
        if cached.is_file():
            encoded = cached.read_bytes()
        else:
            new_bmp = image_to_8bpp_bmp(source_file, info["width"], info["height"])
            comp = lzss_compress(new_bmp)
            aligned = (len(comp) + SECTOR - 1) // SECTOR * SECTOR
            encoded = delta_encode(comp + bytes(aligned - len(comp)))
            if lzss_decompress(delta_decode(encoded)) != new_bmp:
                raise ValueError(f"Round-trip verification failed for {source_file.name}")
            cached.write_bytes(encoded)
        repacked_entries.append((fid, encoded))

    new_da = build_gallery_da(count, repacked_entries, da_size)
    new_da_hash = hashlib.sha256(new_da).hexdigest()
    state_file = cache_dir / "iso_state.json"

    out_iso.parent.mkdir(parents=True, exist_ok=True)
    if not out_iso.is_file():
        with NamedTemporaryFile(dir=out_iso.parent, prefix=".mod-iso-", delete=False) as tmp:
            temp_path = Path(tmp.name)
        try:
            with iso_path.open("rb") as src, temp_path.open("wb") as dst:
                shutil.copyfileobj(src, dst, 1024 * 1024)
                dst.seek(da_off)
                dst.write(new_da)
            os.replace(temp_path, out_iso)
        finally:
            temp_path.unlink(missing_ok=True)
        state_file.write_text(json.dumps({"gallery_da_sha256": new_da_hash}, indent=2) + "\n", encoding="utf-8")
        return out_iso, changed_ids, True

    prev_hash = None
    if state_file.is_file():
        try:
            prev_hash = json.loads(state_file.read_text(encoding="utf-8")).get("gallery_da_sha256")
        except (OSError, ValueError):
            prev_hash = None
    if prev_hash != new_da_hash:
        with out_iso.open("r+b") as dst:
            dst.seek(da_off)
            dst.write(new_da)
        state_file.write_text(json.dumps({"gallery_da_sha256": new_da_hash}, indent=2) + "\n", encoding="utf-8")
        return out_iso, changed_ids, True
    return out_iso, changed_ids, False


def cmd_unpack(args):
    _, _, da = read_gallery_da(args.iso)
    _, entries = parse_entries(da)
    args.out.mkdir(parents=True, exist_ok=True)
    for fid, raw in entries:
        try:
            dec = delta_decode(raw)
            bmp = lzss_decompress(dec)
            if bmp[:2] == b"BM":
                w, h, _, bpp = struct.unpack_from("<IIHH", bmp, 18)
                out_file = args.out / f"gallery_{fid:02d}.bmp"
                out_file.write_bytes(bmp)
                print(f"  fileId={fid:2d}: {out_file.name} ({w}x{h} {bpp}bpp, {len(bmp):,} B)")
                continue
        except Exception:
            pass
        out_file = args.out / f"entry_{fid:02d}.bin"
        out_file.write_bytes(raw)
        print(f"  fileId={fid:2d}: {out_file.name} (raw, {len(raw):,} B)")


def cmd_replace(args):
    da_off, da_size, da = read_gallery_da(args.iso)
    count, entries = parse_entries(da)
    fid = args.file_id
    if not (1 <= fid < count):
        raise ValueError(f"file_id must be between 1 and {count - 1}")

    old_raw = entries[fid - 1][1]
    old_bmp = lzss_decompress(delta_decode(old_raw))
    if old_bmp[:2] != b"BM":
        raise ValueError(f"Entry {fid} is not a BMP")
    w, h, _, bpp = struct.unpack_from("<IIHH", old_bmp, 18)
    print(f"Target fileId={fid}: retail {w}x{h} {bpp}bpp (compressed {len(old_raw):,} B)")

    new_bmp = image_to_8bpp_bmp(args.image, w, h)
    comp = lzss_compress(new_bmp)
    aligned = (len(comp) + SECTOR - 1) // SECTOR * SECTOR
    padded = comp + bytes(aligned - len(comp))
    encoded = delta_encode(padded)
    print(f"Encoded new BMP: {len(new_bmp):,} B -> LZSS {len(comp):,} B -> sector-aligned {len(encoded):,} B")

    # Verify round-trip before touching the ISO!
    check = lzss_decompress(delta_decode(encoded))
    if check != new_bmp:
        raise ValueError("Round-trip verification failed!")

    entries[fid - 1] = (fid, encoded)
    new_da = build_gallery_da(count, entries, da_size)

    out_iso = args.out.resolve()
    if out_iso == args.iso.resolve():
        raise ValueError("Choose a new --out path (do not overwrite the retail ISO)")
    out_iso.parent.mkdir(parents=True, exist_ok=True)
    with NamedTemporaryFile(dir=out_iso.parent, prefix=".gallery-iso-", delete=False) as tmp:
        temp_path = Path(tmp.name)
    try:
        with args.iso.open("rb") as src, temp_path.open("wb") as dst:
            shutil.copyfileobj(src, dst, 1024 * 1024)
            dst.seek(da_off)
            dst.write(new_da)
        os.replace(temp_path, out_iso)
    finally:
        temp_path.unlink(missing_ok=True)
    print(f"Wrote modded ISO: {out_iso}")


def cmd_restore(args):
    iso_path = args.iso or (Path(require_local()["iso"]) if require_local().get("iso") else None)
    if iso_path is None:
        raise ValueError("Pass --iso PATH or run tools/setup.py --iso PATH first.")
    assets_dir = args.out
    if args.file_id is None:
        for ext in ("*.png", "*.jpg", "*.jpeg"):
            for p in assets_dir.glob(ext):
                p.unlink()
        extract_gallery_assets(iso_path, assets_dir, force=True)
        print(f"Restored all retail gallery assets to {assets_dir}")
        return
    _, _, da = read_gallery_da(iso_path)
    count, entries = parse_entries(da)
    fid = args.file_id
    if not (1 <= fid < count):
        raise ValueError(f"file_id must be between 1 and {count - 1}")
    raw = entries[fid - 1][1]
    assets_dir.mkdir(parents=True, exist_ok=True)
    for ext in (".png", ".jpg", ".jpeg"):
        (assets_dir / f"gallery_{fid:02d}{ext}").unlink(missing_ok=True)
    bmp = lzss_decompress(delta_decode(raw))
    out_file = assets_dir / f"gallery_{fid:02d}.bmp"
    out_file.write_bytes(bmp)
    print(f"Restored retail {out_file}")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest="cmd", required=True)

    p_unpack = sub.add_parser("unpack", help="Extract all GALLERY.DA entries from an ISO")
    p_unpack.add_argument("--iso", type=Path, required=True)
    p_unpack.add_argument("--out", type=Path, required=True)

    p_replace = sub.add_parser("replace", help="Replace one gallery BMP and write a modded ISO")
    p_replace.add_argument("--iso", type=Path, required=True)
    p_replace.add_argument("--file-id", type=int, default=3, help="GALLERY.DA entry id (3..37 are artworks)")
    p_replace.add_argument("--image", type=Path, required=True, help="PNG, JPG, or 8-bit BMP")
    p_replace.add_argument("--out", type=Path, default=Path("build/gallery_mod.iso"))

    p_restore = sub.add_parser("restore", help="Restore retail BMPs in assets/gallery/ from the configured ISO")
    p_restore.add_argument("--iso", type=Path, help="override retail ISO path (defaults to local.json)")
    p_restore.add_argument("--file-id", type=int, help="restore only one entry (e.g. 3); omit to restore all")
    p_restore.add_argument("--out", type=Path, default=ROOT / "assets" / "gallery")

    args = parser.parse_args()
    if args.cmd == "unpack":
        cmd_unpack(args)
    elif args.cmd == "replace":
        cmd_replace(args)
    else:
        cmd_restore(args)


if __name__ == "__main__":
    main()
