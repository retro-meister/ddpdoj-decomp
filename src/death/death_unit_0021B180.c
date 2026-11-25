#include "common.h"
#include "entity.h"
#include "sdk/ps2sdk.h"

void death_func_0021D4F0(void);
void death_func_0021D520(void);

extern u8 death_D_006901D0[];

s32 death_func_0021B180(void) {
    return reg_a6 == death_D_006901D0;
}

s32 bullet_fire256();
s32 bullet_fire256_direct();
extern u16 D_00259770[];

#define LOOKUP(d) (((d) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(d) & ~1)) : *(u16 *)reg_a1)

void death_func_0021B1A0(void) {
    reg_d0.h[1] = *(u16 *)(reg_a4 + 0xA);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d6.b[0] = 0x10;
    reg_d7.w = 1;
    reg_d5.w = 0;
    reg_d4.w = 0;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_d3.h[1] = LOOKUP(reg_d3.h[0]);
        reg_d3.h[0] = LOOKUP(reg_d3.h[0] + 2);
        reg_d3.w += reg_d5.w;
        bullet_fire256();
        reg_d1.b[0] += reg_d6.b[0];
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

#define LOOKUP(d) (((d) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(d) & ~1)) : *(u16 *)reg_a1)

void death_func_0021B2E0(void) {
    reg_d0.h[1] = *(u16 *)(reg_a4 + 8);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xA);
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d4.h[1] = *(u16 *)(reg_a4 + 0xC);
    reg_d4.h[0] = *(u16 *)(reg_a4 + 0xE);
    reg_d5.w = 0xFA000000;
    reg_d6.b[0] = 0x15;
    reg_d7.w = 0xB;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_d3.h[1] = LOOKUP(reg_d3.h[0]);
        reg_d3.h[0] = LOOKUP(reg_d3.h[0] + 2);
        reg_d3.w += reg_d5.w;
        bullet_fire256_direct();
        reg_d1.b[0] += reg_d6.b[0];
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

#define LOOKUP(d) (((d) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(d) & ~1)) : *(u16 *)reg_a1)

void death_func_0021B420(void) {
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

#define LOOKUP(d) (((d) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(d) & ~1)) : *(u16 *)reg_a1)

void death_func_0021B5F0(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        return;
    }
    *(u8 *)(reg_a4 + 3) = *(u8 *)(reg_a4 + 2);
    reg_d0.h[1] = *(u16 *)(reg_a4 + 0xA);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
    reg_d1.b[0] = *(u8 *)(reg_a4 + 0x17);
    reg_d4.w = 0;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d6.w = 0xFE000000;
    reg_d7.w = 3;
    reg_a1 = (u8 *) D_00259770;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_d3.h[1] = LOOKUP(reg_d3.h[0]);
        reg_d3.h[0] = LOOKUP(reg_d3.h[0] + 2);
        reg_d3.w += reg_d6.w;
        bullet_fire256_direct();
        reg_d1.h[0] += 0x40;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d1.b[0] = *(u8 *)(reg_a4 + 0x16);
    *(u8 *)(reg_a4 + 0x17) += reg_d1.b[0];
}

extern u16 D_00259970[];

#define LOOKUP(d) (((d) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(d) & ~1)) : *(u16 *)reg_a1)

void death_func_0021B770(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
    *(u8 *)(reg_a4 + 7) -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        return;
    }
    *(u8 *)(reg_a4 + 7) = *(u8 *)(reg_a4 + 6);
    reg_d0.h[1] = *(u16 *)(reg_a4 + 0x12);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x14);
    reg_d1.b[0] = *(u8 *)(reg_a4 + 0x1B);
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d4.w = 0;
    reg_d6.w = 0xFE000000;
    reg_d7.w = 3;
    reg_a1 = (u8 *) D_00259970;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_d3.h[1] = LOOKUP(reg_d3.h[0]);
        reg_d3.h[0] = LOOKUP(reg_d3.h[0] + 2);
        reg_d3.w += reg_d6.w;
        bullet_fire256_direct();
        reg_d1.h[0] += 0x40;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d1.b[0] = *(u8 *)(reg_a4 + 0x1A);
    *(u8 *)(reg_a4 + 0x1B) += reg_d1.b[0];
}

