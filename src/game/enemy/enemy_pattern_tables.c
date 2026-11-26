/* Tables the enemy scripts and several enemy units share. */
#include "common.h"
#include "enemy.h"

void battleship();
void battleship_b();
void battleship_b_first();
void battleship_b_start();
void battleship_first();
void battleship_start();
void bee_container();
void bee_container_first();
void bee_container_start();
void bomb_carrier_first();
void bomb_carrier_start();
void crane_turret();
void crane_turret_first();
void crane_turret_start();
void debris_test_first();
void debris_test_main();
void debris_test_setup();
void dummy_enemy_first();
void dummy_enemy_main();
void dummy_enemy_main_b();
void enemy_remove_entry();
void enemy_remove_entry_entry();
void enemy_spawner_first();
void enemy_spawner_main();
void enemy_spawner_setup();
void explosion_test_first();
void explosion_test_main();
void explosion_test_setup();
void formation_fire_timer_first();
void formation_fire_timer_main();
void formation_fire_timer_setup();
void func_001571D0();
void func_001571E0();
void func_00157260();
void func_001578A0();
void func_001578B0();
void func_001579A0();
void func_00157D80();
void func_00157D90();
void func_00157DC0();
void func_001581E0();
void func_001581F0();
void func_00158370();
void func_00159030();
void func_00159040();
void func_001590B0();
void func_00159C50();
void func_00159C60();
void func_00159CB0();
void func_0015A500();
void func_0015A510();
void func_0015A5B0();
void func_0015AE00();
void func_0015AE10();
void func_0015AE70();
void func_0015AEF0();
void func_0015AF00();
void func_0015B210();
void func_0015C440();
void func_00168110();
void func_00168120();
void func_001683C0();
void func_0016CCD0();
void func_0016CCE0();
void func_0016CD40();
void func_0016EA90();
void func_0016EAA0();
void func_0016ED40();
void func_0016F930();
void func_0016F940();
void func_0016FAE0();
void func_001CBD50();
void func_001CBD60();
void func_001CC0A0();
void func_001D6C80();
void func_001D6C90();
void func_001D6D60();
void func_001F93C0();
void func_001F93D0();
void func_001F9450();
void func_001F9540();
void func_001F9550();
void func_001F95D0();
void ground_turret_a();
void ground_turret_a_first();
void ground_turret_a_start();
void ground_turret_b();
void ground_turret_b_first();
void ground_turret_b_start();
void ground_turret_c();
void ground_turret_c_first();
void ground_turret_c_start();
void heli_a();
void heli_a_first();
void heli_a_start();
void heli_b();
void heli_b_first();
void heli_b_start();
void heli_c();
void heli_c_first();
void heli_c_start();
void heli_d();
void heli_d_first();
void heli_d_start();
void heli_e();
void heli_e_first();
void heli_e_start();
void heli_f();
void heli_f_first();
void heli_f_start();
void heli_g();
void heli_g_first();
void heli_g_start();
void heli_h();
void heli_h_first();
void heli_h_start();
void item_carrier();
void item_carrier_first();
void item_carrier_start();
void map_cell_test_first();
void map_cell_test_main();
void map_cell_test_setup();
void mid_flyer_a();
void mid_flyer_a_first();
void mid_flyer_a_start();
void mid_flyer_b();
void mid_flyer_b_first();
void mid_flyer_b_start();
void mid_flyer_c();
void mid_flyer_c_first();
void mid_flyer_c_start();
void mid_flyer_d();
void mid_flyer_d_first();
void mid_flyer_d_start();
void mid_flyer_e();
void mid_flyer_e_first();
void mid_flyer_e_start();
void mid_tank_horizontal();
void mid_tank_horizontal_b();
void mid_tank_horizontal_b_first();
void mid_tank_horizontal_b_start();
void mid_tank_horizontal_first();
void mid_tank_horizontal_start();
void mid_tank_vertical();
void mid_tank_vertical_first();
void mid_tank_vertical_start();
void rail_turret();
void rail_turret_first();
void rail_turret_start();
void shooter_drone();
void shooter_drone_first();
void shooter_drone_start();
void small_tank_a();
void small_tank_a_first();
void small_tank_a_start();
void small_tank_b();
void small_tank_b_first();
void small_tank_b_start();
void stage1_boss_breakable_bullet();
void stage1_boss_breakable_bullet_b();
void stage1_boss_breakable_bullet_b_first();
void stage1_boss_breakable_bullet_b_start();
void stage1_boss_breakable_bullet_first();
void stage1_boss_breakable_bullet_start();
void stage1_boss_entrance();
void stage1_boss_entrance_first();
void stage1_boss_entrance_start();
void stage1_boss_first();
void stage1_boss_main();
void stage1_boss_side_bullet();
void stage1_boss_side_bullet_first();
void stage1_boss_side_bullet_start();
void stage1_boss_start();
void stage1_midboss_first();
void stage1_midboss_main();
void stage1_midboss_start();
void stage1_midboss_wreck();
void stage1_midboss_wreck_first();
void stage1_midboss_wreck_start();
void stage2_blooming_base();
void stage2_blooming_base_first();
void stage2_blooming_base_start();
void stage2_boss_cannon_shell();
void stage2_boss_cannon_shell_first();
void stage2_boss_cannon_shell_start();
void stage2_boss_dropped_bomb();
void stage2_boss_dropped_bomb_first();
void stage2_boss_dropped_bomb_start();
void stage2_boss_first();
void stage2_boss_hangar();
void stage2_boss_hangar_first();
void stage2_boss_hangar_start();
void stage2_boss_main();
void stage2_boss_ripple();
void stage2_boss_ripple_first();
void stage2_boss_ripple_start();
void stage2_boss_shoulder_bullet();
void stage2_boss_shoulder_bullet_first();
void stage2_boss_shoulder_bullet_start();
void stage2_boss_spread_bullet();
void stage2_boss_spread_bullet_first();
void stage2_boss_spread_bullet_start();
void stage2_boss_start();
void stage2_gymnasium();
void stage2_gymnasium_first();
void stage2_gymnasium_start();
void stage2_long_warehouse();
void stage2_long_warehouse_first();
void stage2_long_warehouse_start();
void stage2_sliding_gun();
void stage2_sliding_gun_first();
void stage2_sliding_gun_start();
void stage2_square_warehouse();
void stage2_square_warehouse_first();
void stage2_square_warehouse_start();
void stage2_wrecker_gun();
void stage2_wrecker_gun_first();
void stage2_wrecker_gun_start();
void stage3_boss_first();
void stage3_boss_lid_bullet();
void stage3_boss_lid_bullet_first();
void stage3_boss_lid_bullet_start();
void stage3_boss_main();
void stage3_boss_start();
void stage3_boss_timber();
void stage3_boss_timber_first();
void stage3_boss_timber_start();
void stage3_cloud();
void stage3_cloud_first();
void stage3_cloud_start();
void stage3_gun_a();
void stage3_gun_a_first();
void stage3_gun_a_start();
void stage3_gun_b_first();
void stage3_gun_b_start();
void stage3_gun_c_first();
void stage3_gun_c_start();
void stage3_gun_d_first();
void stage3_gun_d_start();
void stage3_large_gun();
void stage3_large_gun_first();
void stage3_large_gun_start();
void stage3_midboss_first();
void stage3_midboss_main();
void stage3_midboss_start();
void stage4_boss_cutter();
void stage4_boss_cutter_first();
void stage4_boss_cutter_start();
void stage4_boss_first();
void stage4_boss_main();
void stage4_boss_missile();
void stage4_boss_missile_first();
void stage4_boss_missile_start();
void stage4_boss_start();
void stage4_gate();
void stage4_gate_first();
void stage4_gate_start();
void stage4_heavy_cannon();
void stage4_heavy_cannon_casing();
void stage4_heavy_cannon_casing_first();
void stage4_heavy_cannon_casing_start();
void stage4_heavy_cannon_first();
void stage4_heavy_cannon_start();
void stage4_lift();
void stage4_lift_first();
void stage4_lift_start();
void stage4_reactor();
void stage4_reactor_first();
void stage4_reactor_start();
void stage4_tachyon_particle();
void stage4_tachyon_particle_first();
void stage4_tachyon_particle_start();
void stage4_wave_cannon();
void stage4_wave_cannon_first();
void stage4_wave_cannon_start();
void stage5_bee_drone();
void stage5_bee_drone_first();
void stage5_bee_drone_start();
void stage5_bee_hatch();
void stage5_bee_hatch_first();
void stage5_bee_hatch_start();
void stage5_boss_first();
void stage5_boss_main();
void stage5_boss_start();
void stage5_large_spider_head();
void stage5_large_spider_head_first();
void stage5_large_spider_head_start();
void stage5_large_spider_turret();
void stage5_large_spider_turret_first();
void stage5_large_spider_turret_start();
void stage5_midboss3_first();
void stage5_midboss3_main();
void stage5_midboss3_start();
void stage5_midboss4_arrival();
void stage5_midboss4_arrival_first();
void stage5_midboss4_arrival_start();
void stage5_midboss4_first();
void stage5_midboss4_main();
void stage5_midboss4_start();
void stage5_midboss4_wave_beam();
void stage5_midboss4_wave_beam_first();
void stage5_midboss4_wave_beam_start();
void stage5_midboss5_drone();
void stage5_midboss5_drone_first();
void stage5_midboss5_drone_start();
void stage5_midboss5_first();
void stage5_midboss5_large_blast();
void stage5_midboss5_large_blast_first();
void stage5_midboss5_large_blast_start();
void stage5_midboss5_large_missile();
void stage5_midboss5_large_missile_first();
void stage5_midboss5_large_missile_start();
void stage5_midboss5_main();
void stage5_midboss5_small_blast();
void stage5_midboss5_small_blast_first();
void stage5_midboss5_small_blast_start();
void stage5_midboss5_small_missile();
void stage5_midboss5_small_missile_first();
void stage5_midboss5_small_missile_start();
void stage5_midboss5_spin_drone();
void stage5_midboss5_spin_drone_first();
void stage5_midboss5_spin_drone_start();
void stage5_midboss5_start();
void stage5_small_spider_head();
void stage5_small_spider_head_first();
void stage5_small_spider_head_start();
void stage5_small_spider_turret();
void stage5_small_spider_turret_first();
void stage5_small_spider_turret_start();
void stage5_small_turret();
void stage5_small_turret_first();
void stage5_small_turret_start();
void stage5_spiderling();
void stage5_spiderling_first();
void stage5_spiderling_start();
void star_container();
void star_container_first();
void star_container_start();
void warning_sign();
void warning_sign_first();
void warning_sign_start();
void water_flower_turret();
void water_flower_turret_first();
void water_flower_turret_start();
void wreck_test_first();
void wreck_test_main();
void wreck_test_setup();

