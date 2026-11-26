#include "common.h"
#include "entity.h"
#include "stage5_boss.h"

void stage5_boss_mode_form1_idle_start(void);
void stage5_boss_mode_form1_idle(void);
void stage5_boss_mode_form1_explosion_start(void);
void stage5_boss_mode_form1_explosion(void);
void stage5_boss_mode_form1_to_form2_start(void);
void stage5_boss_mode_form1_to_form2(void);
void stage5_boss_mode_form2_explosion_start(void);
void stage5_boss_mode_form2_explosion(void);
void stage5_boss_mode_form2_to_form3_start(void);
void stage5_boss_mode_form2_to_form3(void);
void stage5_boss_mode_form3_explosion_start(void);
void stage5_boss_mode_form3_explosion(void);
void stage5_boss_mode_form1_arm_guns_aimed_start(void);
void stage5_boss_mode_form1_arm_guns_aimed(void);
void stage5_boss_mode_form1_mouth_start(void);
void stage5_boss_mode_form1_mouth(void);
void stage5_boss_mode_form1_arm_guns_fixed_start(void);
void stage5_boss_mode_form1_arm_guns_fixed(void);
void stage5_boss_mode_form1_horn_start(void);
void stage5_boss_mode_form1_horn(void);
void stage5_boss_mode_form2_mouth_start(void);
void stage5_boss_mode_form2_mouth(void);
void stage5_boss_mode_form2_jet_start(void);
void stage5_boss_mode_form2_jet(void);
void stage5_boss_mode_form2_horn_start(void);
void stage5_boss_mode_form2_horn(void);
void stage5_boss_mode_form2_stinger_start(void);
void stage5_boss_mode_form2_stinger(void);
void stage5_boss_mode_form1_rage_start(void);
void stage5_boss_mode_form1_rage(void);
void stage5_boss_mode_form3_attack_a_start(void);
void stage5_boss_mode_form3_attack_a(void);
void stage5_boss_mode_form3_attack_b_start(void);
void stage5_boss_mode_form3_attack_b(void);
void stage5_boss_mode_form3_attack_c_start(void);
void stage5_boss_mode_form3_attack_c(void);
void stage5_boss_mode_form3_attack_d_start(void);
void stage5_boss_mode_form3_attack_d(void);
void stage5_boss_mode_form3_rage_start(void);
void stage5_boss_mode_form3_rage(void);
void stage5_boss_mode_form1_explosion_afterglow_start(void);
void stage5_boss_mode_form1_explosion_afterglow(void);

#ifdef DEATH_LABEL
void death_func_002237B0(void);
void death_func_00223870(void);
#endif

/* The set-up routine and the per-frame routine of every mode, by mode number. */
void (*stage5_boss_mode_routines[])(void) = {
    stage5_boss_mode_form1_idle_start,
    stage5_boss_mode_form1_idle,
    stage5_boss_mode_form1_explosion_start,
    stage5_boss_mode_form1_explosion,
    stage5_boss_mode_form1_to_form2_start,
    stage5_boss_mode_form1_to_form2,
    stage5_boss_mode_form2_explosion_start,
    stage5_boss_mode_form2_explosion,
    stage5_boss_mode_form2_to_form3_start,
    stage5_boss_mode_form2_to_form3,
    stage5_boss_mode_form3_explosion_start,
    stage5_boss_mode_form3_explosion,
    stage5_boss_mode_form1_arm_guns_aimed_start,
    stage5_boss_mode_form1_arm_guns_aimed,
    stage5_boss_mode_form1_mouth_start,
    stage5_boss_mode_form1_mouth,
    stage5_boss_mode_form1_arm_guns_fixed_start,
    stage5_boss_mode_form1_arm_guns_fixed,
    stage5_boss_mode_form1_horn_start,
    stage5_boss_mode_form1_horn,
    stage5_boss_mode_form2_mouth_start,
    stage5_boss_mode_form2_mouth,
    stage5_boss_mode_form2_jet_start,
    stage5_boss_mode_form2_jet,
    stage5_boss_mode_form2_horn_start,
    stage5_boss_mode_form2_horn,
    stage5_boss_mode_form2_stinger_start,
    stage5_boss_mode_form2_stinger,
    stage5_boss_mode_form1_rage_start,
    stage5_boss_mode_form1_rage,
    stage5_boss_mode_form3_attack_a_start,
    stage5_boss_mode_form3_attack_a,
    stage5_boss_mode_form3_attack_b_start,
    stage5_boss_mode_form3_attack_b,
    stage5_boss_mode_form3_attack_c_start,
    stage5_boss_mode_form3_attack_c,
    stage5_boss_mode_form3_attack_d_start,
    stage5_boss_mode_form3_attack_d,
    stage5_boss_mode_form3_rage_start,
    stage5_boss_mode_form3_rage,
    stage5_boss_mode_form1_explosion_afterglow_start,
    stage5_boss_mode_form1_explosion_afterglow,
#ifdef DEATH_LABEL
    death_func_002237B0, /* a mode only Death Label has */
    death_func_00223870,
#else
    0,
    0,
#endif
};

void stage5_boss_mode_form1_idle();
void stage5_boss_mode_form1_explosion();
void stage5_boss_mode_form1_to_form2();
void stage5_boss_mode_form2_explosion(void);
void stage5_boss_mode_form2_to_form3();
void stage5_boss_mode_form3_explosion();
void stage5_boss_mode_form1_arm_guns_aimed(void);
void stage5_boss_mode_form1_mouth(void);
void stage5_boss_mode_form1_arm_guns_fixed(void);
void stage5_boss_mode_form1_horn();
void stage5_boss_mode_form2_mouth(void);
void stage5_boss_mode_form2_jet(void);
void stage5_boss_mode_form2_horn(void);
void stage5_boss_mode_form2_stinger(void);
void stage5_boss_mode_form1_rage(void);
void stage5_boss_mode_form3_attack_a(void);
void stage5_boss_mode_form3_attack_b(void);
void stage5_boss_mode_form3_attack_c(void);
void stage5_boss_mode_form3_attack_d();
void stage5_boss_mode_form3_rage(void);
void stage5_boss_mode_form1_explosion_afterglow(void);

