#include "common.h"
#include "enemy.h"
#include "ground.h"
#include "player.h"
#include "sdk/ps2sdk.h"

/* Everything a saved pointer field may point at, by field kind. Pointers are
   stored as an index into one of these tables so that a snapshot does not depend
   on where the tables are in memory. */
extern u8 option_style_param_00_04[];
extern u8 option_style_param_01_04[];
extern u8 option_style_param_02_04[];
extern u8 option_style_param_00_15[];
extern u8 option_style_param_01_15[];
extern u8 option_style_param_02_15[];
extern u8 option_style_param_00_19[];
extern u8 option_style_param_01_19[];
extern u8 option_style_param_02_19[];
extern u8 ship0_shot_list_1_00_00_07[];
extern u8 ship0_shot_list_1_00_01_07[];
extern u8 ship0_shot_list_1_00_02_07[];
extern u8 ship0_shot_list_1_00_03_07[];
extern u8 ship0_shot_list_1_00_04_07[];
extern u8 ship0_shot_list_1_02_00_07[];
extern u8 ship0_shot_list_1_02_01_07[];
extern u8 ship0_shot_list_1_02_02_07[];
extern u8 ship0_shot_list_1_02_03_07[];
extern u8 ship0_shot_list_1_02_04_07[];
extern u8 ship0_shot_list_1_04_00_07[];
extern u8 ship0_shot_list_1_04_01_07[];
extern u8 ship0_shot_list_1_04_02_07[];
extern u8 ship0_shot_list_1_04_03_07[];
extern u8 ship0_shot_list_1_04_04_07[];
extern u8 option_shot_list_1_00_00_07[];
extern u8 option_shot_list_1_00_01_07[];
extern u8 option_shot_list_1_00_02_07[];
extern u8 option_shot_list_1_00_03_07[];
extern u8 option_shot_list_1_00_04_07[];
extern u8 option_shot_list_3_00_00_00_00_01[];
extern u8 option_shot_list_3_00_00_00_01_01[];
extern u8 option_shot_list_3_00_00_00_02_01[];
extern u8 option_shot_list_3_00_00_00_03_01[];
extern u8 option_shot_list_3_00_00_00_04_01[];
extern u8 option_shot_list_3_00_00_00_05_01[];
extern u8 option_shot_list_3_00_00_00_06_01[];
extern u8 option_shot_list_3_00_00_00_07_01[];
extern u8 option_shot_list_3_00_00_00_08_01[];
extern u8 option_shot_list_3_00_00_00_09_01[];
extern u8 option_shot_list_3_00_00_00_10_01[];
extern u8 option_shot_list_3_00_00_00_11_01[];
extern u8 option_shot_list_3_00_00_00_12_01[];
extern u8 option_shot_list_3_00_00_00_13_01[];
extern u8 option_shot_list_3_00_00_00_14_01[];
extern u8 option_shot_list_3_00_00_00_15_01[];
extern u8 option_shot_list_3_00_00_00_16_01[];
extern u8 option_shot_list_3_00_01_00_00_01[];
extern u8 option_shot_list_3_00_01_00_01_01[];
extern u8 option_shot_list_3_00_01_00_02_01[];
extern u8 option_shot_list_3_00_01_00_03_01[];
extern u8 option_shot_list_3_00_01_00_04_01[];
extern u8 option_shot_list_3_00_01_00_05_01[];
extern u8 option_shot_list_3_00_01_00_06_01[];
extern u8 option_shot_list_3_00_01_00_07_01[];
extern u8 option_shot_list_3_00_01_00_08_01[];
extern u8 option_shot_list_3_00_01_00_09_01[];
extern u8 option_shot_list_3_00_01_00_10_01[];
extern u8 option_shot_list_3_00_01_00_11_01[];
extern u8 option_shot_list_3_00_01_00_12_01[];
extern u8 option_shot_list_3_00_01_00_13_01[];
extern u8 option_shot_list_3_00_01_00_14_01[];
extern u8 option_shot_list_3_00_01_00_15_01[];
extern u8 option_shot_list_3_00_01_00_16_01[];
extern u8 option_shot_list_3_00_02_00_00_01[];
extern u8 option_shot_list_3_00_02_00_01_01[];
extern u8 option_shot_list_3_00_02_00_02_01[];
extern u8 option_shot_list_3_00_02_00_03_01[];
extern u8 option_shot_list_3_00_02_00_04_01[];
extern u8 option_shot_list_3_00_02_00_05_01[];
extern u8 option_shot_list_3_00_02_00_06_01[];
extern u8 option_shot_list_3_00_02_00_07_01[];
extern u8 option_shot_list_3_00_02_00_08_01[];
extern u8 option_shot_list_3_00_02_00_09_01[];
extern u8 option_shot_list_3_00_02_00_10_01[];
extern u8 option_shot_list_3_00_02_00_11_01[];
extern u8 option_shot_list_3_00_02_00_12_01[];
extern u8 option_shot_list_3_00_02_00_13_01[];
extern u8 option_shot_list_3_00_02_00_14_01[];
extern u8 option_shot_list_3_00_02_00_15_01[];
extern u8 option_shot_list_3_00_02_00_16_01[];
extern u8 option_shot_list_3_00_03_00_00_01[];
extern u8 option_shot_list_3_00_03_00_01_01[];
extern u8 option_shot_list_3_00_03_00_02_01[];
extern u8 option_shot_list_3_00_03_00_03_01[];
extern u8 option_shot_list_3_00_03_00_04_01[];
extern u8 option_shot_list_3_00_03_00_05_01[];
extern u8 option_shot_list_3_00_03_00_06_01[];
extern u8 option_shot_list_3_00_03_00_07_01[];
extern u8 option_shot_list_3_00_03_00_08_01[];
extern u8 option_shot_list_3_00_03_00_09_01[];
extern u8 option_shot_list_3_00_03_00_10_01[];
extern u8 option_shot_list_3_00_03_00_11_01[];
extern u8 option_shot_list_3_00_03_00_12_01[];
extern u8 option_shot_list_3_00_03_00_13_01[];
extern u8 option_shot_list_3_00_03_00_14_01[];
extern u8 option_shot_list_3_00_03_00_15_01[];
extern u8 option_shot_list_3_00_03_00_16_01[];
extern u8 option_shot_list_3_00_04_00_00_01[];
extern u8 option_shot_list_3_00_04_00_01_01[];
extern u8 option_shot_list_3_00_04_00_02_01[];
extern u8 option_shot_list_3_00_04_00_03_01[];
extern u8 option_shot_list_3_00_04_00_04_01[];
extern u8 option_shot_list_3_00_04_00_05_01[];
extern u8 option_shot_list_3_00_04_00_06_01[];
extern u8 option_shot_list_3_00_04_00_07_01[];
extern u8 option_shot_list_3_00_04_00_08_01[];
extern u8 option_shot_list_3_00_04_00_09_01[];
extern u8 option_shot_list_3_00_04_00_10_01[];
extern u8 option_shot_list_3_00_04_00_11_01[];
extern u8 option_shot_list_3_00_04_00_12_01[];
extern u8 option_shot_list_3_00_04_00_13_01[];
extern u8 option_shot_list_3_00_04_00_14_01[];
extern u8 option_shot_list_3_00_04_00_15_01[];
extern u8 option_shot_list_3_00_04_00_16_01[];
extern u8 option_shot_list_4_00_00_07[];
extern u8 option_shot_list_4_00_01_07[];
extern u8 option_shot_list_4_00_02_07[];
extern u8 option_shot_list_4_00_03_07[];
extern u8 option_shot_list_4_00_04_07[];
extern u8 player_shot_3_impact_frames_00[];
extern u8 player_shot_3_impact_frames_04[];
extern u8 player_shot_3_impact_frames_08[];
extern u8 player_shot_3_impact_frames_10[];
extern u8 player_shot_3_impact_frames_12[];
extern u8 player_shot_3_impact_frames_14[];
extern u8 player_shot_3_impact_frames_15[];
extern u8 player_shot_3_impact_frames_19[];
extern u8 player_shot_3_impact_frames_23[];
extern u8 player_shot_5_impact_frames_00[];
extern u8 player_shot_5_impact_frames_02[];
extern u8 player_shot_5_impact_frames_04[];
extern u8 player_shot_5_impact_frames_06[];
extern u8 player_shot_5_impact_frames_08[];
extern u8 player_shot_5_impact_frames_10[];
extern u8 player_shot_5_impact_frames_11[];
extern u8 player_shot_5_impact_frames_12[];
extern u8 player_shot_5_impact_frames_13[];
extern u8 player_shot_5_impact_frames_14[];
extern u8 player_shot_5_impact_frames_15[];
extern u8 player_shot_5_impact_frames_17[];
extern u8 player_shot_5_impact_frames_19[];
extern u8 player_shot_5_impact_frames_21[];
extern u8 player_shot_5_impact_frames_23[];
extern u8 option_shot_list_1_01_00_07[];
extern u8 player_shot_7_flight_028_01[];
extern u8 player_shot_7_flight_048_01[];
extern u8 player_shot_7_flight_068_01[];
extern u8 player_shot_7_flight_088_01[];
extern u8 player_shot_7_direction_5_00_01[];
extern u8 option_shot_list_4_01_00_07[];
extern u8 ship0_shot_list_1_01_00_07[];
extern u8 ship0_shot_list_1_03_00_07[];
extern u8 ship0_shot_list_1_05_00_07[];
extern u8 player_shot_7_impact_frames_00[];
extern u8 player_shot_7_impact_frames_02[];
extern u8 player_shot_7_impact_frames_06[];
extern u8 player_shot_7_impact_frames_10[];
extern u8 player_shot_7_impact_frames_11[];
extern u8 player_shot_7_impact_frames_13[];
extern u8 player_shot_7_impact_frames_15[];
extern u8 player_shot_7_impact_frames_17[];
extern u8 player_shot_7_impact_frames_21[];
extern u8 ship0_shot_list_3_00_00_07[];
extern u8 ship0_shot_list_3_00_01_07[];
extern u8 ship0_shot_list_3_00_02_07[];
extern u8 ship0_shot_list_3_00_03_07[];
extern u8 ship0_shot_list_3_00_04_07[];
extern u8 ship0_shot_list_3_02_00_07[];
extern u8 ship0_shot_list_3_02_01_07[];
extern u8 ship0_shot_list_3_02_02_07[];
extern u8 ship0_shot_list_3_02_03_07[];
extern u8 ship0_shot_list_3_02_04_07[];
extern u8 ship0_shot_list_3_04_00_07[];
extern u8 ship0_shot_list_3_04_01_07[];
extern u8 ship0_shot_list_3_04_02_07[];
extern u8 ship0_shot_list_3_04_03_07[];
extern u8 ship0_shot_list_3_04_04_07[];
extern u8 option_shot_list_1_02_00_07[];
extern u8 option_shot_list_1_02_01_07[];
extern u8 option_shot_list_1_02_02_07[];
extern u8 option_shot_list_1_02_03_07[];
extern u8 option_shot_list_1_02_04_07[];
extern u8 option_shot_list_3_02_00_00_00_01[];
extern u8 option_shot_list_3_02_00_00_01_01[];
extern u8 option_shot_list_3_02_00_00_02_01[];
extern u8 option_shot_list_3_02_00_00_03_01[];
extern u8 option_shot_list_3_02_00_00_04_01[];
extern u8 option_shot_list_3_02_00_00_05_01[];
extern u8 option_shot_list_3_02_00_00_06_01[];
extern u8 option_shot_list_3_02_00_00_07_01[];
extern u8 option_shot_list_3_02_00_00_08_01[];
extern u8 option_shot_list_3_02_00_00_09_01[];
extern u8 option_shot_list_3_02_00_00_10_01[];
extern u8 option_shot_list_3_02_00_00_11_01[];
extern u8 option_shot_list_3_02_00_00_12_01[];
extern u8 option_shot_list_3_02_00_00_13_01[];
extern u8 option_shot_list_3_02_00_00_14_01[];
extern u8 option_shot_list_3_02_00_00_15_01[];
extern u8 option_shot_list_3_02_00_00_16_01[];
extern u8 option_shot_list_3_02_01_00_00_01[];
extern u8 option_shot_list_3_02_01_00_01_01[];
extern u8 option_shot_list_3_02_01_00_02_01[];
extern u8 option_shot_list_3_02_01_00_03_01[];
extern u8 option_shot_list_3_02_01_00_04_01[];
extern u8 option_shot_list_3_02_01_00_05_01[];
extern u8 option_shot_list_3_02_01_00_06_01[];
extern u8 option_shot_list_3_02_01_00_07_01[];
extern u8 option_shot_list_3_02_01_00_08_01[];
extern u8 option_shot_list_3_02_01_00_09_01[];
extern u8 option_shot_list_3_02_01_00_10_01[];
extern u8 option_shot_list_3_02_01_00_11_01[];
extern u8 option_shot_list_3_02_01_00_12_01[];
extern u8 option_shot_list_3_02_01_00_13_01[];
extern u8 option_shot_list_3_02_01_00_14_01[];
extern u8 option_shot_list_3_02_01_00_15_01[];
extern u8 option_shot_list_3_02_01_00_16_01[];
extern u8 option_shot_list_3_02_02_00_00_01[];
extern u8 option_shot_list_3_02_02_00_01_01[];
extern u8 option_shot_list_3_02_02_00_02_01[];
extern u8 option_shot_list_3_02_02_00_03_01[];
extern u8 option_shot_list_3_02_02_00_04_01[];
extern u8 option_shot_list_3_02_02_00_05_01[];
extern u8 option_shot_list_3_02_02_00_06_01[];
extern u8 option_shot_list_3_02_02_00_07_01[];
extern u8 option_shot_list_3_02_02_00_08_01[];
extern u8 option_shot_list_3_02_02_00_09_01[];
extern u8 option_shot_list_3_02_02_00_10_01[];
extern u8 option_shot_list_3_02_02_00_11_01[];
extern u8 option_shot_list_3_02_02_00_12_01[];
extern u8 option_shot_list_3_02_02_00_13_01[];
extern u8 option_shot_list_3_02_02_00_14_01[];
extern u8 option_shot_list_3_02_02_00_15_01[];
extern u8 option_shot_list_3_02_02_00_16_01[];
extern u8 option_shot_list_3_02_03_00_00_01[];
extern u8 option_shot_list_3_02_03_00_01_01[];
extern u8 option_shot_list_3_02_03_00_02_01[];
extern u8 option_shot_list_3_02_03_00_03_01[];
extern u8 option_shot_list_3_02_03_00_04_01[];
extern u8 option_shot_list_3_02_03_00_05_01[];
extern u8 option_shot_list_3_02_03_00_06_01[];
extern u8 option_shot_list_3_02_03_00_07_01[];
extern u8 option_shot_list_3_02_03_00_08_01[];
extern u8 option_shot_list_3_02_03_00_09_01[];
extern u8 option_shot_list_3_02_03_00_10_01[];
extern u8 option_shot_list_3_02_03_00_11_01[];
extern u8 option_shot_list_3_02_03_00_12_01[];
extern u8 option_shot_list_3_02_03_00_13_01[];
extern u8 option_shot_list_3_02_03_00_14_01[];
extern u8 option_shot_list_3_02_03_00_15_01[];
extern u8 option_shot_list_3_02_03_00_16_01[];
extern u8 option_shot_list_3_02_04_00_00_01[];
extern u8 option_shot_list_3_02_04_00_01_01[];
extern u8 option_shot_list_3_02_04_00_02_01[];
extern u8 option_shot_list_3_02_04_00_03_01[];
extern u8 option_shot_list_3_02_04_00_04_01[];
extern u8 option_shot_list_3_02_04_00_05_01[];
extern u8 option_shot_list_3_02_04_00_06_01[];
extern u8 option_shot_list_3_02_04_00_07_01[];
extern u8 option_shot_list_3_02_04_00_08_01[];
extern u8 option_shot_list_3_02_04_00_09_01[];
extern u8 option_shot_list_3_02_04_00_10_01[];
extern u8 option_shot_list_3_02_04_00_11_01[];
extern u8 option_shot_list_3_02_04_00_12_01[];
extern u8 option_shot_list_3_02_04_00_13_01[];
extern u8 option_shot_list_3_02_04_00_14_01[];
extern u8 option_shot_list_3_02_04_00_15_01[];
extern u8 option_shot_list_3_02_04_00_16_01[];
extern u8 option_shot_list_4_02_00_07[];
extern u8 option_shot_list_4_02_01_07[];
extern u8 option_shot_list_4_02_02_07[];
extern u8 option_shot_list_4_02_03_07[];
extern u8 option_shot_list_4_02_04_07[];
extern u8 player_shot_4_impact_frames_00[];
extern u8 player_shot_4_impact_frames_04[];
extern u8 player_shot_4_impact_frames_08[];
extern u8 player_shot_4_impact_frames_10[];
extern u8 player_shot_4_impact_frames_12[];
extern u8 player_shot_4_impact_frames_14[];
extern u8 player_shot_4_impact_frames_15[];
extern u8 player_shot_4_impact_frames_19[];
extern u8 player_shot_4_impact_frames_23[];
extern u8 player_shot_6_impact_frames_00[];
extern u8 player_shot_6_impact_frames_02[];
extern u8 player_shot_6_impact_frames_04[];
extern u8 player_shot_6_impact_frames_06[];
extern u8 player_shot_6_impact_frames_08[];
extern u8 player_shot_6_impact_frames_10[];
extern u8 player_shot_6_impact_frames_11[];
extern u8 player_shot_6_impact_frames_12[];
extern u8 player_shot_6_impact_frames_13[];
extern u8 player_shot_6_impact_frames_14[];
extern u8 player_shot_6_impact_frames_15[];
extern u8 player_shot_6_impact_frames_17[];
extern u8 player_shot_6_impact_frames_19[];
extern u8 player_shot_6_impact_frames_21[];
extern u8 player_shot_6_impact_frames_23[];
extern u8 option_shot_list_1_03_00_07[];
extern u8 player_shot_8_flight_028_01[];
extern u8 player_shot_8_flight_048_01[];
extern u8 player_shot_8_flight_068_01[];
extern u8 player_shot_8_flight_088_01[];
extern u8 D_0025E1F0[];
extern u8 option_shot_list_4_03_00_07[];
extern u8 ship0_shot_list_3_01_00_07[];
extern u8 ship0_shot_list_3_03_00_07[];
extern u8 ship0_shot_list_3_05_00_07[];
extern u8 player_shot_8_impact_frames_00[];
extern u8 player_shot_8_impact_frames_02[];
extern u8 player_shot_8_impact_frames_06[];
extern u8 player_shot_8_impact_frames_10[];
extern u8 player_shot_8_impact_frames_11[];
extern u8 player_shot_8_impact_frames_13[];
extern u8 player_shot_8_impact_frames_15[];
extern u8 player_shot_8_impact_frames_17[];
extern u8 player_shot_8_impact_frames_21[];
extern u8 player_shot_1_impact_frames_00[];
extern u8 player_shot_1_impact_frames_02[];
extern u8 player_shot_1_impact_frames_04[];
extern u8 player_shot_1_impact_frames_06[];
extern u8 player_shot_1_impact_frames_08[];
extern u8 player_shot_1_impact_frames_10[];
extern u8 player_shot_1_impact_frames_11[];
extern u8 player_shot_1_impact_frames_12[];
extern u8 player_shot_1_impact_frames_13[];
extern u8 player_shot_1_impact_frames_14[];
extern u8 player_shot_1_impact_frames_15[];
extern u8 player_shot_1_impact_frames_17[];
extern u8 player_shot_1_impact_frames_19[];
extern u8 player_shot_1_impact_frames_21[];
extern u8 player_shot_1_impact_frames_23[];
extern u8 player_shot_2_impact_frames_00[];
extern u8 player_shot_2_impact_frames_02[];
extern u8 player_shot_2_impact_frames_04[];
extern u8 player_shot_2_impact_frames_06[];
extern u8 player_shot_2_impact_frames_08[];
extern u8 player_shot_2_impact_frames_10[];
extern u8 player_shot_2_impact_frames_11[];
extern u8 player_shot_2_impact_frames_12[];
extern u8 player_shot_2_impact_frames_13[];
extern u8 player_shot_2_impact_frames_14[];
extern u8 player_shot_2_impact_frames_15[];
extern u8 player_shot_2_impact_frames_17[];
extern u8 player_shot_2_impact_frames_19[];
extern u8 player_shot_2_impact_frames_21[];
extern u8 player_shot_2_impact_frames_23[];
extern u8 option_sprites_b_00_00_05[];
extern u8 option_sprites_b_00_01_05[];
extern u8 option_sprites_b_00_02_05[];
extern u8 option_sprites_b_00_03_05[];
extern u8 option_sprites_b_00_04_05[];
extern u8 option_sprites_b_01_00_05[];
extern u8 option_sprites_b_01_01_05[];
extern u8 option_sprites_b_01_02_05[];
extern u8 option_sprites_b_01_03_05[];
extern u8 option_sprites_b_01_04_05[];
extern u8 option_hyper_sprite_b_00_05[];
extern u8 D_00256E50[];
extern u8 D_00256E70[];
extern u8 D_00256E90[];
extern u8 D_00256EB0[];
extern u8 D_00256FC0[];
extern u8 D_00257030[];
extern u8 D_002570A0[];
extern u8 D_00257110[];
extern u8 option_power_value_00[];
extern u8 option_power_value_01[];
extern u8 option_power_value_02[];
extern u8 option_power_value_03[];
extern u8 option_power_value_04[];
extern u8 option_power_value_05[];
extern u8 option_power_value_06[];
extern u8 option_power_value_07[];
extern u8 option_power_value_08[];
extern u8 option_power_value_09[];
extern u8 option_strong_param_00[];
extern u8 option_strong_param_01[];
extern u8 option_strong_param_02[];
extern u8 option_strong_param_03[];
extern u8 option_strong_param_04[];
extern u8 option_strong_param_05[];
extern u8 option_strong_param_06[];
extern u8 option_strong_param_07[];
extern u8 option_strong_param_08[];
extern u8 option_strong_param_09[];
extern u8 option_hyper_param_00[];
extern u8 option_hyper_param_01[];
extern u8 option_hyper_param_02[];
extern u8 option_hyper_param_03[];
extern u8 option_hyper_param_04[];
extern u8 option_power_value_00_07[];
extern u8 option_power_value_05_07[];
extern u8 option_strong_param_00_07[];
extern u8 option_strong_param_05_07[];
extern u8 option_hyper_param_00_07[];
extern u8 option_power_value_00_05[];
extern u8 option_power_value_05_05[];
extern u8 option_strong_param_00_05[];
extern u8 option_hyper_param_00_05[];
extern u8 option_power_value_00_08[];
extern u8 option_power_value_01_08[];
extern u8 option_power_value_02_08[];
extern u8 option_power_value_03_08[];
extern u8 option_power_value_04_08[];
extern u8 option_power_value_05_08[];
extern u8 option_power_value_06_08[];
extern u8 option_power_value_07_08[];
extern u8 option_power_value_08_08[];
extern u8 option_power_value_09_08[];
extern u8 option_strong_param_00_08[];
extern u8 option_strong_param_01_08[];
extern u8 option_strong_param_02_08[];
extern u8 option_strong_param_03_08[];
extern u8 option_strong_param_04_08[];
extern u8 D_00257368[];
extern u8 D_00257378[];
extern u8 D_00257388[];
extern u8 D_00257398[];
extern u8 option_hyper_param_00_08[];
extern u8 D_00257138[];
extern u8 D_00257148[];
extern u8 D_00257158[];
extern u8 D_00257168[];
extern u8 D_00257178[];
extern u8 D_00257188[];
extern u8 D_00257198[];
extern u8 D_002571A8[];
extern u8 D_002571B8[];
extern u8 D_002571C8[];
extern u8 D_002571D8[];
extern u8 D_002571E8[];
extern u8 D_002571F8[];
extern u8 D_00257208[];
extern u8 D_00257218[];
extern u8 D_00257228[];
extern u8 D_00257238[];
extern u8 D_00257248[];
extern u8 D_00257258[];
extern u8 D_00257268[];
extern u8 spread_bomb_a_phase1_frames[];
extern u8 spread_bomb_b_phase1_frames[];
extern u8 spread_bomb_a_phase2_frames[];
extern u8 spread_bomb_b_phase2_frames[];
extern u8 spread_bomb_a_phase3_frames[];
extern u8 spread_bomb_b_phase3_frames[];
extern u8 laser_bomb_a_base_frames[];
extern u8 laser_bomb_a_muzzle_frames[];
extern u8 laser_bomb_a_tip_frames[];
extern u8 laser_bomb_a_impact_frames[];
extern u8 laser_bomb_a_beam_frames[];
extern u8 laser_bomb_a_beam_frame_07[];
extern u8 laser_bomb_a_beam_frame_06[];
extern u8 laser_bomb_a_beam_frame_05[];
extern u8 laser_bomb_a_beam_frame_04[];
extern u8 laser_bomb_a_beam_frame_03[];
extern u8 laser_bomb_a_beam_frame_02[];
extern u8 laser_bomb_a_beam_frame_01[];
extern u8 laser_bomb_a_beam_frame_00[];
extern u8 laser_bomb_a_beam_table[];
extern u8 laser_bomb_a_beam_row_00[];
extern u8 laser_bomb_a_beam_row_01[];
extern u8 laser_bomb_a_beam_row_02[];
extern u8 laser_bomb_a_beam_row_03[];
extern u8 laser_bomb_a_beam_row_04[];
extern u8 laser_bomb_a_beam_row_05[];
extern u8 laser_bomb_a_beam_row_06[];
extern u8 laser_bomb_a_beam_row_07[];
extern u8 laser_bomb_a_beam_row_08[];
extern u8 laser_bomb_a_beam_row_09[];
extern u8 laser_bomb_a_beam_row_10[];
extern u8 laser_bomb_a_beam_row_11[];
extern u8 laser_bomb_b_base_frames[];
extern u8 laser_bomb_b_muzzle_frames[];
extern u8 laser_bomb_b_tip_frames[];
extern u8 laser_bomb_b_impact_frames[];
extern u8 laser_bomb_b_beam_frames[];
extern u8 laser_bomb_b_beam_frame_07[];
extern u8 laser_bomb_b_beam_frame_06[];
extern u8 laser_bomb_b_beam_frame_05[];
extern u8 laser_bomb_b_beam_frame_04[];
extern u8 laser_bomb_b_beam_frame_03[];
extern u8 laser_bomb_b_beam_frame_02[];
extern u8 laser_bomb_b_beam_frame_01[];
extern u8 laser_bomb_b_beam_frame_00[];
extern u8 laser_bomb_b_beam_table[];
extern u8 laser_bomb_b_beam_row_00[];
extern u8 laser_bomb_b_beam_row_01[];
extern u8 laser_bomb_b_beam_row_02[];
extern u8 laser_bomb_b_beam_row_03[];
extern u8 laser_bomb_b_beam_row_04[];
extern u8 laser_bomb_b_beam_row_05[];
extern u8 laser_bomb_b_beam_row_06[];
extern u8 laser_bomb_b_beam_row_07[];
extern u8 laser_bomb_b_beam_row_08[];
extern u8 laser_bomb_b_beam_row_09[];
extern u8 laser_bomb_b_beam_row_10[];
extern u8 laser_bomb_b_beam_row_11[];
extern u8 laser_bomb_template[];
extern u8 laser_bomb_segment_template[];
extern u8 player_shot_levels_0[];
extern u8 player_laser_levels_0[];
extern u8 player_shot_levels_1[];
extern u8 player_laser_levels_1[];
extern u8 player_shot_levels_2[];
extern u8 player_laser_levels_2[];
extern u8 player_shot_levels_3[];
extern u8 player_laser_levels_3[];
extern u8 player_shot_levels_4[];
extern u8 player_laser_levels_4[];
extern u8 player_shot_levels_5[];
extern u8 player_laser_levels_5[];

