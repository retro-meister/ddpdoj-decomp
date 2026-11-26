#ifndef DDPDOJ_STAGE4_BOSS_H
#define DDPDOJ_STAGE4_BOSS_H

#include "types.h"
#include "entity.h"
#include "enemy.h"

/* The stage 4 boss's own part of the enemy state block (reg_a5). */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u16 hp[2];         /* high word first */
    /* 0x1A */ u16 form1_time_left;
    /* 0x1C */ u16 time_left;
} Stage4BossState;

#define STAGE4_BOSS(pointer) ((Stage4BossState *)(pointer))

/* Entities 10 to 12 of the boss are not drawn: they hold its palettes, its damage flags and other values. */
typedef struct {
    /* 0x00 */ u8 unused_00[6];
    /* 0x06 */ u8 body_b;
    /* 0x07 */ u8 body_a;
    /* 0x08 */ u8 right_spinner;
    /* 0x09 */ u8 body_c;
    /* 0x0A */ u8 gun;
    /* 0x0B */ u8 left_spinner;
    /* 0x0C */ u8 left_pod;
    /* 0x0D */ u8 right_pod;
} Stage4BossPalettes;

typedef struct {
    /* 0x00 */ u8 unused_00[6];
    /* 0x06 */ u16 stopped;
    /* 0x08 */ u16 shielded;
    /* 0x0A */ u16 hit_by;
    /* 0x0C */ u8 rage;
    /* 0x0D */ u8 second_form;
} Stage4BossDamage;

typedef struct {
    /* 0x00 */ u8 unused_00[6];
    /* 0x06 */ u8 left_3way_count;
    /* 0x07 */ u8 right_3way_count;
    /* 0x08 */ u8 left_burst;
    /* 0x09 */ u8 right_burst;
    /* 0x0A */ u8 left_random;
    /* 0x0B */ u8 right_random;
    /* 0x0C */ u16 right_pod_y_offset;
    /* 0x0E */ u16 right_pod_x_offset;
    /* 0x10 */ u16 left_pod_y_offset;
    /* 0x12 */ u16 left_pod_x_offset;
    /* 0x14 */ u16 bay_y_offset;
    /* 0x16 */ u16 bay_x_offset;
    /* 0x18 */ u16 right_pod_y_speed;
    /* 0x1A */ u16 left_pod_y_speed;
    /* 0x1C */ u16 bay_b_round;
    /* 0x1E */ u16 cutters_gone;
} Stage4BossExtra;

#define STAGE4_PALETTES(pointer) ((Stage4BossPalettes *)&ENTITY(pointer)[10])
#define STAGE4_DAMAGE(pointer) ((Stage4BossDamage *)&ENTITY(pointer)[11])
#define STAGE4_EXTRA(pointer) ((Stage4BossExtra *)&ENTITY(pointer)[12])

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
        struct {
            u16 y;
            u16 x;
            union { u16 h; struct { u8 dir; u8 speed; } b; } move;
        } at_start;
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

/* The attack part of the boss slot (reg_a4), one record per attack. */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot;
} Basic;

