#include "common.h"
#include "entity.h"
#include "stage5_boss.h"

void stage5_boss_fire_form1_arm_guns_aimed_start(void);
void stage5_boss_fire_form1_arm_guns_aimed(void);
void stage5_boss_fire_form1_mouth_start(void);
void stage5_boss_fire_form1_mouth(s16 *arg1);
void stage5_boss_fire_form1_arm_guns_fixed_start(void);
void stage5_boss_fire_form1_arm_guns_fixed(void);
void stage5_boss_fire_form1_horn_start(void);
void stage5_boss_fire_form1_horn(void);
void stage5_boss_fire_form1_rage_start(void);
void stage5_boss_fire_form1_rage(void);
void stage5_boss_fire_form2_mouth_start(void);
void stage5_boss_fire_form2_mouth(s16 *arg1);
void stage5_boss_fire_form2_jet_start(void);
void stage5_boss_fire_form2_jet(void);
void stage5_boss_fire_form2_horn_start(void);
void stage5_boss_fire_form2_horn(void);
void stage5_boss_fire_form2_stinger_start(void);
void stage5_boss_fire_form2_stinger(void);
void stage5_boss_fire_form3_attack_a_start(void);
void stage5_boss_fire_form3_attack_a(void);
void stage5_boss_fire_form3_attack_b_start(void);
void stage5_boss_fire_form3_attack_b(void);
void stage5_boss_fire_form3_attack_c_start(void);
void stage5_boss_fire_form3_attack_c(u8 *arg0, s16 *arg1);
void stage5_boss_fire_form3_spiral_start(void);
void stage5_boss_fire_form3_spiral(void);
void stage5_boss_fire_form3_rage_start(void);
void stage5_boss_fire_form3_rage(void);

/* The set-up routine and the per-frame routine of every attack, by attack number. */
#ifdef DEATH_LABEL
void twin_boss_first_fire_stinger_start(void);
void twin_boss_first_fire_stinger(void);
void twin_boss_second_fire_stinger_start(void);
void twin_boss_second_fire_stinger(void);
void twin_boss_first_fire_attack_b_start(void);
void twin_boss_first_fire_attack_b(void);
void twin_boss_second_fire_attack_b_start(void);
void twin_boss_second_fire_attack_b(void);
void twin_boss_first_fire_attack_c_start(void);
void twin_boss_first_fire_attack_c(void);
void twin_boss_second_fire_attack_c_start(void);
void twin_boss_second_fire_attack_c(void);
void twin_boss_first_fire_spiral_start(void);
void twin_boss_first_fire_spiral(void);
void twin_boss_second_fire_spiral_start(void);
void twin_boss_second_fire_spiral(void);
void twin_boss_first_fire_rage_start(void);
void twin_boss_first_fire_rage(void);
void twin_boss_second_fire_rage_start(void);
void twin_boss_second_fire_rage(void);
void twin_boss_first_fire_form1_rage_start(void);
void twin_boss_first_fire_form1_rage(void);
void twin_boss_second_fire_form1_rage_start(void);
void twin_boss_second_fire_form1_rage(void);
void twin_boss_first_fire_jet_start(void);
void twin_boss_first_fire_jet(void);
void twin_boss_second_fire_jet_start(void);
void twin_boss_second_fire_jet(void);
#endif

void (*stage5_boss_fire_routines[])(void) = {
    stage5_boss_fire_form1_arm_guns_aimed_start,
    stage5_boss_fire_form1_arm_guns_aimed,
    stage5_boss_fire_form1_mouth_start,
    (void (*)(void))stage5_boss_fire_form1_mouth,
    stage5_boss_fire_form1_arm_guns_fixed_start,
    stage5_boss_fire_form1_arm_guns_fixed,
    stage5_boss_fire_form1_horn_start,
    stage5_boss_fire_form1_horn,
    stage5_boss_fire_form1_rage_start,
    stage5_boss_fire_form1_rage,
    stage5_boss_fire_form2_mouth_start,
    (void (*)(void))stage5_boss_fire_form2_mouth,
    stage5_boss_fire_form2_jet_start,
    stage5_boss_fire_form2_jet,
    stage5_boss_fire_form2_horn_start,
    stage5_boss_fire_form2_horn,
    stage5_boss_fire_form2_stinger_start,
    stage5_boss_fire_form2_stinger,
    stage5_boss_fire_form3_attack_a_start,
    stage5_boss_fire_form3_attack_a,
    stage5_boss_fire_form3_attack_b_start,
    stage5_boss_fire_form3_attack_b,
    stage5_boss_fire_form3_attack_c_start,
    (void (*)(void))stage5_boss_fire_form3_attack_c,
    stage5_boss_fire_form3_spiral_start,
    stage5_boss_fire_form3_spiral,
    stage5_boss_fire_form3_rage_start,
    stage5_boss_fire_form3_rage,
#ifdef DEATH_LABEL
    /* the attacks only Death Label has: one pair for each of the two bosses */
    twin_boss_first_fire_stinger_start,
    twin_boss_first_fire_stinger,
    twin_boss_second_fire_stinger_start,
    twin_boss_second_fire_stinger,
    twin_boss_first_fire_attack_b_start,
    twin_boss_first_fire_attack_b,
    twin_boss_second_fire_attack_b_start,
    twin_boss_second_fire_attack_b,
    twin_boss_first_fire_attack_c_start,
    twin_boss_first_fire_attack_c,
    twin_boss_second_fire_attack_c_start,
    twin_boss_second_fire_attack_c,
    twin_boss_first_fire_spiral_start,
    twin_boss_first_fire_spiral,
    twin_boss_second_fire_spiral_start,
    twin_boss_second_fire_spiral,
    twin_boss_first_fire_rage_start,
    twin_boss_first_fire_rage,
    twin_boss_second_fire_rage_start,
    twin_boss_second_fire_rage,
    twin_boss_first_fire_stinger_start,
    twin_boss_first_fire_stinger,
    twin_boss_second_fire_stinger_start,
    twin_boss_second_fire_stinger,
    twin_boss_first_fire_form1_rage_start,
    twin_boss_first_fire_form1_rage,
    twin_boss_second_fire_form1_rage_start,
    twin_boss_second_fire_form1_rage,
    twin_boss_first_fire_jet_start,
    twin_boss_first_fire_jet,
    twin_boss_second_fire_jet_start,
    twin_boss_second_fire_jet,
#endif
};

s32 bullet_fire256_fixed();
extern u8 D_002641C0[];

void stage5_boss_arm_gun_fire_a(void) {
    u16 temp_a1;
    u16 temp_a1_2;
    u32 temp_a0;

    reg_a2 = (u8 *)D_002641C0;
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
    bullet_fire256_fixed();
}

void stage5_boss_arm_gun_fire_b(void) {
    u16 temp_a0;
    u16 temp_a2;
    u16 temp_a2_2;
    u32 temp_a1;

    reg_a2 = D_002641C0;
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
    temp_a2 = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_tmp.h[1] = temp_a2;
    temp_a1 = reg_d3.w;
    temp_a2_2 = *(u16 *)reg_a3;
    reg_tmp.h[0] = temp_a2_2;
    reg_a3 += 2;
    reg_d4.w = 0;
    reg_d3.w = temp_a1 + reg_tmp.w;
    temp_a0 = ENTITY(reg_a6)->y.h;
    reg_d2.h[1] = temp_a0;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0xC;
    bullet_fire256_fixed();
    reg_d1.h[0] -= 0x18;
    bullet_fire256_fixed();
}

void stage5_boss_arm_gun_fire_c(void) {
    u16 temp_a1;
    u16 temp_a1_2;
    u32 temp_a0;

    reg_a2 = (u8 *)D_002641C0;
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
    bullet_fire256_fixed();
    reg_d1.h[0] += 0x18;
    bullet_fire256_fixed();
    reg_d1.h[0] -= 0x30;
    bullet_fire256_fixed();
}

s32 rng_next();                            /* extern */

