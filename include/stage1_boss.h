#ifndef DDPDOJ_STAGE1_BOSS_H
#define DDPDOJ_STAGE1_BOSS_H

#include "types.h"
#include "entity.h"
#include "enemy.h"

/*
 * The stage 1 boss's own part of the enemy state block (reg_a5). The body and the two sides take damage
 * separately. 32-bit values are two words, high word first, like everywhere in a state block.
 */
typedef struct {
    /* 0x00 */ u8 common[0x16];   /* EnemyState */
    /* 0x16 */ u16 body_hp[2];
    /* 0x1A */ u16 right_hp[2];
    /* 0x1E */ u16 left_hp[2];
    /* 0x22 */ u16 time_left;
    /* 0x24 */ u16 bullet_clear_time;
} Stage1BossState;

#define STAGE1_BOSS(pointer) ((Stage1BossState *)(pointer))

/* Entities 6 to 8 of the boss are not drawn. They hold its gun directions, its damage flags and other values. */
typedef struct {
    /* 0x00 */ u8 unused_00[6];
    /* 0x06 */ u8 gun1_direction;
    /* 0x07 */ u8 gun0_direction;
    /* 0x08 */ u8 gun3_direction;
    /* 0x09 */ u8 gun2_direction;
    /* 0x0A */ u8 unused_0A[0x16];
} Stage1BossGuns;

typedef struct {
    /* 0x00 */ u8 unused_00[6];
    /* 0x06 */ u16 stopped;
    /* 0x08 */ u16 shielded;
    /* 0x0A */ u16 hit_by;
    /* 0x0C */ u8 unused_0C[0x14];
} Stage1BossDamage;

typedef struct {
    /* 0x00 */ u8 unused_00[6];
    /* 0x06 */ u16 next_mode;
    /* 0x08 */ u16 turrets_speed;
    /* 0x0A */ u8 turrets_interval;
    /* 0x0B */ u8 unused_0B[2];
    /* 0x0D */ u8 turrets_burst;
    /* 0x0E */ u16 beam_ways;
    /* 0x10 */ u16 beam_speed;
    /* 0x12 */ u8 spin_width_sub;
    /* 0x13 */ u8 spin_interval_sub;
    /* 0x14 */ u16 spinning;
    /* 0x16 */ u16 unused_16;
    /* 0x18 */ u16 gatling_count;
    /* 0x1A */ u16 enter_anim;
    /* 0x1C */ u8 unused_1C[0x4];
} Stage1BossExtra;

#define STAGE1_GUNS(pointer) (&((Stage1BossGuns *)(pointer))[6])
#define STAGE1_DAMAGE(pointer) (&((Stage1BossDamage *)(pointer))[7])
#define STAGE1_EXTRA(pointer) (&((Stage1BossExtra *)(pointer))[8])

/* The enemies the boss starts take y, x and more from the first words of their request. Kind 0x0F: */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ union {
        struct { u16 y; u16 x; u16 move; } at_start;
        struct { u16 unused_16[2]; u16 frame_list[2]; } now;
    };
    /* 0x1E */ EnemyTimer frame_timer;
    /* 0x20 */ u16 frame;
    /* 0x22 */ u16 unread_22;
} BreakableBulletState;

#define BREAKABLE_BULLET(pointer) ((BreakableBulletState *)(pointer))

/* Kind 0x1F. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ union {
        struct {
            u16 y; u16 x; u16 move;
            u16 burst_speed;
            u16 word_1E;
            u8 unused_20;
            u8 scatter;
            u16 unused_22;
            u16 word_24;
            u16 word_26;
        } at_start;
        struct {
            u16 unused_16[2];
            u16 last_sprite[2];   /* high word first */
            EnemyTimer frame_timer;
            u16 frame;
            u16 unread_22;
            u16 burst_speed;
            u16 unread_26;
        } now;
    };
    /* 0x28 */ u8 unread_28;
    /* 0x29 */ u8 scatter;
    /* 0x2A */ u16 unused_2A;
    /* 0x2C */ u16 unread_2C;
    /* 0x2E */ u16 unread_2E;
} BreakableBulletBState;

#define BREAKABLE_BULLET_B(pointer) ((BreakableBulletBState *)(pointer))

/* The shell of the main guns, kind 0x1E. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ union {
        struct { u16 y; u16 x; u16 move; u16 burst_speed; u16 spare; } at_start;
        struct { u16 unused_16[3]; u16 burst_speed; EnemyTimer frame_timer; } now;
    };
    /* 0x20 */ u16 frame;
    /* 0x22 */ u16 unused_22;
    /* 0x24 */ u16 unread_24;
    /* 0x26 */ EnemyTimer slow_timer;
} Stage1ShellState;

#define STAGE1_SHELL(pointer) ((Stage1ShellState *)(pointer))

/* Kind 0x24. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u16 unused_16;
    /* 0x18 */ u16 frame;
    /* 0x1A */ EnemyTimer frame_timer;
    /* 0x1C */ EnemyTimer timer;
    /* 0x1E */ u16 phase;             /* 0: waiting, 1: speeding up */
} Stage1EntranceState;

#define STAGE1_ENTRANCE(pointer) ((Stage1EntranceState *)(pointer))

/* Two bytes of a boss slot that are set together as one word: a reload value and its countdown. */
typedef union {
    u16 h;
    s16 sh;
    struct { u8 reload; u8 count; } t;
} SlotTimer;