/* The routines of every kind of enemy (enemy_kinds.h): the one that starts it and the one run every frame. */
EnemyRoutines g_enemy_routines[128] = {
    /* 0x00 */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x01 */ { func_0016CCE0, func_0016CD40 },
    /* 0x02 */ { explosion_test_setup, explosion_test_main },
    /* 0x03 */ { debris_test_setup, debris_test_main },
    /* 0x04 */ { wreck_test_setup, wreck_test_main },
    /* 0x05 */ { heli_a_start, heli_a },
    /* 0x06 */ { heli_b_start, heli_b },
    /* 0x07 */ { heli_c_start, heli_c },
    /* 0x08 */ { heli_d_start, heli_d },
    /* 0x09 */ { heli_e_start, heli_e },
    /* 0x0A */ { heli_f_start, heli_f },
    /* 0x0B */ { heli_g_start, heli_g },
    /* 0x0C */ { heli_h_start, heli_h },
    /* 0x0D */ { stage1_midboss_start, stage1_midboss_main },
    /* 0x0E */ { stage1_boss_start, stage1_boss_main },
    /* 0x0F */ { stage1_boss_breakable_bullet_start, stage1_boss_breakable_bullet },
    /* 0x10 */ { small_tank_a_start, small_tank_a },
    /* 0x11 */ { small_tank_b_start, small_tank_b },
    /* 0x12 */ { stage3_midboss_start, stage3_midboss_main },
    /* 0x13 */ { func_001D6C90, func_001D6D60 },
    /* 0x14 */ { stage3_cloud_start, stage3_cloud },
    /* 0x15 */ { func_001581F0, func_00158370 },
    /* 0x16 */ { func_0015A510, func_0015A5B0 },
    /* 0x17 */ { battleship_b_start, battleship_b },
    /* 0x18 */ { func_00159040, func_001590B0 },
    /* 0x19 */ { func_0015AE10, func_0015AE70 },
    /* 0x1A */ { func_0016EAA0, func_0016ED40 },
    /* 0x1B */ { func_0016F940, func_0016FAE0 },
    /* 0x1C */ { stage1_midboss_wreck_start, stage1_midboss_wreck },
    /* 0x1D */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x1E */ { stage1_boss_side_bullet_start, stage1_boss_side_bullet },
    /* 0x1F */ { stage1_boss_breakable_bullet_b_start, stage1_boss_breakable_bullet_b },
    /* 0x20 */ { enemy_spawner_setup, enemy_spawner_main },
    /* 0x21 */ { enemy_spawner_setup, enemy_spawner_main },
    /* 0x22 */ { enemy_spawner_setup, enemy_spawner_main },
    /* 0x23 */ { enemy_spawner_setup, enemy_spawner_main },
    /* 0x24 */ { stage1_boss_entrance_start, stage1_boss_entrance },
    /* 0x25 */ { heli_a_start, heli_a },
    /* 0x26 */ { heli_b_start, heli_b },
    /* 0x27 */ { heli_c_start, heli_c },
    /* 0x28 */ { heli_d_start, heli_d },
    /* 0x29 */ { heli_e_start, heli_e },
    /* 0x2A */ { heli_f_start, heli_f },
    /* 0x2B */ { heli_g_start, heli_g },
    /* 0x2C */ { heli_h_start, heli_h },
    /* 0x2D */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x2E */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x2F */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x30 */ { stage2_boss_start, stage2_boss_main },
    /* 0x31 */ { warning_sign_start, warning_sign },
    /* 0x32 */ { stage2_boss_shoulder_bullet_start, stage2_boss_shoulder_bullet },
    /* 0x33 */ { stage2_boss_spread_bullet_start, stage2_boss_spread_bullet },
    /* 0x34 */ { stage2_boss_cannon_shell_start, stage2_boss_cannon_shell },
    /* 0x35 */ { stage2_boss_dropped_bomb_start, stage2_boss_dropped_bomb },
    /* 0x36 */ { battleship_start, battleship },
    /* 0x37 */ { stage3_gun_a_start, stage3_gun_a },
    /* 0x38 */ { stage3_gun_b_start, stage3_gun_a },
    /* 0x39 */ { stage3_gun_c_start, stage3_gun_a },
    /* 0x3A */ { stage3_gun_d_start, stage3_gun_a },
    /* 0x3B */ { stage3_large_gun_start, stage3_large_gun },
    /* 0x3C */ { func_00159C60, func_00159CB0 },
    /* 0x3D */ { func_0015AF00, func_0015B210 },
    /* 0x3E */ { func_001571E0, func_00157260 },
    /* 0x3F */ { func_001578B0, func_001579A0 },
    /* 0x40 */ { stage4_boss_start, stage4_boss_main },
    /* 0x41 */ { stage4_boss_missile_start, stage4_boss_missile },
    /* 0x42 */ { stage4_boss_cutter_start, stage4_boss_cutter },
    /* 0x43 */ { stage5_midboss4_arrival_start, stage5_midboss4_arrival },
    /* 0x44 */ { stage5_midboss4_start, stage5_midboss4_main },
    /* 0x45 */ { stage5_small_turret_start, stage5_small_turret },
    /* 0x46 */ { stage5_bee_hatch_start, stage5_bee_hatch },
    /* 0x47 */ { stage5_midboss3_start, stage5_midboss3_main },
    /* 0x48 */ { stage5_small_spider_turret_start, stage5_small_spider_turret },
    /* 0x49 */ { stage5_small_spider_head_start, stage5_small_spider_head },
    /* 0x4A */ { stage5_large_spider_turret_start, stage5_large_spider_turret },
    /* 0x4B */ { stage5_large_spider_head_start, stage5_large_spider_head },
    /* 0x4C */ { stage5_midboss5_start, stage5_midboss5_main },
    /* 0x4D */ { stage2_boss_ripple_start, stage2_boss_ripple },
    /* 0x4E */ { stage5_midboss5_small_missile_start, stage5_midboss5_small_missile },
    /* 0x4F */ { stage5_midboss5_small_blast_start, stage5_midboss5_small_blast },
    /* 0x50 */ { stage5_midboss5_large_missile_start, stage5_midboss5_large_missile },
    /* 0x51 */ { stage5_midboss5_large_blast_start, stage5_midboss5_large_blast },
    /* 0x52 */ { stage5_midboss5_drone_start, stage5_midboss5_drone },
    /* 0x53 */ { stage5_midboss4_wave_beam_start, stage5_midboss4_wave_beam },
    /* 0x54 */ { stage5_spiderling_start, stage5_spiderling },
    /* 0x55 */ { stage5_bee_drone_start, stage5_bee_drone },
    /* 0x56 */ { func_001F93D0, func_001F9450 },
    /* 0x57 */ { func_001F9550, func_001F95D0 },
    /* 0x58 */ { stage5_midboss5_spin_drone_start, stage5_midboss5_spin_drone },
    /* 0x59 */ { func_00157D90, func_00157DC0 },
    /* 0x5A */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x5B */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x5C */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x5D */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x5E */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x5F */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x60 */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x61 */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x62 */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x63 */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x64 */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x65 */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x66 */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x67 */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x68 */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x69 */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x6A */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x6B */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x6C */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x6D */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x6E */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x6F */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x70 */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x71 */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x72 */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x73 */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x74 */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x75 */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x76 */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x77 */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x78 */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x79 */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x7A */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x7B */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x7C */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x7D */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x7E */ { dummy_enemy_main, dummy_enemy_main_b },
    /* 0x7F */ { map_cell_test_setup, map_cell_test_main },
};

