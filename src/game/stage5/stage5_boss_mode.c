#include "common.h"
#include "fade.h"
#include "entity.h"
#include "explosion.h"
#include "stage5_boss.h"

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u16 wait;
    /* 0x04 */ u16 second_wait;
} Mode;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u16 wait;
    /* 0x04 */ SlotTimer blast;
} ExplodingMode;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u16 step;              /* 0..4 */
    /* 0x04 */ u16 wait;
    /* 0x06 */ SlotTimer blast;
    /* 0x08 */ u16 entry;
    /* 0x0A */ u16 rounds;
    /* 0x0C */ u8 unused_0C;
    /* 0x0D */ u8 quickened;
    /* 0x0E */ SlotTimer quicken_timer;
    /* 0x10 */ SlotTimer burst_timer;
    /* 0x12 */ union {
        u16 both;
        struct { u8 large_wait; u8 skipped; } b;
    } sound;
} FinalExplosion;

#define MODE(pointer) ((Mode *)(pointer))
#define EXPLODING(pointer) ((ExplodingMode *)(pointer))
#define FINAL_EXPLOSION(pointer) ((FinalExplosion *)(pointer))


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
void twin_boss_mode_stinger_start(void);
void twin_boss_mode_stinger(void);
void twin_boss_mode_attack_b_start(void);
void twin_boss_mode_attack_b(void);
void twin_boss_mode_attack_c_start(void);
void twin_boss_mode_attack_c(void);
void twin_boss_mode_spiral_start(void);
void twin_boss_mode_spiral(void);
void twin_boss_mode_rage_start(void);
void twin_boss_mode_rage(void);
void twin_boss_mode_jet_start(void);
void twin_boss_mode_jet(void);
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
    twin_boss_mode_stinger_start, /* the modes only Death Label has */
    twin_boss_mode_stinger,
    twin_boss_mode_attack_b_start,
    twin_boss_mode_attack_b,
    twin_boss_mode_attack_c_start,
    twin_boss_mode_attack_c,
    twin_boss_mode_spiral_start,
    twin_boss_mode_spiral,
    twin_boss_mode_rage_start,
    twin_boss_mode_rage,
    twin_boss_mode_jet_start,
    twin_boss_mode_jet,
#else
    0,
    0,
#endif
};

