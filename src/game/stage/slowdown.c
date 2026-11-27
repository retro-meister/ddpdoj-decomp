#include "common.h"
#include "black_label.h"
#include "entity.h"

/* How many objects a frame may hold before the game slows down, by stage: the base number, and what is
   added while a boss is on screen. */
s16 slowdown_load_thresholds[5][2] = {
    { 110, 20 }, { 105, 20 }, { 100, 20 }, { 95, 20 }, { 90, 20 },
};
s16 slowdown_load_thresholds_loop2[5][2] = {
    { 90, 20 }, { 90, 20 }, { 90, 20 }, { 90, 20 }, { 90, 20 },
};
/* How far the slow frame budget may build up, by stage. */
s16 slowdown_budget_limits[5] = { 4, 8, 12, 16, 20 };
s16 slowdown_budget_limits_loop2[5] = { 20, 20, 20, 20, 20 };

void frame_layers_flush(void);
void slowdown_reset(void);

extern u8 slowdown_init_state;
extern u8 g_slowdown_frame_state;


void slowdown_init(void) {
    g_slowdown_frame_state = 0;
    slowdown_init_state = 0;
    slowdown_reset();
}

extern u16 g_player_laser_count;
extern u16 g_player_shot_count;
extern u8 g_paused;
extern u8 g_stage_jump_state;
extern s16 g_slowdown_loop2_allowed;
extern s16 g_slowdown_off;
extern s16 g_slowdown_boss_allowed;
extern u16 g_slowdown_budget;
extern s16 g_slowdown_forced_frames;
extern u16 g_frame_mod3;
extern u16 g_p2_hyper_active;
extern u16 g_p1_hyper_active;
extern u16 g_enemy_count_second;
extern u16 g_loop;
extern u16 g_true_last_boss;
extern u16 g_stage_x4;
extern u16 g_stage_x2;
extern u16 g_bullets_alive[];
extern s16 g_bullet_limit_raised_2[];

#ifdef DDPDOJ_BONUS_FEATURES
s16 g_boss_shake_y, g_boss_shake_x;
static u16 shake_frame, burst_wait;

void black_label_shake_start(void) {
    shake_frame = 1;
    burst_wait = 20;
    g_boss_shake_y = g_boss_shake_x = 0;
    g_slowdown_boss_allowed = 6;
    g_slowdown_off = 0;
}

void black_label_shake_stop(void) {
    shake_frame = 0;
}

void black_label_shake_step(void) {
    static const s8 offsets[][2] = {
        { -24, 0 }, { -24, 0 }, { -24, 0 }, { -8, 16 }, { -8, 12 },
        { -8, 8 }, { 16, 8 }, { 16, 8 }, { 12, 8 }, { 6, 4 },
        { 6, 4 }, { 6, 4 }, { 6, -8 }, { 6, -8 }, { 6, -8 },
        { 6, -4 }, { 6, -4 }, { 6, -4 }, { -9, 0 }, { -9, 0 },
        { -3, 12 }, { -3, 12 }, { 6, 6 }, { 6, 6 }, { 3, 3 },
        { 3, 3 }, { 3, -6 }, { 3, -6 }, { 3, -3 }, { 3, -3 },
        { -6, 0 }, { -2, 8 }, { 4, 4 }, { 2, 2 }, { 2, -4 },
        { 2, -2 }, { -3, 0 }, { -1, 4 }, { 2, 2 }, { 1, 1 },
        { 1, -2 }, { 1, -1 }, { 0, 0 },
    };
    if (!shake_frame) return;
    g_boss_shake_y = offsets[shake_frame - 1][0];
    g_boss_shake_x = offsets[shake_frame - 1][1];
    ++shake_frame;
    if (!g_boss_shake_y) {
        shake_frame = 0;
        g_slowdown_boss_allowed = 0;
        g_slowdown_off = 1;
    }
}
#endif