void stage5_boss_arm_guns_new_scatter(void) {
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

extern u16 D_00264140[];
extern u32 D_0028D9CC;

void stage5_boss_fire_form1_arm_guns_aimed_start(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(D_00264140);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9CC >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    stage5_boss_arm_guns_new_scatter();
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
extern u16 stage1_midboss_direction64_offsets_166[];
extern u8 D_00264160[];
extern u16 D_00264180[];
extern u16 g_bullets_blocked;

void stage5_boss_fire_form1_arm_guns_aimed(void) {
    u32 t1;
    u32 t2;
    u32 t3;
    u32 t4;
    u32 t5;
    u32 t6;
    u8 t7;
    u8 t8;
    u8 t9;

    if (g_bullets_blocked != 0) {
        stage5_boss_fire_form1_arm_guns_aimed_start();
        return;
    }
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
        reg_a3 = (u8 *)(D_00264160);
        reg_d1.h[0] = ENTITY(reg_a6)[1].move.h;
        reg_d2.b[0] = ARM_GUNS(reg_a4)->scatter_left_top;
        stage5_boss_arm_gun_fire_c();
        reg_d1.h[0] = ENTITY(reg_a6)[2].move.h;
        reg_d2.b[0] = ARM_GUNS(reg_a4)->scatter_left_middle;
        stage5_boss_arm_gun_fire_b();
        reg_d1.h[0] = ENTITY(reg_a6)[3].move.h;
        reg_d2.b[0] = ARM_GUNS(reg_a4)->scatter_left_bottom;
        stage5_boss_arm_gun_fire_a();
        reg_d1.h[0] = ENTITY(reg_a6)[4].move.h;
        reg_d2.b[0] = ARM_GUNS(reg_a4)->scatter_right_top;
        stage5_boss_arm_gun_fire_c();
        reg_d1.h[0] = ENTITY(reg_a6)[5].move.h;
        reg_d2.b[0] = ARM_GUNS(reg_a4)->scatter_right_middle;
        stage5_boss_arm_gun_fire_b();
        reg_d1.h[0] = ENTITY(reg_a6)[6].move.h;
        reg_d2.b[0] = ARM_GUNS(reg_a4)->scatter_right_bottom;
        stage5_boss_arm_gun_fire_a();
        if (ARM_GUNS(reg_a4)->burst.t.count == 0) {
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_a1 = (u8 *)(stage1_midboss_direction64_offsets_166);
            reg_a3 = (u8 *)(D_00264180);
            reg_d6.w = 5;
            do {
                reg_d7.w = 8;
                reg_d0.h[0] = STAGE5_ADJUST(reg_a6)->arm_guns_speed2_add;
                reg_d0.h[0] += *(u16 *)reg_a3;
                reg_a3 += 2;
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = reg_tmp.h[0];
                reg_d0.h[0] = reg_tmp.h[1];
                t2 = *(u16 *)reg_a3;
                reg_a3 += 2;
                reg_d0.h[0] = t2;
                reg_d1.h[0] = *(u16 *)reg_a3;
                reg_a3 += 2;
                reg_d1.h[0] -= 0x20;
                t3 = *(u16 *)reg_a3;
                reg_a3 += 2;
                reg_d5.h[1] = t3;
                reg_d5.h[0] = *(u16 *)reg_a3;
                reg_a3 += 2;
loop_6:
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                reg_d3.w += reg_d5.w;
                if (reg_d7.w & 1) {
                    bullet_fire256_fixed();
                } else {
                    bullet_fire256_fixed();
                }
                reg_d1.h[0] += 8;
                t4 = reg_d7.h[0] - 1;
                reg_d7.h[0] = t4;
                if (((s64) ((s64) (t4 & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                    goto loop_6;
                }
            } while ((s16)(--reg_d6.h[0]) >= 0);
        }
        reg_tmp.b[0] = ARM_GUNS(reg_a4)->burst.t.count;
        ARM_GUNS(reg_a4)->burst.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            ARM_GUNS(reg_a4)->burst.t.count = (u8) ARM_GUNS(reg_a4)->burst.t.reload;
            stage5_boss_arm_guns_new_scatter();
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
            reg_tmp.b[0] = ARM_GUNS(reg_a4)->rounds.t.count;
            ARM_GUNS(reg_a4)->rounds.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                ARM_GUNS(reg_a4)->rounds.t.count = (u8) ARM_GUNS(reg_a4)->rounds.t.reload;
                ARM_GUNS(reg_a4)->shot.t.count = (u8) ARM_GUNS(reg_a4)->shot.t.reload;
                t7 = STAGE5_ADJUST(reg_a6)->arm_guns_rounds_add;
                if ((s32) t7 < 6) {
                    STAGE5_ADJUST(reg_a6)->arm_guns_rounds_add = (u8) (t7 + 2);
                }
                t8 = STAGE5_ADJUST(reg_a6)->arm_guns_shot_interval_sub;
                if ((s32) t8 < 3) {
                    STAGE5_ADJUST(reg_a6)->arm_guns_shot_interval_sub = (u8) (t8 + 1);
                }
                t9 = STAGE5_ADJUST(reg_a6)->arm_guns_round_interval_sub;
                if ((s32) t9 < 0x20) {
                    STAGE5_ADJUST(reg_a6)->arm_guns_round_interval_sub = (u8) (t9 + 8);
                }
                t5 = STAGE5_ADJUST(reg_a6)->arm_guns_speed_add;
                if ((s16)(t5) < 0x10) {
                    STAGE5_ADJUST(reg_a6)->arm_guns_speed_add = (u16) (t5 + 1);
                }
                t6 = STAGE5_ADJUST(reg_a6)->arm_guns_speed2_add;
                if ((s16)(t6) < 4) {
                    STAGE5_ADJUST(reg_a6)->arm_guns_speed2_add = (u16) (t6 + 1);
                }
                reg_d0.w = 0;
                boss_attack_stop();
            }
        }
    }
}

s32 rng_next_unsigned();
s32 rng_next_0_to_3();
extern u16 D_002642C0[];
extern u32 D_0028D9D0;

void stage5_boss_fire_form1_mouth_start(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(D_002642C0);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9D0 >> 1) - 1;
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

s32 bullet_fire256_2way();
s32 enemy_switch_target_player();
s32 rng_next();
s32 direction256_between();
extern s16 g_player2[];
extern s16 g_player1[];

void stage5_boss_fire_form1_mouth(s16 *arg1) {
    s16 *temp_a0;
    s16 *var_a1;
    u32 temp_v1;
    u32 temp_v1_2;
    u8 temp_v0;

    var_a1 = (s16 *)(arg1);
    if (g_bullets_blocked != 0) {
        stage5_boss_fire_form1_mouth_start();
        return;
    }
    reg_tmp.b[0] = MOUTH(reg_a4)->shot.t.count;
    MOUTH(reg_a4)->shot.t.count -= 1;
    if (reg_tmp.b[0] == 0) {
        MOUTH(reg_a4)->shot.t.count = (u8) MOUTH(reg_a4)->shot_interval;
        if (MOUTH(reg_a4)->burst.t.count & 1) {
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
                    goto block_9;
                }
            } else {
block_9:
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
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d3.w = 0xF0C00000;
                reg_d4.w = 0;
                bullet_fire256_fixed();
                enemy_switch_target_player();
                reg_d0.b[0] = MOUTH(reg_a4)->burst.t.count;
                if (MOUTH(reg_a4)->burst.t.reload == reg_d0.b[0]) {
                    reg_d1.b[0] += 0x40;
                    MOUTH(reg_a4)->fixed_direction_left = (u8) reg_d1.b[0];
                    reg_d1.b[0] += 0x80;
                    reg_d1.b[0] *= -1;
                    MOUTH(reg_a4)->fixed_direction_right = (u8) reg_d1.b[0];
                }
                goto block_11;
            }
        } else {
block_11:
            reg_d1.b[0] = MOUTH(reg_a4)->fixed_direction_left;
            reg_d0.h[1] = MOUTH(reg_a4)->fixed[0].speed;
            reg_d0.h[0] = MOUTH(reg_a4)->fixed[0].bullet;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d3.w = 0xF2C0FC00;
            reg_d4.w = 0;
            bullet_fire256_2way();
            reg_d1.b[0] += 0x20;
            reg_d0.h[1] = MOUTH(reg_a4)->fixed[1].speed;
            reg_d0.h[0] = MOUTH(reg_a4)->fixed[1].bullet;
            bullet_fire256_2way();
            reg_d1.b[0] += 0x60;
            reg_d0.h[1] = MOUTH(reg_a4)->fixed[2].speed;
            reg_d0.h[0] = MOUTH(reg_a4)->fixed[2].bullet;
            bullet_fire256_fixed();
            if (MOUTH(reg_a4)->burst.t.count & 1) {
                reg_d1.b[0] += 0x20;
                reg_d0.w = 0x10003;
                bullet_fire256_fixed();
            }
            reg_d1.b[0] = MOUTH(reg_a4)->fixed_direction_right;
            reg_d0.h[1] = MOUTH(reg_a4)->fixed[0].speed;
            reg_d0.h[0] = MOUTH(reg_a4)->fixed[0].bullet;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d3.h[0] = 0x400;
            reg_d4.w = 0;
            bullet_fire256_2way();
            reg_d1.b[0] += 0x20;
            reg_d0.h[1] = MOUTH(reg_a4)->fixed[1].speed;
            reg_d0.h[0] = MOUTH(reg_a4)->fixed[1].bullet;
            bullet_fire256_2way();
            reg_d1.b[0] += 0x60;
            reg_d0.h[1] = MOUTH(reg_a4)->fixed[2].speed;
            reg_d0.h[0] = MOUTH(reg_a4)->fixed[2].bullet;
            bullet_fire256_fixed();
            if (MOUTH(reg_a4)->burst.t.count & 1) {
                reg_d0.w = 0x10003;
                bullet_fire256_fixed();
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
            if ((s16)(temp_v1) < 4) {
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

void stage5_boss_arm_gun_b_fire(void) {
    u16 temp_a2;

    reg_a2 = D_002641C0;
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

extern u16 D_002642E0[];
extern u32 D_0028D9D4;

void stage5_boss_fire_form1_arm_guns_fixed_start(void) {
    (*(u16 **)&reg_a0) = D_002642E0;
    (*(u16 **)&reg_a1) = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9D4 >> 1) - 1;
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
extern u8 D_00264160[];

void stage5_boss_fire_form1_arm_guns_fixed(void) {
    s16 *temp_a0;
    s16 *var_a1;
    u16 temp_a0_2;
    u16 temp_v0;
    u16 temp_v0_2;

    if (g_bullets_blocked != 0) {
        stage5_boss_fire_form1_arm_guns_fixed_start();
        return;
    }
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
        if (ARM_GUNS_B(reg_a4)->burst.t.count & 1) {
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
                    goto block_9;
                }
            } else {
block_9:
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
                    bullet_fire256_fixed();
                    reg_d0.w += 0x40000;
                    bullet_fire256_fixed();
                    reg_d0.w += 0x40000;
                }
                bullet_fire256_fixed();
                enemy_switch_target_player();
                goto block_12;
            }
        } else {
block_12:
            reg_a3 = (u8 *)D_00264160;
            reg_d1.h[0] = ENTITY(reg_a6)[1].move.h;
            stage5_boss_arm_gun_b_fire();
            reg_d1.h[0] = 0x70;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_left_top;
            bullet_fire256_fixed();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0xC0;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_left_top;
            bullet_fire256_fixed();
            reg_d1.h[0] = ENTITY(reg_a6)[2].move.h;
            stage5_boss_arm_gun_b_fire();
            reg_d1.h[0] = 0x7C;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_left_middle;
            bullet_fire256_fixed();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0xB8;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_left_middle;
            bullet_fire256_fixed();
            reg_d1.h[0] = ENTITY(reg_a6)[3].move.h;
            stage5_boss_arm_gun_b_fire();
            reg_d1.h[0] = 0x98;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_left_bottom;
            bullet_fire256_fixed();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0xB0;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_left_bottom;
            bullet_fire256_fixed();
            reg_d1.h[0] = ENTITY(reg_a6)[4].move.h;
            stage5_boss_arm_gun_b_fire();
            reg_d1.h[0] = 0x90;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_right_top;
            bullet_fire256_fixed();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0x40;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_right_top;
            bullet_fire256_fixed();
            reg_d1.h[0] = ENTITY(reg_a6)[5].move.h;
            stage5_boss_arm_gun_b_fire();
            reg_d1.h[0] = 0x84;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_right_middle;
            bullet_fire256_fixed();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0x48;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_right_middle;
            bullet_fire256_fixed();
            reg_d1.h[0] = ENTITY(reg_a6)[6].move.h;
            stage5_boss_arm_gun_b_fire();
            reg_d1.h[0] = 0x68;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_right_bottom;
            bullet_fire256_fixed();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0x50;
            reg_d1.b[0] += ARM_GUNS_B(reg_a4)->direction_right_bottom;
            bullet_fire256_fixed();
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

void bullet_fire256_double(void);

void bullet_fire256_double_entry(void) {
    bullet_fire256_double();
}

extern u16 D_00264300[];
extern u32 D_0028D9D8;

void stage5_boss_fire_form1_horn_start(void) {
    (*(u16 **)&reg_a0) = D_00264300;
    (*(u16 **)&reg_a1) = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9D8 >> 1) - 1;
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
    HORN(reg_a4)->shot.t.count += 2;
}

extern u16 D_00264320[];

void stage5_boss_fire_form1_horn(void) {
    s16 *t1;
    s8 t2;
    s8 t3;
    u16 t4;
    u16 t5;
    u16 t6;
    u32 t7;
    u8 t8;
    u8 t9;
    u8 t10;
    u8 t11;

    if (g_bullets_blocked != 0) {
        stage5_boss_fire_form1_horn_start();
        return;
    }
    reg_tmp.b[0] = HORN(reg_a4)->shot.t.count;
    HORN(reg_a4)->shot.t.count -= 1;
    if (reg_tmp.b[0] == 0) {
        HORN(reg_a4)->shot.t.count = (u8) HORN(reg_a4)->shot_interval;
        reg_d0.b[0] = HORN(reg_a4)->burst.t.count;
        t8 = HORN(reg_a4)->burst.t.reload;
        if (t8 == reg_d0.b[0]) {
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
        if (0 > *(s16 *)reg_a0) {
            goto next_1;
        }
        if (!(0 > *(s16 *)reg_a1)) {
            goto next_2;
        }
        t1 = (s16 *)(reg_a0);
        reg_a0 = (u8 *)(reg_a1);
        reg_atmp = (u8 *)(t1);
        reg_a1 = (u8 *)(t1);
next_1:
#ifdef DEATH_LABEL
            reg_d2.w = *(u16 *)(reg_a0 + 2);
            reg_d3.w = *(u16 *)(reg_a0 + 4);
#else
            reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
            reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
#endif
            reg_d6.h[0] = reg_d2.h[0];
            reg_d7.h[0] = reg_d3.h[0];
#ifdef DEATH_LABEL
            reg_d0.w = ENTITY(reg_a6)->y.h;
            reg_d1.w = ENTITY(reg_a6)->x.h;
#else
            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
#endif
            reg_a3 = (u8 *)(D_00264320);
            reg_d4.h[0] = HORN(reg_a4)->muzzle;
            reg_a3 += reg_d4.h[0];
            reg_d0.h[0] += 0x940;
            reg_d1.h[0] += 0xD00;
            direction256_between();
            t7 = reg_d1.w;
            reg_d2.h[0] = reg_d6.h[0];
            reg_d3.h[0] = reg_d7.h[0];
#ifdef DEATH_LABEL
            reg_d0.w = ENTITY(reg_a6)->y.h;
            reg_d1.w = ENTITY(reg_a6)->x.h;
#else
            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
#endif
            reg_d0.h[0] += 0x940;
            reg_d1.h[0] += 0x7FFF + 0x7301;
            direction256_between();
            reg_d0.h[1] = HORN(reg_a4)->shots.speed;
            reg_d0.h[0] = HORN(reg_a4)->shots.bullet;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            t5 = ENTITY(reg_a6)->x.h;
            reg_d2.h[0] = t5;
            t4 = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d3.h[1] = t4;
            reg_d3.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d4.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            t2 = (s8) reg_d4.b[0];
            reg_d5.b[0] = HORN(reg_a4)->direction_shift;
            reg_d4.b[0] = (u8) (t2 >> reg_d5.b[0]);
            reg_d1.b[0] += reg_d4.b[0];
            reg_d4.w = 0;
            reg_d6.b[0] = HORN(reg_a4)->rounds.t.count;
            bullet_fire256_double_entry();
            reg_d1.w = t7;
            reg_d3.h[1] = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d3.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d4.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            t3 = (s8) reg_d4.b[0];
            reg_d5.b[0] = HORN(reg_a4)->direction_shift;
            reg_d4.b[0] = (u8) (t3 >> reg_d5.b[0]);
            reg_d1.b[0] += reg_d4.b[0];
            reg_d6.b[0] = HORN(reg_a4)->rounds.t.count;
            reg_d6.b[0] = ~(s8) reg_d6.b[0];
            bullet_fire256_double_entry();
            reg_tmp.h[0] = HORN(reg_a4)->muzzle;
            HORN(reg_a4)->muzzle -= 0xC;
            if ((s32) reg_tmp.h[0] < 0xC) {
                HORN(reg_a4)->muzzle = 0x30U;
            }
next_2:
        HORN(reg_a4)->shots.speed += 1;
        reg_tmp.b[0] = HORN(reg_a4)->burst.t.count;
        HORN(reg_a4)->burst.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            enemy_switch_target_player();
            t11 = HORN(reg_a4)->burst.t.reload;
            if ((s32) t11 < 0x1E) {
                HORN(reg_a4)->burst.t.reload = (u8) (t11 + 0xF);
            }
            HORN(reg_a4)->burst.t.count = (u8) HORN(reg_a4)->burst.t.reload;
            HORN(reg_a4)->shot.t.count = (u8) HORN(reg_a4)->round_interval;
            HORN(reg_a4)->shot.t.count += 4;
            HORN(reg_a4)->speed_reset += 1;
            HORN(reg_a4)->shots.speed = (u16) HORN(reg_a4)->speed_reset;
            reg_tmp.b[0] = HORN(reg_a4)->rounds.t.count;
            HORN(reg_a4)->rounds.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                HORN(reg_a4)->rounds.t.count = (u8) HORN(reg_a4)->rounds.t.reload;
                HORN(reg_a4)->shot.t.count = (u8) HORN(reg_a4)->shot.t.reload;
                t9 = STAGE5_ADJUST(reg_a6)->horn_rounds_add;
                if ((s32) t9 < 2) {
                    STAGE5_ADJUST(reg_a6)->horn_rounds_add = (u8) (t9 + 1);
                }
                t6 = STAGE5_EXTRA(reg_a6)->horn_speed_add;
                if ((s32) t6 < 6) {
                    STAGE5_EXTRA(reg_a6)->horn_speed_add = (u16) (t6 + 1);
                }
                t10 = STAGE5_ADJUST(reg_a6)->horn_round_interval_sub;
                if ((s32) t10 < 0x18) {
                    STAGE5_ADJUST(reg_a6)->horn_round_interval_sub = (u8) (t10 + 2);
                }
                reg_d0.w = 3;
                boss_attack_stop();
            }
        }
    }
}

void stage5_boss_form1_rage_fire(void) {
    s32 bullet_fire256_direct();
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
    reg_d7.w = 3;
    reg_d4.w = 0;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
        reg_d3.w += reg_d5.w;
        bullet_fire256_direct();
        var_a1 = (u16) reg_d1.b[0];
        var_a0 = var_a1 + reg_d6.b[0];
        reg_d1.b[0] = var_a0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

extern u16 D_00264360[];
extern u32 D_0028D9DC;

void stage5_boss_fire_form1_rage_start(void) {
    (*(u16 **)&reg_a0) = D_00264360;
    (*(u16 **)&reg_a1) = (u16 *)((*(s32 *)&reg_a4) + 2);
    reg_d0.w = ((u32) D_0028D9DC >> 1) - 1;
    do {
        *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
        (*(u16 **)&reg_a0) += 1;
        (*(u16 **)&reg_a1) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}


void stage5_boss_fire_form1_rage(void) {
    u32 temp_a0;
    u8 temp_v1;
    u8 temp_v1_2;

    if (g_bullets_blocked != 0) {
        stage5_boss_fire_form1_rage_start();
        return;
    }
    reg_tmp.b[0] = FORM1_RAGE(reg_a4)->shot.t.count;
    FORM1_RAGE(reg_a4)->shot.t.count -= 1;
    if (reg_tmp.b[0] == 0) {
        reg_d0.b[0] = FORM1_RAGE(reg_a4)->shot_interval;
        reg_tmp.h[1] = STAGE5_BOSS(reg_a5)->hp[0];
        reg_tmp.h[0] = STAGE5_BOSS(reg_a5)->hp[1];
        if ((u32) reg_tmp.w < 0x15000U) {
            reg_d0.b[0] -= 4;
        }
        FORM1_RAGE(reg_a4)->shot.t.count = (u8) reg_d0.b[0];
        reg_a1 = (u8 *)stage1_midboss_direction64_offsets_166;
        reg_d1.b[0] = FORM1_RAGE(reg_a4)->direction;
        stage5_boss_form1_rage_fire();
        reg_d1.b[0] = FORM1_RAGE(reg_a4)->direction;
        reg_d1.b[0] += 0x80;
        stage5_boss_form1_rage_fire();
        reg_d0.b[0] = FORM1_RAGE(reg_a4)->turn;
        reg_tmp.h[1] = STAGE5_BOSS(reg_a5)->hp[0];
        reg_tmp.h[0] = STAGE5_BOSS(reg_a5)->hp[1];
        if ((u32) reg_tmp.w < 0x15000U) {
            reg_d0.b[0] = (s8) reg_d0.b[0] * 4;
        }
        FORM1_RAGE(reg_a4)->direction += reg_d0.b[0];
        reg_tmp.b[0] = FORM1_RAGE(reg_a4)->burst.t.count;
        FORM1_RAGE(reg_a4)->burst.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            FORM1_RAGE(reg_a4)->burst.t.count = (u8) FORM1_RAGE(reg_a4)->burst.t.reload;
            FORM1_RAGE(reg_a4)->shot.t.count = (u8) FORM1_RAGE(reg_a4)->round_interval;
            FORM1_RAGE(reg_a4)->turn *= -1;
            temp_a0 = FORM1_RAGE(reg_a4)->shots.speed;
            if ((s16)(temp_a0) < 8) {
                FORM1_RAGE(reg_a4)->shots.speed = (u16) (temp_a0 + 2);
            }
            reg_tmp.b[0] = FORM1_RAGE(reg_a4)->rounds.t.count;
            FORM1_RAGE(reg_a4)->rounds.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                FORM1_RAGE(reg_a4)->rounds.t.count = (u8) FORM1_RAGE(reg_a4)->rounds.t.reload;
                temp_v1 = FORM1_RAGE(reg_a4)->shot_interval;
                if ((s32) temp_v1 > 5) {
                    FORM1_RAGE(reg_a4)->shot_interval = (u8) (temp_v1 - 2);
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

s32 rng_next_masked();
extern u16 D_00264380[];
extern u32 D_0028D9E0;

void stage5_boss_fire_form2_mouth_start(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(D_00264380);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9E0 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    rng_next_masked();
    reg_d0.b[0] += 0x60;
    FORM2_MOUTH(reg_a4)->fixed_direction = (u8) reg_d0.b[0];
    rng_next_unsigned();
    if (0 > reg_d0.sb[0]) {
        FORM2_MOUTH(reg_a4)->fixed_turn *= -1;
    }
    reg_d0.b[0] = STAGE5_ADJUST(reg_a6)->form2_mouth_burst_add;
    FORM2_MOUTH(reg_a4)->burst.t.count += reg_d0.b[0];
    FORM2_MOUTH(reg_a4)->burst.t.reload += reg_d0.b[0];
    reg_d0.h[0] = STAGE5_ADJUST(reg_a6)->form2_mouth_speed_add;
    FORM2_MOUTH(reg_a4)->aimed.speed += reg_d0.h[0];
    reg_d0.h[0] = STAGE5_ADJUST(reg_a6)->form2_mouth_speed2_add;
    FORM2_MOUTH(reg_a4)->fixed.speed += reg_d0.h[0];
}


void stage5_boss_fire_form2_mouth(s16 *arg1) {
    s32 bullet_fire256_direct();
    s16 *t1;
    s16 *t2;
    u32 t3;
    u32 t4;
    u16 t5;
    u8 t6;

    t2 = (s16 *)(arg1);
    if (g_bullets_blocked != 0) {
        stage5_boss_fire_form2_mouth_start();
        return;
    }
    reg_tmp.b[0] = FORM2_MOUTH(reg_a4)->shot.t.count;
    FORM2_MOUTH(reg_a4)->shot.t.count -= 1;
    if (reg_tmp.b[0] == 0) {
        FORM2_MOUTH(reg_a4)->shot.t.count = (u8) FORM2_MOUTH(reg_a4)->shot_interval;
        if (FORM2_MOUTH(reg_a4)->burst.t.count & 1) {
            reg_a0 = (u8 *)(g_player1);
            reg_a1 = (u8 *)(g_player2);
            if (ENEMY_STATE(reg_a5)->target_player != 0) {
                reg_atmp = (u8 *)(reg_a0);
                reg_a0 = (u8 *)(reg_a1);
                reg_a1 = (u8 *)(reg_atmp);
            }
            t1 = (s16 *)(reg_a0);
            if (0 <= (s64)*(s16 *)t1) {
                t2 = (s16 *)(reg_a1);
                if (0 > *t2) {
                    reg_a0 = (u8 *)(t2);
                    reg_atmp = (u8 *)(t1);
                    reg_a1 = (u8 *)(t1);
                    goto next_1;
                }
            } else {
next_1:
                reg_d2.w = (u32) *(u16 *)(reg_a0 + 2);
                reg_d3.w = (u32) *(u16 *)(reg_a0 + 4);
                reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
                reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
                reg_d0.h[0] += 0x7FFF + 0x70C1;
                direction256_between();
                reg_d0.h[1] = FORM2_MOUTH(reg_a4)->aimed.speed;
                reg_d0.h[0] = FORM2_MOUTH(reg_a4)->aimed.bullet;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d5.w = 0xF0C00000;
                reg_d7.w = 6;
                reg_d1.h[0] -= 0x36;
                reg_a1 = (u8 *)(stage1_midboss_direction64_offsets_166);
                reg_d4.w = 0;
                do {
                    reg_d3.h[0] = reg_d1.h[0];
                    reg_d3.h[0] += 2;
                    reg_d3.h[0] &= 0xFC;
                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : (u16) *(s16 *)reg_a1;
                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                    reg_d3.w += reg_d5.w;
                    bullet_fire256_direct();
                    reg_d1.h[0] += 0x12;
                } while ((s16)(--reg_d7.h[0]) >= 0);
                enemy_switch_target_player();
                goto next_2;
            }
        } else {
next_2:
            t5 = 0xC;
            reg_d1.b[0] = FORM2_MOUTH(reg_a4)->fixed_direction;
            reg_d0.h[1] = FORM2_MOUTH(reg_a4)->fixed.speed;
            reg_d0.h[0] = FORM2_MOUTH(reg_a4)->fixed.bullet;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d5.w = 0xF0C00000;
            reg_d7.w = 0xC;
            reg_d1.h[0] -= 0x3C;
            reg_a1 = (u8 *)(stage1_midboss_direction64_offsets_166);
            reg_d4.w = 0;
            do {
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : (u16) *(s16 *)reg_a1;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                reg_d3.w += reg_d5.w;
                bullet_fire256_direct();
                t5 = (u32)reg_d1.h[0] + 0xA;
                reg_d1.h[0] = t5;
            } while ((s16)(--reg_d7.h[0]) >= 0);
            reg_d1.b[0] = FORM2_MOUTH(reg_a4)->fixed_turn;
            if (!(0 > (s8) reg_d1.b[0])) {
                goto next_31;
            }
            FORM2_MOUTH(reg_a4)->fixed_direction += reg_d1.b[0];
            if ((s32) FORM2_MOUTH(reg_a4)->fixed_direction < 0x50) {
                goto next_32;
            }
            goto next_33;
next_31:
            FORM2_MOUTH(reg_a4)->fixed_direction += reg_d1.b[0];
            if ((s32) FORM2_MOUTH(reg_a4)->fixed_direction <= 0xB0) {
                goto next_33;
            }
next_32:
            FORM2_MOUTH(reg_a4)->fixed_turn *= -1;
next_33:;
        }
        reg_tmp.b[0] = FORM2_MOUTH(reg_a4)->burst.t.count;
        FORM2_MOUTH(reg_a4)->burst.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            FORM2_MOUTH(reg_a4)->shot.t.count = (u8) FORM2_MOUTH(reg_a4)->shot.t.reload;
            t6 = STAGE5_ADJUST(reg_a6)->form2_mouth_burst_add;
            if ((s32) t6 < 0x28) {
                STAGE5_ADJUST(reg_a6)->form2_mouth_burst_add = (u8) (t6 + 0xA);
            }
            t3 = STAGE5_ADJUST(reg_a6)->form2_mouth_speed_add;
            if ((s16)(t3) < 4) {
                STAGE5_ADJUST(reg_a6)->form2_mouth_speed_add = (u16) (t3 + 1);
            }
            t4 = STAGE5_ADJUST(reg_a6)->form2_mouth_speed2_add;
            if ((s16)(t4) < 0x1A) {
                STAGE5_ADJUST(reg_a6)->form2_mouth_speed2_add = (u16) (t4 + 1);
            }
            reg_d0.w = 5;
            boss_attack_stop();
        }
    }
}

void stage5_boss_jet_fire(void) {
    s32 bullet_fire256_direct();
    u32 temp_a0;

    reg_d7.h[0] = reg_d1.h[0];
    reg_d0.h[0] = JET(reg_a4)->side_bullet;
    reg_d1.b[0] -= 1;
    bullet_fire256_direct();
    reg_d1.b[0] += 2;
    bullet_fire256_direct();
    reg_d1.h[0] = reg_d7.h[0];
    reg_d0.h[0] = JET(reg_a4)->middle_bullet;
    reg_d0.w += 0x40000;
    bullet_fire256_direct();
    reg_d1.b[0] -= 2;
    bullet_fire256_direct();
    reg_d1.b[0] += 4;
    bullet_fire256_direct();
    reg_d1.h[0] = reg_d7.h[0];
    reg_d0.h[0] = JET(reg_a4)->side_bullet;
    temp_a0 = reg_d0.w;
    reg_d0.w = temp_a0 + 0x40000;
    reg_d1.b[0] -= 1;
    bullet_fire256_direct();
    reg_d1.b[0] += 2;
    bullet_fire256_direct();
    reg_d1.h[0] = reg_d7.h[0];
    reg_d0.h[0] = JET(reg_a4)->middle_bullet;
    reg_d0.w += 0x40000;
    bullet_fire256_direct();
    reg_d1.b[0] -= 2;
    bullet_fire256_direct();
    reg_d1.b[0] += 4;
    bullet_fire256_direct();
}

extern u16 D_00264390[];
extern u32 D_0028D9E4;

void stage5_boss_fire_form2_jet_start(void) {
    (*(u16 **)&reg_a0) = D_00264390;
    (*(u16 **)&reg_a1) = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9E4 >> 1) - 1;
    do {
        *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
        (*(u16 **)&reg_a0) += 1;
        (*(u16 **)&reg_a1) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = STAGE5_ADJUST_B(reg_a6)->jet_speed_add;
    JET(reg_a4)->speed += reg_d0.h[0];
    reg_d0.b[0] = STAGE5_ADJUST_B(reg_a6)->jet_burst_add;
    JET(reg_a4)->burst.t.count += reg_d0.b[0];
    JET(reg_a4)->burst.t.reload += reg_d0.b[0];
}

extern u8 D_002643A0[];

void stage5_boss_fire_form2_jet(void) {
    s16 *temp_v1;
    u16 temp_v0_2;
    u8 temp_v0;

    if (g_bullets_blocked != 0) {
        stage5_boss_fire_form2_jet_start();
        return;
    }
    reg_tmp.b[0] = JET(reg_a4)->shot.t.count;
    JET(reg_a4)->shot.t.count -= 1;
    if (reg_tmp.b[0] == 0) {
        JET(reg_a4)->shot.t.count = (u8) JET(reg_a4)->shot_interval;
        reg_a0 = (u8 *)(g_player1);
        reg_a1 = (u8 *)(g_player2);
        if (ENEMY_STATE(reg_a5)->target_player != 0) {
            reg_atmp = (u8 *)(reg_a0);
            reg_a0 = (u8 *)(reg_a1);
            reg_a1 = (u8 *)(reg_atmp);
        }
        temp_v1 = (s16 *)(reg_a0);
        if (0 <= (s64)*(s16 *)((u8 *)(temp_v1) + (0))) {
            if (0 > (s64)*(s16 *)reg_a1) {
                reg_a0 = (u8 *)(reg_a1);
                reg_atmp = (u8 *)(temp_v1);
                reg_a1 = (u8 *)(temp_v1);
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
            direction256_between();
            rng_next_masked();
            reg_d0.b[0] -= 0x20;
            reg_d1.b[0] += reg_d0.b[0];
            reg_d0.h[0] = JET(reg_a4)->speed;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_a3 = (u8 *)D_002643A0;
            reg_d4.h[0] = JET(reg_a4)->muzzle;
            reg_a3 += reg_d4.h[0];
            reg_d3.h[1] = *(u16 *)reg_a3;
            reg_d3.h[0] = *(u16 *)(reg_a3 + 2);
            reg_d4.w = 0;
            stage5_boss_jet_fire();
            reg_tmp.h[0] = JET(reg_a4)->muzzle;
            JET(reg_a4)->muzzle -= 4;
            if ((s32) reg_tmp.h[0] < 4) {
                JET(reg_a4)->muzzle = 0x14U;
            }
        }
        enemy_switch_target_player();
        reg_tmp.b[0] = JET(reg_a4)->burst.t.count;
        JET(reg_a4)->burst.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            JET(reg_a4)->burst.t.count = (u8) JET(reg_a4)->burst.t.reload;
            JET(reg_a4)->shot.t.count = (u8) JET(reg_a4)->shot.t.reload;
            temp_v0 = STAGE5_ADJUST_B(reg_a6)->jet_burst_add;
            if ((s32) temp_v0 < 0x14) {
                STAGE5_ADJUST_B(reg_a6)->jet_burst_add = (u8) (temp_v0 + 0xA);
            }
            temp_v0_2 = STAGE5_ADJUST_B(reg_a6)->jet_speed_add;
            if ((s32) temp_v0_2 < 6) {
                STAGE5_ADJUST_B(reg_a6)->jet_speed_add = (u16) (temp_v0_2 + 1);
            }
            reg_d0.w = 6;
            boss_attack_stop();
        }
    }
}

void stage5_boss_form2_horn_fire(void) {
    s32 bullet_fire256_direct();
    reg_d3.h[1] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d3.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] += *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d5.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d4.w = 0;
    reg_d1.h[0] += reg_d5.h[0];
    bullet_fire256_direct();
    reg_d4.h[0] = reg_d5.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d4.h[0] = (s16) reg_d4.h[0] >> 1;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d5.h[0] += reg_d4.h[0];
    reg_d4.h[0] = (s16) reg_d4.h[0] >> 2;
    reg_d5.h[0] += reg_d4.h[0];
    reg_d1.h[0] -= reg_d5.h[0];
    reg_d0.h[0] += FORM2_HORN(reg_a4)->small.speed;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] = FORM2_HORN(reg_a4)->small.bullet;
    reg_d4.w = 0;
    bullet_fire256_direct();
}

extern u16 D_002643C0[];
extern u32 D_0028D9E8;

void stage5_boss_fire_form2_horn_start(void) {
    (*(u16 **)&reg_a0) = D_002643C0;
    (*(u16 **)&reg_a1) = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9E8 >> 1) - 1;
    do {
        *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
        (*(u16 **)&reg_a0) += 1;
        (*(u16 **)&reg_a1) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = STAGE5_ADJUST_B(reg_a6)->form2_horn_speed_add;
    FORM2_HORN(reg_a4)->large.speed += reg_d0.h[0];
    reg_d0.b[0] = STAGE5_ADJUST_B(reg_a6)->form2_horn_round_interval_sub;
    FORM2_HORN(reg_a4)->round_interval -= reg_d0.b[0];
}

extern u8 stage5_boss_horn_shot_offsets[];

void stage5_boss_fire_form2_horn(void) {
    s16 *temp_a0;
    u16 temp_a0_2;
    u16 temp_v0_2;
    u8 temp_v0;
    u8 temp_v1;
    u8 *var_a1;

    if (g_bullets_blocked != 0) {
        stage5_boss_fire_form2_horn_start();
        return;
    }
    reg_tmp.b[0] = FORM2_HORN(reg_a4)->shot.t.count;
    FORM2_HORN(reg_a4)->shot.t.count -= 1;
    if (reg_tmp.b[0] == 0) {
        var_a1 = (unsigned char *)(FORM2_HORN(reg_a4)->shot_interval);
        FORM2_HORN(reg_a4)->shot.t.count = (unsigned char)var_a1;
        reg_a0 = (u8 *)(g_player1);
        reg_a1 = (u8 *)(g_player2);
        if (ENEMY_STATE(reg_a5)->target_player != 0) {
            reg_atmp = (u8 *)(reg_a0);
            reg_a0 = (u8 *)(reg_a1);
            reg_a1 = (u8 *)(reg_atmp);
        }
        temp_a0 = (s16 *)(reg_a0);
        if (0 <= (s64)*(s16 *)((u8 *)(temp_a0) + (0))) {
            var_a1 = (unsigned char *)reg_a1;
            if (0 > (s64)*(s16 *)var_a1) {
                reg_a0 = (u8 *) var_a1;
                reg_atmp = (u8 *)(temp_a0);
                reg_a1 = (u8 *)(temp_a0);
                goto block_8;
            }
        } else {
block_8:
            reg_d2.w = (u32) *(u16 *)(reg_a0 + 2);
            reg_d3.w = (u32) *(u16 *)(reg_a0 + 4);
            reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
            reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
            direction256_between();
            reg_d0.h[1] = FORM2_HORN(reg_a4)->large.speed;
            reg_d0.h[0] = FORM2_HORN(reg_a4)->large.bullet;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            temp_a0_2 = ENTITY(reg_a6)->x.h;
            reg_d2.h[0] = temp_a0_2;
            reg_d7.h[0] = reg_d1.h[0];
            reg_a3 = (u8 *)stage5_boss_horn_shot_offsets;
            reg_d4.w = 0;
            reg_d4.b[0] = FORM2_HORN(reg_a4)->rounds.t.count;
            reg_d4.h[0] += reg_d4.h[0];
            reg_d4.h[0] += reg_d4.h[0];
            reg_a3 += reg_d4.h[0];
            reg_tmp.h[1] = *(u16 *)reg_a3;
            reg_tmp.h[0] = *(u16 *)(reg_a3 + 2);
            reg_a3 = (u8 *) reg_tmp.w;
            reg_d4.h[0] = FORM2_HORN(reg_a4)->muzzle;
            reg_a3 += reg_d4.h[0];
            stage5_boss_form2_horn_fire();
            reg_d1.h[0] = reg_d7.h[0];
            reg_d0.h[1] = FORM2_HORN(reg_a4)->large.speed;
            reg_d0.h[0] = FORM2_HORN(reg_a4)->large.bullet;
            stage5_boss_form2_horn_fire();
            reg_tmp.h[0] = FORM2_HORN(reg_a4)->muzzle;
            FORM2_HORN(reg_a4)->muzzle -= 0x10;
            if ((s32) reg_tmp.h[0] < 0x10) {
                FORM2_HORN(reg_a4)->muzzle = 0x40U;
            }
        }
        reg_tmp.b[0] = FORM2_HORN(reg_a4)->burst.t.count;
        FORM2_HORN(reg_a4)->burst.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            enemy_switch_target_player();
            temp_v1 = FORM2_HORN(reg_a4)->burst.t.reload;
            if ((s32) temp_v1 < 0x3B) {
                FORM2_HORN(reg_a4)->burst.t.reload = (u8) (temp_v1 + 0xF);
            }
            FORM2_HORN(reg_a4)->burst.t.count = (u8) FORM2_HORN(reg_a4)->burst.t.reload;
            FORM2_HORN(reg_a4)->large.speed += 2;
            FORM2_HORN(reg_a4)->small.speed += 1;
            FORM2_HORN(reg_a4)->shot.t.count = (u8) FORM2_HORN(reg_a4)->round_interval;
            reg_tmp.b[0] = FORM2_HORN(reg_a4)->rounds.t.count;
            FORM2_HORN(reg_a4)->rounds.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                temp_v0 = STAGE5_ADJUST_B(reg_a6)->form2_horn_round_interval_sub;
                if ((s32) temp_v0 < 0x10) {
                    STAGE5_ADJUST_B(reg_a6)->form2_horn_round_interval_sub = (u8) (temp_v0 + 8);
                }
                temp_v0_2 = STAGE5_ADJUST_B(reg_a6)->form2_horn_speed_add;
                if ((s32) temp_v0_2 < 0xB) {
                    STAGE5_ADJUST_B(reg_a6)->form2_horn_speed_add = (u16) (temp_v0_2 + 2);
                }
                reg_d0.w = 7;
                boss_attack_stop();
            }
        }
    }
}

extern u16 D_00264530[];
extern u32 D_0028D9EC;

void stage5_boss_fire_form2_stinger_start(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(D_00264530);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9EC >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    rng_next_masked();
    reg_d0.b[0] -= 0x20;
    STINGER(reg_a4)->fixed_direction = (u8) reg_d0.b[0];
    rng_next_unsigned();
    if (0 > reg_d0.sb[0]) {
        STINGER(reg_a4)->fixed_turn *= -1;
    }
    reg_d0.b[0] = STAGE5_ADJUST_B(reg_a6)->stinger_burst_add;
    STINGER(reg_a4)->burst.t.count += reg_d0.b[0];
    STINGER(reg_a4)->burst.t.reload += reg_d0.b[0];
}


void stage5_boss_fire_form2_stinger(void) {
    s32 bullet_fire256_direct();
    s16 *t1;
    s16 *t2;
    u16 t3;
    u16 t4;
    u8 t5;
    u8 t6;

    if (g_bullets_blocked != 0) {
        stage5_boss_fire_form2_stinger_start();
        return;
    }
    reg_tmp.b[0] = STINGER(reg_a4)->shot.t.count;
    STINGER(reg_a4)->shot.t.count -= 1;
    if (reg_tmp.b[0] == 0) {
        STINGER(reg_a4)->shot.t.count = (u8) STINGER(reg_a4)->shot_interval;
        reg_a0 = (u8 *)(g_player1);
        reg_a1 = (u8 *)(g_player2);
        if (ENEMY_STATE(reg_a5)->target_player != 0) {
            reg_atmp = (u8 *)(reg_a0);
            reg_a0 = (u8 *)(reg_a1);
            reg_a1 = (u8 *)(reg_atmp);
        }
        t1 = (s16 *)(reg_a0);
        if (0 <= (s64)*(s16 *)((u8 *)(t1) + (0))) {
            t2 = (s16 *)(reg_a1);
            if (0 > *t2) {
                reg_a0 = (u8 *)(t2);
                reg_atmp = (u8 *)(t1);
                reg_a1 = (u8 *)(t1);
                goto next_1;
            }
        } else {
next_1:
            reg_d2.w = (u32) *(u16 *)(reg_a0 + 2);
            reg_d3.w = (u32) *(u16 *)(reg_a0 + 4);
            reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
            t3 = ENTITY(reg_a6)->x.h;
            reg_d0.h[0] += 0x7FFF + 0x5801;
            reg_d1.w = (u32) t3;
            if ((s32) reg_d0.h[0] <= (s32) reg_d2.h[0]) {
                direction256_between();
                reg_d0.w = 0x80013;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d3.w = 0xD8000000;
                reg_d4.w = 0;
                rng_next_d5();
                reg_d5.b[0] = (u8) ((s8) reg_d5.b[0] >> 1);
                reg_d1.b[0] += reg_d5.b[0];
                bullet_fire256_direct();
                reg_d1.b[0] -= 2;
                reg_d0.w += 0x40000;
                bullet_fire256_direct();
                reg_d1.b[0] += 4;
                reg_d0.w += 0x40000;
                bullet_fire256_direct();
            }
            t6 = 6;
            reg_d1.b[0] = STINGER(reg_a4)->fixed_direction;
            reg_d0.h[1] = STINGER(reg_a4)->fixed.speed;
            reg_d0.h[0] = STINGER(reg_a4)->fixed.bullet;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d6.w = 0xD8000000;
            reg_d7.w = 6;
            reg_d1.h[0] -= 0x2D;
            reg_a1 = (u8 *)(stage1_midboss_direction64_offsets_166);
            do {
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : (u16) *(s16 *)reg_a1;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                reg_d4.w = 0x02020020;
                reg_d3.w += reg_d6.w;
                reg_d5.h[0] = 0x42;
                bullet_fire256_direct();
                t4 = reg_d0.h[0];
                reg_d4.w = 0x2C03FFE0;
                reg_d0.h[0] += 1;
                reg_d1.b[0] += 0x80;
                reg_d5.h[0] = 0x2E;
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = reg_tmp.h[0];
                reg_d0.h[0] = reg_tmp.h[1];
                reg_d0.h[0] -= 2;
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = reg_tmp.h[0];
                reg_d0.h[0] = reg_tmp.h[1];
                bullet_fire256_direct();
                reg_d1.b[0] += 0x80;
                reg_d0.h[0] -= 1;
                reg_d1.h[0] += 0xF;
            } while ((s16)(--reg_d7.h[0]) >= 0);
            reg_d1.b[0] = STINGER(reg_a4)->fixed_turn;
            if (0 > (s8) reg_d1.b[0]) {
                goto next_21;
            }
            STINGER(reg_a4)->fixed_direction += reg_d1.b[0];
            if ((s8) STINGER(reg_a4)->fixed_direction > 0x30) {
                goto next_22;
            }
            goto next_23;
next_21:
            STINGER(reg_a4)->fixed_direction += reg_d1.b[0];
            if ((s8) STINGER(reg_a4)->fixed_direction >= -0x30) {
                goto next_23;
            }
next_22:
            STINGER(reg_a4)->fixed_turn *= -1;
next_23:;
        }
        enemy_switch_target_player();
        reg_tmp.b[0] = STINGER(reg_a4)->burst.t.count;
        STINGER(reg_a4)->burst.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            stage5_boss_fire_form2_stinger_start();
            STINGER(reg_a4)->shot.t.count = (u8) STINGER(reg_a4)->shot.t.reload;
            t5 = STAGE5_ADJUST_B(reg_a6)->stinger_burst_add;
            if ((s32) t5 < 0x28) {
                STAGE5_ADJUST_B(reg_a6)->stinger_burst_add = (u8) (t5 + 0x14);
            }
            reg_d0.w = 8;
            boss_attack_stop();
        }
    }
}

void stage5_boss_form3_a_fire_ring(void) {
    extern void bullet_fire256_direct(void);
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d3.w = 0xFA000000;
    reg_d6.h[0] = 5;
    reg_d7.h[0] = 0xF;
    reg_d4.w = 0;
    do {
        bullet_fire256_direct();
        reg_d1.b[0] += reg_d6.b[0];
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

extern u16 D_00264540[];
extern u32 D_0028D9F0;

void stage5_boss_fire_form3_attack_a_start(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(D_00264540);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9F0 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    FORM3_A(reg_a4)->direction = 0x20;
    rng_next_unsigned();
    if (0 > reg_d0.sb[0]) {
        FORM3_A(reg_a4)->turn *= -1;
    }
    reg_d0.h[0] = STAGE5_ADJUST_B(reg_a6)->form3_a_speed_add;
    FORM3_A(reg_a4)->speed += reg_d0.h[0];
    reg_d0.b[0] = STAGE5_ADJUST_B(reg_a6)->form3_a_burst_add;
    FORM3_A(reg_a4)->burst.t.count += reg_d0.b[0];
    FORM3_A(reg_a4)->burst.t.reload += reg_d0.b[0];
}


void stage5_boss_fire_form3_attack_a(void) {
    s16 *temp_v1;
    s16 *var_a0;
    u16 temp_v0_2;
    u8 temp_v0;

    reg_tmp.b[0] = FORM3_A(reg_a4)->shot.t.count;
    FORM3_A(reg_a4)->shot.t.count -= 1;
    if (reg_tmp.b[0] == 0) {
        FORM3_A(reg_a4)->shot.t.count = (u8) FORM3_A(reg_a4)->shot_interval;
        reg_a0 = (u8 *)(g_player1);
        reg_a1 = (u8 *)(g_player2);
        if (ENEMY_STATE(reg_a5)->target_player != 0) {
            reg_atmp = (u8 *)(reg_a0);
            reg_a0 = (u8 *)(reg_a1);
            reg_a1 = (u8 *)(reg_atmp);
        }
        temp_v1 = (s16 *)(reg_a0);
        if (0 <= (s64)*(s16 *)((u8 *)(temp_v1) + (0))) {
            var_a0 = (s16 *)(reg_a1);
            if (0 > *var_a0) {
                reg_a0 = (u8 *)(var_a0);
                reg_atmp = (u8 *)(temp_v1);
                reg_a1 = (u8 *)(temp_v1);
                goto block_6;
            }
        } else {
block_6:
            reg_d2.w = (u32) *(u16 *)(reg_a0 + 2);
            reg_d3.w = (u32) *(u16 *)(reg_a0 + 4);
            reg_d6.h[0] = reg_d2.h[0];
            reg_d7.h[0] = reg_d3.h[0];
            reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
            reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
            direction256_between();
            reg_d5.h[0] = reg_d1.h[0];
            if (FORM3_A(reg_a4)->burst.t.count & 1) {
                reg_d1.b[0] += FORM3_A(reg_a4)->direction;
                reg_d1.h[0] -= 0x23;
                reg_d0.h[0] = FORM3_A(reg_a4)->speed;
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = reg_tmp.h[0];
                reg_d0.h[0] = reg_tmp.h[1];
                reg_d0.h[0] = FORM3_A(reg_a4)->middle_bullet;
                stage5_boss_form3_a_fire_ring();
            } else {
                reg_d1.h[0] = reg_d5.h[0];
                reg_d1.b[0] -= FORM3_A(reg_a4)->direction;
                reg_d1.h[0] -= 0x23;
                reg_d0.h[0] = FORM3_A(reg_a4)->speed;
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = reg_tmp.h[0];
                reg_d0.h[0] = reg_tmp.h[1];
                reg_d0.h[0] = FORM3_A(reg_a4)->side_bullet;
                stage5_boss_form3_a_fire_ring();
            }
            var_a0 = (s16 *)(reg_a4);
            reg_d1.b[0] = (*(u8 *)((u8 *)(var_a0) + (0xE)));
            if (0 <= (s8)(reg_d1.b[0])) {
                (*(u8 *)((u8 *)(var_a0) + (0xF))) += reg_d1.b[0];
                if ((s8) FORM3_A(reg_a4)->direction > 0x10) {
                    goto block_13;
                }
                goto block_end;
            } else {
                (*(u8 *)((u8 *)(var_a0) + (0xF))) += reg_d1.b[0];
                if ((s8) FORM3_A(reg_a4)->direction < -0x10) {
block_13:
                    var_a0 = (s16 *)(reg_a4);
                    (*(u8 *)((u8 *)(var_a0) + (0xE))) *= -1;
                }
            }
        }
block_end:
        enemy_switch_target_player();
        reg_tmp.b[0] = FORM3_A(reg_a4)->burst.t.count;
        FORM3_A(reg_a4)->burst.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            temp_v0 = STAGE5_ADJUST_B(reg_a6)->form3_a_burst_add;
            if ((s32) temp_v0 < 0x1E) {
                STAGE5_ADJUST_B(reg_a6)->form3_a_burst_add = (u8) (temp_v0 + 0x14);
            }
            temp_v0_2 = STAGE5_ADJUST_B(reg_a6)->form3_a_speed_add;
            if ((s32) temp_v0_2 < 2) {
                STAGE5_ADJUST_B(reg_a6)->form3_a_speed_add = (u16) (temp_v0_2 + 1);
            }
            reg_d0.w = 9;
            boss_attack_stop();
        }
    }
}

void stage5_boss_form3_b_fire(void) {
    s32 bullet_fire256_direct();
    u32 var_a1;
    u8 var_a0;

    var_a0 = 0xFA000000;
    reg_d0.h[1] = FORM3_B(reg_a4)->shots.speed;
    reg_d0.h[0] = FORM3_B(reg_a4)->shots.bullet;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d4.h[1] = FORM3_B(reg_a4)->child.speed;
    var_a1 = FORM3_B(reg_a4)->child.bullet;
    reg_d4.h[0] = var_a1;
    reg_d5.w = 0xFA000000;
    reg_d6.b[0] = 0x15;
    reg_d7.w = 0xB;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
        reg_d3.w += reg_d5.w;
        bullet_fire256_direct();
        var_a1 = (u16) reg_d1.b[0];
        var_a0 = var_a1 + reg_d6.b[0];
        reg_d1.b[0] = var_a0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

extern u16 D_00264550[];
extern u32 D_0028D9F4;

void stage5_boss_fire_form3_attack_b_start(void) {
    (*(u16 **)&reg_a0) = D_00264550;
    (*(u16 **)&reg_a1) = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9F4 >> 1) - 1;
    do {
        *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
        (*(u16 **)&reg_a0) += 1;
        (*(u16 **)&reg_a1) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.b[0] = STAGE5_ADJUST_B(reg_a6)->form3_b_burst_add;
    FORM3_B(reg_a4)->burst.t.count += reg_d0.b[0];
    FORM3_B(reg_a4)->burst.t.reload += reg_d0.b[0];
    reg_d0.h[0] = STAGE5_ADJUST_B(reg_a6)->form3_b_speed_add;
    FORM3_B(reg_a4)->shots.speed += reg_d0.h[0];
    reg_d0.h[0] = STAGE5_ADJUST_B(reg_a6)->form3_b_speed2_add;
    FORM3_B(reg_a4)->child.speed += reg_d0.h[0];
    rng_next_unsigned();
    FORM3_B(reg_a4)->direction = (u8) reg_d0.b[0];
    if (STAGE5_ADJUST_B(reg_a6)->form3_b_turn == 0) {
        FORM3_B(reg_a4)->turn *= -1;
    }
}

s32 nearest_player_distance();
extern u16 g_enemy_signal_2;

void stage5_boss_fire_form3_attack_b() {
    u16 temp_v0_2;
    u16 temp_v0_3;
    u8 temp_v0;

    g_enemy_signal_2 = 0;
    nearest_player_distance();
    if ((s32) reg_d0.h[0] < 0x2000) {
        g_enemy_signal_2 = 1;
    }
    reg_tmp.b[0] = FORM3_B(reg_a4)->shot.t.count;
    FORM3_B(reg_a4)->shot.t.count -= 1;
    if (reg_tmp.b[0] == 0) {
        FORM3_B(reg_a4)->shot.t.count = (u8) FORM3_B(reg_a4)->shot_interval;
        reg_a1 = (u8 *) stage1_midboss_direction64_offsets_166;
        reg_d1.b[0] = FORM3_B(reg_a4)->direction;
        stage5_boss_form3_b_fire();
        reg_d0.b[0] = FORM3_B(reg_a4)->turn;
        FORM3_B(reg_a4)->direction += reg_d0.b[0];
        reg_tmp.b[0] = FORM3_B(reg_a4)->burst.t.count;
        FORM3_B(reg_a4)->burst.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            FORM3_B(reg_a4)->burst.t.count = (u8) FORM3_B(reg_a4)->burst.t.reload;
            STAGE5_ADJUST_B(reg_a6)->form3_b_turn = (s8) ~((s8) STAGE5_ADJUST_B(reg_a6)->form3_b_turn);
            temp_v0 = STAGE5_ADJUST_B(reg_a6)->form3_b_burst_add;
            if ((s32) temp_v0 < MAIN_OR_DEATH_LABEL(0x95, 0x81)) {
                STAGE5_ADJUST_B(reg_a6)->form3_b_burst_add = (u8) (temp_v0 + 0xA);
            }
            temp_v0_2 = STAGE5_ADJUST_B(reg_a6)->form3_b_speed_add;
            if ((s32) temp_v0_2 < 2) {
                STAGE5_ADJUST_B(reg_a6)->form3_b_speed_add = (u16) (temp_v0_2 + 1);
            }
            temp_v0_3 = STAGE5_ADJUST_B(reg_a6)->form3_b_speed2_add;
            if ((s32) temp_v0_3 < 3) {
                STAGE5_ADJUST_B(reg_a6)->form3_b_speed2_add = (u16) (temp_v0_3 + 1);
            }
            reg_d0.w = 0xA;
            boss_attack_stop();
        }
    }
}

void stage5_boss_form3_c_fire(void) {
    s32 bullet_fire256_direct();
    reg_d0.h[1] = FORM3_C(reg_a4)->shots.speed;
    reg_d0.h[0] = FORM3_C(reg_a4)->shots.bullet;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d3.w = 0xFA000000;
    reg_d4.w = 0;
    bullet_fire256_direct();
    reg_d0.h[0] += 1;
    reg_d0.w += 0x30000;
    reg_d1.b[0] -= reg_d6.b[0];
    bullet_fire256_direct();
    reg_d0.h[0] += 1;
    reg_d0.w += 0x30000;
    reg_d1.b[0] -= reg_d6.b[0];
    bullet_fire256_direct();
    reg_d0.h[0] += 1;
    reg_d0.w += 0x30000;
    reg_d1.b[0] -= reg_d6.b[0];
    bullet_fire256_direct();
    reg_d0.h[0] -= 1;
    reg_d0.w += 0x30000;
    reg_d1.b[0] -= reg_d6.b[0];
    bullet_fire256_direct();
    reg_d0.h[0] -= 1;
    reg_d0.w += 0x30000;
    reg_d1.b[0] -= reg_d6.b[0];
    bullet_fire256_direct();
    reg_d0.h[0] -= 1;
    reg_d0.w += 0x30000;
    reg_d1.b[0] -= reg_d6.b[0];
    bullet_fire256_direct();
    reg_d0.h[0] += 1;
    reg_d0.w += 0x30000;
    reg_d1.b[0] -= reg_d6.b[0];
    bullet_fire256_direct();
    reg_d0.h[0] += 1;
    reg_d0.w += 0x30000;
    reg_d1.b[0] -= reg_d6.b[0];
    bullet_fire256_direct();
}

extern u16 D_00264560[];
extern u32 D_0028D9F8;

void stage5_boss_fire_form3_attack_c_start(void) {
    (*(u16 **)&reg_a0) = D_00264560;
    (*(u16 **)&reg_a1) = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9F8 >> 1) - 1;
    do {
        *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
        (*(u16 **)&reg_a0) += 1;
        (*(u16 **)&reg_a1) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    FORM3_C(reg_a4)->other_0C.sh = 0x404;
}


void stage5_boss_fire_form3_attack_c(u8 *arg0, s16 *arg1) {
    s16 *temp_a0;
    s16 *var_a1;
    u8 temp_a1;
    u8 temp_a2;
    u8 *var_a0;

    var_a0 = (u8 *)(arg0);
    var_a1 = (s16 *)(arg1);
    if (g_bullets_blocked == 0) {
        reg_tmp.b[0] = FORM3_C(reg_a4)->shot.t.count;
        FORM3_C(reg_a4)->shot.t.count -= 1;
        if (reg_tmp.b[0] == 0) {
            FORM3_C(reg_a4)->shot.t.count = (u8) FORM3_C(reg_a4)->shot_interval;
            reg_d2.b[0] = FORM3_C(reg_a4)->burst.t.count;
            if (FORM3_C(reg_a4)->burst.t.reload == reg_d2.b[0]) {
                reg_a0 = (u8 *)(((u16 *)g_player1));
                reg_a1 = (u8 *)(((u16 *)g_player2));
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
                        goto block_8;
                    }
                } else {
block_8:
                    reg_d2.w = (u32) *(u16 *)(reg_a0 + 2);
                    reg_d3.w = (u32) *(u16 *)(reg_a0 + 4);
                    reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
                    reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
                    reg_d0.h[0] += 0x7FFF + 0x7A01;
                    direction256_between();
                    reg_d1.h[0] = 0x80;
                    FORM3_C(reg_a4)->track_direction = (u8) reg_d1.b[0];
                    goto block_9;
                }
            } else {
block_9:
                reg_d1.b[0] = FORM3_C(reg_a4)->track_direction;
                reg_d6.b[0] = 0xB7;
                reg_d7.h[0] = reg_d1.h[0];
                temp_a1 = FORM3_C(reg_a4)->burst.t.count;
                reg_d6.b[0] -= temp_a1;
                reg_d1.b[0] += reg_d6.b[0];
                reg_d6.h[0] = 0x16;
                stage5_boss_form3_c_fire();
                reg_d6.b[0] = 0xB7;
                reg_d1.h[0] = reg_d7.h[0];
                temp_a2 = FORM3_C(reg_a4)->burst.t.count;
                reg_d6.b[0] -= temp_a2;
                reg_d6.b[0] *= -1;
                reg_d1.b[0] += reg_d6.b[0];
                reg_d6.h[0] = 0xFFEA;
                stage5_boss_form3_c_fire();
            }
            FORM3_C(reg_a4)->other_0C.b[1] -= 1;
            var_a1 = (s16 *)(reg_a4 + 0xD);
            if (FORM3_C(reg_a4)->other_0C.b[1] == 0) {
                FORM3_C(reg_a4)->other_0C.b[1] = (u8) FORM3_C(reg_a4)->other_0C.b[0];
                FORM3_C(reg_a4)->shot.t.count = 4U;
            }
            var_a0 = (u8 *)(reg_a4);
            reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a0) + (5)));
            (*(u8 *)((u8 *)(var_a0) + (5))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                goto block_13;
            }
        }
    } else {
block_13:
        enemy_switch_target_player();
        reg_d0.w = 0xB;
        boss_attack_stop();
    }
}

