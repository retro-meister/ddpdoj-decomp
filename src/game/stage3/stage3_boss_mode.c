#include "common.h"
#include "entity.h"
#include "stage3_boss.h"

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

/*
 * The mode part of the boss slot (reg_a4). `running` is cleared when the mode hands over. Most modes only wait.
 */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u16 delay;
} ModeWait;

/* The explosion between two phases. */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u16 delay;
    /* 0x04 */ SlotTimer blast;
    /* 0x06 */ u16 blasts_left;
} PhaseBlast;

/* The final explosion: rounds of a chain of explosions that gets faster, a flash, then the big one. */
typedef struct {
    /* 0x00 */ u16 running;
    /* 0x02 */ u16 step;
    /* 0x04 */ u16 delay;
    /* 0x06 */ SlotTimer chain;   /* wait between two explosions of the list */
    /* 0x08 */ u16 chain_position;
    /* 0x0A */ u16 rounds_left;
    /* 0x0C */ u8 unused_0C;
    /* 0x0D */ u8 spread;
    /* 0x0E */ SlotTimer speedup; /* explosions between two steps of the chain's wait */
    /* 0x10 */ SlotTimer burst;
    /* 0x12 */ union {
        s16 sh;
        struct { u8 wait; u8 flags; } b; /* flags bit 0: which of two sounds comes next */
    } sound;
} FinalBlast;

#define MODE(pointer) ((ModeWait *)(pointer))
#define BLAST(pointer) ((PhaseBlast *)(pointer))
#define FINAL(pointer) ((FinalBlast *)(pointer))

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

u16 stage3_boss_blast_chain[] = {
    0x0009, 0x0000, 0x0000, 0x0000, 0x0085, 0x0000, 0xE800, 0x0A00,
    0x000C, 0x0000, 0xF000, 0xFA00, 0x0085, 0x0000, 0xDC00, 0xFE00,
    0x0009, 0x0000, 0xFC00, 0x0800, 0x000C, 0x0000, 0x0800, 0xF600,
    0x0009, 0x0000, 0xF800, 0xF400, 0x0085, 0x0000, 0xE400, 0x0C00,
    0x0009, 0x0000, 0x0000, 0x0000, 0x0085, 0x0000, 0xE800, 0xF600,
    0x000C, 0x0000, 0xF000, 0x0600, 0x0085, 0x0000, 0xDC00, 0x0200,
    0x0009, 0x0000, 0xFC00, 0xF800, 0x000C, 0x0000, 0x0800, 0x0A00,
    0x0009, 0x0000, 0xF800, 0x0C00, 0x0085, 0x0000, 0xE400, 0xF400,
    0xFFFF,
};

u16 stage3_boss_final_flash[] = {
    0x0010, 0x7FFF, 0x0000, 0x0780, 0x0004, 0x0005, 0x001F, 0x0004,
    0x7FFF, 0x0008, 0x0000, 0x000B, 0x000C, 0x001F, 0x0005, 0x7FFF,
    0x0008, 0x0040, 0x0012, 0x0013, 0x001F, 0x0005, 0x7FFF, 0x0008,
    0x0080, 0x0019, 0x001A, 0x001F, 0x0005, 0x7FFF, 0x0008, 0x00C0,
    0x0020, 0x0021, 0x001F, 0x0005, 0x7FFF, 0x0008, 0x0100, 0x0027,
    0x0028, 0x001F, 0x0005, 0x7FFF, 0x0008, 0x0140, 0x002E, 0x002F,
    0x001F, 0x0005, 0x7FFF, 0x0008, 0x0180, 0x0035, 0x0036, 0x001F,
    0x0005, 0x7FFF, 0x0008, 0x01C0, 0x003C, 0x003D, 0x001F, 0x0005,
    0x7FFF, 0x0008, 0x0200, 0x0043, 0x0044, 0x001F, 0x0005, 0x7FFF,
    0x0008, 0x0240, 0x004A, 0x004B, 0x001F, 0x0005, 0x7FFF, 0x0008,
    0x0280, 0x0051, 0x0052, 0x001F, 0x0005, 0x7FFF, 0x0008, 0x02C0,
    0x0058, 0x0059, 0x001F, 0x0005, 0x7FFF, 0x0008, 0x0300, 0x005F,
    0x0060, 0x001F, 0x0005, 0x7FFF, 0x0008, 0x0340, 0x0066, 0x0067,
    0x001F, 0x0005, 0x7FFF, 0x0008, 0x0380, 0x006D, 0x006E, 0x001F,
    0x0005,
};

