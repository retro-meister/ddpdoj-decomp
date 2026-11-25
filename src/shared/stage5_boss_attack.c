#include "common.h"
#include "entity.h"

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
};

s32 bullet_fire256_fixed();
extern u8 D_002641C0[];

void func_001E9150(void) {
    u16 temp_a1;
    u16 temp_a1_2;
    u32 temp_a0;

    reg_a2 = (u8 *)D_002641C0;
    reg_d0.h[1] = *(u16 *)(reg_a4 + 0xA);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
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

void func_001E9220(void) {
    u16 temp_a0;
    u16 temp_a2;
    u16 temp_a2_2;
    u32 temp_a1;

    reg_a2 = D_002641C0;
    reg_d0.h[1] = *(u16 *)(reg_a4 + 0xA);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
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

void func_001E9320(void) {
    u16 temp_a1;
    u16 temp_a1_2;
    u32 temp_a0;

    reg_a2 = (u8 *)D_002641C0;
    reg_d0.h[1] = *(u16 *)(reg_a4 + 0xA);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
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

void func_001E9420(void) {
    rng_next();
    *(u8 *)(reg_a4 + 0x1B) = (u8) reg_d0.b[0];
    rng_next();
    *(u8 *)(reg_a4 + 0x1A) = (u8) reg_d0.b[0];
    rng_next();
    *(u8 *)(reg_a4 + 0x1D) = (u8) reg_d0.b[0];
    rng_next();
    *(u8 *)(reg_a4 + 0x1C) = (u8) reg_d0.b[0];
    rng_next();
    *(u8 *)(reg_a4 + 0x1F) = (u8) reg_d0.b[0];
    rng_next();
    *(u8 *)(reg_a4 + 0x1E) = (u8) reg_d0.b[0];
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
    func_001E9420();
    reg_d0.b[0] = ENTITY(reg_a6)[14].offset_y.b[1];
    *(u8 *)(reg_a4 + 7) += reg_d0.b[0];
    *(u8 *)(reg_a4 + 6) += reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[14].offset_x.b[1];
    *(u8 *)(reg_a4 + 9) -= reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[14].offset_x.b[0];
    *(u8 *)(reg_a4 + 8) -= reg_d0.b[0];
    reg_d0.h[0] = ENTITY(reg_a6)[14].draw.h;
    *(u16 *)(reg_a4 + 0xA) += reg_d0.h[0];
    *(u16 *)(reg_a4 + 0xE) += reg_d0.h[0];
}

s32 boss_attack_stop();
extern u16 D_00262A50_as_u16_a[];
extern u16 D_00264160_as_u16_a[];
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
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 9);
        ENTITY(reg_a6)[1].misc.sb.user = 1;
        ENTITY(reg_a6)[2].misc.sb.user = 1;
        ENTITY(reg_a6)[3].misc.sb.user = 1;
        ENTITY(reg_a6)[4].misc.sb.user = 1;
        ENTITY(reg_a6)[5].misc.sb.user = 1;
        ENTITY(reg_a6)[6].misc.sb.user = 1;
        reg_a3 = (u8 *)(D_00264160_as_u16_a);
        reg_d1.h[0] = ENTITY(reg_a6)[1].move.h;
        reg_d2.b[0] = *(u8 *)(reg_a4 + 0x1B);
        func_001E9320();
        reg_d1.h[0] = ENTITY(reg_a6)[2].move.h;
        reg_d2.b[0] = *(u8 *)(reg_a4 + 0x1A);
        func_001E9220();
        reg_d1.h[0] = ENTITY(reg_a6)[3].move.h;
        reg_d2.b[0] = *(u8 *)(reg_a4 + 0x1D);
        func_001E9150();
        reg_d1.h[0] = ENTITY(reg_a6)[4].move.h;
        reg_d2.b[0] = *(u8 *)(reg_a4 + 0x1C);
        func_001E9320();
        reg_d1.h[0] = ENTITY(reg_a6)[5].move.h;
        reg_d2.b[0] = *(u8 *)(reg_a4 + 0x1F);
        func_001E9220();
        reg_d1.h[0] = ENTITY(reg_a6)[6].move.h;
        reg_d2.b[0] = *(u8 *)(reg_a4 + 0x1E);
        func_001E9150();
        if (*(u8 *)(reg_a4 + 5) == 0) {
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_a1 = (u8 *)(D_00262A50_as_u16_a);
            reg_a3 = (u8 *)(D_00264180);
            reg_d6.w = 5;
            do {
                reg_d7.w = 8;
                reg_d0.h[0] = ENTITY(reg_a6)[14].hp.h;
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
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            func_001E9420();
            t1 = *(u16 *)(reg_a4 + 0xA);
            if ((s16)(t1) < 0x10) {
                *(u16 *)(reg_a4 + 0xA) = (u16) (t1 + 1);
            }
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 8);
            ENTITY(reg_a6)[1].misc.sb.user = 0;
            ENTITY(reg_a6)[2].misc.sb.user = 0;
            ENTITY(reg_a6)[3].misc.sb.user = 0;
            ENTITY(reg_a6)[4].misc.sb.user = 0;
            ENTITY(reg_a6)[5].misc.sb.user = 0;
            ENTITY(reg_a6)[6].misc.sb.user = 0;
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
                *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
                t7 = ENTITY(reg_a6)[14].offset_y.b[1];
                if ((s32) t7 < 6) {
                    ENTITY(reg_a6)[14].offset_y.b[1] = (u8) (t7 + 2);
                }
                t8 = ENTITY(reg_a6)[14].offset_x.b[1];
                if ((s32) t8 < 3) {
                    ENTITY(reg_a6)[14].offset_x.b[1] = (u8) (t8 + 1);
                }
                t9 = ENTITY(reg_a6)[14].offset_x.b[0];
                if ((s32) t9 < 0x20) {
                    ENTITY(reg_a6)[14].offset_x.b[0] = (u8) (t9 + 8);
                }
                t5 = ENTITY(reg_a6)[14].draw.h;
                if ((s16)(t5) < 0x10) {
                    ENTITY(reg_a6)[14].draw.h = (u16) (t5 + 1);
                }
                t6 = ENTITY(reg_a6)[14].hp.h;
                if ((s16)(t6) < 4) {
                    ENTITY(reg_a6)[14].hp.h = (u16) (t6 + 1);
                }
                reg_d0.w = 0;
                boss_attack_stop();
            }
        }
    }
}

