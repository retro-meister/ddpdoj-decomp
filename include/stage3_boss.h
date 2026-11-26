#ifndef DDPDOJ_STAGE3_BOSS_H
#define DDPDOJ_STAGE3_BOSS_H

#include "types.h"
#include "entity.h"
#include "enemy.h"

/* The stage 3 boss's own part of the enemy state block (reg_a5). */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u16 hp[2];         /* high word first */
    /* 0x1A */ u16 leave_delay;
} Stage3BossState;

#define STAGE3_BOSS(pointer) ((Stage3BossState *)(pointer))

/* Two bytes of a boss slot that are set together as one word: a reload value and its countdown. */
typedef union {
    u16 h;
    s16 sh;
    struct { u8 reload; u8 count; } t;
} SlotTimer;

/* The drone the stage 3 boss launches (it takes y, x and attr from its request) and the lid bullet. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ union {
        struct { u16 y; u16 x; u16 attr; } at_start;
        struct { u8 unused_16; u8 seen; u16 unfolded; u16 unused_1A; } now;
    };
    /* 0x1C */ u8 hit_flash;
    /* 0x1D */ u8 palette;
    /* 0x1E */ u8 pause;
    /* 0x1F */ u8 wait;
    /* 0x20 */ u8 burst_shots;
    /* 0x21 */ u8 burst_shots_left;
    /* 0x22 */ u8 unused_22;
    /* 0x23 */ u8 shot_interval;
    /* 0x24 */ EnemyTimer accel;
    /* 0x26 */ u16 muzzle;
    /* 0x28 */ EnemyTimer unfold_timer;
    /* 0x2A */ u16 unfold_frame;
    /* 0x2C */ EnemyTimer spin_timer;
    /* 0x2E */ u16 spin_frame;
    /* 0x30 */ u16 bullet_speed;
    /* 0x32 */ u16 bullet;
    /* 0x34 */ u16 move;
    /* 0x36 */ u8 unused_36;
    /* 0x37 */ u8 start_wait;
} Stage3BossDroneState;

typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 unused_16;
    /* 0x17 */ u8 seen;
    /* 0x18 */ EnemyTimer frame_timer;
    /* 0x1A */ u16 frame;
} LidBulletState;

#define BOSS_DRONE(pointer) ((Stage3BossDroneState *)(pointer))
#define LID_BULLET(pointer) ((LidBulletState *)(pointer))

#endif