s32 rng_next_0_to_2();
extern u16 D_00264570[];
extern u32 D_0028D9FC;

void stage5_boss_fire_form3_spiral_start(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(D_00264570);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9FC >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    rng_next_masked();
    reg_d0.b[0] += 0x60;
    FORM3_D(reg_a4)->direction = (u8) reg_d0.b[0];
    rng_next_unsigned();
    if (0 > reg_d0.sb[0]) {
        FORM3_D(reg_a4)->turn *= -1;
    }
    rng_next_0_to_2();
    reg_d0.w = (u32) (s16) reg_d0.h[0];
    FORM3_D(reg_a4)->spin_step_add = (u16) reg_d0.h[0];
    reg_d0.h[0] += 2;
    FORM3_D(reg_a4)->spin_step = (u16) reg_d0.h[0];
    reg_d0.b[0] = STAGE5_ADJUST_B(reg_a6)->form3_d_rounds_add;
    FORM3_D(reg_a4)->rounds.t.count += reg_d0.b[0];
    FORM3_D(reg_a4)->rounds.t.reload += reg_d0.b[0];
}

s32 velocity_from_dir256();
extern u16 g_enemy_signal_1;
extern u16 g_enemy_signal_0;

void stage5_boss_fire_form3_spiral(void) {
    s32 bullet_fire256_direct();
    s16 *t1;
    u8 t2;
    u8 t3;

    reg_d0.w = 0xC;
    boss_attack_stop();
    if (g_bullets_blocked != 0) {
        stage5_boss_fire_form3_spiral_start();
        return;
    }
    reg_tmp.b[0] = FORM3_D(reg_a4)->shot.t.count;
    FORM3_D(reg_a4)->shot.t.count -= 1;
    if (reg_tmp.b[0] == 0) {
        FORM3_D(reg_a4)->shot.t.count = (u8) FORM3_D(reg_a4)->shot_interval;
        reg_d0.b[0] = FORM3_D(reg_a4)->burst.t.count;
        if (FORM3_D(reg_a4)->burst.t.reload == reg_d0.b[0]) {
            reg_a0 = (u8 *)(g_player1);
            reg_a1 = (u8 *)(g_player2);
            if (ENEMY_STATE(reg_a5)->target_player != 0) {
                reg_atmp = (u8 *)(reg_a0);
                reg_a0 = (u8 *)(reg_a1);
                reg_a1 = (u8 *)(reg_atmp);
            }
            t1 = (s16 *)(reg_a0);
            if (0 <= (s64)*(s16 *)((u8 *)(t1) + (0))) {
                if (0 > *(s16 *)reg_a1) {
                    reg_a0 = (u8 *)(reg_a1);
                    reg_atmp = (u8 *)(t1);
                    reg_a1 = (u8 *)(t1);
                    goto next_1;
                }
            } else {
next_1:
                reg_d2.w = (u32) *(u16 *)(reg_a0 + 2);
                reg_d3.w = (u32) *(u16 *)(reg_a0 + 4);
                reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
                reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
                reg_d0.h[0] += 0x7FFF + 0x7A01;
                direction256_between();
                FORM3_D(reg_a4)->track_direction = (u8) reg_d1.b[0];
                goto next_2;
            }
        } else {
next_2:
            reg_d1.w = 0;
            reg_d1.b[0] = FORM3_D(reg_a4)->track_direction;
            reg_d0.h[0] = FORM3_D(reg_a4)->vector_speed;
            velocity_from_dir256();
            g_enemy_signal_0 = reg_d2.h[0];
            g_enemy_signal_1 = reg_d3.h[0];
            enemy_switch_target_player();
            t3 = 0xFA000000;
            reg_d0.h[1] = FORM3_D(reg_a4)->shots.speed;
            reg_d0.h[0] = FORM3_D(reg_a4)->shots.bullet;
            reg_d1.b[0] = FORM3_D(reg_a4)->direction;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d4.h[0] = FORM3_D(reg_a4)->spin_timer.h;
            reg_tmp.w = reg_d4.w;
            reg_d4.h[1] = reg_tmp.h[0];
            reg_d4.h[0] = reg_tmp.h[1];
            reg_d4.h[0] = FORM3_D(reg_a4)->spin_step;
            reg_d5.h[0] = FORM3_D(reg_a4)->accel_timer.h;
            reg_tmp.w = reg_d5.w;
            reg_d5.h[1] = reg_tmp.h[0];
            reg_d5.h[0] = reg_tmp.h[1];
            reg_d5.h[0] = FORM3_D(reg_a4)->accel_step;
            reg_d6.w = 0xFA000000;
            reg_d7.w = 7;
            reg_a1 = (u8 *)(stage1_midboss_direction64_offsets_166);
            do {
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : (u16) *(s16 *)reg_a1;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                reg_d3.w += reg_d6.w;
                bullet_fire256_direct();
                reg_d1.b[0] += 0x20;
            } while ((s16)(--reg_d7.h[0]) >= 0);
            reg_d1.b[0] = FORM3_D(reg_a4)->turn;
            FORM3_D(reg_a4)->direction += reg_d1.b[0];
            FORM3_D(reg_a4)->vector_speed += 1;
        }
        reg_tmp.b[0] = FORM3_D(reg_a4)->burst.t.count;
        FORM3_D(reg_a4)->burst.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            FORM3_D(reg_a4)->burst.t.reload += 1;
            FORM3_D(reg_a4)->burst.t.count = (u8) FORM3_D(reg_a4)->burst.t.reload;
            FORM3_D(reg_a4)->turn *= -1;
            FORM3_D(reg_a4)->vector_speed = 0x12U;
            FORM3_D(reg_a4)->shot.t.count = (u8) FORM3_D(reg_a4)->round_interval;
            FORM3_D(reg_a4)->round_interval -= 4;
            reg_d0.h[0] = FORM3_D(reg_a4)->spin_step_add;
            reg_d0.h[0] += 1;
            if ((s32) reg_d0.h[0] > 2) {
                reg_d0.h[0] = 0;
            }
            FORM3_D(reg_a4)->spin_step_add = (u16) reg_d0.h[0];
            reg_d0.h[0] += 2;
            FORM3_D(reg_a4)->spin_step = (u16) reg_d0.h[0];
            reg_tmp.b[0] = FORM3_D(reg_a4)->rounds.t.count;
            FORM3_D(reg_a4)->rounds.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                t2 = STAGE5_ADJUST_B(reg_a6)->form3_d_rounds_add;
                if ((s32) t2 < 4) {
                    STAGE5_ADJUST_B(reg_a6)->form3_d_rounds_add = (u8) (t2 + 2);
                }
                reg_d0.w = 0xC;
                boss_attack_stop();
            }
        }
    }
}

