#include "common.h"
#include "entity.h"
#include "stage5_boss.h"
#include "sdk/ps2sdk.h"

void twin_boss_second_fire_point_follow(void);
void twin_boss_first_fire_point_follow(void);

extern u8 g_twin_boss_first_fire_point[];

s32 twin_boss_fire_point_is_first(void) {
    return reg_a6 == g_twin_boss_first_fire_point;
}

s32 bullet_fire256();
s32 bullet_fire256_direct();
extern u16 g_direction64_offsets_166[];

#define LOOKUP(d) (((d) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(d) & ~1)) : *(u16 *)reg_a1)

void twin_boss_form1_rage_fire(void) {
    reg_d0.h[1] = FORM1_RAGE(reg_a4)->shots.speed;
    reg_d0.h[0] = FORM1_RAGE(reg_a4)->shots.bullet;
    reg_tmp.h[1] = STAGE5_BOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE5_BOSS(reg_a5)->hp[1];
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

void twin_boss_attack_b_fire(void) {
    reg_d0.h[1] = FORM3_B(reg_a4)->shots.speed;
    reg_d0.h[0] = FORM3_B(reg_a4)->shots.bullet;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d4.h[1] = FORM3_B(reg_a4)->child.speed;
    reg_d4.h[0] = FORM3_B(reg_a4)->child.bullet;
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

void twin_boss_attack_c_fire(void) {
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

#define LOOKUP(d) (((d) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(d) & ~1)) : *(u16 *)reg_a1)

void twin_boss_rage_first_volley(void) {
    reg_tmp.b[0] = FORM3_RAGE(reg_a4)->shot[0].t.count;
    FORM3_RAGE(reg_a4)->shot[0].t.count -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        return;
    }
    FORM3_RAGE(reg_a4)->shot[0].t.count = FORM3_RAGE(reg_a4)->shot[0].t.reload;
    reg_d0.h[1] = FORM3_RAGE(reg_a4)->volley[0].speed;
    reg_d0.h[0] = FORM3_RAGE(reg_a4)->volley[0].bullet;
    reg_d1.b[0] = FORM3_RAGE(reg_a4)->aim[0].direction;
    reg_d4.w = 0;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d6.w = 0xFE000000;
    reg_d7.w = 3;
    reg_a1 = (u8 *) g_direction64_offsets_166;
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
    reg_d1.b[0] = FORM3_RAGE(reg_a4)->aim[0].turn;
    FORM3_RAGE(reg_a4)->aim[0].direction += reg_d1.b[0];
}

extern u16 g_direction64_offsets_432[];

#define LOOKUP(d) (((d) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(d) & ~1)) : *(u16 *)reg_a1)

void twin_boss_rage_third_volley(void) {
    reg_tmp.b[0] = FORM3_RAGE(reg_a4)->shot[2].t.count;
    FORM3_RAGE(reg_a4)->shot[2].t.count -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        return;
    }
    FORM3_RAGE(reg_a4)->shot[2].t.count = FORM3_RAGE(reg_a4)->shot[2].t.reload;
    reg_d0.h[1] = FORM3_RAGE(reg_a4)->volley[2].speed;
    reg_d0.h[0] = FORM3_RAGE(reg_a4)->volley[2].bullet;
    reg_d1.b[0] = FORM3_RAGE(reg_a4)->aim[2].direction;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d4.w = 0;
    reg_d6.w = 0xFE000000;
    reg_d7.w = 3;
    reg_a1 = (u8 *) g_direction64_offsets_432;
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
    reg_d1.b[0] = FORM3_RAGE(reg_a4)->aim[2].turn;
    FORM3_RAGE(reg_a4)->aim[2].direction += reg_d1.b[0];
}

s32 rng_next_unsigned();
extern u16 D_00264550[];
extern u32 D_0028D9F4;

void twin_boss_fire_attack_b_start(void) {
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
    sum = FORM3_B(reg_a4)->burst.t.count + reg_d0.b[0];
    if (sum >= 0xFF) {
        FORM3_B(reg_a4)->burst.t.count = 0xFF;
        FORM3_B(reg_a4)->burst.t.reload = 0xFF;
    } else {
        FORM3_B(reg_a4)->burst.t.count = sum;
        FORM3_B(reg_a4)->burst.t.reload += reg_d0.b[0];
    }
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x12);
    FORM3_B(reg_a4)->shots.speed += reg_d0.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x14);
    FORM3_B(reg_a4)->child.speed += reg_d0.h[0];
    rng_next_unsigned();
    FORM3_B(reg_a4)->direction = reg_d0.b[0];
    if (*(u8 *)(reg_a6 + 0x11) == 0) {
        FORM3_B(reg_a4)->turn *= -1;
    }
}

