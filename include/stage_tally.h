#ifndef DDPDOJ_STAGE_TALLY_H
#define DDPDOJ_STAGE_TALLY_H

#include "entity.h"

typedef struct {
    Field16 small_digits;
    Field16 small_remaining;
    Field16 large_digits;
    Field16 large_remaining;
    /* 0x08 */ u16 unused_08;
} StageStarTally;

typedef struct {
    u16 palette_overflow;
    /* 0x02 */ u8 unused_02;
    u8 flags;
    Field16 setup_delay;
    Field16 panel_motion_offset;
    Field16 panel_edge_x[2][2];
    Field16 star_frame_timer[2];
    /* 0x14 */ u16 unread_14;
    Field16 inner_edge_delay;
    StageStarTally players[2];
    Field16 count_delay;
    /* 0x2E */ u16 unused_2E[6];
    /* 0x3A */ u16 unread_3A[2];
    Field16 bonus_motion_offset;
    Field16 panel_position[3][2]; /* y, x for P1, P2 and the bonus */
    Field16 bonus_offset_y[4];
    Field16 star_sprite[2][2]; /* high and low sprite words */
    /* 0x5C */ u16 unused_5C[2];
} StageTally;

#define STAGE_TALLY(pointer) ((StageTally *)(pointer))

typedef struct {
    u16 dimmed[32];
    u16 original[32];
    StageTally display;
} StageClearStorage;

extern StageClearStorage g_stage_clear;

#endif