void *replay_targets_option_style_a[] = {
    option_style_param_00_04,
    option_style_param_01_04,
    option_style_param_02_04,
};

void *replay_targets_option_style_b[] = {
    option_style_param_00_15,
    option_style_param_01_15,
    option_style_param_02_15,
};

void *replay_targets_option_style_c[] = {
    option_style_param_00_19,
    option_style_param_01_19,
    option_style_param_02_19,
};

void *replay_targets_shot_lists[] = {
    ship0_shot_list_1_00_00_07,
    ship0_shot_list_1_00_01_07,
    ship0_shot_list_1_00_02_07,
    ship0_shot_list_1_00_03_07,
    ship0_shot_list_1_00_04_07,
    ship0_shot_list_1_02_00_07,
    ship0_shot_list_1_02_01_07,
    ship0_shot_list_1_02_02_07,
    ship0_shot_list_1_02_03_07,
    ship0_shot_list_1_02_04_07,
    ship0_shot_list_1_04_00_07,
    ship0_shot_list_1_04_01_07,
    ship0_shot_list_1_04_02_07,
    ship0_shot_list_1_04_03_07,
    ship0_shot_list_1_04_04_07,
    option_shot_list_1_00_00_07,
    option_shot_list_1_00_01_07,
    option_shot_list_1_00_02_07,
    option_shot_list_1_00_03_07,
    option_shot_list_1_00_04_07,
    option_shot_list_3_00_00_00_00_01,
    option_shot_list_3_00_00_00_01_01,
    option_shot_list_3_00_00_00_02_01,
    option_shot_list_3_00_00_00_03_01,
    option_shot_list_3_00_00_00_04_01,
    option_shot_list_3_00_00_00_05_01,
    option_shot_list_3_00_00_00_06_01,
    option_shot_list_3_00_00_00_07_01,
    option_shot_list_3_00_00_00_08_01,
    option_shot_list_3_00_00_00_09_01,
    option_shot_list_3_00_00_00_10_01,
    option_shot_list_3_00_00_00_11_01,
    option_shot_list_3_00_00_00_12_01,
    option_shot_list_3_00_00_00_13_01,
    option_shot_list_3_00_00_00_14_01,
    option_shot_list_3_00_00_00_15_01,
    option_shot_list_3_00_00_00_16_01,
    option_shot_list_3_00_01_00_00_01,
    option_shot_list_3_00_01_00_01_01,
    option_shot_list_3_00_01_00_02_01,
    option_shot_list_3_00_01_00_03_01,
    option_shot_list_3_00_01_00_04_01,
    option_shot_list_3_00_01_00_05_01,
    option_shot_list_3_00_01_00_06_01,
    option_shot_list_3_00_01_00_07_01,
    option_shot_list_3_00_01_00_08_01,
    option_shot_list_3_00_01_00_09_01,
    option_shot_list_3_00_01_00_10_01,
    option_shot_list_3_00_01_00_11_01,
    option_shot_list_3_00_01_00_12_01,
    option_shot_list_3_00_01_00_13_01,
    option_shot_list_3_00_01_00_14_01,
    option_shot_list_3_00_01_00_15_01,
    option_shot_list_3_00_01_00_16_01,
    option_shot_list_3_00_02_00_00_01,
    option_shot_list_3_00_02_00_01_01,
    option_shot_list_3_00_02_00_02_01,
    option_shot_list_3_00_02_00_03_01,
    option_shot_list_3_00_02_00_04_01,
    option_shot_list_3_00_02_00_05_01,
    option_shot_list_3_00_02_00_06_01,
    option_shot_list_3_00_02_00_07_01,
    option_shot_list_3_00_02_00_08_01,
    option_shot_list_3_00_02_00_09_01,
    option_shot_list_3_00_02_00_10_01,
    option_shot_list_3_00_02_00_11_01,
    option_shot_list_3_00_02_00_12_01,
    option_shot_list_3_00_02_00_13_01,
    option_shot_list_3_00_02_00_14_01,
    option_shot_list_3_00_02_00_15_01,
    option_shot_list_3_00_02_00_16_01,
    option_shot_list_3_00_03_00_00_01,
    option_shot_list_3_00_03_00_01_01,
    option_shot_list_3_00_03_00_02_01,
    option_shot_list_3_00_03_00_03_01,
    option_shot_list_3_00_03_00_04_01,
    option_shot_list_3_00_03_00_05_01,
    option_shot_list_3_00_03_00_06_01,
    option_shot_list_3_00_03_00_07_01,
    option_shot_list_3_00_03_00_08_01,
    option_shot_list_3_00_03_00_09_01,
    option_shot_list_3_00_03_00_10_01,
    option_shot_list_3_00_03_00_11_01,
    option_shot_list_3_00_03_00_12_01,
    option_shot_list_3_00_03_00_13_01,
    option_shot_list_3_00_03_00_14_01,
    option_shot_list_3_00_03_00_15_01,
    option_shot_list_3_00_03_00_16_01,
    option_shot_list_3_00_04_00_00_01,
    option_shot_list_3_00_04_00_01_01,
    option_shot_list_3_00_04_00_02_01,
    option_shot_list_3_00_04_00_03_01,
    option_shot_list_3_00_04_00_04_01,
    option_shot_list_3_00_04_00_05_01,
    option_shot_list_3_00_04_00_06_01,
    option_shot_list_3_00_04_00_07_01,
    option_shot_list_3_00_04_00_08_01,
    option_shot_list_3_00_04_00_09_01,
    option_shot_list_3_00_04_00_10_01,
    option_shot_list_3_00_04_00_11_01,
    option_shot_list_3_00_04_00_12_01,
    option_shot_list_3_00_04_00_13_01,
    option_shot_list_3_00_04_00_14_01,
    option_shot_list_3_00_04_00_15_01,
    option_shot_list_3_00_04_00_16_01,
    option_shot_list_4_00_00_07,
    option_shot_list_4_00_01_07,
    option_shot_list_4_00_02_07,
    option_shot_list_4_00_03_07,
    option_shot_list_4_00_04_07,
    player_shot_3_impact_frames_00,
    player_shot_3_impact_frames_04,
    player_shot_3_impact_frames_08,
    player_shot_3_impact_frames_10,
    player_shot_3_impact_frames_12,
    player_shot_3_impact_frames_14,
    player_shot_3_impact_frames_15,
    player_shot_3_impact_frames_19,
    player_shot_3_impact_frames_23,
    player_shot_5_impact_frames_00,
    player_shot_5_impact_frames_02,
    player_shot_5_impact_frames_04,
    player_shot_5_impact_frames_06,
    player_shot_5_impact_frames_08,
    player_shot_5_impact_frames_10,
    player_shot_5_impact_frames_11,
    player_shot_5_impact_frames_12,
    player_shot_5_impact_frames_13,
    player_shot_5_impact_frames_14,
    player_shot_5_impact_frames_15,
    player_shot_5_impact_frames_17,
    player_shot_5_impact_frames_19,
    player_shot_5_impact_frames_21,
    player_shot_5_impact_frames_23,
    option_shot_list_1_01_00_07,
    player_shot_7_flight_028_01,
    player_shot_7_flight_048_01,
    player_shot_7_flight_068_01,
    player_shot_7_flight_088_01,
    player_shot_7_direction_5_00_01,
    option_shot_list_4_01_00_07,
    ship0_shot_list_1_01_00_07,
    ship0_shot_list_1_03_00_07,
    ship0_shot_list_1_05_00_07,
    player_shot_7_impact_frames_00,
    player_shot_7_impact_frames_02,
    player_shot_7_impact_frames_06,
    player_shot_7_impact_frames_10,
    player_shot_7_impact_frames_11,
    player_shot_7_impact_frames_13,
    player_shot_7_impact_frames_15,
    player_shot_7_impact_frames_17,
    player_shot_7_impact_frames_21,
    ship0_shot_list_3_00_00_07,
    ship0_shot_list_3_00_01_07,
    ship0_shot_list_3_00_02_07,
    ship0_shot_list_3_00_03_07,
    ship0_shot_list_3_00_04_07,
    ship0_shot_list_3_02_00_07,
    ship0_shot_list_3_02_01_07,
    ship0_shot_list_3_02_02_07,
    ship0_shot_list_3_02_03_07,
    ship0_shot_list_3_02_04_07,
    ship0_shot_list_3_04_00_07,
    ship0_shot_list_3_04_01_07,
    ship0_shot_list_3_04_02_07,
    ship0_shot_list_3_04_03_07,
    ship0_shot_list_3_04_04_07,
    option_shot_list_1_02_00_07,
    option_shot_list_1_02_01_07,
    option_shot_list_1_02_02_07,
    option_shot_list_1_02_03_07,
    option_shot_list_1_02_04_07,
    option_shot_list_3_02_00_00_00_01,
    option_shot_list_3_02_00_00_01_01,
    option_shot_list_3_02_00_00_02_01,
    option_shot_list_3_02_00_00_03_01,
    option_shot_list_3_02_00_00_04_01,
    option_shot_list_3_02_00_00_05_01,
    option_shot_list_3_02_00_00_06_01,
    option_shot_list_3_02_00_00_07_01,
    option_shot_list_3_02_00_00_08_01,
    option_shot_list_3_02_00_00_09_01,
    option_shot_list_3_02_00_00_10_01,
    option_shot_list_3_02_00_00_11_01,
    option_shot_list_3_02_00_00_12_01,
    option_shot_list_3_02_00_00_13_01,
    option_shot_list_3_02_00_00_14_01,
    option_shot_list_3_02_00_00_15_01,
    option_shot_list_3_02_00_00_16_01,
    option_shot_list_3_02_01_00_00_01,
    option_shot_list_3_02_01_00_01_01,
    option_shot_list_3_02_01_00_02_01,
    option_shot_list_3_02_01_00_03_01,
    option_shot_list_3_02_01_00_04_01,
    option_shot_list_3_02_01_00_05_01,
    option_shot_list_3_02_01_00_06_01,
    option_shot_list_3_02_01_00_07_01,
    option_shot_list_3_02_01_00_08_01,
    option_shot_list_3_02_01_00_09_01,
    option_shot_list_3_02_01_00_10_01,
    option_shot_list_3_02_01_00_11_01,
    option_shot_list_3_02_01_00_12_01,
    option_shot_list_3_02_01_00_13_01,
    option_shot_list_3_02_01_00_14_01,
    option_shot_list_3_02_01_00_15_01,
    option_shot_list_3_02_01_00_16_01,
    option_shot_list_3_02_02_00_00_01,
    option_shot_list_3_02_02_00_01_01,
    option_shot_list_3_02_02_00_02_01,
    option_shot_list_3_02_02_00_03_01,
    option_shot_list_3_02_02_00_04_01,
    option_shot_list_3_02_02_00_05_01,
    option_shot_list_3_02_02_00_06_01,
    option_shot_list_3_02_02_00_07_01,
    option_shot_list_3_02_02_00_08_01,
    option_shot_list_3_02_02_00_09_01,
    option_shot_list_3_02_02_00_10_01,
    option_shot_list_3_02_02_00_11_01,
    option_shot_list_3_02_02_00_12_01,
    option_shot_list_3_02_02_00_13_01,
    option_shot_list_3_02_02_00_14_01,
    option_shot_list_3_02_02_00_15_01,
    option_shot_list_3_02_02_00_16_01,
    option_shot_list_3_02_03_00_00_01,
    option_shot_list_3_02_03_00_01_01,
    option_shot_list_3_02_03_00_02_01,
    option_shot_list_3_02_03_00_03_01,
    option_shot_list_3_02_03_00_04_01,
    option_shot_list_3_02_03_00_05_01,
    option_shot_list_3_02_03_00_06_01,
    option_shot_list_3_02_03_00_07_01,
    option_shot_list_3_02_03_00_08_01,
    option_shot_list_3_02_03_00_09_01,
    option_shot_list_3_02_03_00_10_01,
    option_shot_list_3_02_03_00_11_01,
    option_shot_list_3_02_03_00_12_01,
    option_shot_list_3_02_03_00_13_01,
    option_shot_list_3_02_03_00_14_01,
    option_shot_list_3_02_03_00_15_01,
    option_shot_list_3_02_03_00_16_01,
    option_shot_list_3_02_04_00_00_01,
    option_shot_list_3_02_04_00_01_01,
    option_shot_list_3_02_04_00_02_01,
    option_shot_list_3_02_04_00_03_01,
    option_shot_list_3_02_04_00_04_01,
    option_shot_list_3_02_04_00_05_01,
    option_shot_list_3_02_04_00_06_01,
    option_shot_list_3_02_04_00_07_01,
    option_shot_list_3_02_04_00_08_01,
    option_shot_list_3_02_04_00_09_01,
    option_shot_list_3_02_04_00_10_01,
    option_shot_list_3_02_04_00_11_01,
    option_shot_list_3_02_04_00_12_01,
    option_shot_list_3_02_04_00_13_01,
    option_shot_list_3_02_04_00_14_01,
    option_shot_list_3_02_04_00_15_01,
    option_shot_list_3_02_04_00_16_01,
    option_shot_list_4_02_00_07,
    option_shot_list_4_02_01_07,
    option_shot_list_4_02_02_07,
    option_shot_list_4_02_03_07,
    option_shot_list_4_02_04_07,
    player_shot_4_impact_frames_00,
    player_shot_4_impact_frames_04,
    player_shot_4_impact_frames_08,
    player_shot_4_impact_frames_10,
    player_shot_4_impact_frames_12,
    player_shot_4_impact_frames_14,
    player_shot_4_impact_frames_15,
    player_shot_4_impact_frames_19,
    player_shot_4_impact_frames_23,
    player_shot_6_impact_frames_00,
    player_shot_6_impact_frames_02,
    player_shot_6_impact_frames_04,
    player_shot_6_impact_frames_06,
    player_shot_6_impact_frames_08,
    player_shot_6_impact_frames_10,
    player_shot_6_impact_frames_11,
    player_shot_6_impact_frames_12,
    player_shot_6_impact_frames_13,
    player_shot_6_impact_frames_14,
    player_shot_6_impact_frames_15,
    player_shot_6_impact_frames_17,
    player_shot_6_impact_frames_19,
    player_shot_6_impact_frames_21,
    player_shot_6_impact_frames_23,
    option_shot_list_1_03_00_07,
    player_shot_8_flight_028_01,
    player_shot_8_flight_048_01,
    player_shot_8_flight_068_01,
    player_shot_8_flight_088_01,
    D_0025E1F0,
    option_shot_list_4_03_00_07,
    ship0_shot_list_3_01_00_07,
    ship0_shot_list_3_03_00_07,
    ship0_shot_list_3_05_00_07,
    player_shot_8_impact_frames_00,
    player_shot_8_impact_frames_02,
    player_shot_8_impact_frames_06,
    player_shot_8_impact_frames_10,
    player_shot_8_impact_frames_11,
    player_shot_8_impact_frames_13,
    player_shot_8_impact_frames_15,
    player_shot_8_impact_frames_17,
    player_shot_8_impact_frames_21,
    player_shot_1_impact_frames_00,
    player_shot_1_impact_frames_02,
    player_shot_1_impact_frames_04,
    player_shot_1_impact_frames_06,
    player_shot_1_impact_frames_08,
    player_shot_1_impact_frames_10,
    player_shot_1_impact_frames_11,
    player_shot_1_impact_frames_12,
    player_shot_1_impact_frames_13,
    player_shot_1_impact_frames_14,
    player_shot_1_impact_frames_15,
    player_shot_1_impact_frames_17,
    player_shot_1_impact_frames_19,
    player_shot_1_impact_frames_21,
    player_shot_1_impact_frames_23,
    player_shot_2_impact_frames_00,
    player_shot_2_impact_frames_02,
    player_shot_2_impact_frames_04,
    player_shot_2_impact_frames_06,
    player_shot_2_impact_frames_08,
    player_shot_2_impact_frames_10,
    player_shot_2_impact_frames_11,
    player_shot_2_impact_frames_12,
    player_shot_2_impact_frames_13,
    player_shot_2_impact_frames_14,
    player_shot_2_impact_frames_15,
    player_shot_2_impact_frames_17,
    player_shot_2_impact_frames_19,
    player_shot_2_impact_frames_21,
    player_shot_2_impact_frames_23,
};