/* The routine that claims the enemy's entities, by kind. */
void (*g_enemy_first_routines[128])() = {
    /* 0x00 */ dummy_enemy_first,
    /* 0x01 */ func_0016CCD0,
    /* 0x02 */ explosion_test_first,
    /* 0x03 */ debris_test_first,
    /* 0x04 */ wreck_test_first,
    /* 0x05 */ heli_a_first,
    /* 0x06 */ heli_b_first,
    /* 0x07 */ heli_c_first,
    /* 0x08 */ heli_d_first,
    /* 0x09 */ heli_e_first,
    /* 0x0A */ heli_f_first,
    /* 0x0B */ heli_g_first,
    /* 0x0C */ heli_h_first,
    /* 0x0D */ stage1_midboss_first,
    /* 0x0E */ stage1_boss_first,
    /* 0x0F */ stage1_boss_breakable_bullet_first,
    /* 0x10 */ small_tank_a_first,
    /* 0x11 */ small_tank_b_first,
    /* 0x12 */ stage3_midboss_first,
    /* 0x13 */ func_001D6C80,
    /* 0x14 */ stage3_cloud_first,
    /* 0x15 */ func_001581E0,
    /* 0x16 */ func_0015A500,
    /* 0x17 */ battleship_b_first,
    /* 0x18 */ func_00159030,
    /* 0x19 */ func_0015AE00,
    /* 0x1A */ func_0016EA90,
    /* 0x1B */ func_0016F930,
    /* 0x1C */ stage1_midboss_wreck_first,
    /* 0x1D */ dummy_enemy_first,
    /* 0x1E */ stage1_boss_side_bullet_first,
    /* 0x1F */ stage1_boss_breakable_bullet_b_first,
    /* 0x20 */ enemy_spawner_first,
    /* 0x21 */ enemy_spawner_first,
    /* 0x22 */ enemy_spawner_first,
    /* 0x23 */ enemy_spawner_first,
    /* 0x24 */ stage1_boss_entrance_first,
    /* 0x25 */ heli_a_first,
    /* 0x26 */ heli_b_first,
    /* 0x27 */ heli_c_first,
    /* 0x28 */ heli_d_first,
    /* 0x29 */ heli_e_first,
    /* 0x2A */ heli_f_first,
    /* 0x2B */ heli_g_first,
    /* 0x2C */ heli_h_first,
    /* 0x2D */ dummy_enemy_first,
    /* 0x2E */ dummy_enemy_first,
    /* 0x2F */ dummy_enemy_first,
    /* 0x30 */ stage2_boss_first,
    /* 0x31 */ warning_sign_first,
    /* 0x32 */ stage2_boss_shoulder_bullet_first,
    /* 0x33 */ stage2_boss_spread_bullet_first,
    /* 0x34 */ stage2_boss_cannon_shell_first,
    /* 0x35 */ stage2_boss_dropped_bomb_first,
    /* 0x36 */ battleship_first,
    /* 0x37 */ stage3_gun_a_first,
    /* 0x38 */ stage3_gun_b_first,
    /* 0x39 */ stage3_gun_c_first,
    /* 0x3A */ stage3_gun_d_first,
    /* 0x3B */ stage3_large_gun_first,
    /* 0x3C */ func_00159C50,
    /* 0x3D */ func_0015AEF0,
    /* 0x3E */ func_001571D0,
    /* 0x3F */ func_001578A0,
    /* 0x40 */ stage4_boss_first,
    /* 0x41 */ stage4_boss_missile_first,
    /* 0x42 */ stage4_boss_cutter_first,
    /* 0x43 */ stage5_midboss4_arrival_first,
    /* 0x44 */ stage5_midboss4_first,
    /* 0x45 */ stage5_small_turret_first,
    /* 0x46 */ stage5_bee_hatch_first,
    /* 0x47 */ stage5_midboss3_first,
    /* 0x48 */ stage5_small_spider_turret_first,
    /* 0x49 */ stage5_small_spider_head_first,
    /* 0x4A */ stage5_large_spider_turret_first,
    /* 0x4B */ stage5_large_spider_head_first,
    /* 0x4C */ stage5_midboss5_first,
    /* 0x4D */ stage2_boss_ripple_first,
    /* 0x4E */ stage5_midboss5_small_missile_first,
    /* 0x4F */ stage5_midboss5_small_blast_first,
    /* 0x50 */ stage5_midboss5_large_missile_first,
    /* 0x51 */ stage5_midboss5_large_blast_first,
    /* 0x52 */ stage5_midboss5_drone_first,
    /* 0x53 */ stage5_midboss4_wave_beam_first,
    /* 0x54 */ stage5_spiderling_first,
    /* 0x55 */ stage5_bee_drone_first,
    /* 0x56 */ func_001F93C0,
    /* 0x57 */ func_001F9540,
    /* 0x58 */ stage5_midboss5_spin_drone_first,
    /* 0x59 */ func_00157D80,
    /* 0x5A */ dummy_enemy_first,
    /* 0x5B */ dummy_enemy_first,
    /* 0x5C */ dummy_enemy_first,
    /* 0x5D */ dummy_enemy_first,
    /* 0x5E */ dummy_enemy_first,
    /* 0x5F */ dummy_enemy_first,
    /* 0x60 */ dummy_enemy_first,
    /* 0x61 */ dummy_enemy_first,
    /* 0x62 */ dummy_enemy_first,
    /* 0x63 */ dummy_enemy_first,
    /* 0x64 */ dummy_enemy_first,
    /* 0x65 */ dummy_enemy_first,
    /* 0x66 */ dummy_enemy_first,
    /* 0x67 */ dummy_enemy_first,
    /* 0x68 */ dummy_enemy_first,
    /* 0x69 */ dummy_enemy_first,
    /* 0x6A */ dummy_enemy_first,
    /* 0x6B */ dummy_enemy_first,
    /* 0x6C */ dummy_enemy_first,
    /* 0x6D */ dummy_enemy_first,
    /* 0x6E */ dummy_enemy_first,
    /* 0x6F */ dummy_enemy_first,
    /* 0x70 */ dummy_enemy_first,
    /* 0x71 */ dummy_enemy_first,
    /* 0x72 */ dummy_enemy_first,
    /* 0x73 */ dummy_enemy_first,
    /* 0x74 */ dummy_enemy_first,
    /* 0x75 */ dummy_enemy_first,
    /* 0x76 */ dummy_enemy_first,
    /* 0x77 */ dummy_enemy_first,
    /* 0x78 */ dummy_enemy_first,
    /* 0x79 */ dummy_enemy_first,
    /* 0x7A */ dummy_enemy_first,
    /* 0x7B */ dummy_enemy_first,
    /* 0x7C */ dummy_enemy_first,
    /* 0x7D */ dummy_enemy_first,
    /* 0x7E */ dummy_enemy_first,
    /* 0x7F */ map_cell_test_first,
};