s32 rng_next_unsigned();
s32 func_00201270();
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
        *(u8 *)(reg_a4 + 0x1F) *= -1;
        *(u8 *)(reg_a4 + 0x1E) *= -1;
        func_00201270();
        *(u8 *)(reg_a4 + 0x1F) += reg_d0.b[0];
        func_00201270();
        *(u8 *)(reg_a4 + 0x1E) += reg_d0.b[0];
    }
    ENTITY(reg_a6)[1].misc.sb.user = 1;
    ENTITY(reg_a6)[2].misc.sb.user = 1;
    ENTITY(reg_a6)[3].misc.sb.user = 1;
    ENTITY(reg_a6)[4].misc.sb.user = 1;
    ENTITY(reg_a6)[5].misc.sb.user = 1;
    ENTITY(reg_a6)[6].misc.sb.user = 1;
    reg_d0.b[0] = ENTITY(reg_a6)[14].sprite.b[1];
    *(u8 *)(reg_a4 + 5) += reg_d0.b[0];
    *(u8 *)(reg_a4 + 4) += reg_d0.b[0];
    reg_d0.h[0] = ENTITY(reg_a6)[14].look.h;
    *(u16 *)(reg_a4 + 0xA) += reg_d0.h[0];
    reg_d0.h[0] = ENTITY(reg_a6)[14].hit_y_plus.h;
    *(u16 *)(reg_a4 + 0xE) += reg_d0.h[0];
    *(u16 *)(reg_a4 + 0x12) += reg_d0.h[0];
    *(u16 *)(reg_a4 + 0x16) += reg_d0.h[0];
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
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 7);
        if (*(u8 *)(reg_a4 + 5) & 1) {
            reg_a0 = (u8 *)(g_player1);
            reg_a1 = (u8 *)(g_player2);
            if (*(u8 *)(reg_a5 + 2) != 0) {
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
                reg_d0.h[1] = *(u16 *)(reg_a4 + 0xA);
                reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d3.w = 0xF0C00000;
                reg_d4.w = 0;
                bullet_fire256_fixed();
                enemy_switch_target_player();
                reg_d0.b[0] = *(u8 *)(reg_a4 + 5);
                if (*(u8 *)(reg_a4 + 4) == reg_d0.b[0]) {
                    reg_d1.b[0] += 0x40;
                    *(u8 *)(reg_a4 + 9) = (u8) reg_d1.b[0];
                    reg_d1.b[0] += 0x80;
                    reg_d1.b[0] *= -1;
                    *(u8 *)(reg_a4 + 8) = (u8) reg_d1.b[0];
                }
                goto block_11;
            }
        } else {
block_11:
            reg_d1.b[0] = *(u8 *)(reg_a4 + 9);
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xE);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x10);
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d3.w = 0xF2C0FC00;
            reg_d4.w = 0;
            bullet_fire256_2way();
            reg_d1.b[0] += 0x20;
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0x12);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x14);
            bullet_fire256_2way();
            reg_d1.b[0] += 0x60;
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0x16);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x18);
            bullet_fire256_fixed();
            if (*(u8 *)(reg_a4 + 5) & 1) {
                reg_d1.b[0] += 0x20;
                reg_d0.w = 0x10003;
                bullet_fire256_fixed();
            }
            reg_d1.b[0] = *(u8 *)(reg_a4 + 8);
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xE);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x10);
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d3.h[0] = 0x400;
            reg_d4.w = 0;
            bullet_fire256_2way();
            reg_d1.b[0] += 0x20;
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0x12);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x14);
            bullet_fire256_2way();
            reg_d1.b[0] += 0x60;
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0x16);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x18);
            bullet_fire256_fixed();
            if (*(u8 *)(reg_a4 + 5) & 1) {
                reg_d0.w = 0x10003;
                bullet_fire256_fixed();
            }
            reg_d0.b[0] = *(u8 *)(reg_a4 + 0x1F);
            *(u8 *)(reg_a4 + 9) += reg_d0.b[0];
            var_a1 = (s16 *)(reg_a4);
            reg_d0.b[0] = (*(u8 *)((u8 *)(var_a1) + (0x1E)));
            (*(u8 *)((u8 *)(var_a1) + (8))) += reg_d0.b[0];
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            *(u8 *)(reg_a4 + 0x1F) *= -1;
            *(u8 *)(reg_a4 + 0x1E) *= -1;
            temp_v0 = ENTITY(reg_a6)[14].sprite.b[1];
            if ((s32) temp_v0 < 0x3C) {
                ENTITY(reg_a6)[14].sprite.b[1] = (u8) (temp_v0 + 0x14);
            }
            temp_v1 = ENTITY(reg_a6)[14].look.h;
            if ((s16)(temp_v1) < 4) {
                ENTITY(reg_a6)[14].look.h = (u16) (temp_v1 + 1);
            }
            temp_v1_2 = ENTITY(reg_a6)[14].hit_y_plus.h;
            if ((s16)(temp_v1_2) < 0x1A) {
                ENTITY(reg_a6)[14].hit_y_plus.h = (u16) (temp_v1_2 + 1);
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

void func_001EA0E0(void) {
    u16 temp_a2;

    reg_a2 = D_002641C0;
    reg_d0.h[1] = *(u16 *)(reg_a4 + 0xA);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
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
extern u16 *reg_a0_as_u16_p;
extern u16 *reg_a1_as_u16_p;

void stage5_boss_fire_form1_arm_guns_fixed_start(void) {
    reg_a0_as_u16_p = D_002642E0;
    reg_a1_as_u16_p = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9D4 >> 1) - 1;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    if (ENTITY(reg_a6)[9].attr.b.flip != 0) {
        *(u8 *)(reg_a4 + 0x13) *= -1;
    }
    reg_d0.b[0] = ENTITY(reg_a6)[14].hit_y_minus.b[1];
    *(u8 *)(reg_a4 + 7) += reg_d0.b[0];
    *(u8 *)(reg_a4 + 6) += reg_d0.b[0];
    reg_d0.h[0] = ENTITY(reg_a6)[14].hit_x_plus.h;
    *(u16 *)(reg_a4 + 0xE) += reg_d0.h[0];
    rng_next();
    *(u8 *)(reg_a4 + 0x15) = (u8) reg_d0.b[0];
    rng_next();
    *(u8 *)(reg_a4 + 0x14) = (u8) reg_d0.b[0];
    rng_next();
    *(u8 *)(reg_a4 + 0x17) = (u8) reg_d0.b[0];
    rng_next();
    *(u8 *)(reg_a4 + 0x16) = (u8) reg_d0.b[0];
    rng_next();
    *(u8 *)(reg_a4 + 0x19) = (u8) reg_d0.b[0];
    rng_next();
    *(u8 *)(reg_a4 + 0x18) = (u8) reg_d0.b[0];
}

s32 func_00201100();
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
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        var_a1 = (s16 *)(reg_a4);
        (*(u8 *)((u8 *)(var_a1) + (3))) = (u8) (*(u8 *)((u8 *)(var_a1) + (9)));
        ENTITY(reg_a6)[1].misc.sb.user = 1;
        ENTITY(reg_a6)[2].misc.sb.user = 1;
        ENTITY(reg_a6)[3].misc.sb.user = 1;
        ENTITY(reg_a6)[4].misc.sb.user = 1;
        ENTITY(reg_a6)[5].misc.sb.user = 1;
        ENTITY(reg_a6)[6].misc.sb.user = 1;
        if (*(u8 *)(reg_a4 + 5) & 1) {
            reg_a0 = (u8 *)(g_player1);
            reg_a1 = (u8 *)(g_player2);
            if (*(u8 *)(reg_a5 + 2) != 0) {
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
                reg_d0.h[1] = *(u16 *)(reg_a4 + 0xE);
                reg_d0.h[0] = *(u16 *)(reg_a4 + 0x10);
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                temp_a0_2 = ENTITY(reg_a6)->x.h;
                reg_d2.h[0] = temp_a0_2;
                reg_d3.w = 0xF0C00000;
                reg_d4.w = 0;
                reg_d5.h[0] = ENTITY(reg_a6)->y.h;
                reg_d5.h[0] += 0x7FFF + 0x7601;
                if ((s32) reg_d5.h[0] <= (s32) reg_d7.h[0]) {
                    reg_d0.w += 0x100000;
                    func_00201100();
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
            func_001EA0E0();
            reg_d1.h[0] = 0x70;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x15);
            bullet_fire256_fixed();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0xC0;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x15);
            bullet_fire256_fixed();
            reg_d1.h[0] = ENTITY(reg_a6)[2].move.h;
            func_001EA0E0();
            reg_d1.h[0] = 0x7C;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x14);
            bullet_fire256_fixed();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0xB8;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x14);
            bullet_fire256_fixed();
            reg_d1.h[0] = ENTITY(reg_a6)[3].move.h;
            func_001EA0E0();
            reg_d1.h[0] = 0x98;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x17);
            bullet_fire256_fixed();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0xB0;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x17);
            bullet_fire256_fixed();
            reg_d1.h[0] = ENTITY(reg_a6)[4].move.h;
            func_001EA0E0();
            reg_d1.h[0] = 0x90;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x16);
            bullet_fire256_fixed();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0x40;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x16);
            bullet_fire256_fixed();
            reg_d1.h[0] = ENTITY(reg_a6)[5].move.h;
            func_001EA0E0();
            reg_d1.h[0] = 0x84;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x19);
            bullet_fire256_fixed();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0x48;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x19);
            bullet_fire256_fixed();
            reg_d1.h[0] = ENTITY(reg_a6)[6].move.h;
            func_001EA0E0();
            reg_d1.h[0] = 0x68;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x18);
            bullet_fire256_fixed();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0x50;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x18);
            bullet_fire256_fixed();
        }
        reg_d0.b[0] = *(u8 *)(reg_a4 + 0x13);
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
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            rng_next();
            reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 1);
            reg_d0.b[0] += *(u8 *)(reg_a4 + 4);
            *(u8 *)(reg_a4 + 5) = (u8) reg_d0.b[0];
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 8);
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
                ENTITY(reg_a6)[9].attr.sb.flip = (s8) ~(ENTITY(reg_a6)[9].attr.sb.flip);
                temp_v0 = ENTITY(reg_a6)[14].hit_y_minus.h;
                if ((s32) temp_v0 < 4) {
                    ENTITY(reg_a6)[14].hit_y_minus.h = (u16) (temp_v0 + 1);
                }
                temp_v0_2 = ENTITY(reg_a6)[14].hit_x_plus.h;
                if ((s32) temp_v0_2 < 4) {
                    ENTITY(reg_a6)[14].hit_x_plus.h = (u16) (temp_v0_2 + 1);
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
    reg_a0_as_u16_p = D_00264300;
    reg_a1_as_u16_p = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9D8 >> 1) - 1;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = ENTITY(reg_a6)[9].misc.h;
    *(u16 *)(reg_a4 + 0xA) += reg_d0.h[0];
    *(u16 *)(reg_a4 + 0x12) += reg_d0.h[0];
    reg_d0.b[0] = ENTITY(reg_a6)[14].hit_x_minus.b[1];
    *(u8 *)(reg_a4 + 7) += reg_d0.b[0];
    *(u8 *)(reg_a4 + 6) += reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[14].hit_x_minus.b[0];
    *(u8 *)(reg_a4 + 8) -= reg_d0.b[0];
    *(u8 *)(reg_a4 + 3) += 2;
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
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 9);
        reg_d0.b[0] = *(u8 *)(reg_a4 + 5);
        t8 = *(u8 *)(reg_a4 + 4);
        if (t8 == reg_d0.b[0]) {
            func_00201270();
            *(u8 *)(reg_a4 + 0x15) = (u8) reg_d0.b[0];
        }
        reg_a0 = (u8 *)(g_player1);
        reg_a1 = (u8 *)(g_player2);
        if (*(u8 *)(reg_a5 + 2) != 0) {
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
            reg_d4.h[0] = *(u16 *)(reg_a4 + 0xE);
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
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xA);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
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
            reg_d5.b[0] = *(u8 *)(reg_a4 + 0x15);
            reg_d4.b[0] = (u8) (t2 >> reg_d5.b[0]);
            reg_d1.b[0] += reg_d4.b[0];
            reg_d4.w = 0;
            reg_d6.b[0] = *(u8 *)(reg_a4 + 7);
            bullet_fire256_double_entry();
            reg_d1.w = t7;
            reg_d3.h[1] = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d3.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d4.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            t3 = (s8) reg_d4.b[0];
            reg_d5.b[0] = *(u8 *)(reg_a4 + 0x15);
            reg_d4.b[0] = (u8) (t3 >> reg_d5.b[0]);
            reg_d1.b[0] += reg_d4.b[0];
            reg_d6.b[0] = *(u8 *)(reg_a4 + 7);
            reg_d6.b[0] = ~(s8) reg_d6.b[0];
            bullet_fire256_double_entry();
            reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xE);
            *(u16 *)(reg_a4 + 0xE) -= 0xC;
            if ((s32) reg_tmp.h[0] < 0xC) {
                *(u16 *)(reg_a4 + 0xE) = 0x30U;
            }
