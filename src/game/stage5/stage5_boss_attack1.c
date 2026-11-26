#include "common.h"
#include "entity.h"
#include "stage5_boss.h"

void stage5_boss_fire_loop1_form1_arm_guns_aimed_start(void);
void stage5_boss_fire_loop1_form1_arm_guns_aimed(void);
void stage5_boss_fire_loop1_form1_mouth_start(void);
void stage5_boss_fire_loop1_form1_mouth(s16 *arg1);
void stage5_boss_fire_loop1_form1_arm_guns_fixed_start(void);
void stage5_boss_fire_loop1_form1_arm_guns_fixed(void);
void stage5_boss_fire_loop1_form1_horn_start(void);
void stage5_boss_fire_loop1_form1_horn(void);
void stage5_boss_fire_loop1_form1_rage_start(void);
void stage5_boss_fire_loop1_form1_rage(void);

/* The set-up routine and the per-frame routine of every attack, by attack number. */
void (*stage5_boss_fire_loop1_routines[])(void) = {
    stage5_boss_fire_loop1_form1_arm_guns_aimed_start,
    stage5_boss_fire_loop1_form1_arm_guns_aimed,
    stage5_boss_fire_loop1_form1_mouth_start,
    (void (*)(void))stage5_boss_fire_loop1_form1_mouth,
    stage5_boss_fire_loop1_form1_arm_guns_fixed_start,
    stage5_boss_fire_loop1_form1_arm_guns_fixed,
    stage5_boss_fire_loop1_form1_horn_start,
    stage5_boss_fire_loop1_form1_horn,
    stage5_boss_fire_loop1_form1_rage_start,
    stage5_boss_fire_loop1_form1_rage,
    0,
    0,
};

extern u8 D_00264660[];

void stage5_boss_loop1_arm_gun_fire_a(void) {
    s32 bullet_fire256();
    u16 temp_a1;
    u16 temp_a1_2;
    u32 temp_a0;

    reg_a2 = (u8 *)D_00264660;
    reg_d0.h[1] = ARM_GUNS(reg_a4)->shots.speed;
    reg_d0.h[0] = ARM_GUNS(reg_a4)->shots.bullet;
    reg_d1.b[0] += reg_d1.b[0];
    reg_d3.w = 0;
    reg_d1.b[0] += reg_d1.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d1.b[0] += reg_d2.b[0];
    reg_a2 += reg_d3.h[0];
    reg_d3.h[1] = *(u16 *)reg_a2;
    reg_d3.h[0] = *(u16 *)(reg_a2 + 2);
    temp_a1 = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_tmp.h[1] = temp_a1;
    temp_a0 = reg_d3.w;
    temp_a1_2 = *(u16 *)reg_a3;
    reg_tmp.h[0] = temp_a1_2;
    reg_a3 += 2;
    reg_d4.w = 0;
    reg_d3.w = temp_a0 + reg_tmp.w;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    bullet_fire256();
}

void stage5_boss_loop1_arm_gun_fire_b(void) {
    s32 bullet_fire256();
    u16 temp_a1;
    u16 temp_a1_2;
    u32 temp_a0;

    reg_a2 = (u8 *)D_00264660;
    reg_d0.h[1] = ARM_GUNS(reg_a4)->shots.speed;
    reg_d0.h[0] = ARM_GUNS(reg_a4)->shots.bullet;
    reg_d1.b[0] += reg_d1.b[0];
    reg_d3.w = 0;
    reg_d1.b[0] += reg_d1.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d1.b[0] += reg_d2.b[0];
    reg_a2 += reg_d3.h[0];
    reg_d3.h[1] = *(u16 *)reg_a2;
    reg_d3.h[0] = *(u16 *)(reg_a2 + 2);
    temp_a1 = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_tmp.h[1] = temp_a1;
    temp_a0 = reg_d3.w;
    temp_a1_2 = *(u16 *)reg_a3;
    reg_tmp.h[0] = temp_a1_2;
    reg_a3 += 2;
    reg_d4.w = 0;
    reg_d3.w = temp_a0 + reg_tmp.w;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    bullet_fire256();
}

void stage5_boss_loop1_arm_gun_fire_c(void) {
    s32 bullet_fire256();
    u16 temp_a1;
    u16 temp_a1_2;
    u32 temp_a0;

    reg_a2 = (u8 *)D_00264660;
    reg_d0.h[1] = ARM_GUNS(reg_a4)->shots.speed;
    reg_d0.h[0] = ARM_GUNS(reg_a4)->shots.bullet;
    reg_d1.b[0] += reg_d1.b[0];
    reg_d3.w = 0;
    reg_d1.b[0] += reg_d1.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d1.b[0] += reg_d2.b[0];
    reg_a2 += reg_d3.h[0];
    reg_d3.h[1] = *(u16 *)reg_a2;
    reg_d3.h[0] = *(u16 *)(reg_a2 + 2);
    temp_a1 = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_tmp.h[1] = temp_a1;
    temp_a0 = reg_d3.w;
    temp_a1_2 = *(u16 *)reg_a3;
    reg_tmp.h[0] = temp_a1_2;
    reg_a3 += 2;
    reg_d4.w = 0;
    reg_d3.w = temp_a0 + reg_tmp.w;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    bullet_fire256();
    reg_d1.h[0] += 0x18;
    bullet_fire256();
    reg_d1.h[0] -= 0x30;
    bullet_fire256();
}

s32 rng_next();                            /* extern */

void stage5_boss_loop1_arm_guns_new_scatter(void) {
    rng_next();
    ARM_GUNS(reg_a4)->scatter_left_top = (u8) reg_d0.b[0];
    rng_next();
    ARM_GUNS(reg_a4)->scatter_left_middle = (u8) reg_d0.b[0];
    rng_next();
    ARM_GUNS(reg_a4)->scatter_left_bottom = (u8) reg_d0.b[0];
    rng_next();
    ARM_GUNS(reg_a4)->scatter_right_top = (u8) reg_d0.b[0];
    rng_next();
    ARM_GUNS(reg_a4)->scatter_right_middle = (u8) reg_d0.b[0];
    rng_next();
    ARM_GUNS(reg_a4)->scatter_right_bottom = (u8) reg_d0.b[0];
}

extern u16 stage5_boss_fire_loop1_form1_arm_guns_aimed_start_table[];
extern u32 stage5_boss_fire_loop1_form1_arm_guns_aimed_start_value;

void stage5_boss_fire_loop1_form1_arm_guns_aimed_start(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(stage5_boss_fire_loop1_form1_arm_guns_aimed_start_table);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) stage5_boss_fire_loop1_form1_arm_guns_aimed_start_value >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    stage5_boss_loop1_arm_guns_new_scatter();
    reg_d0.b[0] = STAGE5_ADJUST(reg_a6)->arm_guns_rounds_add;
    ARM_GUNS(reg_a4)->rounds.t.count += reg_d0.b[0];
    ARM_GUNS(reg_a4)->rounds.t.reload += reg_d0.b[0];
    reg_d0.b[0] = STAGE5_ADJUST(reg_a6)->arm_guns_shot_interval_sub;
    ARM_GUNS(reg_a4)->shot_interval -= reg_d0.b[0];
    reg_d0.b[0] = STAGE5_ADJUST(reg_a6)->arm_guns_round_interval_sub;
    ARM_GUNS(reg_a4)->round_interval -= reg_d0.b[0];
    reg_d0.h[0] = STAGE5_ADJUST(reg_a6)->arm_guns_speed_add;
    ARM_GUNS(reg_a4)->shots.speed += reg_d0.h[0];
    ARM_GUNS(reg_a4)->speed_reset += reg_d0.h[0];
}