u16 D_00258FF0[1344] = {
    0x0000, 0x1566, 0x0000, 0x1567, 0x0000, 0x1568, 0x0000, 0x1569, 0x0000, 0x156A, 0x0000, 0x156B, 0x0000, 0x156C, 0x0000, 0x156D,
    0x0000, 0x156E, 0x0000, 0x156F, 0x0000, 0x1570, 0x0000, 0x1571, 0x0000, 0x1572, 0x0000, 0x1573, 0x0000, 0x1574, 0x0000, 0x1575,
    0x0000, 0x1576, 0x0000, 0x1577, 0x0000, 0x1578, 0x0000, 0x1579, 0x0000, 0x157A, 0x0000, 0x157B, 0x0000, 0x157C, 0x0000, 0x157D,
    0x0000, 0x157E, 0x0000, 0x157F, 0x0000, 0x1580, 0x0000, 0x1581, 0x0000, 0x1582, 0x0000, 0x1583, 0x0000, 0x1584, 0x0000, 0x1585,
    0x0000, 0x1586, 0x0000, 0x1587, 0x0000, 0x1588, 0x0000, 0x1589, 0x0000, 0x158A, 0x0000, 0x158B, 0x0000, 0x158C, 0x0000, 0x158D,
    0x0000, 0x158E, 0x0000, 0x158F, 0x0000, 0x1590, 0x0000, 0x1591, 0x0000, 0x1592, 0x0000, 0x1593, 0x0000, 0x1594, 0x0000, 0x1595,
    0x0000, 0x1596, 0x0000, 0x1597, 0x0000, 0x1598, 0x0000, 0x1599, 0x0000, 0x159A, 0x0000, 0x159B, 0x0000, 0x159C, 0x0000, 0x159D,
    0x0000, 0x159E, 0x0000, 0x159F, 0x0000, 0x15A0, 0x0000, 0x15A1, 0x0000, 0x15A2, 0x0000, 0x15A3, 0x0000, 0x15A4, 0x0000, 0x15A5,
    0x0000, 0x15A6, 0x0000, 0x15A7, 0x0000, 0x15A8, 0x0000, 0x15A9, 0x0000, 0x15AA, 0x0000, 0x15AB, 0x0000, 0x15AC, 0x0000, 0x15AD,
    0x0000, 0x15AE, 0x0000, 0x15AF, 0x0000, 0x15B0, 0x0000, 0x15B1, 0x0000, 0x15B2, 0x0000, 0x15B3, 0x0000, 0x15B4, 0x0000, 0x15B5,
    0x0000, 0x15B6, 0x0000, 0x15B7, 0x0000, 0x15B8, 0x0000, 0x15B9, 0x0000, 0x15BA, 0x0000, 0x15BB, 0x0000, 0x15BC, 0x0000, 0x15BD,
    0x0000, 0x15BE, 0x0000, 0x15BF, 0x0000, 0x15C0, 0x0000, 0x15C1, 0x0000, 0x15C2, 0x0000, 0x15C3, 0x0000, 0x15C4, 0x0000, 0x15C5,
    0x0000, 0x15C6, 0x0000, 0x15C7, 0x0000, 0x15C8, 0x0000, 0x15C9, 0x0000, 0x15CA, 0x0000, 0x15CB, 0x0000, 0x15CC, 0x0000, 0x15CD,
    0x0000, 0x15CE, 0x0000, 0x15CF, 0x0000, 0x15D0, 0x0000, 0x15D1, 0x0000, 0x15D2, 0x0000, 0x15D3, 0x0000, 0x15D4, 0x0000, 0x15D5,
    0x0000, 0x15D6, 0x0000, 0x15D7, 0x0000, 0x15D8, 0x0000, 0x15D9, 0x0000, 0x15DA, 0x0000, 0x15DB, 0x0000, 0x15DC, 0x0000, 0x15DD,
    0x0000, 0x15DE, 0x0000, 0x15DF, 0x0000, 0x15E0, 0x0000, 0x15E1, 0x0000, 0x15E2, 0x0000, 0x15E3, 0x0000, 0x15E4, 0x0000, 0x15E5,
    0x0000, 0x15E6, 0x0000, 0x15E7, 0x0000, 0x15E8, 0x0000, 0x15E9, 0x0000, 0x15EA, 0x0000, 0x15EB, 0x0000, 0x15EC, 0x0000, 0x15ED,
    0x0000, 0x15EE, 0x0000, 0x15EF, 0x0000, 0x15F0, 0x0000, 0x15F1, 0x0000, 0x15F2, 0x0000, 0x15F3, 0x0000, 0x15F4, 0x0000, 0x15F5,
    0x0000, 0x15F6, 0x0000, 0x15F7, 0x0000, 0x15F8, 0x0000, 0x15F9, 0x0000, 0x15FA, 0x0000, 0x15FB, 0x0000, 0x15FC, 0x0000, 0x15FD,
    0x0000, 0x15FE, 0x0000, 0x15FF, 0x0000, 0x1600, 0x0000, 0x1601, 0x0000, 0x1602, 0x0000, 0x1603, 0x0000, 0x1604, 0x0000, 0x1605,
    0x0000, 0x1606, 0x0000, 0x1607, 0x0000, 0x1608, 0x0000, 0x1609, 0x0000, 0x160A, 0x0000, 0x160B, 0x0000, 0x160C, 0x0000, 0x160D,
    0x0000, 0x160E, 0x0000, 0x160F, 0x0000, 0x1610, 0x0000, 0x1611, 0x0000, 0x1612, 0x0000, 0x1613, 0x0000, 0x1614, 0x0000, 0x1615,
    0x0000, 0x1616, 0x0000, 0x1617, 0x0000, 0x1618, 0x0000, 0x1619, 0x0000, 0x161A, 0x0000, 0x161B, 0x0000, 0x161C, 0x0000, 0x161D,
    0x0000, 0x161E, 0x0000, 0x161F, 0x0000, 0x1620, 0x0000, 0x1621, 0x0000, 0x1622, 0x0000, 0x1623, 0x0000, 0x1624, 0x0000, 0x1625,
    0x0000, 0x1627, 0x0000, 0x1628, 0x0000, 0x1629, 0x0000, 0x162A, 0x0000, 0x162B, 0x0000, 0x162C, 0x0000, 0x162D, 0x0000, 0x162E,
    0x0000, 0x162F, 0x0000, 0x1630, 0x0000, 0x1631, 0x0000, 0x1632, 0x0000, 0x1633, 0x0000, 0x1634, 0x0000, 0x1635, 0x0000, 0x1636,
    0x0000, 0x1637, 0x0000, 0x1638, 0x0000, 0x1639, 0x0000, 0x163A, 0x0000, 0x163B, 0x0000, 0x163C, 0x0000, 0x163D, 0x0000, 0x163E,
    0x0000, 0x163F, 0x0000, 0x1640, 0x0000, 0x1641, 0x0000, 0x1642, 0x0000, 0x1643, 0x0000, 0x1644, 0x0000, 0x1645, 0x0000, 0x1646,
    0x0540, 0x0000, 0x0500, 0x00C0, 0x04C0, 0x0180, 0x0480, 0x0200, 0x0400, 0x0280, 0x0340, 0x0300, 0x0280, 0x0340, 0x01C0, 0x0380,
    0x0100, 0x03C0, 0x0040, 0x0380, 0xFF80, 0x0340, 0xFEC0, 0x0300, 0xFE00, 0x0280, 0xFD80, 0x0200, 0xFD40, 0x0180, 0xFD00, 0x00C0,
    0xFCC0, 0x0000, 0xFD00, 0xFF40, 0xFD40, 0xFE80, 0xFD80, 0xFE00, 0xFE00, 0xFD80, 0xFEC0, 0xFD00, 0xFF80, 0xFCC0, 0x0040, 0xFC80,
    0x0100, 0xFC40, 0x01C0, 0xFC80, 0x0280, 0xFCC0, 0x0340, 0xFD00, 0x0400, 0xFD80, 0x0480, 0xFE00, 0x04C0, 0xFE80, 0x0500, 0xFF40,
    0x0400, 0xFEC0, 0x0400, 0x0140, 0x0400, 0xFF80, 0x0380, 0x01C0, 0x0400, 0x0040, 0x0300, 0x0280, 0x03C0, 0x0100, 0x0240, 0x0300,
    0x0380, 0x0180, 0x0180, 0x0380, 0x0300, 0x0240, 0x00C0, 0x03C0, 0x0280, 0x02C0, 0x0000, 0x03C0, 0x01C0, 0x0340, 0xFF00, 0x03C0,
    0x00C0, 0x0380, 0xFE00, 0x0380, 0x0000, 0x03C0, 0xFD40, 0x0340, 0xFF40, 0x03C0, 0xFC80, 0x02C0, 0xFE40, 0x03C0, 0xFC00, 0x0240,
    0xFDC0, 0x0380, 0xFBC0, 0x0180, 0xFD00, 0x0300, 0xFB80, 0x0100, 0xFC80, 0x0280, 0xFB80, 0x0040, 0xFC40, 0x01C0, 0xFB80, 0xFF80,
    0xFBC0, 0x0140, 0xFBC0, 0xFEC0, 0xFB80, 0x0080, 0xFC40, 0xFE40, 0xFB80, 0xFFC0, 0xFC80, 0xFD80, 0xFB80, 0xFF00, 0xFD00, 0xFD00,
    0xFBC0, 0xFE80, 0xFDC0, 0xFC80, 0xFC00, 0xFDC0, 0xFE40, 0xFC40, 0xFC80, 0xFD40, 0xFF40, 0xFC40, 0xFD40, 0xFCC0, 0x0000, 0xFC40,
    0xFE00, 0xFC80, 0x00C0, 0xFC80, 0xFF00, 0xFC40, 0x01C0, 0xFCC0, 0x0000, 0xFC40, 0x0280, 0xFD40, 0x00C0, 0xFC40, 0x0300, 0xFDC0,
    0x0180, 0xFC80, 0x0380, 0xFE80, 0x0240, 0xFD00, 0x03C0, 0xFF00, 0x0300, 0xFD80, 0x0400, 0xFFC0, 0x0380, 0xFE40, 0x0400, 0x0080,
    0x0400, 0x0000, 0x0400, 0x0080, 0x03C0, 0x0100, 0x0380, 0x0180, 0x0300, 0x0200, 0x0280, 0x0280, 0x0200, 0x02C0, 0x0140, 0x0300,
    0x0080, 0x0300, 0xFFC0, 0x0300, 0xFF00, 0x02C0, 0xFE80, 0x0280, 0xFE00, 0x0200, 0xFD80, 0x0180, 0xFD40, 0x0100, 0xFD00, 0x0080,
    0xFD00, 0x0000, 0xFD00, 0xFF80, 0xFD40, 0xFF00, 0xFD80, 0xFE80, 0xFE00, 0xFE00, 0xFE80, 0xFD80, 0xFF00, 0xFD40, 0xFFC0, 0xFD00,
    0x0080, 0xFD00, 0x0140, 0xFD00, 0x0200, 0xFD40, 0x0280, 0xFD80, 0x0300, 0xFE00, 0x0380, 0xFE80, 0x03C0, 0xFF00, 0x0400, 0xFF80,
    0x0500, 0x0000, 0x04C0, 0x00C0, 0x0480, 0x0180, 0x0440, 0x0200, 0x03C0, 0x0280, 0x0300, 0x0300, 0x0200, 0x0340, 0x0140, 0x0380,
    0x0040, 0x03C0, 0xFF40, 0x0380, 0xFE80, 0x0340, 0xFD80, 0x0300, 0xFCC0, 0x0280, 0xFC40, 0x0200, 0xFC00, 0x0180, 0xFBC0, 0x00C0,
    0xFB80, 0x0000, 0xFBC0, 0xFF40, 0xFC00, 0xFE80, 0xFC40, 0xFE00, 0xFCC0, 0xFD80, 0xFD80, 0xFD00, 0xFE80, 0xFCC0, 0xFF40, 0xFC80,
    0x0040, 0xFC40, 0x0140, 0xFC80, 0x0200, 0xFCC0, 0x0300, 0xFD00, 0x03C0, 0xFD80, 0x0440, 0xFE00, 0x0480, 0xFE80, 0x04C0, 0xFF40,
    0x0840, 0xFE80, 0x0840, 0x01C0, 0x0840, 0xFF40, 0x0780, 0x0300, 0x07C0, 0x0140, 0x06C0, 0x0400, 0x0740, 0x0280, 0x0580, 0x0540,
    0x06C0, 0x0380, 0x0440, 0x0600, 0x0600, 0x0480, 0x0300, 0x0680, 0x0540, 0x0540, 0x0140, 0x06C0, 0x0380, 0x0600, 0xFFC0, 0x06C0,
    0x0200, 0x0640, 0xFE00, 0x0640, 0x0040, 0x06C0, 0xFC00, 0x0600, 0xFE80, 0x06C0, 0xFAC0, 0x0540, 0xFD40, 0x0680, 0xFA00, 0x0480,
    0xFC00, 0x0600, 0xF980, 0x0380, 0xFB00, 0x0540, 0xF900, 0x0280, 0xFA40, 0x0400, 0xF8C0, 0x0140, 0xF940, 0x0300, 0xF880, 0xFF40,
    0xF880, 0x01C0, 0xF880, 0xFE80, 0xF940, 0xFD00, 0xF880, 0x00C0, 0xFA40, 0xFC00, 0xF8C0, 0xFEC0, 0xFB00, 0xFAC0, 0xF900, 0xFD80,
    0xFC00, 0xFA00, 0xF980, 0xFC80, 0xFD40, 0xF980, 0xFA00, 0xFB80, 0xFE80, 0xF940, 0xFAC0, 0xFAC0, 0x0040, 0xF940, 0xFC00, 0xFA00,
    0x0200, 0xF9C0, 0xFE00, 0xF9C0, 0x0380, 0xFA00, 0xFFC0, 0xF940, 0x0540, 0xFAC0, 0x0140, 0xF940, 0x0600, 0xFB80, 0x0300, 0xF980,
    0x06C0, 0xFC80, 0x0440, 0xFA00, 0x0740, 0xFD80, 0x0580, 0xFAC0, 0x07C0, 0xFEC0, 0x06C0, 0xFC00, 0x0840, 0x00C0, 0x0780, 0xFD00,
    0x0600, 0x0000, 0x0600, 0x0100, 0x05C0, 0x01C0, 0x0500, 0x0280, 0x0480, 0x0380, 0x03C0, 0x0440, 0x02C0, 0x04C0, 0x0180, 0x0500,
    0x0040, 0x0540, 0xFF00, 0x0500, 0xFDC0, 0x04C0, 0xFCC0, 0x0440, 0xFC00, 0x0380, 0xFB80, 0x0280, 0xFAC0, 0x01C0, 0xFA80, 0x0100,
    0xFA80, 0x0000, 0xFA80, 0xFF00, 0xFAC0, 0xFE40, 0xFB80, 0xFD80, 0xFC00, 0xFC80, 0xFCC0, 0xFBC0, 0xFDC0, 0xFB40, 0xFF00, 0xFB00,
    0x0040, 0xFAC0, 0x0180, 0xFB00, 0x02C0, 0xFB40, 0x03C0, 0xFBC0, 0x0480, 0xFC80, 0x0500, 0xFD80, 0x05C0, 0xFE40, 0x0600, 0xFF00,
    0x0166, 0x0000, 0x0162, 0x0016, 0x015C, 0x002C, 0x0154, 0x0044, 0x014A, 0x0058, 0x0138, 0x0070, 0x0128, 0x0084, 0x0112, 0x0096,
    0x00FA, 0x00A8, 0x00E2, 0x00B6, 0x00C6, 0x00C4, 0x00A6, 0x00D0, 0x0086, 0x00DC, 0x0066, 0x00E2, 0x0042, 0x00E8, 0x0020, 0x00EC,
    0x0000, 0x00EE, 0xFFE0, 0x00EC, 0xFFBE, 0x00E8, 0xFF9A, 0x00E2, 0xFF7A, 0x00DC, 0xFF5A, 0x00D0, 0xFF3A, 0x00C4, 0xFF1E, 0x00B6,
    0xFF06, 0x00A8, 0xFEEE, 0x0096, 0xFED8, 0x0084, 0xFEC8, 0x0070, 0xFEB6, 0x0058, 0xFEAC, 0x0044, 0xFEA4, 0x002C, 0xFE9E, 0x0016,
    0xFE9A, 0x0000, 0xFE9E, 0xFFEA, 0xFEA4, 0xFFD4, 0xFEAC, 0xFFBC, 0xFEB6, 0xFFA8, 0xFEC8, 0xFF90, 0xFED8, 0xFF7C, 0xFEEE, 0xFF6A,
    0xFF06, 0xFF58, 0xFF1E, 0xFF4A, 0xFF3A, 0xFF3C, 0xFF5A, 0xFF30, 0xFF7A, 0xFF24, 0xFF9A, 0xFF1E, 0xFFBE, 0xFF18, 0xFFE0, 0xFF14,
    0x0000, 0xFF12, 0x0020, 0xFF14, 0x0042, 0xFF18, 0x0066, 0xFF1E, 0x0086, 0xFF24, 0x00A6, 0xFF30, 0x00C6, 0xFF3C, 0x00E2, 0xFF4A,
    0x00FA, 0xFF58, 0x0112, 0xFF6A, 0x0128, 0xFF7C, 0x0138, 0xFF90, 0x014A, 0xFFA8, 0x0154, 0xFFBC, 0x015C, 0xFFD4, 0x0162, 0xFFEA,
    0x02CC, 0x0000, 0x02C4, 0x002C, 0x02B8, 0x0058, 0x02A8, 0x0088, 0x0294, 0x00B0, 0x0270, 0x00E0, 0x0250, 0x0108, 0x0224, 0x012C,
    0x01F4, 0x0150, 0x01C4, 0x016C, 0x018C, 0x0188, 0x014C, 0x01A0, 0x010C, 0x01B8, 0x00CC, 0x01C4, 0x0084, 0x01D0, 0x0040, 0x01D8,
    0x0000, 0x01DC, 0xFFC0, 0x01D8, 0xFF7C, 0x01D0, 0xFF34, 0x01C4, 0xFEF4, 0x01B8, 0xFEB4, 0x01A0, 0xFE74, 0x0188, 0xFE3C, 0x016C,
    0xFE0C, 0x0150, 0xFDDC, 0x012C, 0xFDB0, 0x0108, 0xFD90, 0x00E0, 0xFD6C, 0x00B0, 0xFD58, 0x0088, 0xFD48, 0x0058, 0xFD3C, 0x002C,
    0xFD34, 0x0000, 0xFD3C, 0xFFD4, 0xFD48, 0xFFA8, 0xFD58, 0xFF78, 0xFD6C, 0xFF50, 0xFD90, 0xFF20, 0xFDB0, 0xFEF8, 0xFDDC, 0xFED4,
    0xFE0C, 0xFEB0, 0xFE3C, 0xFE94, 0xFE74, 0xFE78, 0xFEB4, 0xFE60, 0xFEF4, 0xFE48, 0xFF34, 0xFE3C, 0xFF7C, 0xFE30, 0xFFC0, 0xFE28,
    0x0000, 0xFE24, 0x0040, 0xFE28, 0x0084, 0xFE30, 0x00CC, 0xFE3C, 0x010C, 0xFE48, 0x014C, 0xFE60, 0x018C, 0xFE78, 0x01C4, 0xFE94,
    0x01F4, 0xFEB0, 0x0224, 0xFED4, 0x0250, 0xFEF8, 0x0270, 0xFF20, 0x0294, 0xFF50, 0x02A8, 0xFF78, 0x02B8, 0xFFA8, 0x02C4, 0xFFD4,
    0x0432, 0x0000, 0x0426, 0x0042, 0x0414, 0x0084, 0x03FC, 0x00CC, 0x03DE, 0x0108, 0x03A8, 0x0150, 0x0378, 0x018C, 0x0336, 0x01C2,
    0x02EE, 0x01F8, 0x02A6, 0x0222, 0x0252, 0x024C, 0x01F2, 0x0270, 0x0192, 0x0294, 0x0132, 0x02A6, 0x00C6, 0x02B8, 0x0060, 0x02C4,
    0x0000, 0x02CA, 0xFFA0, 0x02C4, 0xFF3A, 0x02B8, 0xFECE, 0x02A6, 0xFE6E, 0x0294, 0xFE0E, 0x0270, 0xFDAE, 0x024C, 0xFD5A, 0x0222,
    0xFD12, 0x01F8, 0xFCCA, 0x01C2, 0xFC88, 0x018C, 0xFC58, 0x0150, 0xFC22, 0x0108, 0xFC04, 0x00CC, 0xFBEC, 0x0084, 0xFBDA, 0x0042,
    0xFBCE, 0x0000, 0xFBDA, 0xFFBE, 0xFBEC, 0xFF7C, 0xFC04, 0xFF34, 0xFC22, 0xFEF8, 0xFC58, 0xFEB0, 0xFC88, 0xFE74, 0xFCCA, 0xFE3E,
    0xFD12, 0xFE08, 0xFD5A, 0xFDDE, 0xFDAE, 0xFDB4, 0xFE0E, 0xFD90, 0xFE6E, 0xFD6C, 0xFECE, 0xFD5A, 0xFF3A, 0xFD48, 0xFFA0, 0xFD3C,
    0x0000, 0xFD36, 0x0060, 0xFD3C, 0x00C6, 0xFD48, 0x0132, 0xFD5A, 0x0192, 0xFD6C, 0x01F2, 0xFD90, 0x0252, 0xFDB4, 0x02A6, 0xFDDE,
    0x02EE, 0xFE08, 0x0336, 0xFE3E, 0x0378, 0xFE74, 0x03A8, 0xFEB0, 0x03DE, 0xFEF8, 0x03FC, 0xFF34, 0x0414, 0xFF7C, 0x0426, 0xFFBE,
};