next_2:
        *(u16 *)(reg_a4 + 0xA) += 1;
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            enemy_switch_target_player();
            t11 = *(u8 *)(reg_a4 + 4);
            if ((s32) t11 < 0x1E) {
                *(u8 *)(reg_a4 + 4) = (u8) (t11 + 0xF);
            }
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 8);
            *(u8 *)(reg_a4 + 3) += 4;
            *(u16 *)(reg_a4 + 0x12) += 1;
            *(u16 *)(reg_a4 + 0xA) = (u16) *(u16 *)(reg_a4 + 0x12);
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
                *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
                t9 = ENTITY(reg_a6)[14].hit_x_minus.b[1];
                if ((s32) t9 < 2) {
                    ENTITY(reg_a6)[14].hit_x_minus.b[1] = (u8) (t9 + 1);
                }
                t6 = ENTITY(reg_a6)[9].misc.h;
                if ((s32) t6 < 6) {
                    ENTITY(reg_a6)[9].misc.h = (u16) (t6 + 1);
                }
                t10 = ENTITY(reg_a6)[14].hit_x_minus.b[0];
                if ((s32) t10 < 0x18) {
                    ENTITY(reg_a6)[14].hit_x_minus.b[0] = (u8) (t10 + 2);
                }
                reg_d0.w = 3;
                boss_attack_stop();
            }
        }
    }
}