s32 boss_attack_stop();
s32 enemy_switch_target_player();
extern u16 stage1_midboss_direction64_offsets_166[];
extern u8 D_00264600[];
extern u16 stage5_boss_fire_loop1_form1_arm_guns_aimed_table[];

void stage5_boss_fire_loop1_form1_arm_guns_aimed(void) {
    s32 bullet_fire256();
    u32 t1;
    u32 t2;
    u32 t3;
    u8 t4;
    u8 t5;
    u8 t6;

    reg_tmp.b[0] = ARM_GUNS(reg_a4)->shot.t.count;
    ARM_GUNS(reg_a4)->shot.t.count -= 1;
    if (reg_tmp.b[0] == 0) {
        ARM_GUNS(reg_a4)->shot.t.count = (u8) ARM_GUNS(reg_a4)->shot_interval;
        ENTITY(reg_a6)[1].misc.sb.user = 1;
        ENTITY(reg_a6)[2].misc.sb.user = 1;
        ENTITY(reg_a6)[3].misc.sb.user = 1;
        ENTITY(reg_a6)[4].misc.sb.user = 1;
        ENTITY(reg_a6)[5].misc.sb.user = 1;
        ENTITY(reg_a6)[6].misc.sb.user = 1;
        reg_a3 = (u8 *)(((u16 *)D_00264600));
        reg_d1.h[0] = ENTITY(reg_a6)[1].move.h;
        reg_d2.b[0] = ARM_GUNS(reg_a4)->scatter_left_top;
        stage5_boss_loop1_arm_gun_fire_c();
        reg_d1.h[0] = ENTITY(reg_a6)[2].move.h;
        reg_d2.b[0] = ARM_GUNS(reg_a4)->scatter_left_middle;
        stage5_boss_loop1_arm_gun_fire_b();
        reg_d1.h[0] = ENTITY(reg_a6)[3].move.h;
        reg_d2.b[0] = ARM_GUNS(reg_a4)->scatter_left_bottom;
        stage5_boss_loop1_arm_gun_fire_a();
        reg_d1.h[0] = ENTITY(reg_a6)[4].move.h;
        reg_d2.b[0] = ARM_GUNS(reg_a4)->scatter_right_top;
        stage5_boss_loop1_arm_gun_fire_c();
        reg_d1.h[0] = ENTITY(reg_a6)[5].move.h;
        reg_d2.b[0] = ARM_GUNS(reg_a4)->scatter_right_middle;
        stage5_boss_loop1_arm_gun_fire_b();
        reg_d1.h[0] = ENTITY(reg_a6)[6].move.h;
        reg_d2.b[0] = ARM_GUNS(reg_a4)->scatter_right_bottom;
        stage5_boss_loop1_arm_gun_fire_a();
        if (ARM_GUNS(reg_a4)->burst.t.count == 0) {
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_a1 = (u8 *)(stage1_midboss_direction64_offsets_166);
            reg_a3 = (u8 *)(stage5_boss_fire_loop1_form1_arm_guns_aimed_table);
            reg_d6.w = 5;
            do {
                reg_d7.w = 6;
                reg_d0.h[0] = STAGE5_ADJUST(reg_a6)->arm_guns_speed2_add;
                reg_d0.h[0] += *(u16 *)reg_a3;
                reg_a3 += 2;
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = reg_tmp.h[0];
                reg_d0.h[0] = reg_tmp.h[1];
                reg_d0.h[0] = *(u16 *)reg_a3;
                reg_a3 += 2;
                reg_d1.h[0] = *(u16 *)reg_a3;
                reg_a3 += 2;
                reg_d1.h[0] -= 0x18;
                reg_d5.h[1] = *(u16 *)reg_a3;
                reg_a3 += 2;
                reg_d5.h[0] = *(u16 *)reg_a3;
                reg_a3 += 2;
                do {
                    reg_d3.h[0] = reg_d1.h[0];
                    reg_d3.h[0] += 2;
                    reg_d3.h[0] &= 0xFC;
                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                    reg_d3.w += reg_d5.w;
                    bullet_fire256();
                    reg_d1.h[0] += 8;
                } while ((s16)(--reg_d7.h[0]) >= 0);
            } while ((s16)(--reg_d6.h[0]) >= 0);
        }
        reg_tmp.b[0] = ARM_GUNS(reg_a4)->burst.t.count;
        ARM_GUNS(reg_a4)->burst.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            ARM_GUNS(reg_a4)->burst.t.count = (u8) ARM_GUNS(reg_a4)->burst.t.reload;
            stage5_boss_loop1_arm_guns_new_scatter();
            t1 = ARM_GUNS(reg_a4)->shots.speed;
            if ((s16)(t1) < 0x10) {
                ARM_GUNS(reg_a4)->shots.speed = (u16) (t1 + 1);
            }
            ARM_GUNS(reg_a4)->shot.t.count = (u8) ARM_GUNS(reg_a4)->round_interval;
            ENTITY(reg_a6)[1].misc.sb.user = 0;
            ENTITY(reg_a6)[2].misc.sb.user = 0;
            ENTITY(reg_a6)[3].misc.sb.user = 0;
            ENTITY(reg_a6)[4].misc.sb.user = 0;
            ENTITY(reg_a6)[5].misc.sb.user = 0;
            ENTITY(reg_a6)[6].misc.sb.user = 0;
            enemy_switch_target_player();
            reg_tmp.b[0] = ARM_GUNS(reg_a4)->rounds.t.count;
            ARM_GUNS(reg_a4)->rounds.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                ARM_GUNS(reg_a4)->rounds.t.count = (u8) ARM_GUNS(reg_a4)->rounds.t.reload;
                ARM_GUNS(reg_a4)->shot.t.count = (u8) ARM_GUNS(reg_a4)->shot.t.reload;
                t4 = STAGE5_ADJUST(reg_a6)->arm_guns_rounds_add;
                if ((s32) t4 < 6) {
                    STAGE5_ADJUST(reg_a6)->arm_guns_rounds_add = (u8) (t4 + 2);
                }
                t5 = STAGE5_ADJUST(reg_a6)->arm_guns_shot_interval_sub;
                if ((s32) t5 < 2) {
                    STAGE5_ADJUST(reg_a6)->arm_guns_shot_interval_sub = (u8) (t5 + 1);
                }
                t6 = STAGE5_ADJUST(reg_a6)->arm_guns_round_interval_sub;
                if ((s32) t6 < 0x20) {
                    STAGE5_ADJUST(reg_a6)->arm_guns_round_interval_sub = (u8) (t6 + 8);
                }
                t2 = STAGE5_ADJUST(reg_a6)->arm_guns_speed_add;
                if ((s16)(t2) < 0x10) {
                    STAGE5_ADJUST(reg_a6)->arm_guns_speed_add = (u16) (t2 + 1);
                }
                t3 = STAGE5_ADJUST(reg_a6)->arm_guns_speed2_add;
                if ((s16)(t3) < 8) {
                    STAGE5_ADJUST(reg_a6)->arm_guns_speed2_add = (u16) (t3 + 2);
                }
                reg_d0.w = 0;
                boss_attack_stop();
            }
        }
    }
}