s16 stage5_boss_wreck_positions[24][2] = {
    { 0xE00, 0x800 },
    { 0xE00, -0xA00 },
    { 0xC00, 0x1400 },
    { 0xC00, -0x1400 },
    { 0x400, 0x1C00 },
    { 0x400, -0x1C00 },
    { -0x400, 0x1200 },
    { -0x400, -0x1200 },
    { 0x200, 0xA00 },
    { -0x200, -0x800 },
    { -0x1000, 0xC00 },
    { -0x1000, -0xA00 },
    { -0x2000, 0x800 },
    { -0x2000, -0x600 },
    { -0x3000, 0xE00 },
    { -0x3000, -0x800 },
    { 0xC00, -0x100 },
    { -0x200, 0 },
    { -0x1200, 0x200 },
    { -0x2400, 0x200 },
    { -0x3400, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
};

u16 stage5_boss_blast_kinds[16] = {
    0x000D, 0x0085, 0x0009, 0x0005, 0x0084, 0x000C, 0x000A, 0x0004,
    0x0008, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 stage5_boss_flash_palettes_a[104] = {
    0x000E, 0x7FFF, 0x0000, 0x0780, 0x0004, 0x0005, 0x001F, 0x0004,
    0x7FFF, 0x0000, 0x0400, 0x000B, 0x000C, 0x001F, 0x0005, 0x7FFF,
    0x0000, 0x0440, 0x0012, 0x0013, 0x001F, 0x0005, 0x7FFF, 0x0000,
    0x0480, 0x0019, 0x001A, 0x001F, 0x0005, 0x7FFF, 0x0000, 0x04C0,
    0x0020, 0x0021, 0x001F, 0x0005, 0x7FFF, 0x0000, 0x0500, 0x0027,
    0x0028, 0x001F, 0x0005, 0x7FFF, 0x0000, 0x0540, 0x002E, 0x002F,
    0x001F, 0x0005, 0x7FFF, 0x0000, 0x0580, 0x0035, 0x0036, 0x001F,
    0x0005, 0x7FFF, 0x0008, 0x0200, 0x003C, 0x003D, 0x001F, 0x0005,
    0x7FFF, 0x0008, 0x0280, 0x0043, 0x0044, 0x001F, 0x0005, 0x7FFF,
    0x0008, 0x02C0, 0x004A, 0x004B, 0x001F, 0x0005, 0x7FFF, 0x0008,
    0x0580, 0x0051, 0x0052, 0x001F, 0x0005, 0x7FFF, 0x0008, 0x05C0,
    0x0058, 0x0059, 0x001F, 0x0005, 0x7FFF, 0x0008, 0x0740, 0x005F,
    0x0060, 0x001F, 0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 stage5_boss_flash_palettes_b[64] = {
    0x0009, 0x7FFF, 0x0000, 0x0780, 0x0004, 0x0005, 0x001F, 0x0004,
    0x7FFF, 0x0000, 0x05C0, 0x000B, 0x000C, 0x001F, 0x0006, 0x7FFF,
    0x0000, 0x03C0, 0x0012, 0x0013, 0x001F, 0x0006, 0x7FFF, 0x0008,
    0x0200, 0x0019, 0x001A, 0x001F, 0x0006, 0x7FFF, 0x0008, 0x0280,
    0x0020, 0x0021, 0x001F, 0x0006, 0x7FFF, 0x0008, 0x02C0, 0x0027,
    0x0028, 0x001F, 0x0006, 0x7FFF, 0x0008, 0x0580, 0x002E, 0x002F,
    0x001F, 0x0006, 0x7FFF, 0x0008, 0x05C0, 0x0035, 0x0036, 0x001F,
    0x0006, 0x7FFF, 0x0008, 0x0740, 0x003C, 0x003D, 0x001F, 0x0006,
};

s16 stage5_boss_final_blasts[72] = {
    BLAST_SHORT(0x09, 0, 0, 0),
    BLAST_SHORT(0x85, 0, -0x1800, 0xA00),
    BLAST_SHORT(0x0C, 0, -0x1000, -0x600),
    BLAST_SHORT(0x85, 0, -0x2400, -0x200),
    BLAST_SHORT(0x09, 0, -0x400, 0x800),
    BLAST_SHORT(0x0C, 0, 0x800, -0xA00),
    BLAST_SHORT(0x09, 0, -0x800, -0xC00),
    BLAST_SHORT(0x85, 0, -0x1C00, 0xC00),
    BLAST_SHORT(0x09, 0, 0, 0),
    BLAST_SHORT(0x85, 0, -0x1800, -0xA00),
    BLAST_SHORT(0x0C, 0, -0x1000, 0x600),
    BLAST_SHORT(0x85, 0, -0x2400, 0x200),
    BLAST_SHORT(0x09, 0, -0x400, -0x800),
    BLAST_SHORT(0x0C, 0, 0x800, 0xA00),
    BLAST_SHORT(0x09, 0, -0x800, 0xC00),
    BLAST_SHORT(0x85, 0, -0x1C00, -0xC00),
    BLAST_END,
};

u16 stage5_boss_flash_palettes_c[56] = {
    0x0006, 0x7FFF, 0x0000, 0x0780, 0x0004, 0x0005, 0x001F, 0x0004,
    0x7FFF, 0x0008, 0x0200, 0x000B, 0x000C, 0x001F, 0x0006, 0x7FFF,
    0x0008, 0x0280, 0x0012, 0x0013, 0x001F, 0x0006, 0x7FFF, 0x0008,
    0x02C0, 0x0019, 0x001A, 0x001F, 0x0006, 0x7FFF, 0x0008, 0x0580,
    0x0020, 0x0021, 0x001F, 0x0006, 0x7FFF, 0x0008, 0x05C0, 0x0027,
    0x0028, 0x001F, 0x0006, 0x7FFF, 0x0008, 0x0740, 0x002E, 0x002F,
    0x001F, 0x0006, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 stage5_boss_fade_palettes_a[16] = {
    0x0002, 0x0000, 0x05C0, 0x0003, 0x0004, 0x001F, 0x0014, 0x0000,
    0x03C0, 0x0009, 0x000A, 0x001F, 0x0014, 0x0000, 0x0000, 0x0000,
};

u16 stage5_boss_fade_palettes_b[32] = {
    0x0004, 0x7FFF, 0x0000, 0x0400, 0x0004, 0x0005, 0x001F, 0x0003,
    0x7FFF, 0x0000, 0x0440, 0x000B, 0x000C, 0x001F, 0x0003, 0x7FFF,
    0x0000, 0x0480, 0x0012, 0x0013, 0x001F, 0x0003, 0x7FFF, 0x0000,
    0x0580, 0x0019, 0x001A, 0x001F, 0x0003, 0x0000, 0x0000, 0x0000,
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
extern u16 g_stage5_boss_all_forms;

#ifdef DEATH_LABEL
extern s8 g_death_boss_form_as_s8;
#endif

void stage5_boss_mode_form1_idle_start(void) {
    s32 boss_movement_start();
#ifdef DEATH_LABEL
    g_death_boss_form_as_s8 = 0;
#endif
    reg_d0.w = 0;
    boss_animation_start();
    reg_d0.w = 1;
    boss_animation_start();
    reg_d0.w = 0;
    boss_movement_start();
    slowdown_turn_off();
    MODE(reg_a4)->wait = 0x260;
    MODE(reg_a4)->second_wait = 0x160;
    if (g_stage5_boss_all_forms == 0) {
        stage5_boss_mode_form1_idle(0x260);
        return;
    }
    MODE(reg_a4)->second_wait = 0;
    stage5_boss_mode_form1_idle(0x260);
}

s32 boss_phase_start();
s32 fade_in_and_release();
s32 stage5_boss_form1_take_hits();
extern s16 g_boss_hyper_wait_as_s16;
extern u8 *g_boss_hp;
extern s32 g_boss_hp_unit;
extern u8 g_boss_present;
extern u8 g_boss_present_b1;
extern s16 g_true_last_boss_as_s16;

void stage5_boss_mode_form1_idle() {
    u16 temp_v1;
    u16 var_a1;

    temp_v1 = MODE(reg_a4)->second_wait;
    if (temp_v1 != 0) {
        MODE(reg_a4)->second_wait = (u16) (temp_v1 - 1);
        if (MODE(reg_a4)->second_wait == 0) {
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
    MODE(reg_a4)->wait -= 1;
    if (MODE(reg_a4)->wait == 0) {
        g_boss_hyper_wait_as_s16 = 1;
        if (g_stage5_boss_all_forms == 0) {
            g_boss_present_b1 |= 2;
            g_boss_present_b1 |= 0x10;
        } else {
            g_true_last_boss_as_s16 = 1;
        }
        stage5_boss_form1_take_hits();
        reg_a0 = (u8 *)stage5_boss_fade_palettes_b;
        fade_in_and_release();
        reg_d0.w = 6;
        boss_phase_start();
        MODE(reg_a4)->running = 0;
    }
}


void stage5_boss_mode_form1_explosion_start(void) {
    EXPLODING(reg_a4)->wait = 0xC0;
    EXPLODING(reg_a4)->blast.h = 0x303;
    stage5_boss_mode_form1_explosion(0xC0);
}

typedef void (*Fn)();

s32 boss_part_hide_all();
s32 ground_speeds_request();
s32 explosions_clear();
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
extern u8 g_slowdown_timer;

void stage5_boss_mode_form1_explosion() {
    s16 t1;
    s16 t2;
    u32 t3;
    u32 t4;
    u32 t5;
    u32 t6;
    EXPLODING(reg_a4)->wait -= 1;
    if (EXPLODING(reg_a4)->wait == 0) {
        explosions_clear();
        reg_d0.h[0] = 0xD;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        t6 = ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->x = t6;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->start_y = 0x1400U;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0x400;
        reg_d0.h[0] = 0x85;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->start_y = 0x1400U;
        EXPLOSION(reg_a0)->start_x = 0x600U;
        EXPLOSION(reg_a0)->move.h = 0x658;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0;
        EXPLOSION(reg_a0)->delay = 2;
        reg_d0.h[0] = 0xD;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->start_y = 0xC00U;
        EXPLOSION(reg_a0)->start_x = 0xFE00U;
        EXPLOSION(reg_a0)->move.h = 0x6A8;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0;
        EXPLOSION(reg_a0)->delay = 2;
        reg_d0.h[0] = 0x85;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->start_y = 0x400U;
        EXPLOSION(reg_a0)->start_x = 0xFC00U;
        EXPLOSION(reg_a0)->move.h = 0xA88;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0x400;
        EXPLOSION(reg_a0)->delay = 6;
        reg_d0.h[0] = 0xD;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->start_y = 0x600U;
        EXPLOSION(reg_a0)->start_x = 0x400U;
        EXPLOSION(reg_a0)->move.h = 0xA78;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0x400;
        EXPLOSION(reg_a0)->delay = 4;
        reg_d0.h[0] = 0x85;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->start_y = 0xF600U;
        EXPLOSION(reg_a0)->start_x = 0xA00U;
        EXPLOSION(reg_a0)->move.h = 0xA70;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0x400;
        EXPLOSION(reg_a0)->delay = 0xA;
        reg_d0.h[0] = 0xD;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->start_y = 0xF000U;
        EXPLOSION(reg_a0)->start_x = 0xFE00U;
        EXPLOSION(reg_a0)->move.h = 0x588;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0x400;
        EXPLOSION(reg_a0)->delay = 8;
        reg_d0.h[0] = 0x85;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->start_y = 0xE000U;
        EXPLOSION(reg_a0)->start_x = 0xFC00U;
        EXPLOSION(reg_a0)->move.h = 0x4A0;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0x400;
        EXPLOSION(reg_a0)->delay = 8;
        reg_d0.h[0] = 0xD;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->start_y = 0xD800U;
        EXPLOSION(reg_a0)->start_x = 0x400U;
        EXPLOSION(reg_a0)->move.h = 0x460;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0x400;
        EXPLOSION(reg_a0)->delay = 8;
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
        fade_in_and_release();
        if (g_stage5_boss_all_forms == 0) {
            sfx_explosion_boss();
            boss_part_hide_all();
            reg_d7.w = 0x14;
            reg_a3 = (u8 *)(stage5_boss_wreck_positions);
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
            EXPLODING(reg_a4)->running = 0;
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
        EXPLODING(reg_a4)->running = 0;
block_rts:
        return;
    }
    reg_tmp.b[0] = EXPLODING(reg_a4)->blast.t.count;
    EXPLODING(reg_a4)->blast.t.count -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto block_rts;
    }
    EXPLODING(reg_a4)->blast.t.count = (u8) EXPLODING(reg_a4)->blast.t.reload;
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
    reg_a1 = (u8 *)(stage5_boss_blast_kinds);
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    t5 = ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->x = t5;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    EXPLOSION(reg_a0)->debris = 0;
    EXPLOSION(reg_a0)->debris_arg = 0x800;
    func_00201270();
    reg_d0.b[0] += 3;
    EXPLOSION(reg_a0)->move.b.speed = (u8) reg_d0.b[0];
    rng_next_unsigned();
    EXPLOSION(reg_a0)->move.b.dir = reg_d0.b[0];
    rng_next_word();
    t4 = reg_d0.h[0];
    reg_d1.h[0] = t4;
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d0.h[0] = t4 + reg_d1.h[0];
    reg_d0.h[0] += 0x7FFF + 0x7801;
    EXPLOSION(reg_a0)->start_y = (u16) reg_d0.h[0];
    rng_next_word();
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
    EXPLOSION(reg_a0)->start_x = (u16) reg_d0.h[0];
}


#ifdef DEATH_LABEL
extern s8 g_death_boss_form_as_s8;
#endif

void stage5_boss_mode_form1_to_form2_start(void) {
#ifdef DEATH_LABEL
    g_death_boss_form_as_s8 = 1;
#endif
    MODE(reg_a4)->wait = 1;
    MODE(reg_a4)->second_wait = 0x80;
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

    temp_v1 = MODE(reg_a4)->wait;
    temp_a0 = reg_a4 + 2;
    if (temp_v1 != 0) {
        MODE(reg_a4)->wait = (u16) (temp_v1 - 1);
        if (MODE(reg_a4)->wait == 0) {
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
        MODE(reg_a4)->second_wait -= 1;
        if (MODE(reg_a4)->second_wait == 0) {
            reg_d0.w = 0xA;
            boss_phase_start();
            MODE(reg_a4)->running = 0;
        }
    }
}


void stage5_boss_mode_form2_explosion_start(void) {
    s32 boss_movement_start(s32, s32);
    EXPLODING(reg_a4)->wait = 0xC0;
    EXPLODING(reg_a4)->blast.sh = 0x303;
    reg_d0.w = 3;
    boss_movement_start(0x303, 0xC0);
    stage5_boss_mode_form2_explosion();
}


void stage5_boss_mode_form2_explosion(void) {
    u16 temp_a1;
    u16 temp_a3;
    EXPLODING(reg_a4)->wait -= 1;
    if (EXPLODING(reg_a4)->wait == 0) {
        sfx_explosion_extra_1();
        reg_d0.h[0] = 0xD;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        temp_a3 = ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->x = temp_a3;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->start_y = 0x1400U;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0x400;
        reg_d0.h[0] = 0x85;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->start_y = 0x1400U;
        EXPLOSION(reg_a0)->start_x = 0x600U;
        EXPLOSION(reg_a0)->move.h = 0x658;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0;
        EXPLOSION(reg_a0)->delay = 2;
        reg_d0.h[0] = 0xD;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->start_y = 0xC00U;
        EXPLOSION(reg_a0)->start_x = 0xFE00U;
        EXPLOSION(reg_a0)->move.h = 0x6A8;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0;
        EXPLOSION(reg_a0)->delay = 2;
        reg_d0.h[0] = 0x85;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->start_y = 0x400U;
        EXPLOSION(reg_a0)->start_x = 0xFC00U;
        EXPLOSION(reg_a0)->move.h = 0xA88;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0x400;
        EXPLOSION(reg_a0)->delay = 6;
        reg_d0.h[0] = 0xD;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->start_y = 0x600U;
        EXPLOSION(reg_a0)->start_x = 0x400U;
        EXPLOSION(reg_a0)->move.h = 0xA78;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0x400;
        EXPLOSION(reg_a0)->delay = 4;
        reg_d0.h[0] = 0x85;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->start_y = 0xF600U;
        EXPLOSION(reg_a0)->start_x = 0xA00U;
        EXPLOSION(reg_a0)->move.h = 0xA70;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0x400;
        EXPLOSION(reg_a0)->delay = 0xA;
        reg_d0.h[0] = 0xD;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->start_y = 0xF000U;
        EXPLOSION(reg_a0)->start_x = 0xFE00U;
        EXPLOSION(reg_a0)->move.h = 0x588;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0x400;
        EXPLOSION(reg_a0)->delay = 8;
        reg_d0.h[0] = 0x85;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->start_y = 0xE000U;
        EXPLOSION(reg_a0)->start_x = 0xFC00U;
        EXPLOSION(reg_a0)->move.h = 0x4A0;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0x400;
        EXPLOSION(reg_a0)->delay = 8;
        reg_d0.h[0] = 0xD;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->start_y = 0xD800U;
        EXPLOSION(reg_a0)->start_x = 0x400U;
        EXPLOSION(reg_a0)->move.h = 0x460;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0x400;
        EXPLOSION(reg_a0)->delay = 8;
        vibration_start_pad1(0xC8, 0x50, 0x460, 0x400);
        vibration_start_pad2(0xC8, 0x50);
        reg_a0 = (u8 *)stage5_boss_flash_palettes_b;
        fade_in_and_release();
        reg_d0.h[0] = 0x200;
        reg_d1.h[0] = 0x200;
        ground_speeds_request();
        reg_d0.w = 4;
        boss_phase_start();
        EXPLODING(reg_a4)->running = 0;
block_rts:
        return;
    }
    reg_tmp.b[0] = EXPLODING(reg_a4)->blast.t.count;
    EXPLODING(reg_a4)->blast.t.count -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto block_rts;
    }
    {
        EXPLODING(reg_a4)->blast.t.count = (u8) EXPLODING(reg_a4)->blast.t.reload;
        reg_a0 = (u8 *)sfx_explosion_air_medium;
        rng_next_unsigned();
        if (0 > reg_d0.sb[0]) {
            reg_a0 = (u8 *)sfx_explosion_air_large;
        }
        reg_call_target = (Fn)(reg_a0);
        reg_call_target();
        rng_next_unsigned();
        reg_d0.h[0] &= 7;
        reg_a1 = (u8 *)(stage5_boss_blast_kinds);
        reg_d0.h[0] += reg_d0.h[0];
        switch (reg_d0.h[0]) { case 0: goto block_zero; }
        temp_a3 = *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1));
        goto block_join;
block_zero:
        temp_a3 = *(u16 *)reg_a1;
block_join:
        reg_d0.h[0] = temp_a3;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        temp_a1 = ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->x = temp_a1;
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0x800;
        func_00201270();
        reg_d0.b[0] += 3;
        EXPLOSION(reg_a0)->move.b.speed = (u8) reg_d0.b[0];
        rng_next_unsigned();
        EXPLOSION(reg_a0)->move.b.dir = reg_d0.b[0];
        rng_next_word();
        reg_d1.h[0] = reg_d0.h[0];
        reg_d0.h[0] += 0xF800;
        EXPLOSION(reg_a0)->start_y = (u16) reg_d0.h[0];
        rng_next_word();
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
        EXPLOSION(reg_a0)->start_x = (u16) reg_d0.h[0];
    }
}

extern s16 g_enemy_signal_2_as_s16;


#ifdef DEATH_LABEL
extern s8 g_death_boss_form_as_s8;
#endif

void stage5_boss_mode_form2_to_form3_start(void) {
#ifdef DEATH_LABEL
    g_death_boss_form_as_s8 = 2;
#endif
    MODE(reg_a4)->wait = 1;
    MODE(reg_a4)->second_wait = 0x80;
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
extern u8 g_twin_boss_second[];
#endif

void stage5_boss_mode_form2_to_form3() {
    s32 boss_movement_start();
    u16 t1;
    u8 *t2;

    t1 = MODE(reg_a4)->wait;
    t2 = (u8 *)(reg_a4 + 2);
    if (t1 != 0) {
        MODE(reg_a4)->wait = (u16) (t1 - 1);
        if (MODE(reg_a4)->wait == 0) {
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
            ENTITY(g_twin_boss_second)->y.h = ENTITY(g_enemy_entities_second)->y.h;
            ENTITY(g_twin_boss_second)->x.h = ENTITY(g_enemy_entities_second)->x.h;
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
        MODE(reg_a4)->second_wait -= 1;
        if (MODE(reg_a4)->second_wait == 0) {
            reg_d0.w = MAIN_OR_DEATH_LABEL(0xF, 21);
            boss_phase_start();
            MODE(reg_a4)->running = 0;
        }
    }
}

s32 fade_out_and_release();                            /* extern */
s32 sprite_palette_load();                            /* extern */

void stage5_boss_mode_form3_explosion_start(void) {
    reg_d0.h[0] = 0xE;
    reg_a0 = (u8 *)palette_white;
    sprite_palette_load();
    reg_a0 = (u8 *)stage5_boss_fade_palettes_a;
    fade_out_and_release();
    FINAL_EXPLOSION(reg_a4)->step = 0;
    FINAL_EXPLOSION(reg_a4)->blast.sh = 0x101;
    FINAL_EXPLOSION(reg_a4)->entry = 0;
    FINAL_EXPLOSION(reg_a4)->rounds = 1;
    FINAL_EXPLOSION(reg_a4)->quickened = 0;
    FINAL_EXPLOSION(reg_a4)->burst_timer.sh = 0x2020;
    FINAL_EXPLOSION(reg_a4)->sound.both = 0;
    stage5_boss_mode_form3_explosion(1, 0x101);
}


s32 boss_slots_end();
s32 boss_flash_start();
s32 boss_flash_running();
s32 explosion_burst_medium();
s32 sfx_explosion_ground_medium();
s32 rng_next();

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
    if (FINAL_EXPLOSION(reg_a4)->step != 4) goto block_3;
    FINAL_EXPLOSION(reg_a4)->wait -= 1;
    if (FINAL_EXPLOSION(reg_a4)->wait != 0) goto block_rts_2;
    boss_slots_end();
    FINAL_EXPLOSION(reg_a4)->running = 0;
block_rts_2:
    return;
block_3:
    if (FINAL_EXPLOSION(reg_a4)->step != 3) goto block_2;
#ifdef DEATH_LABEL
    y = ENTITY(reg_a6)->x.h;
    x = ENTITY(reg_a6)->y.h;
    for (i = 0; i < 2; i++) {
#endif
    reg_d6.w = 0;
    reg_a1 = (u8 *)stage5_boss_final_blasts;
loop_1:
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    if ((s16)reg_d0.h[0] == -1) goto block_3_end;
    explosion_spawn();
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    EXPLOSION(reg_a0)->attr.b.flip = reg_d0.b[0];
    EXPLOSION(reg_a0)->start_y = *(u16 *)reg_a1;
    reg_a1 += 2;
    EXPLOSION(reg_a0)->start_x = *(u16 *)reg_a1;
    reg_a1 += 2;
    EXPLOSION(reg_a0)->y = BOSS_X;
    EXPLOSION(reg_a0)->x = BOSS_Y;
    EXPLOSION(reg_a0)->draw_layer = 8;
    EXPLOSION(reg_a0)->debris = 0;
    EXPLOSION(reg_a0)->debris_arg = 0;
    rng_next();
    reg_d0.b[0] += 4;
    reg_d0.b[0] += FINAL_EXPLOSION(reg_a4)->quickened;
    EXPLOSION(reg_a0)->move.b.speed = reg_d0.b[0];
    rng_next_unsigned();
    EXPLOSION(reg_a0)->move.b.dir = reg_d0.b[0];
    EXPLOSION(reg_a0)->delay = reg_d6.h[0];
    reg_d6.h[0] += 1;
    goto loop_1;
block_3_end:
#ifdef DEATH_LABEL
        x = ENTITY(reg_a6)[16].y.h;
        y = ENTITY(reg_a6)[16].x.h;
    }
#endif
    FINAL_EXPLOSION(reg_a4)->wait = 0x80;
    FINAL_EXPLOSION(reg_a4)->step = 4;
    sfx_explosion_boss();
    return;
block_2:
    if (FINAL_EXPLOSION(reg_a4)->step != 2) goto block_1;
    boss_flash_running();
    if (cond_flag != 0) goto block_1;
    reg_a0 = (u8 *)stage5_boss_flash_palettes_c;
    fade_in_and_release();
    boss_part_hide_all();
    FINAL_EXPLOSION(reg_a4)->rounds = 1;
    FINAL_EXPLOSION(reg_a4)->step = 3;
    return;
block_1:
    if (FINAL_EXPLOSION(reg_a4)->step != 1) goto block_0;
    reg_tmp.b[0] = FINAL_EXPLOSION(reg_a4)->burst_timer.t.count;
    FINAL_EXPLOSION(reg_a4)->burst_timer.t.count -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_1;
    FINAL_EXPLOSION(reg_a4)->burst_timer.t.count = FINAL_EXPLOSION(reg_a4)->burst_timer.t.reload;
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
    switch (FINAL_EXPLOSION(reg_a4)->blast.t.reload) { case 2: goto next_1; }
    sfx_explosion_ground_medium();
next_1:
    reg_tmp.b[0] = FINAL_EXPLOSION(reg_a4)->quicken_timer.t.count;
    FINAL_EXPLOSION(reg_a4)->quicken_timer.t.count -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_2;
    FINAL_EXPLOSION(reg_a4)->quicken_timer.t.count = FINAL_EXPLOSION(reg_a4)->quicken_timer.t.reload;
    if (FINAL_EXPLOSION(reg_a4)->blast.t.reload == 2) goto next_2;
    FINAL_EXPLOSION(reg_a4)->blast.t.reload -= 1;
    FINAL_EXPLOSION(reg_a4)->quickened += 1;
next_2:
    reg_tmp.b[0] = FINAL_EXPLOSION(reg_a4)->blast.t.count;
    FINAL_EXPLOSION(reg_a4)->blast.t.count -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto block_0;
    FINAL_EXPLOSION(reg_a4)->blast.t.count = FINAL_EXPLOSION(reg_a4)->blast.t.reload;
    if (FINAL_EXPLOSION(reg_a4)->blast.t.reload == 2) goto next_3;
    reg_tmp.b[0] = FINAL_EXPLOSION(reg_a4)->sound.b.large_wait;
    FINAL_EXPLOSION(reg_a4)->sound.b.large_wait -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_3;
    FINAL_EXPLOSION(reg_a4)->sound.b.large_wait = 4;
    sfx_explosion_air_large();
next_3:
#ifdef DEATH_LABEL
    y = ENTITY(reg_a6)->x.h;
    x = ENTITY(reg_a6)->y.h;
    for (i = 0; i < 2; i++) {
#endif
    reg_a1 = (u8 *)stage5_boss_final_blasts;
    reg_a1 += FINAL_EXPLOSION(reg_a4)->entry;
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    explosion_spawn();
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    EXPLOSION(reg_a0)->attr.b.flip = reg_d0.b[0];
    EXPLOSION(reg_a0)->start_y = *(u16 *)reg_a1;
    reg_a1 += 2;
    EXPLOSION(reg_a0)->start_x = *(u16 *)reg_a1;
    reg_a1 += 2;
    EXPLOSION(reg_a0)->y = BOSS_X;
    EXPLOSION(reg_a0)->x = BOSS_Y;
    EXPLOSION(reg_a0)->draw_layer = 8;
    rng_next();
    reg_d0.b[0] = (s8)reg_d0.b[0] >> 2;
    reg_d0.b[0] += 2;
    reg_d1.b[0] = FINAL_EXPLOSION(reg_a4)->quickened;
    reg_d1.b[0] = (s8)reg_d1.b[0] >> 1;
    reg_d0.b[0] += reg_d1.b[0];
    EXPLOSION(reg_a0)->move.b.speed = reg_d0.b[0];
    rng_next_unsigned();
    EXPLOSION(reg_a0)->move.b.dir = reg_d0.b[0];
#ifdef DEATH_LABEL
        x = ENTITY(reg_a6)[16].y.h;
        y = ENTITY(reg_a6)[16].x.h;
    }
#endif
    FINAL_EXPLOSION(reg_a4)->entry += 8;
    if (FINAL_EXPLOSION(reg_a4)->entry != 0x80) goto block_0;
    FINAL_EXPLOSION(reg_a4)->entry = 0;
    if (FINAL_EXPLOSION(reg_a4)->blast.t.reload != 2) goto block_0;
    reg_d0.h[0] = 0xE;
    boss_flash_start();
    FINAL_EXPLOSION(reg_a4)->step = 2;
    return;
block_0:
    if (FINAL_EXPLOSION(reg_a4)->step != 0) return;
    reg_tmp.b[0] = FINAL_EXPLOSION(reg_a4)->blast.t.count;
    FINAL_EXPLOSION(reg_a4)->blast.t.count -= 1;
    if ((s32)reg_tmp.b[0] > 0) return;
    FINAL_EXPLOSION(reg_a4)->blast.t.count = FINAL_EXPLOSION(reg_a4)->blast.t.reload;
    if (FINAL_EXPLOSION(reg_a4)->sound.b.skipped & 1) {
        FINAL_EXPLOSION(reg_a4)->sound.b.skipped &= 0xFE;
        goto next_4;
    }
    FINAL_EXPLOSION(reg_a4)->sound.b.skipped |= 1;
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
    reg_a1 = (u8 *)stage5_boss_final_blasts;
    reg_a1 += FINAL_EXPLOSION(reg_a4)->entry;
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    explosion_spawn();
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    EXPLOSION(reg_a0)->attr.b.flip = reg_d0.b[0];
    EXPLOSION(reg_a0)->start_y = *(u16 *)reg_a1;
    reg_a1 += 2;
    EXPLOSION(reg_a0)->start_x = *(u16 *)reg_a1;
    reg_a1 += 2;
    EXPLOSION(reg_a0)->y = BOSS_X;
    EXPLOSION(reg_a0)->x = BOSS_Y;
    EXPLOSION(reg_a0)->draw_layer = 8;
    EXPLOSION(reg_a0)->debris = 0;
    EXPLOSION(reg_a0)->debris_arg = 0;
#ifdef DEATH_LABEL
        x = ENTITY(reg_a6)[16].y.h;
        y = ENTITY(reg_a6)[16].x.h;
    }
#endif
    FINAL_EXPLOSION(reg_a4)->entry += 8;
    if ((s32)FINAL_EXPLOSION(reg_a4)->entry < 0x80) return;
    FINAL_EXPLOSION(reg_a4)->entry = 0;
    FINAL_EXPLOSION(reg_a4)->rounds -= 1;
    if (FINAL_EXPLOSION(reg_a4)->rounds != 0) return;
    FINAL_EXPLOSION(reg_a4)->blast.h = 0x2010;
    FINAL_EXPLOSION(reg_a4)->quicken_timer.h = 0x1111;
    FINAL_EXPLOSION(reg_a4)->step = 1;
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
        MODE(reg_a4)->running = 0;
    }
}



void stage5_boss_mode_form1_mouth_start(void) {
    MODE(reg_a4)->wait = 0x60;
    stage5_boss_mode_form1_mouth();
}

s32 boss_attack_start();
s32 boss_attack_running();
extern u16 g_bullets_blocked;

void stage5_boss_mode_form1_mouth() {
    u16 temp_a0;

    temp_a0 = MODE(reg_a4)->wait;
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            MODE(reg_a4)->wait = (u16) (temp_a0 - 1);
            if (MODE(reg_a4)->wait == 0) {
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
            MODE(reg_a4)->running = 0;
        }
    }
}


void stage5_boss_mode_form1_arm_guns_fixed_start(void) {
    MODE(reg_a4)->wait = 0x60;
    stage5_boss_mode_form1_arm_guns_fixed();
}

void stage5_boss_mode_form1_arm_guns_fixed() {
    u16 temp_a0;

    temp_a0 = MODE(reg_a4)->wait;
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            MODE(reg_a4)->wait = (u16) (temp_a0 - 1);
            if (MODE(reg_a4)->wait == 0) {
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
            MODE(reg_a4)->running = 0;
        }
    }
}


void stage5_boss_mode_form1_horn_start(void) {
    MODE(reg_a4)->wait = 0x60;
    MODE(reg_a4)->second_wait = 0x40;
    stage5_boss_mode_form1_horn(0x60);
}

void stage5_boss_mode_form1_horn() {
    u16 temp_a0;

    temp_a0 = MODE(reg_a4)->wait;
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            MODE(reg_a4)->wait = (u16) (temp_a0 - 1);
            if (MODE(reg_a4)->wait == 0) {
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
            MODE(reg_a4)->second_wait -= 1;
            if (MODE(reg_a4)->second_wait == 0) {
                reg_d0.w = 6;
                boss_phase_start();
                MODE(reg_a4)->running = 0;
            }
        }
    }
}


void stage5_boss_mode_form2_mouth_start(void) {
    MODE(reg_a4)->wait = 1;
    stage5_boss_mode_form2_mouth();
}

void stage5_boss_mode_form2_mouth() {
    u16 temp_a0;

    temp_a0 = MODE(reg_a4)->wait;
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            MODE(reg_a4)->wait = (u16) (temp_a0 - 1);
            if (MODE(reg_a4)->wait == 0) {
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
            MODE(reg_a4)->running = 0;
        }
    }
}


