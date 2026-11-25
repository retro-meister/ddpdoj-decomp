#include "common.h"
#include "entity.h"

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

void func_001EE0F0(void) {
    s32 bullet_fire256();
    u16 temp_a1;
    u16 temp_a1_2;
    u32 temp_a0;

    reg_a2 = (u8 *)D_00264660;
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
    bullet_fire256();
}

void func_001EE1C0(void) {
    s32 bullet_fire256();
    u16 temp_a1;
    u16 temp_a1_2;
    u32 temp_a0;

    reg_a2 = (u8 *)D_00264660;
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
    bullet_fire256();
}

void func_001EE290(void) {
    s32 bullet_fire256();
    u16 temp_a1;
    u16 temp_a1_2;
    u32 temp_a0;

    reg_a2 = (u8 *)D_00264660;
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
    bullet_fire256();
    reg_d1.h[0] += 0x18;
    bullet_fire256();
    reg_d1.h[0] -= 0x30;
    bullet_fire256();
}

s32 rng_next();                            /* extern */

void func_001EE390(void) {
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

extern u16 D_002645E0[];
extern u32 D_0028DA04;

void stage5_boss_fire_loop1_form1_arm_guns_aimed_start(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(D_002645E0);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028DA04 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    func_001EE390();
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
s32 enemy_switch_target_player();
extern u16 D_00262A50_as_u16_a[];
extern u16 D_00264600_as_u16_a[];
extern u16 D_00264620[];

void stage5_boss_fire_loop1_form1_arm_guns_aimed(void) {
    s32 bullet_fire256();
    u32 t1;
    u32 t2;
    u32 t3;
    u8 t4;
    u8 t5;
    u8 t6;

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
        reg_a3 = (u8 *)(D_00264600_as_u16_a);
        reg_d1.h[0] = ENTITY(reg_a6)[1].move.h;
        reg_d2.b[0] = *(u8 *)(reg_a4 + 0x1B);
        func_001EE290();
        reg_d1.h[0] = ENTITY(reg_a6)[2].move.h;
        reg_d2.b[0] = *(u8 *)(reg_a4 + 0x1A);
        func_001EE1C0();
        reg_d1.h[0] = ENTITY(reg_a6)[3].move.h;
        reg_d2.b[0] = *(u8 *)(reg_a4 + 0x1D);
        func_001EE0F0();
        reg_d1.h[0] = ENTITY(reg_a6)[4].move.h;
        reg_d2.b[0] = *(u8 *)(reg_a4 + 0x1C);
        func_001EE290();
        reg_d1.h[0] = ENTITY(reg_a6)[5].move.h;
        reg_d2.b[0] = *(u8 *)(reg_a4 + 0x1F);
        func_001EE1C0();
        reg_d1.h[0] = ENTITY(reg_a6)[6].move.h;
        reg_d2.b[0] = *(u8 *)(reg_a4 + 0x1E);
        func_001EE0F0();
        if (*(u8 *)(reg_a4 + 5) == 0) {
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_a1 = (u8 *)(D_00262A50_as_u16_a);
            reg_a3 = (u8 *)(D_00264620);
            reg_d6.w = 5;
            do {
                reg_d7.w = 6;
                reg_d0.h[0] = ENTITY(reg_a6)[14].hp.h;
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
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            func_001EE390();
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
            enemy_switch_target_player();
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
                *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
                t4 = ENTITY(reg_a6)[14].offset_y.b[1];
                if ((s32) t4 < 6) {
                    ENTITY(reg_a6)[14].offset_y.b[1] = (u8) (t4 + 2);
                }
                t5 = ENTITY(reg_a6)[14].offset_x.b[1];
                if ((s32) t5 < 2) {
                    ENTITY(reg_a6)[14].offset_x.b[1] = (u8) (t5 + 1);
                }
                t6 = ENTITY(reg_a6)[14].offset_x.b[0];
                if ((s32) t6 < 0x20) {
                    ENTITY(reg_a6)[14].offset_x.b[0] = (u8) (t6 + 8);
                }
                t2 = ENTITY(reg_a6)[14].draw.h;
                if ((s16)(t2) < 0x10) {
                    ENTITY(reg_a6)[14].draw.h = (u16) (t2 + 1);
                }
                t3 = ENTITY(reg_a6)[14].hp.h;
                if ((s16)(t3) < 8) {
                    ENTITY(reg_a6)[14].hp.h = (u16) (t3 + 2);
                }
                reg_d0.w = 0;
                boss_attack_stop();
            }
        }
    }
}

s32 rng_next_unsigned();
s32 func_00201270();
extern u16 D_00264760[];
extern u32 D_0028DA08;

void stage5_boss_fire_loop1_form1_mouth_start(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(D_00264760);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028DA08 >> 1) - 1;
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
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 7);
        reg_d0.b[0] = *(u8 *)(reg_a4 + 5);
        reg_d0.h[0] &= 0xF;
        if (reg_d0.h[0] == 0) {
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
                reg_d0.h[1] = *(u16 *)(reg_a4 + 0xA);
                reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
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
            reg_d0.b[0] = *(u8 *)(reg_a4 + 5);
            if (*(u8 *)(reg_a4 + 4) == reg_d0.b[0]) {
                reg_d1.b[0] += 0x40;
                *(u8 *)(reg_a4 + 9) = (u8) reg_d1.b[0];
                reg_d1.b[0] += 0x80;
                reg_d1.b[0] *= -1;
                *(u8 *)(reg_a4 + 8) = (u8) reg_d1.b[0];
            }
            reg_d1.b[0] = *(u8 *)(reg_a4 + 9);
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xE);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x10);
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d3.w = 0xF2C0FC00;
            reg_d4.w = 0;
            bullet_fire256();
            reg_d1.b[0] += 0x20;
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0x12);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x14);
            bullet_fire256();
            reg_d1.b[0] += 0x60;
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0x16);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x18);
            bullet_fire256();
            if (*(u8 *)(reg_a4 + 5) & 1) {
                reg_d1.b[0] += 0x20;
                reg_d0.w = 0x90003;
                bullet_fire256();
            }
            reg_d1.b[0] = *(u8 *)(reg_a4 + 8);
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xE);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x10);
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d3.h[0] = 0x400;
            reg_d4.w = 0;
            bullet_fire256();
            reg_d1.b[0] += 0x20;
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0x12);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x14);
            bullet_fire256();
            reg_d1.b[0] += 0x60;
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0x16);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x18);
            bullet_fire256();
            if (*(u8 *)(reg_a4 + 5) & 1) {
                reg_d0.w = 0x90003;
                bullet_fire256();
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
            if ((s16)(temp_v1) < 8) {
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

void func_001EF090(void) {
    u16 temp_a2;

    reg_a2 = D_00264660;
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

extern u16 D_00264780[];
extern u32 D_0028DA0C;
extern u16 *reg_a0_as_u16_p;
extern u16 *reg_a1_as_u16_p;

void stage5_boss_fire_loop1_form1_arm_guns_fixed_start(void) {
    reg_a0_as_u16_p = D_00264780;
    reg_a1_as_u16_p = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028DA0C >> 1) - 1;
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
extern u8 D_00264600[];

void stage5_boss_fire_loop1_form1_arm_guns_fixed(void) {
    s32 bullet_fire256();
    s16 *temp_a0;
    s16 *var_a1;
    u16 temp_a0_2;
    u16 temp_v0;
    u16 temp_v0_2;

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
        if (*(u8 *)(reg_a4 + 5) & 2) {
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
            func_001EF090();
            reg_d1.h[0] = 0x70;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x15);
            bullet_fire256();
            reg_d0.w += 0xD0000;
            reg_d1.h[0] = 0xC0;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x15);
            bullet_fire256();
            reg_d1.h[0] = ENTITY(reg_a6)[2].move.h;
            func_001EF090();
            reg_d1.h[0] = 0x7C;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x14);
            bullet_fire256();
            reg_d0.w += 0xD0000;
            reg_d1.h[0] = 0xB8;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x14);
            bullet_fire256();
            reg_d1.h[0] = ENTITY(reg_a6)[3].move.h;
            func_001EF090();
            reg_d1.h[0] = 0x98;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x17);
            bullet_fire256();
            reg_d0.w += 0xD0000;
            reg_d1.h[0] = 0xB0;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x17);
            bullet_fire256();
            reg_d1.h[0] = ENTITY(reg_a6)[4].move.h;
            func_001EF090();
            reg_d1.h[0] = 0x90;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x16);
            bullet_fire256();
            reg_d0.w += 0xD0000;
            reg_d1.h[0] = 0x40;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x16);
            bullet_fire256();
            reg_d1.h[0] = ENTITY(reg_a6)[5].move.h;
            func_001EF090();
            reg_d1.h[0] = 0x84;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x19);
            bullet_fire256();
            reg_d0.w += 0xD0000;
            reg_d1.h[0] = 0x48;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x19);
            bullet_fire256();
            reg_d1.h[0] = ENTITY(reg_a6)[6].move.h;
            func_001EF090();
            reg_d1.h[0] = 0x68;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x18);
            bullet_fire256();
            reg_d0.w += 0xD0000;
            reg_d1.h[0] = 0x50;
            reg_d1.b[0] += *(u8 *)(reg_a4 + 0x18);
            bullet_fire256();
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