s32 boss_animation_start();                            /* extern */
s32 slowdown_turn_off();                            /* extern */
extern u16 D_0028E2E8;

#ifdef DEATH_LABEL
extern s8 death_D_0029085C_as_s8;
#endif

void stage5_boss_mode_form1_idle_start(void) {
    s32 boss_movement_start();
#ifdef DEATH_LABEL
    death_D_0029085C_as_s8 = 0;
#endif
    reg_d0.w = 0;
    boss_animation_start();
    reg_d0.w = 1;
    boss_animation_start();
    reg_d0.w = 0;
    boss_movement_start();
    slowdown_turn_off();
    *(s16 *)(reg_a4 + 2) = 0x260;
    *(s16 *)(reg_a4 + 4) = 0x160;
    if (D_0028E2E8 == 0) {
        stage5_boss_mode_form1_idle(0x260);
        return;
    }
    *(s16 *)(reg_a4 + 4) = 0;
    stage5_boss_mode_form1_idle(0x260);
}

s32 boss_phase_start();
s32 func_0013B2E0();
s32 stage5_boss_form1_take_hits();
extern u8 stage5_boss_fade_palettes_b[];
extern s16 g_boss_hyper_wait_as_s16;
extern u8 *g_boss_hp;
extern s32 g_boss_hp_unit;
extern u8 g_boss_present;
extern u8 g_boss_present_b1;
extern s16 g_true_last_boss_as_s16;

void stage5_boss_mode_form1_idle() {
    u16 temp_v1;
    u16 var_a1;

    temp_v1 = *(u16 *)(reg_a4 + 4);
    if (temp_v1 != 0) {
        *(u16 *)(reg_a4 + 4) = (u16) (temp_v1 - 1);
        if (*(u16 *)(reg_a4 + 4) == 0) {
            reg_tmp.w = 0x69000;
            g_boss_present_b1 |= 1;
            g_boss_present_b1 |= 4;
            g_boss_present |= 1;
            STAGE5_BOSS(reg_a5)->hp[0] = (u16) reg_tmp.h[1];
            var_a1 = reg_tmp.h[0];
            STAGE5_BOSS(reg_a5)->hp[1] = var_a1;
            g_boss_hp_unit = 0x780;
            reg_a0 = reg_a5 + 0x16;
            g_boss_hp = (u8 *)(reg_a0);
        }
    }
    *(u16 *)(reg_a4 + 2) -= 1;
    if (*(u16 *)(reg_a4 + 2) == 0) {
        g_boss_hyper_wait_as_s16 = 1;
        if (D_0028E2E8 == 0) {
            g_boss_present_b1 |= 2;
            g_boss_present_b1 |= 0x10;
        } else {
            g_true_last_boss_as_s16 = 1;
        }
        stage5_boss_form1_take_hits();
        reg_a0 = (u8 *)stage5_boss_fade_palettes_b;
        func_0013B2E0();
        reg_d0.w = 6;
        boss_phase_start();
        *(s16 *)reg_a4 = 0;
    }
}


void stage5_boss_mode_form1_explosion_start(void) {
    ((u16 *)((void *)reg_a4))[1] = 0xC0;
    ((u16 *)((void *)reg_a4))[2] = 0x303;
    stage5_boss_mode_form1_explosion(0xC0);
}

typedef void (*Fn)();

extern u8 stage5_boss_flash_palettes_a[];
s32 boss_part_hide_all();
s32 ground_speeds_request();
s32 func_00139EB0();
s32 explosion_spawn();
s32 sfx_explosion_air_medium();
s32 sfx_explosion_air_large();
s32 sfx_explosion_extra_1();
s32 sfx_explosion_boss();
s32 func_001E1F30();
s32 rng_next_unsigned();
s32 func_00201270();
s32 rng_next_word();
s32 func_00211550();
s32 vibration_start_pad1();
s32 vibration_start_pad2();
extern u16 D_00264BB0[];
extern u16 D_00264C10[];
extern u8 g_slowdown_timer;