s32 rng_next_unsigned();
s32 rng_next_0_to_3();
extern u16 stage5_boss_fire_loop1_form1_mouth_start_table[];
extern u32 stage5_boss_fire_loop1_form1_mouth_start_value;

void stage5_boss_fire_loop1_form1_mouth_start(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(stage5_boss_fire_loop1_form1_mouth_start_table);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) stage5_boss_fire_loop1_form1_mouth_start_value >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    rng_next_unsigned();
    if (0 > reg_d0.sb[0]) {
        MOUTH(reg_a4)->fixed_turn_left *= -1;
        MOUTH(reg_a4)->fixed_turn_right *= -1;
        rng_next_0_to_3();
        MOUTH(reg_a4)->fixed_turn_left += reg_d0.b[0];
        rng_next_0_to_3();
        MOUTH(reg_a4)->fixed_turn_right += reg_d0.b[0];
    }
    ENTITY(reg_a6)[1].misc.sb.user = 1;
    ENTITY(reg_a6)[2].misc.sb.user = 1;
    ENTITY(reg_a6)[3].misc.sb.user = 1;
    ENTITY(reg_a6)[4].misc.sb.user = 1;
    ENTITY(reg_a6)[5].misc.sb.user = 1;
    ENTITY(reg_a6)[6].misc.sb.user = 1;
    reg_d0.b[0] = STAGE5_ADJUST(reg_a6)->mouth_burst_add;
    MOUTH(reg_a4)->burst.t.count += reg_d0.b[0];
    MOUTH(reg_a4)->burst.t.reload += reg_d0.b[0];
    reg_d0.h[0] = STAGE5_ADJUST(reg_a6)->mouth_speed_add;
    MOUTH(reg_a4)->aimed.speed += reg_d0.h[0];
    reg_d0.h[0] = STAGE5_ADJUST(reg_a6)->mouth_speed2_add;
    MOUTH(reg_a4)->fixed[0].speed += reg_d0.h[0];
    MOUTH(reg_a4)->fixed[1].speed += reg_d0.h[0];
    MOUTH(reg_a4)->fixed[2].speed += reg_d0.h[0];
}

s32 rng_next();
s32 direction256_between();
extern s16 g_player2[];
extern s16 g_player1[];

void stage5_boss_fire_loop1_form1_mouth(s16 *arg1) {
    s32 bullet_fire256();
    s16 *temp_a0;
    s16 *var_a1;
    u32 temp_a1;
    u32 temp_v1;
    u32 temp_v1_2;
    u32 temp_a0_3;
    u8 temp_v0;

    var_a1 = (s16 *)(arg1);
    reg_tmp.b[0] = MOUTH(reg_a4)->shot.t.count;
    MOUTH(reg_a4)->shot.t.count -= 1;
    if (reg_tmp.b[0] == 0) {
        MOUTH(reg_a4)->shot.t.count = (u8) MOUTH(reg_a4)->shot_interval;
        reg_d0.b[0] = MOUTH(reg_a4)->burst.t.count;
        reg_d0.h[0] &= 0xF;
        if (reg_d0.h[0] == 0) {
            reg_a0 = (u8 *)(g_player1);
            reg_a1 = (u8 *)(g_player2);
            if (ENEMY_STATE(reg_a5)->target_player != 0) {
                reg_atmp = (u8 *)(reg_a0);
                reg_a0 = (u8 *)(reg_a1);
                reg_a1 = (u8 *)(reg_atmp);
            }
            temp_a0 = (s16 *)(reg_a0);
            if (0 <= (s64)*(s16 *)((u8 *)(temp_a0) + (0))) {
                var_a1 = (s16 *)(reg_a1);
                if (0 > *var_a1) {
                    reg_a0 = (u8 *)(var_a1);
                    reg_atmp = (u8 *)(temp_a0);
                    reg_a1 = (u8 *)(temp_a0);
                    goto block_7;
                }
            } else {
block_7:
                reg_d2.w = (u32) *(u16 *)(reg_a0 + 2);
                reg_d3.w = (u32) *(u16 *)(reg_a0 + 4);
                reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
                reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
                reg_d0.h[0] += 0x7FFF + 0x70C1;
                direction256_between();
                rng_next();
                reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 1);
                reg_d1.b[0] += reg_d0.b[0];
                reg_d0.h[1] = MOUTH(reg_a4)->aimed.speed;
                reg_d0.h[0] = MOUTH(reg_a4)->aimed.bullet;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                temp_a1 = ENTITY(reg_a6)->x.h;
                reg_d2.h[0] = temp_a1;
                reg_d3.w = 0xF0C00000;
                reg_d6.h[0] = reg_d1.h[0];
                reg_d1.b[0] -= 3;
                reg_d4.w = 0;
                bullet_fire256();
                reg_d1.b[0] += 6;
                bullet_fire256();
                reg_d0.w += 0x20000;
                reg_d1.h[0] = reg_d6.h[0];
                bullet_fire256();
                reg_d1.b[0] -= 6;
                bullet_fire256();
                reg_d1.b[0] += 0xC;
                bullet_fire256();
                temp_a0_3 = reg_d0.w;
                reg_d0.w = temp_a0_3 + 0x20000;
                reg_d1.h[0] = reg_d6.h[0];
                reg_d1.b[0] -= 3;
                bullet_fire256();
                reg_d1.b[0] += 6;
                bullet_fire256();
                enemy_switch_target_player();
                goto block_8;
            }
        } else {
block_8:
            reg_d0.b[0] = MOUTH(reg_a4)->burst.t.count;
            if (MOUTH(reg_a4)->burst.t.reload == reg_d0.b[0]) {
                reg_d1.b[0] += 0x40;
                MOUTH(reg_a4)->fixed_direction_left = (u8) reg_d1.b[0];
                reg_d1.b[0] += 0x80;
                reg_d1.b[0] *= -1;
                MOUTH(reg_a4)->fixed_direction_right = (u8) reg_d1.b[0];
            }
            reg_d1.b[0] = MOUTH(reg_a4)->fixed_direction_left;
            reg_d0.h[1] = MOUTH(reg_a4)->fixed[0].speed;
            reg_d0.h[0] = MOUTH(reg_a4)->fixed[0].bullet;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d3.w = 0xF2C0FC00;
            reg_d4.w = 0;
            bullet_fire256();
            reg_d1.b[0] += 0x20;
            reg_d0.h[1] = MOUTH(reg_a4)->fixed[1].speed;
            reg_d0.h[0] = MOUTH(reg_a4)->fixed[1].bullet;
            bullet_fire256();
            reg_d1.b[0] += 0x60;
            reg_d0.h[1] = MOUTH(reg_a4)->fixed[2].speed;
            reg_d0.h[0] = MOUTH(reg_a4)->fixed[2].bullet;
            bullet_fire256();
            if (MOUTH(reg_a4)->burst.t.count & 1) {
                reg_d1.b[0] += 0x20;
                reg_d0.w = 0x90003;
                bullet_fire256();
            }
            reg_d1.b[0] = MOUTH(reg_a4)->fixed_direction_right;
            reg_d0.h[1] = MOUTH(reg_a4)->fixed[0].speed;
            reg_d0.h[0] = MOUTH(reg_a4)->fixed[0].bullet;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d3.h[0] = 0x400;
            reg_d4.w = 0;
            bullet_fire256();
            reg_d1.b[0] += 0x20;
            reg_d0.h[1] = MOUTH(reg_a4)->fixed[1].speed;
            reg_d0.h[0] = MOUTH(reg_a4)->fixed[1].bullet;
            bullet_fire256();
            reg_d1.b[0] += 0x60;
            reg_d0.h[1] = MOUTH(reg_a4)->fixed[2].speed;
            reg_d0.h[0] = MOUTH(reg_a4)->fixed[2].bullet;
            bullet_fire256();
            if (MOUTH(reg_a4)->burst.t.count & 1) {
                reg_d0.w = 0x90003;
                bullet_fire256();
            }
            reg_d0.b[0] = MOUTH(reg_a4)->fixed_turn_left;
            MOUTH(reg_a4)->fixed_direction_left += reg_d0.b[0];
            var_a1 = (s16 *)(reg_a4);
            reg_d0.b[0] = (*(u8 *)((u8 *)(var_a1) + (0x1E)));
            (*(u8 *)((u8 *)(var_a1) + (8))) += reg_d0.b[0];
        }
        reg_tmp.b[0] = MOUTH(reg_a4)->burst.t.count;
        MOUTH(reg_a4)->burst.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            MOUTH(reg_a4)->shot.t.count = (u8) MOUTH(reg_a4)->shot.t.reload;
            MOUTH(reg_a4)->fixed_turn_left *= -1;
            MOUTH(reg_a4)->fixed_turn_right *= -1;
            temp_v0 = STAGE5_ADJUST(reg_a6)->mouth_burst_add;
            if ((s32) temp_v0 < 0x3C) {
                STAGE5_ADJUST(reg_a6)->mouth_burst_add = (u8) (temp_v0 + 0x14);
            }
            temp_v1 = STAGE5_ADJUST(reg_a6)->mouth_speed_add;
            if ((s16)(temp_v1) < 8) {
                STAGE5_ADJUST(reg_a6)->mouth_speed_add = (u16) (temp_v1 + 1);
            }
            temp_v1_2 = STAGE5_ADJUST(reg_a6)->mouth_speed2_add;
            if ((s16)(temp_v1_2) < 0x1A) {
                STAGE5_ADJUST(reg_a6)->mouth_speed2_add = (u16) (temp_v1_2 + 1);
            }
            ENTITY(reg_a6)[1].misc.sb.user = 0;
            ENTITY(reg_a6)[2].misc.sb.user = 0;
            ENTITY(reg_a6)[3].misc.sb.user = 0;
            ENTITY(reg_a6)[4].misc.sb.user = 0;
            ENTITY(reg_a6)[5].misc.sb.user = 0;
            ENTITY(reg_a6)[6].misc.sb.user = 0;
            reg_d0.w = 1;
            boss_attack_stop();
        }
    }
}

