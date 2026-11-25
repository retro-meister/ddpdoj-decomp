#include "common.h"
#include "entity.h"

void stage3_boss_mode_enter_start(void);
void stage3_boss_mode_enter(void);
void stage3_boss_mode_final_explosion_start(void);
void stage3_boss_mode_final_explosion(void);
void stage3_boss_mode_low_main_gun_b_start(void);
void stage3_boss_mode_low_main_gun_b(void);
void stage3_boss_mode_high_six_gun_start(void);
void stage3_boss_mode_high_six_gun(u8 arg0);
void stage3_boss_mode_mid_lid_guns_start(void);
void stage3_boss_mode_mid_lid_guns(void);
void stage3_boss_mode_high_six_gun_b_start(void);
void stage3_boss_mode_high_six_gun_b(void);
void stage3_boss_mode_six_gun_close_wait_start(void);
void stage3_boss_mode_six_gun_close_wait(void);
void stage3_boss_mode_six_gun_b_close_wait_start(void);
void stage3_boss_mode_six_gun_b_close_wait(void);
void stage3_boss_mode_low_all_guns_start(void);
void stage3_boss_mode_low_all_guns(void);
void stage3_boss_mode_phase_explosion_start(void);
void stage3_boss_mode_phase_explosion(void);

/* The set-up routine and the per-frame routine of every mode, by mode number. */
void (*stage3_boss_mode_routines[])(void) = {
    stage3_boss_mode_enter_start,
    stage3_boss_mode_enter,
    stage3_boss_mode_final_explosion_start,
    stage3_boss_mode_final_explosion,
    stage3_boss_mode_low_main_gun_b_start,
    stage3_boss_mode_low_main_gun_b,
    stage3_boss_mode_high_six_gun_start,
    (void (*)(void))stage3_boss_mode_high_six_gun,
    stage3_boss_mode_mid_lid_guns_start,
    stage3_boss_mode_mid_lid_guns,
    stage3_boss_mode_high_six_gun_b_start,
    stage3_boss_mode_high_six_gun_b,
    stage3_boss_mode_six_gun_close_wait_start,
    stage3_boss_mode_six_gun_close_wait,
    stage3_boss_mode_six_gun_b_close_wait_start,
    stage3_boss_mode_six_gun_b_close_wait,
    stage3_boss_mode_low_all_guns_start,
    stage3_boss_mode_low_all_guns,
    stage3_boss_mode_phase_explosion_start,
    stage3_boss_mode_phase_explosion,
};

void stage3_boss_mode_enter(void);
void stage3_boss_mode_final_explosion();
void stage3_boss_mode_low_main_gun_b(void);
void stage3_boss_mode_high_six_gun(u8 arg0);
void stage3_boss_mode_six_gun_close_wait(void);
void stage3_boss_mode_mid_lid_guns(void);
void stage3_boss_mode_high_six_gun_b(void);
void stage3_boss_mode_six_gun_b_close_wait(void);
void stage3_boss_mode_low_all_guns(void);
void stage3_boss_mode_phase_explosion();

s32 boss_movement_start();                            /* extern */
s32 boss_animation_start();                            /* extern */

void stage3_boss_mode_enter_start(void) {
    reg_d0.w = 0;
    boss_movement_start();
    reg_d0.w = 7;
    boss_animation_start();
    stage3_boss_mode_enter();
}

extern s16 *reg_a4_as_s16_p;

void stage3_boss_mode_enter(void) {
    *reg_a4_as_s16_p = 0;
}

s32 func_0013B8B0();                            /* extern */
extern s32 D_0026D990[];

void stage3_boss_mode_final_explosion_start(void) {
    reg_a0 = (u8 *)D_0026D990;
    func_0013B8B0();
    *(s16 *)(reg_a4 + 2) = 0;
    *(s16 *)(reg_a4 + 6) = 0x101;
    *(s16 *)(reg_a4 + 8) = 0;
    *(s16 *)(reg_a4 + 0xA) = 1;
    *(s8 *)(reg_a4 + 0xD) = 0;
    *(s16 *)(reg_a4 + 0x10) = 0x2020;
    *(s16 *)(reg_a4 + 0x12) = 0;
    stage3_boss_mode_final_explosion(1, 0x101);
}