void *replay_targets_option_sprites[] = {
    option_sprites_b_00_00_05,
    option_sprites_b_00_01_05,
    option_sprites_b_00_02_05,
    option_sprites_b_00_03_05,
    option_sprites_b_00_04_05,
    option_sprites_b_01_00_05,
    option_sprites_b_01_01_05,
    option_sprites_b_01_02_05,
    option_sprites_b_01_03_05,
    option_sprites_b_01_04_05,
    option_hyper_sprite_b_00_05,
    D_00256E50,
    D_00256E70,
    D_00256E90,
    D_00256EB0,
    D_00256FC0,
    D_00257030,
    D_002570A0,
    D_00257110,
    option_power_value_00,
    option_power_value_01,
    option_power_value_02,
    option_power_value_03,
    option_power_value_04,
    option_power_value_05,
    option_power_value_06,
    option_power_value_07,
    option_power_value_08,
    option_power_value_09,
    option_strong_param_00,
    option_strong_param_01,
    option_strong_param_02,
    option_strong_param_03,
    option_strong_param_04,
    option_strong_param_05,
    option_strong_param_06,
    option_strong_param_07,
    option_strong_param_08,
    option_strong_param_09,
    option_hyper_param_00,
    option_hyper_param_01,
    option_hyper_param_02,
    option_hyper_param_03,
    option_hyper_param_04,
};

void *replay_targets_option_params_a[] = {
    option_power_value_00_07,
    option_power_value_05_07,
    option_strong_param_00_07,
    option_strong_param_05_07,
    option_hyper_param_00_07,
};

void *replay_blocks_option_params[] = {
    option_power_value_00_05,
    option_power_value_05_05,
    option_strong_param_00_05,
    option_hyper_param_00_05,
    option_power_value_00_08,
    option_power_value_01_08,
    option_power_value_02_08,
    option_power_value_03_08,
    option_power_value_04_08,
    option_power_value_05_08,
    option_power_value_06_08,
    option_power_value_07_08,
    option_power_value_08_08,
    option_power_value_09_08,
    option_strong_param_00_08,
    option_strong_param_01_08,
    option_strong_param_02_08,
    option_strong_param_03_08,
    option_strong_param_04_08,
    D_00257368,
    D_00257378,
    D_00257388,
    D_00257398,
    option_hyper_param_00_08,
};

s32 replay_block_sizes_option_params[] = {
    50, 50, 50, 50, 14, 14, 14, 14,
    14, 14, 14, 14, 14, 14, 14, 14,
    14, 14, 14,
};

void *replay_targets_option_params_b[] = {
    D_00257138,
    D_00257148,
    D_00257158,
    D_00257168,
    D_00257178,
    D_00257188,
    D_00257198,
    D_002571A8,
    D_002571B8,
    D_002571C8,
    D_002571D8,
    D_002571E8,
    D_002571F8,
    D_00257208,
    D_00257218,
    D_00257228,
    D_00257238,
    D_00257248,
    D_00257258,
    D_00257268,
};

void *replay_blocks_bomb[] = {
    spread_bomb_a_phase1_frames,
    spread_bomb_b_phase1_frames,
    spread_bomb_a_phase2_frames,
    spread_bomb_b_phase2_frames,
    spread_bomb_a_phase3_frames,
    spread_bomb_b_phase3_frames,
};

s32 replay_block_sizes_bomb[] = {
    50, 50, 32, 32, 20, 20,
};

void *replay_targets_bomb[] = {
    laser_bomb_a_base_frames,
    laser_bomb_a_muzzle_frames,
    laser_bomb_a_tip_frames,
    laser_bomb_a_impact_frames,
    laser_bomb_a_beam_frames,
    laser_bomb_a_beam_frame_07,
    laser_bomb_a_beam_frame_06,
    laser_bomb_a_beam_frame_05,
    laser_bomb_a_beam_frame_04,
    laser_bomb_a_beam_frame_03,
    laser_bomb_a_beam_frame_02,
    laser_bomb_a_beam_frame_01,
    laser_bomb_a_beam_frame_00,
    laser_bomb_a_beam_table,
    laser_bomb_a_beam_row_00,
    laser_bomb_a_beam_row_01,
    laser_bomb_a_beam_row_02,
    laser_bomb_a_beam_row_03,
    laser_bomb_a_beam_row_04,
    laser_bomb_a_beam_row_05,
    laser_bomb_a_beam_row_06,
    laser_bomb_a_beam_row_07,
    laser_bomb_a_beam_row_08,
    laser_bomb_a_beam_row_09,
    laser_bomb_a_beam_row_10,
    laser_bomb_a_beam_row_11,
    laser_bomb_b_base_frames,
    laser_bomb_b_muzzle_frames,
    laser_bomb_b_tip_frames,
    laser_bomb_b_impact_frames,
    laser_bomb_b_beam_frames,
    laser_bomb_b_beam_frame_07,
    laser_bomb_b_beam_frame_06,
    laser_bomb_b_beam_frame_05,
    laser_bomb_b_beam_frame_04,
    laser_bomb_b_beam_frame_03,
    laser_bomb_b_beam_frame_02,
    laser_bomb_b_beam_frame_01,
    laser_bomb_b_beam_frame_00,
    laser_bomb_b_beam_table,
    laser_bomb_b_beam_row_00,
    laser_bomb_b_beam_row_01,
    laser_bomb_b_beam_row_02,
    laser_bomb_b_beam_row_03,
    laser_bomb_b_beam_row_04,
    laser_bomb_b_beam_row_05,
    laser_bomb_b_beam_row_06,
    laser_bomb_b_beam_row_07,
    laser_bomb_b_beam_row_08,
    laser_bomb_b_beam_row_09,
    laser_bomb_b_beam_row_10,
    laser_bomb_b_beam_row_11,
    laser_bomb_template,
    laser_bomb_segment_template,
};

void *replay_blocks_weapon_levels[] = {
    player_shot_levels_0,
    player_laser_levels_0,
    player_shot_levels_1,
    player_laser_levels_1,
    player_shot_levels_2,
    player_laser_levels_2,
    player_shot_levels_3,
    player_laser_levels_3,
    player_shot_levels_4,
    player_laser_levels_4,
    player_shot_levels_5,
    player_laser_levels_5,
};

s32 replay_block_sizes_weapon_levels[] = {
    10, 10, 10, 10, 10, 10, 10, 10,
    10, 10, 10, 10,
};

typedef struct {
    u8 pad[0x3511];
    s8 data[0x2000];
} Src;

void replay_text_layer_load(const Src *src);

typedef struct {
    f32 v[4];
} Vec4;

typedef struct {
    s16 h[16];
} Row16;

typedef struct {
    u8 a[90];
    u8 b[90];
} Bank90;

typedef struct {
    u8 a[10];
    u8 b[10];
} Bank10;

typedef struct {
    u8 f0000[0xC08];
    u8 padC08[0xE];
    u8 fC16[98];
    u8 fC78[98];
    u8 fCDA[100];
    u8 fD3E[100];
    u8 fDA2[0xD80];
    u8 f1B22[0x600];
    u8 f2122[0x600];
    u8 f2722[0x20];
    u8 f2742[0x20];
    u8 f2762[0x20];
    u8 f2782[0x20];
    u8 f27A2[0x870];
    u8 pad3012[0x1A];
    s32 f302C[16];
    s32 f306C[16];
    s32 f30AC[16];
    s32 f30EC[16];
    u8 pad312C[0xF2];
    u8 f321E[0x48];
    u8 pad3266[0x4E];
    u8 f32B4[90];
    u8 f330E[90];
    u8 f3368[10];
    u8 f3372[10];
    u8 pad337C[0xDC];
    s32 f3458[16];
    s32 f3498[16];
    u8 pad34D8[0x39];
    s8 f3511[0x2000];
    Row16 f5512;
} Buf;