void stage5_boss_loop1_arm_gun_b_fire(void) {
    u16 temp_a2;

    reg_a2 = D_00264660;
    reg_d0.h[1] = ARM_GUNS_B(reg_a4)->shots.speed;
    reg_d0.h[0] = ARM_GUNS_B(reg_a4)->shots.bullet;
    reg_d1.b[0] += reg_d1.b[0];
    reg_d3.w = 0;
    reg_d1.b[0] += reg_d1.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_a2 += reg_d3.h[0];
    reg_d3.h[1] = *(u16 *)reg_a2;
    reg_d3.h[0] = *(u16 *)(reg_a2 + 2);
    temp_a2 = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_tmp.h[1] = temp_a2;
    reg_tmp.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d4.w = 0;
    reg_d3.w += reg_tmp.w;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
}

extern u16 stage5_boss_fire_loop1_form1_arm_guns_fixed_start_table[];
extern u32 stage5_boss_fire_loop1_form1_arm_guns_fixed_start_value;

void stage5_boss_fire_loop1_form1_arm_guns_fixed_start(void) {
    (*(u16 **)&reg_a0) = stage5_boss_fire_loop1_form1_arm_guns_fixed_start_table;
    (*(u16 **)&reg_a1) = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) stage5_boss_fire_loop1_form1_arm_guns_fixed_start_value >> 1) - 1;
    do {
        *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
        (*(u16 **)&reg_a0) += 1;
        (*(u16 **)&reg_a1) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    if (STAGE5_EXTRA(reg_a6)->arm_guns_b_turn != 0) {
        ARM_GUNS_B(reg_a4)->turn *= -1;
    }
    reg_d0.b[0] = STAGE5_ADJUST(reg_a6)->arm_guns_b_rounds_add.b[1];
    ARM_GUNS_B(reg_a4)->rounds.t.count += reg_d0.b[0];
    ARM_GUNS_B(reg_a4)->rounds.t.reload += reg_d0.b[0];
    reg_d0.h[0] = STAGE5_ADJUST(reg_a6)->arm_guns_b_speed2_add;
    ARM_GUNS_B(reg_a4)->aimed.speed += reg_d0.h[0];
    rng_next();
    ARM_GUNS_B(reg_a4)->direction_left_top = (u8) reg_d0.b[0];
    rng_next();
    ARM_GUNS_B(reg_a4)->direction_left_middle = (u8) reg_d0.b[0];
    rng_next();
    ARM_GUNS_B(reg_a4)->direction_left_bottom = (u8) reg_d0.b[0];
    rng_next();
    ARM_GUNS_B(reg_a4)->direction_right_top = (u8) reg_d0.b[0];
    rng_next();
    ARM_GUNS_B(reg_a4)->direction_right_middle = (u8) reg_d0.b[0];
    rng_next();
    ARM_GUNS_B(reg_a4)->direction_right_bottom = (u8) reg_d0.b[0];
}

s32 rng_next_d5();
extern u8 D_00264600[];

