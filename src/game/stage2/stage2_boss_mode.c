#include "common.h"
#ifdef DDPDOJ_PC
#include "pc_gameplay_abi.h"
#endif
#include "entity.h"
#include "explosion.h"
#include "stage2_boss.h"
#include "enemy.h"

void stage2_boss_mode_enter_start(void);
void stage2_boss_mode_enter(void);
void stage2_boss_mode_second_phase_start(void);
void stage2_boss_mode_second_phase(void);
void stage2_boss_mode_final_explosion_start(void);
void stage2_boss_mode_final_explosion(void);
void stage2_boss_mode_high_slow_start(void);
void stage2_boss_mode_high_slow(void);
void stage2_boss_mode_high_fast_start(void);
void stage2_boss_mode_high_fast(void);
void stage2_boss_mode_recoil_start(void);
void stage2_boss_mode_recoil(void);
void stage2_boss_mode_rise_start(void);
void stage2_boss_mode_rise(void);
void stage2_boss_mode_rise_sway_start(void);
void stage2_boss_mode_rise_sway(void);
void stage2_boss_mode_rage_start(void);
void stage2_boss_mode_rage(void);

/* The mode part of the boss slot (reg_a4), one record per mode. */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 step;
    /* 0x04 */ u16 delay;
} RiseMode;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 step;
    /* 0x04 */ u16 delay;
    /* 0x06 */ SlotTimer effect_timer;
    /* 0x08 */ u16 unread_08;
    /* 0x0A */ u8 unused_0A[10];
    /* 0x14 */ u16 effect;
} SecondPhaseMode;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 step;               /* 0, 1: rounds of explosions, 2: flash, 3: last blast, 4: wait */
    /* 0x04 */ u16 delay;
    /* 0x06 */ SlotTimer blast_timer;
    /* 0x08 */ u16 blast;
    /* 0x0A */ u16 rounds_left;
    /* 0x0C */ u8 unused_0C;
    /* 0x0D */ u8 force;
    /* 0x0E */ SlotTimer speedup;
    /* 0x10 */ SlotTimer burst;
    /* 0x12 */ SlotTimer effect_timer;
    /* 0x14 */ u16 effect;
} FinalExplosionMode;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 step;
    /* 0x04 */ u16 delay;
    /* 0x06 */ u16 last_attack;
    /* 0x08 */ u16 attacks_done;
    /* 0x0A */ u16 knee_rounds;
    /* 0x0C */ SlotTimer knee;
    /* 0x0E */ SlotTimer missile_pace;
    /* 0x10 */ u16 rounds_left;
} HighSlowMode;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 gun_step;
    /* 0x03 */ u8 step;
    /* 0x04 */ u16 delay;
    /* 0x06 */ SlotTimer torso;
    /* 0x08 */ u16 torso_shots;
    /* 0x0A */ u8 unused_0A;
    /* 0x0B */ u8 torso_side;         /* 1 or -1, changes with every attack */
    /* 0x0C */ SlotTimer volleys;
    /* 0x0E */ u16 unused_0E;
    /* 0x10 */ SlotTimer pause_a;
    /* 0x12 */ SlotTimer pause_b;
    /* 0x14 */ u8 level_b;
    /* 0x15 */ u8 level_a;
    /* 0x16 */ SlotTimer body;
    /* 0x18 */ Field16 body_arg;
    /* 0x1A */ SlotTimer body_volleys;
} HighFastMode;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 step;
    /* 0x04 */ u16 delay;
    /* 0x06 */ SlotTimer shot;
    /* 0x08 */ u16 shots_left;
    /* 0x0A */ Field16 aim;
} RecoilMode;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 started;
    /* 0x03 */ u8 step;
    /* 0x04 */ u16 delay;
    /* 0x06 */ u16 waypoint;
    /* 0x08 */ u16 path[2];           /* address of the table, high word first */
    /* 0x0C */ u16 side;              /* 1 or -1 */
} RiseSwayMode;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 step;
    /* 0x04 */ u16 delay;
    /* 0x06 */ u16 unread_06;
    /* 0x08 */ u16 unused_08[2];
    /* 0x0C */ u16 unread_0C;
} RageMode;

#define RISE(pointer) ((RiseMode *)(pointer))
#define SECOND_PHASE(pointer) ((SecondPhaseMode *)(pointer))
#define FINAL_EXPLOSION(pointer) ((FinalExplosionMode *)(pointer))
#define HIGH_SLOW(pointer) ((HighSlowMode *)(pointer))
#define HIGH_FAST(pointer) ((HighFastMode *)(pointer))
#define RECOIL_MODE(pointer) ((RecoilMode *)(pointer))
#define RISE_SWAY(pointer) ((RiseSwayMode *)(pointer))
#define RAGE(pointer) ((RageMode *)(pointer))

/* The set-up routine and the per-frame routine of every mode, by mode number. */
void (*stage2_boss_mode_routines[])(void) = {
    stage2_boss_mode_enter_start,
    stage2_boss_mode_enter,
    stage2_boss_mode_second_phase_start,
    stage2_boss_mode_second_phase,
    stage2_boss_mode_final_explosion_start,
    stage2_boss_mode_final_explosion,
    stage2_boss_mode_high_slow_start,
    stage2_boss_mode_high_slow,
    stage2_boss_mode_high_fast_start,
    stage2_boss_mode_high_fast,
    stage2_boss_mode_recoil_start,
    stage2_boss_mode_recoil,
    stage2_boss_mode_rise_start,
    stage2_boss_mode_rise,
    stage2_boss_mode_rise_sway_start,
    stage2_boss_mode_rise_sway,
    stage2_boss_mode_rage_start,
    stage2_boss_mode_rage,
    0,
    0,
};

void sfx_explosion_air_small();
void sfx_explosion_air_medium();
void sfx_explosion_ground_small();
void sfx_explosion_ground_medium();

s16 stage2_boss_second_phase_blasts[32] = {
    BLAST(0, 0x09, 0, -0x800, 0xCC0),
    BLAST(2, 0x05, 0, -0xC00, 0x600),
    BLAST(4, 0x05, 0, -0xA00, -0x680),
    BLAST(0, 0x09, 0, -0x800, -0xCC0),
    BLAST_END,
};

