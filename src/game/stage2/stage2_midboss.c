#include "common.h"
#include "entity.h"
#include "explosion.h"
#include "stage2_boss.h"
#include "enemy.h"


/* The stage 2 mid-boss, kind 0x8C. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u8 unused_16;
    /* 0x17 */ u8 seen;
    /* 0x18 */ u16 attack;            /* 0: hatch volleys, 1: side guns, 2: spreads */
    /* 0x1A */ u16 hatch_phase;       /* 0: waiting, 1: opening, 2: firing, 3: closing */
    /* 0x1C */ u8 hit_flash;
    /* 0x1D */ u8 palette;
    /* 0x1E */ u8 unused_1E;
    /* 0x1F */ u8 hatch_wait;
    /* 0x20 */ u8 hatch_volleys;
    /* 0x21 */ u8 hatch_volleys_left;
    /* 0x22 */ u8 side_pause;
    /* 0x23 */ u8 side_wait;
    /* 0x24 */ u8 side_shots;
    /* 0x25 */ u8 side_shots_left;
    /* 0x26 */ u16 unused_26;
    /* 0x28 */ struct {
        u16 sprite[2];                /* high word first */
        Field16 dir;
    } gun[2];
    /* 0x34 */ u8 side_interval;
    /* 0x35 */ u8 hatch_delay;
    /* 0x36 */ u8 spread_pause;
    /* 0x37 */ u8 spread_wait;
    /* 0x38 */ Field16 spread_step;
    /* 0x3A */ u16 hatch_speed;
    /* 0x3C */ u8 side_angle;
    /* 0x3D */ u8 spread_interval;
    /* 0x3E */ u16 spread_speed;
    /* 0x40 */ u16 unused_40[2];
    /* 0x44 */ u16 after_entities[2];
} Stage2MidbossState;

#define STAGE2_MIDBOSS(pointer) ((Stage2MidbossState *)(pointer))

extern u16 g_enemies_stopped;
void enemy_set_entity_count(s32);

void stage2_midboss_first(void) {
    enemy_set_entity_count(2);
}


s32 fade_in_and_release();
s32 enemy_set_task_state();
s32 enemy_init_entities();
s32 enemy_path_start();
s32 sfx_heli_start();
s32 aim256_at_player();
extern u16 g_direction_sprites_c[];
extern u8 stage2_midboss_start_table[];
extern u8 D_00263030[];
extern u8 D_002630D0[];
extern u16 g_enemy_signal_0;
extern u16 g_loop;
extern u16 g_stage;
extern s16 g_bullet_limit_raised_1[];
extern s16 g_bullet_limit_raised_2[];
extern s8 enemy_move_end_requested;

void stage2_midboss_start(void) {
    reg_a0 = D_00263030;
    enemy_init_entities();
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a0);
    STAGE2_MIDBOSS(reg_a5)->after_entities[0] = (u16) reg_tmp.h[1];
    STAGE2_MIDBOSS(reg_a5)->after_entities[1] = (u16) reg_tmp.h[0];
    reg_a0 = stage2_midboss_start_table;
    reg_d0.w = 0x14;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = ENTITY(reg_a6)->flags.h;
        reg_d0.h[0] &= 0xE7FF;
        reg_d2.h[0] = ENTITY(reg_a6)[1].flags.h;
        reg_d2.h[0] &= 0xDFFE;
        reg_d0.h[0] |= reg_d2.h[0];
        ENTITY(reg_a6)[1].flags.h = (u16) reg_d0.h[0];
        reg_a3 = (u8 *)(g_direction_sprites_c);
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0xAC0;
        reg_d1.h[0] += 0x780;
        aim256_at_player();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
            reg_d1.b[0] *= 4;
        }
        STAGE2_MIDBOSS(reg_a5)->gun[0].dir.b[0] = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0xF8;
        reg_d1.h[0] >>= 1;
        STAGE2_MIDBOSS(reg_a5)->gun[0].sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
        STAGE2_MIDBOSS(reg_a5)->gun[0].sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0xAC0;
        reg_d1.h[0] += 0x7FFF + 0x7881;
        aim256_at_player();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
            reg_d1.b[0] *= 4;
        }
        STAGE2_MIDBOSS(reg_a5)->gun[1].dir.b[0] = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0xF8;
        reg_d1.h[0] >>= 1;
        STAGE2_MIDBOSS(reg_a5)->gun[1].sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
        STAGE2_MIDBOSS(reg_a5)->gun[1].sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
        reg_d0.b[0] = 0x10;
        reg_d1.b[0] = 2;
        reg_d2.b[0] = 0x18;
        if ((s32) g_stage > 1) {
            reg_d0.b[0] = 0x10;
            reg_d1.b[0] = 2;
            reg_d2.b[0] = 0x18;
        }
        STAGE2_MIDBOSS(reg_a5)->hatch_delay = (u8) reg_d0.b[0];
        STAGE2_MIDBOSS(reg_a5)->side_interval = (u8) reg_d1.b[0];
        STAGE2_MIDBOSS(reg_a5)->spread_interval = (u8) reg_d2.b[0];
        reg_a0 = D_002630D0;
        fade_in_and_release();
        g_enemy_signal_0 = 1;
        sfx_heli_start();
        g_bullet_limit_raised_1[0] = 1;
        if (g_loop != 0) {
            g_bullet_limit_raised_2[0] = 1;
        }
    }
}

typedef void (*Fn)();