void stage5_boss_mode_form2_jet_start(void) {
    MODE(reg_a4)->wait = 0x40;
    stage5_boss_mode_form2_jet();
}

void stage5_boss_mode_form2_jet() {
    s32 boss_movement_start();
    u16 temp_a0;

    temp_a0 = MODE(reg_a4)->wait;
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            MODE(reg_a4)->wait = (u16) (temp_a0 - 1);
            if (MODE(reg_a4)->wait == 0) {
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
            MODE(reg_a4)->running = 0;
        }
    }
}


void stage5_boss_mode_form2_horn_start(void) {
    s32 boss_movement_start(s32);
    MODE(reg_a4)->wait = 0x50;
    reg_d0.w = 6;
    boss_movement_start(0x50);
    stage5_boss_mode_form2_horn();
}

void stage5_boss_mode_form2_horn() {
    u16 temp_a0;

    temp_a0 = MODE(reg_a4)->wait;
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            MODE(reg_a4)->wait = (u16) (temp_a0 - 1);
            if (MODE(reg_a4)->wait == 0) {
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
            MODE(reg_a4)->running = 0;
        }
    }
}


void stage5_boss_mode_form2_stinger_start(void) {
    s32 boss_movement_start(s32, s32);
    MODE(reg_a4)->wait = 0x60;
    MODE(reg_a4)->second_wait = 0x40;
    reg_d0.w = 7;
    boss_movement_start(0x40, 0x60);
    ENTITY(reg_a6)->move.sb.speed = 0xC;
    stage5_boss_mode_form2_stinger();
}