void stage5_boss_mode_form1_explosion() {
    s16 t1;
    s16 t2;
    u32 t3;
    u32 t4;
    u32 t5;
    u32 t6;
    *(u16 *)(reg_a4 + 2) -= 1;
    if (*(u16 *)(reg_a4 + 2) == 0) {
        func_00139EB0();
        reg_d0.h[0] = 0xD;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        t6 = ENTITY(reg_a6)->x.h;
        *(u16 *)(reg_a0 + 4) = t6;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0x1400U;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        reg_d0.h[0] = 0x85;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0x1400U;
        *(u16 *)(reg_a0 + 0x28) = 0x600U;
        *(s16 *)(reg_a0 + 0x1A) = 0x658;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0;
        *(s16 *)(reg_a0 + 0x18) = 2;
        reg_d0.h[0] = 0xD;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0xC00U;
        *(u16 *)(reg_a0 + 0x28) = 0xFE00U;
        *(s16 *)(reg_a0 + 0x1A) = 0x6A8;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0;
        *(s16 *)(reg_a0 + 0x18) = 2;
        reg_d0.h[0] = 0x85;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0x400U;
        *(u16 *)(reg_a0 + 0x28) = 0xFC00U;
        *(s16 *)(reg_a0 + 0x1A) = 0xA88;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 6;
        reg_d0.h[0] = 0xD;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0x600U;
        *(u16 *)(reg_a0 + 0x28) = 0x400U;
        *(s16 *)(reg_a0 + 0x1A) = 0xA78;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 4;
        reg_d0.h[0] = 0x85;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0xF600U;
        *(u16 *)(reg_a0 + 0x28) = 0xA00U;
        *(s16 *)(reg_a0 + 0x1A) = 0xA70;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 0xA;
        reg_d0.h[0] = 0xD;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0xF000U;
        *(u16 *)(reg_a0 + 0x28) = 0xFE00U;
        *(s16 *)(reg_a0 + 0x1A) = 0x588;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 8;
        reg_d0.h[0] = 0x85;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0xE000U;
        *(u16 *)(reg_a0 + 0x28) = 0xFC00U;
        *(s16 *)(reg_a0 + 0x1A) = 0x4A0;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 8;
        reg_d0.h[0] = 0xD;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0xD800U;
        *(u16 *)(reg_a0 + 0x28) = 0x400U;
        *(s16 *)(reg_a0 + 0x1A) = 0x460;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 8;
        t1 = (s16) ENTITY(reg_a6)->y.h;
        t2 = ENTITY(reg_a6)->x.sh;
        ENTITY(reg_a6)->y.h += 0x7FFF + 0x7401;
        ENTITY(reg_a6)->x.h += 0x7FFF + 0x7101;
        func_001E1F30();
        ENTITY(reg_a6)->x.h += 0x1E00;
        func_001E1F30();
        ENTITY(reg_a6)->y.h = t1;
        ENTITY(reg_a6)->x.h = t2;
        reg_a0 = (u8 *)stage5_boss_flash_palettes_a;
        func_0013B2E0();
        if (D_0028E2E8 == 0) {
            sfx_explosion_boss();
            boss_part_hide_all();
            reg_d7.w = 0x14;
            reg_a3 = (u8 *)(D_00264BB0);
            do {
                reg_d1.h[0] = 0;
                reg_d2.h[1] = *(u16 *)reg_a3;
                reg_a3 += 2;
                t3 = *(u16 *)reg_a3;
                reg_d2.h[0] = t3;
                reg_a3 += 2;
                reg_d0.w = 0xC;
                func_00211550();
            } while ((s16)(--reg_d7.h[0]) >= 0);
            reg_d0.w = 0x14;
            boss_phase_start();
            *(s16 *)reg_a4 = 0;
            return;
        }
        vibration_start_pad1(0xC8, 0x50);
        vibration_start_pad2(0xC8, 0x50);
        g_slowdown_timer = 0x50;
        sfx_explosion_extra_1();
        reg_d0.h[0] = 0x10;
        reg_d1.h[0] = 0x10;
        ground_speeds_request();
        reg_d0.w = 2;
        boss_phase_start();
        *(s16 *)reg_a4 = 0;
block_rts:
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto block_rts;
    }
    *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
    reg_a0 = (u8 *)sfx_explosion_air_medium;
    rng_next_unsigned();
    if (0 > reg_d0.sb[0]) {
        reg_a0 = (u8 *)sfx_explosion_air_large;
    }
    reg_call_target = (Fn)(reg_a0);
    reg_call_target();
    rng_next_unsigned();
    reg_d0.h[0] &= 7;
    reg_d0.h[0] += reg_d0.h[0];
    reg_a1 = (u8 *)(D_00264C10);
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    t5 = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 4) = t5;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x800;
    func_00201270();
    reg_d0.b[0] += 3;
    *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
    rng_next_unsigned();
    *(u8 *)(reg_a0 + 0x1A) = reg_d0.b[0];
    rng_next_word();
    t4 = reg_d0.h[0];
    reg_d1.h[0] = t4;
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d0.h[0] = t4 + reg_d1.h[0];
    reg_d0.h[0] += 0x7FFF + 0x7801;
    *(u16 *)(reg_a0 + 0x26) = (u16) reg_d0.h[0];
    rng_next_word();
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
    *(u16 *)(reg_a0 + 0x28) = (u16) reg_d0.h[0];
}

extern s16 *reg_a4_as_s16_p;

#ifdef DEATH_LABEL
extern s8 death_D_0029085C_as_s8;
#endif

void stage5_boss_mode_form1_to_form2_start(void) {
#ifdef DEATH_LABEL
    death_D_0029085C_as_s8 = 1;
#endif
    *(s16 *)(reg_a4 + 2) = 1;
    *(s16 *)(reg_a4 + 4) = 0x80;
    STAGE5_BOSS(reg_a5)->time_left = 0x6270;
    stage5_boss_mode_form1_to_form2(0x80, 1);
}

s32 boss_part_show();
s32 boss_part_hide();
s32 stage5_boss_shield_off();
s32 stage5_boss_form2_take_hits();
s32 stage5_boss_start_damage();
s32 slowdown_turn_off();

void stage5_boss_mode_form1_to_form2() {
    s32 boss_movement_start();
    u16 temp_v1;
    u8 *temp_a0;

    temp_v1 = *(u16 *)(reg_a4 + 2);
    temp_a0 = reg_a4 + 2;
    if (temp_v1 != 0) {
        *(u16 *)(reg_a4 + 2) = (u16) (temp_v1 - 1);
        if (*(u16 *)(reg_a4 + 2) == 0) {
            reg_d0.w = 0;
            boss_part_hide();
            reg_d0.w = 1;
            boss_part_hide();
            reg_d0.w = 9;
            boss_part_hide();
            reg_d0.w = 2;
            boss_part_hide();
            reg_d0.w = 5;
            boss_part_hide();
            reg_d0.w = 4;
            boss_part_hide();
            reg_d0.w = 3;
            boss_part_hide();
            reg_d0.w = 8;
            boss_part_hide();
            reg_d0.w = 7;
            boss_part_hide();
            reg_d0.w = 6;
            boss_part_hide();
            reg_d0.w = 0xB;
            boss_part_show();
            reg_d0.w = 0xC;
            boss_part_show();
            reg_d0.w = 0xD;
            boss_part_show();
            reg_d0.w = 0xF;
            boss_part_show();
            reg_d0.w = 1;
            boss_movement_start();
            STAGE5_DAMAGE(reg_a6)->form = 1;
            ENTITY(reg_a6)[11].hit_y_minus.sh = 0;
            reg_tmp.w = 0x23000;
            STAGE5_BOSS(reg_a5)->hp[0] = (u16) reg_tmp.h[1];
            STAGE5_BOSS(reg_a5)->hp[1] = (u16) reg_tmp.h[0];
            stage5_boss_shield_off();
            stage5_boss_form2_take_hits();
            stage5_boss_start_damage();
            slowdown_turn_off();
        }
    } else {
        *(u16 *)(reg_a4 + 4) -= 1;
        if (*(u16 *)(reg_a4 + 4) == 0) {
            reg_d0.w = 0xA;
            boss_phase_start();
            *(s16 *)reg_a4 = 0;
        }
    }
}


