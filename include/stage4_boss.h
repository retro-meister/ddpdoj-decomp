#ifndef DDPDOJ_STAGE4_BOSS_H
#define DDPDOJ_STAGE4_BOSS_H

#include "types.h"
#include "entity.h"
#include "enemy.h"

/* The stage 4 boss's own part of the enemy state block (reg_a5). */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u16 hp[2];         /* high word first */
    /* 0x1A */ u16 form2_delay;
    /* 0x1C */ u16 leave_delay;
} Stage4BossState;

#define STAGE4_BOSS(pointer) ((Stage4BossState *)(pointer))

/* Two bytes of a boss slot that are set together as one word: a reload value and its countdown. */
typedef union {
    u16 h;
    s16 sh;
    struct { u8 reload; u8 count; } t;
} SlotTimer;

/* The missile and the cutter take their position from their request. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ union {
        struct { u16 y; u16 x; u16 move; } at_start;
        struct {
            u8 step;              /* 0: slowing down, 1: speeding up */
            u8 seen;
            EnemyTimer speed_timer;
            u8 unused_1A;
            u8 direction;
        } now;
    };
    /* 0x1C */ s16 unread_1C;
    /* 0x1E */ s16 unread_1E;
    /* 0x20 */ s16 unread_20;
} Stage4MissileState;

typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ union {
        struct {
            u16 y;
            u16 x;
            u8 radius;
            u8 turn;
            u16 owner[2];
            u8 look;
            u8 angle;
        } at_start;
        struct {
            u8 unread_16;
            u8 seen;
            u8 unread_18;
            u8 unused_19[2];
            u8 angle;
            u16 owner[2];         /* the boss's entities, high word first */
            u16 y_offset;
        } now;
    };
    /* 0x22 */ s16 unread_22;
    /* 0x24 */ u8 unused_24[12];
    /* 0x30 */ u16 center_y;
    /* 0x32 */ u16 center_x;
    /* 0x34 */ u8 unused_34[6];
    /* 0x3A */ s8 unread_3A;
    /* 0x3B */ u8 released;
    /* 0x3C */ u16 frame;
    /* 0x3E */ EnemyTimer frame_timer;
} Stage4CutterState;

#define STAGE4_MISSILE(pointer) ((Stage4MissileState *)(pointer))
#define STAGE4_CUTTER(pointer) ((Stage4CutterState *)(pointer))

#endif
