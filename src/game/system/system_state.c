/* State every unit shares: the registers the arcade-derived code computes in, the frame counters, the build,
   test and option settings. Both executables keep it as one block, and its order follows no order of the
   code, so it is one object file's variables and not a run per unit; no unit of code owns it. */
#include "common.h"

/* .sbss (the compiler lays these out in reverse) */
#ifndef DEATH_LABEL
u16 D_0028E4B0;
#endif
s32 password_bits_unpack_state;
Reg32 reg_d0;
Reg32 reg_d1;
Reg32 reg_d2;
Reg32 reg_d3;
Reg32 reg_d4;
Reg32 reg_d5;
Reg32 reg_d6;
Reg32 reg_d7;
Reg32 reg_tmp;
Reg32 reg_tmp1;
Reg32 reg_tmp2;
Reg32 reg_tmp3;
Reg32 reg_tmp4;
Reg32 reg_tmp5;
Reg32 reg_tmp6;
Reg32 reg_tmp7;
u8 *reg_a0;
u8 *reg_a1;
u8 *reg_a2;
u8 *reg_a3;
u8 *reg_a4;
u8 *reg_a5;
u8 *reg_a6;
u8 *reg_atmp;
s16 *reg_save_atmp;
ArcadeSavedAddress reg_save_a0;
u8 *reg_save_a1;
u8 *reg_save_a2;
ArcadeSavedAddress reg_save_a3;
ArcadeSavedAddress reg_save_a4;
u8 *reg_save_a5;
u8 *reg_save_a6;
u32 reg_save_d0;
u32 reg_save_d1;
u32 reg_save_d2;
u32 reg_save_d3;
u32 reg_save_d4;
u32 reg_save_d5;
u32 reg_save_d6;
u32 reg_save_d7;
s8 cond_flag __attribute__((aligned(4)));
s8 enemy_move_end_requested __attribute__((aligned(4)));
u8 sys_init_state __attribute__((aligned(4)));
s16 g_loaded_stage __attribute__((aligned(4)));
s8 g_bomb_panel_seen;
void (*reg_call_target)();
u16 g_game_frame __attribute__((aligned(4)));
u16 g_frame_mod2 __attribute__((aligned(4)));
u16 g_frame_mod3 __attribute__((aligned(4)));
u16 g_frame_mod4 __attribute__((aligned(4)));
u16 g_frame_mod8 __attribute__((aligned(4)));
u16 g_frame_mod16 __attribute__((aligned(4)));
u16 rng_cursor __attribute__((aligned(4)));
s16 g_location_test_build __attribute__((aligned(4)));
s16 g_publicity_build __attribute__((aligned(4)));
s16 g_debug_build __attribute__((aligned(4)));
s16 g_test_switch_on __attribute__((aligned(4)));
s16 frame_counters_init_state __attribute__((aligned(4)));
u16 g_attract_demo __attribute__((aligned(4)));
u16 g_attract_demo_stage __attribute__((aligned(4)));
s16 g_test_mode_entered __attribute__((aligned(4)));
u16 g_select_screen_active __attribute__((aligned(4)));
s16 g_slowdown_forced_frames __attribute__((aligned(4)));
u16 g_slowdown_budget __attribute__((aligned(4)));
s16 g_slowdown_boss_allowed __attribute__((aligned(4)));
s16 g_slowdown_off __attribute__((aligned(4)));
s16 g_slowdown_loop2_allowed __attribute__((aligned(4)));
u8 g_setting_coin_mode __attribute__((aligned(4)));
u8 g_setting_continue __attribute__((aligned(4)));
u8 g_setting_demo_sound __attribute__((aligned(4)));
u8 g_setting_chute_type __attribute__((aligned(4)));
u8 g_setting_difficulty __attribute__((aligned(4)));
u8 g_setting_extend __attribute__((aligned(4)));
u8 g_setting_ship_stock __attribute__((aligned(4)));
u8 g_setting_rapid_fire __attribute__((aligned(4)));
u8 g_slowdown_setting __attribute__((aligned(4)));
u8 g_stage_jump_state __attribute__((aligned(4)));
u8 g_disc_notice_kind __attribute__((aligned(4)));
u8 g_game_frame_ran __attribute__((aligned(4)));
u8 g_paused __attribute__((aligned(4)));
u8 g_replay_file_finalized __attribute__((aligned(4)));
u8 g_pause_lock_timer __attribute__((aligned(4)));
u8 g_pad_vib_state_p1 __attribute__((aligned(4)));
u8 g_pad_vib_state_p2 __attribute__((aligned(4)));
u8 g_setting_screen_mode __attribute__((aligned(4)));
u8 g_setting_screen_variant __attribute__((aligned(4)));
u8 g_stage_load_state __attribute__((aligned(4)));
u16 g_pad_vib_timer_p1 __attribute__((aligned(4)));
u16 g_pad_vib_timer_p2 __attribute__((aligned(4)));
u16 g_pad_vib_power_p1 __attribute__((aligned(4)));
u16 g_pad_vib_power_p2 __attribute__((aligned(4)));
u16 g_pad_vib_saved_timer_p1 __attribute__((aligned(4)));
u16 g_pad_vib_saved_timer_p2 __attribute__((aligned(4)));
u16 g_pad_vib_saved_power_p1 __attribute__((aligned(4)));
u16 g_pad_vib_saved_power_p2 __attribute__((aligned(4)));
u16 g_setting_wallpaper __attribute__((aligned(4)));
u16 g_pause_stage_choice __attribute__((aligned(4)));
u16 g_pause_loop_choice __attribute__((aligned(4)));
s16 g_menu_idle_timer __attribute__((aligned(4)));
u16 g_pause_player __attribute__((aligned(4)));
u16 g_p1_continue_count __attribute__((aligned(4)));
u16 g_p2_continue_count __attribute__((aligned(4)));
u8 g_slowdown_timer __attribute__((aligned(4)));
u8 g_setting_hitbox_display __attribute__((aligned(4)));
u8 g_setting_hitbox_bullets_shown __attribute__((aligned(4)));
u8 g_setting_start_round __attribute__((aligned(4)));
u16 g_unlocked_options __attribute__((aligned(4)));
u16 g_unlocked_options_shown __attribute__((aligned(4)));
u8 g_pad_tate_rotate __attribute__((aligned(4)));
u8 g_splash_visible __attribute__((aligned(4)));
u8 g_stage_map_active __attribute__((aligned(4)));
u8 g_setting_loop_count __attribute__((aligned(4)));
u16 g_stage5_boss_all_forms __attribute__((aligned(4)));
u8 g_no_enemy_bullets __attribute__((aligned(4)));
u8 g_bgm_alternate_set __attribute__((aligned(4)));
u8 g_screen_wide __attribute__((aligned(4)));
u8 g_setting_replay_save __attribute__((aligned(4)));
u8 g_start_rule_rank __attribute__((aligned(4)));
u8 settings_reset_state_4 __attribute__((aligned(4)));
u8 settings_reset_state_3 __attribute__((aligned(4)));
u8 g_simulation_boss_start __attribute__((aligned(4)));
u8 g_start_rule_death __attribute__((aligned(4)));
u8 g_ground_no_draw;
u8 g_session_date[8];
u8 D_0028E2B0 __attribute__((aligned(4)));
u16 g_start_hyper_gauge __attribute__((aligned(4)));
u8 D_0028E2A8 __attribute__((aligned(4)));
u8 g_stage_clear_wait_timer __attribute__((aligned(4)));
u8 g_replay_save_asked __attribute__((aligned(4)));
u16 g_stage_clear_color_index __attribute__((aligned(4)));
u8 g_pad_input_locked __attribute__((aligned(4)));
u8 g_ranking_opened_from_menu __attribute__((aligned(4)));
u8 g_game_mode __attribute__((aligned(4)));
u8 g_stage_map_enabled __attribute__((aligned(4)));
u8 g_p1_stage_start_timer __attribute__((aligned(4)));
u8 g_p2_stage_start_timer __attribute__((aligned(4)));
#ifdef DEATH_LABEL
u8 g_death_boss_form __attribute__((aligned(4)));
u8 g_twin_boss_bullet_speed_limit __attribute__((aligned(4)));
u8 g_twin_boss_bullets_halved __attribute__((aligned(4)));
u8 death_D_00290850 __attribute__((aligned(4)));
#endif
#ifndef DEATH_LABEL
u8 g_stage_select_choice __attribute__((aligned(4)));
#endif
u8 g_pad_vib_enabled __attribute__((aligned(4)));
u8 g_setting_autosave;
#ifdef DDPDOJ_PC
u8 pc_button_mappings[2][4];
#else
u8 g_p2_btn_map_d;
u8 g_p2_btn_map_c;
u8 g_p2_btn_map_b;
u8 g_p2_btn_map_a;
u8 g_p1_btn_map_d;
u8 g_p1_btn_map_c;
u8 g_p1_btn_map_b;
u8 g_p1_btn_map_a __attribute__((aligned(8)));
#endif
u8 g_mc_frame_visible __attribute__((aligned(4)));
u8 settings_reset_state_2 __attribute__((aligned(4)));
u8 settings_reset_state __attribute__((aligned(4)));
u8 g_session_stage_reached __attribute__((aligned(4)));
u8 g_stage_select_unlocked __attribute__((aligned(4)));
s8 g_display_offset_x __attribute__((aligned(4)));
s8 g_display_offset_y;
s8 pad_mask_game_inputs_buffer[4];
s8 g_arcade_input_port[4] __attribute__((aligned(8)));
s16 scroll_shadow_reset_state_2 __attribute__((aligned(4)));
s16 scroll_shadow_reset_state __attribute__((aligned(4)));
s16 g_bg_scroll_x __attribute__((aligned(4)));
s16 g_bg_scroll_y __attribute__((aligned(4)));
u16 g_arcade_zoom_port __attribute__((aligned(4)));
s16 test_switch_read_state __attribute__((aligned(4)));
u16 g_arcade_coin_port __attribute__((aligned(4)));
u16 coin_inputs_update_state __attribute__((aligned(4)));
u16 g_display_control __attribute__((aligned(4)));
u8 g_slowdown_frame_state __attribute__((aligned(4)));
u8 slowdown_init_state __attribute__((aligned(4)));
s16 coin_init_state __attribute__((aligned(4)));
u8 D_0028E210 __attribute__((aligned(4)));
u8 D_0028E20C __attribute__((aligned(4)));
u8 D_0028E208 __attribute__((aligned(4)));
u8 D_0028E204 __attribute__((aligned(4)));
s8 D_0028E200 __attribute__((aligned(4)));
s8 D_0028E1FC __attribute__((aligned(4)));
u16 D_0028E1F8 __attribute__((aligned(4)));
u16 D_0028E1F4 __attribute__((aligned(4)));
u16 D_0028E1F0 __attribute__((aligned(4)));
u8 D_0028E1EC __attribute__((aligned(4)));
u8 D_0028E1E8;
u8 g_credit_display_last[4];
u8 D_0028E1E0 __attribute__((aligned(4)));
u8 D_0028E1DC;
u8 g_coin_counts[4];
u8 D_0028E1D4 __attribute__((aligned(4)));
u8 D_0028E1D0;
#ifdef DDPDOJ_PC
u8 D_0028E1C8[8];
u8 D_0028E1C0[8];
#else
u16 coin_slots_take_buffer_2[2];
u8 D_0028E1C8[4];
u16 coin_slots_take_buffer[2];
u8 D_0028E1C0[4];
#endif
s32 D_0028E1BC;