void stage5_boss_mode_form2_explosion_start(void) {
    s32 boss_movement_start(s32, s32);
    *(s16 *)(reg_a4 + 2) = 0xC0;
    *(s16 *)(reg_a4 + 4) = 0x303;
    reg_d0.w = 3;
    boss_movement_start(0x303, 0xC0);
    stage5_boss_mode_form2_explosion();
}

extern u8 stage5_boss_flash_palettes_b[];

void stage5_boss_mode_form2_explosion(void) {
    u16 temp_a1;
    u16 temp_a3;
    *(u16 *)(reg_a4 + 2) -= 1;
    if (*(u16 *)(reg_a4 + 2) == 0) {
        sfx_explosion_extra_1();
        reg_d0.h[0] = 0xD;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        temp_a3 = ENTITY(reg_a6)->x.h;
        *(u16 *)(reg_a0 + 4) = temp_a3;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0x1400U;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        reg_d0.h[0] = 0x85;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0x1400U;
        *(u16 *)(reg_a0 + 0x28) = 0x600U;
        *(s16 *)(reg_a0 + 0x1A) = 0x658;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0;
        *(s16 *)(reg_a0 + 0x18) = 2;
        reg_d0.h[0] = 0xD;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0xC00U;
        *(u16 *)(reg_a0 + 0x28) = 0xFE00U;
        *(s16 *)(reg_a0 + 0x1A) = 0x6A8;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0;
        *(s16 *)(reg_a0 + 0x18) = 2;
        reg_d0.h[0] = 0x85;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0x400U;
        *(u16 *)(reg_a0 + 0x28) = 0xFC00U;
        *(s16 *)(reg_a0 + 0x1A) = 0xA88;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 6;
        reg_d0.h[0] = 0xD;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0x600U;
        *(u16 *)(reg_a0 + 0x28) = 0x400U;
        *(s16 *)(reg_a0 + 0x1A) = 0xA78;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 4;
        reg_d0.h[0] = 0x85;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0xF600U;
        *(u16 *)(reg_a0 + 0x28) = 0xA00U;
        *(s16 *)(reg_a0 + 0x1A) = 0xA70;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 0xA;
        reg_d0.h[0] = 0xD;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0xF000U;
        *(u16 *)(reg_a0 + 0x28) = 0xFE00U;
        *(s16 *)(reg_a0 + 0x1A) = 0x588;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 8;
        reg_d0.h[0] = 0x85;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0xE000U;
        *(u16 *)(reg_a0 + 0x28) = 0xFC00U;
        *(s16 *)(reg_a0 + 0x1A) = 0x4A0;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 8;
        reg_d0.h[0] = 0xD;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(u16 *)(reg_a0 + 0x26) = 0xD800U;
        *(u16 *)(reg_a0 + 0x28) = 0x400U;
        *(s16 *)(reg_a0 + 0x1A) = 0x460;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x18) = 8;
        vibration_start_pad1(0xC8, 0x50, 0x460, 0x400);
        vibration_start_pad2(0xC8, 0x50);
        reg_a0 = (u8 *)stage5_boss_flash_palettes_b;
        func_0013B2E0();
        reg_d0.h[0] = 0x200;
        reg_d1.h[0] = 0x200;
        ground_speeds_request();
        reg_d0.w = 4;
        boss_phase_start();
        *(s16 *)reg_a4 = 0;
block_rts:
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto block_rts;
    }
    {
        *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
        reg_a0 = (u8 *)sfx_explosion_air_medium;
        rng_next_unsigned();
        if (0 > reg_d0.sb[0]) {
            reg_a0 = (u8 *)sfx_explosion_air_large;
        }
        reg_call_target = (Fn)(reg_a0);
        reg_call_target();
        rng_next_unsigned();
        reg_d0.h[0] &= 7;
        reg_a1 = (u8 *)(D_00264C10);
        reg_d0.h[0] += reg_d0.h[0];
        switch (reg_d0.h[0]) { case 0: goto block_zero; }
        temp_a3 = *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1));
        goto block_join;
block_zero:
        temp_a3 = *(u16 *)reg_a1;
block_join:
        reg_d0.h[0] = temp_a3;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        temp_a1 = ENTITY(reg_a6)->x.h;
        *(u16 *)(reg_a0 + 4) = temp_a1;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x800;
        func_00201270();
        reg_d0.b[0] += 3;
        *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
        rng_next_unsigned();
        *(u8 *)(reg_a0 + 0x1A) = reg_d0.b[0];
        rng_next_word();
        reg_d1.h[0] = reg_d0.h[0];
        reg_d0.h[0] += 0xF800;
        *(u16 *)(reg_a0 + 0x26) = (u16) reg_d0.h[0];
        rng_next_word();
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
        *(u16 *)(reg_a0 + 0x28) = (u16) reg_d0.h[0];
    }
}

typedef struct PartRegA4 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} PartRegA4;

extern s16 g_enemy_signal_2_as_s16;


#ifdef DEATH_LABEL
extern s8 death_D_0029085C_as_s8;
#endif

void stage5_boss_mode_form2_to_form3_start(void) {
#ifdef DEATH_LABEL
    death_D_0029085C_as_s8 = 2;
#endif
    ((PartRegA4 *)reg_a4)->unk2 = 1;
    ((PartRegA4 *)reg_a4)->unk4 = 0x80;
    g_enemy_signal_2_as_s16 = 0;
    stage5_boss_mode_form2_to_form3(1);
}

