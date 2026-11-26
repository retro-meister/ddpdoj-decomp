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
extern u8 g_stage_select_unlocked;
extern u8 g_session_stage_reached;
extern u8 settings_reset_state;
extern u8 settings_reset_state_2;
extern u8 g_mc_frame_visible;
extern u8 g_p1_btn_map_a;
extern u8 g_p1_btn_map_b;
extern u8 g_p1_btn_map_c;
extern u8 g_p1_btn_map_d;
extern u8 g_p2_btn_map_a;
extern u8 g_p2_btn_map_b;
extern u8 g_p2_btn_map_c;
extern u8 g_p2_btn_map_d;
extern u8 g_setting_autosave;
extern u8 g_pad_vib_enabled;
extern u8 g_p2_stage_start_timer;
extern u8 g_p1_stage_start_timer;
extern u8 g_stage_map_enabled;
extern u8 g_ranking_opened_from_menu;
extern u8 g_pad_input_locked;
extern u16 g_stage_clear_color_index;
extern u8 g_replay_save_asked;
extern u8 g_stage_clear_wait_timer;
extern u8 D_0028E2A8;
extern u16 g_start_hyper_gauge;
extern u8 D_0028E2B0;
extern u8 g_start_rule_death;
extern u8 g_simulation_boss_start;
extern u8 settings_reset_state_3;
extern u8 settings_reset_state_4;
extern u8 g_start_rule_rank;
extern u8 g_setting_replay_save;
extern u8 g_screen_wide;
extern u8 g_bgm_alternate_set;
extern u8 g_no_enemy_bullets;
extern u8 g_setting_loop_count;
extern u8 g_splash_visible;
extern u8 g_pad_tate_rotate;
extern u16 g_unlocked_options_shown;
extern u16 g_unlocked_options;
extern u8 g_setting_start_round;
extern u8 g_setting_hitbox_bullets_shown;
extern u8 g_setting_hitbox_display;
extern u8 g_slowdown_timer;
extern u16 g_pause_loop_choice;
extern u16 g_pause_stage_choice;
extern u16 g_setting_wallpaper;
extern u8 g_setting_screen_variant;
extern u8 g_replay_file_finalized;
extern u8 g_paused;
extern u8 g_game_frame_ran;
extern u8 g_disc_notice_kind;
extern u8 g_stage_jump_state;
extern u8 g_slowdown_setting;
extern s32 g_menu_notice_step;
extern s32 g_ranking_entry_index;
extern u8 settings_reset_state_5;
extern s32 g_autosave_unread_flag;
extern u8 g_loaded_replay_id_0;
extern u8 g_loaded_replay_id_1;
extern u8 g_loaded_replay_id_2;
extern u8 g_loaded_replay_id_3;
extern u8 g_loaded_replay_id_4;
extern u8 g_loaded_replay_id_5;
extern u8 g_loaded_replay_id_6;
extern u8 g_loaded_replay_id_7;

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
    settings_reset_state_5 = 0;
#endif
    g_screen_wide = 0;
    g_setting_screen_variant = 0;
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
    g_start_rule_rank = 2;
    settings_reset_state_4 = 3;
    g_p1_btn_map_a = 7;
    g_p2_btn_map_a = 7;
    g_p1_btn_map_b = 6;
    g_p2_btn_map_b = 6;
    g_p1_btn_map_c = 5;
    g_p1_btn_map_d = 1;
    g_p2_btn_map_c = 5;
    g_setting_wallpaper = 5;
    g_p2_btn_map_d = 1;
    g_slowdown_setting = 1;
    g_stage_jump_state = 0xFF;
    g_unlocked_options = 0xFF;
    g_pause_stage_choice = 1;
    g_stage_map_enabled = 1;
    settings_reset_state_2 = 1;
    g_setting_autosave = 0;
    g_pad_vib_enabled = 0;
    g_setting_replay_save = 0;
    g_bgm_alternate_set = 0;
    g_simulation_boss_start = 0;
    g_start_rule_death = 0;
    settings_reset_state_3 = 0;
    D_0028E2B0 = 0;
    g_start_hyper_gauge = 0;
    D_0028E2A8 = 0;
    g_splash_visible = 0;
    g_game_frame_ran = 0;
    g_disc_notice_kind = 0;
    g_paused = 0;
    g_replay_file_finalized = 0;
    g_pause_loop_choice = 0;
    g_setting_loop_count = 0;
    g_no_enemy_bullets = 0;
    g_slowdown_timer = 0;
    g_display_offset_x = 0;
    g_display_offset_y = 0;
    g_pad_tate_rotate = 0;
    g_setting_hitbox_display = 0;
    g_setting_hitbox_bullets_shown = 0;
    g_setting_start_round = 0;
    g_unlocked_options_shown = 0;
    g_mc_frame_visible = 0;
    settings_reset_state = 0;
    g_session_stage_reached = 0;
    g_stage_select_unlocked = 0;
    g_autosave_unread_flag = 0;
    g_stage_clear_wait_timer = 0;
    g_stage_clear_color_index = 0;
    g_replay_save_asked = 0;
    save_snapshot_take(5, 6, 7);
    stage_map_reset();
    menu_item_values_clear();
    g_loaded_replay_id_0 = 0;
    g_stage_select_unlocked = 0xA;
    g_loaded_replay_id_1 = 0;
    g_ranking_entry_index = 0xFF;
    g_loaded_replay_id_2 = 0;
#ifdef DEATH_LABEL
    g_twin_boss_bullet_speed_limit = 0x2A;
#endif
    g_loaded_replay_id_3 = 0;
#ifdef DEATH_LABEL
    g_twin_boss_bullets_halved = 1;
#endif
    g_loaded_replay_id_4 = 0;
    g_loaded_replay_id_5 = 0;
    g_loaded_replay_id_6 = 0;
    g_loaded_replay_id_7 = 0;
    g_pad_input_locked = 0;
    g_ranking_opened_from_menu = 0;
    g_p1_stage_start_timer = 0;
    g_p2_stage_start_timer = 0;
    g_menu_notice_step = 0;
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