extern u8 g_direction_offsets_400[];
s32 bullet_fire256_fixed();
s32 bullet_fire256_fast();
s32 bullet_fire256_2way();
s32 bullet_fire256_3way();
s32 bullet_fire256();
s32 enemy_anims_spawn_listed_long();
s32 explosion_spawn();
s32 enemy_hitbox_debug_draw();
s32 enemy_remove();
s32 enemy_path_step();
s32 enemy_switch_target_player();
s32 sfx_explosion_extra_1();
s32 sfx_beam_loop_stop();
s32 entity_draw_layer1();
s32 entity_draw_layer5();
s32 sprite_draw_layer1();
s32 sprite_draw_layer4();
s32 sprite_draw_layer5();
s32 score_add_no_chain();
s32 score_add();
s32 rng_next_d1();
s32 rng_next_unsigned();
s32 bullet_cancel_with_flags_plain();
s32 direction_steps_toward();
s32 direction256_between();
s32 vibration_start_pad1(s32, s32);
s32 vibration_start_pad2(s32, s32);
extern u16 g_direction64_offsets_432[];
extern u16 stage1_midboss_direction64_offsets_166[];
extern u16 stage2_midboss_table[];
extern u16 stage2_midboss_table_2[];
extern u16 stage2_midboss_table_3[];
extern u16 stage2_midboss_table_4[];
extern u16 stage2_midboss_table_5[];
extern u16 stage2_midboss_table_6[];
extern u16 D_00263290[];
extern u8 g_slowdown_timer;
extern u16 g_frame_mod2;
extern u16 g_game_frame;
extern u16 g_enemy_signal_0;
extern u16 g_bullets_blocked;
extern u16 g_scroll_line;
extern u16 g_damage_blink_counter;
extern u16 g_rank_1_16;
extern u16 g_rank_5_16;
extern u16 g_side_scroll_x[];
extern s16 g_player2[56];
extern s16 g_player1[56];

void stage2_midboss(void) {
    u32 cnt;
    u16 val;
    u8 bits;
    u8 *ptr;

    if (ENTITY(reg_a6)->flags.sb[0] < 0) goto skip_1;
    enemy_path_step();
    if (enemy_move_end_requested != 0) return;
    reg_d0.h[0] = ENTITY(reg_a6)->flags.h;
    reg_d0.h[0] &= 0xE7FF;
    reg_d2.h[0] = ENTITY(reg_a6)[1].flags.h;
    reg_d2.h[0] &= 0xDFFE;
    reg_d0.h[0] |= reg_d2.h[0];
    ENTITY(reg_a6)[1].flags.h = reg_d0.h[0];
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x1A00;
    reg_d0.h[0] += g_side_scroll_x[0];
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x9400;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x9400;
    if (reg_tmp.h[1] != 0) goto next_20;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x7A00;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] += 0xE00;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x7A00;
    if (reg_tmp.h[1] == 0) goto next_30;
next_20:
    if (STAGE2_MIDBOSS(reg_a5)->seen == 0) goto next_40;
    g_enemy_signal_0 = 0;
    sfx_beam_loop_stop();
    enemy_remove();
    return;
next_30:
    STAGE2_MIDBOSS(reg_a5)->seen = 1;
next_40:
    if (ENTITY(reg_a6)->misc.b.user != 0) goto next_45;
    reg_tmp.w = 0xB000;
    ENTITY(reg_a6)[1].attr.h = reg_tmp.h[1];
    ENTITY(reg_a6)[1].misc.h = reg_tmp.h[0];
next_45:
    ENTITY(reg_a6)[1].y.h = ENTITY(reg_a6)->y.h;
    ENTITY(reg_a6)[1].x.h = ENTITY(reg_a6)->x.h;
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[1].flags.b[1];
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) goto next_50;
    reg_d0.b[0] = STAGE2_MIDBOSS(reg_a5)->palette;
    reg_d3.b[0] = ENTITY(reg_a6)[2].offset_x.b[1];
    reg_d5.b[0] = ENTITY(reg_a6)[2].draw.b.priority;
    if (!((s32) ENTITY(reg_a6)->hp.h < 0x2C00)) goto next_90;
    if (g_damage_blink_counter != 0) goto next_90;
    reg_d0.w = 0x19;
    goto next_90;
