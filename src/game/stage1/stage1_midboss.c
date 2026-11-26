#include "common.h"
#include "entity.h"
#include "explosion.h"
#include "enemy.h"
#include "enemy_kinds.h"

extern u16 stage1_midboss_explosions[];
extern u16 stage1_midboss_state_init[];
extern u16 stage1_midboss_entities[];
extern u16 stage1_midboss_hatch_frames[];
extern u16 stage1_midboss_arm_frames[];
extern u16 stage1_midboss_core_frames[];
extern u16 stage1_midboss_body_frames[];
extern u16 stage1_midboss_direction64_offsets_166[];
extern u16 stage1_midboss_fade_script[];
extern u16 stage1_midboss_wreck_entities[];
extern u16 stage1_midboss_wreck_state_init[2];

/* The stage 1 mid-boss: its state block, its body (the first entity) and its eight arms (two entities each). */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 dying;
    /* 0x17 */ u8 arrived;
    /* 0x18 */ u8 spin_backward;
    /* 0x19 */ u8 spin_hold;
    /* 0x1A */ u8 spin_speed;
    /* 0x1B */ u8 spin_top_speed;
    /* 0x1C */ EnemyTimer spin_step;
    /* 0x1E */ u8 unused_1E;
    /* 0x1F */ u8 arms_busy;
    /* 0x20 */ u8 fight;              /* 0: cannot be hurt yet, 1: fighting, 0xFF: leaving */
    /* 0x21 */ u8 arm_turn;
    /* 0x22 */ EnemyTimer body_timer;
    /* 0x24 */ u16 body_frame;
    /* 0x26 */ u16 hp;
    /* 0x28 */ u16 wreck_value;
    /* 0x2A */ u8 unused_2A[0x1A];
    /* 0x44 */ u16 after_entities[2];
} Stage1MidbossState;

#define STAGE1_MIDBOSS(pointer) ((Stage1MidbossState *)(pointer))

typedef struct {
    /* 0x00 */ Field16 flags;
    /* 0x02 */ Field16 y;
    /* 0x04 */ Field16 x;
    /* 0x06 */ EnemyTimer open_wait;
    /* 0x08 */ u16 core_frame;        /* 0: shut, 0x7C: open */
    /* 0x0A */ EnemyTimer core_timer;
    /* 0x0C */ u8 volleys_left;
    /* 0x0D */ u8 core_phase;         /* 0: shut, 1: opening, 2: firing, 3: closing */
    /* 0x0E */ EnemyTimer volley_timer;
    /* 0x10 */ u8 hit_box[8];
    /* 0x18 */ Field16 hp;
    /* 0x1A */ u16 unused_1A;
    /* 0x1C */ Field16 attr;          /* b[0]: palette */
    /* 0x1E */ u8 hit_flash;
    /* 0x1F */ u8 normal_palette;
} Stage1MidbossBody;

#define MIDBOSS_BODY(pointer) ((Stage1MidbossBody *)(pointer))

typedef struct {
    /* 0x00 */ Field16 flags;         /* 0x8000: destroyed */
    /* 0x02 */ Field16 y;
    /* 0x04 */ Field16 x;
    /* 0x06 */ EnemyTimer burst_pause;
    /* 0x08 */ u8 blow_up;
    /* 0x09 */ u8 phase;              /* 0: aimed bursts, 1: opening, 2: sweeping, 3: closing */
    /* 0x0A */ u16 hatch_frame;
    /* 0x0C */ EnemyTimer hatch_timer;
    /* 0x0E */ u8 other_0E[10];
    /* 0x18 */ Field16 hp;
    /* 0x1A */ u8 angle;
    /* 0x1B */ u8 angle_part;
    /* 0x1C */ Field16 attr;
    /* 0x1E */ u8 hit_flash;
    /* 0x1F */ u8 normal_palette;
    /* 0x20 */ u8 other_20[6];
    /* 0x26 */ EnemyTimer sweep_shot;
    /* 0x28 */ u8 unread_28;
    /* 0x29 */ u8 sweep_shots_left;
    /* 0x2A */ u8 burst_shots;
    /* 0x2B */ u8 burst_shots_left;
    /* 0x2C */ EnemyTimer shot;
    /* 0x2E */ EnemyTimer spin_timer;
    /* 0x30 */ u16 spin_frame;
    /* 0x32 */ u8 other_32[0xE];
} Stage1MidbossArm;

#define MIDBOSS_ARM(pointer) ((Stage1MidbossArm *)(pointer))

void stage1_midboss_next_spin(void);
void stage1_midboss_draw_arms(void);
void stage1_midboss_draw_core(void);
void stage1_midboss_draw_body(void);

s32 bullet_fire256();