u16 stage3_boss_final_fade[] = {
    0x0003, 0x0000, 0x0400, 0x0003, 0x0004, 0x001F, 0x0014, 0x0000,
    0x0440, 0x0009, 0x000A, 0x001F, 0x0014, 0x0000, 0x0480, 0x000F,
    0x0010, 0x001F, 0x0014,
};

u16 stage3_boss_phase_blasts[] = {
    0x000D, 0x0085, 0x000D, 0x0085, 0x0084, 0x000C, 0x000A, 0x0004,
    0x0008,
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


void stage3_boss_mode_enter(void) {
    MODE(reg_a4)->running = 0;
}

s32 func_0013B8B0();                            /* extern */

void stage3_boss_mode_final_explosion_start(void) {
    reg_a0 = (u8 *)stage3_boss_final_fade;
    func_0013B8B0();
    FINAL(reg_a4)->step = 0;
    FINAL(reg_a4)->chain.sh = 0x101;
    FINAL(reg_a4)->chain_position = 0;
    FINAL(reg_a4)->rounds_left = 1;
    FINAL(reg_a4)->spread = 0;
    FINAL(reg_a4)->burst.sh = 0x2020;
    FINAL(reg_a4)->sound.sh = 0;
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

void stage3_boss_mode_final_explosion() {
    u8 bits;

    if (FINAL(reg_a4)->step != 4) goto next_s3;
    FINAL(reg_a4)->delay -= 1;
    if (FINAL(reg_a4)->delay != 0) goto next_s4rts;
    boss_slots_end();
    FINAL(reg_a4)->running = 0;
next_s4rts:
    return;
next_s3:
    if (FINAL(reg_a4)->step != 3) goto next_s2;
    reg_d6.w = 0;
    reg_a1 = (u8 *) stage3_boss_blast_chain;
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
    reg_d0.b[0] += FINAL(reg_a4)->spread;
    reg_a0[0x1B] = reg_d0.b[0];
    rng_next_unsigned();
    reg_a0[0x1A] = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x18) = reg_d6.h[0];
    reg_d6.h[0] += 1;
    goto loop_10;
next_20:
    FINAL(reg_a4)->delay = 0x80;
    FINAL(reg_a4)->step = 4;
    sfx_explosion_boss();
    return;
next_s2:
    if (FINAL(reg_a4)->step != 2) goto next_s1;
    boss_flash_running();
    if (cond_flag != 0) goto next_s1;
    reg_a0 = (u8 *) stage3_boss_final_flash;
    func_0013B2E0();
    boss_part_hide_all();
    FINAL(reg_a4)->rounds_left = 1;
    FINAL(reg_a4)->step = 3;
    return;
next_s1:
    if (FINAL(reg_a4)->step != 1) goto next_s0;
    reg_tmp.b[0] = FINAL(reg_a4)->burst.t.count;
    FINAL(reg_a4)->burst.t.count -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_reon;
    FINAL(reg_a4)->burst.t.count = FINAL(reg_a4)->burst.t.reload;
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
    if (FINAL(reg_a4)->chain.t.reload == 2) goto next_reon;
    sfx_explosion_ground_medium();
next_reon:
    reg_tmp.b[0] = FINAL(reg_a4)->speedup.t.count;
    FINAL(reg_a4)->speedup.t.count -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_intdec;
    FINAL(reg_a4)->speedup.t.count = FINAL(reg_a4)->speedup.t.reload;
    if (FINAL(reg_a4)->chain.t.reload == 2) goto next_intdec;
    FINAL(reg_a4)->chain.t.reload -= 1;
    FINAL(reg_a4)->spread += 1;
next_intdec:
    reg_tmp.b[0] = FINAL(reg_a4)->chain.t.count;
    FINAL(reg_a4)->chain.t.count -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_s0;
    FINAL(reg_a4)->chain.t.count = FINAL(reg_a4)->chain.t.reload;
    if (FINAL(reg_a4)->chain.t.reload == 2) goto next_intdec20;
    reg_tmp.b[0] = FINAL(reg_a4)->sound.b.wait;
    FINAL(reg_a4)->sound.b.wait -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_intdec20;
    FINAL(reg_a4)->sound.b.wait = 4;
    sfx_explosion_air_large();
next_intdec20:
    reg_a1 = (u8 *) stage3_boss_blast_chain;
    reg_a1 += FINAL(reg_a4)->chain_position;
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
    reg_d1.b[0] = FINAL(reg_a4)->spread;
    reg_d1.b[0] = (s8) reg_d1.b[0] >> 1;
    reg_d0.b[0] += reg_d1.b[0];
    reg_a0[0x1B] = reg_d0.b[0];
    rng_next_unsigned();
    reg_a0[0x1A] = reg_d0.b[0];
    FINAL(reg_a4)->chain_position += 8;
    if (FINAL(reg_a4)->chain_position != 0x80) goto next_s0;
    FINAL(reg_a4)->chain_position = 0;
    if (FINAL(reg_a4)->chain.t.reload != 2) goto next_s0;
    reg_d0.h[0] = 0xA;
    boss_flash_start();
    FINAL(reg_a4)->step = 2;
    return;
next_s0:
    if (FINAL(reg_a4)->step != 0) goto block_rts;
    reg_tmp.b[0] = FINAL(reg_a4)->chain.t.count;
    FINAL(reg_a4)->chain.t.count -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts;
    FINAL(reg_a4)->chain.t.count = FINAL(reg_a4)->chain.t.reload;
    bits = FINAL(reg_a4)->sound.b.flags;
    if (bits & 1) {
        FINAL(reg_a4)->sound.b.flags = bits & 0xFE;
        goto next_40;
    }
    FINAL(reg_a4)->sound.b.flags = bits | 1;
    reg_a0 = (u8 *) sfx_explosion_air_medium;
    rng_next_unsigned();
    if (reg_d0.sb[0] >= 0) goto next_30;
    reg_a0 = (u8 *) sfx_explosion_air_large;
next_30:
    reg_call_target = (Fn) reg_a0;
    reg_call_target();
next_40:
    reg_a1 = (u8 *) stage3_boss_blast_chain;
    reg_a1 += FINAL(reg_a4)->chain_position;
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
    FINAL(reg_a4)->chain_position += 8;
    if ((s32) FINAL(reg_a4)->chain_position < 0x80) goto block_rts;
    FINAL(reg_a4)->chain_position = 0;
    FINAL(reg_a4)->rounds_left -= 1;
    if (FINAL(reg_a4)->rounds_left != 0) goto block_rts;
    FINAL(reg_a4)->chain.h = 0x2010;
    FINAL(reg_a4)->speedup.h = 0x1111;
    FINAL(reg_a4)->step = 1;
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
        MODE(reg_a4)->running = 0;
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
    temp_a0 = STAGE3_ADJUST(reg_a6)->six_gun_first_frame;
    *(u8 *)(reg_a0 + 3) = temp_a0;
    *(s8 *)(reg_a0 + 2) = 1;
    temp_v0 = STAGE3_ADJUST(reg_a6)->six_gun_first_frame;
    if ((s32) temp_v0 < 0x11) {
        stage3_boss_mode_high_six_gun(temp_a0);
        return;
    }
    STAGE3_ADJUST(reg_a6)->six_gun_first_frame = (u8) (temp_v0 - 0x30);
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
        MODE(reg_a4)->running = 0;
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
            MODE(reg_a4)->running = 0;
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
        MODE(reg_a4)->running = 0;
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
        MODE(reg_a4)->running = 0;
    }
}