void func_001EAF20(void) {
    s32 bullet_fire256_direct();
    u32 var_a1;
    u8 var_a0;

    var_a0 = 0xF0C00000;
    reg_d0.h[1] = *(u16 *)(reg_a4 + 0xA);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
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
extern s32 reg_a4_as_s32;

void stage5_boss_fire_form1_rage_start(void) {
    reg_a0_as_u16_p = D_00264360;
    reg_a1_as_u16_p = (u16 *)(reg_a4_as_s32 + 2);
    reg_d0.w = ((u32) D_0028D9DC >> 1) - 1;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

extern u8 D_00262A50_as_u8_a[];

void stage5_boss_fire_form1_rage(void) {
    u32 temp_a0;
    u8 temp_v1;
    u8 temp_v1_2;

    if (g_bullets_blocked != 0) {
        stage5_boss_fire_form1_rage_start();
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        reg_d0.b[0] = *(u8 *)(reg_a4 + 9);
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
        if ((u32) reg_tmp.w < 0x15000U) {
            reg_d0.b[0] -= 4;
        }
        *(u8 *)(reg_a4 + 3) = (u8) reg_d0.b[0];
        reg_a1 = (u8 *)D_00262A50_as_u8_a;
        reg_d1.b[0] = *(u8 *)(reg_a4 + 0x12);
        func_001EAF20();
        reg_d1.b[0] = *(u8 *)(reg_a4 + 0x12);
        reg_d1.b[0] += 0x80;
        func_001EAF20();
        reg_d0.b[0] = *(u8 *)(reg_a4 + 0x13);
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
        if ((u32) reg_tmp.w < 0x15000U) {
            reg_d0.b[0] = (s8) reg_d0.b[0] * 4;
        }
        *(u8 *)(reg_a4 + 0x12) += reg_d0.b[0];
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 8);
            *(u8 *)(reg_a4 + 0x13) *= -1;
            temp_a0 = *(u16 *)(reg_a4 + 0xA);
            if ((s16)(temp_a0) < 8) {
                *(u16 *)(reg_a4 + 0xA) = (u16) (temp_a0 + 2);
            }
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
                temp_v1 = *(u8 *)(reg_a4 + 9);
                if ((s32) temp_v1 > 5) {
                    *(u8 *)(reg_a4 + 9) = (u8) (temp_v1 - 2);
                }
                temp_v1_2 = *(u8 *)(reg_a4 + 4);
                if ((s32) temp_v1_2 < 0xC7) {
                    *(u8 *)(reg_a4 + 4) = (u8) (temp_v1_2 + 0x14);
                }
                *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
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
    *(u8 *)(reg_a4 + 0x11) = (u8) reg_d0.b[0];
    rng_next_unsigned();
    if (0 > reg_d0.sb[0]) {
        *(u8 *)(reg_a4 + 0x10) *= -1;
    }
    reg_d0.b[0] = ENTITY(reg_a6)[14].move.b.speed;
    *(u8 *)(reg_a4 + 5) += reg_d0.b[0];
    *(u8 *)(reg_a4 + 4) += reg_d0.b[0];
    reg_d0.h[0] = ENTITY(reg_a6)[14].attr.h;
    *(u16 *)(reg_a4 + 8) += reg_d0.h[0];
    reg_d0.h[0] = ENTITY(reg_a6)[14].misc.h;
    *(u16 *)(reg_a4 + 0xC) += reg_d0.h[0];
}

extern s16 D_00262A50[];

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
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 7);
        if (*(u8 *)(reg_a4 + 5) & 1) {
            reg_a0 = (u8 *)(g_player1);
            reg_a1 = (u8 *)(g_player2);
            if (*(u8 *)(reg_a5 + 2) != 0) {
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
                reg_d0.h[1] = *(u16 *)(reg_a4 + 8);
                reg_d0.h[0] = *(u16 *)(reg_a4 + 0xA);
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d5.w = 0xF0C00000;
                reg_d7.w = 6;
                reg_d1.h[0] -= 0x36;
                reg_a1 = (u8 *)(D_00262A50);
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
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0x11);
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xC);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xE);
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d5.w = 0xF0C00000;
            reg_d7.w = 0xC;
            reg_d1.h[0] -= 0x3C;
            reg_a1 = (u8 *)(D_00262A50);
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
            reg_d1.b[0] = reg_a4[0x10];
            if (!(0 > (s8) reg_d1.b[0])) {
                goto next_31;
            }
            reg_a4[0x11] += reg_d1.b[0];
            if ((s32) reg_a4[0x11] < 0x50) {
                goto next_32;
            }
            goto next_33;
next_31:
            reg_a4[0x11] += reg_d1.b[0];
            if ((s32) reg_a4[0x11] <= 0xB0) {
                goto next_33;
            }
next_32:
            reg_a4[0x10] *= -1;