void stage5_boss_mode_form2_stinger() {
    s32 boss_movement_start();
    u16 temp_a0;

    temp_a0 = MODE(reg_a4)->wait;
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            MODE(reg_a4)->wait = (u16) (temp_a0 - 1);
            if (MODE(reg_a4)->wait == 0) {
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
            MODE(reg_a4)->second_wait -= 1;
            if (MODE(reg_a4)->second_wait == 0) {
                reg_d0.w = 0xA;
                boss_phase_start();
                reg_d0.w = 2;
                boss_movement_start();
                MODE(reg_a4)->running = 0;
            }
        }
    }
}


void stage5_boss_mode_form1_rage_start(void) {
    MODE(reg_a4)->wait = 0x40;
    MODE(reg_a4)->second_wait = 1;
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

    temp_a0 = MODE(reg_a4)->wait;
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            MODE(reg_a4)->wait = (u16) (temp_a0 - 1);
            if (MODE(reg_a4)->wait == 0) {
                reg_d0.w = 4;
                boss_attack_start();
                goto block_4;
            }
        }
    } else {
block_4:
        temp_v1 = MODE(reg_a4)->second_wait;
        if (temp_v1 != 0) {
            MODE(reg_a4)->second_wait = (u16) (temp_v1 - 1);
            if (MODE(reg_a4)->second_wait == 0) {
                stage5_boss_shield_off();
            }
        }
    }
}


