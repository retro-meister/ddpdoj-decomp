#ifndef DDPDOJ_SCORE_CELL_H
#define DDPDOJ_SCORE_CELL_H

#include "types.h"

/* The HUD writes tile to destination + 2 and attributes to destination. */
typedef struct {
    u16 dirty;
    u16 destination[2];
    u16 tile;
    u16 attributes;
} ScoreCell;

typedef struct {
    union {
        ScoreCell players[2];
        struct {
            u8 p1[sizeof(ScoreCell)];
            u8 p2[sizeof(ScoreCell)];
        } bytes;
    } pair;
    /* 0x14 */ u8 unused_14[12];
} ExtraScoreCells;

extern ExtraScoreCells g_extra_score_cells;

#endif
