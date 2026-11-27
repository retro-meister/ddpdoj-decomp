/* Global variables of the scoring unit. They lie in a block apart from the unit's own, and one object file can
   place only one block of a section in our link, so they are defined here. */
#include "common.h"

/* .sbss (the compiler lays these out in reverse) */
u32 g_p1_score;
u32 g_p2_score;
s32 g_high_score;
u16 g_p1_score_billions __attribute__((aligned(4)));
u16 g_p2_score_billions __attribute__((aligned(4)));
u16 g_high_score_billions __attribute__((aligned(4)));
u16 g_p1_score_digits __attribute__((aligned(4)));
u16 g_high_score_digits __attribute__((aligned(4)));
u16 g_p2_score_digits;
u32 g_p1_score_saved;
u32 g_p2_score_saved;
u16 g_p1_score_billions_saved __attribute__((aligned(4)));
u16 g_p2_score_billions_saved;
s32 g_p1_extend_score;
s32 g_p2_extend_score;
u16 g_p1_extend_setting __attribute__((aligned(4)));
u16 g_p2_extend_setting;
s32 g_p1_extend_table;
u8 g_p2_extend_table;
s32 g_p1_score_pending;
s32 g_p2_score_pending;
s32 g_score_check_scratch;
u16 g_score_check_billions __attribute__((aligned(4)));
u8 g_p1_score_panel_flags __attribute__((aligned(4)));
u8 g_p2_score_panel_flags __attribute__((aligned(4)));
u16 g_hyper_text_anim_delay __attribute__((aligned(4)));
u16 g_hyper_text_anim_frame;
s32 g_hyper_text_anim_sprite;
u16 g_maximum_text_anim_delay __attribute__((aligned(4)));
u16 g_maximum_text_anim_frame;
s32 g_maximum_text_anim_sprite;
u16 g_max_level_display_timer;
s32 g_score_scratch;
u16 g_p1_combo_at_bomb __attribute__((aligned(4)));
u16 g_p2_combo_at_bomb __attribute__((aligned(4)));
u16 g_max_combo_time __attribute__((aligned(4)));
u16 g_boss_hit_carry __attribute__((aligned(4)));
u16 g_score_player_flag;
s32 g_p1_chain_first_score;
s32 g_p1_chain_first_score_shown;
u16 g_p1_combo_timer __attribute__((aligned(4)));
s16 g_p1_chain_points_display_timer __attribute__((aligned(4)));
u16 g_p1_hit_display_timer __attribute__((aligned(4)));
u16 g_p1_combo_break_color_timer __attribute__((aligned(4)));
s16 g_p1_hit10_display_timer __attribute__((aligned(4)));
u16 g_p1_hit10_color_timer __attribute__((aligned(4)));
u16 g_p1_hit10_anim_count;
s32 g_p1_chain_points;
s32 g_p1_chain_points_shown;
s32 g_p1_chain_points_shown2;
u16 g_p1_hits __attribute__((aligned(4)));
u16 g_p1_hits_shown __attribute__((aligned(4)));
u16 g_p1_laser_hit_timer __attribute__((aligned(4)));
u16 g_p1_laser_hit_step;
s32 g_p2_chain_first_score;
s32 g_p2_chain_first_score_shown;
u16 g_p2_combo_timer __attribute__((aligned(4)));
s16 g_p2_chain_points_display_timer __attribute__((aligned(4)));
u16 g_p2_hit_display_timer __attribute__((aligned(4)));
u16 g_p2_combo_break_color_timer __attribute__((aligned(4)));
s16 g_p2_hit10_display_timer __attribute__((aligned(4)));
u16 g_p2_hit10_color_timer __attribute__((aligned(4)));
u16 g_p2_hit10_anim_count;
s32 g_p2_chain_points;
s32 g_p2_chain_points_shown;
s32 g_p2_chain_points_shown2;
u16 g_p2_hits __attribute__((aligned(4)));
u16 g_p2_hits_shown __attribute__((aligned(4)));
u16 g_p2_laser_hit_timer __attribute__((aligned(4)));
u16 g_p2_laser_hit_step __attribute__((aligned(4)));
u16 g_boss_hit_decay_timer __attribute__((aligned(4)));
u16 g_boss_hit_anim_count __attribute__((aligned(4)));
u16 g_boss_hits __attribute__((aligned(4)));
s16 g_boss_hit_palette __attribute__((aligned(4)));
u16 g_boss_hit_bonus_timer;
s32 g_boss_hit_bonus;
s32 g_boss_score;
#ifdef DDPDOJ_PC
u16 pc_boss_bar_flags;
#else
u8 g_boss_bar_flags;
s8 g_boss_hp_bar_flags __attribute__((aligned(4)));
#endif
u16 g_boss_hp_bar_move_count __attribute__((aligned(4)));
u16 g_lives_display_move_y __attribute__((aligned(4)));
u16 g_lives_display_move_x;
s32 g_boss_hp_unit;
u8 *g_boss_hp;
u16 g_boss_near_death __attribute__((aligned(4)));
u16 g_boss_explosion_flash __attribute__((aligned(4)));
u16 g_p1_max_hits __attribute__((aligned(4)));
u16 g_p2_max_hits __attribute__((aligned(4)));
u16 g_p1_laser_hyper_timer __attribute__((aligned(4)));
u16 g_p2_laser_hyper_timer __attribute__((aligned(4)));
u16 g_p1_shot_hyper_timer __attribute__((aligned(4)));
u16 g_p2_shot_hyper_timer __attribute__((aligned(4)));
u16 g_p1_hyper_active __attribute__((aligned(4)));
u16 g_p2_hyper_active __attribute__((aligned(4)));
u16 g_p1_hyper_time __attribute__((aligned(4)));
u16 g_p2_hyper_time __attribute__((aligned(4)));
u16 g_p1_hyper_total __attribute__((aligned(4)));
u16 g_p2_hyper_total __attribute__((aligned(4)));
u16 g_p1_hyper_gauge __attribute__((aligned(4)));
u16 g_p2_hyper_gauge __attribute__((aligned(4)));
u16 g_p1_hyper_combo_decay __attribute__((aligned(4)));
u16 g_p2_hyper_combo_decay __attribute__((aligned(4)));
u16 g_hyper_text_slide __attribute__((aligned(4)));
u16 g_p1_hyper_level __attribute__((aligned(4)));
u16 g_p2_hyper_level __attribute__((aligned(4)));
u16 g_p1_hyper_in_effect __attribute__((aligned(4)));
u16 g_p2_hyper_in_effect __attribute__((aligned(4)));
u16 g_p1_hyper_items __attribute__((aligned(4)));
u16 g_p2_hyper_items __attribute__((aligned(4)));
u16 g_p1_hyper_items_pending __attribute__((aligned(4)));
u16 g_p2_hyper_items_pending __attribute__((aligned(4)));
u16 g_boss_hyper_wait __attribute__((aligned(4)));
u16 g_hyper_hit_scratch __attribute__((aligned(4)));
u16 g_hyper_level_hit_scratch __attribute__((aligned(4)));
u16 g_boss_double_speed __attribute__((aligned(4)));
u16 g_hyper_debug_check __attribute__((aligned(4)));
u16 g_score_panel_intro __attribute__((aligned(4)));
u16 g_score_task_active;
s32 g_p1_hyper_effect_sprite;
s32 g_p2_hyper_effect_sprite;
u16 g_p1_hyper_effect_frame __attribute__((aligned(4)));
u16 g_p2_hyper_effect_frame __attribute__((aligned(4)));
u16 g_p1_hyper_effect_flag __attribute__((aligned(4)));
u16 g_p2_hyper_effect_flag __attribute__((aligned(4)));
u16 g_p1_hyper_effect_delay __attribute__((aligned(4)));
u16 g_p2_hyper_effect_delay __attribute__((aligned(4)));

