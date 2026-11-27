#include "common.h"
#include "arcade_gameplay.h"
#include "entity.h"
#include "stage2_boss.h"

extern void (*stage2_boss_fire_shoulder_spread_table_2[])();

void stage2_boss_fire_shoulder_spread_start(void);
void stage2_boss_fire_shoulder_spread(void);
void stage2_boss_fire_torso_rapid_start(void);
void stage2_boss_fire_torso_rapid(void);
void stage2_boss_fire_quad_gun_start(void);
void stage2_boss_fire_quad_gun(void);
void stage2_boss_fire_side_gun_start(void);
void stage2_boss_fire_side_gun(void);
void stage2_boss_fire_shoulder_shot(void);
void stage2_boss_fire_shoulder_triple(void);
void stage2_boss_fire_shoulder_sweep_a_start(void);
void stage2_boss_fire_shoulder_sweep_a(void);
void stage2_boss_fire_shoulder_sweep_b_start(void);
void stage2_boss_fire_shoulder_sweep_b(void);
void stage2_boss_fire_shoulder_sweep_c_start(void);
void stage2_boss_fire_shoulder_sweep_c(void);
void stage2_boss_fire_shoulder_sweep_d_start(void);
void stage2_boss_fire_shoulder_sweep_d(void);
void stage2_boss_fire_knee_gun_start(void);
void stage2_boss_fire_knee_gun(void);
void stage2_boss_fire_shoulder_missile_start(void);
void stage2_boss_fire_shoulder_missile(void);
void stage2_boss_fire_rotating_spread_start(void);
void stage2_boss_fire_rotating_spread(void);
void stage2_boss_fire_shoulder_cannon_start(void);
void stage2_boss_fire_shoulder_cannon(void);
void stage2_boss_fire_body_spread_start(void);
void stage2_boss_fire_body_spread(void);
void stage2_boss_fire_body_rage_start(void);
void stage2_boss_fire_body_rage(void);

/* The set-up routine and the per-frame routine of every attack, by attack number. */
void (*stage2_boss_fire_routines[])(void) = {
    stage2_boss_fire_shoulder_spread_start,
    stage2_boss_fire_shoulder_spread,
    stage2_boss_fire_torso_rapid_start,
    stage2_boss_fire_torso_rapid,
    stage2_boss_fire_quad_gun_start,
    stage2_boss_fire_quad_gun,
    stage2_boss_fire_side_gun_start,
    stage2_boss_fire_side_gun,
    stage2_boss_fire_shoulder_shot,
    stage2_boss_fire_shoulder_shot,
    stage2_boss_fire_shoulder_triple,
    stage2_boss_fire_shoulder_triple,
    stage2_boss_fire_shoulder_sweep_a_start,
    stage2_boss_fire_shoulder_sweep_a,
    stage2_boss_fire_shoulder_sweep_b_start,
    stage2_boss_fire_shoulder_sweep_b,
    stage2_boss_fire_shoulder_sweep_c_start,
    stage2_boss_fire_shoulder_sweep_c,
    stage2_boss_fire_shoulder_sweep_d_start,
    stage2_boss_fire_shoulder_sweep_d,
    stage2_boss_fire_knee_gun_start,
    stage2_boss_fire_knee_gun,
    stage2_boss_fire_shoulder_missile_start,
    stage2_boss_fire_shoulder_missile,
    stage2_boss_fire_rotating_spread_start,
    stage2_boss_fire_rotating_spread,
    stage2_boss_fire_shoulder_cannon_start,
    stage2_boss_fire_shoulder_cannon,
    stage2_boss_fire_body_spread_start,
    stage2_boss_fire_body_spread,
    stage2_boss_fire_body_rage_start,
    stage2_boss_fire_body_rage,
};

void stage2_boss_fire_shoulder_spread();
void stage2_boss_fire_torso_rapid(void);
void stage2_boss_fire_quad_gun(void);
void stage2_boss_fire_side_gun(void);
void stage2_boss_fire_shoulder_sweep_a(void);
void stage2_boss_fire_shoulder_sweep_b(void);
void stage2_boss_fire_shoulder_sweep_c(void);
void stage2_boss_fire_shoulder_sweep_d(void);
void stage2_boss_fire_knee_gun(void);
void stage2_boss_fire_shoulder_missile(void);
void stage2_boss_fire_rotating_spread(void);
void stage2_boss_fire_column(void);
void stage2_boss_fire_shoulder_cannon(void);
void stage2_boss_fire_body_spread(void);
void stage2_boss_body_spread_fan();
void stage2_boss_fire_body_rage(void);

extern u16 g_loop;

void stage2_boss_fire_fixed_wider_on_loop(void) {
    if (g_loop != 0) {
        bullet_fire_fixed();
        reg_d1.b[0] -= 1;
        bullet_fire_fixed();
        reg_d1.b[0] += 2;
    }
    bullet_fire_fixed();
}

void stage2_boss_fire_fixed(void)
{
    bullet_fire_fixed();
}


void stage2_boss_fire_shoulder_spread_start(void) {
    SHOULDER_SPREAD(reg_a4)->shot.h = 0x808;
    SHOULDER_SPREAD(reg_a4)->side = 1;
    SHOULDER_SPREAD(reg_a4)->volleys_left = 2;
    ARCADE_REGISTER_CALL(stage2_boss_fire_shoulder_spread, 1, 0x808);
}

typedef void (*Fn)();

extern u16 stage2_boss_fire_shoulder_spread_table[];
extern u16 D_0026C1C0[];

void stage2_boss_fire_shoulder_spread() {
    reg_tmp.b[0] = SHOULDER_SPREAD(reg_a4)->shot.t.count;
    SHOULDER_SPREAD(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts;
    SHOULDER_SPREAD(reg_a4)->shot.t.count = SHOULDER_SPREAD(reg_a4)->shot.t.reload;
    if ((s16) SHOULDER_SPREAD(reg_a4)->side >= 0) goto next_1;
    reg_a0 = (u8 *)(D_0026C1C0);
    reg_d1.w = 0;
    reg_d1.b[0] = ENTITY(reg_a6)[4].move.b.dir;
    reg_d1.b[0] += 1;
    reg_d1.h[0] &= 0x3E;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    reg_tmp2.h[1] = ENTITY(reg_a6)[4].y.h;
    reg_tmp2.h[0] = ENTITY(reg_a6)[4].x.h;
    reg_d2.w = *(u32 *)&reg_tmp2.h[0];
    goto next_2;
next_1:
    reg_a0 = (u8 *)(stage2_boss_fire_shoulder_spread_table);
    reg_d1.w = 0;
    reg_d1.b[0] = ENTITY(reg_a6)[5].move.b.dir;
    reg_d1.b[0] += 1;
    reg_d1.h[0] &= 0x3E;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    reg_d2.h[1] = ENTITY(reg_a6)[5].y.h;
    reg_d2.h[0] = ENTITY(reg_a6)[5].x.h;
next_2:
    reg_a0 = (u8 *)(((u16 *)stage2_boss_fire_shoulder_spread_table_2));
    reg_d0.h[0] = SHOULDER_SPREAD(reg_a4)->speed;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
#ifdef DDPDOJ_PC
    reg_call_target = stage2_boss_fire_shoulder_spread_table_2[reg_d0.h[0] / 4];
#else
    reg_tmp.w = *(u32 *)(reg_a0 + reg_d0.h[0]);
    reg_call_target = *(Fn *)reg_tmp.w;
#endif
    reg_call_target();
    SHOULDER_SPREAD(reg_a4)->side *= 0xFFFF;
    SHOULDER_SPREAD(reg_a4)->volleys_left -= 1;
    if (SHOULDER_SPREAD(reg_a4)->volleys_left != 0) goto block_rts;
    SHOULDER_SPREAD(reg_a4)->running = 0;
block_rts:
    return;
}

void stage2_boss_rage_fan_a(void) {
    reg_d0.w = 0xFFFE0001;
    reg_d7.b[0] = reg_d1.b[0];
    reg_d6.h[0] = 0x10;
    bullet_fire256();
    reg_d1.b[0] += reg_d6.b[0];
    bullet_fire256();
    reg_d1.b[0] += reg_d6.b[0];
    bullet_fire256();
    reg_d1.b[0] += reg_d6.b[0];
    bullet_fire256();
    reg_d1.b[0] = reg_d7.b[0];
    reg_d1.b[0] -= reg_d6.b[0];
    bullet_fire256();
    reg_d1.b[0] -= reg_d6.b[0];
    bullet_fire256();
    reg_d1.b[0] -= reg_d6.b[0];
    bullet_fire256();
}

void stage2_boss_rage_fan_b(void) {
    reg_d0.w = 0x40001;
    reg_d7.b[0] = reg_d1.b[0];
    reg_d6.h[0] = 2;
    bullet_fire256();
    reg_d1.b[0] += reg_d6.b[0];
    bullet_fire256();
    reg_d1.b[0] += reg_d6.b[0];
    bullet_fire256();
    reg_d1.b[0] = reg_d7.b[0];
    reg_d1.b[0] -= reg_d6.b[0];
    bullet_fire256();
    reg_d1.b[0] -= reg_d6.b[0];
    bullet_fire256();
}


void stage2_boss_fire_torso_rapid_start(void) {
    TORSO_RAPID(reg_a4)->shot.h = 5;
    TORSO_RAPID(reg_a4)->sweep = 0;
    TORSO_RAPID(reg_a4)->sweep_step = 1U;
    rng_next_bit();
    if (reg_d0.h[0] != 0) {
        stage2_boss_fire_torso_rapid();
        return;
    }
    TORSO_RAPID(reg_a4)->sweep_step *= -1;
    stage2_boss_fire_torso_rapid();
}


s32 rng_next();
s32 aim_at_player();
extern u16 g_direction64_offsets_166[];

void stage2_boss_fire_torso_rapid(void) {
    u8 t1;

    reg_tmp.b[0] = TORSO_RAPID(reg_a4)->shot.t.count;
    TORSO_RAPID(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        TORSO_RAPID(reg_a4)->shot.t.count = (u8) TORSO_RAPID(reg_a4)->shot.t.reload;
        t1 = TORSO_RAPID(reg_a4)->sweep_step;
        reg_d7.b[0] = t1;
        if ((s8)(t1) < 0) {
            TORSO_RAPID(reg_a4)->sweep += reg_d7.b[0];
            if (0 >= (s8) TORSO_RAPID(reg_a4)->sweep) {
                TORSO_RAPID(reg_a4)->sweep_step *= -1;
            }
        } else {
            TORSO_RAPID(reg_a4)->sweep += reg_d7.b[0];
            if (0 <= (s64)(s8) TORSO_RAPID(reg_a4)->sweep) {
                TORSO_RAPID(reg_a4)->sweep_step *= -1;
            }
        }
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0x800;
        aim_at_player();
        if (cond_flag == 0) {
            reg_d1.b[0] += TORSO_RAPID(reg_a4)->sweep;
            reg_d5.w = 0x08000100;
            if ((s8) TORSO_RAPID(reg_a4)->side < 0) {
                reg_d5.w = 0x07FFFF00;
            }
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d1.h[0] += reg_d1.h[0];
            reg_d4.w = 0;
            reg_d1.h[0] += reg_d1.h[0];
            rng_next();
            reg_d1.b[0] += reg_d0.b[0];
            reg_d0.w = 0x80013;
            reg_a0 = (u8 *)(g_direction64_offsets_166);
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] &= 0x3F;
            reg_d3.h[0] += reg_d3.h[0];
            reg_d3.h[0] += reg_d3.h[0];
            reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_tmp3.h[0] = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d3.w = *(u32 *)&reg_tmp3.h[0];
            reg_d3.w += reg_d5.w;
            bullet_fire256_fixed();
            reg_d1.b[0] += 0xC;
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] &= 0x3F;
            reg_d3.h[0] += reg_d3.h[0];
            reg_d3.h[0] += reg_d3.h[0];
            reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_tmp3.h[0] = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d3.w = *(u32 *)&reg_tmp3.h[0];
            reg_d3.w += reg_d5.w;
            bullet_fire256_fixed();
            reg_d1.b[0] -= 0x18;
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] &= 0x3F;
            reg_d3.h[0] += reg_d3.h[0];
            reg_d3.h[0] += reg_d3.h[0];
            reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_tmp3.h[0] = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d3.w = *(u32 *)&reg_tmp3.h[0];
            reg_d3.w += reg_d5.w;
            bullet_fire256_fixed();
            if (g_loop != 0) {
                reg_d1.b[0] -= 8;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] += reg_d3.h[0];
                reg_d3.h[0] += reg_d3.h[0];
                reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_tmp3.h[0] = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w = *(u32 *)&reg_tmp3.h[0];
                reg_d3.w += reg_d5.w;
                bullet_fire256_fixed();
                reg_d1.b[0] += 0x10;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] += reg_d3.h[0];
                reg_d3.h[0] += reg_d3.h[0];
                reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_tmp3.h[0] = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w = *(u32 *)&reg_tmp3.h[0];
                reg_d3.w += reg_d5.w;
                bullet_fire256_fixed();
                reg_d1.b[0] += 8;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] += reg_d3.h[0];
                reg_d3.h[0] += reg_d3.h[0];
                reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_tmp3.h[0] = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w = *(u32 *)&reg_tmp3.h[0];
                reg_d3.w += reg_d5.w;
                bullet_fire256_fixed();
                reg_d1.b[0] += 0x10;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] += reg_d3.h[0];
                reg_d3.h[0] += reg_d3.h[0];
                reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_tmp3.h[0] = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w = *(u32 *)&reg_tmp3.h[0];
                reg_d3.w += reg_d5.w;
                bullet_fire256_fixed();
            }
        }
        TORSO_RAPID(reg_a4)->shots_left -= 1;
        if (TORSO_RAPID(reg_a4)->shots_left == 0) {
            TORSO_RAPID(reg_a4)->running = 0;
        }
    }
}