void (*stage2_boss_blast_sounds[8])(void) = {
    sfx_explosion_air_small,
    sfx_explosion_air_medium,
    sfx_explosion_air_small,
    sfx_explosion_air_medium,
    sfx_explosion_ground_small,
    sfx_explosion_air_small,
    sfx_explosion_ground_medium,
    sfx_explosion_ground_small,
};

s16 stage2_boss_final_blasts[88] = {
    BLAST_NOW(0x09, 0, 0, 0),
    BLAST_NOW(0x85, 0, -0x1800, 0xA00),
    BLAST_NOW(0x0C, 0, -0x1000, -0x600),
    BLAST_NOW(0x85, 0, -0x2400, -0x200),
    BLAST_NOW(0x09, 0, -0x400, 0x800),
    BLAST_NOW(0x8C, 0, 0x800, -0xA00),
    BLAST_NOW(0x09, 0, -0x800, -0xC00),
    BLAST_NOW(0x85, 0, -0x1C00, 0xC00),
    BLAST_NOW(0x09, 0, 0, 0),
    BLAST_NOW(0x85, 0, -0x1800, -0xA00),
    BLAST_NOW(0x0C, 0, -0x1000, 0x600),
    BLAST_NOW(0x85, 0, -0x2400, 0x200),
    BLAST_NOW(0x09, 0, -0x400, -0x800),
    BLAST_NOW(0x8C, 0, 0x800, 0xA00),
    BLAST_NOW(0x09, 0, -0x800, 0xC00),
    BLAST_NOW(0x85, 0, -0x1C00, -0xC00),
    BLAST_END,
};

u16 stage2_boss_flash_palettes[16] = {
    0x0002, 0x7FFF, 0x0000, 0x0780, 0x0004, 0x0005, 0x001F, 0x0004,
    0x7FFF, 0x0008, 0x0400, 0x000B, 0x000C, 0x001F, 0x0004, 0x0000,
};

u16 stage2_boss_fade_palettes[40] = {
    0x0006, 0x0000, 0x0400, 0x0003, 0x0004, 0x001F, 0x0014, 0x0000,
    0x0440, 0x0009, 0x000A, 0x001F, 0x0014, 0x0000, 0x0480, 0x000F,
    0x0010, 0x001F, 0x0014, 0x0000, 0x05C0, 0x0015, 0x0016, 0x001F,
    0x0014, 0x0000, 0x0340, 0x001B, 0x001C, 0x001F, 0x0014, 0x0000,
    0x04C0, 0x0021, 0x0022, 0x001F, 0x0014, 0x0000, 0x0000, 0x0000,
};

/* attack, shots */
u16 stage2_boss_high_slow_attacks[4][2] = {
    { 6, 0x40 },
    { 7, 0xA0 },
    { 8, 0x40 },
    { 9, 0x30 },
};

u16 stage2_boss_rise_sway_waypoints[8] = {
    0x4600, 0x3800, 0x5600, 0x0800, 0x6400, 0x1C00, 0xFFFF, 0x0000,
};

void stage2_boss_mode_enter(void);
void stage2_boss_mode_second_phase();
void stage2_boss_mode_final_explosion();
void stage2_boss_mode_high_slow();
void stage2_boss_mode_high_fast();
void stage2_boss_mode_recoil();
void stage2_boss_mode_rise_sway(void);
void stage2_boss_rise_sway_next(void);
void stage2_boss_mode_rage(void);

#ifndef DDPDOJ_PC
s32 boss_movement_start();                            /* extern */
#endif
s32 boss_animation_start();                            /* extern */

void stage2_boss_mode_enter_start(void) {
    reg_d0.w = 0;
    boss_movement_start();
    reg_d0.w = 0;
    boss_animation_start();
    reg_d0.w = 2;
    boss_animation_start();
    reg_d0.w = 0xB;
    boss_animation_start();
    reg_d0.w = 0xC;
    boss_animation_start();
    reg_d0.w = 0xD;
    boss_animation_start();
    stage2_boss_mode_enter();
}


void stage2_boss_mode_enter(void) {
    RISE(reg_a4)->running = 0;
}

#ifndef DDPDOJ_PC
s32 boss_movement_start();                            /* extern */
#endif
s32 stage2_boss_shield_on();                            /* extern */
s32 stage2_boss_part_take_hits();                            /* extern */
s32 stage2_boss_part_stop_hits();                            /* extern */

void stage2_boss_mode_second_phase_start(void) {
    reg_d0.w = 3;
    boss_movement_start();
    reg_d0.h[0] = 0x100;
    stage2_boss_part_stop_hits();
    reg_d0.h[0] = 0;
    stage2_boss_part_take_hits();
    reg_d0.h[0] = 0x20;
    stage2_boss_part_take_hits();
    stage2_boss_shield_on();
    SECOND_PHASE(reg_a4)->step = 0;
    SECOND_PHASE(reg_a4)->delay = 0x10;
    SECOND_PHASE(reg_a4)->effect_timer.h = 4;
    SECOND_PHASE(reg_a4)->unread_08 = 0;
#ifdef DDPDOJ_PC
    SECOND_PHASE(reg_a4)->effect = 0;
#endif
    ARCADE_REGISTER_CALL(stage2_boss_mode_second_phase, 0x10);
}

typedef void (*Fn)();

#ifndef DDPDOJ_PC
s32 boss_phase_start();
#endif
s32 boss_part_hide();
s32 stage2_boss_explosions_from_table();

void stage2_boss_mode_second_phase() {
    if (SECOND_PHASE(reg_a4)->step == 0) {
        reg_a1 = (u8 *)stage2_boss_second_phase_blasts;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        stage2_boss_explosions_from_table();
        SECOND_PHASE(reg_a4)->step = 1U;
    }
    if (SECOND_PHASE(reg_a4)->step == 1) {
        reg_tmp.b[0] = SECOND_PHASE(reg_a4)->effect_timer.t.count;
        SECOND_PHASE(reg_a4)->effect_timer.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            SECOND_PHASE(reg_a4)->effect_timer.t.count = (u8) SECOND_PHASE(reg_a4)->effect_timer.t.reload;
#ifdef DDPDOJ_PC
            reg_a0 = ARCADE_POINTER_TABLE_AT(u8 *, stage2_boss_blast_sounds, SECOND_PHASE(reg_a4)->effect);
#else
            reg_a0 = (u8 *)stage2_boss_blast_sounds;
            reg_a0 += SECOND_PHASE(reg_a4)->effect;
            reg_a0 = *(u8 **)reg_a0;
#endif
            reg_call_target = (Fn)(reg_a0);
            reg_call_target();
            SECOND_PHASE(reg_a4)->effect += 4;
#ifdef DDPDOJ_PC
            SECOND_PHASE(reg_a4)->effect &= 0x1F;
#else
            SECOND_PHASE(reg_a4)->unread_08 &= 0x1F;
#endif
        }
        SECOND_PHASE(reg_a4)->delay -= 1;
        if (SECOND_PHASE(reg_a4)->delay == 0) {
            reg_d0.w = 2;
            boss_part_hide();
            SECOND_PHASE(reg_a4)->running = 0;
            reg_d0.w = 4;
            boss_phase_start();
        }
    }
}