extern u16 g_direction64_offsets_166[];

void stage5_boss_form3_rage_first_volley(void) {
    s32 bullet_fire256_direct();
    u16 var_a0;
    reg_tmp.b[0] = FORM3_RAGE(reg_a4)->shot[0].t.count;
    FORM3_RAGE(reg_a4)->shot[0].t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        var_a0 = 0xFE000000;
        FORM3_RAGE(reg_a4)->shot[0].t.count = (u8) FORM3_RAGE(reg_a4)->shot[0].t.reload;
        reg_d0.h[1] = FORM3_RAGE(reg_a4)->volley[0].speed;
        reg_d0.h[0] = FORM3_RAGE(reg_a4)->volley[0].bullet;
        reg_d1.b[0] = FORM3_RAGE(reg_a4)->aim[0].direction;
        reg_d4.w = 0;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d6.w = 0xFE000000;
        reg_d7.w = 3;
        reg_a1 = (u8 *)(g_direction64_offsets_166);
        do {
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] += 2;
            reg_d3.h[0] &= 0xFC;
            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
            reg_d3.w += reg_d6.w;
            bullet_fire256_direct();
            var_a0 = (u32)reg_d1.h[0] + 0x40;
            reg_d1.h[0] = var_a0;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        reg_d1.b[0] = FORM3_RAGE(reg_a4)->aim[0].turn;
        FORM3_RAGE(reg_a4)->aim[0].direction += reg_d1.b[0];
    }
}

