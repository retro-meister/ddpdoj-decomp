#include "common.h"
#include "entity.h"
#include "enemy_kinds.h"
#include "stage3_boss.h"

extern void *D_0026CC40[8];
extern void *D_0026CD60[8];
extern void *D_0026CE00[8];
extern void *D_0026CE20[8];
extern void *D_0026CF40[8];
extern void *D_0026CFE0[8];
extern void *D_0026D080[8];
extern void *D_0026D1D0[8];

/* The attack part of the boss slot (reg_a4), one record per attack. */
typedef struct {
    /* 0x00 */ u16 speed;
    /* 0x02 */ u16 bullet;
} Shot;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u16 launched;
} LaunchDrone;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer wait;
    /* 0x04 */ SlotTimer rounds;
    /* 0x06 */ u8 shot_interval;
    /* 0x07 */ u8 unused_07;
    /* 0x08 */ u16 speed;
    /* 0x0A */ u16 bullet;
    /* 0x0C */ u8 unused_0C[10];
    /* 0x16 */ u8 turn;
    /* 0x17 */ u8 direction;
    /* 0x18 */ SlotTimer salvo;
} MainGun;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer shot;
    /* 0x04 */ u8 unused_04[13];
    /* 0x11 */ u8 other_11;
    /* 0x12 */ u8 unused_12[4];
    /* 0x16 */ u8 turn_a;
    /* 0x17 */ u8 direction_a;
    /* 0x18 */ u8 turn_b;
    /* 0x19 */ u8 direction_b;
} SideTurrets;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ struct { SlotTimer wait; SlotTimer burst; } side[2];
    /* 0x0A */ u8 unused_0A;
    /* 0x0B */ u8 shot_interval;
    /* 0x0C */ u16 bullet_arg;
} LidSixGun;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 wait;
    /* 0x04 */ u8 unused_04;
    /* 0x05 */ u8 volleys_left;
    /* 0x06 */ u8 unused_06;
    /* 0x07 */ u8 shot_interval;
    /* 0x08 */ Shot aimed;
    /* 0x0C */ Shot fan_a;
    /* 0x10 */ Shot fan_b;
    /* 0x14 */ Shot three_way;
    /* 0x18 */ u8 three_way_angle;
    /* 0x19 */ u8 fan_angle;
    /* 0x1A */ u8 unused_1A[2];
    /* 0x1C */ u8 three_way_turn;
    /* 0x1D */ u8 fan_turn;
} BodySixGun;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 wait;
    /* 0x04 */ u16 shots_left;
    /* 0x06 */ u16 shots;
    /* 0x08 */ u8 pause;
    /* 0x09 */ u8 shot_interval;
    /* 0x0A */ u8 other_0A;
    /* 0x0B */ u8 rounds_left;
    /* 0x0C */ u16 speed;
    /* 0x0E */ u16 shots_step;
} MainGunB;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 wait_a;
    /* 0x04 */ u8 shot_interval;
    /* 0x05 */ u8 wait_b;
    /* 0x06 */ Shot shot_a;
    /* 0x0A */ Shot shot_b;
    /* 0x0E */ u16 count;
    /* 0x10 */ u16 spread;
} SideTurretsB;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 wait;
    /* 0x04 */ SlotTimer burst;
    /* 0x06 */ u8 next_interval;
    /* 0x07 */ u8 shot_interval;
    /* 0x08 */ u8 turn;
    /* 0x09 */ u8 other_09;
    /* 0x0A */ u8 unused_0A;
    /* 0x0B */ u8 rounds_left;
    /* 0x0C */ u8 unused_0C;
    /* 0x0D */ u8 round_pause;
    /* 0x0E */ Shot shot_a;
    /* 0x12 */ Shot shot_b;
    /* 0x16 */ u8 unused_16[4];
    /* 0x1A */ u16 speed_step;
    /* 0x1C */ u16 ramp_step;
    /* 0x1E */ u8 aimed;
    /* 0x1F */ u8 direction;
} SixGun;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 wait;
    /* 0x04 */ SlotTimer burst;
    /* 0x06 */ u8 next_interval;
    /* 0x07 */ u8 shot_interval;
    /* 0x08 */ u8 turn;
    /* 0x09 */ u8 burst_step;
    /* 0x0A */ u8 unused_0A;
    /* 0x0B */ u8 rounds_left;
    /* 0x0C */ u8 unused_0C;
    /* 0x0D */ u8 round_pause;
    /* 0x0E */ Shot shot_a;
    /* 0x12 */ Shot shot_b;
    /* 0x16 */ u16 speed_step;
    /* 0x18 */ u16 ramp_step;
    /* 0x1A */ u8 direction;
    /* 0x1B */ u8 aimed;
} SixGunB;

#define LAUNCH_DRONE(pointer) ((LaunchDrone *)(pointer))
#define MAIN_GUN(pointer) ((MainGun *)(pointer))
#define SIDE_TURRETS(pointer) ((SideTurrets *)(pointer))
#define LID_SIX_GUN(pointer) ((LidSixGun *)(pointer))
#define BODY_SIX_GUN(pointer) ((BodySixGun *)(pointer))
#define MAIN_GUN_B(pointer) ((MainGunB *)(pointer))
#define SIDE_TURRETS_B(pointer) ((SideTurretsB *)(pointer))
#define SIX_GUN(pointer) ((SixGun *)(pointer))
#define SIX_GUN_B(pointer) ((SixGunB *)(pointer))


void stage3_boss_launch_drone_start(void);
void stage3_boss_launch_drone(void);
void stage3_boss_fire_main_gun_start(void);
void stage3_boss_fire_main_gun(void);
void stage3_boss_fire_side_turrets_start(void);
void stage3_boss_fire_side_turrets(void);
void stage3_boss_fire_lid_six_gun_start(void);
void stage3_boss_fire_lid_six_gun(void);
void stage3_boss_fire_body_six_gun_start(void);
void stage3_boss_fire_body_six_gun(void);
void stage3_boss_fire_six_gun_start(void);
void stage3_boss_fire_six_gun(void);
void stage3_boss_fire_main_gun_b_start(void);
void stage3_boss_fire_main_gun_b(void);
void stage3_boss_fire_side_turrets_b_start(void);
void stage3_boss_fire_side_turrets_b(void);
void stage3_boss_fire_six_gun_b_start(void);
void stage3_boss_fire_six_gun_b(void);

/* The set-up routine and the per-frame routine of every attack, by attack number. */
void (*stage3_boss_fire_routines[])(void) = {
    stage3_boss_launch_drone_start,
    stage3_boss_launch_drone,
    stage3_boss_fire_main_gun_start,
    stage3_boss_fire_main_gun,
    stage3_boss_fire_side_turrets_start,
    stage3_boss_fire_side_turrets,
    stage3_boss_fire_lid_six_gun_start,
    stage3_boss_fire_lid_six_gun,
    stage3_boss_fire_body_six_gun_start,
    stage3_boss_fire_body_six_gun,
    stage3_boss_fire_six_gun_start,
    stage3_boss_fire_six_gun,
    stage3_boss_fire_main_gun_b_start,
    stage3_boss_fire_main_gun_b,
    stage3_boss_fire_side_turrets_b_start,
    stage3_boss_fire_side_turrets_b,
    stage3_boss_fire_six_gun_b_start,
    stage3_boss_fire_six_gun_b,
    0,
    0,
};

void stage3_boss_launch_drone(void);
void stage3_boss_fire_body_six_gun(void);
void stage3_boss_fire_main_gun_b(void);
void stage3_boss_fire_side_turrets_b(void);
void stage3_boss_fire_six_gun(void);
void stage3_boss_fire_six_gun_b(void);


void stage3_boss_launch_drone_start(void) {
    LAUNCH_DRONE(reg_a4)->launched = 0;
    stage3_boss_launch_drone();
}

s32 boss_part_hide();
s32 spawn_request_add();
s32 rng_next();

void stage3_boss_launch_drone(void) {
    u32 temp_s0;

    if (LAUNCH_DRONE(reg_a4)->launched != 0) {
        reg_d0.w = 2;
        boss_part_hide();
        reg_d0.w = 3;
        boss_part_hide();
        LAUNCH_DRONE(reg_a4)->running = 0;
        return;
    }
    reg_d0.h[0] = ENEMY_STAGE3_BOSS_DRONE;
    spawn_request_add();
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[1] += 0x4C0;
    reg_d0.h[0] += 0x7FFF + 0x7601;
    BOSS_DRONE(reg_a0)->at_start.y = (u16) reg_d0.h[1];
    BOSS_DRONE(reg_a0)->at_start.x = (u16) reg_d0.h[0];
    reg_d0.w = 0;
    reg_d0.b[0] = STAGE3_PALETTES(reg_a6)->drone;
    BOSS_DRONE(reg_a0)->at_start.attr = (u16) reg_d0.h[0];
    BOSS_DRONE(reg_a0)->move = 0x184;
    rng_next();
    temp_s0 = reg_d0.w;
    BOSS_DRONE(reg_a0)->start_wait = (u8) reg_d0.b[0];
    reg_d0.h[0] = ENEMY_STAGE3_BOSS_DRONE;
    spawn_request_add();
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[1] += 0x4C0;
    reg_d0.h[0] += 0xA00;
    BOSS_DRONE(reg_a0)->at_start.y = (u16) reg_d0.h[1];
    BOSS_DRONE(reg_a0)->at_start.x = (u16) reg_d0.h[0];
    reg_d0.h[0] = 0x4000;
    reg_d0.b[0] = STAGE3_PALETTES(reg_a6)->drone;
    BOSS_DRONE(reg_a0)->at_start.attr = (u16) reg_d0.h[0];
    BOSS_DRONE(reg_a0)->move = 0x17C;
    reg_d0.w = temp_s0;
    BOSS_DRONE(reg_a0)->start_wait = (u8) reg_d0.b[0];
    LAUNCH_DRONE(reg_a4)->launched = 1U;
}

void func_001CE980(void) {
    void bullet_fire256_fast(void);
    s32 status = reg_d1.b[0];

    if (status < 0x20 || status > 0xE0) {
        reg_d0.w += 0x80000;
    }
    bullet_fire256_fast();
}

s32 func_001713C0();
s32 rng_next_unsigned();
extern u32 D_0028DB20;
extern u16 g_loop;