/* The spinner attacks: `pattern` picks one of the routines below. */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u16 pattern;
} Spinner;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u16 pattern;
    /* 0x04 */ SlotTimer shot;
    /* 0x06 */ u16 volleys_left;
    /* 0x08 */ u16 speed;
    /* 0x0A */ u16 arm;           /* 0 to 2 */
} SpinnerVolleys;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u16 pattern;
    /* 0x04 */ SlotTimer shot;
    /* 0x06 */ u16 volleys_left;
    /* 0x08 */ u16 speed;
    /* 0x0A */ u8 unused_0A;
    /* 0x0B */ u8 arm;            /* 0 to 2 */
} SpinnerArms;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u16 pattern;
    /* 0x04 */ SlotTimer shot;
    /* 0x06 */ SlotTimer rounds;
    /* 0x08 */ u16 speed;
    /* 0x0A */ u16 arm;           /* 0 to 2 */
    /* 0x0C */ u16 pass;          /* 0 to 2 */
} SpinnerRounds;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u16 pattern;
    /* 0x04 */ SlotTimer shot;
    /* 0x06 */ u16 shots_left;
    /* 0x08 */ u16 speed;
    /* 0x0A */ u16 wait;
    /* 0x0C */ u16 unread_0C;
    /* 0x0E */ u8 unused_0E;
    /* 0x0F */ u8 aim;
    /* 0x10 */ u16 unread_10;
    /* 0x12 */ u16 unread_12;
    /* 0x14 */ u16 unread_14;
    /* 0x16 */ u8 side;           /* 1 or -1 */
    /* 0x17 */ u8 step;           /* 0: waiting, 1: firing */
    /* 0x18 */ u8 unused_18;
    /* 0x19 */ u8 spread;
    /* 0x1A */ SlotTimer speed_up;
} SpinnerSweep;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u16 unused_02;
    /* 0x04 */ SlotTimer shot;
    /* 0x06 */ u8 aim;
    /* 0x07 */ u8 spread;
    /* 0x08 */ u8 unused_08;
    /* 0x09 */ u8 outer_spread;
} AimedGun;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u16 unused_02;
    /* 0x04 */ SlotTimer turn;
    /* 0x06 */ SlotTimer shot;
    /* 0x08 */ u16 speed;
    /* 0x0A */ u16 volleys;
    /* 0x0C */ u16 rounds_left;
    /* 0x0E */ u8 unused_0E[17];
    /* 0x1F */ u8 direction;
} BothSpinners;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ Field16 sides;     /* b[1] bit 0, bit 1: one side each */
    /* 0x04 */ SlotTimer shot;
    /* 0x06 */ u16 muzzle;
    /* 0x08 */ u16 volleys_left;
} CenterHatch;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u16 unused_02;
    /* 0x04 */ SlotTimer shot;
    /* 0x06 */ SlotTimer burst;
} PodAimed;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 unread_03;
    /* 0x04 */ SlotTimer shot;
    /* 0x06 */ SlotTimer turn;
    /* 0x08 */ u8 unused_08[8];
    /* 0x10 */ u8 direction_b;
    /* 0x11 */ u8 direction_a;
} PodSpray;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ struct { SlotTimer wait; SlotTimer shot; SlotTimer burst; } side[2];
    /* 0x0E */ u16 unused_0E;
    /* 0x10 */ u8 speed_b;
    /* 0x11 */ u8 speed_a;
    /* 0x12 */ u8 turn_a;
    /* 0x13 */ u8 angle_a;
    /* 0x14 */ u8 turn_b;
    /* 0x15 */ u8 angle_b;
    /* 0x16 */ u8 other_16;
    /* 0x17 */ u8 other_17;
} CutterBay;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer wait;
    /* 0x04 */ u16 launched;
    /* 0x06 */ u16 unread_06;
    /* 0x08 */ u8 angle;
    /* 0x09 */ u8 unread_09;
    /* 0x0A */ u8 unused_0A[6];
    /* 0x10 */ u16 release_delay;
} Cutters;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer wait;
    /* 0x04 */ u16 unread_04;
    /* 0x06 */ u16 unread_06;
    /* 0x08 */ u8 unread_08;
    /* 0x09 */ u8 angle;
} CuttersB;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 step;           /* 0, 1 */
    /* 0x04 */ SlotTimer wait;
    /* 0x06 */ SlotTimer shot;
    /* 0x08 */ SlotTimer burst;
    /* 0x0A */ u8 aim;
    /* 0x0B */ u8 speed;
    /* 0x0C */ u16 muzzle;
    /* 0x0E */ u16 aimed;
} CutterBayB;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 unread_03;
    /* 0x04 */ SlotTimer wait;
    /* 0x06 */ SlotTimer shot;
    /* 0x08 */ SlotTimer burst;
    /* 0x0A */ u16 pattern;       /* 0, 4 */
    /* 0x0C */ u8 unused_0C[4];
    /* 0x10 */ Field16 burst_shots;   /* the number is b[0] */
    /* 0x12 */ u16 unread_12;
} BothSides;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 unread_03;
    /* 0x04 */ SlotTimer wait;
    /* 0x06 */ SlotTimer shot;
    /* 0x08 */ SlotTimer burst;
    /* 0x0A */ u16 muzzle;        /* 0 to 3 */
    /* 0x0C */ Field16 aim;       /* the angle is b[1] */
    /* 0x0E */ u16 speed;
    /* 0x10 */ u16 rounds_left;
} RageWings;

#define BASIC(pointer) ((Basic *)(pointer))
#define SPINNER(pointer) ((Spinner *)(pointer))
#define SPINNER_VOLLEYS(pointer) ((SpinnerVolleys *)(pointer))
#define SPINNER_ARMS(pointer) ((SpinnerArms *)(pointer))
#define SPINNER_ROUNDS(pointer) ((SpinnerRounds *)(pointer))
#define SPINNER_SWEEP(pointer) ((SpinnerSweep *)(pointer))
#define AIMED_GUN(pointer) ((AimedGun *)(pointer))
#define BOTH_SPINNERS(pointer) ((BothSpinners *)(pointer))
#define CENTER_HATCH(pointer) ((CenterHatch *)(pointer))
#define POD_AIMED(pointer) ((PodAimed *)(pointer))
#define POD_SPRAY(pointer) ((PodSpray *)(pointer))
#define CUTTER_BAY(pointer) ((CutterBay *)(pointer))
#define CUTTERS(pointer) ((Cutters *)(pointer))
#define CUTTERS_B(pointer) ((CuttersB *)(pointer))
#define CUTTER_BAY_B(pointer) ((CutterBayB *)(pointer))
#define BOTH_SIDES(pointer) ((BothSides *)(pointer))
#define RAGE_WINGS(pointer) ((RageWings *)(pointer))

#endif
