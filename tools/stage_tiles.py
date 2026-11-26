#!/usr/bin/env python3
"""The stages' background tiles: STnBG.PHD / STnBG.PRS on the disc <-> one sheet of tiles a stage.

    uv run tools/stage_tiles.py unpack            the five sheets into assets/stage_tiles/
    uv run tools/stage_tiles.py preview           each stage's whole map as a picture, from the sources
    uv run tools/stage_tiles.py pack              the tile files of the changed sheets into build/mod/tiles/

A sheet (stN.png) holds the stage's tiles 64 to a row, tile 0 at the top left, 32 by 32 pixels each, upright
as on an upright screen (the disc holds them turned, see `upright`). It is a palette image whose pixel values
are the tiles' colour numbers (0 to 31); the greys it is shown in mean nothing, since the map gives every cell
its own palette. `build.py --mod --iso` writes changed sheets to the
disc image.
"""
import argparse
import hashlib
import json
import re
import struct
from pathlib import Path

from PIL import Image

from iso import find_extent, read_at, root_directory

ROOT = Path(__file__).resolve().parent.parent
ASSETS = ROOT / "assets" / "stage_tiles"
STAGES = range(1, 6)
TILE = 32
TILE_WORDS = TILE * TILE // 4
SHEET_COLUMNS = 64
# The game reads a stage's pixel file whole into `g_bg_tile_pixels` (src/game/system/system.c); a larger
# file needs that array enlarged with it.
PIXEL_FILE_LIMIT = 0x208000
PIXEL_MASK = 0x1F1F1F1F
PACKED = 0x80000000
REPEAT = 0x40000000


def disc_paths(stage):
    return f"SPRITE/ST{stage}BG.PHD", f"SPRITE/ST{stage}BG.PRS"


def read_tile_files(iso_path, stage):
    with Path(iso_path).open("rb") as image:
        root = root_directory(image)
        return tuple(read_at(image, *find_extent(image, root, path)) for path in disc_paths(stage))


def tile_spans(offsets_file, pixels_file):
    """Every tile's bytes in the pixel file: a tile runs to where the next one starts."""
    offsets = struct.unpack(f"<{len(offsets_file) // 4}I", offsets_file)
    if list(offsets) != sorted(offsets) or offsets[-1] > len(pixels_file):
        raise ValueError("Tile offsets are not in order")
    ends = offsets[1:] + (len(pixels_file),)
    return [pixels_file[start:end] for start, end in zip(offsets, ends)]


def unpack_tile(stored):
    """A stored tile -> 1,024 colour numbers, or None for a stub shorter than a tile."""
    words = struct.unpack(f"<{len(stored) // 4}I", stored)
    out = []
    if not words[0] & PACKED:
        if len(words) < TILE_WORDS:
            return None
        out = list(words[:TILE_WORDS])
    else:
        cursor = 0
        while len(out) < TILE_WORDS and cursor < len(words):
            word = words[cursor]
            cursor += 1
            if word & REPEAT:
                if cursor >= len(words):
                    return None
                out += [words[cursor] & PIXEL_MASK] * ((word & 0x3FFF) + 1)
                cursor += 1
            else:
                out.append(word & PIXEL_MASK)
        if len(out) != TILE_WORDS:
            return None
    return struct.pack(f"<{TILE_WORDS}I", *out)


def pack_tile(pixels):
    """1,024 colour numbers -> a stored tile, padded to 16 bytes. Plain when packing gains nothing."""
    words = struct.unpack(f"<{TILE_WORDS}I", pixels)
    out = []
    cursor = 0
    while cursor < TILE_WORDS:
        end = cursor
        while end < TILE_WORDS and words[end] == words[cursor]:
            end += 1
        if end - cursor >= 3:
            out += [PACKED | REPEAT | (end - cursor - 1), words[cursor]]
            cursor = end
        else:
            out.append(PACKED | words[cursor])
            cursor += 1
    out += [0] * (-len(out) % 4)
    if len(out) >= TILE_WORDS:
        return pixels
    stored = struct.pack(f"<{len(out)}I", *out)
    if unpack_tile(stored) != pixels:
        raise ValueError("Tile does not survive packing")
    return stored


def upright(tile):
    """A tile image as the disc holds it <-> as it stands on an upright screen (the same turn both ways).

    The disc's tiles are mirrored along the diagonal that runs from the bottom left to the top right: the
    game draws its upright picture lying on its side.
    """
    return tile.transpose(Image.Transpose.TRANSVERSE)


