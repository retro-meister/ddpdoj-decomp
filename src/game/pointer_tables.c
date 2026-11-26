#include "common.h"
#include "task.h"
#include "sdk/ps2sdk.h"

extern u16 laser_bomb_b_beam_frames[];
extern u16 D_002420A8[];
extern u16 p1_maximum_level_texts[];
extern u16 p2_maximum_level_texts[];
extern u16 player_weapon_tables[];
extern u16 ship0_shot_lists_1[];
extern u16 ship0_shot_lists_2[];
extern u16 ship0_shot_lists_3[];
extern u16 D_00255EE0[];
extern u16 small_tank_draw_routines[];
extern u16 option_shot_lists_1[];
extern u16 option_shot_lists_2[];
extern u16 option_shot_lists_3[];
extern u16 option_shot_lists_4[];
extern u16 option_style_params[];
extern u16 option_strong_params[];
extern u16 option_hyper_params[];
extern u16 player_ship_sprite_tables[];
extern u16 D_0028C9D8[];

extern u16 stage3_midboss_table[];
extern u16 stage3_midboss_flash_palettes[];
extern u16 stage3_midboss2_state_routines_0[];

extern u16 ship0_shot_list_1_00_00[];
extern u16 ship0_shot_list_2_00_00[];
extern u16 ship0_shot_list_1_00_01[];
extern u16 ship0_shot_list_2_00_01[];
extern u16 ship0_shot_list_1_00_02[];
extern u16 ship0_shot_list_2_00_02[];
extern u16 ship0_shot_list_1_00_03[];
extern u16 ship0_shot_list_2_00_03[];
extern u16 ship0_shot_list_1_00_04[];
extern u16 ship0_shot_list_2_00_04[];
extern u16 ship0_shot_list_1_02_00[];
extern u16 ship0_shot_list_1_02_01[];
extern u16 ship0_shot_list_1_02_02[];
extern u16 ship0_shot_list_1_02_03[];
extern u16 ship0_shot_list_1_02_04[];
extern u16 ship0_shot_list_1_04_00[];
extern u16 ship0_shot_list_2_04_00[];
extern u16 ship0_shot_list_1_04_01[];
extern u16 ship0_shot_list_2_04_01[];
extern u16 ship0_shot_list_1_04_02[];
extern u16 ship0_shot_list_2_04_02[];
extern u16 ship0_shot_list_1_04_03[];
extern u16 ship0_shot_list_2_04_03[];
extern u16 ship0_shot_list_1_04_04[];
extern u16 ship0_shot_list_2_04_04[];
extern u16 ship0_shot_list_3_00_00[];
extern u16 ship0_shot_list_3_00_01[];
extern u16 ship0_shot_list_3_00_02[];
extern u16 ship0_shot_list_3_00_03[];
extern u16 ship0_shot_list_3_00_04[];
extern u16 ship0_shot_list_3_02_00[];
extern u16 ship0_shot_list_3_02_01[];
extern u16 ship0_shot_list_3_02_02[];
extern u16 ship0_shot_list_3_02_03[];
extern u16 ship0_shot_list_3_02_04[];
extern u16 ship0_shot_list_3_04_00[];
extern u16 ship0_shot_list_3_04_01[];
extern u16 ship0_shot_list_3_04_02[];
extern u16 ship0_shot_list_3_04_03[];
extern u16 ship0_shot_list_3_04_04[];
extern u16 ship0_shot_list_1_01_00[];
extern u16 ship0_shot_list_2_01_00[];
extern u16 ship0_shot_list_1_01_01[];
extern u16 ship0_shot_list_2_01_01[];
extern u16 ship0_shot_list_1_01_02[];
extern u16 ship0_shot_list_2_01_02[];
extern u16 ship0_shot_list_1_01_03[];
extern u16 ship0_shot_list_2_01_03[];
extern u16 ship0_shot_list_1_01_04[];
extern u16 ship0_shot_list_2_01_04[];
extern u16 ship0_shot_list_1_03_00[];
extern u16 ship0_shot_list_1_03_01[];
extern u16 ship0_shot_list_1_03_02[];
extern u16 ship0_shot_list_1_03_03[];
extern u16 ship0_shot_list_1_03_04[];
extern u16 ship0_shot_list_1_05_00[];
extern u16 ship0_shot_list_2_05_00[];
extern u16 ship0_shot_list_1_05_01[];
extern u16 ship0_shot_list_2_05_01[];
extern u16 ship0_shot_list_1_05_02[];
extern u16 ship0_shot_list_2_05_02[];
extern u16 ship0_shot_list_1_05_03[];
extern u16 ship0_shot_list_2_05_03[];
extern u16 ship0_shot_list_1_05_04[];
extern u16 ship0_shot_list_2_05_04[];
extern u16 ship0_shot_list_3_01_00[];
extern u16 ship0_shot_list_3_01_01[];
extern u16 ship0_shot_list_3_01_02[];
extern u16 ship0_shot_list_3_01_03[];
extern u16 ship0_shot_list_3_01_04[];
extern u16 ship0_shot_list_3_03_00[];
extern u16 ship0_shot_list_3_03_01[];
extern u16 ship0_shot_list_3_03_02[];
extern u16 ship0_shot_list_3_03_03[];
extern u16 ship0_shot_list_3_03_04[];
extern u16 ship0_shot_list_3_05_00[];
extern u16 ship0_shot_list_3_05_01[];
extern u16 ship0_shot_list_3_05_02[];
extern u16 ship0_shot_list_3_05_03[];
extern u16 ship0_shot_list_3_05_04[];
extern u16 option_power_value_00[];
extern u16 option_power_value_01[];
extern u16 option_power_value_02[];
extern u16 option_power_value_03[];
extern u16 option_power_value_04[];
extern u16 option_power_value_05[];
extern u16 option_power_value_06[];
extern u16 option_power_value_07[];
extern u16 option_power_value_08[];
extern u16 option_power_value_09[];
extern u16 option_strong_param_00[];
extern u16 option_strong_param_01[];
extern u16 option_strong_param_02[];
extern u16 option_strong_param_03[];
extern u16 option_strong_param_04[];
extern u16 option_strong_param_05[];
extern u16 option_strong_param_06[];
extern u16 option_strong_param_07[];
extern u16 option_strong_param_08[];
extern u16 option_strong_param_09[];
extern u16 option_hyper_param_00[];
extern u16 option_hyper_param_01[];
extern u16 option_hyper_param_02[];
extern u16 option_hyper_param_03[];
extern u16 option_hyper_param_04[];
extern u16 option_sprites_a_00_00[];
extern u16 option_sprites_a_00_01[];
extern u16 option_sprites_a_00_02[];
extern u16 option_sprites_a_00_03[];
extern u16 option_sprites_a_00_04[];
extern u16 option_sprites_a_01_00[];
extern u16 option_sprites_a_01_01[];
extern u16 option_sprites_a_01_02[];
extern u16 option_sprites_a_01_03[];
extern u16 option_sprites_a_01_04[];
extern u16 option_strong_sprite_a_00[];
extern u16 option_strong_sprite_a_01[];
extern u16 option_strong_sprite_a_02[];
extern u16 option_strong_sprite_a_03[];
extern u16 option_strong_sprite_a_04[];
extern u16 option_hyper_sprite_a_00[];
extern u16 option_sprites_b_00_00[];
extern u16 option_sprites_b_00_01[];
extern u16 option_sprites_b_00_02[];
extern u16 option_sprites_b_00_03[];
extern u16 option_sprites_b_00_04[];
extern u16 option_sprites_b_01_00[];
extern u16 option_sprites_b_01_01[];
extern u16 option_sprites_b_01_02[];
extern u16 option_sprites_b_01_03[];
extern u16 option_sprites_b_01_04[];
extern u16 option_strong_sprites_b_00_00[];
extern u16 option_strong_sprites_b_00_01[];
extern u16 option_strong_sprites_b_00_02[];
extern u16 option_strong_sprites_b_00_03[];
extern u16 option_strong_sprites_b_00_04[];
extern u16 option_strong_sprites_b_01_00[];
extern u16 option_strong_sprites_b_01_01[];
extern u16 option_strong_sprites_b_01_02[];
extern u16 option_strong_sprites_b_01_03[];
extern u16 option_strong_sprites_b_01_04[];
extern u16 option_hyper_sprite_b_00[];
extern u16 option_hyper_sprite_b_01[];
extern u16 option_hyper_sprite_b_02[];
extern u16 option_hyper_sprite_b_03[];
extern u16 option_hyper_sprite_b_04[];
extern u16 option_shot_list_1_00_00[];
extern u16 option_shot_list_2_00_00[];
extern u16 option_shot_list_1_00_01[];
extern u16 option_shot_list_2_00_01[];
extern u16 option_shot_list_1_00_02[];
extern u16 option_shot_list_2_00_02[];
extern u16 option_shot_list_1_00_03[];
extern u16 option_shot_list_2_00_03[];
extern u16 option_shot_list_1_00_04[];
extern u16 option_shot_list_2_00_04[];
extern u16 option_shot_list_3_00_00[];
extern u16 option_shot_list_3_00_01[];
extern u16 option_shot_list_3_00_02[];
extern u16 option_shot_list_3_00_03[];
extern u16 option_shot_list_3_00_04[];
extern u16 option_shot_list_4_00_00[];
extern u16 option_shot_list_4_00_01[];
extern u16 option_shot_list_4_00_02[];
extern u16 option_shot_list_4_00_03[];
extern u16 option_shot_list_4_00_04[];
extern u16 option_shot_list_1_02_00[];
extern u16 option_shot_list_2_02_00[];
extern u16 option_shot_list_1_02_01[];
extern u16 option_shot_list_2_02_01[];
extern u16 option_shot_list_1_02_02[];
extern u16 option_shot_list_2_02_02[];
extern u16 option_shot_list_1_02_03[];
extern u16 option_shot_list_2_02_03[];
extern u16 option_shot_list_1_02_04[];
extern u16 option_shot_list_2_02_04[];
extern u16 option_shot_list_3_02_00[];
extern u16 option_shot_list_3_02_01[];
extern u16 option_shot_list_3_02_02[];
extern u16 option_shot_list_3_02_03[];
extern u16 option_shot_list_3_02_04[];
extern u16 option_shot_list_4_02_00[];
extern u16 option_shot_list_4_02_01[];
extern u16 option_shot_list_4_02_02[];
extern u16 option_shot_list_4_02_03[];
extern u16 option_shot_list_4_02_04[];
extern u16 option_shot_list_1_03_00[];
extern u16 option_shot_list_2_03_00[];
extern u16 option_shot_list_1_03_01[];
extern u16 option_shot_list_2_03_01[];
extern u16 option_shot_list_1_03_02[];
extern u16 option_shot_list_2_03_02[];
extern u16 option_shot_list_1_03_03[];
extern u16 option_shot_list_2_03_03[];
extern u16 option_shot_list_1_03_04[];
extern u16 option_shot_list_2_03_04[];
extern u16 option_shot_list_3_03_00[];
extern u16 option_shot_list_3_03_01[];
extern u16 option_shot_list_3_03_02[];
extern u16 option_shot_list_3_03_03[];
extern u16 option_shot_list_3_03_04[];
extern u16 option_shot_list_4_03_00[];
extern u16 option_shot_list_4_03_01[];
extern u16 option_shot_list_4_03_02[];
extern u16 option_shot_list_4_03_03[];
extern u16 option_shot_list_4_03_04[];

extern u16 spread_bomb_phase1_template[];
extern u16 spread_bomb_phase2_template[];
extern u16 spread_bomb_phase3_template[];
extern u16 laser_bomb_b_beam_table[];
extern u16 laser_bomb_template[];
extern u16 D_00242020[];
extern u16 D_00242070[];
extern u16 D_002576C0[];
extern u16 D_00257C10[];
extern u16 D_002589B0[];
extern u16 D_0025A0B0[];
extern u16 D_0025A160[];
extern u16 D_0025A230[];
extern u16 D_0025A2C0[];
extern u16 D_0025A3B0[];
extern u16 D_0025A4B0[];
extern u16 D_0025A5A0[];
extern u16 D_0025AD90[];
extern u16 small_tank_a_state[];
extern u16 small_tank_b_state[];
extern u16 large_tank_entities[];
extern u16 hatch_gunner_entities[];
extern u16 option_offsets[];
extern u16 stage1_midboss_entities[];
extern u16 stage1_midboss_fade_script[];
extern u16 D_00263030[];
extern u16 D_002630D0[];
extern u16 D_00263290[];
extern u16 D_002638B0[];
extern u16 D_002639B0[];
extern u16 D_00263A50[];
extern u16 D_00263B80[];
extern u16 D_00263C70[];
extern u16 D_00263C80[];
extern u16 D_00263C90[];
extern u16 D_00263CF0[];
extern u16 D_00265B60[];
extern u16 D_00265F60[];
extern u16 D_00266330[];
extern u16 D_0028C5E0[];
extern u16 D_0028C9B0[];

void task_table_init(void);
void option_offsets_init(void);
void bomb_tables_init(void);
void player_shot_1_tables_init(void);
void player_shot_2_tables_init(void);
void player_shot_5_tables_init(void);
void player_shot_6_tables_init(void);
void player_shot_3_tables_init(void);
void player_shot_4_tables_init(void);
void player_shot_8_tables_init(void);
void player_tables_init(void);
void maximum_level_texts_init(void);
void option_power_pointers_store(void);
void option_tables_init(void);
void option_shot_lists_init(void);
void ground_enemy_pointers_store(void);
void explosion_test_pointers_store(void);
void small_tank_pointers_store(void);
void stage1_midboss_pointers_store(void);
void stage3_midboss_pointers_store(void);
void pointers_store_part_6(void);
void pointers_store_part_7(void);
void pointers_store_part_8(void);
void pointers_store_part_9(void);
void pointers_store_part_10(void);
void pointers_store_part_11(void);
void player_shot_7_tables_init(void);


void pointer_tables_init(void) {
    task_table_init();
    option_offsets_init();
    bomb_tables_init();
    player_shot_1_tables_init();
    player_shot_2_tables_init();
    player_shot_5_tables_init();
    player_shot_6_tables_init();
    player_shot_3_tables_init();
    player_shot_4_tables_init();
    player_shot_8_tables_init();
    player_tables_init();
    maximum_level_texts_init();
    option_power_pointers_store();
    option_tables_init();
    option_shot_lists_init();
    ground_enemy_pointers_store();
    explosion_test_pointers_store();
    small_tank_pointers_store();
    stage1_midboss_pointers_store();
    stage3_midboss_pointers_store();
    pointers_store_part_6();
    pointers_store_part_7();
    pointers_store_part_8();
    pointers_store_part_9();
    pointers_store_part_10();
    pointers_store_part_11();
    player_shot_7_tables_init();
}

extern u16 g_task_table[];

#ifndef DDPDOJ_PC
#define TASK_CALLBACK(index, function) void function();
#define TASK_RESERVED(index)
#include "task_callbacks.h"
#undef TASK_RESERVED
#undef TASK_CALLBACK
#endif

void task_table_init(void) {
#ifndef DDPDOJ_PC
#define TASK_CALLBACK(index, function) STORE_POINTER(g_task_table + 4 * index, function);
#define TASK_RESERVED(index) TASK_CALLBACK(index, 0)
#include "task_callbacks.h"
#undef TASK_RESERVED
#undef TASK_CALLBACK
#endif
}

extern u16 option_offset_13[];
extern u16 option_offset_19[];
extern u16 D_00261CB0[];


void option_offsets_init(void) {
    STORE_POINTER(option_offsets + 26, option_offset_13);
    STORE_POINTER(option_offsets + 30, D_00261CB0);
    STORE_POINTER(option_offsets + 34, D_00261CB0);
    STORE_POINTER(option_offsets + 38, option_offset_19);
}

extern u16 spread_bomb_a_phase1_frames[];
extern u16 spread_bomb_a_phase2_frames[];
extern u16 spread_bomb_a_phase3_frames[];
extern u16 laser_bomb_a_base_frames[];
extern u16 laser_bomb_a_muzzle_frames[];
extern u16 laser_bomb_a_tip_frames[];
extern u16 laser_bomb_a_impact_frames[];
extern u16 laser_bomb_a_beam_frames[];
extern u16 laser_bomb_a_beam_frame_07[];
extern u16 laser_bomb_a_beam_frame_06[];
extern u16 laser_bomb_a_beam_frame_05[];
extern u16 laser_bomb_a_beam_frame_04[];
extern u16 laser_bomb_a_beam_frame_03[];
extern u16 laser_bomb_a_beam_frame_02[];
extern u16 laser_bomb_a_beam_frame_01[];
extern u16 laser_bomb_a_beam_frame_00[];
extern u16 laser_bomb_a_beam_table[];
extern u16 laser_bomb_a_beam_row_00[];
extern u16 laser_bomb_a_beam_row_01[];
extern u16 laser_bomb_a_beam_row_02[];
extern u16 laser_bomb_a_beam_row_03[];
extern u16 laser_bomb_a_beam_row_04[];
extern u16 laser_bomb_a_beam_row_05[];
extern u16 laser_bomb_a_beam_row_06[];
extern u16 laser_bomb_a_beam_row_07[];
extern u16 laser_bomb_a_beam_row_08[];
extern u16 laser_bomb_a_beam_row_09[];
extern u16 laser_bomb_a_beam_row_10[];
extern u16 laser_bomb_a_beam_row_11[];
extern u16 laser_bomb_b_beam_frame_07[];
extern u16 laser_bomb_b_beam_frame_06[];
extern u16 laser_bomb_b_beam_frame_05[];
extern u16 laser_bomb_b_beam_frame_04[];
extern u16 laser_bomb_b_beam_frame_03[];
extern u16 laser_bomb_b_beam_frame_02[];
extern u16 laser_bomb_b_beam_frame_01[];
extern u16 laser_bomb_b_beam_frame_00[];
extern u16 laser_bomb_b_beam_row_00[];
extern u16 laser_bomb_b_beam_row_01[];
extern u16 laser_bomb_b_beam_row_02[];
extern u16 laser_bomb_b_beam_row_03[];
extern u16 laser_bomb_b_beam_row_04[];
extern u16 laser_bomb_b_beam_row_05[];
extern u16 laser_bomb_b_beam_row_06[];
extern u16 laser_bomb_b_beam_row_07[];
extern u16 laser_bomb_b_beam_row_08[];
extern u16 laser_bomb_b_beam_row_09[];
extern u16 laser_bomb_b_beam_row_10[];
extern u16 laser_bomb_b_beam_row_11[];


void bomb_tables_init(void) {
    STORE_POINTER(spread_bomb_phase1_template + 8, spread_bomb_a_phase1_frames);
    STORE_POINTER(spread_bomb_phase2_template + 10, spread_bomb_a_phase2_frames);
    STORE_POINTER(spread_bomb_phase3_template + 10, spread_bomb_a_phase3_frames);
    STORE_POINTER(laser_bomb_a_beam_frames, laser_bomb_a_beam_frame_00);
    STORE_POINTER(laser_bomb_a_beam_frames + 2, laser_bomb_a_beam_frame_01);
    STORE_POINTER(laser_bomb_a_beam_frames + 4, laser_bomb_a_beam_frame_02);
    STORE_POINTER(laser_bomb_a_beam_frames + 6, laser_bomb_a_beam_frame_03);
    STORE_POINTER(laser_bomb_a_beam_frames + 8, laser_bomb_a_beam_frame_04);
    STORE_POINTER(laser_bomb_a_beam_frames + 10, laser_bomb_a_beam_frame_05);
    STORE_POINTER(laser_bomb_a_beam_frames + 12, laser_bomb_a_beam_frame_06);
    STORE_POINTER(laser_bomb_a_beam_frames + 14, laser_bomb_a_beam_frame_07);
    STORE_POINTER(laser_bomb_a_beam_table + 8, laser_bomb_a_beam_row_00);
    STORE_POINTER(laser_bomb_a_beam_table + 18, laser_bomb_a_beam_row_01);
    STORE_POINTER(laser_bomb_a_beam_table + 28, laser_bomb_a_beam_row_02);
    STORE_POINTER(laser_bomb_a_beam_table + 38, laser_bomb_a_beam_row_03);
    STORE_POINTER(laser_bomb_a_beam_table + 48, laser_bomb_a_beam_row_04);
    STORE_POINTER(laser_bomb_a_beam_table + 58, laser_bomb_a_beam_row_05);
    STORE_POINTER(laser_bomb_a_beam_table + 68, laser_bomb_a_beam_row_06);
    STORE_POINTER(laser_bomb_a_beam_table + 78, laser_bomb_a_beam_row_07);
    STORE_POINTER(laser_bomb_a_beam_table + 88, laser_bomb_a_beam_row_08);
    STORE_POINTER(laser_bomb_a_beam_table + 98, laser_bomb_a_beam_row_09);
    STORE_POINTER(laser_bomb_a_beam_table + 108, laser_bomb_a_beam_row_10);
    STORE_POINTER(laser_bomb_a_beam_table + 118, laser_bomb_a_beam_row_11);
    STORE_POINTER(((u16 *)laser_bomb_b_beam_frames), laser_bomb_b_beam_frame_00);
    STORE_POINTER(laser_bomb_b_beam_frames + 2, laser_bomb_b_beam_frame_01);
    STORE_POINTER(laser_bomb_b_beam_frames + 4, laser_bomb_b_beam_frame_02);
    STORE_POINTER(laser_bomb_b_beam_frames + 6, laser_bomb_b_beam_frame_03);
    STORE_POINTER(laser_bomb_b_beam_frames + 8, laser_bomb_b_beam_frame_04);
    STORE_POINTER(laser_bomb_b_beam_frames + 10, laser_bomb_b_beam_frame_05);
    STORE_POINTER(laser_bomb_b_beam_frames + 12, laser_bomb_b_beam_frame_06);
    STORE_POINTER(laser_bomb_b_beam_frames + 14, laser_bomb_b_beam_frame_07);
    STORE_POINTER(laser_bomb_b_beam_table + 8, laser_bomb_b_beam_row_00);
    STORE_POINTER(laser_bomb_b_beam_table + 18, laser_bomb_b_beam_row_01);
    STORE_POINTER(laser_bomb_b_beam_table + 28, laser_bomb_b_beam_row_02);
    STORE_POINTER(laser_bomb_b_beam_table + 38, laser_bomb_b_beam_row_03);
    STORE_POINTER(laser_bomb_b_beam_table + 48, laser_bomb_b_beam_row_04);
    STORE_POINTER(laser_bomb_b_beam_table + 58, laser_bomb_b_beam_row_05);
    STORE_POINTER(laser_bomb_b_beam_table + 68, laser_bomb_b_beam_row_06);
    STORE_POINTER(laser_bomb_b_beam_table + 78, laser_bomb_b_beam_row_07);
    STORE_POINTER(laser_bomb_b_beam_table + 88, laser_bomb_b_beam_row_08);
    STORE_POINTER(laser_bomb_b_beam_table + 98, laser_bomb_b_beam_row_09);
    STORE_POINTER(laser_bomb_b_beam_table + 108, laser_bomb_b_beam_row_10);
    STORE_POINTER(laser_bomb_b_beam_table + 118, laser_bomb_b_beam_row_11);
    STORE_POINTER(laser_bomb_template + 10, laser_bomb_a_base_frames);
    STORE_POINTER(laser_bomb_template + 15, laser_bomb_a_beam_table);
    STORE_POINTER(laser_bomb_template + 17, laser_bomb_a_beam_frames);
    STORE_POINTER(laser_bomb_template + 30, laser_bomb_a_tip_frames);
    STORE_POINTER(laser_bomb_template + 50, laser_bomb_a_muzzle_frames);
    STORE_POINTER(laser_bomb_template + 70, laser_bomb_a_impact_frames);
}

extern u16 ship0_shot_list_1_00_00_02[];
extern u16 ship0_shot_list_1_00_01_02[];
extern u16 ship0_shot_list_1_00_02_02[];
extern u16 ship0_shot_list_1_00_03_02[];
extern u16 ship0_shot_list_1_00_04_02[];
extern u16 ship0_shot_list_1_02_00_02[];
extern u16 ship0_shot_list_1_02_01_02[];
extern u16 ship0_shot_list_1_02_02_02[];
extern u16 ship0_shot_list_1_02_03_02[];
extern u16 ship0_shot_list_1_02_04_02[];
extern u16 ship0_shot_list_1_04_00_02[];
extern u16 ship0_shot_list_1_04_01_02[];
extern u16 ship0_shot_list_1_04_02_02[];
extern u16 ship0_shot_list_1_04_03_02[];
extern u16 ship0_shot_list_1_04_04_02[];
extern u16 player_shot_1_impact_frames_00[];
extern u16 player_shot_1_impact_frames_02[];
extern u16 player_shot_1_impact_frames_04[];
extern u16 player_shot_1_impact_frames_06[];
extern u16 player_shot_1_impact_frames_08[];
extern u16 player_shot_1_impact_frames_10[];
extern u16 player_shot_1_impact_frames_11[];
extern u16 player_shot_1_impact_frames_12[];
extern u16 player_shot_1_impact_frames_13[];
extern u16 player_shot_1_impact_frames_14[];
extern u16 player_shot_1_impact_frames_15[];
extern u16 player_shot_1_impact_frames_17[];
extern u16 player_shot_1_impact_frames_19[];
extern u16 player_shot_1_impact_frames_21[];
extern u16 player_shot_1_impact_frames_23[];
extern u16 player_shot_1_impact_00[];
extern u16 player_shot_1_impact_01[];
extern u16 player_shot_1_impact_02[];
extern u16 player_shot_1_impact_03[];
extern u16 player_shot_1_impact_04[];
extern u16 player_shot_1_impact_05[];
extern u16 player_shot_1_impact_06[];
extern u16 player_shot_1_impact_07[];
extern u16 player_shot_1_impact_08[];
extern u16 player_shot_1_impact_09[];
extern u16 player_shot_1_impact_10[];
extern u16 player_shot_1_impact_11[];
extern u16 player_shot_1_impact_12[];
extern u16 player_shot_1_impact_13[];
extern u16 player_shot_1_impact_14[];
extern u16 player_shot_1_impact_15[];
extern u16 player_shot_1_impact_16[];
extern u16 player_shot_1_impact_17[];
extern u16 player_shot_1_impact_18[];
extern u16 player_shot_1_impact_19[];
extern u16 player_shot_1_impact_20[];
extern u16 player_shot_1_impact_21[];
extern u16 player_shot_1_impact_22[];
extern u16 player_shot_1_impact_23[];
extern u16 player_shot_1_impact_24[];
extern u16 ship0_shot_list_1_00_00_07[];
extern u16 ship0_shot_list_1_00_01_07[];
extern u16 ship0_shot_list_1_00_02_07[];
extern u16 ship0_shot_list_1_00_03_07[];
extern u16 ship0_shot_list_1_00_04_07[];
extern u16 ship0_shot_list_1_02_00_07[];
extern u16 ship0_shot_list_1_02_01_07[];
extern u16 ship0_shot_list_1_02_02_07[];
extern u16 ship0_shot_list_1_02_03_07[];
extern u16 ship0_shot_list_1_02_04_07[];
extern u16 ship0_shot_list_1_04_00_07[];
extern u16 ship0_shot_list_1_04_01_07[];
extern u16 ship0_shot_list_1_04_02_07[];
extern u16 ship0_shot_list_1_04_03_07[];
extern u16 ship0_shot_list_1_04_04_07[];
extern u16 player_shot_1_flight_00[];
extern u16 player_shot_1_flight_01[];
extern u16 player_shot_1_flight_02[];
extern u16 player_shot_1_flight_03[];
extern u16 player_shot_1_flight_04[];
extern u16 player_shot_1_flight_05[];
extern u16 player_shot_1_flight_06[];
extern u16 player_shot_1_flight_07[];
extern u16 player_shot_1_flight_08[];
extern u16 player_shot_1_flight_09[];
extern u16 player_shot_1_flight_10[];
extern u16 player_shot_1_flight_11[];
extern u16 player_shot_1_flight_12[];
extern u16 player_shot_1_flight_13[];
extern u16 player_shot_1_flight_14[];
extern u16 player_shot_1_flight_15[];
extern u16 player_shot_1_flight_16[];
extern u16 player_shot_1_flight_17[];
extern u16 player_shot_1_flight_18[];
extern u16 player_shot_1_flight_19[];
extern u16 player_shot_1_flight_20[];
extern u16 player_shot_1_flight_21[];
extern u16 player_shot_1_flight_22[];
extern u16 player_shot_1_flight_23[];
extern u16 player_shot_1_flight_24[];

extern u16 player_shot_1_flight_table[];
extern u16 player_shot_1_impact_table[];

void player_shot_1_tables_init(void) {
    STORE_POINTER(ship0_shot_list_1_00_00 + 5, ship0_shot_list_1_00_00_02);
    STORE_POINTER(ship0_shot_list_1_00_00 + 15, ship0_shot_list_1_00_00_07);
    STORE_POINTER(ship0_shot_list_2_00_00 + 5, ship0_shot_list_1_00_00_02);
    STORE_POINTER(ship0_shot_list_2_00_00 + 15, ship0_shot_list_1_00_00_07);
    STORE_POINTER(ship0_shot_list_1_00_01 + 5, ship0_shot_list_1_00_01_02);
    STORE_POINTER(ship0_shot_list_1_00_01 + 15, ship0_shot_list_1_00_01_07);
    STORE_POINTER(ship0_shot_list_2_00_01 + 5, ship0_shot_list_1_00_01_02);
    STORE_POINTER(ship0_shot_list_2_00_01 + 15, ship0_shot_list_1_00_01_07);
    STORE_POINTER(ship0_shot_list_1_00_02 + 5, ship0_shot_list_1_00_02_02);
    STORE_POINTER(ship0_shot_list_1_00_02 + 15, ship0_shot_list_1_00_02_07);
    STORE_POINTER(ship0_shot_list_2_00_02 + 5, ship0_shot_list_1_00_02_02);
    STORE_POINTER(ship0_shot_list_2_00_02 + 15, ship0_shot_list_1_00_02_07);
    STORE_POINTER(ship0_shot_list_1_00_03 + 5, ship0_shot_list_1_00_03_02);
    STORE_POINTER(ship0_shot_list_1_00_03 + 15, ship0_shot_list_1_00_03_07);
    STORE_POINTER(ship0_shot_list_2_00_03 + 5, ship0_shot_list_1_00_03_02);
    STORE_POINTER(ship0_shot_list_2_00_03 + 15, ship0_shot_list_1_00_03_07);
    STORE_POINTER(ship0_shot_list_1_00_04 + 5, ship0_shot_list_1_00_04_02);
    STORE_POINTER(ship0_shot_list_1_00_04 + 15, ship0_shot_list_1_00_04_07);
    STORE_POINTER(ship0_shot_list_2_00_04 + 5, ship0_shot_list_1_00_04_02);
    STORE_POINTER(ship0_shot_list_2_00_04 + 15, ship0_shot_list_1_00_04_07);
    STORE_POINTER(ship0_shot_list_1_02_00 + 5, ship0_shot_list_1_02_00_02);
    STORE_POINTER(ship0_shot_list_1_02_00 + 15, ship0_shot_list_1_02_00_07);
    STORE_POINTER(ship0_shot_list_1_02_01 + 5, ship0_shot_list_1_02_01_02);
    STORE_POINTER(ship0_shot_list_1_02_01 + 15, ship0_shot_list_1_02_01_07);
    STORE_POINTER(ship0_shot_list_1_02_02 + 5, ship0_shot_list_1_02_02_02);
    STORE_POINTER(ship0_shot_list_1_02_02 + 15, ship0_shot_list_1_02_02_07);
    STORE_POINTER(ship0_shot_list_1_02_03 + 5, ship0_shot_list_1_02_03_02);
    STORE_POINTER(ship0_shot_list_1_02_03 + 15, ship0_shot_list_1_02_03_07);
    STORE_POINTER(ship0_shot_list_1_02_04 + 5, ship0_shot_list_1_02_04_02);
    STORE_POINTER(ship0_shot_list_1_02_04 + 15, ship0_shot_list_1_02_04_07);
    STORE_POINTER(ship0_shot_list_1_04_00 + 5, ship0_shot_list_1_04_00_02);
    STORE_POINTER(ship0_shot_list_1_04_00 + 15, ship0_shot_list_1_04_00_07);
    STORE_POINTER(ship0_shot_list_2_04_00 + 5, ship0_shot_list_1_04_00_02);
    STORE_POINTER(ship0_shot_list_2_04_00 + 15, ship0_shot_list_1_04_00_07);
    STORE_POINTER(ship0_shot_list_1_04_01 + 5, ship0_shot_list_1_04_01_02);
    STORE_POINTER(ship0_shot_list_1_04_01 + 15, ship0_shot_list_1_04_01_07);
    STORE_POINTER(ship0_shot_list_2_04_01 + 5, ship0_shot_list_1_04_01_02);
    STORE_POINTER(ship0_shot_list_2_04_01 + 15, ship0_shot_list_1_04_01_07);
    STORE_POINTER(ship0_shot_list_1_04_02 + 5, ship0_shot_list_1_04_02_02);
    STORE_POINTER(ship0_shot_list_1_04_02 + 15, ship0_shot_list_1_04_02_07);
    STORE_POINTER(ship0_shot_list_2_04_02 + 5, ship0_shot_list_1_04_02_02);
    STORE_POINTER(ship0_shot_list_2_04_02 + 15, ship0_shot_list_1_04_02_07);
    STORE_POINTER(ship0_shot_list_1_04_03 + 5, ship0_shot_list_1_04_03_02);
    STORE_POINTER(ship0_shot_list_1_04_03 + 15, ship0_shot_list_1_04_03_07);
    STORE_POINTER(ship0_shot_list_2_04_03 + 5, ship0_shot_list_1_04_03_02);
    STORE_POINTER(ship0_shot_list_2_04_03 + 15, ship0_shot_list_1_04_03_07);
    STORE_POINTER(ship0_shot_list_1_04_04 + 5, ship0_shot_list_1_04_04_02);
    STORE_POINTER(ship0_shot_list_1_04_04 + 15, ship0_shot_list_1_04_04_07);
    STORE_POINTER(ship0_shot_list_2_04_04 + 5, ship0_shot_list_1_04_04_02);
    STORE_POINTER(ship0_shot_list_2_04_04 + 15, ship0_shot_list_1_04_04_07);
    STORE_POINTER(player_shot_1_flight_table, player_shot_1_flight_00);
    STORE_POINTER(player_shot_1_flight_table + 2, player_shot_1_flight_01);
    STORE_POINTER(player_shot_1_flight_table + 4, player_shot_1_flight_02);
    STORE_POINTER(player_shot_1_flight_table + 6, player_shot_1_flight_03);
    STORE_POINTER(player_shot_1_flight_table + 8, player_shot_1_flight_04);
    STORE_POINTER(player_shot_1_flight_table + 10, player_shot_1_flight_05);
    STORE_POINTER(player_shot_1_flight_table + 12, player_shot_1_flight_06);
    STORE_POINTER(player_shot_1_flight_table + 14, player_shot_1_flight_07);
    STORE_POINTER(player_shot_1_flight_table + 16, player_shot_1_flight_08);
    STORE_POINTER(player_shot_1_flight_table + 18, player_shot_1_flight_09);
    STORE_POINTER(player_shot_1_flight_table + 20, player_shot_1_flight_10);
    STORE_POINTER(player_shot_1_flight_table + 22, player_shot_1_flight_11);
    STORE_POINTER(player_shot_1_flight_table + 24, player_shot_1_flight_12);
    STORE_POINTER(player_shot_1_flight_table + 26, player_shot_1_flight_13);
    STORE_POINTER(player_shot_1_flight_table + 28, player_shot_1_flight_14);
    STORE_POINTER(player_shot_1_flight_table + 30, player_shot_1_flight_15);
    STORE_POINTER(player_shot_1_flight_table + 32, player_shot_1_flight_16);
    STORE_POINTER(player_shot_1_flight_table + 34, player_shot_1_flight_17);
    STORE_POINTER(player_shot_1_flight_table + 36, player_shot_1_flight_18);
    STORE_POINTER(player_shot_1_flight_table + 38, player_shot_1_flight_19);
    STORE_POINTER(player_shot_1_flight_table + 40, player_shot_1_flight_20);
    STORE_POINTER(player_shot_1_flight_table + 42, player_shot_1_flight_21);
    STORE_POINTER(player_shot_1_flight_table + 44, player_shot_1_flight_22);
    STORE_POINTER(player_shot_1_flight_table + 46, player_shot_1_flight_23);
    STORE_POINTER(player_shot_1_flight_table + 48, player_shot_1_flight_24);
    STORE_POINTER(player_shot_1_impact_table, player_shot_1_impact_00);
    STORE_POINTER(player_shot_1_impact_table + 2, player_shot_1_impact_01);
    STORE_POINTER(player_shot_1_impact_table + 4, player_shot_1_impact_02);
    STORE_POINTER(player_shot_1_impact_table + 6, player_shot_1_impact_03);
    STORE_POINTER(player_shot_1_impact_table + 8, player_shot_1_impact_04);
    STORE_POINTER(player_shot_1_impact_table + 10, player_shot_1_impact_05);
    STORE_POINTER(player_shot_1_impact_table + 12, player_shot_1_impact_06);
    STORE_POINTER(player_shot_1_impact_table + 14, player_shot_1_impact_07);
    STORE_POINTER(player_shot_1_impact_table + 16, player_shot_1_impact_08);
    STORE_POINTER(player_shot_1_impact_table + 18, player_shot_1_impact_09);
    STORE_POINTER(player_shot_1_impact_table + 20, player_shot_1_impact_10);
    STORE_POINTER(player_shot_1_impact_table + 22, player_shot_1_impact_11);
    STORE_POINTER(player_shot_1_impact_table + 24, player_shot_1_impact_12);
    STORE_POINTER(player_shot_1_impact_table + 26, player_shot_1_impact_13);
    STORE_POINTER(player_shot_1_impact_table + 28, player_shot_1_impact_14);
    STORE_POINTER(player_shot_1_impact_table + 30, player_shot_1_impact_15);
    STORE_POINTER(player_shot_1_impact_table + 32, player_shot_1_impact_16);
    STORE_POINTER(player_shot_1_impact_table + 34, player_shot_1_impact_17);
    STORE_POINTER(player_shot_1_impact_table + 36, player_shot_1_impact_18);
    STORE_POINTER(player_shot_1_impact_table + 38, player_shot_1_impact_19);
    STORE_POINTER(player_shot_1_impact_table + 40, player_shot_1_impact_20);
    STORE_POINTER(player_shot_1_impact_table + 42, player_shot_1_impact_21);
    STORE_POINTER(player_shot_1_impact_table + 44, player_shot_1_impact_22);
    STORE_POINTER(player_shot_1_impact_table + 46, player_shot_1_impact_23);
    STORE_POINTER(player_shot_1_impact_table + 48, player_shot_1_impact_24);
    STORE_POINTER(player_shot_1_impact_00 + 3, player_shot_1_impact_frames_00);
    STORE_POINTER(player_shot_1_impact_01 + 3, player_shot_1_impact_frames_00);
    STORE_POINTER(player_shot_1_impact_02 + 3, player_shot_1_impact_frames_02);
    STORE_POINTER(player_shot_1_impact_03 + 3, player_shot_1_impact_frames_02);
    STORE_POINTER(player_shot_1_impact_04 + 3, player_shot_1_impact_frames_04);
    STORE_POINTER(player_shot_1_impact_05 + 3, player_shot_1_impact_frames_04);
    STORE_POINTER(player_shot_1_impact_06 + 3, player_shot_1_impact_frames_06);
    STORE_POINTER(player_shot_1_impact_07 + 3, player_shot_1_impact_frames_06);
    STORE_POINTER(player_shot_1_impact_08 + 3, player_shot_1_impact_frames_08);
    STORE_POINTER(player_shot_1_impact_09 + 3, player_shot_1_impact_frames_08);
    STORE_POINTER(player_shot_1_impact_10 + 3, player_shot_1_impact_frames_10);
    STORE_POINTER(player_shot_1_impact_11 + 3, player_shot_1_impact_frames_11);
    STORE_POINTER(player_shot_1_impact_12 + 3, player_shot_1_impact_frames_12);
    STORE_POINTER(player_shot_1_impact_13 + 3, player_shot_1_impact_frames_13);
    STORE_POINTER(player_shot_1_impact_14 + 3, player_shot_1_impact_frames_14);
    STORE_POINTER(player_shot_1_impact_15 + 3, player_shot_1_impact_frames_15);
    STORE_POINTER(player_shot_1_impact_16 + 3, player_shot_1_impact_frames_15);
    STORE_POINTER(player_shot_1_impact_17 + 3, player_shot_1_impact_frames_17);
    STORE_POINTER(player_shot_1_impact_18 + 3, player_shot_1_impact_frames_17);
    STORE_POINTER(player_shot_1_impact_19 + 3, player_shot_1_impact_frames_19);
    STORE_POINTER(player_shot_1_impact_20 + 3, player_shot_1_impact_frames_19);
    STORE_POINTER(player_shot_1_impact_21 + 3, player_shot_1_impact_frames_21);
    STORE_POINTER(player_shot_1_impact_22 + 3, player_shot_1_impact_frames_21);
    STORE_POINTER(player_shot_1_impact_23 + 3, player_shot_1_impact_frames_23);
    STORE_POINTER(player_shot_1_impact_24 + 3, player_shot_1_impact_frames_23);
}

extern u16 ship0_shot_list_3_00_00_02[];
extern u16 ship0_shot_list_3_00_01_02[];
extern u16 ship0_shot_list_3_00_02_02[];
extern u16 ship0_shot_list_3_00_03_02[];
extern u16 ship0_shot_list_3_00_04_02[];
extern u16 ship0_shot_list_3_02_00_02[];
extern u16 ship0_shot_list_3_02_01_02[];
extern u16 ship0_shot_list_3_02_02_02[];
extern u16 ship0_shot_list_3_02_03_02[];
extern u16 ship0_shot_list_3_02_04_02[];
extern u16 ship0_shot_list_3_04_00_02[];
extern u16 ship0_shot_list_3_04_01_02[];
extern u16 ship0_shot_list_3_04_02_02[];
extern u16 ship0_shot_list_3_04_03_02[];
extern u16 ship0_shot_list_3_04_04_02[];
extern u16 player_shot_2_impact_frames_00[];
extern u16 player_shot_2_impact_frames_02[];
extern u16 player_shot_2_impact_frames_04[];
extern u16 player_shot_2_impact_frames_06[];
extern u16 player_shot_2_impact_frames_08[];
extern u16 player_shot_2_impact_frames_10[];
extern u16 player_shot_2_impact_frames_11[];
extern u16 player_shot_2_impact_frames_12[];
extern u16 player_shot_2_impact_frames_13[];
extern u16 player_shot_2_impact_frames_14[];
extern u16 player_shot_2_impact_frames_15[];
extern u16 player_shot_2_impact_frames_17[];
extern u16 player_shot_2_impact_frames_19[];
extern u16 player_shot_2_impact_frames_21[];
extern u16 player_shot_2_impact_frames_23[];
extern u16 player_shot_2_impact_00[];
extern u16 player_shot_2_impact_01[];
extern u16 player_shot_2_impact_02[];
extern u16 player_shot_2_impact_03[];
extern u16 player_shot_2_impact_04[];
extern u16 player_shot_2_impact_05[];
extern u16 player_shot_2_impact_06[];
extern u16 player_shot_2_impact_07[];
extern u16 player_shot_2_impact_08[];
extern u16 player_shot_2_impact_09[];
extern u16 player_shot_2_impact_10[];
extern u16 player_shot_2_impact_11[];
extern u16 player_shot_2_impact_12[];
extern u16 player_shot_2_impact_13[];
extern u16 player_shot_2_impact_14[];
extern u16 player_shot_2_impact_15[];
extern u16 player_shot_2_impact_16[];
extern u16 player_shot_2_impact_17[];
extern u16 player_shot_2_impact_18[];
extern u16 player_shot_2_impact_19[];
extern u16 player_shot_2_impact_20[];
extern u16 player_shot_2_impact_21[];
extern u16 player_shot_2_impact_22[];
extern u16 player_shot_2_impact_23[];
extern u16 player_shot_2_impact_24[];
extern u16 ship0_shot_list_3_00_00_07[];
extern u16 ship0_shot_list_3_00_01_07[];
extern u16 ship0_shot_list_3_00_02_07[];
extern u16 ship0_shot_list_3_00_03_07[];
extern u16 ship0_shot_list_3_00_04_07[];
extern u16 ship0_shot_list_3_02_00_07[];
extern u16 ship0_shot_list_3_02_01_07[];
extern u16 ship0_shot_list_3_02_02_07[];
extern u16 ship0_shot_list_3_02_03_07[];
extern u16 ship0_shot_list_3_02_04_07[];
extern u16 ship0_shot_list_3_04_00_07[];
extern u16 ship0_shot_list_3_04_01_07[];
extern u16 ship0_shot_list_3_04_02_07[];
extern u16 ship0_shot_list_3_04_03_07[];
extern u16 ship0_shot_list_3_04_04_07[];
extern u16 player_shot_2_flight_00[];
extern u16 player_shot_2_flight_01[];
extern u16 player_shot_2_flight_02[];
extern u16 player_shot_2_flight_03[];
extern u16 player_shot_2_flight_04[];
extern u16 player_shot_2_flight_05[];
extern u16 player_shot_2_flight_06[];
extern u16 player_shot_2_flight_07[];
extern u16 player_shot_2_flight_08[];
extern u16 player_shot_2_flight_09[];
extern u16 player_shot_2_flight_10[];
extern u16 player_shot_2_flight_11[];
extern u16 player_shot_2_flight_12[];
extern u16 player_shot_2_flight_13[];
extern u16 player_shot_2_flight_14[];
extern u16 player_shot_2_flight_15[];
extern u16 player_shot_2_flight_16[];
extern u16 player_shot_2_flight_17[];
extern u16 player_shot_2_flight_18[];
extern u16 player_shot_2_flight_19[];
extern u16 player_shot_2_flight_20[];
extern u16 player_shot_2_flight_21[];
extern u16 player_shot_2_flight_22[];
extern u16 player_shot_2_flight_23[];
extern u16 player_shot_2_flight_24[];

extern u16 player_shot_2_flight_table[];
extern u16 player_shot_2_impact_table[];

void player_shot_2_tables_init(void) {
    STORE_POINTER(ship0_shot_list_3_00_00 + 5, ship0_shot_list_3_00_00_02);
    STORE_POINTER(ship0_shot_list_3_00_00 + 15, ship0_shot_list_3_00_00_07);
    STORE_POINTER(ship0_shot_list_3_00_00 + 24, ship0_shot_list_3_00_00_02);
    STORE_POINTER(ship0_shot_list_3_00_00 + 34, ship0_shot_list_3_00_00_07);
    STORE_POINTER(ship0_shot_list_3_00_01 + 5, ship0_shot_list_3_00_01_02);
    STORE_POINTER(ship0_shot_list_3_00_01 + 15, ship0_shot_list_3_00_01_07);
    STORE_POINTER(ship0_shot_list_3_00_01 + 24, ship0_shot_list_3_00_01_02);
    STORE_POINTER(ship0_shot_list_3_00_01 + 34, ship0_shot_list_3_00_01_07);
    STORE_POINTER(ship0_shot_list_3_00_02 + 5, ship0_shot_list_3_00_02_02);
    STORE_POINTER(ship0_shot_list_3_00_02 + 15, ship0_shot_list_3_00_02_07);
    STORE_POINTER(ship0_shot_list_3_00_02 + 24, ship0_shot_list_3_00_02_02);
    STORE_POINTER(ship0_shot_list_3_00_02 + 34, ship0_shot_list_3_00_02_07);
    STORE_POINTER(ship0_shot_list_3_00_03 + 5, ship0_shot_list_3_00_03_02);
    STORE_POINTER(ship0_shot_list_3_00_03 + 15, ship0_shot_list_3_00_03_07);
    STORE_POINTER(ship0_shot_list_3_00_03 + 24, ship0_shot_list_3_00_03_02);
    STORE_POINTER(ship0_shot_list_3_00_03 + 34, ship0_shot_list_3_00_03_07);
    STORE_POINTER(ship0_shot_list_3_00_04 + 5, ship0_shot_list_3_00_04_02);
    STORE_POINTER(ship0_shot_list_3_00_04 + 15, ship0_shot_list_3_00_04_07);
    STORE_POINTER(ship0_shot_list_3_00_04 + 24, ship0_shot_list_3_00_04_02);
    STORE_POINTER(ship0_shot_list_3_00_04 + 34, ship0_shot_list_3_00_04_07);
    STORE_POINTER(ship0_shot_list_3_02_00 + 5, ship0_shot_list_3_02_00_02);
    STORE_POINTER(ship0_shot_list_3_02_00 + 15, ship0_shot_list_3_02_00_07);
    STORE_POINTER(ship0_shot_list_3_02_01 + 5, ship0_shot_list_3_02_01_02);
    STORE_POINTER(ship0_shot_list_3_02_01 + 15, ship0_shot_list_3_02_01_07);
    STORE_POINTER(ship0_shot_list_3_02_02 + 5, ship0_shot_list_3_02_02_02);
    STORE_POINTER(ship0_shot_list_3_02_02 + 15, ship0_shot_list_3_02_02_07);
    STORE_POINTER(ship0_shot_list_3_02_03 + 5, ship0_shot_list_3_02_03_02);
    STORE_POINTER(ship0_shot_list_3_02_03 + 15, ship0_shot_list_3_02_03_07);
    STORE_POINTER(ship0_shot_list_3_02_04 + 5, ship0_shot_list_3_02_04_02);
    STORE_POINTER(ship0_shot_list_3_02_04 + 15, ship0_shot_list_3_02_04_07);
    STORE_POINTER(ship0_shot_list_3_04_00 + 5, ship0_shot_list_3_04_00_02);
    STORE_POINTER(ship0_shot_list_3_04_00 + 15, ship0_shot_list_3_04_00_07);
    STORE_POINTER(ship0_shot_list_3_04_00 + 24, ship0_shot_list_3_04_00_02);
    STORE_POINTER(ship0_shot_list_3_04_00 + 34, ship0_shot_list_3_04_00_07);
    STORE_POINTER(ship0_shot_list_3_04_01 + 5, ship0_shot_list_3_04_01_02);
    STORE_POINTER(ship0_shot_list_3_04_01 + 15, ship0_shot_list_3_04_01_07);
    STORE_POINTER(ship0_shot_list_3_04_01 + 24, ship0_shot_list_3_04_01_02);
    STORE_POINTER(ship0_shot_list_3_04_01 + 34, ship0_shot_list_3_04_01_07);
    STORE_POINTER(ship0_shot_list_3_04_02 + 5, ship0_shot_list_3_04_02_02);
    STORE_POINTER(ship0_shot_list_3_04_02 + 15, ship0_shot_list_3_04_02_07);
    STORE_POINTER(ship0_shot_list_3_04_02 + 24, ship0_shot_list_3_04_02_02);
    STORE_POINTER(ship0_shot_list_3_04_02 + 34, ship0_shot_list_3_04_02_07);
    STORE_POINTER(ship0_shot_list_3_04_03 + 5, ship0_shot_list_3_04_03_02);
    STORE_POINTER(ship0_shot_list_3_04_03 + 15, ship0_shot_list_3_04_03_07);
    STORE_POINTER(ship0_shot_list_3_04_03 + 24, ship0_shot_list_3_04_03_02);
    STORE_POINTER(ship0_shot_list_3_04_03 + 34, ship0_shot_list_3_04_03_07);
    STORE_POINTER(ship0_shot_list_3_04_04 + 5, ship0_shot_list_3_04_04_02);
    STORE_POINTER(ship0_shot_list_3_04_04 + 15, ship0_shot_list_3_04_04_07);
    STORE_POINTER(ship0_shot_list_3_04_04 + 24, ship0_shot_list_3_04_04_02);
    STORE_POINTER(ship0_shot_list_3_04_04 + 34, ship0_shot_list_3_04_04_07);
    STORE_POINTER(player_shot_2_flight_table, player_shot_2_flight_00);
    STORE_POINTER(player_shot_2_flight_table + 2, player_shot_2_flight_01);
    STORE_POINTER(player_shot_2_flight_table + 4, player_shot_2_flight_02);
    STORE_POINTER(player_shot_2_flight_table + 6, player_shot_2_flight_03);
    STORE_POINTER(player_shot_2_flight_table + 8, player_shot_2_flight_04);
    STORE_POINTER(player_shot_2_flight_table + 10, player_shot_2_flight_05);
    STORE_POINTER(player_shot_2_flight_table + 12, player_shot_2_flight_06);
    STORE_POINTER(player_shot_2_flight_table + 14, player_shot_2_flight_07);
    STORE_POINTER(player_shot_2_flight_table + 16, player_shot_2_flight_08);
    STORE_POINTER(player_shot_2_flight_table + 18, player_shot_2_flight_09);
    STORE_POINTER(player_shot_2_flight_table + 20, player_shot_2_flight_10);
    STORE_POINTER(player_shot_2_flight_table + 22, player_shot_2_flight_11);
    STORE_POINTER(player_shot_2_flight_table + 24, player_shot_2_flight_12);
    STORE_POINTER(player_shot_2_flight_table + 26, player_shot_2_flight_13);
    STORE_POINTER(player_shot_2_flight_table + 28, player_shot_2_flight_14);
    STORE_POINTER(player_shot_2_flight_table + 30, player_shot_2_flight_15);
    STORE_POINTER(player_shot_2_flight_table + 32, player_shot_2_flight_16);
    STORE_POINTER(player_shot_2_flight_table + 34, player_shot_2_flight_17);
    STORE_POINTER(player_shot_2_flight_table + 36, player_shot_2_flight_18);
    STORE_POINTER(player_shot_2_flight_table + 38, player_shot_2_flight_19);
    STORE_POINTER(player_shot_2_flight_table + 40, player_shot_2_flight_20);
    STORE_POINTER(player_shot_2_flight_table + 42, player_shot_2_flight_21);
    STORE_POINTER(player_shot_2_flight_table + 44, player_shot_2_flight_22);
    STORE_POINTER(player_shot_2_flight_table + 46, player_shot_2_flight_23);
    STORE_POINTER(player_shot_2_flight_table + 48, player_shot_2_flight_24);
    STORE_POINTER(player_shot_2_impact_table, player_shot_2_impact_00);
    STORE_POINTER(player_shot_2_impact_table + 2, player_shot_2_impact_01);
    STORE_POINTER(player_shot_2_impact_table + 4, player_shot_2_impact_02);
    STORE_POINTER(player_shot_2_impact_table + 6, player_shot_2_impact_03);
    STORE_POINTER(player_shot_2_impact_table + 8, player_shot_2_impact_04);
    STORE_POINTER(player_shot_2_impact_table + 10, player_shot_2_impact_05);
    STORE_POINTER(player_shot_2_impact_table + 12, player_shot_2_impact_06);
    STORE_POINTER(player_shot_2_impact_table + 14, player_shot_2_impact_07);
    STORE_POINTER(player_shot_2_impact_table + 16, player_shot_2_impact_08);
    STORE_POINTER(player_shot_2_impact_table + 18, player_shot_2_impact_09);
    STORE_POINTER(player_shot_2_impact_table + 20, player_shot_2_impact_10);
    STORE_POINTER(player_shot_2_impact_table + 22, player_shot_2_impact_11);
    STORE_POINTER(player_shot_2_impact_table + 24, player_shot_2_impact_12);
    STORE_POINTER(player_shot_2_impact_table + 26, player_shot_2_impact_13);
    STORE_POINTER(player_shot_2_impact_table + 28, player_shot_2_impact_14);
    STORE_POINTER(player_shot_2_impact_table + 30, player_shot_2_impact_15);
    STORE_POINTER(player_shot_2_impact_table + 32, player_shot_2_impact_16);
    STORE_POINTER(player_shot_2_impact_table + 34, player_shot_2_impact_17);
    STORE_POINTER(player_shot_2_impact_table + 36, player_shot_2_impact_18);
    STORE_POINTER(player_shot_2_impact_table + 38, player_shot_2_impact_19);
    STORE_POINTER(player_shot_2_impact_table + 40, player_shot_2_impact_20);
    STORE_POINTER(player_shot_2_impact_table + 42, player_shot_2_impact_21);
    STORE_POINTER(player_shot_2_impact_table + 44, player_shot_2_impact_22);
    STORE_POINTER(player_shot_2_impact_table + 46, player_shot_2_impact_23);
    STORE_POINTER(player_shot_2_impact_table + 48, player_shot_2_impact_24);
    STORE_POINTER(player_shot_2_impact_00 + 3, player_shot_2_impact_frames_00);
    STORE_POINTER(player_shot_2_impact_01 + 3, player_shot_2_impact_frames_00);
    STORE_POINTER(player_shot_2_impact_02 + 3, player_shot_2_impact_frames_02);
    STORE_POINTER(player_shot_2_impact_03 + 3, player_shot_2_impact_frames_02);
    STORE_POINTER(player_shot_2_impact_04 + 3, player_shot_2_impact_frames_04);
    STORE_POINTER(player_shot_2_impact_05 + 3, player_shot_2_impact_frames_04);
    STORE_POINTER(player_shot_2_impact_06 + 3, player_shot_2_impact_frames_06);
    STORE_POINTER(player_shot_2_impact_07 + 3, player_shot_2_impact_frames_06);
    STORE_POINTER(player_shot_2_impact_08 + 3, player_shot_2_impact_frames_08);
    STORE_POINTER(player_shot_2_impact_09 + 3, player_shot_2_impact_frames_08);
    STORE_POINTER(player_shot_2_impact_10 + 3, player_shot_2_impact_frames_10);
    STORE_POINTER(player_shot_2_impact_11 + 3, player_shot_2_impact_frames_11);
    STORE_POINTER(player_shot_2_impact_12 + 3, player_shot_2_impact_frames_12);
    STORE_POINTER(player_shot_2_impact_13 + 3, player_shot_2_impact_frames_13);
    STORE_POINTER(player_shot_2_impact_14 + 3, player_shot_2_impact_frames_14);
    STORE_POINTER(player_shot_2_impact_15 + 3, player_shot_2_impact_frames_15);
    STORE_POINTER(player_shot_2_impact_16 + 3, player_shot_2_impact_frames_15);
    STORE_POINTER(player_shot_2_impact_17 + 3, player_shot_2_impact_frames_17);
    STORE_POINTER(player_shot_2_impact_18 + 3, player_shot_2_impact_frames_17);
    STORE_POINTER(player_shot_2_impact_19 + 3, player_shot_2_impact_frames_19);
    STORE_POINTER(player_shot_2_impact_20 + 3, player_shot_2_impact_frames_19);
    STORE_POINTER(player_shot_2_impact_21 + 3, player_shot_2_impact_frames_21);
    STORE_POINTER(player_shot_2_impact_22 + 3, player_shot_2_impact_frames_21);
    STORE_POINTER(player_shot_2_impact_23 + 3, player_shot_2_impact_frames_23);
    STORE_POINTER(player_shot_2_impact_24 + 3, player_shot_2_impact_frames_23);
}

extern u16 ship0_shot_list_1_01_00_02[];
extern u16 ship0_shot_list_1_03_00_02[];
extern u16 ship0_shot_list_1_05_00_02[];
extern u16 player_shot_5_impact_frames_00[];
extern u16 player_shot_5_impact_frames_02[];
extern u16 player_shot_5_impact_frames_04[];
extern u16 player_shot_5_impact_frames_06[];
extern u16 player_shot_5_impact_frames_08[];
extern u16 player_shot_5_impact_frames_10[];
extern u16 player_shot_5_impact_frames_11[];
extern u16 player_shot_5_impact_frames_12[];
extern u16 player_shot_5_impact_frames_13[];
extern u16 player_shot_5_impact_frames_14[];
extern u16 player_shot_5_impact_frames_15[];
extern u16 player_shot_5_impact_frames_17[];
extern u16 player_shot_5_impact_frames_19[];
extern u16 player_shot_5_impact_frames_21[];
extern u16 player_shot_5_impact_frames_23[];
extern u16 player_shot_5_impact_00[];
extern u16 player_shot_5_impact_01[];
extern u16 player_shot_5_impact_02[];
extern u16 player_shot_5_impact_03[];
extern u16 player_shot_5_impact_04[];
extern u16 player_shot_5_impact_05[];
extern u16 player_shot_5_impact_06[];
extern u16 player_shot_5_impact_07[];
extern u16 player_shot_5_impact_08[];
extern u16 player_shot_5_impact_09[];
extern u16 player_shot_5_impact_10[];
extern u16 player_shot_5_impact_11[];
extern u16 player_shot_5_impact_12[];
extern u16 player_shot_5_impact_13[];
extern u16 player_shot_5_impact_14[];
extern u16 player_shot_5_impact_15[];
extern u16 player_shot_5_impact_16[];
extern u16 player_shot_5_impact_17[];
extern u16 player_shot_5_impact_18[];
extern u16 player_shot_5_impact_19[];
extern u16 player_shot_5_impact_20[];
extern u16 player_shot_5_impact_21[];
extern u16 player_shot_5_impact_22[];
extern u16 player_shot_5_impact_23[];
extern u16 player_shot_5_impact_24[];
extern u16 ship0_shot_list_1_01_00_07[];
extern u16 ship0_shot_list_1_03_00_07[];
extern u16 ship0_shot_list_1_05_00_07[];
extern u16 player_shot_5_flight_00[];
extern u16 player_shot_5_flight_01[];
extern u16 player_shot_5_flight_02[];
extern u16 player_shot_5_flight_03[];
extern u16 player_shot_5_flight_04[];
extern u16 player_shot_5_flight_05[];
extern u16 player_shot_5_flight_06[];
extern u16 player_shot_5_flight_07[];
extern u16 player_shot_5_flight_08[];
extern u16 player_shot_5_flight_09[];
extern u16 player_shot_5_flight_10[];
extern u16 player_shot_5_flight_11[];
extern u16 player_shot_5_flight_12[];
extern u16 player_shot_5_flight_13[];
extern u16 player_shot_5_flight_14[];
extern u16 player_shot_5_flight_15[];
extern u16 player_shot_5_flight_16[];
extern u16 player_shot_5_flight_17[];
extern u16 player_shot_5_flight_18[];
extern u16 player_shot_5_flight_19[];
extern u16 player_shot_5_flight_20[];
extern u16 player_shot_5_flight_21[];
extern u16 player_shot_5_flight_22[];
extern u16 player_shot_5_flight_23[];
extern u16 player_shot_5_flight_24[];

extern u16 player_shot_5_flight_table[];
extern u16 player_shot_5_impact_table[];

void player_shot_5_tables_init(void) {
    STORE_POINTER(ship0_shot_list_1_01_00 + 5, ship0_shot_list_1_01_00_02);
    STORE_POINTER(ship0_shot_list_1_01_00 + 15, ship0_shot_list_1_01_00_07);
    STORE_POINTER(ship0_shot_list_2_01_00 + 5, ship0_shot_list_1_01_00_02);
    STORE_POINTER(ship0_shot_list_2_01_00 + 15, ship0_shot_list_1_01_00_07);
    STORE_POINTER(ship0_shot_list_1_01_01 + 5, ship0_shot_list_1_01_00_02);
    STORE_POINTER(ship0_shot_list_1_01_01 + 15, ship0_shot_list_1_01_00_07);
    STORE_POINTER(ship0_shot_list_2_01_01 + 5, ship0_shot_list_1_01_00_02);
    STORE_POINTER(ship0_shot_list_2_01_01 + 15, ship0_shot_list_1_01_00_07);
    STORE_POINTER(ship0_shot_list_1_01_02 + 5, ship0_shot_list_1_01_00_02);
    STORE_POINTER(ship0_shot_list_1_01_02 + 15, ship0_shot_list_1_01_00_07);
    STORE_POINTER(ship0_shot_list_2_01_02 + 5, ship0_shot_list_1_01_00_02);
    STORE_POINTER(ship0_shot_list_2_01_02 + 15, ship0_shot_list_1_01_00_07);
    STORE_POINTER(ship0_shot_list_1_01_03 + 5, ship0_shot_list_1_01_00_02);
    STORE_POINTER(ship0_shot_list_1_01_03 + 15, ship0_shot_list_1_01_00_07);
    STORE_POINTER(ship0_shot_list_2_01_03 + 5, ship0_shot_list_1_01_00_02);
    STORE_POINTER(ship0_shot_list_2_01_03 + 15, ship0_shot_list_1_01_00_07);
    STORE_POINTER(ship0_shot_list_1_01_04 + 5, ship0_shot_list_1_01_00_02);
    STORE_POINTER(ship0_shot_list_1_01_04 + 15, ship0_shot_list_1_01_00_07);
    STORE_POINTER(ship0_shot_list_2_01_04 + 5, ship0_shot_list_1_01_00_02);
    STORE_POINTER(ship0_shot_list_2_01_04 + 15, ship0_shot_list_1_01_00_07);
    STORE_POINTER(ship0_shot_list_1_03_00 + 5, ship0_shot_list_1_03_00_02);
    STORE_POINTER(ship0_shot_list_1_03_00 + 15, ship0_shot_list_1_03_00_07);
    STORE_POINTER(ship0_shot_list_1_03_01 + 5, ship0_shot_list_1_03_00_02);
    STORE_POINTER(ship0_shot_list_1_03_01 + 15, ship0_shot_list_1_03_00_07);
    STORE_POINTER(ship0_shot_list_1_03_02 + 5, ship0_shot_list_1_03_00_02);
    STORE_POINTER(ship0_shot_list_1_03_02 + 15, ship0_shot_list_1_03_00_07);
    STORE_POINTER(ship0_shot_list_1_03_03 + 5, ship0_shot_list_1_03_00_02);
    STORE_POINTER(ship0_shot_list_1_03_03 + 15, ship0_shot_list_1_03_00_07);
    STORE_POINTER(ship0_shot_list_1_03_04 + 5, ship0_shot_list_1_03_00_02);
    STORE_POINTER(ship0_shot_list_1_03_04 + 15, ship0_shot_list_1_03_00_07);
    STORE_POINTER(ship0_shot_list_1_05_00 + 5, ship0_shot_list_1_05_00_02);
    STORE_POINTER(ship0_shot_list_1_05_00 + 15, ship0_shot_list_1_05_00_07);
    STORE_POINTER(ship0_shot_list_2_05_00 + 5, ship0_shot_list_1_05_00_02);
    STORE_POINTER(ship0_shot_list_2_05_00 + 15, ship0_shot_list_1_05_00_07);
    STORE_POINTER(ship0_shot_list_1_05_01 + 5, ship0_shot_list_1_05_00_02);
    STORE_POINTER(ship0_shot_list_1_05_01 + 15, ship0_shot_list_1_05_00_07);
    STORE_POINTER(ship0_shot_list_2_05_01 + 5, ship0_shot_list_1_05_00_02);
    STORE_POINTER(ship0_shot_list_2_05_01 + 15, ship0_shot_list_1_05_00_07);
    STORE_POINTER(ship0_shot_list_1_05_02 + 5, ship0_shot_list_1_05_00_02);
    STORE_POINTER(ship0_shot_list_1_05_02 + 15, ship0_shot_list_1_05_00_07);
    STORE_POINTER(ship0_shot_list_2_05_02 + 5, ship0_shot_list_1_05_00_02);
    STORE_POINTER(ship0_shot_list_2_05_02 + 15, ship0_shot_list_1_05_00_07);
    STORE_POINTER(ship0_shot_list_1_05_03 + 5, ship0_shot_list_1_05_00_02);
    STORE_POINTER(ship0_shot_list_1_05_03 + 15, ship0_shot_list_1_05_00_07);
    STORE_POINTER(ship0_shot_list_2_05_03 + 5, ship0_shot_list_1_05_00_02);
    STORE_POINTER(ship0_shot_list_2_05_03 + 15, ship0_shot_list_1_05_00_07);
    STORE_POINTER(ship0_shot_list_1_05_04 + 5, ship0_shot_list_1_05_00_02);
    STORE_POINTER(ship0_shot_list_1_05_04 + 15, ship0_shot_list_1_05_00_07);
    STORE_POINTER(ship0_shot_list_2_05_04 + 5, ship0_shot_list_1_05_00_02);
    STORE_POINTER(ship0_shot_list_2_05_04 + 15, ship0_shot_list_1_05_00_07);
    STORE_POINTER(player_shot_5_flight_table, player_shot_5_flight_00);
    STORE_POINTER(player_shot_5_flight_table + 2, player_shot_5_flight_01);
    STORE_POINTER(player_shot_5_flight_table + 4, player_shot_5_flight_02);
    STORE_POINTER(player_shot_5_flight_table + 6, player_shot_5_flight_03);
    STORE_POINTER(player_shot_5_flight_table + 8, player_shot_5_flight_04);
    STORE_POINTER(player_shot_5_flight_table + 10, player_shot_5_flight_05);
    STORE_POINTER(player_shot_5_flight_table + 12, player_shot_5_flight_06);
    STORE_POINTER(player_shot_5_flight_table + 14, player_shot_5_flight_07);
    STORE_POINTER(player_shot_5_flight_table + 16, player_shot_5_flight_08);
    STORE_POINTER(player_shot_5_flight_table + 18, player_shot_5_flight_09);
    STORE_POINTER(player_shot_5_flight_table + 20, player_shot_5_flight_10);
    STORE_POINTER(player_shot_5_flight_table + 22, player_shot_5_flight_11);
    STORE_POINTER(player_shot_5_flight_table + 24, player_shot_5_flight_12);
    STORE_POINTER(player_shot_5_flight_table + 26, player_shot_5_flight_13);
    STORE_POINTER(player_shot_5_flight_table + 28, player_shot_5_flight_14);
    STORE_POINTER(player_shot_5_flight_table + 30, player_shot_5_flight_15);
    STORE_POINTER(player_shot_5_flight_table + 32, player_shot_5_flight_16);
    STORE_POINTER(player_shot_5_flight_table + 34, player_shot_5_flight_17);
    STORE_POINTER(player_shot_5_flight_table + 36, player_shot_5_flight_18);
    STORE_POINTER(player_shot_5_flight_table + 38, player_shot_5_flight_19);
    STORE_POINTER(player_shot_5_flight_table + 40, player_shot_5_flight_20);
    STORE_POINTER(player_shot_5_flight_table + 42, player_shot_5_flight_21);
    STORE_POINTER(player_shot_5_flight_table + 44, player_shot_5_flight_22);
    STORE_POINTER(player_shot_5_flight_table + 46, player_shot_5_flight_23);
    STORE_POINTER(player_shot_5_flight_table + 48, player_shot_5_flight_24);
    STORE_POINTER(player_shot_5_impact_table, player_shot_5_impact_00);
    STORE_POINTER(player_shot_5_impact_table + 2, player_shot_5_impact_01);
    STORE_POINTER(player_shot_5_impact_table + 4, player_shot_5_impact_02);
    STORE_POINTER(player_shot_5_impact_table + 6, player_shot_5_impact_03);
    STORE_POINTER(player_shot_5_impact_table + 8, player_shot_5_impact_04);
    STORE_POINTER(player_shot_5_impact_table + 10, player_shot_5_impact_05);
    STORE_POINTER(player_shot_5_impact_table + 12, player_shot_5_impact_06);
    STORE_POINTER(player_shot_5_impact_table + 14, player_shot_5_impact_07);
    STORE_POINTER(player_shot_5_impact_table + 16, player_shot_5_impact_08);
    STORE_POINTER(player_shot_5_impact_table + 18, player_shot_5_impact_09);
    STORE_POINTER(player_shot_5_impact_table + 20, player_shot_5_impact_10);
    STORE_POINTER(player_shot_5_impact_table + 22, player_shot_5_impact_11);
    STORE_POINTER(player_shot_5_impact_table + 24, player_shot_5_impact_12);
    STORE_POINTER(player_shot_5_impact_table + 26, player_shot_5_impact_13);
    STORE_POINTER(player_shot_5_impact_table + 28, player_shot_5_impact_14);
    STORE_POINTER(player_shot_5_impact_table + 30, player_shot_5_impact_15);
    STORE_POINTER(player_shot_5_impact_table + 32, player_shot_5_impact_16);
    STORE_POINTER(player_shot_5_impact_table + 34, player_shot_5_impact_17);
    STORE_POINTER(player_shot_5_impact_table + 36, player_shot_5_impact_18);
    STORE_POINTER(player_shot_5_impact_table + 38, player_shot_5_impact_19);
    STORE_POINTER(player_shot_5_impact_table + 40, player_shot_5_impact_20);
    STORE_POINTER(player_shot_5_impact_table + 42, player_shot_5_impact_21);
    STORE_POINTER(player_shot_5_impact_table + 44, player_shot_5_impact_22);
    STORE_POINTER(player_shot_5_impact_table + 46, player_shot_5_impact_23);
    STORE_POINTER(player_shot_5_impact_table + 48, player_shot_5_impact_24);
    STORE_POINTER(player_shot_5_impact_00 + 3, player_shot_5_impact_frames_00);
    STORE_POINTER(player_shot_5_impact_01 + 3, player_shot_5_impact_frames_00);
    STORE_POINTER(player_shot_5_impact_02 + 3, player_shot_5_impact_frames_02);
    STORE_POINTER(player_shot_5_impact_03 + 3, player_shot_5_impact_frames_02);
    STORE_POINTER(player_shot_5_impact_04 + 3, player_shot_5_impact_frames_04);
    STORE_POINTER(player_shot_5_impact_05 + 3, player_shot_5_impact_frames_04);
    STORE_POINTER(player_shot_5_impact_06 + 3, player_shot_5_impact_frames_06);
    STORE_POINTER(player_shot_5_impact_07 + 3, player_shot_5_impact_frames_06);
    STORE_POINTER(player_shot_5_impact_08 + 3, player_shot_5_impact_frames_08);
    STORE_POINTER(player_shot_5_impact_09 + 3, player_shot_5_impact_frames_08);
    STORE_POINTER(player_shot_5_impact_10 + 3, player_shot_5_impact_frames_10);
    STORE_POINTER(player_shot_5_impact_11 + 3, player_shot_5_impact_frames_11);
    STORE_POINTER(player_shot_5_impact_12 + 3, player_shot_5_impact_frames_12);
    STORE_POINTER(player_shot_5_impact_13 + 3, player_shot_5_impact_frames_13);
    STORE_POINTER(player_shot_5_impact_14 + 3, player_shot_5_impact_frames_14);
    STORE_POINTER(player_shot_5_impact_15 + 3, player_shot_5_impact_frames_15);
    STORE_POINTER(player_shot_5_impact_16 + 3, player_shot_5_impact_frames_15);
    STORE_POINTER(player_shot_5_impact_17 + 3, player_shot_5_impact_frames_17);
    STORE_POINTER(player_shot_5_impact_18 + 3, player_shot_5_impact_frames_17);
    STORE_POINTER(player_shot_5_impact_19 + 3, player_shot_5_impact_frames_19);
    STORE_POINTER(player_shot_5_impact_20 + 3, player_shot_5_impact_frames_19);
    STORE_POINTER(player_shot_5_impact_21 + 3, player_shot_5_impact_frames_21);
    STORE_POINTER(player_shot_5_impact_22 + 3, player_shot_5_impact_frames_21);
    STORE_POINTER(player_shot_5_impact_23 + 3, player_shot_5_impact_frames_23);
    STORE_POINTER(player_shot_5_impact_24 + 3, player_shot_5_impact_frames_23);
}

extern u16 ship0_shot_list_3_01_00_02[];
extern u16 ship0_shot_list_3_03_00_02[];
extern u16 ship0_shot_list_3_05_00_02[];
extern u16 player_shot_6_impact_frames_00[];
extern u16 player_shot_6_impact_frames_02[];
extern u16 player_shot_6_impact_frames_04[];
extern u16 player_shot_6_impact_frames_06[];
extern u16 player_shot_6_impact_frames_08[];
extern u16 player_shot_6_impact_frames_10[];
extern u16 player_shot_6_impact_frames_11[];
extern u16 player_shot_6_impact_frames_12[];
extern u16 player_shot_6_impact_frames_13[];
extern u16 player_shot_6_impact_frames_14[];
extern u16 player_shot_6_impact_frames_15[];
extern u16 player_shot_6_impact_frames_17[];
extern u16 player_shot_6_impact_frames_19[];
extern u16 player_shot_6_impact_frames_21[];
extern u16 player_shot_6_impact_frames_23[];
extern u16 player_shot_6_impact_00[];
extern u16 player_shot_6_impact_01[];
extern u16 player_shot_6_impact_02[];
extern u16 player_shot_6_impact_03[];
extern u16 player_shot_6_impact_04[];
extern u16 player_shot_6_impact_05[];
extern u16 player_shot_6_impact_06[];
extern u16 player_shot_6_impact_07[];
extern u16 player_shot_6_impact_08[];
extern u16 player_shot_6_impact_09[];
extern u16 player_shot_6_impact_10[];
extern u16 player_shot_6_impact_11[];
extern u16 player_shot_6_impact_12[];
extern u16 player_shot_6_impact_13[];
extern u16 player_shot_6_impact_14[];
extern u16 player_shot_6_impact_15[];
extern u16 player_shot_6_impact_16[];
extern u16 player_shot_6_impact_17[];
extern u16 player_shot_6_impact_18[];
extern u16 player_shot_6_impact_19[];
extern u16 player_shot_6_impact_20[];
extern u16 player_shot_6_impact_21[];
extern u16 player_shot_6_impact_22[];
extern u16 player_shot_6_impact_23[];
extern u16 player_shot_6_impact_24[];
extern u16 ship0_shot_list_3_01_00_07[];
extern u16 ship0_shot_list_3_03_00_07[];
extern u16 ship0_shot_list_3_05_00_07[];
extern u16 player_shot_6_flight_00[];
extern u16 player_shot_6_flight_01[];
extern u16 player_shot_6_flight_02[];
extern u16 player_shot_6_flight_03[];
extern u16 player_shot_6_flight_04[];
extern u16 player_shot_6_flight_05[];
extern u16 player_shot_6_flight_06[];
extern u16 player_shot_6_flight_07[];
extern u16 player_shot_6_flight_08[];
extern u16 player_shot_6_flight_09[];
extern u16 player_shot_6_flight_10[];
extern u16 player_shot_6_flight_11[];
extern u16 player_shot_6_flight_12[];
extern u16 player_shot_6_flight_13[];
extern u16 player_shot_6_flight_14[];
extern u16 player_shot_6_flight_15[];
extern u16 player_shot_6_flight_16[];
extern u16 player_shot_6_flight_17[];
extern u16 player_shot_6_flight_18[];
extern u16 player_shot_6_flight_19[];
extern u16 player_shot_6_flight_20[];
extern u16 player_shot_6_flight_21[];
extern u16 player_shot_6_flight_22[];
extern u16 player_shot_6_flight_23[];
extern u16 player_shot_6_flight_24[];

extern u16 player_shot_6_flight_table[];
extern u16 player_shot_6_impact_table[];

void player_shot_6_tables_init(void) {
    STORE_POINTER(ship0_shot_list_3_01_00 + 5, ship0_shot_list_3_01_00_02);
    STORE_POINTER(ship0_shot_list_3_01_00 + 15, ship0_shot_list_3_01_00_07);
    STORE_POINTER(ship0_shot_list_3_01_00 + 24, ship0_shot_list_3_01_00_02);
    STORE_POINTER(ship0_shot_list_3_01_00 + 34, ship0_shot_list_3_01_00_07);
    STORE_POINTER(ship0_shot_list_3_01_01 + 5, ship0_shot_list_3_01_00_02);
    STORE_POINTER(ship0_shot_list_3_01_01 + 15, ship0_shot_list_3_01_00_07);
    STORE_POINTER(ship0_shot_list_3_01_01 + 24, ship0_shot_list_3_01_00_02);
    STORE_POINTER(ship0_shot_list_3_01_01 + 34, ship0_shot_list_3_01_00_07);
    STORE_POINTER(ship0_shot_list_3_01_02 + 5, ship0_shot_list_3_01_00_02);
    STORE_POINTER(ship0_shot_list_3_01_02 + 15, ship0_shot_list_3_01_00_07);
    STORE_POINTER(ship0_shot_list_3_01_02 + 24, ship0_shot_list_3_01_00_02);
    STORE_POINTER(ship0_shot_list_3_01_02 + 34, ship0_shot_list_3_01_00_07);
    STORE_POINTER(ship0_shot_list_3_01_03 + 5, ship0_shot_list_3_01_00_02);
    STORE_POINTER(ship0_shot_list_3_01_03 + 15, ship0_shot_list_3_01_00_07);
    STORE_POINTER(ship0_shot_list_3_01_03 + 24, ship0_shot_list_3_01_00_02);
    STORE_POINTER(ship0_shot_list_3_01_03 + 34, ship0_shot_list_3_01_00_07);
    STORE_POINTER(ship0_shot_list_3_01_04 + 5, ship0_shot_list_3_01_00_02);
    STORE_POINTER(ship0_shot_list_3_01_04 + 15, ship0_shot_list_3_01_00_07);
    STORE_POINTER(ship0_shot_list_3_01_04 + 24, ship0_shot_list_3_01_00_02);
    STORE_POINTER(ship0_shot_list_3_01_04 + 34, ship0_shot_list_3_01_00_07);
    STORE_POINTER(ship0_shot_list_3_03_00 + 5, ship0_shot_list_3_03_00_02);
    STORE_POINTER(ship0_shot_list_3_03_00 + 15, ship0_shot_list_3_03_00_07);
    STORE_POINTER(ship0_shot_list_3_03_01 + 5, ship0_shot_list_3_03_00_02);
    STORE_POINTER(ship0_shot_list_3_03_01 + 15, ship0_shot_list_3_03_00_07);
    STORE_POINTER(ship0_shot_list_3_03_02 + 5, ship0_shot_list_3_03_00_02);
    STORE_POINTER(ship0_shot_list_3_03_02 + 15, ship0_shot_list_3_03_00_07);
    STORE_POINTER(ship0_shot_list_3_03_03 + 5, ship0_shot_list_3_03_00_02);
    STORE_POINTER(ship0_shot_list_3_03_03 + 15, ship0_shot_list_3_03_00_07);
    STORE_POINTER(ship0_shot_list_3_03_04 + 5, ship0_shot_list_3_03_00_02);
    STORE_POINTER(ship0_shot_list_3_03_04 + 15, ship0_shot_list_3_03_00_07);
    STORE_POINTER(ship0_shot_list_3_05_00 + 5, ship0_shot_list_3_05_00_02);
    STORE_POINTER(ship0_shot_list_3_05_00 + 15, ship0_shot_list_3_05_00_07);
    STORE_POINTER(ship0_shot_list_3_05_00 + 24, ship0_shot_list_3_05_00_02);
    STORE_POINTER(ship0_shot_list_3_05_00 + 34, ship0_shot_list_3_05_00_07);
    STORE_POINTER(ship0_shot_list_3_05_01 + 5, ship0_shot_list_3_05_00_02);
    STORE_POINTER(ship0_shot_list_3_05_01 + 15, ship0_shot_list_3_05_00_07);
    STORE_POINTER(ship0_shot_list_3_05_01 + 24, ship0_shot_list_3_05_00_02);
    STORE_POINTER(ship0_shot_list_3_05_01 + 34, ship0_shot_list_3_05_00_07);
    STORE_POINTER(ship0_shot_list_3_05_02 + 5, ship0_shot_list_3_05_00_02);
    STORE_POINTER(ship0_shot_list_3_05_02 + 15, ship0_shot_list_3_05_00_07);
    STORE_POINTER(ship0_shot_list_3_05_02 + 24, ship0_shot_list_3_05_00_02);
    STORE_POINTER(ship0_shot_list_3_05_02 + 34, ship0_shot_list_3_05_00_07);
    STORE_POINTER(ship0_shot_list_3_05_03 + 5, ship0_shot_list_3_05_00_02);
    STORE_POINTER(ship0_shot_list_3_05_03 + 15, ship0_shot_list_3_05_00_07);
    STORE_POINTER(ship0_shot_list_3_05_03 + 24, ship0_shot_list_3_05_00_02);
    STORE_POINTER(ship0_shot_list_3_05_03 + 34, ship0_shot_list_3_05_00_07);
    STORE_POINTER(ship0_shot_list_3_05_04 + 5, ship0_shot_list_3_05_00_02);
    STORE_POINTER(ship0_shot_list_3_05_04 + 15, ship0_shot_list_3_05_00_07);
    STORE_POINTER(ship0_shot_list_3_05_04 + 24, ship0_shot_list_3_05_00_02);
    STORE_POINTER(ship0_shot_list_3_05_04 + 34, ship0_shot_list_3_05_00_07);
    STORE_POINTER(player_shot_6_flight_table, player_shot_6_flight_00);
    STORE_POINTER(player_shot_6_flight_table + 2, player_shot_6_flight_01);
    STORE_POINTER(player_shot_6_flight_table + 4, player_shot_6_flight_02);
    STORE_POINTER(player_shot_6_flight_table + 6, player_shot_6_flight_03);
    STORE_POINTER(player_shot_6_flight_table + 8, player_shot_6_flight_04);
    STORE_POINTER(player_shot_6_flight_table + 10, player_shot_6_flight_05);
    STORE_POINTER(player_shot_6_flight_table + 12, player_shot_6_flight_06);
    STORE_POINTER(player_shot_6_flight_table + 14, player_shot_6_flight_07);
    STORE_POINTER(player_shot_6_flight_table + 16, player_shot_6_flight_08);
    STORE_POINTER(player_shot_6_flight_table + 18, player_shot_6_flight_09);
    STORE_POINTER(player_shot_6_flight_table + 20, player_shot_6_flight_10);
    STORE_POINTER(player_shot_6_flight_table + 22, player_shot_6_flight_11);
    STORE_POINTER(player_shot_6_flight_table + 24, player_shot_6_flight_12);
    STORE_POINTER(player_shot_6_flight_table + 26, player_shot_6_flight_13);
    STORE_POINTER(player_shot_6_flight_table + 28, player_shot_6_flight_14);
    STORE_POINTER(player_shot_6_flight_table + 30, player_shot_6_flight_15);
    STORE_POINTER(player_shot_6_flight_table + 32, player_shot_6_flight_16);
    STORE_POINTER(player_shot_6_flight_table + 34, player_shot_6_flight_17);
    STORE_POINTER(player_shot_6_flight_table + 36, player_shot_6_flight_18);
    STORE_POINTER(player_shot_6_flight_table + 38, player_shot_6_flight_19);
    STORE_POINTER(player_shot_6_flight_table + 40, player_shot_6_flight_20);
    STORE_POINTER(player_shot_6_flight_table + 42, player_shot_6_flight_21);
    STORE_POINTER(player_shot_6_flight_table + 44, player_shot_6_flight_22);
    STORE_POINTER(player_shot_6_flight_table + 46, player_shot_6_flight_23);
    STORE_POINTER(player_shot_6_flight_table + 48, player_shot_6_flight_24);
    STORE_POINTER(player_shot_6_impact_table, player_shot_6_impact_00);
    STORE_POINTER(player_shot_6_impact_table + 2, player_shot_6_impact_01);
    STORE_POINTER(player_shot_6_impact_table + 4, player_shot_6_impact_02);
    STORE_POINTER(player_shot_6_impact_table + 6, player_shot_6_impact_03);
    STORE_POINTER(player_shot_6_impact_table + 8, player_shot_6_impact_04);
    STORE_POINTER(player_shot_6_impact_table + 10, player_shot_6_impact_05);
    STORE_POINTER(player_shot_6_impact_table + 12, player_shot_6_impact_06);
    STORE_POINTER(player_shot_6_impact_table + 14, player_shot_6_impact_07);
    STORE_POINTER(player_shot_6_impact_table + 16, player_shot_6_impact_08);
    STORE_POINTER(player_shot_6_impact_table + 18, player_shot_6_impact_09);
    STORE_POINTER(player_shot_6_impact_table + 20, player_shot_6_impact_10);
    STORE_POINTER(player_shot_6_impact_table + 22, player_shot_6_impact_11);
    STORE_POINTER(player_shot_6_impact_table + 24, player_shot_6_impact_12);
    STORE_POINTER(player_shot_6_impact_table + 26, player_shot_6_impact_13);
    STORE_POINTER(player_shot_6_impact_table + 28, player_shot_6_impact_14);
    STORE_POINTER(player_shot_6_impact_table + 30, player_shot_6_impact_15);
    STORE_POINTER(player_shot_6_impact_table + 32, player_shot_6_impact_16);
    STORE_POINTER(player_shot_6_impact_table + 34, player_shot_6_impact_17);
    STORE_POINTER(player_shot_6_impact_table + 36, player_shot_6_impact_18);
    STORE_POINTER(player_shot_6_impact_table + 38, player_shot_6_impact_19);
    STORE_POINTER(player_shot_6_impact_table + 40, player_shot_6_impact_20);
    STORE_POINTER(player_shot_6_impact_table + 42, player_shot_6_impact_21);
    STORE_POINTER(player_shot_6_impact_table + 44, player_shot_6_impact_22);
    STORE_POINTER(player_shot_6_impact_table + 46, player_shot_6_impact_23);
    STORE_POINTER(player_shot_6_impact_table + 48, player_shot_6_impact_24);
    STORE_POINTER(player_shot_6_impact_00 + 3, player_shot_6_impact_frames_00);
    STORE_POINTER(player_shot_6_impact_01 + 3, player_shot_6_impact_frames_00);
    STORE_POINTER(player_shot_6_impact_02 + 3, player_shot_6_impact_frames_02);
    STORE_POINTER(player_shot_6_impact_03 + 3, player_shot_6_impact_frames_02);
    STORE_POINTER(player_shot_6_impact_04 + 3, player_shot_6_impact_frames_04);
    STORE_POINTER(player_shot_6_impact_05 + 3, player_shot_6_impact_frames_04);
    STORE_POINTER(player_shot_6_impact_06 + 3, player_shot_6_impact_frames_06);
    STORE_POINTER(player_shot_6_impact_07 + 3, player_shot_6_impact_frames_06);
    STORE_POINTER(player_shot_6_impact_08 + 3, player_shot_6_impact_frames_08);
    STORE_POINTER(player_shot_6_impact_09 + 3, player_shot_6_impact_frames_08);
    STORE_POINTER(player_shot_6_impact_10 + 3, player_shot_6_impact_frames_10);
    STORE_POINTER(player_shot_6_impact_11 + 3, player_shot_6_impact_frames_11);
    STORE_POINTER(player_shot_6_impact_12 + 3, player_shot_6_impact_frames_12);
    STORE_POINTER(player_shot_6_impact_13 + 3, player_shot_6_impact_frames_13);
    STORE_POINTER(player_shot_6_impact_14 + 3, player_shot_6_impact_frames_14);
    STORE_POINTER(player_shot_6_impact_15 + 3, player_shot_6_impact_frames_15);
    STORE_POINTER(player_shot_6_impact_16 + 3, player_shot_6_impact_frames_15);
    STORE_POINTER(player_shot_6_impact_17 + 3, player_shot_6_impact_frames_17);
    STORE_POINTER(player_shot_6_impact_18 + 3, player_shot_6_impact_frames_17);
    STORE_POINTER(player_shot_6_impact_19 + 3, player_shot_6_impact_frames_19);
    STORE_POINTER(player_shot_6_impact_20 + 3, player_shot_6_impact_frames_19);
    STORE_POINTER(player_shot_6_impact_21 + 3, player_shot_6_impact_frames_21);
    STORE_POINTER(player_shot_6_impact_22 + 3, player_shot_6_impact_frames_21);
    STORE_POINTER(player_shot_6_impact_23 + 3, player_shot_6_impact_frames_23);
    STORE_POINTER(player_shot_6_impact_24 + 3, player_shot_6_impact_frames_23);
}

extern u16 option_shot_list_1_00_00_02[];
extern u16 option_shot_list_1_00_02_02[];
extern u16 option_shot_list_1_00_04_02[];
extern u16 option_shot_list_3_00_00_02[];
extern u16 option_shot_list_3_00_02_02[];
extern u16 option_shot_list_3_00_04_02[];
extern u16 option_shot_list_4_00_00_02[];
extern u16 option_shot_list_4_00_02_02[];
extern u16 option_shot_list_4_00_04_02[];
extern u16 player_shot_3_impact_frames_00[];
extern u16 player_shot_3_impact_frames_04[];
extern u16 player_shot_3_impact_frames_08[];
extern u16 player_shot_3_impact_frames_10[];
extern u16 player_shot_3_impact_frames_12[];
extern u16 player_shot_3_impact_frames_14[];
extern u16 player_shot_3_impact_frames_15[];
extern u16 player_shot_3_impact_frames_19[];
extern u16 player_shot_3_impact_frames_23[];
extern u16 option_shot_list_3_00_00_00[];
extern u16 option_shot_list_3_00_00_00_00[];
extern u16 option_shot_list_3_00_00_00_13[];
extern u16 option_shot_list_3_00_01_00[];
extern u16 option_shot_list_3_00_02_00[];
extern u16 option_shot_list_3_00_03_00[];
extern u16 option_shot_list_3_00_04_00[];
extern u16 player_shot_3_impact_00[];
extern u16 player_shot_3_impact_02[];
extern u16 player_shot_3_impact_04[];
extern u16 player_shot_3_impact_06[];
extern u16 player_shot_3_impact_08[];
extern u16 player_shot_3_impact_10[];
extern u16 player_shot_3_impact_11[];
extern u16 player_shot_3_impact_12[];
extern u16 player_shot_3_impact_13[];
extern u16 player_shot_3_impact_14[];
extern u16 player_shot_3_impact_15[];
extern u16 player_shot_3_impact_17[];
extern u16 player_shot_3_impact_19[];
extern u16 player_shot_3_impact_21[];
extern u16 player_shot_3_impact_23[];
extern u16 option_shot_list_1_00_00_07[];
extern u16 option_shot_list_1_00_01_07[];
extern u16 option_shot_list_1_00_02_07[];
extern u16 option_shot_list_1_00_03_07[];
extern u16 option_shot_list_1_00_04_07[];
extern u16 option_shot_list_3_00_00_00_00_01[];
extern u16 option_shot_list_3_00_00_00_01_01[];
extern u16 option_shot_list_3_00_00_00_02_01[];
extern u16 option_shot_list_3_00_00_00_03_01[];
extern u16 option_shot_list_3_00_00_00_04_01[];
extern u16 option_shot_list_3_00_00_00_05_01[];
extern u16 option_shot_list_3_00_00_00_06_01[];
extern u16 option_shot_list_3_00_00_00_07_01[];
extern u16 option_shot_list_3_00_00_00_08_01[];
extern u16 option_shot_list_3_00_00_00_09_01[];
extern u16 option_shot_list_3_00_00_00_10_01[];
extern u16 option_shot_list_3_00_00_00_11_01[];
extern u16 option_shot_list_3_00_00_00_12_01[];
extern u16 option_shot_list_3_00_00_00_13_01[];
extern u16 option_shot_list_3_00_00_00_14_01[];
extern u16 option_shot_list_3_00_00_00_15_01[];
extern u16 option_shot_list_3_00_00_00_16_01[];
extern u16 option_shot_list_3_00_01_00_00_01[];
extern u16 option_shot_list_3_00_01_00_01_01[];
extern u16 option_shot_list_3_00_01_00_02_01[];
extern u16 option_shot_list_3_00_01_00_03_01[];
extern u16 option_shot_list_3_00_01_00_04_01[];
extern u16 option_shot_list_3_00_01_00_05_01[];
extern u16 option_shot_list_3_00_01_00_06_01[];
extern u16 option_shot_list_3_00_01_00_07_01[];
extern u16 option_shot_list_3_00_01_00_08_01[];
extern u16 option_shot_list_3_00_01_00_09_01[];
extern u16 option_shot_list_3_00_01_00_10_01[];
extern u16 option_shot_list_3_00_01_00_11_01[];
extern u16 option_shot_list_3_00_01_00_12_01[];
extern u16 option_shot_list_3_00_01_00_13_01[];
extern u16 option_shot_list_3_00_01_00_14_01[];
extern u16 option_shot_list_3_00_01_00_15_01[];
extern u16 option_shot_list_3_00_01_00_16_01[];
extern u16 option_shot_list_3_00_02_00_00_01[];
extern u16 option_shot_list_3_00_02_00_01_01[];
extern u16 option_shot_list_3_00_02_00_02_01[];
extern u16 option_shot_list_3_00_02_00_03_01[];
extern u16 option_shot_list_3_00_02_00_04_01[];
extern u16 option_shot_list_3_00_02_00_05_01[];
extern u16 option_shot_list_3_00_02_00_06_01[];
extern u16 option_shot_list_3_00_02_00_07_01[];
extern u16 option_shot_list_3_00_02_00_08_01[];
extern u16 option_shot_list_3_00_02_00_09_01[];
extern u16 option_shot_list_3_00_02_00_10_01[];
extern u16 option_shot_list_3_00_02_00_11_01[];
extern u16 option_shot_list_3_00_02_00_12_01[];
extern u16 option_shot_list_3_00_02_00_13_01[];
extern u16 option_shot_list_3_00_02_00_14_01[];
extern u16 option_shot_list_3_00_02_00_15_01[];
extern u16 option_shot_list_3_00_02_00_16_01[];
extern u16 option_shot_list_3_00_03_00_00_01[];
extern u16 option_shot_list_3_00_03_00_01_01[];
extern u16 option_shot_list_3_00_03_00_02_01[];
extern u16 option_shot_list_3_00_03_00_03_01[];
extern u16 option_shot_list_3_00_03_00_04_01[];
extern u16 option_shot_list_3_00_03_00_05_01[];
extern u16 option_shot_list_3_00_03_00_06_01[];
extern u16 option_shot_list_3_00_03_00_07_01[];
extern u16 option_shot_list_3_00_03_00_08_01[];
extern u16 option_shot_list_3_00_03_00_09_01[];
extern u16 option_shot_list_3_00_03_00_10_01[];
extern u16 option_shot_list_3_00_03_00_11_01[];
extern u16 option_shot_list_3_00_03_00_12_01[];
extern u16 option_shot_list_3_00_03_00_13_01[];
extern u16 option_shot_list_3_00_03_00_14_01[];
extern u16 option_shot_list_3_00_03_00_15_01[];
extern u16 option_shot_list_3_00_03_00_16_01[];
extern u16 option_shot_list_3_00_04_00_00_01[];
extern u16 option_shot_list_3_00_04_00_01_01[];
extern u16 option_shot_list_3_00_04_00_02_01[];
extern u16 option_shot_list_3_00_04_00_03_01[];
extern u16 option_shot_list_3_00_04_00_04_01[];
extern u16 option_shot_list_3_00_04_00_05_01[];
extern u16 option_shot_list_3_00_04_00_06_01[];
extern u16 option_shot_list_3_00_04_00_07_01[];
extern u16 option_shot_list_3_00_04_00_08_01[];
extern u16 option_shot_list_3_00_04_00_09_01[];
extern u16 option_shot_list_3_00_04_00_10_01[];
extern u16 option_shot_list_3_00_04_00_11_01[];
extern u16 option_shot_list_3_00_04_00_12_01[];
extern u16 option_shot_list_3_00_04_00_13_01[];
extern u16 option_shot_list_3_00_04_00_14_01[];
extern u16 option_shot_list_3_00_04_00_15_01[];
extern u16 option_shot_list_3_00_04_00_16_01[];
extern u16 option_shot_list_4_00_00_07[];
extern u16 option_shot_list_4_00_01_07[];
extern u16 option_shot_list_4_00_02_07[];
extern u16 option_shot_list_4_00_03_07[];
extern u16 option_shot_list_4_00_04_07[];
extern u16 player_shot_3_flight_00[];
extern u16 player_shot_3_flight_02[];
extern u16 player_shot_3_flight_04[];
extern u16 player_shot_3_flight_06[];
extern u16 player_shot_3_flight_08[];
extern u16 player_shot_3_flight_10[];
extern u16 player_shot_3_flight_11[];
extern u16 player_shot_3_flight_12[];
extern u16 player_shot_3_flight_13[];
extern u16 player_shot_3_flight_14[];
extern u16 player_shot_3_flight_15[];
extern u16 player_shot_3_flight_17[];
extern u16 player_shot_3_flight_19[];
extern u16 player_shot_3_flight_21[];
extern u16 player_shot_3_flight_23[];
extern u16 option_shot_list_3_00_00_00_01[];
extern u16 option_shot_list_3_00_00_00_02[];
extern u16 option_shot_list_3_00_00_00_03[];
extern u16 option_shot_list_3_00_00_00_04[];
extern u16 option_shot_list_3_00_00_00_05[];
extern u16 option_shot_list_3_00_00_00_06[];
extern u16 option_shot_list_3_00_00_00_07[];
extern u16 option_shot_list_3_00_00_00_08[];
extern u16 option_shot_list_3_00_00_00_09[];
extern u16 option_shot_list_3_00_00_00_10[];
extern u16 option_shot_list_3_00_00_00_11[];
extern u16 option_shot_list_3_00_00_00_12[];
extern u16 option_shot_list_3_00_00_00_14[];
extern u16 option_shot_list_3_00_00_00_15[];
extern u16 option_shot_list_3_00_00_00_16[];
extern u16 option_shot_list_3_00_01_00_00[];
extern u16 option_shot_list_3_00_01_00_01[];
extern u16 option_shot_list_3_00_01_00_02[];
extern u16 option_shot_list_3_00_01_00_03[];
extern u16 option_shot_list_3_00_01_00_04[];
extern u16 option_shot_list_3_00_01_00_05[];
extern u16 option_shot_list_3_00_01_00_06[];
extern u16 option_shot_list_3_00_01_00_07[];
extern u16 option_shot_list_3_00_01_00_08[];
extern u16 option_shot_list_3_00_01_00_09[];
extern u16 option_shot_list_3_00_01_00_10[];
extern u16 option_shot_list_3_00_01_00_11[];
extern u16 option_shot_list_3_00_01_00_12[];
extern u16 option_shot_list_3_00_01_00_13[];
extern u16 option_shot_list_3_00_01_00_14[];
extern u16 option_shot_list_3_00_01_00_15[];
extern u16 option_shot_list_3_00_01_00_16[];
extern u16 option_shot_list_3_00_02_00_00[];
extern u16 option_shot_list_3_00_02_00_01[];
extern u16 option_shot_list_3_00_02_00_02[];
extern u16 option_shot_list_3_00_02_00_03[];
extern u16 option_shot_list_3_00_02_00_04[];
extern u16 option_shot_list_3_00_02_00_05[];
extern u16 option_shot_list_3_00_02_00_06[];
extern u16 option_shot_list_3_00_02_00_07[];
extern u16 option_shot_list_3_00_02_00_08[];
extern u16 option_shot_list_3_00_02_00_09[];
extern u16 option_shot_list_3_00_02_00_10[];
extern u16 option_shot_list_3_00_02_00_11[];
extern u16 option_shot_list_3_00_02_00_12[];
extern u16 option_shot_list_3_00_02_00_13[];
extern u16 option_shot_list_3_00_02_00_14[];
extern u16 option_shot_list_3_00_02_00_15[];
extern u16 option_shot_list_3_00_02_00_16[];
extern u16 option_shot_list_3_00_03_00_00[];
extern u16 option_shot_list_3_00_03_00_01[];
extern u16 option_shot_list_3_00_03_00_02[];
extern u16 option_shot_list_3_00_03_00_03[];
extern u16 option_shot_list_3_00_03_00_04[];
extern u16 option_shot_list_3_00_03_00_05[];
extern u16 option_shot_list_3_00_03_00_06[];
extern u16 option_shot_list_3_00_03_00_07[];
extern u16 option_shot_list_3_00_03_00_08[];
extern u16 option_shot_list_3_00_03_00_09[];
extern u16 option_shot_list_3_00_03_00_10[];
extern u16 option_shot_list_3_00_03_00_11[];
extern u16 option_shot_list_3_00_03_00_12[];
extern u16 option_shot_list_3_00_03_00_13[];
extern u16 option_shot_list_3_00_03_00_14[];
extern u16 option_shot_list_3_00_03_00_15[];
extern u16 option_shot_list_3_00_03_00_16[];
extern u16 option_shot_list_3_00_04_00_00[];
extern u16 option_shot_list_3_00_04_00_01[];
extern u16 option_shot_list_3_00_04_00_02[];
extern u16 option_shot_list_3_00_04_00_03[];
extern u16 option_shot_list_3_00_04_00_04[];
extern u16 option_shot_list_3_00_04_00_05[];
extern u16 option_shot_list_3_00_04_00_06[];
extern u16 option_shot_list_3_00_04_00_07[];
extern u16 option_shot_list_3_00_04_00_08[];
extern u16 option_shot_list_3_00_04_00_09[];
extern u16 option_shot_list_3_00_04_00_10[];
extern u16 option_shot_list_3_00_04_00_11[];
extern u16 option_shot_list_3_00_04_00_12[];
extern u16 option_shot_list_3_00_04_00_13[];
extern u16 option_shot_list_3_00_04_00_14[];
extern u16 option_shot_list_3_00_04_00_15[];
extern u16 option_shot_list_3_00_04_00_16[];

extern u16 player_shot_3_flight_table[];
extern u16 player_shot_3_impact_table[];

void player_shot_3_tables_init(void) {
    STORE_POINTER(option_shot_list_1_00_00 + 5, option_shot_list_1_00_00_02);
    STORE_POINTER(option_shot_list_1_00_00 + 15, option_shot_list_1_00_00_07);
    STORE_POINTER(option_shot_list_2_00_00 + 5, option_shot_list_1_00_00_02);
    STORE_POINTER(option_shot_list_2_00_00 + 15, option_shot_list_1_00_00_07);
    STORE_POINTER(option_shot_list_1_00_01 + 5, option_shot_list_1_00_00_02);
    STORE_POINTER(option_shot_list_1_00_01 + 15, option_shot_list_1_00_01_07);
    STORE_POINTER(option_shot_list_2_00_01 + 5, option_shot_list_1_00_00_02);
    STORE_POINTER(option_shot_list_2_00_01 + 15, option_shot_list_1_00_01_07);
    STORE_POINTER(option_shot_list_1_00_02 + 5, option_shot_list_1_00_02_02);
    STORE_POINTER(option_shot_list_1_00_02 + 15, option_shot_list_1_00_02_07);
    STORE_POINTER(option_shot_list_2_00_02 + 5, option_shot_list_1_00_02_02);
    STORE_POINTER(option_shot_list_2_00_02 + 15, option_shot_list_1_00_02_07);
    STORE_POINTER(option_shot_list_1_00_03 + 5, option_shot_list_1_00_02_02);
    STORE_POINTER(option_shot_list_1_00_03 + 15, option_shot_list_1_00_03_07);
    STORE_POINTER(option_shot_list_2_00_03 + 5, option_shot_list_1_00_02_02);
    STORE_POINTER(option_shot_list_2_00_03 + 15, option_shot_list_1_00_03_07);
    STORE_POINTER(option_shot_list_1_00_04 + 5, option_shot_list_1_00_04_02);
    STORE_POINTER(option_shot_list_1_00_04 + 15, option_shot_list_1_00_04_07);
    STORE_POINTER(option_shot_list_2_00_04 + 5, option_shot_list_1_00_04_02);
    STORE_POINTER(option_shot_list_2_00_04 + 15, option_shot_list_1_00_04_07);
    STORE_POINTER(option_shot_list_3_00_00 + 1, option_shot_list_3_00_00_00);
    STORE_POINTER(option_shot_list_3_00_00 + 5, option_shot_list_3_00_00_02);
    STORE_POINTER(option_shot_list_3_00_01 + 1, option_shot_list_3_00_01_00);
    STORE_POINTER(option_shot_list_3_00_01 + 5, option_shot_list_3_00_00_02);
    STORE_POINTER(option_shot_list_3_00_02 + 1, option_shot_list_3_00_02_00);
    STORE_POINTER(option_shot_list_3_00_02 + 5, option_shot_list_3_00_02_02);
    STORE_POINTER(option_shot_list_3_00_03 + 1, option_shot_list_3_00_03_00);
    STORE_POINTER(option_shot_list_3_00_03 + 5, option_shot_list_3_00_02_02);
    STORE_POINTER(option_shot_list_3_00_04 + 1, option_shot_list_3_00_04_00);
    STORE_POINTER(option_shot_list_3_00_04 + 5, option_shot_list_3_00_04_02);
    STORE_POINTER(option_shot_list_4_00_00 + 5, option_shot_list_4_00_00_02);
    STORE_POINTER(option_shot_list_4_00_00 + 15, option_shot_list_4_00_00_07);
    STORE_POINTER(option_shot_list_4_00_00 + 24, option_shot_list_4_00_00_02);
    STORE_POINTER(option_shot_list_4_00_00 + 34, option_shot_list_4_00_00_07);
    STORE_POINTER(option_shot_list_4_00_01 + 5, option_shot_list_4_00_00_02);
    STORE_POINTER(option_shot_list_4_00_01 + 15, option_shot_list_4_00_01_07);
    STORE_POINTER(option_shot_list_4_00_01 + 24, option_shot_list_4_00_00_02);
    STORE_POINTER(option_shot_list_4_00_01 + 34, option_shot_list_4_00_01_07);
    STORE_POINTER(option_shot_list_4_00_02 + 5, option_shot_list_4_00_02_02);
    STORE_POINTER(option_shot_list_4_00_02 + 15, option_shot_list_4_00_02_07);
    STORE_POINTER(option_shot_list_4_00_02 + 24, option_shot_list_4_00_02_02);
    STORE_POINTER(option_shot_list_4_00_02 + 34, option_shot_list_4_00_02_07);
    STORE_POINTER(option_shot_list_4_00_03 + 5, option_shot_list_4_00_02_02);
    STORE_POINTER(option_shot_list_4_00_03 + 15, option_shot_list_4_00_03_07);
    STORE_POINTER(option_shot_list_4_00_03 + 24, option_shot_list_4_00_02_02);
    STORE_POINTER(option_shot_list_4_00_03 + 34, option_shot_list_4_00_03_07);
    STORE_POINTER(option_shot_list_4_00_04 + 5, option_shot_list_4_00_04_02);
    STORE_POINTER(option_shot_list_4_00_04 + 15, option_shot_list_4_00_04_07);
    STORE_POINTER(option_shot_list_4_00_04 + 24, option_shot_list_4_00_04_02);
    STORE_POINTER(option_shot_list_4_00_04 + 34, option_shot_list_4_00_04_07);
    STORE_POINTER(player_shot_3_flight_table, player_shot_3_flight_00);
    STORE_POINTER(player_shot_3_flight_table + 2, player_shot_3_flight_00);
    STORE_POINTER(player_shot_3_flight_table + 4, player_shot_3_flight_02);
    STORE_POINTER(player_shot_3_flight_table + 6, player_shot_3_flight_02);
    STORE_POINTER(player_shot_3_flight_table + 8, player_shot_3_flight_04);
    STORE_POINTER(player_shot_3_flight_table + 10, player_shot_3_flight_04);
    STORE_POINTER(player_shot_3_flight_table + 12, player_shot_3_flight_06);
    STORE_POINTER(player_shot_3_flight_table + 14, player_shot_3_flight_06);
    STORE_POINTER(player_shot_3_flight_table + 16, player_shot_3_flight_08);
    STORE_POINTER(player_shot_3_flight_table + 18, player_shot_3_flight_08);
    STORE_POINTER(player_shot_3_flight_table + 20, player_shot_3_flight_10);
    STORE_POINTER(player_shot_3_flight_table + 22, player_shot_3_flight_11);
    STORE_POINTER(player_shot_3_flight_table + 24, player_shot_3_flight_12);
    STORE_POINTER(player_shot_3_flight_table + 26, player_shot_3_flight_13);
    STORE_POINTER(player_shot_3_flight_table + 28, player_shot_3_flight_14);
    STORE_POINTER(player_shot_3_flight_table + 30, player_shot_3_flight_15);
    STORE_POINTER(player_shot_3_flight_table + 32, player_shot_3_flight_15);
    STORE_POINTER(player_shot_3_flight_table + 34, player_shot_3_flight_17);
    STORE_POINTER(player_shot_3_flight_table + 36, player_shot_3_flight_17);
    STORE_POINTER(player_shot_3_flight_table + 38, player_shot_3_flight_19);
    STORE_POINTER(player_shot_3_flight_table + 40, player_shot_3_flight_19);
    STORE_POINTER(player_shot_3_flight_table + 42, player_shot_3_flight_21);
    STORE_POINTER(player_shot_3_flight_table + 44, player_shot_3_flight_21);
    STORE_POINTER(player_shot_3_flight_table + 46, player_shot_3_flight_23);
    STORE_POINTER(player_shot_3_flight_table + 48, player_shot_3_flight_23);
    STORE_POINTER(option_shot_list_3_00_00_00, option_shot_list_3_00_00_00_00);
    STORE_POINTER(option_shot_list_3_00_00_00 + 2, option_shot_list_3_00_00_00_01);
    STORE_POINTER(option_shot_list_3_00_00_00 + 4, option_shot_list_3_00_00_00_02);
    STORE_POINTER(option_shot_list_3_00_00_00 + 6, option_shot_list_3_00_00_00_03);
    STORE_POINTER(option_shot_list_3_00_00_00 + 8, option_shot_list_3_00_00_00_04);
    STORE_POINTER(option_shot_list_3_00_00_00 + 10, option_shot_list_3_00_00_00_05);
    STORE_POINTER(option_shot_list_3_00_00_00 + 12, option_shot_list_3_00_00_00_06);
    STORE_POINTER(option_shot_list_3_00_00_00 + 14, option_shot_list_3_00_00_00_07);
    STORE_POINTER(option_shot_list_3_00_00_00 + 16, option_shot_list_3_00_00_00_08);
    STORE_POINTER(option_shot_list_3_00_00_00 + 18, option_shot_list_3_00_00_00_09);
    STORE_POINTER(option_shot_list_3_00_00_00 + 20, option_shot_list_3_00_00_00_10);
    STORE_POINTER(option_shot_list_3_00_00_00 + 22, option_shot_list_3_00_00_00_11);
    STORE_POINTER(option_shot_list_3_00_00_00 + 24, option_shot_list_3_00_00_00_12);
    STORE_POINTER(option_shot_list_3_00_00_00 + 26, option_shot_list_3_00_00_00_13);
    STORE_POINTER(option_shot_list_3_00_00_00 + 28, option_shot_list_3_00_00_00_14);
    STORE_POINTER(option_shot_list_3_00_00_00 + 30, option_shot_list_3_00_00_00_15);
    STORE_POINTER(option_shot_list_3_00_00_00 + 32, option_shot_list_3_00_00_00_16);
    STORE_POINTER(option_shot_list_3_00_00_00_00 + 2, option_shot_list_3_00_00_00_00_01);
    STORE_POINTER(option_shot_list_3_00_00_00_01 + 2, option_shot_list_3_00_00_00_01_01);
    STORE_POINTER(option_shot_list_3_00_00_00_02 + 2, option_shot_list_3_00_00_00_02_01);
    STORE_POINTER(option_shot_list_3_00_00_00_03 + 2, option_shot_list_3_00_00_00_03_01);
    STORE_POINTER(option_shot_list_3_00_00_00_04 + 2, option_shot_list_3_00_00_00_04_01);
    STORE_POINTER(option_shot_list_3_00_00_00_05 + 2, option_shot_list_3_00_00_00_05_01);
    STORE_POINTER(option_shot_list_3_00_00_00_06 + 2, option_shot_list_3_00_00_00_06_01);
    STORE_POINTER(option_shot_list_3_00_00_00_07 + 2, option_shot_list_3_00_00_00_07_01);
    STORE_POINTER(option_shot_list_3_00_00_00_08 + 2, option_shot_list_3_00_00_00_08_01);
    STORE_POINTER(option_shot_list_3_00_00_00_09 + 2, option_shot_list_3_00_00_00_09_01);
    STORE_POINTER(option_shot_list_3_00_00_00_10 + 2, option_shot_list_3_00_00_00_10_01);
    STORE_POINTER(option_shot_list_3_00_00_00_11 + 2, option_shot_list_3_00_00_00_11_01);
    STORE_POINTER(option_shot_list_3_00_00_00_12 + 2, option_shot_list_3_00_00_00_12_01);
    STORE_POINTER(option_shot_list_3_00_00_00_13 + 2, option_shot_list_3_00_00_00_13_01);
    STORE_POINTER(option_shot_list_3_00_00_00_14 + 2, option_shot_list_3_00_00_00_14_01);
    STORE_POINTER(option_shot_list_3_00_00_00_15 + 2, option_shot_list_3_00_00_00_15_01);
    STORE_POINTER(option_shot_list_3_00_00_00_16 + 2, option_shot_list_3_00_00_00_16_01);
    STORE_POINTER(option_shot_list_3_00_01_00, option_shot_list_3_00_01_00_00);
    STORE_POINTER(option_shot_list_3_00_01_00 + 2, option_shot_list_3_00_01_00_01);
    STORE_POINTER(option_shot_list_3_00_01_00 + 4, option_shot_list_3_00_01_00_02);
    STORE_POINTER(option_shot_list_3_00_01_00 + 6, option_shot_list_3_00_01_00_03);
    STORE_POINTER(option_shot_list_3_00_01_00 + 8, option_shot_list_3_00_01_00_04);
    STORE_POINTER(option_shot_list_3_00_01_00 + 10, option_shot_list_3_00_01_00_05);
    STORE_POINTER(option_shot_list_3_00_01_00 + 12, option_shot_list_3_00_01_00_06);
    STORE_POINTER(option_shot_list_3_00_01_00 + 14, option_shot_list_3_00_01_00_07);
    STORE_POINTER(option_shot_list_3_00_01_00 + 16, option_shot_list_3_00_01_00_08);
    STORE_POINTER(option_shot_list_3_00_01_00 + 18, option_shot_list_3_00_01_00_09);
    STORE_POINTER(option_shot_list_3_00_01_00 + 20, option_shot_list_3_00_01_00_10);
    STORE_POINTER(option_shot_list_3_00_01_00 + 22, option_shot_list_3_00_01_00_11);
    STORE_POINTER(option_shot_list_3_00_01_00 + 24, option_shot_list_3_00_01_00_12);
    STORE_POINTER(option_shot_list_3_00_01_00 + 26, option_shot_list_3_00_01_00_13);
    STORE_POINTER(option_shot_list_3_00_01_00 + 28, option_shot_list_3_00_01_00_14);
    STORE_POINTER(option_shot_list_3_00_01_00 + 30, option_shot_list_3_00_01_00_15);
    STORE_POINTER(option_shot_list_3_00_01_00 + 32, option_shot_list_3_00_01_00_16);
    STORE_POINTER(option_shot_list_3_00_01_00_00 + 2, option_shot_list_3_00_01_00_00_01);
    STORE_POINTER(option_shot_list_3_00_01_00_01 + 2, option_shot_list_3_00_01_00_01_01);
    STORE_POINTER(option_shot_list_3_00_01_00_02 + 2, option_shot_list_3_00_01_00_02_01);
    STORE_POINTER(option_shot_list_3_00_01_00_03 + 2, option_shot_list_3_00_01_00_03_01);
    STORE_POINTER(option_shot_list_3_00_01_00_04 + 2, option_shot_list_3_00_01_00_04_01);
    STORE_POINTER(option_shot_list_3_00_01_00_05 + 2, option_shot_list_3_00_01_00_05_01);
    STORE_POINTER(option_shot_list_3_00_01_00_06 + 2, option_shot_list_3_00_01_00_06_01);
    STORE_POINTER(option_shot_list_3_00_01_00_07 + 2, option_shot_list_3_00_01_00_07_01);
    STORE_POINTER(option_shot_list_3_00_01_00_08 + 2, option_shot_list_3_00_01_00_08_01);
    STORE_POINTER(option_shot_list_3_00_01_00_09 + 2, option_shot_list_3_00_01_00_09_01);
    STORE_POINTER(option_shot_list_3_00_01_00_10 + 2, option_shot_list_3_00_01_00_10_01);
    STORE_POINTER(option_shot_list_3_00_01_00_11 + 2, option_shot_list_3_00_01_00_11_01);
    STORE_POINTER(option_shot_list_3_00_01_00_12 + 2, option_shot_list_3_00_01_00_12_01);
    STORE_POINTER(option_shot_list_3_00_01_00_13 + 2, option_shot_list_3_00_01_00_13_01);
    STORE_POINTER(option_shot_list_3_00_01_00_14 + 2, option_shot_list_3_00_01_00_14_01);
    STORE_POINTER(option_shot_list_3_00_01_00_15 + 2, option_shot_list_3_00_01_00_15_01);
    STORE_POINTER(option_shot_list_3_00_01_00_16 + 2, option_shot_list_3_00_01_00_16_01);
    STORE_POINTER(option_shot_list_3_00_02_00, option_shot_list_3_00_02_00_00);
    STORE_POINTER(option_shot_list_3_00_02_00 + 2, option_shot_list_3_00_02_00_01);
    STORE_POINTER(option_shot_list_3_00_02_00 + 4, option_shot_list_3_00_02_00_02);
    STORE_POINTER(option_shot_list_3_00_02_00 + 6, option_shot_list_3_00_02_00_03);
    STORE_POINTER(option_shot_list_3_00_02_00 + 8, option_shot_list_3_00_02_00_04);
    STORE_POINTER(option_shot_list_3_00_02_00 + 10, option_shot_list_3_00_02_00_05);
    STORE_POINTER(option_shot_list_3_00_02_00 + 12, option_shot_list_3_00_02_00_06);
    STORE_POINTER(option_shot_list_3_00_02_00 + 14, option_shot_list_3_00_02_00_07);
    STORE_POINTER(option_shot_list_3_00_02_00 + 16, option_shot_list_3_00_02_00_08);
    STORE_POINTER(option_shot_list_3_00_02_00 + 18, option_shot_list_3_00_02_00_09);
    STORE_POINTER(option_shot_list_3_00_02_00 + 20, option_shot_list_3_00_02_00_10);
    STORE_POINTER(option_shot_list_3_00_02_00 + 22, option_shot_list_3_00_02_00_11);
    STORE_POINTER(option_shot_list_3_00_02_00 + 24, option_shot_list_3_00_02_00_12);
    STORE_POINTER(option_shot_list_3_00_02_00 + 26, option_shot_list_3_00_02_00_13);
    STORE_POINTER(option_shot_list_3_00_02_00 + 28, option_shot_list_3_00_02_00_14);
    STORE_POINTER(option_shot_list_3_00_02_00 + 30, option_shot_list_3_00_02_00_15);
    STORE_POINTER(option_shot_list_3_00_02_00 + 32, option_shot_list_3_00_02_00_16);
    STORE_POINTER(option_shot_list_3_00_02_00_00 + 2, option_shot_list_3_00_02_00_00_01);
    STORE_POINTER(option_shot_list_3_00_02_00_01 + 2, option_shot_list_3_00_02_00_01_01);
    STORE_POINTER(option_shot_list_3_00_02_00_02 + 2, option_shot_list_3_00_02_00_02_01);
    STORE_POINTER(option_shot_list_3_00_02_00_03 + 2, option_shot_list_3_00_02_00_03_01);
    STORE_POINTER(option_shot_list_3_00_02_00_04 + 2, option_shot_list_3_00_02_00_04_01);
    STORE_POINTER(option_shot_list_3_00_02_00_05 + 2, option_shot_list_3_00_02_00_05_01);
    STORE_POINTER(option_shot_list_3_00_02_00_06 + 2, option_shot_list_3_00_02_00_06_01);
    STORE_POINTER(option_shot_list_3_00_02_00_07 + 2, option_shot_list_3_00_02_00_07_01);
    STORE_POINTER(option_shot_list_3_00_02_00_08 + 2, option_shot_list_3_00_02_00_08_01);
    STORE_POINTER(option_shot_list_3_00_02_00_09 + 2, option_shot_list_3_00_02_00_09_01);
    STORE_POINTER(option_shot_list_3_00_02_00_10 + 2, option_shot_list_3_00_02_00_10_01);
    STORE_POINTER(option_shot_list_3_00_02_00_11 + 2, option_shot_list_3_00_02_00_11_01);
    STORE_POINTER(option_shot_list_3_00_02_00_12 + 2, option_shot_list_3_00_02_00_12_01);
    STORE_POINTER(option_shot_list_3_00_02_00_13 + 2, option_shot_list_3_00_02_00_13_01);
    STORE_POINTER(option_shot_list_3_00_02_00_14 + 2, option_shot_list_3_00_02_00_14_01);
    STORE_POINTER(option_shot_list_3_00_02_00_15 + 2, option_shot_list_3_00_02_00_15_01);
    STORE_POINTER(option_shot_list_3_00_02_00_16 + 2, option_shot_list_3_00_02_00_16_01);
    STORE_POINTER(option_shot_list_3_00_03_00, option_shot_list_3_00_03_00_00);
    STORE_POINTER(option_shot_list_3_00_03_00 + 2, option_shot_list_3_00_03_00_01);
    STORE_POINTER(option_shot_list_3_00_03_00 + 4, option_shot_list_3_00_03_00_02);
    STORE_POINTER(option_shot_list_3_00_03_00 + 6, option_shot_list_3_00_03_00_03);
    STORE_POINTER(option_shot_list_3_00_03_00 + 8, option_shot_list_3_00_03_00_04);
    STORE_POINTER(option_shot_list_3_00_03_00 + 10, option_shot_list_3_00_03_00_05);
    STORE_POINTER(option_shot_list_3_00_03_00 + 12, option_shot_list_3_00_03_00_06);
    STORE_POINTER(option_shot_list_3_00_03_00 + 14, option_shot_list_3_00_03_00_07);
    STORE_POINTER(option_shot_list_3_00_03_00 + 16, option_shot_list_3_00_03_00_08);
    STORE_POINTER(option_shot_list_3_00_03_00 + 18, option_shot_list_3_00_03_00_09);
    STORE_POINTER(option_shot_list_3_00_03_00 + 20, option_shot_list_3_00_03_00_10);
    STORE_POINTER(option_shot_list_3_00_03_00 + 22, option_shot_list_3_00_03_00_11);
    STORE_POINTER(option_shot_list_3_00_03_00 + 24, option_shot_list_3_00_03_00_12);
    STORE_POINTER(option_shot_list_3_00_03_00 + 26, option_shot_list_3_00_03_00_13);
    STORE_POINTER(option_shot_list_3_00_03_00 + 28, option_shot_list_3_00_03_00_14);
    STORE_POINTER(option_shot_list_3_00_03_00 + 30, option_shot_list_3_00_03_00_15);
    STORE_POINTER(option_shot_list_3_00_03_00 + 32, option_shot_list_3_00_03_00_16);
    STORE_POINTER(option_shot_list_3_00_03_00_00 + 2, option_shot_list_3_00_03_00_00_01);
    STORE_POINTER(option_shot_list_3_00_03_00_01 + 2, option_shot_list_3_00_03_00_01_01);
    STORE_POINTER(option_shot_list_3_00_03_00_02 + 2, option_shot_list_3_00_03_00_02_01);
    STORE_POINTER(option_shot_list_3_00_03_00_03 + 2, option_shot_list_3_00_03_00_03_01);
    STORE_POINTER(option_shot_list_3_00_03_00_04 + 2, option_shot_list_3_00_03_00_04_01);
    STORE_POINTER(option_shot_list_3_00_03_00_05 + 2, option_shot_list_3_00_03_00_05_01);
    STORE_POINTER(option_shot_list_3_00_03_00_06 + 2, option_shot_list_3_00_03_00_06_01);
    STORE_POINTER(option_shot_list_3_00_03_00_07 + 2, option_shot_list_3_00_03_00_07_01);
    STORE_POINTER(option_shot_list_3_00_03_00_08 + 2, option_shot_list_3_00_03_00_08_01);
    STORE_POINTER(option_shot_list_3_00_03_00_09 + 2, option_shot_list_3_00_03_00_09_01);
    STORE_POINTER(option_shot_list_3_00_03_00_10 + 2, option_shot_list_3_00_03_00_10_01);
    STORE_POINTER(option_shot_list_3_00_03_00_11 + 2, option_shot_list_3_00_03_00_11_01);
    STORE_POINTER(option_shot_list_3_00_03_00_12 + 2, option_shot_list_3_00_03_00_12_01);
    STORE_POINTER(option_shot_list_3_00_03_00_13 + 2, option_shot_list_3_00_03_00_13_01);
    STORE_POINTER(option_shot_list_3_00_03_00_14 + 2, option_shot_list_3_00_03_00_14_01);
    STORE_POINTER(option_shot_list_3_00_03_00_15 + 2, option_shot_list_3_00_03_00_15_01);
    STORE_POINTER(option_shot_list_3_00_03_00_16 + 2, option_shot_list_3_00_03_00_16_01);
    STORE_POINTER(option_shot_list_3_00_04_00, option_shot_list_3_00_04_00_00);
    STORE_POINTER(option_shot_list_3_00_04_00 + 2, option_shot_list_3_00_04_00_01);
    STORE_POINTER(option_shot_list_3_00_04_00 + 4, option_shot_list_3_00_04_00_02);
    STORE_POINTER(option_shot_list_3_00_04_00 + 6, option_shot_list_3_00_04_00_03);
    STORE_POINTER(option_shot_list_3_00_04_00 + 8, option_shot_list_3_00_04_00_04);
    STORE_POINTER(option_shot_list_3_00_04_00 + 10, option_shot_list_3_00_04_00_05);
    STORE_POINTER(option_shot_list_3_00_04_00 + 12, option_shot_list_3_00_04_00_06);
    STORE_POINTER(option_shot_list_3_00_04_00 + 14, option_shot_list_3_00_04_00_07);
    STORE_POINTER(option_shot_list_3_00_04_00 + 16, option_shot_list_3_00_04_00_08);
    STORE_POINTER(option_shot_list_3_00_04_00 + 18, option_shot_list_3_00_04_00_09);
    STORE_POINTER(option_shot_list_3_00_04_00 + 20, option_shot_list_3_00_04_00_10);
    STORE_POINTER(option_shot_list_3_00_04_00 + 22, option_shot_list_3_00_04_00_11);
    STORE_POINTER(option_shot_list_3_00_04_00 + 24, option_shot_list_3_00_04_00_12);
    STORE_POINTER(option_shot_list_3_00_04_00 + 26, option_shot_list_3_00_04_00_13);
    STORE_POINTER(option_shot_list_3_00_04_00 + 28, option_shot_list_3_00_04_00_14);
    STORE_POINTER(option_shot_list_3_00_04_00 + 30, option_shot_list_3_00_04_00_15);
    STORE_POINTER(option_shot_list_3_00_04_00 + 32, option_shot_list_3_00_04_00_16);
    STORE_POINTER(option_shot_list_3_00_04_00_00 + 2, option_shot_list_3_00_04_00_00_01);
    STORE_POINTER(option_shot_list_3_00_04_00_01 + 2, option_shot_list_3_00_04_00_01_01);
    STORE_POINTER(option_shot_list_3_00_04_00_02 + 2, option_shot_list_3_00_04_00_02_01);
    STORE_POINTER(option_shot_list_3_00_04_00_03 + 2, option_shot_list_3_00_04_00_03_01);
    STORE_POINTER(option_shot_list_3_00_04_00_04 + 2, option_shot_list_3_00_04_00_04_01);
    STORE_POINTER(option_shot_list_3_00_04_00_05 + 2, option_shot_list_3_00_04_00_05_01);
    STORE_POINTER(option_shot_list_3_00_04_00_06 + 2, option_shot_list_3_00_04_00_06_01);
    STORE_POINTER(option_shot_list_3_00_04_00_07 + 2, option_shot_list_3_00_04_00_07_01);
    STORE_POINTER(option_shot_list_3_00_04_00_08 + 2, option_shot_list_3_00_04_00_08_01);
    STORE_POINTER(option_shot_list_3_00_04_00_09 + 2, option_shot_list_3_00_04_00_09_01);
    STORE_POINTER(option_shot_list_3_00_04_00_10 + 2, option_shot_list_3_00_04_00_10_01);
    STORE_POINTER(option_shot_list_3_00_04_00_11 + 2, option_shot_list_3_00_04_00_11_01);
    STORE_POINTER(option_shot_list_3_00_04_00_12 + 2, option_shot_list_3_00_04_00_12_01);
    STORE_POINTER(option_shot_list_3_00_04_00_13 + 2, option_shot_list_3_00_04_00_13_01);
    STORE_POINTER(option_shot_list_3_00_04_00_14 + 2, option_shot_list_3_00_04_00_14_01);
    STORE_POINTER(option_shot_list_3_00_04_00_15 + 2, option_shot_list_3_00_04_00_15_01);
    STORE_POINTER(option_shot_list_3_00_04_00_16 + 2, option_shot_list_3_00_04_00_16_01);
    STORE_POINTER(player_shot_3_impact_table, player_shot_3_impact_00);
    STORE_POINTER(player_shot_3_impact_table + 2, player_shot_3_impact_00);
    STORE_POINTER(player_shot_3_impact_table + 4, player_shot_3_impact_02);
    STORE_POINTER(player_shot_3_impact_table + 6, player_shot_3_impact_02);
    STORE_POINTER(player_shot_3_impact_table + 8, player_shot_3_impact_04);
    STORE_POINTER(player_shot_3_impact_table + 10, player_shot_3_impact_04);
    STORE_POINTER(player_shot_3_impact_table + 12, player_shot_3_impact_06);
    STORE_POINTER(player_shot_3_impact_table + 14, player_shot_3_impact_06);
    STORE_POINTER(player_shot_3_impact_table + 16, player_shot_3_impact_08);
    STORE_POINTER(player_shot_3_impact_table + 18, player_shot_3_impact_08);
    STORE_POINTER(player_shot_3_impact_table + 20, player_shot_3_impact_10);
    STORE_POINTER(player_shot_3_impact_table + 22, player_shot_3_impact_11);
    STORE_POINTER(player_shot_3_impact_table + 24, player_shot_3_impact_12);
    STORE_POINTER(player_shot_3_impact_table + 26, player_shot_3_impact_13);
    STORE_POINTER(player_shot_3_impact_table + 28, player_shot_3_impact_14);
    STORE_POINTER(player_shot_3_impact_table + 30, player_shot_3_impact_15);
    STORE_POINTER(player_shot_3_impact_table + 32, player_shot_3_impact_15);
    STORE_POINTER(player_shot_3_impact_table + 34, player_shot_3_impact_17);
    STORE_POINTER(player_shot_3_impact_table + 36, player_shot_3_impact_17);
    STORE_POINTER(player_shot_3_impact_table + 38, player_shot_3_impact_19);
    STORE_POINTER(player_shot_3_impact_table + 40, player_shot_3_impact_19);
    STORE_POINTER(player_shot_3_impact_table + 42, player_shot_3_impact_21);
    STORE_POINTER(player_shot_3_impact_table + 44, player_shot_3_impact_21);
    STORE_POINTER(player_shot_3_impact_table + 46, player_shot_3_impact_23);
    STORE_POINTER(player_shot_3_impact_table + 48, player_shot_3_impact_23);
    STORE_POINTER(player_shot_3_impact_00 + 3, player_shot_3_impact_frames_00);
    STORE_POINTER(player_shot_3_impact_02 + 3, player_shot_3_impact_frames_00);
    STORE_POINTER(player_shot_3_impact_04 + 3, player_shot_3_impact_frames_04);
    STORE_POINTER(player_shot_3_impact_06 + 3, player_shot_3_impact_frames_04);
    STORE_POINTER(player_shot_3_impact_08 + 3, player_shot_3_impact_frames_08);
    STORE_POINTER(player_shot_3_impact_10 + 3, player_shot_3_impact_frames_10);
    STORE_POINTER(player_shot_3_impact_11 + 3, player_shot_3_impact_frames_10);
    STORE_POINTER(player_shot_3_impact_12 + 3, player_shot_3_impact_frames_12);
    STORE_POINTER(player_shot_3_impact_13 + 3, player_shot_3_impact_frames_12);
    STORE_POINTER(player_shot_3_impact_14 + 3, player_shot_3_impact_frames_14);
    STORE_POINTER(player_shot_3_impact_15 + 3, player_shot_3_impact_frames_15);
    STORE_POINTER(player_shot_3_impact_17 + 3, player_shot_3_impact_frames_15);
    STORE_POINTER(player_shot_3_impact_19 + 3, player_shot_3_impact_frames_19);
    STORE_POINTER(player_shot_3_impact_21 + 3, player_shot_3_impact_frames_19);
    STORE_POINTER(player_shot_3_impact_23 + 3, player_shot_3_impact_frames_23);
}

extern u16 option_shot_list_1_02_00_02[];
extern u16 option_shot_list_1_02_02_02[];
extern u16 option_shot_list_1_02_04_02[];
extern u16 option_shot_list_3_02_00_02[];
extern u16 option_shot_list_3_02_02_02[];
extern u16 option_shot_list_3_02_04_02[];
extern u16 option_shot_list_4_02_00_02[];
extern u16 option_shot_list_4_02_02_02[];
extern u16 option_shot_list_4_02_04_02[];
extern u16 player_shot_4_impact_frames_00[];
extern u16 player_shot_4_impact_frames_04[];
extern u16 player_shot_4_impact_frames_08[];
extern u16 player_shot_4_impact_frames_10[];
extern u16 player_shot_4_impact_frames_12[];
extern u16 player_shot_4_impact_frames_14[];
extern u16 player_shot_4_impact_frames_15[];
extern u16 player_shot_4_impact_frames_19[];
extern u16 player_shot_4_impact_frames_23[];
extern u16 option_shot_list_3_02_00_00[];
extern u16 option_shot_list_3_02_00_00_00[];
extern u16 option_shot_list_3_02_00_00_13[];
extern u16 option_shot_list_3_02_01_00[];
extern u16 option_shot_list_3_02_02_00[];
extern u16 option_shot_list_3_02_03_00[];
extern u16 option_shot_list_3_02_04_00[];
extern u16 player_shot_4_impact_00[];
extern u16 player_shot_4_impact_02[];
extern u16 player_shot_4_impact_04[];
extern u16 player_shot_4_impact_06[];
extern u16 player_shot_4_impact_08[];
extern u16 player_shot_4_impact_10[];
extern u16 player_shot_4_impact_11[];
extern u16 player_shot_4_impact_12[];
extern u16 player_shot_4_impact_13[];
extern u16 player_shot_4_impact_14[];
extern u16 player_shot_4_impact_15[];
extern u16 player_shot_4_impact_17[];
extern u16 player_shot_4_impact_19[];
extern u16 player_shot_4_impact_21[];
extern u16 player_shot_4_impact_23[];
extern u16 option_shot_list_1_02_00_07[];
extern u16 option_shot_list_1_02_01_07[];
extern u16 option_shot_list_1_02_02_07[];
extern u16 option_shot_list_1_02_03_07[];
extern u16 option_shot_list_1_02_04_07[];
extern u16 option_shot_list_3_02_00_00_00_01[];
extern u16 option_shot_list_3_02_00_00_01_01[];
extern u16 option_shot_list_3_02_00_00_02_01[];
extern u16 option_shot_list_3_02_00_00_03_01[];
extern u16 option_shot_list_3_02_00_00_04_01[];
extern u16 option_shot_list_3_02_00_00_05_01[];
extern u16 option_shot_list_3_02_00_00_06_01[];
extern u16 option_shot_list_3_02_00_00_07_01[];
extern u16 option_shot_list_3_02_00_00_08_01[];
extern u16 option_shot_list_3_02_00_00_09_01[];
extern u16 option_shot_list_3_02_00_00_10_01[];
extern u16 option_shot_list_3_02_00_00_11_01[];
extern u16 option_shot_list_3_02_00_00_12_01[];
extern u16 option_shot_list_3_02_00_00_13_01[];
extern u16 option_shot_list_3_02_00_00_14_01[];
extern u16 option_shot_list_3_02_00_00_15_01[];
extern u16 option_shot_list_3_02_00_00_16_01[];
extern u16 option_shot_list_3_02_01_00_00_01[];
extern u16 option_shot_list_3_02_01_00_01_01[];
extern u16 option_shot_list_3_02_01_00_02_01[];
extern u16 option_shot_list_3_02_01_00_03_01[];
extern u16 option_shot_list_3_02_01_00_04_01[];
extern u16 option_shot_list_3_02_01_00_05_01[];
extern u16 option_shot_list_3_02_01_00_06_01[];
extern u16 option_shot_list_3_02_01_00_07_01[];
extern u16 option_shot_list_3_02_01_00_08_01[];
extern u16 option_shot_list_3_02_01_00_09_01[];
extern u16 option_shot_list_3_02_01_00_10_01[];
extern u16 option_shot_list_3_02_01_00_11_01[];
extern u16 option_shot_list_3_02_01_00_12_01[];
extern u16 option_shot_list_3_02_01_00_13_01[];
extern u16 option_shot_list_3_02_01_00_14_01[];
extern u16 option_shot_list_3_02_01_00_15_01[];
extern u16 option_shot_list_3_02_01_00_16_01[];
extern u16 option_shot_list_3_02_02_00_00_01[];
extern u16 option_shot_list_3_02_02_00_01_01[];
extern u16 option_shot_list_3_02_02_00_02_01[];
extern u16 option_shot_list_3_02_02_00_03_01[];
extern u16 option_shot_list_3_02_02_00_04_01[];
extern u16 option_shot_list_3_02_02_00_05_01[];
extern u16 option_shot_list_3_02_02_00_06_01[];
extern u16 option_shot_list_3_02_02_00_07_01[];
extern u16 option_shot_list_3_02_02_00_08_01[];
extern u16 option_shot_list_3_02_02_00_09_01[];
extern u16 option_shot_list_3_02_02_00_10_01[];
extern u16 option_shot_list_3_02_02_00_11_01[];
extern u16 option_shot_list_3_02_02_00_12_01[];
extern u16 option_shot_list_3_02_02_00_13_01[];
extern u16 option_shot_list_3_02_02_00_14_01[];
extern u16 option_shot_list_3_02_02_00_15_01[];
extern u16 option_shot_list_3_02_02_00_16_01[];
extern u16 option_shot_list_3_02_03_00_00_01[];
extern u16 option_shot_list_3_02_03_00_01_01[];
extern u16 option_shot_list_3_02_03_00_02_01[];
extern u16 option_shot_list_3_02_03_00_03_01[];
extern u16 option_shot_list_3_02_03_00_04_01[];
extern u16 option_shot_list_3_02_03_00_05_01[];
extern u16 option_shot_list_3_02_03_00_06_01[];
extern u16 option_shot_list_3_02_03_00_07_01[];
extern u16 option_shot_list_3_02_03_00_08_01[];
extern u16 option_shot_list_3_02_03_00_09_01[];
extern u16 option_shot_list_3_02_03_00_10_01[];
extern u16 option_shot_list_3_02_03_00_11_01[];
extern u16 option_shot_list_3_02_03_00_12_01[];
extern u16 option_shot_list_3_02_03_00_13_01[];
extern u16 option_shot_list_3_02_03_00_14_01[];
extern u16 option_shot_list_3_02_03_00_15_01[];
extern u16 option_shot_list_3_02_03_00_16_01[];
extern u16 option_shot_list_3_02_04_00_00_01[];
extern u16 option_shot_list_3_02_04_00_01_01[];
extern u16 option_shot_list_3_02_04_00_02_01[];
extern u16 option_shot_list_3_02_04_00_03_01[];
extern u16 option_shot_list_3_02_04_00_04_01[];
extern u16 option_shot_list_3_02_04_00_05_01[];
extern u16 option_shot_list_3_02_04_00_06_01[];
extern u16 option_shot_list_3_02_04_00_07_01[];
extern u16 option_shot_list_3_02_04_00_08_01[];
extern u16 option_shot_list_3_02_04_00_09_01[];
extern u16 option_shot_list_3_02_04_00_10_01[];
extern u16 option_shot_list_3_02_04_00_11_01[];
extern u16 option_shot_list_3_02_04_00_12_01[];
extern u16 option_shot_list_3_02_04_00_13_01[];
extern u16 option_shot_list_3_02_04_00_14_01[];
extern u16 option_shot_list_3_02_04_00_15_01[];
extern u16 option_shot_list_3_02_04_00_16_01[];
extern u16 option_shot_list_4_02_00_07[];
extern u16 option_shot_list_4_02_01_07[];
extern u16 option_shot_list_4_02_02_07[];
extern u16 option_shot_list_4_02_03_07[];
extern u16 option_shot_list_4_02_04_07[];
extern u16 player_shot_4_flight_00[];
extern u16 player_shot_4_flight_02[];
extern u16 player_shot_4_flight_04[];
extern u16 player_shot_4_flight_06[];
extern u16 player_shot_4_flight_08[];
extern u16 player_shot_4_flight_10[];
extern u16 player_shot_4_flight_11[];
extern u16 player_shot_4_flight_12[];
extern u16 player_shot_4_flight_13[];
extern u16 player_shot_4_flight_14[];
extern u16 player_shot_4_flight_15[];
extern u16 player_shot_4_flight_17[];
extern u16 player_shot_4_flight_19[];
extern u16 player_shot_4_flight_21[];
extern u16 player_shot_4_flight_23[];
extern u16 option_shot_list_3_02_00_00_01[];
extern u16 option_shot_list_3_02_00_00_02[];
extern u16 option_shot_list_3_02_00_00_03[];
extern u16 option_shot_list_3_02_00_00_04[];
extern u16 option_shot_list_3_02_00_00_05[];
extern u16 option_shot_list_3_02_00_00_06[];
extern u16 option_shot_list_3_02_00_00_07[];
extern u16 option_shot_list_3_02_00_00_08[];
extern u16 option_shot_list_3_02_00_00_09[];
extern u16 option_shot_list_3_02_00_00_10[];
extern u16 option_shot_list_3_02_00_00_11[];
extern u16 option_shot_list_3_02_00_00_12[];
extern u16 option_shot_list_3_02_00_00_14[];
extern u16 option_shot_list_3_02_00_00_15[];
extern u16 option_shot_list_3_02_00_00_16[];
extern u16 option_shot_list_3_02_01_00_00[];
extern u16 option_shot_list_3_02_01_00_01[];
extern u16 option_shot_list_3_02_01_00_02[];
extern u16 option_shot_list_3_02_01_00_03[];
extern u16 option_shot_list_3_02_01_00_04[];
extern u16 option_shot_list_3_02_01_00_05[];
extern u16 option_shot_list_3_02_01_00_06[];
extern u16 option_shot_list_3_02_01_00_07[];
extern u16 option_shot_list_3_02_01_00_08[];
extern u16 option_shot_list_3_02_01_00_09[];
extern u16 option_shot_list_3_02_01_00_10[];
extern u16 option_shot_list_3_02_01_00_11[];
extern u16 option_shot_list_3_02_01_00_12[];
extern u16 option_shot_list_3_02_01_00_13[];
extern u16 option_shot_list_3_02_01_00_14[];
extern u16 option_shot_list_3_02_01_00_15[];
extern u16 option_shot_list_3_02_01_00_16[];
extern u16 option_shot_list_3_02_02_00_00[];
extern u16 option_shot_list_3_02_02_00_01[];
extern u16 option_shot_list_3_02_02_00_02[];
extern u16 option_shot_list_3_02_02_00_03[];
extern u16 option_shot_list_3_02_02_00_04[];
extern u16 option_shot_list_3_02_02_00_05[];
extern u16 option_shot_list_3_02_02_00_06[];
extern u16 option_shot_list_3_02_02_00_07[];
extern u16 option_shot_list_3_02_02_00_08[];
extern u16 option_shot_list_3_02_02_00_09[];
extern u16 option_shot_list_3_02_02_00_10[];
extern u16 option_shot_list_3_02_02_00_11[];
extern u16 option_shot_list_3_02_02_00_12[];
extern u16 option_shot_list_3_02_02_00_13[];
extern u16 option_shot_list_3_02_02_00_14[];
extern u16 option_shot_list_3_02_02_00_15[];
extern u16 option_shot_list_3_02_02_00_16[];
extern u16 option_shot_list_3_02_03_00_00[];
extern u16 option_shot_list_3_02_03_00_01[];
extern u16 option_shot_list_3_02_03_00_02[];
extern u16 option_shot_list_3_02_03_00_03[];
extern u16 option_shot_list_3_02_03_00_04[];
extern u16 option_shot_list_3_02_03_00_05[];
extern u16 option_shot_list_3_02_03_00_06[];
extern u16 option_shot_list_3_02_03_00_07[];
extern u16 option_shot_list_3_02_03_00_08[];
extern u16 option_shot_list_3_02_03_00_09[];
extern u16 option_shot_list_3_02_03_00_10[];
extern u16 option_shot_list_3_02_03_00_11[];
extern u16 option_shot_list_3_02_03_00_12[];
extern u16 option_shot_list_3_02_03_00_13[];
extern u16 option_shot_list_3_02_03_00_14[];
extern u16 option_shot_list_3_02_03_00_15[];
extern u16 option_shot_list_3_02_03_00_16[];
extern u16 option_shot_list_3_02_04_00_00[];
extern u16 option_shot_list_3_02_04_00_01[];
extern u16 option_shot_list_3_02_04_00_02[];
extern u16 option_shot_list_3_02_04_00_03[];
extern u16 option_shot_list_3_02_04_00_04[];
extern u16 option_shot_list_3_02_04_00_05[];
extern u16 option_shot_list_3_02_04_00_06[];
extern u16 option_shot_list_3_02_04_00_07[];
extern u16 option_shot_list_3_02_04_00_08[];
extern u16 option_shot_list_3_02_04_00_09[];
extern u16 option_shot_list_3_02_04_00_10[];
extern u16 option_shot_list_3_02_04_00_11[];
extern u16 option_shot_list_3_02_04_00_12[];
extern u16 option_shot_list_3_02_04_00_13[];
extern u16 option_shot_list_3_02_04_00_14[];
extern u16 option_shot_list_3_02_04_00_15[];
extern u16 option_shot_list_3_02_04_00_16[];

extern u16 player_shot_4_flight_table[];
extern u16 player_shot_4_impact_table[];

void player_shot_4_tables_init(void) {
    STORE_POINTER(option_shot_list_1_02_00 + 5, option_shot_list_1_02_00_02);
    STORE_POINTER(option_shot_list_1_02_00 + 15, option_shot_list_1_02_00_07);
    STORE_POINTER(option_shot_list_2_02_00 + 5, option_shot_list_1_02_00_02);
    STORE_POINTER(option_shot_list_2_02_00 + 15, option_shot_list_1_02_00_07);
    STORE_POINTER(option_shot_list_1_02_01 + 5, option_shot_list_1_02_00_02);
    STORE_POINTER(option_shot_list_1_02_01 + 15, option_shot_list_1_02_01_07);
    STORE_POINTER(option_shot_list_2_02_01 + 5, option_shot_list_1_02_00_02);
    STORE_POINTER(option_shot_list_2_02_01 + 15, option_shot_list_1_02_01_07);
    STORE_POINTER(option_shot_list_1_02_02 + 5, option_shot_list_1_02_02_02);
    STORE_POINTER(option_shot_list_1_02_02 + 15, option_shot_list_1_02_02_07);
    STORE_POINTER(option_shot_list_2_02_02 + 5, option_shot_list_1_02_02_02);
    STORE_POINTER(option_shot_list_2_02_02 + 15, option_shot_list_1_02_02_07);
    STORE_POINTER(option_shot_list_1_02_03 + 5, option_shot_list_1_02_02_02);
    STORE_POINTER(option_shot_list_1_02_03 + 15, option_shot_list_1_02_03_07);
    STORE_POINTER(option_shot_list_2_02_03 + 5, option_shot_list_1_02_02_02);
    STORE_POINTER(option_shot_list_2_02_03 + 15, option_shot_list_1_02_03_07);
    STORE_POINTER(option_shot_list_1_02_04 + 5, option_shot_list_1_02_04_02);
    STORE_POINTER(option_shot_list_1_02_04 + 15, option_shot_list_1_02_04_07);
    STORE_POINTER(option_shot_list_2_02_04 + 5, option_shot_list_1_02_04_02);
    STORE_POINTER(option_shot_list_2_02_04 + 15, option_shot_list_1_02_04_07);
    STORE_POINTER(option_shot_list_3_02_00 + 1, option_shot_list_3_02_00_00);
    STORE_POINTER(option_shot_list_3_02_00 + 5, option_shot_list_3_02_00_02);
    STORE_POINTER(option_shot_list_3_02_01 + 1, option_shot_list_3_02_01_00);
    STORE_POINTER(option_shot_list_3_02_01 + 5, option_shot_list_3_02_00_02);
    STORE_POINTER(option_shot_list_3_02_02 + 1, option_shot_list_3_02_02_00);
    STORE_POINTER(option_shot_list_3_02_02 + 5, option_shot_list_3_02_02_02);
    STORE_POINTER(option_shot_list_3_02_03 + 1, option_shot_list_3_02_03_00);
    STORE_POINTER(option_shot_list_3_02_03 + 5, option_shot_list_3_02_02_02);
    STORE_POINTER(option_shot_list_3_02_04 + 1, option_shot_list_3_02_04_00);
    STORE_POINTER(option_shot_list_3_02_04 + 5, option_shot_list_3_02_04_02);
    STORE_POINTER(option_shot_list_4_02_00 + 5, option_shot_list_4_02_00_02);
    STORE_POINTER(option_shot_list_4_02_00 + 15, option_shot_list_4_02_00_07);
    STORE_POINTER(option_shot_list_4_02_00 + 24, option_shot_list_4_02_00_02);
    STORE_POINTER(option_shot_list_4_02_00 + 34, option_shot_list_4_02_00_07);
    STORE_POINTER(option_shot_list_4_02_01 + 5, option_shot_list_4_02_00_02);
    STORE_POINTER(option_shot_list_4_02_01 + 15, option_shot_list_4_02_01_07);
    STORE_POINTER(option_shot_list_4_02_01 + 24, option_shot_list_4_02_00_02);
    STORE_POINTER(option_shot_list_4_02_01 + 34, option_shot_list_4_02_01_07);
    STORE_POINTER(option_shot_list_4_02_02 + 5, option_shot_list_4_02_02_02);
    STORE_POINTER(option_shot_list_4_02_02 + 15, option_shot_list_4_02_02_07);
    STORE_POINTER(option_shot_list_4_02_02 + 24, option_shot_list_4_02_02_02);
    STORE_POINTER(option_shot_list_4_02_02 + 34, option_shot_list_4_02_02_07);
    STORE_POINTER(option_shot_list_4_02_03 + 5, option_shot_list_4_02_02_02);
    STORE_POINTER(option_shot_list_4_02_03 + 15, option_shot_list_4_02_03_07);
    STORE_POINTER(option_shot_list_4_02_03 + 24, option_shot_list_4_02_02_02);
    STORE_POINTER(option_shot_list_4_02_03 + 34, option_shot_list_4_02_03_07);
    STORE_POINTER(option_shot_list_4_02_04 + 5, option_shot_list_4_02_04_02);
    STORE_POINTER(option_shot_list_4_02_04 + 15, option_shot_list_4_02_04_07);
    STORE_POINTER(option_shot_list_4_02_04 + 24, option_shot_list_4_02_04_02);
    STORE_POINTER(option_shot_list_4_02_04 + 34, option_shot_list_4_02_04_07);
    STORE_POINTER(player_shot_4_flight_table, player_shot_4_flight_00);
    STORE_POINTER(player_shot_4_flight_table + 2, player_shot_4_flight_00);
    STORE_POINTER(player_shot_4_flight_table + 4, player_shot_4_flight_02);
    STORE_POINTER(player_shot_4_flight_table + 6, player_shot_4_flight_02);
    STORE_POINTER(player_shot_4_flight_table + 8, player_shot_4_flight_04);
    STORE_POINTER(player_shot_4_flight_table + 10, player_shot_4_flight_04);
    STORE_POINTER(player_shot_4_flight_table + 12, player_shot_4_flight_06);
    STORE_POINTER(player_shot_4_flight_table + 14, player_shot_4_flight_06);
    STORE_POINTER(player_shot_4_flight_table + 16, player_shot_4_flight_08);
    STORE_POINTER(player_shot_4_flight_table + 18, player_shot_4_flight_08);
    STORE_POINTER(player_shot_4_flight_table + 20, player_shot_4_flight_10);
    STORE_POINTER(player_shot_4_flight_table + 22, player_shot_4_flight_11);
    STORE_POINTER(player_shot_4_flight_table + 24, player_shot_4_flight_12);
    STORE_POINTER(player_shot_4_flight_table + 26, player_shot_4_flight_13);
    STORE_POINTER(player_shot_4_flight_table + 28, player_shot_4_flight_14);
    STORE_POINTER(player_shot_4_flight_table + 30, player_shot_4_flight_15);
    STORE_POINTER(player_shot_4_flight_table + 32, player_shot_4_flight_15);
    STORE_POINTER(player_shot_4_flight_table + 34, player_shot_4_flight_17);
    STORE_POINTER(player_shot_4_flight_table + 36, player_shot_4_flight_17);
    STORE_POINTER(player_shot_4_flight_table + 38, player_shot_4_flight_19);
    STORE_POINTER(player_shot_4_flight_table + 40, player_shot_4_flight_19);
    STORE_POINTER(player_shot_4_flight_table + 42, player_shot_4_flight_21);
    STORE_POINTER(player_shot_4_flight_table + 44, player_shot_4_flight_21);
    STORE_POINTER(player_shot_4_flight_table + 46, player_shot_4_flight_23);
    STORE_POINTER(player_shot_4_flight_table + 48, player_shot_4_flight_23);
    STORE_POINTER(option_shot_list_3_02_00_00, option_shot_list_3_02_00_00_00);
    STORE_POINTER(option_shot_list_3_02_00_00 + 2, option_shot_list_3_02_00_00_01);
    STORE_POINTER(option_shot_list_3_02_00_00 + 4, option_shot_list_3_02_00_00_02);
    STORE_POINTER(option_shot_list_3_02_00_00 + 6, option_shot_list_3_02_00_00_03);
    STORE_POINTER(option_shot_list_3_02_00_00 + 8, option_shot_list_3_02_00_00_04);
    STORE_POINTER(option_shot_list_3_02_00_00 + 10, option_shot_list_3_02_00_00_05);
    STORE_POINTER(option_shot_list_3_02_00_00 + 12, option_shot_list_3_02_00_00_06);
    STORE_POINTER(option_shot_list_3_02_00_00 + 14, option_shot_list_3_02_00_00_07);
    STORE_POINTER(option_shot_list_3_02_00_00 + 16, option_shot_list_3_02_00_00_08);
    STORE_POINTER(option_shot_list_3_02_00_00 + 18, option_shot_list_3_02_00_00_09);
    STORE_POINTER(option_shot_list_3_02_00_00 + 20, option_shot_list_3_02_00_00_10);
    STORE_POINTER(option_shot_list_3_02_00_00 + 22, option_shot_list_3_02_00_00_11);
    STORE_POINTER(option_shot_list_3_02_00_00 + 24, option_shot_list_3_02_00_00_12);
    STORE_POINTER(option_shot_list_3_02_00_00 + 26, option_shot_list_3_02_00_00_13);
    STORE_POINTER(option_shot_list_3_02_00_00 + 28, option_shot_list_3_02_00_00_14);
    STORE_POINTER(option_shot_list_3_02_00_00 + 30, option_shot_list_3_02_00_00_15);
    STORE_POINTER(option_shot_list_3_02_00_00 + 32, option_shot_list_3_02_00_00_16);
    STORE_POINTER(option_shot_list_3_02_00_00_00 + 2, option_shot_list_3_02_00_00_00_01);
    STORE_POINTER(option_shot_list_3_02_00_00_01 + 2, option_shot_list_3_02_00_00_01_01);
    STORE_POINTER(option_shot_list_3_02_00_00_02 + 2, option_shot_list_3_02_00_00_02_01);
    STORE_POINTER(option_shot_list_3_02_00_00_03 + 2, option_shot_list_3_02_00_00_03_01);
    STORE_POINTER(option_shot_list_3_02_00_00_04 + 2, option_shot_list_3_02_00_00_04_01);
    STORE_POINTER(option_shot_list_3_02_00_00_05 + 2, option_shot_list_3_02_00_00_05_01);
    STORE_POINTER(option_shot_list_3_02_00_00_06 + 2, option_shot_list_3_02_00_00_06_01);
    STORE_POINTER(option_shot_list_3_02_00_00_07 + 2, option_shot_list_3_02_00_00_07_01);
    STORE_POINTER(option_shot_list_3_02_00_00_08 + 2, option_shot_list_3_02_00_00_08_01);
    STORE_POINTER(option_shot_list_3_02_00_00_09 + 2, option_shot_list_3_02_00_00_09_01);
    STORE_POINTER(option_shot_list_3_02_00_00_10 + 2, option_shot_list_3_02_00_00_10_01);
    STORE_POINTER(option_shot_list_3_02_00_00_11 + 2, option_shot_list_3_02_00_00_11_01);
    STORE_POINTER(option_shot_list_3_02_00_00_12 + 2, option_shot_list_3_02_00_00_12_01);
    STORE_POINTER(option_shot_list_3_02_00_00_13 + 2, option_shot_list_3_02_00_00_13_01);
    STORE_POINTER(option_shot_list_3_02_00_00_14 + 2, option_shot_list_3_02_00_00_14_01);
    STORE_POINTER(option_shot_list_3_02_00_00_15 + 2, option_shot_list_3_02_00_00_15_01);
    STORE_POINTER(option_shot_list_3_02_00_00_16 + 2, option_shot_list_3_02_00_00_16_01);
    STORE_POINTER(option_shot_list_3_02_01_00, option_shot_list_3_02_01_00_00);
    STORE_POINTER(option_shot_list_3_02_01_00 + 2, option_shot_list_3_02_01_00_01);
    STORE_POINTER(option_shot_list_3_02_01_00 + 4, option_shot_list_3_02_01_00_02);
    STORE_POINTER(option_shot_list_3_02_01_00 + 6, option_shot_list_3_02_01_00_03);
    STORE_POINTER(option_shot_list_3_02_01_00 + 8, option_shot_list_3_02_01_00_04);
    STORE_POINTER(option_shot_list_3_02_01_00 + 10, option_shot_list_3_02_01_00_05);
    STORE_POINTER(option_shot_list_3_02_01_00 + 12, option_shot_list_3_02_01_00_06);
    STORE_POINTER(option_shot_list_3_02_01_00 + 14, option_shot_list_3_02_01_00_07);
    STORE_POINTER(option_shot_list_3_02_01_00 + 16, option_shot_list_3_02_01_00_08);
    STORE_POINTER(option_shot_list_3_02_01_00 + 18, option_shot_list_3_02_01_00_09);
    STORE_POINTER(option_shot_list_3_02_01_00 + 20, option_shot_list_3_02_01_00_10);
    STORE_POINTER(option_shot_list_3_02_01_00 + 22, option_shot_list_3_02_01_00_11);
    STORE_POINTER(option_shot_list_3_02_01_00 + 24, option_shot_list_3_02_01_00_12);
    STORE_POINTER(option_shot_list_3_02_01_00 + 26, option_shot_list_3_02_01_00_13);
    STORE_POINTER(option_shot_list_3_02_01_00 + 28, option_shot_list_3_02_01_00_14);
    STORE_POINTER(option_shot_list_3_02_01_00 + 30, option_shot_list_3_02_01_00_15);
    STORE_POINTER(option_shot_list_3_02_01_00 + 32, option_shot_list_3_02_01_00_16);
    STORE_POINTER(option_shot_list_3_02_01_00_00 + 2, option_shot_list_3_02_01_00_00_01);
    STORE_POINTER(option_shot_list_3_02_01_00_01 + 2, option_shot_list_3_02_01_00_01_01);
    STORE_POINTER(option_shot_list_3_02_01_00_02 + 2, option_shot_list_3_02_01_00_02_01);
    STORE_POINTER(option_shot_list_3_02_01_00_03 + 2, option_shot_list_3_02_01_00_03_01);
    STORE_POINTER(option_shot_list_3_02_01_00_04 + 2, option_shot_list_3_02_01_00_04_01);
    STORE_POINTER(option_shot_list_3_02_01_00_05 + 2, option_shot_list_3_02_01_00_05_01);
    STORE_POINTER(option_shot_list_3_02_01_00_06 + 2, option_shot_list_3_02_01_00_06_01);
    STORE_POINTER(option_shot_list_3_02_01_00_07 + 2, option_shot_list_3_02_01_00_07_01);
    STORE_POINTER(option_shot_list_3_02_01_00_08 + 2, option_shot_list_3_02_01_00_08_01);
    STORE_POINTER(option_shot_list_3_02_01_00_09 + 2, option_shot_list_3_02_01_00_09_01);
    STORE_POINTER(option_shot_list_3_02_01_00_10 + 2, option_shot_list_3_02_01_00_10_01);
    STORE_POINTER(option_shot_list_3_02_01_00_11 + 2, option_shot_list_3_02_01_00_11_01);
    STORE_POINTER(option_shot_list_3_02_01_00_12 + 2, option_shot_list_3_02_01_00_12_01);
    STORE_POINTER(option_shot_list_3_02_01_00_13 + 2, option_shot_list_3_02_01_00_13_01);
    STORE_POINTER(option_shot_list_3_02_01_00_14 + 2, option_shot_list_3_02_01_00_14_01);
    STORE_POINTER(option_shot_list_3_02_01_00_15 + 2, option_shot_list_3_02_01_00_15_01);
    STORE_POINTER(option_shot_list_3_02_01_00_16 + 2, option_shot_list_3_02_01_00_16_01);
    STORE_POINTER(option_shot_list_3_02_02_00, option_shot_list_3_02_02_00_00);
    STORE_POINTER(option_shot_list_3_02_02_00 + 2, option_shot_list_3_02_02_00_01);
    STORE_POINTER(option_shot_list_3_02_02_00 + 4, option_shot_list_3_02_02_00_02);
    STORE_POINTER(option_shot_list_3_02_02_00 + 6, option_shot_list_3_02_02_00_03);
    STORE_POINTER(option_shot_list_3_02_02_00 + 8, option_shot_list_3_02_02_00_04);
    STORE_POINTER(option_shot_list_3_02_02_00 + 10, option_shot_list_3_02_02_00_05);
    STORE_POINTER(option_shot_list_3_02_02_00 + 12, option_shot_list_3_02_02_00_06);
    STORE_POINTER(option_shot_list_3_02_02_00 + 14, option_shot_list_3_02_02_00_07);
    STORE_POINTER(option_shot_list_3_02_02_00 + 16, option_shot_list_3_02_02_00_08);
    STORE_POINTER(option_shot_list_3_02_02_00 + 18, option_shot_list_3_02_02_00_09);
    STORE_POINTER(option_shot_list_3_02_02_00 + 20, option_shot_list_3_02_02_00_10);
    STORE_POINTER(option_shot_list_3_02_02_00 + 22, option_shot_list_3_02_02_00_11);
    STORE_POINTER(option_shot_list_3_02_02_00 + 24, option_shot_list_3_02_02_00_12);
    STORE_POINTER(option_shot_list_3_02_02_00 + 26, option_shot_list_3_02_02_00_13);
    STORE_POINTER(option_shot_list_3_02_02_00 + 28, option_shot_list_3_02_02_00_14);
    STORE_POINTER(option_shot_list_3_02_02_00 + 30, option_shot_list_3_02_02_00_15);
    STORE_POINTER(option_shot_list_3_02_02_00 + 32, option_shot_list_3_02_02_00_16);
    STORE_POINTER(option_shot_list_3_02_02_00_00 + 2, option_shot_list_3_02_02_00_00_01);
    STORE_POINTER(option_shot_list_3_02_02_00_01 + 2, option_shot_list_3_02_02_00_01_01);
    STORE_POINTER(option_shot_list_3_02_02_00_02 + 2, option_shot_list_3_02_02_00_02_01);
    STORE_POINTER(option_shot_list_3_02_02_00_03 + 2, option_shot_list_3_02_02_00_03_01);
    STORE_POINTER(option_shot_list_3_02_02_00_04 + 2, option_shot_list_3_02_02_00_04_01);
    STORE_POINTER(option_shot_list_3_02_02_00_05 + 2, option_shot_list_3_02_02_00_05_01);
    STORE_POINTER(option_shot_list_3_02_02_00_06 + 2, option_shot_list_3_02_02_00_06_01);
    STORE_POINTER(option_shot_list_3_02_02_00_07 + 2, option_shot_list_3_02_02_00_07_01);
    STORE_POINTER(option_shot_list_3_02_02_00_08 + 2, option_shot_list_3_02_02_00_08_01);
    STORE_POINTER(option_shot_list_3_02_02_00_09 + 2, option_shot_list_3_02_02_00_09_01);
    STORE_POINTER(option_shot_list_3_02_02_00_10 + 2, option_shot_list_3_02_02_00_10_01);
    STORE_POINTER(option_shot_list_3_02_02_00_11 + 2, option_shot_list_3_02_02_00_11_01);
    STORE_POINTER(option_shot_list_3_02_02_00_12 + 2, option_shot_list_3_02_02_00_12_01);
    STORE_POINTER(option_shot_list_3_02_02_00_13 + 2, option_shot_list_3_02_02_00_13_01);
    STORE_POINTER(option_shot_list_3_02_02_00_14 + 2, option_shot_list_3_02_02_00_14_01);
    STORE_POINTER(option_shot_list_3_02_02_00_15 + 2, option_shot_list_3_02_02_00_15_01);
    STORE_POINTER(option_shot_list_3_02_02_00_16 + 2, option_shot_list_3_02_02_00_16_01);
    STORE_POINTER(option_shot_list_3_02_03_00, option_shot_list_3_02_03_00_00);
    STORE_POINTER(option_shot_list_3_02_03_00 + 2, option_shot_list_3_02_03_00_01);
    STORE_POINTER(option_shot_list_3_02_03_00 + 4, option_shot_list_3_02_03_00_02);
    STORE_POINTER(option_shot_list_3_02_03_00 + 6, option_shot_list_3_02_03_00_03);
    STORE_POINTER(option_shot_list_3_02_03_00 + 8, option_shot_list_3_02_03_00_04);
    STORE_POINTER(option_shot_list_3_02_03_00 + 10, option_shot_list_3_02_03_00_05);
    STORE_POINTER(option_shot_list_3_02_03_00 + 12, option_shot_list_3_02_03_00_06);
    STORE_POINTER(option_shot_list_3_02_03_00 + 14, option_shot_list_3_02_03_00_07);
    STORE_POINTER(option_shot_list_3_02_03_00 + 16, option_shot_list_3_02_03_00_08);
    STORE_POINTER(option_shot_list_3_02_03_00 + 18, option_shot_list_3_02_03_00_09);
    STORE_POINTER(option_shot_list_3_02_03_00 + 20, option_shot_list_3_02_03_00_10);
    STORE_POINTER(option_shot_list_3_02_03_00 + 22, option_shot_list_3_02_03_00_11);
    STORE_POINTER(option_shot_list_3_02_03_00 + 24, option_shot_list_3_02_03_00_12);
    STORE_POINTER(option_shot_list_3_02_03_00 + 26, option_shot_list_3_02_03_00_13);
    STORE_POINTER(option_shot_list_3_02_03_00 + 28, option_shot_list_3_02_03_00_14);
    STORE_POINTER(option_shot_list_3_02_03_00 + 30, option_shot_list_3_02_03_00_15);
    STORE_POINTER(option_shot_list_3_02_03_00 + 32, option_shot_list_3_02_03_00_16);
    STORE_POINTER(option_shot_list_3_02_03_00_00 + 2, option_shot_list_3_02_03_00_00_01);
    STORE_POINTER(option_shot_list_3_02_03_00_01 + 2, option_shot_list_3_02_03_00_01_01);
    STORE_POINTER(option_shot_list_3_02_03_00_02 + 2, option_shot_list_3_02_03_00_02_01);
    STORE_POINTER(option_shot_list_3_02_03_00_03 + 2, option_shot_list_3_02_03_00_03_01);
    STORE_POINTER(option_shot_list_3_02_03_00_04 + 2, option_shot_list_3_02_03_00_04_01);
    STORE_POINTER(option_shot_list_3_02_03_00_05 + 2, option_shot_list_3_02_03_00_05_01);
    STORE_POINTER(option_shot_list_3_02_03_00_06 + 2, option_shot_list_3_02_03_00_06_01);
    STORE_POINTER(option_shot_list_3_02_03_00_07 + 2, option_shot_list_3_02_03_00_07_01);
    STORE_POINTER(option_shot_list_3_02_03_00_08 + 2, option_shot_list_3_02_03_00_08_01);
    STORE_POINTER(option_shot_list_3_02_03_00_09 + 2, option_shot_list_3_02_03_00_09_01);
    STORE_POINTER(option_shot_list_3_02_03_00_10 + 2, option_shot_list_3_02_03_00_10_01);
    STORE_POINTER(option_shot_list_3_02_03_00_11 + 2, option_shot_list_3_02_03_00_11_01);
    STORE_POINTER(option_shot_list_3_02_03_00_12 + 2, option_shot_list_3_02_03_00_12_01);
    STORE_POINTER(option_shot_list_3_02_03_00_13 + 2, option_shot_list_3_02_03_00_13_01);
    STORE_POINTER(option_shot_list_3_02_03_00_14 + 2, option_shot_list_3_02_03_00_14_01);
    STORE_POINTER(option_shot_list_3_02_03_00_15 + 2, option_shot_list_3_02_03_00_15_01);
    STORE_POINTER(option_shot_list_3_02_03_00_16 + 2, option_shot_list_3_02_03_00_16_01);
    STORE_POINTER(option_shot_list_3_02_04_00, option_shot_list_3_02_04_00_00);
    STORE_POINTER(option_shot_list_3_02_04_00 + 2, option_shot_list_3_02_04_00_01);
    STORE_POINTER(option_shot_list_3_02_04_00 + 4, option_shot_list_3_02_04_00_02);
    STORE_POINTER(option_shot_list_3_02_04_00 + 6, option_shot_list_3_02_04_00_03);
    STORE_POINTER(option_shot_list_3_02_04_00 + 8, option_shot_list_3_02_04_00_04);
    STORE_POINTER(option_shot_list_3_02_04_00 + 10, option_shot_list_3_02_04_00_05);
    STORE_POINTER(option_shot_list_3_02_04_00 + 12, option_shot_list_3_02_04_00_06);
    STORE_POINTER(option_shot_list_3_02_04_00 + 14, option_shot_list_3_02_04_00_07);
    STORE_POINTER(option_shot_list_3_02_04_00 + 16, option_shot_list_3_02_04_00_08);
    STORE_POINTER(option_shot_list_3_02_04_00 + 18, option_shot_list_3_02_04_00_09);
    STORE_POINTER(option_shot_list_3_02_04_00 + 20, option_shot_list_3_02_04_00_10);
    STORE_POINTER(option_shot_list_3_02_04_00 + 22, option_shot_list_3_02_04_00_11);
    STORE_POINTER(option_shot_list_3_02_04_00 + 24, option_shot_list_3_02_04_00_12);
    STORE_POINTER(option_shot_list_3_02_04_00 + 26, option_shot_list_3_02_04_00_13);
    STORE_POINTER(option_shot_list_3_02_04_00 + 28, option_shot_list_3_02_04_00_14);
    STORE_POINTER(option_shot_list_3_02_04_00 + 30, option_shot_list_3_02_04_00_15);
    STORE_POINTER(option_shot_list_3_02_04_00 + 32, option_shot_list_3_02_04_00_16);
    STORE_POINTER(option_shot_list_3_02_04_00_00 + 2, option_shot_list_3_02_04_00_00_01);
    STORE_POINTER(option_shot_list_3_02_04_00_01 + 2, option_shot_list_3_02_04_00_01_01);
    STORE_POINTER(option_shot_list_3_02_04_00_02 + 2, option_shot_list_3_02_04_00_02_01);
    STORE_POINTER(option_shot_list_3_02_04_00_03 + 2, option_shot_list_3_02_04_00_03_01);
    STORE_POINTER(option_shot_list_3_02_04_00_04 + 2, option_shot_list_3_02_04_00_04_01);
    STORE_POINTER(option_shot_list_3_02_04_00_05 + 2, option_shot_list_3_02_04_00_05_01);
    STORE_POINTER(option_shot_list_3_02_04_00_06 + 2, option_shot_list_3_02_04_00_06_01);
    STORE_POINTER(option_shot_list_3_02_04_00_07 + 2, option_shot_list_3_02_04_00_07_01);
    STORE_POINTER(option_shot_list_3_02_04_00_08 + 2, option_shot_list_3_02_04_00_08_01);
    STORE_POINTER(option_shot_list_3_02_04_00_09 + 2, option_shot_list_3_02_04_00_09_01);
    STORE_POINTER(option_shot_list_3_02_04_00_10 + 2, option_shot_list_3_02_04_00_10_01);
    STORE_POINTER(option_shot_list_3_02_04_00_11 + 2, option_shot_list_3_02_04_00_11_01);
    STORE_POINTER(option_shot_list_3_02_04_00_12 + 2, option_shot_list_3_02_04_00_12_01);
    STORE_POINTER(option_shot_list_3_02_04_00_13 + 2, option_shot_list_3_02_04_00_13_01);
    STORE_POINTER(option_shot_list_3_02_04_00_14 + 2, option_shot_list_3_02_04_00_14_01);
    STORE_POINTER(option_shot_list_3_02_04_00_15 + 2, option_shot_list_3_02_04_00_15_01);
    STORE_POINTER(option_shot_list_3_02_04_00_16 + 2, option_shot_list_3_02_04_00_16_01);
    STORE_POINTER(player_shot_4_impact_table, player_shot_4_impact_00);
    STORE_POINTER(player_shot_4_impact_table + 2, player_shot_4_impact_00);
    STORE_POINTER(player_shot_4_impact_table + 4, player_shot_4_impact_02);
    STORE_POINTER(player_shot_4_impact_table + 6, player_shot_4_impact_02);
    STORE_POINTER(player_shot_4_impact_table + 8, player_shot_4_impact_04);
    STORE_POINTER(player_shot_4_impact_table + 10, player_shot_4_impact_04);
    STORE_POINTER(player_shot_4_impact_table + 12, player_shot_4_impact_06);
    STORE_POINTER(player_shot_4_impact_table + 14, player_shot_4_impact_06);
    STORE_POINTER(player_shot_4_impact_table + 16, player_shot_4_impact_08);
    STORE_POINTER(player_shot_4_impact_table + 18, player_shot_4_impact_08);
    STORE_POINTER(player_shot_4_impact_table + 20, player_shot_4_impact_10);
    STORE_POINTER(player_shot_4_impact_table + 22, player_shot_4_impact_11);
    STORE_POINTER(player_shot_4_impact_table + 24, player_shot_4_impact_12);
    STORE_POINTER(player_shot_4_impact_table + 26, player_shot_4_impact_13);
    STORE_POINTER(player_shot_4_impact_table + 28, player_shot_4_impact_14);
    STORE_POINTER(player_shot_4_impact_table + 30, player_shot_4_impact_15);
    STORE_POINTER(player_shot_4_impact_table + 32, player_shot_4_impact_15);
    STORE_POINTER(player_shot_4_impact_table + 34, player_shot_4_impact_17);
    STORE_POINTER(player_shot_4_impact_table + 36, player_shot_4_impact_17);
    STORE_POINTER(player_shot_4_impact_table + 38, player_shot_4_impact_19);
    STORE_POINTER(player_shot_4_impact_table + 40, player_shot_4_impact_19);
    STORE_POINTER(player_shot_4_impact_table + 42, player_shot_4_impact_21);
    STORE_POINTER(player_shot_4_impact_table + 44, player_shot_4_impact_21);
    STORE_POINTER(player_shot_4_impact_table + 46, player_shot_4_impact_23);
    STORE_POINTER(player_shot_4_impact_table + 48, player_shot_4_impact_23);
    STORE_POINTER(player_shot_4_impact_00 + 3, player_shot_4_impact_frames_00);
    STORE_POINTER(player_shot_4_impact_02 + 3, player_shot_4_impact_frames_00);
    STORE_POINTER(player_shot_4_impact_04 + 3, player_shot_4_impact_frames_04);
    STORE_POINTER(player_shot_4_impact_06 + 3, player_shot_4_impact_frames_04);
    STORE_POINTER(player_shot_4_impact_08 + 3, player_shot_4_impact_frames_08);
    STORE_POINTER(player_shot_4_impact_10 + 3, player_shot_4_impact_frames_10);
    STORE_POINTER(player_shot_4_impact_11 + 3, player_shot_4_impact_frames_10);
    STORE_POINTER(player_shot_4_impact_12 + 3, player_shot_4_impact_frames_12);
    STORE_POINTER(player_shot_4_impact_13 + 3, player_shot_4_impact_frames_12);
    STORE_POINTER(player_shot_4_impact_14 + 3, player_shot_4_impact_frames_14);
    STORE_POINTER(player_shot_4_impact_15 + 3, player_shot_4_impact_frames_15);
    STORE_POINTER(player_shot_4_impact_17 + 3, player_shot_4_impact_frames_15);
    STORE_POINTER(player_shot_4_impact_19 + 3, player_shot_4_impact_frames_19);
    STORE_POINTER(player_shot_4_impact_21 + 3, player_shot_4_impact_frames_19);
    STORE_POINTER(player_shot_4_impact_23 + 3, player_shot_4_impact_frames_23);
}

extern u16 option_shot_list_1_03_00_02[];
extern u16 option_shot_list_3_03_00_02[];
extern u16 option_shot_list_4_03_00_02[];
extern u16 option_shot_list_1_03_00_07[];
extern u16 player_shot_8_flight_028_01[];
extern u16 player_shot_8_flight_048_01[];
extern u16 player_shot_8_flight_068_01[];
extern u16 player_shot_8_flight_088_01[];
extern u16 replay_targets_shot_lists_292[];
extern u16 option_shot_list_4_03_00_07[];
extern u16 player_shot_8_impact_frames_00[];
extern u16 player_shot_8_impact_frames_02[];
extern u16 player_shot_8_impact_frames_06[];
extern u16 player_shot_8_impact_frames_10[];
extern u16 player_shot_8_impact_frames_11[];
extern u16 player_shot_8_impact_frames_13[];
extern u16 player_shot_8_impact_frames_15[];
extern u16 player_shot_8_impact_frames_17[];
extern u16 player_shot_8_impact_frames_21[];
extern u16 option_shot_list_3_03_00_00[];
extern u16 player_shot_8_impact_00[];
extern u16 player_shot_8_impact_02[];
extern u16 player_shot_8_impact_04[];
extern u16 player_shot_8_impact_06[];
extern u16 player_shot_8_impact_08[];
extern u16 player_shot_8_impact_10[];
extern u16 player_shot_8_impact_11[];
extern u16 player_shot_8_impact_12[];
extern u16 player_shot_8_impact_13[];
extern u16 player_shot_8_impact_14[];
extern u16 player_shot_8_impact_15[];
extern u16 player_shot_8_impact_17[];
extern u16 player_shot_8_impact_19[];
extern u16 player_shot_8_impact_21[];
extern u16 player_shot_8_impact_23[];
extern u16 player_shot_8_flight_000[];
extern u16 player_shot_8_flight_002[];
extern u16 player_shot_8_flight_004[];
extern u16 player_shot_8_flight_006[];
extern u16 player_shot_8_flight_008[];
extern u16 player_shot_8_flight_010[];
extern u16 player_shot_8_flight_011[];
extern u16 player_shot_8_flight_012[];
extern u16 player_shot_8_flight_013[];
extern u16 player_shot_8_flight_014[];
extern u16 player_shot_8_flight_015[];
extern u16 player_shot_8_flight_017[];
extern u16 player_shot_8_flight_019[];
extern u16 player_shot_8_flight_021[];
extern u16 player_shot_8_flight_023[];
extern u16 player_shot_8_flight_028[];
extern u16 player_shot_8_flight_029[];
extern u16 player_shot_8_flight_030[];
extern u16 player_shot_8_flight_031[];
extern u16 player_shot_8_flight_032[];
extern u16 player_shot_8_flight_033[];
extern u16 player_shot_8_flight_034[];
extern u16 player_shot_8_flight_035[];
extern u16 player_shot_8_flight_036[];
extern u16 player_shot_8_flight_037[];
extern u16 player_shot_8_flight_038[];
extern u16 player_shot_8_flight_039[];
extern u16 player_shot_8_flight_040[];
extern u16 player_shot_8_flight_041[];
extern u16 player_shot_8_flight_042[];
extern u16 player_shot_8_flight_043[];
extern u16 player_shot_8_flight_044[];
extern u16 player_shot_8_flight_048[];
extern u16 player_shot_8_flight_049[];
extern u16 player_shot_8_flight_050[];
extern u16 player_shot_8_flight_051[];
extern u16 player_shot_8_flight_052[];
extern u16 player_shot_8_flight_053[];
extern u16 player_shot_8_flight_054[];
extern u16 player_shot_8_flight_055[];
extern u16 player_shot_8_flight_056[];
extern u16 player_shot_8_flight_057[];
extern u16 player_shot_8_flight_058[];
extern u16 player_shot_8_flight_059[];
extern u16 player_shot_8_flight_060[];
extern u16 player_shot_8_flight_061[];
extern u16 player_shot_8_flight_062[];
extern u16 player_shot_8_flight_063[];
extern u16 player_shot_8_flight_064[];
extern u16 player_shot_8_flight_068[];
extern u16 player_shot_8_flight_069[];
extern u16 player_shot_8_flight_070[];
extern u16 player_shot_8_flight_071[];
extern u16 player_shot_8_flight_072[];
extern u16 player_shot_8_flight_073[];
extern u16 player_shot_8_flight_074[];
extern u16 player_shot_8_flight_075[];
extern u16 player_shot_8_flight_076[];
extern u16 player_shot_8_flight_077[];
extern u16 player_shot_8_flight_078[];
extern u16 player_shot_8_flight_079[];
extern u16 player_shot_8_flight_080[];
extern u16 player_shot_8_flight_081[];
extern u16 player_shot_8_flight_082[];
extern u16 player_shot_8_flight_083[];
extern u16 player_shot_8_flight_084[];
extern u16 player_shot_8_flight_088[];
extern u16 player_shot_8_flight_089[];
extern u16 player_shot_8_flight_090[];
extern u16 player_shot_8_flight_091[];
extern u16 player_shot_8_flight_092[];
extern u16 player_shot_8_flight_093[];
extern u16 player_shot_8_flight_094[];
extern u16 player_shot_8_flight_095[];
extern u16 player_shot_8_flight_096[];
extern u16 player_shot_8_flight_097[];
extern u16 player_shot_8_flight_098[];
extern u16 player_shot_8_flight_099[];
extern u16 player_shot_8_flight_100[];
extern u16 player_shot_8_flight_101[];
extern u16 player_shot_8_flight_102[];
extern u16 player_shot_8_flight_103[];
extern u16 player_shot_8_flight_104[];
extern u16 option_shot_list_3_03_00_00_at_0[];
extern u16 option_shot_list_3_03_00_00_at_2[];
extern u16 option_shot_list_3_03_00_00_at_4[];
extern u16 option_shot_list_3_03_00_00_at_6[];
extern u16 option_shot_list_3_03_00_00_at_8[];
extern u16 option_shot_list_3_03_00_00_at_10[];
extern u16 option_shot_list_3_03_00_00_at_12[];
extern u16 option_shot_list_3_03_00_00_at_14[];
extern u16 option_shot_list_3_03_00_00_at_16[];
extern u16 option_shot_list_3_03_00_00_at_18[];
extern u16 option_shot_list_3_03_00_00_at_20[];
extern u16 option_shot_list_3_03_00_00_at_22[];
extern u16 option_shot_list_3_03_00_00_at_24[];
extern u16 option_shot_list_3_03_00_00_at_26[];
extern u16 option_shot_list_3_03_00_00_at_28[];
extern u16 option_shot_list_3_03_00_00_at_30[];
extern u16 option_shot_list_3_03_00_00_at_32[];

extern u16 player_shot_8_flight_table[];
extern u16 player_shot_8_impact_table[];

void player_shot_8_tables_init(void) {
    STORE_POINTER(option_shot_list_1_03_00 + 5, option_shot_list_1_03_00_02);
    STORE_POINTER(option_shot_list_1_03_00 + 15, option_shot_list_1_03_00_07);
    STORE_POINTER(option_shot_list_2_03_00 + 5, option_shot_list_1_03_00_02);
    STORE_POINTER(option_shot_list_2_03_00 + 15, option_shot_list_1_03_00_07);
    STORE_POINTER(option_shot_list_1_03_01 + 5, option_shot_list_1_03_00_02);
    STORE_POINTER(option_shot_list_1_03_01 + 15, option_shot_list_1_03_00_07);
    STORE_POINTER(option_shot_list_2_03_01 + 5, option_shot_list_1_03_00_02);
    STORE_POINTER(option_shot_list_2_03_01 + 15, option_shot_list_1_03_00_07);
    STORE_POINTER(option_shot_list_1_03_02 + 5, option_shot_list_1_03_00_02);
    STORE_POINTER(option_shot_list_1_03_02 + 15, option_shot_list_1_03_00_07);
    STORE_POINTER(option_shot_list_2_03_02 + 5, option_shot_list_1_03_00_02);
    STORE_POINTER(option_shot_list_2_03_02 + 15, option_shot_list_1_03_00_07);
    STORE_POINTER(option_shot_list_1_03_03 + 5, option_shot_list_1_03_00_02);
    STORE_POINTER(option_shot_list_1_03_03 + 15, option_shot_list_1_03_00_07);
    STORE_POINTER(option_shot_list_2_03_03 + 5, option_shot_list_1_03_00_02);
    STORE_POINTER(option_shot_list_2_03_03 + 15, option_shot_list_1_03_00_07);
    STORE_POINTER(option_shot_list_1_03_04 + 5, option_shot_list_1_03_00_02);
    STORE_POINTER(option_shot_list_1_03_04 + 15, option_shot_list_1_03_00_07);
    STORE_POINTER(option_shot_list_2_03_04 + 5, option_shot_list_1_03_00_02);
    STORE_POINTER(option_shot_list_2_03_04 + 15, option_shot_list_1_03_00_07);
    STORE_POINTER(option_shot_list_3_03_00 + 1, option_shot_list_3_03_00_00);
    STORE_POINTER(option_shot_list_3_03_00 + 5, option_shot_list_3_03_00_02);
    STORE_POINTER(option_shot_list_3_03_01 + 1, option_shot_list_3_03_00_00);
    STORE_POINTER(option_shot_list_3_03_01 + 5, option_shot_list_3_03_00_02);
    STORE_POINTER(option_shot_list_3_03_02 + 1, option_shot_list_3_03_00_00);
    STORE_POINTER(option_shot_list_3_03_02 + 5, option_shot_list_3_03_00_02);
    STORE_POINTER(option_shot_list_3_03_03 + 1, option_shot_list_3_03_00_00);
    STORE_POINTER(option_shot_list_3_03_03 + 5, option_shot_list_3_03_00_02);
    STORE_POINTER(option_shot_list_3_03_04 + 1, option_shot_list_3_03_00_00);
    STORE_POINTER(option_shot_list_3_03_04 + 5, option_shot_list_3_03_00_02);
    STORE_POINTER(option_shot_list_4_03_00 + 5, option_shot_list_4_03_00_02);
    STORE_POINTER(option_shot_list_4_03_00 + 15, option_shot_list_4_03_00_07);
    STORE_POINTER(option_shot_list_4_03_00 + 24, option_shot_list_4_03_00_02);
    STORE_POINTER(option_shot_list_4_03_00 + 34, option_shot_list_4_03_00_07);
    STORE_POINTER(option_shot_list_4_03_01 + 5, option_shot_list_4_03_00_02);
    STORE_POINTER(option_shot_list_4_03_01 + 15, option_shot_list_4_03_00_07);
    STORE_POINTER(option_shot_list_4_03_01 + 24, option_shot_list_4_03_00_02);
    STORE_POINTER(option_shot_list_4_03_01 + 34, option_shot_list_4_03_00_07);
    STORE_POINTER(option_shot_list_4_03_02 + 5, option_shot_list_4_03_00_02);
    STORE_POINTER(option_shot_list_4_03_02 + 15, option_shot_list_4_03_00_07);
    STORE_POINTER(option_shot_list_4_03_02 + 24, option_shot_list_4_03_00_02);
    STORE_POINTER(option_shot_list_4_03_02 + 34, option_shot_list_4_03_00_07);
    STORE_POINTER(option_shot_list_4_03_03 + 5, option_shot_list_4_03_00_02);
    STORE_POINTER(option_shot_list_4_03_03 + 15, option_shot_list_4_03_00_07);
    STORE_POINTER(option_shot_list_4_03_03 + 24, option_shot_list_4_03_00_02);
    STORE_POINTER(option_shot_list_4_03_03 + 34, option_shot_list_4_03_00_07);
    STORE_POINTER(option_shot_list_4_03_04 + 5, option_shot_list_4_03_00_02);
    STORE_POINTER(option_shot_list_4_03_04 + 15, option_shot_list_4_03_00_07);
    STORE_POINTER(option_shot_list_4_03_04 + 24, option_shot_list_4_03_00_02);
    STORE_POINTER(option_shot_list_4_03_04 + 34, option_shot_list_4_03_00_07);
    STORE_POINTER(player_shot_8_flight_table, player_shot_8_flight_000);
    STORE_POINTER(player_shot_8_flight_table + 2, player_shot_8_flight_000);
    STORE_POINTER(player_shot_8_flight_table + 4, player_shot_8_flight_002);
    STORE_POINTER(player_shot_8_flight_table + 6, player_shot_8_flight_002);
    STORE_POINTER(player_shot_8_flight_table + 8, player_shot_8_flight_004);
    STORE_POINTER(player_shot_8_flight_table + 10, player_shot_8_flight_004);
    STORE_POINTER(player_shot_8_flight_table + 12, player_shot_8_flight_006);
    STORE_POINTER(player_shot_8_flight_table + 14, player_shot_8_flight_006);
    STORE_POINTER(player_shot_8_flight_table + 16, player_shot_8_flight_008);
    STORE_POINTER(player_shot_8_flight_table + 18, player_shot_8_flight_008);
    STORE_POINTER(player_shot_8_flight_table + 20, player_shot_8_flight_010);
    STORE_POINTER(player_shot_8_flight_table + 22, player_shot_8_flight_011);
    STORE_POINTER(player_shot_8_flight_table + 24, player_shot_8_flight_012);
    STORE_POINTER(player_shot_8_flight_table + 26, player_shot_8_flight_013);
    STORE_POINTER(player_shot_8_flight_table + 28, player_shot_8_flight_014);
    STORE_POINTER(player_shot_8_flight_table + 30, player_shot_8_flight_015);
    STORE_POINTER(player_shot_8_flight_table + 32, player_shot_8_flight_015);
    STORE_POINTER(player_shot_8_flight_table + 34, player_shot_8_flight_017);
    STORE_POINTER(player_shot_8_flight_table + 36, player_shot_8_flight_017);
    STORE_POINTER(player_shot_8_flight_table + 38, player_shot_8_flight_019);
    STORE_POINTER(player_shot_8_flight_table + 40, player_shot_8_flight_019);
    STORE_POINTER(player_shot_8_flight_table + 42, player_shot_8_flight_021);
    STORE_POINTER(player_shot_8_flight_table + 44, player_shot_8_flight_021);
    STORE_POINTER(player_shot_8_flight_table + 46, player_shot_8_flight_023);
    STORE_POINTER(player_shot_8_flight_table + 48, player_shot_8_flight_023);
    STORE_POINTER(player_shot_8_flight_table + 56, player_shot_8_flight_028);
    STORE_POINTER(player_shot_8_flight_table + 58, player_shot_8_flight_029);
    STORE_POINTER(player_shot_8_flight_table + 60, player_shot_8_flight_030);
    STORE_POINTER(player_shot_8_flight_table + 62, player_shot_8_flight_031);
    STORE_POINTER(player_shot_8_flight_table + 64, player_shot_8_flight_032);
    STORE_POINTER(player_shot_8_flight_table + 66, player_shot_8_flight_033);
    STORE_POINTER(player_shot_8_flight_table + 68, player_shot_8_flight_034);
    STORE_POINTER(player_shot_8_flight_table + 70, player_shot_8_flight_035);
    STORE_POINTER(player_shot_8_flight_table + 72, player_shot_8_flight_036);
    STORE_POINTER(player_shot_8_flight_table + 74, player_shot_8_flight_037);
    STORE_POINTER(player_shot_8_flight_table + 76, player_shot_8_flight_038);
    STORE_POINTER(player_shot_8_flight_table + 78, player_shot_8_flight_039);
    STORE_POINTER(player_shot_8_flight_table + 80, player_shot_8_flight_040);
    STORE_POINTER(player_shot_8_flight_table + 82, player_shot_8_flight_041);
    STORE_POINTER(player_shot_8_flight_table + 84, player_shot_8_flight_042);
    STORE_POINTER(player_shot_8_flight_table + 86, player_shot_8_flight_043);
    STORE_POINTER(player_shot_8_flight_table + 88, player_shot_8_flight_044);
    STORE_POINTER(player_shot_8_flight_028 + 2, player_shot_8_flight_028_01);
    STORE_POINTER(player_shot_8_flight_029 + 2, player_shot_8_flight_028_01);
    STORE_POINTER(player_shot_8_flight_030 + 2, player_shot_8_flight_028_01);
    STORE_POINTER(player_shot_8_flight_031 + 2, player_shot_8_flight_028_01);
    STORE_POINTER(player_shot_8_flight_032 + 2, player_shot_8_flight_028_01);
    STORE_POINTER(player_shot_8_flight_033 + 2, player_shot_8_flight_028_01);
    STORE_POINTER(player_shot_8_flight_034 + 2, player_shot_8_flight_028_01);
    STORE_POINTER(player_shot_8_flight_035 + 2, player_shot_8_flight_028_01);
    STORE_POINTER(player_shot_8_flight_036 + 2, player_shot_8_flight_028_01);
    STORE_POINTER(player_shot_8_flight_037 + 2, player_shot_8_flight_028_01);
    STORE_POINTER(player_shot_8_flight_038 + 2, player_shot_8_flight_028_01);
    STORE_POINTER(player_shot_8_flight_039 + 2, player_shot_8_flight_028_01);
    STORE_POINTER(player_shot_8_flight_040 + 2, player_shot_8_flight_028_01);
    STORE_POINTER(player_shot_8_flight_041 + 2, player_shot_8_flight_028_01);
    STORE_POINTER(player_shot_8_flight_042 + 2, player_shot_8_flight_028_01);
    STORE_POINTER(player_shot_8_flight_043 + 2, player_shot_8_flight_028_01);
    STORE_POINTER(player_shot_8_flight_044 + 2, player_shot_8_flight_028_01);
    STORE_POINTER(player_shot_8_flight_table + 96, player_shot_8_flight_048);
    STORE_POINTER(player_shot_8_flight_table + 98, player_shot_8_flight_049);
    STORE_POINTER(player_shot_8_flight_table + 100, player_shot_8_flight_050);
    STORE_POINTER(player_shot_8_flight_table + 102, player_shot_8_flight_051);
    STORE_POINTER(player_shot_8_flight_table + 104, player_shot_8_flight_052);
    STORE_POINTER(player_shot_8_flight_table + 106, player_shot_8_flight_053);
    STORE_POINTER(player_shot_8_flight_table + 108, player_shot_8_flight_054);
    STORE_POINTER(player_shot_8_flight_table + 110, player_shot_8_flight_055);
    STORE_POINTER(player_shot_8_flight_table + 112, player_shot_8_flight_056);
    STORE_POINTER(player_shot_8_flight_table + 114, player_shot_8_flight_057);
    STORE_POINTER(player_shot_8_flight_table + 116, player_shot_8_flight_058);
    STORE_POINTER(player_shot_8_flight_table + 118, player_shot_8_flight_059);
    STORE_POINTER(player_shot_8_flight_table + 120, player_shot_8_flight_060);
    STORE_POINTER(player_shot_8_flight_table + 122, player_shot_8_flight_061);
    STORE_POINTER(player_shot_8_flight_table + 124, player_shot_8_flight_062);
    STORE_POINTER(player_shot_8_flight_table + 126, player_shot_8_flight_063);
    STORE_POINTER(player_shot_8_flight_table + 128, player_shot_8_flight_064);
    STORE_POINTER(player_shot_8_flight_048 + 2, player_shot_8_flight_048_01);
    STORE_POINTER(player_shot_8_flight_049 + 2, player_shot_8_flight_048_01);
    STORE_POINTER(player_shot_8_flight_050 + 2, player_shot_8_flight_048_01);
    STORE_POINTER(player_shot_8_flight_051 + 2, player_shot_8_flight_048_01);
    STORE_POINTER(player_shot_8_flight_052 + 2, player_shot_8_flight_048_01);
    STORE_POINTER(player_shot_8_flight_053 + 2, player_shot_8_flight_048_01);
    STORE_POINTER(player_shot_8_flight_054 + 2, player_shot_8_flight_048_01);
    STORE_POINTER(player_shot_8_flight_055 + 2, player_shot_8_flight_048_01);
    STORE_POINTER(player_shot_8_flight_056 + 2, player_shot_8_flight_048_01);
    STORE_POINTER(player_shot_8_flight_057 + 2, player_shot_8_flight_048_01);
    STORE_POINTER(player_shot_8_flight_058 + 2, player_shot_8_flight_048_01);
    STORE_POINTER(player_shot_8_flight_059 + 2, player_shot_8_flight_048_01);
    STORE_POINTER(player_shot_8_flight_060 + 2, player_shot_8_flight_048_01);
    STORE_POINTER(player_shot_8_flight_061 + 2, player_shot_8_flight_048_01);
    STORE_POINTER(player_shot_8_flight_062 + 2, player_shot_8_flight_048_01);
    STORE_POINTER(player_shot_8_flight_063 + 2, player_shot_8_flight_048_01);
    STORE_POINTER(player_shot_8_flight_064 + 2, player_shot_8_flight_048_01);
    STORE_POINTER(player_shot_8_flight_table + 136, player_shot_8_flight_068);
    STORE_POINTER(player_shot_8_flight_table + 138, player_shot_8_flight_069);
    STORE_POINTER(player_shot_8_flight_table + 140, player_shot_8_flight_070);
    STORE_POINTER(player_shot_8_flight_table + 142, player_shot_8_flight_071);
    STORE_POINTER(player_shot_8_flight_table + 144, player_shot_8_flight_072);
    STORE_POINTER(player_shot_8_flight_table + 146, player_shot_8_flight_073);
    STORE_POINTER(player_shot_8_flight_table + 148, player_shot_8_flight_074);
    STORE_POINTER(player_shot_8_flight_table + 150, player_shot_8_flight_075);
    STORE_POINTER(player_shot_8_flight_table + 152, player_shot_8_flight_076);
    STORE_POINTER(player_shot_8_flight_table + 154, player_shot_8_flight_077);
    STORE_POINTER(player_shot_8_flight_table + 156, player_shot_8_flight_078);
    STORE_POINTER(player_shot_8_flight_table + 158, player_shot_8_flight_079);
    STORE_POINTER(player_shot_8_flight_table + 160, player_shot_8_flight_080);
    STORE_POINTER(player_shot_8_flight_table + 162, player_shot_8_flight_081);
    STORE_POINTER(player_shot_8_flight_table + 164, player_shot_8_flight_082);
    STORE_POINTER(player_shot_8_flight_table + 166, player_shot_8_flight_083);
    STORE_POINTER(player_shot_8_flight_table + 168, player_shot_8_flight_084);
    STORE_POINTER(player_shot_8_flight_068 + 2, player_shot_8_flight_068_01);
    STORE_POINTER(player_shot_8_flight_069 + 2, player_shot_8_flight_068_01);
    STORE_POINTER(player_shot_8_flight_070 + 2, player_shot_8_flight_068_01);
    STORE_POINTER(player_shot_8_flight_071 + 2, player_shot_8_flight_068_01);
    STORE_POINTER(player_shot_8_flight_072 + 2, player_shot_8_flight_068_01);
    STORE_POINTER(player_shot_8_flight_073 + 2, player_shot_8_flight_068_01);
    STORE_POINTER(player_shot_8_flight_074 + 2, player_shot_8_flight_068_01);
    STORE_POINTER(player_shot_8_flight_075 + 2, player_shot_8_flight_068_01);
    STORE_POINTER(player_shot_8_flight_076 + 2, player_shot_8_flight_068_01);
    STORE_POINTER(player_shot_8_flight_077 + 2, player_shot_8_flight_068_01);
    STORE_POINTER(player_shot_8_flight_078 + 2, player_shot_8_flight_068_01);
    STORE_POINTER(player_shot_8_flight_079 + 2, player_shot_8_flight_068_01);
    STORE_POINTER(player_shot_8_flight_080 + 2, player_shot_8_flight_068_01);
    STORE_POINTER(player_shot_8_flight_081 + 2, player_shot_8_flight_068_01);
    STORE_POINTER(player_shot_8_flight_082 + 2, player_shot_8_flight_068_01);
    STORE_POINTER(player_shot_8_flight_083 + 2, player_shot_8_flight_068_01);
    STORE_POINTER(player_shot_8_flight_084 + 2, player_shot_8_flight_068_01);
    STORE_POINTER(player_shot_8_flight_table + 176, player_shot_8_flight_088);
    STORE_POINTER(player_shot_8_flight_table + 178, player_shot_8_flight_089);
    STORE_POINTER(player_shot_8_flight_table + 180, player_shot_8_flight_090);
    STORE_POINTER(player_shot_8_flight_table + 182, player_shot_8_flight_091);
    STORE_POINTER(player_shot_8_flight_table + 184, player_shot_8_flight_092);
    STORE_POINTER(player_shot_8_flight_table + 186, player_shot_8_flight_093);
    STORE_POINTER(player_shot_8_flight_table + 188, player_shot_8_flight_094);
    STORE_POINTER(player_shot_8_flight_table + 190, player_shot_8_flight_095);
    STORE_POINTER(player_shot_8_flight_table + 192, player_shot_8_flight_096);
    STORE_POINTER(player_shot_8_flight_table + 194, player_shot_8_flight_097);
    STORE_POINTER(player_shot_8_flight_table + 196, player_shot_8_flight_098);
    STORE_POINTER(player_shot_8_flight_table + 198, player_shot_8_flight_099);
    STORE_POINTER(player_shot_8_flight_table + 200, player_shot_8_flight_100);
    STORE_POINTER(player_shot_8_flight_table + 202, player_shot_8_flight_101);
    STORE_POINTER(player_shot_8_flight_table + 204, player_shot_8_flight_102);
    STORE_POINTER(player_shot_8_flight_table + 206, player_shot_8_flight_103);
    STORE_POINTER(player_shot_8_flight_table + 208, player_shot_8_flight_104);
    STORE_POINTER(player_shot_8_flight_088 + 2, player_shot_8_flight_088_01);
    STORE_POINTER(player_shot_8_flight_089 + 2, player_shot_8_flight_088_01);
    STORE_POINTER(player_shot_8_flight_090 + 2, player_shot_8_flight_088_01);
    STORE_POINTER(player_shot_8_flight_091 + 2, player_shot_8_flight_088_01);
    STORE_POINTER(player_shot_8_flight_092 + 2, player_shot_8_flight_088_01);
    STORE_POINTER(player_shot_8_flight_093 + 2, player_shot_8_flight_088_01);
    STORE_POINTER(player_shot_8_flight_094 + 2, player_shot_8_flight_088_01);
    STORE_POINTER(player_shot_8_flight_095 + 2, player_shot_8_flight_088_01);
    STORE_POINTER(player_shot_8_flight_096 + 2, player_shot_8_flight_088_01);
    STORE_POINTER(player_shot_8_flight_097 + 2, player_shot_8_flight_088_01);
    STORE_POINTER(player_shot_8_flight_098 + 2, player_shot_8_flight_088_01);
    STORE_POINTER(player_shot_8_flight_099 + 2, player_shot_8_flight_088_01);
    STORE_POINTER(player_shot_8_flight_100 + 2, player_shot_8_flight_088_01);
    STORE_POINTER(player_shot_8_flight_101 + 2, player_shot_8_flight_088_01);
    STORE_POINTER(player_shot_8_flight_102 + 2, player_shot_8_flight_088_01);
    STORE_POINTER(player_shot_8_flight_103 + 2, player_shot_8_flight_088_01);
    STORE_POINTER(player_shot_8_flight_104 + 2, player_shot_8_flight_088_01);
    STORE_POINTER(option_shot_list_3_03_00_00, option_shot_list_3_03_00_00_at_0);
    STORE_POINTER(option_shot_list_3_03_00_00 + 2, option_shot_list_3_03_00_00_at_2);
    STORE_POINTER(option_shot_list_3_03_00_00 + 4, option_shot_list_3_03_00_00_at_4);
    STORE_POINTER(option_shot_list_3_03_00_00 + 6, option_shot_list_3_03_00_00_at_6);
    STORE_POINTER(option_shot_list_3_03_00_00 + 8, option_shot_list_3_03_00_00_at_8);
    STORE_POINTER(option_shot_list_3_03_00_00 + 10, option_shot_list_3_03_00_00_at_10);
    STORE_POINTER(option_shot_list_3_03_00_00 + 12, option_shot_list_3_03_00_00_at_12);
    STORE_POINTER(option_shot_list_3_03_00_00 + 14, option_shot_list_3_03_00_00_at_14);
    STORE_POINTER(option_shot_list_3_03_00_00 + 16, option_shot_list_3_03_00_00_at_16);
    STORE_POINTER(option_shot_list_3_03_00_00 + 18, option_shot_list_3_03_00_00_at_18);
    STORE_POINTER(option_shot_list_3_03_00_00 + 20, option_shot_list_3_03_00_00_at_20);
    STORE_POINTER(option_shot_list_3_03_00_00 + 22, option_shot_list_3_03_00_00_at_22);
    STORE_POINTER(option_shot_list_3_03_00_00 + 24, option_shot_list_3_03_00_00_at_24);
    STORE_POINTER(option_shot_list_3_03_00_00 + 26, option_shot_list_3_03_00_00_at_26);
    STORE_POINTER(option_shot_list_3_03_00_00 + 28, option_shot_list_3_03_00_00_at_28);
    STORE_POINTER(option_shot_list_3_03_00_00 + 30, option_shot_list_3_03_00_00_at_30);
    STORE_POINTER(option_shot_list_3_03_00_00 + 32, option_shot_list_3_03_00_00_at_32);
    STORE_POINTER(option_shot_list_3_03_00_00_at_0 + 2, replay_targets_shot_lists_292);
    STORE_POINTER(option_shot_list_3_03_00_00_at_2 + 2, replay_targets_shot_lists_292);
    STORE_POINTER(option_shot_list_3_03_00_00_at_4 + 2, replay_targets_shot_lists_292);
    STORE_POINTER(option_shot_list_3_03_00_00_at_6 + 2, replay_targets_shot_lists_292);
    STORE_POINTER(option_shot_list_3_03_00_00_at_8 + 2, replay_targets_shot_lists_292);
    STORE_POINTER(option_shot_list_3_03_00_00_at_10 + 2, replay_targets_shot_lists_292);
    STORE_POINTER(option_shot_list_3_03_00_00_at_12 + 2, replay_targets_shot_lists_292);
    STORE_POINTER(option_shot_list_3_03_00_00_at_14 + 2, replay_targets_shot_lists_292);
    STORE_POINTER(option_shot_list_3_03_00_00_at_16 + 2, replay_targets_shot_lists_292);
    STORE_POINTER(option_shot_list_3_03_00_00_at_18 + 2, replay_targets_shot_lists_292);
    STORE_POINTER(option_shot_list_3_03_00_00_at_20 + 2, replay_targets_shot_lists_292);
    STORE_POINTER(option_shot_list_3_03_00_00_at_22 + 2, replay_targets_shot_lists_292);
    STORE_POINTER(option_shot_list_3_03_00_00_at_24 + 2, replay_targets_shot_lists_292);
    STORE_POINTER(option_shot_list_3_03_00_00_at_26 + 2, replay_targets_shot_lists_292);
    STORE_POINTER(option_shot_list_3_03_00_00_at_28 + 2, replay_targets_shot_lists_292);
    STORE_POINTER(option_shot_list_3_03_00_00_at_30 + 2, replay_targets_shot_lists_292);
    STORE_POINTER(option_shot_list_3_03_00_00_at_32 + 2, replay_targets_shot_lists_292);
    STORE_POINTER(player_shot_8_impact_table, player_shot_8_impact_00);
    STORE_POINTER(player_shot_8_impact_table + 2, player_shot_8_impact_00);
    STORE_POINTER(player_shot_8_impact_table + 4, player_shot_8_impact_02);
    STORE_POINTER(player_shot_8_impact_table + 6, player_shot_8_impact_02);
    STORE_POINTER(player_shot_8_impact_table + 8, player_shot_8_impact_04);
    STORE_POINTER(player_shot_8_impact_table + 10, player_shot_8_impact_04);
    STORE_POINTER(player_shot_8_impact_table + 12, player_shot_8_impact_06);
    STORE_POINTER(player_shot_8_impact_table + 14, player_shot_8_impact_06);
    STORE_POINTER(player_shot_8_impact_table + 16, player_shot_8_impact_08);
    STORE_POINTER(player_shot_8_impact_table + 18, player_shot_8_impact_08);
    STORE_POINTER(player_shot_8_impact_table + 20, player_shot_8_impact_10);
    STORE_POINTER(player_shot_8_impact_table + 22, player_shot_8_impact_11);
    STORE_POINTER(player_shot_8_impact_table + 24, player_shot_8_impact_12);
    STORE_POINTER(player_shot_8_impact_table + 26, player_shot_8_impact_13);
    STORE_POINTER(player_shot_8_impact_table + 28, player_shot_8_impact_14);
    STORE_POINTER(player_shot_8_impact_table + 30, player_shot_8_impact_15);
    STORE_POINTER(player_shot_8_impact_table + 32, player_shot_8_impact_15);
    STORE_POINTER(player_shot_8_impact_table + 34, player_shot_8_impact_17);
    STORE_POINTER(player_shot_8_impact_table + 36, player_shot_8_impact_17);
    STORE_POINTER(player_shot_8_impact_table + 38, player_shot_8_impact_19);
    STORE_POINTER(player_shot_8_impact_table + 40, player_shot_8_impact_19);
    STORE_POINTER(player_shot_8_impact_table + 42, player_shot_8_impact_21);
    STORE_POINTER(player_shot_8_impact_table + 44, player_shot_8_impact_21);
    STORE_POINTER(player_shot_8_impact_table + 46, player_shot_8_impact_23);
    STORE_POINTER(player_shot_8_impact_table + 48, player_shot_8_impact_23);
    STORE_POINTER(player_shot_8_impact_00 + 3, player_shot_8_impact_frames_00);
    STORE_POINTER(player_shot_8_impact_02 + 3, player_shot_8_impact_frames_02);
    STORE_POINTER(player_shot_8_impact_04 + 3, player_shot_8_impact_frames_02);
    STORE_POINTER(player_shot_8_impact_06 + 3, player_shot_8_impact_frames_06);
    STORE_POINTER(player_shot_8_impact_08 + 3, player_shot_8_impact_frames_06);
    STORE_POINTER(player_shot_8_impact_10 + 3, player_shot_8_impact_frames_10);
    STORE_POINTER(player_shot_8_impact_11 + 3, player_shot_8_impact_frames_11);
    STORE_POINTER(player_shot_8_impact_12 + 3, player_shot_8_impact_frames_11);
    STORE_POINTER(player_shot_8_impact_13 + 3, player_shot_8_impact_frames_13);
    STORE_POINTER(player_shot_8_impact_14 + 3, player_shot_8_impact_frames_13);
    STORE_POINTER(player_shot_8_impact_15 + 3, player_shot_8_impact_frames_15);
    STORE_POINTER(player_shot_8_impact_17 + 3, player_shot_8_impact_frames_17);
    STORE_POINTER(player_shot_8_impact_19 + 3, player_shot_8_impact_frames_17);
    STORE_POINTER(player_shot_8_impact_21 + 3, player_shot_8_impact_frames_21);
    STORE_POINTER(player_shot_8_impact_23 + 3, player_shot_8_impact_frames_21);
}

extern u16 ship0_shot_list_1_00_00[];
extern u16 ship0_shot_list_2_00_00[];
extern u16 ship0_shot_list_1_00_01[];
extern u16 ship0_shot_list_2_00_01[];
extern u16 ship0_shot_list_1_00_02[];
extern u16 ship0_shot_list_2_00_02[];
extern u16 ship0_shot_list_1_00_03[];
extern u16 ship0_shot_list_2_00_03[];
extern u16 ship0_shot_list_1_00_04[];
extern u16 ship0_shot_list_2_00_04[];
extern u16 ship0_shot_list_1_02_00[];
extern u16 ship0_shot_list_1_02_01[];
extern u16 ship0_shot_list_1_02_02[];
extern u16 ship0_shot_list_1_02_03[];
extern u16 ship0_shot_list_1_02_04[];
extern u16 ship0_shot_list_1_04_00[];
extern u16 ship0_shot_list_2_04_00[];
extern u16 ship0_shot_list_1_04_01[];
extern u16 ship0_shot_list_2_04_01[];
extern u16 ship0_shot_list_1_04_02[];
extern u16 ship0_shot_list_2_04_02[];
extern u16 ship0_shot_list_1_04_03[];
extern u16 ship0_shot_list_2_04_03[];
extern u16 ship0_shot_list_1_04_04[];
extern u16 ship0_shot_list_2_04_04[];
extern u16 ship0_shot_list_3_00_00[];
extern u16 ship0_shot_list_3_00_01[];
extern u16 ship0_shot_list_3_00_02[];
extern u16 ship0_shot_list_3_00_03[];
extern u16 ship0_shot_list_3_00_04[];
extern u16 ship0_shot_list_3_02_00[];
extern u16 ship0_shot_list_3_02_01[];
extern u16 ship0_shot_list_3_02_02[];
extern u16 ship0_shot_list_3_02_03[];
extern u16 ship0_shot_list_3_02_04[];
extern u16 ship0_shot_list_3_04_00[];
extern u16 ship0_shot_list_3_04_01[];
extern u16 ship0_shot_list_3_04_02[];
extern u16 ship0_shot_list_3_04_03[];
extern u16 ship0_shot_list_3_04_04[];
extern u16 ship0_shot_list_1_01_00[];
extern u16 ship0_shot_list_2_01_00[];
extern u16 ship0_shot_list_1_01_01[];
extern u16 ship0_shot_list_2_01_01[];
extern u16 ship0_shot_list_1_01_02[];
extern u16 ship0_shot_list_2_01_02[];
extern u16 ship0_shot_list_1_01_03[];
extern u16 ship0_shot_list_2_01_03[];
extern u16 ship0_shot_list_1_01_04[];
extern u16 ship0_shot_list_2_01_04[];
extern u16 ship0_shot_list_1_03_00[];
extern u16 ship0_shot_list_1_03_01[];
extern u16 ship0_shot_list_1_03_02[];
extern u16 ship0_shot_list_1_03_03[];
extern u16 ship0_shot_list_1_03_04[];
extern u16 ship0_shot_list_1_05_00[];
extern u16 ship0_shot_list_2_05_00[];
extern u16 ship0_shot_list_1_05_01[];
extern u16 ship0_shot_list_2_05_01[];
extern u16 ship0_shot_list_1_05_02[];
extern u16 ship0_shot_list_2_05_02[];
extern u16 ship0_shot_list_1_05_03[];
extern u16 ship0_shot_list_2_05_03[];
extern u16 ship0_shot_list_1_05_04[];
extern u16 ship0_shot_list_2_05_04[];
extern u16 ship0_shot_list_3_01_00[];
extern u16 ship0_shot_list_3_01_01[];
extern u16 ship0_shot_list_3_01_02[];
extern u16 ship0_shot_list_3_01_03[];
extern u16 ship0_shot_list_3_01_04[];
extern u16 ship0_shot_list_3_03_00[];
extern u16 ship0_shot_list_3_03_01[];
extern u16 ship0_shot_list_3_03_02[];
extern u16 ship0_shot_list_3_03_03[];
extern u16 ship0_shot_list_3_03_04[];
extern u16 ship0_shot_list_3_05_00[];
extern u16 ship0_shot_list_3_05_01[];
extern u16 ship0_shot_list_3_05_02[];
extern u16 ship0_shot_list_3_05_03[];
extern u16 ship0_shot_list_3_05_04[];
extern u16 player_shot_levels_0[];
extern u16 player_shot_levels_1[];
extern u16 player_shot_levels_2[];
extern u16 player_shot_levels_3[];
extern u16 player_shot_levels_4[];
extern u16 player_shot_levels_5[];
extern u16 player_laser_levels_0[];
extern u16 player_laser_levels_1[];
extern u16 player_laser_levels_2[];
extern u16 player_laser_levels_3[];
extern u16 player_laser_levels_4[];
extern u16 player_laser_levels_5[];
extern u16 player_ship_sprites_00[];
extern u16 player_ship_sprites_01[];
extern u16 player_ship_hitboxes_00[];
extern u16 player_ship_hitboxes_01[];
extern u16 player_ship_shadows_00[];
extern u16 player_ship_shadows_01[];
extern u16 ship0_shot_list_1_00[];
extern u16 ship0_shot_list_2_00[];
extern u16 ship0_shot_list_3_00[];
extern u16 ship0_shot_list_1_01[];
extern u16 ship0_shot_list_2_01[];
extern u16 ship0_shot_list_3_01[];
extern u16 ship0_shot_list_1_02[];
extern u16 ship0_shot_list_3_02[];
extern u16 ship0_shot_list_1_03[];
extern u16 ship0_shot_list_3_03[];
extern u16 ship0_shot_list_1_04[];
extern u16 ship0_shot_list_2_04[];
extern u16 ship0_shot_list_3_04[];
extern u16 ship0_shot_list_1_05[];
extern u16 ship0_shot_list_2_05[];
extern u16 ship0_shot_list_3_05[];
extern u16 player_shield_sprites_00[];
extern u16 player_shield_sprites_01[];
extern u16 player_exhaust_sprites_00[];
extern u16 player_exhaust_sprites_01[];
extern u16 player_exhaust_slow_sprites_00[];
extern u16 player_exhaust_slow_sprites_01[];
extern u16 D_00255D48[];
extern u16 D_00255DB8[];
extern u16 D_00255DC8[];
extern u16 D_00255DD8[];
extern u16 D_00255DE8[];
extern u16 D_00255DF8[];
extern u16 D_00255E08[];
extern u16 D_00255E78[];
extern u16 D_00255E88[];
extern u16 D_00255E98[];
extern u16 D_00255EA8[];
extern u16 D_00255EB8[];
extern u16 D_00255EC8[];
extern u16 D_00255F80[];
extern u16 D_00255FA0[];
extern u16 D_00255FC0[];
extern u16 D_00255FE0[];
extern u16 D_00256000[];
extern u16 D_00256010[];
extern u16 D_00256020[];
extern u16 D_00256030[];
extern u16 D_00256040[];
extern u16 D_00256050[];
extern u16 D_00256060[];
extern u16 D_00256070[];
extern u16 D_00256080[];
extern u16 D_00256090[];
extern u16 D_002560A0[];
extern u16 player_shield_sprites_01_04[];
extern u16 player_shield_sprites_01_05[];
extern u16 player_shield_sprites_01_06[];
extern u16 player_shield_sprites_01_07[];
extern u16 player_shield_sprites_01_08[];
extern u16 player_shield_sprites_01_09[];
extern u16 player_shield_sprites_01_10[];
extern u16 player_shield_sprites_01_11[];
extern u16 D_0028C680[];
extern u16 player_exhaust_sprites_00_01[];
extern u16 player_exhaust_sprites_00_02[];
extern u16 player_exhaust_sprites_00_03[];
extern u16 player_exhaust_sprites_00_04[];
extern u16 player_exhaust_sprites_00_05[];
extern u16 player_exhaust_sprites_00_06[];
extern u16 player_exhaust_sprites_00_07[];
extern u16 player_exhaust_sprites_00_08[];
extern u16 player_exhaust_sprites_00_12[];
extern u16 player_exhaust_sprites_00_13[];
extern u16 player_exhaust_sprites_00_14[];
extern u16 player_exhaust_sprites_00_15[];
extern u16 player_exhaust_sprites_00_16[];
extern u16 player_exhaust_sprites_00_17[];
extern u16 player_exhaust_sprites_00_18[];
extern u16 player_exhaust_sprites_00_19[];
extern u16 player_exhaust_sprites_01_at_0[];
extern u16 player_exhaust_sprites_01_01[];
extern u16 player_exhaust_sprites_01_02[];
extern u16 player_exhaust_sprites_01_03[];
extern u16 player_exhaust_sprites_01_04[];
extern u16 player_exhaust_sprites_01_05[];
extern u16 player_exhaust_sprites_01_06[];
extern u16 player_exhaust_sprites_01_07[];
extern u16 player_exhaust_sprites_01_08[];
extern u16 player_exhaust_sprites_01_12[];
extern u16 player_exhaust_sprites_01_13[];
extern u16 player_exhaust_sprites_01_14[];
extern u16 player_exhaust_sprites_01_15[];
extern u16 player_exhaust_sprites_01_16[];
extern u16 player_exhaust_sprites_01_17[];
extern u16 player_exhaust_sprites_01_18[];
extern u16 player_exhaust_sprites_01_19[];
extern u16 player_exhaust_slow_sprites_00_00[];
extern u16 player_exhaust_slow_sprites_00_01[];
extern u16 player_exhaust_slow_sprites_00_02[];
extern u16 player_exhaust_slow_sprites_00_03[];
extern u16 player_exhaust_slow_sprites_00_04[];
extern u16 player_exhaust_slow_sprites_00_05[];
extern u16 player_exhaust_slow_sprites_00_06[];
extern u16 player_exhaust_slow_sprites_00_07[];
extern u16 player_exhaust_slow_sprites_00_08[];
extern u16 player_exhaust_slow_sprites_00_12[];
extern u16 player_exhaust_slow_sprites_00_13[];
extern u16 player_exhaust_slow_sprites_00_14[];
extern u16 player_exhaust_slow_sprites_00_15[];
extern u16 player_exhaust_slow_sprites_00_16[];
extern u16 player_exhaust_slow_sprites_00_17[];
extern u16 player_exhaust_slow_sprites_00_18[];
extern u16 player_exhaust_slow_sprites_00_19[];
extern u16 player_exhaust_slow_sprites_01_00[];
extern u16 player_exhaust_slow_sprites_01_01[];
extern u16 player_exhaust_slow_sprites_01_02[];
extern u16 player_exhaust_slow_sprites_01_03[];
extern u16 player_exhaust_slow_sprites_01_04[];
extern u16 player_exhaust_slow_sprites_01_05[];
extern u16 player_exhaust_slow_sprites_01_06[];
extern u16 player_exhaust_slow_sprites_01_07[];
extern u16 player_exhaust_slow_sprites_01_08[];
extern u16 D_0028C870[];
extern u16 D_0028C878[];
extern u16 D_0028C888[];
extern u16 D_0028C890[];
extern u16 D_0028C898[];
extern u16 D_0028C8A0[];
extern u16 D_0028C8A8[];
extern u16 D_0028C8B0[];
extern u16 D_0028C8B8[];
extern u16 D_0028C8C0[];
extern u16 D_0028C8C8[];
extern u16 D_0028C8D0[];
extern u16 D_0028C8D8[];
extern u16 D_0028C8E0[];
extern u16 D_0028C8E8[];
extern u16 D_0028C8F0[];
extern u16 D_0028C8F8[];
extern u16 D_0028C900[];
extern u16 D_0028C908[];
extern u16 D_0028C910[];
extern u16 D_0028C918[];
extern u16 D_0028C920[];
extern u16 D_0028C928[];
extern u16 D_0028C930[];
extern u16 D_0028C938[];
extern u16 D_0028C940[];

extern u16 player_ship_hitbox_tables[];
extern u16 player_ship_shadow_tables[];
extern u16 player_shield_sprite_tables[];
extern u16 player_exhaust_sprite_tables[];
extern u16 player_exhaust_slow_sprite_tables[];
extern u16 D_0028C868[];
extern u16 D_0028C880[];

void player_tables_init(void) {
    STORE_POINTER(((u16 *)player_weapon_tables), player_shot_levels_0);
    STORE_POINTER(player_weapon_tables + 2, player_laser_levels_0);
    STORE_POINTER(player_weapon_tables + 4, player_shot_levels_1);
    STORE_POINTER(player_weapon_tables + 6, player_laser_levels_1);
    STORE_POINTER(player_weapon_tables + 8, player_shot_levels_2);
    STORE_POINTER(player_weapon_tables + 10, player_laser_levels_2);
    STORE_POINTER(player_weapon_tables + 12, player_shot_levels_3);
    STORE_POINTER(player_weapon_tables + 14, player_laser_levels_3);
    STORE_POINTER(player_weapon_tables + 16, player_shot_levels_4);
    STORE_POINTER(player_weapon_tables + 18, player_laser_levels_4);
    STORE_POINTER(player_weapon_tables + 20, player_shot_levels_5);
    STORE_POINTER(player_weapon_tables + 22, player_laser_levels_5);
    STORE_POINTER(player_laser_levels_5 + 8, (u32)player_shot_levels_2 + 8);
    STORE_POINTER(player_laser_levels_5 + 10, (u32)player_laser_levels_2 + 8);
    STORE_POINTER(player_laser_levels_5 + 12, (u32)player_shot_levels_3 + 8);
    STORE_POINTER(player_laser_levels_5 + 14, (u32)player_laser_levels_3 + 8);
    STORE_POINTER(((u16 *)player_ship_sprite_tables), player_ship_sprites_00);
    STORE_POINTER(player_ship_sprite_tables + 2, player_ship_sprites_01);
    STORE_POINTER(player_ship_hitbox_tables, player_ship_hitboxes_00);
    STORE_POINTER(player_ship_hitbox_tables + 2, player_ship_hitboxes_01);
    STORE_POINTER(player_ship_shadow_tables, player_ship_shadows_00);
    STORE_POINTER(player_ship_shadow_tables + 2, player_ship_shadows_01);
    STORE_POINTER(((u16 *)ship0_shot_lists_1), ship0_shot_list_1_00);
    STORE_POINTER(ship0_shot_lists_1 + 2, ship0_shot_list_1_01);
    STORE_POINTER(ship0_shot_lists_1 + 4, ship0_shot_list_1_02);
    STORE_POINTER(ship0_shot_lists_1 + 6, ship0_shot_list_1_03);
    STORE_POINTER(ship0_shot_lists_1 + 8, ship0_shot_list_1_04);
    STORE_POINTER(ship0_shot_lists_1 + 10, ship0_shot_list_1_05);
    STORE_POINTER(((u16 *)ship0_shot_lists_2), ship0_shot_list_2_00);
    STORE_POINTER(ship0_shot_lists_2 + 2, ship0_shot_list_2_01);
    STORE_POINTER(ship0_shot_lists_2 + 8, ship0_shot_list_2_04);
    STORE_POINTER(ship0_shot_lists_2 + 10, ship0_shot_list_2_05);
    STORE_POINTER(((u16 *)ship0_shot_lists_3), ship0_shot_list_3_00);
    STORE_POINTER(ship0_shot_lists_3 + 2, ship0_shot_list_3_01);
    STORE_POINTER(ship0_shot_lists_3 + 4, ship0_shot_list_3_02);
    STORE_POINTER(ship0_shot_lists_3 + 6, ship0_shot_list_3_03);
    STORE_POINTER(ship0_shot_lists_3 + 8, ship0_shot_list_3_04);
    STORE_POINTER(ship0_shot_lists_3 + 10, ship0_shot_list_3_05);
    STORE_POINTER(ship0_shot_list_1_00, ship0_shot_list_1_00_00);
    STORE_POINTER(ship0_shot_list_1_00 + 2, ship0_shot_list_1_00_01);
    STORE_POINTER(ship0_shot_list_1_00 + 4, ship0_shot_list_1_00_02);
    STORE_POINTER(ship0_shot_list_1_00 + 6, ship0_shot_list_1_00_03);
    STORE_POINTER(ship0_shot_list_1_00 + 8, ship0_shot_list_1_00_04);
    STORE_POINTER(ship0_shot_list_2_00, ship0_shot_list_2_00_00);
    STORE_POINTER(ship0_shot_list_2_00 + 2, ship0_shot_list_2_00_01);
    STORE_POINTER(ship0_shot_list_2_00 + 4, ship0_shot_list_2_00_02);
    STORE_POINTER(ship0_shot_list_2_00 + 6, ship0_shot_list_2_00_03);
    STORE_POINTER(ship0_shot_list_2_00 + 8, ship0_shot_list_2_00_04);
    STORE_POINTER(ship0_shot_list_3_00, ship0_shot_list_3_00_00);
    STORE_POINTER(ship0_shot_list_3_00 + 2, ship0_shot_list_3_00_01);
    STORE_POINTER(ship0_shot_list_3_00 + 4, ship0_shot_list_3_00_02);
    STORE_POINTER(ship0_shot_list_3_00 + 6, ship0_shot_list_3_00_03);
    STORE_POINTER(ship0_shot_list_3_00 + 8, ship0_shot_list_3_00_04);
    STORE_POINTER(ship0_shot_list_1_01, ship0_shot_list_1_01_00);
    STORE_POINTER(ship0_shot_list_1_01 + 2, ship0_shot_list_1_01_01);
    STORE_POINTER(ship0_shot_list_1_01 + 4, ship0_shot_list_1_01_02);
    STORE_POINTER(ship0_shot_list_1_01 + 6, ship0_shot_list_1_01_03);
    STORE_POINTER(ship0_shot_list_1_01 + 8, ship0_shot_list_1_01_04);
    STORE_POINTER(ship0_shot_list_2_01, ship0_shot_list_2_01_00);
    STORE_POINTER(ship0_shot_list_2_01 + 2, ship0_shot_list_2_01_01);
    STORE_POINTER(ship0_shot_list_2_01 + 4, ship0_shot_list_2_01_02);
    STORE_POINTER(ship0_shot_list_2_01 + 6, ship0_shot_list_2_01_03);
    STORE_POINTER(ship0_shot_list_2_01 + 8, ship0_shot_list_2_01_04);
    STORE_POINTER(ship0_shot_list_3_01, ship0_shot_list_3_01_00);
    STORE_POINTER(ship0_shot_list_3_01 + 2, ship0_shot_list_3_01_01);
    STORE_POINTER(ship0_shot_list_3_01 + 4, ship0_shot_list_3_01_02);
    STORE_POINTER(ship0_shot_list_3_01 + 6, ship0_shot_list_3_01_03);
    STORE_POINTER(ship0_shot_list_3_01 + 8, ship0_shot_list_3_01_04);
    STORE_POINTER(ship0_shot_list_1_02, ship0_shot_list_1_02_00);
    STORE_POINTER(ship0_shot_list_1_02 + 2, ship0_shot_list_1_02_01);
    STORE_POINTER(ship0_shot_list_1_02 + 4, ship0_shot_list_1_02_02);
    STORE_POINTER(ship0_shot_list_1_02 + 6, ship0_shot_list_1_02_03);
    STORE_POINTER(ship0_shot_list_1_02 + 8, ship0_shot_list_1_02_04);
    STORE_POINTER(ship0_shot_list_3_02, ship0_shot_list_3_02_00);
    STORE_POINTER(ship0_shot_list_3_02 + 2, ship0_shot_list_3_02_01);
    STORE_POINTER(ship0_shot_list_3_02 + 4, ship0_shot_list_3_02_02);
    STORE_POINTER(ship0_shot_list_3_02 + 6, ship0_shot_list_3_02_03);
    STORE_POINTER(ship0_shot_list_3_02 + 8, ship0_shot_list_3_02_04);
    STORE_POINTER(ship0_shot_list_1_03, ship0_shot_list_1_03_00);
    STORE_POINTER(ship0_shot_list_1_03 + 2, ship0_shot_list_1_03_01);
    STORE_POINTER(ship0_shot_list_1_03 + 4, ship0_shot_list_1_03_02);
    STORE_POINTER(ship0_shot_list_1_03 + 6, ship0_shot_list_1_03_03);
    STORE_POINTER(ship0_shot_list_1_03 + 8, ship0_shot_list_1_03_04);
    STORE_POINTER(ship0_shot_list_3_03, ship0_shot_list_3_03_00);
    STORE_POINTER(ship0_shot_list_3_03 + 2, ship0_shot_list_3_03_01);
    STORE_POINTER(ship0_shot_list_3_03 + 4, ship0_shot_list_3_03_02);
    STORE_POINTER(ship0_shot_list_3_03 + 6, ship0_shot_list_3_03_03);
    STORE_POINTER(ship0_shot_list_3_03 + 8, ship0_shot_list_3_03_04);
    STORE_POINTER(ship0_shot_list_1_04, ship0_shot_list_1_04_00);
    STORE_POINTER(ship0_shot_list_1_04 + 2, ship0_shot_list_1_04_01);
    STORE_POINTER(ship0_shot_list_1_04 + 4, ship0_shot_list_1_04_02);
    STORE_POINTER(ship0_shot_list_1_04 + 6, ship0_shot_list_1_04_03);
    STORE_POINTER(ship0_shot_list_1_04 + 8, ship0_shot_list_1_04_04);
    STORE_POINTER(ship0_shot_list_2_04, ship0_shot_list_2_04_00);
    STORE_POINTER(ship0_shot_list_2_04 + 2, ship0_shot_list_2_04_01);
    STORE_POINTER(ship0_shot_list_2_04 + 4, ship0_shot_list_2_04_02);
    STORE_POINTER(ship0_shot_list_2_04 + 6, ship0_shot_list_2_04_03);
    STORE_POINTER(ship0_shot_list_2_04 + 8, ship0_shot_list_2_04_04);
    STORE_POINTER(ship0_shot_list_3_04, ship0_shot_list_3_04_00);
    STORE_POINTER(ship0_shot_list_3_04 + 2, ship0_shot_list_3_04_01);
    STORE_POINTER(ship0_shot_list_3_04 + 4, ship0_shot_list_3_04_02);
    STORE_POINTER(ship0_shot_list_3_04 + 6, ship0_shot_list_3_04_03);
    STORE_POINTER(ship0_shot_list_3_04 + 8, ship0_shot_list_3_04_04);
    STORE_POINTER(ship0_shot_list_1_05, ship0_shot_list_1_05_00);
    STORE_POINTER(ship0_shot_list_1_05 + 2, ship0_shot_list_1_05_01);
    STORE_POINTER(ship0_shot_list_1_05 + 4, ship0_shot_list_1_05_02);
    STORE_POINTER(ship0_shot_list_1_05 + 6, ship0_shot_list_1_05_03);
    STORE_POINTER(ship0_shot_list_1_05 + 8, ship0_shot_list_1_05_04);
    STORE_POINTER(ship0_shot_list_2_05, ship0_shot_list_2_05_00);
    STORE_POINTER(ship0_shot_list_2_05 + 2, ship0_shot_list_2_05_01);
    STORE_POINTER(ship0_shot_list_2_05 + 4, ship0_shot_list_2_05_02);
    STORE_POINTER(ship0_shot_list_2_05 + 6, ship0_shot_list_2_05_03);
    STORE_POINTER(ship0_shot_list_2_05 + 8, ship0_shot_list_2_05_04);
    STORE_POINTER(ship0_shot_list_3_05, ship0_shot_list_3_05_00);
    STORE_POINTER(ship0_shot_list_3_05 + 2, ship0_shot_list_3_05_01);
    STORE_POINTER(ship0_shot_list_3_05 + 4, ship0_shot_list_3_05_02);
    STORE_POINTER(ship0_shot_list_3_05 + 6, ship0_shot_list_3_05_03);
    STORE_POINTER(ship0_shot_list_3_05 + 8, ship0_shot_list_3_05_04);
    STORE_POINTER(player_shield_sprite_tables, player_shield_sprites_00);
    STORE_POINTER(player_shield_sprite_tables + 2, player_shield_sprites_01);
    STORE_POINTER(player_exhaust_sprite_tables, player_exhaust_sprites_00);
    STORE_POINTER(player_exhaust_sprite_tables + 2, player_exhaust_sprites_01);
    STORE_POINTER(player_shield_sprites_01 + 8, player_shield_sprites_01_04);
    STORE_POINTER(player_shield_sprites_01 + 10, player_shield_sprites_01_05);
    STORE_POINTER(player_shield_sprites_01 + 12, player_shield_sprites_01_06);
    STORE_POINTER(player_shield_sprites_01 + 14, player_shield_sprites_01_07);
    STORE_POINTER(player_shield_sprites_01 + 16, player_shield_sprites_01_08);
    STORE_POINTER(player_shield_sprites_01 + 18, player_shield_sprites_01_09);
    STORE_POINTER(player_shield_sprites_01 + 20, player_shield_sprites_01_10);
    STORE_POINTER(player_shield_sprites_01 + 22, player_shield_sprites_01_11);
    STORE_POINTER(player_exhaust_sprites_00, D_0028C680);
    STORE_POINTER(player_exhaust_sprites_00 + 2, player_exhaust_sprites_00_01);
    STORE_POINTER(player_exhaust_sprites_00 + 4, player_exhaust_sprites_00_02);
    STORE_POINTER(player_exhaust_sprites_00 + 6, player_exhaust_sprites_00_03);
    STORE_POINTER(player_exhaust_sprites_00 + 8, player_exhaust_sprites_00_04);
    STORE_POINTER(player_exhaust_sprites_00 + 10, player_exhaust_sprites_00_05);
    STORE_POINTER(player_exhaust_sprites_00 + 12, player_exhaust_sprites_00_06);
    STORE_POINTER(player_exhaust_sprites_00 + 14, player_exhaust_sprites_00_07);
    STORE_POINTER(player_exhaust_sprites_00 + 16, player_exhaust_sprites_00_08);
    STORE_POINTER(player_exhaust_sprites_00 + 24, player_exhaust_sprites_00_12);
    STORE_POINTER(player_exhaust_sprites_00 + 26, player_exhaust_sprites_00_13);
    STORE_POINTER(player_exhaust_sprites_00 + 28, player_exhaust_sprites_00_14);
    STORE_POINTER(player_exhaust_sprites_00 + 30, player_exhaust_sprites_00_15);
    STORE_POINTER(player_exhaust_sprites_00 + 32, player_exhaust_sprites_00_16);
    STORE_POINTER(player_exhaust_sprites_00 + 34, player_exhaust_sprites_00_17);
    STORE_POINTER(player_exhaust_sprites_00 + 36, player_exhaust_sprites_00_18);
    STORE_POINTER(player_exhaust_sprites_00 + 38, player_exhaust_sprites_00_19);
    STORE_POINTER(player_exhaust_sprites_01, player_exhaust_sprites_01_at_0);
    STORE_POINTER(player_exhaust_sprites_01 + 2, player_exhaust_sprites_01_01);
    STORE_POINTER(player_exhaust_sprites_01 + 4, player_exhaust_sprites_01_02);
    STORE_POINTER(player_exhaust_sprites_01 + 6, player_exhaust_sprites_01_03);
    STORE_POINTER(player_exhaust_sprites_01 + 8, player_exhaust_sprites_01_04);
    STORE_POINTER(player_exhaust_sprites_01 + 10, player_exhaust_sprites_01_05);
    STORE_POINTER(player_exhaust_sprites_01 + 12, player_exhaust_sprites_01_06);
    STORE_POINTER(player_exhaust_sprites_01 + 14, player_exhaust_sprites_01_07);
    STORE_POINTER(player_exhaust_sprites_01 + 16, player_exhaust_sprites_01_08);
    STORE_POINTER(player_exhaust_slow_sprite_tables, player_exhaust_slow_sprites_00);
    STORE_POINTER(player_exhaust_slow_sprite_tables + 2, player_exhaust_slow_sprites_01);
    STORE_POINTER(player_exhaust_sprites_01 + 24, player_exhaust_sprites_01_12);
    STORE_POINTER(player_exhaust_sprites_01 + 26, player_exhaust_sprites_01_13);
    STORE_POINTER(player_exhaust_sprites_01 + 28, player_exhaust_sprites_01_14);
    STORE_POINTER(player_exhaust_sprites_01 + 30, player_exhaust_sprites_01_15);
    STORE_POINTER(player_exhaust_sprites_01 + 32, player_exhaust_sprites_01_16);
    STORE_POINTER(player_exhaust_sprites_01 + 34, player_exhaust_sprites_01_17);
    STORE_POINTER(player_exhaust_sprites_01 + 36, player_exhaust_sprites_01_18);
    STORE_POINTER(player_exhaust_sprites_01 + 38, player_exhaust_sprites_01_19);
    STORE_POINTER(player_exhaust_slow_sprites_00, player_exhaust_slow_sprites_00_00);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 2, player_exhaust_slow_sprites_00_01);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 4, player_exhaust_slow_sprites_00_02);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 6, player_exhaust_slow_sprites_00_03);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 8, player_exhaust_slow_sprites_00_04);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 10, player_exhaust_slow_sprites_00_05);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 12, player_exhaust_slow_sprites_00_06);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 14, player_exhaust_slow_sprites_00_07);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 16, player_exhaust_slow_sprites_00_08);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 24, player_exhaust_slow_sprites_00_12);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 26, player_exhaust_slow_sprites_00_13);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 28, player_exhaust_slow_sprites_00_14);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 30, player_exhaust_slow_sprites_00_15);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 32, player_exhaust_slow_sprites_00_16);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 34, player_exhaust_slow_sprites_00_17);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 36, player_exhaust_slow_sprites_00_18);
    STORE_POINTER(player_exhaust_slow_sprites_00 + 38, player_exhaust_slow_sprites_00_19);
    STORE_POINTER(player_exhaust_slow_sprites_01, player_exhaust_slow_sprites_01_00);
    STORE_POINTER(player_exhaust_slow_sprites_01 + 2, player_exhaust_slow_sprites_01_01);
    STORE_POINTER(player_exhaust_slow_sprites_01 + 4, player_exhaust_slow_sprites_01_02);
    STORE_POINTER(player_exhaust_slow_sprites_01 + 6, player_exhaust_slow_sprites_01_03);
    STORE_POINTER(player_exhaust_slow_sprites_01 + 8, player_exhaust_slow_sprites_01_04);
    STORE_POINTER(player_exhaust_slow_sprites_01 + 10, player_exhaust_slow_sprites_01_05);
    STORE_POINTER(player_exhaust_slow_sprites_01 + 12, player_exhaust_slow_sprites_01_06);
    STORE_POINTER(player_exhaust_slow_sprites_01 + 14, player_exhaust_slow_sprites_01_07);
    STORE_POINTER(player_exhaust_slow_sprites_01 + 16, player_exhaust_slow_sprites_01_08);
    STORE_POINTER(D_0028C868, D_0028C870);
    STORE_POINTER(D_0028C868 + 2, D_0028C878);
    STORE_POINTER(D_0028C880, D_0028C888);
    STORE_POINTER(D_0028C880 + 2, D_00255D48);
    STORE_POINTER(D_00255D48 + 12, D_00255DB8);
    STORE_POINTER(D_00255D48 + 14, D_00255DB8);
    STORE_POINTER(D_00255D48 + 16, D_00255DB8);
    STORE_POINTER(D_00255D48 + 18, D_00255DC8);
    STORE_POINTER(D_00255D48 + 20, D_00255DC8);
    STORE_POINTER(D_00255D48 + 22, D_00255DC8);
    STORE_POINTER(D_00255D48 + 24, D_00255DD8);
    STORE_POINTER(D_00255D48 + 26, D_00255DD8);
    STORE_POINTER(D_00255D48 + 28, D_00255DD8);
    STORE_POINTER(D_00255D48 + 36, D_00255DE8);
    STORE_POINTER(D_00255D48 + 38, D_00255DE8);
    STORE_POINTER(D_00255D48 + 40, D_00255DE8);
    STORE_POINTER(D_00255D48 + 42, D_00255DF8);
    STORE_POINTER(D_00255D48 + 44, D_00255DF8);
    STORE_POINTER(D_00255D48 + 46, D_00255DF8);
    STORE_POINTER(D_00255D48 + 48, D_00255E08);
    STORE_POINTER(D_00255D48 + 50, D_00255E08);
    STORE_POINTER(D_00255D48 + 52, D_00255E08);
    STORE_POINTER(D_00255E08 + 12, D_00255E78);
    STORE_POINTER(D_00255E08 + 14, D_00255E78);
    STORE_POINTER(D_00255E08 + 16, D_00255E78);
    STORE_POINTER(D_00255E08 + 18, D_00255E88);
    STORE_POINTER(D_00255E08 + 20, D_00255E88);
    STORE_POINTER(D_00255E08 + 22, D_00255E88);
    STORE_POINTER(D_00255E08 + 24, D_00255E98);
    STORE_POINTER(D_00255E08 + 26, D_00255E98);
    STORE_POINTER(D_00255E08 + 28, D_00255E98);
    STORE_POINTER(D_00255E08 + 36, D_00255EA8);
    STORE_POINTER(D_00255E08 + 38, D_00255EA8);
    STORE_POINTER(D_00255E08 + 40, D_00255EA8);
    STORE_POINTER(D_00255E08 + 42, D_00255EB8);
    STORE_POINTER(D_00255E08 + 44, D_00255EB8);
    STORE_POINTER(D_00255E08 + 46, D_00255EB8);
    STORE_POINTER(D_00255E08 + 48, D_00255EC8);
    STORE_POINTER(D_00255E08 + 50, D_00255EC8);
    STORE_POINTER(D_00255E08 + 52, D_00255EC8);
    STORE_POINTER(((u16 *)D_00255EE0), D_00255F80);
    STORE_POINTER(D_00255EE0 + 2, D_0028C890);
    STORE_POINTER(D_00255EE0 + 4, D_0028C898);
    STORE_POINTER(D_00255EE0 + 6, D_0028C8A0);
    STORE_POINTER(D_00255EE0 + 8, D_0028C8A8);
    STORE_POINTER(D_00255EE0 + 10, D_0028C8B0);
    STORE_POINTER(D_00255EE0 + 12, D_00255FA0);
    STORE_POINTER(D_00255EE0 + 14, D_0028C8B8);
    STORE_POINTER(D_00255EE0 + 16, D_0028C8C0);
    STORE_POINTER(D_00255EE0 + 18, D_0028C8C8);
    STORE_POINTER(D_00255EE0 + 20, D_0028C8D0);
    STORE_POINTER(D_00255EE0 + 22, D_0028C8D8);
    STORE_POINTER(D_00255EE0 + 24, D_0028C8E0);
    STORE_POINTER(D_00255EE0 + 26, D_0028C8E8);
    STORE_POINTER(D_00255EE0 + 28, D_0028C8F0);
    STORE_POINTER(D_00255EE0 + 30, D_0028C8F8);
    STORE_POINTER(D_00255EE0 + 32, D_0028C900);
    STORE_POINTER(D_00255EE0 + 34, D_0028C908);
    STORE_POINTER(D_00255EE0 + 36, D_0028C910);
    STORE_POINTER(D_00255EE0 + 38, D_0028C918);
    STORE_POINTER(D_00255EE0 + 40, D_0028C920);
    STORE_POINTER(D_00255EE0 + 42, D_0028C928);
    STORE_POINTER(D_00255EE0 + 44, D_00255FC0);
    STORE_POINTER(D_00255EE0 + 46, D_0028C930);
    STORE_POINTER(D_00255EE0 + 48, D_00255FE0);
    STORE_POINTER(D_00255EE0 + 50, D_00256000);
    STORE_POINTER(D_00255EE0 + 52, D_00256010);
    STORE_POINTER(D_00255EE0 + 54, D_00256020);
    STORE_POINTER(D_00255EE0 + 56, D_00256030);
    STORE_POINTER(D_00255EE0 + 58, D_00256040);
    STORE_POINTER(D_00255EE0 + 60, D_00256050);
    STORE_POINTER(D_00255EE0 + 62, D_00256060);
    STORE_POINTER(D_00255EE0 + 64, D_00256070);
    STORE_POINTER(D_00255EE0 + 66, D_00256080);
    STORE_POINTER(D_00255EE0 + 68, D_00256090);
    STORE_POINTER(D_00255EE0 + 70, D_002560A0);
    STORE_POINTER(D_00255EE0 + 72, D_0028C938);
    STORE_POINTER(D_00255EE0 + 74, D_0028C940);
}

extern u16 D_00261E30[];
extern u16 D_00261E70[];
extern u16 D_00261EB0[];


void maximum_level_texts_init(void) {
    STORE_POINTER(((u16 *)p1_maximum_level_texts), D_00261CB0);
    STORE_POINTER(p1_maximum_level_texts + 4, D_00261E30);
    STORE_POINTER(p1_maximum_level_texts + 8, D_00261E70);
    STORE_POINTER(D_0028C5E0 + 4, D_00261EB0);
    STORE_POINTER(((u16 *)p2_maximum_level_texts), D_00261CB0);
    STORE_POINTER(p2_maximum_level_texts + 4, D_00261E30);
    STORE_POINTER(p2_maximum_level_texts + 8, D_00261E70);
    STORE_POINTER(D_0028C5E0 + 8, D_00261EB0);
}

extern u16 option_power_value_00_05[];
extern u16 option_power_value_05_05[];
extern u16 option_strong_param_00_05[];
extern u16 option_hyper_param_00_05[];
extern u16 option_sprites_a_00_00_01[];
extern u16 option_sprites_a_00_01_01[];
extern u16 option_sprites_a_00_02_01[];
extern u16 option_sprites_a_00_03_01[];
extern u16 option_sprites_a_00_04_01[];
extern u16 option_sprites_a_01_00_01[];
extern u16 option_sprites_a_01_01_01[];
extern u16 option_sprites_a_01_02_01[];
extern u16 option_sprites_a_01_03_01[];
extern u16 option_sprites_a_01_04_01[];
extern u16 option_strong_sprite_a_00_01[];
extern u16 option_strong_sprite_a_01_01[];
extern u16 option_strong_sprite_a_02_01[];
extern u16 option_strong_sprite_a_03_01[];
extern u16 option_strong_sprite_a_04_01[];
extern u16 option_hyper_sprite_a_00_01[];
extern u16 replay_targets_option_sprites_11[];
extern u16 replay_targets_option_sprites_12[];
extern u16 replay_targets_option_sprites_13[];
extern u16 replay_targets_option_sprites_14[];
extern u16 option_power_value_00_07[];
extern u16 option_power_value_05_07[];
extern u16 option_strong_param_00_07[];
extern u16 option_strong_param_05_07[];
extern u16 option_hyper_param_00_07[];
extern u16 replay_targets_option_sprites_15[];
extern u16 D_00256FD8[];
extern u16 D_00256FE8[];
extern u16 D_00256FF8[];
extern u16 D_00257008[];
extern u16 D_00257018[];
extern u16 replay_targets_option_sprites_16[];
extern u16 D_00257048[];
extern u16 D_00257058[];
extern u16 D_00257068[];
extern u16 D_00257078[];
extern u16 D_00257088[];
extern u16 replay_targets_option_sprites_17[];
extern u16 D_002570B8[];
extern u16 D_002570C8[];
extern u16 D_002570D8[];
extern u16 D_002570E8[];
extern u16 D_002570F8[];
extern u16 replay_targets_option_sprites_18[];
extern u16 D_00257128[];
extern u16 replay_targets_option_params_b_0[];
extern u16 replay_targets_option_params_b_1[];
extern u16 replay_targets_option_params_b_2[];
extern u16 replay_targets_option_params_b_3[];
extern u16 replay_targets_option_params_b_4[];
extern u16 replay_targets_option_params_b_5[];
extern u16 replay_targets_option_params_b_6[];
extern u16 replay_targets_option_params_b_7[];
extern u16 replay_targets_option_params_b_8[];
extern u16 replay_targets_option_params_b_9[];
extern u16 replay_targets_option_params_b_10[];
extern u16 replay_targets_option_params_b_11[];
extern u16 replay_targets_option_params_b_12[];
extern u16 replay_targets_option_params_b_13[];
extern u16 replay_targets_option_params_b_14[];
extern u16 replay_targets_option_params_b_19[];
extern u16 option_power_value_00_08[];
extern u16 option_power_value_01_08[];
extern u16 option_power_value_02_08[];
extern u16 option_power_value_03_08[];
extern u16 option_power_value_04_08[];
extern u16 option_power_value_05_08[];
extern u16 option_power_value_06_08[];
extern u16 option_power_value_07_08[];
extern u16 option_power_value_08_08[];
extern u16 option_power_value_09_08[];
extern u16 option_strong_param_00_08[];
extern u16 option_strong_param_01_08[];
extern u16 option_strong_param_02_08[];
extern u16 option_strong_param_03_08[];
extern u16 option_strong_param_04_08[];
extern u16 option_hyper_param_00_08[];
extern u16 D_002573C0[];
extern u16 D_002573F0[];
extern u16 D_00257420[];
extern u16 D_00257450[];
extern u16 D_00257480[];
extern u16 D_002574B0[];
extern u16 D_002574E0[];
extern u16 D_00257510[];
extern u16 D_00257540[];
extern u16 D_00257570[];
extern u16 D_002575A0[];
extern u16 D_002575D0[];
extern u16 D_00257600[];
extern u16 D_00257630[];
extern u16 D_00257660[];
extern u16 D_00257690[];
extern u16 option_sprites_b_00_00_05[];
extern u16 option_sprites_b_00_01_05[];
extern u16 option_sprites_b_00_02_05[];
extern u16 option_sprites_b_00_03_05[];
extern u16 option_sprites_b_00_04_05[];
extern u16 option_sprites_b_01_00_05[];
extern u16 option_sprites_b_01_01_05[];
extern u16 option_sprites_b_01_02_05[];
extern u16 option_sprites_b_01_03_05[];
extern u16 option_sprites_b_01_04_05[];
extern u16 option_hyper_sprite_b_00_05[];


void option_power_pointers_store(void) {
    STORE_POINTER(option_power_value_00 + 10, option_power_value_00_05);
    STORE_POINTER(option_power_value_00 + 15, option_power_value_00_07);
    STORE_POINTER(option_power_value_00 + 17, option_power_value_00_08);
    STORE_POINTER(option_power_value_01 + 10, option_power_value_00_05);
    STORE_POINTER(option_power_value_01 + 15, option_power_value_00_07);
    STORE_POINTER(option_power_value_01 + 17, option_power_value_01_08);
    STORE_POINTER(option_power_value_02 + 10, option_power_value_00_05);
    STORE_POINTER(option_power_value_02 + 15, option_power_value_00_07);
    STORE_POINTER(option_power_value_02 + 17, option_power_value_02_08);
    STORE_POINTER(option_power_value_03 + 10, option_power_value_00_05);
    STORE_POINTER(option_power_value_03 + 15, option_power_value_00_07);
    STORE_POINTER(option_power_value_03 + 17, option_power_value_03_08);
    STORE_POINTER(option_power_value_04 + 10, option_power_value_00_05);
    STORE_POINTER(option_power_value_04 + 15, option_power_value_00_07);
    STORE_POINTER(option_power_value_04 + 17, option_power_value_04_08);
    STORE_POINTER(option_power_value_05 + 10, option_power_value_05_05);
    STORE_POINTER(option_power_value_05 + 15, option_power_value_05_07);
    STORE_POINTER(option_power_value_05 + 17, option_power_value_05_08);
    STORE_POINTER(option_power_value_06 + 10, option_power_value_05_05);
    STORE_POINTER(option_power_value_06 + 15, option_power_value_05_07);
    STORE_POINTER(option_power_value_06 + 17, option_power_value_06_08);
    STORE_POINTER(option_power_value_07 + 10, option_power_value_05_05);
    STORE_POINTER(option_power_value_07 + 15, option_power_value_05_07);
    STORE_POINTER(option_power_value_07 + 17, option_power_value_07_08);
    STORE_POINTER(option_power_value_08 + 10, option_power_value_05_05);
    STORE_POINTER(option_power_value_08 + 15, option_power_value_05_07);
    STORE_POINTER(option_power_value_08 + 17, option_power_value_08_08);
    STORE_POINTER(option_power_value_09 + 10, option_power_value_05_05);
    STORE_POINTER(option_power_value_09 + 15, option_power_value_05_07);
    STORE_POINTER(option_power_value_09 + 17, option_power_value_09_08);
    STORE_POINTER(option_strong_param_00 + 10, option_strong_param_00_05);
    STORE_POINTER(option_strong_param_00 + 15, option_strong_param_00_07);
    STORE_POINTER(option_strong_param_00 + 17, option_strong_param_00_08);
    STORE_POINTER(option_strong_param_01 + 10, option_strong_param_00_05);
    STORE_POINTER(option_strong_param_01 + 15, option_strong_param_00_07);
    STORE_POINTER(option_strong_param_01 + 17, option_strong_param_01_08);
    STORE_POINTER(option_strong_param_02 + 10, option_strong_param_00_05);
    STORE_POINTER(option_strong_param_02 + 15, option_strong_param_00_07);
    STORE_POINTER(option_strong_param_02 + 17, option_strong_param_02_08);
    STORE_POINTER(option_strong_param_03 + 10, option_strong_param_00_05);
    STORE_POINTER(option_strong_param_03 + 15, option_strong_param_00_07);
    STORE_POINTER(option_strong_param_03 + 17, option_strong_param_03_08);
    STORE_POINTER(option_strong_param_04 + 10, option_strong_param_00_05);
    STORE_POINTER(option_strong_param_04 + 15, option_strong_param_00_07);
    STORE_POINTER(option_strong_param_04 + 17, option_strong_param_04_08);
    STORE_POINTER(option_strong_param_05 + 10, option_strong_param_00_05);
    STORE_POINTER(option_strong_param_05 + 15, option_strong_param_05_07);
    STORE_POINTER(option_strong_param_05 + 17, option_strong_param_00_08);
    STORE_POINTER(option_strong_param_06 + 10, option_strong_param_00_05);
    STORE_POINTER(option_strong_param_06 + 15, option_strong_param_05_07);
    STORE_POINTER(option_strong_param_06 + 17, option_strong_param_01_08);
    STORE_POINTER(option_strong_param_07 + 10, option_strong_param_00_05);
    STORE_POINTER(option_strong_param_07 + 15, option_strong_param_05_07);
    STORE_POINTER(option_strong_param_07 + 17, option_strong_param_02_08);
    STORE_POINTER(option_strong_param_08 + 10, option_strong_param_00_05);
    STORE_POINTER(option_strong_param_08 + 15, option_strong_param_05_07);
    STORE_POINTER(option_strong_param_08 + 17, option_strong_param_03_08);
    STORE_POINTER(option_strong_param_09 + 10, option_strong_param_00_05);
    STORE_POINTER(option_strong_param_09 + 15, option_strong_param_05_07);
    STORE_POINTER(option_strong_param_09 + 17, option_strong_param_04_08);
    STORE_POINTER(option_hyper_param_00 + 10, option_hyper_param_00_05);
    STORE_POINTER(option_hyper_param_00 + 15, option_hyper_param_00_07);
    STORE_POINTER(option_hyper_param_00 + 17, option_hyper_param_00_08);
    STORE_POINTER(option_hyper_param_01 + 10, option_hyper_param_00_05);
    STORE_POINTER(option_hyper_param_01 + 15, option_hyper_param_00_07);
    STORE_POINTER(option_hyper_param_01 + 17, option_hyper_param_00_08);
    STORE_POINTER(option_hyper_param_02 + 10, option_hyper_param_00_05);
    STORE_POINTER(option_hyper_param_02 + 15, option_hyper_param_00_07);
    STORE_POINTER(option_hyper_param_02 + 17, option_hyper_param_00_08);
    STORE_POINTER(option_hyper_param_03 + 10, option_hyper_param_00_05);
    STORE_POINTER(option_hyper_param_03 + 15, option_hyper_param_00_07);
    STORE_POINTER(option_hyper_param_03 + 17, option_hyper_param_00_08);
    STORE_POINTER(option_hyper_param_04 + 10, option_hyper_param_00_05);
    STORE_POINTER(option_hyper_param_04 + 15, option_hyper_param_00_07);
    STORE_POINTER(option_hyper_param_04 + 17, option_hyper_param_00_08);
    STORE_POINTER(option_sprites_a_00_00 + 3, option_sprites_a_00_00_01);
    STORE_POINTER(option_sprites_a_00_01 + 3, option_sprites_a_00_01_01);
    STORE_POINTER(option_sprites_a_00_02 + 3, option_sprites_a_00_02_01);
    STORE_POINTER(option_sprites_a_00_03 + 3, option_sprites_a_00_03_01);
    STORE_POINTER(option_sprites_a_00_04 + 3, option_sprites_a_00_04_01);
    STORE_POINTER(option_sprites_a_01_00 + 3, option_sprites_a_01_00_01);
    STORE_POINTER(option_sprites_a_01_01 + 3, option_sprites_a_01_01_01);
    STORE_POINTER(option_sprites_a_01_02 + 3, option_sprites_a_01_02_01);
    STORE_POINTER(option_sprites_a_01_03 + 3, option_sprites_a_01_03_01);
    STORE_POINTER(option_sprites_a_01_04 + 3, option_sprites_a_01_04_01);
    STORE_POINTER(option_strong_sprite_a_00 + 3, option_strong_sprite_a_00_01);
    STORE_POINTER(option_strong_sprite_a_01 + 3, option_strong_sprite_a_01_01);
    STORE_POINTER(option_strong_sprite_a_02 + 3, option_strong_sprite_a_02_01);
    STORE_POINTER(option_strong_sprite_a_03 + 3, option_strong_sprite_a_03_01);
    STORE_POINTER(option_strong_sprite_a_04 + 3, option_strong_sprite_a_04_01);
    STORE_POINTER(option_hyper_sprite_a_00 + 3, option_hyper_sprite_a_00_01);
    STORE_POINTER(option_sprites_b_00_00 + 10, option_sprites_b_00_00_05);
    STORE_POINTER(option_sprites_b_00_01 + 10, option_sprites_b_00_01_05);
    STORE_POINTER(option_sprites_b_00_02 + 10, option_sprites_b_00_02_05);
    STORE_POINTER(option_sprites_b_00_03 + 10, option_sprites_b_00_03_05);
    STORE_POINTER(option_sprites_b_00_04 + 10, option_sprites_b_00_04_05);
    STORE_POINTER(option_sprites_b_01_00 + 10, option_sprites_b_01_00_05);
    STORE_POINTER(option_sprites_b_01_01 + 10, option_sprites_b_01_01_05);
    STORE_POINTER(option_sprites_b_01_02 + 10, option_sprites_b_01_02_05);
    STORE_POINTER(option_sprites_b_01_03 + 10, option_sprites_b_01_03_05);
    STORE_POINTER(option_sprites_b_01_04 + 10, option_sprites_b_01_04_05);
    STORE_POINTER(option_strong_sprites_b_00_00 + 10, option_sprites_b_00_00_05);
    STORE_POINTER(option_strong_sprites_b_00_01 + 10, option_sprites_b_00_01_05);
    STORE_POINTER(option_strong_sprites_b_00_02 + 10, option_sprites_b_00_02_05);
    STORE_POINTER(option_strong_sprites_b_00_03 + 10, option_sprites_b_00_03_05);
    STORE_POINTER(option_strong_sprites_b_00_04 + 10, option_sprites_b_00_04_05);
    STORE_POINTER(option_strong_sprites_b_01_00 + 10, option_sprites_b_01_00_05);
    STORE_POINTER(option_strong_sprites_b_01_01 + 10, option_sprites_b_01_01_05);
    STORE_POINTER(option_strong_sprites_b_01_02 + 10, option_sprites_b_01_02_05);
    STORE_POINTER(option_strong_sprites_b_01_03 + 10, option_sprites_b_01_03_05);
    STORE_POINTER(option_strong_sprites_b_01_04 + 10, option_sprites_b_01_04_05);
    STORE_POINTER(option_hyper_sprite_b_00 + 10, option_hyper_sprite_b_00_05);
    STORE_POINTER(option_hyper_sprite_b_01 + 10, option_hyper_sprite_b_00_05);
    STORE_POINTER(option_hyper_sprite_b_02 + 10, option_hyper_sprite_b_00_05);
    STORE_POINTER(option_hyper_sprite_b_03 + 10, option_hyper_sprite_b_00_05);
    STORE_POINTER(option_hyper_sprite_b_04 + 10, option_hyper_sprite_b_00_05);
    STORE_POINTER(option_power_value_00_07 + 9, replay_targets_option_sprites_11);
    STORE_POINTER(option_power_value_00_07 + 15, replay_targets_option_sprites_15);
    STORE_POINTER(option_power_value_05_07 + 9, replay_targets_option_sprites_12);
    STORE_POINTER(option_power_value_05_07 + 15, replay_targets_option_sprites_16);
    STORE_POINTER(option_strong_param_00_07 + 9, replay_targets_option_sprites_13);
    STORE_POINTER(option_strong_param_00_07 + 15, replay_targets_option_sprites_17);
    STORE_POINTER(option_strong_param_05_07 + 9, replay_targets_option_sprites_13);
    STORE_POINTER(option_strong_param_05_07 + 15, replay_targets_option_sprites_17);
    STORE_POINTER(option_hyper_param_00_07 + 9, replay_targets_option_sprites_14);
    STORE_POINTER(option_hyper_param_00_07 + 15, replay_targets_option_sprites_18);
    STORE_POINTER(replay_targets_option_sprites_15, D_00256FD8);
    STORE_POINTER(replay_targets_option_sprites_15 + 2, D_00256FE8);
    STORE_POINTER(replay_targets_option_sprites_15 + 4, D_00256FF8);
    STORE_POINTER(replay_targets_option_sprites_15 + 6, D_00257008);
    STORE_POINTER(replay_targets_option_sprites_15 + 8, D_00257018);
    STORE_POINTER(D_00256FD8, replay_targets_option_params_b_0);
    STORE_POINTER(D_00256FE8, replay_targets_option_params_b_1);
    STORE_POINTER(D_00256FF8, replay_targets_option_params_b_2);
    STORE_POINTER(D_00257008, replay_targets_option_params_b_3);
    STORE_POINTER(D_00257018, replay_targets_option_params_b_4);
    STORE_POINTER(replay_targets_option_sprites_16, D_00257048);
    STORE_POINTER(replay_targets_option_sprites_16 + 2, D_00257058);
    STORE_POINTER(replay_targets_option_sprites_16 + 4, D_00257068);
    STORE_POINTER(replay_targets_option_sprites_16 + 6, D_00257078);
    STORE_POINTER(replay_targets_option_sprites_16 + 8, D_00257088);
    STORE_POINTER(D_00257048, replay_targets_option_params_b_5);
    STORE_POINTER(D_00257058, replay_targets_option_params_b_6);
    STORE_POINTER(D_00257068, replay_targets_option_params_b_7);
    STORE_POINTER(D_00257078, replay_targets_option_params_b_8);
    STORE_POINTER(D_00257088, replay_targets_option_params_b_9);
    STORE_POINTER(replay_targets_option_sprites_17, D_002570B8);
    STORE_POINTER(replay_targets_option_sprites_17 + 2, D_002570C8);
    STORE_POINTER(replay_targets_option_sprites_17 + 4, D_002570D8);
    STORE_POINTER(replay_targets_option_sprites_17 + 6, D_002570E8);
    STORE_POINTER(replay_targets_option_sprites_17 + 8, D_002570F8);
    STORE_POINTER(D_002570B8, replay_targets_option_params_b_10);
    STORE_POINTER(D_002570C8, replay_targets_option_params_b_11);
    STORE_POINTER(D_002570D8, replay_targets_option_params_b_12);
    STORE_POINTER(D_002570E8, replay_targets_option_params_b_13);
    STORE_POINTER(D_002570F8, replay_targets_option_params_b_14);
    STORE_POINTER(replay_targets_option_sprites_18, D_00257128);
    STORE_POINTER(replay_targets_option_sprites_18 + 2, D_00257128);
    STORE_POINTER(replay_targets_option_sprites_18 + 4, D_00257128);
    STORE_POINTER(replay_targets_option_sprites_18 + 6, D_00257128);
    STORE_POINTER(replay_targets_option_sprites_18 + 8, D_00257128);
    STORE_POINTER(D_00257128, replay_targets_option_params_b_19);
    STORE_POINTER(D_002576C0 + 2, D_002573C0);
    STORE_POINTER(D_002576C0 + 6, D_002573F0);
    STORE_POINTER(D_002576C0 + 10, D_00257420);
    STORE_POINTER(D_002576C0 + 14, D_00257450);
    STORE_POINTER(D_002576C0 + 18, D_00257480);
    STORE_POINTER(D_002576C0 + 22, D_002574B0);
    STORE_POINTER(D_002576C0 + 26, D_002574E0);
    STORE_POINTER(D_002576C0 + 30, D_00257510);
    STORE_POINTER(D_002576C0 + 34, D_00257540);
    STORE_POINTER(D_002576C0 + 38, D_00257570);
    STORE_POINTER(D_002576C0 + 42, D_002575A0);
    STORE_POINTER(D_002576C0 + 46, D_002575D0);
    STORE_POINTER(D_002576C0 + 50, D_00257600);
    STORE_POINTER(D_002576C0 + 54, D_00257630);
    STORE_POINTER(D_002576C0 + 58, D_00257660);
    STORE_POINTER(D_002576C0 + 62, D_00257690);
    STORE_POINTER(D_002576C0 + 66, D_00257690);
    STORE_POINTER(D_002576C0 + 70, D_00257690);
    STORE_POINTER(D_002576C0 + 74, D_00257690);
    STORE_POINTER(D_002576C0 + 78, D_00257690);
}

extern u16 option_power_value_00[];
extern u16 option_power_value_01[];
extern u16 option_power_value_02[];
extern u16 option_power_value_03[];
extern u16 option_power_value_04[];
extern u16 option_power_value_05[];
extern u16 option_power_value_06[];
extern u16 option_power_value_07[];
extern u16 option_power_value_08[];
extern u16 option_power_value_09[];
extern u16 option_strong_param_00[];
extern u16 option_strong_param_01[];
extern u16 option_strong_param_02[];
extern u16 option_strong_param_03[];
extern u16 option_strong_param_04[];
extern u16 option_strong_param_05[];
extern u16 option_strong_param_06[];
extern u16 option_strong_param_07[];
extern u16 option_strong_param_08[];
extern u16 option_strong_param_09[];
extern u16 option_hyper_param_00[];
extern u16 option_hyper_param_01[];
extern u16 option_hyper_param_02[];
extern u16 option_hyper_param_03[];
extern u16 option_hyper_param_04[];
extern u16 option_sprites_a_00_00[];
extern u16 option_sprites_a_00_01[];
extern u16 option_sprites_a_00_02[];
extern u16 option_sprites_a_00_03[];
extern u16 option_sprites_a_00_04[];
extern u16 option_sprites_a_01_00[];
extern u16 option_sprites_a_01_01[];
extern u16 option_sprites_a_01_02[];
extern u16 option_sprites_a_01_03[];
extern u16 option_sprites_a_01_04[];
extern u16 option_strong_sprite_a_00[];
extern u16 option_strong_sprite_a_01[];
extern u16 option_strong_sprite_a_02[];
extern u16 option_strong_sprite_a_03[];
extern u16 option_strong_sprite_a_04[];
extern u16 option_hyper_sprite_a_00[];
extern u16 option_sprites_b_00_00[];
extern u16 option_sprites_b_00_01[];
extern u16 option_sprites_b_00_02[];
extern u16 option_sprites_b_00_03[];
extern u16 option_sprites_b_00_04[];
extern u16 option_sprites_b_01_00[];
extern u16 option_sprites_b_01_01[];
extern u16 option_sprites_b_01_02[];
extern u16 option_sprites_b_01_03[];
extern u16 option_sprites_b_01_04[];
extern u16 option_strong_sprites_b_00_00[];
extern u16 option_strong_sprites_b_00_01[];
extern u16 option_strong_sprites_b_00_02[];
extern u16 option_strong_sprites_b_00_03[];
extern u16 option_strong_sprites_b_00_04[];
extern u16 option_strong_sprites_b_01_00[];
extern u16 option_strong_sprites_b_01_01[];
extern u16 option_strong_sprites_b_01_02[];
extern u16 option_strong_sprites_b_01_03[];
extern u16 option_strong_sprites_b_01_04[];
extern u16 option_hyper_sprite_b_00[];
extern u16 option_hyper_sprite_b_01[];
extern u16 option_hyper_sprite_b_02[];
extern u16 option_hyper_sprite_b_03[];
extern u16 option_hyper_sprite_b_04[];
extern u16 option_style_param_00_15[];
extern u16 option_style_param_01_15[];
extern u16 option_style_param_02_15[];
extern u16 option_style_param_00_19[];
extern u16 option_style_param_01_19[];
extern u16 option_style_param_02_19[];
extern u16 option_style_param_00_04[];
extern u16 option_style_param_01_04[];
extern u16 option_style_param_02_04[];
extern u16 option_style_param_00[];
extern u16 option_style_param_01[];
extern u16 option_style_param_02[];
extern u16 option_sprites_a_00[];
extern u16 option_sprites_a_01[];
extern u16 option_sprites_b_00[];
extern u16 option_sprites_b_01[];
extern u16 option_strong_sprites_b_00[];
extern u16 option_strong_sprites_b_01[];
extern u16 option_strong_sprites_b_02[];
extern u16 option_strong_sprites_b_03[];

extern u16 option_power_values[];
extern u16 option_strong_sprites_a[];
extern u16 option_hyper_sprites_a[];
extern u16 option_hyper_sprites_b[];
extern u16 option_sprites_a_tables[];
extern u16 option_sprites_b_tables[];
extern u16 option_strong_sprites_b_tables[];

void option_tables_init(void) {
    STORE_POINTER(option_style_param_00 + 8, option_style_param_00_04);
    STORE_POINTER(option_style_param_00 + 19, option_style_param_00_04);
    STORE_POINTER(option_style_param_00 + 30, option_style_param_00_15);
    STORE_POINTER(option_style_param_00 + 39, option_style_param_00_19);
    STORE_POINTER(option_style_param_01 + 8, option_style_param_01_04);
    STORE_POINTER(option_style_param_01 + 19, option_style_param_01_04);
    STORE_POINTER(option_style_param_01 + 30, option_style_param_01_15);
    STORE_POINTER(option_style_param_01 + 39, option_style_param_01_19);
    STORE_POINTER(option_style_param_02 + 8, option_style_param_02_04);
    STORE_POINTER(option_style_param_02 + 19, option_style_param_02_04);
    STORE_POINTER(option_style_param_02 + 30, option_style_param_02_15);
    STORE_POINTER(option_style_param_02 + 39, option_style_param_02_19);
    STORE_POINTER(((u16 *)option_style_params), option_style_param_00);
    STORE_POINTER(option_style_params + 2, option_style_param_01);
    STORE_POINTER(option_style_params + 4, option_style_param_02);
    STORE_POINTER(option_power_values, option_power_value_00);
    STORE_POINTER(option_power_values + 2, option_power_value_01);
    STORE_POINTER(option_power_values + 4, option_power_value_02);
    STORE_POINTER(option_power_values + 6, option_power_value_03);
    STORE_POINTER(option_power_values + 8, option_power_value_04);
    STORE_POINTER(option_power_values + 10, option_power_value_05);
    STORE_POINTER(option_power_values + 12, option_power_value_06);
    STORE_POINTER(option_power_values + 14, option_power_value_07);
    STORE_POINTER(option_power_values + 16, option_power_value_08);
    STORE_POINTER(option_power_values + 18, option_power_value_09);
    STORE_POINTER(((u16 *)option_strong_params), option_strong_param_00);
    STORE_POINTER(option_strong_params + 2, option_strong_param_01);
    STORE_POINTER(option_strong_params + 4, option_strong_param_02);
    STORE_POINTER(option_strong_params + 6, option_strong_param_03);
    STORE_POINTER(option_strong_params + 8, option_strong_param_04);
    STORE_POINTER(option_strong_params + 10, option_strong_param_05);
    STORE_POINTER(option_strong_params + 12, option_strong_param_06);
    STORE_POINTER(option_strong_params + 14, option_strong_param_07);
    STORE_POINTER(option_strong_params + 16, option_strong_param_08);
    STORE_POINTER(option_strong_params + 18, option_strong_param_09);
    STORE_POINTER(((u16 *)option_hyper_params), option_hyper_param_00);
    STORE_POINTER(option_hyper_params + 2, option_hyper_param_01);
    STORE_POINTER(option_hyper_params + 4, option_hyper_param_02);
    STORE_POINTER(option_hyper_params + 6, option_hyper_param_03);
    STORE_POINTER(option_hyper_params + 8, option_hyper_param_04);
    STORE_POINTER(option_sprites_a_tables, option_sprites_a_00);
    STORE_POINTER(option_sprites_a_tables + 2, option_sprites_a_01);
    STORE_POINTER(option_sprites_a_00, option_sprites_a_00_00);
    STORE_POINTER(option_sprites_a_00 + 2, option_sprites_a_00_01);
    STORE_POINTER(option_sprites_a_00 + 4, option_sprites_a_00_02);
    STORE_POINTER(option_sprites_a_00 + 6, option_sprites_a_00_03);
    STORE_POINTER(option_sprites_a_00 + 8, option_sprites_a_00_04);
    STORE_POINTER(option_sprites_a_01, option_sprites_a_01_00);
    STORE_POINTER(option_sprites_a_01 + 2, option_sprites_a_01_01);
    STORE_POINTER(option_sprites_a_01 + 4, option_sprites_a_01_02);
    STORE_POINTER(option_sprites_a_01 + 6, option_sprites_a_01_03);
    STORE_POINTER(option_sprites_a_01 + 8, option_sprites_a_01_04);
    STORE_POINTER(option_strong_sprites_a, option_strong_sprite_a_00);
    STORE_POINTER(option_strong_sprites_a + 2, option_strong_sprite_a_01);
    STORE_POINTER(option_strong_sprites_a + 4, option_strong_sprite_a_02);
    STORE_POINTER(option_strong_sprites_a + 6, option_strong_sprite_a_03);
    STORE_POINTER(option_strong_sprites_a + 8, option_strong_sprite_a_04);
    STORE_POINTER(option_hyper_sprites_a, option_hyper_sprite_a_00);
    STORE_POINTER(option_hyper_sprites_a + 2, option_hyper_sprite_a_00);
    STORE_POINTER(option_hyper_sprites_a + 4, option_hyper_sprite_a_00);
    STORE_POINTER(option_hyper_sprites_a + 6, option_hyper_sprite_a_00);
    STORE_POINTER(option_hyper_sprites_a + 8, option_hyper_sprite_a_00);
    STORE_POINTER(option_sprites_b_tables, option_sprites_b_00);
    STORE_POINTER(option_sprites_b_tables + 2, option_sprites_b_01);
    STORE_POINTER(option_sprites_b_00, option_sprites_b_00_00);
    STORE_POINTER(option_sprites_b_00 + 2, option_sprites_b_00_01);
    STORE_POINTER(option_sprites_b_00 + 4, option_sprites_b_00_02);
    STORE_POINTER(option_sprites_b_00 + 6, option_sprites_b_00_03);
    STORE_POINTER(option_sprites_b_00 + 8, option_sprites_b_00_04);
    STORE_POINTER(option_sprites_b_01, option_sprites_b_01_00);
    STORE_POINTER(option_sprites_b_01 + 2, option_sprites_b_01_01);
    STORE_POINTER(option_sprites_b_01 + 4, option_sprites_b_01_02);
    STORE_POINTER(option_sprites_b_01 + 6, option_sprites_b_01_03);
    STORE_POINTER(option_sprites_b_01 + 8, option_sprites_b_01_04);
    STORE_POINTER(option_strong_sprites_b_tables, option_strong_sprites_b_00);
    STORE_POINTER(option_strong_sprites_b_tables + 2, option_strong_sprites_b_01);
    STORE_POINTER(option_strong_sprites_b_00, option_strong_sprites_b_00_00);
    STORE_POINTER(option_strong_sprites_b_00 + 2, option_strong_sprites_b_00_01);
    STORE_POINTER(option_strong_sprites_b_00 + 4, option_strong_sprites_b_00_02);
    STORE_POINTER(option_strong_sprites_b_00 + 6, option_strong_sprites_b_00_03);
    STORE_POINTER(option_strong_sprites_b_00 + 8, option_strong_sprites_b_00_04);
    STORE_POINTER(option_strong_sprites_b_01, option_strong_sprites_b_01_00);
    STORE_POINTER(option_strong_sprites_b_01 + 2, option_strong_sprites_b_01_01);
    STORE_POINTER(option_strong_sprites_b_01 + 4, option_strong_sprites_b_01_02);
    STORE_POINTER(option_strong_sprites_b_01 + 6, option_strong_sprites_b_01_03);
    STORE_POINTER(option_strong_sprites_b_01 + 8, option_strong_sprites_b_01_04);
    STORE_POINTER(option_hyper_sprites_b, option_hyper_sprite_b_00);
    STORE_POINTER(option_hyper_sprites_b + 2, option_hyper_sprite_b_01);
    STORE_POINTER(option_hyper_sprites_b + 4, option_hyper_sprite_b_02);
    STORE_POINTER(option_hyper_sprites_b + 6, option_hyper_sprite_b_03);
    STORE_POINTER(option_hyper_sprites_b + 8, option_hyper_sprite_b_04);
    STORE_POINTER(option_strong_sprites_b_tables + 4, option_strong_sprites_b_02);
    STORE_POINTER(option_strong_sprites_b_tables + 6, option_strong_sprites_b_03);
}

extern u16 option_shot_list_1_00_00[];
extern u16 option_shot_list_2_00_00[];
extern u16 option_shot_list_1_00_01[];
extern u16 option_shot_list_2_00_01[];
extern u16 option_shot_list_1_00_02[];
extern u16 option_shot_list_2_00_02[];
extern u16 option_shot_list_1_00_03[];
extern u16 option_shot_list_2_00_03[];
extern u16 option_shot_list_1_00_04[];
extern u16 option_shot_list_2_00_04[];
extern u16 option_shot_list_3_00_00[];
extern u16 option_shot_list_3_00_01[];
extern u16 option_shot_list_3_00_02[];
extern u16 option_shot_list_3_00_03[];
extern u16 option_shot_list_3_00_04[];
extern u16 option_shot_list_4_00_00[];
extern u16 option_shot_list_4_00_01[];
extern u16 option_shot_list_4_00_02[];
extern u16 option_shot_list_4_00_03[];
extern u16 option_shot_list_4_00_04[];
extern u16 option_shot_list_1_02_00[];
extern u16 option_shot_list_2_02_00[];
extern u16 option_shot_list_1_02_01[];
extern u16 option_shot_list_2_02_01[];
extern u16 option_shot_list_1_02_02[];
extern u16 option_shot_list_2_02_02[];
extern u16 option_shot_list_1_02_03[];
extern u16 option_shot_list_2_02_03[];
extern u16 option_shot_list_1_02_04[];
extern u16 option_shot_list_2_02_04[];
extern u16 option_shot_list_3_02_00[];
extern u16 option_shot_list_3_02_01[];
extern u16 option_shot_list_3_02_02[];
extern u16 option_shot_list_3_02_03[];
extern u16 option_shot_list_3_02_04[];
extern u16 option_shot_list_4_02_00[];
extern u16 option_shot_list_4_02_01[];
extern u16 option_shot_list_4_02_02[];
extern u16 option_shot_list_4_02_03[];
extern u16 option_shot_list_4_02_04[];
extern u16 option_shot_list_1_01_00[];
extern u16 option_shot_list_2_01_00[];
extern u16 option_shot_list_1_01_01[];
extern u16 option_shot_list_2_01_01[];
extern u16 option_shot_list_1_01_02[];
extern u16 option_shot_list_2_01_02[];
extern u16 option_shot_list_1_01_03[];
extern u16 option_shot_list_2_01_03[];
extern u16 option_shot_list_1_01_04[];
extern u16 option_shot_list_2_01_04[];
extern u16 option_shot_list_3_01_00[];
extern u16 option_shot_list_3_01_01[];
extern u16 option_shot_list_3_01_02[];
extern u16 option_shot_list_3_01_03[];
extern u16 option_shot_list_3_01_04[];
extern u16 option_shot_list_4_01_00[];
extern u16 option_shot_list_4_01_01[];
extern u16 option_shot_list_4_01_02[];
extern u16 option_shot_list_4_01_03[];
extern u16 option_shot_list_4_01_04[];
extern u16 option_shot_list_1_03_00[];
extern u16 option_shot_list_2_03_00[];
extern u16 option_shot_list_1_03_01[];
extern u16 option_shot_list_2_03_01[];
extern u16 option_shot_list_1_03_02[];
extern u16 option_shot_list_2_03_02[];
extern u16 option_shot_list_1_03_03[];
extern u16 option_shot_list_2_03_03[];
extern u16 option_shot_list_1_03_04[];
extern u16 option_shot_list_2_03_04[];
extern u16 option_shot_list_3_03_00[];
extern u16 option_shot_list_3_03_01[];
extern u16 option_shot_list_3_03_02[];
extern u16 option_shot_list_3_03_03[];
extern u16 option_shot_list_3_03_04[];
extern u16 option_shot_list_4_03_00[];
extern u16 option_shot_list_4_03_01[];
extern u16 option_shot_list_4_03_02[];
extern u16 option_shot_list_4_03_03[];
extern u16 option_shot_list_4_03_04[];
extern u16 option_shot_list_1_00[];
extern u16 option_shot_list_1_02[];
extern u16 option_shot_list_1_01[];
extern u16 option_shot_list_1_03[];
extern u16 option_shot_list_2_00[];
extern u16 option_shot_list_2_02[];
extern u16 option_shot_list_2_01[];
extern u16 option_shot_list_2_03[];
extern u16 option_shot_list_3_00[];
extern u16 option_shot_list_3_02[];
extern u16 option_shot_list_3_01[];
extern u16 option_shot_list_3_03[];
extern u16 option_shot_list_4_00[];
extern u16 option_shot_list_4_02[];
extern u16 option_shot_list_4_01[];
extern u16 option_shot_list_4_03[];


void option_shot_lists_init(void) {
    STORE_POINTER(((u16 *)option_shot_lists_1), option_shot_list_1_00);
    STORE_POINTER(option_shot_lists_1 + 2, option_shot_list_1_01);
    STORE_POINTER(option_shot_lists_1 + 4, option_shot_list_1_02);
    STORE_POINTER(option_shot_lists_1 + 6, option_shot_list_1_03);
    STORE_POINTER(option_shot_list_1_00, option_shot_list_1_00_00);
    STORE_POINTER(option_shot_list_1_00 + 2, option_shot_list_1_00_01);
    STORE_POINTER(option_shot_list_1_00 + 4, option_shot_list_1_00_02);
    STORE_POINTER(option_shot_list_1_00 + 6, option_shot_list_1_00_03);
    STORE_POINTER(option_shot_list_1_00 + 8, option_shot_list_1_00_04);
    STORE_POINTER(option_shot_list_1_02, option_shot_list_1_02_00);
    STORE_POINTER(option_shot_list_1_02 + 2, option_shot_list_1_02_01);
    STORE_POINTER(option_shot_list_1_02 + 4, option_shot_list_1_02_02);
    STORE_POINTER(option_shot_list_1_02 + 6, option_shot_list_1_02_03);
    STORE_POINTER(option_shot_list_1_02 + 8, option_shot_list_1_02_04);
    STORE_POINTER(option_shot_list_1_01, option_shot_list_1_01_00);
    STORE_POINTER(option_shot_list_1_01 + 2, option_shot_list_1_01_01);
    STORE_POINTER(option_shot_list_1_01 + 4, option_shot_list_1_01_02);
    STORE_POINTER(option_shot_list_1_01 + 6, option_shot_list_1_01_03);
    STORE_POINTER(option_shot_list_1_01 + 8, option_shot_list_1_01_04);
    STORE_POINTER(option_shot_list_1_03, option_shot_list_1_03_00);
    STORE_POINTER(option_shot_list_1_03 + 2, option_shot_list_1_03_01);
    STORE_POINTER(option_shot_list_1_03 + 4, option_shot_list_1_03_02);
    STORE_POINTER(option_shot_list_1_03 + 6, option_shot_list_1_03_03);
    STORE_POINTER(option_shot_list_1_03 + 8, option_shot_list_1_03_04);
    STORE_POINTER(((u16 *)option_shot_lists_2), option_shot_list_2_00);
    STORE_POINTER(option_shot_lists_2 + 2, option_shot_list_2_01);
    STORE_POINTER(option_shot_lists_2 + 4, option_shot_list_2_02);
    STORE_POINTER(option_shot_lists_2 + 6, option_shot_list_2_03);
    STORE_POINTER(option_shot_list_2_00, option_shot_list_2_00_00);
    STORE_POINTER(option_shot_list_2_00 + 2, option_shot_list_2_00_01);
    STORE_POINTER(option_shot_list_2_00 + 4, option_shot_list_2_00_02);
    STORE_POINTER(option_shot_list_2_00 + 6, option_shot_list_2_00_03);
    STORE_POINTER(option_shot_list_2_00 + 8, option_shot_list_2_00_04);
    STORE_POINTER(option_shot_list_2_02, option_shot_list_2_02_00);
    STORE_POINTER(option_shot_list_2_02 + 2, option_shot_list_2_02_01);
    STORE_POINTER(option_shot_list_2_02 + 4, option_shot_list_2_02_02);
    STORE_POINTER(option_shot_list_2_02 + 6, option_shot_list_2_02_03);
    STORE_POINTER(option_shot_list_2_02 + 8, option_shot_list_2_02_04);
    STORE_POINTER(option_shot_list_2_01, option_shot_list_2_01_00);
    STORE_POINTER(option_shot_list_2_01 + 2, option_shot_list_2_01_01);
    STORE_POINTER(option_shot_list_2_01 + 4, option_shot_list_2_01_02);
    STORE_POINTER(option_shot_list_2_01 + 6, option_shot_list_2_01_03);
    STORE_POINTER(option_shot_list_2_01 + 8, option_shot_list_2_01_04);
    STORE_POINTER(option_shot_list_2_03, option_shot_list_2_03_00);
    STORE_POINTER(option_shot_list_2_03 + 2, option_shot_list_2_03_01);
    STORE_POINTER(option_shot_list_2_03 + 4, option_shot_list_2_03_02);
    STORE_POINTER(option_shot_list_2_03 + 6, option_shot_list_2_03_03);
    STORE_POINTER(option_shot_list_2_03 + 8, option_shot_list_2_03_04);
    STORE_POINTER(((u16 *)option_shot_lists_3), option_shot_list_3_00);
    STORE_POINTER(option_shot_lists_3 + 2, option_shot_list_3_01);
    STORE_POINTER(option_shot_lists_3 + 4, option_shot_list_3_02);
    STORE_POINTER(option_shot_lists_3 + 6, option_shot_list_3_03);
    STORE_POINTER(option_shot_list_3_00, option_shot_list_3_00_00);
    STORE_POINTER(option_shot_list_3_00 + 2, option_shot_list_3_00_01);
    STORE_POINTER(option_shot_list_3_00 + 4, option_shot_list_3_00_02);
    STORE_POINTER(option_shot_list_3_00 + 6, option_shot_list_3_00_03);
    STORE_POINTER(option_shot_list_3_00 + 8, option_shot_list_3_00_04);
    STORE_POINTER(option_shot_list_3_02, option_shot_list_3_02_00);
    STORE_POINTER(option_shot_list_3_02 + 2, option_shot_list_3_02_01);
    STORE_POINTER(option_shot_list_3_02 + 4, option_shot_list_3_02_02);
    STORE_POINTER(option_shot_list_3_02 + 6, option_shot_list_3_02_03);
    STORE_POINTER(option_shot_list_3_02 + 8, option_shot_list_3_02_04);
    STORE_POINTER(option_shot_list_3_01, option_shot_list_3_01_00);
    STORE_POINTER(option_shot_list_3_01 + 2, option_shot_list_3_01_01);
    STORE_POINTER(option_shot_list_3_01 + 4, option_shot_list_3_01_02);
    STORE_POINTER(option_shot_list_3_01 + 6, option_shot_list_3_01_03);
    STORE_POINTER(option_shot_list_3_01 + 8, option_shot_list_3_01_04);
    STORE_POINTER(option_shot_list_3_03, option_shot_list_3_03_00);
    STORE_POINTER(option_shot_list_3_03 + 2, option_shot_list_3_03_01);
    STORE_POINTER(option_shot_list_3_03 + 4, option_shot_list_3_03_02);
    STORE_POINTER(option_shot_list_3_03 + 6, option_shot_list_3_03_03);
    STORE_POINTER(option_shot_list_3_03 + 8, option_shot_list_3_03_04);
    STORE_POINTER(((u16 *)option_shot_lists_4), option_shot_list_4_00);
    STORE_POINTER(option_shot_lists_4 + 2, option_shot_list_4_01);
    STORE_POINTER(option_shot_lists_4 + 4, option_shot_list_4_02);
    STORE_POINTER(option_shot_lists_4 + 6, option_shot_list_4_03);
    STORE_POINTER(option_shot_list_4_00, option_shot_list_4_00_00);
    STORE_POINTER(option_shot_list_4_00 + 2, option_shot_list_4_00_01);
    STORE_POINTER(option_shot_list_4_00 + 4, option_shot_list_4_00_02);
    STORE_POINTER(option_shot_list_4_00 + 6, option_shot_list_4_00_03);
    STORE_POINTER(option_shot_list_4_00 + 8, option_shot_list_4_00_04);
    STORE_POINTER(option_shot_list_4_02, option_shot_list_4_02_00);
    STORE_POINTER(option_shot_list_4_02 + 2, option_shot_list_4_02_01);
    STORE_POINTER(option_shot_list_4_02 + 4, option_shot_list_4_02_02);
    STORE_POINTER(option_shot_list_4_02 + 6, option_shot_list_4_02_03);
    STORE_POINTER(option_shot_list_4_02 + 8, option_shot_list_4_02_04);
    STORE_POINTER(option_shot_list_4_01, option_shot_list_4_01_00);
    STORE_POINTER(option_shot_list_4_01 + 2, option_shot_list_4_01_01);
    STORE_POINTER(option_shot_list_4_01 + 4, option_shot_list_4_01_02);
    STORE_POINTER(option_shot_list_4_01 + 6, option_shot_list_4_01_03);
    STORE_POINTER(option_shot_list_4_01 + 8, option_shot_list_4_01_04);
    STORE_POINTER(option_shot_list_4_03, option_shot_list_4_03_00);
    STORE_POINTER(option_shot_list_4_03 + 2, option_shot_list_4_03_01);
    STORE_POINTER(option_shot_list_4_03 + 4, option_shot_list_4_03_02);
    STORE_POINTER(option_shot_list_4_03 + 6, option_shot_list_4_03_03);
    STORE_POINTER(option_shot_list_4_03 + 8, option_shot_list_4_03_04);
}

extern u16 ground_gun_a_aim[];
extern u16 ground_gun_c_aim[];
extern u16 D_00258880[];
extern u16 D_00258900[];
extern u16 D_0028C0D8[];
extern u16 D_0028C0DC[];
extern void ground_shot_random_a(void);
extern void ground_shot_random_b(void);
extern void ground_gun_a_fire(void);
extern void ground_gun_b_aim(void);
extern void ground_gun_b_fire(void);
extern void ground_gun_c_fire(void);
extern void wing_gunner_fire(void);
extern void ground_pointer_rows_fill(void);
extern void entity_draw_layer1(void);
extern void sprite_draw_layer1(void);

extern u16 D_00258560[];
extern u16 D_002586E0[];
extern u16 D_00258760[];
extern u16 D_00258770[];

void ground_enemy_pointers_store(void) {
    STORE_POINTER(D_0028C9B0 + 4, ground_shot_random_b);
    STORE_POINTER(D_0028C9B0 + 6, ground_shot_random_a);
    STORE_POINTER(D_00258560, ground_gun_a_aim);
    STORE_POINTER(D_00258560 + 2, ground_gun_a_fire);
    STORE_POINTER(D_00258560 + 4, ground_gun_b_aim);
    STORE_POINTER(D_00258560 + 6, ground_gun_b_fire);
    STORE_POINTER(D_00258560 + 8, ground_gun_a_aim);
    STORE_POINTER(D_00258560 + 10, ground_gun_a_fire);
    STORE_POINTER(D_00258560 + 12, ground_gun_b_aim);
    STORE_POINTER(D_00258560 + 14, ground_gun_b_fire);
    STORE_POINTER(D_002586E0, ground_gun_c_aim);
    STORE_POINTER(D_002586E0 + 2, ground_gun_c_fire);
    STORE_POINTER(D_002586E0 + 4, ground_gun_c_aim);
    STORE_POINTER(D_002586E0 + 6, ground_gun_c_fire);
    STORE_POINTER(D_00258760, ground_pointer_rows_fill);
    STORE_POINTER(D_00258760 + 2, wing_gunner_fire);
    STORE_POINTER(D_00258760 + 4, wing_gunner_fire);
    STORE_POINTER(D_00258760 + 6, wing_gunner_fire);
    STORE_POINTER(D_00258770, wing_gunner_fire);
    STORE_POINTER(D_00258770 + 2, wing_gunner_fire);
    STORE_POINTER(D_00258770 + 4, ground_pointer_rows_fill);
    STORE_POINTER(D_00258770 + 6, ground_pointer_rows_fill);
    STORE_POINTER(D_00258770 + 8, wing_gunner_fire);
    STORE_POINTER(D_00258770 + 10, wing_gunner_fire);
    STORE_POINTER(D_00258770 + 12, wing_gunner_fire);
    STORE_POINTER(D_00258770 + 14, ground_pointer_rows_fill);
    STORE_POINTER(((u16 *)D_0028C9D8), D_00258880);
    STORE_POINTER(D_0028C9D8 + 2, D_00258900);
    STORE_POINTER(D_002589B0 + 10, entity_draw_layer1);
    STORE_POINTER(D_002589B0 + 12, sprite_draw_layer1);
    STORE_POINTER(D_00257C10 + 104, D_0028C0DC);
    STORE_POINTER(D_00257C10 + 112, D_0028C0DC);
    STORE_POINTER(D_00257C10 + 120, D_0028C0D8);
    STORE_POINTER(D_00257C10 + 128, D_0028C0D8);
}

extern u16 g_explosion_test_labels_at_0[];
extern u16 g_explosion_test_labels_at_2[];

extern u16 g_explosion_test_labels[];

void explosion_test_pointers_store(void) {
    STORE_POINTER(g_explosion_test_labels, g_explosion_test_labels_at_0);
    STORE_POINTER(g_explosion_test_labels + 2, g_explosion_test_labels_at_2);
}

extern u16 large_tank_entities_at_47[];
extern u16 D_0028C0C8[];
extern void entity_draw_layer2(void);
extern void entity_draw_layer3(void);
extern void entity_draw_layer4(void);
extern void entity_draw_layer5(void);
extern void sprite_draw_layer2(void);
extern void sprite_draw_layer3(void);
extern void sprite_draw_layer4(void);
extern void sprite_draw_layer5(void);


void small_tank_pointers_store(void) {
    STORE_POINTER(small_tank_draw_routines, entity_draw_layer1);
    STORE_POINTER(small_tank_draw_routines + 2, sprite_draw_layer1);
    STORE_POINTER(small_tank_draw_routines + 4, entity_draw_layer1);
    STORE_POINTER(small_tank_draw_routines + 6, sprite_draw_layer1);
    STORE_POINTER(small_tank_draw_routines + 8, entity_draw_layer2);
    STORE_POINTER(small_tank_draw_routines + 10, sprite_draw_layer2);
    STORE_POINTER(small_tank_draw_routines + 12, entity_draw_layer3);
    STORE_POINTER(small_tank_draw_routines + 14, sprite_draw_layer3);
    STORE_POINTER(small_tank_draw_routines + 16, entity_draw_layer4);
    STORE_POINTER(small_tank_draw_routines + 18, sprite_draw_layer4);
    STORE_POINTER(small_tank_draw_routines + 20, entity_draw_layer5);
    STORE_POINTER(small_tank_draw_routines + 22, sprite_draw_layer5);
    STORE_POINTER(small_tank_a_state + 10, entity_draw_layer1);
    STORE_POINTER(small_tank_a_state + 12, sprite_draw_layer1);
    STORE_POINTER(small_tank_b_state + 10, entity_draw_layer1);
    STORE_POINTER(small_tank_b_state + 12, sprite_draw_layer1);
    STORE_POINTER(large_tank_entities + 33, D_0028C0C8);
    STORE_POINTER(large_tank_entities + 40, D_0028C0C8);
    STORE_POINTER(large_tank_entities + 47, large_tank_entities_at_47);
    STORE_POINTER(large_tank_entities + 54, large_tank_entities_at_47);
    STORE_POINTER(hatch_gunner_entities + 33, D_0028C0C8);
    STORE_POINTER(hatch_gunner_entities + 40, D_0028C0C8);
}

extern u16 stage1_midboss_fade_script_at_60[];
extern u16 stage1_midboss_fade_script_at_67[];
extern u16 stage1_midboss_fade_script_at_74[];
extern u16 stage1_midboss_fade_script_at_81[];
extern u16 stage1_midboss_fade_script_at_88[];
extern u16 stage1_midboss_fade_script_at_95[];
extern u8 stage1_midboss_fade_script_at_11[];
extern u8 stage1_midboss_fade_script_at_18[];
extern u8 stage1_midboss_fade_script_at_25[];
extern u16 D_002610F0[];
extern u16 D_00261130[];
extern u16 D_00261170[];
extern u16 D_002611B0[];
extern u16 D_002611F0[];
extern u16 D_0028C0D0[];


void stage1_midboss_pointers_store(void) {
    STORE_POINTER(stage1_midboss_entities + 243, D_0028C0D0);
    STORE_POINTER(stage1_midboss_fade_script + 4, D_002610F0);
    STORE_POINTER(stage1_midboss_fade_script + 11, ((u16 *)stage1_midboss_fade_script_at_11));
    STORE_POINTER(stage1_midboss_fade_script + 18, ((u16 *)stage1_midboss_fade_script_at_18));
    STORE_POINTER(stage1_midboss_fade_script + 25, ((u16 *)stage1_midboss_fade_script_at_25));
    STORE_POINTER(stage1_midboss_fade_script + 32, D_00261170);
    STORE_POINTER(stage1_midboss_fade_script + 39, D_00261130);
    STORE_POINTER(stage1_midboss_fade_script + 46, D_002611B0);
    STORE_POINTER(stage1_midboss_fade_script + 53, D_002611F0);
    STORE_POINTER(stage1_midboss_fade_script + 60, stage1_midboss_fade_script_at_60);
    STORE_POINTER(stage1_midboss_fade_script + 67, stage1_midboss_fade_script_at_67);
    STORE_POINTER(stage1_midboss_fade_script + 74, stage1_midboss_fade_script_at_74);
    STORE_POINTER(stage1_midboss_fade_script + 81, stage1_midboss_fade_script_at_81);
    STORE_POINTER(stage1_midboss_fade_script + 88, stage1_midboss_fade_script_at_88);
    STORE_POINTER(stage1_midboss_fade_script + 95, stage1_midboss_fade_script_at_95);
}



extern u16 g_stage3_map_palettes[];
extern u16 stage3_midboss_flash_palettes_05[];
extern void stage3_midboss_mode_00(void);
extern void stage3_midboss_mode_attack_a(void);
extern void stage3_midboss_mode_attack_b(void);
extern void stage3_midboss2_state_0_04(void);
extern void stage3_midboss_shot(void);
extern void stage3_midboss_mode_05(void);
extern void stage3_midboss_mode_leave(void);

extern u16 stage3_midboss_mode_routines[];
extern u16 D_002635C2[];
extern u16 stage3_midboss2_state_routines_1[];
extern u16 D_00263612[];

void stage3_midboss_pointers_store(void) {
    if (stage3_midboss_table[103] != 0x67) {
        printf("error! st3mb_tbl[103]\n");
    }
    STORE_POINTER(stage3_midboss_table + 103, D_0028C0D0);
    if (stage3_midboss_flash_palettes[4] != 0x4) {
        printf("error! st3mbflush0_tbl[4]\n");
    }
    STORE_POINTER(stage3_midboss_flash_palettes + 4, D_002610F0);
    if (stage3_midboss_flash_palettes[11] != 0xb) {
        printf("error! st3mbflush0_tbl[11]\n");
    }
    STORE_POINTER(stage3_midboss_flash_palettes + 11, stage3_midboss_flash_palettes_05);
    if (stage3_midboss_flash_palettes[18] != 0x12) {
        printf("error! st3mbflush0_tbl[18]\n");
    }
    STORE_POINTER(stage3_midboss_flash_palettes + 18, g_stage3_map_palettes);
    if (stage3_midboss_mode_routines[0] != 0x0) {
        printf("error! st3mb_md_tbl[0]\n");
    }
    STORE_POINTER(stage3_midboss_mode_routines, stage3_midboss_mode_00);
    if (D_002635C2[1] != 0x2) {
        printf("error! st3mb_md_tbl[2]\n");
    }
    STORE_POINTER(D_002635C2 + 1, stage3_midboss_mode_attack_a);
    if (D_002635C2[3] != 0x4) {
        printf("error! st3mb_md_tbl[4]\n");
    }
    STORE_POINTER(D_002635C2 + 3, stage3_midboss_mode_attack_b);
    if (D_002635C2[5] != 0x6) {
        printf("error! st3mb_md_tbl[6]\n");
    }
    STORE_POINTER(D_002635C2 + 5, stage3_midboss_mode_attack_a);
    if (D_002635C2[7] != 0x8) {
        printf("error! st3mb_md_tbl[8]\n");
    }
    STORE_POINTER(D_002635C2 + 7, stage3_midboss_mode_attack_b);
    if (D_002635C2[9] != 0xa) {
        printf("error! st3mb_md_tbl[10]\n");
    }
    STORE_POINTER(D_002635C2 + 9, stage3_midboss_mode_05);
    if (D_002635C2[11] != 0xc) {
        printf("error! st3mb_md_tbl[12]\n");
    }
    STORE_POINTER(D_002635C2 + 11, stage3_midboss_mode_leave);
    if (stage3_midboss2_state_routines_0[8] != 0x0) {
        printf("error! s3mm2_st_tbl0[0]\n");
    }
    STORE_POINTER(stage3_midboss2_state_routines_0 + 8, stage3_midboss2_state_0_04);
    if (stage3_midboss2_state_routines_0[10] != 0x2) {
        printf("error! s3mm2_st_tbl0[2]\n");
    }
    STORE_POINTER(stage3_midboss2_state_routines_0 + 10, stage3_midboss2_state_0_04);
    if (stage3_midboss2_state_routines_0[12] != 0x4) {
        printf("error! s3mm2_st_tbl0[4]\n");
    }
    STORE_POINTER(stage3_midboss2_state_routines_0 + 12, stage3_midboss2_state_0_04);
    if (stage3_midboss2_state_routines_0[14] != 0x6) {
        printf("error! s3mm2_st_tbl0[6]\n");
    }
    STORE_POINTER(stage3_midboss2_state_routines_0 + 14, stage3_midboss2_state_0_04);
    if (stage3_midboss2_state_routines_0[16] != 0x8) {
        printf("error! s3mm2_st_tbl0[8]\n");
    }
    STORE_POINTER(stage3_midboss2_state_routines_0 + 16, stage3_midboss2_state_0_04);
    if (stage3_midboss2_state_routines_0[18] != 0xa) {
        printf("error! s3mm2_st_tbl0[10]\n");
    }
    STORE_POINTER(stage3_midboss2_state_routines_0 + 18, stage3_midboss2_state_0_04);
    if (stage3_midboss2_state_routines_0[20] != 0xc) {
        printf("error! s3mm2_st_tbl0[12]\n");
    }
    STORE_POINTER(stage3_midboss2_state_routines_0 + 20, stage3_midboss2_state_0_04);
    if (stage3_midboss2_state_routines_0[22] != 0xe) {
        printf("error! s3mm2_st_tbl0[14]\n");
    }
    STORE_POINTER(stage3_midboss2_state_routines_0 + 22, stage3_midboss2_state_0_04);
    if (stage3_midboss2_state_routines_1[0] != 0x0) {
        printf("error! s3mm2_st_tbl1[0]\n");
    }
    STORE_POINTER(stage3_midboss2_state_routines_1, stage3_midboss_shot);
    if (D_00263612[1] != 0x2) {
        printf("error! s3mm2_st_tbl1[2]\n");
    }
    STORE_POINTER(D_00263612 + 1, stage3_midboss_shot);
    if (D_00263612[3] != 0x4) {
        printf("error! s3mm2_st_tbl1[4]\n");
    }
    STORE_POINTER(D_00263612 + 3, stage3_midboss_shot);
    if (D_00263612[5] != 0x6) {
        printf("error! s3mm2_st_tbl1[6]\n");
    }
    STORE_POINTER(D_00263612 + 5, stage3_midboss_shot);
    if (D_00263612[7] != 0x8) {
        printf("error! s3mm2_st_tbl1[8]\n");
    }
    STORE_POINTER(D_00263612 + 7, stage3_midboss_shot);
    if (D_00263612[9] != 0xa) {
        printf("error! s3mm2_st_tbl1[10]\n");
    }
    STORE_POINTER(D_00263612 + 9, stage3_midboss_shot);
    if (D_00263612[11] != 0xc) {
        printf("error! s3mm2_st_tbl1[12]\n");
    }
    STORE_POINTER(D_00263612 + 11, stage3_midboss_shot);
    if (D_00263612[13] != 0xe) {
        printf("error! s3mm2_st_tbl1[14]\n");
    }
    STORE_POINTER(D_00263612 + 13, stage3_midboss_shot);
}

extern u16 D_00261D30[];


void pointers_store_part_6(void) {
    STORE_POINTER(D_00265B60 + 91, D_00261D30);
    STORE_POINTER(D_00265F60 + 3, D_00261D30);
    STORE_POINTER(D_00266330 + 3, D_00261D30);
}

extern void entity_draw_layer1_keep(void);
extern void entity_draw_layer2_keep(void);
extern void entity_draw_layer3_keep(void);
extern void entity_draw_layer4_keep(void);
extern void entity_draw_layer5_keep(void);
extern void entity_draw_layer1_zoom(void);
extern void entity_draw_layer2_zoom(void);
extern void entity_draw_layer3_zoom(void);
extern void entity_draw_layer4_zoom(void);
extern void entity_draw_layer5_zoom(void);
extern void sprite_draw_layer1_keep(void);
extern void sprite_draw_layer2_keep(void);
extern void sprite_draw_layer3_keep(void);
extern void sprite_draw_layer4_keep(void);
extern void sprite_draw_layer5_keep(void);

extern u16 D_0025AE10[];
extern u16 D_0025AE50[];
extern u16 D_0025AE70[];

void pointers_store_part_7(void) {
    STORE_POINTER(D_0025A0B0 + 33, D_0028C0C8);
    STORE_POINTER(D_0025A0B0 + 40, D_0028C0C8);
    STORE_POINTER(D_0025A0B0 + 47, large_tank_entities_at_47);
    STORE_POINTER(D_0025A0B0 + 54, large_tank_entities_at_47);
    STORE_POINTER(D_0025A160 + 33, D_0028C0C8);
    STORE_POINTER(D_0025A160 + 40, D_0028C0C8);
    STORE_POINTER(D_0025A160 + 47, large_tank_entities_at_47);
    STORE_POINTER(D_0025A160 + 54, large_tank_entities_at_47);
    STORE_POINTER(D_0025A230 + 33, D_0028C0C8);
    STORE_POINTER(D_0025A230 + 40, D_0028C0C8);
    STORE_POINTER(D_0025A2C0 + 33, D_0028C0C8);
    STORE_POINTER(D_0025A2C0 + 40, D_0028C0C8);
    STORE_POINTER(D_0025A2C0 + 47, large_tank_entities_at_47);
    STORE_POINTER(D_0025A3B0 + 33, D_0028C0C8);
    STORE_POINTER(D_0025A3B0 + 40, D_0028C0C8);
    STORE_POINTER(D_0025A3B0 + 47, large_tank_entities_at_47);
    STORE_POINTER(D_0025A3B0 + 54, large_tank_entities_at_47);
    STORE_POINTER(D_0025A4B0 + 33, D_0028C0C8);
    STORE_POINTER(D_0025A4B0 + 40, D_0028C0C8);
    STORE_POINTER(D_0025A4B0 + 47, large_tank_entities_at_47);
    STORE_POINTER(D_0025A5A0 + 33, D_0028C0C8);
    STORE_POINTER(D_0025A5A0 + 40, D_0028C0C8);
    STORE_POINTER(D_0025A5A0 + 47, large_tank_entities_at_47);
    STORE_POINTER(D_0025AD90 + 19, D_0028C0C8);
    STORE_POINTER(D_0025AD90 + 26, D_0028C0C8);
    STORE_POINTER(D_0025AD90 + 33, large_tank_entities_at_47);
    STORE_POINTER(D_0025AE10, entity_draw_layer1);
    STORE_POINTER(D_0025AE10 + 2, entity_draw_layer1);
    STORE_POINTER(D_0025AE10 + 4, entity_draw_layer2);
    STORE_POINTER(D_0025AE10 + 6, entity_draw_layer3);
    STORE_POINTER(D_0025AE10 + 8, entity_draw_layer4);
    STORE_POINTER(D_0025AE10 + 10, entity_draw_layer5);
    STORE_POINTER(D_0025AE10 + 16, entity_draw_layer1_keep);
    STORE_POINTER(D_0025AE10 + 18, entity_draw_layer1_keep);
    STORE_POINTER(D_0025AE10 + 20, entity_draw_layer2_keep);
    STORE_POINTER(D_0025AE10 + 22, entity_draw_layer3_keep);
    STORE_POINTER(D_0025AE10 + 24, entity_draw_layer4_keep);
    STORE_POINTER(D_0025AE10 + 26, entity_draw_layer5_keep);
    STORE_POINTER(D_0025AE50, entity_draw_layer1_zoom);
    STORE_POINTER(D_0025AE50 + 2, entity_draw_layer1_zoom);
    STORE_POINTER(D_0025AE50 + 4, entity_draw_layer2_zoom);
    STORE_POINTER(D_0025AE50 + 6, entity_draw_layer3_zoom);
    STORE_POINTER(D_0025AE50 + 8, entity_draw_layer4_zoom);
    STORE_POINTER(D_0025AE50 + 10, entity_draw_layer5_zoom);
    STORE_POINTER(D_0025AE70, sprite_draw_layer1);
    STORE_POINTER(D_0025AE70 + 2, sprite_draw_layer1);
    STORE_POINTER(D_0025AE70 + 4, sprite_draw_layer2);
    STORE_POINTER(D_0025AE70 + 6, sprite_draw_layer3);
    STORE_POINTER(D_0025AE70 + 8, sprite_draw_layer4);
    STORE_POINTER(D_0025AE70 + 10, sprite_draw_layer5);
    STORE_POINTER(D_0025AE70 + 16, sprite_draw_layer1_keep);
    STORE_POINTER(D_0025AE70 + 18, sprite_draw_layer1_keep);
    STORE_POINTER(D_0025AE70 + 20, sprite_draw_layer2_keep);
    STORE_POINTER(D_0025AE70 + 22, sprite_draw_layer3_keep);
    STORE_POINTER(D_0025AE70 + 24, sprite_draw_layer4_keep);
    STORE_POINTER(D_0025AE70 + 26, sprite_draw_layer5_keep);
}

extern u16 g_stage2_map_palettes[];
extern u16 D_002469D0[];
extern u16 D_00246A10[];
extern u16 D_00246A50[];
extern u16 D_00246A90[];
extern u16 D_00246AD0[];
extern u16 D_00246B10[];
extern u16 D_00246B50[];
extern u16 D_00246B90[];
extern u16 D_00246BD0[];
extern u16 D_00246C10[];
extern u16 D_00260270[];
extern u16 D_002602B0[];
extern u16 D_002602F0[];


void pointers_store_part_8(void) {
    STORE_POINTER(D_00263030 + 48, D_0028C0C8);
    STORE_POINTER(D_00263030 + 56, D_0028C0C8);
    STORE_POINTER(D_00263030 + 64, large_tank_entities_at_47);
    STORE_POINTER(D_00263030 + 72, large_tank_entities_at_47);
    STORE_POINTER(D_002630D0 + 4, D_00260270);
    STORE_POINTER(D_002630D0 + 11, D_002602B0);
    STORE_POINTER(D_002630D0 + 18, D_002602F0);
    STORE_POINTER(D_00263290 + 4, D_002610F0);
    STORE_POINTER(D_00263290 + 11, D_00260270);
    STORE_POINTER(D_00263290 + 18, D_002602B0);
    STORE_POINTER(D_00263290 + 25, D_002602F0);
    STORE_POINTER(D_00263290 + 32, g_stage2_map_palettes);
    STORE_POINTER(D_00263290 + 39, D_002469D0);
    STORE_POINTER(D_00263290 + 46, D_00246A10);
    STORE_POINTER(D_00263290 + 53, D_00246A50);
    STORE_POINTER(D_00263290 + 60, D_00246A90);
    STORE_POINTER(D_00263290 + 67, D_00246AD0);
    STORE_POINTER(D_00263290 + 74, D_00246B10);
    STORE_POINTER(D_00263290 + 81, D_00246B50);
    STORE_POINTER(D_00263290 + 88, D_00246B90);
    STORE_POINTER(D_00263290 + 95, D_00246BD0);
    STORE_POINTER(D_00263290 + 102, D_00246C10);
}

extern u16 D_00249E10[];
extern u16 D_00249E50[];
extern u16 stage4_boss_flash_palettes_at_11[];
extern u8 stage4_heavy_cannon_start_table[];
extern u8 stage4_wave_cannon_table[];
extern u8 stage4_heavy_cannon_start_table_2[];
extern u8 stage4_heavy_cannon_start_table_3[];
extern u8 stage4_wave_cannon_start_table[];
extern u8 stage4_gate_start_table[];
extern u16 stage4_scroll_palettes_at_54[];
extern u16 stage4_scroll_palettes_at_63[];
extern u16 D_00263AE0[];
extern u16 D_00263B10[];
extern u16 D_00263B30[];


void pointers_store_part_9(void) {
    STORE_POINTER(D_002638B0 + 47, D_0028C0C8);
    STORE_POINTER(D_002638B0 + 54, D_0028C0C8);
    STORE_POINTER(D_002638B0 + 61, large_tank_entities_at_47);
    STORE_POINTER(D_002638B0 + 68, large_tank_entities_at_47);
    STORE_POINTER(D_002639B0 + 4, D_002610F0);
    STORE_POINTER(D_002639B0 + 11, ((u16 *)stage4_heavy_cannon_start_table));
    STORE_POINTER(D_002639B0 + 18, ((u16 *)stage4_heavy_cannon_start_table_2));
    STORE_POINTER(D_002639B0 + 25, ((u16 *)stage4_heavy_cannon_start_table_3));
    STORE_POINTER(D_002639B0 + 32, ((u16 *)stage4_gate_start_table));
    STORE_POINTER(D_002639B0 + 39, stage4_scroll_palettes_at_54);
    STORE_POINTER(D_002639B0 + 46, D_00249E10);
    STORE_POINTER(D_002639B0 + 53, D_00249E50);
    STORE_POINTER(D_00263A50 + 64, D_00263AE0);
    STORE_POINTER(D_00263A50 + 66, D_00263B10);
    STORE_POINTER(D_00263A50 + 68, D_00263B30);
    STORE_POINTER(D_00263B80 + 47, D_0028C0C8);
    STORE_POINTER(D_00263B80 + 54, D_0028C0C8);
    STORE_POINTER(D_00263B80 + 61, large_tank_entities_at_47);
    STORE_POINTER(D_00263B80 + 68, large_tank_entities_at_47);
    STORE_POINTER(D_00263C70 + 3, ((u16 *)stage4_wave_cannon_table));
    STORE_POINTER(D_00263C80 + 3, D_00261D30);
    STORE_POINTER(D_00263C90 + 4, D_002610F0);
    STORE_POINTER(D_00263C90 + 11, ((u16 *)stage4_wave_cannon_table));
    STORE_POINTER(D_00263C90 + 18, D_00249E50);
    STORE_POINTER(D_00263C90 + 25, stage4_boss_flash_palettes_at_11);
    STORE_POINTER(D_00263C90 + 32, ((u16 *)stage4_gate_start_table));
    STORE_POINTER(D_00263C90 + 39, stage4_scroll_palettes_at_63);
    STORE_POINTER(D_00263CF0 + 4, ((u16 *)stage4_wave_cannon_start_table));
}

extern u16 D_002420C0[];
extern u16 D_002420D0[];
extern u16 D_002420E0[];


void pointers_store_part_10(void) {
    STORE_POINTER(D_00242020 + 20, entity_draw_layer1);
    STORE_POINTER(D_00242020 + 22, sprite_draw_layer1);
    STORE_POINTER(D_00242070 + 20, entity_draw_layer1);
    STORE_POINTER(D_00242070 + 22, sprite_draw_layer1);
    STORE_POINTER(((u16 *)D_002420A8), D_002420C0);
    STORE_POINTER(D_002420A8 + 2, D_002420D0);
    STORE_POINTER(D_002420A8 + 4, D_002420E0);
}

void pointers_store_part_11(void) {
}


extern u16 option_shot_list_1_01_00_02[];
extern u16 D_0025D800[];
extern u16 option_shot_list_4_01_00_02[];
extern u16 option_shot_list_1_01_00_07[];
extern u16 player_shot_7_flight_028_01[];
extern u16 player_shot_7_flight_048_01[];
extern u16 player_shot_7_flight_068_01[];
extern u16 player_shot_7_flight_088_01[];
extern u16 player_shot_7_direction_5_00_01[];
extern u16 option_shot_list_4_01_00_07[];
extern u16 player_shot_7_impact_frames_00[];
extern u16 player_shot_7_impact_frames_02[];
extern u16 player_shot_7_impact_frames_06[];
extern u16 player_shot_7_impact_frames_10[];
extern u16 player_shot_7_impact_frames_11[];
extern u16 player_shot_7_impact_frames_13[];
extern u16 player_shot_7_impact_frames_15[];
extern u16 player_shot_7_impact_frames_17[];
extern u16 player_shot_7_impact_frames_21[];
extern u16 player_shot_7_directions_5[];
extern u16 player_shot_7_impact_00[];
extern u16 player_shot_7_impact_02[];
extern u16 player_shot_7_impact_04[];
extern u16 player_shot_7_impact_06[];
extern u16 player_shot_7_impact_08[];
extern u16 player_shot_7_impact_10[];
extern u16 player_shot_7_impact_11[];
extern u16 player_shot_7_impact_12[];
extern u16 player_shot_7_impact_13[];
extern u16 player_shot_7_impact_14[];
extern u16 player_shot_7_impact_15[];
extern u16 player_shot_7_impact_17[];
extern u16 player_shot_7_impact_19[];
extern u16 player_shot_7_impact_21[];
extern u16 player_shot_7_impact_23[];
extern u16 player_shot_7_flight_000[];
extern u16 player_shot_7_flight_002[];
extern u16 player_shot_7_flight_004[];
extern u16 player_shot_7_flight_006[];
extern u16 player_shot_7_flight_008[];
extern u16 player_shot_7_flight_010[];
extern u16 player_shot_7_flight_011[];
extern u16 player_shot_7_flight_012[];
extern u16 player_shot_7_flight_013[];
extern u16 player_shot_7_flight_014[];
extern u16 player_shot_7_flight_015[];
extern u16 player_shot_7_flight_017[];
extern u16 player_shot_7_flight_019[];
extern u16 player_shot_7_flight_021[];
extern u16 player_shot_7_flight_023[];
extern u16 player_shot_7_flight_028[];
extern u16 player_shot_7_flight_029[];
extern u16 player_shot_7_flight_030[];
extern u16 player_shot_7_flight_031[];
extern u16 player_shot_7_flight_032[];
extern u16 player_shot_7_flight_033[];
extern u16 player_shot_7_flight_034[];
extern u16 player_shot_7_flight_035[];
extern u16 player_shot_7_flight_036[];
extern u16 player_shot_7_flight_037[];
extern u16 player_shot_7_flight_038[];
extern u16 player_shot_7_flight_039[];
extern u16 player_shot_7_flight_040[];
extern u16 player_shot_7_flight_041[];
extern u16 player_shot_7_flight_042[];
extern u16 player_shot_7_flight_043[];
extern u16 player_shot_7_flight_044[];
extern u16 player_shot_7_flight_048[];
extern u16 player_shot_7_flight_049[];
extern u16 player_shot_7_flight_050[];
extern u16 player_shot_7_flight_051[];
extern u16 player_shot_7_flight_052[];
extern u16 player_shot_7_flight_053[];
extern u16 player_shot_7_flight_054[];
extern u16 player_shot_7_flight_055[];
extern u16 player_shot_7_flight_056[];
extern u16 player_shot_7_flight_057[];
extern u16 player_shot_7_flight_058[];
extern u16 player_shot_7_flight_059[];
extern u16 player_shot_7_flight_060[];
extern u16 player_shot_7_flight_061[];
extern u16 player_shot_7_flight_062[];
extern u16 player_shot_7_flight_063[];
extern u16 player_shot_7_flight_064[];
extern u16 player_shot_7_flight_068[];
extern u16 player_shot_7_flight_069[];
extern u16 player_shot_7_flight_070[];
extern u16 player_shot_7_flight_071[];
extern u16 player_shot_7_flight_072[];
extern u16 player_shot_7_flight_073[];
extern u16 player_shot_7_flight_074[];
extern u16 player_shot_7_flight_075[];
extern u16 player_shot_7_flight_076[];
extern u16 player_shot_7_flight_077[];
extern u16 player_shot_7_flight_078[];
extern u16 player_shot_7_flight_079[];
extern u16 player_shot_7_flight_080[];
extern u16 player_shot_7_flight_081[];
extern u16 player_shot_7_flight_082[];
extern u16 player_shot_7_flight_083[];
extern u16 player_shot_7_flight_084[];
extern u16 player_shot_7_flight_088[];
extern u16 player_shot_7_flight_089[];
extern u16 player_shot_7_flight_090[];
extern u16 player_shot_7_flight_091[];
extern u16 player_shot_7_flight_092[];
extern u16 player_shot_7_flight_093[];
extern u16 player_shot_7_flight_094[];
extern u16 player_shot_7_flight_095[];
extern u16 player_shot_7_flight_096[];
extern u16 player_shot_7_flight_097[];
extern u16 player_shot_7_flight_098[];
extern u16 player_shot_7_flight_099[];
extern u16 player_shot_7_flight_100[];
extern u16 player_shot_7_flight_101[];
extern u16 player_shot_7_flight_102[];
extern u16 player_shot_7_flight_103[];
extern u16 player_shot_7_flight_104[];
extern u16 player_shot_7_direction_5_00[];
extern u16 player_shot_7_direction_5_01[];
extern u16 player_shot_7_direction_5_02[];
extern u16 player_shot_7_direction_5_03[];
extern u16 player_shot_7_direction_5_04[];
extern u16 player_shot_7_direction_5_05[];
extern u16 player_shot_7_direction_5_06[];
extern u16 player_shot_7_direction_5_07[];
extern u16 player_shot_7_direction_5_08[];
extern u16 player_shot_7_direction_5_09[];
extern u16 player_shot_7_direction_5_10[];
extern u16 player_shot_7_direction_5_11[];
extern u16 player_shot_7_direction_5_12[];
extern u16 player_shot_7_direction_5_13[];
extern u16 player_shot_7_direction_5_14[];
extern u16 player_shot_7_direction_5_15[];
extern u16 player_shot_7_direction_5_16[];

extern u16 D_0025DB94[];
extern u16 D_0025DBC4[];
extern u16 D_0025DBF4[];
extern u16 D_0025DC24[];
extern u16 D_0025DC54[];
extern u16 player_shot_7_flight_table[];
extern u16 player_shot_7_impact_table[];

void player_shot_7_tables_init(void) {
    if (option_shot_list_1_01_00[5] != 0x5) {
        printf("error! hoshot_a_sh_r_p1[5]\n");
    }
    STORE_POINTER(option_shot_list_1_01_00 + 5, option_shot_list_1_01_00_02);
    if (option_shot_list_1_01_00[15] != 0xf) {
        printf("error! hoshot_a_sh_r_p1[15]\n");
    }
    STORE_POINTER(option_shot_list_1_01_00 + 15, option_shot_list_1_01_00_07);
    if (option_shot_list_2_01_00[5] != 0x5) {
        printf("error! hoshot_a_sh_l_p1[5]\n");
    }
    STORE_POINTER(option_shot_list_2_01_00 + 5, option_shot_list_1_01_00_02);
    if (option_shot_list_2_01_00[15] != 0xf) {
        printf("error! hoshot_a_sh_l_p1[15]\n");
    }
    STORE_POINTER(option_shot_list_2_01_00 + 15, option_shot_list_1_01_00_07);
    if (option_shot_list_1_01_01[5] != 0x5) {
        printf("error! hoshot_a_sh_r_p2[5]\n");
    }
    STORE_POINTER(option_shot_list_1_01_01 + 5, option_shot_list_1_01_00_02);
    if (option_shot_list_1_01_01[15] != 0xf) {
        printf("error! hoshot_a_sh_r_p2[15]\n");
    }
    STORE_POINTER(option_shot_list_1_01_01 + 15, option_shot_list_1_01_00_07);
    if (option_shot_list_2_01_01[5] != 0x5) {
        printf("error! hoshot_a_sh_l_p2[5]\n");
    }
    STORE_POINTER(option_shot_list_2_01_01 + 5, option_shot_list_1_01_00_02);
    if (option_shot_list_2_01_01[15] != 0xf) {
        printf("error! hoshot_a_sh_l_p2[15]\n");
    }
    STORE_POINTER(option_shot_list_2_01_01 + 15, option_shot_list_1_01_00_07);
    if (option_shot_list_1_01_02[5] != 0x5) {
        printf("error! hoshot_a_sh_r_p3[5]\n");
    }
    STORE_POINTER(option_shot_list_1_01_02 + 5, option_shot_list_1_01_00_02);
    if (option_shot_list_1_01_02[15] != 0xf) {
        printf("error! hoshot_a_sh_r_p3[15]\n");
    }
    STORE_POINTER(option_shot_list_1_01_02 + 15, option_shot_list_1_01_00_07);
    if (option_shot_list_2_01_02[5] != 0x5) {
        printf("error! hoshot_a_sh_l_p3[5]\n");
    }
    STORE_POINTER(option_shot_list_2_01_02 + 5, option_shot_list_1_01_00_02);
    if (option_shot_list_2_01_02[15] != 0xf) {
        printf("error! hoshot_a_sh_l_p3[15]\n");
    }
    STORE_POINTER(option_shot_list_2_01_02 + 15, option_shot_list_1_01_00_07);
    if (option_shot_list_1_01_03[5] != 0x5) {
        printf("error! hoshot_a_sh_r_p4[5]\n");
    }
    STORE_POINTER(option_shot_list_1_01_03 + 5, option_shot_list_1_01_00_02);
    if (option_shot_list_1_01_03[15] != 0xf) {
        printf("error! hoshot_a_sh_r_p4[15]\n");
    }
    STORE_POINTER(option_shot_list_1_01_03 + 15, option_shot_list_1_01_00_07);
    if (option_shot_list_2_01_03[5] != 0x5) {
        printf("error! hoshot_a_sh_l_p4[5]\n");
    }
    STORE_POINTER(option_shot_list_2_01_03 + 5, option_shot_list_1_01_00_02);
    if (option_shot_list_2_01_03[15] != 0xf) {
        printf("error! hoshot_a_sh_l_p4[15]\n");
    }
    STORE_POINTER(option_shot_list_2_01_03 + 15, option_shot_list_1_01_00_07);
    if (option_shot_list_1_01_04[5] != 0x5) {
        printf("error! hoshot_a_sh_r_p5[5]\n");
    }
    STORE_POINTER(option_shot_list_1_01_04 + 5, option_shot_list_1_01_00_02);
    if (option_shot_list_1_01_04[15] != 0xf) {
        printf("error! hoshot_a_sh_r_p5[15]\n");
    }
    STORE_POINTER(option_shot_list_1_01_04 + 15, option_shot_list_1_01_00_07);
    if (option_shot_list_2_01_04[5] != 0x5) {
        printf("error! hoshot_a_sh_l_p5[5]\n");
    }
    STORE_POINTER(option_shot_list_2_01_04 + 5, option_shot_list_1_01_00_02);
    if (option_shot_list_2_01_04[15] != 0xf) {
        printf("error! hoshot_a_sh_l_p5[15]\n");
    }
    STORE_POINTER(option_shot_list_2_01_04 + 15, option_shot_list_1_01_00_07);
    if (option_shot_list_3_01_00[1] != 0x1) {
        printf("error! hoshot_a_la_p1[1]\n");
    }
    STORE_POINTER(option_shot_list_3_01_00 + 1, player_shot_7_directions_5);
    if (D_0025DB94[3] != 0x5) {
        printf("error! hoshot_a_la_p1[5]\n");
    }
    STORE_POINTER(D_0025DB94 + 3, D_0025D800);
    if (option_shot_list_3_01_01[1] != 0x1) {
        printf("error! hoshot_a_la_p2[1]\n");
    }
    STORE_POINTER(option_shot_list_3_01_01 + 1, player_shot_7_directions_5);
    if (D_0025DBC4[3] != 0x5) {
        printf("error! hoshot_a_la_p2[5]\n");
    }
    STORE_POINTER(D_0025DBC4 + 3, D_0025D800);
    if (option_shot_list_3_01_02[1] != 0x1) {
        printf("error! hoshot_a_la_p3[1]\n");
    }
    STORE_POINTER(option_shot_list_3_01_02 + 1, player_shot_7_directions_5);
    if (D_0025DBF4[3] != 0x5) {
        printf("error! hoshot_a_la_p3[5]\n");
    }
    STORE_POINTER(D_0025DBF4 + 3, D_0025D800);
    if (option_shot_list_3_01_03[1] != 0x1) {
        printf("error! hoshot_a_la_p4[1]\n");
    }
    STORE_POINTER(option_shot_list_3_01_03 + 1, player_shot_7_directions_5);
    if (D_0025DC24[3] != 0x5) {
        printf("error! hoshot_a_la_p4[5]\n");
    }
    STORE_POINTER(D_0025DC24 + 3, D_0025D800);
    if (option_shot_list_3_01_04[1] != 0x1) {
        printf("error! hoshot_a_la_p5[1]\n");
    }
    STORE_POINTER(option_shot_list_3_01_04 + 1, player_shot_7_directions_5);
    if (D_0025DC54[3] != 0x5) {
        printf("error! hoshot_a_la_p5[5]\n");
    }
    STORE_POINTER(D_0025DC54 + 3, D_0025D800);
    if (option_shot_list_4_01_00[5] != 0x5) {
        printf("error! hoshot_a_ex_p1[5]\n");
    }
    STORE_POINTER(option_shot_list_4_01_00 + 5, option_shot_list_4_01_00_02);
    if (option_shot_list_4_01_00[15] != 0xf) {
        printf("error! hoshot_a_ex_p1[15]\n");
    }
    STORE_POINTER(option_shot_list_4_01_00 + 15, option_shot_list_4_01_00_07);
    if (option_shot_list_4_01_00[24] != 0x18) {
        printf("error! hoshot_a_ex_p1[24]\n");
    }
    STORE_POINTER(option_shot_list_4_01_00 + 24, option_shot_list_4_01_00_02);
    if (option_shot_list_4_01_00[34] != 0x22) {
        printf("error! hoshot_a_ex_p1[34]\n");
    }
    STORE_POINTER(option_shot_list_4_01_00 + 34, option_shot_list_4_01_00_07);
    if (option_shot_list_4_01_01[5] != 0x5) {
        printf("error! hoshot_a_ex_p2[5]\n");
    }
    STORE_POINTER(option_shot_list_4_01_01 + 5, option_shot_list_4_01_00_02);
    if (option_shot_list_4_01_01[15] != 0xf) {
        printf("error! hoshot_a_ex_p2[15]\n");
    }
    STORE_POINTER(option_shot_list_4_01_01 + 15, option_shot_list_4_01_00_07);
    if (option_shot_list_4_01_01[24] != 0x18) {
        printf("error! hoshot_a_ex_p2[24]\n");
    }
    STORE_POINTER(option_shot_list_4_01_01 + 24, option_shot_list_4_01_00_02);
    if (option_shot_list_4_01_01[34] != 0x22) {
        printf("error! hoshot_a_ex_p2[34]\n");
    }
    STORE_POINTER(option_shot_list_4_01_01 + 34, option_shot_list_4_01_00_07);
    if (option_shot_list_4_01_02[5] != 0x5) {
        printf("error! hoshot_a_ex_p3[5]\n");
    }
    STORE_POINTER(option_shot_list_4_01_02 + 5, option_shot_list_4_01_00_02);
    if (option_shot_list_4_01_02[15] != 0xf) {
        printf("error! hoshot_a_ex_p3[15]\n");
    }
    STORE_POINTER(option_shot_list_4_01_02 + 15, option_shot_list_4_01_00_07);
    if (option_shot_list_4_01_02[24] != 0x18) {
        printf("error! hoshot_a_ex_p3[24]\n");
    }
    STORE_POINTER(option_shot_list_4_01_02 + 24, option_shot_list_4_01_00_02);
    if (option_shot_list_4_01_02[34] != 0x22) {
        printf("error! hoshot_a_ex_p3[34]\n");
    }
    STORE_POINTER(option_shot_list_4_01_02 + 34, option_shot_list_4_01_00_07);
    if (option_shot_list_4_01_03[5] != 0x5) {
        printf("error! hoshot_a_ex_p4[5]\n");
    }
    STORE_POINTER(option_shot_list_4_01_03 + 5, option_shot_list_4_01_00_02);
    if (option_shot_list_4_01_03[15] != 0xf) {
        printf("error! hoshot_a_ex_p4[15]\n");
    }
    STORE_POINTER(option_shot_list_4_01_03 + 15, option_shot_list_4_01_00_07);
    if (option_shot_list_4_01_03[24] != 0x18) {
        printf("error! hoshot_a_ex_p4[24]\n");
    }
    STORE_POINTER(option_shot_list_4_01_03 + 24, option_shot_list_4_01_00_02);
    if (option_shot_list_4_01_03[34] != 0x22) {
        printf("error! hoshot_a_ex_p4[34]\n");
    }
    STORE_POINTER(option_shot_list_4_01_03 + 34, option_shot_list_4_01_00_07);
    if (option_shot_list_4_01_04[5] != 0x5) {
        printf("error! hoshot_a_ex_p5[5]\n");
    }
    STORE_POINTER(option_shot_list_4_01_04 + 5, option_shot_list_4_01_00_02);
    if (option_shot_list_4_01_04[15] != 0xf) {
        printf("error! hoshot_a_ex_p5[15]\n");
    }
    STORE_POINTER(option_shot_list_4_01_04 + 15, option_shot_list_4_01_00_07);
    if (option_shot_list_4_01_04[24] != 0x18) {
        printf("error! hoshot_a_ex_p5[24]\n");
    }
    STORE_POINTER(option_shot_list_4_01_04 + 24, option_shot_list_4_01_00_02);
    if (option_shot_list_4_01_04[34] != 0x22) {
        printf("error! hoshot_a_ex_p5[34]\n");
    }
    STORE_POINTER(option_shot_list_4_01_04 + 34, option_shot_list_4_01_00_07);
    if (player_shot_7_flight_table[0] != 0x0) {
        printf("error! hoa_data[0]\n");
    }
    STORE_POINTER(player_shot_7_flight_table, player_shot_7_flight_000);
    if (player_shot_7_flight_table[2] != 0x2) {
        printf("error! hoa_data[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 2, player_shot_7_flight_000);
    if (player_shot_7_flight_table[4] != 0x4) {
        printf("error! hoa_data[4]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 4, player_shot_7_flight_002);
    if (player_shot_7_flight_table[6] != 0x6) {
        printf("error! hoa_data[6]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 6, player_shot_7_flight_002);
    if (player_shot_7_flight_table[8] != 0x8) {
        printf("error! hoa_data[8]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 8, player_shot_7_flight_004);
    if (player_shot_7_flight_table[10] != 0xa) {
        printf("error! hoa_data[10]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 10, player_shot_7_flight_004);
    if (player_shot_7_flight_table[12] != 0xc) {
        printf("error! hoa_data[12]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 12, player_shot_7_flight_006);
    if (player_shot_7_flight_table[14] != 0xe) {
        printf("error! hoa_data[14]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 14, player_shot_7_flight_006);
    if (player_shot_7_flight_table[16] != 0x10) {
        printf("error! hoa_data[16]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 16, player_shot_7_flight_008);
    if (player_shot_7_flight_table[18] != 0x12) {
        printf("error! hoa_data[18]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 18, player_shot_7_flight_008);
    if (player_shot_7_flight_table[20] != 0x14) {
        printf("error! hoa_data[20]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 20, player_shot_7_flight_010);
    if (player_shot_7_flight_table[22] != 0x16) {
        printf("error! hoa_data[22]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 22, player_shot_7_flight_011);
    if (player_shot_7_flight_table[24] != 0x18) {
        printf("error! hoa_data[24]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 24, player_shot_7_flight_012);
    if (player_shot_7_flight_table[26] != 0x1a) {
        printf("error! hoa_data[26]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 26, player_shot_7_flight_013);
    if (player_shot_7_flight_table[28] != 0x1c) {
        printf("error! hoa_data[28]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 28, player_shot_7_flight_014);
    if (player_shot_7_flight_table[30] != 0x1e) {
        printf("error! hoa_data[30]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 30, player_shot_7_flight_015);
    if (player_shot_7_flight_table[32] != 0x20) {
        printf("error! hoa_data[32]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 32, player_shot_7_flight_015);
    if (player_shot_7_flight_table[34] != 0x22) {
        printf("error! hoa_data[34]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 34, player_shot_7_flight_017);
    if (player_shot_7_flight_table[36] != 0x24) {
        printf("error! hoa_data[36]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 36, player_shot_7_flight_017);
    if (player_shot_7_flight_table[38] != 0x26) {
        printf("error! hoa_data[38]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 38, player_shot_7_flight_019);
    if (player_shot_7_flight_table[40] != 0x28) {
        printf("error! hoa_data[40]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 40, player_shot_7_flight_019);
    if (player_shot_7_flight_table[42] != 0x2a) {
        printf("error! hoa_data[42]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 42, player_shot_7_flight_021);
    if (player_shot_7_flight_table[44] != 0x2c) {
        printf("error! hoa_data[44]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 44, player_shot_7_flight_021);
    if (player_shot_7_flight_table[46] != 0x2e) {
        printf("error! hoa_data[46]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 46, player_shot_7_flight_023);
    if (player_shot_7_flight_table[48] != 0x30) {
        printf("error! hoa_data[48]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 48, player_shot_7_flight_023);
    if (player_shot_7_flight_table[56] != 0x0) {
        printf("error! hopt_la_a1_shdip[0]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 56, player_shot_7_flight_028);
    if (player_shot_7_flight_table[58] != 0x2) {
        printf("error! hopt_la_a1_shdip[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 58, player_shot_7_flight_029);
    if (player_shot_7_flight_table[60] != 0x4) {
        printf("error! hopt_la_a1_shdip[4]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 60, player_shot_7_flight_030);
    if (player_shot_7_flight_table[62] != 0x6) {
        printf("error! hopt_la_a1_shdip[6]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 62, player_shot_7_flight_031);
    if (player_shot_7_flight_table[64] != 0x8) {
        printf("error! hopt_la_a1_shdip[8]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 64, player_shot_7_flight_032);
    if (player_shot_7_flight_table[66] != 0xa) {
        printf("error! hopt_la_a1_shdip[10]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 66, player_shot_7_flight_033);
    if (player_shot_7_flight_table[68] != 0xc) {
        printf("error! hopt_la_a1_shdip[12]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 68, player_shot_7_flight_034);
    if (player_shot_7_flight_table[70] != 0xe) {
        printf("error! hopt_la_a1_shdip[14]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 70, player_shot_7_flight_035);
    if (player_shot_7_flight_table[72] != 0x10) {
        printf("error! hopt_la_a1_shdip[16]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 72, player_shot_7_flight_036);
    if (player_shot_7_flight_table[74] != 0x12) {
        printf("error! hopt_la_a1_shdip[18]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 74, player_shot_7_flight_037);
    if (player_shot_7_flight_table[76] != 0x14) {
        printf("error! hopt_la_a1_shdip[20]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 76, player_shot_7_flight_038);
    if (player_shot_7_flight_table[78] != 0x16) {
        printf("error! hopt_la_a1_shdip[22]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 78, player_shot_7_flight_039);
    if (player_shot_7_flight_table[80] != 0x18) {
        printf("error! hopt_la_a1_shdip[24]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 80, player_shot_7_flight_040);
    if (player_shot_7_flight_table[82] != 0x1a) {
        printf("error! hopt_la_a1_shdip[26]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 82, player_shot_7_flight_041);
    if (player_shot_7_flight_table[84] != 0x1c) {
        printf("error! hopt_la_a1_shdip[28]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 84, player_shot_7_flight_042);
    if (player_shot_7_flight_table[86] != 0x1e) {
        printf("error! hopt_la_a1_shdip[30]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 86, player_shot_7_flight_043);
    if (player_shot_7_flight_table[88] != 0x20) {
        printf("error! hopt_la_a1_shdip[32]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 88, player_shot_7_flight_044);
    if (player_shot_7_flight_028[2] != 0x2) {
        printf("error! hop_la_a1_d00[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_028 + 2, player_shot_7_flight_028_01);
    if (player_shot_7_flight_029[2] != 0x2) {
        printf("error! hop_la_a1_d02[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_029 + 2, player_shot_7_flight_028_01);
    if (player_shot_7_flight_030[2] != 0x2) {
        printf("error! hop_la_a1_d04[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_030 + 2, player_shot_7_flight_028_01);
    if (player_shot_7_flight_031[2] != 0x2) {
        printf("error! hop_la_a1_d06[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_031 + 2, player_shot_7_flight_028_01);
    if (player_shot_7_flight_032[2] != 0x2) {
        printf("error! hop_la_a1_d08[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_032 + 2, player_shot_7_flight_028_01);
    if (player_shot_7_flight_033[2] != 0x2) {
        printf("error! hop_la_a1_d0a[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_033 + 2, player_shot_7_flight_028_01);
    if (player_shot_7_flight_034[2] != 0x2) {
        printf("error! hop_la_a1_d0c[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_034 + 2, player_shot_7_flight_028_01);
    if (player_shot_7_flight_035[2] != 0x2) {
        printf("error! hop_la_a1_d0e[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_035 + 2, player_shot_7_flight_028_01);
    if (player_shot_7_flight_036[2] != 0x2) {
        printf("error! hop_la_a1_d10[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_036 + 2, player_shot_7_flight_028_01);
    if (player_shot_7_flight_037[2] != 0x2) {
        printf("error! hop_la_a1_d12[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_037 + 2, player_shot_7_flight_028_01);
    if (player_shot_7_flight_038[2] != 0x2) {
        printf("error! hop_la_a1_d14[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_038 + 2, player_shot_7_flight_028_01);
    if (player_shot_7_flight_039[2] != 0x2) {
        printf("error! hop_la_a1_d16[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_039 + 2, player_shot_7_flight_028_01);
    if (player_shot_7_flight_040[2] != 0x2) {
        printf("error! hop_la_a1_d18[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_040 + 2, player_shot_7_flight_028_01);
    if (player_shot_7_flight_041[2] != 0x2) {
        printf("error! hop_la_a1_d1a[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_041 + 2, player_shot_7_flight_028_01);
    if (player_shot_7_flight_042[2] != 0x2) {
        printf("error! hop_la_a1_d1c[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_042 + 2, player_shot_7_flight_028_01);
    if (player_shot_7_flight_043[2] != 0x2) {
        printf("error! hop_la_a1_d1e[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_043 + 2, player_shot_7_flight_028_01);
    if (player_shot_7_flight_044[2] != 0x2) {
        printf("error! hop_la_a1_d20[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_044 + 2, player_shot_7_flight_028_01);
    if (player_shot_7_flight_table[96] != 0x0) {
        printf("error! hopt_la_a2_shdip[0]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 96, player_shot_7_flight_048);
    if (player_shot_7_flight_table[98] != 0x2) {
        printf("error! hopt_la_a2_shdip[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 98, player_shot_7_flight_049);
    if (player_shot_7_flight_table[100] != 0x4) {
        printf("error! hopt_la_a2_shdip[4]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 100, player_shot_7_flight_050);
    if (player_shot_7_flight_table[102] != 0x6) {
        printf("error! hopt_la_a2_shdip[6]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 102, player_shot_7_flight_051);
    if (player_shot_7_flight_table[104] != 0x8) {
        printf("error! hopt_la_a2_shdip[8]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 104, player_shot_7_flight_052);
    if (player_shot_7_flight_table[106] != 0xa) {
        printf("error! hopt_la_a2_shdip[10]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 106, player_shot_7_flight_053);
    if (player_shot_7_flight_table[108] != 0xc) {
        printf("error! hopt_la_a2_shdip[12]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 108, player_shot_7_flight_054);
    if (player_shot_7_flight_table[110] != 0xe) {
        printf("error! hopt_la_a2_shdip[14]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 110, player_shot_7_flight_055);
    if (player_shot_7_flight_table[112] != 0x10) {
        printf("error! hopt_la_a2_shdip[16]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 112, player_shot_7_flight_056);
    if (player_shot_7_flight_table[114] != 0x12) {
        printf("error! hopt_la_a2_shdip[18]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 114, player_shot_7_flight_057);
    if (player_shot_7_flight_table[116] != 0x14) {
        printf("error! hopt_la_a2_shdip[20]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 116, player_shot_7_flight_058);
    if (player_shot_7_flight_table[118] != 0x16) {
        printf("error! hopt_la_a2_shdip[22]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 118, player_shot_7_flight_059);
    if (player_shot_7_flight_table[120] != 0x18) {
        printf("error! hopt_la_a2_shdip[24]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 120, player_shot_7_flight_060);
    if (player_shot_7_flight_table[122] != 0x1a) {
        printf("error! hopt_la_a2_shdip[26]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 122, player_shot_7_flight_061);
    if (player_shot_7_flight_table[124] != 0x1c) {
        printf("error! hopt_la_a2_shdip[28]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 124, player_shot_7_flight_062);
    if (player_shot_7_flight_table[126] != 0x1e) {
        printf("error! hopt_la_a2_shdip[30]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 126, player_shot_7_flight_063);
    if (player_shot_7_flight_table[128] != 0x20) {
        printf("error! hopt_la_a2_shdip[32]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 128, player_shot_7_flight_064);
    if (player_shot_7_flight_048[2] != 0x2) {
        printf("error! hop_la_a2_d00[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_048 + 2, player_shot_7_flight_048_01);
    if (player_shot_7_flight_049[2] != 0x2) {
        printf("error! hop_la_a2_d02[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_049 + 2, player_shot_7_flight_048_01);
    if (player_shot_7_flight_050[2] != 0x2) {
        printf("error! hop_la_a2_d04[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_050 + 2, player_shot_7_flight_048_01);
    if (player_shot_7_flight_051[2] != 0x2) {
        printf("error! hop_la_a2_d06[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_051 + 2, player_shot_7_flight_048_01);
    if (player_shot_7_flight_052[2] != 0x2) {
        printf("error! hop_la_a2_d08[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_052 + 2, player_shot_7_flight_048_01);
    if (player_shot_7_flight_053[2] != 0x2) {
        printf("error! hop_la_a2_d0a[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_053 + 2, player_shot_7_flight_048_01);
    if (player_shot_7_flight_054[2] != 0x2) {
        printf("error! hop_la_a2_d0c[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_054 + 2, player_shot_7_flight_048_01);
    if (player_shot_7_flight_055[2] != 0x2) {
        printf("error! hop_la_a2_d0e[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_055 + 2, player_shot_7_flight_048_01);
    if (player_shot_7_flight_056[2] != 0x2) {
        printf("error! hop_la_a2_d10[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_056 + 2, player_shot_7_flight_048_01);
    if (player_shot_7_flight_057[2] != 0x2) {
        printf("error! hop_la_a2_d12[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_057 + 2, player_shot_7_flight_048_01);
    if (player_shot_7_flight_058[2] != 0x2) {
        printf("error! hop_la_a2_d14[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_058 + 2, player_shot_7_flight_048_01);
    if (player_shot_7_flight_059[2] != 0x2) {
        printf("error! hop_la_a2_d16[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_059 + 2, player_shot_7_flight_048_01);
    if (player_shot_7_flight_060[2] != 0x2) {
        printf("error! hop_la_a2_d18[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_060 + 2, player_shot_7_flight_048_01);
    if (player_shot_7_flight_061[2] != 0x2) {
        printf("error! hop_la_a2_d1a[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_061 + 2, player_shot_7_flight_048_01);
    if (player_shot_7_flight_062[2] != 0x2) {
        printf("error! hop_la_a2_d1c[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_062 + 2, player_shot_7_flight_048_01);
    if (player_shot_7_flight_063[2] != 0x2) {
        printf("error! hop_la_a2_d1e[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_063 + 2, player_shot_7_flight_048_01);
    if (player_shot_7_flight_064[2] != 0x2) {
        printf("error! hop_la_a2_d20[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_064 + 2, player_shot_7_flight_048_01);
    if (player_shot_7_flight_table[136] != 0x0) {
        printf("error! hopt_la_a3_shdip[0]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 136, player_shot_7_flight_068);
    if (player_shot_7_flight_table[138] != 0x2) {
        printf("error! hopt_la_a3_shdip[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 138, player_shot_7_flight_069);
    if (player_shot_7_flight_table[140] != 0x4) {
        printf("error! hopt_la_a3_shdip[4]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 140, player_shot_7_flight_070);
    if (player_shot_7_flight_table[142] != 0x6) {
        printf("error! hopt_la_a3_shdip[6]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 142, player_shot_7_flight_071);
    if (player_shot_7_flight_table[144] != 0x8) {
        printf("error! hopt_la_a3_shdip[8]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 144, player_shot_7_flight_072);
    if (player_shot_7_flight_table[146] != 0xa) {
        printf("error! hopt_la_a3_shdip[10]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 146, player_shot_7_flight_073);
    if (player_shot_7_flight_table[148] != 0xc) {
        printf("error! hopt_la_a3_shdip[12]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 148, player_shot_7_flight_074);
    if (player_shot_7_flight_table[150] != 0xe) {
        printf("error! hopt_la_a3_shdip[14]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 150, player_shot_7_flight_075);
    if (player_shot_7_flight_table[152] != 0x10) {
        printf("error! hopt_la_a3_shdip[16]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 152, player_shot_7_flight_076);
    if (player_shot_7_flight_table[154] != 0x12) {
        printf("error! hopt_la_a3_shdip[18]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 154, player_shot_7_flight_077);
    if (player_shot_7_flight_table[156] != 0x14) {
        printf("error! hopt_la_a3_shdip[20]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 156, player_shot_7_flight_078);
    if (player_shot_7_flight_table[158] != 0x16) {
        printf("error! hopt_la_a3_shdip[22]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 158, player_shot_7_flight_079);
    if (player_shot_7_flight_table[160] != 0x18) {
        printf("error! hopt_la_a3_shdip[24]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 160, player_shot_7_flight_080);
    if (player_shot_7_flight_table[162] != 0x1a) {
        printf("error! hopt_la_a3_shdip[26]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 162, player_shot_7_flight_081);
    if (player_shot_7_flight_table[164] != 0x1c) {
        printf("error! hopt_la_a3_shdip[28]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 164, player_shot_7_flight_082);
    if (player_shot_7_flight_table[166] != 0x1e) {
        printf("error! hopt_la_a3_shdip[30]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 166, player_shot_7_flight_083);
    if (player_shot_7_flight_table[168] != 0x20) {
        printf("error! hopt_la_a3_shdip[32]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 168, player_shot_7_flight_084);
    if (player_shot_7_flight_068[2] != 0x2) {
        printf("error! hop_la_a3_d00[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_068 + 2, player_shot_7_flight_068_01);
    if (player_shot_7_flight_069[2] != 0x2) {
        printf("error! hop_la_a3_d02[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_069 + 2, player_shot_7_flight_068_01);
    if (player_shot_7_flight_070[2] != 0x2) {
        printf("error! hop_la_a3_d04[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_070 + 2, player_shot_7_flight_068_01);
    if (player_shot_7_flight_071[2] != 0x2) {
        printf("error! hop_la_a3_d06[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_071 + 2, player_shot_7_flight_068_01);
    if (player_shot_7_flight_072[2] != 0x2) {
        printf("error! hop_la_a3_d08[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_072 + 2, player_shot_7_flight_068_01);
    if (player_shot_7_flight_073[2] != 0x2) {
        printf("error! hop_la_a3_d0a[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_073 + 2, player_shot_7_flight_068_01);
    if (player_shot_7_flight_074[2] != 0x2) {
        printf("error! hop_la_a3_d0c[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_074 + 2, player_shot_7_flight_068_01);
    if (player_shot_7_flight_075[2] != 0x2) {
        printf("error! hop_la_a3_d0e[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_075 + 2, player_shot_7_flight_068_01);
    if (player_shot_7_flight_076[2] != 0x2) {
        printf("error! hop_la_a3_d10[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_076 + 2, player_shot_7_flight_068_01);
    if (player_shot_7_flight_077[2] != 0x2) {
        printf("error! hop_la_a3_d12[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_077 + 2, player_shot_7_flight_068_01);
    if (player_shot_7_flight_078[2] != 0x2) {
        printf("error! hop_la_a3_d14[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_078 + 2, player_shot_7_flight_068_01);
    if (player_shot_7_flight_079[2] != 0x2) {
        printf("error! hop_la_a3_d16[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_079 + 2, player_shot_7_flight_068_01);
    if (player_shot_7_flight_080[2] != 0x2) {
        printf("error! hop_la_a3_d18[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_080 + 2, player_shot_7_flight_068_01);
    if (player_shot_7_flight_081[2] != 0x2) {
        printf("error! hop_la_a3_d1a[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_081 + 2, player_shot_7_flight_068_01);
    if (player_shot_7_flight_082[2] != 0x2) {
        printf("error! hop_la_a3_d1c[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_082 + 2, player_shot_7_flight_068_01);
    if (player_shot_7_flight_083[2] != 0x2) {
        printf("error! hop_la_a3_d1e[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_083 + 2, player_shot_7_flight_068_01);
    if (player_shot_7_flight_084[2] != 0x2) {
        printf("error! hop_la_a3_d20[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_084 + 2, player_shot_7_flight_068_01);
    if (player_shot_7_flight_table[176] != 0x0) {
        printf("error! hopt_la_a4_shdip[0]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 176, player_shot_7_flight_088);
    if (player_shot_7_flight_table[178] != 0x2) {
        printf("error! hopt_la_a4_shdip[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 178, player_shot_7_flight_089);
    if (player_shot_7_flight_table[180] != 0x4) {
        printf("error! hopt_la_a4_shdip[4]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 180, player_shot_7_flight_090);
    if (player_shot_7_flight_table[182] != 0x6) {
        printf("error! hopt_la_a4_shdip[6]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 182, player_shot_7_flight_091);
    if (player_shot_7_flight_table[184] != 0x8) {
        printf("error! hopt_la_a4_shdip[8]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 184, player_shot_7_flight_092);
    if (player_shot_7_flight_table[186] != 0xa) {
        printf("error! hopt_la_a4_shdip[10]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 186, player_shot_7_flight_093);
    if (player_shot_7_flight_table[188] != 0xc) {
        printf("error! hopt_la_a4_shdip[12]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 188, player_shot_7_flight_094);
    if (player_shot_7_flight_table[190] != 0xe) {
        printf("error! hopt_la_a4_shdip[14]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 190, player_shot_7_flight_095);
    if (player_shot_7_flight_table[192] != 0x10) {
        printf("error! hopt_la_a4_shdip[16]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 192, player_shot_7_flight_096);
    if (player_shot_7_flight_table[194] != 0x12) {
        printf("error! hopt_la_a4_shdip[18]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 194, player_shot_7_flight_097);
    if (player_shot_7_flight_table[196] != 0x14) {
        printf("error! hopt_la_a4_shdip[20]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 196, player_shot_7_flight_098);
    if (player_shot_7_flight_table[198] != 0x16) {
        printf("error! hopt_la_a4_shdip[22]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 198, player_shot_7_flight_099);
    if (player_shot_7_flight_table[200] != 0x18) {
        printf("error! hopt_la_a4_shdip[24]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 200, player_shot_7_flight_100);
    if (player_shot_7_flight_table[202] != 0x1a) {
        printf("error! hopt_la_a4_shdip[26]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 202, player_shot_7_flight_101);
    if (player_shot_7_flight_table[204] != 0x1c) {
        printf("error! hopt_la_a4_shdip[28]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 204, player_shot_7_flight_102);
    if (player_shot_7_flight_table[206] != 0x1e) {
        printf("error! hopt_la_a4_shdip[30]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 206, player_shot_7_flight_103);
    if (player_shot_7_flight_table[208] != 0x20) {
        printf("error! hopt_la_a4_shdip[32]\n");
    }
    STORE_POINTER(player_shot_7_flight_table + 208, player_shot_7_flight_104);
    if (player_shot_7_flight_088[2] != 0x2) {
        printf("error! hop_la_a4_d00[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_088 + 2, player_shot_7_flight_088_01);
    if (player_shot_7_flight_089[2] != 0x2) {
        printf("error! hop_la_a4_d02[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_089 + 2, player_shot_7_flight_088_01);
    if (player_shot_7_flight_090[2] != 0x2) {
        printf("error! hop_la_a4_d04[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_090 + 2, player_shot_7_flight_088_01);
    if (player_shot_7_flight_091[2] != 0x2) {
        printf("error! hop_la_a4_d06[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_091 + 2, player_shot_7_flight_088_01);
    if (player_shot_7_flight_092[2] != 0x2) {
        printf("error! hop_la_a4_d08[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_092 + 2, player_shot_7_flight_088_01);
    if (player_shot_7_flight_093[2] != 0x2) {
        printf("error! hop_la_a4_d0a[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_093 + 2, player_shot_7_flight_088_01);
    if (player_shot_7_flight_094[2] != 0x2) {
        printf("error! hop_la_a4_d0c[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_094 + 2, player_shot_7_flight_088_01);
    if (player_shot_7_flight_095[2] != 0x2) {
        printf("error! hop_la_a4_d0e[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_095 + 2, player_shot_7_flight_088_01);
    if (player_shot_7_flight_096[2] != 0x2) {
        printf("error! hop_la_a4_d10[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_096 + 2, player_shot_7_flight_088_01);
    if (player_shot_7_flight_097[2] != 0x2) {
        printf("error! hop_la_a4_d12[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_097 + 2, player_shot_7_flight_088_01);
    if (player_shot_7_flight_098[2] != 0x2) {
        printf("error! hop_la_a4_d14[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_098 + 2, player_shot_7_flight_088_01);
    if (player_shot_7_flight_099[2] != 0x2) {
        printf("error! hop_la_a4_d16[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_099 + 2, player_shot_7_flight_088_01);
    if (player_shot_7_flight_100[2] != 0x2) {
        printf("error! hop_la_a4_d18[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_100 + 2, player_shot_7_flight_088_01);
    if (player_shot_7_flight_101[2] != 0x2) {
        printf("error! hop_la_a4_d1a[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_101 + 2, player_shot_7_flight_088_01);
    if (player_shot_7_flight_102[2] != 0x2) {
        printf("error! hop_la_a4_d1c[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_102 + 2, player_shot_7_flight_088_01);
    if (player_shot_7_flight_103[2] != 0x2) {
        printf("error! hop_la_a4_d1e[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_103 + 2, player_shot_7_flight_088_01);
    if (player_shot_7_flight_104[2] != 0x2) {
        printf("error! hop_la_a4_d20[2]\n");
    }
    STORE_POINTER(player_shot_7_flight_104 + 2, player_shot_7_flight_088_01);
    if (player_shot_7_directions_5[0] != 0x0) {
        printf("error! hopt_la_a5_shdip[0]\n");
    }
    STORE_POINTER(player_shot_7_directions_5, player_shot_7_direction_5_00);
    if (player_shot_7_directions_5[2] != 0x2) {
        printf("error! hopt_la_a5_shdip[2]\n");
    }
    STORE_POINTER(player_shot_7_directions_5 + 2, player_shot_7_direction_5_01);
    if (player_shot_7_directions_5[4] != 0x4) {
        printf("error! hopt_la_a5_shdip[4]\n");
    }
    STORE_POINTER(player_shot_7_directions_5 + 4, player_shot_7_direction_5_02);
    if (player_shot_7_directions_5[6] != 0x6) {
        printf("error! hopt_la_a5_shdip[6]\n");
    }
    STORE_POINTER(player_shot_7_directions_5 + 6, player_shot_7_direction_5_03);
    if (player_shot_7_directions_5[8] != 0x8) {
        printf("error! hopt_la_a5_shdip[8]\n");
    }
    STORE_POINTER(player_shot_7_directions_5 + 8, player_shot_7_direction_5_04);
    if (player_shot_7_directions_5[10] != 0xa) {
        printf("error! hopt_la_a5_shdip[10]\n");
    }
    STORE_POINTER(player_shot_7_directions_5 + 10, player_shot_7_direction_5_05);
    if (player_shot_7_directions_5[12] != 0xc) {
        printf("error! hopt_la_a5_shdip[12]\n");
    }
    STORE_POINTER(player_shot_7_directions_5 + 12, player_shot_7_direction_5_06);
    if (player_shot_7_directions_5[14] != 0xe) {
        printf("error! hopt_la_a5_shdip[14]\n");
    }
    STORE_POINTER(player_shot_7_directions_5 + 14, player_shot_7_direction_5_07);
    if (player_shot_7_directions_5[16] != 0x10) {
        printf("error! hopt_la_a5_shdip[16]\n");
    }
    STORE_POINTER(player_shot_7_directions_5 + 16, player_shot_7_direction_5_08);
    if (player_shot_7_directions_5[18] != 0x12) {
        printf("error! hopt_la_a5_shdip[18]\n");
    }
    STORE_POINTER(player_shot_7_directions_5 + 18, player_shot_7_direction_5_09);
    if (player_shot_7_directions_5[20] != 0x14) {
        printf("error! hopt_la_a5_shdip[20]\n");
    }
    STORE_POINTER(player_shot_7_directions_5 + 20, player_shot_7_direction_5_10);
    if (player_shot_7_directions_5[22] != 0x16) {
        printf("error! hopt_la_a5_shdip[22]\n");
    }
    STORE_POINTER(player_shot_7_directions_5 + 22, player_shot_7_direction_5_11);
    if (player_shot_7_directions_5[24] != 0x18) {
        printf("error! hopt_la_a5_shdip[24]\n");
    }
    STORE_POINTER(player_shot_7_directions_5 + 24, player_shot_7_direction_5_12);
    if (player_shot_7_directions_5[26] != 0x1a) {
        printf("error! hopt_la_a5_shdip[26]\n");
    }
    STORE_POINTER(player_shot_7_directions_5 + 26, player_shot_7_direction_5_13);
    if (player_shot_7_directions_5[28] != 0x1c) {
        printf("error! hopt_la_a5_shdip[28]\n");
    }
    STORE_POINTER(player_shot_7_directions_5 + 28, player_shot_7_direction_5_14);
    if (player_shot_7_directions_5[30] != 0x1e) {
        printf("error! hopt_la_a5_shdip[30]\n");
    }
    STORE_POINTER(player_shot_7_directions_5 + 30, player_shot_7_direction_5_15);
    if (player_shot_7_directions_5[32] != 0x20) {
        printf("error! hopt_la_a5_shdip[32]\n");
    }
    STORE_POINTER(player_shot_7_directions_5 + 32, player_shot_7_direction_5_16);
    if (player_shot_7_direction_5_00[2] != 0x2) {
        printf("error! hop_la_a5_d00[2]\n");
    }
    STORE_POINTER(player_shot_7_direction_5_00 + 2, player_shot_7_direction_5_00_01);
    if (player_shot_7_direction_5_01[2] != 0x2) {
        printf("error! hop_la_a5_d02[2]\n");
    }
    STORE_POINTER(player_shot_7_direction_5_01 + 2, player_shot_7_direction_5_00_01);
    if (player_shot_7_direction_5_02[2] != 0x2) {
        printf("error! hop_la_a5_d04[2]\n");
    }
    STORE_POINTER(player_shot_7_direction_5_02 + 2, player_shot_7_direction_5_00_01);
    if (player_shot_7_direction_5_03[2] != 0x2) {
        printf("error! hop_la_a5_d06[2]\n");
    }
    STORE_POINTER(player_shot_7_direction_5_03 + 2, player_shot_7_direction_5_00_01);
    if (player_shot_7_direction_5_04[2] != 0x2) {
        printf("error! hop_la_a5_d08[2]\n");
    }
    STORE_POINTER(player_shot_7_direction_5_04 + 2, player_shot_7_direction_5_00_01);
    if (player_shot_7_direction_5_05[2] != 0x2) {
        printf("error! hop_la_a5_d0a[2]\n");
    }
    STORE_POINTER(player_shot_7_direction_5_05 + 2, player_shot_7_direction_5_00_01);
    if (player_shot_7_direction_5_06[2] != 0x2) {
        printf("error! hop_la_a5_d0c[2]\n");
    }
    STORE_POINTER(player_shot_7_direction_5_06 + 2, player_shot_7_direction_5_00_01);
    if (player_shot_7_direction_5_07[2] != 0x2) {
        printf("error! hop_la_a5_d0e[2]\n");
    }
    STORE_POINTER(player_shot_7_direction_5_07 + 2, player_shot_7_direction_5_00_01);
    if (player_shot_7_direction_5_08[2] != 0x2) {
        printf("error! hop_la_a5_d10[2]\n");
    }
    STORE_POINTER(player_shot_7_direction_5_08 + 2, player_shot_7_direction_5_00_01);
    if (player_shot_7_direction_5_09[2] != 0x2) {
        printf("error! hop_la_a5_d12[2]\n");
    }
    STORE_POINTER(player_shot_7_direction_5_09 + 2, player_shot_7_direction_5_00_01);
    if (player_shot_7_direction_5_10[2] != 0x2) {
        printf("error! hop_la_a5_d14[2]\n");
    }
    STORE_POINTER(player_shot_7_direction_5_10 + 2, player_shot_7_direction_5_00_01);
    if (player_shot_7_direction_5_11[2] != 0x2) {
        printf("error! hop_la_a5_d16[2]\n");
    }
    STORE_POINTER(player_shot_7_direction_5_11 + 2, player_shot_7_direction_5_00_01);
    if (player_shot_7_direction_5_12[2] != 0x2) {
        printf("error! hop_la_a5_d18[2]\n");
    }
    STORE_POINTER(player_shot_7_direction_5_12 + 2, player_shot_7_direction_5_00_01);
    if (player_shot_7_direction_5_13[2] != 0x2) {
        printf("error! hop_la_a5_d1a[2]\n");
    }
    STORE_POINTER(player_shot_7_direction_5_13 + 2, player_shot_7_direction_5_00_01);
    if (player_shot_7_direction_5_14[2] != 0x2) {
        printf("error! hop_la_a5_d1c[2]\n");
    }
    STORE_POINTER(player_shot_7_direction_5_14 + 2, player_shot_7_direction_5_00_01);
    if (player_shot_7_direction_5_15[2] != 0x2) {
        printf("error! hop_la_a5_d1e[2]\n");
    }
    STORE_POINTER(player_shot_7_direction_5_15 + 2, player_shot_7_direction_5_00_01);
    if (player_shot_7_direction_5_16[2] != 0x2) {
        printf("error! hop_la_a5_d20[2]\n");
    }
    STORE_POINTER(player_shot_7_direction_5_16 + 2, player_shot_7_direction_5_00_01);
    if (player_shot_7_impact_table[0] != 0x0) {
        printf("error! hoa_tou_data[0]\n");
    }
    STORE_POINTER(player_shot_7_impact_table, player_shot_7_impact_00);
    if (player_shot_7_impact_table[2] != 0x2) {
        printf("error! hoa_tou_data[2]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 2, player_shot_7_impact_00);
    if (player_shot_7_impact_table[4] != 0x4) {
        printf("error! hoa_tou_data[4]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 4, player_shot_7_impact_02);
    if (player_shot_7_impact_table[6] != 0x6) {
        printf("error! hoa_tou_data[6]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 6, player_shot_7_impact_02);
    if (player_shot_7_impact_table[8] != 0x8) {
        printf("error! hoa_tou_data[8]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 8, player_shot_7_impact_04);
    if (player_shot_7_impact_table[10] != 0xa) {
        printf("error! hoa_tou_data[10]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 10, player_shot_7_impact_04);
    if (player_shot_7_impact_table[12] != 0xc) {
        printf("error! hoa_tou_data[12]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 12, player_shot_7_impact_06);
    if (player_shot_7_impact_table[14] != 0xe) {
        printf("error! hoa_tou_data[14]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 14, player_shot_7_impact_06);
    if (player_shot_7_impact_table[16] != 0x10) {
        printf("error! hoa_tou_data[16]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 16, player_shot_7_impact_08);
    if (player_shot_7_impact_table[18] != 0x12) {
        printf("error! hoa_tou_data[18]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 18, player_shot_7_impact_08);
    if (player_shot_7_impact_table[20] != 0x14) {
        printf("error! hoa_tou_data[20]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 20, player_shot_7_impact_10);
    if (player_shot_7_impact_table[22] != 0x16) {
        printf("error! hoa_tou_data[22]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 22, player_shot_7_impact_11);
    if (player_shot_7_impact_table[24] != 0x18) {
        printf("error! hoa_tou_data[24]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 24, player_shot_7_impact_12);
    if (player_shot_7_impact_table[26] != 0x1a) {
        printf("error! hoa_tou_data[26]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 26, player_shot_7_impact_13);
    if (player_shot_7_impact_table[28] != 0x1c) {
        printf("error! hoa_tou_data[28]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 28, player_shot_7_impact_14);
    if (player_shot_7_impact_table[30] != 0x1e) {
        printf("error! hoa_tou_data[30]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 30, player_shot_7_impact_15);
    if (player_shot_7_impact_table[32] != 0x20) {
        printf("error! hoa_tou_data[32]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 32, player_shot_7_impact_15);
    if (player_shot_7_impact_table[34] != 0x22) {
        printf("error! hoa_tou_data[34]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 34, player_shot_7_impact_17);
    if (player_shot_7_impact_table[36] != 0x24) {
        printf("error! hoa_tou_data[36]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 36, player_shot_7_impact_17);
    if (player_shot_7_impact_table[38] != 0x26) {
        printf("error! hoa_tou_data[38]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 38, player_shot_7_impact_19);
    if (player_shot_7_impact_table[40] != 0x28) {
        printf("error! hoa_tou_data[40]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 40, player_shot_7_impact_19);
    if (player_shot_7_impact_table[42] != 0x2a) {
        printf("error! hoa_tou_data[42]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 42, player_shot_7_impact_21);
    if (player_shot_7_impact_table[44] != 0x2c) {
        printf("error! hoa_tou_data[44]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 44, player_shot_7_impact_21);
    if (player_shot_7_impact_table[46] != 0x2e) {
        printf("error! hoa_tou_data[46]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 46, player_shot_7_impact_23);
    if (player_shot_7_impact_table[48] != 0x30) {
        printf("error! hoa_tou_data[48]\n");
    }
    STORE_POINTER(player_shot_7_impact_table + 48, player_shot_7_impact_23);
    if (player_shot_7_impact_00[3] != 0x3) {
        printf("error! hot_sh_a1_r[3]\n");
    }
    STORE_POINTER(player_shot_7_impact_00 + 3, player_shot_7_impact_frames_00);
    if (player_shot_7_impact_02[3] != 0x3) {
        printf("error! hot_sh_a2_r[3]\n");
    }
    STORE_POINTER(player_shot_7_impact_02 + 3, player_shot_7_impact_frames_02);
    if (player_shot_7_impact_04[3] != 0x3) {
        printf("error! hot_sh_a3_r[3]\n");
    }
    STORE_POINTER(player_shot_7_impact_04 + 3, player_shot_7_impact_frames_02);
    if (player_shot_7_impact_06[3] != 0x3) {
        printf("error! hot_sh_a4_r[3]\n");
    }
    STORE_POINTER(player_shot_7_impact_06 + 3, player_shot_7_impact_frames_06);
    if (player_shot_7_impact_08[3] != 0x3) {
        printf("error! hot_sh_a5_r[3]\n");
    }
    STORE_POINTER(player_shot_7_impact_08 + 3, player_shot_7_impact_frames_06);
    if (player_shot_7_impact_10[3] != 0x3) {
        printf("error! hot_la_a1[3]\n");
    }
    STORE_POINTER(player_shot_7_impact_10 + 3, player_shot_7_impact_frames_10);
    if (player_shot_7_impact_11[3] != 0x3) {
        printf("error! hot_la_a2[3]\n");
    }
    STORE_POINTER(player_shot_7_impact_11 + 3, player_shot_7_impact_frames_11);
    if (player_shot_7_impact_12[3] != 0x3) {
        printf("error! hot_la_a3[3]\n");
    }
    STORE_POINTER(player_shot_7_impact_12 + 3, player_shot_7_impact_frames_11);
    if (player_shot_7_impact_13[3] != 0x3) {
        printf("error! hot_la_a4[3]\n");
    }
    STORE_POINTER(player_shot_7_impact_13 + 3, player_shot_7_impact_frames_13);
    if (player_shot_7_impact_14[3] != 0x3) {
        printf("error! hot_la_a5[3]\n");
    }
    STORE_POINTER(player_shot_7_impact_14 + 3, player_shot_7_impact_frames_13);
    if (player_shot_7_impact_15[3] != 0x3) {
        printf("error! hot_ex_a1_r[3]\n");
    }
    STORE_POINTER(player_shot_7_impact_15 + 3, player_shot_7_impact_frames_15);
    if (player_shot_7_impact_17[3] != 0x3) {
        printf("error! hot_ex_a2_r[3]\n");
    }
    STORE_POINTER(player_shot_7_impact_17 + 3, player_shot_7_impact_frames_17);
    if (player_shot_7_impact_19[3] != 0x3) {
        printf("error! hot_ex_a3_r[3]\n");
    }
    STORE_POINTER(player_shot_7_impact_19 + 3, player_shot_7_impact_frames_17);
    if (player_shot_7_impact_21[3] != 0x3) {
        printf("error! hot_ex_a4_r[3]\n");
    }
    STORE_POINTER(player_shot_7_impact_21 + 3, player_shot_7_impact_frames_21);
    if (player_shot_7_impact_23[3] != 0x3) {
        printf("error! hot_ex_a5_r[3]\n");
    }
    STORE_POINTER(player_shot_7_impact_23 + 3, player_shot_7_impact_frames_21);
}
