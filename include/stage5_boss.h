#ifndef DDPDOJ_STAGE5_BOSS_H
#define DDPDOJ_STAGE5_BOSS_H

#include "types.h"
#include "entity.h"
#include "enemy.h"

/* The stage 5 boss's own part of the enemy state block (reg_a5). */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u16 hp[2];         /* high word first */
    /* 0x1A */ u16 time_left;
    /* 0x1C */ u16 hp_scratch[2];
} Stage5BossState;

#define STAGE5_BOSS(pointer) ((Stage5BossState *)(pointer))

/* Two bytes of a boss slot that are set together as one word: a reload value and its countdown. */
typedef union {
    u16 h;
    s16 sh;
    struct { u8 reload; u8 count; } t;
} SlotTimer;

/* Entities 7 to 9, 14 and 15 of the boss are not drawn. They hold its palettes, its damage flags and other values. */
typedef struct {
    /* 0x00 */ u8 unused_00[6];
    /* 0x06 */ u8 chest;
    /* 0x07 */ u8 head;
    /* 0x08 */ u8 arm_guns;
    /* 0x09 */ u8 belly;
    /* 0x0A */ u8 wings_opening;
    /* 0x0B */ u8 exhaust;
    /* 0x0C */ u8 form3_body;
    /* 0x0D */ u8 wings;
    /* 0x0E */ u8 unused_0E;
    /* 0x0F */ u8 barrier;
    /* 0x10 */ u8 unused_10[0x10];
} Stage5BossPalettes;

typedef struct {
    /* 0x00 */ u8 unused_00[6];
    /* 0x06 */ u16 stopped;
    /* 0x08 */ u16 shielded;
    /* 0x0A */ u16 hit_by;
    /* 0x0C */ u8 rage;
    /* 0x0D */ u8 form1_second_phase;
    /* 0x0E */ u8 unused_0E;
    /* 0x0F */ u8 form;
    /* 0x10 */ u8 unused_10;
    /* 0x11 */ u8 form3_second_phase;
    /* 0x12 */ u8 unused_12[0xE];
} Stage5BossDamage;

typedef struct {
    /* 0x00 */ u8 unused_00[6];
    /* 0x06 */ u16 head_anim;
    /* 0x08 */ u16 belly_anim;
    /* 0x0A */ u16 exhaust_anim;
    /* 0x0C */ u16 wings_anim;
    /* 0x0E */ u16 tail_direction;
    /* 0x10 */ u8 head_direction;
    /* 0x11 */ u8 tail_track_stop;
    /* 0x12 */ u16 form3_body_anim;
    /* 0x14 */ u16 arm_guns_target_y;
    /* 0x16 */ u16 arm_guns_target_x;
    /* 0x18 */ u16 barrier_anim;
    /* 0x1A */ u16 barrier_time;
    /* 0x1C */ u8 belly_direction;
    /* 0x1D */ u8 arm_guns_b_turn;
    /* 0x1E */ u16 horn_speed_add;
} Stage5BossExtra;

/* What the boss adds to or takes from the values of its attacks. */
typedef struct {
    /* 0x00 */ u8 unused_00[6];
    /* 0x06 */ u8 unused_06;
    /* 0x07 */ u8 arm_guns_rounds_add;
    /* 0x08 */ u8 arm_guns_round_interval_sub;
    /* 0x09 */ u8 arm_guns_shot_interval_sub;
    /* 0x0A */ u16 arm_guns_speed_add;
    /* 0x0C */ u8 unused_0C;
    /* 0x0D */ u8 mouth_burst_add;
    /* 0x0E */ u16 mouth_speed_add;
    /* 0x10 */ u16 mouth_speed2_add;
    /* 0x12 */ Field16 arm_guns_b_rounds_add;
    /* 0x14 */ u16 arm_guns_b_speed2_add;
    /* 0x16 */ u8 horn_round_interval_sub;
    /* 0x17 */ u8 horn_rounds_add;
    /* 0x18 */ u16 arm_guns_speed2_add;
    /* 0x1A */ u8 unused_1A;
    /* 0x1B */ u8 form2_mouth_burst_add;
    /* 0x1C */ u16 form2_mouth_speed_add;
    /* 0x1E */ u16 form2_mouth_speed2_add;
} Stage5BossAdjust;