void func_001EF990(void) {
    void bullet_fire256(void);
    bullet_fire256();
}

extern u16 D_002647A0[];
extern u32 D_0028DA10;

void stage5_boss_fire_loop1_form1_horn_start(void) {
    reg_a0_as_u16_p = D_002647A0;
    reg_a1_as_u16_p = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028DA10 >> 1) - 1;
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
#ifndef DEATH_LABEL
    *(u8 *)(reg_a4 + 3) += 2;
#endif
}

extern u16 D_002647C0[];

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

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 9);
        reg_d0.b[0] = *(u8 *)(reg_a4 + 5);
        temp_a0 = *(u8 *)(reg_a4 + 4);
        if (temp_a0 == reg_d0.b[0]) {
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
            reg_a3 = (u8 *)(D_002647C0);
            temp_a1 = *(u16 *)(reg_a4 + 0xE);
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
            reg_d5.b[0] = *(u8 *)(reg_a4 + 0x15);
            reg_d4.b[0] = (u8) (temp_a0_5 >> reg_d5.b[0]);
            reg_d1.b[0] += reg_d4.b[0];
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xA);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
            reg_d4.w = 0;
            reg_d6.b[0] = *(u8 *)(reg_a4 + 7);
            func_001EF990();
            reg_d1.w = temp_s0;
            reg_d3.h[1] = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d3.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d4.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            temp_a0_6 = (s8) reg_d4.b[0];
            reg_d5.b[0] = *(u8 *)(reg_a4 + 0x15);
            reg_d4.b[0] = (u8) (temp_a0_6 >> reg_d5.b[0]);
            reg_d1.b[0] += reg_d4.b[0];
            reg_d4.w = 0;
            reg_d6.b[0] = *(u8 *)(reg_a4 + 7);
            reg_d6.b[0] = ~(s8) reg_d6.b[0];
            func_001EF990();
            reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xE);
            *(u16 *)(reg_a4 + 0xE) -= 0xC;
            if ((s32) reg_tmp.h[0] < 0xC) {
                *(u16 *)(reg_a4 + 0xE) = 0x30U;
            }
        }
        *(u16 *)(reg_a4 + 0xA) += 1;
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            enemy_switch_target_player();
            temp_v1 = *(u8 *)(reg_a4 + 4);
            if ((s32) temp_v1 < 0x1E) {
                *(u8 *)(reg_a4 + 4) = (u8) (temp_v1 + 0xF);
            }
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 8);
#ifndef DEATH_LABEL
            *(u8 *)(reg_a4 + 3) += 4;
