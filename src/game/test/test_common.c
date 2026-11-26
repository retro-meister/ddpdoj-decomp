#include "common.h"
#include "test_mode.h"

s32 text_layer_put(void);
s32 stage_map_reset();
s32 menu_item_values_clear();
s32 screen_setting_apply();
s32 menu_game_option_defaults();
s32 menu_system_option_defaults();
s32 save_snapshot_take();

extern s8 g_default_setting_continue[];
extern s8 g_default_setting_demo_sound[];
extern s8 g_default_setting_chute_type[];
extern s8 g_default_setting_difficulty[];
extern s8 g_default_setting_extend[];
extern s8 g_default_setting_ship_stock[];
extern s8 g_default_setting_rapid_fire[];
extern s8 g_display_offset_y;
extern s8 g_display_offset_x;
extern u8 D_0028E258;
extern u8 D_0028E25C;
extern u8 D_0028E260;
extern u8 D_0028E264;
extern u8 D_0028E268;
extern u8 g_p1_btn_map_a;
extern u8 g_p1_btn_map_b;
extern u8 g_p1_btn_map_c;
extern u8 D_0028E273;
extern u8 g_p2_btn_map_a;
extern u8 g_p2_btn_map_b;
extern u8 g_p2_btn_map_c;
extern u8 D_0028E277;
extern u8 D_0028E278;
extern u8 g_pad_vib_enabled;
extern u8 D_0028E284;
extern u8 D_0028E288;
extern u8 g_stage_map_enabled;
extern u8 D_0028E294;
extern u8 g_pad_input_locked;
extern u16 D_0028E29C;
extern u8 D_0028E2A0;
extern u8 D_0028E2A4;
extern u8 D_0028E2A8;
extern u16 D_0028E2AC;
extern u8 D_0028E2B0;
extern u8 D_0028E2C4;
extern u8 g_simulation_boss_start;
extern u8 D_0028E2CC;
extern u8 D_0028E2D0;
extern u8 D_0028E2D4;
extern u8 D_0028E2D8;
extern u8 g_screen_wide;
extern u8 g_bgm_alternate_set;
extern u8 D_0028E2E4;
extern u8 D_0028E2EC;
extern u8 g_splash_visible;
extern u8 g_pad_tate_rotate;
extern u16 D_0028E2FC;
extern u16 D_0028E300;
extern u8 D_0028E304;
extern u8 D_0028E308;
extern u8 D_0028E30C;
extern u8 g_slowdown_timer;
extern u16 D_0028E324;
extern u16 D_0028E328;
extern u16 D_0028E32C;
extern u8 D_0028E354;
extern u8 D_0028E368;
extern u8 g_paused;
extern u8 g_game_frame_ran;
extern u8 D_0028E374;
extern u8 D_0028E378;
extern u8 D_0028E37C;
extern s32 D_0028EAF8;
extern s32 D_0028EAFC;
extern u8 D_0028EC54;
extern s32 D_0028EC78;
extern u8 D_0028ED30;
extern u8 D_0028ED31;
extern u8 D_0028ED32;
extern u8 D_0028ED33;
extern u8 D_0028ED34;
extern u8 D_0028ED35;
extern u8 D_0028ED36;
extern u8 D_0028ED37;

void test_print_lines(void) {
    u32 saved_d0;

    saved_d0 = reg_d0.w;
    reg_d3.w = 0;
    reg_d2.w = 0;
    reg_d5.h[0] = reg_d0.h[0];
next_record:
    reg_d1.w = 0;
    reg_d0.w = 0;
    reg_d0.b[0] = *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d1.b[0] = *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_a0 += 1;
next_char:
    reg_d4.w = 0;
    reg_d4.b[0] = *(s8 *)reg_a0;
    reg_a0 += 1;
    if (reg_d4.b[0] == 0x7F) {
        goto next_record;
    }
    if ((s8) reg_d4.b[0] != -1) {
        reg_d4.h[0] &= 0xFF;
        reg_tmp4.h[0] = reg_d4.h[0];
        reg_d4.h[0] = reg_d5.h[0];
        reg_d4.h[1] = reg_tmp4.h[0];
        text_layer_put();
        reg_d0.h[0] += 1;
        goto next_char;
    }
    reg_d0.w = saved_d0;
}

void test_print_at(void) {
    u8 *saved_a0;
    u32 saved_d0;
    u32 saved_d1;
    u32 saved_d2;

    saved_d2 = reg_d2.w;
    saved_d0 = reg_d0.w;
    saved_d1 = reg_d1.w;
    saved_a0 = reg_a0;
    reg_d3.w = 0;
    reg_d5.h[0] = reg_d2.h[0];
    reg_d2.w = 0;
next_char:
    reg_d4.w = 0;
    reg_d4.sb[0] = *(s8 *)reg_a0;
    reg_a0 += 1;
    if (reg_d4.sb[0] == -1) goto done;
    reg_d4.h[0] = reg_d4.b[0];
    reg_tmp4.h[0] = reg_d4.h[0];
    reg_d4.h[0] = reg_d5.h[0];
    reg_d4.h[1] = reg_tmp4.h[0];
    text_layer_put();
    reg_d0.h[0] += 1;
    goto next_char;
done:
    reg_d0.w = saved_d0;
    reg_d1.w = saved_d1;
    reg_d2.w = saved_d2;
    reg_a0 = saved_a0;
}

void test_cursor_put(void) {
    s32 value = 0x200002;

    reg_d4.sw = value;
    value = 0;
    if ((s16)value <= (s16)reg_d2.sw) {
        reg_d4.sw = 0x3E0002;
    }
    reg_d3.sw = value;
    reg_d2.sw = 0;
    text_layer_put();
}