#ifndef DDPDOJ_PC
s32 boss_movement_start();                            /* extern */
#endif
s32 fade_out_and_release();                            /* extern */

void stage2_boss_mode_final_explosion_start(void) {
    reg_d0.w = 1;
    boss_movement_start();
    reg_a0 = (u8 *)stage2_boss_fade_palettes;
    fade_out_and_release();
    FINAL_EXPLOSION(reg_a4)->step = 0;
    FINAL_EXPLOSION(reg_a4)->blast_timer.h = 0x101;
    FINAL_EXPLOSION(reg_a4)->blast = 0;
    FINAL_EXPLOSION(reg_a4)->rounds_left = 1;
    FINAL_EXPLOSION(reg_a4)->force = 0;
    FINAL_EXPLOSION(reg_a4)->burst.h = 0x2020;
    FINAL_EXPLOSION(reg_a4)->effect_timer.h = 4;
    FINAL_EXPLOSION(reg_a4)->effect = 0;
    ARCADE_REGISTER_CALL(stage2_boss_mode_final_explosion, 0x2020, 1, 0x101);
}


s32 boss_slots_end();
s32 boss_part_hide_all();
s32 boss_flash_start();
s32 boss_flash_running();
s32 explosion_spawn();
s32 explosion_burst_medium();
s32 fade_in_and_release();
void sfx_explosion_ground_medium();
s32 sfx_explosion_boss();
s32 rng_next();
s32 rng_next_unsigned();
s32 rng_next_word();