/* .bss (the compiler lays these out in reverse) */
u8 p1_rank_entry_insert_buffer[16];
u8 p2_rank_entry_insert_buffer[16];
s32 g_ranking_scores[8];
s32 g_ranking_names[16];
s32 g_death_label_ranking_scores[36];
s32 g_death_label_ranking_names[16];
s32 g_stored_ranking_scores[36];
s32 g_stored_ranking_names[16];
u8 g_death_label_ranking_texts[272];
u8 g_stored_ranking_texts[160];
u8 scores_reset_buffer[80];
u16 g_p1_score_cells[96];
#ifdef DEATH_LABEL
u16 score_pending_apply_side_buffer[8];
#endif
#ifdef DEATH_LABEL
u16 g_p1_score_extra_cell[8];
#else
u16 g_p1_score_extra_cell[16];
#endif
s32 g_p1_position_trail[16];
s32 g_p2_position_trail[16];

#ifdef DDPDOJ_PC
#include "pc_data_alias.h"

PC_DATA_ALIAS(g_boss_hp_bar_flags, pc_boss_bar_flags, 0);
PC_DATA_ALIAS(g_boss_bar_flags, pc_boss_bar_flags, 1);

PC_DATA_ALIAS(g_death_label_ranking_scores_as_s32_a, g_death_label_ranking_scores, 0x0);
PC_DATA_ALIAS(g_ranking_score_tops, g_death_label_ranking_scores, 0x18);
PC_DATA_ALIAS(g_ranking_score_tops_as_u16_a, g_death_label_ranking_scores, 0x18);
PC_DATA_ALIAS(D_002BB342, g_death_label_ranking_scores, 0x22);
PC_DATA_ALIAS(g_ranking_continues, g_death_label_ranking_scores, 0x28);
PC_DATA_ALIAS(g_ranking_continues_as_u16_a, g_death_label_ranking_scores, 0x28);
PC_DATA_ALIAS(D_002BB352, g_death_label_ranking_scores, 0x32);
PC_DATA_ALIAS(g_ranking_hits, g_death_label_ranking_scores, 0x38);
PC_DATA_ALIAS(g_ranking_hits_as_u16_a, g_death_label_ranking_scores, 0x38);
PC_DATA_ALIAS(D_002BB362, g_death_label_ranking_scores, 0x42);
PC_DATA_ALIAS(g_ranking_power_styles, g_death_label_ranking_scores, 0x48);
PC_DATA_ALIAS(g_ranking_power_styles_as_u16_a, g_death_label_ranking_scores, 0x48);
PC_DATA_ALIAS(D_002BB372, g_death_label_ranking_scores, 0x52);
PC_DATA_ALIAS(g_ranking_ship_types, g_death_label_ranking_scores, 0x58);
PC_DATA_ALIAS(g_ranking_ship_types_as_u16_a, g_death_label_ranking_scores, 0x58);
PC_DATA_ALIAS(D_002BB382, g_death_label_ranking_scores, 0x62);
PC_DATA_ALIAS(g_ranking_stages, g_death_label_ranking_scores, 0x68);
PC_DATA_ALIAS(g_ranking_stages_as_u16_a, g_death_label_ranking_scores, 0x68);
PC_DATA_ALIAS(D_002BB392, g_death_label_ranking_scores, 0x72);
PC_DATA_ALIAS(g_ranking_loops, g_death_label_ranking_scores, 0x78);
PC_DATA_ALIAS(g_ranking_loops_as_u16_a, g_death_label_ranking_scores, 0x78);
PC_DATA_ALIAS(D_002BB3A2, g_death_label_ranking_scores, 0x82);