next_33:;
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            t6 = ENTITY(reg_a6)[14].move.b.speed;
            if ((s32) t6 < 0x28) {
                ENTITY(reg_a6)[14].move.b.speed = (u8) (t6 + 0xA);
            }
            t3 = ENTITY(reg_a6)[14].attr.h;
            if ((s16)(t3) < 4) {
                ENTITY(reg_a6)[14].attr.h = (u16) (t3 + 1);
            }
            t4 = ENTITY(reg_a6)[14].misc.h;
            if ((s16)(t4) < 0x1A) {
                ENTITY(reg_a6)[14].misc.h = (u16) (t4 + 1);
            }
            reg_d0.w = 5;
            boss_attack_stop();
        }
    }
}

void func_001EB8E0(void) {
    s32 bullet_fire256_direct();
    u32 temp_a0;

    reg_d7.h[0] = reg_d1.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xA);
    reg_d1.b[0] -= 1;
    bullet_fire256_direct();
    reg_d1.b[0] += 2;
    bullet_fire256_direct();
    reg_d1.h[0] = reg_d7.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
    reg_d0.w += 0x40000;
    bullet_fire256_direct();
    reg_d1.b[0] -= 2;
    bullet_fire256_direct();
    reg_d1.b[0] += 4;
    bullet_fire256_direct();
    reg_d1.h[0] = reg_d7.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xA);
    temp_a0 = reg_d0.w;
    reg_d0.w = temp_a0 + 0x40000;
    reg_d1.b[0] -= 1;
    bullet_fire256_direct();
    reg_d1.b[0] += 2;
    bullet_fire256_direct();
    reg_d1.h[0] = reg_d7.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
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
    reg_a0_as_u16_p = D_00264390;
    reg_a1_as_u16_p = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9E4 >> 1) - 1;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = ENTITY(reg_a6)[15].offset_x.h;
    *(u16 *)(reg_a4 + 8) += reg_d0.h[0];
    reg_d0.b[0] = ENTITY(reg_a6)[15].offset_y.b[1];
    *(u8 *)(reg_a4 + 5) += reg_d0.b[0];
    *(u8 *)(reg_a4 + 4) += reg_d0.b[0];
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
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 7);
        reg_a0 = (u8 *)(g_player1);
        reg_a1 = (u8 *)(g_player2);
        if (*(u8 *)(reg_a5 + 2) != 0) {
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
            reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_a3 = (u8 *)D_002643A0;
            reg_d4.h[0] = *(u16 *)(reg_a4 + 0xE);
            reg_a3 += reg_d4.h[0];
            reg_d3.h[1] = *(u16 *)reg_a3;
            reg_d3.h[0] = *(u16 *)(reg_a3 + 2);
            reg_d4.w = 0;
            func_001EB8E0();
            reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xE);
            *(u16 *)(reg_a4 + 0xE) -= 4;
            if ((s32) reg_tmp.h[0] < 4) {
                *(u16 *)(reg_a4 + 0xE) = 0x14U;
            }
        }
        enemy_switch_target_player();
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            temp_v0 = ENTITY(reg_a6)[15].offset_y.b[1];
            if ((s32) temp_v0 < 0x14) {
                ENTITY(reg_a6)[15].offset_y.b[1] = (u8) (temp_v0 + 0xA);
            }
            temp_v0_2 = ENTITY(reg_a6)[15].offset_x.h;
            if ((s32) temp_v0_2 < 6) {
                ENTITY(reg_a6)[15].offset_x.h = (u16) (temp_v0_2 + 1);
            }
            reg_d0.w = 6;
            boss_attack_stop();
        }
    }
}

void func_001EBD30(void) {
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
    reg_d0.h[0] += *(u16 *)(reg_a4 + 0xE);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x10);
    reg_d4.w = 0;
    bullet_fire256_direct();
}

extern u16 D_002643C0[];
extern u32 D_0028D9E8;

void stage5_boss_fire_form2_horn_start(void) {
    reg_a0_as_u16_p = D_002643C0;
    reg_a1_as_u16_p = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9E8 >> 1) - 1;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = ENTITY(reg_a6)[15].sprite.h;
    *(u16 *)(reg_a4 + 0xA) += reg_d0.h[0];
    reg_d0.b[0] = ENTITY(reg_a6)[15].draw.b.priority;
    *(u8 *)(reg_a4 + 8) -= reg_d0.b[0];
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
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        var_a1 = (unsigned char *)(*(u8 *)(reg_a4 + 9));
        *(u8 *)(reg_a4 + 3) = (unsigned char)var_a1;
        reg_a0 = (u8 *)(g_player1);
        reg_a1 = (u8 *)(g_player2);
        if (*(u8 *)(reg_a5 + 2) != 0) {
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
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xA);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            temp_a0_2 = ENTITY(reg_a6)->x.h;
            reg_d2.h[0] = temp_a0_2;
            reg_d7.h[0] = reg_d1.h[0];
            reg_a3 = (u8 *)stage5_boss_horn_shot_offsets;
            reg_d4.w = 0;
            reg_d4.b[0] = *(u8 *)(reg_a4 + 7);
            reg_d4.h[0] += reg_d4.h[0];
            reg_d4.h[0] += reg_d4.h[0];
            reg_a3 += reg_d4.h[0];
            reg_tmp.h[1] = *(u16 *)reg_a3;
            reg_tmp.h[0] = *(u16 *)(reg_a3 + 2);
            reg_a3 = (u8 *) reg_tmp.w;
            reg_d4.h[0] = *(u16 *)(reg_a4 + 0x12);
            reg_a3 += reg_d4.h[0];
            func_001EBD30();
            reg_d1.h[0] = reg_d7.h[0];
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xA);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
            func_001EBD30();
            reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x12);
            *(u16 *)(reg_a4 + 0x12) -= 0x10;
            if ((s32) reg_tmp.h[0] < 0x10) {
                *(u16 *)(reg_a4 + 0x12) = 0x40U;
            }
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            enemy_switch_target_player();
            temp_v1 = *(u8 *)(reg_a4 + 4);
            if ((s32) temp_v1 < 0x3B) {
                *(u8 *)(reg_a4 + 4) = (u8) (temp_v1 + 0xF);
            }
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            *(u16 *)(reg_a4 + 0xA) += 2;
            *(u16 *)(reg_a4 + 0xE) += 1;
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 8);
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                temp_v0 = ENTITY(reg_a6)[15].draw.b.priority;
                if ((s32) temp_v0 < 0x10) {
                    ENTITY(reg_a6)[15].draw.b.priority = (u8) (temp_v0 + 8);
                }
                temp_v0_2 = ENTITY(reg_a6)[15].sprite.h;
                if ((s32) temp_v0_2 < 0xB) {
                    ENTITY(reg_a6)[15].sprite.h = (u16) (temp_v0_2 + 2);
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
    *(u8 *)(reg_a4 + 0x11) = (u8) reg_d0.b[0];
    rng_next_unsigned();
    if (0 > reg_d0.sb[0]) {
        *(u8 *)(reg_a4 + 0x10) *= -1;
    }
    reg_d0.b[0] = ENTITY(reg_a6)[15].look.b.size;
    *(u8 *)(reg_a4 + 5) += reg_d0.b[0];
    *(u8 *)(reg_a4 + 4) += reg_d0.b[0];
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
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 7);
        reg_a0 = (u8 *)(g_player1);
        reg_a1 = (u8 *)(g_player2);
        if (*(u8 *)(reg_a5 + 2) != 0) {
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
                func_00201100();
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
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0x11);
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xC);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xE);
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d6.w = 0xD8000000;
            reg_d7.w = 6;
            reg_d1.h[0] -= 0x2D;
            reg_a1 = (u8 *)(D_00262A50);
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
            reg_d1.b[0] = reg_a4[0x10];
            if (0 > (s8) reg_d1.b[0]) {
                goto next_21;
            }
            reg_a4[0x11] += reg_d1.b[0];
            if (*(s8 *)(reg_a4 + 0x11) > 0x30) {
                goto next_22;
            }
            goto next_23;
