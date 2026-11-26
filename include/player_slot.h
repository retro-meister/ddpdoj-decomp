#ifndef DDPDOJ_PLAYER_SLOT_H
#define DDPDOJ_PLAYER_SLOT_H

#include "types.h"

/* What a player's slot starts from. The start-up fill puts the address of the lives count in. */
typedef struct {
    /* 0x00 */ u16 other_00[2];
    /* 0x04 */ u16 other_04[2];
    /* 0x08 */ u16 task;
    /* 0x0A */ u16 player;
    /* 0x0C */ u16 lives[2];
} PlayerStart;

/* One player's slot of the game task. */
typedef struct {
    /* 0x00 */ u16 step;            /* index into player_slot_steps, 0: nothing to do */
    /* 0x02 */ u16 other_02;
    /* 0x04 */ u16 other_04;
    /* 0x06 */ u16 other_06;
    /* 0x08 */ u16 lives[2];
    /* 0x0C */ u16 other_0C[2];
    /* 0x10 */ u16 other_10[2];
    /* 0x14 */ u16 task;
    /* 0x16 */ u8 player;
    /* 0x17 */ u8 unused_17;
    /* 0x18 */ u16 ship_task[2];
    /* 0x1C */ u16 other_task_1C[2];
    /* 0x20 */ u16 other_task_20[2];
} PlayerSlot;

#define PLAYER_SLOT(p) ((PlayerSlot *)(p))

extern PlayerStart player_starts[2];

#endif