s32 boss_movement_stop();
s32 boss_animation_start();
s32 music_play_bgm9();
s32 stage5_boss_form3_take_hits();
extern void *g_boss_hp_as_void_p;
extern u16 g_true_last_boss;
extern u16 D_00299768_as_u16_a[];
extern u16 D_0029976A_as_u16_a[];
extern u16 D_0029976C[];
extern u16 D_0029976E[];

#ifdef DEATH_LABEL
extern u16 death_D_0068FFB2[];
extern u16 death_D_0068FFB4[];
extern u16 death_D_006901B2[];
extern u16 death_D_006901B4[];
#endif

void stage5_boss_mode_form2_to_form3() {
    s32 boss_movement_start();
    u16 t1;
    u8 *t2;

    t1 = *(u16 *)(reg_a4 + 2);
    t2 = (u8 *)(reg_a4 + 2);
    if (t1 != 0) {
        *(u16 *)(reg_a4 + 2) = (u16) (t1 - 1);
        if (*(u16 *)(reg_a4 + 2) == 0) {
            g_boss_present_b1 |= 2;
            reg_d0.w = 0xB;
            g_boss_present_b1 |= 0x10;
            boss_part_hide();
            reg_d0.w = 0xC;
            boss_part_hide();
            reg_d0.w = 0xD;
            boss_part_hide();
            reg_d0.w = 0xF;
            boss_part_hide();
            reg_d0.w = 0x10;
            boss_part_show();
            reg_d0.w = 6;
            boss_animation_start();
            reg_d0.w = 7;
            boss_animation_start();
            reg_d0.w = 3;
            boss_movement_stop();
            reg_d0.w = MAIN_OR_DEATH_LABEL(4, 16);
            boss_movement_start();
#ifdef DEATH_LABEL
            death_D_006901B2[0] = death_D_0068FFB2[0];
            death_D_006901B4[0] = death_D_0068FFB4[0];
#endif
            STAGE5_DAMAGE(reg_a6)->form = 2;
            g_true_last_boss = 0xFFFF;
            reg_d0.w = 0x4D000;
            STAGE5_BOSS(reg_a5)->hp[0] = (u16) reg_d0.h[1];
            STAGE5_BOSS(reg_a5)->hp[1] = (u16) reg_d0.h[0];
            STAGE5_BOSS(reg_a5)->hp_scratch[0] = (u16) reg_d0.h[1];
            STAGE5_BOSS(reg_a5)->hp_scratch[1] = (u16) reg_d0.h[0];
            g_boss_hp_unit = 0x580;
            reg_a0 = (u8 *)(reg_a5 + 0x16);
            g_boss_hp_as_void_p = (void *)reg_a0;
            g_boss_present_b1 |= 1;
            g_boss_present_b1 |= 4;
            g_boss_present |= 1;
            stage5_boss_shield_off();
            stage5_boss_form3_take_hits();
            stage5_boss_start_damage();
            D_00299768_as_u16_a[0] = 1;
            D_0029976A_as_u16_a[0] = 1;
            D_0029976C[0] = 1;
            D_0029976E[0] = 1;
            slowdown_turn_off();
            music_play_bgm9();
        }
    } else {
        *(u16 *)(reg_a4 + 4) -= 1;
        if (*(u16 *)(reg_a4 + 4) == 0) {
            reg_d0.w = MAIN_OR_DEATH_LABEL(0xF, 21);
            boss_phase_start();
            *(s16 *)reg_a4 = 0;
        }
    }
}

s32 func_0013B8B0();                            /* extern */
s32 sprite_palette_load();                            /* extern */
extern s32 g_default_sprite_palette_as_s32_a[];
extern s32 stage5_boss_fade_palettes_a[];

void stage5_boss_mode_form3_explosion_start(void) {
    reg_d0.h[0] = 0xE;
    reg_a0 = (u8 *)g_default_sprite_palette_as_s32_a;
    sprite_palette_load();
    reg_a0 = (u8 *)stage5_boss_fade_palettes_a;
    func_0013B8B0();
    *(s16 *)(reg_a4 + 2) = 0;
    *(s16 *)(reg_a4 + 6) = 0x101;
    *(s16 *)(reg_a4 + 8) = 0;
    *(s16 *)(reg_a4 + 0xA) = 1;
    *(s8 *)(reg_a4 + 0xD) = 0;
    *(s16 *)(reg_a4 + 0x10) = 0x2020;
    *(s16 *)(reg_a4 + 0x12) = 0;
    stage5_boss_mode_form3_explosion(1, 0x101);
}

extern u8 stage5_boss_flash_palettes_c[];

s32 boss_slots_end();
s32 boss_flash_start();
s32 boss_flash_running();
s32 explosion_burst_medium();
s32 sfx_explosion_ground_medium();
s32 rng_next();
extern u16 D_00264D80[];

/* Death Label runs each emitter twice, once per boss body. */
#ifdef DEATH_LABEL
#define BOSS_X x
#define BOSS_Y y
#else
#define BOSS_X (ENTITY(reg_a6)->y.h)
#define BOSS_Y (ENTITY(reg_a6)->x.h)
#endif

void stage5_boss_mode_form3_explosion() {
#ifdef DEATH_LABEL
    s32 i;
    u16 y;
    u16 x;

#endif
    if (*(u16 *)(reg_a4 + 2) != 4) goto block_3;
    *(u16 *)(reg_a4 + 4) -= 1;
    if (*(u16 *)(reg_a4 + 4) != 0) goto block_rts_2;
    boss_slots_end();
    *(u16 *)(reg_a4 + 0) = 0;
block_rts_2:
    return;
block_3:
    if (*(u16 *)(reg_a4 + 2) != 3) goto block_2;
#ifdef DEATH_LABEL
    y = ENTITY(reg_a6)->x.h;
    x = ENTITY(reg_a6)->y.h;
    for (i = 0; i < 2; i++) {
#endif
    reg_d6.w = 0;
    reg_a1 = (u8 *)D_00264D80;
loop_1:
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    if ((s16)reg_d0.h[0] == -1) goto block_3_end;
    explosion_spawn();
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u8 *)(reg_a0 + 0x1D) = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x26) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 0x28) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 2) = BOSS_X;
    *(u16 *)(reg_a0 + 4) = BOSS_Y;
    *(u16 *)(reg_a0 + 0x1E) = 8;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0;
    rng_next();
    reg_d0.b[0] += 4;
    reg_d0.b[0] += *(u8 *)(reg_a4 + 0xD);
    *(u8 *)(reg_a0 + 0x1B) = reg_d0.b[0];
    rng_next_unsigned();
    *(u8 *)(reg_a0 + 0x1A) = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x18) = reg_d6.h[0];
    reg_d6.h[0] += 1;
    goto loop_1;