typedef void (*Fn)();

s32 boss_slots_end();
s32 boss_part_hide_all();
s32 boss_flash_start();
s32 boss_flash_running();
s32 explosion_spawn();
s32 explosion_burst_medium();
s32 func_0013B2E0();
s32 sfx_explosion_air_medium();
s32 sfx_explosion_air_large();
s32 sfx_explosion_ground_medium();
s32 sfx_explosion_boss();
s32 rng_next();
s32 rng_next_unsigned();
s32 rng_next_word();
extern u16 D_0026D810[];
extern u16 D_0026D8A0[];

void stage3_boss_mode_final_explosion() {
    u8 bits;

    if (*(u16 *)(reg_a4 + 2) != 4) goto next_s3;
    *(u16 *)(reg_a4 + 4) -= 1;
    if (*(u16 *)(reg_a4 + 4) != 0) goto next_s4rts;
    boss_slots_end();
    *(u16 *)reg_a4 = 0;
next_s4rts:
    return;
next_s3:
    if (*(u16 *)(reg_a4 + 2) != 3) goto next_s2;
    reg_d6.w = 0;
    reg_a1 = (u8 *) D_0026D810;
loop_10:
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    if ((s16) reg_d0.h[0] == -1) goto next_20;
    explosion_spawn();
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0[0x1D] = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x26) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 0x28) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 8;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0;
    rng_next();
    reg_d0.b[0] += 4;
    reg_d0.b[0] += reg_a4[0xD];
    reg_a0[0x1B] = reg_d0.b[0];
    rng_next_unsigned();
    reg_a0[0x1A] = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x18) = reg_d6.h[0];
    reg_d6.h[0] += 1;
    goto loop_10;
next_20:
    *(u16 *)(reg_a4 + 4) = 0x80;
    *(u16 *)(reg_a4 + 2) = 4;
    sfx_explosion_boss();
    return;
next_s2:
    if (*(u16 *)(reg_a4 + 2) != 2) goto next_s1;
    boss_flash_running();
    if (cond_flag != 0) goto next_s1;
    reg_a0 = (u8 *) D_0026D8A0;
    func_0013B2E0();
    boss_part_hide_all();
    *(u16 *)(reg_a4 + 0xA) = 1;
    *(u16 *)(reg_a4 + 2) = 3;
    return;
next_s1:
    if (*(u16 *)(reg_a4 + 2) != 1) goto next_s0;
    reg_tmp.b[0] = reg_a4[0x11];
    reg_a4[0x11] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_reon;
    reg_a4[0x11] = reg_a4[0x10];
    rng_next_unsigned();
    reg_d1.b[0] = reg_d0.b[0];
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    rng_next_word();
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 2;
    reg_d2.h[0] += reg_d0.h[0];
    reg_tmp2.w = reg_d2.w;
    reg_d2.h[1] = reg_d2.h[0];
    reg_d2.h[0] = reg_tmp2.h[1];
    rng_next_word();
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 1;
    reg_d2.h[0] += reg_d0.h[0];
    reg_d2.h[0] -= 0x1000;
    reg_tmp2.w = reg_d2.w;
    reg_d2.h[1] = reg_d2.h[0];
    reg_d2.h[0] = reg_tmp2.h[1];
    reg_d3.h[0] = 8;
    reg_d0.h[0] = 0;
    explosion_burst_medium();
    if (reg_a4[6] == 2) goto next_reon;
    sfx_explosion_ground_medium();
next_reon:
    reg_tmp.b[0] = reg_a4[0xF];
    reg_a4[0xF] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_intdec;
    reg_a4[0xF] = reg_a4[0xE];
    if (reg_a4[6] == 2) goto next_intdec;
    reg_a4[6] -= 1;
    reg_a4[0xD] += 1;