void stage2_boss_fire_quad_gun_start() {
    QUAD_GUN(reg_a4)->shot.h = 1;
    QUAD_GUN(reg_a4)->barrel = 0;
    QUAD_GUN(reg_a4)->burst.h = 0x1010;
    rng_next();
    reg_d0.b[0] += reg_d0.b[0];
    QUAD_GUN(reg_a4)->burst.t.count += reg_d0.b[0];
    stage2_boss_fire_quad_gun();
}

extern u8 stage2_boss_fire_quad_gun_table[];

void stage2_boss_fire_quad_gun(void) {
    reg_tmp.b[0] = QUAD_GUN(reg_a4)->shot.t.count;
    QUAD_GUN(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        QUAD_GUN(reg_a4)->shot.t.count = (u8) QUAD_GUN(reg_a4)->shot.t.reload;
        if ((s16) QUAD_GUN(reg_a4)->side >= 0) {
            rng_next();
            reg_d1.w = 0;
            reg_d0.b[0] += 0x10;
            reg_d1.b[0] = reg_d0.b[0];
        } else {
            rng_next();
            reg_d1.w = 0;
            reg_d0.b[0] += 0x30;
            reg_d1.b[0] = reg_d0.b[0];
        }
        reg_a0 = (u8 *)stage2_boss_fire_quad_gun_table;
        reg_a0 += QUAD_GUN(reg_a4)->barrel;
        reg_d3.h[1] = *(u16 *)reg_a0;
        reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
        QUAD_GUN(reg_a4)->barrel += 4;
        QUAD_GUN(reg_a4)->barrel &= 0xF;
        reg_d4.h[0] = 0x140;
        reg_d0.w = 0xFFEC0012;
        reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
        bullet_fire();
        reg_d0.w += 0x20000;
        reg_d4.h[0] -= 0x60;
        bullet_fire();
        reg_d0.w += 0x20000;
        reg_d4.h[0] -= 0x60;
        bullet_fire();
        reg_d0.w += 0x20000;
        reg_d4.h[0] -= 0x60;
        bullet_fire();
        reg_tmp.b[0] = QUAD_GUN(reg_a4)->burst.t.count;
        QUAD_GUN(reg_a4)->burst.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            QUAD_GUN(reg_a4)->burst.t.count = (u8) QUAD_GUN(reg_a4)->burst.t.reload;
            rng_next();
            reg_d0.b[0] += reg_d0.b[0];
            QUAD_GUN(reg_a4)->burst.t.count += reg_d0.b[0];
            QUAD_GUN(reg_a4)->shot.t.count = 0x18U;
        }
    }
}


void stage2_boss_fire_side_gun_start(void) {
    SIDE_GUN(reg_a4)->shot.h = 4;
    SIDE_GUN(reg_a4)->unread_04 = 0;
    SIDE_GUN(reg_a4)->shots_left = 4;
    stage2_boss_fire_side_gun();
}


void stage2_boss_fire_side_gun() {
    u8 temp_a1;

    reg_tmp.b[0] = SIDE_GUN(reg_a4)->shot.t.count;
    SIDE_GUN(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        temp_a1 = SIDE_GUN(reg_a4)->shot.t.reload;
        SIDE_GUN(reg_a4)->shot.t.count = temp_a1;
        reg_d0.w = 7;
        reg_d1.w = 0x20;
        reg_d2.h[1] = ENTITY(reg_a6)[7].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[7].x.h;
        reg_d3.w = 0xF7000080;
        bullet_fire();
        reg_d0.w = 7;
        reg_d1.w = 0x20;
        reg_d2.h[1] = ENTITY(reg_a6)[6].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[6].x.h;
        reg_d3.w = 0xF6FFFF80;
        bullet_fire();
        SIDE_GUN(reg_a4)->shots_left -= 1;
        if (SIDE_GUN(reg_a4)->shots_left == 0) {
            SIDE_GUN(reg_a4)->running = 0;
        }
    }
}

s32 spawn_request_add();

void stage2_boss_fire_shoulder_shot(void) {
    reg_d0.w = 0x32;
    spawn_request_add();
    if ((s16) SHOULDER_SHOT(reg_a4)->side >= 0) {
        reg_d2.h[1] = ENTITY(reg_a6)[4].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[4].x.h;
        *(u16 *)(reg_a0 + 0x16) = (u16) reg_d2.h[1];
        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d2.h[0];
        *(s8 *)(reg_a0 + 0x1B) = 0x30;
        reg_d0.b[0] = ENTITY(reg_a6)[4].move.b.dir;
        reg_d0.b[0] += 0x20;
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a0 + 0x1A) = reg_d0.b[0];
    } else {
        reg_tmp2.h[1] = ENTITY(reg_a6)[5].y.h;
        reg_tmp2.h[0] = ENTITY(reg_a6)[5].x.h;
        reg_d2.w = reg_tmp2.w;
        *(u16 *)(reg_a0 + 0x16) = (u16) reg_d2.h[1];
        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d2.h[0];
        *(s8 *)(reg_a0 + 0x1B) = 0x30;
        reg_d0.b[0] = ENTITY(reg_a6)[5].move.b.dir;
        reg_d0.b[0] += 0x20;
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a0 + 0x1A) = reg_d0.b[0];
    }
    SHOULDER_SHOT(reg_a4)->running = 0;
}