s32 rng_next_unsigned();
extern u16 D_00264550[];
extern u32 D_0028D9F4;

void death_func_0021B8F0(void) {
    s32 sum;

    reg_a0 = (u8 *) D_00264550;
    reg_a1 = reg_a4 + 2;
    reg_d0.w = ((u32) D_0028D9F4 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x10);
    sum = *(u8 *)(reg_a4 + 5) + reg_d0.b[0];
    if (sum >= 0xFF) {
        *(u8 *)(reg_a4 + 5) = 0xFF;
        *(u8 *)(reg_a4 + 4) = 0xFF;
    } else {
        *(u8 *)(reg_a4 + 5) = sum;
        *(u8 *)(reg_a4 + 4) += reg_d0.b[0];
    }
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x12);
    *(u16 *)(reg_a4 + 8) += reg_d0.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x14);
    *(u16 *)(reg_a4 + 0xC) += reg_d0.h[0];
    rng_next_unsigned();
    *(u8 *)(reg_a4 + 0x10) = reg_d0.b[0];
    if (*(u8 *)(reg_a6 + 0x11) == 0) {
        *(u8 *)(reg_a4 + 0x11) *= -1;
    }
}

s32 boss_attack_stop();
s32 func_00202A80();
extern u16 D_00262A50_as_u16_a[];
extern u16 g_enemy_signal_2;

void death_func_0021BA40(void) {
    g_enemy_signal_2 = 0;
    func_00202A80();
    if ((s32) reg_d0.h[0] < 0x2000) {
        g_enemy_signal_2 = 1;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] != 0) {
        return;
    }
    *(u8 *)(reg_a4 + 3) = *(u8 *)(reg_a4 + 7);
    reg_a1 = (u8 *) D_00262A50_as_u16_a;
    reg_d1.b[0] = *(u8 *)(reg_a4 + 0x10);
    death_func_0021B2E0();
    reg_d0.b[0] = *(u8 *)(reg_a4 + 0x11);
    *(u8 *)(reg_a4 + 0x10) += reg_d0.b[0];
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        return;
    }
    *(u8 *)(reg_a4 + 5) = *(u8 *)(reg_a4 + 4);
    *(s8 *)(reg_a6 + 0x11) = ~*(s8 *)(reg_a6 + 0x11);
    if ((s32) *(u8 *)(reg_a6 + 0x10) < 0x81) {
        *(u8 *)(reg_a6 + 0x10) += 0xA;
    }
    if ((s32) *(u16 *)(reg_a6 + 0x12) < 2) {
        *(u16 *)(reg_a6 + 0x12) += 1;
    }
    if ((s32) *(u16 *)(reg_a6 + 0x14) < 3) {
        *(u16 *)(reg_a6 + 0x14) += 1;
    }
    if (death_func_0021B180()) {
        reg_d0.w = 0x10;
    } else {
        reg_d0.w = 0x11;
    }
    boss_attack_stop();
}

extern u16 D_00264560[];
extern u32 D_0028D9F8;

void death_func_0021BBB0(void) {
    reg_a0 = (u8 *) D_00264560;
    reg_a1 = reg_a4 + 2;
    reg_d0.w = ((u32) D_0028D9F8 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    *(u16 *)(reg_a4 + 0xC) = 0x404;
}

s32 enemy_switch_target_player();
s32 direction256_between();
extern u16 g_bullets_blocked;
extern u16 D_0029F1F0_as_u16_a[];
extern u16 D_0029F260_as_u16_a[];

void death_func_0021BC30(arg0, arg1)
    u8 *arg0;
    s16 *arg1;
{
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
                reg_a0 = (u8 *)(D_0029F260_as_u16_a);
                reg_a1 = (u8 *)(D_0029F1F0_as_u16_a);
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
                death_func_0021B420();
                reg_d6.b[0] = 0xB7;
                reg_d1.h[0] = reg_d7.h[0];
                temp_a2 = *(u8 *)(reg_a4 + 5);
                reg_d6.b[0] -= temp_a2;
                reg_d6.b[0] *= -1;
                reg_d1.b[0] += reg_d6.b[0];
                reg_d6.h[0] = 0xFFEA;
                death_func_0021B420();
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
        if (death_func_0021B180()) {
            reg_d0.w = 0x12;
        } else {
            reg_d0.w = 0x13;
        }
        boss_attack_stop();
    }
}