s32 boss_attack_stop();
s32 nearest_player_distance();
extern u16 stage1_midboss_direction64_offsets_166[];
extern u16 g_enemy_signal_2;

void twin_boss_fire_attack_b(void) {
    g_enemy_signal_2 = 0;
    nearest_player_distance();
    if ((s32) reg_d0.h[0] < 0x2000) {
        g_enemy_signal_2 = 1;
    }
    reg_tmp.b[0] = FORM3_B(reg_a4)->shot.t.count;
    FORM3_B(reg_a4)->shot.t.count -= 1;
    if (reg_tmp.b[0] != 0) {
        return;
    }
    FORM3_B(reg_a4)->shot.t.count = FORM3_B(reg_a4)->shot_interval;
    reg_a1 = (u8 *) stage1_midboss_direction64_offsets_166;
    reg_d1.b[0] = FORM3_B(reg_a4)->direction;
    twin_boss_attack_b_fire();
    reg_d0.b[0] = FORM3_B(reg_a4)->turn;
    FORM3_B(reg_a4)->direction += reg_d0.b[0];
    reg_tmp.b[0] = FORM3_B(reg_a4)->burst.t.count;
    FORM3_B(reg_a4)->burst.t.count -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        return;
    }
    FORM3_B(reg_a4)->burst.t.count = FORM3_B(reg_a4)->burst.t.reload;
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
    if (twin_boss_fire_point_is_first()) {
        reg_d0.w = 0x10;
    } else {
        reg_d0.w = 0x11;
    }
    boss_attack_stop();
}

extern u16 D_00264560[];
extern u32 D_0028D9F8;

void twin_boss_fire_attack_c_start(void) {
    reg_a0 = (u8 *) D_00264560;
    reg_a1 = reg_a4 + 2;
    reg_d0.w = ((u32) D_0028D9F8 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    FORM3_C(reg_a4)->other_0C.h = 0x404;
}

s32 enemy_switch_target_player();
s32 direction256_between();
extern u16 g_bullets_blocked;
extern s16 g_player2[];
extern s16 g_player1[];

void twin_boss_fire_attack_c(arg0, arg1)
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
                twin_boss_attack_c_fire();
                reg_d6.b[0] = 0xB7;
                reg_d1.h[0] = reg_d7.h[0];
                temp_a2 = FORM3_C(reg_a4)->burst.t.count;
                reg_d6.b[0] -= temp_a2;
                reg_d6.b[0] *= -1;
                reg_d1.b[0] += reg_d6.b[0];
                reg_d6.h[0] = 0xFFEA;
                twin_boss_attack_c_fire();
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
        if (twin_boss_fire_point_is_first()) {
            reg_d0.w = 0x12;
        } else {
            reg_d0.w = 0x13;
        }
        boss_attack_stop();
    }
}

s32 rng_next_masked();
s32 rng_next_0_to_2();
extern u16 D_00264570[];
extern u32 D_0028D9FC;

void twin_boss_fire_spiral_start(void) {
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
    reg_d0.b[0] = ENTITY(reg_a6)->look.b.palette;
    FORM3_D(reg_a4)->rounds.t.count += reg_d0.b[0];
    FORM3_D(reg_a4)->rounds.t.reload += reg_d0.b[0];
}

s32 velocity_from_dir256();

extern u16 g_enemy_signal_1;
extern u16 g_enemy_signal_0;
extern s16 g_player2[];
extern s16 g_player1[];