void stage2_boss_fire_shoulder_triple(void) {
    reg_d6.b[0] = ENTITY(reg_a6)[4].move.b.dir;
    reg_d6.b[0] += 0x20;
    reg_d6.b[0] &= 0x3F;
    reg_d2.h[1] = ENTITY(reg_a6)[4].y.h;
    reg_d2.h[0] = ENTITY(reg_a6)[4].x.h;
    reg_d0.w = 0x32;
    spawn_request_add();
    *(u16 *)(reg_a0 + 0x16) = (u16) reg_d2.h[1];
    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d2.h[0];
    *(s8 *)(reg_a0 + 0x1B) = 0x18;
    *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d6.b[0];
    reg_d0.w = 0x32;
    spawn_request_add();
    *(u16 *)(reg_a0 + 0x16) = (u16) reg_d2.h[1];
    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d2.h[0];
    *(s8 *)(reg_a0 + 0x1B) = 0x18;
    reg_d6.h[0] += 2;
    *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d6.b[0];
    reg_d0.w = 0x32;
    spawn_request_add();
    *(u16 *)(reg_a0 + 0x16) = (u16) reg_d2.h[1];
    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d2.h[0];
    *(s8 *)(reg_a0 + 0x1B) = 0x18;
    reg_d6.h[0] += 2;
    *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d6.b[0];
    reg_d0.w = 0x32;
    spawn_request_add();
    *(u16 *)(reg_a0 + 0x16) = (u16) reg_d2.h[1];
    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d2.h[0];
    *(s8 *)(reg_a0 + 0x1B) = 0x18;
    reg_d6.h[0] += 2;
    *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d6.b[0];
    reg_d0.w = 0x32;
    spawn_request_add();
    *(u16 *)(reg_a0 + 0x16) = (u16) reg_d2.h[1];
    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d2.h[0];
    *(s8 *)(reg_a0 + 0x1B) = 0x18;
    reg_d6.h[0] += 2;
    *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d6.b[0];
    SHOULDER_SHOT(reg_a4)->running = 0;
}

void stage2_boss_shoulder_sweep_a_shot(void) {
    reg_d5.b[0] = 2;
    if (g_loop != 0) {
        reg_d5.b[0] = 3;
    }
    reg_d0.w = 0xFFFC0007;
    reg_d1.b[0] -= reg_d5.b[0];
    reg_d1.h[0] &= 0x3F;
    if (((s32) reg_d1.h[0] < 0x10) || ((s32) reg_d1.h[0] > 0x30)) {
        reg_d0.w += 0x80000;
    }
    bullet_fire_fixed();
    reg_d0.w = 0xFFFD0007;
    reg_d1.b[0] += reg_d5.b[0];
    reg_d1.h[0] &= 0x3F;
    if (((s32) reg_d1.h[0] < 0x10) || ((s32) reg_d1.h[0] > 0x30)) {
        reg_d0.w += 0x80000;
    }
    bullet_fire_fixed();
    reg_d0.w = 0xFFFE0007;
    reg_d1.b[0] += reg_d5.b[0];
    reg_d1.h[0] &= 0x3F;
    if (((s32) reg_d1.h[0] < 0x10) || ((s32) reg_d1.h[0] > 0x30)) {
        reg_d0.w += 0x80000;
    }
    bullet_fire_fixed();
    if (g_loop != 0) {
        reg_d0.w = 0xFFFF0007;
        reg_d1.b[0] += reg_d5.b[0];
        reg_d1.h[0] &= 0x3F;
        if (((s32) reg_d1.h[0] < 0x10) || ((s32) reg_d1.h[0] > 0x30)) {
            reg_d0.w += 0x80000;
        }
        bullet_fire_fixed();
        reg_d0.w = 7;
        reg_d1.b[0] += reg_d5.b[0];
        reg_d1.h[0] &= 0x3F;
        if (((s32) reg_d1.h[0] < 0x10) || ((s32) reg_d1.h[0] > 0x30)) {
            reg_d0.w += 0x80000;
        }
        bullet_fire_fixed();
    }
}


void stage2_boss_fire_shoulder_sweep_a_start() {
    SHOULDER_SWEEP(reg_a4)->step = 0;
    SHOULDER_SWEEP(reg_a4)->turn_a = 1;
    rng_next_bit();
    if (reg_d0.h[0] == 0) {
        SHOULDER_SWEEP(reg_a4)->turn_a = 0xFF;
    }
    SHOULDER_SWEEP(reg_a4)->turn_b = 1;
    rng_next_bit();
    if (reg_d0.h[0] == 0) {
        SHOULDER_SWEEP(reg_a4)->turn_b = 0xFF;
    }
    SHOULDER_SWEEP(reg_a4)->shot.h = 0x1000;
    SHOULDER_SWEEP(reg_a4)->start_angle_a = 0x20U;
    do {
        rng_next();
    } while (reg_d0.b[0] == 0);
    reg_d0.b[0] += reg_d0.b[0];
    SHOULDER_SWEEP(reg_a4)->start_angle_a += reg_d0.b[0];
    stage2_boss_fire_shoulder_sweep_a();
}

s32 direction_turn_toward();
extern u16 g_bullets_blocked;

void stage2_boss_fire_shoulder_sweep_a(void) {
    if (SHOULDER_SWEEP(reg_a4)->step == 0) {
        reg_d0.w = 0;
        reg_d1.w = 0;
        reg_d1.b[0] = SHOULDER_SWEEP(reg_a4)->start_angle_a;
        reg_d0.b[0] = ENTITY(reg_a6)[4].move.b.dir;
        direction_turn_toward();
        ENTITY(reg_a6)[4].move.b.dir = (u8) reg_d1.b[0];
        ENTITY(reg_a6)[5].move.b.dir = (u8) reg_d1.b[0];
        if (SHOULDER_SWEEP(reg_a4)->start_angle_a == reg_d1.b[0]) {
            SHOULDER_SWEEP(reg_a4)->step = 1U;
        }
    }
    if (SHOULDER_SWEEP(reg_a4)->step == 1) {
        reg_tmp.b[0] = SHOULDER_SWEEP(reg_a4)->shot.t.count;
        SHOULDER_SWEEP(reg_a4)->shot.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            SHOULDER_SWEEP(reg_a4)->shot.t.count = (u8) SHOULDER_SWEEP(reg_a4)->shot.t.reload;
            if (g_bullets_blocked == 0) {
                reg_d1.b[0] = SHOULDER_SWEEP(reg_a4)->turn_a;
                ENTITY(reg_a6)[4].move.b.dir += reg_d1.b[0];
                ENTITY(reg_a6)[4].move.b.dir &= 0x3F;
                reg_d1.b[0] = SHOULDER_SWEEP(reg_a4)->turn_b;
                ENTITY(reg_a6)[5].move.b.dir += reg_d1.b[0];
                ENTITY(reg_a6)[5].move.b.dir &= 0x3F;
                reg_a0 = (u8 *)(D_0026C1C0);
                reg_d1.w = 0;
                reg_d1.b[0] = ENTITY(reg_a6)[4].move.b.dir;
                reg_d1.b[0] += 1;
                if (!(reg_d1.w & 1)) {
                    reg_d1.h[0] &= 0x3E;
                    reg_d3.h[0] = reg_d1.h[0];
                    reg_d3.h[0] += reg_d3.h[0];
                    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d3.w = reg_tmp3.w;
                    reg_d2.h[1] = ENTITY(reg_a6)[4].y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)[4].x.h;
                    stage2_boss_shoulder_sweep_a_shot();
                }
                reg_d1.w = 0;
                reg_a0 = (u8 *)(D_0026C1C0);
                reg_d1.b[0] = ENTITY(reg_a6)[5].move.b.dir;
                reg_d1.b[0] += 1;
                if (!(reg_d1.w & 1)) {
                    reg_d1.h[0] &= 0x3E;
                    reg_d3.h[0] = reg_d1.h[0];
                    reg_d3.h[0] += reg_d3.h[0];
                    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d3.w = reg_tmp3.w;
                    reg_d2.h[1] = ENTITY(reg_a6)[5].y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)[5].x.h;
                    stage2_boss_shoulder_sweep_a_shot();
                }
                SHOULDER_SWEEP(reg_a4)->shots_left -= 1;
                if (SHOULDER_SWEEP(reg_a4)->shots_left == 0) {
                    SHOULDER_SWEEP(reg_a4)->running = 0;
                }
            }
        }
    }
}

s32 bullet_fire_2way();
extern u16 g_direction64_offsets_2CC[];

void stage2_boss_shoulder_sweep_b_shot(void) {
    reg_a0 = (u8 *)(g_direction64_offsets_2CC);
    reg_d0.w = 0xFFFA0007;
    reg_d1.h[0] &= 0x3F;
    if (((s32) reg_d1.b[0] < 0x10) || ((s32) reg_d1.b[0] > 0x30)) {
        reg_d0.w += 0x80000;
    }
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d3.w += reg_d5.w;
    bullet_fire_2way();
    reg_d0.w = 0xFFFA0007;
    reg_d1.b[0] += 6;
    reg_d1.h[0] &= 0x3F;
    if (((s32) reg_d1.b[0] < 0x10) || ((s32) reg_d1.b[0] > 0x30)) {
        reg_d0.w += 0x80000;
    }
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d3.w += reg_d5.w;
    bullet_fire_2way();
    reg_d0.w = 0xFFFA0007;
    reg_d1.b[0] += 6;
    reg_d1.h[0] &= 0x3F;
    if (((s32) reg_d1.b[0] < 0x10) || ((s32) reg_d1.b[0] > 0x30)) {
        reg_d0.w += 0x80000;
    }
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d3.w += reg_d5.w;
    bullet_fire_2way();
    reg_d0.w = 0xFFFA0007;
    reg_d1.b[0] -= 0x12;
    reg_d1.h[0] &= 0x3F;
    if (((s32) reg_d1.b[0] < 0x10) || ((s32) reg_d1.b[0] > 0x30)) {
        reg_d0.w += 0x80000;
    }
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d3.w += reg_d5.w;
    bullet_fire_2way();
    reg_d0.w = 0xFFFA0007;
    reg_d1.b[0] -= 6;
    reg_d1.h[0] &= 0x3F;
    if (((s32) reg_d1.b[0] < 0x10) || ((s32) reg_d1.b[0] > 0x30)) {
        reg_d0.w += 0x80000;
    }
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d3.w += reg_d5.w;
    bullet_fire_2way();
}

s32 rng_next_masked();