PC_DATA_ALIAS(g_ranking_names_as_s32_a, g_ranking_names, 0x0);
PC_DATA_ALIAS(D_002BB3EC, g_ranking_names, 0x3c);

PC_DATA_ALIAS(g_ranking_scores_as_s32_a, g_ranking_scores, 0x0);
PC_DATA_ALIAS(D_002BB404, g_ranking_scores, 0x14);

PC_DATA_ALIAS(g_stored_ranking_scores_as_s32_a, g_stored_ranking_scores, 0x0);
PC_DATA_ALIAS(g_death_label_ranking_score_tops, g_stored_ranking_scores, 0x18);
PC_DATA_ALIAS(g_death_label_ranking_score_tops_as_u16_a, g_stored_ranking_scores, 0x18);
PC_DATA_ALIAS(g_death_label_ranking_continues, g_stored_ranking_scores, 0x28);
PC_DATA_ALIAS(g_death_label_ranking_continues_as_u16_a, g_stored_ranking_scores, 0x28);
PC_DATA_ALIAS(g_death_label_ranking_hits, g_stored_ranking_scores, 0x38);
PC_DATA_ALIAS(g_death_label_ranking_hits_as_u16_a, g_stored_ranking_scores, 0x38);
PC_DATA_ALIAS(g_death_label_ranking_power_styles, g_stored_ranking_scores, 0x48);
PC_DATA_ALIAS(g_death_label_ranking_power_styles_as_u16_a, g_stored_ranking_scores, 0x48);
PC_DATA_ALIAS(g_death_label_ranking_ship_types, g_stored_ranking_scores, 0x58);
PC_DATA_ALIAS(g_death_label_ranking_ship_types_as_u16_a, g_stored_ranking_scores, 0x58);
PC_DATA_ALIAS(g_death_label_ranking_stages, g_stored_ranking_scores, 0x68);
PC_DATA_ALIAS(g_death_label_ranking_stages_as_u16_a, g_stored_ranking_scores, 0x68);
PC_DATA_ALIAS(g_death_label_ranking_loops, g_stored_ranking_scores, 0x78);
PC_DATA_ALIAS(g_death_label_ranking_loops_as_u16_a, g_stored_ranking_scores, 0x78);

