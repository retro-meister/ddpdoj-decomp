#include "common.h"
#include "entity.h"

void frame_layers_flush(void);
void slowdown_reset(void);

extern u8 D_0028E218;
extern u8 g_slowdown_frame_state;


void slowdown_init(void) {
    g_slowdown_frame_state = 0;
    D_0028E218 = 0;
    slowdown_reset();
}

extern u8 slowdown_load_thresholds[];
extern u8 slowdown_load_thresholds_loop2[];
extern u8 slowdown_budget_limits[];
extern u8 slowdown_budget_limits_loop2[];
extern u16 g_player_laser_count;
extern u16 g_player_shot_count;
extern u8 g_paused;
extern u8 D_0028E378;
extern u16 g_slowdown_loop2_allowed_as_u16;
extern u16 g_slowdown_off_as_u16;
extern u16 g_slowdown_boss_allowed_as_u16;
extern u16 g_slowdown_budget;
extern u16 g_slowdown_forced_frames_as_u16;
extern u16 g_frame_mod3;
extern u16 g_p2_hyper_active;
extern u16 g_p1_hyper_active;
extern u16 D_0028E7E4;
extern u16 g_loop;
extern u16 g_stage_x4;
extern u16 g_stage_x2;
extern u16 D_00299760[];
extern u16 D_0029976A_as_u16_a[];
void slowdown_update(void) {
    u8 *tbl;

    frame_layers_flush();
    if (g_paused != 0) return;
    g_slowdown_frame_state = 1;
    if (g_frame_mod3 != 0) return;
    if (g_slowdown_forced_frames_as_u16 != 0) {
        g_slowdown_forced_frames_as_u16 -= 1;
        goto next_20;
    }
    if (g_slowdown_off_as_u16 != 0) return;
    reg_d0.h[0] = D_00299760[0];
    if (D_0028E7E4 == 0) goto next_5;
    if (g_slowdown_boss_allowed_as_u16 == 0) return;
next_5:
    reg_d0.h[0] += g_player_shot_count;
    reg_d0.h[0] += g_player_laser_count;
    reg_d0.h[0] += g_player_laser_count;
    reg_d1.w = 0;
    tbl = slowdown_load_thresholds;
    if (g_loop == 0) goto next_8;
    tbl = slowdown_load_thresholds_loop2;
    if (g_slowdown_loop2_allowed_as_u16 == 0) return;
    reg_d1.h[0] += 0x28;
next_8:
    reg_d2.h[0] = g_stage_x4;
    tbl += reg_d2.h[0] & ~1;
    reg_d1.h[0] += *(s16 *) (tbl + 0);
    if (D_0029976A_as_u16_a[0] == 0) goto next_10;
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
    tbl = slowdown_budget_limits;
    if (g_loop == 0) goto next_17;
    tbl = slowdown_budget_limits_loop2;
next_17:
    reg_d2.h[0] = (s32) g_stage_x2 >> 1;
    reg_d2.h[0] = ((s16 *) tbl)[reg_d2.h[0]];
    if (!((s32) g_slowdown_budget < (s32) reg_d2.h[0])) goto next_20;
    g_slowdown_budget += 2;
next_20:
    g_slowdown_frame_state = 2;
    if (D_0028E378 == 0xFF) {
        g_slowdown_frame_state = 0;
    }
}

s32 layer_a_apply_scroll();                            /* extern */
s32 deferred_text_flush();                            /* extern */
s32 func_00130790();                            /* extern */
s32 func_00130A60();                            /* extern */
s32 func_001A2C80();                            /* extern */
s32 func_001AB5C0();                            /* extern */
s32 func_00206CB0();                            /* extern */

void frame_layers_flush(void) {
    func_00130790();
    func_00130A60();
    func_001A2C80();
    layer_a_apply_scroll();
    deferred_text_flush();
    func_001AB5C0();
    func_00206CB0();
}

extern s16 g_slowdown_loop2_allowed;
extern s16 g_slowdown_off;
extern s16 g_slowdown_boss_allowed;
extern s16 g_slowdown_budget_as_s16;
extern s16 g_slowdown_forced_frames;

void slowdown_reset(void) {
    g_slowdown_forced_frames = 0;
    g_slowdown_budget_as_s16 = 0;
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
