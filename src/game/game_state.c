/* Global variables of the game unit. They lie in a block apart from the unit's own, and one object file can
   place only one block of a section in our link, so they are defined here. */
#include "common.h"

/* .sbss (the compiler lays these out in reverse) */
u16 g_game_flow_scroll_line __attribute__((aligned(4)));
u16 g_player_start_request __attribute__((aligned(4)));
u16 g_game_flow_paused __attribute__((aligned(4)));
u16 g_p1_ship_type __attribute__((aligned(4)));
u16 g_p2_ship_type __attribute__((aligned(4)));
u16 g_p1_power_style __attribute__((aligned(4)));
u16 g_p2_power_style __attribute__((aligned(4)));
u16 g_two_player_game __attribute__((aligned(4)));
u16 g_two_player_state __attribute__((aligned(4)));
u16 g_two_player_seen __attribute__((aligned(4)));
u16 g_stage __attribute__((aligned(4)));
u16 g_stage_x2 __attribute__((aligned(4)));
u16 g_stage_x4 __attribute__((aligned(4)));
u16 g_loop __attribute__((aligned(4)));
u16 g_game_completed __attribute__((aligned(4)));
u16 g_true_last_boss __attribute__((aligned(4)));
u16 g_rank __attribute__((aligned(4)));
u16 g_rank_15_16 __attribute__((aligned(4)));
u16 g_rank_14_16 __attribute__((aligned(4)));
u16 g_rank_13_16 __attribute__((aligned(4)));
u16 g_rank_12_16 __attribute__((aligned(4)));
u16 g_rank_11_16 __attribute__((aligned(4)));
u16 g_rank_10_16 __attribute__((aligned(4)));
u16 g_rank_9_16 __attribute__((aligned(4)));
u16 g_rank_8_16 __attribute__((aligned(4)));
u16 g_rank_7_16 __attribute__((aligned(4)));
u16 g_rank_6_16 __attribute__((aligned(4)));
u16 g_rank_5_16 __attribute__((aligned(4)));
u16 g_rank_4_16 __attribute__((aligned(4)));
u16 g_rank_3_16 __attribute__((aligned(4)));
u16 g_rank_2_16 __attribute__((aligned(4)));
u16 g_rank_1_16 __attribute__((aligned(4)));
u16 g_p1_lives __attribute__((aligned(4)));
u16 g_p2_lives;
s32 g_play_time;
u16 g_damage_blink_counter __attribute__((aligned(4)));
u8 g_name_entry_player __attribute__((aligned(4)));
u8 g_name_entry_player_pad __attribute__((aligned(4)));
u16 g_scroll_line_offset __attribute__((aligned(4)));
u16 g_scroll_line __attribute__((aligned(4)));
u16 g_scroll_line_step __attribute__((aligned(4)));
u16 g_enemies_stopped __attribute__((aligned(4)));
u16 g_bullets_blocked __attribute__((aligned(4)));
u16 g_stopped_and_blocked __attribute__((aligned(4)));
u16 g_enemy_signal_0 __attribute__((aligned(4)));
u16 g_enemy_signal_1 __attribute__((aligned(4)));
u16 g_enemy_signal_2 __attribute__((aligned(4)));
u16 g_enemy_signal_3 __attribute__((aligned(4)));
u16 g_enemy_signal_4 __attribute__((aligned(4)));
u16 g_enemy_signal_5 __attribute__((aligned(4)));
u16 g_enemy_signal_6 __attribute__((aligned(4)));
u16 g_enemy_signal_7 __attribute__((aligned(4)));
u16 g_enemy_signal_8 __attribute__((aligned(4)));
u16 g_enemy_signal_9 __attribute__((aligned(4)));
u16 g_enemy_signal_a __attribute__((aligned(4)));
u16 g_enemy_signal_b __attribute__((aligned(4)));
u16 g_enemy_signal_c __attribute__((aligned(4)));
u16 g_enemy_signal_d __attribute__((aligned(4)));
u16 g_enemy_signal_e __attribute__((aligned(4)));
u16 g_enemy_signal_f __attribute__((aligned(4)));
u8 g_boss_present_b1;
u8 g_boss_present __attribute__((aligned(4)));
u16 g_continue_pending_count;
s32 g_ground_task_handle;
s32 g_misc_task_handle;
s32 g_gauge_task_handle;
s32 g_player_panel1_task_handle;
s32 g_player_panel2_task_handle;

/* .bss (the compiler lays these out in reverse) */
u8 D_002BF390[80];