/* The same two tables for the kinds from 0x80 up. */
EnemyRoutines g_enemy_routines_high[128] = {
    /* 0x80 */ { mid_flyer_a_start, mid_flyer_a },
    /* 0x81 */ { mid_flyer_b_start, mid_flyer_b },
    /* 0x82 */ { mid_flyer_c_start, mid_flyer_c },
    /* 0x83 */ { mid_flyer_d_start, mid_flyer_d },
    /* 0x84 */ { mid_tank_vertical_start, mid_tank_vertical },
    /* 0x85 */ { item_carrier_start, item_carrier },
    /* 0x86 */ { bomb_carrier_start, item_carrier },
    /* 0x87 */ { shooter_drone_start, shooter_drone },
    /* 0x88 */ { mid_tank_horizontal_start, mid_tank_horizontal },
    /* 0x89 */ { ground_turret_b_start, ground_turret_b },
    /* 0x8A */ { bee_container_start, bee_container },
    /* 0x8B */ { star_container_start, star_container },
    /* 0x8C */ { func_001CBD60, func_001CC0A0 },
    /* 0x8D */ { water_flower_turret_start, water_flower_turret },
    /* 0x8E */ { ground_turret_a_start, ground_turret_a },
    /* 0x8F */ { ground_turret_c_start, ground_turret_c },
    /* 0x90 */ { stage2_blooming_base_start, stage2_blooming_base },
    /* 0x91 */ { stage2_long_warehouse_start, stage2_long_warehouse },
    /* 0x92 */ { stage2_square_warehouse_start, stage2_square_warehouse },
    /* 0x93 */ { stage2_gymnasium_start, stage2_gymnasium },
    /* 0x94 */ { stage2_sliding_gun_start, stage2_sliding_gun },
    /* 0x95 */ { mid_flyer_e_start, mid_flyer_e },
    /* 0x96 */ { stage2_wrecker_gun_start, stage2_wrecker_gun },
    /* 0x97 */ { mid_tank_horizontal_b_start, mid_tank_horizontal_b },
    /* 0x98 */ { stage2_boss_hangar_start, stage2_boss_hangar },
    /* 0x99 */ { stage3_boss_timber_start, stage3_boss_timber },
    /* 0x9A */ { stage3_boss_lid_bullet_start, stage3_boss_lid_bullet },
    /* 0x9B */ { stage4_gate_start, stage4_gate },
    /* 0x9C */ { stage4_lift_start, stage4_lift },
    /* 0x9D */ { stage4_heavy_cannon_start, stage4_heavy_cannon },
    /* 0x9E */ { stage4_heavy_cannon_casing_start, stage4_heavy_cannon_casing },
    /* 0x9F */ { stage4_wave_cannon_start, stage4_wave_cannon },
    /* 0xA0 */ { stage3_boss_start, stage3_boss_main },
    /* 0xA1 */ { stage4_reactor_start, stage4_reactor },
    /* 0xA2 */ { crane_turret_start, crane_turret },
    /* 0xA3 */ { rail_turret_start, rail_turret },
    /* 0xA4 */ { stage4_tachyon_particle_start, stage4_tachyon_particle },
    /* 0xA5 */ { func_00168120, func_001683C0 },
    /* 0xA6 */ { formation_fire_timer_setup, formation_fire_timer_main },
    /* 0xA7 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xA8 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xA9 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xAA */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xAB */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xAC */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xAD */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xAE */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xAF */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xB0 */ { stage5_boss_start, stage5_boss_main },
    /* 0xB1 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xB2 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xB3 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xB4 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xB5 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xB6 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xB7 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xB8 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xB9 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xBA */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xBB */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xBC */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xBD */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xBE */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xBF */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xC0 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xC1 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xC2 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xC3 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xC4 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xC5 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xC6 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xC7 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xC8 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xC9 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xCA */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xCB */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xCC */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xCD */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xCE */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xCF */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xD0 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xD1 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xD2 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xD3 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xD4 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xD5 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xD6 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xD7 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xD8 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xD9 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xDA */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xDB */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xDC */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xDD */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xDE */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xDF */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xE0 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xE1 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xE2 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xE3 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xE4 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xE5 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xE6 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xE7 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xE8 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xE9 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xEA */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xEB */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xEC */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xED */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xEE */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xEF */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xF0 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xF1 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xF2 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xF3 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xF4 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xF5 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xF6 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xF7 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xF8 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xF9 */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xFA */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xFB */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xFC */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xFD */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xFE */ { enemy_remove_entry_entry, enemy_remove_entry },
    /* 0xFF */ { enemy_remove_entry_entry, enemy_remove_entry },
};