PC_DATA_ALIAS(g_death_label_ranking_names_as_s32_a, g_death_label_ranking_names, 0x0);

PC_DATA_ALIAS(g_death_label_ranking_texts_as_s8_a5_a30, g_death_label_ranking_texts, 0x0);
PC_DATA_ALIAS(g_stored_ranking_score_tops, g_death_label_ranking_texts, 0x98);
PC_DATA_ALIAS(g_stored_ranking_score_tops_as_u16_a, g_death_label_ranking_texts, 0x98);
PC_DATA_ALIAS(g_stored_ranking_continues, g_death_label_ranking_texts, 0xa8);
PC_DATA_ALIAS(g_stored_ranking_hits, g_death_label_ranking_texts, 0xb8);
PC_DATA_ALIAS(g_stored_ranking_hits_as_u16_a, g_death_label_ranking_texts, 0xb8);
PC_DATA_ALIAS(g_stored_ranking_power_styles, g_death_label_ranking_texts, 0xc8);
PC_DATA_ALIAS(g_stored_ranking_power_styles_as_u16_a, g_death_label_ranking_texts, 0xc8);
PC_DATA_ALIAS(g_stored_ranking_ship_types, g_death_label_ranking_texts, 0xd8);
PC_DATA_ALIAS(g_stored_ranking_ship_types_as_u16_a, g_death_label_ranking_texts, 0xd8);
PC_DATA_ALIAS(g_stored_ranking_stages, g_death_label_ranking_texts, 0xe8);
PC_DATA_ALIAS(g_stored_ranking_stages_as_u16_a, g_death_label_ranking_texts, 0xe8);
PC_DATA_ALIAS(g_stored_ranking_loops, g_death_label_ranking_texts, 0xf8);
PC_DATA_ALIAS(g_stored_ranking_loops_as_u16_a, g_death_label_ranking_texts, 0xf8);

PC_DATA_ALIAS(g_p1_score_cells_as_Bank90, g_p1_score_cells, 0x0);
PC_DATA_ALIAS(g_p1_score_cells_as_Pair90, g_p1_score_cells, 0x0);
PC_DATA_ALIAS(g_p2_score_cells, g_p1_score_cells, 0x5a);

PC_DATA_ALIAS(g_p1_score_extra_cell_as_Bank10, g_p1_score_extra_cell, 0x0);
PC_DATA_ALIAS(g_p1_score_extra_cell_as_Pair10, g_p1_score_extra_cell, 0x0);
PC_DATA_ALIAS(g_p2_score_extra_cell, g_p1_score_extra_cell, 0xa);

PC_DATA_ALIAS(g_stored_ranking_texts_as_s8_a5_a30, g_stored_ranking_texts, 0x0);

#ifdef DEATH_LABEL
PC_DATA_ALIAS(death_D_0068DAA6, g_p1_score_extra_cell, 0x6);
PC_DATA_ALIAS(death_D_0068DAA8, g_p1_score_extra_cell, 0x8);
#endif

PC_DATA_ALIAS(g_p1_score_pending_as_u8, g_p1_score_pending, 0x0);
PC_DATA_ALIAS(g_p2_score_pending_as_u8, g_p2_score_pending, 0x0);

#ifdef DEATH_LABEL
PC_DATA_ALIAS(death_D_0068DAB2, score_pending_apply_side_buffer, 0x2);
#endif

PC_DATA_ALIAS(D_0028E579, g_p2_hyper_effect_delay, 1);
PC_DATA_ALIAS(D_0028E57D, g_p1_hyper_effect_delay, 1);
PC_DATA_ALIAS(D_0028E5D9, g_p2_hyper_combo_decay, 1);
PC_DATA_ALIAS(D_0028E5DD, g_p1_hyper_combo_decay, 1);
PC_DATA_ALIAS(D_0028E61D, g_boss_near_death, 1);
PC_DATA_ALIAS(D_0028E705, g_hyper_text_anim_delay, 1);
#endif