void stage2_boss_mode_final_explosion() {
    u16 *t1;
    u16 *t2;
    u32 t3;
    u32 t4;
    u32 t5;
    u32 t6;
    u8 t7;
    u8 t8;
    u8 t9;
    u8 t10;
    u8 t11;
    u8 *v1;

    v1 = (u8 *)(reg_a4);
    t7 = FINAL_EXPLOSION(v1)->step;
    if (t7 == 4) {
        FINAL_EXPLOSION(v1)->delay -= 1;
        if (FINAL_EXPLOSION(reg_a4)->delay != 0) {
            goto block_rts;
        }
        boss_slots_end();
        FINAL_EXPLOSION(reg_a4)->running = 0;
block_rts:
        return;
    } else {
        if (t7 == 3) {
            reg_d6.w = 0;
            reg_a1 = (u8 *)(stage2_boss_final_blasts);
loop_6:
            t3 = *(u16 *)reg_a1;
            reg_d0.h[0] = t3;
            reg_a1 += 2;
            if (reg_d0.h[0] != 0xFFFF) {
                explosion_spawn();
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                EXPLOSION(reg_a0)->attr.b.flip = (u8) reg_d0.b[0];
                EXPLOSION(reg_a0)->start_y = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                EXPLOSION(reg_a0)->start_x = (u16) *(u16 *)reg_a1;
                t1 = (u16 *)(reg_a1 + 2);
                reg_a1 = (u8 *)(t1);
                EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
                t4 = ENTITY(reg_a6)->x.h;
                EXPLOSION(reg_a0)->x = t4;
                EXPLOSION(reg_a0)->draw_layer = 8;
                EXPLOSION(reg_a0)->debris = 0;
                EXPLOSION(reg_a0)->debris_arg = 0;
                rng_next();
                reg_d0.b[0] += 4;
                reg_d0.b[0] += FINAL_EXPLOSION(reg_a4)->force;
                EXPLOSION(reg_a0)->move.b.speed = (u8) reg_d0.b[0];
                rng_next_unsigned();
                EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
                EXPLOSION(reg_a0)->delay = (u16) reg_d6.h[0];
                reg_d6.h[0] += 1;
                reg_a1 += 2;
                goto loop_6;
            }
            reg_d0.h[0] = 0x1E;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            t6 = ENTITY(reg_a6)->x.h;
            EXPLOSION(reg_a0)->x = t6;
            reg_tmp.w = 0xF4000000;
            EXPLOSION(reg_a0)->start_y = (u16) reg_tmp.h[1];
            EXPLOSION(reg_a0)->start_x = (u16) reg_tmp.h[0];
            EXPLOSION(reg_a0)->draw_layer = 4;
            sfx_explosion_boss();
            v1 = (u8 *)((void *)0x80);
            FINAL_EXPLOSION(reg_a4)->delay = 0x80U;
            FINAL_EXPLOSION(reg_a4)->step = 4U;
        }
        t9 = FINAL_EXPLOSION(reg_a4)->step;
        if (t9 == 2) {
            boss_flash_running();
            if (cond_flag == 0) {
                reg_a0 = (u8 *)stage2_boss_flash_palettes;
                fade_in_and_release();
                boss_part_hide_all();
                FINAL_EXPLOSION(reg_a4)->step = 3U;
                FINAL_EXPLOSION(reg_a4)->rounds_left = 1U;
            }
        }
        t10 = FINAL_EXPLOSION(reg_a4)->step;
        if (t10 == 1) {
            reg_tmp.b[0] = FINAL_EXPLOSION(reg_a4)->burst.t.count;
            FINAL_EXPLOSION(reg_a4)->burst.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                FINAL_EXPLOSION(reg_a4)->burst.t.count = (u8) FINAL_EXPLOSION(reg_a4)->burst.t.reload;
                rng_next_unsigned();
                reg_d1.b[0] = reg_d0.b[0];
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                rng_next_word();
                reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
                reg_d2.h[0] += reg_d0.h[0];
                reg_tmp2.w = reg_d2.w;
                reg_d2.h[1] = reg_d2.h[0];
                reg_d2.h[0] = reg_tmp2.h[1];
                rng_next_word();
                reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
                reg_d2.h[0] += reg_d0.h[0];
                reg_d2.h[0] -= 0x1000;
                reg_tmp2.w = reg_d2.w;
                reg_d2.h[1] = reg_d2.h[0];
                reg_d2.h[0] = reg_tmp2.h[1];
                reg_d3.h[0] = 8;
                reg_d0.h[0] = 0;
                explosion_burst_medium();
                sfx_explosion_ground_medium();
            }
            reg_tmp.b[0] = FINAL_EXPLOSION(reg_a4)->speedup.t.count;
            FINAL_EXPLOSION(reg_a4)->speedup.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                FINAL_EXPLOSION(reg_a4)->speedup.t.count = (u8) FINAL_EXPLOSION(reg_a4)->speedup.t.reload;
                t11 = FINAL_EXPLOSION(reg_a4)->blast_timer.t.reload;
                if (t11 != 2) {
                    FINAL_EXPLOSION(reg_a4)->blast_timer.t.reload = (u8) (t11 - 1);
                    FINAL_EXPLOSION(reg_a4)->force += 1;
                }
            }
            reg_tmp.b[0] = FINAL_EXPLOSION(reg_a4)->blast_timer.t.count;
            FINAL_EXPLOSION(reg_a4)->blast_timer.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                FINAL_EXPLOSION(reg_a4)->blast_timer.t.count = (u8) FINAL_EXPLOSION(reg_a4)->blast_timer.t.reload;
                reg_tmp.b[0] = FINAL_EXPLOSION(reg_a4)->effect_timer.t.count;
                FINAL_EXPLOSION(reg_a4)->effect_timer.t.count -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    FINAL_EXPLOSION(reg_a4)->effect_timer.t.count = (u8) FINAL_EXPLOSION(reg_a4)->effect_timer.t.reload;
#ifdef DDPDOJ_PC
                    reg_a0 = ARCADE_POINTER_TABLE_AT(u8 *, stage2_boss_blast_sounds, FINAL_EXPLOSION(reg_a4)->effect);
#else
                    reg_a0 = (u8 *)stage2_boss_blast_sounds;
                    reg_a0 += FINAL_EXPLOSION(reg_a4)->effect;
                    reg_a0 = *(u8 **)reg_a0;
#endif
                    reg_call_target = (Fn)(reg_a0);
                    reg_call_target();
                    FINAL_EXPLOSION(reg_a4)->effect += 4;
                    FINAL_EXPLOSION(reg_a4)->effect &= 0x1F;
                }
                reg_a1 = (u8 *)(stage2_boss_final_blasts);
                reg_a1 += FINAL_EXPLOSION(reg_a4)->blast;
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                explosion_spawn();
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                EXPLOSION(reg_a0)->attr.b.flip = (u8) reg_d0.b[0];
                EXPLOSION(reg_a0)->start_y = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                EXPLOSION(reg_a0)->start_x = (u16) *(u16 *)reg_a1;
                t2 = (u16 *)(reg_a1 + 2);
                reg_a1 = (u8 *)(t2);
                EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
                t5 = ENTITY(reg_a6)->x.h;
                EXPLOSION(reg_a0)->x = t5;
                EXPLOSION(reg_a0)->draw_layer = 8;
                rng_next();
                reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 2);
                reg_d0.b[0] += 2;
                reg_d1.b[0] = FINAL_EXPLOSION(reg_a4)->force;
                reg_d1.b[0] = (u8) ((s8) reg_d1.b[0] >> 1);
                reg_d0.b[0] += reg_d1.b[0];
                EXPLOSION(reg_a0)->move.b.speed = (u8) reg_d0.b[0];
                rng_next_unsigned();
                EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
                FINAL_EXPLOSION(reg_a4)->blast += 0xA;
                if (FINAL_EXPLOSION(reg_a4)->blast == 0xA0) {
                    FINAL_EXPLOSION(reg_a4)->blast = 0U;
                    t8 = FINAL_EXPLOSION(reg_a4)->blast_timer.t.reload;
                    if (t8 == 2) {
                        reg_d0.h[0] = 0x16;
                        boss_flash_start();
                        FINAL_EXPLOSION(reg_a4)->step = 2U;
                    }
                }
            }
        }
        if (FINAL_EXPLOSION(reg_a4)->step == 0) {
            reg_tmp.b[0] = FINAL_EXPLOSION(reg_a4)->effect_timer.t.count;
            FINAL_EXPLOSION(reg_a4)->effect_timer.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                FINAL_EXPLOSION(reg_a4)->effect_timer.t.count = (u8) FINAL_EXPLOSION(reg_a4)->effect_timer.t.reload;
#ifdef DDPDOJ_PC
                reg_a0 = ARCADE_POINTER_TABLE_AT(u8 *, stage2_boss_blast_sounds, FINAL_EXPLOSION(reg_a4)->effect);
#else
                reg_a0 = (u8 *)stage2_boss_blast_sounds;
                reg_a0 += FINAL_EXPLOSION(reg_a4)->effect;
                reg_a0 = *(u8 **)reg_a0;
#endif
                reg_call_target = (Fn)(reg_a0);
                reg_call_target();
                FINAL_EXPLOSION(reg_a4)->effect += 4;
                FINAL_EXPLOSION(reg_a4)->effect &= 0x1F;
            }
            reg_tmp.b[0] = FINAL_EXPLOSION(reg_a4)->blast_timer.t.count;
            FINAL_EXPLOSION(reg_a4)->blast_timer.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                FINAL_EXPLOSION(reg_a4)->blast_timer.t.count = (u8) FINAL_EXPLOSION(reg_a4)->blast_timer.t.reload;
                reg_a1 = (u8 *)(stage2_boss_final_blasts);
                reg_a1 += FINAL_EXPLOSION(reg_a4)->blast;
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                explosion_spawn();
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                EXPLOSION(reg_a0)->attr.b.flip = (u8) reg_d0.b[0];
                EXPLOSION(reg_a0)->start_y = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                EXPLOSION(reg_a0)->start_x = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
                EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
                EXPLOSION(reg_a0)->draw_layer = 8;
                EXPLOSION(reg_a0)->debris = 0;
                EXPLOSION(reg_a0)->debris_arg = 0;
                FINAL_EXPLOSION(reg_a4)->blast += 0xA;
                if ((s16) FINAL_EXPLOSION(reg_a4)->blast >= 0xA0) {
                    FINAL_EXPLOSION(reg_a4)->blast = 0U;
                    FINAL_EXPLOSION(reg_a4)->rounds_left -= 1;
                    if (FINAL_EXPLOSION(reg_a4)->rounds_left == 0) {
                        FINAL_EXPLOSION(reg_a4)->blast_timer.h = 0x2010;
                        FINAL_EXPLOSION(reg_a4)->speedup.h = 0x1111;
                        FINAL_EXPLOSION(reg_a4)->step = 1U;
                        FINAL_EXPLOSION(reg_a4)->effect_timer.h = 0x101;
                        FINAL_EXPLOSION(reg_a4)->effect = 0U;
                    }
                }
            }
        }
    }
}