typedef struct {
    /* 0x00 */ u8 unused_00[6];
    /* 0x06 */ u8 unused_06;
    /* 0x07 */ u8 jet_burst_add;
    /* 0x08 */ u16 jet_speed_add;
    /* 0x0A */ u8 unused_0A;
    /* 0x0B */ u8 form2_horn_round_interval_sub;
    /* 0x0C */ u16 form2_horn_speed_add;
    /* 0x0E */ u8 form3_d_rounds_add;
    /* 0x0F */ u8 stinger_burst_add;
    /* 0x10 */ u8 form3_b_burst_add;
    /* 0x11 */ u8 form3_b_turn;
    /* 0x12 */ u16 form3_b_speed_add;
    /* 0x14 */ u16 form3_b_speed2_add;
    /* 0x16 */ u8 unused_16;
    /* 0x17 */ u8 form3_a_burst_add;
    /* 0x18 */ u16 form3_a_speed_add;
    /* 0x1A */ u16 arms_y_shift;
    /* 0x1C */ u8 rage_turn_interval;
    /* 0x1D */ u8 rage_turn_flag;
    /* 0x1E */ u16 rage_rounds;
} Stage5BossAdjustB;

#define STAGE5_PALETTES(pointer) (&((Stage5BossPalettes *)(pointer))[7])
#define STAGE5_DAMAGE(pointer) (&((Stage5BossDamage *)(pointer))[8])
#define STAGE5_EXTRA(pointer) (&((Stage5BossExtra *)(pointer))[9])
#define STAGE5_ADJUST(pointer) (&((Stage5BossAdjust *)(pointer))[14])
#define STAGE5_ADJUST_B(pointer) (&((Stage5BossAdjustB *)(pointer))[15])

/* A bullet speed and the bullet kind fired with it. */
typedef struct {
    /* 0x00 */ u16 speed;
    /* 0x02 */ u16 bullet;
} Shot;

/*
 * The attack part of the boss slot (reg_a4), one record per attack. `shot` counts down to the next shot, `burst`
 * the shots of a burst and `rounds` the bursts.
 */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot;
    /* 0x04 */ SlotTimer burst;
    /* 0x06 */ SlotTimer rounds;
    /* 0x08 */ u8 round_interval;
    /* 0x09 */ u8 shot_interval;
    /* 0x0A */ Shot shots;
    /* 0x0E */ u16 speed_reset;
    /* 0x10 */ SlotTimer shot_interval_down;
    /* 0x12 */ SlotTimer round_interval_down;
    /* 0x14 */ SlotTimer speed_up;
    /* 0x16 */ SlotTimer rounds_up;
    /* 0x18 */ u16 unused_18;
    /* 0x1A */ u8 scatter_left_middle;
    /* 0x1B */ u8 scatter_left_top;
    /* 0x1C */ u8 scatter_right_top;
    /* 0x1D */ u8 scatter_left_bottom;
    /* 0x1E */ u8 scatter_right_bottom;
    /* 0x1F */ u8 scatter_right_middle;
} ArmGuns;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot;
    /* 0x04 */ SlotTimer burst;
    /* 0x06 */ u8 unused_06;
    /* 0x07 */ u8 shot_interval;
    /* 0x08 */ u8 fixed_direction_right;
    /* 0x09 */ u8 fixed_direction_left;
    /* 0x0A */ Shot aimed;
    /* 0x0E */ Shot fixed[3];
    /* 0x1A */ SlotTimer burst_up;
    /* 0x1C */ SlotTimer speed_up;
    /* 0x1E */ u8 fixed_turn_right;
    /* 0x1F */ u8 fixed_turn_left;
} Mouth;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot;
    /* 0x04 */ SlotTimer burst;
    /* 0x06 */ SlotTimer rounds;
    /* 0x08 */ u8 round_interval;
    /* 0x09 */ u8 shot_interval;
    /* 0x0A */ Shot shots;
    /* 0x0E */ Shot aimed;
    /* 0x12 */ u8 unused_12;
    /* 0x13 */ u8 turn;
    /* 0x14 */ u8 direction_left_middle;
    /* 0x15 */ u8 direction_left_top;
    /* 0x16 */ u8 direction_right_top;
    /* 0x17 */ u8 direction_left_bottom;
    /* 0x18 */ u8 direction_right_bottom;
    /* 0x19 */ u8 direction_right_middle;
} ArmGunsB;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot;
    /* 0x04 */ SlotTimer burst;
    /* 0x06 */ SlotTimer rounds;
    /* 0x08 */ u8 round_interval;
    /* 0x09 */ u8 shot_interval;
    /* 0x0A */ Shot shots;
    /* 0x0E */ u16 muzzle;
    /* 0x10 */ u8 unused_10;
    /* 0x11 */ u8 burst_reset;
    /* 0x12 */ u16 speed_reset;
    /* 0x14 */ u8 unused_14;
    /* 0x15 */ u8 direction_shift;
} Horn;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot;
    /* 0x04 */ SlotTimer burst;
    /* 0x06 */ SlotTimer rounds;
    /* 0x08 */ u8 round_interval;
    /* 0x09 */ u8 shot_interval;
    /* 0x0A */ Shot shots;
    /* 0x0E */ Shot aimed;
    /* 0x12 */ u8 direction;
    /* 0x13 */ u8 turn;
} Form1Rage;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot;
    /* 0x04 */ SlotTimer burst;
    /* 0x06 */ u8 unused_06;
    /* 0x07 */ u8 shot_interval;
    /* 0x08 */ Shot aimed;
    /* 0x0C */ Shot fixed;
    /* 0x10 */ u8 fixed_turn;
    /* 0x11 */ u8 fixed_direction;
} Form2Mouth;