next_21:
            reg_a4[0x11] += reg_d1.b[0];
            if (*(s8 *)(reg_a4 + 0x11) >= -0x30) {
                goto next_23;
            }
next_22:
            reg_a4[0x10] *= -1;
next_23:;
        }
        enemy_switch_target_player();
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            stage5_boss_fire_form2_stinger_start();
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            t5 = ENTITY(reg_a6)[15].look.b.size;
            if ((s32) t5 < 0x28) {
                ENTITY(reg_a6)[15].look.b.size = (u8) (t5 + 0x14);
            }
            reg_d0.w = 8;
            boss_attack_stop();
        }
    }
}

void func_001EC790(void) {
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
    *(s8 *)(reg_a4 + 0xF) = 0x20;
    rng_next_unsigned();
    if (0 > reg_d0.sb[0]) {
        *(u8 *)(reg_a4 + 0xE) *= -1;
    }
    reg_d0.h[0] = ENTITY(reg_a6)[15].hp.h;
    *(u16 *)(reg_a4 + 8) += reg_d0.h[0];
    reg_d0.b[0] = ENTITY(reg_a6)[15].hit_x_minus.b[1];
    *(u8 *)(reg_a4 + 5) += reg_d0.b[0];
    *(u8 *)(reg_a4 + 4) += reg_d0.b[0];
}


void stage5_boss_fire_form3_attack_a(void) {
    s16 *temp_v1;
    s16 *var_a0;
    u16 temp_v0_2;
    u8 temp_v0;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 7);
        reg_a0 = (u8 *)(g_player1);
        reg_a1 = (u8 *)(g_player2);
        if (*(u8 *)(reg_a5 + 2) != 0) {
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
            if (*(u8 *)(reg_a4 + 5) & 1) {
                reg_d1.b[0] += *(u8 *)(reg_a4 + 0xF);
                reg_d1.h[0] -= 0x23;
                reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = reg_tmp.h[0];
                reg_d0.h[0] = reg_tmp.h[1];
                reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
                func_001EC790();
            } else {
                reg_d1.h[0] = reg_d5.h[0];
                reg_d1.b[0] -= *(u8 *)(reg_a4 + 0xF);
                reg_d1.h[0] -= 0x23;
                reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = reg_tmp.h[0];
                reg_d0.h[0] = reg_tmp.h[1];
                reg_d0.h[0] = *(u16 *)(reg_a4 + 0xA);
                func_001EC790();
            }
            var_a0 = (s16 *)(reg_a4);
            reg_d1.b[0] = (*(u8 *)((u8 *)(var_a0) + (0xE)));
            if (0 <= (s8)(reg_d1.b[0])) {
                (*(u8 *)((u8 *)(var_a0) + (0xF))) += reg_d1.b[0];
                if ((s8) *(u8 *)(reg_a4 + 0xF) > 0x10) {
                    goto block_13;
                }
                goto block_end;
            } else {
                (*(u8 *)((u8 *)(var_a0) + (0xF))) += reg_d1.b[0];
                if ((s8) *(u8 *)(reg_a4 + 0xF) < -0x10) {
block_13:
                    var_a0 = (s16 *)(reg_a4);
                    (*(u8 *)((u8 *)(var_a0) + (0xE))) *= -1;
                }
            }
        }
block_end:
        enemy_switch_target_player();
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            temp_v0 = ENTITY(reg_a6)[15].hit_x_minus.b[1];
            if ((s32) temp_v0 < 0x1E) {
                ENTITY(reg_a6)[15].hit_x_minus.b[1] = (u8) (temp_v0 + 0x14);
            }
            temp_v0_2 = ENTITY(reg_a6)[15].hp.h;
            if ((s32) temp_v0_2 < 2) {
                ENTITY(reg_a6)[15].hp.h = (u16) (temp_v0_2 + 1);
            }
            reg_d0.w = 9;
            boss_attack_stop();
        }
    }
}

void func_001ECBD0(void) {
    s32 bullet_fire256_direct();
    u32 var_a1;
    u8 var_a0;

    var_a0 = 0xFA000000;
    reg_d0.h[1] = *(u16 *)(reg_a4 + 8);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xA);
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d4.h[1] = *(u16 *)(reg_a4 + 0xC);
    var_a1 = *(u16 *)(reg_a4 + 0xE);
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
    reg_a0_as_u16_p = D_00264550;
    reg_a1_as_u16_p = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9F4 >> 1) - 1;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.b[0] = ENTITY(reg_a6)[15].hit_y_plus.b[0];
    *(u8 *)(reg_a4 + 5) += reg_d0.b[0];
    *(u8 *)(reg_a4 + 4) += reg_d0.b[0];
    reg_d0.h[0] = ENTITY(reg_a6)[15].hit_y_minus.h;
    *(u16 *)(reg_a4 + 8) += reg_d0.h[0];
    reg_d0.h[0] = ENTITY(reg_a6)[15].hit_x_plus.h;
    *(u16 *)(reg_a4 + 0xC) += reg_d0.h[0];
    rng_next_unsigned();
    *(u8 *)(reg_a4 + 0x10) = (u8) reg_d0.b[0];
    if (ENTITY(reg_a6)[15].hit_y_plus.b[1] == 0) {
        *(u8 *)(reg_a4 + 0x11) *= -1;
    }
}

s32 func_00202A80();
extern s16 g_enemy_signal_2_as_s16;