extern u16 g_p2_died_in_hyper;
extern u16 g_p1_died_in_hyper;
extern u16 g_players_stage_clear;
extern u16 g_players_hidden;
extern u16 g_player_shots_disabled;
extern u16 g_bomb_afterglow_timer;
extern u16 g_laser_bomb_sizzle2;
extern u16 g_laser_bomb_sizzle;
extern u16 g_p2_laser_stop_y;
extern u16 g_p1_laser_stop_y;
extern u16 g_p2_y_delta;
extern u16 g_p1_y_delta;
extern u16 g_player_laser_count;
extern u16 g_player_shot_count;
extern u16 g_laser_bomb_hit_flag;
extern u16 g_laser_bomb_pushback;
extern s32 g_laser_bomb_hit_entity;
extern u16 g_laser_bomb_hit_position;
extern u16 g_hyper_bullet_speed;
extern u16 g_p2_laser_bomb_active;
extern u16 g_p1_laser_bomb_active;
extern u16 g_p2_loop2_extend_ok;
extern u16 g_p1_loop2_extend_ok;
extern u16 g_p2_stage_bomb_used;
extern u16 g_p1_stage_bomb_used;
extern u16 g_p2_bombs_used;
extern u16 g_p1_bombs_used;
extern u16 g_p2_stage_misses;
extern u16 g_p1_stage_misses;
extern u16 g_p2_death_count;
extern u16 g_p1_death_count;
extern u16 g_p2_continued;
extern u16 g_p1_continued;
extern u16 g_p2_past_first_ship;
extern u16 g_p1_past_first_ship;
extern u16 g_p2_missed;
extern u16 g_p1_missed;
extern u16 g_p2_hyper_ready_anim_delay;
extern u16 g_p1_hyper_ready_anim_delay;
extern s32 g_p2_hyper_ready_sprite;
extern s32 g_p1_hyper_ready_sprite;
extern u16 g_p2_maximum_anim_delay_reset;
extern u16 g_p2_maximum_anim_delay;
extern u16 g_p1_maximum_anim_delay_reset;
extern u16 g_p1_maximum_anim_delay;
extern u16 g_p2_maximum_level;
extern u16 g_p1_maximum_level;
extern s32 g_p2_weapon_level_data_as_s32_a[];
extern s32 g_p2_option_level_data_as_s32_a[];
extern s32 g_p1_weapon_level_data_as_s32_a[];
extern s32 g_p1_option_level_data_as_s32_a[];
extern u16 g_laser_bomb_impact_frame;
extern u8 D_0028E284;
extern u8 D_0028E288;
extern u8 D_0028E2EC;
extern u8 D_0028E304;
extern u8 g_setting_ship_stock;
extern u8 g_setting_extend;
extern u8 g_setting_difficulty;
extern u16 g_frame_mod16;
extern u16 g_frame_mod8;
extern u16 g_frame_mod4;
extern u16 g_frame_mod3;
extern u16 g_frame_mod2;
extern u16 g_game_frame;
extern u16 g_p2_hyper_effect_delay;
extern u16 g_p1_hyper_effect_delay;
extern u16 g_p2_hyper_effect_flag;
extern u16 g_p1_hyper_effect_flag;
extern u16 g_p2_hyper_effect_frame;
extern u16 g_p1_hyper_effect_frame;
extern s32 g_p2_hyper_effect_sprite;
extern s32 g_p1_hyper_effect_sprite;
extern u16 g_score_task_active;
extern u16 g_score_panel_intro;
extern u16 g_hyper_debug_check;
extern u16 g_boss_double_speed;
extern u16 g_hyper_level_hit_scratch;
extern u16 g_hyper_hit_scratch;
extern u16 g_boss_hyper_wait;
extern u16 g_p2_hyper_items_pending;
extern u16 g_p1_hyper_items_pending;
extern u16 g_p2_hyper_items;
extern u16 g_p1_hyper_items;
extern u16 g_p2_hyper_in_effect;
extern u16 g_p1_hyper_in_effect;
extern u16 g_p2_hyper_level;
extern u16 g_p1_hyper_level;
extern u16 g_hyper_text_slide;
extern u16 g_p2_hyper_combo_decay;
extern u16 g_p1_hyper_combo_decay;
extern u16 g_p2_hyper_gauge;
extern u16 g_p1_hyper_gauge;
extern u16 g_p2_hyper_total;
extern u16 g_p1_hyper_total;
extern u16 g_p2_hyper_time;
extern u16 g_p1_hyper_time;
extern u16 g_p2_hyper_active;
extern u16 g_p1_hyper_active;
extern u16 g_p2_shot_hyper_timer;
extern u16 g_p1_shot_hyper_timer;
extern u16 g_p2_laser_hyper_timer;
extern u16 g_p1_laser_hyper_timer;
extern u16 g_p2_max_hits;
extern u16 g_p1_max_hits;
extern u16 g_boss_explosion_flash;
extern u16 g_boss_near_death;
extern u8 *g_boss_hp;
extern s32 g_boss_hp_unit;
extern u16 g_lives_display_move_x;
extern u16 g_lives_display_move_y;
extern u16 g_boss_hp_bar_move_count;
extern s8 g_boss_hp_bar_flags;
extern s32 g_boss_score;
extern s32 g_boss_hit_bonus;
extern u16 g_boss_hit_bonus_timer;
extern s16 g_boss_hit_palette;
extern u16 g_boss_hits;
extern u16 g_boss_hit_anim_count;
extern u16 g_boss_hit_decay_timer;
extern u16 g_p2_laser_hit_step;
extern u16 g_p2_laser_hit_timer;
extern u16 g_p2_hits_shown;
extern u16 g_p2_hits;
extern s32 g_p2_chain_points_shown2;
extern s32 g_p2_chain_points_shown;
extern s32 g_p2_chain_points;
extern u16 g_p2_hit10_anim_count;
extern u16 g_p2_hit10_color_timer;
extern s16 g_p2_hit10_display_timer;
extern u16 g_p2_combo_break_color_timer;
extern u16 g_p2_hit_display_timer;
extern s16 g_p2_chain_points_display_timer;
extern u16 g_p2_combo_timer;
extern s32 g_p2_chain_first_score_shown;
extern s32 g_p2_chain_first_score;
extern u16 g_p1_laser_hit_step;
extern u16 g_p1_laser_hit_timer;
extern u16 g_p1_hits_shown;
extern u16 g_p1_hits;
extern s32 g_p1_chain_points_shown2;
extern s32 g_p1_chain_points_shown;
extern s32 g_p1_chain_points;
extern u16 g_p1_hit10_anim_count;
extern u16 g_p1_hit10_color_timer;
extern s16 g_p1_hit10_display_timer;
extern u16 g_p1_combo_break_color_timer;
extern u16 g_p1_hit_display_timer;
extern s16 g_p1_chain_points_display_timer;
extern u16 g_p1_combo_timer;
extern s32 g_p1_chain_first_score_shown;
extern s32 g_p1_chain_first_score;
extern u16 g_score_player_flag;
extern u16 g_boss_hit_carry;
extern u16 g_max_combo_time;
extern u16 g_p2_combo_at_bomb;
extern u16 g_p1_combo_at_bomb;
extern s32 g_score_scratch;
extern u16 g_max_level_display_timer;
extern s32 g_maximum_text_anim_sprite;
extern u16 g_maximum_text_anim_frame;
extern u16 g_maximum_text_anim_delay;
extern s32 g_hyper_text_anim_sprite;
extern u16 g_hyper_text_anim_frame;
extern u16 g_hyper_text_anim_delay;
extern u8 g_p2_score_panel_flags;
extern u8 g_p1_score_panel_flags;
extern u16 g_score_check_billions;
extern s32 g_score_check_scratch;
extern s32 g_p2_score_pending;
extern s32 g_p1_score_pending;
extern u16 g_p2_extend_setting;
extern u16 g_p1_extend_setting;
extern s32 g_p2_extend_score;
extern s32 g_p1_extend_score;
extern u16 g_p2_score_billions_saved;
extern u16 g_p1_score_billions_saved;
extern u32 g_p2_score_saved;
extern u32 g_p1_score_saved;
extern u16 g_p2_score_digits;
extern u16 g_high_score_digits;
extern u16 g_p1_score_digits;
extern u16 g_high_score_billions;
extern u16 g_p2_score_billions;
extern u16 g_p1_score_billions;
extern s32 g_high_score;
extern u32 g_p2_score;
extern u32 g_p1_score;
extern u16 g_continue_pending_count;
extern u8 g_boss_present;
extern u16 g_enemy_signal_f;
extern u16 g_enemy_signal_e;
extern u16 g_enemy_signal_d;
extern u16 g_enemy_signal_c;
extern u16 g_enemy_signal_b;
extern u16 g_enemy_signal_a;
extern u16 g_enemy_signal_9;
extern u16 g_enemy_signal_8;
extern u16 g_enemy_signal_7;
extern u16 g_enemy_signal_6;
extern u16 g_enemy_signal_5;
extern u16 g_enemy_signal_4;
extern u16 g_enemy_signal_3;
extern u16 g_enemy_signal_2;
extern u16 g_enemy_signal_1;
extern u16 g_enemy_signal_0;
extern u16 g_scroll_line_step;
extern u16 g_scroll_line;
extern u16 g_scroll_line_offset;
extern u8 g_name_entry_player_pad;
extern u8 g_name_entry_player;
extern u16 g_damage_blink_counter;
extern s32 g_play_time;
extern u16 g_p2_lives;
extern u16 g_p1_lives;
extern u16 g_rank_1_16;
extern u16 g_rank_2_16;
extern u16 g_rank_3_16;
extern u16 g_rank_4_16;
extern u16 g_rank_5_16;
extern u16 g_rank_6_16;
extern u16 g_rank_7_16;
extern u16 g_rank_8_16;
extern u16 g_rank_9_16;
extern u16 g_rank_10_16;
extern u16 g_rank_11_16;
extern u16 g_rank_12_16;
extern u16 g_rank_13_16;
extern u16 g_rank_14_16;
extern u16 g_rank_15_16;
extern u16 g_rank;
extern u16 g_true_last_boss;
extern u16 g_game_completed;
extern u16 g_loop;
extern u16 g_stage_x4;
extern u16 g_stage_x2;
extern u16 g_stage;
extern u16 g_two_player_seen;
extern u16 g_two_player_state;
extern u16 g_two_player_game;
extern u16 g_p2_stage_stars_small;
extern u16 g_p2_stage_stars_large;
extern u16 g_p1_stage_stars_small;
extern u16 g_p1_stage_stars_large;
extern u16 g_bee_value_step;
extern u16 g_stage_bees_collected;
extern u16 g_bullet_count;
extern u16 g_p2_maximum_value[16];
extern u16 g_p2_maximum_count[];
extern u16 g_p1_maximum_value[];
extern u16 g_p1_maximum_count[];
extern u8 g_p2_afterimage_sprites[64];
extern s32 g_p1_afterimage_sprites[];
extern u8 g_p2_afterimage_positions[64];
extern s32 g_p1_afterimage_positions[];
extern u16 g_bomb_entities[24];
extern u8 D_0029D710[];
extern u8 D_0029D730[];
extern u8 D_0029D750[];
extern u8 D_0029D770[];
extern u8 g_p2_laser_entities[];
extern u8 g_p1_laser_entities[];
extern u8 D_0029E390[];
extern u8 g_p2_options[];
extern u8 g_p1_options[];
extern u8 g_player2[];
extern u8 g_player1[];
extern u8 g_text_layer[];
extern s32 g_p2_position_trail[];
extern s32 g_p1_position_trail[];
extern Bank10 g_p1_score_extra_cell_as_Bank10;
extern Bank90 g_p1_score_cells_as_Bank90;
extern u8 g_player_slots[];
extern u8 g_pickups[];
extern u16 D_006C58AA[];
extern u16 D_006C58B0[];
extern u16 D_006C58B2[];
extern u16 D_006C58B4[];
extern u16 D_006C58B6[];
extern u16 D_006C58B8[];
extern u16 D_006C58BA[];
extern u16 D_006C58BC[];
extern u16 D_006C58BE[];
extern u16 D_006C58C0[];
extern u16 D_006C58C2[];
extern u16 D_006C58C6[];
extern u16 D_006C58C8[];
extern u16 D_006C58CA[];
extern u16 D_006C58CC[];
extern u16 D_006C58CE[];
extern u16 D_006C58D0[488];
extern u16 D_006C58D2[];
extern u16 D_006C58D4[];
extern u16 D_006C58D6[];
void replay_snapshot_save(Buf *buf) {
    s32 i;
    s32 v;
    u8 *p = (u8 *)buf;

    printf("replay size[%d]\n", 0x5534);
    for (i = 0; i < 0xC08; i++) {
        buf->f0000[i] = g_pickups[i];
    }
    *(u16 *)(p + 0xC08) = g_bullet_count;
    *(u16 *)(p + 0xC0A) = g_stage_bees_collected;
    *(u16 *)(p + 0xC0C) = g_bee_value_step;
    *(u16 *)(p + 0xC0E) = g_p1_stage_stars_large;
    *(u16 *)(p + 0xC10) = g_p1_stage_stars_small;
    *(u16 *)(p + 0xC12) = g_p2_stage_stars_large;
    *(u16 *)(p + 0xC14) = g_p2_stage_stars_small;
    for (i = 0; i < 98; i++) {
        buf->fC16[i] = ((u8 *)g_player1)[i];
        buf->fC78[i] = ((u8 *)g_player2)[i];
    }
    for (i = 0; i < 100; i++) {
        buf->fCDA[i] = g_p1_options[i];
        buf->fD3E[i] = g_p2_options[i];
    }
    for (i = 0; i < 0xD80; i++) {
        buf->fDA2[i] = D_0029E390[i];
    }
    for (i = 0; i < 0x600; i++) {
        buf->f1B22[i] = g_p1_laser_entities[i];
        buf->f2122[i] = g_p2_laser_entities[i];
    }
    for (i = 0; i < 0x20; i++) {
        buf->f2722[i] = D_0029D770[i];
        buf->f2742[i] = D_0029D750[i];
    }
    for (i = 0; i < 0x20; i++) {
        buf->f2762[i] = D_0029D730[i];
        buf->f2782[i] = D_0029D710[i];
    }
    for (i = 0; i < 0x870; i++) {
        buf->f27A2[i] = ((u8 *)g_bomb_entities)[i];
    }
    *(u16 *)(p + 0x301A) = g_laser_bomb_impact_frame;
    *(s32 *)(p + 0x301C) = g_p1_weapon_level_data_as_s32_a[0];
    *(s32 *)(p + 0x3024) = g_p2_weapon_level_data_as_s32_a[0];
    *(s32 *)(p + 0x3020) = g_p1_option_level_data_as_s32_a[0];
    *(s32 *)(p + 0x3028) = g_p2_option_level_data_as_s32_a[0];
    for (i = 0; i < 16; i++) {
        buf->f302C[i] = g_p1_afterimage_positions[i];
        buf->f306C[i] = ((s32 *)g_p2_afterimage_positions)[i];
        buf->f30AC[i] = g_p1_afterimage_sprites[i];
        buf->f30EC[i] = ((s32 *)g_p2_afterimage_sprites)[i];
    }
    *(Vec4 *)(p + 0x312C) = *(Vec4 *)((f32 *)g_p1_maximum_value);
    *(Vec4 *)(p + 0x313C) = *(Vec4 *)((f32 *)g_p2_maximum_value);
    *(u16 *)(p + 0x314C) = g_p1_maximum_level;
    *(u16 *)(p + 0x314E) = g_p2_maximum_level;
    *(u16 *)(p + 0x3150) = g_p1_maximum_anim_delay;
    *(u16 *)(p + 0x3152) = g_p1_maximum_anim_delay_reset;
    *(u16 *)(p + 0x3154) = g_p2_maximum_anim_delay;
    *(u16 *)(p + 0x3156) = g_p2_maximum_anim_delay_reset;
    *(s32 *)(p + 0x3158) = g_p1_hyper_ready_sprite;
    *(s32 *)(p + 0x315C) = g_p2_hyper_ready_sprite;
    *(u16 *)(p + 0x3160) = g_p1_hyper_ready_anim_delay;
    *(u16 *)(p + 0x3162) = g_p2_hyper_ready_anim_delay;
    *(u16 *)(p + 0x3164) = g_p1_missed;
    *(u16 *)(p + 0x3166) = g_p2_missed;
    *(u16 *)(p + 0x3168) = g_p1_past_first_ship;
    *(u16 *)(p + 0x316A) = g_p2_past_first_ship;
    *(u16 *)(p + 0x316C) = g_p1_continued;
    *(u16 *)(p + 0x316E) = g_p2_continued;
    *(u16 *)(p + 0x3170) = g_p1_death_count;
    *(u16 *)(p + 0x3172) = g_p2_death_count;
    *(u16 *)(p + 0x3174) = g_p1_stage_misses;
    *(u16 *)(p + 0x3176) = g_p2_stage_misses;
    *(u16 *)(p + 0x3178) = g_p1_bombs_used;
    *(u16 *)(p + 0x317A) = g_p2_bombs_used;
    *(u16 *)(p + 0x317C) = g_p1_stage_bomb_used;
    *(u16 *)(p + 0x317E) = g_p2_stage_bomb_used;
    *(u16 *)(p + 0x3180) = g_p1_loop2_extend_ok;
    *(u16 *)(p + 0x3182) = g_p2_loop2_extend_ok;
    *(u16 *)(p + 0x3184) = g_p1_laser_bomb_active;
    *(u16 *)(p + 0x3186) = g_p2_laser_bomb_active;
    *(u16 *)(p + 0x3188) = g_hyper_bullet_speed;
    *(u16 *)(p + 0x318A) = g_laser_bomb_hit_position;
    *(s32 *)(p + 0x318C) = g_laser_bomb_hit_entity;
    *(u16 *)(p + 0x3190) = g_laser_bomb_pushback;
    *(u16 *)(p + 0x3192) = g_laser_bomb_hit_flag;
    *(u16 *)(p + 0x3194) = g_player_shot_count;
    *(u16 *)(p + 0x3196) = g_player_laser_count;
    *(u16 *)(p + 0x3198) = g_p1_y_delta;
    *(u16 *)(p + 0x319A) = g_p2_y_delta;
    *(u16 *)(p + 0x319C) = g_p1_laser_stop_y;
    *(u16 *)(p + 0x319E) = g_p2_laser_stop_y;
    *(u16 *)(p + 0x31A0) = g_laser_bomb_sizzle;
    *(u16 *)(p + 0x31A2) = g_laser_bomb_sizzle2;
    *(u16 *)(p + 0x31A4) = g_bomb_afterglow_timer;
    *(u16 *)(p + 0x31A6) = g_player_shots_disabled;
    *(u16 *)(p + 0x31A8) = g_players_hidden;
    *(u16 *)(p + 0x31AA) = g_players_stage_clear;
    *(u16 *)(p + 0x31AC) = g_p1_died_in_hyper;
    *(u16 *)(p + 0x31AE) = g_p2_died_in_hyper;
    *(u16 *)(p + 0x31B0) = g_two_player_game;
    *(u16 *)(p + 0x31B2) = g_two_player_state;
    *(u16 *)(p + 0x31B4) = g_two_player_seen;
    *(u16 *)(p + 0x31B6) = g_stage;
    *(u16 *)(p + 0x31B8) = g_stage_x2;
    *(u16 *)(p + 0x31BA) = g_stage_x4;
    *(u16 *)(p + 0x31BC) = g_loop;
    *(u16 *)(p + 0x31BE) = g_game_completed;
    *(u16 *)(p + 0x31C0) = g_true_last_boss;
    *(u16 *)(p + 0x31C2) = g_rank;
    *(u16 *)(p + 0x31C4) = g_rank_15_16;
    *(u16 *)(p + 0x31C6) = g_rank_14_16;
    *(u16 *)(p + 0x31C8) = g_rank_13_16;
    *(u16 *)(p + 0x31CA) = g_rank_12_16;
    *(u16 *)(p + 0x31CC) = g_rank_11_16;
    *(u16 *)(p + 0x31CE) = g_rank_10_16;
    *(u16 *)(p + 0x31D0) = g_rank_9_16;
    *(u16 *)(p + 0x31D2) = g_rank_8_16;
    *(u16 *)(p + 0x31D4) = g_rank_7_16;
    *(u16 *)(p + 0x31D6) = g_rank_6_16;
    *(u16 *)(p + 0x31D8) = g_rank_5_16;
    *(u16 *)(p + 0x31DA) = g_rank_4_16;
    *(u16 *)(p + 0x31DC) = g_rank_3_16;
    *(u16 *)(p + 0x31DE) = g_rank_2_16;
    *(u16 *)(p + 0x31E0) = g_rank_1_16;
    *(u16 *)(p + 0x31E2) = g_p1_lives;
    *(u16 *)(p + 0x31E4) = g_p2_lives;
    *(s32 *)(p + 0x31E8) = g_play_time;
    *(u16 *)(p + 0x31EC) = g_damage_blink_counter;
    p[0x31EE] = g_name_entry_player;
    p[0x31EF] = g_name_entry_player_pad;
    *(u16 *)(p + 0x31F0) = g_scroll_line;
    *(u16 *)(p + 0x31F2) = g_scroll_line_step;
    *(u16 *)(p + 0x31F4) = g_scroll_line_offset;
    *(u16 *)(p + 0x31FC) = g_enemy_signal_0;
    *(u16 *)(p + 0x31FE) = g_enemy_signal_1;
    *(u16 *)(p + 0x3200) = g_enemy_signal_2;
    *(u16 *)(p + 0x3202) = g_enemy_signal_3;
    *(u16 *)(p + 0x3204) = g_enemy_signal_4;
    *(u16 *)(p + 0x3206) = g_enemy_signal_5;
    *(u16 *)(p + 0x3208) = g_enemy_signal_6;
    *(u16 *)(p + 0x320A) = g_enemy_signal_7;
    *(u16 *)(p + 0x320C) = g_enemy_signal_8;
    *(u16 *)(p + 0x320E) = g_enemy_signal_9;
    *(u16 *)(p + 0x3210) = g_enemy_signal_a;
    *(u16 *)(p + 0x3212) = g_enemy_signal_b;
    *(u16 *)(p + 0x3214) = g_enemy_signal_c;
    *(u16 *)(p + 0x3216) = g_enemy_signal_d;
    *(u16 *)(p + 0x3218) = g_enemy_signal_e;
    *(u16 *)(p + 0x321A) = g_enemy_signal_f;
    *(u16 *)(p + 0x321C) = (*(u16 *)&g_boss_present);
    for (i = 0; i < 0x48; i++) {
        buf->f321E[i] = g_player_slots[i];
    }
    *(u16 *)(p + 0x3266) = g_continue_pending_count;
    *(s32 *)(p + 0x327C) = (s32)g_p1_score;
    *(s32 *)(p + 0x3280) = (s32)g_p2_score;
    *(s32 *)(p + 0x3284) = g_high_score;
    *(u16 *)(p + 0x3288) = g_p1_score_billions;
    *(u16 *)(p + 0x328A) = g_p2_score_billions;
    *(u16 *)(p + 0x328C) = g_high_score_billions;
    *(u16 *)(p + 0x328E) = g_p1_score_digits;
    *(u16 *)(p + 0x3290) = g_high_score_digits;
    *(u16 *)(p + 0x3292) = g_p2_score_digits;
    *(s32 *)(p + 0x3294) = (s32)g_p1_score_saved;
    *(s32 *)(p + 0x3298) = (s32)g_p2_score_saved;
    *(u16 *)(p + 0x329C) = g_p1_score_billions_saved;
    *(u16 *)(p + 0x329E) = g_p2_score_billions_saved;
    *(s32 *)(p + 0x32A0) = g_p1_extend_score;
    *(s32 *)(p + 0x32A4) = g_p2_extend_score;
    *(u16 *)(p + 0x32A8) = g_p1_extend_setting;
    *(u16 *)(p + 0x32AA) = g_p2_extend_setting;
    *(s32 *)(p + 0x32AC) = g_p1_score_pending;
    *(s32 *)(p + 0x32B0) = g_p2_score_pending;
    for (i = 0; i < 90; i++) {
        buf->f32B4[i] = g_p1_score_cells_as_Bank90.a[i];
    }
    for (i = 0; i < 90; i++) {
        buf->f330E[i] = g_p1_score_cells_as_Bank90.b[i];
    }
    for (i = 0; i < 10; i++) {
        buf->f3368[i] = g_p1_score_extra_cell_as_Bank10.a[i];
    }
    for (i = 0; i < 10; i++) {
        buf->f3372[i] = g_p1_score_extra_cell_as_Bank10.b[i];
    }
    *(s32 *)(p + 0x337C) = g_score_check_scratch;
    *(u16 *)(p + 0x3380) = g_score_check_billions;
    p[0x3382] = g_p1_score_panel_flags;
    p[0x3383] = g_p2_score_panel_flags;
    *(u16 *)(p + 0x3384) = g_hyper_text_anim_delay;
    *(u16 *)(p + 0x3386) = g_hyper_text_anim_frame;
    *(s32 *)(p + 0x3388) = g_hyper_text_anim_sprite;
    *(u16 *)(p + 0x338C) = g_maximum_text_anim_delay;
    *(u16 *)(p + 0x338E) = g_maximum_text_anim_frame;
    *(s32 *)(p + 0x3390) = g_maximum_text_anim_sprite;
    *(u16 *)(p + 0x3394) = g_max_level_display_timer;
    *(s32 *)(p + 0x3398) = g_score_scratch;
    *(u16 *)(p + 0x339C) = g_p1_combo_at_bomb;
    *(u16 *)(p + 0x339E) = g_p2_combo_at_bomb;
    *(u16 *)(p + 0x33A0) = g_max_combo_time;
    *(u16 *)(p + 0x33A2) = g_boss_hit_carry;
    *(u16 *)(p + 0x33A4) = g_score_player_flag;
    *(s32 *)(p + 0x33A8) = g_p1_chain_first_score;
    *(s32 *)(p + 0x33AC) = g_p1_chain_first_score_shown;
    *(u16 *)(p + 0x33B0) = g_p1_combo_timer;
    *(u16 *)(p + 0x33B2) = (*(u16 *)&g_p1_chain_points_display_timer);
    *(u16 *)(p + 0x33B4) = g_p1_hit_display_timer;
    *(u16 *)(p + 0x33B6) = g_p1_combo_break_color_timer;
    *(u16 *)(p + 0x33B8) = (*(u16 *)&g_p1_hit10_display_timer);
    *(u16 *)(p + 0x33BA) = g_p1_hit10_color_timer;
    *(u16 *)(p + 0x33BC) = g_p1_hit10_anim_count;
    *(s32 *)(p + 0x33C0) = g_p1_chain_points;
    *(s32 *)(p + 0x33C4) = g_p1_chain_points_shown;
    *(s32 *)(p + 0x33C8) = g_p1_chain_points_shown2;
    *(u16 *)(p + 0x33CC) = g_p1_hits;
    *(u16 *)(p + 0x33CE) = g_p1_hits_shown;
    *(u16 *)(p + 0x33D0) = g_p1_laser_hit_timer;
    *(u16 *)(p + 0x33D2) = g_p1_laser_hit_step;
    *(s32 *)(p + 0x33D4) = g_p2_chain_first_score;
    *(s32 *)(p + 0x33D8) = g_p2_chain_first_score_shown;
    *(u16 *)(p + 0x33DC) = g_p2_combo_timer;
    *(u16 *)(p + 0x33DE) = (*(u16 *)&g_p2_chain_points_display_timer);
    *(u16 *)(p + 0x33E0) = g_p2_hit_display_timer;
    *(u16 *)(p + 0x33E2) = g_p2_combo_break_color_timer;
    *(u16 *)(p + 0x33E4) = (*(u16 *)&g_p2_hit10_display_timer);
    *(u16 *)(p + 0x33E6) = g_p2_hit10_color_timer;
    *(u16 *)(p + 0x33E8) = g_p2_hit10_anim_count;
    *(s32 *)(p + 0x33EC) = g_p2_chain_points;
    *(s32 *)(p + 0x33F0) = g_p2_chain_points_shown;
    *(s32 *)(p + 0x33F4) = g_p2_chain_points_shown2;
    *(u16 *)(p + 0x33F8) = g_p2_hits;
    *(u16 *)(p + 0x33FA) = g_p2_hits_shown;
    *(u16 *)(p + 0x33FC) = g_p2_laser_hit_timer;
    *(u16 *)(p + 0x33FE) = g_p2_laser_hit_step;
    *(u16 *)(p + 0x3400) = g_boss_hit_decay_timer;
    *(u16 *)(p + 0x3402) = g_boss_hit_anim_count;
    *(u16 *)(p + 0x3404) = g_boss_hits;
    *(u16 *)(p + 0x3406) = (*(u16 *)&g_boss_hit_palette);
    *(u16 *)(p + 0x3408) = g_boss_hit_bonus_timer;
    *(s32 *)(p + 0x340C) = g_boss_hit_bonus;
    *(s32 *)(p + 0x3410) = g_boss_score;
    *(u16 *)(p + 0x3414) = (*(u16 *)&g_boss_hp_bar_flags);
    *(u16 *)(p + 0x3416) = g_boss_hp_bar_move_count;
    *(u16 *)(p + 0x3418) = g_lives_display_move_y;
    *(u16 *)(p + 0x341A) = g_lives_display_move_x;
    *(s32 *)(p + 0x341C) = g_boss_hp_unit;
    *(s32 *)(p + 0x3420) = (*(s32 *)&g_boss_hp);
    *(u16 *)(p + 0x3424) = g_boss_near_death;
    *(u16 *)(p + 0x3426) = g_boss_explosion_flash;
    *(u16 *)(p + 0x3428) = g_p1_max_hits;
    *(u16 *)(p + 0x342A) = g_p2_max_hits;
    *(u16 *)(p + 0x342C) = g_p1_laser_hyper_timer;
    *(u16 *)(p + 0x342E) = g_p2_laser_hyper_timer;
    *(u16 *)(p + 0x3430) = g_p1_shot_hyper_timer;
    *(u16 *)(p + 0x3432) = g_p2_shot_hyper_timer;
    *(u16 *)(p + 0x3434) = g_p1_hyper_active;
    *(u16 *)(p + 0x3436) = g_p2_hyper_active;
    *(u16 *)(p + 0x3438) = g_p1_hyper_time;
    *(u16 *)(p + 0x343A) = g_p2_hyper_time;
    *(u16 *)(p + 0x343C) = g_p1_hyper_total;
    *(u16 *)(p + 0x343E) = g_p2_hyper_total;
    *(u16 *)(p + 0x3440) = g_p1_hyper_gauge;
    *(u16 *)(p + 0x3442) = g_p2_hyper_gauge;
    *(u16 *)(p + 0x3444) = g_p1_hyper_combo_decay;
    *(u16 *)(p + 0x3446) = g_p2_hyper_combo_decay;
    *(u16 *)(p + 0x3448) = g_hyper_text_slide;
    *(u16 *)(p + 0x344A) = g_p1_hyper_level;
    *(u16 *)(p + 0x344C) = g_p2_hyper_level;
    *(u16 *)(p + 0x344E) = g_p1_hyper_in_effect;
    *(u16 *)(p + 0x3450) = g_p2_hyper_in_effect;
    *(u16 *)(p + 0x3452) = g_p1_hyper_items;
    *(u16 *)(p + 0x3454) = g_p2_hyper_items;
    for (i = 0; i < 16; i++) {
        buf->f3458[i] = g_p1_position_trail[i];
    }
    for (i = 0; i < 16; i++) {
        buf->f3498[i] = g_p2_position_trail[i];
    }
    *(u16 *)(p + 0x34D8) = g_p1_hyper_items_pending;
    *(u16 *)(p + 0x34DA) = g_p2_hyper_items_pending;
    *(u16 *)(p + 0x34DC) = g_boss_hyper_wait;
    *(u16 *)(p + 0x34DE) = g_hyper_hit_scratch;
    *(u16 *)(p + 0x34E0) = g_hyper_level_hit_scratch;
    *(u16 *)(p + 0x34E2) = g_boss_double_speed;
    *(u16 *)(p + 0x34E4) = g_hyper_debug_check;
    *(u16 *)(p + 0x34E6) = g_score_panel_intro;
    *(u16 *)(p + 0x34E8) = g_score_task_active;
    *(s32 *)(p + 0x34EC) = g_p1_hyper_effect_sprite;
    *(s32 *)(p + 0x34F0) = g_p2_hyper_effect_sprite;
    *(u16 *)(p + 0x34F4) = g_p1_hyper_effect_frame;
    *(u16 *)(p + 0x34F6) = g_p2_hyper_effect_frame;
    *(u16 *)(p + 0x34F8) = g_p1_hyper_effect_flag;
    *(u16 *)(p + 0x34FA) = g_p2_hyper_effect_flag;
    *(u16 *)(p + 0x34FC) = g_p1_hyper_effect_delay;
    *(u16 *)(p + 0x34FE) = g_p2_hyper_effect_delay;
    p[0x350C] = g_setting_difficulty;
    p[0x350D] = g_setting_extend;
    p[0x350E] = g_setting_ship_stock;
    p[0x350F] = D_0028E2EC;
    p[0x3510] = D_0028E304;
    *(u16 *)(p + 0x3500) = g_game_frame;
    *(u16 *)(p + 0x3502) = g_frame_mod2;
    *(u16 *)(p + 0x3504) = g_frame_mod3;
    *(u16 *)(p + 0x3506) = g_frame_mod4;
    *(u16 *)(p + 0x3508) = g_frame_mod8;
    *(u16 *)(p + 0x350A) = g_frame_mod16;
    *(Row16 *)(p + 0x5512) = *(Row16 *)&g_ground_state;
    for (i = 0; i < 0x2000; i++) {
        buf->f3511[i] = ((s8 *)g_text_layer)[i];
    }
    p[0x5532] = D_0028E288;
    p[0x5533] = D_0028E284;
    ((s16 *)D_006C58D6)[0] = MAIN_OR_DEATH_LABEL(0xCB, 0x6E);
    ((s16 *)D_006C58AA)[0] = g_setting_difficulty;
    ((s16 *)D_006C58C8)[0] = g_setting_extend;
    if (*(s16 *)((u8 *)g_player1) < 0) {
        D_006C58C6[0] = g_p1_lives;
    } else {
        D_006C58C6[0] = g_p2_lives;
    }
    ((s16 *)D_006C58B8)[0] = 0;
    ((s16 *)D_006C58C2)[0] = 1;
    ((s16 *)D_006C58BA)[0] = 0;
#ifdef DEATH_LABEL
    D_006C58D4[0] = 0;
#endif
    D_006C58C0[0] = g_rank;
    if (*(s16 *)((u8 *)g_player1) < 0) {
#ifndef DEATH_LABEL
        D_006C58D4[0] = g_p1_death_count;
        if (D_006C58D4[0] > 8) {
            D_006C58D4[0] = 8;
        }
#endif
        v = PLAYER(((u8 *)g_player1))->shot_power.h;
        if (v != 0) {
            v /= 2;
        }
        D_006C58B2[0] = v;
        v = PLAYER(((u8 *)g_player1))->laser_power.h;
        if (v != 0) {
            v /= 2;
        }
        D_006C58B0[0] = v;
        D_006C58D2[0] = g_p1_hyper_total;
        if (g_p1_hyper_gauge != 0) {
            v = (u16)g_p1_hyper_gauge * 100 / 2400;
        } else {
            v = MAIN_OR_DEATH_LABEL(0, 1);
        }
        v += g_p1_hyper_items_pending * 100;
        D_006C58BE[0] = v;
        if (g_p1_hyper_time != 0) {
            v = (u16)g_p1_hyper_time * 100 / 2400;
        } else {
            v = 0;
        }
        ((s16 *)D_006C58CC)[0] = v;
        if (g_p1_hyper_in_effect != 0) {
            ((s16 *)D_006C58CA)[0] = 1;
            D_006C58BC[0] = g_p1_hyper_level;
        } else {
            ((s16 *)D_006C58CA)[0] = 0;
            ((s16 *)D_006C58CC)[0] = 0;
            D_006C58BC[0] = g_p1_hyper_items;
        }
        D_006C58B4[0] = PLAYER(((u8 *)g_player1))->bombs.b.capacity;
        if (D_006C58B4[0] != 0) {
            D_006C58B4[0] -= 1;
        }
        ((s16 *)D_006C58B6)[0] = PLAYER(((u8 *)g_player1))->bombs.b.count;
#ifdef DEATH_LABEL
        if (((u8 *)g_player1)[0] & 2) {
            ((s16 *)D_006C58B6)[0] = 7;
        }
#else
        if ((((u8 *)g_player1)[0] & 2) && !(PLAYER(((u8 *)g_player1))->flags.b[1] & 0x40) && *(u16 *)((f32 *)g_p1_maximum_value) != 0) {
            ((s16 *)D_006C58B6)[0] = 7;
        }
        if (*(u8 *)((u8 *)g_player1) & 2) {
            printf("------1  on-\n");
        } else {
            printf("------1  off-\n");
        }
        if (PLAYER(((u8 *)g_player1))->flags.b[1] & 0x40) {
            printf("------6  on-\n");
        } else {
            printf("------6  off-\n");
        }
        printf("------[%d]\n", *(u16 *)((f32 *)g_p1_maximum_value));
#endif
        if (g_p1_maximum_count[0] != 0) {
            v = (u16)g_p1_maximum_count[0] - 1;
        } else {
            v = 0;
        }
        ((s16 *)D_006C58D0)[0] = v;
        if (g_p1_maximum_level != 0) {
            v = (u16)g_p1_maximum_level / 4;
        } else {
            v = 0;
        }
        ((s16 *)D_006C58CE)[0] = v;
    } else {
#ifndef DEATH_LABEL
        D_006C58D4[0] = g_p2_death_count;
        if (D_006C58D4[0] > 8) {
            D_006C58D4[0] = 8;
        }
#endif
        v = PLAYER(((u8 *)g_player2))->shot_power.h;
        if (v != 0) {
            v /= 2;
        }
        D_006C58B2[0] = v;
        v = PLAYER(((u8 *)g_player2))->laser_power.h;
        if (v != 0) {
            v /= 2;
        }
        D_006C58B0[0] = v;
        D_006C58D2[0] = g_p2_hyper_total;
        if (g_p2_hyper_gauge != 0) {
            v = (u16)g_p2_hyper_gauge * 100 / 2400;
        } else {
            v = MAIN_OR_DEATH_LABEL(0, 1);
        }
        v += g_p2_hyper_items_pending * 100;
        D_006C58BE[0] = v;
        if (g_p2_hyper_time != 0) {
            v = (u16)g_p2_hyper_time * 100 / 2400;
        } else {
            v = 0;
        }
        ((s16 *)D_006C58CC)[0] = v;
        if (g_p2_hyper_in_effect != 0) {
            ((s16 *)D_006C58CA)[0] = 1;
            D_006C58BC[0] = g_p2_hyper_level;
        } else {
            ((s16 *)D_006C58CA)[0] = 0;
            ((s16 *)D_006C58CC)[0] = 0;
            D_006C58BC[0] = g_p2_hyper_items;
        }
        D_006C58B4[0] = PLAYER(((u8 *)g_player2))->bombs.b.capacity;
        if (D_006C58B4[0] != 0) {
            D_006C58B4[0] -= 1;
        }
        ((s16 *)D_006C58B6)[0] = PLAYER(((u8 *)g_player2))->bombs.b.count;
#ifdef DEATH_LABEL
        if (((u8 *)g_player2)[0] & 2) {
            ((s16 *)D_006C58B6)[0] = 7;
        }
#else
        if ((((u8 *)g_player2)[0] & 2) && !(PLAYER(((u8 *)g_player2))->flags.b[1] & 0x40) && *(u16 *)((f32 *)g_p2_maximum_value) != 0) {
            ((s16 *)D_006C58B6)[0] = 7;
        }
        if (*(u8 *)((u8 *)g_player2) & 2) {
            printf("------1  on-\n");
        } else {
            printf("------1  off-\n");
        }
        if (PLAYER(((u8 *)g_player2))->flags.b[1] & 0x40) {
            printf("------6  on-\n");
        } else {
            printf("------6  off-\n");
        }
        printf("------[%d]\n", *(u16 *)((f32 *)g_p2_maximum_value));
#endif
        if (g_p2_maximum_count[0] != 0) {
            v = (u16)g_p2_maximum_count[0] - 1;
        } else {
            v = 0;
        }
        ((s16 *)D_006C58D0)[0] = v;
        if (g_p2_maximum_level != 0) {
            v = (u16)g_p2_maximum_level / 4;
        } else {
            v = 0;
        }
        ((s16 *)D_006C58CE)[0] = v;
    }
}