next_intdec:
    reg_tmp.b[0] = reg_a4[7];
    reg_a4[7] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_s0;
    reg_a4[7] = reg_a4[6];
    if (reg_a4[6] == 2) goto next_intdec20;
    reg_tmp.b[0] = reg_a4[0x12];
    reg_a4[0x12] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_intdec20;
    reg_a4[0x12] = 4;
    sfx_explosion_air_large();
next_intdec20:
    reg_a1 = (u8 *) D_0026D810;
    reg_a1 += *(u16 *)(reg_a4 + 8);
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    explosion_spawn();
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0[0x1D] = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x26) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 0x28) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 8;
    rng_next();
    reg_d0.b[0] = (s8) reg_d0.b[0] >> 2;
    reg_d0.b[0] += 2;
    reg_d1.b[0] = reg_a4[0xD];
    reg_d1.b[0] = (s8) reg_d1.b[0] >> 1;
    reg_d0.b[0] += reg_d1.b[0];
    reg_a0[0x1B] = reg_d0.b[0];
    rng_next_unsigned();
    reg_a0[0x1A] = reg_d0.b[0];
    *(u16 *)(reg_a4 + 8) += 8;
    if (*(u16 *)(reg_a4 + 8) != 0x80) goto next_s0;
    *(u16 *)(reg_a4 + 8) = 0;
    if (reg_a4[6] != 2) goto next_s0;
    reg_d0.h[0] = 0xA;
    boss_flash_start();
    *(u16 *)(reg_a4 + 2) = 2;
    return;
next_s0:
    if (*(u16 *)(reg_a4 + 2) != 0) goto block_rts;
    reg_tmp.b[0] = reg_a4[7];
    reg_a4[7] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts;
    reg_a4[7] = reg_a4[6];
    bits = reg_a4[0x13];
    if (bits & 1) {
        reg_a4[0x13] = bits & 0xFE;
        goto next_40;
    }
    reg_a4[0x13] = bits | 1;
    reg_a0 = (u8 *) sfx_explosion_air_medium;
    rng_next_unsigned();
    if (reg_d0.sb[0] >= 0) goto next_30;
    reg_a0 = (u8 *) sfx_explosion_air_large;
next_30:
    reg_call_target = (Fn) reg_a0;
    reg_call_target();
next_40:
    reg_a1 = (u8 *) D_0026D810;
    reg_a1 += *(u16 *)(reg_a4 + 8);
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    explosion_spawn();
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0[0x1D] = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x26) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 0x28) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 8;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0;
    *(u16 *)(reg_a4 + 8) += 8;
    if ((s32) *(u16 *)(reg_a4 + 8) < 0x80) goto block_rts;
    *(u16 *)(reg_a4 + 8) = 0;
    *(u16 *)(reg_a4 + 0xA) -= 1;
    if (*(u16 *)(reg_a4 + 0xA) != 0) goto block_rts;
    *(u16 *)(reg_a4 + 6) = 0x2010;
    *(u16 *)(reg_a4 + 0xE) = 0x1111;
    *(u16 *)(reg_a4 + 2) = 1;
block_rts:
    return;
}

s32 boss_movement_start();                            /* extern */
s32 boss_attack_start();                            /* extern */

void stage3_boss_mode_low_main_gun_b_start(void) {
    reg_d0.w = 1;
    boss_movement_start();
    reg_d0.w = 6;
    boss_attack_start();
    reg_d0.w = 7;
    boss_attack_start();
    stage3_boss_mode_low_main_gun_b();
}

s32 boss_phase_start();                            /* extern */
s32 boss_attack_running();                            /* extern */

void stage3_boss_mode_low_main_gun_b(void) {
    reg_d0.w = 6;
    boss_attack_running();
    if (cond_flag == 0) {
        reg_d0.w = 3;
        boss_phase_start();
        *reg_a4_as_s16_p = 0;
    }
}

s32 boss_movement_start();                            /* extern */
s32 boss_animation_start();                            /* extern */

