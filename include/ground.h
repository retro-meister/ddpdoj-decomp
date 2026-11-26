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
 * The ground task's own record (reg_a5 while it and the scroll events run). Addresses are kept as two words,
 * high word first.
 */
typedef struct {
    /* 0x00 */ u16 state;
    /* 0x02 */ u8 flags;
    /* 0x03 */ u8 flags_03;
    /* 0x04 */ u16 other_04;
    /* 0x06 */ u16 start_line;        /* the scroll line the stage starts at */
    /* 0x08 */ u16 line_held;         /* the scroll line stays while the map goes on */
    /* 0x0A */ u16 map_at[2];         /* first plane: the next row of the map */
    /* 0x0E */ u16 plane_row;         /* and the row of the plane (0 to 63) it goes to */
    /* 0x10 */ u16 second_map_at[2];
    /* 0x14 */ u8 other_14[8];
    /* 0x1C */ u16 speed;             /* first plane, 1/64 pixel a frame */
    /* 0x1E */ u16 line_offset;       /* position inside the scroll line, 0 to 0x1FF */
    /* 0x20 */ u16 row_offset;        /* position inside the map row, 0 to 0x7FF */
    /* 0x22 */ u16 second_speed;
    /* 0x24 */ u8 other_24[4];
    /* 0x28 */ u16 side_x_shown;      /* the sideways scroll position in whole pixels */
    /* 0x2A */ u16 side_x;            /* the sideways scroll position, -0x800 to 0x800 */
    /* 0x2C */ u8 other_2C[5];
    /* 0x31 */ u8 side_edges;         /* bits: a player is at an edge of the screen */
} GroundTask;

#define GROUND_TASK(pointer) ((GroundTask *)(pointer))

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