#ifndef DDPDOJ_PC
s32 boss_movement_start();                            /* extern */
#endif
s32 boss_animation_start();                            /* extern */

void stage2_boss_mode_high_slow_start(void) {
    HIGH_SLOW(reg_a4)->step = 0;
    reg_d0.w = 2;
    boss_movement_start();
    reg_d0.w = 3;
    boss_animation_start();
    HIGH_SLOW(reg_a4)->delay = 0x40;
    HIGH_SLOW(reg_a4)->attacks_done = 0;
    HIGH_SLOW(reg_a4)->last_attack = 0;
    HIGH_SLOW(reg_a4)->knee_rounds = 2;
    ARCADE_REGISTER_CALL(stage2_boss_mode_high_slow, 0x40);
}

s32 boss_animation_stop();
s32 boss_attack_start();
s32 boss_attack_running();
s32 stage2_boss_shield_off();
s32 rng_next_masked();
extern u16 g_loop;

void stage2_boss_mode_high_slow() {
    u16 temp_v1;
    u16 temp_v1_2;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;
    u8 temp_v1_3;
    u8 *temp_a1;

    if (HIGH_SLOW(reg_a4)->step == 0) {
        temp_v1 = HIGH_SLOW(reg_a4)->delay;
        temp_a1 = (u8 *)(reg_a4 + 4);
        if (temp_v1 != 0) {
            HIGH_SLOW(reg_a4)->delay = (u16) (temp_v1 - 1);
            if (HIGH_SLOW(reg_a4)->delay == 0) {
                stage2_boss_shield_off();
                if (g_loop != 0) {
                    reg_d0.w = 0xD;
                    boss_animation_stop();
                }
                reg_d0.w = 6;
                boss_attack_start();
                SHOULDER_SWEEP(reg_a0)->shots_left = 0xA0U;
            }
        } else {
            reg_d0.w = 6;
            boss_attack_running();
            if (cond_flag == 0) {
                HIGH_SLOW(reg_a4)->step = 2U;
            }
        }
    }
    temp_a0 = HIGH_SLOW(reg_a4)->step;
    if (temp_a0 == 2) {
        reg_d0.w = 6;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 7;
            boss_attack_running();
            if (cond_flag == 0) {
                reg_d0.w = 8;
                boss_attack_running();
                if (cond_flag == 0) {
                    reg_d0.w = 9;
                    boss_attack_running();
                    if (cond_flag == 0) {
                        do {
                            rng_next_masked();
                            reg_d0.h[0] &= 3;
                        } while (HIGH_SLOW(reg_a4)->last_attack == reg_d0.h[0]);
                        HIGH_SLOW(reg_a4)->last_attack = (u16) reg_d0.h[0];
                        reg_a1 = (u8 *)(stage2_boss_high_slow_attacks);
                        reg_d0.h[0] += reg_d0.h[0];
                        reg_d0.h[0] += reg_d0.h[0];
                        reg_a1 += reg_d0.h[0];
                        reg_d0.h[0] = *(u16 *)reg_a1;
                        reg_a1 += 2;
                        boss_attack_start();
                        SHOULDER_SWEEP(reg_a0)->shots_left = (u16) *(u16 *)reg_a1;
                        reg_a1 += 2;
                        HIGH_SLOW(reg_a4)->attacks_done += 1;
                        if (HIGH_SLOW(reg_a4)->attacks_done == 3) {
                            HIGH_SLOW(reg_a4)->attacks_done = 0U;
                            HIGH_SLOW(reg_a4)->step = 3U;
                            HIGH_SLOW(reg_a4)->delay = 0x40U;
                        }
                    }
                }
            }
        }
    }
    temp_a0_2 = HIGH_SLOW(reg_a4)->step;
    if (temp_a0_2 == 3) {
        reg_d0.w = 6;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 7;
            boss_attack_running();
            if (cond_flag == 0) {
                reg_d0.w = 8;
                boss_attack_running();
                if (cond_flag == 0) {
                    reg_d0.w = 9;
                    boss_attack_running();
                    if (cond_flag == 0) {
                        temp_v1_2 = HIGH_SLOW(reg_a4)->delay;
                        if (temp_v1_2 != 0) {
                            HIGH_SLOW(reg_a4)->delay = (u16) (temp_v1_2 - 1);
                            if (HIGH_SLOW(reg_a4)->delay == 0) {
                                HIGH_SLOW(reg_a4)->knee.h = 0x20;
                                HIGH_SLOW(reg_a4)->missile_pace.h = 0x4040U;
                                HIGH_SLOW(reg_a4)->rounds_left = 4U;
                            }
                        } else {
                            reg_d0.w = 0xB;
                            boss_attack_running();
                            if (cond_flag == 0) {
                                reg_d0.w = 0xB;
                                boss_attack_start();
                                SHOULDER_MISSILE(reg_a0)->shot.h = (u16) HIGH_SLOW(reg_a4)->missile_pace.h;
                                temp_v1_3 = HIGH_SLOW(reg_a4)->missile_pace.t.count;
                                if (temp_v1_3 != 0x10) {
                                    HIGH_SLOW(reg_a4)->missile_pace.t.count = (u8) (temp_v1_3 - 8);
                                    if ((s8) HIGH_SLOW(reg_a4)->missile_pace.t.count < 0x11) {
                                        HIGH_SLOW(reg_a4)->missile_pace.t.count = 0x10U;
                                    }
                                }
                                HIGH_SLOW(reg_a4)->rounds_left -= 1;
                                if (HIGH_SLOW(reg_a4)->rounds_left == 0) {
                                    HIGH_SLOW(reg_a4)->step = 2U;
                                } else {
                                    goto block_31;
                                }
                            } else {
block_31:
                                reg_d0.w = 0xA;
                                boss_attack_running();
                                if (cond_flag == 0) {
                                    reg_tmp.b[0] = HIGH_SLOW(reg_a4)->knee.t.count;
                                    HIGH_SLOW(reg_a4)->knee.t.count -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        HIGH_SLOW(reg_a4)->knee.t.count = HIGH_SLOW(reg_a4)->knee.t.reload;
                                        reg_d0.w = 0xA;
                                        boss_attack_start();
                                        rng_next_masked();
                                        reg_d0.h[0] &= 3;
                                        reg_d0.h[0] += HIGH_SLOW(reg_a4)->knee_rounds;
                                        KNEE_GUN(reg_a0)->rounds_left = (u16) reg_d0.h[0];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    temp_a0_3 = HIGH_SLOW(reg_a4)->step;
    if (temp_a0_3 == 4) {
        reg_d0.w = 0xA;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 0xB;
            boss_attack_running();
            if (cond_flag == 0) {
                HIGH_SLOW(reg_a4)->step = 0U;
                HIGH_SLOW(reg_a4)->delay = 0x40U;
            }
        }
    }
}


void stage2_boss_mode_high_fast_start(void) {
    HIGH_FAST(reg_a4)->step = 0;
    HIGH_FAST(reg_a4)->gun_step = 0;
    HIGH_FAST(reg_a4)->delay = 0x60;
    HIGH_FAST(reg_a4)->torso.h = 0x6060;
    HIGH_FAST(reg_a4)->torso_shots = 0x1E;
    HIGH_FAST(reg_a4)->torso_side = 1;
    HIGH_FAST(reg_a4)->pause_a.h = 0x3040;
    HIGH_FAST(reg_a4)->pause_b.h = 0x20;
    HIGH_FAST(reg_a4)->volleys.h = 0x303;
    HIGH_FAST(reg_a4)->body.h = 0x2024;
    HIGH_FAST(reg_a4)->body_volleys.h = 0x303;
    HIGH_FAST(reg_a4)->level_a = 0;
    HIGH_FAST(reg_a4)->level_b = 0;
    HIGH_FAST(reg_a4)->body_arg.b[1] = 2;
    HIGH_FAST(reg_a4)->body_arg.b[0] = 2;
    stage2_boss_mode_high_fast();
}

s32 boss_animation_start();
s32 boss_animation_running();

#ifdef DDPDOJ_PC
void stage2_boss_mode_high_fast(void)
#else
void stage2_boss_mode_high_fast(arg1)
    s32 arg1;
#endif
{
    s32 var_a1;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;
    u8 temp_a0_4;
    u8 temp_a0_5;
    u8 temp_a0_6;
    u8 temp_a0_7;
    u8 temp_a0_8;

#ifndef DDPDOJ_PC
    var_a1 = arg1;
#endif
    if (HIGH_FAST(reg_a4)->step == 0) {
        HIGH_FAST(reg_a4)->delay -= 1;
        if (HIGH_FAST(reg_a4)->delay == 0) {
            reg_d0.w = 2;
            boss_animation_stop();
            reg_d0.w = 6;
            boss_animation_start();
            var_a1 = 2;
            HIGH_FAST(reg_a4)->step = 2U;
            HIGH_FAST(reg_a4)->gun_step = 1U;
        }
    }
    temp_a0 = HIGH_FAST(reg_a4)->gun_step;
    if (temp_a0 == 1) {
        reg_d0.w = 1;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 0xE;
            boss_attack_running();
            if (cond_flag == 0) {
                reg_tmp.b[0] = HIGH_FAST(reg_a4)->body.t.count;
                HIGH_FAST(reg_a4)->body.t.count -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    HIGH_FAST(reg_a4)->body.t.count = (u8) HIGH_FAST(reg_a4)->body.t.reload;
                    reg_tmp.h[1] = STAGE2_BOSS(reg_a5)->hp[0];
                    reg_tmp.h[0] = STAGE2_BOSS(reg_a5)->hp[1];
                    if ((s32) reg_tmp.w < 0x7700) {
                        HIGH_FAST(reg_a4)->body.t.count = 8U;
                    }
                    reg_d0.w = 0xE;
                    boss_attack_start();
                    *(u16 *)(reg_a0 + 6) = (u16) HIGH_FAST(reg_a4)->body_arg.h;
                    BODY_SPREAD(reg_a0)->speed = 0xFFFB;
                    BODY_SPREAD(reg_a0)->bullet = 4;
                    BODY_SPREAD(reg_a0)->next_bullet = 5;
                    reg_tmp.b[0] = HIGH_FAST(reg_a4)->body_volleys.t.count;
                    HIGH_FAST(reg_a4)->body_volleys.t.count -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        HIGH_FAST(reg_a4)->body_volleys.t.count = (u8) HIGH_FAST(reg_a4)->body_volleys.t.reload;
                        BODY_SPREAD(reg_a0)->speed = 0xFFFA;
                        BODY_SPREAD(reg_a0)->bullet = 0xB;
                        *(s16 *)(reg_a0 + 0x18) = 0xC;
                        *(s8 *)(reg_a0 + 7) = 4;
                        HIGH_FAST(reg_a4)->gun_step = 2U;
                    }
                }
            }
        }
    }
    temp_a0_2 = HIGH_FAST(reg_a4)->gun_step;
    if (temp_a0_2 == 2) {
        reg_d0.w = 1;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_tmp.b[0] = HIGH_FAST(reg_a4)->torso.t.count;
            HIGH_FAST(reg_a4)->torso.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                HIGH_FAST(reg_a4)->torso.t.count = (u8) HIGH_FAST(reg_a4)->torso.t.reload;
                reg_d0.w = 1;
                boss_attack_start();
                TORSO_RAPID(reg_a0)->side = (u8) HIGH_FAST(reg_a4)->torso_side;
                TORSO_RAPID(reg_a0)->shots_left = (u16) HIGH_FAST(reg_a4)->torso_shots;
                HIGH_FAST(reg_a4)->torso_side = (u8) -(s8) HIGH_FAST(reg_a4)->torso_side;
                HIGH_FAST(reg_a4)->gun_step = 1U;
                HIGH_FAST(reg_a4)->torso_shots += 1;
                if ((s16) HIGH_FAST(reg_a4)->torso_shots >= 0x28) {
                    HIGH_FAST(reg_a4)->torso_shots = 0x28U;
                }
            }
        }
    }
    temp_a0_3 = HIGH_FAST(reg_a4)->step;
    if (temp_a0_3 == 2) {
        reg_d0.w = 0xA;
        boss_animation_running();
        if (cond_flag == 0) {
            reg_d0.w = 0xC;
            boss_attack_running();
            if (cond_flag == 0) {
                reg_tmp.b[0] = HIGH_FAST(reg_a4)->pause_a.t.count;
                HIGH_FAST(reg_a4)->pause_a.t.count -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    HIGH_FAST(reg_a4)->pause_a.t.count = (u8) HIGH_FAST(reg_a4)->pause_a.t.reload;
                    HIGH_FAST(reg_a4)->step = 3U;
                    HIGH_FAST(reg_a4)->delay = 0x20U;
                    temp_a0_4 = HIGH_FAST(reg_a4)->level_a;
                    if (temp_a0_4 != 4) {
                        HIGH_FAST(reg_a4)->level_a = (u8) (temp_a0_4 + 1);
                    }
                }
            }
        }
    }
    temp_a0_5 = HIGH_FAST(reg_a4)->step;
    if (temp_a0_5 == 3) {
        reg_d0.w = 0xC;
        boss_attack_running();
        if (cond_flag == 0) {
            HIGH_FAST(reg_a4)->delay -= 1;
            if (HIGH_FAST(reg_a4)->delay == 0) {
                reg_d0.w = 9;
                boss_animation_start();
                HIGH_FAST(reg_a4)->step = 4U;
            }
        }
    }
    temp_a0_6 = HIGH_FAST(reg_a4)->step;
    if (temp_a0_6 == 4) {
        reg_d0.w = 9;
        boss_animation_running();
        if (cond_flag == 0) {
            reg_d0.w = 0xD;
            boss_attack_running();
            if (cond_flag == 0) {
                reg_tmp.b[0] = HIGH_FAST(reg_a4)->pause_b.t.count;
                HIGH_FAST(reg_a4)->pause_b.t.count -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    HIGH_FAST(reg_a4)->pause_b.t.count = (u8) HIGH_FAST(reg_a4)->pause_b.t.reload;
                    reg_d0.w = 0xD;
                    boss_attack_start();
                    SHOULDER_CANNON(reg_a0)->volleys_left = 4U;
                    HIGH_FAST(reg_a4)->volleys.t.count -= 1;
                    if (HIGH_FAST(reg_a4)->volleys.t.count == 0) {
                        HIGH_FAST(reg_a4)->volleys.t.count = (u8) HIGH_FAST(reg_a4)->volleys.t.reload;
                        HIGH_FAST(reg_a4)->pause_b.t.reload -= 4;
                        if ((s8) HIGH_FAST(reg_a4)->pause_b.t.reload < 0x11) {
                            HIGH_FAST(reg_a4)->pause_b.t.reload = 0x10U;
                        }
                        HIGH_FAST(reg_a4)->pause_b.t.count = (u8) HIGH_FAST(reg_a4)->pause_b.t.reload;
                        HIGH_FAST(reg_a4)->step = 5U;
                    }
                }
            }
        }
    }
    temp_a0_7 = HIGH_FAST(reg_a4)->step;
    if (temp_a0_7 == 5) {
        reg_d0.w = 0xD;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 0xA;
            boss_animation_start();
            HIGH_FAST(reg_a4)->step = 2U;
            temp_a0_8 = HIGH_FAST(reg_a4)->level_b;
            if (temp_a0_8 != 4) {
                HIGH_FAST(reg_a4)->level_b = (u8) (temp_a0_8 + 1);
            }
        }
    }
}


