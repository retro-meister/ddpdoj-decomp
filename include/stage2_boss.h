#ifndef DDPDOJ_STAGE2_BOSS_H
#define DDPDOJ_STAGE2_BOSS_H

#include "types.h"
#include "entity.h"
#include "enemy.h"

/* The stage 2 boss's own part of the enemy state block (reg_a5). */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u16 hp[2];
    /* 0x1A */ u16 leave_delay;
} Stage2BossState;

#define STAGE2_BOSS(pointer) ((Stage2BossState *)(pointer))

/* Two bytes of a boss slot that are set together as one word: a reload value and its countdown. */
typedef union {
    u16 h;
    s16 sh;
    struct { u8 reload; u8 count; } t;
} SlotTimer;

/* The attack part of the boss slot (reg_a4), one record per attack. */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot;
    /* 0x04 */ u16 speed;
    /* 0x06 */ u16 side;
    /* 0x08 */ u16 volleys_left;
} ShoulderSpread;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot;
    /* 0x04 */ u8 unused_04;
    /* 0x05 */ u8 side;
    /* 0x06 */ u16 shots_left;
    /* 0x08 */ u8 sweep;
    /* 0x09 */ u8 sweep_step;     /* 1 or -1 */
} TorsoRapid;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot;
    /* 0x04 */ u16 barrel;        /* 0 to 12 in steps of 4: which of the four fires next */
    /* 0x06 */ SlotTimer burst;
    /* 0x08 */ u16 side;
} QuadGun;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot;
    /* 0x04 */ u16 unread_04;
    /* 0x06 */ u16 shots_left;
} SideGun;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u16 unused_02[3];
    /* 0x08 */ u16 side;
} ShoulderShot;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 step;           /* 0: turning to the start angles, 1: firing */
    /* 0x04 */ u16 shots_left;
    /* 0x06 */ SlotTimer shot;
    /* 0x08 */ u8 start_angle_b;
    /* 0x09 */ u8 start_angle_a;
    /* 0x0A */ u8 turn_b;         /* 1 or -1 */
    /* 0x0B */ u8 turn_a;
    /* 0x0C */ SlotTimer second;
} ShoulderSweep;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 step;
    /* 0x04 */ u16 rounds_left;
    /* 0x06 */ SlotTimer shot;
    /* 0x08 */ u16 unused_08[2];
    /* 0x0C */ u16 shot_arg;
    /* 0x0E */ u16 side;
    /* 0x10 */ SlotTimer shots;
    /* 0x12 */ u16 extra;
    /* 0x14 */ u8 first_angle;
    /* 0x15 */ u8 angle;
} KneeGun;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 step;
    /* 0x04 */ u16 unused_04[4];
    /* 0x0C */ SlotTimer shot;
} ShoulderMissile;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 turns_left;
    /* 0x03 */ u8 step;           /* 0: waiting, 1: turning */
    /* 0x04 */ SlotTimer shot;
    /* 0x06 */ u8 angle_b;
    /* 0x07 */ u8 angle_a;
    /* 0x08 */ u16 unused_08;
    /* 0x0A */ u16 delay;
    /* 0x0C */ Field16 turned;
} RotatingSpread;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 step;
    /* 0x04 */ SlotTimer shot;
    /* 0x06 */ u16 volleys_left;
} ShoulderCannon;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 step;
    /* 0x04 */ u16 unused_04;
    /* 0x06 */ u8 unused_06;
    /* 0x07 */ u8 angle_step;
    /* 0x08 */ u16 speed;
    /* 0x0A */ u8 unused_0A[6];
    /* 0x10 */ SlotTimer shot;
    /* 0x12 */ u8 unused_12;
    /* 0x13 */ u8 direction;
    /* 0x14 */ u16 shots_left;
    /* 0x16 */ u16 bullet;
    /* 0x18 */ u16 next_bullet;
} BodySpread;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 step;
    /* 0x04 */ SlotTimer shot;
    /* 0x06 */ Field16 toggle;
} BodyRage;

#define SHOULDER_SPREAD(pointer) ((ShoulderSpread *)(pointer))
#define TORSO_RAPID(pointer) ((TorsoRapid *)(pointer))
#define QUAD_GUN(pointer) ((QuadGun *)(pointer))
#define SIDE_GUN(pointer) ((SideGun *)(pointer))
#define SHOULDER_SHOT(pointer) ((ShoulderShot *)(pointer))
#define SHOULDER_SWEEP(pointer) ((ShoulderSweep *)(pointer))
#define KNEE_GUN(pointer) ((KneeGun *)(pointer))
#define SHOULDER_MISSILE(pointer) ((ShoulderMissile *)(pointer))
#define ROTATING_SPREAD(pointer) ((RotatingSpread *)(pointer))
#define SHOULDER_CANNON(pointer) ((ShoulderCannon *)(pointer))
#define BODY_SPREAD(pointer) ((BodySpread *)(pointer))
#define BODY_RAGE(pointer) ((BodyRage *)(pointer))

/* Kinds 0x32 to 0x35 and 0x4D; they take y, x and more from the first words of their request. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ union {
        struct { u16 y; u16 x; u16 move; u16 unused_1C; u16 shot_timer; } at_start;
        struct {
            u8 unused_16;
            u8 seen;
            u16 unused_18;
            u16 frame_list[2];   /* high word first */
            EnemyTimer frame_timer;
        } now;
    };
    /* 0x20 */ u16 frame;
    /* 0x22 */ u8 unread_22;
    /* 0x23 */ u8 unread_23;
    /* 0x24 */ u16 unread_24;
    /* 0x26 */ u16 unread_26;
    /* 0x28 */ EnemyTimer smoke_timer;
    /* 0x2A */ u8 unused_2A;
    /* 0x2B */ u8 unread_2B;
    /* 0x2C */ u16 unread_2C;
    /* 0x2E */ EnemyTimer shot_timer;
    /* 0x30 */ u8 unused_30;
    /* 0x31 */ u8 unread_31;
} Stage2BossShotState;

#define STAGE2_SHOT(pointer) ((Stage2BossShotState *)(pointer))

#endif