next_50:
    reg_d0.h[0] = 0xA3;
    ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[1].flags.b[1] &= reg_d0.b[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    reg_d3.b[0] = ENTITY(reg_a6)[2].offset_y.b[1];
    reg_d5.b[0] = ENTITY(reg_a6)[2].offset_y.b[0];
    if (reg_d0.b[0] != 0x19) goto next_60;
    reg_d0.b[0] = STAGE2_MIDBOSS(reg_a5)->palette;
    reg_d3.b[0] = ENTITY(reg_a6)[2].offset_x.b[1];
    reg_d5.b[0] = ENTITY(reg_a6)[2].draw.b.priority;
next_60:
    reg_d2.b[0] = STAGE2_MIDBOSS(reg_a5)->hit_flash;
    reg_d0.b[0] ^= reg_d2.b[0];
    reg_d2.b[0] = ENTITY(reg_a6)[2].offset_x.b[0];
    reg_d3.b[0] ^= reg_d2.b[0];
    reg_d2.b[0] = ENTITY(reg_a6)[2].draw.b.flip;
    reg_d5.b[0] ^= reg_d2.b[0];
    reg_d4.h[0] = ENTITY(reg_a6)->hp.h;
    if (!((s16) ENTITY(reg_a6)[1].hp.h < (s16) reg_d4.h[0])) goto next_80;
    reg_d4.h[0] = ENTITY(reg_a6)[1].hp.h;
next_80:
    reg_d6.w = 0x7FFF;
    ENTITY(reg_a6)->hp.h = reg_d6.h[0];
    ENTITY(reg_a6)[1].hp.h = reg_d6.h[0];
    reg_d6.h[0] -= reg_d4.h[0];
    reg_tmp.h[1] = ENTITY(reg_a6)[1].attr.h;
    reg_tmp.h[0] = ENTITY(reg_a6)[1].misc.h;
    reg_tmp.w -= reg_d6.w;
    ENTITY(reg_a6)[1].attr.h = reg_tmp.h[1];
    ENTITY(reg_a6)[1].misc.h = reg_tmp.h[0];
    if ((s32) reg_tmp.w < 0) goto next_700;
next_90:
    ENTITY(reg_a6)->attr.b.palette = reg_d0.b[0];
    ENTITY(reg_a6)[2].offset_y.b[1] = reg_d3.b[0];
    ENTITY(reg_a6)[2].offset_y.b[0] = reg_d5.b[0];
    reg_d0.h[1] = ENTITY(reg_a6)[1].attr.h;
    reg_d0.h[0] = ENTITY(reg_a6)[1].misc.h;
    enemy_anims_spawn_listed_long();
    reg_tmp.b[0] = ENTITY(reg_a6)[1].offset_y.b[1];
    ENTITY(reg_a6)[1].offset_y.b[1] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_120;
    ENTITY(reg_a6)[1].offset_y.b[1] = ENTITY(reg_a6)[1].offset_y.b[0];
    reg_d0.h[0] = ENTITY(reg_a6)[1].offset_x.h;
    reg_a0 = (u8 *) stage2_midboss_table;
    switch (reg_d0.h[0]) { case 0: goto block_zero; }
    val = *(u16 *)(reg_a0 + ((s16) reg_d0.h[0] & ~1));
    goto block_join;
block_zero:
    val = *(u16 *)reg_a0;
block_join:
    ENTITY(reg_a6)[1].draw.h = val;
    ENTITY(reg_a6)[1].sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)[1].offset_x.h -= 4;
    if ((s16) ENTITY(reg_a6)[1].offset_x.h >= 0) goto next_120;
    ENTITY(reg_a6)[1].offset_x.h = 0x1C;
next_120:
    if (g_enemies_stopped != 0) goto next_500;
    if (g_bullets_blocked != 0) goto next_500;
    if (g_enemies_stopped != 0) goto next_500;
    if (g_bullets_blocked != 0) goto next_500;
    if (STAGE2_MIDBOSS(reg_a5)->attack != 0) goto next_400;
    if ((s16) ENTITY(reg_a6)->y.h < 0x1000) goto next_400;
    reg_d0.h[0] = STAGE2_MIDBOSS(reg_a5)->hatch_phase;
    if (reg_d0.h[0] != 0) goto next_200;
    reg_tmp.b[0] = STAGE2_MIDBOSS(reg_a5)->hatch_wait;
    STAGE2_MIDBOSS(reg_a5)->hatch_wait -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_400;
    STAGE2_MIDBOSS(reg_a5)->hatch_wait = STAGE2_MIDBOSS(reg_a5)->hatch_delay;
    STAGE2_MIDBOSS(reg_a5)->hatch_phase = 1;
    goto next_400;
next_200:
    if ((reg_d0.h[0] & 0xFFFF) != 1) goto next_220;
    reg_tmp.b[0] = ENTITY(reg_a6)[1].move.b.speed;
    ENTITY(reg_a6)[1].move.b.speed -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_400;
    ENTITY(reg_a6)[1].move.b.speed = ENTITY(reg_a6)[1].move.b.dir;
    ENTITY(reg_a6)[1].look.h += 4;
    if (ENTITY(reg_a6)[1].look.h != 0x5C) goto next_400;
    STAGE2_MIDBOSS(reg_a5)->hatch_phase = 2;
    goto next_400;
next_220:
    if ((reg_d0.h[0] & 0xFFFF) != 2) goto next_300;
    reg_tmp.b[0] = STAGE2_MIDBOSS(reg_a5)->hatch_wait;
    STAGE2_MIDBOSS(reg_a5)->hatch_wait -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_400;
    reg_d0.h[0] = 0x10;
    reg_d1.h[0] = g_rank_1_16;
    reg_d1.h[0] >>= 2;
    reg_d0.b[0] -= reg_d1.b[0];
    STAGE2_MIDBOSS(reg_a5)->hatch_wait = reg_d0.b[0];
    reg_a0 = (u8 *) ((u16 *)g_player1);
    reg_a1 = (u8 *) ((u16 *)g_player2);
    if (ENEMY_STATE(reg_a5)->target_player == 0) goto next_240;
    reg_atmp = (u8 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) reg_atmp;
next_240:
    if (*(s16 *)reg_a0 < 0) goto next_260;
    if (*(s16 *)reg_a1 >= 0) goto next_400;
    ptr = reg_a0;
    reg_a0 = reg_a1;
    reg_atmp = (u8 *) ptr;
    reg_a1 = ptr;
next_260:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0xF800;
    direction256_between();
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d4.w = 0;
    reg_a0 = (u8 *) stage2_midboss_table_4;
    reg_a1 = (u8 *) stage1_midboss_direction64_offsets_166;
    reg_d6.h[0] = reg_d1.h[0];
    reg_d7.w = 0xB;
loop_280:
    rng_next_d1();
    reg_d1.b[0] = (s8) reg_d1.b[0] * 8;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d0.h[0] = STAGE2_MIDBOSS(reg_a5)->hatch_speed;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = 0x13;
    reg_d5.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d5.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a1 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a1 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d3.w += reg_d5.w;
    if (!(reg_d7.h[0] & 1)) goto next_285;
    bullet_fire256_2way();
    goto next_290;