extern u16 g_direction64_offsets_432[];

void stage5_boss_form3_rage_third_volley(void) {
    s32 bullet_fire256_direct();
    u16 var_a0;
    reg_tmp.b[0] = FORM3_RAGE(reg_a4)->shot[2].t.count;
    FORM3_RAGE(reg_a4)->shot[2].t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        var_a0 = 0xFE000000;
        FORM3_RAGE(reg_a4)->shot[2].t.count = (u8) FORM3_RAGE(reg_a4)->shot[2].t.reload;
        reg_d0.h[1] = FORM3_RAGE(reg_a4)->volley[2].speed;
        reg_d0.h[0] = FORM3_RAGE(reg_a4)->volley[2].bullet;
        reg_d1.b[0] = FORM3_RAGE(reg_a4)->aim[2].direction;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d6.w = 0xFE000000;
        reg_d7.w = 3;
        reg_a1 = (u8 *)(g_direction64_offsets_432);
        reg_d4.w = 0;
        do {
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] += 2;
            reg_d3.h[0] &= 0xFC;
            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
            reg_d3.w += reg_d6.w;
            bullet_fire256_direct();
            var_a0 = (u32)reg_d1.h[0] + 0x40;
            reg_d1.h[0] = var_a0;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        reg_d1.b[0] = FORM3_RAGE(reg_a4)->aim[2].turn;
        FORM3_RAGE(reg_a4)->aim[2].direction += reg_d1.b[0];
    }
}