void stage2_boss_fire_shoulder_sweep_b_start(void) {
    SHOULDER_SWEEP(reg_a4)->step = 0;
    SHOULDER_SWEEP(reg_a4)->shot.h = 0x1002;
    SHOULDER_SWEEP(reg_a4)->second.h = 0x2018;
    SHOULDER_SWEEP(reg_a4)->turn_a = 1;
    ARCADE_REGISTER_CALL(rng_next_bit, 0x2018, 0x1002);
    if (reg_d0.h[0] == 0) {
        SHOULDER_SWEEP(reg_a4)->turn_a = 0xFF;
    }
    SHOULDER_SWEEP(reg_a4)->turn_b = 1;
    rng_next_bit();
    if (reg_d0.h[0] == 0) {
        SHOULDER_SWEEP(reg_a4)->turn_b = 0xFF;
    }
    rng_next_masked();
    SHOULDER_SWEEP(reg_a4)->start_angle_a = (u8) reg_d0.b[0];
    rng_next_masked();
    SHOULDER_SWEEP(reg_a4)->start_angle_b = (u8) reg_d0.b[0];
    stage2_boss_fire_shoulder_sweep_b();
}


void stage2_boss_fire_shoulder_sweep_b(void) {
    if (SHOULDER_SWEEP(reg_a4)->step == 0) {
        reg_d0.w = 0;
        reg_d1.w = 0;
        reg_d1.b[0] = SHOULDER_SWEEP(reg_a4)->start_angle_a;
        reg_d0.b[0] = ENTITY(reg_a6)[4].move.b.dir;
        direction_turn_toward();
        ENTITY(reg_a6)[4].move.b.dir = (u8) reg_d1.b[0];
        reg_d1.b[0] = SHOULDER_SWEEP(reg_a4)->start_angle_b;
        reg_d0.b[0] = ENTITY(reg_a6)[5].move.b.dir;
        direction_turn_toward();
        ENTITY(reg_a6)[5].move.b.dir = (u8) reg_d1.b[0];
        reg_d1.b[0] = ENTITY(reg_a6)[4].move.b.dir;
        if (SHOULDER_SWEEP(reg_a4)->start_angle_a == reg_d1.b[0]) {
            reg_d1.b[0] = ENTITY(reg_a6)[5].move.b.dir;
            if (SHOULDER_SWEEP(reg_a4)->start_angle_b == reg_d1.b[0]) {
                SHOULDER_SWEEP(reg_a4)->step = 1U;
            }
        }
    }
    if (SHOULDER_SWEEP(reg_a4)->step == 1) {
        reg_tmp.b[0] = SHOULDER_SWEEP(reg_a4)->second.t.count;
        SHOULDER_SWEEP(reg_a4)->second.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            SHOULDER_SWEEP(reg_a4)->second.t.count = (u8) SHOULDER_SWEEP(reg_a4)->second.t.reload;
            if (g_bullets_blocked == 0) {
                reg_d1.w = 0;
                reg_d0.w = 0x6000B;
                reg_d1.b[0] = ENTITY(reg_a6)[4].move.b.dir;
                reg_d1.b[0] += 0x20;
                reg_d2.h[1] = ENTITY(reg_a6)[4].y.h;
                reg_d2.h[0] = ENTITY(reg_a6)[4].x.h;
                reg_d3.w = 0;
                reg_d4.w = 0;
                stage2_boss_fire_fixed_wider_on_loop();
                reg_d1.w = 0;
                reg_d0.w = 0x6000B;
                reg_d1.b[0] = ENTITY(reg_a6)[5].move.b.dir;
                reg_d1.b[0] += 0x20;
                reg_d2.h[1] = ENTITY(reg_a6)[5].y.h;
                reg_d2.h[0] = ENTITY(reg_a6)[5].x.h;
                reg_d3.w = 0;
                reg_d4.w = 0;
                stage2_boss_fire_fixed_wider_on_loop();
            }
        }
        reg_tmp.b[0] = SHOULDER_SWEEP(reg_a4)->shot.t.count;
        SHOULDER_SWEEP(reg_a4)->shot.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            SHOULDER_SWEEP(reg_a4)->shot.t.count = (u8) SHOULDER_SWEEP(reg_a4)->shot.t.reload;
            if (g_bullets_blocked == 0) {
                reg_d1.b[0] = SHOULDER_SWEEP(reg_a4)->turn_a;
                ENTITY(reg_a6)[4].move.b.dir += reg_d1.b[0];
                ENTITY(reg_a6)[4].move.b.dir &= 0x3F;
                reg_d1.b[0] = SHOULDER_SWEEP(reg_a4)->turn_b;
                ENTITY(reg_a6)[5].move.b.dir += reg_d1.b[0];
                ENTITY(reg_a6)[5].move.b.dir &= 0x3F;
                reg_a0 = (u8 *)(D_0026C1C0);
                reg_d1.w = 0;
                reg_d1.b[0] = ENTITY(reg_a6)[4].move.b.dir;
                reg_d1.b[0] += 1;
                if (!(reg_d1.w & 1)) {
                    reg_d1.h[0] &= 0x3E;
                    reg_d5.h[0] = reg_d1.h[0];
                    reg_d5.h[0] += reg_d5.h[0];
                    reg_tmp5.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_tmp5.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d5.w = reg_tmp5.w;
                    reg_d2.h[1] = ENTITY(reg_a6)[4].y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)[4].x.h;
                    stage2_boss_shoulder_sweep_b_shot();
                }
                reg_d1.w = 0;
                reg_a0 = (u8 *)(D_0026C1C0);
                reg_d1.b[0] = ENTITY(reg_a6)[5].move.b.dir;
                reg_d1.b[0] += 1;
                if (!(reg_d1.w & 1)) {
                    reg_d1.h[0] &= 0x3E;
                    reg_d5.h[0] = reg_d1.h[0];
                    reg_d5.h[0] += reg_d5.h[0];
                    reg_tmp5.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_tmp5.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d5.w = reg_tmp5.w;
                    reg_d2.h[1] = ENTITY(reg_a6)[5].y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)[5].x.h;
                    stage2_boss_shoulder_sweep_b_shot();
                }
                SHOULDER_SWEEP(reg_a4)->shots_left -= 1;
                if (SHOULDER_SWEEP(reg_a4)->shots_left == 0) {
                    SHOULDER_SWEEP(reg_a4)->running = 0;
                }
            }
        }
    }
}

void stage2_boss_shoulder_sweep_c_shot(void) {
    reg_a0 = (u8 *)(g_direction64_offsets_2CC);
    reg_d0.w = 0xFFFF0007;
    reg_d1.b[0] -= 2;
    if (((s32) reg_d1.b[0] < 0x40) || ((s32) reg_d1.b[0] > 0xC0)) {
        reg_d0.w += 0x80000;
    }
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d3.w += reg_d5.w;
    bullet_fire256_fixed();
    reg_d0.w = 0xFFFF0007;
    reg_d1.b[0] += 2;
    if (((s32) reg_d1.b[0] < 0x40) || ((s32) reg_d1.b[0] > 0xC0)) {
        reg_d0.w += 0x80000;
    }
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d3.w += reg_d5.w;
    bullet_fire256_fixed();
    reg_d0.w = 0xFFFF0007;
    reg_d1.b[0] += 2;
    if (((s32) reg_d1.b[0] < 0x40) || ((s32) reg_d1.b[0] > 0xC0)) {
        reg_d0.w += 0x80000;
    }
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d3.w += reg_d5.w;
    bullet_fire256_fixed();
    if (g_loop != 0) {
        reg_d0.w = 0xFFFD0007;
        reg_d1.b[0] += 1;
        if (((s32) reg_d1.b[0] < 0x40) || ((s32) reg_d1.b[0] > 0xC0)) {
            reg_d0.w += 0x80000;
        }
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w = *(u32 *)&reg_tmp3.h[0];
        reg_d3.w += reg_d5.w;
        bullet_fire256_fixed();
        reg_d0.w = 0xFFFD0007;
        reg_d1.b[0] -= 6;
        if (((s32) reg_d1.b[0] < 0x40) || ((s32) reg_d1.b[0] > 0xC0)) {
            reg_d0.w += 0x80000;
        }
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w = *(u32 *)&reg_tmp3.h[0];
        reg_d3.w += reg_d5.w;
        bullet_fire256_fixed();
    }
}


void stage2_boss_fire_shoulder_sweep_c_start() {
    SHOULDER_SWEEP(reg_a4)->step = 0;
    SHOULDER_SWEEP(reg_a4)->shot.h = 0x1000;
    SHOULDER_SWEEP(reg_a4)->second.h = 0x2010;
    reg_d0.h[0] = ENTITY(reg_a6)[4].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[4].x.h;
    aim_at_player();
    reg_d1.b[0] &= 0x3F;
    SHOULDER_SWEEP(reg_a4)->start_angle_a = (u8) reg_d1.b[0];
    reg_d0.h[0] = ENTITY(reg_a6)[5].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[5].x.h;
    aim_at_player();
    reg_d1.b[0] &= 0x3F;
    SHOULDER_SWEEP(reg_a4)->start_angle_b = (u8) reg_d1.b[0];
    SHOULDER_SWEEP(reg_a4)->turn_a = 1;
    rng_next_bit();
    if (reg_d0.h[0] == 0) {
        SHOULDER_SWEEP(reg_a4)->turn_a = 0xFF;
    }
    SHOULDER_SWEEP(reg_a4)->turn_b = 1;
    rng_next_bit();
    if (reg_d0.h[0] != 0) {
        stage2_boss_fire_shoulder_sweep_c();
        return;
    }
    SHOULDER_SWEEP(reg_a4)->turn_b = 0xFF;
    stage2_boss_fire_shoulder_sweep_c();
}