def grey_palette():
    palette = []
    for value in range(256):
        level = (value & 0x1F) * 255 // 31 if value < 32 else 0
        palette += [level, level, level] if value < 32 else [255, 0, 255]
    return palette


def sheet_size(count):
    return SHEET_COLUMNS * TILE, -(-count // SHEET_COLUMNS) * TILE


def tiles_to_sheet(tiles):
    sheet = Image.new("P", sheet_size(len(tiles)), 0)
    sheet.putpalette(grey_palette())
    for number, pixels in enumerate(tiles):
        if pixels is None:
            continue
        tile = upright(Image.frombytes("P", (TILE, TILE), pixels))
        sheet.paste(tile, (number % SHEET_COLUMNS * TILE, number // SHEET_COLUMNS * TILE))
    return sheet


def sheet_to_tiles(path, count):
    sheet = Image.open(path)
    if sheet.mode != "P":
        raise ValueError(f"{path}: keep the sheet a palette image; its pixel values are the colour numbers")
    if sheet.size != sheet_size(count):
        raise ValueError(f"{path}: expected {sheet_size(count)[0]} by {sheet_size(count)[1]} pixels")
    tiles = []
    for number in range(count):
        left, top = number % SHEET_COLUMNS * TILE, number // SHEET_COLUMNS * TILE
        pixels = upright(sheet.crop((left, top, left + TILE, top + TILE))).tobytes()
        if max(pixels) > 31:
            raise ValueError(f"{path}: tile {number:#x} has a colour number above 31")
        tiles.append(pixels)
    return tiles


def stage_tiles(iso_path, stage):
    offsets_file, pixels_file = read_tile_files(iso_path, stage)
    stored = tile_spans(offsets_file, pixels_file)
    return stored, [unpack_tile(tile) for tile in stored]


def extract_stage_tiles(iso_path, assets_dir=ASSETS, force=False):
    """Write the five sheets and a record of what the disc holds; leaves sheets that exist alone."""
    assets_dir = Path(assets_dir)
    manifest_path = assets_dir / ".manifest.json"
    if manifest_path.is_file() and not force:
        return manifest_path
    assets_dir.mkdir(parents=True, exist_ok=True)
    manifest = {}
    for stage in STAGES:
        _, tiles = stage_tiles(iso_path, stage)
        name = f"st{stage}.png"
        tiles_to_sheet(tiles).save(assets_dir / name, optimize=True)
        manifest[str(stage)] = {
            "file": name,
            "tiles": len(tiles),
            "retail_sha256": hashlib.sha256((assets_dir / name).read_bytes()).hexdigest(),
        }
    manifest_path.write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")
    return manifest_path


def build_tile_files(iso_path, assets_dir=ASSETS):
    """{disc path: contents} of every stage's two files, and the stages whose sheet was changed.

    A tile whose pixels are the disc's keeps the disc's bytes, so an untouched sheet gives the disc's files.
    """
    assets_dir = Path(assets_dir)
    manifest = json.loads(extract_stage_tiles(iso_path, assets_dir).read_text(encoding="utf-8"))
    files = {}
    changed = []
    for stage in STAGES:
        info = manifest[str(stage)]
        offsets_path, pixels_path = disc_paths(stage)
        offsets_file, pixels_file = read_tile_files(iso_path, stage)
        files[offsets_path], files[pixels_path] = offsets_file, pixels_file
        sheet = assets_dir / info["file"]
        if not sheet.is_file() or hashlib.sha256(sheet.read_bytes()).hexdigest() == info["retail_sha256"]:
            continue
        stored = tile_spans(offsets_file, pixels_file)
        retail = [unpack_tile(tile) for tile in stored]
        edited = sheet_to_tiles(sheet, info["tiles"])
        offsets = []
        body = bytearray()
        for old_stored, old, new in zip(stored, retail, edited):
            offsets.append(len(body))
            body += old_stored if old is None or new == old else pack_tile(new)
        if bytes(body) == pixels_file:
            continue
        if -(-len(body) // 2048) * 2048 > PIXEL_FILE_LIMIT:
            raise ValueError(f"{sheet.name}: the tiles pack to {len(body):,} bytes, more than the "
                             f"{PIXEL_FILE_LIMIT:,} the game has room for (g_bg_tile_pixels)")
        files[offsets_path] = struct.pack(f"<{len(offsets)}I", *offsets)
        files[pixels_path] = bytes(body)
        changed.append(stage)
    return files, changed


def source_map(stage):
    """The stage's map rows and its 32 palettes, read from the C source."""
    text = (ROOT / "src" / "game" / f"stage{stage}" / f"stage{stage}_map.c").read_text(encoding="utf-8")
    body = text[text.index(f"g_stage{stage}_map["):text.index(f"g_stage{stage}_map_palettes")]
    rows = []
    for line in body.splitlines():
        cells = re.findall(r"MAP_CELL\((\w+), (\w+)\)((?: \| MAP_FLIP_[XY])*)|(MAP_NONE)", line)
        if cells:
            rows.append([None if none else (int(tile, 0), int(palette, 0), "X" in flips, "Y" in flips)
                         for tile, palette, flips, none in cells])
    palette_text = text[text.index(f"g_stage{stage}_map_palettes"):]
    palette_text = palette_text[palette_text.index("{"):palette_text.index("};")]
    colours = [int(value, 16) for value in re.findall(r"0x([0-9A-Fa-f]{4})\b", palette_text)]
    palettes = [colours[start:start + 32] for start in range(0, 32 * 32, 32)]
    return rows, palettes


def colour(value):
    return tuple(((value >> shift) & 0x1F) * 255 // 31 for shift in (0, 5, 10))


def render_map(iso_path, stage, assets_dir=ASSETS):
    """The whole map of a stage as a picture, upright: the first row is at the bottom and a row's first cell
    at the right."""
    rows, palettes = source_map(stage)
    sheet = Path(assets_dir) / f"st{stage}.png"
    _, tiles = stage_tiles(iso_path, stage)
    if sheet.is_file():
        tiles = sheet_to_tiles(sheet, len(tiles))
    picture = Image.new("RGB", (len(rows[0]) * TILE, len(rows) * TILE))
    for row_number, row in enumerate(rows):
        for column, cell in enumerate(row):
            if cell is None:
                continue
            number, palette, flip_x, flip_y = cell
            if number >= len(tiles) or tiles[number] is None:
                continue
            tile = upright(Image.frombytes("P", (TILE, TILE), tiles[number]))
            flat = []
            for value in palettes[palette]:
                flat += colour(value)
            tile.putpalette(flat + [0] * (768 - len(flat)))
            if flip_x:
                tile = tile.transpose(Image.Transpose.FLIP_LEFT_RIGHT)
            if flip_y:
                tile = tile.transpose(Image.Transpose.FLIP_TOP_BOTTOM)
            picture.paste(tile.convert("RGB"), ((len(row) - 1 - column) * TILE, (len(rows) - 1 - row_number) * TILE))
    return picture


def default_iso():
    local = ROOT / "local.json"
    iso = json.loads(local.read_text(encoding="utf-8")).get("iso") if local.is_file() else None
    if not iso:
        raise ValueError("Pass --iso PATH or run tools/setup.py --iso PATH first.")
    return Path(iso)


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("command", choices=("unpack", "preview", "pack"))
    parser.add_argument("--iso", type=Path, help="the retail disc image (default: the one tools/setup.py recorded)")
    parser.add_argument("--assets", type=Path, default=ASSETS)
    parser.add_argument("--force", action="store_true", help="unpack: write the sheets again over edited ones")
    args = parser.parse_args()
    iso_path = args.iso or default_iso()
    if args.command == "unpack":
        manifest = extract_stage_tiles(iso_path, args.assets, args.force)
        print(manifest.parent.relative_to(ROOT) if manifest.is_relative_to(ROOT) else manifest.parent)
    elif args.command == "preview":
        folder = ROOT / "build" / "stage_maps"
        folder.mkdir(parents=True, exist_ok=True)
        for stage in STAGES:
            output = folder / f"stage{stage}_map.png"
            render_map(iso_path, stage, args.assets).save(output)
            print(output.relative_to(ROOT))
    else:
        files, changed = build_tile_files(iso_path, args.assets)
        folder = ROOT / "build" / "mod" / "tiles"
        folder.mkdir(parents=True, exist_ok=True)
        for stage in changed:
            for path in disc_paths(stage):
                (folder / Path(path).name).write_bytes(files[path])
                print(f"{(folder / Path(path).name).relative_to(ROOT)}  {len(files[path]):,} B")
        if not changed:
            print("No sheet differs from the disc.")


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError) as error:
        raise SystemExit(f"Stage tiles: {error}")