void stage2_boss_mode_recoil_start(void) {
    RECOIL_MODE(reg_a4)->step = 0;
    RECOIL_MODE(reg_a4)->delay = 0x60;
    RECOIL_MODE(reg_a4)->shot.h = 0;
    RECOIL_MODE(reg_a4)->shots_left = 8;
    ARCADE_REGISTER_CALL(stage2_boss_mode_recoil, 0x60);
}

s32 aim_at_player();
s32 direction_turn_toward();
extern u16 D_0026C250[];
extern u16 D_0026C252[];
extern u16 D_0026C260[];
extern u16 D_0026C262[];

void stage2_boss_mode_recoil() {
    u16 temp_a1;
    u16 temp_a1_2;
    u16 temp_a1_3;
    u16 temp_a1_4;
    u8 temp_a0_3;

    if (RECOIL_MODE(reg_a4)->step == 0) {
        RECOIL_MODE(reg_a4)->delay -= 1;
        if (RECOIL_MODE(reg_a4)->delay == 0) {
            RECOIL_MODE(reg_a4)->step = 1U;
            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
            temp_a1 = ENTITY(reg_a6)->x.h;
            reg_d1.h[0] = temp_a1;
            reg_d0.h[0] += D_0026C250[0];
            reg_d1.h[0] += D_0026C252[0];
            aim_at_player();
            RECOIL_MODE(reg_a4)->aim.b[1] = (u8) reg_d1.b[0];
            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
            temp_a1_2 = ENTITY(reg_a6)->x.h;
            reg_d1.h[0] = temp_a1_2;
            reg_d0.h[0] += D_0026C260[0];
            reg_d1.h[0] += D_0026C262[0];
            aim_at_player();
            RECOIL_MODE(reg_a4)->aim.b[0] = (u8) reg_d1.b[0];
        }
    }
    temp_a0_3 = RECOIL_MODE(reg_a4)->step;
    if (temp_a0_3 == 1) {
        reg_d0.w = 8;
        boss_animation_running();
        if (cond_flag == 0) {
            reg_tmp.b[0] = RECOIL_MODE(reg_a4)->shot.t.count;
            RECOIL_MODE(reg_a4)->shot.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                RECOIL_MODE(reg_a4)->shot.t.count = (u8) RECOIL_MODE(reg_a4)->shot.t.reload;
                reg_d0.w = 8;
                boss_animation_start();
                reg_d7.w = 1;
                do {
                    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                    temp_a1_3 = ENTITY(reg_a6)->x.h;
                    reg_d1.h[0] = temp_a1_3;
                    reg_d0.h[0] += D_0026C250[0];
                    reg_d1.h[0] += D_0026C252[0];
                    aim_at_player();
                    reg_d0.b[0] = RECOIL_MODE(reg_a4)->aim.b[1];
                    direction_turn_toward();
                    RECOIL_MODE(reg_a4)->aim.b[1] = (u8) reg_d1.b[0];
                    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                    temp_a1_4 = ENTITY(reg_a6)->x.h;
                    reg_d1.h[0] = temp_a1_4;
                    reg_d0.h[0] += D_0026C260[0];
                    reg_d1.h[0] += D_0026C262[0];
                    aim_at_player();
                    reg_d0.b[0] = RECOIL_MODE(reg_a4)->aim.b[0];
                    direction_turn_toward();
                    RECOIL_MODE(reg_a4)->aim.b[0] = (u8) reg_d1.b[0];
                } while ((s16)(--reg_d7.h[0]) >= 0);
                reg_d0.w = 0xD;
                boss_attack_start();
                SHOULDER_CANNON(reg_a0)->shot.h = (u16) RECOIL_MODE(reg_a4)->aim.h;
                RECOIL_MODE(reg_a4)->shots_left -= 1;
                if (RECOIL_MODE(reg_a4)->shots_left == 0) {
                    RECOIL_MODE(reg_a4)->running = 0;
                    reg_d0.w = 4;
                    boss_phase_start();
                }
            }
        }
    }
}