#endif
            *(u16 *)(reg_a4 + 0x12) += 1;
            *(u16 *)(reg_a4 + 0xA) = (u16) *(u16 *)(reg_a4 + 0x12);
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
                *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
                temp_v0 = ENTITY(reg_a6)[14].hit_x_minus.b[1];
                if ((s32) temp_v0 < 2) {
                    ENTITY(reg_a6)[14].hit_x_minus.b[1] = (u8) (temp_v0 + 1);
                }
                temp_v0_2 = ENTITY(reg_a6)[9].misc.h;
                if ((s32) temp_v0_2 < 6) {
                    ENTITY(reg_a6)[9].misc.h = (u16) (temp_v0_2 + 1);
                }
                temp_v0_3 = ENTITY(reg_a6)[14].hit_x_minus.b[0];
                if ((s32) temp_v0_3 < 0x10) {
                    ENTITY(reg_a6)[14].hit_x_minus.b[0] = (u8) (temp_v0_3 + 4);
                }
                reg_d0.w = 3;
                boss_attack_stop();
            }
        }
    }
}

void func_001EFF10(void) {
    s32 bullet_fire256();
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
extern s32 reg_a4_as_s32;

void stage5_boss_fire_loop1_form1_rage_start(void) {
    reg_a0_as_u16_p = D_00264800;
    reg_a1_as_u16_p = (u16 *)(reg_a4_as_s32 + 2);
    reg_d0.w = ((u32) D_0028DA14 >> 1) - 1;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}