void stage2_boss_fire_shoulder_sweep_c(void) {
    if (SHOULDER_SWEEP(reg_a4)->step == 0) {
        reg_d0.w = 0;
        reg_d1.w = 0;
        reg_d1.b[0] = SHOULDER_SWEEP(reg_a4)->start_angle_a;
        reg_d0.b[0] = ENTITY(reg_a6)[4].move.b.dir;
        direction_turn_toward();
        ENTITY(reg_a6)[4].move.b.dir = (u8) reg_d1.b[0];
        reg_d1.b[0] = SHOULDER_SWEEP(reg_a4)->start_angle_b;
        reg_d0.b[0] = ENTITY(reg_a6)[5].move.b.dir;
        direction_turn_toward();
        ENTITY(reg_a6)[5].move.b.dir = (u8) reg_d1.b[0];
        reg_d1.b[0] = ENTITY(reg_a6)[4].move.b.dir;
        if (SHOULDER_SWEEP(reg_a4)->start_angle_a == reg_d1.b[0]) {
            reg_d1.b[0] = ENTITY(reg_a6)[5].move.b.dir;
            if (SHOULDER_SWEEP(reg_a4)->start_angle_b == reg_d1.b[0]) {
                SHOULDER_SWEEP(reg_a4)->step = 1;
            }
        }
    }
    if (SHOULDER_SWEEP(reg_a4)->step == 1) {
        reg_tmp.b[0] = SHOULDER_SWEEP(reg_a4)->second.t.count;
        SHOULDER_SWEEP(reg_a4)->second.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            SHOULDER_SWEEP(reg_a4)->second.t.count = (u8) SHOULDER_SWEEP(reg_a4)->second.t.reload;
            if (g_bullets_blocked == 0) {
                reg_d1.w = 0;
                reg_d0.w = 0x6000B;
                reg_d1.b[0] = ENTITY(reg_a6)[4].move.b.dir;
                reg_d1.b[0] += 0x20;
                reg_d2.h[1] = ENTITY(reg_a6)[4].y.h;
                reg_d2.h[0] = ENTITY(reg_a6)[4].x.h;
                reg_d3.w = 0;
                reg_d4.w = 0;
                stage2_boss_fire_fixed_wider_on_loop();
                reg_d1.w = 0;
                reg_d0.w = 0x6000B;
                reg_d1.b[0] = ENTITY(reg_a6)[5].move.b.dir;
                reg_d1.b[0] += 0x20;
                reg_d2.h[1] = ENTITY(reg_a6)[5].y.h;
                reg_d2.h[0] = ENTITY(reg_a6)[5].x.h;
                reg_d3.w = 0;
                reg_d4.w = 0;
                stage2_boss_fire_fixed_wider_on_loop();
            }
        }
        reg_tmp.b[0] = SHOULDER_SWEEP(reg_a4)->shot.t.count;
        SHOULDER_SWEEP(reg_a4)->shot.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            SHOULDER_SWEEP(reg_a4)->shot.t.count = (u8) SHOULDER_SWEEP(reg_a4)->shot.t.reload;
            if (g_bullets_blocked == 0) {
                reg_d1.b[0] = SHOULDER_SWEEP(reg_a4)->turn_a;
                ENTITY(reg_a6)[4].move.b.dir += reg_d1.b[0];
                ENTITY(reg_a6)[4].move.b.dir &= 0x3F;
                reg_d1.b[0] = SHOULDER_SWEEP(reg_a4)->turn_b;
                ENTITY(reg_a6)[5].move.b.dir += reg_d1.b[0];
                ENTITY(reg_a6)[5].move.b.dir &= 0x3F;
                reg_a0 = (u8 *)(D_0026C1C0);
                reg_d1.w = 0;
                reg_d1.b[0] = ENTITY(reg_a6)[4].move.b.dir;
                reg_d1.b[0] += 1;
                if (!(reg_d1.w & 1)) {
                    reg_d1.h[0] &= 0x3E;
                    reg_d5.h[0] = reg_d1.h[0];
                    reg_d5.h[0] += reg_d5.h[0];
                    reg_tmp5.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_tmp5.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d5.w = reg_tmp5.w;
                    reg_d1.b[0] += reg_d1.b[0];
                    reg_d1.b[0] += reg_d1.b[0];
                    reg_d2.h[1] = ENTITY(reg_a6)[4].y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)[4].x.h;
                    stage2_boss_shoulder_sweep_c_shot();
                }
                reg_d1.w = 0;
                reg_a0 = (u8 *)(D_0026C1C0);
                reg_d1.b[0] = ENTITY(reg_a6)[5].move.b.dir;
                reg_d1.b[0] += 1;
                if (!(reg_d1.w & 1)) {
                    reg_d1.h[0] &= 0x3E;
                    reg_d5.h[0] = reg_d1.h[0];
                    reg_d5.h[0] += reg_d5.h[0];
                    reg_tmp5.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_tmp5.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d5.w = reg_tmp5.w;
                    reg_d1.b[0] += reg_d1.b[0];
                    reg_d1.b[0] += reg_d1.b[0];
                    reg_d2.h[1] = ENTITY(reg_a6)[5].y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)[5].x.h;
                    stage2_boss_shoulder_sweep_c_shot();
                }
                SHOULDER_SWEEP(reg_a4)->shots_left -= 1;
                if (SHOULDER_SWEEP(reg_a4)->shots_left == 0) {
                    SHOULDER_SWEEP(reg_a4)->running = 0;
                }
            }
        }
    }
}

void stage2_boss_shoulder_sweep_d_shot(void) {
    u32 var_a1;
    reg_a0 = (u8 *)(g_direction64_offsets_2CC);
    reg_d0.w = 7;
    reg_d7.w = 3;
    reg_d1.h[0] &= 0x3F;
    if (((s32) reg_d1.b[0] < 0x10) || ((s32) reg_d1.b[0] > 0x30)) {
        reg_d0.w = 0x170007;
        reg_d7.w = 1;
    }
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] &= 0x3F;
        reg_d3.h[0] += reg_d3.h[0];
        reg_d3.h[0] += reg_d3.h[0];
        reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w = *(u32 *)&reg_tmp3.h[0];
        reg_d3.w += reg_d5.w;
        bullet_fire_fixed();
        var_a1 = reg_d0.w;
        reg_d0.w = var_a1 + 0x20000;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    if (g_loop != 0) {
        reg_d0.w = 7;
        reg_d1.b[0] += 4;
        reg_d7.w = 1;
        reg_d1.h[0] &= 0x3F;
        if (((s32) reg_d1.b[0] < 0x10) || ((s32) reg_d1.b[0] > 0x30)) {
            reg_d7.w = 0;
            reg_d0.w = 0x170007;
        }
        do {
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] &= 0x3F;
            reg_d3.h[0] += reg_d3.h[0];
            reg_d3.h[0] += reg_d3.h[0];
            reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d3.w = *(u32 *)&reg_tmp3.h[0];
            reg_d3.w += reg_d5.w;
            bullet_fire_fixed();
            var_a1 = reg_d0.w;
            reg_d0.w = var_a1 + 0x20000;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
}


void stage2_boss_fire_shoulder_sweep_d_start() {
    SHOULDER_SWEEP(reg_a4)->step = 0;
    SHOULDER_SWEEP(reg_a4)->shot.h = 0x4400;
    SHOULDER_SWEEP(reg_a4)->second.h = 0x1802;
    reg_d0.h[0] = ENTITY(reg_a6)[4].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[4].x.h;
    aim_at_player();
    reg_d1.b[0] += 0x20;
    reg_d1.b[0] &= 0x3F;
    SHOULDER_SWEEP(reg_a4)->start_angle_a = (u8) reg_d1.b[0];
    reg_d0.h[0] = ENTITY(reg_a6)[5].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[5].x.h;
    aim_at_player();
    reg_d1.b[0] += 0x20;
    reg_d1.b[0] &= 0x3F;
    SHOULDER_SWEEP(reg_a4)->start_angle_b = (u8) reg_d1.b[0];
    SHOULDER_SWEEP(reg_a4)->turn_a = 1;
    rng_next_bit();
    if (reg_d0.h[0] == 0) {
        SHOULDER_SWEEP(reg_a4)->turn_a = 0xFF;
    }
    SHOULDER_SWEEP(reg_a4)->turn_b = 1;
    rng_next_bit();
    if (reg_d0.h[0] != 0) {
        stage2_boss_fire_shoulder_sweep_d();
        return;
    }
    SHOULDER_SWEEP(reg_a4)->turn_b = 0xFF;
    stage2_boss_fire_shoulder_sweep_d();
}