#ifdef DDPDOJ_PC
#include "pc_data_alias.h"

PC_DATA_ALIAS(g_p1_btn_map_a, pc_button_mappings, 0);
PC_DATA_ALIAS(g_p1_btn_map_b, pc_button_mappings, 1);
PC_DATA_ALIAS(g_p1_btn_map_c, pc_button_mappings, 2);
PC_DATA_ALIAS(g_p1_btn_map_d, pc_button_mappings, 3);
PC_DATA_ALIAS(g_p2_btn_map_a, pc_button_mappings, 4);
PC_DATA_ALIAS(g_p2_btn_map_b, pc_button_mappings, 5);
PC_DATA_ALIAS(g_p2_btn_map_c, pc_button_mappings, 6);
PC_DATA_ALIAS(g_p2_btn_map_d, pc_button_mappings, 7);

PC_DATA_ALIAS(D_0028E1D9, g_coin_counts, 0x1);
PC_DATA_ALIAS(D_0028E1DA, g_coin_counts, 0x2);

PC_DATA_ALIAS(D_0028E1E5, g_credit_display_last, 0x1);
PC_DATA_ALIAS(g_credit_display_last_coins, g_credit_display_last, 0x2);

PC_DATA_ALIAS(coin_slots_take_buffer_2, D_0028E1C8, 0x4);
PC_DATA_ALIAS(coin_slots_take_buffer, D_0028E1C0, 0x4);