#ifndef DDPDOJ_PC
s32 boss_movement_start();                            /* extern */
#endif

void stage2_boss_mode_rise_start(void) {
    reg_d0.w = 4;
    boss_movement_start();
    RISE(reg_a4)->step = 0;
    RISE(reg_a4)->delay = 0x20;
}

s32 boss_movement_current();

void stage2_boss_mode_rise() {
    if (RISE(reg_a4)->step == 0) {
        boss_movement_current();
        if (reg_d0.h[0] == 5) {
            RISE(reg_a4)->step = 1U;
        }
    }
    if (RISE(reg_a4)->step == 1) {
        RISE(reg_a4)->delay -= 1;
        if (RISE(reg_a4)->delay == 0) {
            RISE(reg_a4)->running = 0;
            reg_d0.w = 3;
            boss_phase_start();
        }
    }
}


void stage2_boss_mode_rise_sway_start(void) {
    RISE_SWAY(reg_a4)->step = 0;
    RISE_SWAY(reg_a4)->started = 0;
    RISE_SWAY(reg_a4)->waypoint = 0;
    RISE_SWAY(reg_a4)->delay = 0x20;
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(stage2_boss_rise_sway_waypoints);
#ifdef DDPDOJ_PC
    RISE_SWAY(reg_a4)->path[0] = reg_tmp.h[1];
    RISE_SWAY(reg_a4)->path[1] = reg_tmp.h[0];
#else
    ENEMY_STATE(reg_a5)->entities[1] = (u16) reg_tmp.h[1];
    ENEMY_STATE(reg_a5)->line_step = (u16) reg_tmp.h[0];
#endif
    RISE_SWAY(reg_a4)->side = 1;
    stage2_boss_mode_rise_sway();
}