void slowdown_update(void) {
    u8 *tbl;

    frame_layers_flush();
    if (g_paused != 0) return;
    g_slowdown_frame_state = 1;
    /* The game increments this counter after running the stage tasks. */
    if (g_frame_mod3 != GAME_RULE(0, 1)) return;
    if ((u16)g_slowdown_forced_frames != 0) {
        (*(u16 *)&g_slowdown_forced_frames) -= 1;
        goto next_20;
    }
#ifdef DDPDOJ_BONUS_FEATURES
    if (g_black_label_active && burst_wait) {
        --burst_wait;
        g_slowdown_frame_state = burst_wait > 15 ? 3 : 2;
        return;
    }
#endif
    if ((u16)g_slowdown_off != 0) return;
    reg_d0.h[0] = g_bullets_alive[0];
    if (g_enemy_count_second == 0) goto next_5;
    if ((u16)g_slowdown_boss_allowed == 0) return;
#ifdef DDPDOJ_BONUS_FEATURES
    if (g_black_label_active && g_slowdown_boss_allowed >= 5) {
        g_slowdown_frame_state = g_slowdown_boss_allowed;
        return;
    }
#endif
next_5:
    reg_d0.h[0] += g_player_shot_count;
    reg_d0.h[0] += g_player_laser_count;
    reg_d0.h[0] += g_player_laser_count;
    reg_d1.w = 0;
    tbl = (u8 *)slowdown_load_thresholds;
#ifdef DDPDOJ_BONUS_FEATURES
    if (g_black_label_active && g_loop == 0 && (g_stage_x4 == 4 || g_stage_x4 == 8)) {
        reg_d1.h[0] -= 5;
    }
#endif
    if (GAME_RULE(g_loop == 0, g_loop == 0 && !(g_black_label_single_loop && g_true_last_boss > 1))) goto next_8;
    tbl = (u8 *)slowdown_load_thresholds_loop2;
    if (GAME_RULE((u16)g_slowdown_loop2_allowed == 0, 0)) return;
    reg_d1.h[0] += 0x28;
next_8:
    reg_d2.h[0] = g_stage_x4;
    tbl += reg_d2.h[0] & ~1;
    reg_d1.h[0] += *(s16 *) (tbl + 0);
    if (((u16 *)g_bullet_limit_raised_2)[0] == 0) goto next_10;
    reg_d1.h[0] += *(s16 *) (tbl + 2);
next_10:
    reg_d2.h[0] = g_p1_hyper_active;
    reg_d2.h[0] |= g_p2_hyper_active;
    if (reg_d2.h[0] == 0) goto next_12;
    reg_d1.h[0] += 0x1E;
next_12:
    if (!((s32) reg_d1.h[0] > (s32) reg_d0.h[0])) goto next_15;
    if (g_slowdown_budget == 0) return;
    g_slowdown_budget -= 1;
    goto next_20;
next_15:
    tbl = (u8 *)slowdown_budget_limits;
    if (GAME_RULE(g_loop == 0, g_loop == 0 && !(g_black_label_single_loop && g_true_last_boss > 1))) goto next_17;
    tbl = (u8 *)slowdown_budget_limits_loop2;
next_17:
    reg_d2.h[0] = (s32) g_stage_x2 >> 1;
    reg_d2.h[0] = ((s16 *) tbl)[reg_d2.h[0]];
    if (!((s32) g_slowdown_budget < (s32) reg_d2.h[0])) goto next_20;
    g_slowdown_budget += 2;
next_20:
    g_slowdown_frame_state = 2;
    if (g_stage_jump_state == 0xFF) {
        g_slowdown_frame_state = 0;
    }
}

s32 layer_a_apply_scroll();                            /* extern */
s32 deferred_text_flush();                            /* extern */
s32 coin_update();                            /* extern */
s32 coin_inputs_update();                            /* extern */
s32 palette_banks_flush();                            /* extern */
s32 score_cells_flush();                            /* extern */
s32 display_control_pulse_bit_3();                            /* extern */

void frame_layers_flush(void) {
    coin_update();
    coin_inputs_update();
    palette_banks_flush();
    layer_a_apply_scroll();
    deferred_text_flush();
    score_cells_flush();
    display_control_pulse_bit_3();
}

extern s16 g_slowdown_loop2_allowed;
extern s16 g_slowdown_off;
extern s16 g_slowdown_boss_allowed;
extern s16 g_slowdown_forced_frames;

void slowdown_reset(void) {
#ifdef DDPDOJ_BONUS_FEATURES
    burst_wait = 0;
#endif
    g_slowdown_forced_frames = 0;
    g_slowdown_budget = 0;
    g_slowdown_boss_allowed = 0;
    g_slowdown_off = 0;
    g_slowdown_loop2_allowed = 0;
}

void slowdown_allow_with_boss(void) {
    g_slowdown_off = 0;
    g_slowdown_boss_allowed = 1;
}

void slowdown_turn_off(void) {
    g_slowdown_boss_allowed = 0;
    g_slowdown_off = 1;
}

u16 D_002693C0[16] = {
    0x0002, 0x0000, 0x0000, 0x0000, 0x0004, 0x0005, 0x001F, 0x0003,
    0x0000, 0x0008, 0x0000, 0x000B, 0x000C, 0x001F, 0x0003, 0x0000,
};