extern u16 D_00264590[];
extern u32 D_0028DA00;

void stage5_boss_fire_form3_rage_start(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(D_00264590);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028DA00 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    rng_next_unsigned();
    FORM3_RAGE(reg_a4)->aim[0].direction = (u8) reg_d0.b[0];
    rng_next_unsigned();
    FORM3_RAGE(reg_a4)->aim[1].direction = (u8) reg_d0.b[0];
    rng_next_unsigned();
    FORM3_RAGE(reg_a4)->aim[2].direction = (u8) reg_d0.b[0];
    STAGE5_ADJUST_B(reg_a6)->rage_rounds = 5;
    STAGE5_ADJUST_B(reg_a6)->rage_turn_interval = 8;
}

extern u16 g_direction64_offsets_2CC[];

void stage5_boss_fire_form3_rage(void) {
    s32 bullet_fire256_direct();
    u8 *p;
    u8 t;

    stage5_boss_form3_rage_first_volley();
    p = reg_a4 + 0x1C;
    switch (*(u16 *)p) { case 0: goto next_0; }
    *(u16 *)p -= 1;
    reg_tmp.h[1] = STAGE5_BOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE5_BOSS(reg_a5)->hp[1];
    if ((u32)reg_tmp.w >= 0x1F800U) goto next_2;
next_0:
    stage5_boss_form3_rage_third_volley();
    p = reg_a4 + 0x1E;
    if (*(u16 *)p == 0) goto next_1;
    *(u16 *)p -= 1;
    reg_tmp.h[1] = STAGE5_BOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE5_BOSS(reg_a5)->hp[1];
    if ((u32)reg_tmp.w >= 0x1C000U) goto next_9;
next_1:
    reg_tmp.b[0] = FORM3_RAGE(reg_a4)->shot[1].t.count;
    FORM3_RAGE(reg_a4)->shot[1].t.count -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_2;
    FORM3_RAGE(reg_a4)->shot[1].t.count = FORM3_RAGE(reg_a4)->shot[1].t.reload;
    reg_d0.h[1] = FORM3_RAGE(reg_a4)->volley[1].speed;
    reg_d0.h[0] = FORM3_RAGE(reg_a4)->volley[1].bullet;
    reg_d1.b[0] = FORM3_RAGE(reg_a4)->aim[1].direction;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    g_enemy_signal_0 = 0;
    g_enemy_signal_1 = 0;
    reg_d4.h[0] = 0x101;
    reg_tmp.w = reg_d4.w;
    reg_d4.h[1] = reg_tmp.h[0];
    reg_d4.h[0] = reg_tmp.h[1];
    reg_d4.h[0] = STAGE5_ADJUST_B(reg_a6)->rage_rounds;
    reg_d5.w = 0x01010001;
    reg_d6.w = 0xFE000000;
    reg_d7.w = 9;
    reg_a1 = (u8 *)g_direction64_offsets_2CC;
loop_0:
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d3.w += reg_d6.w;
    bullet_fire256_direct();
    reg_d1.h[0] += 0x19;
    if ((s16)(reg_d7.h[0] -= 1) >= 0) goto loop_0;
    reg_d1.b[0] = FORM3_RAGE(reg_a4)->aim[1].turn;
    FORM3_RAGE(reg_a4)->aim[1].direction += reg_d1.b[0];
next_2:
    reg_tmp.b[0] = STAGE5_ADJUST_B(reg_a6)->rage_turn_interval;
    STAGE5_ADJUST_B(reg_a6)->rage_turn_interval -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_9;
    STAGE5_ADJUST_B(reg_a6)->rage_turn_interval = 8;
    if (STAGE5_ADJUST_B(reg_a6)->rage_turn_flag & 1) goto next_4;
    if ((s8)FORM3_RAGE(reg_a4)->aim[1].turn == -6) goto next_3;
    FORM3_RAGE(reg_a4)->aim[1].turn -= 1;
    goto next_7;
next_3:
    if (STAGE5_ADJUST_B(reg_a6)->rage_rounds == 5) goto next_8;
    STAGE5_ADJUST_B(reg_a6)->rage_rounds += 1;
    goto next_7;
next_4:
    if (FORM3_RAGE(reg_a4)->aim[1].turn == 6) goto next_5;
    FORM3_RAGE(reg_a4)->aim[1].turn += 1;
    goto next_7;
next_5:
    if ((s16)STAGE5_ADJUST_B(reg_a6)->rage_rounds == -5) goto next_8;
    STAGE5_ADJUST_B(reg_a6)->rage_rounds -= 1;
next_7:
    return;
next_8:
    reg_tmp.b[0] = FORM3_RAGE(reg_a4)->burst.t.count;
    FORM3_RAGE(reg_a4)->burst.t.count -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_9;
    FORM3_RAGE(reg_a4)->burst.t.count = FORM3_RAGE(reg_a4)->burst.t.reload;
    t = STAGE5_ADJUST_B(reg_a6)->rage_turn_flag;
    if (t & 1) {
        STAGE5_ADJUST_B(reg_a6)->rage_turn_flag = t & 0xFE;
        goto next_9;
    }
    STAGE5_ADJUST_B(reg_a6)->rage_turn_flag = t | 1;
next_9:
    return;
}