void stage5_boss_fire_loop1_form1_arm_guns_fixed(void) {
    s32 bullet_fire256();
    s16 *temp_a0;
    s16 *var_a1;
    u16 temp_a0_2;
    u16 temp_v0;
    u16 temp_v0_2;

    reg_tmp.b[0] = ARM_GUNS_B(reg_a4)->shot.t.count;
    ARM_GUNS_B(reg_a4)->shot.t.count -= 1;
    if (reg_tmp.b[0] == 0) {
        var_a1 = (s16 *)(reg_a4);
        (*(u8 *)((u8 *)(var_a1) + (3))) = (u8) (*(u8 *)((u8 *)(var_a1) + (9)));
        ENTITY(reg_a6)[1].misc.sb.user = 1;
        ENTITY(reg_a6)[2].misc.sb.user = 1;
        ENTITY(reg_a6)[3].misc.sb.user = 1;
        ENTITY(reg_a6)[4].misc.sb.user = 1;
        ENTITY(reg_a6)[5].misc.sb.user = 1;
        ENTITY(reg_a6)[6].misc.sb.user = 1;
        if (ARM_GUNS_B(reg_a4)->burst.t.count & 2) {
            reg_a0 = (u8 *)(g_player1);
            reg_a1 = (u8 *)(g_player2);
            if (ENEMY_STATE(reg_a5)->target_player != 0) {
                reg_atmp = (u8 *)(reg_a0);
                reg_a0 = (u8 *)(reg_a1);
                reg_a1 = (u8 *)(reg_atmp);
            }
            temp_a0 = (s16 *)(reg_a0);
            if (0 <= (s64)*(s16 *)((u8 *)(temp_a0) + (0))) {
                var_a1 = (s16 *)(reg_a1);
                if (0 > *var_a1) {
                    reg_a0 = (u8 *)(var_a1);
                    reg_atmp = (u8 *)(temp_a0);
                    reg_a1 = (u8 *)(temp_a0);
                    goto block_7;
                }
            } else {
block_7:
                reg_d2.w = (u32) *(u16 *)(reg_a0 + 2);
                reg_d3.w = (u32) *(u16 *)(reg_a0 + 4);
                reg_d7.h[0] = reg_d2.h[0];
                reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
                reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
                reg_d0.h[0] += 0x7FFF + 0x70C1;
                direction256_between();
                reg_d0.h[1] = ARM_GUNS_B(reg_a4)->aimed.speed;
                reg_d0.h[0] = ARM_GUNS_B(reg_a4)->aimed.bullet;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                temp_a0_2 = ENTITY(reg_a6)->x.h;
                reg_d2.h[0] = temp_a0_2;
                reg_d3.w = 0xF0C00000;
                reg_d4.w = 0;
                reg_d5.h[0] = ENTITY(reg_a6)->y.h;
                reg_d5.h[0] += 0x7FFF + 0x7601;
                if ((s32) reg_d5.h[0] <= (s32) reg_d7.h[0]) {
                    reg_d0.w += 0x100000;
                    rng_next_d5();
                    reg_d5.b[0] = (u8) ((s8) reg_d5.b[0] >> 1);
                    reg_d1.b[0] += reg_d5.b[0];
                    bullet_fire256();
                    reg_d0.w += 0x40000;
                    bullet_fire256();
                    reg_d0.w += 0x40000;
                }
                bullet_fire256();
                enemy_switch_target_player();
                goto block_10;
            }
        } else {
block_10:
            reg_a3 = (u8 *)D_00264600;
            reg_d1.h[0] = ENTITY(reg_a6)[1].move.h;
            stage5_boss_loop1_arm_gun_b_fire();
            reg_d1.h[0] = 0x70;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_left_top;
            bullet_fire256();
            reg_d0.w += 0xD0000;
            reg_d1.h[0] = 0xC0;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_left_top;
            bullet_fire256();
            reg_d1.h[0] = ENTITY(reg_a6)[2].move.h;
            stage5_boss_loop1_arm_gun_b_fire();
            reg_d1.h[0] = 0x7C;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_left_middle;
            bullet_fire256();
            reg_d0.w += 0xD0000;
            reg_d1.h[0] = 0xB8;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_left_middle;
            bullet_fire256();
            reg_d1.h[0] = ENTITY(reg_a6)[3].move.h;
            stage5_boss_loop1_arm_gun_b_fire();
            reg_d1.h[0] = 0x98;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_left_bottom;
            bullet_fire256();
            reg_d0.w += 0xD0000;
            reg_d1.h[0] = 0xB0;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_left_bottom;
            bullet_fire256();
            reg_d1.h[0] = ENTITY(reg_a6)[4].move.h;
            stage5_boss_loop1_arm_gun_b_fire();
            reg_d1.h[0] = 0x90;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_right_top;
            bullet_fire256();
            reg_d0.w += 0xD0000;
            reg_d1.h[0] = 0x40;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_right_top;
            bullet_fire256();
            reg_d1.h[0] = ENTITY(reg_a6)[5].move.h;
            stage5_boss_loop1_arm_gun_b_fire();
            reg_d1.h[0] = 0x84;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_right_middle;
            bullet_fire256();
            reg_d0.w += 0xD0000;
            reg_d1.h[0] = 0x48;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_right_middle;
            bullet_fire256();
            reg_d1.h[0] = ENTITY(reg_a6)[6].move.h;
            stage5_boss_loop1_arm_gun_b_fire();
            reg_d1.h[0] = 0x68;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_right_bottom;
            bullet_fire256();
            reg_d0.w += 0xD0000;
            reg_d1.h[0] = 0x50;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_right_bottom;
            bullet_fire256();
        }
        reg_d0.b[0] = ARM_GUNS_B(reg_a4)->turn;
        ENTITY(reg_a6)[1].move.b.dir += reg_d0.b[0];
        ENTITY(reg_a6)[2].move.b.dir -= reg_d0.b[0];
        ENTITY(reg_a6)[3].move.b.dir += reg_d0.b[0];
        ENTITY(reg_a6)[4].move.b.dir -= reg_d0.b[0];
        ENTITY(reg_a6)[5].move.b.dir += reg_d0.b[0];
        ENTITY(reg_a6)[6].move.b.dir -= reg_d0.b[0];
        reg_d0.h[0] = 0x3F;
        ENTITY(reg_a6)[1].move.b.dir &= reg_d0.b[0];
        ENTITY(reg_a6)[2].move.b.dir &= reg_d0.b[0];
        ENTITY(reg_a6)[3].move.b.dir &= reg_d0.b[0];
        ENTITY(reg_a6)[4].move.b.dir &= reg_d0.b[0];
        ENTITY(reg_a6)[5].move.b.dir &= reg_d0.b[0];
        ENTITY(reg_a6)[6].move.b.dir &= reg_d0.b[0];
        reg_tmp.b[0] = ARM_GUNS_B(reg_a4)->burst.t.count;
        ARM_GUNS_B(reg_a4)->burst.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            rng_next();
            reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 1);
            reg_d0.b[0] += ARM_GUNS_B(reg_a4)->burst.t.reload;
            ARM_GUNS_B(reg_a4)->burst.t.count = (u8) reg_d0.b[0];
            ARM_GUNS_B(reg_a4)->shot.t.count = (u8) ARM_GUNS_B(reg_a4)->round_interval;
            rng_next();
            ARM_GUNS_B(reg_a4)->direction_left_top = (u8) reg_d0.b[0];
            rng_next();
            ARM_GUNS_B(reg_a4)->direction_left_middle = (u8) reg_d0.b[0];
            rng_next();
            ARM_GUNS_B(reg_a4)->direction_left_bottom = (u8) reg_d0.b[0];
            rng_next();
            ARM_GUNS_B(reg_a4)->direction_right_top = (u8) reg_d0.b[0];
            rng_next();
            ARM_GUNS_B(reg_a4)->direction_right_middle = (u8) reg_d0.b[0];
            rng_next();
            ARM_GUNS_B(reg_a4)->direction_right_bottom = (u8) reg_d0.b[0];
            reg_tmp.b[0] = ARM_GUNS_B(reg_a4)->rounds.t.count;
            ARM_GUNS_B(reg_a4)->rounds.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                ARM_GUNS_B(reg_a4)->shot.t.count = (u8) ARM_GUNS_B(reg_a4)->shot.t.reload;
                STAGE5_EXTRA(reg_a6)->arm_guns_b_turn = (s8) ~((s8) STAGE5_EXTRA(reg_a6)->arm_guns_b_turn);
                temp_v0 = STAGE5_ADJUST(reg_a6)->arm_guns_b_rounds_add.h;
                if ((s32) temp_v0 < 4) {
                    STAGE5_ADJUST(reg_a6)->arm_guns_b_rounds_add.h = (u16) (temp_v0 + 1);
                }
                temp_v0_2 = STAGE5_ADJUST(reg_a6)->arm_guns_b_speed2_add;
                if ((s32) temp_v0_2 < 4) {
                    STAGE5_ADJUST(reg_a6)->arm_guns_b_speed2_add = (u16) (temp_v0_2 + 1);
                }
                ENTITY(reg_a6)[1].misc.sb.user = 0;
                ENTITY(reg_a6)[2].misc.sb.user = 0;
                ENTITY(reg_a6)[3].misc.sb.user = 0;
                ENTITY(reg_a6)[4].misc.sb.user = 0;
                ENTITY(reg_a6)[5].misc.sb.user = 0;
                ENTITY(reg_a6)[6].misc.sb.user = 0;
                reg_d0.w = 2;
                boss_attack_stop();
            }
        }
    }
}