typedef Form2Mouth Stinger;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot;
    /* 0x04 */ SlotTimer burst;
    /* 0x06 */ u8 round_interval;
    /* 0x07 */ u8 shot_interval;
    /* 0x08 */ u16 speed;
    /* 0x0A */ u16 side_bullet;
    /* 0x0C */ u16 middle_bullet;
    /* 0x0E */ u16 muzzle;
} Jet;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot;
    /* 0x04 */ SlotTimer burst;
    /* 0x06 */ SlotTimer rounds;
    /* 0x08 */ u8 round_interval;
    /* 0x09 */ u8 shot_interval;
    /* 0x0A */ Shot large;
    /* 0x0E */ Shot small;
    /* 0x12 */ u16 muzzle;
} Form2Horn;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot;
    /* 0x04 */ SlotTimer burst;
    /* 0x06 */ u8 round_interval;
    /* 0x07 */ u8 shot_interval;
    /* 0x08 */ u16 speed;
    /* 0x0A */ u16 side_bullet;
    /* 0x0C */ u16 middle_bullet;
    /* 0x0E */ u8 turn;
    /* 0x0F */ u8 direction;
} Form3A;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot;
    /* 0x04 */ SlotTimer burst;
    /* 0x06 */ u8 unused_06;
    /* 0x07 */ u8 shot_interval;
    /* 0x08 */ Shot shots;
    /* 0x0C */ Shot child;
    /* 0x10 */ u8 direction;
    /* 0x11 */ u8 turn;
} Form3B;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot;
    /* 0x04 */ SlotTimer burst;
    /* 0x06 */ u8 track_direction;
    /* 0x07 */ u8 shot_interval;
    /* 0x08 */ Shot shots;
    /* 0x0C */ Field16 other_0C;
} Form3C;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot;
    /* 0x04 */ SlotTimer burst;
    /* 0x06 */ SlotTimer rounds;
    /* 0x08 */ u8 round_interval;
    /* 0x09 */ u8 shot_interval;
    /* 0x0A */ Shot shots;
    /* 0x0E */ u8 turn;
    /* 0x0F */ u8 direction;
    /* 0x10 */ SlotTimer spin_timer;
    /* 0x12 */ u16 spin_step;
    /* 0x14 */ SlotTimer accel_timer;
    /* 0x16 */ u16 accel_step;
    /* 0x18 */ u16 vector_speed;
    /* 0x1A */ u8 unused_1A;
    /* 0x1B */ u8 track_direction;
    /* 0x1C */ u16 spin_step_add;
} Form3D;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot[3];
    /* 0x08 */ SlotTimer burst;
    /* 0x0A */ Shot volley[3];
    /* 0x16 */ struct { u8 turn; u8 direction; } aim[3];
    /* 0x1C */ u16 until_second;
    /* 0x1E */ u16 until_third;
} Form3Rage;

#define ARM_GUNS(pointer) ((ArmGuns *)(pointer))
#define MOUTH(pointer) ((Mouth *)(pointer))
#define ARM_GUNS_B(pointer) ((ArmGunsB *)(pointer))
#define HORN(pointer) ((Horn *)(pointer))
#define FORM1_RAGE(pointer) ((Form1Rage *)(pointer))
#define FORM2_MOUTH(pointer) ((Form2Mouth *)(pointer))
#define JET(pointer) ((Jet *)(pointer))
#define FORM2_HORN(pointer) ((Form2Horn *)(pointer))
#define STINGER(pointer) ((Stinger *)(pointer))
#define FORM3_A(pointer) ((Form3A *)(pointer))
#define FORM3_B(pointer) ((Form3B *)(pointer))
#define FORM3_C(pointer) ((Form3C *)(pointer))
#define FORM3_D(pointer) ((Form3D *)(pointer))
#define FORM3_RAGE(pointer) ((Form3Rage *)(pointer))

#endif