void (*g_enemy_first_routines_high[128])() = {
    /* 0x80 */ mid_flyer_a_first,
    /* 0x81 */ mid_flyer_b_first,
    /* 0x82 */ mid_flyer_c_first,
    /* 0x83 */ mid_flyer_d_first,
    /* 0x84 */ mid_tank_vertical_first,
    /* 0x85 */ item_carrier_first,
    /* 0x86 */ bomb_carrier_first,
    /* 0x87 */ shooter_drone_first,
    /* 0x88 */ mid_tank_horizontal_first,
    /* 0x89 */ ground_turret_b_first,
    /* 0x8A */ bee_container_first,
    /* 0x8B */ star_container_first,
    /* 0x8C */ func_001CBD50,
    /* 0x8D */ water_flower_turret_first,
    /* 0x8E */ ground_turret_a_first,
    /* 0x8F */ ground_turret_c_first,
    /* 0x90 */ stage2_blooming_base_first,
    /* 0x91 */ stage2_long_warehouse_first,
    /* 0x92 */ stage2_square_warehouse_first,
    /* 0x93 */ stage2_gymnasium_first,
    /* 0x94 */ stage2_sliding_gun_first,
    /* 0x95 */ mid_flyer_e_first,
    /* 0x96 */ stage2_wrecker_gun_first,
    /* 0x97 */ mid_tank_horizontal_b_first,
    /* 0x98 */ stage2_boss_hangar_first,
    /* 0x99 */ stage3_boss_timber_first,
    /* 0x9A */ stage3_boss_lid_bullet_first,
    /* 0x9B */ stage4_gate_first,
    /* 0x9C */ stage4_lift_first,
    /* 0x9D */ stage4_heavy_cannon_first,
    /* 0x9E */ stage4_heavy_cannon_casing_first,
    /* 0x9F */ stage4_wave_cannon_first,
    /* 0xA0 */ stage3_boss_first,
    /* 0xA1 */ stage4_reactor_first,
    /* 0xA2 */ crane_turret_first,
    /* 0xA3 */ rail_turret_first,
    /* 0xA4 */ stage4_tachyon_particle_first,
    /* 0xA5 */ func_00168110,
    /* 0xA6 */ formation_fire_timer_first,
    /* 0xA7 */ func_0015C440,
    /* 0xA8 */ func_0015C440,
    /* 0xA9 */ func_0015C440,
    /* 0xAA */ func_0015C440,
    /* 0xAB */ func_0015C440,
    /* 0xAC */ func_0015C440,
    /* 0xAD */ func_0015C440,
    /* 0xAE */ func_0015C440,
    /* 0xAF */ func_0015C440,
    /* 0xB0 */ stage5_boss_first,
    /* 0xB1 */ func_0015C440,
    /* 0xB2 */ func_0015C440,
    /* 0xB3 */ func_0015C440,
    /* 0xB4 */ func_0015C440,
    /* 0xB5 */ func_0015C440,
    /* 0xB6 */ func_0015C440,
    /* 0xB7 */ func_0015C440,
    /* 0xB8 */ func_0015C440,
    /* 0xB9 */ func_0015C440,
    /* 0xBA */ func_0015C440,
    /* 0xBB */ func_0015C440,
    /* 0xBC */ func_0015C440,
    /* 0xBD */ func_0015C440,
    /* 0xBE */ func_0015C440,
    /* 0xBF */ func_0015C440,
    /* 0xC0 */ func_0015C440,
    /* 0xC1 */ func_0015C440,
    /* 0xC2 */ func_0015C440,
    /* 0xC3 */ func_0015C440,
    /* 0xC4 */ func_0015C440,
    /* 0xC5 */ func_0015C440,
    /* 0xC6 */ func_0015C440,
    /* 0xC7 */ func_0015C440,
    /* 0xC8 */ func_0015C440,
    /* 0xC9 */ func_0015C440,
    /* 0xCA */ func_0015C440,
    /* 0xCB */ func_0015C440,
    /* 0xCC */ func_0015C440,
    /* 0xCD */ func_0015C440,
    /* 0xCE */ func_0015C440,
    /* 0xCF */ func_0015C440,
    /* 0xD0 */ func_0015C440,
    /* 0xD1 */ func_0015C440,
    /* 0xD2 */ func_0015C440,
    /* 0xD3 */ func_0015C440,
    /* 0xD4 */ func_0015C440,
    /* 0xD5 */ func_0015C440,
    /* 0xD6 */ func_0015C440,
    /* 0xD7 */ func_0015C440,
    /* 0xD8 */ func_0015C440,
    /* 0xD9 */ func_0015C440,
    /* 0xDA */ func_0015C440,
    /* 0xDB */ func_0015C440,
    /* 0xDC */ func_0015C440,
    /* 0xDD */ func_0015C440,
    /* 0xDE */ func_0015C440,
    /* 0xDF */ func_0015C440,
    /* 0xE0 */ func_0015C440,
    /* 0xE1 */ func_0015C440,
    /* 0xE2 */ func_0015C440,
    /* 0xE3 */ func_0015C440,
    /* 0xE4 */ func_0015C440,
    /* 0xE5 */ func_0015C440,
    /* 0xE6 */ func_0015C440,
    /* 0xE7 */ func_0015C440,
    /* 0xE8 */ func_0015C440,
    /* 0xE9 */ func_0015C440,
    /* 0xEA */ func_0015C440,
    /* 0xEB */ func_0015C440,
    /* 0xEC */ func_0015C440,
    /* 0xED */ func_0015C440,
    /* 0xEE */ func_0015C440,
    /* 0xEF */ func_0015C440,
    /* 0xF0 */ func_0015C440,
    /* 0xF1 */ func_0015C440,
    /* 0xF2 */ func_0015C440,
    /* 0xF3 */ func_0015C440,
    /* 0xF4 */ func_0015C440,
    /* 0xF5 */ func_0015C440,
    /* 0xF6 */ func_0015C440,
    /* 0xF7 */ func_0015C440,
    /* 0xF8 */ func_0015C440,
    /* 0xF9 */ func_0015C440,
    /* 0xFA */ func_0015C440,
    /* 0xFB */ func_0015C440,
    /* 0xFC */ func_0015C440,
    /* 0xFD */ func_0015C440,
    /* 0xFE */ func_0015C440,
    /* 0xFF */ func_0015C440,
};
