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
    /* 0x08 */ u8 arm_guns_shot2_sub;
    /* 0x09 */ u8 arm_guns_shot_sub;
    /* 0x0A */ u16 arm_guns_speed_add;
    /* 0x0C */ u8 unused_0C;
    /* 0x0D */ u8 mouth_burst_add;
    /* 0x0E */ u16 mouth_speed_add;
    /* 0x10 */ u16 mouth_speed2_add;
    /* 0x12 */ Field16 arm_guns_b_rounds_add;
    /* 0x14 */ u16 arm_guns_b_speed2_add;
    /* 0x16 */ u8 horn_shot2_sub;
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
    /* 0x0B */ u8 form2_horn_shot2_sub;
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

#endif