void stage5_boss_fire_form3_attack_b() {
    u16 temp_v0_2;
    u16 temp_v0_3;
    u8 temp_v0;

    g_enemy_signal_2_as_s16 = 0;
    func_00202A80();
    if ((s32) reg_d0.h[0] < 0x2000) {
        g_enemy_signal_2_as_s16 = 1;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 7);
        reg_a1 = D_00262A50_as_u8_a;
        reg_d1.b[0] = *(u8 *)(reg_a4 + 0x10);
        func_001ECBD0();
        reg_d0.b[0] = *(u8 *)(reg_a4 + 0x11);
        *(u8 *)(reg_a4 + 0x10) += reg_d0.b[0];
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            ENTITY(reg_a6)[15].hit_y_plus.sb[1] = (s8) ~(ENTITY(reg_a6)[15].hit_y_plus.sb[1]);
            temp_v0 = ENTITY(reg_a6)[15].hit_y_plus.b[0];
            if ((s32) temp_v0 < MAIN_OR_DEATH_LABEL(0x95, 0x81)) {
                ENTITY(reg_a6)[15].hit_y_plus.b[0] = (u8) (temp_v0 + 0xA);
            }
            temp_v0_2 = ENTITY(reg_a6)[15].hit_y_minus.h;
            if ((s32) temp_v0_2 < 2) {
                ENTITY(reg_a6)[15].hit_y_minus.h = (u16) (temp_v0_2 + 1);
            }
            temp_v0_3 = ENTITY(reg_a6)[15].hit_x_plus.h;
            if ((s32) temp_v0_3 < 3) {
                ENTITY(reg_a6)[15].hit_x_plus.h = (u16) (temp_v0_3 + 1);
            }
            reg_d0.w = 0xA;
            boss_attack_stop();
        }
    }
}

void func_001ECF90(void) {
    s32 bullet_fire256_direct();
    reg_d0.h[1] = *(u16 *)(reg_a4 + 8);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xA);
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
    reg_a0_as_u16_p = D_00264560;
    reg_a1_as_u16_p = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9F8 >> 1) - 1;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    *(s16 *)(reg_a4 + 0xC) = 0x404;
}

extern u16 g_player2_as_u16_a[];
extern u16 g_player1_as_u16_a[];

void stage5_boss_fire_form3_attack_c(u8 *arg0, s16 *arg1) {
    s16 *temp_a0;
    s16 *var_a1;
    u8 temp_a1;
    u8 temp_a2;
    u8 *var_a0;

    var_a0 = (u8 *)(arg0);
    var_a1 = (s16 *)(arg1);
    if (g_bullets_blocked == 0) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if (reg_tmp.b[0] == 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 7);
            reg_d2.b[0] = *(u8 *)(reg_a4 + 5);
            if (*(u8 *)(reg_a4 + 4) == reg_d2.b[0]) {
                reg_a0 = (u8 *)(g_player1_as_u16_a);
                reg_a1 = (u8 *)(g_player2_as_u16_a);
                if (*(u8 *)(reg_a5 + 2) != 0) {
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
                    *(u8 *)(reg_a4 + 6) = (u8) reg_d1.b[0];
                    goto block_9;
                }
            } else {
block_9:
                reg_d1.b[0] = *(u8 *)(reg_a4 + 6);
                reg_d6.b[0] = 0xB7;
                reg_d7.h[0] = reg_d1.h[0];
                temp_a1 = *(u8 *)(reg_a4 + 5);
                reg_d6.b[0] -= temp_a1;
                reg_d1.b[0] += reg_d6.b[0];
                reg_d6.h[0] = 0x16;
                func_001ECF90();
                reg_d6.b[0] = 0xB7;
                reg_d1.h[0] = reg_d7.h[0];
                temp_a2 = *(u8 *)(reg_a4 + 5);
                reg_d6.b[0] -= temp_a2;
                reg_d6.b[0] *= -1;
                reg_d1.b[0] += reg_d6.b[0];
                reg_d6.h[0] = 0xFFEA;
                func_001ECF90();
            }
            *(u8 *)(reg_a4 + 0xD) -= 1;
            var_a1 = (s16 *)(reg_a4 + 0xD);
            if (*(u8 *)(reg_a4 + 0xD) == 0) {
                *(u8 *)(reg_a4 + 0xD) = (u8) *(u8 *)(reg_a4 + 0xC);
                *(u8 *)(reg_a4 + 3) = 4U;
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

s32 func_00201230();
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
    *(u8 *)(reg_a4 + 0xF) = (u8) reg_d0.b[0];
    rng_next_unsigned();
    if (0 > reg_d0.sb[0]) {
        *(u8 *)(reg_a4 + 0xE) *= -1;
    }
    func_00201230();
    reg_d0.w = (u32) (s16) reg_d0.h[0];
    *(u16 *)(reg_a4 + 0x1C) = (u16) reg_d0.h[0];
    reg_d0.h[0] += 2;
    *(u16 *)(reg_a4 + 0x12) = (u16) reg_d0.h[0];
    reg_d0.b[0] = ENTITY(reg_a6)[15].look.b.palette;
    *(u8 *)(reg_a4 + 7) += reg_d0.b[0];
    *(u8 *)(reg_a4 + 6) += reg_d0.b[0];
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
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 9);
        reg_d0.b[0] = *(u8 *)(reg_a4 + 5);
        if (*(u8 *)(reg_a4 + 4) == reg_d0.b[0]) {
            reg_a0 = (u8 *)(g_player1);
            reg_a1 = (u8 *)(g_player2);
            if (*(u8 *)(reg_a5 + 2) != 0) {
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
                *(u8 *)(reg_a4 + 0x1B) = (u8) reg_d1.b[0];
                goto next_2;
            }
        } else {
next_2:
            reg_d1.w = 0;
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0x1B);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x18);
            velocity_from_dir256();
            g_enemy_signal_0 = reg_d2.h[0];
            g_enemy_signal_1 = reg_d3.h[0];
            enemy_switch_target_player();
            t3 = 0xFA000000;
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xA);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0xF);
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d4.h[0] = *(u16 *)(reg_a4 + 0x10);
            reg_tmp.w = reg_d4.w;
            reg_d4.h[1] = reg_tmp.h[0];
            reg_d4.h[0] = reg_tmp.h[1];
            reg_d4.h[0] = *(u16 *)(reg_a4 + 0x12);
            reg_d5.h[0] = *(u16 *)(reg_a4 + 0x14);
            reg_tmp.w = reg_d5.w;
            reg_d5.h[1] = reg_tmp.h[0];
            reg_d5.h[0] = reg_tmp.h[1];
            reg_d5.h[0] = *(u16 *)(reg_a4 + 0x16);
            reg_d6.w = 0xFA000000;
            reg_d7.w = 7;
            reg_a1 = (u8 *)(D_00262A50);
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
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0xE);
            *(u8 *)(reg_a4 + 0xF) += reg_d1.b[0];
            *(u16 *)(reg_a4 + 0x18) += 1;
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 4) += 1;
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            *(u8 *)(reg_a4 + 0xE) *= -1;
            *(u16 *)(reg_a4 + 0x18) = 0x12U;
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 8);
            *(u8 *)(reg_a4 + 8) -= 4;
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x1C);
            reg_d0.h[0] += 1;
            if ((s32) reg_d0.h[0] > 2) {
                reg_d0.h[0] = 0;
            }
            *(u16 *)(reg_a4 + 0x1C) = (u16) reg_d0.h[0];
            reg_d0.h[0] += 2;
            *(u16 *)(reg_a4 + 0x12) = (u16) reg_d0.h[0];
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                t2 = ENTITY(reg_a6)[15].look.b.palette;
                if ((s32) t2 < 4) {
                    ENTITY(reg_a6)[15].look.b.palette = (u8) (t2 + 2);
                }
                reg_d0.w = 0xC;
                boss_attack_stop();
            }
        }
    }
}