typedef struct {
    u8 pad[0x302C];
    s32 a[16];
    s32 b[16];
    s32 c[16];
    s32 d[16];
} QuadSrc;

typedef struct {
    u8 pad[0x3458];
    s32 a[16];
    s32 b[16];
} PairSrc;

typedef struct {
    u8 pad[0x5512];
    Row16 row;
} RowSrc;

void replay_snapshot_load(u8 *p) {
    s32 i;

    for (i = 0; i < 0xC08; i++) {
        g_pickups[i] = p[0x0 + i];
    }
    g_bullet_count = *(u16 *)(p + 0xC08);
    g_stage_bees_collected = *(u16 *)(p + 0xC0A);
    g_bee_value_step = *(u16 *)(p + 0xC0C);
    g_p1_stage_stars_large = *(u16 *)(p + 0xC0E);
    g_p1_stage_stars_small = *(u16 *)(p + 0xC10);
    g_p2_stage_stars_large = *(u16 *)(p + 0xC12);
    g_p2_stage_stars_small = *(u16 *)(p + 0xC14);
    for (i = 0; i < 98; i++) {
        ((u8 *)g_player1)[i] = p[0xC16 + i];
        ((u8 *)g_player2)[i] = p[0xC78 + i];
    }
    for (i = 0; i < 100; i++) {
        g_p1_options[i] = p[0xCDA + i];
        g_p2_options[i] = p[0xD3E + i];
    }
    for (i = 0; i < 0xD80; i++) {
        D_0029E390[i] = p[0xDA2 + i];
    }
    for (i = 0; i < 0x600; i++) {
        g_p1_laser_entities[i] = p[0x1B22 + i];
        g_p2_laser_entities[i] = p[0x2122 + i];
    }
    for (i = 0; i < 0x20; i++) {
        D_0029D770[i] = p[0x2722 + i];
        D_0029D750[i] = p[0x2742 + i];
    }
    for (i = 0; i < 0x20; i++) {
        D_0029D730[i] = p[0x2762 + i];
        D_0029D710[i] = p[0x2782 + i];
    }
    for (i = 0; i < 0x870; i++) {
        ((u8 *)g_bomb_entities)[i] = p[0x27A2 + i];
    }
    g_laser_bomb_impact_frame = *(u16 *)(p + 0x301A);
    for (i = 0; i < 16; i++) {
        g_p1_afterimage_positions[i] = ((QuadSrc *)p)->a[i];
        ((s32 *)g_p2_afterimage_positions)[i] = ((QuadSrc *)p)->b[i];
        g_p1_afterimage_sprites[i] = ((QuadSrc *)p)->c[i];
        ((s32 *)g_p2_afterimage_sprites)[i] = ((QuadSrc *)p)->d[i];
    }
    g_p1_weapon_level_data_as_s32_a[0] = *(s32 *)(p + 0x301C);
    g_p2_weapon_level_data_as_s32_a[0] = *(s32 *)(p + 0x3024);
    g_p1_option_level_data_as_s32_a[0] = *(s32 *)(p + 0x3020);
    g_p2_option_level_data_as_s32_a[0] = *(s32 *)(p + 0x3028);
    *(Vec4 *)((u8 *)g_p1_maximum_value) = *(Vec4 *)(p + 0x312C);
    *(Vec4 *)((u8 *)g_p2_maximum_value) = *(Vec4 *)(p + 0x313C);
    g_p1_maximum_level = *(u16 *)(p + 0x314C);
    g_p2_maximum_level = *(u16 *)(p + 0x314E);
    g_p1_maximum_anim_delay = *(u16 *)(p + 0x3150);
    g_p1_maximum_anim_delay_reset = *(u16 *)(p + 0x3152);
    g_p2_maximum_anim_delay = *(u16 *)(p + 0x3154);
    g_p2_maximum_anim_delay_reset = *(u16 *)(p + 0x3156);
    g_p1_hyper_ready_sprite = *(s32 *)(p + 0x3158);
    g_p2_hyper_ready_sprite = *(s32 *)(p + 0x315C);
    g_p1_hyper_ready_anim_delay = *(u16 *)(p + 0x3160);
    g_p2_hyper_ready_anim_delay = *(u16 *)(p + 0x3162);
    g_p1_missed = *(u16 *)(p + 0x3164);
    g_p2_missed = *(u16 *)(p + 0x3166);
    g_p1_past_first_ship = *(u16 *)(p + 0x3168);
    g_p2_past_first_ship = *(u16 *)(p + 0x316A);
    g_p1_continued = *(u16 *)(p + 0x316C);
    g_p2_continued = *(u16 *)(p + 0x316E);
    g_p1_death_count = *(u16 *)(p + 0x3170);
    g_p2_death_count = *(u16 *)(p + 0x3172);
    g_p1_stage_misses = *(u16 *)(p + 0x3174);
    g_p2_stage_misses = *(u16 *)(p + 0x3176);
    g_p1_bombs_used = *(u16 *)(p + 0x3178);
    g_p2_bombs_used = *(u16 *)(p + 0x317A);
    g_p1_stage_bomb_used = *(u16 *)(p + 0x317C);
    g_p2_stage_bomb_used = *(u16 *)(p + 0x317E);
    g_p1_loop2_extend_ok = *(u16 *)(p + 0x3180);
    g_p2_loop2_extend_ok = *(u16 *)(p + 0x3182);
    g_p1_laser_bomb_active = *(u16 *)(p + 0x3184);
    g_p2_laser_bomb_active = *(u16 *)(p + 0x3186);
    g_hyper_bullet_speed = *(u16 *)(p + 0x3188);
    g_laser_bomb_hit_position = *(u16 *)(p + 0x318A);
    g_laser_bomb_hit_entity = *(s32 *)(p + 0x318C);
    g_laser_bomb_pushback = *(u16 *)(p + 0x3190);
    g_laser_bomb_hit_flag = *(u16 *)(p + 0x3192);
    g_player_shot_count = *(u16 *)(p + 0x3194);
    g_player_laser_count = *(u16 *)(p + 0x3196);
    g_p1_y_delta = *(u16 *)(p + 0x3198);
    g_p2_y_delta = *(u16 *)(p + 0x319A);
    g_p1_laser_stop_y = *(u16 *)(p + 0x319C);
    g_p2_laser_stop_y = *(u16 *)(p + 0x319E);
    g_laser_bomb_sizzle = *(u16 *)(p + 0x31A0);
    g_laser_bomb_sizzle2 = *(u16 *)(p + 0x31A2);
    g_bomb_afterglow_timer = *(u16 *)(p + 0x31A4);
    g_player_shots_disabled = *(u16 *)(p + 0x31A6);
    g_players_hidden = *(u16 *)(p + 0x31A8);
    g_players_stage_clear = *(u16 *)(p + 0x31AA);
    g_p1_died_in_hyper = *(u16 *)(p + 0x31AC);
    g_p2_died_in_hyper = *(u16 *)(p + 0x31AE);
    g_two_player_game = *(u16 *)(p + 0x31B0);
    g_two_player_state = *(u16 *)(p + 0x31B2);
    g_two_player_seen = *(u16 *)(p + 0x31B4);
    g_stage = *(u16 *)(p + 0x31B6);
    g_stage_x2 = *(u16 *)(p + 0x31B8);
    g_stage_x4 = *(u16 *)(p + 0x31BA);
    g_loop = *(u16 *)(p + 0x31BC);
    g_game_completed = *(u16 *)(p + 0x31BE);
    g_true_last_boss = *(u16 *)(p + 0x31C0);
    g_rank = *(u16 *)(p + 0x31C2);
    g_rank_15_16 = *(u16 *)(p + 0x31C4);
    g_rank_14_16 = *(u16 *)(p + 0x31C6);
    g_rank_13_16 = *(u16 *)(p + 0x31C8);
    g_rank_12_16 = *(u16 *)(p + 0x31CA);
    g_rank_11_16 = *(u16 *)(p + 0x31CC);
    g_rank_10_16 = *(u16 *)(p + 0x31CE);
    g_rank_9_16 = *(u16 *)(p + 0x31D0);
    g_rank_8_16 = *(u16 *)(p + 0x31D2);
    g_rank_7_16 = *(u16 *)(p + 0x31D4);
    g_rank_6_16 = *(u16 *)(p + 0x31D6);
    g_rank_5_16 = *(u16 *)(p + 0x31D8);
    g_rank_4_16 = *(u16 *)(p + 0x31DA);
    g_rank_3_16 = *(u16 *)(p + 0x31DC);
    g_rank_2_16 = *(u16 *)(p + 0x31DE);
    g_rank_1_16 = *(u16 *)(p + 0x31E0);
    g_p1_lives = *(u16 *)(p + 0x31E2);
    g_p2_lives = *(u16 *)(p + 0x31E4);
    g_play_time = *(s32 *)(p + 0x31E8);
    g_damage_blink_counter = *(u16 *)(p + 0x31EC);
    g_name_entry_player = p[0x31EE];
    g_name_entry_player_pad = p[0x31EF];
    g_scroll_line = *(u16 *)(p + 0x31F0);
    g_scroll_line_step = *(u16 *)(p + 0x31F2);
    g_scroll_line_offset = *(u16 *)(p + 0x31F4);
    g_enemy_signal_0 = *(u16 *)(p + 0x31FC);
    g_enemy_signal_1 = *(u16 *)(p + 0x31FE);
    g_enemy_signal_2 = *(u16 *)(p + 0x3200);
    g_enemy_signal_3 = *(u16 *)(p + 0x3202);
    g_enemy_signal_4 = *(u16 *)(p + 0x3204);
    g_enemy_signal_5 = *(u16 *)(p + 0x3206);
    g_enemy_signal_6 = *(u16 *)(p + 0x3208);
    g_enemy_signal_7 = *(u16 *)(p + 0x320A);
    g_enemy_signal_8 = *(u16 *)(p + 0x320C);
    g_enemy_signal_9 = *(u16 *)(p + 0x320E);
    g_enemy_signal_a = *(u16 *)(p + 0x3210);
    g_enemy_signal_b = *(u16 *)(p + 0x3212);
    g_enemy_signal_c = *(u16 *)(p + 0x3214);
    g_enemy_signal_d = *(u16 *)(p + 0x3216);
    g_enemy_signal_e = *(u16 *)(p + 0x3218);
    g_enemy_signal_f = *(u16 *)(p + 0x321A);
    (*(u16 *)&g_boss_present) = *(u16 *)(p + 0x321C);
    for (i = 0; i < 0x48; i++) {
        g_player_slots[i] = p[0x321E + i];
    }
    g_continue_pending_count = *(u16 *)(p + 0x3266);
    g_p1_score = *(s32 *)(p + 0x327C);
    g_p2_score = *(s32 *)(p + 0x3280);
    g_high_score = *(s32 *)(p + 0x3284);
    g_p1_score_billions = *(u16 *)(p + 0x3288);
    g_p2_score_billions = *(u16 *)(p + 0x328A);
    g_high_score_billions = *(u16 *)(p + 0x328C);
    g_p1_score_digits = *(u16 *)(p + 0x328E);
    g_high_score_digits = *(u16 *)(p + 0x3290);
    g_p2_score_digits = *(u16 *)(p + 0x3292);
    g_p1_score_saved = *(s32 *)(p + 0x3294);
    g_p2_score_saved = *(s32 *)(p + 0x3298);
    g_p1_score_billions_saved = *(u16 *)(p + 0x329C);
    g_p2_score_billions_saved = *(u16 *)(p + 0x329E);
    g_p1_extend_score = *(s32 *)(p + 0x32A0);
    g_p2_extend_score = *(s32 *)(p + 0x32A4);
    g_p1_extend_setting = *(u16 *)(p + 0x32A8);
    g_p2_extend_setting = *(u16 *)(p + 0x32AA);
    g_p1_score_pending = *(s32 *)(p + 0x32AC);
    g_p2_score_pending = *(s32 *)(p + 0x32B0);
    for (i = 0; i < 90; i++) {
        g_p1_score_cells_as_Bank90.a[i] = p[0x32B4 + i];
    }
    for (i = 0; i < 90; i++) {
        g_p1_score_cells_as_Bank90.b[i] = p[0x330E + i];
    }
    for (i = 0; i < 10; i++) {
        g_p1_score_extra_cell_as_Bank10.a[i] = p[0x3368 + i];
    }
    for (i = 0; i < 10; i++) {
        g_p1_score_extra_cell_as_Bank10.b[i] = p[0x3372 + i];
    }
    g_score_check_scratch = *(s32 *)(p + 0x337C);
    g_score_check_billions = *(u16 *)(p + 0x3380);
    g_p1_score_panel_flags = p[0x3382];
    g_p2_score_panel_flags = p[0x3383];
    g_hyper_text_anim_delay = *(u16 *)(p + 0x3384);
    g_hyper_text_anim_frame = *(u16 *)(p + 0x3386);
    g_hyper_text_anim_sprite = *(s32 *)(p + 0x3388);
    g_maximum_text_anim_delay = *(u16 *)(p + 0x338C);
    g_maximum_text_anim_frame = *(u16 *)(p + 0x338E);
    g_maximum_text_anim_sprite = *(s32 *)(p + 0x3390);
    g_max_level_display_timer = *(u16 *)(p + 0x3394);
    g_score_scratch = *(s32 *)(p + 0x3398);
    g_p1_combo_at_bomb = *(u16 *)(p + 0x339C);
    g_p2_combo_at_bomb = *(u16 *)(p + 0x339E);
    g_max_combo_time = *(u16 *)(p + 0x33A0);
    g_boss_hit_carry = *(u16 *)(p + 0x33A2);
    g_score_player_flag = *(u16 *)(p + 0x33A4);
    g_p1_chain_first_score = *(s32 *)(p + 0x33A8);
    g_p1_chain_first_score_shown = *(s32 *)(p + 0x33AC);
    g_p1_combo_timer = *(u16 *)(p + 0x33B0);
    g_p1_chain_points_display_timer = *(u16 *)(p + 0x33B2);
    g_p1_hit_display_timer = *(u16 *)(p + 0x33B4);
    g_p1_combo_break_color_timer = *(u16 *)(p + 0x33B6);
    g_p1_hit10_display_timer = *(u16 *)(p + 0x33B8);
    g_p1_hit10_color_timer = *(u16 *)(p + 0x33BA);
    g_p1_hit10_anim_count = *(u16 *)(p + 0x33BC);
    g_p1_chain_points = *(s32 *)(p + 0x33C0);
    g_p1_chain_points_shown = *(s32 *)(p + 0x33C4);
    g_p1_chain_points_shown2 = *(s32 *)(p + 0x33C8);
    g_p1_hits = *(u16 *)(p + 0x33CC);
    g_p1_hits_shown = *(u16 *)(p + 0x33CE);
    g_p1_laser_hit_timer = *(u16 *)(p + 0x33D0);
    g_p1_laser_hit_step = *(u16 *)(p + 0x33D2);
    g_p2_chain_first_score = *(s32 *)(p + 0x33D4);
    g_p2_chain_first_score_shown = *(s32 *)(p + 0x33D8);
    g_p2_combo_timer = *(u16 *)(p + 0x33DC);
    g_p2_chain_points_display_timer = *(u16 *)(p + 0x33DE);
    g_p2_hit_display_timer = *(u16 *)(p + 0x33E0);
    g_p2_combo_break_color_timer = *(u16 *)(p + 0x33E2);
    g_p2_hit10_display_timer = *(u16 *)(p + 0x33E4);
    g_p2_hit10_color_timer = *(u16 *)(p + 0x33E6);
    g_p2_hit10_anim_count = *(u16 *)(p + 0x33E8);
    g_p2_chain_points = *(s32 *)(p + 0x33EC);
    g_p2_chain_points_shown = *(s32 *)(p + 0x33F0);
    g_p2_chain_points_shown2 = *(s32 *)(p + 0x33F4);
    g_p2_hits = *(u16 *)(p + 0x33F8);
    g_p2_hits_shown = *(u16 *)(p + 0x33FA);
    g_p2_laser_hit_timer = *(u16 *)(p + 0x33FC);
    g_p2_laser_hit_step = *(u16 *)(p + 0x33FE);
    g_boss_hit_decay_timer = *(u16 *)(p + 0x3400);
    g_boss_hit_anim_count = *(u16 *)(p + 0x3402);
    g_boss_hits = *(u16 *)(p + 0x3404);
    g_boss_hit_palette = *(u16 *)(p + 0x3406);
    g_boss_hit_bonus_timer = *(u16 *)(p + 0x3408);
    g_boss_hit_bonus = *(s32 *)(p + 0x340C);
    g_boss_score = *(s32 *)(p + 0x3410);
    (*(u16 *)&g_boss_hp_bar_flags) = *(u16 *)(p + 0x3414);
    if (g_stage != 0) {
        g_boss_hp_bar_move_count = *(u16 *)(p + 0x3416);
    }
    g_lives_display_move_y = *(u16 *)(p + 0x3418);
    g_lives_display_move_x = *(u16 *)(p + 0x341A);
    g_boss_hp_unit = *(s32 *)(p + 0x341C);
    (*(s32 *)&g_boss_hp) = *(s32 *)(p + 0x3420);
    g_boss_near_death = *(u16 *)(p + 0x3424);
    g_boss_explosion_flash = *(u16 *)(p + 0x3426);
    g_p1_max_hits = *(u16 *)(p + 0x3428);
    g_p2_max_hits = *(u16 *)(p + 0x342A);
    g_p1_laser_hyper_timer = *(u16 *)(p + 0x342C);
    g_p2_laser_hyper_timer = *(u16 *)(p + 0x342E);
    g_p1_shot_hyper_timer = *(u16 *)(p + 0x3430);
    g_p2_shot_hyper_timer = *(u16 *)(p + 0x3432);
    g_p1_hyper_active = *(u16 *)(p + 0x3434);
    g_p2_hyper_active = *(u16 *)(p + 0x3436);
    g_p1_hyper_time = *(u16 *)(p + 0x3438);
    g_p2_hyper_time = *(u16 *)(p + 0x343A);
    g_p1_hyper_total = *(u16 *)(p + 0x343C);
    g_p2_hyper_total = *(u16 *)(p + 0x343E);
    g_p1_hyper_gauge = *(u16 *)(p + 0x3440);
    g_p2_hyper_gauge = *(u16 *)(p + 0x3442);
    g_p1_hyper_combo_decay = *(u16 *)(p + 0x3444);
    g_p2_hyper_combo_decay = *(u16 *)(p + 0x3446);
    g_hyper_text_slide = *(u16 *)(p + 0x3448);
    g_p1_hyper_level = *(u16 *)(p + 0x344A);
    g_p2_hyper_level = *(u16 *)(p + 0x344C);
    g_p1_hyper_in_effect = *(u16 *)(p + 0x344E);
    g_p2_hyper_in_effect = *(u16 *)(p + 0x3450);
    g_p1_hyper_items = *(u16 *)(p + 0x3452);
    g_p2_hyper_items = *(u16 *)(p + 0x3454);
    for (i = 0; i < 16; i++) {
        g_p1_position_trail[i] = ((PairSrc *)p)->a[i];
    }
    for (i = 0; i < 16; i++) {
        g_p2_position_trail[i] = ((PairSrc *)p)->b[i];
    }
    g_p1_hyper_items_pending = *(u16 *)(p + 0x34D8);
    g_p2_hyper_items_pending = *(u16 *)(p + 0x34DA);
    g_boss_hyper_wait = *(u16 *)(p + 0x34DC);
    g_hyper_hit_scratch = *(u16 *)(p + 0x34DE);
    g_hyper_level_hit_scratch = *(u16 *)(p + 0x34E0);
    g_boss_double_speed = *(u16 *)(p + 0x34E2);
    g_hyper_debug_check = *(u16 *)(p + 0x34E4);
    g_score_panel_intro = *(u16 *)(p + 0x34E6);
    g_score_task_active = *(u16 *)(p + 0x34E8);
    g_p1_hyper_effect_sprite = *(s32 *)(p + 0x34EC);
    g_p2_hyper_effect_sprite = *(s32 *)(p + 0x34F0);
    g_p1_hyper_effect_frame = *(u16 *)(p + 0x34F4);
    g_p2_hyper_effect_frame = *(u16 *)(p + 0x34F6);
    g_p1_hyper_effect_flag = *(u16 *)(p + 0x34F8);
    g_p2_hyper_effect_flag = *(u16 *)(p + 0x34FA);
    g_p1_hyper_effect_delay = *(u16 *)(p + 0x34FC);
    g_p2_hyper_effect_delay = *(u16 *)(p + 0x34FE);
    g_setting_difficulty = p[0x350C];
    g_setting_extend = p[0x350D];
    g_setting_ship_stock = p[0x350E];
    D_0028E2EC = p[0x350F];
    D_0028E304 = p[0x3510];
    g_game_frame = *(u16 *)(p + 0x3500);
    g_frame_mod2 = *(u16 *)(p + 0x3502);
    g_frame_mod3 = *(u16 *)(p + 0x3504);
    g_frame_mod4 = *(u16 *)(p + 0x3506);
    g_frame_mod8 = *(u16 *)(p + 0x3508);
    g_frame_mod16 = *(u16 *)(p + 0x350A);
    *(Row16 *)&g_ground_state = ((RowSrc *)p)->row;
    D_0028E288 = p[0x5532];
    D_0028E284 = p[0x5533];
    replay_text_layer_load((const Src *)p);
}