void stage3_boss_fire_main_gun_start(void) {
    s32 temp_a1;
    u16 *temp_a0;
    u16 temp_a2;
    func_001713C0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    temp_a2 = reg_d0.h[0];
    temp_a1 = temp_a2 & ~3;
    reg_a0 = *(u8 **)(((u8 *)D_0026CC40) + temp_a1);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028DB20 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.b[0] = 8;
    if (g_loop != 0) {
        reg_d0.b[0] = 4;
    }
    MAIN_GUN(reg_a4)->shot_interval = (u8) reg_d0.b[0];
    rng_next_unsigned();
    MAIN_GUN(reg_a4)->direction = (u8) reg_d0.b[0];
    reg_d1.h[0] = 3;
    rng_next_unsigned();
    if ((s8) reg_d0.b[0] < 0) {
        reg_d1.h[0] = 0xFFFD;
    }
    MAIN_GUN(reg_a4)->turn = (u8) reg_d1.b[0];
    MAIN_GUN(reg_a4)->salvo.h = 0x606;
}

s32 enemy_switch_target_player();

void stage3_boss_fire_main_gun(void) {
    u16 var_a0;

    reg_tmp.b[0] = MAIN_GUN(reg_a4)->wait.t.count;
    MAIN_GUN(reg_a4)->wait.t.count -= 1;
    if (reg_tmp.b[0] == 0) {
        MAIN_GUN(reg_a4)->wait.t.count = (u8) MAIN_GUN(reg_a4)->shot_interval;
        reg_d1.b[0] = MAIN_GUN(reg_a4)->direction;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        var_a0 = ENTITY(reg_a6)->x.h;
        reg_d2.h[0] = var_a0;
        reg_d3.w = 0xE2000000;
        reg_d7.w = 3;
        reg_d4.w = 0;
        do {
            reg_d0.h[1] = MAIN_GUN(reg_a4)->speed;
            reg_d0.h[0] = MAIN_GUN(reg_a4)->bullet;
            func_001CE980();
            var_a0 = (u32)reg_d1.h[0] + 0x40;
            reg_d1.h[0] = var_a0;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        reg_d0.b[0] = MAIN_GUN(reg_a4)->turn;
        MAIN_GUN(reg_a4)->direction += reg_d0.b[0];
        MAIN_GUN(reg_a4)->salvo.t.count -= 1;
        if (MAIN_GUN(reg_a4)->salvo.t.count == 0) {
            MAIN_GUN(reg_a4)->salvo.t.count = (u8) MAIN_GUN(reg_a4)->salvo.t.reload;
            MAIN_GUN(reg_a4)->wait.t.count = 0x12U;
        }
        reg_tmp.b[0] = MAIN_GUN(reg_a4)->rounds.t.count;
        MAIN_GUN(reg_a4)->rounds.t.count -= 1;
        if (reg_tmp.b[0] == 0) {
            MAIN_GUN(reg_a4)->turn *= -1;
            enemy_switch_target_player();
            MAIN_GUN(reg_a4)->rounds.t.count = (u8) MAIN_GUN(reg_a4)->rounds.t.reload;
            MAIN_GUN(reg_a4)->wait.t.count = (u8) MAIN_GUN(reg_a4)->wait.t.reload;
        }
    }
}

s32 bullet_fire256_fixed();

void func_001CEC30(void) {
    s32 bullet_fire256_fast();
    u32 tmp;

    if (g_loop != 0) goto next_4;
    reg_d5.w = 0xFFFE0004;
    reg_d7.h[0] = 2;
    reg_d6.h[0] = 0x55;
    reg_tmp.h[1] = STAGE3_BOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE3_BOSS(reg_a5)->hp[1];
    if (!(reg_tmp.w < 0x8C00U)) goto loop_1;
    reg_d5.w = 0xFFFE0004;
    reg_d7.h[0] = 3;
    reg_d6.h[0] = 0x40;
loop_1:
    reg_d0.w = reg_d5.w;
    if (reg_d1.b[0] < 0x40) goto next_2;
    if (reg_d1.b[0] <= 0xC0) goto next_3;
next_2:
    reg_d0.w += 0x80000;
next_3:
    bullet_fire256_fixed();
    reg_d1.b[0] += reg_d6.b[0];
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    goto block_rts;
next_4:
    reg_d5.w = 0xFFFE0004;
    reg_d7.h[0] = 4;
    reg_d6.h[0] = 0x33;
    reg_tmp.h[1] = STAGE3_BOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE3_BOSS(reg_a5)->hp[1];
    if (!(reg_tmp.w < 0x8C00U)) goto loop_5;
    reg_d5.w = 0xFFFE0004;
    reg_d7.h[0] = 5;
    reg_d6.h[0] = 0x2A;
loop_5:
    reg_d0.w = reg_d5.w;
    if (reg_d1.b[0] < 0x40) goto next_6;
    if (reg_d1.b[0] <= 0xC0) goto next_7;
next_6:
    reg_d0.w += 0x100000;
next_7:
    bullet_fire256_fast();
    reg_d1.b[0] += reg_d6.b[0];
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_5;
block_rts:
    return;
}

s32 rng_next_bit();
extern u32 D_0028DB24;

void stage3_boss_fire_side_turrets_start(void) {
    s32 temp_a1;
    u16 *temp_a0;
    u16 temp_a2;
    func_001713C0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    temp_a2 = reg_d0.h[0];
    temp_a1 = temp_a2 & ~3;
    reg_a0 = *(u8 **)(((u8 *)D_0026CD60) + temp_a1);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028DB24 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    rng_next_bit();
    SIDE_TURRETS(reg_a4)->other_11 = (u8) reg_d0.b[0];
    rng_next_unsigned();
    SIDE_TURRETS(reg_a4)->direction_a = (u8) reg_d0.b[0];
    SIDE_TURRETS(reg_a4)->turn_a = 5;
    reg_d0.b[0] *= -1;
    SIDE_TURRETS(reg_a4)->direction_b = (u8) reg_d0.b[0];
    SIDE_TURRETS(reg_a4)->turn_b = 0xFB;
    if (g_loop != 0) {
        SIDE_TURRETS(reg_a4)->shot.t.reload = 3;
    }
}

extern u16 g_direction_offsets_400[];

void stage3_boss_fire_side_turrets(void) {
    reg_tmp.b[0] = SIDE_TURRETS(reg_a4)->shot.t.count;
    SIDE_TURRETS(reg_a4)->shot.t.count -= 1;
    if (reg_tmp.b[0] == 0) {
        SIDE_TURRETS(reg_a4)->shot.t.count = (u8) SIDE_TURRETS(reg_a4)->shot.t.reload;
        reg_tmp.h[1] = STAGE3_BOSS(reg_a5)->hp[0];
        reg_tmp.h[0] = STAGE3_BOSS(reg_a5)->hp[1];
        if ((u32) reg_tmp.w < 0x8C00U) {
            SIDE_TURRETS(reg_a4)->turn_a = 5U;
            SIDE_TURRETS(reg_a4)->turn_b = 0xFBU;
            SIDE_TURRETS(reg_a4)->shot.t.reload = 3U;
            if (g_loop != 0) {
                SIDE_TURRETS(reg_a4)->shot.t.reload = 3U;
            }
        }
        reg_a3 = (u8 *)(g_direction_offsets_400);
        reg_d1.h[0] = STAGE3_EXTRA(reg_a6)->left_turret_direction;
        reg_d0.h[0] = reg_d1.h[0];
        reg_d0.h[0] &= 0x3E;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
        reg_d3.h[0] = ((((u16)reg_d0.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(((u16)reg_d0.h[0]) + 2) & ~1)) : *(u16 *)reg_a3;
        reg_d3.w += 0x11000080;
        reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
        reg_d4.w = 0;
        reg_d0.b[0] = SIDE_TURRETS(reg_a4)->turn_a;
        SIDE_TURRETS(reg_a4)->direction_a += reg_d0.b[0];
        reg_d1.b[0] = SIDE_TURRETS(reg_a4)->direction_a;
        func_001CEC30();
        reg_d1.h[0] = STAGE3_EXTRA(reg_a6)->right_turret_direction;
        reg_d5.h[0] = reg_d1.h[0];
        reg_d5.h[0] &= 0x3E;
        reg_d5.h[0] += reg_d5.h[0];
        reg_d3.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a3;
        reg_d3.h[0] = ((((u16)reg_d5.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(((u16)reg_d5.h[0]) + 2) & ~1)) : *(u16 *)reg_a3;
        reg_d3.w += 0x1100FF80;
        reg_d2.h[1] = ENTITY(reg_a6)[2].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[2].x.h;
        reg_d4.w = 0;
        reg_d0.b[0] = SIDE_TURRETS(reg_a4)->turn_b;
        SIDE_TURRETS(reg_a4)->direction_b += reg_d0.b[0];
        reg_d1.b[0] = SIDE_TURRETS(reg_a4)->direction_b;
        func_001CEC30();
        enemy_switch_target_player();
    }
}

extern u32 D_0028DB28;
extern u16 D_0028DB70[];
extern u32 D_0028DB78;

void stage3_boss_fire_lid_six_gun_start(void) {
    func_001713C0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = *(u8 **)(((u8 *)D_0026CE00) + (reg_d0.h[0] & ~3));
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028DB28 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *)(D_0028DB70);
    reg_d0.w = ((u32) D_0028DB78 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.b[0] = STAGE3_ADJUST(reg_a6)->lid_six_gun_shot_sub;
    LID_SIX_GUN(reg_a4)->side[0].wait.t.reload -= reg_d0.b[0];
    reg_d0.b[0] = STAGE3_ADJUST_B(reg_a6)->wait_sub;
    reg_d0.b[0] = (s8) reg_d0.b[0] * 2;
    LID_SIX_GUN(reg_a4)->side[0].wait.t.count += reg_d0.b[0];
    LID_SIX_GUN(reg_a4)->side[1].wait.t.count += reg_d0.b[0];
}

void stage3_boss_fire_lid_six_gun(void) {
    reg_tmp.b[0] = LID_SIX_GUN(reg_a4)->side[0].wait.t.count;
    LID_SIX_GUN(reg_a4)->side[0].wait.t.count -= 1;
    if (reg_tmp.b[0] == 0) {
        LID_SIX_GUN(reg_a4)->side[0].wait.t.count = (u8) LID_SIX_GUN(reg_a4)->shot_interval;
        reg_d0.h[0] = 0x9A;
        spawn_request_add();
        reg_d0.h[1] = ENTITY(reg_a6)->y.h;
        reg_d0.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[1] += 0x7FFF + 0x5C81;
        reg_d0.h[0] += 0x7FFF + 0x7801;
        *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
        reg_d0.b[0] = 0xD;
        reg_d0.b[0] += STAGE3_ADJUST(reg_a6)->lid_six_gun_speed_add;
        *(u8 *)(reg_a0 + 0x1B) = reg_d0.b[0];
        *(u8 *)(reg_a0 + 0x1A) = 0x80;
        *(u16 *)(reg_a0 + 0x1C) = (u16) LID_SIX_GUN(reg_a4)->bullet_arg;
        reg_tmp.h[0] = LID_SIX_GUN(reg_a4)->bullet_arg;
        LID_SIX_GUN(reg_a4)->bullet_arg -= 4;
        if ((s32) reg_tmp.h[0] < 4) {
            LID_SIX_GUN(reg_a4)->bullet_arg = 8U;
        }
        reg_tmp.b[0] = LID_SIX_GUN(reg_a4)->side[0].burst.t.count;
        LID_SIX_GUN(reg_a4)->side[0].burst.t.count -= 1;
        if (reg_tmp.b[0] == 0) {
            LID_SIX_GUN(reg_a4)->side[0].burst.t.count = (u8) LID_SIX_GUN(reg_a4)->side[0].burst.t.reload;
            LID_SIX_GUN(reg_a4)->side[0].wait.t.count = (u8) LID_SIX_GUN(reg_a4)->side[0].wait.t.reload;
        }
    }
    reg_tmp.b[0] = LID_SIX_GUN(reg_a4)->side[1].wait.t.count;
    LID_SIX_GUN(reg_a4)->side[1].wait.t.count -= 1;
    if (reg_tmp.b[0] == 0) {
        LID_SIX_GUN(reg_a4)->side[1].wait.t.count = (u8) LID_SIX_GUN(reg_a4)->shot_interval;
        reg_d0.h[0] = 0x9A;
        spawn_request_add();
        reg_d0.h[1] = ENTITY(reg_a6)->y.h;
        reg_d0.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[1] += 0x7FFF + 0x5C81;
        reg_d0.h[0] += 0x800;
        *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
        reg_d0.b[0] = 0xD;
        reg_d0.b[0] += STAGE3_ADJUST(reg_a6)->lid_six_gun_speed_add;
        *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
        *(u8 *)(reg_a0 + 0x1A) = 0x80;
        *(u16 *)(reg_a0 + 0x1C) = (u16) LID_SIX_GUN(reg_a4)->bullet_arg;
        reg_tmp.h[0] = LID_SIX_GUN(reg_a4)->bullet_arg;
        LID_SIX_GUN(reg_a4)->bullet_arg -= 4;
        if ((s32) reg_tmp.h[0] < 4) {
            LID_SIX_GUN(reg_a4)->bullet_arg = 8U;
        }
        reg_tmp.b[0] = LID_SIX_GUN(reg_a4)->side[1].burst.t.count;
        LID_SIX_GUN(reg_a4)->side[1].burst.t.count -= 1;
        if (reg_tmp.b[0] == 0) {
            LID_SIX_GUN(reg_a4)->side[1].burst.t.count = (u8) LID_SIX_GUN(reg_a4)->side[1].burst.t.reload;
            LID_SIX_GUN(reg_a4)->side[1].wait.t.count = (u8) LID_SIX_GUN(reg_a4)->side[1].wait.t.reload;
        }
    }
}

extern u32 D_0028DB7C;
extern u16 D_0028DB80[];
extern u32 D_0028DB84;
extern u16 D_0028DB88[];
extern u32 D_0028DB90;

void stage3_boss_fire_body_six_gun_start(void) {
    u16 *temp_a0;
    u16 *temp_s0;
    u16 temp_a1;
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_a0 = (u8 *)(D_0028DB80);
    reg_d0.w = ((u32) D_0028DB84 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    temp_s0 = (u16 *)(reg_a1);
    func_001713C0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    temp_a1 = reg_d0.h[0];
    reg_a0 = *(u8 **)(((u8 *)D_0026CE20) + (temp_a1 & ~3));
    reg_a1 = (u8 *)(temp_s0);
    reg_d0.w = ((u32) D_0028DB7C >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *)(D_0028DB88);
    reg_d0.w = ((u32) D_0028DB90 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.b[0] = STAGE3_ADJUST(reg_a6)->body_six_gun_burst_add;
    BODY_SIX_GUN(reg_a4)->volleys_left += reg_d0.b[0];
    reg_d0.b[0] = STAGE3_ADJUST(reg_a6)->body_six_gun_shot_sub;
    BODY_SIX_GUN(reg_a4)->shot_interval -= reg_d0.b[0];
    reg_d0.h[0] = STAGE3_ADJUST(reg_a6)->body_six_gun_speed_add;
    BODY_SIX_GUN(reg_a4)->aimed.speed += reg_d0.h[0];
    BODY_SIX_GUN(reg_a4)->fan_a.speed += reg_d0.h[0];
    BODY_SIX_GUN(reg_a4)->fan_b.speed += reg_d0.h[0];
    BODY_SIX_GUN(reg_a4)->three_way.speed += reg_d0.h[0];
    reg_d0.b[0] = STAGE3_ADJUST_B(reg_a6)->wait_sub;
    reg_d0.b[0] = (s8) reg_d0.b[0] * 8;
    BODY_SIX_GUN(reg_a4)->wait += reg_d0.b[0];
    stage3_boss_fire_body_six_gun();
}

s32 boss_attack_stop();
s32 bullet_fire256_2way();
s32 bullet_fire256_3way();
s32 direction256_between();
extern s16 g_player2[];
extern s16 g_player1[];

void stage3_boss_fire_body_six_gun(void) {
    s32 bullet_fire256_fast();
    s16 *t1;
    s16 *t2;
    s16 *v1;
    u16 t3;
    u16 t4;
    u16 t5;
    u16 t6;
    u16 t7;
    u32 t8;
    u32 t9;
    u8 t10;
    u8 t11;
    u8 t12;

    reg_tmp.b[0] = BODY_SIX_GUN(reg_a4)->wait;
    BODY_SIX_GUN(reg_a4)->wait -= 1;
    if (reg_tmp.b[0] == 0) {
        BODY_SIX_GUN(reg_a4)->wait = (u8) BODY_SIX_GUN(reg_a4)->shot_interval;
        reg_a0 = (u8 *)(g_player1);
        reg_a1 = (u8 *)(g_player2);
        if (ENEMY_STATE(reg_a5)->target_player != 0) {
            t1 = (s16 *)(reg_a1);
            reg_a1 = (u8 *)(reg_a0);
            reg_a0 = (u8 *)(t1);
        }
        v1 = (s16 *)(reg_a0);
        if ((*(s16 *)((u8 *)(v1) + (0))) >= 0) {
            t2 = (s16 *)(reg_a1);
            if (*t2 < 0) {
                reg_a1 = (u8 *)(v1);
                reg_a0 = (u8 *)(t2);
                goto next_1;
            }
        } else {
next_1:
            reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
            t8 = reg_d2.w;
            reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
            t9 = reg_d3.w;
            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d0.h[0] += 0x400;
            reg_d1.h[0] += 0x7FFF + 0x7D01;
            direction256_between();
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d4.w = 0;
            reg_d0.h[1] = BODY_SIX_GUN(reg_a4)->aimed.speed;
            reg_d0.h[0] = BODY_SIX_GUN(reg_a4)->aimed.bullet;
            reg_d3.w = 0x0400FD00;
            bullet_fire256_fast();
            reg_d2.w = t8;
            reg_d3.w = t9;
            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d0.h[0] += 0x400;
            reg_d1.h[0] += 0x300;
            direction256_between();
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d4.w = 0;
            reg_d0.h[1] = BODY_SIX_GUN(reg_a4)->aimed.speed;
            reg_d0.h[0] = BODY_SIX_GUN(reg_a4)->aimed.bullet;
            reg_d3.w = 0x04000300;
            bullet_fire256_fast();
            enemy_switch_target_player();
            reg_d1.b[0] = BODY_SIX_GUN(reg_a4)->fan_angle;
            reg_d6.h[0] = reg_d1.h[0];
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d3.w = 0xFE00FD00;
            reg_d4.w = 0;
            reg_d0.h[1] = BODY_SIX_GUN(reg_a4)->fan_a.speed;
            reg_d0.h[0] = BODY_SIX_GUN(reg_a4)->fan_a.bullet;
            bullet_fire256_2way();
            reg_d0.h[1] = BODY_SIX_GUN(reg_a4)->fan_b.speed;
            reg_d0.h[0] = BODY_SIX_GUN(reg_a4)->fan_b.bullet;
            reg_d1.h[0] += 4;
            bullet_fire256_2way();
            reg_d0.h[1] = BODY_SIX_GUN(reg_a4)->fan_a.speed;
            t3 = BODY_SIX_GUN(reg_a4)->fan_a.bullet;
            reg_d0.h[0] = t3;
            reg_d0.w -= 0x80000;
            reg_d1.h[0] += 4;
            bullet_fire256_2way();
            reg_d0.h[1] = BODY_SIX_GUN(reg_a4)->fan_b.speed;
            t4 = BODY_SIX_GUN(reg_a4)->fan_b.bullet;
            reg_d0.h[0] = t4;
            reg_d0.w -= 0x80000;
            reg_d1.h[0] += 4;
            bullet_fire256_2way();
            reg_d1.h[0] = reg_d6.h[0];
            reg_d1.b[0] *= -1;
            reg_d0.h[1] = BODY_SIX_GUN(reg_a4)->fan_a.speed;
            reg_d0.h[0] = BODY_SIX_GUN(reg_a4)->fan_a.bullet;
            reg_d3.h[0] = 0x300;
            bullet_fire256_2way();
            reg_d0.h[1] = BODY_SIX_GUN(reg_a4)->fan_b.speed;
            reg_d0.h[0] = BODY_SIX_GUN(reg_a4)->fan_b.bullet;
            reg_d1.h[0] -= 4;
            bullet_fire256_2way();
            reg_d0.h[1] = BODY_SIX_GUN(reg_a4)->fan_a.speed;
            t5 = BODY_SIX_GUN(reg_a4)->fan_a.bullet;
            reg_d0.h[0] = t5;
            reg_d0.w -= 0x80000;
            reg_d1.h[0] -= 4;
            bullet_fire256_2way();
            reg_d0.h[1] = BODY_SIX_GUN(reg_a4)->fan_b.speed;
            t6 = BODY_SIX_GUN(reg_a4)->fan_b.bullet;
            reg_d0.h[0] = t6;
            reg_d0.w -= 0x80000;
            reg_d1.h[0] -= 4;
            bullet_fire256_2way();
            reg_d0.h[1] = BODY_SIX_GUN(reg_a4)->three_way.speed;
            reg_d0.h[0] = BODY_SIX_GUN(reg_a4)->three_way.bullet;
            reg_d1.b[0] = BODY_SIX_GUN(reg_a4)->three_way_angle;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d3.w = 0xF800FD00;
            bullet_fire256_3way();
            reg_d1.h[0] -= 0x10;
            bullet_fire256_3way();
            reg_d1.h[0] -= 0x10;
            bullet_fire256_3way();
            reg_d3.h[0] = 0x300;
            reg_d1.b[0] *= -1;
            bullet_fire256_3way();
            reg_d1.h[0] -= 0x10;
            bullet_fire256_3way();
            reg_d1.h[0] -= 0x10;
            bullet_fire256_3way();
            reg_d0.b[0] = BODY_SIX_GUN(reg_a4)->fan_turn;
            BODY_SIX_GUN(reg_a4)->fan_angle -= reg_d0.b[0];
            if (BODY_SIX_GUN(reg_a4)->fan_angle > 0xC0) {
                BODY_SIX_GUN(reg_a4)->fan_angle = 0xC0;
                goto next_11;
            }
            if (BODY_SIX_GUN(reg_a4)->fan_angle >= 0x40) {
                goto skip_1;
            }
            BODY_SIX_GUN(reg_a4)->fan_angle = 0x40;
next_11:
            BODY_SIX_GUN(reg_a4)->fan_turn *= -1;
skip_1:
            reg_d0.b[0] = BODY_SIX_GUN(reg_a4)->three_way_turn;
            BODY_SIX_GUN(reg_a4)->three_way_angle -= reg_d0.b[0];
            if (BODY_SIX_GUN(reg_a4)->three_way_angle > 0xC0) {
                BODY_SIX_GUN(reg_a4)->three_way_angle = 0xC0;
                goto next_12;
            }
            if (BODY_SIX_GUN(reg_a4)->three_way_angle >= 0x40) {
                goto skip_2;
            }
            BODY_SIX_GUN(reg_a4)->three_way_angle = 0x40;
next_12:
            BODY_SIX_GUN(reg_a4)->three_way_turn *= -1;
skip_2:;
        }
        reg_tmp.b[0] = BODY_SIX_GUN(reg_a4)->volleys_left;
        BODY_SIX_GUN(reg_a4)->volleys_left -= 1;
        if (reg_tmp.b[0] == 0) {
            t10 = STAGE3_ADJUST(reg_a6)->body_six_gun_burst_add;
            if ((s32) t10 < 0x60) {
                STAGE3_ADJUST(reg_a6)->body_six_gun_burst_add = (u8) (t10 + 0x10);
            }
            t11 = STAGE3_ADJUST(reg_a6)->body_six_gun_shot_sub;
            if ((s32) t11 < 4) {
                STAGE3_ADJUST(reg_a6)->body_six_gun_shot_sub = (u8) (t11 - 2);
            }
            t7 = STAGE3_ADJUST(reg_a6)->body_six_gun_speed_add;
            if ((s32) t7 < 5) {
                STAGE3_ADJUST(reg_a6)->body_six_gun_speed_add = (u16) (t7 + 1);
            }
            t12 = STAGE3_ADJUST(reg_a6)->lid_six_gun_shot_sub;
            if ((s32) t12 < 0xA) {
                STAGE3_ADJUST(reg_a6)->lid_six_gun_shot_sub = (u8) (t12 + 2);
            }
            reg_d0.w = 4;
            boss_attack_stop();
            reg_d0.w = 3;
            boss_attack_stop();
        }
    }
}

extern u32 D_0028DB94;
extern u16 D_0028DB98[];
extern u32 D_0028DB9C;

void stage3_boss_fire_main_gun_b_start(void) {
    u16 *temp_a0;
    u16 *temp_s0;
    u16 temp_a1;
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_a0 = (u8 *)(D_0028DB98);
    reg_d0.w = ((u32) D_0028DB9C >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    temp_s0 = (u16 *)(reg_a1);
    func_001713C0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    temp_a1 = reg_d0.h[0];
    reg_a0 = *(u8 **)(((u8 *)D_0026CF40) + (temp_a1 & ~3));
    reg_a1 = (u8 *)(temp_s0);
    reg_d0.w = ((u32) D_0028DB94 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.b[0] = STAGE3_ADJUST_B(reg_a6)->main_gun_b_rounds_add;
    MAIN_GUN_B(reg_a4)->rounds_left += reg_d0.b[0];
    MAIN_GUN_B(reg_a4)->other_0A += reg_d0.b[0];
    reg_d0.h[0] = STAGE3_ADJUST_B(reg_a6)->main_gun_b_speed_add;
    MAIN_GUN_B(reg_a4)->speed += reg_d0.h[0];
    reg_d0.b[0] = STAGE3_ADJUST_B(reg_a6)->wait_sub;
    MAIN_GUN_B(reg_a4)->wait -= reg_d0.b[0];
    stage3_boss_fire_main_gun_b();
}

extern s16 *reg_save_atmp;

void stage3_boss_fire_main_gun_b(void) {
    s16 *temp_a0;
    u16 temp_v0;
    u16 temp_v0_3;
    u16 temp_v0_4;
    u8 temp_v0_2;

    reg_tmp.b[0] = MAIN_GUN_B(reg_a4)->wait;
    MAIN_GUN_B(reg_a4)->wait -= 1;
    if (reg_tmp.b[0] == 0) {
        MAIN_GUN_B(reg_a4)->wait = (u8) MAIN_GUN_B(reg_a4)->shot_interval;
        reg_a0 = (u8 *)(g_player1);
        reg_a1 = (u8 *)(g_player2);
        switch (ENEMY_STATE(reg_a5)->target_player) { case 0: break; default:
            reg_save_atmp = (s16 *)(reg_a1);
            reg_a1 = (u8 *)(reg_a0);
            reg_a0 = (u8 *)(reg_save_atmp);
        }
        if (*(s16 *)reg_a0 >= 0) {
            temp_a0 = (s16 *)(reg_a1);
            if (*temp_a0 < 0) {
                reg_a1 = (u8 *)(reg_a0);
                reg_save_atmp = (s16 *)(temp_a0);
                reg_a0 = (u8 *)(temp_a0);
                goto block_6;
            }
        } else {
block_6:
            reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
            reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d0.h[0] += 0x7FFF + 0x6201;
            direction256_between();
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d3.w = 0xE2000000;
            reg_d4.w = (u32) reg_a6;
            reg_d0.h[0] = MAIN_GUN_B(reg_a4)->shots;
            reg_d0.h[0] -= MAIN_GUN_B(reg_a4)->shots_left;
            reg_d0.h[0] += reg_d0.h[0];
            reg_d0.h[0] += MAIN_GUN_B(reg_a4)->speed;
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = reg_d0.h[0];
            reg_d0.h[0] = 0xB;
            bullet_fire256_fixed();
        }
        reg_tmp.h[0] = MAIN_GUN_B(reg_a4)->shots_left;
        MAIN_GUN_B(reg_a4)->shots_left -= 1;
        switch (reg_tmp.h[0]) {
        case 0:
            enemy_switch_target_player();
            MAIN_GUN_B(reg_a4)->wait = (u8) MAIN_GUN_B(reg_a4)->pause;
            reg_d0.h[0] = MAIN_GUN_B(reg_a4)->shots_step;
            MAIN_GUN_B(reg_a4)->shots += reg_d0.h[0];
            if ((s32) MAIN_GUN_B(reg_a4)->shots > 0xC) {
                MAIN_GUN_B(reg_a4)->shots = 0xCU;
            }
            MAIN_GUN_B(reg_a4)->shots_left = (u16) MAIN_GUN_B(reg_a4)->shots;
            reg_tmp.b[0] = MAIN_GUN_B(reg_a4)->rounds_left;
            MAIN_GUN_B(reg_a4)->rounds_left -= 1;
            if (reg_tmp.b[0] == 0) {
                temp_v0 = STAGE3_ADJUST_B(reg_a6)->main_gun_b_speed_add;
                if ((s32) temp_v0 < 6) {
                    STAGE3_ADJUST_B(reg_a6)->main_gun_b_speed_add = (u16) (temp_v0 + 3);
                }
                temp_v0_2 = STAGE3_ADJUST_B(reg_a6)->wait_sub;
                if ((s32) temp_v0_2 < 0x20) {
                    STAGE3_ADJUST_B(reg_a6)->wait_sub = (u8) (temp_v0_2 + 8);
                }
                temp_v0_3 = STAGE3_ADJUST(reg_a6)->turrets_b_speed_add;
                if ((s32) temp_v0_3 < 0xF) {
                    STAGE3_ADJUST(reg_a6)->turrets_b_speed_add = (u16) (temp_v0_3 + 3);
                }
                temp_v0_4 = STAGE3_ADJUST(reg_a6)->turrets_b_ways_add;
                if ((s32) temp_v0_4 < 6) {
                    STAGE3_ADJUST(reg_a6)->turrets_b_ways_add = (u16) (temp_v0_4 + 2);
                    STAGE3_ADJUST(reg_a6)->turrets_b_spread_add += 4;
                }
                reg_d0.w = 6;
                boss_attack_stop();
                reg_d0.w = 7;
                boss_attack_stop();
            }
            break;
        }
    }
}

void bullet_fire256(void);

void bullet_fire256_entry(void) {
    bullet_fire256();
}

extern u32 D_0028DBA0;
extern u16 D_0028DBA4[];
extern u32 D_0028DBA8;

void stage3_boss_fire_side_turrets_b_start(void) {
    u16 *temp_a0;
    u16 *temp_s0;
    u16 temp_a1;
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_a0 = (u8 *)(D_0028DBA4);
    reg_d0.w = ((u32) D_0028DBA8 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    temp_s0 = (u16 *)(reg_a1);
    func_001713C0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    temp_a1 = reg_d0.h[0];
    reg_a0 = *(u8 **)(((u8 *)D_0026CFE0) + (temp_a1 & ~3));
    reg_a1 = (u8 *)(temp_s0);
    reg_d0.w = ((u32) D_0028DBA0 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = STAGE3_ADJUST(reg_a6)->turrets_b_speed_add;
    SIDE_TURRETS_B(reg_a4)->shot_a.speed += reg_d0.h[0];
    SIDE_TURRETS_B(reg_a4)->shot_b.speed += reg_d0.h[0];
    reg_d0.h[0] = STAGE3_ADJUST(reg_a6)->turrets_b_ways_add;
    SIDE_TURRETS_B(reg_a4)->count += reg_d0.h[0];
    reg_d0.h[0] = STAGE3_ADJUST(reg_a6)->turrets_b_spread_add;
    SIDE_TURRETS_B(reg_a4)->spread += reg_d0.h[0];
    reg_d0.b[0] = STAGE3_ADJUST_B(reg_a6)->wait_sub;
    SIDE_TURRETS_B(reg_a4)->wait_a -= reg_d0.b[0];
    SIDE_TURRETS_B(reg_a4)->wait_b -= reg_d0.b[0];
    stage3_boss_fire_side_turrets_b();
}


void stage3_boss_fire_side_turrets_b(void) {
    u16 var_a0_3;
    u8 *var_a0_4;

    reg_tmp.b[0] = SIDE_TURRETS_B(reg_a4)->wait_a;
    SIDE_TURRETS_B(reg_a4)->wait_a -= 1;
    if (reg_tmp.b[0] == 0) {
        SIDE_TURRETS_B(reg_a4)->wait_a = (u8) SIDE_TURRETS_B(reg_a4)->shot_interval;
        reg_a3 = (u8 *)(g_direction_offsets_400);
        reg_d1.h[0] = STAGE3_EXTRA(reg_a6)->left_turret_direction;
        reg_d0.h[0] = reg_d1.h[0];
        reg_d0.h[0] &= 0x3E;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
        reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a3;
        reg_d3.w += 0x11000080;
        reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
        var_a0_3 = ENTITY(reg_a6)[1].x.h;
        reg_d4.w = (u32) reg_a6;
        reg_d1.h[0] += reg_d1.h[0];
        reg_d2.h[0] = var_a0_3;
        reg_d4.w += 0x20;
        reg_d1.h[0] += reg_d1.h[0];
        reg_d1.h[0] -= SIDE_TURRETS_B(reg_a4)->spread;
        reg_d7.h[0] = SIDE_TURRETS_B(reg_a4)->count;
        do {
            if (!(reg_d7.w & 1)) {
                reg_d0.h[1] = SIDE_TURRETS_B(reg_a4)->shot_a.speed;
                reg_d0.h[0] = SIDE_TURRETS_B(reg_a4)->shot_a.bullet;
                bullet_fire256_entry();
                reg_d0.w += 0x30000;
                bullet_fire256_entry();
                reg_d0.w += 0xFFFD0000;
            } else {
                reg_d0.h[1] = SIDE_TURRETS_B(reg_a4)->shot_b.speed;
                reg_d0.h[0] = SIDE_TURRETS_B(reg_a4)->shot_b.bullet;
                bullet_fire256_entry();
            }
            reg_d1.b[0] += 4;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    reg_tmp.b[0] = SIDE_TURRETS_B(reg_a4)->wait_b;
    SIDE_TURRETS_B(reg_a4)->wait_b -= 1;
    if (reg_tmp.b[0] == 0) {
        SIDE_TURRETS_B(reg_a4)->wait_b = (u8) SIDE_TURRETS_B(reg_a4)->shot_interval;
        var_a0_4 = (u8 *)(reg_a6);
        reg_a3 = (u8 *)(g_direction_offsets_400);
        reg_d1.h[0] = (*(u16 *)((u8 *)(var_a0_4) + (0xB2)));
        reg_d3.w = 0x1100FF80;
        reg_d5.h[0] = reg_d1.h[0];
        reg_d5.h[0] &= 0x3E;
        reg_d5.h[0] += reg_d5.h[0];
        reg_d2.h[1] = (*(u16 *)((u8 *)(var_a0_4) + (0x42)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(var_a0_4) + (0x44)));
        reg_d1.h[0] += reg_d1.h[0];
        reg_d4.w = (u32) var_a0_4;
        reg_d4.w += 0x40;
        reg_d1.h[0] += reg_d1.h[0];
        reg_d1.h[0] += SIDE_TURRETS_B(reg_a4)->spread;
        reg_d7.h[0] = SIDE_TURRETS_B(reg_a4)->count;
        do {
            if (!(reg_d7.w & 1)) {
                reg_d0.h[1] = SIDE_TURRETS_B(reg_a4)->shot_a.speed;
                reg_d0.h[0] = SIDE_TURRETS_B(reg_a4)->shot_a.bullet;
                bullet_fire256_entry();
                reg_d0.w += 0x30000;
                bullet_fire256_entry();
                reg_d0.w += 0xFFFD0000;
            } else {
                reg_d0.h[1] = SIDE_TURRETS_B(reg_a4)->shot_b.speed;
                reg_d0.h[0] = SIDE_TURRETS_B(reg_a4)->shot_b.bullet;
                bullet_fire256_entry();
            }
            var_a0_4 = (u8 *)(reg_d1.b[0] - 4);
            reg_d1.b[0] = (u8) var_a0_4;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
}

extern u32 D_0028DBAC;
extern u16 D_0028DBB0[];
extern u32 D_0028DBB4;
extern u16 D_0028DBB8[];
extern u32 D_0028DBBC;

void stage3_boss_fire_six_gun_start(void) {
    u16 *temp_a0;
    u16 *temp_s0;
    u16 temp_a1;
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_a0 = (u8 *)(D_0028DBB0);
    reg_d0.w = ((u32) D_0028DBB4 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    temp_s0 = (u16 *)(reg_a1);
    func_001713C0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    temp_a1 = reg_d0.h[0];
    reg_a0 = *(u8 **)(((u8 *)D_0026D080) + (temp_a1 & ~3));
    reg_a1 = (u8 *)(temp_s0);
    reg_d0.w = ((u32) D_0028DBAC >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *)(D_0028DBB8);
    reg_d0.w = ((u32) D_0028DBBC >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = STAGE3_ADJUST(reg_a6)->six_gun_speed_add;
    SIX_GUN(reg_a4)->shot_a.speed += reg_d0.h[0];
    SIX_GUN(reg_a4)->shot_b.speed += reg_d0.h[0];
    stage3_boss_fire_six_gun();
}

s32 boss_animation_start();
extern u16 D_0026D1A0[];

void stage3_boss_fire_six_gun(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a0_4;
    u16 temp_a0_5;
    u16 temp_a1;
    u16 temp_a1_2;
    u16 temp_a1_3;
    u16 temp_a1_4;
    u16 temp_a1_5;
    u16 temp_v1_2;
    u8 temp_v1;

    reg_tmp.b[0] = SIX_GUN(reg_a4)->wait;
    SIX_GUN(reg_a4)->wait -= 1;
    if (reg_tmp.b[0] == 0) {
        SIX_GUN(reg_a4)->wait = (u8) SIX_GUN(reg_a4)->shot_interval;
        temp_v1 = SIX_GUN(reg_a4)->aimed;
        if (!(temp_v1 & 1)) {
            SIX_GUN(reg_a4)->aimed = (u8) (temp_v1 | 1);
            rng_next_unsigned();
            if ((s8)(reg_d0.b[0]) >= 0) {
                reg_d0.b[0] *= -1;
            }
            SIX_GUN(reg_a4)->direction = (u8) reg_d0.b[0];
        }
        reg_d1.b[0] = SIX_GUN(reg_a4)->direction;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d4.w = 0;
        reg_d6.b[0] = SIX_GUN(reg_a4)->other_09;
        reg_a3 = (u8 *)(D_0026D1A0);
        temp_a1 = *(u16 *)reg_a3;
        reg_d3.h[1] = temp_a1;
        reg_a3 += 2;
        temp_a0 = *(u16 *)reg_a3;
        reg_d3.h[0] = temp_a0;
        reg_a3 += 2;
        reg_d0.h[1] = SIX_GUN(reg_a4)->shot_a.speed;
        reg_d0.h[0] = SIX_GUN(reg_a4)->shot_a.bullet;
        reg_d1.b[0] += reg_d6.b[0];
        bullet_fire256_fixed();
        temp_a1_2 = *(u16 *)reg_a3;
        reg_d3.h[1] = temp_a1_2;
        reg_a3 += 2;
        temp_a0_2 = *(u16 *)reg_a3;
        reg_d3.h[0] = temp_a0_2;
        reg_a3 += 2;
        reg_d0.h[1] = SIX_GUN(reg_a4)->shot_b.speed;
        reg_d0.h[0] = SIX_GUN(reg_a4)->shot_b.bullet;
        reg_d1.b[0] -= reg_d6.b[0];
        bullet_fire256_3way();
        temp_a1_3 = *(u16 *)reg_a3;
        reg_d3.h[1] = temp_a1_3;
        reg_a3 += 2;
        temp_a0_3 = *(u16 *)reg_a3;
        reg_d3.h[0] = temp_a0_3;
        reg_a3 += 2;
        reg_d0.h[1] = SIX_GUN(reg_a4)->shot_a.speed;
        reg_d0.h[0] = SIX_GUN(reg_a4)->shot_a.bullet;
        reg_d1.b[0] -= reg_d6.b[0];
        bullet_fire256_2way();
        reg_d1.b[0] += 0x80;
        temp_v1_2 = *(u16 *)reg_a3;
        reg_a3 += 2;
        reg_d3.h[1] = temp_v1_2;
        reg_d3.h[0] = *(u16 *)reg_a3;
        reg_a3 += 2;
        bullet_fire256_fixed();
        temp_a1_4 = *(u16 *)reg_a3;
        reg_d3.h[1] = temp_a1_4;
        reg_a3 += 2;
        temp_a0_4 = *(u16 *)reg_a3;
        reg_d3.h[0] = temp_a0_4;
        reg_a3 += 2;
        reg_d0.h[1] = SIX_GUN(reg_a4)->shot_b.speed;
        reg_d0.h[0] = SIX_GUN(reg_a4)->shot_b.bullet;
        reg_d1.b[0] += reg_d6.b[0];
        bullet_fire256_3way();
        temp_a1_5 = *(u16 *)reg_a3;
        reg_d3.h[1] = temp_a1_5;
        reg_a3 += 2;
        temp_a0_5 = *(u16 *)reg_a3;
        reg_d3.h[0] = temp_a0_5;
        reg_a3 += 2;
        reg_d0.h[1] = SIX_GUN(reg_a4)->shot_a.speed;
        reg_d0.h[0] = SIX_GUN(reg_a4)->shot_a.bullet;
        reg_d1.b[0] += reg_d6.b[0];
        bullet_fire256_2way();
        reg_d0.b[0] = SIX_GUN(reg_a4)->turn;
        SIX_GUN(reg_a4)->direction += reg_d0.b[0];
        reg_tmp.b[0] = SIX_GUN(reg_a4)->burst.t.count;
        SIX_GUN(reg_a4)->burst.t.count -= 1;
        if (reg_tmp.b[0] == 0) {
            SIX_GUN(reg_a4)->burst.t.count = (u8) SIX_GUN(reg_a4)->burst.t.reload;
            SIX_GUN(reg_a4)->shot_interval = (u8) SIX_GUN(reg_a4)->next_interval;
            SIX_GUN(reg_a4)->wait = (u8) SIX_GUN(reg_a4)->round_pause;
            SIX_GUN(reg_a4)->turn *= -1;
            SIX_GUN(reg_a4)->aimed &= 0xFE;
            reg_d0.h[0] = SIX_GUN(reg_a4)->speed_step;
            SIX_GUN(reg_a4)->shot_a.speed += reg_d0.h[0];
            SIX_GUN(reg_a4)->shot_b.speed += reg_d0.h[0];
            reg_tmp.b[0] = SIX_GUN(reg_a4)->rounds_left;
            SIX_GUN(reg_a4)->rounds_left -= 1;
            if (reg_tmp.b[0] == 0) {
                reg_d0.h[0] = SIX_GUN(reg_a4)->ramp_step;
                STAGE3_ADJUST(reg_a6)->six_gun_speed_add += reg_d0.h[0];
                if ((s32) STAGE3_ADJUST(reg_a6)->six_gun_speed_add > 12) {
                    STAGE3_ADJUST(reg_a6)->six_gun_speed_add = 0xCU;
                }
                reg_d0.w = 5;
                boss_attack_stop();
                reg_d0.w = 5;
                boss_animation_start();
            }
        }
    }
}

extern u32 D_0028DBC0;
extern u16 D_0028DBC4[];
extern u32 D_0028DBC8;

void stage3_boss_fire_six_gun_b_start(void) {
    s32 temp_a1;
    u16 temp_a2;
    func_001713C0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    temp_a2 = reg_d0.h[0];
    temp_a1 = temp_a2 & ~3;
    reg_a0 = *(u8 **)(((u8 *)D_0026D1D0) + temp_a1);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028DBC0 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *)(D_0028DBC4);
    reg_d0.w = ((u32) D_0028DBC8 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = STAGE3_ADJUST(reg_a6)->six_gun_b_speed_add;
    SIX_GUN_B(reg_a4)->shot_a.speed += reg_d0.h[0];
    SIX_GUN_B(reg_a4)->shot_b.speed += reg_d0.h[0];
    reg_d0.b[0] = STAGE3_ADJUST(reg_a6)->six_gun_b_burst_add;
    SIX_GUN_B(reg_a4)->burst.t.count += reg_d0.b[0];
    SIX_GUN_B(reg_a4)->burst.t.reload += reg_d0.b[0];
    reg_d0.b[0] = STAGE3_ADJUST(reg_a6)->six_gun_b_rounds_add;
    SIX_GUN_B(reg_a4)->rounds_left += reg_d0.b[0];
    if ((s32) SIX_GUN_B(reg_a4)->burst.t.count > 0xE) {
        reg_d0.b[0] = 0xE;
        SIX_GUN_B(reg_a4)->burst.t.count = (u8) reg_d0.b[0];
        SIX_GUN_B(reg_a4)->burst.t.reload = (u8) reg_d0.b[0];
    }
    stage3_boss_fire_six_gun_b();
}

extern u16 D_0026D1B8[];
extern u16 g_player2_as_u16_a[];
extern u16 g_player1_as_u16_a[];

void stage3_boss_fire_six_gun_b(void) {
    s16 *temp_a0_2;
    s16 *var_a1;
    u32 temp_a0_10;
    u32 temp_a0_3;
    u32 temp_a0_6;
    u32 temp_a0_7;
    u32 temp_a0_8;
    u32 temp_a1;
    u8 temp_a0;

    reg_tmp.b[0] = SIX_GUN_B(reg_a4)->wait;
    SIX_GUN_B(reg_a4)->wait -= 1;
    if (reg_tmp.b[0] == 0) {
        SIX_GUN_B(reg_a4)->wait = (u8) SIX_GUN_B(reg_a4)->shot_interval;
        temp_a0 = SIX_GUN_B(reg_a4)->aimed;
        if (!(temp_a0 & 1)) {
            SIX_GUN_B(reg_a4)->aimed = (u8) (temp_a0 | 1);
            reg_a0 = (u8 *)(g_player1_as_u16_a);
            reg_a1 = (u8 *)(g_player2_as_u16_a);
            if (ENEMY_STATE(reg_a5)->target_player != 0) {
                reg_save_atmp = (s16 *)(reg_a1);
                reg_a1 = (u8 *)(reg_a0);
                reg_a0 = (u8 *)(reg_save_atmp);
            }
            var_a1 = (s16 *)(reg_a0);
            if ((*(s16 *)((u8 *)(var_a1) + (0))) >= 0) {
                temp_a0_2 = (s16 *)(reg_a1);
                if (*temp_a0_2 < 0) {
                    reg_a1 = (u8 *)(var_a1);
                    reg_save_atmp = (s16 *)(temp_a0_2);
                    reg_a0 = (u8 *)(temp_a0_2);
                    goto block_7;
                }
            } else {
block_7:
                reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                reg_d0.h[0] += 0x7FFF + 0x7541;
                direction256_between();
                SIX_GUN_B(reg_a4)->direction = (u8) reg_d1.b[0];
                goto block_8;
            }
        } else {
block_8:
            reg_d1.b[0] = SIX_GUN_B(reg_a4)->direction;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            temp_a1 = ENTITY(reg_a6)->x.h;
            reg_d2.h[0] = temp_a1;
            reg_d6.h[0] = 8;
            reg_d7.h[0] = 0xFFFE;
            reg_d4.w = 0;
            if (g_loop != 0) {
                reg_d6.h[0] = 0xA;
                reg_d7.h[0] = 0xFFFF;
            }
            reg_a3 = (u8 *)(D_0026D1A0);
            if ((s8) SIX_GUN_B(reg_a4)->turn >= 0) {
                reg_a3 = (u8 *)(D_0026D1B8);
            }
            reg_d3.h[1] = *(u16 *)reg_a3;
            reg_a3 += 2;
            temp_a0_3 = *(u16 *)reg_a3;
            reg_d3.h[0] = temp_a0_3;
            reg_a3 += 2;
            reg_d0.h[1] = SIX_GUN_B(reg_a4)->shot_a.speed;
            reg_d0.h[0] = SIX_GUN_B(reg_a4)->shot_a.bullet;
            reg_d1.h[0] += 0x14;
            bullet_fire256_fixed();
            if (g_loop != 0) {
                reg_d0.h[0] = 5;
                reg_d0.h[1] -= reg_d7.h[0];
                reg_d1.h[0] += reg_d6.h[0];
                bullet_fire256_fixed();
                reg_d1.h[0] -= reg_d6.h[0];
            }
            reg_d0.h[0] = 5;
            reg_d0.h[1] -= reg_d7.h[0];
            reg_d1.h[0] -= reg_d6.h[0];
            bullet_fire256_fixed();
            reg_d1.h[0] += reg_d6.h[0];
            temp_a0_6 = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d3.h[1] = temp_a0_6;
            temp_a0_7 = *(u16 *)reg_a3;
            reg_d3.h[0] = temp_a0_7;
            reg_a3 += 2;
            reg_d0.h[1] = SIX_GUN_B(reg_a4)->shot_b.speed;
            reg_d0.h[0] = SIX_GUN_B(reg_a4)->shot_b.bullet;
            reg_d1.h[0] -= 0x14;
            bullet_fire256_3way();
            reg_d3.h[1] = *(u16 *)reg_a3;
            reg_a3 += 2;
            temp_a0_8 = *(u16 *)reg_a3;
            reg_d3.h[0] = temp_a0_8;
            reg_a3 += 2;
            reg_d0.h[1] = SIX_GUN_B(reg_a4)->shot_a.speed;
            reg_d0.h[0] = SIX_GUN_B(reg_a4)->shot_a.bullet;
            reg_d1.h[0] -= 0x14;
            bullet_fire256_fixed();
            reg_d0.h[0] = 5;
            reg_d0.h[1] -= reg_d7.h[0];
            reg_d1.h[0] += reg_d6.h[0];
            bullet_fire256_fixed();
            reg_d1.h[0] -= reg_d6.h[0];
            switch (g_loop) { case 0: break; default:
                temp_a0_10 = reg_d0.h[1];
                reg_d0.h[0] = 5;
                reg_d0.h[1] = temp_a0_10 - reg_d7.h[0];
                reg_d1.h[0] -= reg_d6.h[0];
                bullet_fire256_fixed();
            }
            var_a1 = (s16 *)(reg_a4);
            reg_d0.b[0] = (u8) (*(u8 *)((u8 *)(var_a1) + (8)));
            (*(u8 *)((u8 *)(var_a1) + (0x1A))) += reg_d0.b[0];
        }
        reg_tmp.b[0] = SIX_GUN_B(reg_a4)->burst.t.count;
        SIX_GUN_B(reg_a4)->burst.t.count -= 1;
        switch (reg_tmp.b[0]) {
        case 0:
            SIX_GUN_B(reg_a4)->shot_interval = (u8) SIX_GUN_B(reg_a4)->next_interval;
            SIX_GUN_B(reg_a4)->wait = (u8) SIX_GUN_B(reg_a4)->round_pause;
            SIX_GUN_B(reg_a4)->turn *= -1;
            SIX_GUN_B(reg_a4)->aimed &= 0xFE;
            enemy_switch_target_player();
            reg_d0.b[0] = SIX_GUN_B(reg_a4)->burst_step;
            SIX_GUN_B(reg_a4)->burst.t.reload += reg_d0.b[0];
            if ((s32) SIX_GUN_B(reg_a4)->burst.t.reload > 0xE) {
                SIX_GUN_B(reg_a4)->burst.t.reload = 0xEU;
            }
            SIX_GUN_B(reg_a4)->burst.t.count = (u8) SIX_GUN_B(reg_a4)->burst.t.reload;
            reg_d0.h[0] = SIX_GUN_B(reg_a4)->speed_step;
            SIX_GUN_B(reg_a4)->shot_a.speed += reg_d0.h[0];
            SIX_GUN_B(reg_a4)->shot_b.speed += reg_d0.h[0];
            reg_tmp.b[0] = SIX_GUN_B(reg_a4)->rounds_left;
            SIX_GUN_B(reg_a4)->rounds_left -= 1;
            if (reg_tmp.b[0] == 0) {
                reg_d0.b[0] = SIX_GUN_B(reg_a4)->burst_step;
                STAGE3_ADJUST(reg_a6)->six_gun_b_burst_add += reg_d0.b[0];
                if ((s32) STAGE3_ADJUST(reg_a6)->six_gun_b_burst_add > 0xE) {
                    STAGE3_ADJUST(reg_a6)->six_gun_b_burst_add = 0xEU;
                }
                STAGE3_ADJUST(reg_a6)->six_gun_b_rounds_add += 1;
                if ((s32) STAGE3_ADJUST(reg_a6)->six_gun_b_rounds_add > 4) {
                    STAGE3_ADJUST(reg_a6)->six_gun_b_rounds_add = 4U;
                }
                reg_d0.h[0] = SIX_GUN_B(reg_a4)->ramp_step;
                STAGE3_ADJUST(reg_a6)->six_gun_b_speed_add += reg_d0.b[0];
                if ((s32) STAGE3_ADJUST(reg_a6)->six_gun_b_speed_add > 0xC) {
                    STAGE3_ADJUST(reg_a6)->six_gun_b_speed_add = 0xCU;
                }
                reg_d0.w = 8;
                boss_attack_stop();
                reg_d0.w = 5;
                boss_animation_start();
            }
            break;
        }
    }
}

extern u16 D_0026CC60[16];
extern u16 D_0026CC80[16];
extern u16 D_0026CCA0[16];
extern u16 D_0026CCC0[16];
extern u16 D_0026CCE0[16];
extern u16 D_0026CD00[16];
extern u16 D_0026CD20[16];
extern u16 D_0026CD40[16];
extern u16 D_0026CD80[8];
extern u16 D_0026CD90[8];
extern u16 D_0026CDA0[8];
extern u16 D_0026CDB0[8];
extern u16 D_0026CDC0[8];
extern u16 D_0026CDD0[8];
extern u16 D_0026CDE0[8];
extern u16 D_0026CDF0[8];
extern u16 D_0028DB30[4];
extern u16 D_0028DB38[4];
extern u16 D_0028DB40[4];
extern u16 D_0028DB48[4];
extern u16 D_0028DB50[4];
extern u16 D_0028DB58[4];
extern u16 D_0028DB60[4];
extern u16 D_0028DB68[4];
extern u16 D_0026CE40[16];
extern u16 D_0026CE60[16];
extern u16 D_0026CE80[16];
extern u16 D_0026CEA0[16];
extern u16 D_0026CEC0[16];
extern u16 D_0026CEE0[16];
extern u16 D_0026CF00[16];
extern u16 D_0026CF20[16];
extern u16 D_0026CF60[8];
extern u16 D_0026CF70[8];
extern u16 D_0026CF80[8];
extern u16 D_0026CF90[8];
extern u16 D_0026CFA0[8];
extern u16 D_0026CFB0[8];
extern u16 D_0026CFC0[8];
extern u16 D_0026CFD0[8];
extern u16 D_0026D000[8];
extern u16 D_0026D010[8];
extern u16 D_0026D020[8];
extern u16 D_0026D030[8];
extern u16 D_0026D040[8];
extern u16 D_0026D050[8];
extern u16 D_0026D060[8];
extern u16 D_0026D070[8];
extern u16 D_0026D0A0[16];
extern u16 D_0026D0C0[16];
extern u16 D_0026D0E0[16];
extern u16 D_0026D100[16];
extern u16 D_0026D120[16];
extern u16 D_0026D140[16];
extern u16 D_0026D160[16];
extern u16 D_0026D180[16];
extern u16 D_0026D1F0[16];
extern u16 D_0026D210[16];
extern u16 D_0026D230[16];
extern u16 D_0026D250[16];
extern u16 D_0026D270[16];
extern u16 D_0026D290[16];
extern u16 D_0026D2B0[16];
extern u16 D_0026D2D0[16];

void *D_0026CC40[8] = {
    D_0026CC60,
    D_0026CC80,
    D_0026CCA0,
    D_0026CCC0,
    D_0026CCE0,
    D_0026CD00,
    D_0026CD20,
    D_0026CD40,
};

u16 D_0026CC60[16] = {
    0x165C, 0x1717, 0x0738, 0xFFF5, 0x0013, 0xFFF5, 0x0013, 0x0202,
    0x0303, 0x0303, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026CC80[16] = {
    0x144C, 0x1515, 0x0528, 0xFFF7, 0x0013, 0xFFF7, 0x0013, 0x0101,
    0x0202, 0x0202, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026CCA0[16] = {
    0x123C, 0x1313, 0x0318, 0xFFF9, 0x0013, 0xFFF9, 0x0013, 0x0101,
    0x0101, 0x0101, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026CCC0[16] = {
    0x102C, 0x1111, 0x0108, 0xFFFB, 0x0013, 0xFFFB, 0x0013, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026CCE0[16] = {
    0x0F2B, 0x1111, 0x0106, 0xFFFD, 0x0013, 0xFFFD, 0x0013, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026CD00[16] = {
    0x0E2A, 0x1111, 0x0104, 0xFFFF, 0x0013, 0xFFFF, 0x0013, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026CD20[16] = {
    0x0D29, 0x1010, 0x0102, 0x0001, 0x0013, 0x0001, 0x0013, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026CD40[16] = {
    0x0C28, 0x0F0F, 0x0100, 0x0003, 0x0013, 0x0003, 0x0013, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

void *D_0026CD60[8] = {
    D_0026CD80,
    D_0026CD90,
    D_0026CDA0,
    D_0026CDB0,
    D_0026CDC0,
    D_0026CDD0,
    D_0026CDE0,
    D_0026CDF0,
};

u16 D_0026CD80[8] = {
    0x6036, 0x0001, 0x0004, 0xFFF9, 0x0005, 0x0000, 0x0000, 0x0000,
};

u16 D_0026CD90[8] = {
    0x5026, 0x0004, 0x0004, 0xFFFC, 0x0005, 0x0000, 0x0000, 0x0000,
};

u16 D_0026CDA0[8] = {
    0x4016, 0x0007, 0x0004, 0xFFFF, 0x0005, 0x0000, 0x0000, 0x0000,
};

u16 D_0026CDB0[8] = {
    0x3006, 0x000A, 0x0004, 0x0002, 0x0005, 0x0000, 0x0000, 0x0000,
};

u16 D_0026CDC0[8] = {
    0x2E04, 0x000B, 0x0004, 0x0003, 0x0005, 0x0000, 0x0000, 0x0000,
};

u16 D_0026CDD0[8] = {
    0x2C02, 0x000C, 0x0004, 0x0004, 0x0005, 0x0000, 0x0000, 0x0000,
};

u16 D_0026CDE0[8] = {
    0x2A00, 0x000D, 0x0004, 0x0005, 0x0005, 0x0000, 0x0000, 0x0000,
};

u16 D_0026CDF0[8] = {
    0x28FE, 0x000E, 0x0004, 0x0006, 0x0005, 0x0000, 0x0000, 0x0000,
};

void *D_0026CE00[8] = {
    D_0028DB30,
    D_0028DB38,
    D_0028DB40,
    D_0028DB48,
    D_0028DB50,
    D_0028DB58,
    D_0028DB60,
    D_0028DB68,
};

void *D_0026CE20[8] = {
    D_0026CE40,
    D_0026CE60,
    D_0026CE80,
    D_0026CEA0,
    D_0026CEC0,
    D_0026CEE0,
    D_0026CF00,
    D_0026CF20,
};

u16 D_0026CE40[16] = {
    0x1A00, 0xFFF3, 0x000B, 0xFFFC, 0x0003, 0xFFF8, 0x0004, 0xFFFA,
    0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026CE60[16] = {
    0x1600, 0xFFF6, 0x000B, 0x0000, 0x0003, 0xFFFC, 0x0004, 0xFFFD,
    0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026CE80[16] = {
    0x1200, 0xFFF9, 0x000B, 0x0004, 0x0003, 0x0000, 0x0004, 0x0000,
    0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026CEA0[16] = {
    0x0E00, 0xFFFC, 0x000B, 0x0008, 0x0003, 0x0004, 0x0004, 0x0003,
    0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026CEC0[16] = {
    0x0D00, 0xFFFE, 0x000B, 0x000A, 0x0003, 0x0006, 0x0004, 0x0005,
    0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026CEE0[16] = {
    0x0C00, 0x0002, 0x000B, 0x000E, 0x0003, 0x0008, 0x0004, 0x0007,
    0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026CF00[16] = {
    0x0B00, 0x0008, 0x000B, 0x0014, 0x0003, 0x000D, 0x0004, 0x000C,
    0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026CF20[16] = {
    0x0A00, 0x000C, 0x000B, 0x0018, 0x0003, 0x0010, 0x0004, 0x000F,
    0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

void *D_0026CF40[8] = {
    D_0026CF60,
    D_0026CF70,
    D_0026CF80,
    D_0026CF90,
    D_0026CFA0,
    D_0026CFB0,
    D_0026CFC0,
    D_0026CFD0,
};

u16 D_0026CF60[8] = {
    0x0001, 0x0001, 0x0A2E, 0x0202, 0xFFFA, 0x0002, 0x0000, 0x0000,
};

u16 D_0026CF70[8] = {
    0x0001, 0x0001, 0x0828, 0x0303, 0xFFFB, 0x0003, 0x0000, 0x0000,
};

u16 D_0026CF80[8] = {
    0x0002, 0x0002, 0x0622, 0x0303, 0xFFFB, 0x0003, 0x0000, 0x0000,
};

u16 D_0026CF90[8] = {
    0x0002, 0x0002, 0x041C, 0x0303, 0xFFFB, 0x0004, 0x0000, 0x0000,
};

u16 D_0026CFA0[8] = {
    0x0003, 0x0003, 0x0418, 0x0303, 0xFFFD, 0x0005, 0x0000, 0x0000,
};

u16 D_0026CFB0[8] = {
    0x0004, 0x0004, 0x0414, 0x0303, 0xFFFF, 0x0006, 0x0000, 0x0000,
};

u16 D_0026CFC0[8] = {
    0x0005, 0x0005, 0x0310, 0x0404, 0x0001, 0x0007, 0x0000, 0x0000,
};

u16 D_0026CFD0[8] = {
    0x0006, 0x0006, 0x030C, 0x0404, 0x0003, 0x0008, 0x0000, 0x0000,
};

void *D_0026CFE0[8] = {
    D_0026D000,
    D_0026D010,
    D_0026D020,
    D_0026D030,
    D_0026D040,
    D_0026D050,
    D_0026D060,
    D_0026D070,
};

u16 D_0026D000[8] = {
    0xB8B0, 0xFFFE, 0x0004, 0xFFFB, 0x0005, 0x0006, 0x000B, 0x0000,
};

u16 D_0026D010[8] = {
    0xB0A0, 0xFFFF, 0x0004, 0xFFFC, 0x0005, 0x0008, 0x000E, 0x0000,
};

u16 D_0026D020[8] = {
    0xA890, 0x0000, 0x0004, 0xFFFD, 0x0005, 0x0008, 0x0011, 0x0000,
};

u16 D_0026D030[8] = {
    0xA080, 0x0001, 0x0004, 0xFFFE, 0x0005, 0x000A, 0x0014, 0x0000,
};

u16 D_0026D040[8] = {
    0x9E7C, 0x0003, 0x0004, 0x0000, 0x0005, 0x000A, 0x0014, 0x0000,
};

u16 D_0026D050[8] = {
    0x9C78, 0x0005, 0x0004, 0x0002, 0x0005, 0x000C, 0x0017, 0x0000,
};

u16 D_0026D060[8] = {
    0x9A74, 0x0007, 0x0004, 0x0004, 0x0005, 0x000C, 0x0017, 0x0000,
};

u16 D_0026D070[8] = {
    0x9870, 0x0009, 0x0004, 0x0006, 0x0005, 0x000E, 0x001A, 0x0000,
};

void *D_0026D080[8] = {
    D_0026D0A0,
    D_0026D0C0,
    D_0026D0E0,
    D_0026D100,
    D_0026D120,
    D_0026D140,
    D_0026D160,
    D_0026D180,
};

u16 D_0026D0A0[16] = {
    0x0B0E, 0x0504, 0x170E, 0x0101, 0x1616, 0x0000, 0x0004, 0x0000,
    0x0003, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026D0C0[16] = {
    0x0F16, 0x0403, 0x160C, 0x0101, 0x1414, 0x0004, 0x0004, 0x0004,
    0x0003, 0x0002, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026D0E0[16] = {
    0x131E, 0x0302, 0x150A, 0x0101, 0x1212, 0x0008, 0x0004, 0x0008,
    0x0003, 0x0003, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026D100[16] = {
    0x1726, 0x0201, 0x1408, 0x0101, 0x1010, 0x000C, 0x0004, 0x000C,
    0x0003, 0x0004, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026D120[16] = {
    0x1B2A, 0x0201, 0x1307, 0x0101, 0x0F0F, 0x000C, 0x0004, 0x000C,
    0x0003, 0x0004, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026D140[16] = {
    0x1F2E, 0x0201, 0x1206, 0x0101, 0x0E0E, 0x000E, 0x0004, 0x000E,
    0x0003, 0x0005, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026D160[16] = {
    0x2332, 0x0201, 0x1105, 0x0101, 0x0D0D, 0x0010, 0x0004, 0x0010,
    0x0003, 0x0006, 0x0003, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026D180[16] = {
    0x2736, 0x0201, 0x1004, 0x0101, 0x0C0C, 0x0012, 0x0004, 0x0012,
    0x0003, 0x0007, 0x0004, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026D1A0[24] = {
    0xFB40, 0xF780, 0xF540, 0xF640, 0xF100, 0xF9C0, 0xFB40, 0x0880,
    0xF540, 0x09C0, 0xF100, 0x0640, 0xF100, 0x0640, 0xF540, 0x09C0,
    0xFB40, 0x0880, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

void *D_0026D1D0[8] = {
    D_0026D1F0,
    D_0026D210,
    D_0026D230,
    D_0026D250,
    D_0026D270,
    D_0026D290,
    D_0026D2B0,
    D_0026D2D0,
};

u16 D_0026D1F0[16] = {
    0x6000, 0x0101, 0x0606, 0x0100, 0x0101, 0x2020, 0x0005, 0x0004,
    0x0005, 0x0003, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026D210[16] = {
    0x1000, 0x0202, 0x0505, 0x0101, 0x0202, 0x1C1C, 0x0007, 0x0004,
    0x0007, 0x0003, 0x0001, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026D230[16] = {
    0x0800, 0x0303, 0x0404, 0x0201, 0x0202, 0x1818, 0x0009, 0x0004,
    0x0009, 0x0003, 0x0001, 0x0003, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026D250[16] = {
    0x0000, 0x0404, 0x0303, 0x0202, 0x0202, 0x1414, 0x000B, 0x0004,
    0x000B, 0x0003, 0x0001, 0x0004, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026D270[16] = {
    0x0000, 0x0404, 0x0303, 0x0202, 0x0303, 0x1414, 0x000B, 0x0004,
    0x000C, 0x0003, 0x0001, 0x0004, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026D290[16] = {
    0x0000, 0x0505, 0x0303, 0x0302, 0x0303, 0x1313, 0x000C, 0x0004,
    0x000D, 0x0003, 0x0001, 0x0004, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026D2B0[16] = {
    0x0000, 0x0505, 0x0303, 0x0302, 0x0303, 0x1212, 0x000C, 0x0004,
    0x000C, 0x0003, 0x0001, 0x0004, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_0026D2D0[16] = {
    0x0000, 0x0606, 0x0202, 0x0402, 0x0404, 0x1111, 0x000D, 0x0004,
    0x000D, 0x0003, 0x0002, 0x0005, 0x0000, 0x0000, 0x0000, 0x0000,
};

u32 D_0028DB20 = 0x14;

u32 D_0028DB24 = 0xA;

u32 D_0028DB28 __attribute__((aligned(8))) = 8;

u16 D_0028DB30[4] = {
    0x9088, 0x0000, 0xE088, 0x0000,
};

u16 D_0028DB38[4] = {
    0x8068, 0x0101, 0xC068, 0x0101,
};

u16 D_0028DB40[4] = {
    0x7048, 0x0202, 0xA048, 0x0202,
};

u16 D_0028DB48[4] = {
    0x6028, 0x0202, 0x8028, 0x0202,
};

u16 D_0028DB50[4] = {
    0x5C24, 0x0202, 0x7C24, 0x0202,
};

u16 D_0028DB58[4] = {
    0x5820, 0x0303, 0x7820, 0x0303,
};

u16 D_0028DB60[4] = {
    0x541C, 0x0303, 0x741C, 0x0303,
};

u16 D_0028DB68[4] = {
    0x5018, 0x0404, 0x7018, 0x0404,
};

u16 D_0028DB70[4] = {
    0x0C00, 0x0008, 0x0000, 0x0000,
};

u32 D_0028DB78 = 6;

u32 D_0028DB7C = 0x12;

u16 D_0028DB80[2] = {
    0x8060, 0x2727,
};

u32 D_0028DB84 = 4;

u16 D_0028DB88[4] = {
    0xC080, 0x0101, 0x0404, 0x0000,
};

u32 D_0028DB90 = 6;

u32 D_0028DB94 = 0xC;

u16 D_0028DB98[2] = {
    0x3030, 0x0000,
};

u32 D_0028DB9C = 2;

u32 D_0028DBA0 = 0xE;

u16 D_0028DBA4[2] = {
    0x6000, 0x0000,
};

u32 D_0028DBA8 = 2;

u32 D_0028DBAC = 0x16;

u16 D_0028DBB0[2] = {
    0x1018, 0x0000,
};

u32 D_0028DBB4 = 2;

u16 D_0028DBB8[2] = {
    0x0000, 0x0000,
};

u32 D_0028DBBC = 2;

u32 D_0028DBC0 = 0x18;

u16 D_0028DBC4[2] = {
    0x0000, 0x0000,
};

u32 D_0028DBC8 __attribute__((aligned(8))) = 2;

u16 D_0028DBD0[4] = {
    0x1C24, 0x2A09, 0xFFFC, 0x0000,
};

u16 D_0028DBD8[4] = {
    0x181C, 0x2207, 0xFFFD, 0x0200,
};

u16 D_0028DBE0[4] = {
    0x1414, 0x1A05, 0xFFFE, 0x0400,
};

u16 D_0028DBE8[4] = {
    0x100C, 0x1203, 0xFFFF, 0x0600,
};

u16 D_0028DBF0[4] = {
    0x0E0C, 0x1203, 0x0000, 0x0680,
};

u16 D_0028DBF8[4] = {
    0x0C0B, 0x1103, 0x0001, 0x0700,
};

u16 D_0028DC00[4] = {
    0x0A0B, 0x1102, 0x0002, 0x0780,
};

u16 D_0028DC08[4] = {
    0x080A, 0x1002, 0x0003, 0x0800,
};