void stage5_boss_mode_form3_attack_a_start(void) {
    MODE(reg_a4)->wait = 0x60;
    stage5_boss_mode_form3_attack_a();
}

void stage5_boss_mode_form3_attack_a() {
    s32 boss_movement_start();
    u16 temp_a0;

    temp_a0 = MODE(reg_a4)->wait;
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            MODE(reg_a4)->wait = (u16) (temp_a0 - 1);
            if (MODE(reg_a4)->wait == 0) {
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
            MODE(reg_a4)->running = 0;
        }
    }
}


void stage5_boss_mode_form3_attack_b_start(void) {
    MODE(reg_a4)->wait = 0x60;
    stage5_boss_mode_form3_attack_b();
}

void stage5_boss_mode_form3_attack_b() {
    s32 boss_movement_start();
    u16 temp_a0;

    temp_a0 = MODE(reg_a4)->wait;
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            MODE(reg_a4)->wait = (u16) (temp_a0 - 1);
            if (MODE(reg_a4)->wait == 0) {
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
            MODE(reg_a4)->running = 0;
        }
    }
}


void stage5_boss_mode_form3_attack_c_start(void) {
    MODE(reg_a4)->wait = 0x60;
    stage5_boss_mode_form3_attack_c();
}

void stage5_boss_mode_form3_attack_c() {
    s32 boss_movement_start();
    u16 temp_a0;

    temp_a0 = MODE(reg_a4)->wait;
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            MODE(reg_a4)->wait = (u16) (temp_a0 - 1);
            if (MODE(reg_a4)->wait == 0) {
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
            MODE(reg_a4)->running = 0;
        }
    }
}


