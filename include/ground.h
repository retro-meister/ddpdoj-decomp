#ifndef DDPDOJ_GROUND_H
#define DDPDOJ_GROUND_H

#include "types.h"

/*
 * What other units ask of the ground task, and the state of the sideways scroll. The requests are taken up
 * by the task on its next frame.
 */
typedef struct {
    /* 0x00 */ u16 side_move;          /* sideways move still to be made */
    /* 0x02 */ u16 side_by_push;       /* 0: the screen follows the one player there is; else the players push it */
    /* 0x04 */ u16 side_step;          /* this frame's sideways move, handed to both planes */
    /* 0x06 */ u8 other_06[8];
    /* 0x0E */ u16 side_total;         /* every sideways step taken off it */
    /* 0x10 */ u16 side_at_limit;      /* the sideways scroll is at one of its ends */
    /* 0x12 */ u8 other_12[2];
    /* 0x14 */ u16 line_hold_request;  /* 1: hold the scroll line, 2: let it go on */
    /* 0x16 */ u16 speeds_requested;
    /* 0x18 */ u16 speed_request[2];   /* first and second plane */
    /* 0x1C */ u8 other_1C[4];
} GroundState;

extern GroundState g_ground_state;

/*
 * A game that starts at a boss runs its stage forward, without drawing, until the scroll line is the one
 * here; the stage's boss start placements (enemy_tables.h) begin on the lines after it. The two executables
 * differ in three of them. A stage whose events or length change needs its line moved with them.
 */
#define STAGE1_BOSS_START_LINE 463
#define STAGE2_BOSS_START_LINE MAIN_OR_DEATH_LABEL(469, 470)
#define STAGE3_BOSS_START_LINE MAIN_OR_DEATH_LABEL(410, 409)
#define STAGE4_BOSS_START_LINE MAIN_OR_DEATH_LABEL(709, 710)
#define STAGE5_BOSS_START_LINE 793

/* Stage 3 holds the scroll line here (its SCROLL_LINE_HOLD event); the run to the boss lets it go on. */
#define STAGE3_HELD_LINE 228

#endif