void replay_text_layer_load(const Src *src) {
    s32 i;
    for (i = 0; i < 0x2000; i++) {
        ((s8 *)g_text_layer)[i] = src->data[i];
    }
}

extern void pickups_clear(void);
extern void bullets_clear(void);
extern void game_state_clear(void);
extern void enemy_anims_clear(void);
extern void explosions_clear(void);
extern void players_clear(void);
extern void enemies_reset(void);
extern void items_clear(void);
extern void score_cells_init(void);
extern void scores_reset(void);
extern void debris_clear(void);
extern void sparks_clear(void);
extern void wrecks_clear(void);
void replay_start_state_load(u8 *p) {
    s32 i;

    enemies_reset();
    explosions_clear();
    debris_clear();
    wrecks_clear();
    enemy_anims_clear();
    sparks_clear();
    items_clear();
    bullets_clear();
    game_state_clear();
    pickups_clear();
    scores_reset();
    score_cells_init();
    players_clear();
    g_stage_bees_collected = *(u16 *)(p + 0x0);
    g_bee_value_step = *(u16 *)(p + 0x2);
    g_p1_stage_stars_large = *(u16 *)(p + 0x4);
    g_p1_stage_stars_small = *(u16 *)(p + 0x6);
    g_p2_stage_stars_large = *(u16 *)(p + 0x8);
    g_p2_stage_stars_small = *(u16 *)(p + 0xA);
    for (i = 0; i < 98; i++) {
        ((u8 *)g_player1)[i] = p[12 + i];
        ((u8 *)g_player2)[i] = p[110 + i];
    }
    *(Vec4 *)((u8 *)g_p1_maximum_value) = *(Vec4 *)(p + 0xD0);
    *(Vec4 *)((u8 *)g_p2_maximum_value) = *(Vec4 *)(p + 0xE0);
    g_p1_maximum_level = *(u16 *)(p + 0xF0);
    g_p2_maximum_level = *(u16 *)(p + 0xF2);
    g_p1_maximum_anim_delay = *(u16 *)(p + 0xF4);
    g_p1_maximum_anim_delay_reset = *(u16 *)(p + 0xF6);
    g_p2_maximum_anim_delay = *(u16 *)(p + 0xF8);
    g_p2_maximum_anim_delay_reset = *(u16 *)(p + 0xFA);
    g_p1_hyper_ready_sprite = *(s32 *)(p + 0xFC);
    g_p2_hyper_ready_sprite = *(s32 *)(p + 0x100);
    g_p1_hyper_ready_anim_delay = *(u16 *)(p + 0x104);
    g_p2_hyper_ready_anim_delay = *(u16 *)(p + 0x106);
    g_p1_missed = *(u16 *)(p + 0x108);
    g_p2_missed = *(u16 *)(p + 0x10A);
    g_p1_past_first_ship = *(u16 *)(p + 0x10C);
    g_p2_past_first_ship = *(u16 *)(p + 0x10E);
    g_p1_continued = *(u16 *)(p + 0x110);
    g_p2_continued = *(u16 *)(p + 0x112);
    g_p1_death_count = *(u16 *)(p + 0x114);
    g_p2_death_count = *(u16 *)(p + 0x116);
    g_p1_stage_misses = *(u16 *)(p + 0x118);
    g_p2_stage_misses = *(u16 *)(p + 0x11A);
    g_p1_bombs_used = *(u16 *)(p + 0x11C);
    g_p2_bombs_used = *(u16 *)(p + 0x11E);
    g_p1_stage_bomb_used = *(u16 *)(p + 0x120);
    g_p2_stage_bomb_used = *(u16 *)(p + 0x122);
    g_p1_loop2_extend_ok = *(u16 *)(p + 0x124);
    g_p2_loop2_extend_ok = *(u16 *)(p + 0x126);
    g_p1_laser_bomb_active = *(u16 *)(p + 0x128);
    g_p2_laser_bomb_active = *(u16 *)(p + 0x12A);
    g_hyper_bullet_speed = *(u16 *)(p + 0x12C);
    g_laser_bomb_hit_position = *(u16 *)(p + 0x12E);
    g_laser_bomb_pushback = *(u16 *)(p + 0x130);
    g_laser_bomb_hit_flag = *(u16 *)(p + 0x132);
    g_player_shot_count = *(u16 *)(p + 0x134);
    g_player_laser_count = *(u16 *)(p + 0x136);
    g_p1_y_delta = *(u16 *)(p + 0x138);
    g_p2_y_delta = *(u16 *)(p + 0x13A);
    g_p1_laser_stop_y = *(u16 *)(p + 0x13C);
    g_p2_laser_stop_y = *(u16 *)(p + 0x13E);
    g_laser_bomb_sizzle = *(u16 *)(p + 0x140);
    g_laser_bomb_sizzle2 = *(u16 *)(p + 0x142);
    g_bomb_afterglow_timer = *(u16 *)(p + 0x144);
    g_player_shots_disabled = *(u16 *)(p + 0x146);
    g_players_hidden = *(u16 *)(p + 0x148);
    g_players_stage_clear = *(u16 *)(p + 0x14A);
    g_p1_died_in_hyper = *(u16 *)(p + 0x14C);
    g_p2_died_in_hyper = *(u16 *)(p + 0x14E);
    g_two_player_game = *(u16 *)(p + 0x150);
    g_two_player_state = *(u16 *)(p + 0x152);
    g_two_player_seen = *(u16 *)(p + 0x154);
    g_stage = *(u16 *)(p + 0x156);
    g_stage_x2 = *(u16 *)(p + 0x158);
    g_stage_x4 = *(u16 *)(p + 0x15A);
    g_loop = *(u16 *)(p + 0x15C);
    g_game_completed = *(u16 *)(p + 0x15E);
    g_true_last_boss = *(u16 *)(p + 0x160);
    g_rank = *(u16 *)(p + 0x162);
    g_rank_15_16 = *(u16 *)(p + 0x164);
    g_rank_14_16 = *(u16 *)(p + 0x166);
    g_rank_13_16 = *(u16 *)(p + 0x168);
    g_rank_12_16 = *(u16 *)(p + 0x16A);
    g_rank_11_16 = *(u16 *)(p + 0x16C);
    g_rank_10_16 = *(u16 *)(p + 0x16E);
    g_rank_9_16 = *(u16 *)(p + 0x170);
    g_rank_8_16 = *(u16 *)(p + 0x172);
    g_rank_7_16 = *(u16 *)(p + 0x174);
    g_rank_6_16 = *(u16 *)(p + 0x176);
    g_rank_5_16 = *(u16 *)(p + 0x178);
    g_rank_4_16 = *(u16 *)(p + 0x17A);
    g_rank_3_16 = *(u16 *)(p + 0x17C);
    g_rank_2_16 = *(u16 *)(p + 0x17E);
    g_rank_1_16 = *(u16 *)(p + 0x180);
    g_p1_lives = *(u16 *)(p + 0x182);
    g_p2_lives = *(u16 *)(p + 0x184);
    g_play_time = *(s32 *)(p + 0x188);
    g_damage_blink_counter = *(u16 *)(p + 0x18C);
    g_name_entry_player = p[0x18E];
    g_name_entry_player_pad = p[0x18F];
    g_enemy_signal_0 = *(u16 *)(p + 0x190);
    g_enemy_signal_1 = *(u16 *)(p + 0x192);
    g_enemy_signal_2 = *(u16 *)(p + 0x194);
    g_enemy_signal_3 = *(u16 *)(p + 0x196);
    g_enemy_signal_4 = *(u16 *)(p + 0x198);
    g_enemy_signal_5 = *(u16 *)(p + 0x19A);
    g_enemy_signal_6 = *(u16 *)(p + 0x19C);
    g_enemy_signal_7 = *(u16 *)(p + 0x19E);
    g_enemy_signal_8 = *(u16 *)(p + 0x1A0);
    g_enemy_signal_9 = *(u16 *)(p + 0x1A2);
    g_enemy_signal_a = *(u16 *)(p + 0x1A4);
    g_enemy_signal_b = *(u16 *)(p + 0x1A6);
    g_enemy_signal_c = *(u16 *)(p + 0x1A8);
    g_enemy_signal_d = *(u16 *)(p + 0x1AA);
    g_enemy_signal_e = *(u16 *)(p + 0x1AC);
    g_enemy_signal_f = *(u16 *)(p + 0x1AE);
    (*(u16 *)&g_boss_present) = *(u16 *)(p + 0x1B0);
    g_p1_score = *(s32 *)(p + 0x1B4);
    g_p2_score = *(s32 *)(p + 0x1B8);
    g_high_score = *(s32 *)(p + 0x1BC);
    g_p1_score_billions = *(u16 *)(p + 0x1C0);
    g_p2_score_billions = *(u16 *)(p + 0x1C2);
    g_high_score_billions = *(u16 *)(p + 0x1C4);
    g_p1_score_digits = *(u16 *)(p + 0x1C6);
    g_high_score_digits = *(u16 *)(p + 0x1C8);
    g_p2_score_digits = *(u16 *)(p + 0x1CA);
    g_p1_score_saved = *(s32 *)(p + 0x1CC);
    g_p2_score_saved = *(s32 *)(p + 0x1D0);
    g_p1_score_billions_saved = *(u16 *)(p + 0x1D4);
    g_p2_score_billions_saved = *(u16 *)(p + 0x1D6);
    g_p1_extend_score = *(s32 *)(p + 0x1D8);
    g_p2_extend_score = *(s32 *)(p + 0x1DC);
    g_p1_extend_setting = *(u16 *)(p + 0x1E0);
    g_p2_extend_setting = *(u16 *)(p + 0x1E2);
    g_p1_score_pending = *(s32 *)(p + 0x1E4);
    g_p2_score_pending = *(s32 *)(p + 0x1E8);
    for (i = 0; i < 90; i++) {
        g_p1_score_cells_as_Bank90.a[i] = p[0x1EC + i];
    }
    for (i = 0; i < 90; i++) {
        g_p1_score_cells_as_Bank90.b[i] = p[0x246 + i];
    }
    for (i = 0; i < 10; i++) {
        g_p1_score_extra_cell_as_Bank10.a[i] = p[0x2A0 + i];
    }
    for (i = 0; i < 10; i++) {
        g_p1_score_extra_cell_as_Bank10.b[i] = p[0x2AA + i];
    }
    g_score_check_scratch = *(s32 *)(p + 0x2B4);
    g_score_check_billions = *(u16 *)(p + 0x2B8);
    g_p1_score_panel_flags = p[0x2BA];
    g_p2_score_panel_flags = p[0x2BB];
    g_hyper_text_anim_delay = *(u16 *)(p + 0x2BC);
    g_hyper_text_anim_frame = *(u16 *)(p + 0x2BE);
    g_hyper_text_anim_sprite = *(s32 *)(p + 0x2C0);
    g_maximum_text_anim_delay = *(u16 *)(p + 0x2C4);
    g_maximum_text_anim_frame = *(u16 *)(p + 0x2C6);
    g_maximum_text_anim_sprite = *(s32 *)(p + 0x2C8);
    g_max_level_display_timer = *(u16 *)(p + 0x2CC);
    g_score_scratch = *(s32 *)(p + 0x2D0);
    g_p1_combo_at_bomb = *(u16 *)(p + 0x2D4);
    g_p2_combo_at_bomb = *(u16 *)(p + 0x2D6);
    g_max_combo_time = *(u16 *)(p + 0x2D8);
    g_boss_hit_carry = *(u16 *)(p + 0x2DA);
    g_score_player_flag = *(u16 *)(p + 0x2DC);
    g_p1_chain_first_score = *(s32 *)(p + 0x2E0);
    g_p1_chain_first_score_shown = *(s32 *)(p + 0x2E4);
    g_p1_combo_timer = *(u16 *)(p + 0x2E8);
    g_p1_chain_points_display_timer = *(u16 *)(p + 0x2EA);
    g_p1_hit_display_timer = *(u16 *)(p + 0x2EC);
    g_p1_combo_break_color_timer = *(u16 *)(p + 0x2EE);
    g_p1_hit10_display_timer = *(u16 *)(p + 0x2F0);
    g_p1_hit10_color_timer = *(u16 *)(p + 0x2F2);
    g_p1_hit10_anim_count = *(u16 *)(p + 0x2F4);
    g_p1_chain_points = *(s32 *)(p + 0x2F8);
    g_p1_chain_points_shown = *(s32 *)(p + 0x2FC);
    g_p1_chain_points_shown2 = *(s32 *)(p + 0x300);
    g_p1_hits = *(u16 *)(p + 0x304);
    g_p1_hits_shown = *(u16 *)(p + 0x306);
    g_p1_laser_hit_timer = *(u16 *)(p + 0x308);
    g_p1_laser_hit_step = *(u16 *)(p + 0x30A);
    g_p2_chain_first_score = *(s32 *)(p + 0x30C);
    g_p2_chain_first_score_shown = *(s32 *)(p + 0x310);
    g_p2_combo_timer = *(u16 *)(p + 0x314);
    g_p2_chain_points_display_timer = *(u16 *)(p + 0x316);
    g_p2_hit_display_timer = *(u16 *)(p + 0x318);
    g_p2_combo_break_color_timer = *(u16 *)(p + 0x31A);
    g_p2_hit10_display_timer = *(u16 *)(p + 0x31C);
    g_p2_hit10_color_timer = *(u16 *)(p + 0x31E);
    g_p2_hit10_anim_count = *(u16 *)(p + 0x320);
    g_p2_chain_points = *(s32 *)(p + 0x324);
    g_p2_chain_points_shown = *(s32 *)(p + 0x328);
    g_p2_chain_points_shown2 = *(s32 *)(p + 0x32C);
    g_p2_hits = *(u16 *)(p + 0x330);
    g_p2_hits_shown = *(u16 *)(p + 0x332);
    g_p2_laser_hit_timer = *(u16 *)(p + 0x334);
    g_p2_laser_hit_step = *(u16 *)(p + 0x336);
    g_boss_hit_decay_timer = *(u16 *)(p + 0x338);
    g_boss_hit_anim_count = *(u16 *)(p + 0x33A);
    g_boss_hits = *(u16 *)(p + 0x33C);
    g_boss_hit_palette = *(u16 *)(p + 0x33E);
    g_boss_hit_bonus_timer = *(u16 *)(p + 0x340);
    g_boss_hit_bonus = *(s32 *)(p + 0x344);
    g_boss_score = *(s32 *)(p + 0x348);
    (*(u16 *)&g_boss_hp_bar_flags) = *(u16 *)(p + 0x34C);
    g_p1_max_hits = *(u16 *)(p + 0x34E);
    g_p2_max_hits = *(u16 *)(p + 0x350);
    g_p1_laser_hyper_timer = *(u16 *)(p + 0x352);
    g_p2_laser_hyper_timer = *(u16 *)(p + 0x354);
    g_p1_shot_hyper_timer = *(u16 *)(p + 0x356);
    g_p2_shot_hyper_timer = *(u16 *)(p + 0x358);
    g_p1_hyper_active = *(u16 *)(p + 0x35A);
    g_p2_hyper_active = *(u16 *)(p + 0x35C);
    g_p1_hyper_time = *(u16 *)(p + 0x35E);
    g_p2_hyper_time = *(u16 *)(p + 0x360);
    g_p1_hyper_total = *(u16 *)(p + 0x362);
    g_p2_hyper_total = *(u16 *)(p + 0x364);
    g_p1_hyper_gauge = *(u16 *)(p + 0x366);
    g_p2_hyper_gauge = *(u16 *)(p + 0x368);
    g_p1_hyper_combo_decay = *(u16 *)(p + 0x36A);
    g_p2_hyper_combo_decay = *(u16 *)(p + 0x36C);
    g_hyper_text_slide = *(u16 *)(p + 0x36E);
    g_p1_hyper_level = *(u16 *)(p + 0x370);
    g_p2_hyper_level = *(u16 *)(p + 0x372);
    g_p1_hyper_in_effect = *(u16 *)(p + 0x374);
    g_p2_hyper_in_effect = *(u16 *)(p + 0x376);
    g_p1_hyper_items = *(u16 *)(p + 0x378);
    g_p2_hyper_items = *(u16 *)(p + 0x37A);
    g_p1_hyper_items_pending = *(u16 *)(p + 0x37C);
    g_p2_hyper_items_pending = *(u16 *)(p + 0x37E);
    g_boss_hyper_wait = *(u16 *)(p + 0x380);
    g_hyper_hit_scratch = *(u16 *)(p + 0x382);
    g_hyper_level_hit_scratch = *(u16 *)(p + 0x384);
    g_boss_double_speed = *(u16 *)(p + 0x386);
    g_hyper_debug_check = *(u16 *)(p + 0x388);
    g_score_panel_intro = *(u16 *)(p + 0x38A);
    g_score_task_active = *(u16 *)(p + 0x38C);
    g_p1_hyper_effect_sprite = *(s32 *)(p + 0x390);
    g_p2_hyper_effect_sprite = *(s32 *)(p + 0x394);
    g_p1_hyper_effect_frame = *(u16 *)(p + 0x398);
    g_p2_hyper_effect_frame = *(u16 *)(p + 0x39A);
    g_p1_hyper_effect_flag = *(u16 *)(p + 0x39C);
    g_p2_hyper_effect_flag = *(u16 *)(p + 0x39E);
    g_p1_hyper_effect_delay = *(u16 *)(p + 0x3A0);
    g_p2_hyper_effect_delay = *(u16 *)(p + 0x3A2);
}

