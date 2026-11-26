#ifndef DDPDOJ_STAGE3_BOSS_H
#define DDPDOJ_STAGE3_BOSS_H

#include "types.h"
#include "entity.h"
#include "enemy.h"

/* The stage 3 boss's own part of the enemy state block (reg_a5). */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u16 hp[2];         /* high word first */
    /* 0x1A */ u16 time_left;
} Stage3BossState;

#define STAGE3_BOSS(pointer) ((Stage3BossState *)(pointer))

/* Entities 3 to 5, 8 and 9 of the boss are not drawn. They hold its palettes, its damage flags and other values. */
typedef struct {
    /* 0x00 */ u8 unused_00[6];
    /* 0x06 */ u8 lid;
    /* 0x07 */ u8 body;
    /* 0x08 */ u8 drone;
    /* 0x09 */ u8 legs;
    /* 0x0A */ u8 unused_0A[0x16];
} Stage3BossPalettes;

typedef struct {
    /* 0x00 */ u8 unused_00[6];
    /* 0x06 */ u16 stopped;
    /* 0x08 */ u16 shielded;
    /* 0x0A */ u16 hit_by;
    /* 0x0C */ u8 rage;
    /* 0x0D */ u8 second_form;
    /* 0x0E */ u8 unused_0E[0x12];
} Stage3BossDamage;

typedef struct {
    /* 0x00 */ u8 unused_00[6];
    /* 0x06 */ u16 legs_anim;
    /* 0x08 */ u16 six_gun_anim;
    /* 0x0A */ u16 left_drone_anim;
    /* 0x0C */ u16 right_drone_anim;
    /* 0x0E */ u16 six_gun_dead;
    /* 0x10 */ u16 left_turret_direction;
    /* 0x12 */ u16 right_turret_direction;
    /* 0x14 */ u8 right_turret_dead;
    /* 0x15 */ u8 left_turret_dead;
    /* 0x16 */ u16 left_turret_track_stop;
    /* 0x18 */ u16 right_turret_track_stop;
    /* 0x1A */ u16 unused_1A;
    /* 0x1C */ u16 start_anim;
    /* 0x1E */ u16 lid_anim;
} Stage3BossExtra;

/* What the boss adds to or takes from the values of its attacks. */
typedef struct {
    /* 0x00 */ u8 unused_00[6];
    /* 0x06 */ u8 body_six_gun_shot_sub;
    /* 0x07 */ u8 body_six_gun_burst_add;
    /* 0x08 */ u16 body_six_gun_speed_add;
    /* 0x0A */ u8 lid_six_gun_speed_add;
    /* 0x0B */ u8 lid_six_gun_shot_sub;
    /* 0x0C */ u16 turrets_b_speed_add;
    /* 0x0E */ u16 turrets_b_ways_add;
    /* 0x10 */ u16 turrets_b_spread_add;
    /* 0x12 */ u16 six_gun_speed_add;
    /* 0x14 */ u8 unused_14;
    /* 0x15 */ u8 six_gun_first_frame;
    /* 0x16 */ u8 six_gun_b_rounds_add;
    /* 0x17 */ u8 six_gun_b_burst_add;
    /* 0x18 */ u16 six_gun_b_speed_add;
    /* 0x1A */ u16 unused_1A;
    /* 0x1C */ u16 start_zoom;
    /* 0x1E */ u8 unused_1E[0x2];
} Stage3BossAdjust;

typedef struct {
    /* 0x00 */ u8 unused_00[6];
    /* 0x06 */ u16 main_gun_b_speed_add;
    /* 0x08 */ u16 main_gun_b_burst_add;
    /* 0x0A */ u8 wait_sub;
    /* 0x0B */ u8 main_gun_b_rounds_add;
    /* 0x0C */ u8 unused_0C[0x14];
} Stage3BossAdjustB;

#define STAGE3_PALETTES(pointer) (&((Stage3BossPalettes *)(pointer))[3])
#define STAGE3_DAMAGE(pointer) (&((Stage3BossDamage *)(pointer))[4])
#define STAGE3_EXTRA(pointer) (&((Stage3BossExtra *)(pointer))[5])
#define STAGE3_ADJUST(pointer) (&((Stage3BossAdjust *)(pointer))[8])
#define STAGE3_ADJUST_B(pointer) (&((Stage3BossAdjustB *)(pointer))[9])

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