void stage3_boss_mode_high_six_gun_start(void) {
    u8 temp_a0;
    u8 temp_v0;

    reg_d0.w = 2;
    boss_movement_start();
    reg_d0.w = 4;
    boss_animation_start();
    temp_a0 = ENTITY(reg_a6)[8].hit_x_plus.b[1];
    *(u8 *)(reg_a0 + 3) = temp_a0;
    *(s8 *)(reg_a0 + 2) = 1;
    temp_v0 = ENTITY(reg_a6)[8].hit_x_plus.b[1];
    if ((s32) temp_v0 < 0x11) {
        stage3_boss_mode_high_six_gun(temp_a0);
        return;
    }
    ENTITY(reg_a6)[8].hit_x_plus.b[1] = (u8) (temp_v0 - 0x30);
    stage3_boss_mode_high_six_gun(temp_a0);
}

s32 boss_phase_start();                            /* extern */
s32 boss_animation_running();                            /* extern */
s32 boss_attack_start();                            /* extern */

void stage3_boss_mode_high_six_gun(u8 arg0) {
    reg_d0.w = 4;
    boss_animation_running();
    if (cond_flag == 0) {
        reg_d0.w = 5;
        boss_attack_start();
        reg_d0.w = 6;
        boss_phase_start();
        *reg_a4_as_s16_p = 0;
    }
}


void stage3_boss_mode_six_gun_close_wait_start(void) {
    stage3_boss_mode_six_gun_close_wait();
}

s32 boss_phase_start();                            /* extern */
s32 boss_animation_running();                            /* extern */
s32 boss_attack_running();                            /* extern */

void stage3_boss_mode_six_gun_close_wait(void) {
    reg_d0.w = 5;
    boss_attack_running();
    if (cond_flag == 0) {
        reg_d0.w = 5;
        boss_animation_running();
        if (cond_flag == 0) {
            reg_d0.w = 4;
            boss_phase_start();
            *reg_a4_as_s16_p = 0;
        }
    }
}

s32 boss_movement_start();                            /* extern */
s32 boss_attack_start();                            /* extern */

void stage3_boss_mode_mid_lid_guns_start(void) {
    reg_d0.w = 3;
    boss_movement_start();
    reg_d0.w = 3;
    boss_attack_start();
    reg_d0.w = 4;
    boss_attack_start();
    stage3_boss_mode_mid_lid_guns();
}

s32 boss_phase_start();                            /* extern */
s32 boss_attack_running();                            /* extern */

void stage3_boss_mode_mid_lid_guns(void) {
    reg_d0.w = 4;
    boss_attack_running();
    if (cond_flag == 0) {
        reg_d0.w = 5;
        boss_phase_start();
        *reg_a4_as_s16_p = 0;
    }
}

s32 boss_animation_start();                            /* extern */

void stage3_boss_mode_high_six_gun_b_start(void) {
    reg_d0.w = 4;
    boss_animation_start();
    *(s16 *)(reg_a0 + 2) = 0x5001;
    stage3_boss_mode_high_six_gun_b();
}

s32 boss_phase_start();                            /* extern */
s32 boss_animation_running();                            /* extern */
s32 boss_attack_start();                            /* extern */

void stage3_boss_mode_high_six_gun_b(void) {
    reg_d0.w = 4;
    boss_animation_running();
    if (cond_flag == 0) {
        reg_d0.w = 8;
        boss_attack_start();
        reg_d0.w = 7;
        boss_phase_start();
        *reg_a4_as_s16_p = 0;
    }
}


void stage3_boss_mode_six_gun_b_close_wait_start(void) {
    *(s16 *)(reg_a4 + 2) = 0;
    stage3_boss_mode_six_gun_b_close_wait();
}

s32 boss_phase_start(void *);                      /* extern */
s32 boss_animation_running();                            /* extern */
s32 boss_attack_running(void *);                      /* extern */