block_3_end:
#ifdef DEATH_LABEL
        x = ENTITY(reg_a6)[16].y.h;
        y = ENTITY(reg_a6)[16].x.h;
    }
#endif
    *(u16 *)(reg_a4 + 4) = 0x80;
    *(u16 *)(reg_a4 + 2) = 4;
    sfx_explosion_boss();
    return;
block_2:
    if (*(u16 *)(reg_a4 + 2) != 2) goto block_1;
    boss_flash_running();
    if (cond_flag != 0) goto block_1;
    reg_a0 = (u8 *)stage5_boss_flash_palettes_c;
    func_0013B2E0();
    boss_part_hide_all();
    *(u16 *)(reg_a4 + 0xA) = 1;
    *(u16 *)(reg_a4 + 2) = 3;
    return;
block_1:
    if (*(u16 *)(reg_a4 + 2) != 1) goto block_0;
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x11);
    *(u8 *)(reg_a4 + 0x11) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_1;
    *(u8 *)(reg_a4 + 0x11) = *(u8 *)(reg_a4 + 0x10);
#ifdef DEATH_LABEL
    y = ENTITY(reg_a6)->x.h;
    x = ENTITY(reg_a6)->y.h;
    for (i = 0; i < 2; i++) {
#endif
    rng_next_unsigned();
    reg_d1.b[0] = reg_d0.b[0];
    reg_d2.h[1] = BOSS_X;
    reg_d2.h[0] = BOSS_Y;
    rng_next_word();
    reg_d0.h[0] = (s16)reg_d0.h[0] >> 2;
    reg_d2.h[0] += reg_d0.h[0];
    reg_tmp.w = reg_d2.w;
    reg_d2.h[1] = reg_tmp.h[0];
    reg_d2.h[0] = reg_tmp.h[1];
    rng_next_word();
    reg_d0.h[0] = (s16)reg_d0.h[0] >> 1;
    reg_d2.h[0] += reg_d0.h[0];
    reg_d2.h[0] -= 0x1000;
    reg_tmp.w = reg_d2.w;
    reg_d2.h[1] = reg_tmp.h[0];
    reg_d2.h[0] = reg_tmp.h[1];
    reg_d3.h[0] = 8;
    reg_d0.h[0] = 0;
    explosion_burst_medium();
#ifdef DEATH_LABEL
        x = ENTITY(reg_a6)[16].y.h;
        y = ENTITY(reg_a6)[16].x.h;
    }
#endif
    switch (*(u8 *)(reg_a4 + 6)) { case 2: goto next_1; }
    sfx_explosion_ground_medium();
next_1:
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xF);
    *(u8 *)(reg_a4 + 0xF) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_2;
    *(u8 *)(reg_a4 + 0xF) = *(u8 *)(reg_a4 + 0xE);
    if (*(u8 *)(reg_a4 + 6) == 2) goto next_2;
    *(u8 *)(reg_a4 + 6) -= 1;
    *(u8 *)(reg_a4 + 0xD) += 1;
next_2:
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
    *(u8 *)(reg_a4 + 7) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto block_0;
    *(u8 *)(reg_a4 + 7) = *(u8 *)(reg_a4 + 6);
    if (*(u8 *)(reg_a4 + 6) == 2) goto next_3;
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x12);
    *(u8 *)(reg_a4 + 0x12) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_3;
    *(u8 *)(reg_a4 + 0x12) = 4;
    sfx_explosion_air_large();
next_3:
#ifdef DEATH_LABEL
    y = ENTITY(reg_a6)->x.h;
    x = ENTITY(reg_a6)->y.h;
    for (i = 0; i < 2; i++) {
#endif
    reg_a1 = (u8 *)D_00264D80;
    reg_a1 += *(u16 *)(reg_a4 + 8);
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    explosion_spawn();
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u8 *)(reg_a0 + 0x1D) = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x26) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 0x28) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 2) = BOSS_X;
    *(u16 *)(reg_a0 + 4) = BOSS_Y;
    *(u16 *)(reg_a0 + 0x1E) = 8;
    rng_next();
    reg_d0.b[0] = (s8)reg_d0.b[0] >> 2;
    reg_d0.b[0] += 2;
    reg_d1.b[0] = *(u8 *)(reg_a4 + 0xD);
    reg_d1.b[0] = (s8)reg_d1.b[0] >> 1;
    reg_d0.b[0] += reg_d1.b[0];
    *(u8 *)(reg_a0 + 0x1B) = reg_d0.b[0];
    rng_next_unsigned();
    *(u8 *)(reg_a0 + 0x1A) = reg_d0.b[0];
#ifdef DEATH_LABEL
        x = ENTITY(reg_a6)[16].y.h;
        y = ENTITY(reg_a6)[16].x.h;
    }
#endif
    *(u16 *)(reg_a4 + 8) += 8;
    if (*(u16 *)(reg_a4 + 8) != 0x80) goto block_0;
    *(u16 *)(reg_a4 + 8) = 0;
    if (*(u8 *)(reg_a4 + 6) != 2) goto block_0;
    reg_d0.h[0] = 0xE;
    boss_flash_start();
    *(u16 *)(reg_a4 + 2) = 2;
    return;
