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
    /* 0x22 */ u16 leave_delay;   /* frames until the boss gives up and leaves */
    /* 0x24 */ u16 shake;         /* frames of shaking left after a part was destroyed */
} Stage1BossState;

#define STAGE1_BOSS(pointer) ((Stage1BossState *)(pointer))

/*
 * The enemies the boss starts. It leaves their position and more in the first words of the request; their
 * start routines take those and then use the words for their own state.
 *
 * A bullet that can be shot down, kind 0x0F.
 */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ union {
        struct { u16 y; u16 x; u16 move; } at_start;
        struct { u16 unused_16[2]; u16 frame_list[2]; } now;   /* address of its sprites, high word first */
    };
    /* 0x1E */ EnemyTimer frame_timer;
    /* 0x20 */ u16 frame;             /* 0 to 12 in steps of 4 */
    /* 0x22 */ u16 unread_22;
} BreakableBulletState;

#define BREAKABLE_BULLET(pointer) ((BreakableBulletState *)(pointer))

/* The larger one, kind 0x1F: two entities, and four bullets when it is shot down. */
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
            u16 last_sprite[2];       /* the sprite after its last frame, high word first */
            EnemyTimer frame_timer;
            u16 frame;
            u16 unread_22;
            u16 burst_speed;          /* speed of the bullets it leaves */
            u16 unread_26;
        } now;
    };
    /* 0x28 */ u8 unread_28;
    /* 0x29 */ u8 scatter;            /* how far the directions of those bullets are spread at random */
    /* 0x2A */ u16 unused_2A;
    /* 0x2C */ u16 unread_2C;
    /* 0x2E */ u16 unread_2E;
} BreakableBulletBState;

#define BREAKABLE_BULLET_B(pointer) ((BreakableBulletBState *)(pointer))

/* A shell of the main guns, kind 0x1E: slows down, then bursts into three rings of sixteen bullets. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ union {
        struct { u16 y; u16 x; u16 move; u16 burst_speed; u16 spare; } at_start;
        struct { u16 unused_16[3]; u16 burst_speed; EnemyTimer frame_timer; } now;
    };
    /* 0x20 */ u16 frame;
    /* 0x22 */ u16 unused_22;
    /* 0x24 */ u16 unread_24;         /* at_start.spare */
    /* 0x26 */ EnemyTimer slow_timer; /* frames between two steps of slowing down */
} Stage1ShellState;

#define STAGE1_SHELL(pointer) ((Stage1ShellState *)(pointer))

/* What flies past before the boss arrives, kind 0x24. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u16 unused_16;
    /* 0x18 */ u16 frame;
    /* 0x1A */ EnemyTimer frame_timer;
    /* 0x1C */ EnemyTimer timer;      /* frames to wait, then the frames between two steps of speeding up */
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
    /* 0x02 */ u16 shell_spare;   /* handed to the shell, which does not use it */
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

#endif