void stage2_boss_fire_shoulder_sweep_d(void) {
    if (SHOULDER_SWEEP(reg_a4)->step == 0) {
        reg_d0.w = 0;
        reg_d1.w = 0;
        reg_d1.b[0] = SHOULDER_SWEEP(reg_a4)->start_angle_a;
        reg_d0.b[0] = ENTITY(reg_a6)[4].move.b.dir;
        direction_turn_toward();
        ENTITY(reg_a6)[4].move.b.dir = (u8) reg_d1.b[0];
        reg_d1.b[0] = SHOULDER_SWEEP(reg_a4)->start_angle_b;
        reg_d0.b[0] = ENTITY(reg_a6)[5].move.b.dir;
        direction_turn_toward();
        ENTITY(reg_a6)[5].move.b.dir = (u8) reg_d1.b[0];
        reg_d1.b[0] = ENTITY(reg_a6)[4].move.b.dir;
        if (SHOULDER_SWEEP(reg_a4)->start_angle_a == reg_d1.b[0]) {
            reg_d1.b[0] = ENTITY(reg_a6)[5].move.b.dir;
            if (SHOULDER_SWEEP(reg_a4)->start_angle_b == reg_d1.b[0]) {
                SHOULDER_SWEEP(reg_a4)->step = 1U;
            }
        }
    }
    if (SHOULDER_SWEEP(reg_a4)->step == 1) {
        reg_tmp.b[0] = SHOULDER_SWEEP(reg_a4)->second.t.count;
        SHOULDER_SWEEP(reg_a4)->second.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            SHOULDER_SWEEP(reg_a4)->second.t.count = (u8) SHOULDER_SWEEP(reg_a4)->second.t.reload;
            if (g_bullets_blocked == 0) {
                reg_d1.w = 0;
                reg_d0.w = 0x7000B;
                reg_d1.b[0] = ENTITY(reg_a6)[4].move.b.dir;
                reg_d1.b[0] += 0x20;
                reg_d2.h[1] = ENTITY(reg_a6)[4].y.h;
                reg_d2.h[0] = ENTITY(reg_a6)[4].x.h;
                reg_d3.w = 0;
                reg_d4.w = 0;
                stage2_boss_fire_fixed();
                reg_d1.w = 0;
                reg_d0.w = 0x7000B;
                reg_d1.b[0] = ENTITY(reg_a6)[5].move.b.dir;
                reg_d1.b[0] += 0x20;
                reg_d2.h[1] = ENTITY(reg_a6)[5].y.h;
                reg_d2.h[0] = ENTITY(reg_a6)[5].x.h;
                reg_d3.w = 0;
                reg_d4.w = 0;
                stage2_boss_fire_fixed();
            }
        }
        reg_tmp.b[0] = SHOULDER_SWEEP(reg_a4)->shot.t.count;
        SHOULDER_SWEEP(reg_a4)->shot.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            SHOULDER_SWEEP(reg_a4)->shot.t.count = (u8) SHOULDER_SWEEP(reg_a4)->shot.t.reload;
            if (g_bullets_blocked == 0) {
                reg_d1.b[0] = SHOULDER_SWEEP(reg_a4)->turn_a;
                ENTITY(reg_a6)[4].move.b.dir += reg_d1.b[0];
                ENTITY(reg_a6)[4].move.b.dir &= 0x3F;
                reg_d1.b[0] = SHOULDER_SWEEP(reg_a4)->turn_b;
                ENTITY(reg_a6)[5].move.b.dir += reg_d1.b[0];
                ENTITY(reg_a6)[5].move.b.dir &= 0x3F;
                reg_a0 = (u8 *)(D_0026C1C0);
                reg_d1.w = 0;
                reg_d1.b[0] = ENTITY(reg_a6)[4].move.b.dir;
                reg_d1.b[0] += 1;
                if (!(reg_d1.w & 1)) {
                    reg_d1.h[0] &= 0x3E;
                    reg_d5.h[0] = reg_d1.h[0];
                    reg_d5.h[0] += reg_d5.h[0];
                    reg_tmp5.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_tmp5.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d5.w = reg_tmp5.w;
                    reg_d2.h[1] = ENTITY(reg_a6)[4].y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)[4].x.h;
                    stage2_boss_shoulder_sweep_d_shot();
                }
                reg_d1.w = 0;
                reg_a0 = (u8 *)(D_0026C1C0);
                reg_d1.b[0] = ENTITY(reg_a6)[5].move.b.dir;
                reg_d1.b[0] += 1;
                if (!(reg_d1.w & 1)) {
                    reg_d1.h[0] &= 0x3E;
                    reg_d5.h[0] = reg_d1.h[0];
                    reg_d5.h[0] += reg_d5.h[0];
                    reg_tmp5.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_tmp5.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d5.w = reg_tmp5.w;
                    reg_d2.h[1] = ENTITY(reg_a6)[5].y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)[5].x.h;
                    stage2_boss_shoulder_sweep_d_shot();
                }
                SHOULDER_SWEEP(reg_a4)->shots_left -= 1;
                if (SHOULDER_SWEEP(reg_a4)->shots_left == 0) {
                    SHOULDER_SWEEP(reg_a4)->running = 0;
                }
            }
        }
    }
}

void stage2_boss_knee_gun_shot(void) {
    reg_a0 = (u8 *)(g_direction64_offsets_166);
    reg_d0.h[0] = KNEE_GUN(reg_a4)->shot_arg;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 7;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d3.w += reg_d5.w;
    bullet_fire256_fixed();
    reg_d7.h[0] = reg_d1.h[0];
    if (g_loop != 0) {
        reg_d1.b[0] -= 2;
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w = *(u32 *)&reg_tmp3.h[0];
        reg_d3.w += reg_d5.w;
        bullet_fire256_fixed();
        reg_d1.b[0] += 4;
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w = *(u32 *)&reg_tmp3.h[0];
        reg_d3.w += reg_d5.w;
        bullet_fire256_fixed();
    }
    reg_d6.h[0] = KNEE_GUN(reg_a4)->extra;
    do {
        reg_d1.b[0] += KNEE_GUN(reg_a4)->angle;
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w = *(u32 *)&reg_tmp3.h[0];
        reg_d3.w += reg_d5.w;
        bullet_fire256_fixed();
        if (g_loop != 0) {
            reg_d0.w += 0xFFFC0000;
            reg_d1.b[0] -= 4;
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] += 2;
            reg_d3.h[0] &= 0xFC;
            reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d3.w = *(u32 *)&reg_tmp3.h[0];
            reg_d3.w += reg_d5.w;
            bullet_fire256_fixed();
            reg_d0.w += 0x40000;
            reg_d1.b[0] += 4;
        }
    } while ((s16)(--reg_d6.h[0]) >= 0);
    reg_d1.h[0] = reg_d7.h[0];
    reg_d6.h[0] = KNEE_GUN(reg_a4)->extra;
    do {
        reg_d1.b[0] -= KNEE_GUN(reg_a4)->angle;
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w = *(u32 *)&reg_tmp3.h[0];
        reg_d3.w += reg_d5.w;
        bullet_fire256_fixed();
        if (g_loop != 0) {
            reg_d0.w += 0xFFFC0000;
            reg_d1.b[0] += 4;
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] += 2;
            reg_d3.h[0] &= 0xFC;
            reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d3.w = *(u32 *)&reg_tmp3.h[0];
            reg_d3.w += reg_d5.w;
            bullet_fire256_fixed();
            reg_d0.w += 0x40000;
            reg_d1.b[0] -= 4;
        }
    } while ((s16)(--reg_d6.h[0]) >= 0);
}


void stage2_boss_fire_knee_gun_start(void)
{
    KNEE_GUN(reg_a4)->step = 0;
    KNEE_GUN(reg_a4)->shot.h = 0x1004;
    KNEE_GUN(reg_a4)->shot_arg = 0xFFFF;
    KNEE_GUN(reg_a4)->side = 1;
    KNEE_GUN(reg_a4)->shots.h = 0x0606;
    KNEE_GUN(reg_a4)->extra = 0;
    KNEE_GUN(reg_a4)->angle = 0x0C;
    KNEE_GUN(reg_a4)->first_angle = 0x0C;
    stage2_boss_fire_knee_gun();
}

s32 enemy_switch_target_player();
extern u16 g_direction_offsets_500[];

void stage2_boss_fire_knee_gun(void) {
    u16 t1;
    u16 t2;
    if ((s16) KNEE_GUN(reg_a4)->side < 0) {
        reg_d0.h[0] = ENTITY(reg_a6)[2].y.h;
        reg_d1.h[0] = ENTITY(reg_a6)[2].x.h;
        aim_at_player();
        reg_d0.b[0] = ENTITY(reg_a6)[2].move.b.dir;
        direction_turn_toward();
        ENTITY(reg_a6)[2].move.b.dir = (u8) reg_d1.b[0];
    } else {
        reg_d0.h[0] = ENTITY(reg_a6)[3].y.h;
        reg_d1.h[0] = ENTITY(reg_a6)[3].x.h;
        aim_at_player();
        reg_d0.b[0] = ENTITY(reg_a6)[3].move.b.dir;
        direction_turn_toward();
        ENTITY(reg_a6)[3].move.b.dir = (u8) reg_d1.b[0];
    }
    reg_tmp.b[0] = KNEE_GUN(reg_a4)->shot.t.count;
    KNEE_GUN(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        KNEE_GUN(reg_a4)->shot.t.count = (u8) KNEE_GUN(reg_a4)->shot.t.reload;
        enemy_switch_target_player();
        if ((s16) KNEE_GUN(reg_a4)->side >= 0) {
            reg_d1.w = 0;
            reg_a0 = (u8 *)(g_direction_offsets_500);
            reg_d1.b[0] = ENTITY(reg_a6)[2].move.b.dir;
            t1 = reg_d1.h[0];
            reg_d1.b[0] += 1;
            reg_d1.h[0] &= 0x3E;
            reg_d5.h[0] = reg_d1.h[0];
            reg_d5.h[0] += reg_d5.h[0];
            reg_d6.h[0] = t1;
            reg_tmp5.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_tmp5.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d5.w = reg_tmp5.w;
            reg_d1.h[0] = reg_d6.h[0];
            reg_d1.h[0] += reg_d1.h[0];
            reg_d1.h[0] += reg_d1.h[0];
            reg_d2.h[1] = ENTITY(reg_a6)[2].y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[2].x.h;
            stage2_boss_knee_gun_shot();
        } else {
            reg_d1.w = 0;
            reg_a0 = (u8 *)(g_direction_offsets_500);
            reg_d1.b[0] = ENTITY(reg_a6)[3].move.b.dir;
            t2 = reg_d1.h[0];
            reg_d1.b[0] += 1;
            reg_d1.h[0] &= 0x3E;
            reg_d5.h[0] = reg_d1.h[0];
            reg_d5.h[0] += reg_d5.h[0];
            reg_d6.h[0] = t2;
            reg_tmp5.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_tmp5.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d5.w = reg_tmp5.w;
            reg_d1.h[0] = reg_d6.h[0];
            reg_d1.h[0] += reg_d1.h[0];
            reg_d1.h[0] += reg_d1.h[0];
            reg_d2.h[1] = ENTITY(reg_a6)[3].y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[3].x.h;
            stage2_boss_knee_gun_shot();
        }
        KNEE_GUN(reg_a4)->angle += 0xA;
        KNEE_GUN(reg_a4)->shots.t.count -= 1;
        if (KNEE_GUN(reg_a4)->shots.t.count == 0) {
            KNEE_GUN(reg_a4)->shots.t.count = (u8) KNEE_GUN(reg_a4)->shots.t.reload;
            KNEE_GUN(reg_a4)->angle = (u8) KNEE_GUN(reg_a4)->first_angle;
            KNEE_GUN(reg_a4)->side *= -1;
            KNEE_GUN(reg_a4)->rounds_left -= 1;
            if (KNEE_GUN(reg_a4)->rounds_left == 0) {
                KNEE_GUN(reg_a4)->running = 0;
            }
        }
    }
}