typedef struct {
    u8 pad0[0x1EC];
    u8 a[90];
    u8 b[90];
    u8 c[10];
    u8 d[10];
} Buf2;

void replay_start_state_save(Buf2 *buf) {
    s32 i;
    u8 *p = (u8 *)buf;

    *(u16 *)(p + 0x0) = g_stage_bees_collected;
    *(u16 *)(p + 0x2) = g_bee_value_step;
    *(u16 *)(p + 0x4) = g_p1_stage_stars_large;
    *(u16 *)(p + 0x6) = g_p1_stage_stars_small;
    *(u16 *)(p + 0x8) = g_p2_stage_stars_large;
    *(u16 *)(p + 0xA) = g_p2_stage_stars_small;
    for (i = 0; i < 98; i++) {
        p[12 + i] = ((u8 *)g_player1)[i];
        p[110 + i] = ((u8 *)g_player2)[i];
    }
    *(Vec4 *)(p + 0xD0) = *(Vec4 *)((u8 *)g_p1_maximum_value);
    *(Vec4 *)(p + 0xE0) = *(Vec4 *)((u8 *)g_p2_maximum_value);
    *(u16 *)(p + 0xF0) = g_p1_maximum_level;
    *(u16 *)(p + 0xF2) = g_p2_maximum_level;
    *(u16 *)(p + 0xF4) = g_p1_maximum_anim_delay;
    *(u16 *)(p + 0xF6) = g_p1_maximum_anim_delay_reset;
    *(u16 *)(p + 0xF8) = g_p2_maximum_anim_delay;
    *(u16 *)(p + 0xFA) = g_p2_maximum_anim_delay_reset;
    *(s32 *)(p + 0xFC) = g_p1_hyper_ready_sprite;
    *(s32 *)(p + 0x100) = g_p2_hyper_ready_sprite;
    *(u16 *)(p + 0x104) = g_p1_hyper_ready_anim_delay;
    *(u16 *)(p + 0x106) = g_p2_hyper_ready_anim_delay;
    *(u16 *)(p + 0x108) = g_p1_missed;
    *(u16 *)(p + 0x10A) = g_p2_missed;
    *(u16 *)(p + 0x10C) = g_p1_past_first_ship;
    *(u16 *)(p + 0x10E) = g_p2_past_first_ship;
    *(u16 *)(p + 0x110) = g_p1_continued;
    *(u16 *)(p + 0x112) = g_p2_continued;
    *(u16 *)(p + 0x114) = g_p1_death_count;
    *(u16 *)(p + 0x116) = g_p2_death_count;
    *(u16 *)(p + 0x118) = g_p1_stage_misses;
    *(u16 *)(p + 0x11A) = g_p2_stage_misses;
    *(u16 *)(p + 0x11C) = g_p1_bombs_used;
    *(u16 *)(p + 0x11E) = g_p2_bombs_used;
    *(u16 *)(p + 0x120) = g_p1_stage_bomb_used;
    *(u16 *)(p + 0x122) = g_p2_stage_bomb_used;
    *(u16 *)(p + 0x124) = g_p1_loop2_extend_ok;
    *(u16 *)(p + 0x126) = g_p2_loop2_extend_ok;
    *(u16 *)(p + 0x128) = g_p1_laser_bomb_active;
    *(u16 *)(p + 0x12A) = g_p2_laser_bomb_active;
    *(u16 *)(p + 0x12C) = g_hyper_bullet_speed;
    *(u16 *)(p + 0x12E) = g_laser_bomb_hit_position;
    *(u16 *)(p + 0x130) = g_laser_bomb_pushback;
    *(u16 *)(p + 0x132) = g_laser_bomb_hit_flag;
    *(u16 *)(p + 0x134) = g_player_shot_count;
    *(u16 *)(p + 0x136) = g_player_laser_count;
    *(u16 *)(p + 0x138) = g_p1_y_delta;
    *(u16 *)(p + 0x13A) = g_p2_y_delta;
    *(u16 *)(p + 0x13C) = g_p1_laser_stop_y;
    *(u16 *)(p + 0x13E) = g_p2_laser_stop_y;
    *(u16 *)(p + 0x140) = g_laser_bomb_sizzle;
    *(u16 *)(p + 0x142) = g_laser_bomb_sizzle2;
    *(u16 *)(p + 0x144) = g_bomb_afterglow_timer;
    *(u16 *)(p + 0x146) = g_player_shots_disabled;
    *(u16 *)(p + 0x148) = g_players_hidden;
    *(u16 *)(p + 0x14A) = g_players_stage_clear;
    *(u16 *)(p + 0x14C) = g_p1_died_in_hyper;
    *(u16 *)(p + 0x14E) = g_p2_died_in_hyper;
    *(u16 *)(p + 0x150) = g_two_player_game;
    *(u16 *)(p + 0x152) = g_two_player_state;
    *(u16 *)(p + 0x154) = g_two_player_seen;
    *(u16 *)(p + 0x156) = g_stage;
    *(u16 *)(p + 0x158) = g_stage_x2;
    *(u16 *)(p + 0x15A) = g_stage_x4;
    *(u16 *)(p + 0x15C) = g_loop;
    *(u16 *)(p + 0x15E) = g_game_completed;
    *(u16 *)(p + 0x160) = g_true_last_boss;
    *(u16 *)(p + 0x162) = g_rank;
    *(u16 *)(p + 0x164) = g_rank_15_16;
    *(u16 *)(p + 0x166) = g_rank_14_16;
    *(u16 *)(p + 0x168) = g_rank_13_16;
    *(u16 *)(p + 0x16A) = g_rank_12_16;
    *(u16 *)(p + 0x16C) = g_rank_11_16;
    *(u16 *)(p + 0x16E) = g_rank_10_16;
    *(u16 *)(p + 0x170) = g_rank_9_16;
    *(u16 *)(p + 0x172) = g_rank_8_16;
    *(u16 *)(p + 0x174) = g_rank_7_16;
    *(u16 *)(p + 0x176) = g_rank_6_16;
    *(u16 *)(p + 0x178) = g_rank_5_16;
    *(u16 *)(p + 0x17A) = g_rank_4_16;
    *(u16 *)(p + 0x17C) = g_rank_3_16;
    *(u16 *)(p + 0x17E) = g_rank_2_16;
    *(u16 *)(p + 0x180) = g_rank_1_16;
    *(u16 *)(p + 0x182) = g_p1_lives;
    *(u16 *)(p + 0x184) = g_p2_lives;
    *(s32 *)(p + 0x188) = g_play_time;
    *(u16 *)(p + 0x18C) = g_damage_blink_counter;
    p[0x18E] = g_name_entry_player;
    p[0x18F] = g_name_entry_player_pad;
    *(u16 *)(p + 0x190) = g_enemy_signal_0;
    *(u16 *)(p + 0x192) = g_enemy_signal_1;
    *(u16 *)(p + 0x194) = g_enemy_signal_2;
    *(u16 *)(p + 0x196) = g_enemy_signal_3;
    *(u16 *)(p + 0x198) = g_enemy_signal_4;
    *(u16 *)(p + 0x19A) = g_enemy_signal_5;
    *(u16 *)(p + 0x19C) = g_enemy_signal_6;
    *(u16 *)(p + 0x19E) = g_enemy_signal_7;
    *(u16 *)(p + 0x1A0) = g_enemy_signal_8;
    *(u16 *)(p + 0x1A2) = g_enemy_signal_9;
    *(u16 *)(p + 0x1A4) = g_enemy_signal_a;
    *(u16 *)(p + 0x1A6) = g_enemy_signal_b;
    *(u16 *)(p + 0x1A8) = g_enemy_signal_c;
    *(u16 *)(p + 0x1AA) = g_enemy_signal_d;
    *(u16 *)(p + 0x1AC) = g_enemy_signal_e;
    *(u16 *)(p + 0x1AE) = g_enemy_signal_f;
    *(u16 *)(p + 0x1B0) = (*(u16 *)&g_boss_present);
    *(s32 *)(p + 0x1B4) = (s32)g_p1_score;
    *(s32 *)(p + 0x1B8) = (s32)g_p2_score;
    *(s32 *)(p + 0x1BC) = g_high_score;
    *(u16 *)(p + 0x1C0) = g_p1_score_billions;
    *(u16 *)(p + 0x1C2) = g_p2_score_billions;
    *(u16 *)(p + 0x1C4) = g_high_score_billions;
    *(u16 *)(p + 0x1C6) = g_p1_score_digits;
    *(u16 *)(p + 0x1C8) = g_high_score_digits;
    *(u16 *)(p + 0x1CA) = g_p2_score_digits;
    *(s32 *)(p + 0x1CC) = (s32)g_p1_score_saved;
    *(s32 *)(p + 0x1D0) = (s32)g_p2_score_saved;
    *(u16 *)(p + 0x1D4) = g_p1_score_billions_saved;
    *(u16 *)(p + 0x1D6) = g_p2_score_billions_saved;
    *(s32 *)(p + 0x1D8) = g_p1_extend_score;
    *(s32 *)(p + 0x1DC) = g_p2_extend_score;
    *(u16 *)(p + 0x1E0) = g_p1_extend_setting;
    *(u16 *)(p + 0x1E2) = g_p2_extend_setting;
    *(s32 *)(p + 0x1E4) = g_p1_score_pending;
    *(s32 *)(p + 0x1E8) = g_p2_score_pending;
    for (i = 0; i < 90; i++) {
        buf->a[i] = g_p1_score_cells_as_Bank90.a[i];
    }
    for (i = 0; i < 90; i++) {
        buf->b[i] = g_p1_score_cells_as_Bank90.b[i];
    }
    for (i = 0; i < 10; i++) {
        buf->c[i] = g_p1_score_extra_cell_as_Bank10.a[i];
    }
    for (i = 0; i < 10; i++) {
        buf->d[i] = g_p1_score_extra_cell_as_Bank10.b[i];
    }
    *(s32 *)(p + 0x2B4) = g_score_check_scratch;
    *(u16 *)(p + 0x2B8) = g_score_check_billions;
    p[0x2BA] = g_p1_score_panel_flags;
    p[0x2BB] = g_p2_score_panel_flags;
    *(u16 *)(p + 0x2BC) = g_hyper_text_anim_delay;
    *(u16 *)(p + 0x2BE) = g_hyper_text_anim_frame;
    *(s32 *)(p + 0x2C0) = g_hyper_text_anim_sprite;
    *(u16 *)(p + 0x2C4) = g_maximum_text_anim_delay;
    *(u16 *)(p + 0x2C6) = g_maximum_text_anim_frame;
    *(s32 *)(p + 0x2C8) = g_maximum_text_anim_sprite;
    *(u16 *)(p + 0x2CC) = g_max_level_display_timer;
    *(s32 *)(p + 0x2D0) = g_score_scratch;
    *(u16 *)(p + 0x2D4) = g_p1_combo_at_bomb;
    *(u16 *)(p + 0x2D6) = g_p2_combo_at_bomb;
    *(u16 *)(p + 0x2D8) = g_max_combo_time;
    *(u16 *)(p + 0x2DA) = g_boss_hit_carry;
    *(u16 *)(p + 0x2DC) = g_score_player_flag;
    *(s32 *)(p + 0x2E0) = g_p1_chain_first_score;
    *(s32 *)(p + 0x2E4) = g_p1_chain_first_score_shown;
    *(u16 *)(p + 0x2E8) = g_p1_combo_timer;
    *(u16 *)(p + 0x2EA) = (*(u16 *)&g_p1_chain_points_display_timer);
    *(u16 *)(p + 0x2EC) = g_p1_hit_display_timer;
    *(u16 *)(p + 0x2EE) = g_p1_combo_break_color_timer;
    *(u16 *)(p + 0x2F0) = (*(u16 *)&g_p1_hit10_display_timer);
    *(u16 *)(p + 0x2F2) = g_p1_hit10_color_timer;
    *(u16 *)(p + 0x2F4) = g_p1_hit10_anim_count;
    *(s32 *)(p + 0x2F8) = g_p1_chain_points;
    *(s32 *)(p + 0x2FC) = g_p1_chain_points_shown;
    *(s32 *)(p + 0x300) = g_p1_chain_points_shown2;
    *(u16 *)(p + 0x304) = g_p1_hits;
    *(u16 *)(p + 0x306) = g_p1_hits_shown;
    *(u16 *)(p + 0x308) = g_p1_laser_hit_timer;
    *(u16 *)(p + 0x30A) = g_p1_laser_hit_step;
    *(s32 *)(p + 0x30C) = g_p2_chain_first_score;
    *(s32 *)(p + 0x310) = g_p2_chain_first_score_shown;
    *(u16 *)(p + 0x314) = g_p2_combo_timer;
    *(u16 *)(p + 0x316) = (*(u16 *)&g_p2_chain_points_display_timer);
    *(u16 *)(p + 0x318) = g_p2_hit_display_timer;
    *(u16 *)(p + 0x31A) = g_p2_combo_break_color_timer;
    *(u16 *)(p + 0x31C) = (*(u16 *)&g_p2_hit10_display_timer);
    *(u16 *)(p + 0x31E) = g_p2_hit10_color_timer;
    *(u16 *)(p + 0x320) = g_p2_hit10_anim_count;
    *(s32 *)(p + 0x324) = g_p2_chain_points;
    *(s32 *)(p + 0x328) = g_p2_chain_points_shown;
    *(s32 *)(p + 0x32C) = g_p2_chain_points_shown2;
    *(u16 *)(p + 0x330) = g_p2_hits;
    *(u16 *)(p + 0x332) = g_p2_hits_shown;
    *(u16 *)(p + 0x334) = g_p2_laser_hit_timer;
    *(u16 *)(p + 0x336) = g_p2_laser_hit_step;
    *(u16 *)(p + 0x338) = g_boss_hit_decay_timer;
    *(u16 *)(p + 0x33A) = g_boss_hit_anim_count;
    *(u16 *)(p + 0x33C) = g_boss_hits;
    *(u16 *)(p + 0x33E) = (*(u16 *)&g_boss_hit_palette);
    *(u16 *)(p + 0x340) = g_boss_hit_bonus_timer;
    *(s32 *)(p + 0x344) = g_boss_hit_bonus;
    *(s32 *)(p + 0x348) = g_boss_score;
    *(u16 *)(p + 0x34C) = (*(u16 *)&g_boss_hp_bar_flags);
    *(u16 *)(p + 0x34E) = g_p1_max_hits;
    *(u16 *)(p + 0x350) = g_p2_max_hits;
    *(u16 *)(p + 0x352) = g_p1_laser_hyper_timer;
    *(u16 *)(p + 0x354) = g_p2_laser_hyper_timer;
    *(u16 *)(p + 0x356) = g_p1_shot_hyper_timer;
    *(u16 *)(p + 0x358) = g_p2_shot_hyper_timer;
    *(u16 *)(p + 0x35A) = g_p1_hyper_active;
    *(u16 *)(p + 0x35C) = g_p2_hyper_active;
    *(u16 *)(p + 0x35E) = g_p1_hyper_time;
    *(u16 *)(p + 0x360) = g_p2_hyper_time;
    *(u16 *)(p + 0x362) = g_p1_hyper_total;
    *(u16 *)(p + 0x364) = g_p2_hyper_total;
    *(u16 *)(p + 0x366) = g_p1_hyper_gauge;
    *(u16 *)(p + 0x368) = g_p2_hyper_gauge;
    *(u16 *)(p + 0x36A) = g_p1_hyper_combo_decay;
    *(u16 *)(p + 0x36C) = g_p2_hyper_combo_decay;
    *(u16 *)(p + 0x36E) = g_hyper_text_slide;
    *(u16 *)(p + 0x370) = g_p1_hyper_level;
    *(u16 *)(p + 0x372) = g_p2_hyper_level;
    *(u16 *)(p + 0x374) = g_p1_hyper_in_effect;
    *(u16 *)(p + 0x376) = g_p2_hyper_in_effect;
    *(u16 *)(p + 0x378) = g_p1_hyper_items;
    *(u16 *)(p + 0x37A) = g_p2_hyper_items;
    *(u16 *)(p + 0x37C) = g_p1_hyper_items_pending;
    *(u16 *)(p + 0x37E) = g_p2_hyper_items_pending;
    *(u16 *)(p + 0x380) = g_boss_hyper_wait;
    *(u16 *)(p + 0x382) = g_hyper_hit_scratch;
    *(u16 *)(p + 0x384) = g_hyper_level_hit_scratch;
    *(u16 *)(p + 0x386) = g_boss_double_speed;
    *(u16 *)(p + 0x388) = g_hyper_debug_check;
    *(u16 *)(p + 0x38A) = g_score_panel_intro;
    *(u16 *)(p + 0x38C) = g_score_task_active;
    *(s32 *)(p + 0x390) = g_p1_hyper_effect_sprite;
    *(s32 *)(p + 0x394) = g_p2_hyper_effect_sprite;
    *(u16 *)(p + 0x398) = g_p1_hyper_effect_frame;
    *(u16 *)(p + 0x39A) = g_p2_hyper_effect_frame;
    *(u16 *)(p + 0x39C) = g_p1_hyper_effect_flag;
    *(u16 *)(p + 0x39E) = g_p2_hyper_effect_flag;
    *(u16 *)(p + 0x3A0) = g_p1_hyper_effect_delay;
    *(u16 *)(p + 0x3A2) = g_p2_hyper_effect_delay;
}