PC_DATA_ALIAS(g_session_date_1, g_session_date, 0x1);
PC_DATA_ALIAS(g_session_date_2, g_session_date, 0x2);
PC_DATA_ALIAS(g_session_date_3, g_session_date, 0x3);
PC_DATA_ALIAS(g_session_date_4, g_session_date, 0x4);
PC_DATA_ALIAS(g_session_date_5, g_session_date, 0x5);
PC_DATA_ALIAS(g_session_date_6, g_session_date, 0x6);
PC_DATA_ALIAS(g_session_date_7, g_session_date, 0x7);

PC_DATA_ALIAS(D_0028E249, g_arcade_input_port, 0x1);
PC_DATA_ALIAS(D_0028E24A, g_arcade_input_port, 0x2);
PC_DATA_ALIAS(D_0028E24B, g_arcade_input_port, 0x3);
PC_DATA_ALIAS(D_0028E24D, pad_mask_game_inputs_buffer, 0x1);
PC_DATA_ALIAS(D_0028E24E, pad_mask_game_inputs_buffer, 0x2);
PC_DATA_ALIAS(D_0028E24F, pad_mask_game_inputs_buffer, 0x3);
PC_DATA_ALIAS(reg_a0_as_s8_p, reg_a0, 0x0);
PC_DATA_ALIAS(reg_a4_as_u16_p, reg_a4, 0x0);
PC_DATA_ALIAS(reg_call_target_as_fn, reg_call_target, 0x0);
PC_DATA_ALIAS(reg_call_target_as_u8_p, reg_call_target, 0x0);
#endif