s32 rng_next_masked();
s32 func_00201230();
extern u16 D_00264570[];
extern u32 D_0028D9FC;

void death_func_0021BE80(void) {
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
    reg_d0.b[0] = ENTITY(reg_a6)->look.b.palette;
    *(u8 *)(reg_a4 + 7) += reg_d0.b[0];
    *(u8 *)(reg_a4 + 6) += reg_d0.b[0];
}

s32 velocity_from_dir256();
extern s16 D_00262A50[];
extern u16 g_enemy_signal_1;
extern u16 g_enemy_signal_0;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];

void death_func_0021BFC0(void) {
    s16 *t1;
    u8 t2;
    u8 t3;

    if (death_func_0021B180()) {
        reg_d0.w = 0x14;
    } else {
        reg_d0.w = 0x15;
    }
    boss_attack_stop();
    if (g_bullets_blocked != 0) {
        death_func_0021BE80();
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 9);
        reg_d0.b[0] = *(u8 *)(reg_a4 + 5);
        if (*(u8 *)(reg_a4 + 4) == reg_d0.b[0]) {
            reg_a0 = (u8 *)(D_0029F260);
            reg_a1 = (u8 *)(D_0029F1F0);
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
                t2 = ENTITY(reg_a6)->look.b.palette;
                if ((s32) t2 < 4) {
                    ENTITY(reg_a6)->look.b.palette = (u8) (t2 + 2);
                }
                if (death_func_0021B180()) {
                    reg_d0.w = 0x14;
                } else {
                    reg_d0.w = 0x15;
                }
                boss_attack_stop();
            }
        }
    }
}

extern u16 D_00264590[];
extern u32 D_0028DA00;

void death_func_0021C430(void) {
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
    *(s16 *)(reg_a6 + 0x1e) = 5;
    *(s8 *)(reg_a6 + 0x1c) = 8;
}

extern u16 D_00259870[];
extern s16 g_enemy_signal_1_as_s16;
extern s16 g_enemy_signal_0_as_s16;

void death_func_0021C500(void) {
    u8 *p;
    u8 t;

    death_func_0021B5F0();
    p = reg_a4 + 0x1C;
    switch (*(u16 *)p) { case 0: goto next_0; }
    *(u16 *)p -= 1;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if ((u32)reg_tmp.w >= 0x1F800U) goto next_2;
next_0:
    death_func_0021B770();
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
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1e);
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
    reg_tmp.b[0] = ENTITY(reg_a6)->attr.b.palette;
    ENTITY(reg_a6)->attr.b.palette -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_9;
    ENTITY(reg_a6)->attr.b.palette = 8;
    if (ENTITY(reg_a6)->attr.b.flip & 1) goto next_4;
    if ((s8)reg_a4[0x18] == -6) goto next_3;
    reg_a4[0x18] -= 1;
    goto next_7;
next_3:
    if (*(u16 *)(reg_a6 + 0x1e) == 5) goto next_8;
    *(u16 *)(reg_a6 + 0x1e) += 1;
    goto next_7;
next_4:
    if (reg_a4[0x18] == 6) goto next_5;
    reg_a4[0x18] += 1;
    goto next_7;
next_5:
    if ((s16)*(u16 *)(reg_a6 + 0x1e) == -5) goto next_8;
    *(u16 *)(reg_a6 + 0x1e) -= 1;
next_7:
    return;