void stage3_boss_mode_six_gun_b_close_wait_start(void) {
    MODE(reg_a4)->delay = 0;
    stage3_boss_mode_six_gun_b_close_wait();
}

s32 boss_phase_start(void *);                      /* extern */
s32 boss_animation_running();                            /* extern */
s32 boss_attack_running(void *);                      /* extern */

void stage3_boss_mode_six_gun_b_close_wait(void) {
    u16 temp_v1;
    u8 *temp_a0;

    temp_a0 = reg_a4 + 2;
    temp_v1 = MODE(reg_a4)->delay;
    if (temp_v1 != 0) {
        MODE(reg_a4)->delay = (u16) (temp_v1 - 1);
        if (MODE(reg_a4)->delay == 0) {
            reg_d0.w = 2;
            boss_phase_start(temp_a0);
            MODE(reg_a4)->running = 0;
        }
    } else {
        reg_d0.w = 8;
        boss_attack_running(temp_a0);
        if (cond_flag == 0) {
            reg_d0.w = 5;
            boss_animation_running();
            if (cond_flag == 0) {
                MODE(reg_a4)->delay = 1U;
            }
        }
    }
}

s32 boss_movement_start(s32);                     /* extern */

void stage3_boss_mode_low_all_guns_start(void) {
    MODE(reg_a4)->delay = 0x80;
    reg_d0.w = 1;
    boss_movement_start(0x80);
    stage3_boss_mode_low_all_guns();
}