#ifdef DDPDOJ_PC
#include "pc_frame_regions.h"

const PcFrameRegion pc_system_regions[] = {
#ifndef DEATH_LABEL
    PC_FRAME_REGION(D_0028E4B0),
#endif
    PC_FRAME_REGION(password_bits_unpack_state),
    PC_FRAME_REGION(reg_d0),
    PC_FRAME_REGION(reg_d1),
    PC_FRAME_REGION(reg_d2),
    PC_FRAME_REGION(reg_d3),
    PC_FRAME_REGION(reg_d4),
    PC_FRAME_REGION(reg_d5),
    PC_FRAME_REGION(reg_d6),
    PC_FRAME_REGION(reg_d7),
    PC_FRAME_REGION(reg_tmp),
    PC_FRAME_REGION(reg_tmp1),
    PC_FRAME_REGION(reg_tmp2),
    PC_FRAME_REGION(reg_tmp3),
    PC_FRAME_REGION(reg_tmp4),
    PC_FRAME_REGION(reg_tmp5),
    PC_FRAME_REGION(reg_tmp6),
    PC_FRAME_REGION(reg_tmp7),
    PC_FRAME_REGION(reg_save_d0),
    PC_FRAME_REGION(reg_save_d1),
    PC_FRAME_REGION(reg_save_d2),
    PC_FRAME_REGION(reg_save_d3),
    PC_FRAME_REGION(reg_save_d4),
    PC_FRAME_REGION(reg_save_d5),
    PC_FRAME_REGION(reg_save_d6),
    PC_FRAME_REGION(reg_save_d7),
    PC_FRAME_REGION(cond_flag),
    PC_FRAME_REGION(enemy_move_end_requested),
    PC_FRAME_REGION(sys_init_state),
    PC_FRAME_REGION(g_loaded_stage),
    PC_FRAME_REGION(g_bomb_panel_seen),
    PC_FRAME_REGION(g_game_frame),
    PC_FRAME_REGION(g_frame_mod2),
    PC_FRAME_REGION(g_frame_mod3),
    PC_FRAME_REGION(g_frame_mod4),
    PC_FRAME_REGION(g_frame_mod8),
    PC_FRAME_REGION(g_frame_mod16),
    PC_FRAME_REGION(rng_cursor),
    PC_FRAME_REGION(g_location_test_build),
    PC_FRAME_REGION(g_publicity_build),
    PC_FRAME_REGION(g_debug_build),
    PC_FRAME_REGION(g_test_switch_on),
    PC_FRAME_REGION(frame_counters_init_state),
    PC_FRAME_REGION(g_attract_demo),
    PC_FRAME_REGION(g_attract_demo_stage),
    PC_FRAME_REGION(g_test_mode_entered),
    PC_FRAME_REGION(g_select_screen_active),
    PC_FRAME_REGION(g_slowdown_forced_frames),
    PC_FRAME_REGION(g_slowdown_budget),
    PC_FRAME_REGION(g_slowdown_boss_allowed),
    PC_FRAME_REGION(g_slowdown_off),
    PC_FRAME_REGION(g_slowdown_loop2_allowed),
    PC_FRAME_REGION(g_setting_coin_mode),
    PC_FRAME_REGION(g_setting_continue),
    PC_FRAME_REGION(g_setting_demo_sound),
    PC_FRAME_REGION(g_setting_chute_type),
    PC_FRAME_REGION(g_setting_difficulty),
    PC_FRAME_REGION(g_setting_extend),
    PC_FRAME_REGION(g_setting_ship_stock),
    PC_FRAME_REGION(g_setting_rapid_fire),
    PC_FRAME_REGION(g_slowdown_setting),
    PC_FRAME_REGION(g_stage_jump_state),
    PC_FRAME_REGION(g_disc_notice_kind),
    PC_FRAME_REGION(g_game_frame_ran),
    PC_FRAME_REGION(g_paused),
    PC_FRAME_REGION(g_replay_file_finalized),
    PC_FRAME_REGION(g_pause_lock_timer),
    PC_FRAME_REGION(g_pad_vib_state_p1),
    PC_FRAME_REGION(g_pad_vib_state_p2),
    PC_FRAME_REGION(g_setting_screen_mode),
    PC_FRAME_REGION(g_setting_screen_variant),
    PC_FRAME_REGION(g_stage_load_state),
    PC_FRAME_REGION(g_pad_vib_timer_p1),
    PC_FRAME_REGION(g_pad_vib_timer_p2),
    PC_FRAME_REGION(g_pad_vib_power_p1),
    PC_FRAME_REGION(g_pad_vib_power_p2),
    PC_FRAME_REGION(g_pad_vib_saved_timer_p1),
    PC_FRAME_REGION(g_pad_vib_saved_timer_p2),
    PC_FRAME_REGION(g_pad_vib_saved_power_p1),
    PC_FRAME_REGION(g_pad_vib_saved_power_p2),
    PC_FRAME_REGION(g_setting_wallpaper),
    PC_FRAME_REGION(g_pause_stage_choice),
    PC_FRAME_REGION(g_pause_loop_choice),
    PC_FRAME_REGION(g_menu_idle_timer),
    PC_FRAME_REGION(g_pause_player),
    PC_FRAME_REGION(g_p1_continue_count),
    PC_FRAME_REGION(g_p2_continue_count),
    PC_FRAME_REGION(g_slowdown_timer),
    PC_FRAME_REGION(g_setting_hitbox_display),
    PC_FRAME_REGION(g_setting_hitbox_bullets_shown),
    PC_FRAME_REGION(g_setting_start_round),
    PC_FRAME_REGION(g_unlocked_options),
    PC_FRAME_REGION(g_unlocked_options_shown),
    PC_FRAME_REGION(g_pad_tate_rotate),
    PC_FRAME_REGION(g_splash_visible),
    PC_FRAME_REGION(g_stage_map_active),
    PC_FRAME_REGION(g_setting_loop_count),
    PC_FRAME_REGION(g_stage5_boss_all_forms),
    PC_FRAME_REGION(g_no_enemy_bullets),
    PC_FRAME_REGION(g_bgm_alternate_set),
    PC_FRAME_REGION(g_screen_wide),
    PC_FRAME_REGION(g_setting_replay_save),
    PC_FRAME_REGION(g_start_rule_rank),
    PC_FRAME_REGION(settings_reset_state_4),
    PC_FRAME_REGION(settings_reset_state_3),
    PC_FRAME_REGION(g_simulation_boss_start),
    PC_FRAME_REGION(g_start_rule_death),
    PC_FRAME_REGION(g_ground_no_draw),
    PC_FRAME_REGION(g_session_date),
    PC_FRAME_REGION(D_0028E2B0),
    PC_FRAME_REGION(g_start_hyper_gauge),
    PC_FRAME_REGION(D_0028E2A8),
    PC_FRAME_REGION(g_stage_clear_wait_timer),
    PC_FRAME_REGION(g_replay_save_asked),
    PC_FRAME_REGION(g_stage_clear_color_index),
    PC_FRAME_REGION(g_pad_input_locked),
    PC_FRAME_REGION(g_ranking_opened_from_menu),
    PC_FRAME_REGION(g_game_mode),
    PC_FRAME_REGION(g_stage_map_enabled),
    PC_FRAME_REGION(g_p1_stage_start_timer),
    PC_FRAME_REGION(g_p2_stage_start_timer),
#ifndef DEATH_LABEL
    PC_FRAME_REGION(g_stage_select_choice),
#endif
    PC_FRAME_REGION(g_pad_vib_enabled),
    PC_FRAME_REGION(g_setting_autosave),
    PC_FRAME_REGION(pc_button_mappings),
    PC_FRAME_REGION(g_mc_frame_visible),
    PC_FRAME_REGION(settings_reset_state_2),
    PC_FRAME_REGION(settings_reset_state),
    PC_FRAME_REGION(g_session_stage_reached),
    PC_FRAME_REGION(g_stage_select_unlocked),
    PC_FRAME_REGION(g_display_offset_x),
    PC_FRAME_REGION(g_display_offset_y),
    PC_FRAME_REGION(pad_mask_game_inputs_buffer),
    PC_FRAME_REGION(g_arcade_input_port),
    PC_FRAME_REGION(scroll_shadow_reset_state_2),
    PC_FRAME_REGION(scroll_shadow_reset_state),
    PC_FRAME_REGION(g_bg_scroll_x),
    PC_FRAME_REGION(g_bg_scroll_y),
    PC_FRAME_REGION(g_arcade_zoom_port),
    PC_FRAME_REGION(test_switch_read_state),
    PC_FRAME_REGION(g_arcade_coin_port),
    PC_FRAME_REGION(coin_inputs_update_state),
    PC_FRAME_REGION(g_display_control),
    PC_FRAME_REGION(g_slowdown_frame_state),
    PC_FRAME_REGION(slowdown_init_state),
    PC_FRAME_REGION(coin_init_state),
    PC_FRAME_REGION(D_0028E210),
    PC_FRAME_REGION(D_0028E20C),
    PC_FRAME_REGION(D_0028E208),
    PC_FRAME_REGION(D_0028E204),
    PC_FRAME_REGION(D_0028E200),
    PC_FRAME_REGION(D_0028E1FC),
    PC_FRAME_REGION(D_0028E1F8),
    PC_FRAME_REGION(D_0028E1F4),
    PC_FRAME_REGION(D_0028E1F0),
    PC_FRAME_REGION(D_0028E1EC),
    PC_FRAME_REGION(D_0028E1E8),
    PC_FRAME_REGION(g_credit_display_last),
    PC_FRAME_REGION(D_0028E1E0),
    PC_FRAME_REGION(D_0028E1DC),
    PC_FRAME_REGION(g_coin_counts),
    PC_FRAME_REGION(D_0028E1D4),
    PC_FRAME_REGION(D_0028E1D0),
    { D_0028E1C8 + 4, 4, false },
    { D_0028E1C8, 4, false },
    { D_0028E1C0 + 4, 4, false },
    { D_0028E1C0, 4, false },
    PC_FRAME_REGION(D_0028E1BC),
#ifdef DEATH_LABEL
    PC_FRAME_REGION(g_death_boss_form),
#endif
#ifdef DEATH_LABEL
    PC_FRAME_REGION(g_twin_boss_bullet_speed_limit),
#endif
#ifdef DEATH_LABEL
    PC_FRAME_REGION(g_twin_boss_bullets_halved),
#endif
#ifdef DEATH_LABEL
    PC_FRAME_REGION(death_D_00290850),
#endif
    { NULL, 0 },
};
#endif