next_8:
    reg_tmp.b[0] = reg_a4[9];
    reg_a4[9] -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_9;
    reg_a4[9] = reg_a4[8];
    t = ENTITY(reg_a6)->attr.b.flip;
    if (t & 1) {
        ENTITY(reg_a6)->attr.b.flip = t & 0xFE;
        goto next_9;
    }
    ENTITY(reg_a6)->attr.b.flip = t | 1;
next_9:
    return;
}

extern u16 D_00264530[];
extern u32 D_0028D9EC;

void death_func_0021C8A0(void) {
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
    reg_d0.b[0] = ENTITY(reg_a6)->look.b.size;
    *(u8 *)(reg_a4 + 5) += reg_d0.b[0];
    *(u8 *)(reg_a4 + 4) += reg_d0.b[0];
}

s32 func_00201100();

void death_func_0021C9A0(void) {
    s16 *t1;
    s16 *t2;
    u16 t3;
    u16 t4;
    u8 t5;
    u8 t6;

    if (g_bullets_blocked != 0) {
        death_func_0021C8A0();
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 7);
        reg_a0 = (u8 *)(D_0029F260);
        reg_a1 = (u8 *)(D_0029F1F0);
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
            reg_d1.w = (u32) t3;
            if ((s32) reg_d0.h[0] <= (s32) reg_d2.h[0]) {
                direction256_between();
                reg_d0.w = 0x80013;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d3.w = 0;
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
            death_func_0021C8A0();
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            t5 = ENTITY(reg_a6)->look.b.size;
            if ((s32) t5 < 0x28) {
                ENTITY(reg_a6)->look.b.size = (u8) (t5 + 0x14);
            }
            if (death_func_0021B180()) {
                reg_d0.w = 0x18;
            } else {
                reg_d0.w = 0x19;
            }
            boss_attack_stop();
        }
    }
}

extern u16 D_00264800[];
extern u32 D_0028DA14;
extern u16 *reg_a0_as_u16_p;
extern u16 *reg_a1_as_u16_p;
extern s32 reg_a4_as_s32;

void death_func_0021CE10(void) {
    reg_a0_as_u16_p = D_00264800;
    reg_a1_as_u16_p = (u16 *)(reg_a4_as_s32 + 2);
    reg_d0.w = ((u32) D_0028DA14 >> 1) - 1;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

s32 func_0020ED00();
extern u8 D_00262A50_as_u8_a[];

void death_func_0021CE90(void) {
    u32 temp_a0;
    u8 temp_v1;
    u8 temp_v1_2;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        reg_d0.b[0] = *(u8 *)(reg_a4 + 9);
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
        if ((u32) reg_tmp.w < 0xE000U) {
            reg_d0.b[0] -= 2;
            func_0020ED00();
        }
        *(u8 *)(reg_a4 + 3) = (u8) reg_d0.b[0];
        reg_a1 = (u8 *)D_00262A50_as_u8_a;
        reg_d1.b[0] = *(u8 *)(reg_a4 + 0x12);
        death_func_0021B1A0();
        reg_d1.b[0] = *(u8 *)(reg_a4 + 0x12);
        reg_d1.b[0] += 0x40;
        death_func_0021B1A0();
        reg_d1.b[0] = *(u8 *)(reg_a4 + 0x12);
        reg_d1.b[0] += 0x80;
        death_func_0021B1A0();
        reg_d1.b[0] = *(u8 *)(reg_a4 + 0x12);
        reg_d1.b[0] += 0xC0;
        death_func_0021B1A0();
        reg_d0.b[0] = *(u8 *)(reg_a4 + 0x13);
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
        if ((u32) reg_tmp.w < 0xE000U) {
            reg_d0.b[0] = (s8) reg_d0.b[0] * 2;
        }
        *(u8 *)(reg_a4 + 0x12) += reg_d0.b[0];
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 8);
            *(u8 *)(reg_a4 + 0x13) *= -1;
            temp_a0 = *(u16 *)(reg_a4 + 0xA);
            if ((s16)(temp_a0) < 6) {
                *(u16 *)(reg_a4 + 0xA) = (u16) (temp_a0 + 2);
            }
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
                temp_v1 = *(u8 *)(reg_a4 + 9);
                if ((s32) temp_v1 > 7) {
                    *(u8 *)(reg_a4 + 9) = (u8) (temp_v1 - 2);
                    if ((s32) *(u8 *)(reg_a4 + 9) < 8) {
                        func_0020ED00();
                    }
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

void death_func_0021D0F0(void) {
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

void death_func_0021D210(void) {
    reg_a0_as_u16_p = D_00264390;
    reg_a1_as_u16_p = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9E4 >> 1) - 1;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x1E8);
    *(u16 *)(reg_a4 + 8) += reg_d0.h[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1E7);
    *(u8 *)(reg_a4 + 5) += reg_d0.b[0];
    *(u8 *)(reg_a4 + 4) += reg_d0.b[0];
}

s32 func_001EBA00();
extern u8 death_D_00269860[];

void death_func_0021D2E0(void) {
    s16 *temp_v1;

    if (g_bullets_blocked != 0) {
        func_001EBA00();
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 7);
        reg_a0 = (u8 *)(D_0029F260);
        reg_a1 = (u8 *)(D_0029F1F0);
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
            reg_a3 = (u8 *)death_D_00269860;
            reg_d4.h[0] = *(u16 *)(reg_a4 + 0xE);
            reg_a3 += reg_d4.h[0];
            reg_d3.h[1] = *(u16 *)reg_a3;
            reg_d3.h[0] = *(u16 *)(reg_a3 + 2);
            reg_d4.w = 0;
            death_func_0021D0F0();
            reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xE);
            *(u16 *)(reg_a4 + 0xE) -= 4;
            if ((s32) reg_tmp.h[0] < 4) {
                *(u16 *)(reg_a4 + 0xE) = 0x14U;
            }
        }
        enemy_switch_target_player();
    }
}