void test_screen_request() {
    g_test_screen_state = TEST_SCREEN_REQUESTED;
    g_test_screen = reg_d0.b[0];
}

#ifdef DEATH_LABEL
extern u8 g_twin_boss_bullets_halved;
extern u8 g_twin_boss_bullet_speed_limit;
#endif

void settings_reset(void) {
    g_setting_coin_mode = 0x12;
#ifndef DEATH_LABEL
    D_0028EC54 = 0;
#endif
    g_screen_wide = 0;
    D_0028E354 = 0;
    g_setting_continue = g_default_setting_continue[0];
    g_setting_demo_sound = g_default_setting_demo_sound[0];
    g_setting_chute_type = g_default_setting_chute_type[0];
    g_setting_difficulty = g_default_setting_difficulty[0];
    g_setting_extend = g_default_setting_extend[0];
    g_setting_ship_stock = g_default_setting_ship_stock[0];
    g_setting_rapid_fire = g_default_setting_rapid_fire[0];
    menu_game_option_defaults(g_default_setting_difficulty[0], g_default_setting_chute_type[0], g_default_setting_demo_sound[0], g_default_setting_continue[0]);
    menu_system_option_defaults();
    screen_setting_apply();
    D_0028E2D4 = 2;
    D_0028E2D0 = 3;
    g_p1_btn_map_a = 7;
    g_p2_btn_map_a = 7;
    g_p1_btn_map_b = 6;
    g_p2_btn_map_b = 6;
    g_p1_btn_map_c = 5;
    D_0028E273 = 1;
    g_p2_btn_map_c = 5;
    D_0028E32C = 5;
    D_0028E277 = 1;
    D_0028E37C = 1;
    D_0028E378 = 0xFF;
    D_0028E300 = 0xFF;
    D_0028E328 = 1;
    g_stage_map_enabled = 1;
    D_0028E264 = 1;
    D_0028E278 = 0;
    g_pad_vib_enabled = 0;
    D_0028E2D8 = 0;
    g_bgm_alternate_set = 0;
    g_simulation_boss_start = 0;
    D_0028E2C4 = 0;
    D_0028E2CC = 0;
    D_0028E2B0 = 0;
    D_0028E2AC = 0;
    D_0028E2A8 = 0;
    g_splash_visible = 0;
    g_game_frame_ran = 0;
    D_0028E374 = 0;
    g_paused = 0;
    D_0028E368 = 0;
    D_0028E324 = 0;
    D_0028E2EC = 0;
    D_0028E2E4 = 0;
    g_slowdown_timer = 0;
    g_display_offset_x = 0;
    g_display_offset_y = 0;
    g_pad_tate_rotate = 0;
    D_0028E30C = 0;
    D_0028E308 = 0;
    D_0028E304 = 0;
    D_0028E2FC = 0;
    D_0028E268 = 0;
    D_0028E260 = 0;
    D_0028E25C = 0;
    D_0028E258 = 0;
    D_0028EC78 = 0;
    D_0028E2A4 = 0;
    D_0028E29C = 0;
    D_0028E2A0 = 0;
    save_snapshot_take(5, 6, 7);
    stage_map_reset();
    menu_item_values_clear();
    D_0028ED30 = 0;
    D_0028E258 = 0xA;
    D_0028ED31 = 0;
    D_0028EAFC = 0xFF;
    D_0028ED32 = 0;
#ifdef DEATH_LABEL
    g_twin_boss_bullet_speed_limit = 0x2A;
#endif
    D_0028ED33 = 0;
#ifdef DEATH_LABEL
    g_twin_boss_bullets_halved = 1;
#endif
    D_0028ED34 = 0;
    D_0028ED35 = 0;
    D_0028ED36 = 0;
    D_0028ED37 = 0;
    g_pad_input_locked = 0;
    D_0028E294 = 0;
    D_0028E288 = 0;
    D_0028E284 = 0;
    D_0028EAF8 = 0;
}

void settings_validate(void) {
    reg_d0.b[0] = g_setting_coin_mode;
    if ((s8) reg_d0.b[0] > 0x12) goto out_of_range;
    if (0 > (s8) reg_d0.b[0]) goto out_of_range;
    reg_d0.b[0] = g_setting_continue;
    if ((s8) reg_d0.b[0] > 0x1) goto out_of_range;
    if (0 > (s8) reg_d0.b[0]) goto out_of_range;
    reg_d0.b[0] = g_setting_demo_sound;
    if ((s8) reg_d0.b[0] > 0x1) goto out_of_range;
    if (0 > (s8) reg_d0.b[0]) goto out_of_range;
    reg_d0.b[0] = g_setting_chute_type;
    if ((s8) reg_d0.b[0] > 0x2) goto out_of_range;
    if (0 > (s8) reg_d0.b[0]) goto out_of_range;
    reg_d0.b[0] = g_setting_difficulty;
    if ((s8) reg_d0.b[0] > 0x3) goto out_of_range;
    if (0 > (s8) reg_d0.b[0]) goto out_of_range;
    reg_d0.b[0] = g_setting_extend;
    if ((s8) reg_d0.b[0] > 0x3) goto out_of_range;
    if (0 > (s16) reg_d0.b[0]) goto out_of_range;
    reg_d0.b[0] = g_setting_ship_stock;
    if ((s8) reg_d0.b[0] > 0x4) goto out_of_range;
    if (0 > (s8) reg_d0.b[0]) goto out_of_range;
    reg_d0.b[0] = g_setting_rapid_fire;
    if ((s8) reg_d0.b[0] > 0x1) goto out_of_range;
    if (0 > (s8) reg_d0.b[0]) goto out_of_range;
    cond_flag = 0;
    return;
out_of_range:
    cond_flag = 1;
}