/*
 * The attack part of the boss slot (reg_a4), one record per attack. `running` is cleared when the attack is over.
 * The mode that starts an attack fills in some of its fields. Directions are in 1/256 of a turn where the
 * bullets are fired with the 256-step routines, otherwise in 1/64.
 */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot;
    /* 0x04 */ u16 speed;
    /* 0x06 */ u16 shots_left;
    /* 0x08 */ u16 spread;        /* angle between the pairs; grows by spread_step with every shot */
    /* 0x0A */ u8 unused_0A;
    /* 0x0B */ u8 direction;
    /* 0x0C */ u16 spread_step;
} BodyPortsRage;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot;
    /* 0x04 */ u8 swing;          /* one bit per turret: swinging back */
    /* 0x05 */ u8 volleys_left;
    /* 0x06 */ u8 unused_06;
    /* 0x07 */ u8 aimed;          /* every turret has reached its start angle */
    /* 0x08 */ u8 start_angle[4];
    /* 0x0C */ u16 speed;
} TurretsScatter;

/* The gatling attacks that turn the gun toward the player first. */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer aim_wait;
    /* 0x04 */ u8 target_angle;
    /* 0x05 */ u8 step;
    /* 0x06 */ SlotTimer turn;
    /* 0x08 */ SlotTimer shot;
    /* 0x0A */ u16 shots_left;
    /* 0x0C */ u16 speed;
} Gatling;

/* The beams of the right and the left side. */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 kind;           /* 0: one aimed line, otherwise a fan */
    /* 0x03 */ u8 shots_left;
    /* 0x04 */ SlotTimer shot;
    /* 0x06 */ Field16 spare;
    /* 0x08 */ u16 y;             /* where the bullets start */
    /* 0x0A */ u16 x;
    /* 0x0C */ u8 unused_0C;
    /* 0x0D */ u8 direction;
    /* 0x0E */ u16 unused_0E;
    /* 0x10 */ u16 speed;
} SideBeam;

/* The main guns of the right and the left side. */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 interval;       /* frames between two shots; gets shorter */
    /* 0x03 */ u8 wait;
    /* 0x04 */ s16 unused_04;
    /* 0x06 */ s16 unused_06;
    /* 0x08 */ u8 unused_08[3];
    /* 0x0B */ u8 direction;      /* turns with every shot */
    /* 0x0C */ u8 unused_0C[2];
    /* 0x0E */ SlotTimer speedup; /* shots between two steps of the interval */
    /* 0x10 */ SlotTimer spare;
    /* 0x12 */ u8 unused_12;
    /* 0x13 */ u8 unused_13;
    /* 0x14 */ u16 speed;
} SideMainGun;

/* Both main guns fire shells that can be shot down. */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u16 shell_spare;
    /* 0x04 */ u16 shell_burst_speed;
    /* 0x06 */ SlotTimer shot;
    /* 0x08 */ u16 side;          /* 0 or 1, changes with every volley */
    /* 0x0A */ u16 volleys_left;
} MainGunsBurst;

/* The four ports of the body, fired straight down or toward the player. */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02[6];
    /* 0x08 */ SlotTimer shot;
    /* 0x0A */ u16 shots_left;
    /* 0x0C */ u8 unused_0C;
    /* 0x0D */ u8 direction;
} BodyPorts;

/* The front guns once a side is lost, straight and spread. */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot;
    /* 0x04 */ u16 shots_left;
} FrontGuns;

/* The gatling volleys of the gatling mode; the mode fills in speed and shots_left. */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02[2];
    /* 0x04 */ u8 volley_number;
    /* 0x05 */ u8 speed;
    /* 0x06 */ u16 shots_left;
    /* 0x08 */ s16 unused_08;
    /* 0x0A */ u16 spare_0A;
    /* 0x0C */ u16 spare_0C;
    /* 0x0E */ u8 unused_0E[3];
    /* 0x11 */ u8 direction;
    /* 0x12 */ u16 jitter;        /* random offset of the next bullet */
} GatlingVolley;

/* Both sides fire spreads toward the player in turn. */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u16 unused_02;
    /* 0x04 */ SlotTimer round;   /* wait between two rounds; gets shorter */
    /* 0x06 */ u16 side;          /* 0 or 1, changes with every round */
    /* 0x08 */ SlotTimer volleys; /* volleys in a round */
    /* 0x0A */ SlotTimer shot;
} SideSpread;

#define RAGE(pointer) ((BodyPortsRage *)(pointer))
#define TURRETS(pointer) ((TurretsScatter *)(pointer))
#define GATLING(pointer) ((Gatling *)(pointer))
#define BEAM(pointer) ((SideBeam *)(pointer))
#define MAIN_GUN(pointer) ((SideMainGun *)(pointer))
#define BURST(pointer) ((MainGunsBurst *)(pointer))
#define PORTS(pointer) ((BodyPorts *)(pointer))
#define FRONT_GUNS(pointer) ((FrontGuns *)(pointer))
#define GATLING_C(pointer) ((GatlingVolley *)(pointer))
#define SIDE_SPREAD(pointer) ((SideSpread *)(pointer))

typedef struct {
    u16 sprite_hi;
    u16 sprite_lo;
    u16 offset_y;
    u16 offset_x;
    u16 attributes;
    /* 0x0A */ u16 unused_0A[3];
} BossEntranceFrame;

typedef struct {
    BossEntranceFrame frames[24];
    /* The entrance timer reaches the first ten bytes of the bullet setup. */
    union {
        u16 entity_words[16];
        BossEntranceFrame frames[2];
    } bullet;
} BossEntranceData;

extern BossEntranceData stage1_entrance_data;

#endif