void stage1_midboss_fan_singles(void) {

    reg_d0.w = 0x50003;
    reg_d7.w = 3;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w += 0x12000000;
        if (!(MIDBOSS_BODY(reg_a6)->volleys_left & 1)) {
            bullet_fire256();
        }
        reg_d1.h[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

s32 bullet_fire256_2way();

void stage1_midboss_fan_pairs(void) {

    reg_d0.w = 0x50004;
    reg_d7.w = 3;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w += 0x27000000;
        if (MIDBOSS_BODY(reg_a6)->volleys_left & 1) {
            bullet_fire256_2way();
        }
        reg_d1.h[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

s32 explosion_spawn();
s32 sfx_explosion_extra_1();

void stage1_midboss_blow_up(arg1)
    u16 arg1;
{
    s16 var_a0;
    u16 temp_a1;
    u16 var_a1;

    var_a1 = arg1;
    var_a0 = 0x70;
    STAGE1_MIDBOSS(reg_a5)->dying = 0x70;
    reg_d7.w = 7;
    reg_a4 = reg_a6 + 0x20;
    do {
        if (MIDBOSS_ARM(reg_a4)->flags.h == 0x8000) {
            reg_d0.w = 0xC;
            explosion_spawn();
            var_a0 = 2;
            EXPLOSION(reg_a0)->y = (u16) MIDBOSS_ARM(reg_a4)->y.h;
            var_a1 = MIDBOSS_ARM(reg_a4)->x.h;
            EXPLOSION(reg_a0)->x = var_a1;
            EXPLOSION(reg_a0)->follows_scroll = 2;
            EXPLOSION(reg_a0)->draw_layer = 0xC;
            EXPLOSION(reg_a0)->debris = 0;
            EXPLOSION(reg_a0)->debris_arg = 0;
        }
        MIDBOSS_ARM(reg_a4)->blow_up = 1;
        reg_a4 += 0x40;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    sfx_explosion_extra_1();
    reg_a4 = (u8 *)stage1_midboss_explosions;
loop_5:
    temp_a1 = *(u16 *)reg_a4;
    reg_d1.h[0] = temp_a1;
    reg_a4 += 2;
    if ((s16) reg_d1.h[0] != -1) {
        reg_d0.h[0] = *(u16 *)reg_a4;
        reg_a4 += 2;
        explosion_spawn();
        EXPLOSION(reg_a0)->delay = (u16) reg_d1.h[0];
        EXPLOSION(reg_a0)->start_y = (u16) *(u16 *)reg_a4;
        reg_a4 += 2;
        EXPLOSION(reg_a0)->start_x = (u16) *(u16 *)reg_a4;
        reg_a4 += 2;
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
        EXPLOSION(reg_a0)->follows_scroll = 2;
        EXPLOSION(reg_a0)->draw_layer = 0xC;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0x800;
        goto loop_5;
    }
}


void stage1_midboss_place_arms(void) {
    reg_d5.w = 0;
    reg_d7.w = 7;
    reg_d6.w = 0;
    reg_a0 = reg_a6 + 0x20;
    do {
        MIDBOSS_ARM(reg_a0)->angle = reg_d6.b[0];
        MIDBOSS_ARM(reg_a0)->unread_28 = reg_d5.b[0];
        reg_d6.b[0] += 0x20;
        reg_d5.b[0] += 8;
        reg_a0 += 0x40;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    stage1_midboss_next_spin();
}

s32 rng_next_bit();
s32 func_00201270();

void stage1_midboss_next_spin(void) {
    func_00201270();
    reg_tmp.h[0] = (u16) (s8) reg_d0.b[0];
    reg_d0.h[0] = reg_tmp.h[0];
    reg_d0.b[0] += reg_d0.b[0];
    reg_d0.h[0] += 0x14;
    STAGE1_MIDBOSS(reg_a5)->spin_top_speed = (u8) reg_d0.b[0];
    STAGE1_MIDBOSS(reg_a5)->spin_speed = 0;
    STAGE1_MIDBOSS(reg_a5)->spin_step.b.countdown = 0;
    func_00201270();
    reg_d0.b[0] += reg_d0.b[0];
    reg_d0.b[0] += 0x10;
    STAGE1_MIDBOSS(reg_a5)->spin_step.b.interval = (u8) reg_d0.b[0];
    STAGE1_MIDBOSS(reg_a5)->spin_backward = 0;
    rng_next_bit();
    if (reg_d0.h[0] != 0) {
        STAGE1_MIDBOSS(reg_a5)->spin_backward = 1;
    }
    func_00201270();
    reg_d0.b[0] *= 4;
    reg_d0.b[0] += 0x10;
    STAGE1_MIDBOSS(reg_a5)->spin_hold = (u8) reg_d0.b[0];
}

s32 velocity_from_dir256();

void stage1_midboss_move_arms(void) {
    if (STAGE1_MIDBOSS(reg_a5)->arms_busy != 0) goto block_main;
    reg_d0.b[0] = STAGE1_MIDBOSS(reg_a5)->spin_top_speed;
    if (reg_d0.b[0] == 0) goto next_1;
    if (STAGE1_MIDBOSS(reg_a5)->spin_speed == reg_d0.b[0]) goto next_1;
#ifdef DEATH_LABEL
    STAGE1_MIDBOSS(reg_a5)->spin_step.b.countdown -= 1;
    if ((s8) STAGE1_MIDBOSS(reg_a5)->spin_step.b.countdown >= 0) goto block_main;
    STAGE1_MIDBOSS(reg_a5)->spin_step.b.countdown = STAGE1_MIDBOSS(reg_a5)->spin_step.b.interval;
    STAGE1_MIDBOSS(reg_a5)->spin_speed += 1;
    goto block_main;
next_1:
    if (STAGE1_MIDBOSS(reg_a5)->spin_hold != 0) goto next_3;
    STAGE1_MIDBOSS(reg_a5)->spin_step.b.countdown -= 1;
    if ((s8) STAGE1_MIDBOSS(reg_a5)->spin_step.b.countdown >= 0) goto block_main;
    STAGE1_MIDBOSS(reg_a5)->spin_step.b.countdown = STAGE1_MIDBOSS(reg_a5)->spin_step.b.interval;
    STAGE1_MIDBOSS(reg_a5)->spin_speed -= 1;
    if ((s8) STAGE1_MIDBOSS(reg_a5)->spin_speed > 0) goto block_main;
    if ((s8) STAGE1_MIDBOSS(reg_a5)->fight >= 0) goto next_2;
#else
    reg_tmp.b[0] = STAGE1_MIDBOSS(reg_a5)->spin_step.b.countdown;
    STAGE1_MIDBOSS(reg_a5)->spin_step.b.countdown -= 1;
    if (reg_tmp.sb[0] > 0) goto block_main;
    STAGE1_MIDBOSS(reg_a5)->spin_step.b.countdown = STAGE1_MIDBOSS(reg_a5)->spin_step.b.interval;
    STAGE1_MIDBOSS(reg_a5)->spin_speed += 1;
    goto block_main;
next_1:
    if (STAGE1_MIDBOSS(reg_a5)->spin_hold != 0) goto next_3;
    reg_tmp.b[0] = STAGE1_MIDBOSS(reg_a5)->spin_step.b.countdown;
    STAGE1_MIDBOSS(reg_a5)->spin_step.b.countdown -= 1;
    if (reg_tmp.sb[0] > 0) goto block_main;
    STAGE1_MIDBOSS(reg_a5)->spin_step.b.countdown = STAGE1_MIDBOSS(reg_a5)->spin_step.b.interval;
    reg_tmp.b[0] = STAGE1_MIDBOSS(reg_a5)->spin_speed;
    STAGE1_MIDBOSS(reg_a5)->spin_speed -= 1;
    if (reg_tmp.sb[0] >= 2) goto block_main;
    if ((s8) STAGE1_MIDBOSS(reg_a5)->fight <= 0) goto next_2;
#endif
    STAGE1_MIDBOSS(reg_a5)->arms_busy = 1;
    rng_next_bit();
    reg_d0.b[0] += 1;
    reg_d6.b[0] = reg_d0.b[0];
    reg_a4 = reg_a6 + 0x20;
    reg_d7.w = 7;
    do {
        MIDBOSS_ARM(reg_a4)->phase = 1;
        MIDBOSS_ARM(reg_a4)->sweep_shots_left = reg_d6.b[0];
        reg_a4 += 0x40;
    } while ((s16)(--reg_d7.h[0]) >= 0);
next_2:
    stage1_midboss_next_spin();
    goto block_main;
next_3:
    STAGE1_MIDBOSS(reg_a5)->spin_hold -= 1;
    if (STAGE1_MIDBOSS(reg_a5)->spin_hold != 0) goto block_main;
    STAGE1_MIDBOSS(reg_a5)->spin_top_speed = 0;
    STAGE1_MIDBOSS(reg_a5)->spin_step.both = 0x404;
block_main:
    reg_d5.w = 0;
    reg_d5.b[0] = STAGE1_MIDBOSS(reg_a5)->spin_speed;
    if (STAGE1_MIDBOSS(reg_a5)->spin_backward == 0) goto next_4;
    reg_d5.h[0] *= 0xFFFF;
next_4:
    reg_a4 = reg_a6 + 0x20;
    reg_d7.w = 7;
    do {
        reg_d0.h[0] = 0x70;
        reg_d1.w = 0;
        reg_d1.b[0] = MIDBOSS_ARM(reg_a4)->angle;
        velocity_from_dir256();
        reg_d6.h[1] = ENTITY(reg_a6)->y.h;
        reg_d6.h[0] = ENTITY(reg_a6)->x.h;
        reg_d6.w += 0x02000000;
        MIDBOSS_ARM(reg_a4)->y.h = reg_d6.h[1];
        MIDBOSS_ARM(reg_a4)->x.h = reg_d6.h[0];
        reg_d1.h[0] = reg_d2.h[0];
        reg_d2.h[0] = (s16) reg_d2.h[0] * 2;
        reg_d3.h[0] = reg_d3.sh[0] * 4;
        reg_d2.h[0] = reg_d2.sh[0] + reg_d1.sh[0];
        MIDBOSS_ARM(reg_a4)->y.sh += reg_d2.sh[0];
        MIDBOSS_ARM(reg_a4)->x.sh += reg_d3.sh[0];
        reg_d6.w = 0;
        reg_d6.b[0] = MIDBOSS_ARM(reg_a4)->angle_part;
        reg_tmp6.h[0] = (u16) reg_d6.sb[0];
        reg_d6.h[0] = reg_tmp6.h[0];
        reg_d6.h[0] = reg_d6.sh[0] + reg_d5.sh[0];
        if ((s16) reg_d6.h[0] >= 0) {
            reg_d4.w = 1;
        } else {
            reg_d4.w = -1;
            reg_d6.h[0] *= 0xFFFF;
        }
loop_6:
        reg_d0.h[0] = 0x70;
        reg_d1.h[0] = reg_d4.h[0];
        reg_d1.b[0] += MIDBOSS_ARM(reg_a4)->angle;
        reg_d1.h[0] = reg_d1.b[0];
        velocity_from_dir256();
        reg_d1.h[0] = reg_d2.h[0];
        reg_d2.h[0] = (s16) reg_d2.h[0] * 2;
        reg_d3.h[0] = reg_d3.sh[0] * 4;
        reg_d2.h[0] = reg_d2.sh[0] + reg_d1.sh[0];
        reg_d2.h[0] = reg_d2.sh[0] + ENTITY(reg_a6)->y.sh;
        reg_d2.h[0] = reg_d2.sh[0] + 0x200;
        reg_d3.h[0] = reg_d3.sh[0] + ENTITY(reg_a6)->x.sh;
        reg_d2.h[0] = reg_d2.sh[0] - MIDBOSS_ARM(reg_a4)->y.sh;
        reg_d3.h[0] = reg_d3.sh[0] - MIDBOSS_ARM(reg_a4)->x.sh;
        reg_d2.h[0] = reg_d2.sh[0] >> 4;
        reg_d3.h[0] = reg_d3.sh[0] >> 4;
        reg_tmp2.w = (s16) reg_d2.h[0];
        reg_d2.w = reg_tmp2.w;
        reg_tmp3.w = (s16) reg_d3.h[0];
        reg_d3.w = reg_tmp3.w;
#ifdef DEATH_LABEL
        reg_d2.h[0] = reg_d2.sh[0] * reg_d6.sh[0];
        reg_d3.h[0] = reg_d3.sh[0] * reg_d6.sh[0];
#else
        reg_d2.h[0] = reg_d2.h[0] * reg_d6.h[0];
        reg_d3.h[0] = (s16) reg_d3.h[0] * reg_d6.h[0];
#endif
        MIDBOSS_ARM(reg_a4)->y.sh += reg_d2.sh[0];
        MIDBOSS_ARM(reg_a4)->x.sh += reg_d3.sh[0];
        if (reg_d6.sh[0] < 0x10) goto next_7;
#ifdef DEATH_LABEL
        MIDBOSS_ARM(reg_a4)->angle += reg_d4.b[0];
#else
        MIDBOSS_ARM(reg_a4)->angle = (s8) MIDBOSS_ARM(reg_a4)->angle + reg_d4.sb[0];
#endif
        reg_d6.h[0] -= 0x10;
        if (reg_d6.h[0] != 0) goto loop_6;
next_7:
        if (reg_d4.sh[0] >= 0) goto next_8;
        reg_d6.h[0] *= 0xFFFF;
next_8:
        MIDBOSS_ARM(reg_a4)->angle_part = reg_d6.b[0];
        reg_tmp.b[0] = MIDBOSS_ARM(reg_a4)->spin_timer.b.countdown;
        MIDBOSS_ARM(reg_a4)->spin_timer.b.countdown -= 1;
        if ((s32) reg_tmp.b[0] > 0) goto next_9;
        MIDBOSS_ARM(reg_a4)->spin_timer.b.countdown = MIDBOSS_ARM(reg_a4)->spin_timer.b.interval;
        MIDBOSS_ARM(reg_a4)->spin_frame += 4;
        MIDBOSS_ARM(reg_a4)->spin_frame &= 0x7F;
next_9:
        reg_a4 += 0x40;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}


void stage1_midboss_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0x10);
}

s32 enemy_set_task_state();
s32 enemy_init_entities();
s32 enemy_path_start();
s32 sprite_palette_load();
extern u8 D_002601B0[];
extern u8 D_002601F0[];
extern u8 D_00260230[];
extern s16 g_enemy_signal_1_as_s16;
extern s16 g_enemy_signal_0_as_s16;
extern s8 enemy_move_end_requested;

void stage1_midboss_start() {
    reg_a0 = (u8 *) stage1_midboss_entities;
    enemy_init_entities();
    reg_tmp.w = (u32) reg_a0;
    STAGE1_MIDBOSS(reg_a5)->after_entities[0] = (u16) reg_tmp.h[1];
    STAGE1_MIDBOSS(reg_a5)->after_entities[1] = (u16) reg_tmp.h[0];
    reg_a0 = (u8 *) stage1_midboss_state_init;
    reg_d0.h[0] = 9;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        ENTITY(reg_a6)->y.h += 0xA40;
        stage1_midboss_place_arms();
        stage1_midboss_move_arms();
        g_enemy_signal_1_as_s16 = 0;
        g_enemy_signal_0_as_s16 = 1;
        reg_d0.h[0] = 0x10;
        reg_a0 = D_002601B0;
        sprite_palette_load();
        reg_d0.h[0] = 0x11;
        reg_a0 = D_002601F0;
        sprite_palette_load();
        reg_d0.h[0] = 0xF;
        reg_a0 = D_00260230;
        sprite_palette_load();
    }
}

s32 bullet_fire256_3way();
s32 func_001368E0();
s32 ground_speeds_request();
s32 fade_in_and_release();
s32 enemy_hitbox_debug_draw();
s32 spawn_request_add();
s32 enemy_remove();
s32 sfx_explosion_air_small();
s32 score_add_no_chain();
s32 score_add();
s32 func_00201800();
s32 entity_follow_scroll();
s32 aim256_at_player();
s32 vibration_start_pad1();
s32 vibration_start_pad2();
extern u8 g_direction64_offsets_432[];
extern u8 g_slowdown_timer;
extern u16 g_enemy_signal_1;
extern u16 g_enemy_signal_0;
extern u16 g_enemies_stopped;
extern u16 g_scroll_line;

void stage1_midboss_main(void) {
    u16 temp_v1;
    u8 temp_a0;
    u32 temp_a0_2;
    u8 temp_a1;
    u8 temp_v0_2;
    u8 temp_v0_5;
    u8 *var_a0;

    if (STAGE1_MIDBOSS(reg_a5)->dying != 0) {
        entity_follow_scroll();
        reg_d1.h[0] = STAGE1_MIDBOSS(reg_a5)->wreck_value;
        func_00201800();
        STAGE1_MIDBOSS(reg_a5)->dying -= 1;
        temp_a0 = STAGE1_MIDBOSS(reg_a5)->dying;
        if (temp_a0 != 0) {
            if (temp_a0 >= 0x48) goto block_tail;
            if (temp_a0 == 48) {
            g_enemy_signal_0 = 0;
            reg_d0.h[0] = 0x20;
            reg_d1.h[0] = 0x20;
            ground_speeds_request();
                return;
            }
        } else {
            enemy_remove();
        }
        return;
    } else {
        if (g_scroll_line == 0xD8) {
            STAGE1_MIDBOSS(reg_a5)->fight = 1U;
        }
        if (g_scroll_line == 0xF8) {
            STAGE1_MIDBOSS(reg_a5)->fight = 0xFFU;
        }
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
        if (reg_d1.b[0] != 0) {
            reg_d0.b[0] = 0xA3;
            ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
            score_add_no_chain();
            reg_d0.b[0] = MIDBOSS_BODY(reg_a6)->attr.b[0];
            reg_d2.b[0] = MIDBOSS_BODY(reg_a6)->hit_flash;
            reg_d0.b[0] ^= reg_d2.b[0];
            MIDBOSS_BODY(reg_a6)->attr.b[0] = (u8) reg_d0.b[0];
            if (STAGE1_MIDBOSS(reg_a5)->fight == 0) {
                ENTITY(reg_a6)->hp.h = 0x3500U;
            }
            if (MIDBOSS_BODY(reg_a6)->core_frame == 0) {
                ENTITY(reg_a6)->hp.h = (u16) STAGE1_MIDBOSS(reg_a5)->hp;
                if ((s8) STAGE1_MIDBOSS(reg_a5)->fight < 0) {
                    ENTITY(reg_a6)->hp.h = 0x7FFFU;
                }
                goto block_18;
            }
            if ((s16) ENTITY(reg_a6)->hp.h < 0) {
                g_enemy_signal_1 = 1;
                reg_d0.w = ENEMY_STAGE1_MIDBOSS_WRECK;
                spawn_request_add();
                STAGE1_MIDBOSS(reg_a5)->wreck_value = (u16) reg_d1.h[0];
                reg_d0.w = 0x353;
                score_add();
                stage1_midboss_blow_up();
                vibration_start_pad1(0xB4, 0x50);
                vibration_start_pad2(0xB4, 0x50);
                g_slowdown_timer = MAIN_OR_DEATH_LABEL(0x54, 0x5A);
                reg_a0 = (u8 *) stage1_midboss_fade_script;
                fade_in_and_release();
                reg_d1.h[0] = STAGE1_MIDBOSS(reg_a5)->wreck_value;
                func_00201800();
                ENTITY(reg_a6)->flags.h = 0x8080;
                goto block_18;
            }
        } else {
block_18:
            MIDBOSS_BODY(reg_a6)->attr.b[0] = (u8) MIDBOSS_BODY(reg_a6)->normal_palette;
        }
        STAGE1_MIDBOSS(reg_a5)->hp = (u16) ENTITY(reg_a6)->hp.h;
        reg_d7.w = 7;
        reg_a4 = reg_a6 + 0x20;
        do {
            var_a0 = (u8 *)(reg_a4);
            reg_d0.h[0] = MIDBOSS_ARM(var_a0)->flags.h;
            if (reg_d0.h[0] != 0x8000) {
                if (MIDBOSS_ARM(var_a0)->blow_up == 0) {
                    reg_d1.w = 0x5C;
                    reg_d1.b[0] &= MIDBOSS_ARM(var_a0)->flags.b[1];
                    if (reg_d1.b[0] != 0) {
                        reg_d0.b[0] = 0xA3;
                        MIDBOSS_ARM(var_a0)->flags.b[1] &= reg_d0.b[0];
                        score_add_no_chain();
                        var_a0 = (u8 *)(reg_a4);
                        reg_d0.b[0] = MIDBOSS_ARM(var_a0)->attr.b[0];
                        reg_d2.b[0] = MIDBOSS_ARM(var_a0)->hit_flash;
                        reg_d0.b[0] ^= reg_d2.b[0];
                        MIDBOSS_ARM(var_a0)->attr.b[0] = (u8) reg_d0.b[0];
                        if (STAGE1_MIDBOSS(reg_a5)->fight == 0) {
                            MIDBOSS_ARM(reg_a4)->hp.sh = 0x400;
                        }
                        if (MIDBOSS_ARM(reg_a4)->hp.sh < 0) {
                            reg_d0.w = 0x26;
                            score_add();
block_27:
                            sfx_explosion_air_small();
                            reg_d0.h[0] = 0x85;
                            explosion_spawn();
                            var_a0 = (u8 *)((void *)1);
                            EXPLOSION(reg_a0)->y = (u16) MIDBOSS_ARM(reg_a4)->y.h;
                            EXPLOSION(reg_a0)->x = (u16) MIDBOSS_ARM(reg_a4)->x.h;
                            EXPLOSION(reg_a0)->follows_scroll = 2;
                            EXPLOSION(reg_a0)->draw_layer = 0xC;
                            EXPLOSION(reg_a0)->debris = 1;
                            EXPLOSION(reg_a0)->debris_arg = 0;
                            MIDBOSS_ARM(reg_a4)->flags.h = 0x8000U;
                        }
                    } else {
                        MIDBOSS_ARM(var_a0)->attr.b[0] = (u8) MIDBOSS_ARM(var_a0)->normal_palette;
                    }
                } else {
                    goto block_27;
                }
            }
            reg_a4 += 0x40;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        if (STAGE1_MIDBOSS(reg_a5)->arrived == 0) {
            if (ENTITY(reg_a6)->y.sh >= 0) {
                STAGE1_MIDBOSS(reg_a5)->arrived = 1U;
            }
            goto block_35;
        }
        if (ENTITY(reg_a6)->y.sh < -0x23FF) {
            g_enemy_signal_0 = 0;
            enemy_remove();
            return;
        }
block_35:
        func_001368E0();
        if (g_enemies_stopped == 0) {
            entity_follow_scroll();
            stage1_midboss_move_arms();
            reg_tmp.b[0] = STAGE1_MIDBOSS(reg_a5)->body_timer.b.countdown;
            STAGE1_MIDBOSS(reg_a5)->body_timer.b.countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                STAGE1_MIDBOSS(reg_a5)->body_timer.b.countdown = (u8) STAGE1_MIDBOSS(reg_a5)->body_timer.b.interval;
                STAGE1_MIDBOSS(reg_a5)->body_frame += 4;
                if ((s16) STAGE1_MIDBOSS(reg_a5)->body_frame >= 0x14) {
                    STAGE1_MIDBOSS(reg_a5)->body_frame = 0U;
                }
            }
            temp_v0_2 = MIDBOSS_BODY(reg_a6)->core_phase;
            if (temp_v0_2 == 0) {
                if ((s8) STAGE1_MIDBOSS(reg_a5)->fight > 0) {
                    reg_tmp.b[0] = MIDBOSS_BODY(reg_a6)->open_wait.b.countdown;
                    MIDBOSS_BODY(reg_a6)->open_wait.b.countdown -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        MIDBOSS_BODY(reg_a6)->open_wait.b.countdown = (u8) MIDBOSS_BODY(reg_a6)->open_wait.b.interval;
                        MIDBOSS_BODY(reg_a6)->core_phase = 1U;
                        MIDBOSS_BODY(reg_a6)->core_timer.both = 2;
#ifndef DEATH_LABEL
                        MIDBOSS_BODY(reg_a6)->core_timer.b.countdown = 0U;
                        MIDBOSS_BODY(reg_a6)->core_timer.b.interval = 2;
#endif
                    }
                }
            } else if ((temp_v0_2 & 0xFF) == 1) {
                if ((MIDBOSS_BODY(reg_a6)->core_frame != 0) || (STAGE1_MIDBOSS(reg_a5)->arms_busy == 0)) {
                    reg_tmp.b[0] = MIDBOSS_BODY(reg_a6)->core_timer.b.countdown;
                    MIDBOSS_BODY(reg_a6)->core_timer.b.countdown -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        MIDBOSS_BODY(reg_a6)->core_timer.b.countdown = MIDBOSS_BODY(reg_a6)->core_timer.b.interval;
                        MIDBOSS_BODY(reg_a6)->core_frame += 4;
                        if (MIDBOSS_BODY(reg_a6)->core_frame == 0x7C) {
                            MIDBOSS_BODY(reg_a6)->core_phase = 2U;
                            MIDBOSS_BODY(reg_a6)->volleys_left = 2U;
                            MIDBOSS_BODY(reg_a6)->volley_timer.both = 2;
                        }
                        goto block_50;
                    }
                }
            } else {
block_50:
                if (MIDBOSS_BODY(reg_a6)->core_phase == 2) {
                    reg_tmp.b[0] = MIDBOSS_BODY(reg_a6)->volley_timer.b.countdown;
                    MIDBOSS_BODY(reg_a6)->volley_timer.b.countdown -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        MIDBOSS_BODY(reg_a6)->volley_timer.b.countdown = MIDBOSS_BODY(reg_a6)->volley_timer.b.interval;
                        temp_v1 = ENTITY(reg_a6)->y.h;
                        if ((s32) temp_v1 >= 0x1000) {
                            reg_d0.h[0] = temp_v1;
                            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d0.h[0] += 0x2700;
                            aim256_at_player();
                            if (cond_flag == 0) {
                                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                                reg_d4.w = 0;
                                reg_d6.h[0] = reg_d1.h[0];
                                if (MIDBOSS_BODY(reg_a6)->volleys_left & 1) {
                                    reg_d0.w = 0x30003;
                                    reg_d1.h[0] -= 0xC;
                                    reg_d3.w = 0x27000000;
                                    reg_d7.w = 6;
                                    do {
                                        bullet_fire256();
                                        reg_d1.h[0] += 4;
                                    } while ((s16)(--reg_d7.h[0]) >= 0);
                                }
                                reg_d1.h[0] = reg_d6.h[0];
                                reg_a0 = g_direction64_offsets_432;
                                reg_d1.h[0] -= 0x56;
                                stage1_midboss_fan_singles();
                                stage1_midboss_fan_pairs();
                                stage1_midboss_fan_singles();
                                stage1_midboss_fan_pairs();
                                stage1_midboss_fan_singles();
                                stage1_midboss_fan_pairs();
                                stage1_midboss_fan_singles();
                                stage1_midboss_fan_pairs();
                                stage1_midboss_fan_singles();
                                stage1_midboss_fan_pairs();
                                stage1_midboss_fan_singles();
                            }
                        }
                        MIDBOSS_BODY(reg_a6)->volleys_left -= 1;
                        if (MIDBOSS_BODY(reg_a6)->volleys_left == 0) {
                            MIDBOSS_BODY(reg_a6)->core_phase = 3U;
                            MIDBOSS_BODY(reg_a6)->core_timer.both = 0x1001;
#ifndef DEATH_LABEL
                            MIDBOSS_BODY(reg_a6)->core_timer.b.countdown = 0x10U;
                            MIDBOSS_BODY(reg_a6)->core_timer.b.interval = 1;
#endif
                            goto block_60;
                        }
                    }
                } else {
block_60:
                    if (MIDBOSS_BODY(reg_a6)->core_phase == 3) {
                        reg_tmp.b[0] = MIDBOSS_BODY(reg_a6)->core_timer.b.countdown;
                        MIDBOSS_BODY(reg_a6)->core_timer.b.countdown -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            MIDBOSS_BODY(reg_a6)->core_timer.b.countdown = MIDBOSS_BODY(reg_a6)->core_timer.b.interval;
                            MIDBOSS_BODY(reg_a6)->core_frame -= 4;
                            if (MIDBOSS_BODY(reg_a6)->core_frame == 0) {
                                MIDBOSS_BODY(reg_a6)->core_phase = 0U;
                            }
                        }
                    }
                }
            }
            if ((s8) STAGE1_MIDBOSS(reg_a5)->fight > 0) {
                STAGE1_MIDBOSS(reg_a5)->arm_turn += 1;
                STAGE1_MIDBOSS(reg_a5)->arm_turn &= 7;
                reg_d7.w = 7;
                reg_a4 = reg_a6 + 0x20;
                do {
                    if (MIDBOSS_ARM(reg_a4)->flags.h != 0x8000) {
                        temp_v0_5 = MIDBOSS_ARM(reg_a4)->phase;
                        if (temp_v0_5 == 0) {
                            if (MIDBOSS_ARM(reg_a4)->burst_shots_left == 0) {
                                reg_tmp.b[0] = MIDBOSS_ARM(reg_a4)->burst_pause.b.countdown;
                                MIDBOSS_ARM(reg_a4)->burst_pause.b.countdown -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    MIDBOSS_ARM(reg_a4)->burst_pause.b.countdown = (u8) MIDBOSS_ARM(reg_a4)->burst_pause.b.interval;
                                    MIDBOSS_ARM(reg_a4)->burst_shots_left = (u8) MIDBOSS_ARM(reg_a4)->burst_shots;
                                    goto block_71;
                                }
                            } else {
block_71:
                                reg_tmp.b[0] = MIDBOSS_ARM(reg_a4)->shot.b.countdown;
                                MIDBOSS_ARM(reg_a4)->shot.b.countdown -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    MIDBOSS_ARM(reg_a4)->shot.b.countdown = (u8) MIDBOSS_ARM(reg_a4)->shot.b.interval;
                                    reg_d0.b[0] = STAGE1_MIDBOSS(reg_a5)->arm_turn;
                                    reg_d1.h[0] = reg_d7.h[0];
                                    reg_d1.h[0] &= 3;
                                    reg_d0.h[0] &= 3;
                                    if (reg_d0.h[0] == reg_d1.h[0]) {
                                        reg_d0.h[0] = MIDBOSS_ARM(reg_a4)->y.h;
                                        reg_d1.h[0] = MIDBOSS_ARM(reg_a4)->x.h;
                                        reg_d1.b[0] = MIDBOSS_ARM(reg_a4)->angle;
#ifdef DEATH_LABEL
                                        if (((reg_d1.sb[0] < -0x20) || (0 < reg_d1.sb[0])) && ((reg_d1.sb[0] > 0x20) || (0 > reg_d1.sb[0]))) {
#else
                                        if (((s32) reg_d1.b[0] < 0xE1) && ((s32) reg_d1.b[0] > 0x20)) {
#endif
                                            reg_d3.w = 0x02000000;
                                            reg_d2.h[1] = MIDBOSS_ARM(reg_a4)->y.h;
                                            reg_d2.h[0] = MIDBOSS_ARM(reg_a4)->x.h;
                                            reg_d0.w = 0xFFFE0007;
                                            bullet_fire256_3way();
                                            MIDBOSS_ARM(reg_a4)->burst_shots_left -= 1;
                                        }
                                    }
                                }
                            }
                        } else if ((temp_v0_5 & 0xFF) == 1) {
                            if (MIDBOSS_BODY(reg_a6)->core_frame == 0) {
                                reg_tmp.b[0] = MIDBOSS_ARM(reg_a4)->hatch_timer.b.countdown;
                                MIDBOSS_ARM(reg_a4)->hatch_timer.b.countdown -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    MIDBOSS_ARM(reg_a4)->hatch_timer.b.countdown = (u8) MIDBOSS_ARM(reg_a4)->hatch_timer.b.interval;
                                    MIDBOSS_ARM(reg_a4)->hatch_frame += 4;
                                    if (MIDBOSS_ARM(reg_a4)->hatch_frame == 0x1C) {
                                        MIDBOSS_ARM(reg_a4)->phase = 2U;
                                        MIDBOSS_ARM(reg_a4)->sweep_shot.both = 1;
                                        MIDBOSS_ARM(reg_a4)->sweep_shots_left = 8U;
                                        goto block_81;
                                    }
                                }
                            }
                        } else {
block_81:
                            if (MIDBOSS_ARM(reg_a4)->phase == 2) {
                                reg_tmp.b[0] = MIDBOSS_ARM(reg_a4)->sweep_shot.b.countdown;
                                MIDBOSS_ARM(reg_a4)->sweep_shot.b.countdown -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    MIDBOSS_ARM(reg_a4)->sweep_shot.b.countdown = MIDBOSS_ARM(reg_a4)->sweep_shot.b.interval;
                                    reg_tmp.b[0] = MIDBOSS_ARM(reg_a4)->angle;
#ifdef DEATH_LABEL
                                    if (((reg_tmp.sb[0] < -0x18) || (0 < reg_tmp.sb[0])) && ((reg_tmp.sb[0] > 0x18) || (0 > reg_tmp.sb[0]))) {
#else
                                    if (((s32) reg_tmp.b[0] < 0xE9) && ((s32) reg_tmp.b[0] > 0x18)) {
#endif
                                        reg_d1.b[0] = MIDBOSS_ARM(reg_a4)->sweep_shots_left;
                                        reg_d1.b[0] *= 4;
                                        temp_a0_2 = MIDBOSS_ARM(reg_a4)->angle;
                                        temp_a1 = reg_d1.b[0];
                                        reg_d1.b[0] = temp_a1 + temp_a0_2;
                                        reg_d3.w = 0x02000000;
                                        reg_d2.h[1] = MIDBOSS_ARM(reg_a4)->y.h;
                                        reg_d2.h[0] = MIDBOSS_ARM(reg_a4)->x.h;
                                        reg_d0.w = 0x20007;
                                        bullet_fire256_3way();
                                        MIDBOSS_ARM(reg_a4)->unread_28 += 2;
                                    }
                                    MIDBOSS_ARM(reg_a4)->sweep_shots_left -= 1;
                                    if (MIDBOSS_ARM(reg_a4)->sweep_shots_left == 0) {
                                        MIDBOSS_ARM(reg_a4)->phase = 3U;
                                        MIDBOSS_ARM(reg_a4)->hatch_timer.b.countdown = 0x20U;
                                        goto block_88;
                                    }
                                }
                            } else {
block_88:
                                if (MIDBOSS_ARM(reg_a4)->phase == 3) {
                                    reg_tmp.b[0] = MIDBOSS_ARM(reg_a4)->hatch_timer.b.countdown;
                                    MIDBOSS_ARM(reg_a4)->hatch_timer.b.countdown -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        MIDBOSS_ARM(reg_a4)->hatch_timer.b.countdown = (u8) MIDBOSS_ARM(reg_a4)->hatch_timer.b.interval;
                                        MIDBOSS_ARM(reg_a4)->hatch_frame -= 4;
                                        if (MIDBOSS_ARM(reg_a4)->hatch_frame == 0) {
                                            MIDBOSS_ARM(reg_a4)->phase = 0U;
                                            MIDBOSS_ARM(reg_a4)->hatch_timer.b.countdown = 0x10U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    reg_a4 += 0x40;
                } while ((s16)(--reg_d7.h[0]) >= 0);
                reg_d6.w = 0;
                reg_d7.w = 7;
                reg_a4 = reg_a6 + 0x20;
                do {
                    if ((MIDBOSS_ARM(reg_a4)->flags.h != 0x8000) && (MIDBOSS_ARM(reg_a4)->phase != 0)) {
                        reg_d6.w = 1;
                    }
                    reg_a4 += 0x40;
                } while ((s16)(--reg_d7.h[0]) >= 0);
                if (reg_d6.h[0] == 0) {
                    STAGE1_MIDBOSS(reg_a5)->arms_busy = 0U;
                }
            }
        }
block_tail:
        stage1_midboss_draw_body();
        if (STAGE1_MIDBOSS(reg_a5)->dying == 0) {
            stage1_midboss_draw_arms();
            stage1_midboss_draw_core();
        }
        reg_a0 = reg_a6;
        enemy_hitbox_debug_draw();
        reg_a0 = reg_a6 + 0x20;
        enemy_hitbox_debug_draw();
        reg_a0 = reg_a6 + 0x40;
        enemy_hitbox_debug_draw();
        reg_a0 = reg_a6 + 0x60;
        enemy_hitbox_debug_draw();
        reg_a0 = reg_a6 + 0x80;
        enemy_hitbox_debug_draw();
        reg_a0 = reg_a6 + 0xA0;
        enemy_hitbox_debug_draw();
        reg_a0 = reg_a6 + 0xC0;
        enemy_hitbox_debug_draw();
        reg_a0 = reg_a6 + 0xE0;
        enemy_hitbox_debug_draw();
        reg_a0 = reg_a6 + 0x100;
        enemy_hitbox_debug_draw();
        reg_a0 = reg_a6 + 0x120;
        enemy_hitbox_debug_draw();
        reg_a0 = reg_a6 + 0x140;
        enemy_hitbox_debug_draw();
        reg_a0 = reg_a6 + 0x160;
        enemy_hitbox_debug_draw();
        reg_a0 = reg_a6 + 0x180;
        enemy_hitbox_debug_draw();
        reg_a0 = reg_a6 + 0x1A0;
        enemy_hitbox_debug_draw();
        reg_a0 = reg_a6 + 0x1C0;
        enemy_hitbox_debug_draw();
        reg_a0 = reg_a6 + 0x1E0;
        enemy_hitbox_debug_draw();
    }
}

s32 sprite_draw_layer4_keep();

void stage1_midboss_draw_arms(void) {
    u16 temp_a0;
    u16 temp_a1;
    reg_a0 = reg_a6 + 0x20;
    reg_d7.w = 7;
    do {
        reg_d0.h[0] = MIDBOSS_ARM(reg_a0)->flags.h;
        if (reg_d0.h[0] != 0x8000) {
            reg_a1 = (u8 *)stage1_midboss_arm_frames;
            reg_a1 += MIDBOSS_ARM(reg_a0)->spin_frame;
            reg_d2.h[1] = *(u16 *)reg_a1;
            reg_d2.h[0] = *(u16 *)(reg_a1 + 2);
            reg_d1.h[1] = MIDBOSS_ARM(reg_a0)->y.h;
            temp_a0 = MIDBOSS_ARM(reg_a0)->x.h;
            reg_d1.h[0] = temp_a0;
            reg_d1.w += 0xFA00FC00;
            reg_d3.h[0] = 0x620;
            reg_d4.h[0] = MIDBOSS_ARM(reg_a0)->attr.h;
            sprite_draw_layer4_keep();
            reg_a1 = (u8 *)stage1_midboss_hatch_frames;
            reg_d2.h[0] = MIDBOSS_ARM(reg_a0)->hatch_frame;
            reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a1;
            reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
            reg_d1.h[1] = MIDBOSS_ARM(reg_a0)->y.h;
            temp_a1 = MIDBOSS_ARM(reg_a0)->x.h;
            reg_d1.h[0] = temp_a1;
            reg_d1.w += 0xFC00FC00;
            reg_d3.h[0] = 0x420;
            reg_d4.h[0] = MIDBOSS_ARM(reg_a0)->attr.h;
            sprite_draw_layer4_keep();
        }
        reg_a0 += 0x40;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

void sprite_draw_layer4(void);

void stage1_midboss_draw_core(void) {
    reg_a0 = (u8 *)stage1_midboss_core_frames;
    reg_d2.h[0] = MIDBOSS_BODY(reg_a6)->core_frame;
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[1] += 0x1600;
    reg_d1.h[0] += 0x7FFF + 0x7401;
    reg_d1.h[1] += 0x7FFF + 0x6601;
    reg_d3.h[0] = 0x1A60;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    sprite_draw_layer4();
}

extern void sprite_draw_layer4(void);

void stage1_midboss_draw_body(void) {
    reg_a0 = (u8 *)stage1_midboss_body_frames;
    reg_a0 += STAGE1_MIDBOSS(reg_a5)->body_frame;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xDC00E600U;
    reg_d3.h[0] = 0x24D0;
    reg_d4.h[0] = 0x11;
    sprite_draw_layer4();
}

void stage1_midboss_wreck_first(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(0);
}

s32 enemy_set_task_state();                            /* extern */
s32 enemy_init_entities();                            /* extern */

void stage1_midboss_wreck_start(void) {
    reg_a0 = (u8 *)stage1_midboss_wreck_entities;
    enemy_init_entities();
    reg_d0.w = 0;
    reg_a0 = (u8 *) stage1_midboss_wreck_state_init;
    enemy_set_task_state();
    reg_tmp.w = 0x38001C00;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
}

extern u32 D_00251720[];
extern u16 g_attract_demo;
extern u8 g_replay_mode;
extern u8 g_simulation_active;
extern u32 g_bg_layer_as_u32_a[];
extern u32 D_002B6DF4[];
extern u32 D_002B6E0C[];

void stage1_midboss_wreck(void) {
    s32 flag;
    u32 *dst;
    u32 *src;
    u32 cnt;
    u32 cnt2;

    if (g_scroll_line == 0x105) {
        enemy_remove();
        return;
    }
    src = D_00251720;
    reg_a0 = (u8 *)(D_002B6E0C);
    reg_tmp.w = 0xBC;
    flag = g_simulation_active == 1;
    if (flag == 0) {
        flag = g_replay_mode == 2;
    }
    if ((flag != 0) || (g_attract_demo != 0)) {
        reg_a0 = (u8 *)(D_002B6DF4);
        reg_tmp.w = 0xA4;
    }
    reg_d6.w = 0x16;
loop_1:
    dst = (u32 *)(reg_a0);
    reg_d7.w = 8;
loop_2:
    reg_d4.w = *src;
    src += 1;
    reg_d4.h[1] += 0x800;
    *dst = reg_d4.w;
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    dst += 64;
    if (((s64) ((s64) (u16) cnt << 0x30) >> 0x30) >= 0) {
        goto loop_2;
    }
    (*(u8 **)&reg_tmp1) = (u8 *)g_bg_layer_as_u32_a;
    reg_tmp.w += 4;
    reg_tmp.w = (u32) reg_tmp.b[0];
    (*(u8 **)&reg_tmp1) += reg_tmp.w;
    reg_a0 = (u8 *)((*(u8 **)&reg_tmp1));
    cnt2 = reg_d6.h[0] - 1;
    reg_d6.h[0] = cnt2;
    if (((s64) ((s64) (u16) cnt2 << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
}

u16 stage1_midboss_explosions[64] = {
    0x0001, 0x000D, 0x0800, 0x0000, 0x0005, 0x0009, 0x0A00, 0x0C00,
    0x0009, 0x0005, 0x0800, 0x0800, 0x000D, 0x000C, 0x0200, 0x1400,
    0x0011, 0x000C, 0xF800, 0x1200, 0x0015, 0x0005, 0xEC00, 0x0E00,
    0x0019, 0x000C, 0xEA00, 0x0400, 0x000E, 0x000D, 0xFA00, 0x0200,
    0x0003, 0x000C, 0x1000, 0xF000, 0x0007, 0x0007, 0x0C00, 0xF800,
    0x000B, 0x0007, 0x0600, 0xEC00, 0x000F, 0x0005, 0xFC00, 0xF000,
    0x0013, 0x000C, 0xEE00, 0xF000, 0x0011, 0x0009, 0xE800, 0xFC00,
    0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 stage1_midboss_state_init[16] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0002, 0x0000, 0x0101, 0x0000,
    0x3500, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 stage1_midboss_entities[248] = {
    0xA000, 0x1001, 0x0000, 0x0001, 0x0000, 0x0000, 0x1E00, 0xFC00,
    0x0980, 0x0980, 0x3500, 0x0800, 0x0000, 0x100F, 0xA000, 0x1020,
    0x0000, 0x0000, 0x1003, 0x0000, 0x0800, 0x0400, 0x0300, 0x0300,
    0x0400, 0x0000, 0x0000, 0x0F10, 0x8000, 0x0000, 0x0000, 0x0005,
    0x0000, 0x0101, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0xA000, 0x1020, 0x0000, 0x0000, 0x1003, 0x0000,
    0x0800, 0x0400, 0x0300, 0x0300, 0x0400, 0x0000, 0x0000, 0x0F10,
    0x8000, 0x0000, 0x0000, 0x0005, 0x0000, 0x0101, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xA000, 0x1020,
    0x0000, 0x0000, 0x1003, 0x0000, 0x0800, 0x0400, 0x0300, 0x0300,
    0x0400, 0x0000, 0x0000, 0x0F10, 0x8000, 0x0000, 0x0000, 0x0005,
    0x0000, 0x0101, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0xA000, 0x1020, 0x0000, 0x0000, 0x1003, 0x0000,
    0x0800, 0x0400, 0x0300, 0x0300, 0x0400, 0x0000, 0x0000, 0x0F10,
    0x8000, 0x0000, 0x0000, 0x0005, 0x0000, 0x0101, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xA000, 0x1020,
    0x0000, 0x0000, 0x1003, 0x0000, 0x0800, 0x0400, 0x0300, 0x0300,
    0x0400, 0x0000, 0x0000, 0x0F10, 0x8000, 0x0000, 0x0000, 0x0005,
    0x0000, 0x0101, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0xA000, 0x1020, 0x0000, 0x0000, 0x1003, 0x0000,
    0x0800, 0x0400, 0x0300, 0x0300, 0x0400, 0x0000, 0x0000, 0x0F10,
    0x8000, 0x0000, 0x0000, 0x0005, 0x0000, 0x0101, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xA000, 0x1020,
    0x0000, 0x0000, 0x1003, 0x0000, 0x0800, 0x0400, 0x0300, 0x0300,
    0x0400, 0x0000, 0x0000, 0x0F10, 0x8000, 0x0000, 0x0000, 0x0005,
    0x0000, 0x0101, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0xA000, 0x1020, 0x0000, 0x0000, 0x1003, 0x0000,
    0x0800, 0x0400, 0x0300, 0x0300, 0x0400, 0x0000, 0x0000, 0x0F10,
    0x8000, 0x0000, 0x0000, 0x0005, 0x0000, 0x0101, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2E60, 0x0000,
    0x0000, 0x0010, 0xFFBF, 0x00F3, 0x00F4, 0xFFFF, 0x0000, 0x0000,
};

u16 stage1_midboss_hatch_frames[16] = {
    0x0000, 0x1AB8, 0x0000, 0x1AB9, 0x0000, 0x1ABA, 0x0000, 0x1ABB,
    0x0000, 0x1ABC, 0x0000, 0x1ABD, 0x0000, 0x1ABE, 0x0000, 0x1ABF,
};

u16 stage1_midboss_arm_frames[64] = {
    0x0000, 0x1A98, 0x0000, 0x1A99, 0x0000, 0x1A9A, 0x0000, 0x1A9B,
    0x0000, 0x1A9C, 0x0000, 0x1A9D, 0x0000, 0x1A9E, 0x0000, 0x1A9F,
    0x0000, 0x1AA0, 0x0000, 0x1AA1, 0x0000, 0x1AA2, 0x0000, 0x1AA3,
    0x0000, 0x1AA4, 0x0000, 0x1AA5, 0x0000, 0x1AA6, 0x0000, 0x1AA7,
    0x0000, 0x1AA8, 0x0000, 0x1AA9, 0x0000, 0x1AAA, 0x0000, 0x1AAB,
    0x0000, 0x1AAC, 0x0000, 0x1AAD, 0x0000, 0x1AAE, 0x0000, 0x1AAF,
    0x0000, 0x1AB0, 0x0000, 0x1AB1, 0x0000, 0x1AB2, 0x0000, 0x1AB3,
    0x0000, 0x1AB4, 0x0000, 0x1AB5, 0x0000, 0x1AB6, 0x0000, 0x1AB7,
};

u16 stage1_midboss_core_frames[64] = {
    0x0000, 0x1A73, 0x0000, 0x1A74, 0x0000, 0x1A75, 0x0000, 0x1A76,
    0x0000, 0x1A77, 0x0000, 0x1A78, 0x0000, 0x1A79, 0x0000, 0x1A7A,
    0x0000, 0x1A7B, 0x0000, 0x1A7C, 0x0000, 0x1A7D, 0x0000, 0x1A7E,
    0x0000, 0x1A7F, 0x0000, 0x1A80, 0x0000, 0x1A81, 0x0000, 0x1A82,
    0x0000, 0x1A83, 0x0000, 0x1A84, 0x0000, 0x1A85, 0x0000, 0x1A86,
    0x0000, 0x1A87, 0x0000, 0x1A88, 0x0000, 0x1A89, 0x0000, 0x1A8A,
    0x0000, 0x1A8B, 0x0000, 0x1A8C, 0x0000, 0x1A8D, 0x0000, 0x1A8E,
    0x0000, 0x1A8F, 0x0000, 0x1A90, 0x0000, 0x1A91, 0x0000, 0x1A92,
};

u16 stage1_midboss_body_frames[16] = {
    0x0000, 0x1A93, 0x0000, 0x1A94, 0x0000, 0x1A95, 0x0000, 0x1A96,
    0x0000, 0x1A97, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 stage1_midboss_direction64_offsets_166[128] = {
    0x0166, 0x0000, 0x0162, 0x0016, 0x015C, 0x002C, 0x0154, 0x0044,
    0x014A, 0x0058, 0x0138, 0x0070, 0x0128, 0x0084, 0x0112, 0x0096,
    0x00FA, 0x00A8, 0x00E2, 0x00B6, 0x00C6, 0x00C4, 0x00A6, 0x00D0,
    0x0086, 0x00DC, 0x0066, 0x00E2, 0x0042, 0x00E8, 0x0020, 0x00EC,
    0x0000, 0x00EE, 0xFFE0, 0x00EC, 0xFFBE, 0x00E8, 0xFF9A, 0x00E2,
    0xFF7A, 0x00DC, 0xFF5A, 0x00D0, 0xFF3A, 0x00C4, 0xFF1E, 0x00B6,
    0xFF06, 0x00A8, 0xFEEE, 0x0096, 0xFED8, 0x0084, 0xFEC8, 0x0070,
    0xFEB6, 0x0058, 0xFEAC, 0x0044, 0xFEA4, 0x002C, 0xFE9E, 0x0016,
    0xFE9A, 0x0000, 0xFE9E, 0xFFEA, 0xFEA4, 0xFFD4, 0xFEAC, 0xFFBC,
    0xFEB6, 0xFFA8, 0xFEC8, 0xFF90, 0xFED8, 0xFF7C, 0xFEEE, 0xFF6A,
    0xFF06, 0xFF58, 0xFF1E, 0xFF4A, 0xFF3A, 0xFF3C, 0xFF5A, 0xFF30,
    0xFF7A, 0xFF24, 0xFF9A, 0xFF1E, 0xFFBE, 0xFF18, 0xFFE0, 0xFF14,
    0x0000, 0xFF12, 0x0020, 0xFF14, 0x0042, 0xFF18, 0x0066, 0xFF1E,
    0x0086, 0xFF24, 0x00A6, 0xFF30, 0x00C6, 0xFF3C, 0x00E2, 0xFF4A,
    0x00FA, 0xFF58, 0x0112, 0xFF6A, 0x0128, 0xFF7C, 0x0138, 0xFF90,
    0x014A, 0xFFA8, 0x0154, 0xFFBC, 0x015C, 0xFFD4, 0x0162, 0xFFEA,
};

u16 stage1_midboss_fade_script[104] = {
    0x000E, 0x7FFF, 0x0000, 0x0780, 0x0004, 0x0005, 0x001F, 0x0004,
    0x7FFF, 0x0000, 0x0400, 0x000B, 0x000C, 0x001F, 0x0005, 0x7FFF,
    0x0000, 0x0440, 0x0012, 0x0013, 0x001F, 0x0005, 0x7FFF, 0x0000,
    0x03C0, 0x0019, 0x001A, 0x001F, 0x0005, 0x7FFF, 0x0000, 0x04C0,
    0x0020, 0x0021, 0x001F, 0x0005, 0x7FFF, 0x0000, 0x0500, 0x0027,
    0x0028, 0x001F, 0x0005, 0x7FFF, 0x0000, 0x0580, 0x002E, 0x002F,
    0x001F, 0x0005, 0x7FFF, 0x0000, 0x05C0, 0x0035, 0x0036, 0x001F,
    0x0005, 0x7FFF, 0x0008, 0x0140, 0x003C, 0x003D, 0x001F, 0x0005,
    0x7FFF, 0x0008, 0x0180, 0x0043, 0x0044, 0x001F, 0x0005, 0x7FFF,
    0x0008, 0x01C0, 0x004A, 0x004B, 0x001F, 0x0005, 0x7FFF, 0x0008,
    0x0540, 0x0051, 0x0052, 0x001F, 0x0005, 0x7FFF, 0x0008, 0x0580,
    0x0058, 0x0059, 0x001F, 0x0005, 0x7FFF, 0x0008, 0x05C0, 0x005F,
    0x0060, 0x001F, 0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 stage1_midboss_wreck_entities[16] = {
    0x8000, 0xFC00, 0xFD00, 0x0000, 0x02D3, 0x0418, 0x1B80, 0xFC00,
    0x0A00, 0x0A00, 0x7FFF, 0x1000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 stage1_midboss_wreck_state_init[2] = {
    0x0000, 0x0000,
};