extern s32 g_replay_pointer_not_found;

s32 pointer_to_table_index(Reg32 *entry, Reg32 *table, s32 count) {
    Reg32 key;
    Reg32 cur;
    s32 offset;
    u8 *mark = &entry->b[2];

    key.h[1] = entry->h[0];
    key.h[0] = entry->h[1];
    if (key.w == 0) {
        return -1;
    }
    for (offset = 0; offset < count * 4; offset += 4) {
        cur.h[1] = table->h[1];
        cur.h[0] = table->h[0];
        if (cur.w == key.w) {
            entry->h[0] = offset;
            entry->b[3] = 0x80;
            *mark = 0x99;
            return 1;
        }
        table++;
    }
    g_replay_pointer_not_found = 1;
    return 0;
}

typedef union {
    u16 h[2];
    u32 w;
} HalfPair;


s32 pointer_to_block_offset(u16 *addr, u16 *starts, s32 *sizes, s32 count) {
    HalfPair target;
    HalfPair start;
    s32 i;
    s32 size;
    s32 j;
    u32 pos;

    u8 *hi = (u8 *)(addr + 1);

    target.h[1] = addr[0];
    target.h[0] = addr[1];
    if (target.w == 0) {
        return -1;
    }
    for (i = 0; i < count * 4; i += 4) {
        start.h[1] = starts[1];
        start.h[0] = starts[0];
        pos = start.w;
        size = *(s32 *)((u8 *)sizes + i);
        if (pos <= target.w && target.w < pos + size) {
            for (j = 0; j < size; j += 2) {
                if (pos == target.w) {
                    ((u8 *)addr)[1] = i;
                    ((u8 *)addr)[0] = j;
                    ((u8 *)addr)[3] = 0x81;
                    *hi = 0x99;
                    return 1;
                }
                pos += 2;
            }
        }
        starts += 2;
    }
    g_replay_pointer_not_found = 1;
    return 0;
}

s32 pointer_to_array_offset(Reg32 *entry, u8 *code, u32 count, u32 stride) {
    Reg32 key;
    u32 offset;
    u8 *mark = &entry->b[2];

    key.h[1] = entry->h[0];
    key.h[0] = entry->h[1];
    if (key.w == 0) {
        return -1;
    }
    for (offset = 0; offset < count * stride; offset += stride) {
        if ((u32)code == key.w) {
            entry->h[0] = offset;
            entry->b[3] = 0x82;
            *mark = 0x99;
            return 1;
        }
        code += stride;
    }
    g_replay_pointer_not_found = 1;
    return 0;
}

s32 pointer_to_array_offset_swapped(Reg32 *entry, u8 *code, u32 count, u32 stride) {
    Reg32 key;
    u32 offset;
    u8 *mark = &entry->b[2];

    key.h[0] = entry->h[0];
    key.h[1] = entry->h[1];
    if (key.w == 0) {
        return -1;
    }
    for (offset = 0; offset < count * stride; offset += stride) {
        if ((u32)code == key.w) {
            entry->h[0] = offset;
            entry->b[3] = 0x83;
            *mark = 0x99;
            return 1;
        }
        code += stride;
    }
    g_replay_pointer_not_found = 1;
    return 0;
}

extern u16 entity_draw_layer_routines[];
extern void *replay_targets_players[2];
extern void *replay_targets_lives[2];

void replay_snapshot_pointers_encode(u8 *base) {
    s32 off;
    u8 *p;
    u8 *q;
    s32 j;
    u8 *r;
    s32 k;
    u8 *t;
    s32 m;
    s32 n;

    for (off = 0; off < 0xC08; off += 0x2C) {
        p = base + off;
        pointer_to_table_index((void *)(p + 0x24), (void *)replay_targets_players, 2);
        pointer_to_table_index((void *)(p + 0x28), (void *)entity_draw_layer_routines, 6);
    }
    pointer_to_table_index((void *)(base + 0xCF0), (void *)replay_targets_option_style_a, 3);
    pointer_to_table_index((void *)(base + 0xD0A), (void *)replay_targets_option_style_a, 3);
    pointer_to_table_index((void *)(base + 0xD20), (void *)replay_targets_option_style_b, 3);
    pointer_to_table_index((void *)(base + 0xD32), (void *)replay_targets_option_style_c, 3);
    pointer_to_table_index((void *)(base + 0xD54), (void *)replay_targets_option_style_a, 3);
    pointer_to_table_index((void *)(base + 0xD6E), (void *)replay_targets_option_style_a, 3);
    pointer_to_table_index((void *)(base + 0xD84), (void *)replay_targets_option_style_b, 3);
    pointer_to_table_index((void *)(base + 0xD96), (void *)replay_targets_option_style_c, 3);
    for (off = 0; off < 0xD80; off += 0x30) {
        pointer_to_table_index((void *)(base + off + 0xDC0), (void *)replay_targets_shot_lists, 0x150);
    }
    for (j = 0; j < 0x510; j += 0x30) {
        q = base + j;
        pointer_to_table_index((void *)(q + 0x1B40), (void *)replay_targets_option_sprites, 0x2C);
        pointer_to_table_index((void *)(q + 0x1B4A), (void *)replay_targets_option_params_a, 5);
        pointer_to_block_offset((void *)(q + 0x1B4E), (void *)replay_blocks_option_params, (void *)replay_block_sizes_option_params, 0x18);
        pointer_to_table_index((void *)(q + 0x2140), (void *)replay_targets_option_sprites, 0x2C);
        pointer_to_table_index((void *)(q + 0x214A), (void *)replay_targets_option_params_a, 5);
        pointer_to_block_offset((void *)(q + 0x214E), (void *)replay_blocks_option_params, (void *)replay_block_sizes_option_params, 0x18);
    }
    q = base + j;
    pointer_to_table_index((void *)(q + 0x1B40), (void *)replay_targets_option_sprites, 0x2C);
    pointer_to_table_index((void *)(q + 0x1B4A), (void *)replay_targets_option_params_a, 5);
    pointer_to_block_offset((void *)(q + 0x1B4E), (void *)replay_blocks_option_params, (void *)replay_block_sizes_option_params, 0x18);
    pointer_to_table_index((void *)(q + 0x2140), (void *)replay_targets_option_sprites, 0x2C);
    pointer_to_table_index((void *)(q + 0x214A), (void *)replay_targets_option_params_a, 5);
    pointer_to_block_offset((void *)(q + 0x214E), (void *)replay_blocks_option_params, (void *)replay_block_sizes_option_params, 0x18);
    for (k = 0x540; k < 0x5A0; k += 0x30) {
        r = base + k;
        pointer_to_block_offset((void *)(r + 0x1B40), (void *)replay_blocks_option_params, (void *)replay_block_sizes_option_params, 0x18);
        pointer_to_table_index((void *)(r + 0x1B4A), (void *)replay_targets_option_params_a, 5);
        pointer_to_block_offset((void *)(r + 0x1B4E), (void *)replay_blocks_option_params, (void *)replay_block_sizes_option_params, 0x18);
        pointer_to_block_offset((void *)(r + 0x2140), (void *)replay_blocks_option_params, (void *)replay_block_sizes_option_params, 0x18);
        pointer_to_table_index((void *)(r + 0x214A), (void *)replay_targets_option_params_a, 5);
        pointer_to_block_offset((void *)(r + 0x214E), (void *)replay_blocks_option_params, (void *)replay_block_sizes_option_params, 0x18);
    }
    r = base + k;
    pointer_to_table_index((void *)(r + 0x1B40), (void *)replay_targets_option_sprites, 0x2C);
    pointer_to_table_index((void *)(r + 0x1B4A), (void *)replay_targets_option_params_a, 5);
    pointer_to_block_offset((void *)(r + 0x1B4E), (void *)replay_blocks_option_params, (void *)replay_block_sizes_option_params, 0x18);
    pointer_to_table_index((void *)(r + 0x2140), (void *)replay_targets_option_sprites, 0x2C);
    pointer_to_table_index((void *)(r + 0x214A), (void *)replay_targets_option_params_a, 5);
    pointer_to_block_offset((void *)(r + 0x214E), (void *)replay_blocks_option_params, (void *)replay_block_sizes_option_params, 0x18);
    r = base + (k + 0x30);
    pointer_to_table_index((void *)(r + 0x1B40), (void *)replay_targets_option_sprites, 0x2C);
    pointer_to_table_index((void *)(r + 0x1B4C), (void *)replay_targets_option_params_b, 0x14);
    pointer_to_table_index((void *)(r + 0x2140), (void *)replay_targets_option_sprites, 0x2C);
    pointer_to_table_index((void *)(r + 0x214C), (void *)replay_targets_option_params_b, 0x14);
    for (m = 0; m < 0x7E0; m += 0x30) {
        t = base + m + 0x27C0;
        if (pointer_to_table_index((void *)(t), (void *)replay_targets_bomb, 0x36) == 0 && pointer_to_block_offset((void *)(t), (void *)replay_blocks_bomb, (void *)replay_block_sizes_bomb, 6) != 0) {
            g_replay_pointer_not_found = 0;
        }
    }
    for (off = 0x7E0; off < 0x870; off += 0x30) {
        pointer_to_table_index((void *)(base + off + 0x27C0), (void *)replay_targets_bomb, 0x36);
    }
    pointer_to_block_offset((void *)(base + 0x301C), (void *)replay_blocks_weapon_levels, (void *)replay_block_sizes_weapon_levels, 0xC);
    pointer_to_block_offset((void *)(base + 0x3020), (void *)replay_blocks_weapon_levels, (void *)replay_block_sizes_weapon_levels, 0xC);
    pointer_to_block_offset((void *)(base + 0x3024), (void *)replay_blocks_weapon_levels, (void *)replay_block_sizes_weapon_levels, 0xC);
    pointer_to_block_offset((void *)(base + 0x3028), (void *)replay_blocks_weapon_levels, (void *)replay_block_sizes_weapon_levels, 0xC);
    pointer_to_array_offset_swapped((void *)(base + 0x318C), (void *)g_enemy_entities_second, 0x32, 0x20);
    pointer_to_table_index((void *)(base + 0x3226), (void *)replay_targets_lives, 2);
    pointer_to_table_index((void *)(base + 0x324A), (void *)replay_targets_lives, 2);
    for (n = 0; n < 0x5A; n += 10) {
        pointer_to_array_offset((void *)(&((u8 (*)[10])(base + 0x32B6))[0][n]), (void *)((u16 *)g_text_layer), 0x800, 4);
        pointer_to_array_offset((void *)(&((u8 (*)[10])(base + 0x3310))[0][n]), (void *)((u16 *)g_text_layer), 0x800, 4);
    }
}

#pragma push
#pragma opt_common_subs off
extern u8 g_text_layer[];


void replay_text_pointers_encode(s32 baseAddress)
{
    s32 entryOffset = 0;

    do {
        pointer_to_array_offset((void *)(entryOffset + baseAddress + 0x1EE), (void *)g_text_layer, 0x800, 4);
        pointer_to_array_offset((void *)(entryOffset + baseAddress + 0x248), (void *)g_text_layer, 0x800, 4);
        entryOffset += 0xA;
    } while (entryOffset < 0x5A);
}
#pragma pop

s32 replay_snapshot_checksum();

void replay_file_pointers_encode(u8 *arg0) {
    g_replay_pointer_not_found = 0;
    replay_snapshot_pointers_encode(arg0 + 0x400);
    replay_text_pointers_encode((s32)(arg0 + 0x5934));
    (*(s32 *)((u8 *)(arg0) + (0x5CE4))) = replay_snapshot_checksum(arg0 + 0x400);
}

typedef union {
    u32 w;
    u16 h[2];
} Pair;

static inline void pointer_decode_read(u16 *dst, u16 *mem, s32 addr) {
    u16 value;

    if (addr != 0) {
        value = *(u16 *)((u8 *)mem + ((s16)addr & ~1));
    } else {
        value = *mem;
    }
    *dst = value;
}

s32 pointer_decode(u8 *entry, u16 *mem, s32 op) {
    Pair r;
    u8 *tag;
    u16 addr;
    u8 lo;
    s32 base;

    tag = entry + 2;
    if (*tag != 0x99) {
        return -1;
    }
    if (entry[3] != op) {
        return 0;
    }
    switch (op) {
    case 0x80:
        addr = *(u16 *)entry;
        pointer_decode_read(&r.h[0], mem, addr);
        pointer_decode_read(&r.h[1], mem, addr + 2);
        *(u16 *)entry = r.h[1];
        *(u16 *)tag = r.h[0];
        break;
    case 0x81:
        lo = entry[1];
        base = entry[0];
        pointer_decode_read(&r.h[0], mem, lo);
        pointer_decode_read(&r.h[1], mem, lo + 2);
        r.w += base;
        *(u16 *)entry = r.h[1];
        *(u16 *)tag = r.h[0];
        break;
    case 0x82:
        r.w = (u32)mem + *(u16 *)entry;
        *(u16 *)entry = r.h[1];
        *(u16 *)tag = r.h[0];
        break;
    case 0x83:
        r.w = (u32)mem + *(u16 *)entry;
        *(u16 *)entry = r.h[0];
        *(u16 *)tag = r.h[1];
        break;
    default:
        return 0;
    }
    return 1;
}


void replay_snapshot_pointers_decode(u8 *base) {
    s32 off;
    u8 *p;
    u8 *q;
    s32 j;
    u8 *r;
    s32 k;
    u8 *t;
    s32 m;
    s32 n;

    for (off = 0; off < 0xC08; off += 0x2C) {
        p = base + off;
        pointer_decode(p + 0x24, (u16 *)replay_targets_players, 0x80);
        pointer_decode(p + 0x28, entity_draw_layer_routines, 0x80);
    }
    pointer_decode(base + 0xCF0, (u16 *)replay_targets_option_style_a, 0x80);
    pointer_decode(base + 0xD0A, (u16 *)replay_targets_option_style_a, 0x80);
    pointer_decode(base + 0xD20, (u16 *)replay_targets_option_style_b, 0x80);
    pointer_decode(base + 0xD32, (u16 *)replay_targets_option_style_c, 0x80);
    pointer_decode(base + 0xD54, (u16 *)replay_targets_option_style_a, 0x80);
    pointer_decode(base + 0xD6E, (u16 *)replay_targets_option_style_a, 0x80);
    pointer_decode(base + 0xD84, (u16 *)replay_targets_option_style_b, 0x80);
    pointer_decode(base + 0xD96, (u16 *)replay_targets_option_style_c, 0x80);
    for (off = 0; off < 0xD80; off += 0x30) {
        pointer_decode(base + off + 0xDC0, (u16 *)replay_targets_shot_lists, 0x80);
    }
    for (j = 0; j < 0x510; j += 0x30) {
        q = base + j;
        pointer_decode(q + 0x1B40, (u16 *)replay_targets_option_sprites, 0x80);
        pointer_decode(q + 0x1B4A, (u16 *)replay_targets_option_params_a, 0x80);
        pointer_decode(q + 0x1B4E, (u16 *)replay_blocks_option_params, 0x81);
        pointer_decode(q + 0x2140, (u16 *)replay_targets_option_sprites, 0x80);
        pointer_decode(q + 0x214A, (u16 *)replay_targets_option_params_a, 0x80);
        pointer_decode(q + 0x214E, (u16 *)replay_blocks_option_params, 0x81);
    }
    q = base + j;
    pointer_decode(q + 0x1B40, (u16 *)replay_targets_option_sprites, 0x80);
    pointer_decode(q + 0x1B4A, (u16 *)replay_targets_option_params_a, 0x80);
    pointer_decode(q + 0x1B4E, (u16 *)replay_blocks_option_params, 0x81);
    pointer_decode(q + 0x2140, (u16 *)replay_targets_option_sprites, 0x80);
    pointer_decode(q + 0x214A, (u16 *)replay_targets_option_params_a, 0x80);
    pointer_decode(q + 0x214E, (u16 *)replay_blocks_option_params, 0x81);
    for (k = 0x540; k < 0x5A0; k += 0x30) {
        r = base + k;
        pointer_decode(r + 0x1B40, (u16 *)replay_blocks_option_params, 0x81);
        pointer_decode(r + 0x1B4A, (u16 *)replay_targets_option_params_a, 0x80);
        pointer_decode(r + 0x1B4E, (u16 *)replay_blocks_option_params, 0x81);
        pointer_decode(r + 0x2140, (u16 *)replay_blocks_option_params, 0x81);
        pointer_decode(r + 0x214A, (u16 *)replay_targets_option_params_a, 0x80);
        pointer_decode(r + 0x214E, (u16 *)replay_blocks_option_params, 0x81);
    }
    r = base + k;
    pointer_decode(r + 0x1B40, (u16 *)replay_targets_option_sprites, 0x80);
    pointer_decode(r + 0x1B4A, (u16 *)replay_targets_option_params_a, 0x80);
    pointer_decode(r + 0x1B4E, (u16 *)replay_blocks_option_params, 0x81);
    pointer_decode(r + 0x2140, (u16 *)replay_targets_option_sprites, 0x80);
    pointer_decode(r + 0x214A, (u16 *)replay_targets_option_params_a, 0x80);
    pointer_decode(r + 0x214E, (u16 *)replay_blocks_option_params, 0x81);
    r = base + (k + 0x30);
    pointer_decode(r + 0x1B40, (u16 *)replay_targets_option_sprites, 0x80);
    pointer_decode(r + 0x1B4C, (u16 *)replay_targets_option_params_b, 0x80);
    pointer_decode(r + 0x2140, (u16 *)replay_targets_option_sprites, 0x80);
    pointer_decode(r + 0x214C, (u16 *)replay_targets_option_params_b, 0x80);
    for (m = 0; m < 0x7E0; m += 0x30) {
        t = base + m + 0x27C0;
        pointer_decode(t, (u16 *)replay_targets_bomb, 0x80);
        pointer_decode(t, (u16 *)replay_blocks_bomb, 0x81);
    }
    for (off = 0x7E0; off < 0x870; off += 0x30) {
        pointer_decode(base + off + 0x27C0, (u16 *)replay_targets_bomb, 0x80);
    }
    pointer_decode(base + 0x301C, (u16 *)replay_blocks_weapon_levels, 0x81);
    pointer_decode(base + 0x3020, (u16 *)replay_blocks_weapon_levels, 0x81);
    pointer_decode(base + 0x3024, (u16 *)replay_blocks_weapon_levels, 0x81);
    pointer_decode(base + 0x3028, (u16 *)replay_blocks_weapon_levels, 0x81);
    pointer_decode(base + 0x318C, ((u16 *)g_enemy_entities_second), 0x83);
    pointer_decode(base + 0x3226, (u16 *)replay_targets_lives, 0x80);
    pointer_decode(base + 0x324A, (u16 *)replay_targets_lives, 0x80);
    for (n = 0; n < 0x5A; n += 10) {
        pointer_decode(&((u8 (*)[10])(base + 0x32B6))[0][n], ((u16 *)g_text_layer), 0x82);
        pointer_decode(&((u8 (*)[10])(base + 0x3310))[0][n], ((u16 *)g_text_layer), 0x82);
    }
}


void replay_text_pointers_decode(u8 *base)
{
    s32 offset = 0;

    do {
        pointer_decode((void *)((u8 *)offset + (s32)base + 0x1EE), (void *)g_text_layer, 0x82);
        pointer_decode((void *)((u8 *)(offset + (s32)base) + 0x248), (void *)g_text_layer, 0x82);
        offset += 0xA;
    } while (offset < 0x5A);
}

s32 replay_snapshot_checksum(s32);                             /* extern */
extern s32 g_replay_checksum;

void replay_file_pointers_decode(s32 arg0) {
    g_replay_checksum = replay_snapshot_checksum(arg0 + 0x400);
    replay_snapshot_pointers_decode((void *)(arg0 + 0x400));
    replay_text_pointers_decode((void *)(arg0 + 0x5934));
}

extern u8 g_player1[];
extern u8 g_player2[];

/* What the pointers of a saved state may aim at; they are stored as an index into these. */
void *replay_targets_players[2] = {
    g_player1,
    g_player2,
};

void *replay_targets_lives[2] = {
    &g_p1_lives,
    &g_p2_lives,
};

#ifndef DEATH_LABEL
/* Four empty tables that end the small data; nothing uses them. */
u16 replay_state_unused_a[4] = { 0, 0, 0, 0 };
u16 replay_state_unused_b[4] = { 0, 0, 0, 0 };
u16 replay_state_unused_c[4] = { 0, 0, 0, 0 };
u16 replay_state_unused_d[4] = { 0, 0, 0, 0 };
#endif

/* .sbss (the compiler lays these out in reverse) */
s32 g_replay_pointer_not_found;