block_0:
    if (*(u16 *)(reg_a4 + 2) != 0) return;
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
    *(u8 *)(reg_a4 + 7) -= 1;
    if ((s32)reg_tmp.b[0] > 0) return;
    *(u8 *)(reg_a4 + 7) = *(u8 *)(reg_a4 + 6);
    if (*(u8 *)(reg_a4 + 0x13) & 1) {
        *(u8 *)(reg_a4 + 0x13) &= 0xFE;
        goto next_4;
    }
    *(u8 *)(reg_a4 + 0x13) |= 1;
    reg_a0 = (u8 *)sfx_explosion_air_medium;
    rng_next_unsigned();
    if (!(0 > reg_d0.sb[0])) goto next_5;
    reg_a0 = (u8 *)sfx_explosion_air_large;
next_5:
    reg_call_target = (Fn)reg_a0;
    reg_call_target();
next_4:
#ifdef DEATH_LABEL
    y = ENTITY(reg_a6)->x.h;
    x = ENTITY(reg_a6)->y.h;
    for (i = 0; i < 2; i++) {
#endif
    reg_a1 = (u8 *)D_00264D80;
    reg_a1 += *(u16 *)(reg_a4 + 8);
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    explosion_spawn();
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u8 *)(reg_a0 + 0x1D) = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x26) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 0x28) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 2) = BOSS_X;
    *(u16 *)(reg_a0 + 4) = BOSS_Y;
    *(u16 *)(reg_a0 + 0x1E) = 8;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0;
#ifdef DEATH_LABEL
        x = ENTITY(reg_a6)[16].y.h;
        y = ENTITY(reg_a6)[16].x.h;
    }
#endif
    *(u16 *)(reg_a4 + 8) += 8;
    if ((s32)*(u16 *)(reg_a4 + 8) < 0x80) return;
    *(u16 *)(reg_a4 + 8) = 0;
    *(u16 *)(reg_a4 + 0xA) -= 1;
    if (*(u16 *)(reg_a4 + 0xA) != 0) return;
    *(u16 *)(reg_a4 + 6) = 0x2010;
    *(u16 *)(reg_a4 + 0xE) = 0x1111;
    *(u16 *)(reg_a4 + 2) = 1;
block_rts:
    return;
}

s32 boss_attack_start();                            /* extern */

void stage5_boss_mode_form1_arm_guns_aimed_start(void) {
    reg_d0.w = 2;
    boss_animation_start();
    reg_d0.w = 0;
    boss_attack_start();
    stage5_boss_mode_form1_arm_guns_aimed();
}

s32 boss_phase_start();                            /* extern */
s32 boss_attack_running();                            /* extern */

void stage5_boss_mode_form1_arm_guns_aimed(void) {
    reg_d0.w = 0;
    boss_attack_running();
    if (cond_flag == 0) {
        reg_d0.w = 7;
        boss_phase_start();
        *reg_a4_as_s16_p = 0;
    }
}



void stage5_boss_mode_form1_mouth_start(void) {
    *(u16 *)(reg_a4 + 2) = 0x60;
    stage5_boss_mode_form1_mouth();
}

s32 boss_attack_start();
s32 boss_attack_running();
extern u16 g_bullets_blocked;

void stage5_boss_mode_form1_mouth() {
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 1;
                boss_attack_start();
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 1;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 8;
            boss_phase_start();
            *(s16 *)reg_a4 = 0;
        }
    }
}


void stage5_boss_mode_form1_arm_guns_fixed_start(void) {
    *(s16 *)(reg_a4 + 2) = 0x60;
    stage5_boss_mode_form1_arm_guns_fixed();
}

void stage5_boss_mode_form1_arm_guns_fixed() {
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 2;
                boss_attack_start();
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 2;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 9;
            boss_phase_start();
            *(s16 *)reg_a4 = 0;
        }
    }
}


void stage5_boss_mode_form1_horn_start(void) {
    ((s16 *)((void *)reg_a4))[1] = 0x60;
    ((s16 *)((void *)reg_a4))[2] = 0x40;
    stage5_boss_mode_form1_horn(0x60);
}

void stage5_boss_mode_form1_horn() {
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 3;
                boss_attack_start();
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 3;
        boss_attack_running();
        if (cond_flag == 0) {
            *(u16 *)(reg_a4 + 4) -= 1;
            if (*(u16 *)(reg_a4 + 4) == 0) {
                reg_d0.w = 6;
                boss_phase_start();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}


void stage5_boss_mode_form2_mouth_start(void) {
    *(u16 *)(reg_a4 + 2) = 1;
    stage5_boss_mode_form2_mouth();
}

void stage5_boss_mode_form2_mouth() {
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 5;
                boss_attack_start();
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 5;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 0xB;
            boss_phase_start();
            *(s16 *)reg_a4 = 0;
        }
    }
}


void stage5_boss_mode_form2_jet_start(void) {
    *(s16 *)(reg_a4 + 2) = 0x40;
    stage5_boss_mode_form2_jet();
}

void stage5_boss_mode_form2_jet() {
    s32 boss_movement_start();
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 6;
                boss_attack_start();
                reg_d0.w = 0xE;
                boss_part_hide();
                ENTITY(reg_a6)[11].hit_y_minus.sh = 0;
                reg_d0.w = 5;
                boss_movement_start();
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 6;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 0xE;
            boss_part_show();
            ENTITY(reg_a6)[11].hit_y_minus.sh = 0x1000;
            reg_d0.w = 0xC;
            boss_phase_start();
            *(s16 *)reg_a4 = 0;
        }
    }
}


void stage5_boss_mode_form2_horn_start(void) {
    s32 boss_movement_start(s32);
    *(s16 *)(reg_a4 + 2) = 0x50;
    reg_d0.w = 6;
    boss_movement_start(0x50);
    stage5_boss_mode_form2_horn();
}

void stage5_boss_mode_form2_horn() {
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 7;
                boss_attack_start();
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 7;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 0xD;
            boss_phase_start();
            *(s16 *)reg_a4 = 0;
        }
    }
}


void stage5_boss_mode_form2_stinger_start(void) {
    s32 boss_movement_start(s32, s32);
    *(s16 *)(reg_a4 + 2) = 0x60;
    *(s16 *)(reg_a4 + 4) = 0x40;
    reg_d0.w = 7;
    boss_movement_start(0x40, 0x60);
    ENTITY(reg_a6)->move.sb.speed = 0xC;
    stage5_boss_mode_form2_stinger();
}