next_285:
    bullet_fire256_fixed();
next_290:
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (cnt & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_280;
    enemy_switch_target_player();
    reg_tmp.b[0] = STAGE2_MIDBOSS(reg_a5)->hatch_volleys_left;
    STAGE2_MIDBOSS(reg_a5)->hatch_volleys_left -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_400;
    STAGE2_MIDBOSS(reg_a5)->hatch_volleys_left = STAGE2_MIDBOSS(reg_a5)->hatch_volleys;
    reg_d0.h[0] = 0x50;
    reg_d0.h[0] -= g_rank_5_16;
    STAGE2_MIDBOSS(reg_a5)->hatch_wait = reg_d0.b[0];
    STAGE2_MIDBOSS(reg_a5)->hatch_phase = 3;
    goto next_400;
next_300:
    reg_tmp.b[0] = ENTITY(reg_a6)[1].move.b.speed;
    ENTITY(reg_a6)[1].move.b.speed -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_400;
    ENTITY(reg_a6)[1].move.b.speed = ENTITY(reg_a6)[1].move.b.dir;
    ENTITY(reg_a6)[1].look.h -= 4;
    if (ENTITY(reg_a6)[1].look.h != 0) goto next_400;
    STAGE2_MIDBOSS(reg_a5)->hatch_phase = 0;
    STAGE2_MIDBOSS(reg_a5)->attack = 1;
next_400:
    reg_d0.h[0] = ENTITY(reg_a6)[1].look.h;
    reg_a0 = (u8 *) stage2_midboss_table_3;
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    ENTITY(reg_a6)[1].hit_y_plus.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)[1].hit_y_minus.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)[1].hit_x_plus.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)[1].hit_x_minus.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a0 = (u8 *) ((u16 *)g_player1);
    reg_a1 = (u8 *) ((u16 *)g_player2);
    if (ENEMY_STATE(reg_a5)->target_player == 0) goto next_420;
    reg_atmp = (u8 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) reg_atmp;
next_420:
    if (*(s16 *)reg_a0 < 0) goto next_440;
    if (*(s16 *)reg_a1 >= 0) goto next_500;
    ptr = reg_a0;
    reg_a0 = reg_a1;
    reg_atmp = (u8 *) ptr;
    reg_a1 = ptr;
next_440:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d5.w = 4;
    reg_d0.b[0] = STAGE2_MIDBOSS(reg_a5)->side_shots_left;
    if (STAGE2_MIDBOSS(reg_a5)->side_shots != reg_d0.b[0]) goto next_460;
    reg_d5.w = 1;