void stage2_boss_fire_shoulder_missile_start(void) {
    SHOULDER_MISSILE(reg_a4)->step = 0;
    stage2_boss_fire_shoulder_missile();
}

void stage2_boss_fire_shoulder_missile(void) {
    reg_d0.h[0] = ENTITY(reg_a6)[4].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[4].x.h;
    aim_at_player();
    reg_d1.b[0] += 0x20;
    reg_d1.b[0] &= 0x3F;
    reg_d0.b[0] = ENTITY(reg_a6)[4].move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)[4].move.b.dir = (u8) reg_d1.b[0];
    reg_d0.h[0] = ENTITY(reg_a6)[5].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[5].x.h;
    aim_at_player();
    reg_d1.b[0] += 0x20;
    reg_d1.b[0] &= 0x3F;
    reg_d0.b[0] = ENTITY(reg_a6)[5].move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)[5].move.b.dir = (u8) reg_d1.b[0];
    reg_tmp.b[0] = SHOULDER_MISSILE(reg_a4)->shot.t.count;
    SHOULDER_MISSILE(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        SHOULDER_MISSILE(reg_a4)->shot.t.count = (u8) SHOULDER_MISSILE(reg_a4)->shot.t.reload;
        reg_d0.w = 0x6000B;
        reg_d1.w = 0;
        reg_d1.b[0] = ENTITY(reg_a6)[4].move.b.dir;
        reg_d1.b[0] += 0x20;
        reg_d1.b[0] &= 0x3F;
        reg_d2.h[1] = ENTITY(reg_a6)[4].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[4].x.h;
        reg_d3.w = 0;
        reg_d4.w = 0;
        stage2_boss_fire_fixed_wider_on_loop();
        reg_d1.w = 0;
        reg_d0.w = 0x6000B;
        reg_d1.b[0] = ENTITY(reg_a6)[5].move.b.dir;
        reg_d1.b[0] += 0x20;
        reg_d1.b[0] &= 0x3F;
        reg_d2.h[1] = ENTITY(reg_a6)[5].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[5].x.h;
        reg_d3.w = 0;
        reg_d4.w = 0;
        stage2_boss_fire_fixed_wider_on_loop();
        SHOULDER_MISSILE(reg_a4)->running = 0;
    }
}


void stage2_boss_fire_rotating_spread_start() {
    ROTATING_SPREAD(reg_a4)->step = 0;
    ROTATING_SPREAD(reg_a4)->shot.h = 2;
    rng_next();
    reg_d0.b[0] += 0x10;
    ROTATING_SPREAD(reg_a4)->angle_a = (u8) reg_d0.b[0];
    rng_next();
    reg_d0.b[0] += 0x30;
    ROTATING_SPREAD(reg_a4)->angle_b = (u8) reg_d0.b[0];
    ROTATING_SPREAD(reg_a4)->delay = 0x40;
    ROTATING_SPREAD(reg_a4)->turned.h = 0;
    stage2_boss_fire_rotating_spread();
}


void stage2_boss_fire_rotating_spread(void) {
    u32 temp_v1;
    u8 temp_v1_2;

    if (ROTATING_SPREAD(reg_a4)->step == 0) {
        ROTATING_SPREAD(reg_a4)->delay -= 1;
        if ((s16) ROTATING_SPREAD(reg_a4)->delay < 0) {
            ROTATING_SPREAD(reg_a4)->step = 1U;
        }
    }
    if (ROTATING_SPREAD(reg_a4)->step == 1) {
        ROTATING_SPREAD(reg_a4)->angle_a += 1;
        ROTATING_SPREAD(reg_a4)->angle_b -= 1;
        ROTATING_SPREAD(reg_a4)->turned.b[1] += 1;
        temp_v1 = ROTATING_SPREAD(reg_a4)->turned.b[1] & 0x3F;
        ROTATING_SPREAD(reg_a4)->turned.b[1] = temp_v1;
        if ((temp_v1 == 0) && ((temp_v1_2 = ROTATING_SPREAD(reg_a4)->turns_left, (temp_v1_2 == 0)) || (ROTATING_SPREAD(reg_a4)->turns_left = (u8) (temp_v1_2 - 1), (ROTATING_SPREAD(reg_a4)->turns_left == 0)))) {
            ROTATING_SPREAD(reg_a4)->running = 0;
            return;
        }
    }
    reg_tmp.b[0] = ROTATING_SPREAD(reg_a4)->shot.t.count;
    ROTATING_SPREAD(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        ROTATING_SPREAD(reg_a4)->shot.t.count = (u8) ROTATING_SPREAD(reg_a4)->shot.t.reload;
        reg_d7.b[0] = 0x28;
        reg_d6.b[0] = ROTATING_SPREAD(reg_a4)->angle_b;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d2.w += 0x03FFFF00;
        stage2_boss_fire_column();
        if (ROTATING_SPREAD(reg_a4)->turns_left != 0) {
            reg_d6.b[0] -= 4;
            stage2_boss_fire_column();
        }
        reg_d6.b[0] = ROTATING_SPREAD(reg_a4)->angle_a;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d2.w += 0x04000100;
        stage2_boss_fire_column();
        if (ROTATING_SPREAD(reg_a4)->turns_left != 0) {
            reg_d6.b[0] += 4;
            stage2_boss_fire_column();
        }
    }
}

void stage2_boss_fire_column(void)
{
    u32 savedD6;
    u32 adjustedD0;
    u16 lowD6;

    reg_d0.h[0] = 0xFFEA;
    savedD6 = reg_d6.w;
    reg_d3.w = 0;
    reg_d4.w = 0;
    reg_d0.h[0] += reg_d7.h[0];
    adjustedD0 = reg_d0.w;
    lowD6 = reg_d6.h[0];
    reg_d1.h[0] = lowD6;
    reg_tmp.w = adjustedD0;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 7;
    ARCADE_REGISTER_CALL(bullet_fire, adjustedD0, lowD6);
    reg_d6.w = savedD6;
}


void stage2_boss_fire_shoulder_cannon_start(void) {
    SHOULDER_CANNON(reg_a4)->step = 0;
    SHOULDER_CANNON(reg_a4)->shot.h = 4;
    if (g_loop == 0) {
        stage2_boss_fire_shoulder_cannon();
        return;
    }
    SHOULDER_CANNON(reg_a4)->shot.h = 2;
    stage2_boss_fire_shoulder_cannon();
}

extern u16 D_0026C250[];
extern u16 D_0026C252[];
extern u16 D_0026C254[];
extern u16 D_0026C256[];
extern u16 D_0026C260[];
extern u16 D_0026C262[];
extern u16 D_0026C264[];
extern u16 D_0026C266[];

void stage2_boss_fire_shoulder_cannon(void) {
    u16 t1;
    u16 t2;
    u16 t3;
    u16 t4;

    reg_tmp.b[0] = SHOULDER_CANNON(reg_a4)->shot.t.count;
    SHOULDER_CANNON(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        SHOULDER_CANNON(reg_a4)->shot.t.count = (u8) SHOULDER_CANNON(reg_a4)->shot.t.reload;
        reg_d6.h[0] = 0x20;
        reg_d7.h[0] = 0x14;
        if (g_loop != 0) {
            reg_d7.h[0] = 0x28;
        }
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        t1 = ENTITY(reg_a6)->x.h;
        reg_d2.h[0] = t1;
        reg_tmp2.h[1] = D_0026C250[0];
        reg_tmp2.h[0] = D_0026C252[0];
        reg_d2.w += reg_tmp2.w;
        stage2_boss_fire_column();
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        t2 = ENTITY(reg_a6)->x.h;
        reg_d2.h[0] = t2;
        reg_tmp2.h[1] = D_0026C254[0];
        reg_tmp2.h[0] = D_0026C256[0];
        reg_d2.w += reg_tmp2.w;
        stage2_boss_fire_column();
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        t3 = ENTITY(reg_a6)->x.h;
        reg_d2.h[0] = t3;
        reg_tmp2.h[1] = D_0026C260[0];
        reg_tmp2.h[0] = D_0026C262[0];
        reg_d2.w += reg_tmp2.w;
        stage2_boss_fire_column();
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        t4 = ENTITY(reg_a6)->x.h;
        reg_d2.h[0] = t4;
        reg_tmp2.h[1] = D_0026C264[0];
        reg_tmp2.h[0] = D_0026C266[0];
        reg_d2.w += reg_tmp2.w;
        stage2_boss_fire_column();
        SHOULDER_CANNON(reg_a4)->volleys_left -= 1;
        if (SHOULDER_CANNON(reg_a4)->volleys_left == 0) {
            SHOULDER_CANNON(reg_a4)->running = 0;
        }
    }
}

s32 enemy_switch_target_player();                            /* extern */

void stage2_boss_fire_body_spread_start(void) {
    enemy_switch_target_player();
    BODY_SPREAD(reg_a4)->step = 0;
    BODY_SPREAD(reg_a4)->shot.h = 8;
    BODY_SPREAD(reg_a4)->shots_left = 2;
    BODY_SPREAD(reg_a4)->direction = 0x80U;
    ARCADE_REGISTER_CALL(direction256_to_target_player, 2, 8);
    if (cond_flag != 0) {
        stage2_boss_fire_body_spread();
        return;
    }
    BODY_SPREAD(reg_a4)->direction = (u8) reg_d1.b[0];
    stage2_boss_fire_body_spread();
}