void death_func_0021D4B0(void) {
    if (death_func_0021B180()) {
        death_func_0021D520();
    } else {
        death_func_0021D4F0();
    }
}

extern u16 death_D_006901B2[];
extern u16 death_D_006901B4[];
extern u16 death_D_006901F2[];
extern u16 death_D_006901F4[];

void death_func_0021D4F0(void) {
    death_D_006901F2[0] = death_D_006901B2[0];
    death_D_006901F4[0] = death_D_006901B4[0];
}

extern u16 death_D_0068FFB2[];
extern u16 death_D_0068FFB4[];
extern u16 death_D_006901D2[];
extern u16 death_D_006901D4[];

void death_func_0021D520(void) {
    death_D_006901D2[0] = death_D_0068FFB2[0];
    death_D_006901D4[0] = death_D_0068FFB4[0];
}

extern char death_D_0028E398[];

void death_func_0021D550(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901D0;
    death_func_0021D4B0();
    death_func_0021B8F0();
    reg_a6 = save_a6;
    printf(death_D_0028E398);
}


void death_func_0021D5A0(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901D0;
    death_func_0021D4B0();
    death_func_0021BA40();
    reg_a6 = save_a6;
}

extern char death_D_0028E3A0[];

void death_func_0021D5E0(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901D0;
    death_func_0021D4B0();
    death_func_0021BBB0();
    reg_a6 = save_a6;
    printf(death_D_0028E3A0);
}


void death_func_0021D630(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901D0;
    death_func_0021D4B0();
    death_func_0021BC30();
    reg_a6 = save_a6;
}

extern char death_D_0028E3A8[];

void death_func_0021D670(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901D0;
    death_func_0021D4B0();
    death_func_0021BE80();
    reg_a6 = save_a6;
    printf(death_D_0028E3A8);
}


void death_func_0021D6C0(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901D0;
    death_func_0021D4B0();
    death_func_0021BFC0();
    reg_a6 = save_a6;
}

extern char death_D_0028E3B0[];