void stage5_boss_loop1_horn_fire(void) {
    void bullet_fire256(void);
    bullet_fire256();
}

extern u16 stage5_boss_fire_loop1_form1_horn_start_table[];
extern u32 stage5_boss_fire_loop1_form1_horn_start_value;

void stage5_boss_fire_loop1_form1_horn_start(void) {
    (*(u16 **)&reg_a0) = stage5_boss_fire_loop1_form1_horn_start_table;
    (*(u16 **)&reg_a1) = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) stage5_boss_fire_loop1_form1_horn_start_value >> 1) - 1;
    do {
        *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
        (*(u16 **)&reg_a0) += 1;
        (*(u16 **)&reg_a1) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = STAGE5_EXTRA(reg_a6)->horn_speed_add;
    HORN(reg_a4)->shots.speed += reg_d0.h[0];
    HORN(reg_a4)->speed_reset += reg_d0.h[0];
    reg_d0.b[0] = STAGE5_ADJUST(reg_a6)->horn_rounds_add;
    HORN(reg_a4)->rounds.t.count += reg_d0.b[0];
    HORN(reg_a4)->rounds.t.reload += reg_d0.b[0];
    reg_d0.b[0] = STAGE5_ADJUST(reg_a6)->horn_round_interval_sub;
    HORN(reg_a4)->round_interval -= reg_d0.b[0];
#ifndef DEATH_LABEL
    HORN(reg_a4)->shot.t.count += 2;
#endif
}

extern u16 stage5_boss_fire_loop1_form1_horn_table[];

void stage5_boss_fire_loop1_form1_horn(void) {
    s16 *temp_a0_2;
    s8 temp_a0_5;
    s8 temp_a0_6;
    u16 temp_a0_4;
    u16 temp_a1;
    u16 temp_a1_2;
    u16 temp_v0_2;
    u32 temp_s0;
    u8 temp_a0;
    u8 temp_v0;
    u8 temp_v0_3;
    u8 temp_v1;

    reg_tmp.b[0] = HORN(reg_a4)->shot.t.count;
    HORN(reg_a4)->shot.t.count -= 1;
    if (reg_tmp.b[0] == 0) {
        HORN(reg_a4)->shot.t.count = (u8) HORN(reg_a4)->shot_interval;
        reg_d0.b[0] = HORN(reg_a4)->burst.t.count;
        temp_a0 = HORN(reg_a4)->burst.t.reload;
        if (temp_a0 == reg_d0.b[0]) {
            rng_next_0_to_3();
            HORN(reg_a4)->direction_shift = (u8) reg_d0.b[0];
        }
        reg_a0 = (u8 *)(g_player1);
        reg_a1 = (u8 *)(g_player2);
        if (ENEMY_STATE(reg_a5)->target_player != 0) {
            reg_atmp = (u8 *)(reg_a0);
            reg_a0 = (u8 *)(reg_a1);
            reg_a1 = (u8 *)(reg_atmp);
        }
        temp_a0_2 = (s16 *)(reg_a0);
        if (0 <= (s64)*(s16 *)((u8 *)(temp_a0_2) + (0))) {
            if (0 > (s64)*(s16 *)reg_a1) {
                reg_a0 = (u8 *)(reg_a1);
                reg_atmp = (u8 *)(temp_a0_2);
                reg_a1 = (u8 *)(temp_a0_2);
                goto block_8;
            }
        } else {
block_8:
            reg_d2.w = (u32) *(u16 *)(reg_a0 + 2);
            reg_d3.w = (u32) *(u16 *)(reg_a0 + 4);
            reg_d6.h[0] = reg_d2.h[0];
            reg_d7.h[0] = reg_d3.h[0];
            reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
            reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
            reg_a3 = (u8 *)(stage5_boss_fire_loop1_form1_horn_table);
            temp_a1 = HORN(reg_a4)->muzzle;
            reg_d4.h[0] = temp_a1;
            reg_a3 += reg_d4.h[0];
            reg_d0.h[0] += 0x940;
            reg_d1.h[0] += 0xD00;
            direction256_between();
            temp_s0 = reg_d1.w;
            reg_d2.h[0] = reg_d6.h[0];
            reg_d3.h[0] = reg_d7.h[0];
            reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
            reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
            reg_d0.h[0] += 0x940;
            reg_d1.h[0] += 0x7FFF + 0x7301;
            direction256_between();
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            temp_a1_2 = ENTITY(reg_a6)->x.h;
            reg_d2.h[0] = temp_a1_2;
            temp_a0_4 = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d3.h[1] = temp_a0_4;
            reg_d3.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d4.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            temp_a0_5 = (s8) reg_d4.b[0];
            reg_d5.b[0] = HORN(reg_a4)->direction_shift;
            reg_d4.b[0] = (u8) (temp_a0_5 >> reg_d5.b[0]);
            reg_d1.b[0] += reg_d4.b[0];
            reg_d0.h[1] = HORN(reg_a4)->shots.speed;
            reg_d0.h[0] = HORN(reg_a4)->shots.bullet;
            reg_d4.w = 0;
            reg_d6.b[0] = HORN(reg_a4)->rounds.t.count;
            stage5_boss_loop1_horn_fire();
            reg_d1.w = temp_s0;
            reg_d3.h[1] = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d3.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d4.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            temp_a0_6 = (s8) reg_d4.b[0];
            reg_d5.b[0] = HORN(reg_a4)->direction_shift;
            reg_d4.b[0] = (u8) (temp_a0_6 >> reg_d5.b[0]);
            reg_d1.b[0] += reg_d4.b[0];
            reg_d4.w = 0;
            reg_d6.b[0] = HORN(reg_a4)->rounds.t.count;
            reg_d6.b[0] = ~(s8) reg_d6.b[0];
            stage5_boss_loop1_horn_fire();
            reg_tmp.h[0] = HORN(reg_a4)->muzzle;
            HORN(reg_a4)->muzzle -= 0xC;
            if ((s32) reg_tmp.h[0] < 0xC) {
                HORN(reg_a4)->muzzle = 0x30U;
            }
        }
        HORN(reg_a4)->shots.speed += 1;
        reg_tmp.b[0] = HORN(reg_a4)->burst.t.count;
        HORN(reg_a4)->burst.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            enemy_switch_target_player();
            temp_v1 = HORN(reg_a4)->burst.t.reload;
            if ((s32) temp_v1 < 0x1E) {
                HORN(reg_a4)->burst.t.reload = (u8) (temp_v1 + 0xF);
            }
            HORN(reg_a4)->burst.t.count = (u8) HORN(reg_a4)->burst.t.reload;
            HORN(reg_a4)->shot.t.count = (u8) HORN(reg_a4)->round_interval;
#ifndef DEATH_LABEL
            HORN(reg_a4)->shot.t.count += 4;
#endif
            HORN(reg_a4)->speed_reset += 1;
            HORN(reg_a4)->shots.speed = (u16) HORN(reg_a4)->speed_reset;
            reg_tmp.b[0] = HORN(reg_a4)->rounds.t.count;
            HORN(reg_a4)->rounds.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                HORN(reg_a4)->rounds.t.count = (u8) HORN(reg_a4)->rounds.t.reload;
                HORN(reg_a4)->shot.t.count = (u8) HORN(reg_a4)->shot.t.reload;
                temp_v0 = STAGE5_ADJUST(reg_a6)->horn_rounds_add;
                if ((s32) temp_v0 < 2) {
                    STAGE5_ADJUST(reg_a6)->horn_rounds_add = (u8) (temp_v0 + 1);
                }
                temp_v0_2 = STAGE5_EXTRA(reg_a6)->horn_speed_add;
                if ((s32) temp_v0_2 < 6) {
                    STAGE5_EXTRA(reg_a6)->horn_speed_add = (u16) (temp_v0_2 + 1);
                }
                temp_v0_3 = STAGE5_ADJUST(reg_a6)->horn_round_interval_sub;
                if ((s32) temp_v0_3 < 0x10) {
                    STAGE5_ADJUST(reg_a6)->horn_round_interval_sub = (u8) (temp_v0_3 + 4);
                }
                reg_d0.w = 3;
                boss_attack_stop();
            }
        }
    }
}