void stage2_boss_fire_body_spread(void) {
    reg_tmp.b[0] = BODY_SPREAD(reg_a4)->shot.t.count;
    BODY_SPREAD(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        BODY_SPREAD(reg_a4)->shot.t.count = (u8) BODY_SPREAD(reg_a4)->shot.t.reload;
        reg_d0.h[0] = BODY_SPREAD(reg_a4)->speed;
        reg_tmp.w = reg_d0.w;
        reg_d0.h[1] = reg_d0.h[0];
        reg_d0.h[0] = reg_tmp.h[1];
        reg_d0.h[0] = BODY_SPREAD(reg_a4)->bullet;
        stage2_boss_body_spread_fan(reg_a4);
        BODY_SPREAD(reg_a4)->speed += 0xA;
        BODY_SPREAD(reg_a4)->angle_step += 2;
        BODY_SPREAD(reg_a4)->bullet = (u16) BODY_SPREAD(reg_a4)->next_bullet;
        BODY_SPREAD(reg_a4)->shots_left -= 1;
        if (BODY_SPREAD(reg_a4)->shots_left == 0) {
            BODY_SPREAD(reg_a4)->running = 0;
        }
    }
}


void stage2_boss_body_spread_fan() {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u32 temp_a0;
    u32 temp_a0_2;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    reg_d1.w = 0;
    reg_d1.b[0] = BODY_SPREAD(reg_a4)->direction;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d5.w = 0x08000000;
    reg_a0 = (u8 *)(g_direction64_offsets_2CC);
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d3.w += reg_d5.w;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d4.w = 0;
    bullet_fire256_fast();
    reg_d7.w = 0;
    reg_d7.b[0] = 9;
    reg_d6.b[0] = reg_d1.b[0];
    if (BODY_SPREAD(reg_a4)->bullet == 4) {
        reg_d7.b[0] = 2;
    }
    do {
        reg_d1.b[0] += BODY_SPREAD(reg_a4)->angle_step;
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w = *(u32 *)&reg_tmp3.h[0];
        reg_d3.w += reg_d5.w;
        bullet_fire256_fast();
        if (g_loop != 0) {
            temp_a0 = reg_d0.w;
            reg_d0.w = temp_a0 + 0xFFFC0000;
            reg_d1.b[0] -= 2;
            bullet_fire256_fast();
            reg_d1.b[0] += 2;
            reg_d0.w += 0x40000;
        }
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d7.w = 0;
    reg_d7.b[0] = 9;
    reg_d1.b[0] = reg_d6.b[0];
    if (BODY_SPREAD(reg_a4)->bullet == 4) {
        reg_d7.b[0] = 2;
    }
    do {
        reg_d1.b[0] -= BODY_SPREAD(reg_a4)->angle_step;
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w = *(u32 *)&reg_tmp3.h[0];
        reg_d3.w += reg_d5.w;
        bullet_fire256_fast();
        if (g_loop != 0) {
            temp_a0_2 = reg_d0.w;
            reg_d0.w = temp_a0_2 + 0xFFFC0000;
            reg_d1.b[0] += 2;
            bullet_fire256_fast();
            reg_d1.b[0] -= 2;
            reg_d0.w += 0x40000;
        }
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
}

s32 enemy_switch_target_player();                            /* extern */

void stage2_boss_fire_body_rage_start(void) {
    enemy_switch_target_player();
    BODY_RAGE(reg_a4)->step = 0;
    BODY_RAGE(reg_a4)->shot.h = 0;
    BODY_RAGE(reg_a4)->toggle.h = 0;
    stage2_boss_fire_body_rage();
}

s32 bullet_fire256_double();
s32 bullet_fire256_2way();
s32 rng_next_word();
extern u16 g_frame_mod2;

void stage2_boss_fire_body_rage(void) {
    u8 t;
    u32 c;

    reg_tmp.b[0] = BODY_RAGE(reg_a4)->shot.t.count;
    BODY_RAGE(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts;
    BODY_RAGE(reg_a4)->shot.t.count = BODY_RAGE(reg_a4)->shot.t.reload;
    reg_d6.w = 0;
    reg_d7.w = 0;
    reg_tmp.h[1] = STAGE2_BOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE2_BOSS(reg_a5)->hp[1];
    if (!((s32) reg_tmp.w < 0x2F99)) goto loop_1;
    reg_d6.w = 3;
    if (g_frame_mod2 != 0) goto loop_1;
    reg_d7.w = 1;
loop_1:
    direction256_to_target_player();
    if (cond_flag != 0) goto block_rts;
    rng_next_word();
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 3;
    reg_d3.h[0] = reg_d0.h[0];
    rng_next_word();
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 3;
    reg_tmp3.w = reg_d3.w;
    reg_d3.h[1] = reg_d3.h[0];
    reg_d3.h[0] = reg_d0.h[0];
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d2.w += 0x06000000;
    rng_next();
    reg_d5.h[0] = reg_d0.h[0];
    reg_d4.h[0] = reg_d0.h[0];
    reg_d0.b[0] = (s8) reg_d0.b[0] * 4;
    reg_d0.b[0] += reg_d4.b[0];
    reg_d1.b[0] += reg_d0.b[0];
    rng_next();
    reg_d0.h[0] = (s8) reg_d0.b[0];
    reg_d5.h[0] = (s8) reg_d5.b[0];
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 1;
    reg_d0.h[0] -= 6;
    if ((s16) reg_d5.h[0] >= 0) goto next_1;
    reg_d5.h[0] *= 0xFFFF;
next_1:
    if (reg_d5.h[0] <= 1) goto next_2;
    reg_d0.h[0] += reg_d5.h[0];
next_2:
    reg_d0.h[0] += reg_d6.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 0x16;
    reg_d4.w = 0;
    t = BODY_RAGE(reg_a4)->toggle.b[1];
    if (!(t & 1)) goto next_3;
    BODY_RAGE(reg_a4)->toggle.b[1] = t ^ 1;
    goto next_4;
next_3:
    BODY_RAGE(reg_a4)->toggle.b[1] = t ^ 1;
    bullet_fire256_double();
    goto next_5;
next_4:
    bullet_fire256_2way();
next_5:
    c = reg_d7.h[0] - 1;
    reg_d7.h[0] = c;
    if (((s64) ((s64) (c & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
block_rts:
    return;
}

u16 stage2_boss_fire_shoulder_spread_table[64] = {
    0x0600, 0x0000, 0x0600, 0x0100, 0x0600, 0x0240, 0x05C0, 0x0340,
    0x0540, 0x0440, 0x0400, 0x0500, 0x0300, 0x0540, 0x0180, 0x05C0,
    0xFF80, 0x0580, 0xFE40, 0x0580, 0xFD40, 0x0540, 0xFB00, 0x03C0,
    0xFAC0, 0x0440, 0xFA80, 0x0340, 0xFA00, 0x0200, 0xF980, 0x0100,
    0xF9C0, 0x0000, 0xFA00, 0xFF00, 0xFA00, 0xFDC0, 0xFA80, 0xFCC0,
    0xFB80, 0xFC00, 0xFC80, 0xFB00, 0xFD00, 0xFAC0, 0xFE80, 0xFA40,
    0xFF80, 0xFA40, 0x0180, 0xFA40, 0x0300, 0xFA40, 0x0480, 0xFAC0,
    0x05C0, 0xFB80, 0x0680, 0xFC40, 0x0700, 0xFD00, 0x0580, 0xFF00,
};

u16 D_0026C1C0[64] = {
    0x0800, 0x0000, 0x0800, 0x0100, 0x0840, 0x0240, 0x07C0, 0x0300,
    0x0740, 0x0440, 0x0680, 0x0500, 0x0540, 0x0580, 0x0400, 0x05C0,
    0x0200, 0x0580, 0x0100, 0x0580, 0xFF00, 0x0540, 0xFE40, 0x0500,
    0xFD40, 0x0440, 0xFC40, 0x0340, 0xFC00, 0x0200, 0xFB80, 0x0100,
    0xFB80, 0x0000, 0xFB80, 0xFEC0, 0xFBC0, 0xFD80, 0xFCC0, 0xFCC0,
    0xFD40, 0xFBC0, 0xFE40, 0xFB00, 0xFF40, 0xFA80, 0x00C0, 0xFA40,
    0x0240, 0xFA40, 0x03C0, 0xFA40, 0x0500, 0xFA80, 0x06C0, 0xFAC0,
    0x07C0, 0xFB80, 0x08C0, 0xFC40, 0x0980, 0xFD40, 0x0840, 0xFF00,
};

u8 stage2_boss_fire_quad_gun_table[16] = {
    0x80, 0xFD, 0x00, 0xF9, 0x80, 0xFD, 0x00, 0x01, 0x00, 0xFB, 0x00, 0xF9, 0x00, 0xFB, 0x00, 0x01,
};

u16 D_0026C250[8] = {
    0xF9C0, 0xF080, 0xF9C0, 0xF400, 0xF740, 0xF080, 0xF740, 0xF400,
};

u16 D_0026C260[8] = {
    0xF9C0, 0x0BC0, 0xF9C0, 0x0F00, 0xF740, 0x0BC0, 0xF740, 0x0F00,
};

void (*stage2_boss_fire_shoulder_spread_table_2[2])() = {
    stage2_boss_rage_fan_a,
    stage2_boss_rage_fan_b,
};

#ifdef DDPDOJ_PC
#include "pc_data_alias.h"

PC_DATA_ALIAS(D_0026C252, D_0026C250, 0x2);
PC_DATA_ALIAS(D_0026C254, D_0026C250, 0x4);
PC_DATA_ALIAS(D_0026C256, D_0026C250, 0x6);

PC_DATA_ALIAS(D_0026C262, D_0026C260, 0x2);
PC_DATA_ALIAS(D_0026C264, D_0026C260, 0x4);
PC_DATA_ALIAS(D_0026C266, D_0026C260, 0x6);
#endif