void stage2_boss_mode_rise_sway(void) {
    u16 temp_a0_2;
    u8 temp_a0;

    if (RISE_SWAY(reg_a4)->step == 0) {
        RISE_SWAY(reg_a4)->delay -= 1;
        if (RISE_SWAY(reg_a4)->delay == 0) {
            RISE_SWAY(reg_a4)->step = 1U;
        }
    }
    temp_a0 = RISE_SWAY(reg_a4)->step;
    if ((temp_a0 == 1) && (boss_movement_current(temp_a0), (reg_d0.h[0] == 5))) {
        reg_tmp.h[1] = RISE_SWAY(reg_a4)->path[0];
        reg_tmp.h[0] = RISE_SWAY(reg_a4)->path[1];
        reg_a1 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
        temp_a0_2 = RISE_SWAY(reg_a4)->waypoint;
        reg_a1 += temp_a0_2;
        if (*(s16 *)reg_a1 != -1) {
            stage2_boss_rise_sway_next();
            return;
        }
        reg_d0.w = 4;
        boss_phase_start();
        RISE_SWAY(reg_a4)->running = 0;
    }
}

#ifndef DDPDOJ_PC
s32 boss_movement_start();
#endif
s32 enemy_switch_target_player();

void stage2_boss_rise_sway_next(void) {
    reg_d0.w = 6;
    boss_movement_start();
    *(u16 *)(reg_a0 + 8) = (u16) *(u16 *)reg_a1;
    *(u16 *)(reg_a0 + 0xA) = (u16) *(u16 *)(reg_a1 + 2);
    RISE_SWAY(reg_a4)->waypoint += 4;
    enemy_switch_target_player();
    if (RISE_SWAY(reg_a4)->started != 0) {
        reg_d0.w = 2;
        boss_attack_start();
        QUAD_GUN(reg_a0)->side = (u16) RISE_SWAY(reg_a4)->side;
        RISE_SWAY(reg_a4)->side *= 0xFFFF;
    }
    RISE_SWAY(reg_a4)->started = 1U;
}

s32 boss_animation_start(s32, s32, s32);   /* extern */
s32 boss_attack_start();                            /* extern */

void stage2_boss_mode_rage_start(void) {
    RAGE(reg_a4)->step = 0;
    RAGE(reg_a4)->delay = 0x10;
    RAGE(reg_a4)->unread_06 = 0x200A;
    RAGE(reg_a4)->unread_0C = 0x101;
    reg_d0.w = 0xA;
    boss_animation_start(0x101, 0x200A, 0x10);
    reg_d0.w = 0xF;
    boss_attack_start();
    stage2_boss_mode_rage();
}

void stage2_boss_mode_rage(void) {
}