s32 boss_animation_start();
s32 boss_attack_start();
s32 func_001D4550();

void stage3_boss_mode_low_all_guns() {
    MODE(reg_a4)->delay -= 1;
    if ((s16) MODE(reg_a4)->delay < 0) {
        reg_d0.w = 2;
        boss_animation_start();
        reg_d0.w = 1;
        boss_attack_start();
        reg_d0.w = 2;
        boss_attack_start();
        func_001D4550();
        MODE(reg_a4)->running = 0;
    }
}



void stage3_boss_mode_phase_explosion_start(void) {
    BLAST(reg_a4)->delay = 0x40;
    BLAST(reg_a4)->blast.h = 0x404;
    BLAST(reg_a4)->blasts_left = 0x17;
    stage3_boss_mode_phase_explosion(0x404, 0x40);
}

s32 boss_phase_start();
s32 boss_part_hide();
s32 rng_next_masked();
s32 func_002013F0();

void stage3_boss_mode_phase_explosion() {
    u16 temp_a2;
    u16 temp_v1;

    temp_v1 = BLAST(reg_a4)->delay;
    if (temp_v1 != 0) {
        BLAST(reg_a4)->delay = (u16) (temp_v1 - 1);
        if (BLAST(reg_a4)->delay == 0) {
            reg_d0.w = 8;
            boss_part_hide();
        }
    }
    reg_tmp.b[0] = BLAST(reg_a4)->blast.t.count;
    BLAST(reg_a4)->blast.t.count -= 1;
    if (reg_tmp.b[0] == 0) {
        BLAST(reg_a4)->blast.t.count = (u8) BLAST(reg_a4)->blast.t.reload;
        reg_a0 = (u8 *)sfx_explosion_air_medium;
        rng_next_unsigned();
        if ((s8) reg_d0.b[0] >= 0) {
            reg_a0 = (u8 *)sfx_explosion_air_large;
        }
        reg_call_target = (Fn)(reg_a0);
        reg_call_target();
        rng_next_unsigned();
        reg_d0.h[0] &= 7;
        reg_d0.h[0] = *(u16 *)(((u8 *)stage3_boss_phase_blasts) + (reg_d0.h[0] * 2));
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
        BLAST(reg_a4)->blasts_left -= 1;
        if ((s16) BLAST(reg_a4)->blasts_left < 0) {
            reg_d0.w = 8;
            boss_phase_start();
            BLAST(reg_a4)->running = 0;
        }
    }
}