extern u8 text_start[];

u16 D_00264140[16] = {
    0x2080, 0x0303, 0x0404, 0x0540, 0xFFF9, 0x0007, 0xFFF9, 0x0404,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u8 D_00264160[32] = {
    0xC0, 0x14, 0x80, 0xF1, 0x00, 0xFB, 0x40, 0xEE, 0x80, 0xE8, 0xC0, 0xEE, 0x40, 0x07, 0x40, 0x10,
    0x80, 0xF7, 0xC0, 0x14, 0x40, 0xE5, 0x40, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u16 D_00264180[32] = {
    0x0002, 0x0004, 0x0078, 0x0DC0, 0xED40, 0xFFFB, 0x0004, 0x007C,
    0x0940, 0xF300, 0xFFF4, 0x0004, 0x0080, 0x06C0, 0xF940, 0x0002,
    0x0004, 0x0088, 0x0DC0, 0x12C0, 0xFFFB, 0x0004, 0x0084, 0x0940,
    0x0D00, 0xFFF4, 0x0004, 0x0080, 0x06C0, 0x06C0, 0x0000, 0x0000,
};

u8 D_002641C0[256] = {
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

u16 D_002642C0[16] = {
    0x2080, 0x8B8B, 0x0300, 0x0000, 0xFFF9, 0x0013, 0x0002, 0x0004,
    0xFFFD, 0x0005, 0xFFF5, 0x0006, 0x0000, 0x0000, 0x05FB, 0x0000,
};

u16 D_002642E0[16] = {
    0x2080, 0x0B0B, 0x1111, 0x0208, 0x0003, 0x0013, 0xFFF8, 0x0016,
    0xFF00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_00264300[16] = {
    0x2080, 0x1D1D, 0x0303, 0x001A, 0xFFFE, 0x000B, 0x0030, 0x1D00,
    0xFFFE, 0x0303, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_00264320[32] = {
    0x0DC0, 0xED40, 0x0010, 0x0DC0, 0x12C0, 0xFFF0, 0x0B40, 0xF000,
    0x0008, 0x0B40, 0x1000, 0xFFF8, 0x0940, 0xF300, 0x0000, 0x0940,
    0x0D00, 0x0000, 0x0800, 0xF640, 0xFFF8, 0x0800, 0x09C0, 0x0008,
    0x06C0, 0xF940, 0xFFF0, 0x06C0, 0x06C0, 0x0010, 0x0000, 0x0000,
};

u16 D_00264360[16] = {
    0x2080, 0x6363, 0x0101, 0x0B40, 0xFFF8, 0x0019, 0x0000, 0x0007,
    0x0140, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_00264380[8] = {
    0x2080, 0x2727, 0x0600, 0x0000, 0x000B, 0x0006, 0x0004, 0x0006,
};

u16 D_00264390[8] = {
    0x2080, 0x3B3B, 0x0320, 0x0000, 0x0013, 0x0013, 0x0014, 0x0000,
};

u8 D_002643A0[32] = {
    0x80, 0x00, 0x40, 0xF6, 0x40, 0xFB, 0x40, 0xF6, 0x40, 0xF6, 0x40, 0xF6, 0x00, 0xFF, 0x40, 0x09,
    0x80, 0xFA, 0x40, 0x09, 0xC0, 0xF5, 0x40, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u16 D_002643C0[16] = {
    0x6080, 0x1D1D, 0x0202, 0x0130, 0x0005, 0x0003, 0x0002, 0x0004,
    0x0040, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u8 stage5_boss_horn_shot_offsets[16] = {
    0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0x00, 0x06, 0x00, 0x07, 0x00,
};

u16 D_002643F0[40] = {
    0x0DC0, 0xED40, 0x0000, 0x000A, 0x0DC0, 0x12C0, 0x0000, 0xFFF6,
    0x0B40, 0xF000, 0x0000, 0x0005, 0x0B40, 0x1000, 0x0000, 0xFFFB,
    0x0940, 0xF300, 0x0000, 0x0000, 0x0940, 0x0D00, 0x0000, 0x0000,
    0x0800, 0xF640, 0x0000, 0xFFFB, 0x0800, 0x09C0, 0x0000, 0x0005,
    0x06C0, 0xF940, 0x0000, 0xFFF6, 0x06C0, 0x06C0, 0x0000, 0x000A,
};

u16 D_00264440[40] = {
    0x0DC0, 0xED40, 0x0000, 0x000C, 0x0DC0, 0x12C0, 0x0000, 0xFFF4,
    0x0B40, 0xF000, 0x0000, 0x0006, 0x0B40, 0x1000, 0x0000, 0xFFFA,
    0x0940, 0xF300, 0x0000, 0x0000, 0x0940, 0x0D00, 0x0000, 0x0000,
    0x0800, 0xF640, 0x0000, 0xFFFA, 0x0800, 0x09C0, 0x0000, 0x0006,
    0x06C0, 0xF940, 0x0000, 0xFFF4, 0x06C0, 0x06C0, 0x0000, 0x000C,
};

u16 D_00264490[40] = {
    0x0DC0, 0xED40, 0x0000, 0x000E, 0x0DC0, 0x12C0, 0x0000, 0xFFF2,
    0x0B40, 0xF000, 0x0000, 0x0007, 0x0B40, 0x1000, 0x0000, 0xFFF9,
    0x0940, 0xF300, 0x0000, 0x0000, 0x0940, 0x0D00, 0x0000, 0x0000,
    0x0800, 0xF640, 0x0000, 0xFFF9, 0x0800, 0x09C0, 0x0000, 0x0007,
    0x06C0, 0xF940, 0x0000, 0xFFF2, 0x06C0, 0x06C0, 0x0000, 0x000E,
};

struct D002644e0Record { u16 w0[2]; void *p1; u16 w2[34]; void *p3; };
struct D002644e0Record D_002644E0 = {
    { 0x0DC0, 0xED40 },
    text_start,
    { 0x0DC0, 0x12C0, 0x0000, 0xFFF0, 0x0B40, 0xF000, 0x0000, 0x0008, 0x0B40, 0x1000, 0x0000, 0xFFF8, 0x0940, 0xF300, 0x0000, 0x0000, 0x0940, 0x0D00, 0x0000, 0x0000, 0x0800, 0xF640, 0x0000, 0xFFF8, 0x0800, 0x09C0, 0x0000, 0x0008, 0x06C0, 0xF940, 0x0000, 0xFFF0, 0x06C0, 0x06C0 },
    text_start,
};

u16 D_00264530[8] = {
    0x6080, 0x4F4F, 0x0500, 0x0000, 0x000C, 0x000A, 0x0017, 0x0003,
};

u16 D_00264540[8] = {
    0x1080, 0x4545, 0x0300, 0x0009, 0x0007, 0x0007, 0x0001, 0x0000,
};

u16 D_00264550[8] = {
    0x1080, 0x7777, 0x0500, 0x0006, 0x001C, 0x0003, 0x0016, 0x0200,
};

u16 D_00264560[8] = {
    0x1080, 0xB3B3, 0x0100, 0x0013, 0x0003, 0x0000, 0x0000, 0x0000,
};

u16 D_00264570[16] = {
    0x20E0, 0x3B3B, 0x3B3B, 0x0750, 0xFFF9, 0x0022, 0x0001, 0x0101,
    0x0002, 0x0B0B, 0x0001, 0x0012, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_00264590[16] = {
    0x0104, 0x2003, 0x4004, 0x3030, 0x000A, 0x000B, 0xFFFA, 0x001B,
    0x0005, 0x000B, 0x00FE, 0x00FA, 0x0003, 0x0100, 0x0100, 0x0000,
};

u32 D_0028D9CC = 0x16;

u32 D_0028D9D0 = 0x1E;

u32 D_0028D9D4 = 0x18;

u32 D_0028D9D8 = 0x14;

u32 D_0028D9DC = 0x12;

u32 D_0028D9E0 = 0x10;

u32 D_0028D9E4 = 0xE;

u32 D_0028D9E8 = 0x12;

u32 D_0028D9EC = 0x10;

u32 D_0028D9F0 = 0xE;

u32 D_0028D9F4 = 0x10;

u32 D_0028D9F8 = 0xA;

u32 D_0028D9FC = 0x1C;

u32 D_0028DA00 = 0x1E;