next_460:
    reg_a3 = (u8 *)g_direction_sprites_c;
    bits = ENTITY(reg_a6)->flags.b[0];
    if (bits & 0x40) {
        ENTITY(reg_a6)->flags.b[0] = bits & 0xBF;
        goto next_480;
    }
    ENTITY(reg_a6)->flags.b[0] = bits | 0x40;
    reg_d0.h[0] += 0xAC0;
    reg_d1.h[0] += 0x780;
    direction256_between();
    reg_d0.h[0] = STAGE2_MIDBOSS(reg_a5)->gun[0].dir.h;
    direction_steps_toward();
    STAGE2_MIDBOSS(reg_a5)->gun[0].dir.h = reg_d1.h[0];
    reg_d1.b[0] += 4;
    reg_d1.h[0] &= 0xF8;
    reg_d1.h[0] >>= 1;
    STAGE2_MIDBOSS(reg_a5)->gun[0].sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)(reg_a3 + ((s16) reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
    STAGE2_MIDBOSS(reg_a5)->gun[0].sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a3 + ((s16) (reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
    goto next_500;
next_480:
    reg_d0.h[0] += 0xAC0;
    reg_d1.h[0] += 0xF880;
    direction256_between();
    reg_d0.h[0] = STAGE2_MIDBOSS(reg_a5)->gun[1].dir.h;
    direction_steps_toward();
    STAGE2_MIDBOSS(reg_a5)->gun[1].dir.h = reg_d1.h[0];
    reg_d1.h[0] += 4;
    reg_d1.h[0] &= 0xF8;
    reg_d1.h[0] >>= 1;
    STAGE2_MIDBOSS(reg_a5)->gun[1].sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)(reg_a3 + ((s16) reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
    STAGE2_MIDBOSS(reg_a5)->gun[1].sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a3 + ((s16) (reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
next_500:
    reg_a2 = (u8 *) entity_draw_layer5;
    reg_a3 = (u8 *) sprite_draw_layer5;
    reg_a4 = (u8 *) sprite_draw_layer4;
    if (!((s32) g_scroll_line < 0x11E)) goto next_510;
    reg_a2 = (u8 *) entity_draw_layer1;
    reg_a3 = (u8 *) sprite_draw_layer1;
    reg_a4 = (u8 *) sprite_draw_layer1;
next_510:
    reg_call_target = (Fn) reg_a2;
    reg_call_target();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0xF200;
    reg_d1.h[1] += 0xE400;
    reg_d0.h[0] = ENTITY(reg_a6)[1].look.h;
    reg_a0 = (u8 *) stage2_midboss_table_2;
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = 0x1670;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)[2].offset_y.b[0];
    reg_call_target = (Fn) reg_a3;
    reg_call_target();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x480;
    reg_d1.h[1] += 0x6C0;
    reg_d2.h[1] = STAGE2_MIDBOSS(reg_a5)->gun[0].sprite[0];
    reg_d2.h[0] = STAGE2_MIDBOSS(reg_a5)->gun[0].sprite[1];
    reg_d3.h[0] = 0x418;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_call_target = (Fn) reg_a3;
    reg_call_target();
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0xF580;
    reg_d2.h[1] = STAGE2_MIDBOSS(reg_a5)->gun[1].sprite[0];
    reg_d2.h[0] = STAGE2_MIDBOSS(reg_a5)->gun[1].sprite[1];
    reg_call_target = (Fn) reg_a3;
    reg_call_target();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0xEE00;
    reg_d1.h[1] += 0xF900;
    reg_d2.h[1] = ENTITY(reg_a6)[1].draw.h;
    reg_d2.h[0] = ENTITY(reg_a6)[1].sprite.h;
    reg_d3.h[0] = 0x1290;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)[2].offset_y.b[1];
    reg_call_target = (Fn) reg_a3;
    reg_call_target();
    if (g_loop != 0) goto next_540;
    if (g_frame_mod2 == 0) goto next_540;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[1] += 0xD600;
    reg_d2.w = 0x1B9F;
    reg_d3.h[0] = 0xC48;
    reg_d4.h[0] = 0x18;
    if (!(g_game_frame & 2)) goto next_520;
    reg_d4.h[0] |= 0x4000;
next_520:
    reg_call_target = (Fn) reg_a4;
    reg_call_target();
next_540:
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x20;
    enemy_hitbox_debug_draw();
    if (g_enemies_stopped != 0) goto block_rts;
    if (g_bullets_blocked != 0) goto block_rts;
    if ((s16) ENTITY(reg_a6)->y.h < 0x1000) goto block_rts;
    reg_d0.h[0] = STAGE2_MIDBOSS(reg_a5)->attack;
    if (reg_d0.h[0] == 0) goto block_rts;
    if (reg_d0.h[0] != 1) goto next_800;
    reg_tmp1.w = 0;
    reg_tmp.w = 0;
    reg_tmp.b[0] = STAGE2_MIDBOSS(reg_a5)->side_wait;
    reg_tmp.h[0] -= 1;
    STAGE2_MIDBOSS(reg_a5)->side_wait -= 1;
    if (reg_tmp.b[1] != 0) goto next_600;
block_rts:
    return;
next_600:
    STAGE2_MIDBOSS(reg_a5)->side_wait = STAGE2_MIDBOSS(reg_a5)->side_interval;
    reg_a4 = (u8 *)g_direction_offsets_400;
    reg_d1.h[0] = STAGE2_MIDBOSS(reg_a5)->gun[0].dir.h;
    reg_d0.h[0] = reg_d1.h[0];
    reg_d0.h[0] += 4;
    reg_d0.h[0] &= 0xF8;
    reg_d0.h[0] >>= 1;
    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a4 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a4 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] += 0x780;
    reg_d3.h[1] += 0xAC0;
    reg_d4.w = (u32) reg_a6;
    reg_d0.w = 0x180007;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    bullet_fire256_3way();
    reg_d6.b[0] = STAGE2_MIDBOSS(reg_a5)->side_shots_left;
    reg_d6.b[0] += reg_d6.b[0];
    reg_d6.b[0] += STAGE2_MIDBOSS(reg_a5)->side_angle;
    reg_d1.b[0] -= reg_d6.b[0];
    bullet_fire256_fast();
    reg_d1.h[0] = STAGE2_MIDBOSS(reg_a5)->gun[1].dir.h;
    reg_d4.h[0] = reg_d1.h[0];
    reg_d4.h[0] += 4;
    reg_d4.h[0] &= 0xF8;
    reg_d4.h[0] >>= 1;
    reg_d3.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)(reg_a4 + ((s16) reg_d4.h[0] & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] = (((u16) reg_d4.h[0] + 2) != 0) ? *(u16 *)(reg_a4 + ((s16) ((u16) reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] += 0xF880;
    reg_d3.h[1] += 0xAC0;
    bullet_fire256_3way();
    reg_d6.b[0] = STAGE2_MIDBOSS(reg_a5)->side_shots_left;
    reg_d6.b[0] += reg_d6.b[0];
    reg_d6.b[0] += STAGE2_MIDBOSS(reg_a5)->side_angle;
    reg_d1.b[0] += reg_d6.b[0];
    bullet_fire256_fast();
    reg_tmp.b[0] = STAGE2_MIDBOSS(reg_a5)->side_shots_left;
    STAGE2_MIDBOSS(reg_a5)->side_shots_left -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_650;
    STAGE2_MIDBOSS(reg_a5)->side_shots += 6;
    STAGE2_MIDBOSS(reg_a5)->side_shots_left = STAGE2_MIDBOSS(reg_a5)->side_shots;
    STAGE2_MIDBOSS(reg_a5)->side_wait = STAGE2_MIDBOSS(reg_a5)->side_pause;
    enemy_switch_target_player();
    STAGE2_MIDBOSS(reg_a5)->attack = 2;
    STAGE2_MIDBOSS(reg_a5)->side_angle -= 2;
    if ((s32) STAGE2_MIDBOSS(reg_a5)->side_angle >= 5) goto next_650;
    STAGE2_MIDBOSS(reg_a5)->side_angle = 5;
next_650:
    return;
next_800:
    reg_tmp.w = 0;
    reg_tmp.b[0] = STAGE2_MIDBOSS(reg_a5)->spread_wait;
    reg_tmp.h[0] -= 1;
    STAGE2_MIDBOSS(reg_a5)->spread_wait -= 1;
    if (reg_tmp.b[1] != 0) goto next_820;
    return;
next_820:
    STAGE2_MIDBOSS(reg_a5)->spread_wait = STAGE2_MIDBOSS(reg_a5)->spread_interval;
    if (!(STAGE2_MIDBOSS(reg_a5)->spread_step.b[0] & 4)) goto next_830;
    rng_next_unsigned();
    reg_d1.h[0] = reg_d0.h[0];
    goto next_870;
next_830:
    reg_a0 = (u8 *) ((u16 *)g_player1);
    reg_a1 = (u8 *) ((u16 *)g_player2);
    if (ENEMY_STATE(reg_a5)->target_player == 0) goto next_840;
    reg_atmp = (u8 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) reg_atmp;
next_840:
    if (*(s16 *)reg_a0 < 0) goto next_860;
    if (*(s16 *)reg_a1 >= 0) goto next_900;
    ptr = reg_a0;
    reg_a0 = reg_a1;
    reg_atmp = (u8 *) ptr;
    reg_a1 = ptr;
next_860:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0xF940;
    direction256_between();
next_870:
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d4.h[0] = STAGE2_MIDBOSS(reg_a5)->spread_step.h;
    reg_d0.h[0] = STAGE2_MIDBOSS(reg_a5)->spread_speed;
    reg_d0.h[0] = reg_d0.h[0] - reg_d4.h[0];
    reg_d0.h[0] >>= 1;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = 3;
    if (!(STAGE2_MIDBOSS(reg_a5)->spread_step.b[0] & 4)) goto next_875;
    reg_d0.h[0] = 3;
next_875:
    reg_a0 = (u8 *) stage2_midboss_table_5;
    reg_d5.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d4.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d5.h[0] = (((u16) reg_d4.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) ((u16) reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) stage2_midboss_table_6;
    reg_d6.h[0] = (reg_d4.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d4.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d7.h[0] = (((u16) reg_d4.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) ((u16) reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d4.w = 0;
    reg_a0 = (u8 *) g_direction64_offsets_432;
loop_880:
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += reg_d5.w;
    bullet_fire256();
    if (!(reg_d7.h[0] & 1)) goto next_890;
    reg_d0.w -= 0x60000;
    reg_d0.h[0] += 1;
    bullet_fire256_fixed();
    reg_d0.w += 0x60000;
    reg_d0.h[0] -= 1;
next_890:
    reg_d1.h[0] += reg_d6.h[0];
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (cnt & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_880;
    STAGE2_MIDBOSS(reg_a5)->spread_step.h -= 4;
    if ((s16) STAGE2_MIDBOSS(reg_a5)->spread_step.h >= 0) goto next_900;
    STAGE2_MIDBOSS(reg_a5)->spread_speed += 8;
    STAGE2_MIDBOSS(reg_a5)->spread_step.h = 0xC;
    STAGE2_MIDBOSS(reg_a5)->spread_wait = STAGE2_MIDBOSS(reg_a5)->spread_pause;
    enemy_switch_target_player();
    STAGE2_MIDBOSS(reg_a5)->attack = 0;
next_900:
    return;
next_700:
    sfx_beam_loop_stop();
    sfx_explosion_extra_1();
    ENTITY(reg_a6)[2].look.h = reg_d1.h[0];
    reg_d0.w = 0x457;
    score_add();
    vibration_start_pad1(0xB4, 0x3C);
    vibration_start_pad2(0xB4, 0x3C);
    g_slowdown_timer = 0x3C;
    reg_a0 = (u8 *) D_00263290;
    fade_in_and_release();
    reg_d0.h[0] = 0x8080;
    ENTITY(reg_a6)->flags.sh = (s16) reg_d0.h[0];
    ENTITY(reg_a6)[1].flags.h = (u16) reg_d0.h[0];
    reg_d0.w = 0xD;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    val = ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->x = val;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    EXPLOSION(reg_a0)->start_y = 0x400;
    EXPLOSION(reg_a0)->debris = 0;
    EXPLOSION(reg_a0)->debris_arg = 0x400;
    reg_d0.h[0] = 0x84;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    EXPLOSION(reg_a0)->start_y = 0x400;
    EXPLOSION(reg_a0)->start_x = 0x200;
    EXPLOSION(reg_a0)->move.h = 0x44C;
    EXPLOSION(reg_a0)->debris = 0;
    EXPLOSION(reg_a0)->debris_arg = 0;
    EXPLOSION(reg_a0)->delay = 1;
    reg_d0.h[0] = 0x84;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    EXPLOSION(reg_a0)->start_y = 0x400;
    EXPLOSION(reg_a0)->start_x = 0xFE00;
    EXPLOSION(reg_a0)->move.h = 0x4B4;
    EXPLOSION(reg_a0)->debris = 0;
    EXPLOSION(reg_a0)->debris_arg = 0x400;
    EXPLOSION(reg_a0)->attr.b.flip = 0x40;
    EXPLOSION(reg_a0)->delay = 2;
    reg_d0.w = 0xD;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    EXPLOSION(reg_a0)->start_y = 0xFA00;
    EXPLOSION(reg_a0)->start_x = 0xFE00;
    EXPLOSION(reg_a0)->move.h = 0x6A8;
    EXPLOSION(reg_a0)->debris = 0;
    EXPLOSION(reg_a0)->debris_arg = 0;
    EXPLOSION(reg_a0)->delay = 2;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    EXPLOSION(reg_a0)->start_y = 0xFC00;
    EXPLOSION(reg_a0)->start_x = 0x100;
    EXPLOSION(reg_a0)->move.h = 0x858;
    EXPLOSION(reg_a0)->debris = 0;
    EXPLOSION(reg_a0)->debris_arg = 0;
    EXPLOSION(reg_a0)->delay = 4;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    EXPLOSION(reg_a0)->start_y = 0xF400;
    EXPLOSION(reg_a0)->start_x = 0xFE00;
    EXPLOSION(reg_a0)->move.h = 0xA88;
    EXPLOSION(reg_a0)->debris = 0;
    EXPLOSION(reg_a0)->debris_arg = 0x400;
    EXPLOSION(reg_a0)->delay = 6;
    reg_d0.w = 0xD;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    EXPLOSION(reg_a0)->start_y = 0xF400;
    EXPLOSION(reg_a0)->start_x = 0x400;
    EXPLOSION(reg_a0)->move.h = 0xA78;
    EXPLOSION(reg_a0)->debris = 0;
    EXPLOSION(reg_a0)->debris_arg = 0x400;
    EXPLOSION(reg_a0)->delay = 4;
    reg_d0.h[0] = 0xD;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    EXPLOSION(reg_a0)->start_y = 0;
    EXPLOSION(reg_a0)->start_x = 0xF200;
    EXPLOSION(reg_a0)->move.h = 0x4A0;
    EXPLOSION(reg_a0)->debris = 0;
    EXPLOSION(reg_a0)->debris_arg = 0x400;
    EXPLOSION(reg_a0)->delay = 8;
    reg_d0.h[0] = 0xD;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    EXPLOSION(reg_a0)->start_y = 0;
    EXPLOSION(reg_a0)->start_x = 0xE00;
    EXPLOSION(reg_a0)->move.h = 0x460;
    EXPLOSION(reg_a0)->debris = 0;
    EXPLOSION(reg_a0)->debris_arg = 0x400;
    EXPLOSION(reg_a0)->delay = 8;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    EXPLOSION(reg_a0)->start_y = 0xEA00;
    EXPLOSION(reg_a0)->start_x = 0xF600;
    EXPLOSION(reg_a0)->move.h = 0xA90;
    EXPLOSION(reg_a0)->debris = 0;
    EXPLOSION(reg_a0)->debris_arg = 0x400;
    EXPLOSION(reg_a0)->delay = 0xA;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    EXPLOSION(reg_a0)->start_y = 0xEA00;
    EXPLOSION(reg_a0)->start_x = 0xA00;
    EXPLOSION(reg_a0)->move.h = 0xA70;
    EXPLOSION(reg_a0)->debris = 0;
    EXPLOSION(reg_a0)->debris_arg = 0x400;
    EXPLOSION(reg_a0)->delay = 0xA;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
    EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
    EXPLOSION(reg_a0)->draw_layer = 0x10;
    EXPLOSION(reg_a0)->start_y = 0xE400;
    EXPLOSION(reg_a0)->start_x = 0x200;
    EXPLOSION(reg_a0)->move.h = 0x588;
    EXPLOSION(reg_a0)->debris = 0;
    EXPLOSION(reg_a0)->debris_arg = 0x400;
    EXPLOSION(reg_a0)->delay = 8;
skip_1:
    if (ENTITY(reg_a6)[2].sprite.h == 0x30) {
        g_enemy_signal_0 = 0;
    }
    reg_d1.h[0] = ENTITY(reg_a6)[2].look.h;
    bullet_cancel_with_flags_plain();
    ENTITY(reg_a6)[2].sprite.h -= 1;
    if (ENTITY(reg_a6)[2].sprite.h == 0) {
        sfx_beam_loop_stop();
        enemy_remove();
    }
}

u8 stage2_midboss_start_table[48] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x15, 0x50, 0x60, 0x09, 0x09, 0x30, 0x40, 0x11, 0x11,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x0C, 0x00, 0xFE, 0xFF, 0x08, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 D_00263030[160] = {
    0x01, 0xA0, 0x00, 0xEE, 0x00, 0xF1, 0x00, 0x00, 0x7E, 0x1B, 0x78, 0x12, 0x00, 0x0E, 0x00, 0x06,
    0x00, 0x0E, 0x00, 0x0E, 0xFF, 0x7F, 0x00, 0x10, 0x15, 0x00, 0x00, 0x00, 0x01, 0xA0, 0x00, 0x00,
    0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x0E, 0x00, 0x06, 0x00, 0x06,
    0xFF, 0x7F, 0x01, 0x00, 0x00, 0x00, 0x00, 0xB0, 0x00, 0x80, 0x17, 0x16, 0x09, 0x16, 0x08, 0x17,
    0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x7B, 0x00, 0x04, 0x00, 0xFA, 0x14, 0x00, 0x00, 0x00,
    0x30, 0x00, 0x31, 0x00, 0x00, 0x00, 0xAE, 0x60, 0x00, 0xFA, 0x00, 0x02, 0x14, 0x00, 0x00, 0x00,
    0x38, 0x00, 0x39, 0x00, 0x00, 0x00, 0x50, 0x46, 0x00, 0x02, 0x00, 0xFE, 0x08, 0x00, 0x00, 0x00,
    0x40, 0x00, 0x41, 0x00, 0x00, 0x00, 0xF2, 0x2B, 0x00, 0x08, 0x00, 0x04, 0x14, 0x00, 0x00, 0x00,
    0x48, 0x00, 0x49, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 D_002630D0[48] = {
    0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x05, 0x04, 0x00, 0x05, 0x00, 0x1F, 0x00, 0x05, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0x05, 0x0B, 0x00, 0x0C, 0x00, 0x1F, 0x00, 0x05, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xC0, 0x05, 0x12, 0x00, 0x13, 0x00, 0x1F, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u16 stage2_midboss_table[16] = {
    0x0000, 0x1B86, 0x0000, 0x1B85, 0x0000, 0x1B84, 0x0000, 0x1B83,
    0x0000, 0x1B82, 0x0000, 0x1B81, 0x0000, 0x1B80, 0x0000, 0x1B7F,
};

u16 stage2_midboss_table_2[48] = {
    0x0000, 0x1B87, 0x0000, 0x1B88, 0x0000, 0x1B89, 0x0000, 0x1B8A,
    0x0000, 0x1B8B, 0x0000, 0x1B8C, 0x0000, 0x1B8D, 0x0000, 0x1B8E,
    0x0000, 0x1B8F, 0x0000, 0x1B90, 0x0000, 0x1B91, 0x0000, 0x1B92,
    0x0000, 0x1B93, 0x0000, 0x1B94, 0x0000, 0x1B95, 0x0000, 0x1B96,
    0x0000, 0x1B97, 0x0000, 0x1B98, 0x0000, 0x1B99, 0x0000, 0x1B9A,
    0x0000, 0x1B9B, 0x0000, 0x1B9C, 0x0000, 0x1B9D, 0x0000, 0x1B9E,
};

u16 stage2_midboss_table_3[96] = {
    0xFA00, 0x0E00, 0x0900, 0x0900, 0xFA00, 0x0E40, 0x0940, 0x0940,
    0xFA00, 0x0E80, 0x0980, 0x0980, 0xFA00, 0x0EC0, 0x09C0, 0x09C0,
    0xFA00, 0x0F00, 0x0A00, 0x0A00, 0xFA00, 0x0F40, 0x0A40, 0x0A40,
    0xFA00, 0x0F80, 0x0A80, 0x0A80, 0xFA00, 0x0FC0, 0x0AC0, 0x0AC0,
    0xFA00, 0x1000, 0x0B00, 0x0B00, 0xFA00, 0x1040, 0x0B40, 0x0B40,
    0xFA00, 0x1080, 0x0B80, 0x0B80, 0xFA00, 0x10C0, 0x0BC0, 0x0BC0,
    0xFA00, 0x1100, 0x0C00, 0x0C00, 0xFA00, 0x1140, 0x0C40, 0x0C40,
    0xFA00, 0x1180, 0x0C80, 0x0C80, 0xFA00, 0x11C0, 0x0CC0, 0x0CC0,
    0xFA00, 0x1200, 0x0D00, 0x0D00, 0xFA00, 0x1240, 0x0D40, 0x0D40,
    0xFA00, 0x1280, 0x0D80, 0x0D80, 0xFA00, 0x12C0, 0x0D80, 0x0D80,
    0xFA00, 0x1300, 0x0D80, 0x0D80, 0xFA00, 0x1340, 0x0D80, 0x0D80,
    0xFA00, 0x1380, 0x0D80, 0x0D80, 0xFA00, 0x13C0, 0x0D80, 0x0D80,
};

u16 stage2_midboss_table_4[24] = {
    0xF600, 0xFB00, 0xF200, 0x0880, 0xF3C0, 0xFB00, 0xF840, 0x0880,
    0xEF80, 0x0500, 0xF3C0, 0x0500, 0xF500, 0xF780, 0xEF80, 0xFB00,
    0xF500, 0x0880, 0xF840, 0xF780, 0xF200, 0xF780, 0xF600, 0x0500,
};

u16 stage2_midboss_table_5[8] = {
    0xF080, 0xFD80, 0xF080, 0x0280, 0xF600, 0xFD80, 0xF600, 0x0280,
};

u16 stage2_midboss_table_6[8] = {
    0x0008, 0x001F, 0x0010, 0x000F, 0x0008, 0x001F, 0x0010, 0x000F,
};

u16 D_00263290[112] = {
    0x000F, 0x7FFF, 0x0000, 0x0780, 0x0004, 0x0005, 0x001F, 0x0004,
    0x7FFF, 0x0000, 0x0540, 0x000B, 0x000C, 0x001F, 0x0005, 0x7FFF,
    0x0000, 0x0580, 0x0012, 0x0013, 0x001F, 0x0005, 0x7FFF, 0x0000,
    0x05C0, 0x0019, 0x001A, 0x001F, 0x0005, 0x7FFF, 0x0008, 0x0000,
    0x0020, 0x0021, 0x001F, 0x0005, 0x7FFF, 0x0008, 0x0040, 0x0027,
    0x0028, 0x001F, 0x0005, 0x7FFF, 0x0008, 0x0080, 0x002E, 0x002F,
    0x001F, 0x0005, 0x7FFF, 0x0008, 0x0100, 0x0035, 0x0036, 0x001F,
    0x0005, 0x7FFF, 0x0008, 0x0180, 0x003C, 0x003D, 0x001F, 0x0005,
    0x7FFF, 0x0008, 0x01C0, 0x0043, 0x0044, 0x001F, 0x0005, 0x7FFF,
    0x0008, 0x0200, 0x004A, 0x004B, 0x001F, 0x0005, 0x7FFF, 0x0008,
    0x0240, 0x0051, 0x0052, 0x001F, 0x0005, 0x7FFF, 0x0008, 0x0280,
    0x0058, 0x0059, 0x001F, 0x0005, 0x7FFF, 0x0008, 0x02C0, 0x005F,
    0x0060, 0x001F, 0x0005, 0x7FFF, 0x0008, 0x0300, 0x0066, 0x0067,
    0x001F, 0x0005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};