void stage5_boss_mode_form2_stinger() {
    s32 boss_movement_start();
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 8;
                boss_attack_start();
                ENTITY(reg_a6)->move.sb.speed = 4;
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 8;
        boss_attack_running();
        if (cond_flag == 0) {
            *(u16 *)(reg_a4 + 4) -= 1;
            if (*(u16 *)(reg_a4 + 4) == 0) {
                reg_d0.w = 0xA;
                boss_phase_start();
                reg_d0.w = 2;
                boss_movement_start();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}


void stage5_boss_mode_form1_rage_start(void) {
    *(s16 *)(reg_a4 + 2) = 0x40;
    *(s16 *)(reg_a4 + 4) = 1;
    ENTITY(reg_a6)[1].misc.sb.user = 0;
    ENTITY(reg_a6)[2].misc.sb.user = 0;
    ENTITY(reg_a6)[3].misc.sb.user = 0;
    ENTITY(reg_a6)[4].misc.sb.user = 0;
    ENTITY(reg_a6)[5].misc.sb.user = 0;
    ENTITY(reg_a6)[6].misc.sb.user = 0;
    stage5_boss_mode_form1_rage();
}

void stage5_boss_mode_form1_rage() {
    u16 temp_a0;
    u16 temp_v1;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 4;
                boss_attack_start();
                goto block_4;
            }
        }
    } else {
block_4:
        temp_v1 = *(u16 *)(reg_a4 + 4);
        if (temp_v1 != 0) {
            *(u16 *)(reg_a4 + 4) = (u16) (temp_v1 - 1);
            if (*(u16 *)(reg_a4 + 4) == 0) {
                stage5_boss_shield_off();
            }
        }
    }
}


void stage5_boss_mode_form3_attack_a_start(void) {
    *(s16 *)(reg_a4 + 2) = 0x60;
    stage5_boss_mode_form3_attack_a();
}

void stage5_boss_mode_form3_attack_a() {
    s32 boss_movement_start();
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 9;
                boss_attack_start();
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 9;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 0x11;
            boss_phase_start();
            reg_d0.w = MAIN_OR_DEATH_LABEL(9, 14);
            boss_movement_start();
            ENTITY(reg_a6)->move.sb.speed = 0xC;
#ifdef DEATH_LABEL
            ENTITY(reg_a6)[16].move.sb.speed = 0xC;
#endif
            *(s16 *)reg_a4 = 0;
        }
    }
}


void stage5_boss_mode_form3_attack_b_start(void) {
    *(s16 *)(reg_a4 + 2) = 0x60;
    stage5_boss_mode_form3_attack_b();
}

void stage5_boss_mode_form3_attack_b() {
    s32 boss_movement_start();
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 0xA;
                boss_attack_start();
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 0xA;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 0xF;
            boss_phase_start();
            reg_d0.w = MAIN_OR_DEATH_LABEL(4, 16);
            boss_movement_start();
            *(s16 *)reg_a4 = 0;
        }
    }
}


void stage5_boss_mode_form3_attack_c_start(void) {
    *(u16 *)(reg_a4 + 2) = 0x60;
    stage5_boss_mode_form3_attack_c();
}

void stage5_boss_mode_form3_attack_c() {
    s32 boss_movement_start();
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 0xB;
                boss_attack_start();
                ENTITY(reg_a6)->move.sb.speed = 4;
#ifdef DEATH_LABEL
                ENTITY(reg_a6)[16].move.sb.speed = 4;
#endif
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 0xB;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 0x10;
            boss_phase_start();
            reg_d0.w = MAIN_OR_DEATH_LABEL(8, 0xD);
            boss_movement_start();
            *(s16 *)reg_a4 = 0;
        }
    }
}


void stage5_boss_mode_form3_attack_d_start(void) {
    ((s16 *)((void *)reg_a4))[1] = 0x60;
    ((s16 *)((void *)reg_a4))[2] = 0x40;
    stage5_boss_mode_form3_attack_d(0x60);
}

void stage5_boss_mode_form3_attack_d() {
    s32 boss_movement_start();
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
            if (*(u16 *)(reg_a4 + 2) == 0) {
                reg_d0.w = 0xC;
                boss_attack_start();
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 0xC;
        boss_attack_running();
        if (cond_flag == 0) {
            *(u16 *)(reg_a4 + 4) -= 1;
            if (*(u16 *)(reg_a4 + 4) == 0) {
                reg_d0.w = 0xF;
                boss_phase_start();
                reg_d0.w = MAIN_OR_DEATH_LABEL(4, 16);
                boss_movement_start();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}


void stage5_boss_mode_form3_rage_start(void) {
    s32 boss_movement_start(s32);
    *(s16 *)(reg_a4 + 2) = 0x60;
    reg_d0.w = MAIN_OR_DEATH_LABEL(0xB, 0x10);
    boss_movement_start(0x60);
    stage5_boss_mode_form3_rage();
}

void stage5_boss_mode_form3_rage() {
    u16 temp_a0;

    temp_a0 = *(u16 *)(reg_a4 + 2);
    if ((temp_a0 != 0) && (g_bullets_blocked == 0)) {
        *(u16 *)(reg_a4 + 2) = (u16) (temp_a0 - 1);
        if (*(u16 *)(reg_a4 + 2) == 0) {
            reg_d0.w = 0xD;
            boss_attack_start();
            stage5_boss_shield_off();
        }
    }
}


void stage5_boss_mode_form1_explosion_afterglow_start(void) {
    *(s16 *)(reg_a4 + 2) = 0x80;
    stage5_boss_mode_form1_explosion_afterglow();
}

void stage5_boss_mode_form1_explosion_afterglow() {
    *(u16 *)(reg_a4 + 2) -= 1;
    if (*(u16 *)(reg_a4 + 2) == 0) {
        boss_slots_end();
        *(s16 *)reg_a4 = 0;
    }
}
