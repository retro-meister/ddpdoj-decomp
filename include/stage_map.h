#ifndef DDPDOJ_STAGE_MAP_H
#define DDPDOJ_STAGE_MAP_H

#include "types.h"

/*
 * A stage's background map: rows of nine cells, one row for every four scroll lines, each cell a tile of 32
 * by 32 pixels. The ground task copies the rows into the plane (64 rows of 64 cells, g_bg_layer) as the
 * stage scrolls, and the display code draws nine rows of fifteen cells from there.
 *
 * A cell is 32 bits: the tile number (13 bits) in the upper half, and in the lower half the palette (bits 1
 * to 5) and the two flip bits (6: left to right, 7: top to bottom). The maps of the five stages use no flip.
 * A cell of 0 is not drawn.
 */
#define MAP_ROW_CELLS 9
#define MAP_FLIP_X 0x40
#define MAP_FLIP_Y 0x80
#define MAP_CELL(tile, palette) (((u32)(tile) << 16) | ((palette) << 1))
#define MAP_NONE 0

#endif