void stage5_boss_loop1_form1_rage_fire(void) {
    s32 bullet_fire256();
    u32 var_a1;
    u8 var_a0;

    var_a0 = 0xF0C00000;
    reg_d0.h[1] = FORM1_RAGE(reg_a4)->shots.speed;
    reg_d0.h[0] = FORM1_RAGE(reg_a4)->shots.bullet;
    reg_tmp.h[1] = STAGE5_BOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE5_BOSS(reg_a5)->hp[1];
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    var_a1 = ENTITY(reg_a6)->x.h;
    reg_d2.h[0] = var_a1;
    reg_d5.w = 0xF0C00000;
    reg_d6.b[0] = 0x10;
    reg_d7.w = 1;
    reg_d4.w = 0;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
        reg_d3.w += reg_d5.w;
        bullet_fire256();
        var_a1 = (u16) reg_d1.b[0];
        var_a0 = var_a1 + reg_d6.b[0];
        reg_d1.b[0] = var_a0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

extern u16 D_00264800[];
extern u32 D_0028DA14;

void stage5_boss_fire_loop1_form1_rage_start(void) {
    (*(u16 **)&reg_a0) = D_00264800;
    (*(u16 **)&reg_a1) = (u16 *)((*(s32 *)&reg_a4) + 2);
    reg_d0.w = ((u32) D_0028DA14 >> 1) - 1;
    do {
        *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
        (*(u16 **)&reg_a0) += 1;
        (*(u16 **)&reg_a1) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

s32 slowdown_allow_with_boss();

void stage5_boss_fire_loop1_form1_rage(void) {
    u32 temp_a0;
    u8 temp_v1;
    u8 temp_v1_2;

    reg_tmp.b[0] = FORM1_RAGE(reg_a4)->shot.t.count;
    FORM1_RAGE(reg_a4)->shot.t.count -= 1;
    if (reg_tmp.b[0] == 0) {
        reg_d0.b[0] = FORM1_RAGE(reg_a4)->shot_interval;
        reg_tmp.h[1] = STAGE5_BOSS(reg_a5)->hp[0];
        reg_tmp.h[0] = STAGE5_BOSS(reg_a5)->hp[1];
        if ((u32) reg_tmp.w < 0x15000U) {
            reg_d0.b[0] -= 2;
            slowdown_allow_with_boss();
        }
        FORM1_RAGE(reg_a4)->shot.t.count = (u8) reg_d0.b[0];
        reg_a1 = (u8 *)stage1_midboss_direction64_offsets_166;
        reg_d1.b[0] = FORM1_RAGE(reg_a4)->direction;
        stage5_boss_loop1_form1_rage_fire();
        reg_d1.b[0] = FORM1_RAGE(reg_a4)->direction;
        reg_d1.b[0] += 0x40;
        stage5_boss_loop1_form1_rage_fire();
        reg_d1.b[0] = FORM1_RAGE(reg_a4)->direction;
        reg_d1.b[0] += 0x80;
        stage5_boss_loop1_form1_rage_fire();
        reg_d1.b[0] = FORM1_RAGE(reg_a4)->direction;
        reg_d1.b[0] += 0xC0;
        stage5_boss_loop1_form1_rage_fire();
        reg_d0.b[0] = FORM1_RAGE(reg_a4)->turn;
        reg_tmp.h[1] = STAGE5_BOSS(reg_a5)->hp[0];
        reg_tmp.h[0] = STAGE5_BOSS(reg_a5)->hp[1];
        if ((u32) reg_tmp.w < 0x15000U) {
            reg_d0.b[0] = (s8) reg_d0.b[0] * 2;
        }
        FORM1_RAGE(reg_a4)->direction += reg_d0.b[0];
        reg_tmp.b[0] = FORM1_RAGE(reg_a4)->burst.t.count;
        FORM1_RAGE(reg_a4)->burst.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            FORM1_RAGE(reg_a4)->burst.t.count = (u8) FORM1_RAGE(reg_a4)->burst.t.reload;
            FORM1_RAGE(reg_a4)->shot.t.count = (u8) FORM1_RAGE(reg_a4)->round_interval;
            FORM1_RAGE(reg_a4)->turn *= -1;
            temp_a0 = FORM1_RAGE(reg_a4)->shots.speed;
            if ((s16)(temp_a0) < 6) {
                FORM1_RAGE(reg_a4)->shots.speed = (u16) (temp_a0 + 2);
            }
            reg_tmp.b[0] = FORM1_RAGE(reg_a4)->rounds.t.count;
            FORM1_RAGE(reg_a4)->rounds.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                FORM1_RAGE(reg_a4)->rounds.t.count = (u8) FORM1_RAGE(reg_a4)->rounds.t.reload;
                temp_v1 = FORM1_RAGE(reg_a4)->shot_interval;
                if ((s32) temp_v1 > 7) {
                    FORM1_RAGE(reg_a4)->shot_interval = (u8) (temp_v1 - 2);
                    if ((s32) FORM1_RAGE(reg_a4)->shot_interval < 8) {
                        slowdown_allow_with_boss();
                    }
                }
                temp_v1_2 = FORM1_RAGE(reg_a4)->burst.t.reload;
                if ((s32) temp_v1_2 < 0xC7) {
                    FORM1_RAGE(reg_a4)->burst.t.reload = (u8) (temp_v1_2 + 0x14);
                }
                FORM1_RAGE(reg_a4)->burst.t.count = (u8) FORM1_RAGE(reg_a4)->burst.t.reload;
            }
        }
    }
}

u16 stage5_boss_fire_loop1_form1_arm_guns_aimed_start_table[16] = {
    0x2080, 0x0202, 0x0606, 0x0440, 0xFFFB, 0x0007, 0xFFFB, 0x0404,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u8 D_00264600[32] = {
    0xC0, 0x14, 0x80, 0xF1, 0x00, 0xFB, 0x40, 0xEE, 0x80, 0xE8, 0xC0, 0xEE, 0x40, 0x07, 0x40, 0x10,
    0x80, 0xF7, 0xC0, 0x14, 0x40, 0xE5, 0x40, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u16 stage5_boss_fire_loop1_form1_arm_guns_aimed_table[32] = {
    0xFFF7, 0x0005, 0x005C, 0x0DC0, 0xED40, 0xFFF6, 0x0004, 0x006E,
    0x0940, 0xF300, 0xFFF5, 0x0005, 0x0080, 0x06C0, 0xF940, 0xFFF7,
    0x0005, 0x00A4, 0x0DC0, 0x12C0, 0xFFF6, 0x0004, 0x0092, 0x0940,
    0x0D00, 0xFFF5, 0x0005, 0x0080, 0x06C0, 0x06C0, 0x0000, 0x0000,
};

u8 D_00264660[256] = {
    0x00, 0x0E, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x01, 0x40, 0x0D, 0x00, 0x02, 0x00, 0x0D, 0x00, 0x03,
    0x40, 0x0C, 0xC0, 0x03, 0xC0, 0x0B, 0xC0, 0x04, 0x80, 0x0A, 0x80, 0x05, 0x00, 0x0A, 0x40, 0x06,
    0x00, 0x09, 0x00, 0x07, 0x00, 0x08, 0x80, 0x07, 0x00, 0x07, 0xC0, 0x07, 0xC0, 0x05, 0x00, 0x08,
    0xC0, 0x04, 0x40, 0x08, 0xC0, 0x03, 0x80, 0x08, 0xC0, 0x02, 0xC0, 0x08, 0x80, 0x01, 0xC0, 0x08,
    0x80, 0x00, 0xC0, 0x08, 0x40, 0xFF, 0xC0, 0x08, 0x40, 0xFE, 0xC0, 0x08, 0x80, 0xFD, 0x80, 0x08,
    0x00, 0xFC, 0x80, 0x08, 0x40, 0xFB, 0x00, 0x08, 0x40, 0xFA, 0x80, 0x07, 0x40, 0xF9, 0x40, 0x07,
    0x00, 0xF8, 0xC0, 0x06, 0x00, 0xF7, 0x40, 0x06, 0x80, 0xF6, 0x80, 0x05, 0xC0, 0xF5, 0xC0, 0x04,
    0x40, 0xF5, 0xC0, 0x03, 0x80, 0xF4, 0x00, 0x03, 0x00, 0xF4, 0x00, 0x02, 0x00, 0xF4, 0x00, 0x01,
    0xC0, 0xF3, 0x00, 0x00, 0x00, 0xF4, 0x00, 0xFF, 0x00, 0xF4, 0x40, 0xFE, 0x40, 0xF4, 0x80, 0xFD,
    0x80, 0xF4, 0xC0, 0xFC, 0x00, 0xF5, 0x00, 0xFC, 0x80, 0xF5, 0x40, 0xFB, 0x40, 0xF6, 0x80, 0xFA,
    0x00, 0xF7, 0xC0, 0xF9, 0xC0, 0xF7, 0x40, 0xF9, 0xC0, 0xF8, 0x80, 0xF8, 0xC0, 0xF9, 0x00, 0xF8,
    0x00, 0xFB, 0xC0, 0xF7, 0x80, 0xFC, 0x80, 0xF7, 0x80, 0xFD, 0x00, 0xF7, 0x00, 0xFF, 0x00, 0xF7,
    0x80, 0x00, 0xC0, 0xF6, 0x00, 0x02, 0x00, 0xF7, 0x80, 0x03, 0x40, 0xF7, 0x00, 0x05, 0x40, 0xF7,
    0x00, 0x06, 0xC0, 0xF7, 0x80, 0x07, 0x00, 0xF8, 0x80, 0x08, 0x80, 0xF8, 0x80, 0x09, 0x00, 0xF9,
    0x40, 0x0A, 0xC0, 0xF9, 0x00, 0x0B, 0x80, 0xFA, 0x80, 0x0B, 0x40, 0xFB, 0x00, 0x0C, 0x00, 0xFC,
    0x80, 0x0C, 0xC0, 0xFC, 0x00, 0x0D, 0x80, 0xFD, 0x40, 0x0D, 0x40, 0xFE, 0x80, 0x0D, 0x00, 0xFF,
};

u16 stage5_boss_fire_loop1_form1_mouth_start_table[16] = {
    0x7080, 0x8B8B, 0x0300, 0x0000, 0xFFFA, 0x000B, 0xFFFF, 0x0004,
    0xFFFE, 0x0005, 0xFFF9, 0x0006, 0x0000, 0x0000, 0x06FA, 0x0000,
};

u16 stage5_boss_fire_loop1_form1_arm_guns_fixed_start_table[16] = {
    0x2080, 0x0909, 0x0F0F, 0x0408, 0x0003, 0x0013, 0xFFF7, 0x0005,
    0xFF00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 stage5_boss_fire_loop1_form1_horn_start_table[16] = {
    0x2080, 0x1D1D, 0x0303, 0x0020, 0xFFFF, 0x000B, 0x0030, 0x1D00,
    0xFFFF, 0x0303, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 stage5_boss_fire_loop1_form1_horn_table[32] = {
    0x0DC0, 0xED40, 0x0010, 0x0DC0, 0x12C0, 0xFFF0, 0x0B40, 0xF000,
    0x0008, 0x0B40, 0x1000, 0xFFF8, 0x0940, 0xF300, 0x0000, 0x0940,
    0x0D00, 0x0000, 0x0800, 0xF640, 0xFFF8, 0x0800, 0x09C0, 0x0008,
    0x06C0, 0xF940, 0xFFF0, 0x06C0, 0x06C0, 0x0010, 0x0000, 0x0000,
};

u16 D_00264800[16] = {
    0x2080, 0x4545, 0x0000, 0x0B40, 0xFFFA, 0x0019, 0x0001, 0x0007,
    0x0140, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u32 stage5_boss_fire_loop1_form1_arm_guns_aimed_start_value = 22;

u32 stage5_boss_fire_loop1_form1_mouth_start_value = 30;

u32 stage5_boss_fire_loop1_form1_arm_guns_fixed_start_value = 24;

u32 stage5_boss_fire_loop1_form1_horn_start_value = 20;

u32 D_0028DA14 = 18;