void death_func_0021D700(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901D0;
    death_func_0021D4B0();
    death_func_0021C430();
    reg_a6 = save_a6;
    printf(death_D_0028E3B0);
}


void death_func_0021D750(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901D0;
    death_func_0021D4B0();
    death_func_0021C500();
    reg_a6 = save_a6;
}

extern char death_D_0028E3C0[];

void death_func_0021D790(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901D0;
    death_func_0021D4B0();
    death_func_0021C8A0();
    reg_a6 = save_a6;
    printf(death_D_0028E3C0);
}


void death_func_0021D7E0(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901D0;
    death_func_0021D4B0();
    death_func_0021C9A0();
    reg_a6 = save_a6;
}

extern char death_D_0028E3D0[];

void death_func_0021D820(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901D0;
    death_func_0021D4B0();
    death_func_0021CE10();
    reg_a6 = save_a6;
    printf(death_D_0028E3D0);
}


void death_func_0021D870(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901D0;
    death_func_0021D4B0();
    death_func_0021CE90();
    reg_a6 = save_a6;
}

extern char death_D_0028E3E0[];

void death_func_0021D8B0(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901D0;
    death_func_0021D4B0();
    death_func_0021D210();
    reg_a6 = save_a6;
    printf(death_D_0028E3E0);
}


void death_func_0021D900(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901D0;
    death_func_0021D4B0();
    death_func_0021D2E0();
    reg_a6 = save_a6;
}

extern char death_D_0028E3F0[];
extern u8 death_D_006901F0[];

void death_func_0021D940(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901F0;
    death_func_0021D4B0();
    death_func_0021B8F0();
    reg_a6 = save_a6;
    printf(death_D_0028E3F0);
}

void death_func_0021D990(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901F0;
    death_func_0021D4B0();
    death_func_0021BA40();
    reg_a6 = save_a6;
}

extern char death_D_0028E3F8[];

void death_func_0021D9D0(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901F0;
    death_func_0021D4B0();
    death_func_0021BBB0();
    reg_a6 = save_a6;
    printf(death_D_0028E3F8);
}

void death_func_0021DA20(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901F0;
    death_func_0021D4B0();
    death_func_0021BC30();
    reg_a6 = save_a6;
}

extern char death_D_0028E400[];

void death_func_0021DA60(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901F0;
    death_func_0021D4B0();
    death_func_0021BE80();
    reg_a6 = save_a6;
    printf(death_D_0028E400);
}

void death_func_0021DAB0(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901F0;
    death_func_0021D4B0();
    death_func_0021BFC0();
    reg_a6 = save_a6;
}

extern char death_D_0028E408[];

void death_func_0021DAF0(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901F0;
    death_func_0021D4B0();
    death_func_0021C430();
    reg_a6 = save_a6;
    printf(death_D_0028E408);
}

void death_func_0021DB40(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901F0;
    death_func_0021D4B0();
    death_func_0021C500();
    reg_a6 = save_a6;
}

extern char death_D_0028E418[];

void death_func_0021DB80(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901F0;
    death_func_0021D4B0();
    death_func_0021C8A0();
    reg_a6 = save_a6;
    printf(death_D_0028E418);
}

void death_func_0021DBD0(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901F0;
    death_func_0021D4B0();
    death_func_0021C9A0();
    reg_a6 = save_a6;
}

extern char death_D_0028E428[];

void death_func_0021DC10(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901F0;
    death_func_0021D4B0();
    death_func_0021CE10();
    reg_a6 = save_a6;
    printf(death_D_0028E428);
}

void death_func_0021DC60(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901F0;
    death_func_0021D4B0();
    death_func_0021CE90();
    reg_a6 = save_a6;
}

extern char death_D_0028E438[];

void death_func_0021DCA0(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901F0;
    death_func_0021D4B0();
    death_func_0021D210();
    reg_a6 = save_a6;
    printf(death_D_0028E438);
}

void death_func_0021DCF0(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = death_D_006901F0;
    death_func_0021D4B0();
    death_func_0021D2E0();
    reg_a6 = save_a6;
}