void stage3_boss_mode_six_gun_b_close_wait(void) {
    u16 temp_v1;
    u8 *temp_a0;

    temp_a0 = reg_a4 + 2;
    temp_v1 = *(u16 *)(reg_a4 + 2);
    if (temp_v1 != 0) {
        *(u16 *)(reg_a4 + 2) = (u16) (temp_v1 - 1);
        if (*(u16 *)(reg_a4 + 2) == 0) {
            reg_d0.w = 2;
            boss_phase_start(temp_a0);
            *(s16 *)reg_a4 = 0;
        }
    } else {
        reg_d0.w = 8;
        boss_attack_running(temp_a0);
        if (cond_flag == 0) {
            reg_d0.w = 5;
            boss_animation_running();
            if (cond_flag == 0) {
                *(u16 *)(reg_a4 + 2) = 1U;
            }
        }
    }
}

s32 boss_movement_start(s32);                     /* extern */

void stage3_boss_mode_low_all_guns_start(void) {
    *(s16 *)(reg_a4 + 2) = 0x80;
    reg_d0.w = 1;
    boss_movement_start(0x80);
    stage3_boss_mode_low_all_guns();
}

s32 boss_animation_start();
s32 boss_attack_start();
s32 func_001D4550();

void stage3_boss_mode_low_all_guns() {
    *(u16 *)(reg_a4 + 2) -= 1;
    if ((s16) *(u16 *)(reg_a4 + 2) < 0) {
        reg_d0.w = 2;
        boss_animation_start();
        reg_d0.w = 1;
        boss_attack_start();
        reg_d0.w = 2;
        boss_attack_start();
        func_001D4550();
        *(s16 *)reg_a4 = 0;
    }
}

typedef struct WorkRegA4 {
    u8 pad0[2];
    u16 unk2;
    u16 unk4;
    u16 unk6;
} WorkRegA4;


void stage3_boss_mode_phase_explosion_start(void) {
    ((WorkRegA4 *)reg_a4)->unk2 = 0x40;
    ((WorkRegA4 *)reg_a4)->unk4 = 0x404;
    ((WorkRegA4 *)reg_a4)->unk6 = 0x17;
    stage3_boss_mode_phase_explosion(0x404, 0x40);
}

s32 boss_phase_start();
s32 boss_part_hide();
s32 rng_next_masked();
s32 func_002013F0();
extern u8 D_0026D9C0[];

void stage3_boss_mode_phase_explosion() {
    u16 temp_a2;
    u16 temp_v1;

    temp_v1 = *(u16 *)(reg_a4 + 2);
    if (temp_v1 != 0) {
        *(u16 *)(reg_a4 + 2) = (u16) (temp_v1 - 1);
        if (*(u16 *)(reg_a4 + 2) == 0) {
            reg_d0.w = 8;
            boss_part_hide();
        }
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
        reg_a0 = (u8 *)sfx_explosion_air_medium;
        rng_next_unsigned();
        if ((s8) reg_d0.b[0] >= 0) {
            reg_a0 = (u8 *)sfx_explosion_air_large;
        }
        reg_call_target = (Fn)(reg_a0);
        reg_call_target();
        rng_next_unsigned();
        reg_d0.h[0] &= 7;
        reg_d0.h[0] = *(u16 *)(D_0026D9C0 + (reg_d0.h[0] * 2));
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        temp_a2 = ENTITY(reg_a6)->x.h;
        *(u16 *)(reg_a0 + 4) = temp_a2;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x800;
        *(s8 *)(reg_a0 + 0x1B) = 2;
        rng_next_masked();
        reg_d0.b[0] += 0x60;
        *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
        *(s16 *)(reg_a0 + 0x20) = 0;
        *(u16 *)(reg_a0 + 0x22) = 0xFFF9;
        func_002013F0();
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += 0x7FFF + 0x6641;
        *(u16 *)(reg_a0 + 0x26) = (u16) reg_d1.h[0];
        func_002013F0();
        reg_d0.h[0] = reg_d1.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d0.h[0];
        *(u16 *)(reg_a0 + 0x28) = (u16) reg_d1.h[0];
        *(u16 *)(reg_a4 + 6) -= 1;
        if ((s16) *(u16 *)(reg_a4 + 6) < 0) {
            reg_d0.w = 8;
            boss_phase_start();
            *(s16 *)reg_a4 = 0;
        }
    }
}
