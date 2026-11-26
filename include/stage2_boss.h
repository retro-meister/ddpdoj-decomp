#ifndef DDPDOJ_STAGE2_BOSS_H
#define DDPDOJ_STAGE2_BOSS_H

#include "types.h"
#include "entity.h"
#include "enemy.h"

/*
 * What the stage 2 boss fires as enemies of their own: the shoulder bullet, the spread bullet, the cannon shell,
 * the dropped bomb and the ripple it leaves on the water. The boss leaves their position and more in the first
 * words of the request; the start routine takes those and then uses the words for its own state. Each kind
 * uses a part of the record; the `unread` fields are set and not read.
 */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ union {
        struct { u16 y; u16 x; u16 move; u16 unused_1C; u16 shot_timer; } at_start;
        struct {
            u8 unused_16;
            u8 seen;                  /* it has been inside the screen */
            u16 unused_18;
            u16 frame_list[2];        /* spread bullet: address of its sprites, high word first */
            EnemyTimer frame_timer;
        } now;
    };
    /* 0x20 */ u16 frame;
    /* 0x22 */ u8 unread_22;
    /* 0x23 */ u8 unread_23;
    /* 0x24 */ u16 unread_24;
    /* 0x26 */ u16 unread_26;
    /* 0x28 */ EnemyTimer smoke_timer;    /* cannon shell: frames between two puffs */
    /* 0x2A */ u8 unused_2A;
    /* 0x2B */ u8 unread_2B;
    /* 0x2C */ u16 unread_2C;
    /* 0x2E */ EnemyTimer shot_timer;     /* cannon shell: from at_start.shot_timer */
    /* 0x30 */ u8 unused_30;
    /* 0x31 */ u8 unread_31;
} Stage2BossShotState;

#define STAGE2_SHOT(pointer) ((Stage2BossShotState *)(pointer))

#endif