extern u16 D_00259770[];

void func_001ED980(void) {
    s32 bullet_fire256_direct();
    u16 var_a0;
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        var_a0 = 0xFE000000;
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        reg_d0.h[1] = *(u16 *)(reg_a4 + 0xA);
        reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
        reg_d1.b[0] = *(u8 *)(reg_a4 + 0x17);
        reg_d4.w = 0;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d6.w = 0xFE000000;
        reg_d7.w = 3;
        reg_a1 = (u8 *)(D_00259770);
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
        reg_d1.b[0] = *(u8 *)(reg_a4 + 0x16);
        *(u8 *)(reg_a4 + 0x17) += reg_d1.b[0];
    }
}

extern u16 D_00259970[];

void func_001EDB00(void) {
    s32 bullet_fire256_direct();
    u16 var_a0;
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
    *(u8 *)(reg_a4 + 7) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        var_a0 = 0xFE000000;
        *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
        reg_d0.h[1] = *(u16 *)(reg_a4 + 0x12);
        reg_d0.h[0] = *(u16 *)(reg_a4 + 0x14);
        reg_d1.b[0] = *(u8 *)(reg_a4 + 0x1B);
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d6.w = 0xFE000000;
        reg_d7.w = 3;
        reg_a1 = (u8 *)(D_00259970);
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
        reg_d1.b[0] = *(u8 *)(reg_a4 + 0x1A);
        *(u8 *)(reg_a4 + 0x1B) += reg_d1.b[0];
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
    *(u8 *)(reg_a4 + 0x17) = (u8) reg_d0.b[0];
    rng_next_unsigned();
    *(u8 *)(reg_a4 + 0x19) = (u8) reg_d0.b[0];
    rng_next_unsigned();
    *(u8 *)(reg_a4 + 0x1B) = (u8) reg_d0.b[0];
    ENTITY(reg_a6)[15].misc.sh = 5;
    ENTITY(reg_a6)[15].attr.sb.palette = 8;
}

extern u16 D_00259870[];
extern s16 g_enemy_signal_1_as_s16;
extern s16 g_enemy_signal_0_as_s16;

void stage5_boss_fire_form3_rage(void) {
    s32 bullet_fire256_direct();
    u8 *p;
    u8 t;

    func_001ED980();
    p = reg_a4 + 0x1C;
    switch (*(u16 *)p) { case 0: goto next_0; }
    *(u16 *)p -= 1;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if ((u32)reg_tmp.w >= 0x1F800U) goto next_2;
next_0:
    func_001EDB00();
    p = reg_a4 + 0x1E;
    if (*(u16 *)p == 0) goto next_1;
    *(u16 *)p -= 1;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if ((u32)reg_tmp.w >= 0x1C000U) goto next_9;
next_1:
    reg_tmp.b[0] = reg_a4[5];
    reg_a4[5] -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_2;
    reg_a4[5] = reg_a4[4];
    reg_d0.h[1] = *(u16 *)(reg_a4 + 0xE);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x10);
    reg_d1.b[0] = reg_a4[0x19];
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    g_enemy_signal_0_as_s16 = 0;
    g_enemy_signal_1_as_s16 = 0;
    reg_d4.h[0] = 0x101;
    reg_tmp.w = reg_d4.w;
    reg_d4.h[1] = reg_tmp.h[0];
    reg_d4.h[0] = reg_tmp.h[1];
    reg_d4.h[0] = ENTITY(reg_a6)[15].misc.h;
    reg_d5.w = 0x01010001;
    reg_d6.w = 0xFE000000;
    reg_d7.w = 9;
    reg_a1 = (u8 *)D_00259870;
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
    reg_d1.b[0] = reg_a4[0x18];
    reg_a4[0x19] += reg_d1.b[0];
next_2:
    reg_tmp.b[0] = ENTITY(reg_a6)[15].attr.b.palette;
    ENTITY(reg_a6)[15].attr.b.palette -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_9;
    ENTITY(reg_a6)[15].attr.b.palette = 8;
    if (ENTITY(reg_a6)[15].attr.b.flip & 1) goto next_4;
    if ((s8)reg_a4[0x18] == -6) goto next_3;
    reg_a4[0x18] -= 1;
    goto next_7;
next_3:
    if (ENTITY(reg_a6)[15].misc.h == 5) goto next_8;
    ENTITY(reg_a6)[15].misc.h += 1;
    goto next_7;
next_4:
    if (reg_a4[0x18] == 6) goto next_5;
    reg_a4[0x18] += 1;
    goto next_7;
next_5:
    if ((s16)ENTITY(reg_a6)[15].misc.h == -5) goto next_8;
    ENTITY(reg_a6)[15].misc.h -= 1;
next_7:
    return;
next_8:
    reg_tmp.b[0] = reg_a4[9];
    reg_a4[9] -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_9;
    reg_a4[9] = reg_a4[8];
    t = ENTITY(reg_a6)[15].attr.b.flip;
    if (t & 1) {
        ENTITY(reg_a6)[15].attr.b.flip = t & 0xFE;
        goto next_9;
    }
    ENTITY(reg_a6)[15].attr.b.flip = t | 1;
next_9:
    return;
}