void twin_boss_fire_spiral(void) {
    s16 *t1;
    u8 t2;
    u8 t3;

    if (twin_boss_fire_point_is_first()) {
        reg_d0.w = 0x14;
    } else {
        reg_d0.w = 0x15;
    }
    boss_attack_stop();
    if (g_bullets_blocked != 0) {
        twin_boss_fire_spiral_start();
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
                t2 = ENTITY(reg_a6)->look.b.palette;
                if ((s32) t2 < 4) {
                    ENTITY(reg_a6)->look.b.palette = (u8) (t2 + 2);
                }
                if (twin_boss_fire_point_is_first()) {
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

void twin_boss_fire_rage_start(void) {
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
    *(s16 *)(reg_a6 + 0x1e) = 5;
    *(s8 *)(reg_a6 + 0x1c) = 8;
}

extern u16 g_direction64_offsets_2CC[];

void twin_boss_fire_rage(void) {
    u8 *p;
    u8 t;

    twin_boss_rage_first_volley();
    p = reg_a4 + 0x1C;
    switch (*(u16 *)p) { case 0: goto next_0; }
    *(u16 *)p -= 1;
    reg_tmp.h[1] = STAGE5_BOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE5_BOSS(reg_a5)->hp[1];
    if ((u32)reg_tmp.w >= 0x1F800U) goto next_2;
next_0:
    twin_boss_rage_third_volley();
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
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1e);
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
    reg_tmp.b[0] = ENTITY(reg_a6)->attr.b.palette;
    ENTITY(reg_a6)->attr.b.palette -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_9;
    ENTITY(reg_a6)->attr.b.palette = 8;
    if (ENTITY(reg_a6)->attr.b.flip & 1) goto next_4;
    if ((s8)FORM3_RAGE(reg_a4)->aim[1].turn == -6) goto next_3;
    FORM3_RAGE(reg_a4)->aim[1].turn -= 1;
    goto next_7;
next_3:
    if (*(u16 *)(reg_a6 + 0x1e) == 5) goto next_8;
    *(u16 *)(reg_a6 + 0x1e) += 1;
    goto next_7;
next_4:
    if (FORM3_RAGE(reg_a4)->aim[1].turn == 6) goto next_5;
    FORM3_RAGE(reg_a4)->aim[1].turn += 1;
    goto next_7;
next_5:
    if ((s16)*(u16 *)(reg_a6 + 0x1e) == -5) goto next_8;
    *(u16 *)(reg_a6 + 0x1e) -= 1;
next_7:
    return;
next_8:
    reg_tmp.b[0] = FORM3_RAGE(reg_a4)->burst.t.count;
    FORM3_RAGE(reg_a4)->burst.t.count -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_9;
    FORM3_RAGE(reg_a4)->burst.t.count = FORM3_RAGE(reg_a4)->burst.t.reload;
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

void twin_boss_fire_stinger_start(void) {
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
    reg_d0.b[0] = ENTITY(reg_a6)->look.b.size;
    STINGER(reg_a4)->burst.t.count += reg_d0.b[0];
    STINGER(reg_a4)->burst.t.reload += reg_d0.b[0];
}

s32 rng_next_d5();

void twin_boss_fire_stinger(void) {
    s16 *t1;
    s16 *t2;
    u16 t3;
    u16 t4;
    u8 t5;
    u8 t6;

    if (g_bullets_blocked != 0) {
        twin_boss_fire_stinger_start();
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
            reg_d1.w = (u32) t3;
            if ((s32) reg_d0.h[0] <= (s32) reg_d2.h[0]) {
                direction256_between();
                reg_d0.w = 0x80013;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d3.w = 0;
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
            twin_boss_fire_stinger_start();
            STINGER(reg_a4)->shot.t.count = (u8) STINGER(reg_a4)->shot.t.reload;
            t5 = ENTITY(reg_a6)->look.b.size;
            if ((s32) t5 < 0x28) {
                ENTITY(reg_a6)->look.b.size = (u8) (t5 + 0x14);
            }
            if (twin_boss_fire_point_is_first()) {
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

void twin_boss_fire_form1_rage_start(void) {
    (*(u16 **)&reg_a0) = D_00264800;
#ifdef DDPDOJ_PC
    reg_a1 = reg_a4 + 2;
#else
    (*(u16 **)&reg_a1) = (u16 *)((*(s32 *)&reg_a4) + 2);
#endif
    reg_d0.w = ((u32) D_0028DA14 >> 1) - 1;
    do {
        *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
        (*(u16 **)&reg_a0) += 1;
        (*(u16 **)&reg_a1) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

s32 slowdown_allow_with_boss();


void twin_boss_fire_form1_rage(void) {
    u32 temp_a0;
    u8 temp_v1;
    u8 temp_v1_2;

    reg_tmp.b[0] = FORM1_RAGE(reg_a4)->shot.t.count;
    FORM1_RAGE(reg_a4)->shot.t.count -= 1;
    if (reg_tmp.b[0] == 0) {
        reg_d0.b[0] = FORM1_RAGE(reg_a4)->shot_interval;
        reg_tmp.h[1] = STAGE5_BOSS(reg_a5)->hp[0];
        reg_tmp.h[0] = STAGE5_BOSS(reg_a5)->hp[1];
        if ((u32) reg_tmp.w < 0xE000U) {
            reg_d0.b[0] -= 2;
            slowdown_allow_with_boss();
        }
        FORM1_RAGE(reg_a4)->shot.t.count = (u8) reg_d0.b[0];
        reg_a1 = (u8 *)stage1_midboss_direction64_offsets_166;
        reg_d1.b[0] = FORM1_RAGE(reg_a4)->direction;
        twin_boss_form1_rage_fire();
        reg_d1.b[0] = FORM1_RAGE(reg_a4)->direction;
        reg_d1.b[0] += 0x40;
        twin_boss_form1_rage_fire();
        reg_d1.b[0] = FORM1_RAGE(reg_a4)->direction;
        reg_d1.b[0] += 0x80;
        twin_boss_form1_rage_fire();
        reg_d1.b[0] = FORM1_RAGE(reg_a4)->direction;
        reg_d1.b[0] += 0xC0;
        twin_boss_form1_rage_fire();
        reg_d0.b[0] = FORM1_RAGE(reg_a4)->turn;
        reg_tmp.h[1] = STAGE5_BOSS(reg_a5)->hp[0];
        reg_tmp.h[0] = STAGE5_BOSS(reg_a5)->hp[1];
        if ((u32) reg_tmp.w < 0xE000U) {
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

void twin_boss_jet_fire(void) {
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

void twin_boss_fire_jet_start(void) {
    (*(u16 **)&reg_a0) = D_00264390;
    (*(u16 **)&reg_a1) = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9E4 >> 1) - 1;
    do {
        *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
        (*(u16 **)&reg_a0) += 1;
        (*(u16 **)&reg_a1) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x1E8);
    JET(reg_a4)->speed += reg_d0.h[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1E7);
    JET(reg_a4)->burst.t.count += reg_d0.b[0];
    JET(reg_a4)->burst.t.reload += reg_d0.b[0];
}

s32 stage5_boss_fire_form2_jet_start();
/* Where each of a jet's six shots leaves it, as y and x from the boss. */
s16 twin_boss_jet_muzzles[6][2] = {
    { 0x80, -0x4E0 },
    { -0x4C0, -0x4E0 },
    { -0x9C0, -0x4E0 },
    { -0x100, 0x4A0 },
    { -0x580, 0x4A0 },
    { -0xA40, 0x4A0 },
};

void twin_boss_fire_jet(void) {
    s16 *temp_v1;

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
            reg_a3 = (u8 *)twin_boss_jet_muzzles;
            reg_d4.h[0] = JET(reg_a4)->muzzle;
            reg_a3 += reg_d4.h[0];
            reg_d3.h[1] = *(u16 *)reg_a3;
            reg_d3.h[0] = *(u16 *)(reg_a3 + 2);
            reg_d4.w = 0;
            twin_boss_jet_fire();
            reg_tmp.h[0] = JET(reg_a4)->muzzle;
            JET(reg_a4)->muzzle -= 4;
            if ((s32) reg_tmp.h[0] < 4) {
                JET(reg_a4)->muzzle = 0x14U;
            }
        }
        enemy_switch_target_player();
    }
}


void twin_boss_fire_point_follow(void) {
    if (twin_boss_fire_point_is_first()) {
        twin_boss_first_fire_point_follow();
    } else {
        twin_boss_second_fire_point_follow();
    }
}

extern u8 g_twin_boss_second[];
extern u8 g_twin_boss_second_fire_point[];

void twin_boss_second_fire_point_follow(void) {
    ENTITY(g_twin_boss_second_fire_point)->y.h = ENTITY(g_twin_boss_second)->y.h;
    ENTITY(g_twin_boss_second_fire_point)->x.h = ENTITY(g_twin_boss_second)->x.h;
}

void twin_boss_first_fire_point_follow(void) {
    ENTITY(g_twin_boss_first_fire_point)->y.h = ENTITY(g_enemy_entities_second)->y.h;
    ENTITY(g_twin_boss_first_fire_point)->x.h = ENTITY(g_enemy_entities_second)->x.h;
}


void twin_boss_first_fire_attack_b_start(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_first_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_attack_b_start();
    reg_a6 = save_a6;
    printf("att b1\n");
}


void twin_boss_first_fire_attack_b(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_first_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_attack_b();
    reg_a6 = save_a6;
}


void twin_boss_first_fire_attack_c_start(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_first_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_attack_c_start();
    reg_a6 = save_a6;
    printf("att c1\n");
}


void twin_boss_first_fire_attack_c(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_first_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_attack_c();
    reg_a6 = save_a6;
}


void twin_boss_first_fire_spiral_start(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_first_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_spiral_start();
    reg_a6 = save_a6;
    printf("att d1\n");
}


void twin_boss_first_fire_spiral(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_first_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_spiral();
    reg_a6 = save_a6;
}


void twin_boss_first_fire_rage_start(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_first_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_rage_start();
    reg_a6 = save_a6;
    printf("att hak1\n");
}


void twin_boss_first_fire_rage(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_first_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_rage();
    reg_a6 = save_a6;
}


void twin_boss_first_fire_stinger_start(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_first_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_stinger_start();
    reg_a6 = save_a6;
    printf("att doku1\n");
}


void twin_boss_first_fire_stinger(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_first_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_stinger();
    reg_a6 = save_a6;
}


void twin_boss_first_fire_form1_rage_start(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_first_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_form1_rage_start();
    reg_a6 = save_a6;
    printf("att hak r1 1\n");
}


void twin_boss_first_fire_form1_rage(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_first_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_form1_rage();
    reg_a6 = save_a6;
}


void twin_boss_first_fire_jet_start(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_first_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_jet_start();
    reg_a6 = save_a6;
    printf("att jet1\n");
}


void twin_boss_first_fire_jet(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_first_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_jet();
    reg_a6 = save_a6;
}

extern u8 g_twin_boss_second_fire_point[];

void twin_boss_second_fire_attack_b_start(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_second_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_attack_b_start();
    reg_a6 = save_a6;
    printf("att b2\n");
}

void twin_boss_second_fire_attack_b(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_second_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_attack_b();
    reg_a6 = save_a6;
}


void twin_boss_second_fire_attack_c_start(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_second_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_attack_c_start();
    reg_a6 = save_a6;
    printf("att c2\n");
}

void twin_boss_second_fire_attack_c(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_second_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_attack_c();
    reg_a6 = save_a6;
}


void twin_boss_second_fire_spiral_start(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_second_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_spiral_start();
    reg_a6 = save_a6;
    printf("att d2\n");
}

void twin_boss_second_fire_spiral(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_second_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_spiral();
    reg_a6 = save_a6;
}


void twin_boss_second_fire_rage_start(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_second_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_rage_start();
    reg_a6 = save_a6;
    printf("att hak2\n");
}

void twin_boss_second_fire_rage(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_second_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_rage();
    reg_a6 = save_a6;
}


void twin_boss_second_fire_stinger_start(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_second_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_stinger_start();
    reg_a6 = save_a6;
    printf("att doku2\n");
}

void twin_boss_second_fire_stinger(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_second_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_stinger();
    reg_a6 = save_a6;
}


void twin_boss_second_fire_form1_rage_start(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_second_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_form1_rage_start();
    reg_a6 = save_a6;
    printf("att hak r1 2\n");
}

void twin_boss_second_fire_form1_rage(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_second_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_form1_rage();
    reg_a6 = save_a6;
}


void twin_boss_second_fire_jet_start(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_second_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_jet_start();
    reg_a6 = save_a6;
    printf("att jet2\n");
}

void twin_boss_second_fire_jet(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = g_twin_boss_second_fire_point;
    twin_boss_fire_point_follow();
    twin_boss_fire_jet();
    reg_a6 = save_a6;
}