void stage5_boss_mode_form3_attack_d_start(void) {
    MODE(reg_a4)->wait = 0x60;
    MODE(reg_a4)->second_wait = 0x40;
    stage5_boss_mode_form3_attack_d(0x60);
}

void stage5_boss_mode_form3_attack_d() {
    s32 boss_movement_start();
    u16 temp_a0;

    temp_a0 = MODE(reg_a4)->wait;
    if (temp_a0 != 0) {
        if (g_bullets_blocked == 0) {
            MODE(reg_a4)->wait = (u16) (temp_a0 - 1);
            if (MODE(reg_a4)->wait == 0) {
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
            MODE(reg_a4)->second_wait -= 1;
            if (MODE(reg_a4)->second_wait == 0) {
                reg_d0.w = 0xF;
                boss_phase_start();
                reg_d0.w = MAIN_OR_DEATH_LABEL(4, 16);
                boss_movement_start();
                MODE(reg_a4)->running = 0;
            }
        }
    }
}


void stage5_boss_mode_form3_rage_start(void) {
    s32 boss_movement_start(s32);
    MODE(reg_a4)->wait = 0x60;
    reg_d0.w = MAIN_OR_DEATH_LABEL(0xB, 0x10);
    boss_movement_start(0x60);
    stage5_boss_mode_form3_rage();
}

void stage5_boss_mode_form3_rage() {
    u16 temp_a0;

    temp_a0 = MODE(reg_a4)->wait;
    if ((temp_a0 != 0) && (g_bullets_blocked == 0)) {
        MODE(reg_a4)->wait = (u16) (temp_a0 - 1);
        if (MODE(reg_a4)->wait == 0) {
            reg_d0.w = 0xD;
            boss_attack_start();
            stage5_boss_shield_off();
        }
    }
}


void stage5_boss_mode_form1_explosion_afterglow_start(void) {
    MODE(reg_a4)->wait = 0x80;
    stage5_boss_mode_form1_explosion_afterglow();
}

void stage5_boss_mode_form1_explosion_afterglow() {
    MODE(reg_a4)->wait -= 1;
    if (MODE(reg_a4)->wait == 0) {
        boss_slots_end();
        MODE(reg_a4)->running = 0;
    }
}
