#include "common.h"
#ifdef DDPDOJ_PC
#include "pc_gameplay_abi.h"
#endif
#ifdef DDPDOJ_PC
#include "pc_replay_storage.h"
#endif
#include "entity.h"
#include "player.h"

void player_spawn(void);
void player_spawn_power_setup(void);
void player_spawn_timers_set(void);
void player_displays_reset(void);
void player_sprite_update(void);
void player_update(void);
void player_destroyed_begin(void);
void player_destroyed_update(void);
void player_shot_fire_gun_a(void);
void player_shot_fire_gun_b(void);
void player_shot_fire_volley_a_entry(void);
void player_shot_fire_volley_a(void);
void player_shot_fire_volley_b_entry(void);
void player_shot_fire_volley_b(void);
void player_roll_recenter(void);
void player_draw(void);
void player_draw_plain(void);
#ifndef DDPDOJ_PC
void player_draw_entering();
#endif


void player_option_delay_clear(void) {
    *(u16 *)(reg_a4 + 0x60) = 0;
}

s32 sfx_extend();
s32 hud_p1_lives_put();
extern u16 g_p1_stage_bomb_used;
extern u16 g_p1_stage_misses;
extern u8 g_game_mode;
extern s8 D_0028E3F8;
extern u16 g_p1_lives;
extern u16 g_loop;
extern u16 g_stage;

#ifdef DEATH_LABEL
extern u8 death_D_00290850;
extern u8 death_D_00290DC0;
#endif

void p1_stage_clear_reward(void) {
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u32 temp_a0;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    if ((g_game_mode == 2) || ((g_loop != 0) && ((g_p1_stage_misses == 0) || (g_p1_stage_bomb_used == 0)))) {
#ifdef DEATH_LABEL
        if (death_D_00290DC0 == 0)
#endif
        {
        temp_a0 = g_p1_lives;
        if (temp_a0 != 0x14) {
            g_p1_lives = temp_a0 + 1;
            hud_p1_lives_put();
#ifdef DEATH_LABEL
            if (death_D_00290850 == 0) {
                if (g_stage == 4) {
                    death_D_00290850 = 1;
                }
                sfx_extend();
            }
#else
            if ((D_0028E3F8 == 0) && ((s32) g_stage < 4)) {
                sfx_extend();
            }
#endif
        }
        }
    }
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}

s32 hud_p2_lives_put();
extern u16 g_p2_stage_bomb_used;
extern u16 g_p2_stage_misses;
extern u16 g_p2_lives;

#ifdef DEATH_LABEL
extern u8 death_D_00290850;
extern u8 death_D_00290DC0;
#endif

void p2_stage_clear_reward(void) {
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u32 temp_a0;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    if ((g_game_mode == 2) || ((g_loop != 0) && ((g_p2_stage_misses == 0) || (g_p2_stage_bomb_used == 0)))) {
#ifdef DEATH_LABEL
        if (death_D_00290DC0 == 0)
#endif
        {
        temp_a0 = g_p2_lives;
        if (temp_a0 != 0x14) {
            g_p2_lives = temp_a0 + 1;
            hud_p2_lives_put();
#ifdef DEATH_LABEL
            if (death_D_00290850 == 0) {
                if (g_stage == 4) {
                    death_D_00290850 = 1;
                }
                sfx_extend();
            }
#else
            if ((D_0028E3F8 == 0) && ((s32) g_stage < 4)) {
                sfx_extend();
            }
#endif
        }
        }
    }
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}

extern u16 g_p1_hyper_items_pending;
extern u16 g_p1_hyper_items;
extern u16 g_p1_hyper_in_effect;
extern u16 g_p1_hyper_level;
extern u16 g_p1_hyper_combo_decay;
extern u16 g_p1_hyper_gauge;
extern u16 g_p1_hyper_time;
extern u16 g_p1_hyper_active;
extern s32 g_p1_position_trail[];

void p1_hyper_state_clear(void) {
    reg_d0.w = 0;
    g_p1_position_trail[0] = 0;
    g_p1_hyper_active = reg_d0.h[0];
    g_p1_hyper_gauge = reg_d0.h[0];
    g_p1_hyper_time = reg_d0.h[0];
    g_p1_hyper_combo_decay = reg_d0.h[0];
    g_p1_hyper_level = reg_d0.h[0];
    g_p1_hyper_in_effect = reg_d0.h[0];
    g_p1_hyper_items = reg_d0.h[0];
    g_p1_hyper_items_pending = reg_d0.h[0];
}

extern u16 g_p2_hyper_items_pending;
extern u16 g_p2_hyper_items;
extern u16 g_p2_hyper_in_effect;
extern u16 g_p2_hyper_level;
extern u16 g_p2_hyper_combo_decay;
extern u16 g_p2_hyper_gauge;
extern u16 g_p2_hyper_time;
extern u16 g_p2_hyper_active;
extern s32 g_p2_position_trail[];

void p2_hyper_state_clear(void) {
    reg_d0.w = 0;
    g_p2_position_trail[0] = 0;
    g_p2_hyper_active = reg_d0.h[0];
    g_p2_hyper_gauge = reg_d0.h[0];
    g_p2_hyper_time = reg_d0.h[0];
    g_p2_hyper_combo_decay = reg_d0.h[0];
    g_p2_hyper_level = reg_d0.h[0];
    g_p2_hyper_in_effect = reg_d0.h[0];
    g_p2_hyper_items = reg_d0.h[0];
    g_p2_hyper_items_pending = reg_d0.h[0];
}

extern u16 g_p1_hyper_total;

void p1_hyper_state_clear_for_ending(void) {
    reg_d0.w = 0;
    g_p1_position_trail[0] = 0;
    g_p1_hyper_active = reg_d0.h[0];
    g_p1_hyper_total = reg_d0.h[0];
    g_p1_hyper_gauge = reg_d0.h[0];
    g_p1_hyper_combo_decay = reg_d0.h[0];
    g_p1_hyper_level = reg_d0.h[0];
    g_p1_hyper_in_effect = reg_d0.h[0];
    g_p1_hyper_items_pending = reg_d0.h[0];
}

extern u16 g_p2_hyper_total;

void p2_hyper_state_clear_for_ending(void) {
    reg_d0.w = 0;
    g_p2_position_trail[0] = 0;
    g_p2_hyper_active = reg_d0.h[0];
    g_p2_hyper_total = reg_d0.h[0];
    g_p2_hyper_gauge = reg_d0.h[0];
    g_p2_hyper_combo_decay = reg_d0.h[0];
    g_p2_hyper_level = reg_d0.h[0];
    g_p2_hyper_in_effect = reg_d0.h[0];
    g_p2_hyper_items_pending = reg_d0.h[0];
}

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
extern u16 g_p2_bombs_used;
extern u16 g_p1_bombs_used;
extern u16 g_p2_death_count;
extern u16 g_p1_death_count;
extern u16 g_p2_continued;
extern u16 g_p1_continued;
extern u16 g_p2_past_first_ship;
extern u16 g_p1_past_first_ship;
extern u16 g_p2_missed;
extern u16 g_p1_missed;
extern s16 g_p2_choosing_power_style;
extern s16 g_p1_choosing_power_style;
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
extern u8 g_p2_weapon_level_data[];
extern s32 g_p2_option_level_data_as_s32_a[];
extern u8 g_p1_weapon_level_data[];
extern s32 g_p1_option_level_data_as_s32_a[];
extern u16 g_laser_bomb_impact_frame;
extern u16 g_p2_maximum_value[16];
extern s32 g_p2_maximum_value_digits[];
extern u32 g_p2_maximum_half_digits[];
extern s16 g_p2_maximum_count_as_s16_a[];
extern u16 g_p2_maximum_count_digits[];
extern u16 g_p1_maximum_value[];
extern s32 g_p1_maximum_value_digits[];
extern u32 g_p1_maximum_half_digits[];
extern s16 g_p1_maximum_count_as_s16_a[];
extern u16 g_p1_maximum_count_digits[];
extern u8 g_p2_afterimage_sprites[];
extern s32 g_p1_afterimage_sprites[16];
extern u8 g_p2_afterimage_positions[];
extern s32 g_p1_afterimage_positions[16];
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
extern s16 g_player2[56];
extern s16 g_player1[56];
void players_clear(void) {
    s8 *temp_v1;
    u8 *temp_a1;
    u8 *temp_a1_2;
    s8 *var_a1;
    u8 *temp_a2;
    u8 *temp_a2_3;
    u8 *temp_a2_4;
    u8 *temp_a2_5;
    s32 var_a2;
    s32 var_a2_2;
    u8 *temp_a3_2;
    u8 *temp_a3_3;
    u8 *temp_a3_4;
    s32 var_a3;
    u8 *temp_t0;
    s32 var_t0_2;
    s32 var_t0_3;
    s32 var_t0_4;
    s32 var_t0_5;
    u8 *temp_t1;
    u8 *temp_t2;
    u8 *temp_t3;
    u8 *temp_t4;
    s32 var_t5;

    var_a3 = 0;
    do {
        temp_a2 = (u8 *)(((u8 *)g_player1) + var_a3);
        temp_t0 = (u8 *)(((u8 *)g_player2) + var_a3);
        (*(s8 *)((u8 *)(temp_a2) + (0))) = 0;
        var_a3 += 8;
        (*(s8 *)((u8 *)(temp_t0) + (0))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_t0) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_t0) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_t0) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_t0) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_t0) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_t0) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (7))) = 0;
        (*(s8 *)((u8 *)(temp_t0) + (7))) = 0;
    } while (var_a3 < 0x5A);
    if (var_a3 < 0x62) {
        var_a1 = (s8 *)(((u8 *)g_player1) + var_a3);
        do {
            temp_v1 = (s8 *)(((u8 *)g_player2) + var_a3);
            var_a1 = (s8 *)(((u8 *)g_player1) + var_a3);
            *var_a1 = 0;
            *temp_v1 = 0;
            var_a3 += 1;
        } while (var_a3 < 0x62);
    }
    for (var_a3 = 0; var_a3 < 0x64; var_a3++) {
        g_p1_options[var_a3] = 0;
        g_p2_options[var_a3] = 0;
    }
    var_a2 = 0;
    do {
        temp_a1 = (u8 *)(D_0029E390 + var_a2);
        (*(s8 *)((u8 *)(temp_a1) + (0))) = 0;
        var_a2 += 8;
        (*(s8 *)((u8 *)(temp_a1) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (7))) = 0;
    } while (var_a2 < 0xD80);
    var_t0_2 = 0;
    do {
        temp_a2_3 = (u8 *)(g_p1_laser_entities + var_t0_2);
        temp_a3_2 = (u8 *)(g_p2_laser_entities + var_t0_2);
        (*(s8 *)((u8 *)(temp_a2_3) + (0))) = 0;
        var_t0_2 += 8;
        (*(s8 *)((u8 *)(temp_a3_2) + (0))) = 0;
        (*(s8 *)((u8 *)(temp_a2_3) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a3_2) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a2_3) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a3_2) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a2_3) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a3_2) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a2_3) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a3_2) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a2_3) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a3_2) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a2_3) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a3_2) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a2_3) + (7))) = 0;
        (*(s8 *)((u8 *)(temp_a3_2) + (7))) = 0;
    } while (var_t0_2 < 0x600);
    var_t0_3 = 0;
    do {
        temp_a2_4 = (u8 *)(D_0029D770 + var_t0_3);
        temp_a3_3 = (u8 *)(D_0029D750 + var_t0_3);
        (*(s8 *)((u8 *)(temp_a2_4) + (0))) = 0;
        var_t0_3 += 8;
        (*(s8 *)((u8 *)(temp_a3_3) + (0))) = 0;
        (*(s8 *)((u8 *)(temp_a2_4) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a3_3) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a2_4) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a3_3) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a2_4) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a3_3) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a2_4) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a3_3) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a2_4) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a3_3) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a2_4) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a3_3) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a2_4) + (7))) = 0;
        (*(s8 *)((u8 *)(temp_a3_3) + (7))) = 0;
    } while (var_t0_3 < 0x20);
    var_t0_4 = 0;
    do {
        temp_a2_5 = (u8 *)(D_0029D730 + var_t0_4);
        temp_a3_4 = (u8 *)(D_0029D710 + var_t0_4);
        (*(s8 *)((u8 *)(temp_a2_5) + (0))) = 0;
        var_t0_4 += 8;
        (*(s8 *)((u8 *)(temp_a3_4) + (0))) = 0;
        (*(s8 *)((u8 *)(temp_a2_5) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a3_4) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a2_5) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a3_4) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a2_5) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a3_4) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a2_5) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a3_4) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a2_5) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a3_4) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a2_5) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a3_4) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a2_5) + (7))) = 0;
        (*(s8 *)((u8 *)(temp_a3_4) + (7))) = 0;
    } while (var_t0_4 < 0x20);
    var_a2_2 = 0;
    do {
        temp_a1_2 = (u8 *)(((u8 *)g_bomb_entities) + var_a2_2);
        (*(s8 *)((u8 *)(temp_a1_2) + (0))) = 0;
        var_a2_2 += 8;
        (*(s8 *)((u8 *)(temp_a1_2) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a1_2) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a1_2) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a1_2) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a1_2) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a1_2) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a1_2) + (7))) = 0;
    } while (var_a2_2 < 0x870);
    g_laser_bomb_impact_frame = 0;
    ((s32 *)g_p1_weapon_level_data)[0] = 0;
    var_t5 = 0;
    var_t0_5 = 0;
    g_p1_option_level_data_as_s32_a[0] = 0;
    ((s32 *)g_p2_weapon_level_data)[0] = 0;
    g_p2_option_level_data_as_s32_a[0] = 0;
    do {
        temp_t1 = (u8 *)(((u8 *)g_p1_afterimage_positions) + var_t0_5);
        temp_t2 = (u8 *)(g_p2_afterimage_positions + var_t0_5);
        temp_t3 = (u8 *)(((u8 *)g_p1_afterimage_sprites) + var_t0_5);
        var_t5 += 8;
        (*(s32 *)((u8 *)(temp_t1) + (0))) = 0;
        (*(s32 *)((u8 *)(temp_t2) + (0))) = 0;
        temp_t4 = (u8 *)(g_p2_afterimage_sprites + var_t0_5);
        (*(s32 *)((u8 *)(temp_t3) + (0))) = 0;
        (*(s32 *)((u8 *)(temp_t4) + (0))) = 0;
        (*(s32 *)((u8 *)(temp_t1) + (4))) = 0;
        var_t0_5 += 0x20;
        (*(s32 *)((u8 *)(temp_t2) + (4))) = 0;
        (*(s32 *)((u8 *)(temp_t3) + (4))) = 0;
        (*(s32 *)((u8 *)(temp_t4) + (4))) = 0;
        (*(s32 *)((u8 *)(temp_t1) + (8))) = 0;
        (*(s32 *)((u8 *)(temp_t2) + (8))) = 0;
        (*(s32 *)((u8 *)(temp_t3) + (8))) = 0;
        (*(s32 *)((u8 *)(temp_t4) + (8))) = 0;
        (*(s32 *)((u8 *)(temp_t1) + (0xC))) = 0;
        (*(s32 *)((u8 *)(temp_t2) + (0xC))) = 0;
        (*(s32 *)((u8 *)(temp_t3) + (0xC))) = 0;
        (*(s32 *)((u8 *)(temp_t4) + (0xC))) = 0;
        (*(s32 *)((u8 *)(temp_t1) + (0x10))) = 0;
        (*(s32 *)((u8 *)(temp_t2) + (0x10))) = 0;
        (*(s32 *)((u8 *)(temp_t3) + (0x10))) = 0;
        (*(s32 *)((u8 *)(temp_t4) + (0x10))) = 0;
        (*(s32 *)((u8 *)(temp_t1) + (0x14))) = 0;
        (*(s32 *)((u8 *)(temp_t2) + (0x14))) = 0;
        (*(s32 *)((u8 *)(temp_t3) + (0x14))) = 0;
        (*(s32 *)((u8 *)(temp_t4) + (0x14))) = 0;
        (*(s32 *)((u8 *)(temp_t1) + (0x18))) = 0;
        (*(s32 *)((u8 *)(temp_t2) + (0x18))) = 0;
        (*(s32 *)((u8 *)(temp_t3) + (0x18))) = 0;
        (*(s32 *)((u8 *)(temp_t4) + (0x18))) = 0;
        (*(s32 *)((u8 *)(temp_t1) + (0x1C))) = 0;
        (*(s32 *)((u8 *)(temp_t2) + (0x1C))) = 0;
        (*(s32 *)((u8 *)(temp_t3) + (0x1C))) = 0;
        (*(s32 *)((u8 *)(temp_t4) + (0x1C))) = 0;
    } while (var_t5 < 0x10);
    g_p1_maximum_level = 0;
    ((s16 *)g_p1_maximum_value)[0] = 0;
    g_p2_maximum_level = 0;
    g_p1_maximum_value_digits[0] = 0;
    g_p1_maximum_anim_delay = 0;
    ((s32 *)g_p1_maximum_half_digits)[0] = 0;
    g_p1_maximum_anim_delay_reset = 0;
    g_p1_maximum_count_as_s16_a[0] = 0;
    g_p2_maximum_anim_delay = 0;
    ((s16 *)g_p1_maximum_count_digits)[0] = 0;
    g_p2_maximum_anim_delay_reset = 0;
    ((s16 *)g_p2_maximum_value)[0] = 0;
    g_p1_hyper_ready_sprite = 0;
    g_p2_maximum_value_digits[0] = 0;
    g_p2_hyper_ready_sprite = 0;
    ((s32 *)g_p2_maximum_half_digits)[0] = 0;
    g_p1_hyper_ready_anim_delay = 0;
    g_p2_maximum_count_as_s16_a[0] = 0;
    g_p2_hyper_ready_anim_delay = 0;
    ((s16 *)g_p2_maximum_count_digits)[0] = 0;
    g_p1_choosing_power_style = 0;
    g_p2_choosing_power_style = 0;
    g_p1_missed = 0;
    g_p2_missed = 0;
    g_p1_past_first_ship = 0;
    g_p2_past_first_ship = 0;
    g_p1_continued = 0;
    g_p2_continued = 0;
    g_p1_death_count = 0;
    g_p2_death_count = 0;
    g_p1_stage_misses = 0;
    g_p2_stage_misses = 0;
    g_p1_bombs_used = 0;
    g_p2_bombs_used = 0;
    g_p1_stage_bomb_used = 0;
    g_p2_stage_bomb_used = 0;
    g_p1_loop2_extend_ok = 0;
    g_p2_loop2_extend_ok = 0;
    g_p1_laser_bomb_active = 0;
    g_p2_laser_bomb_active = 0;
    g_hyper_bullet_speed = 0;
    g_laser_bomb_hit_position = 0;
    g_laser_bomb_hit_entity = 0;
    g_laser_bomb_pushback = 0;
    g_laser_bomb_hit_flag = 0;
    g_player_shot_count = 0;
    g_player_laser_count = 0;
    g_p1_y_delta = 0;
    g_p2_y_delta = 0;
    g_p1_laser_stop_y = 0;
    g_p2_laser_stop_y = 0;
    g_laser_bomb_sizzle = 0;
    g_laser_bomb_sizzle2 = 0;
    g_bomb_afterglow_timer = 0;
    g_player_shots_disabled = 0;
    g_players_hidden = 0;
    g_players_stage_clear = 0;
    g_p1_died_in_hyper = 0;
    g_p2_died_in_hyper = 0;
}


void bcd_add(s32 *arg0, u32 *arg1) {
    s32 carry;
    s32 n;
    s32 digit;
    s32 i;

    carry = 0;
    n = 0;
    reg_tmp.w = *arg1;
    reg_tmp1.w = *arg0;
    reg_d2.w = 0;
    do {
        digit = carry + ((reg_tmp.w & 0xF) + (reg_tmp1.w & 0xF));
        carry = 0;
        if (digit >= 0xA) {
            carry = 1;
            digit -= 0xA;
        }
        n += 1;
        reg_tmp.w = (u32) reg_tmp.w >> 4;
        reg_tmp1.w = (u32) reg_tmp1.w >> 4;
        reg_d2.w *= 0x10;
        reg_d2.w |= digit;
    } while (n < 8);
    *arg0 = 0;
    for (i = 0; i < 8; i++) {
        *arg0 *= 0x10;
        *arg0 = *arg0 | (reg_d2.w & 0xF);
        reg_d2.w = (u32) ((s64) (((u64) reg_d2.w >> 4) << 0x20) >> 0x20);
    }
}

extern u16 g_p1_past_first_ship;
extern u16 g_p1_missed;
extern u16 g_p1_hyper_ready_sprite_lo;
extern u8 g_p1_weapon_level_data[];
extern u16 g_p1_hyper_effect_flag;
extern u16 g_two_player_seen;
extern u16 g_p1_power_style;
extern u16 g_p1_ship_type;
extern u8 g_replay_begin_pending;
extern u8 g_replay_mode;

void player1_task() {
    reg_a6 = ((u8 *)g_player1);
    reg_a2 = g_p1_options;
    g_two_player_seen |= 1;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 2);
    *(u8 *)(reg_a5 + 2) |= 1;
    if (reg_tmp.b[0] & 1) {
        player_update();
        return;
    }
    g_p1_hyper_effect_flag = 0;
    if (g_replay_mode == 1) {
        g_replay_begin_pending = 1;
    }
    reg_a3 = ((u8 *)g_p1_maximum_value);
    reg_a4 = g_p1_weapon_level_data;
    reg_d3.w = 0x25000E00;
    reg_d4.h[0] = g_p1_past_first_ship;
    reg_d6.h[0] = g_p1_missed;
    PLAYER(reg_a6)->ship_type.h = (u16) g_p1_ship_type;
    PLAYER(reg_a6)->power_style.h = (u16) g_p1_power_style;
    if (*(u8 *)(reg_a5 + 7) != 0) {
        player_spawn();
        return;
    }
    g_p1_maximum_anim_delay = 2;
    g_p1_maximum_anim_delay_reset = 2;
    reg_tmp.w = 0xC30;
    g_p1_hyper_ready_anim_delay = 0x101;
    g_p1_maximum_level = 0;
    (*(u16 *)&g_p1_hyper_ready_sprite) = reg_tmp.h[1];
    g_p1_hyper_ready_sprite_lo = reg_tmp.h[0];
    player_spawn();
}

extern u16 g_p2_past_first_ship;
extern u16 g_p2_missed;
extern u16 g_p2_hyper_ready_sprite_lo;
extern u8 g_p2_weapon_level_data[];
extern u16 g_p2_hyper_effect_flag;
extern u16 g_p2_power_style;
extern u16 g_p2_ship_type;

void player2_task() {
    reg_a6 = ((u8 *)g_player2);
    reg_a2 = g_p2_options;
    g_two_player_seen |= 2;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 2);
    *(u8 *)(reg_a5 + 2) |= 1;
    if (reg_tmp.b[0] & 1) {
        player_update();
        return;
    }
    g_p2_hyper_effect_flag = 0;
    if (g_replay_mode == 1) {
        g_replay_begin_pending = 1;
    }
    reg_a3 = ((u8 *)g_p2_maximum_value);
    reg_a4 = g_p2_weapon_level_data;
    reg_d3.w = 0x25002E00;
    reg_d4.h[0] = g_p2_past_first_ship;
    reg_d6.h[0] = g_p2_missed;
    PLAYER(reg_a6)->ship_type.h = (u16) g_p2_ship_type;
    PLAYER(reg_a6)->power_style.h = (u16) g_p2_power_style;
    if (*(u8 *)(reg_a5 + 7) != 0) {
        player_spawn();
        return;
    }
    g_p2_maximum_anim_delay = 2;
    g_p2_maximum_anim_delay_reset = 2;
    reg_tmp.w = 0xC30;
    g_p2_hyper_ready_anim_delay = 0x101;
    g_p2_maximum_level = 0;
    (*(u16 *)&g_p2_hyper_ready_sprite) = reg_tmp.h[1];
    g_p2_hyper_ready_sprite_lo = reg_tmp.h[0];
    player_spawn();
}

s32 player_slot_request_bomb_display();
s32 p1_hyper_item_take();
s32 p2_hyper_item_take();
s32 weapon_level_data_set(u8 *);
s32 p1_hyper_items_pending_take();
s32 p2_hyper_items_pending_take();
extern u16 player_spawn_table[];
extern u16 player_spawn_table_2[];
extern u16 player_weapon_tables[24];
extern u16 player_spawn_table_3[];
extern u16 player_spawn_table_4[];
extern u16 player_spawn_table_5[];
extern u16 player_spawn_table_6[];
extern u8 D_0028C608[];
extern u16 g_p2_died_in_hyper;
extern u16 g_p1_died_in_hyper;
extern u16 g_players_stage_clear;
extern u16 g_players_hidden;
extern u16 g_player_shots_disabled;
extern u16 g_p2_death_count;
extern u16 g_p1_death_count;
extern u8 D_0028E280;
extern u8 D_0028E284;
extern u8 D_0028E288;
extern u8 D_0028E2A8;
extern u16 D_0028E2AC;
extern u8 D_0028E2B0;
extern u8 D_0028E2C4;
extern u8 g_simulation_active;
extern u16 D_006E5BF0[];
extern u16 D_006E5BF2[];
extern u16 D_006E5BFC[];
extern u16 D_006E5C12[];
extern u16 D_006E5C14[];

#ifdef DEATH_LABEL
extern u16 g_attract_demo;
extern u16 D_0028E810;
#endif

void player_spawn(void) {
    s32 i;
    s32 val;
    s32 rem;
    s32 n;

    *(u16 *)reg_a2 = 0x8000;
    reg_a0 = (u8 *)player_spawn_table_4;
    g_players_hidden = 0;
    g_player_shots_disabled = 0;
    g_players_stage_clear = 0;
    reg_a1 = reg_a6;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[0] |= PLAYER(reg_a6)->flags.h;
    *(u16 *)reg_a1 = reg_d0.h[0];
    reg_a1 += 2;
    reg_d0.h[1] = PLAYER(reg_a6)->ship_type.h;
    reg_d0.h[0] = PLAYER(reg_a6)->power_style.h;
    reg_d1.h[1] = PLAYER(reg_a6)->shot_power.h;
    reg_d1.h[0] = PLAYER(reg_a6)->laser_power.h;
    reg_d2.b[0] = reg_a6[0x24];
    if (reg_a5[7] != 0) goto skip_1;
    reg_d5.w = 0x2F;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d5.h[0]) >= 0);
skip_1:
    PLAYER(reg_a6)->ship_type.h = reg_d0.h[1];
    PLAYER(reg_a6)->power_style.h = reg_d0.h[0];
    reg_a6[0x56] = reg_a5[6];
    if (reg_a5[7] != 0) goto next_30;
    reg_d0.w = 0;
    *(u16 *)(reg_a3 + 0) = reg_d0.h[0];
    *(u16 *)(reg_a3 + 4) = reg_d0.h[1];
    *(u16 *)(reg_a3 + 6) = reg_d0.h[0];
    *(u16 *)(reg_a3 + 8) = reg_d0.h[1];
    *(u16 *)(reg_a3 + 0xA) = reg_d0.h[0];
    *(u16 *)(reg_a3 + 0xC) = reg_d0.h[0];
    *(u16 *)(reg_a3 + 0xE) = reg_d0.h[0];
    reg_d0.h[0] = PLAYER(reg_a6)->power_style.h;
    reg_a0 = (u8 *)((u16 *)D_0028C608);
    reg_d0.h[0] -= 2;
    reg_a0 += reg_d0.h[0];
    reg_d0.b[0] = reg_a0[1];
    reg_a6[0x25] = reg_d0.b[0];
    reg_a6[0x24] = reg_a0[0];
    reg_a0 += 2;
    if (reg_d6.h[0] == 0) goto next_25;
    PLAYER(reg_a6)->shot_power.h = reg_d1.h[1];
    PLAYER(reg_a6)->laser_power.h = reg_d1.h[0];
    reg_a6[0x25] = reg_d2.b[0];
    reg_a6[0x24] = reg_d2.b[0];
    if (reg_d4.h[0] != 0) goto next_30;
next_25:
    reg_a6[0x25] = reg_d0.b[0];
    reg_a6[0x24] = reg_d0.b[0];
    reg_d0.w = 0;
    PLAYER(reg_a6)->shot_power.h = reg_d0.h[1];
    PLAYER(reg_a6)->laser_power.h = reg_d0.h[0];
    reg_d0.h[0] = PLAYER(reg_a6)->power_style.h;
    reg_d0.h[0] -= 2;
    reg_d0.h[0] <<= 1;
    reg_d0.h[0] += PLAYER(reg_a6)->ship_type.h;
    reg_a2 = (u8 *)((u16 *)player_weapon_tables);
    reg_d0.h[0] <<= 2;
    *(u16 *)(reg_a4 + 0) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    *(u16 *)(reg_a4 + 2) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    *(u16 *)(reg_a4 + 4) = ((reg_d0.h[0] + 4) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d0.h[0] + 4) & ~1)) : *(u16 *)reg_a2;
    *(u16 *)(reg_a4 + 6) = ((reg_d0.h[0] + 6) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d0.h[0] + 6) & ~1)) : *(u16 *)reg_a2;
next_30:
    reg_d0.w = 0;
    reg_d0.b[0] = reg_a5[6];
    if (g_simulation_active != 0) {
        player_spawn_power_setup();
    }
    player_slot_request_bomb_display();
#ifdef DEATH_LABEL
    if (g_attract_demo != 0) {
        reg_d1.w = 0;
        reg_d1.h[0] = D_0028E810;
        PLAYER(reg_a6)->shot_power.h = reg_d1.h[0];
        PLAYER(reg_a6)->laser_power.h = reg_d1.h[0];
        reg_d0.h[0] = PLAYER(reg_a6)->power_style.h;
        reg_d0.h[0] -= 2;
        reg_d0.h[0] <<= 1;
        reg_d0.h[0] += PLAYER(reg_a6)->ship_type.h;
        reg_a2 = (u8 *)((u16 *)player_weapon_tables);
        reg_d0.h[0] <<= 2;
        *(u16 *)(reg_a4 + 0) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
        *(u16 *)(reg_a4 + 2) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        *(u16 *)(reg_a4 + 4) = ((reg_d0.h[0] + 4) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d0.h[0] + 4) & ~1)) : *(u16 *)reg_a2;
        *(u16 *)(reg_a4 + 6) = ((reg_d0.h[0] + 6) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d0.h[0] + 6) & ~1)) : *(u16 *)reg_a2;
        reg_tmp.h[1] = *(u16 *)(reg_a4 + 0);
        reg_tmp.h[0] = *(u16 *)(reg_a4 + 2);
        reg_tmp.w += reg_d1.w;
        *(u16 *)(reg_a4 + 0) = reg_tmp.h[1];
        *(u16 *)(reg_a4 + 2) = reg_tmp.h[0];
        reg_tmp.h[1] = *(u16 *)(reg_a4 + 4);
        reg_tmp.h[0] = *(u16 *)(reg_a4 + 6);
        reg_tmp.w += reg_d1.w;
        *(u16 *)(reg_a4 + 4) = reg_tmp.h[1];
        *(u16 *)(reg_a4 + 6) = reg_tmp.h[0];
    }
#endif
    if (g_game_mode != 2) goto next_40;
    if (reg_d6.h[0] != 0) goto next_35;
    player_displays_reset();
    goto next_36;
next_35:
    player_spawn_timers_set();
next_36:
    weapon_level_data_set(reg_a6);
next_40:
    if (g_simulation_active == 0) goto next_76;
    if (reg_d6.h[0] == 0) goto next_41;
    if (D_0028E2C4 == 0) goto next_76;
next_41:
#ifndef DEATH_LABEL
    if (reg_a6 == ((u8 *)g_player1)) {
        g_p1_death_count = D_006E5C14[0];
    } else {
        g_p2_death_count = D_006E5C14[0];
    }
#endif
    reg_d1.w = 0;
    reg_d1.h[0] = D_006E5BF2[0];
    PLAYER(reg_a6)->shot_power.h = reg_d1.h[0];
    reg_d1.h[0] = D_006E5BF0[0];
    PLAYER(reg_a6)->laser_power.h = reg_d1.h[0];
    weapon_level_data_set(reg_a6);
    g_p1_hyper_items = 0;
    g_p2_hyper_items = 0;
    if (D_0028E2B0 != 0) goto next_60;
    for (i = 0; i < D_006E5BFC[0]; i++) {
        if (reg_a6 == ((u8 *)g_player1)) {
            p1_hyper_item_take();
        } else {
            p2_hyper_item_take();
        }
    }
#ifdef DEATH_LABEL
    if (reg_a6 == ((u8 *)g_player1)) {
        if (D_0028E2AC == 0) goto next_50;
        if (reg_d6.h[0] == 0) {
            val = D_0028E2AC & 0xFFFF;
            rem = val % 100;
            g_p1_hyper_gauge = (rem * 0x960) / 100;
            if (val == 0x1F4) {
                g_p1_hyper_items_pending = 4;
                g_p1_hyper_gauge = 0x95F;
            } else {
                g_p1_hyper_items_pending = val / 100;
            }
        } else {
            val = D_0028E2AC & 0xFFFF;
            if (val >= 100) {
                g_p1_hyper_items_pending = 0;
                g_p1_hyper_gauge = 0x95F;
            } else {
                g_p1_hyper_items_pending = 0;
                g_p1_hyper_gauge = ((val % 100) * 0x960) / 100;
            }
        }
    } else {
        if (D_0028E2AC == 0) goto next_50;
        if (reg_d6.h[0] == 0) {
            val = D_0028E2AC & 0xFFFF;
            rem = val % 100;
            g_p2_hyper_gauge = (rem * 0x960) / 100;
            if (val == 0x1F4) {
                g_p2_hyper_items_pending = 4;
                g_p2_hyper_gauge = 0x95F;
            } else {
                g_p2_hyper_items_pending = val / 100;
            }
        } else {
            val = D_0028E2AC & 0xFFFF;
            if (val >= 100) {
                g_p2_hyper_items_pending = 0;
                g_p2_hyper_gauge = 0x95F;
            } else {
                g_p2_hyper_items_pending = 0;
                g_p2_hyper_gauge = ((val % 100) * 0x960) / 100;
            }
        }
    }
#else
    if (reg_d6.h[0] != 0) goto next_45;
    if (D_0028E280 != 5) goto next_45;
    if (reg_a6 == ((u8 *)g_player1)) {
        if (g_p1_hyper_items != 0) {
            g_p1_hyper_time = 0;
            D_0028E288 = 0x78;
        }
    } else if (g_p2_hyper_items != 0) {
        g_p2_hyper_time = 0;
        D_0028E284 = 0x78;
    }
next_45:
    if (reg_a6 == ((u8 *)g_player1)) {
        if (D_0028E2AC == 0) goto next_50;
        val = D_0028E2AC & 0xFFFF;
        rem = val % 100;
        g_p1_hyper_gauge = (rem * 0x960) / 100;
        if (val == 0x1F4) {
            g_p1_hyper_items_pending = 4;
            g_p1_hyper_gauge = 0x95F;
        } else {
            g_p1_hyper_items_pending = val / 100;
        }
        if (reg_d6.h[0] == 0) goto next_50;
        p1_hyper_items_pending_take();
    } else {
        if (D_0028E2AC == 0) goto next_50;
        val = D_0028E2AC & 0xFFFF;
        rem = val % 100;
        g_p2_hyper_gauge = (rem * 0x960) / 100;
        if (val == 0x1F4) {
            g_p2_hyper_items_pending = 4;
            g_p2_hyper_gauge = 0x95F;
        } else {
            g_p2_hyper_items_pending = val / 100;
        }
        if (reg_d6.h[0] == 0) goto next_50;
        p2_hyper_items_pending_take();
    }
#endif
next_50:
    if (reg_a6 == ((u8 *)g_player1)) {
        g_p1_hyper_total = D_006E5C12[0];
    } else {
        g_p2_hyper_total = D_006E5C12[0];
    }
    goto next_76;
next_60:
    if (reg_a6 == ((u8 *)g_player1)) {
        g_p1_hyper_total = D_006E5C12[0];
    } else {
        g_p2_hyper_total = D_006E5C12[0];
    }
    n = D_006E5BFC[0];
    if (n == 0) {
        n = 1;
    }
    if (reg_a6 == ((u8 *)g_player1)) {
        g_p1_hyper_in_effect = 1;
        g_p1_hyper_active = 1;
        g_p1_died_in_hyper = 1;
        PLAYER(reg_a6)->flags.b[0] |= 1;
        g_p1_hyper_level = n;
        g_p1_hyper_items = 0;
        if (D_0028E2AC != 0) {
            val = D_0028E2AC & 0xFFFF;
            rem = val % 100;
            g_p1_hyper_gauge = (rem * 0x960) / 100;
            if (val == 0x1F4) {
                g_p1_hyper_items_pending = 4;
                g_p1_hyper_gauge = 0x95F;
            } else {
                g_p1_hyper_items_pending = val / 100;
            }
        }
        if (D_0028E2A8 != 0) {
            val = D_0028E2A8 & 0xFF;
            g_p1_hyper_time = (val * 0x960) / 100;
        }
        g_p1_hyper_combo_decay = 0;
    } else {
        g_p2_hyper_in_effect = 1;
        g_p2_hyper_active = 1;
        g_p2_died_in_hyper = 1;
        PLAYER(reg_a6)->flags.b[0] |= 1;
        g_p2_hyper_level = n;
        g_p2_hyper_items = 0;
        if (D_0028E2AC != 0) {
            val = D_0028E2AC & 0xFFFF;
            rem = val % 100;
            g_p2_hyper_gauge = (rem * 0x960) / 100;
            if (val == 0x1F4) {
                g_p2_hyper_items_pending = 4;
                g_p2_hyper_gauge = 0x95F;
            } else {
                g_p2_hyper_items_pending = val / 100;
            }
        }
        if (D_0028E2A8 != 0) {
            val = D_0028E2A8 & 0xFF;
            g_p2_hyper_time = (val * 0x960) / 100;
        }
        g_p2_hyper_combo_decay = 0;
    }
next_76:
    reg_a6[0x3F] = 0xF0;
    if (g_game_mode == 2) goto next_85;
    if (reg_d6.h[0] != 0) goto next_85;
    if (g_stage == 0) goto next_85;
    if (g_simulation_active == 0) goto next_85;
    reg_a6[0x3F] = 0;
next_85:
    reg_a0 = (u8 *)player_spawn_table_5;
    if (reg_a5[6] != 0) {
        reg_a0 = (u8 *)player_spawn_table_6;
    }
    PLAYER(reg_a6)->y.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    PLAYER(reg_a6)->x.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    PLAYER(reg_a6)->attr.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a6[0x55] = reg_a0[1];
    reg_a6[0x54] = reg_a0[0];
    reg_a0 += 2;
    reg_a6[0x3A] = PLAYER(reg_a6)->attr.b.palette;
    reg_a6[0x57] = reg_a6[0x55];
    PLAYER(reg_a6)->y.h = *(u16 *)(reg_a5 + 8);
    PLAYER(reg_a6)->x.h = *(u16 *)(reg_a5 + 0xA);
    reg_d0.h[0] = PLAYER(reg_a6)->ship_type.h;
    reg_a0 = (u8 *)player_spawn_table;
    reg_d0.h[0] <<= 2;
    reg_a0 += reg_d0.h[0];
    PLAYER(reg_a6)->sprite_hi.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    PLAYER(reg_a6)->sprite_lo.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    PLAYER(reg_a6)->hit_y_plus.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    PLAYER(reg_a6)->hit_y_minus.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[0] = PLAYER(reg_a6)->power_style.h;
    reg_d0.h[0] -= 2;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] <<= 1;
    reg_d2.h[0] = PLAYER(reg_a6)->ship_type.h;
    reg_d0.h[0] += reg_d2.h[0];
    reg_d2.h[0] <<= 1;
    reg_d1.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)player_spawn_table_2;
    reg_a0 += reg_d0.h[0];
    PLAYER(reg_a6)->move.b.speed = reg_a0[1];
    reg_a6[0x38] = reg_a0[1];
    reg_a6[0x39] = reg_a0[0];
    reg_a0 = (u8 *)player_spawn_table_3;
    reg_a0 += reg_d1.h[0];
    PLAYER(reg_a6)->burst_reset.h = *(u16 *)reg_a0;
    PLAYER(reg_a6)->option_burst_reset.h = *(u16 *)(reg_a0 + 2);
    reg_a0 += 4;
    player_sprite_update();
}

void p1_maximum_digits_update(void);
void p2_maximum_digits_update(void);
extern u8 D_0028C608[];
extern u16 g_p2_maximum_anim_delay_reset;
extern u16 g_p2_maximum_anim_delay;
extern u16 g_p1_maximum_anim_delay_reset;
extern u16 g_p1_maximum_anim_delay;
extern u16 D_006E5BF4[];
extern u16 D_006E5BF6[];
extern u16 D_006E5C0E[];
extern u16 D_006E5C10[];

void player_spawn_power_setup(void) {
#ifndef DDPDOJ_PC
    void p1_maximum_level_show(void);
    void p2_maximum_level_show(void);
#endif
    u8 *sa0;
    u8 *sa1;
    u8 *sa2;
    u8 *sa3;
    u8 *sa4;
    u8 *sa5;
    u32 sd0;
    u32 v1;
    u32 v2;
    u32 sd1;
    u32 sd2;
    u32 sd3;
    u32 sd4;
    u32 sd5;
    u32 sd6;
    u32 sd7;
    u8 *sa6;

    if (reg_d6.h[0] == 0 || D_0028E2C4 != 0) {
        sd0 = reg_d0.w;
        sd1 = reg_d1.w;
        sd2 = reg_d2.w;
        sd3 = reg_d3.w;
        sd4 = reg_d4.w;
        sd5 = reg_d5.w;
        sd6 = reg_d6.w;
        sd7 = reg_d7.w;
        sa0 = reg_a0;
        sa1 = reg_a1;
        sa2 = reg_a2;
        sa3 = reg_a3;
        sa4 = reg_a4;
        sa5 = reg_a5;
        sa6 = reg_a6;
        reg_d5.h[0] = *(u16 *)(sa6 + 0x5A);
        reg_a0 = (u8 *)D_0028C608;
        reg_d5.h[0] -= 2;
        reg_d5.b[0] = *(reg_a0 + reg_d5.h[0] + (!(reg_d5.h[0] & 1) ? 1 : -1));
        reg_d5.b[0] *= 2;
        if (D_006E5BF4[0] == 6) {
            *(u8 *)(sa6 + 0x24) = (s32)reg_d5.b[0] / 2;
        } else if ((s32)reg_d5.b[0] < (s32)(D_006E5BF4[0] + 1)) {
            *(u8 *)(sa6 + 0x24) = reg_d5.b[0];
        } else {
            *(u8 *)(sa6 + 0x24) = D_006E5BF4[0] + 1;
        }
        if (D_006E5BF6[0] == 8) {
            PLAYER(reg_a6)->bombs.b.count = PLAYER(reg_a6)->bombs.b.capacity;
        } else if (D_006E5BF6[0] == 7) {
            PLAYER(reg_a6)->bombs.b.count = PLAYER(reg_a6)->bombs.b.capacity;
            if (reg_a6 == ((u8 *)g_player1)) {
                PLAYER(((u8 *)g_player1))->flags.b[1] &= 0xBF;
                ((u8 *)g_player1)[0] |= 2;
                g_p1_maximum_count_as_s16_a[0] = D_006E5C10[0] + 1;
                ((s16 *)g_p1_maximum_value)[0] = (D_006E5C10[0] + 1) * 0x16;
                p1_maximum_digits_update();
                v1 = D_006E5C0E[0];
                g_p1_maximum_level = v1 * 4;
                p1_maximum_level_show();
                g_p1_maximum_anim_delay_reset = 2 - v1;
                g_p1_maximum_anim_delay = g_p1_maximum_anim_delay_reset;
            } else {
                PLAYER(((u8 *)g_player2))->flags.b[1] &= 0xBF;
                ((u8 *)g_player2)[0] |= 2;
                g_p2_maximum_count_as_s16_a[0] = D_006E5C10[0] + 1;
                ((s16 *)g_p2_maximum_value)[0] = (D_006E5C10[0] + 1) * 0x16;
                p2_maximum_digits_update();
                v2 = D_006E5C0E[0];
                g_p2_maximum_level = v2 * 4;
                p2_maximum_level_show();
                g_p2_maximum_anim_delay_reset = 2 - v2;
                g_p2_maximum_anim_delay = g_p2_maximum_anim_delay_reset;
            }
        } else if ((s32)PLAYER(reg_a6)->bombs.b.capacity < (s32)D_006E5BF6[0]) {
            PLAYER(reg_a6)->bombs.b.count = PLAYER(reg_a6)->bombs.b.capacity;
        } else {
            PLAYER(reg_a6)->bombs.b.count = D_006E5BF6[0];
        }
        reg_a6 = sa6;
        reg_d1.w = sd1;
        reg_d2.w = sd2;
        reg_d3.w = sd3;
        reg_d4.w = sd4;
        reg_a0 = sa0;
        reg_d5.w = sd5;
        reg_d6.w = sd6;
        reg_d7.w = sd7;
        reg_a1 = sa1;
        reg_a2 = sa2;
        reg_a3 = sa3;
        reg_a4 = sa4;
        reg_a5 = sa5;
        reg_d0.w = sd0;
    }
}

#pragma push
#pragma opt_propagation off

void hyper_ready_displays_reset(void) {
    u8 *a0;
    u8 *a1;
    u8 *a2;
    u8 *a3;
    u8 *a4;
    u8 *a5;
    u8 *a6;
    u32 d0;
    u32 d1;
    u32 d2;
    u32 d3;
    u32 d4;
    u32 d5;
    u32 d6;
    u32 d7;

    g_p1_hyper_ready_anim_delay = 0x101;
    g_p2_hyper_ready_anim_delay = 0x101;
    d0 = reg_d0.w;
    d1 = reg_d1.w;
    d2 = reg_d2.w;
    d3 = reg_d3.w;
    d4 = reg_d4.w;
    d5 = reg_d5.w;
    d6 = reg_d6.w;
    d7 = reg_d7.w;
    a0 = reg_a0;
    a1 = reg_a1;
    a2 = reg_a2;
    a3 = reg_a3;
    a4 = reg_a4;
    a5 = reg_a5;
    a6 = reg_a6;
    reg_d0.w = 0xC30;
    (*(u16 *)&g_p1_hyper_ready_sprite) = reg_d0.h[1];
    g_p1_hyper_ready_sprite_lo = reg_d0.h[0];
    g_p1_hyper_items_pending = 0;
    g_p1_hyper_gauge = 0;
    g_p2_hyper_items_pending = 0;
    g_p2_hyper_gauge = 0;
    g_p1_hyper_total = 0;
    g_p2_hyper_total = 0;
    reg_d0.w = 0xC30;
    (*(u16 *)&g_p2_hyper_ready_sprite) = reg_d0.h[1];
    g_p2_hyper_ready_sprite_lo = reg_d0.h[0];
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_d3.w = d3;
    reg_d4.w = d4;
    reg_d5.w = d5;
    reg_d6.w = d6;
    reg_d7.w = d7;
    reg_a0 = a0;
    reg_a1 = a1;
    reg_a2 = a2;
    reg_a3 = a3;
    reg_a4 = a4;
    reg_a5 = a5;
    reg_a6 = a6;
}
#pragma pop

void player_spawn_timers_set(void) {
    u8 *sa0;
    u8 *sa1;
    u8 *sa2;
    u8 *sa3;
    u8 *sa4;
    u8 *sa5;
    s32 sd0;
    s32 sd1;
    s32 sd2;
    s32 sd3;
    s32 sd4;
    s32 sd5;
    s32 sd6;
    s32 sd7;
    u8 *sa6;

    sd0 = reg_d0.w;
    sd1 = reg_d1.w;
    sd2 = reg_d2.w;
    sd3 = reg_d3.w;
    sd4 = reg_d4.w;
    sd5 = reg_d5.w;
    sd6 = reg_d6.w;
    sd7 = reg_d7.w;
    sa0 = reg_a0;
    sa1 = reg_a1;
    sa2 = reg_a2;
    sa3 = reg_a3;
    sa4 = reg_a4;
    sa5 = reg_a5;
    sa6 = reg_a6;
    reg_d1.w = 0;
    reg_d1.h[0] = 8;
    *(u16 *) (reg_a6 + 0x20) = reg_d1.h[0];
    *(u16 *) (reg_a6 + 0x22) = reg_d1.h[0];
    reg_a0 = sa0;
    reg_a1 = sa1;
    reg_a2 = sa2;
    reg_a3 = sa3;
    reg_a4 = sa4;
    reg_a5 = sa5;
    reg_a6 = sa6;
    reg_d0.w = sd0;
    reg_d1.w = sd1;
    reg_d2.w = sd2;
    reg_d3.w = sd3;
    reg_d4.w = sd4;
    reg_d5.w = sd5;
    reg_d6.w = sd6;
    reg_d7.w = sd7;
}

s32 p1_hyper_end();
s32 p2_hyper_end();
#ifdef DEATH_LABEL
extern u8 death_D_00290DC0;
extern u16 g_hyper_bullet_speed;
extern u16 g_bullet_speed_bonus;
#endif

void player_displays_reset(void) {
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    s32 lo;
    s32 step;
    s32 i;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    if (save_a6 == ((u8 *)g_player1)) {
        g_p1_maximum_anim_delay = 2;
        g_p1_maximum_anim_delay_reset = 2;
        reg_d0.w = 0xC30;
        g_p1_hyper_ready_anim_delay = 0x101;
        g_p1_maximum_level = 0;
        (*(u16 *)&g_p1_hyper_ready_sprite) = reg_d0.h[1];
        g_p1_hyper_ready_sprite_lo = reg_d0.h[0];
        p1_hyper_end();
        p1_hyper_state_clear();
    } else {
        g_p2_maximum_anim_delay = 2;
        g_p2_maximum_anim_delay_reset = 2;
        reg_d0.w = 0xC30;
        g_p2_hyper_ready_anim_delay = 0x101;
        g_p2_maximum_level = 0;
        (*(u16 *)&g_p2_hyper_ready_sprite) = reg_d0.h[1];
        g_p2_hyper_ready_sprite_lo = reg_d0.h[0];
        p2_hyper_end();
        p2_hyper_state_clear();
    }
    reg_d1.w = 0;
    reg_d1.h[0] = 8;
    PLAYER(reg_a6)->shot_power.h = (u16) reg_d1.h[0];
    PLAYER(reg_a6)->laser_power.h = (u16) reg_d1.h[0];
    g_p1_hyper_items = 0;
    g_p2_hyper_items = 0;
    for (i = 0; i < (s32) D_006E5BFC[0]; i++) {
        if (reg_a6 == ((u8 *)g_player1)) {
            p1_hyper_item_take();
        } else {
            p2_hyper_item_take();
        }
    }
#ifdef DEATH_LABEL
    if (reg_a6 == ((u8 *)g_player1)) {
        PLAYER(reg_a6)->flags.b[0] &= 0xFE;
        if (death_D_00290DC0 == 0) {
            g_p1_hyper_items_pending = 4;
            g_p1_hyper_gauge = 0x95F;
        } else {
            g_p1_hyper_items_pending = 0;
            g_p1_hyper_gauge = 0;
        }
        g_p1_hyper_total = 0xF;
    } else {
        PLAYER(reg_a6)->flags.b[0] &= 0xFE;
        if (death_D_00290DC0 == 0) {
            g_p2_hyper_items_pending = 4;
            g_p2_hyper_gauge = 0x95F;
        } else {
            g_p2_hyper_items_pending = 0;
            g_p2_hyper_gauge = 0;
        }
    }
    g_p2_hyper_total = 0xF;
    g_hyper_bullet_speed = 0xA;
    g_bullet_speed_bonus = 2;
#else
    if (reg_a6 == ((u8 *)g_player1)) {
        PLAYER(reg_a6)->flags.b[0] &= 0xFE;
        g_p1_hyper_items_pending = 4;
        g_p1_hyper_gauge = 0x95F;
        g_p1_hyper_total = 0xF;
    } else {
        PLAYER(reg_a6)->flags.b[0] &= 0xFE;
        g_p2_hyper_items_pending = 4;
        g_p2_hyper_gauge = 0x95F;
        g_p2_hyper_total = 0xF;
    }
#endif
    reg_d5.h[0] = PLAYER(reg_a6)->power_style.h;
    reg_a0 = (u8 *)D_0028C608;
    reg_d5.h[0] -= 2;
    lo = reg_d5.h[0] & 1;
    step = (lo != 0) ? -1 : 1;
    reg_d5.b[0] = *(reg_a0 + reg_d5.h[0] + step);
    reg_d5.b[0] *= 2;
    PLAYER(reg_a6)->bombs.b.capacity = (u8) reg_d5.b[0];
#ifdef DEATH_LABEL
    if (death_D_00290DC0 == 0) {
        PLAYER(reg_a6)->bombs.b.count = (u8) PLAYER(reg_a6)->bombs.b.capacity;
    } else {
        PLAYER(reg_a6)->bombs.b.count = 0;
        PLAYER(reg_a6)->bombs.b.count = (u8) PLAYER(reg_a6)->bombs.b.capacity;
    }
#else
    PLAYER(reg_a6)->bombs.b.count = (u8) PLAYER(reg_a6)->bombs.b.capacity;
#endif
    if (reg_a6 == ((u8 *)g_player1)) {
        ((s16 *)g_p1_maximum_value)[0] = 0;
        g_p1_maximum_count_as_s16_a[0] = 0;
        PLAYER(((u8 *)g_player1))->flags.b[1] |= 0x40;
        ((u8 *)g_player1)[0] &= 0xFD;
    } else {
        ((s16 *)g_p2_maximum_value)[0] = 0;
        g_p2_maximum_count_as_s16_a[0] = 0;
        PLAYER(((u8 *)g_player2))->flags.b[1] |= 0x40;
        ((u8 *)g_player2)[0] &= 0xFD;
    }
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    player_slot_request_bomb_display();
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
}

s32 sprite_draw_with_player_shadows();
extern u8 player_ship_sprite_tables[];
extern u16 player_ship_hitbox_tables[];
extern u16 player_ship_shadow_tables[];
extern u8 g_game_frame_ran;
extern u16 g_select_screen_active;
extern u16 g_frame_mod2;
extern u8 g_p2_score_pending_as_u8;
extern u8 g_p1_score_pending_as_u8;
extern u8 g_boss_present_b1;
extern u16 g_true_last_boss;
extern u8 D_0028EC4C;

void player_sprite_update(void) {
    u8 *p0;
    s32 *p1;
    u16 idx;

    reg_a0 = (u8 *)player_ship_sprite_tables;
    reg_d0.h[0] = PLAYER(reg_a6)->ship_type.h;
    reg_d0.h[0] *= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = PLAYER(reg_a6)->roll_frame.h;
    PLAYER(reg_a6)->sprite_hi.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    PLAYER(reg_a6)->sprite_lo.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)player_ship_hitbox_tables;
    reg_d1.w = 0;
    reg_d1.h[0] *= 4;
    reg_tmp.h[1] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    PLAYER(reg_a6)->hit_x_plus.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    PLAYER(reg_a6)->hit_x_minus.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    if ((g_players_hidden == 0) && (g_frame_mod2 == 0) && (g_loop == 0) && (g_stage != 2)) {
        reg_d1.h[1] = PLAYER(reg_a6)->y.h;
        reg_d1.h[0] = PLAYER(reg_a6)->x.h;
        reg_d5.h[0] = 0x1C00;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d5.h[0] = 0x1400;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.w += 0xFE00FE00;
        reg_a0 = (u8 *)player_ship_shadow_tables;
        reg_d0.h[0] = PLAYER(reg_a6)->ship_type.h;
        reg_d0.h[0] *= 2;
        idx = reg_d0.h[0];
        reg_tmp.h[1] = (idx != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)idx & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[0] = (((idx & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((idx & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *) reg_tmp.w;
        reg_d0.h[0] = PLAYER(reg_a6)->roll_frame.h;
        reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d2.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.h[0] = 0x210;
        reg_d4.h[0] = 0x18;
        sprite_draw_with_player_shadows();
    }
    if ((g_game_frame_ran != 0) && (D_0028EC4C == 0) && (g_select_screen_active == 0) && !(g_boss_present_b1 & 1) && (g_true_last_boss == 0) && !(PLAYER(reg_a6)->flags.b[1] & 0x40)) {
        if (*(u8 *)(reg_a5 + 6) == 0) {
            if (g_p1_maximum_anim_delay == 0) {
                p0 = &g_p1_score_pending_as_u8;
                p1 = (s32 *)(p0 - 0x34);
                *p1 = g_p1_maximum_value_digits[0];
                bcd_add((void *)p0, (void *)p1);
                if (g_loop != 0) {
                    bcd_add((void *)p0, (void *)p1);
                }
                return;
            }
        } else if (g_p2_maximum_anim_delay == 0) {
            p0 = &g_p2_score_pending_as_u8;
            p1 = (s32 *)(p0 - 0x30);
            *p1 = g_p2_maximum_value_digits[0];
            bcd_add((void *)p0, (void *)p1);
            if (g_loop != 0) {
                bcd_add((void *)p0, (void *)p1);
            }
        }
    }
    return;
}

typedef void (*Fn)();

extern u8 hyper_bullet_speed_table[];
extern u8 player_update_table_2[];
extern u8 ship0_shot_lists_1[];
extern u8 ship0_shot_lists_2[];
extern u8 ship0_shot_lists_3[];
extern u8 player_update_table_5[2];
extern u8 player_update_table_6[2];
extern u8 D_0029EA50[];
s32 bomb_palette_load_first();
s32 bomb_palette_load_second();
s32 side_scroll_follow_at_limit();
s32 p1_laser_stop();
s32 p1_laser_clear();
s32 p2_laser_stop();
s32 p2_laser_clear();
s32 bomb_stock_draw_for_task();
s32 input_get_p1_held();
s32 input_get_p2_held();
s32 input_get_p1_pressed();
s32 input_get_p2_pressed();
s32 sfx_shot_a();
s32 sfx_shot_b();
s32 sfx_shot_hyper();
s32 sfx_misc_2();
s32 p1_hyper_items_update();
s32 p2_hyper_items_update();
s32 binary_to_bcd();
s32 bullet_cancel_by_player1();
s32 bullet_cancel_by_player2();
s32 bullet_cancel_begin();
#ifndef DDPDOJ_PC
s32 entity_velocity();
#endif
extern u8 player_update_table[];
extern u16 player_update_table_3[];
extern u16 player_update_table_4[];
extern u16 g_p2_bombs_used;
extern u16 g_p1_bombs_used;
extern u16 g_p2_weapon_level_data_lo[];
extern u16 g_p1_weapon_level_data_lo[];
extern u8 g_setting_rapid_fire;
extern s16 g_slowdown_loop2_allowed;
extern s16 g_slowdown_forced_frames;
extern u16 g_p2_combo_timer;
extern u16 g_p1_combo_timer;
extern u16 g_p2_combo_at_bomb;
extern u16 g_p1_combo_at_bomb;
extern u16 g_scroll_line;
extern u16 g_two_player_game;
extern u16 g_bullet_cancel[];
extern u16 g_bullet_cancel_kind[];
extern u16 g_side_scroll_step[];

void player_update(void) {
    u32 tmp_dec;
    u8 *p0;
    s32 *p1;
    u8 *temp_a0_10;
    u8 *temp_a2_5;
    u8 *temp_a3;
    u8 *temp_a3_3;
    u8 *temp_s0;
    s16 temp_a0_11;
    s16 temp_a0_14;
    s16 temp_a0_16;
    u32 temp_a0_4;
    u32 temp_a0_5;
    u32 temp_a0_9;
    u32 temp_a1_9;
    u32 temp_v0_2;
    u32 temp_v1_2;
    u16 var_a3;
    u16 var_v1;
    u8 temp_a0;
    u8 temp_a0_3;
    u8 temp_a0_6;
    u8 temp_a0_7;
    u8 temp_v0;
    u8 temp_v1;
    u8 *temp_a0_8;
    u8 *temp_a1;
    u8 *temp_a1_3;
    u8 *temp_a1_8;
    u8 *temp_a2_2;
    u8 *var_a0;

    PLAYER(reg_a6)->who.b.side = (u8) *(u8 *)(reg_a5 + 6);
    temp_a0 = PLAYER(reg_a6)->flags.b[1];
    temp_a1 = (u8 *)(reg_a6 + 1);
    if (temp_a0 & 1) {
        player_destroyed_update();
        return;
    }
    if (g_players_stage_clear != 0) goto L_else;
    {
        reg_tmp.b[0] = temp_a0;
        PLAYER(reg_a6)->flags.b[1] &= 0xDF;
        if (reg_tmp.b[0] & 0x20) {
            if (g_game_mode == 2) {
                player_displays_reset();
            }
            PLAYER(reg_a6)->flags.b[0] &= 0xFB;
            PLAYER(reg_a6)->move.b.speed = (u8) PLAYER(reg_a6)->speed.b.normal;
        }
        var_a0 = (u8 *)(reg_a6);
        switch ((*(u8 *)((u8 *)(var_a0) + (0x3F)))) { case 0: break; default:
            (*(u8 *)((u8 *)(var_a0) + (1))) &= 0xEF;
            var_a0 = (u8 *)(reg_a6 + 0x3F);
            temp_v1 = PLAYER(reg_a6)->state.b.invincible;
            if ((temp_v1 != 0xFF) && (g_game_frame_ran != 0)) {
                PLAYER(reg_a6)->state.b.invincible = (u8) (temp_v1 - 1);
            }
            goto block_13;
        }
        (*(u8 *)((u8 *)(var_a0) + (0x1C))) = (u8) (*(u8 *)((u8 *)(var_a0) + (0x3A)));
        reg_tmp.b[0] = PLAYER(reg_a6)->flags.b[1];
        PLAYER(reg_a6)->flags.b[1] &= 0xEF;
        if (reg_tmp.b[0] & 0x10) {
            player_destroyed_begin();
            return;
        }
block_13:
        PLAYER(reg_a6)->flags.h &= 0xFFDF;
        temp_v0 = PLAYER(reg_a6)->aux.b.shot_sound_wait;
        if (temp_v0 != 0) {
            PLAYER(reg_a6)->aux.b.shot_sound_wait = (u8) (temp_v0 - 1);
        }
        if (*(u8 *)(reg_a5 + 6) == 0) {
            input_get_p1_held();
            PLAYER(reg_a6)->input.b.raw = (u8) reg_d0.b[0];
            input_get_p1_pressed();
            PLAYER(reg_a6)->input.b.filtered = reg_d0.b[0];
        } else {
            input_get_p2_held();
            PLAYER(reg_a6)->input.b.raw = (u8) reg_d0.b[0];
            input_get_p2_pressed();
            PLAYER(reg_a6)->input.b.filtered = reg_d0.b[0];
        }
        reg_d0.w = 0;
        PLAYER(reg_a6)->moved_y.h = 0U;
        PLAYER(reg_a6)->moved_x.h = 0U;
        if (g_player_shots_disabled != 0) {
            PLAYER(reg_a6)->input.b.raw &= 0xF;
            PLAYER(reg_a6)->input.b.filtered &= 0xF;
            PLAYER(reg_a6)->state.b.invincible = 0xFFU;
        }
        reg_d0.w = 0xF;
        reg_d0.b[0] &= PLAYER(reg_a6)->input.b.raw;
        reg_a2 = (u8 *)player_update_table;
        PLAYER(reg_a6)->move.b.dir = (u8) *(reg_a2 + reg_d0.h[0] + ((reg_d0.h[0] & 1) ? -1 : 1));
        if ((s8) PLAYER(reg_a6)->move.b.dir < 0) {
            player_roll_recenter();
            reg_d2.h[0] = PLAYER(reg_a6)->y.h;
            reg_d3.h[0] = PLAYER(reg_a6)->x.h;
        } else {
            entity_velocity();
            PLAYER(reg_a6)->moved_y.h = (u16) reg_d2.h[0];
            PLAYER(reg_a6)->moved_x.h = (u16) reg_d3.h[0];
            PLAYER(reg_a6)->scroll_offset.h = (u16) reg_d3.h[0];
            reg_d2.h[0] = PLAYER(reg_a6)->y.h;
            reg_d3.h[0] = PLAYER(reg_a6)->x.h;
            temp_a0_3 = PLAYER(reg_a6)->input.b.raw;
            if (temp_a0_3 & 4) {
                PLAYER(reg_a6)->flags.h |= 0x20;
                if (PLAYER(reg_a6)->roll_frame.sh != -0x20) {
                    reg_tmp.h[0] = PLAYER(reg_a6)->roll_delay.h;
                    PLAYER(reg_a6)->roll_delay.h -= 1;
                    if ((s32) reg_tmp.h[0] <= 0) {
                        PLAYER(reg_a6)->roll_delay.h = 2U;
                        PLAYER(reg_a6)->roll_frame.h += 0x7FFF + 0x7FFD;
                    }
                }
                if ((s32) reg_d3.h[0] < 0x301) {
                    reg_d3.h[0] -= 0x300;
                    temp_a0_4 = PLAYER(reg_a6)->moved_x.h;
                    PLAYER(reg_a6)->moved_x.h = (u16) (temp_a0_4 - reg_d3.h[0]);
                    reg_d3.h[0] = 0x300;
                    side_scroll_follow_at_limit();
                }
            } else if (temp_a0_3 & 8) {
                PLAYER(reg_a6)->flags.h |= 0x20;
                if (PLAYER(reg_a6)->roll_frame.h != 0x20) {
                    reg_tmp.h[0] = PLAYER(reg_a6)->roll_delay.h;
                    PLAYER(reg_a6)->roll_delay.h -= 1;
                    if ((s32) reg_tmp.h[0] <= 0) {
                        PLAYER(reg_a6)->roll_delay.h = 2U;
                        PLAYER(reg_a6)->roll_frame.h += 4;
                    }
                }
                if ((s32) reg_d3.h[0] >= 0x3500) {
                    reg_d3.h[0] -= 0x3500;
                    temp_a0_5 = PLAYER(reg_a6)->moved_x.h;
                    PLAYER(reg_a6)->moved_x.h = (u16) (temp_a0_5 - reg_d3.h[0]);
                    reg_d3.h[0] = 0x3500;
                    side_scroll_follow_at_limit();
                }
            } else {
                player_roll_recenter();
            }
            temp_a0_6 = PLAYER(reg_a6)->input.b.raw;
            if (temp_a0_6 & 1) {
                if ((s32) reg_d2.h[0] > 0x6500) {
                    reg_d2.h[0] -= 0x6500;
                    PLAYER(reg_a6)->moved_y.h -= reg_d2.h[0];
                    reg_d2.h[0] = 0x6500;
                }
            } else if ((temp_a0_6 & 2) && ((s32) reg_d2.h[0] < 0x800)) {
                reg_d2.h[0] -= 0x800;
                var_v1 = 0x800;
                PLAYER(reg_a6)->moved_y.h -= reg_d2.h[0];
                reg_d2.h[0] = var_v1;
            }
        }
        if ((s8) PLAYER(reg_a6)->flags.b[0] < 0) {
            temp_v1_2 = PLAYER(reg_a6)->laser_bomb_recoil.h;
            if (temp_v1_2 != 0) {
                reg_d0.h[0] = temp_v1_2;
                reg_a0 = (u8 *)player_update_table_2;
                reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                PLAYER(reg_a6)->offset_y.h -= reg_d0.h[0];
                PLAYER(reg_a6)->laser_recoil.h = (u16) reg_d0.h[0];
                PLAYER(reg_a6)->laser_bomb_recoil.h -= 2;
            }
            if (g_laser_bomb_hit_entity != 0) {
                PLAYER(reg_a6)->moved_y.h -= 0x48;
                reg_d2.h[0] -= 0x48;
            }
            if ((s32) reg_d2.h[0] < 0x800) {
                reg_d0.h[0] = 0x800;
                reg_d0.h[0] -= reg_d2.h[0];
                PLAYER(reg_a6)->moved_y.h += reg_d0.h[0];
                reg_d2.h[0] = 0x800;
            }
        }
        PLAYER(reg_a6)->y.h = (u16) reg_d2.h[0];
        PLAYER(reg_a6)->x.h = (u16) reg_d3.h[0];
        if ((g_two_player_game == 0) && !(PLAYER(reg_a6)->flags.b[0] & 0x20)) {
            reg_d3.h[0] = PLAYER(reg_a6)->x.h;
            reg_d0.h[0] = g_side_scroll_step[0];
            reg_d3.h[0] -= reg_d0.h[0];
            PLAYER(reg_a6)->x.h = (u16) reg_d3.h[0];
        }
        if ((g_setting_rapid_fire != 0) && (PLAYER(reg_a6)->input.b.raw & 0x40) && (PLAYER(reg_a6)->fire_lockout.b[1] == 0)) {
            reg_a0 = (u8 *)g_p1_options;
            if (*(u8 *)(reg_a5 + 6) != 0) {
                reg_a0 = (u8 *)g_p2_options;
            }
            PLAYER(reg_a6)->input.b.filtered &= 0xEF;
            PLAYER(reg_a6)->flags.b[0] &= 0xF7;
            *reg_a0 &= 0xF7;
            temp_a0_7 = PLAYER(reg_a6)->flags.b[0];
            if (temp_a0_7 & 0x10) {
                PLAYER(reg_a6)->flags.b[0] = (u8) (temp_a0_7 & 0xEF);
            } else {
                PLAYER(reg_a6)->flags.b[0] = (u8) (temp_a0_7 | 0x10);
                PLAYER(reg_a6)->flags.b[0] |= 8;
                *reg_a0 |= 8;
                PLAYER(reg_a6)->input.b.filtered |= 0x10;
            }
        }
        if (((s32) g_scroll_line >= 4) && (PLAYER(reg_a6)->input.b.raw & 0x20)) {
            temp_a2_2 = (u8 *)(reg_a5 + 6);
            if (*(u8 *)(reg_a5 + 6) == 0) {
                reg_a0 = (u8 *)p1_laser_stop;
                reg_a1 = (u8 *)((u8 *)&g_p1_hyper_items);
                reg_a2 = &(*(u8 *)&g_p1_hyper_in_effect);
                reg_a3 = (u8 *)(player_update_table_3);
                reg_d6.h[0] = g_p1_hyper_total;
                reg_d7.h[0] = *(u16 *)((u8 *)g_p1_maximum_value);
            } else {
                reg_a0 = (u8 *)p2_laser_stop;
                reg_a1 = (u8 *)((u8 *)&g_p2_hyper_items);
                reg_a2 = &(*(u8 *)&g_p2_hyper_in_effect);
                reg_a3 = (u8 *)(player_update_table_4);
                reg_d6.h[0] = g_p2_hyper_total;
                reg_d7.h[0] = *(u16 *)((u8 *)g_p2_maximum_value);
            }
            reg_d1.h[0] = *(u16 *)reg_a1;
            if (reg_d1.h[0] != 0) {
                reg_d1.h[0] -= 1;
                reg_d1.h[0] *= 2;
                reg_a1 = (u8 *)hyper_bullet_speed_table;
                reg_d6.h[0] -= 1;
                reg_d6.h[0] *= 2;
                reg_d6.h[0] = (reg_d6.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d6.h[0] & ~1)) : *(u16 *)reg_a1;
                g_bullet_cancel[0] += 8;
                g_bullet_cancel_kind[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                reg_call_target = (Fn)(reg_a0);
                reg_call_target();
                *(s16 *)reg_a2 = 1;
                PLAYER(reg_a6)->flags.b[0] |= 1;
                sfx_misc_2();
                reg_a0 = (u8 *)bullet_cancel_by_player1;
                if (*(u8 *)(reg_a5 + 6) != 0) {
                    reg_a0 = (u8 *)bullet_cancel_by_player2;
                }
                reg_call_target = (Fn)(reg_a0);
                reg_call_target();
                PLAYER(reg_a6)->state.b.invincible = 2U;
                g_slowdown_forced_frames = 0x14;
                if ((PLAYER(reg_a6)->flags.b[1] & 0x40) || (reg_d7.h[0] == 0)) {
                    bomb_stock_draw_for_task();
                }
                goto block_122;
            }
            temp_a0_8 = (u8 *)(reg_a6 + 0x25);
            if (PLAYER(reg_a6)->bombs.b.count != 0) {
                reg_a1 = (u8 *)((u8 *)&g_p1_hyper_effect_flag);
                if (*(u8 *)(reg_a5 + 6) != 0) {
                    reg_a1 = (u8 *)((u8 *)&g_p2_hyper_effect_flag);
                }
                if ((*(u16 *)reg_a1 == 0) && (reg_a1 = (u8 *)((u8 *)g_bomb_entities), ((s16) *(u16 *)reg_a1 >= 0))) {
                    g_slowdown_loop2_allowed = 1;
                    PLAYER(reg_a6)->bombs.b.count -= 1;
                    if (PLAYER(reg_a6)->bombs.b.count == 0) {
                        if (*(u8 *)(reg_a5 + 6) == 0) {
                            p1_hyper_items_update();
                        } else {
                            p2_hyper_items_update();
                        }
                    }
                    if (*(u8 *)(reg_a5 + 6) == 0) {
                        g_p1_stage_bomb_used = 1;
                        if ((s32) g_p1_bombs_used < 0x63) {
                            g_p1_bombs_used += 1;
                        }
                        reg_a2 = (u8 *)((u8 *)g_player2);
                        reg_a3 = (u8 *)(&g_p1_combo_at_bomb);
                        reg_a4 = (u8 *)((u8 *)g_p1_maximum_value);
                        reg_d0.h[0] = g_p1_combo_timer;
                        if (g_p1_hyper_active != 0) {
                            p1_hyper_end();
                            reg_tmp.h[0] = g_p1_hyper_total;
                            g_p1_hyper_total -= 3;
                            if ((s32) reg_tmp.h[0] < 3) {
                                g_p1_hyper_total = 0;
                            }
                        }
                    } else {
                        g_p2_stage_bomb_used = 1;
                        if ((s32) g_p2_bombs_used < 0x63) {
                            g_p2_bombs_used += 1;
                        }
                        reg_a2 = (u8 *)((u8 *)g_player1);
                        reg_a3 = (u8 *)(&g_p2_combo_at_bomb);
                        reg_a4 = (u8 *)((u8 *)g_p2_maximum_value);
                        reg_d0.h[0] = g_p2_combo_timer;
                        if (g_p2_hyper_active != 0) {
                            p2_hyper_end();
                            reg_tmp.h[0] = g_p2_hyper_total;
                            g_p2_hyper_total -= 3;
                            if ((s32) reg_tmp.h[0] < 3) {
                                g_p2_hyper_total = 0;
                            }
                        }
                    }
                    if (reg_d0.h[0] != 0) {
                        *(u16 *)reg_a3 = 1;
                    }
                    if (!(PLAYER(reg_a6)->flags.b[1] & 0x40)) {
                        temp_v0_2 = *(u16 *)reg_a4;
                        if (temp_v0_2 != 0) {
                            *(u16 *)reg_a4 = (u16) (temp_v0_2 - 0x2C);
                            reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xC);
                            *(u16 *)(reg_a4 + 0xC) -= 2;
                            if ((s32) reg_tmp.h[0] < 2) {
                                *(u16 *)reg_a4 = 0U;
                                *(u16 *)(reg_a4 + 0xC) = 0U;
                            }
                            reg_d0.h[0] = *(u16 *)reg_a4;
                            reg_d5.h[0] = reg_d0.h[0];
                            binary_to_bcd();
                            *(u16 *)(reg_a4 + 4) = (u16) reg_d2.h[1];
                            *(u16 *)(reg_a4 + 6) = (u16) reg_d2.h[0];
                            reg_d5.h[0] >>= 1;
                            reg_d0.h[0] = reg_d5.h[0];
                            binary_to_bcd();
                            *(u16 *)(reg_a4 + 8) = (u16) reg_d2.h[1];
                            *(u16 *)(reg_a4 + 0xA) = (u16) reg_d2.h[0];
                            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
                            binary_to_bcd();
                            *(u16 *)(reg_a4 + 0xE) = (u16) reg_d2.h[0];
                        }
                    }
                    bomb_stock_draw_for_task();
                    PLAYER(reg_a6)->flags.b[1] |= 0x40;
                    PLAYER(reg_a6)->flags.b[0] |= 0x40;
                    reg_d2.w = 0;
                    reg_d2.b[0] = *(u8 *)(reg_a5 + 6);
                    reg_d2.h[0] <<= 7;
                    reg_d2.h[0] |= 0x8000;
                    reg_d0.h[0] = PLAYER(reg_a6)->ship_type.h;
                    reg_d2.b[0] |= reg_d0.b[0];
                    *(u16 *)reg_a1 = (u16) reg_d2.h[0];
                    reg_d0.h[0] *= 2;
                    reg_d1.h[0] = reg_d0.h[0];
                    *(u16 *)(reg_a1 + 2) = (u16) PLAYER(reg_a6)->y.h;
                    temp_a0_9 = PLAYER(reg_a6)->x.h;
                    *(u16 *)(reg_a1 + 4) = temp_a0_9;
                    PLAYER(reg_a6)->state.b.invincible = 0xFFU;
                    if (PLAYER(reg_a6)->state.b.laser_mode == 0) {
                        bomb_palette_load_first();
                        PLAYER(reg_a6)->shield_anim_delay.h = 0U;
                        PLAYER(reg_a6)->shield_anim_frame.h = 0x3CU;
                        PLAYER(reg_a6)->move.b.speed += 6;
                        reg_a0 = (u8 *)player_update_table_5;
                    } else {
                        bomb_palette_load_second();
                        PLAYER(reg_a6)->shield_anim_delay.h = 0x101U;
                        PLAYER(reg_a6)->shield_anim_frame.h = 0xCU;
                        PLAYER(reg_a6)->flags.b[0] |= 0x80;
                        temp_a0_10 = (u8 *)(reg_a1);
                        (*(u8 *)((u8 *)(temp_a0_10) + (0))) |= 1;
                        g_laser_bomb_impact_frame = 0;
                        PLAYER(reg_a6)->laser_bomb_recoil.h = 0x2EU;
                        temp_s0 = (u8 *)(reg_a2);
                        if (*(u8 *)(reg_a5 + 6) == 0) {
                            reg_a1 = (u8 *)g_p1_options;
                            reg_a2 = &(*(u8 *)&g_p1_laser_bomb_active);
                            p1_laser_clear();
                        } else {
                            reg_a1 = (u8 *)g_p2_options;
                            reg_a2 = &(*(u8 *)&g_p2_laser_bomb_active);
                            p2_laser_clear();
                        }
                        *(s16 *)(reg_a1 + 0x38) = 0x26;
                        *(s16 *)(reg_a1 + 0x56) = 8;
                        *(s16 *)reg_a2 = 1;
                        reg_a2 = temp_s0;
                        bullet_cancel_begin();
                        reg_a0 = (u8 *)player_update_table_6;
                    }
                    reg_a0 += reg_d1.h[0];
                    reg_d0.h[0] = *(u16 *)reg_a0;
                    reg_a0 += 2;
                    if (((reg_d0.h[0] == 0) || !(PLAYER(reg_a6)->power_style.b[0] & 4)) && (*(u8 *)(reg_a5 + 6) != 0)) {
                        reg_d0.h[0] += 0xC;
                    }
                    if (*(s16 *)reg_a2 < 0) {
                        *(u8 *)(reg_a2 + 0x3F) = (u8) PLAYER(reg_a6)->state.b.invincible;
                        *(u16 *)(reg_a2 + 0x28) = (u16) PLAYER(reg_a6)->shield_anim_frame.h;
                        *(u16 *)(reg_a2 + 0x26) = (u16) PLAYER(reg_a6)->shield_anim_delay.h;
                    }
                } else {
                    goto block_122;
                }
            } else {
                goto block_122;
            }
        } else {
block_122:
            reg_d0.b[0] = PLAYER(reg_a6)->weapon.b.shot_palette;
            if (PLAYER(reg_a6)->flags.b[0] & 1) {
                reg_d0.b[0] = PLAYER(reg_a6)->weapon.b.hyper_palette;
            }
            PLAYER(reg_a6)->who.b.palette = (u8) reg_d0.b[0];
            if (PLAYER(reg_a6)->state.b.laser_mode == 0) {
                if (PLAYER(reg_a6)->input.b.filtered & 0x10) {
                    PLAYER(reg_a6)->fire_lockout.b[1] = 1U;
                    reg_d0.b[0] = PLAYER(reg_a6)->shot_power.b[0];
                    if (PLAYER(reg_a6)->flags.b[0] & 1) {
                        reg_d0.h[0] = 8;
                    }
                    reg_d0.h[0] >>= 1;
                    reg_d0.b[0] &= 6;
                    reg_d0.b[0] += PLAYER(reg_a6)->burst_reset.b.shots;
                    PLAYER(reg_a6)->burst.b.shots = (u8) reg_d0.b[0];
                    reg_tmp.b[0] = PLAYER(reg_a6)->flags.b[0];
                    PLAYER(reg_a6)->flags.b[0] &= 0xF7;
                    if (reg_tmp.b[0] & 8) {
                        PLAYER(reg_a6)->flags.b[1] |= 8;
                        PLAYER(reg_a6)->burst.b.shots = 0U;
                        goto block_135;
                    }
                    reg_tmp.b[0] = PLAYER(reg_a6)->flags.b[1];
                    PLAYER(reg_a6)->flags.b[1] &= 0xF7;
                    if (reg_tmp.b[0] & 8) {
                        PLAYER(reg_a6)->burst.b.wait = 1U;
                    } else {
                        goto block_135;
                    }
                } else {
                    PLAYER(reg_a6)->fire_lockout.b[1] = 0U;
                    PLAYER(reg_a6)->flags.b[1] &= 0xF7;
                    PLAYER(reg_a6)->flags.b[0] &= 0xEF;
                    if (PLAYER(reg_a6)->burst.b.shots != 0) {
                        PLAYER(reg_a6)->burst.b.wait -= 1;
                        if (PLAYER(reg_a6)->burst.b.wait == 0) {
                            PLAYER(reg_a6)->burst.b.shots -= 1;
                            PLAYER(reg_a6)->flags.b[1] |= 8;
                            PLAYER(reg_a6)->flags.b[0] |= 0x10;
block_135:
                            reg_d0.b[0] = PLAYER(reg_a6)->burst_reset.b.wait;
                            if ((PLAYER(reg_a6)->flags.b[0] & 1) || ((PLAYER(reg_a6)->ship_type.h == 0) && (PLAYER(reg_a6)->shot_power.h == 8))) {
                                reg_d0.w = 2;
                            }
                            PLAYER(reg_a6)->burst.b.wait = (u8) reg_d0.b[0];
                            reg_d0.h[0] = PLAYER(reg_a6)->ship_type.h;
                            if (reg_d0.h[0] == 0) {
                                reg_a0 = (u8 *)D_0029E390;
                                reg_tmp.h[1] = ((u16 *)g_p1_weapon_level_data)[0];
                                reg_tmp.h[0] = g_p1_weapon_level_data_lo[0];
                                reg_a2 = (u8 *) reg_tmp.w;
                                if (*(u8 *)(reg_a5 + 6) != 0) {
                                    reg_a0 = (u8 *)D_0029EA50;
                                    reg_tmp.h[1] = ((u16 *)g_p2_weapon_level_data)[0];
                                    reg_tmp.h[0] = g_p2_weapon_level_data_lo[0];
                                    reg_a2 = (u8 *) reg_tmp.w;
                                }
                                reg_d7.h[0] = *(u16 *)reg_a2;
                                if (PLAYER(reg_a6)->flags.b[0] & 1) {
                                    reg_d7.h[0] = 6;
                                }
                                reg_d0.h[0] = PLAYER(reg_a6)->power_style.h;
                                reg_d0.h[0] -= 2;
                                reg_d0.h[0] *= 4;
                                if (PLAYER(reg_a6)->flags.b[0] & 1) {
                                    reg_d0.h[0] += 4;
                                }
                                var_a3 = reg_d0.h[0];
                                reg_a1 = (u8 *)ship0_shot_lists_1;
                                reg_d5.h[0] = var_a3;
                                reg_tmp.h[1] = (var_a3 != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)var_a3 & ~1)) : *(u16 *)reg_a1;
                                reg_tmp.h[0] = (((var_a3 & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((var_a3 & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a1;
                                reg_a1 = (u8 *) reg_tmp.w;
                                reg_d0.h[0] = PLAYER(reg_a6)->shot_power.h;
                                reg_d0.h[0] *= 2;
                                temp_a1_3 = (u8 *)(reg_a6 + 0x20);
                                reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
                                reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                                reg_a1 = (u8 *) reg_tmp.w;
                                if (PLAYER(reg_a6)->power_style.h != 4) {
                                    reg_a0 += 0x2A0;
                                    reg_a4 = reg_a0 + 0x150;
                                    if ((g_two_player_game == 0) && ((s32) reg_d7.h[0] > 3)) {
                                        reg_d7.w = 3;
                                    }
                                    reg_d6.h[0] = reg_d7.h[0];
loop_164:
                                    if ((*(s16 *)reg_a0) < 0) {
                                        reg_a0 += 0x30;
                                        tmp_dec = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec;
                                        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                                            goto loop_164;
                                        }
                                    } else {
                                        player_shot_fire_gun_a();
                                    }
                                    reg_a1 = (u8 *)ship0_shot_lists_2;
                                    reg_tmp.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a1;
                                    reg_tmp.h[0] = (((u16)reg_d5.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d5.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                                    reg_a1 = (u8 *) reg_tmp.w;
                                    reg_d0.h[0] = PLAYER(reg_a6)->shot_power.h;
                                    reg_d0.h[0] *= 2;
                                    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
                                    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                                    reg_a1 = (u8 *) reg_tmp.w;
loop_181:
                                    if ((*(s16 *)reg_a4) < 0) {
                                        reg_a4 += 0x30;
                                        tmp_dec = reg_d6.h[0] - 1; reg_d6.h[0] = tmp_dec;
                                        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                                            goto loop_181;
                                        }
                                        if (PLAYER(reg_a6)->shot_power.h != 8) {
                                            PLAYER(reg_a6)->burst.b.shots = 0U;
                                            PLAYER(reg_a6)->flags.b[1] &= 0xF7;
                                        }
                                        if ((s16) reg_d7.h[0] >= 0) {
                                            goto block_196;
                                        }
                                    } else {
                                        reg_a0 = reg_a4;
                                        player_shot_fire_volley_a_entry();
                                        goto block_196;
                                    }
                                } else {
                                    temp_a3 = (u8 *)(reg_a0 + 0x1B0);
                                    reg_a0 = temp_a3;
                                    reg_d7.h[0] += 2;
                                    if ((g_two_player_game == 0) && ((s32) reg_d7.h[0] > 4)) {
                                        reg_d7.w = 4;
                                    }
loop_191:
                                    temp_a0_11 = (*(s16 *)reg_a0);
                                    if (temp_a0_11 < 0) {
                                        reg_a0 += 0x30;
                                        tmp_dec = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec;
                                        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                                            goto loop_191;
                                        }
                                            if (PLAYER(reg_a6)->shot_power.h != 8) {
                                                PLAYER(reg_a6)->burst.b.shots = 0U;
                                                PLAYER(reg_a6)->flags.b[1] &= 0xF7;
                                            }
                                    } else {
                                        player_shot_fire_volley_a();
block_196:
                                        if (PLAYER(reg_a6)->aux.b.shot_sound_wait == 0) {
                                            PLAYER(reg_a6)->aux.b.shot_sound_wait = 2U;
                                            reg_a0 = (u8 *)sfx_shot_a;
                                            if (PLAYER(reg_a6)->flags.b[0] & 1) {
                                                reg_a0 = (u8 *)sfx_shot_hyper;
                                            }
                                            reg_call_target = (Fn)(reg_a0);
                                            reg_call_target();
                                        }
                                    }
                                }
                            } else {
                                reg_a0 = (u8 *)D_0029E390;
                                reg_tmp.h[1] = ((u16 *)g_p1_weapon_level_data)[0];
                                reg_tmp.h[0] = g_p1_weapon_level_data_lo[0];
                                reg_a2 = (u8 *) reg_tmp.w;
                                if (*(u8 *)(reg_a5 + 6) != 0) {
                                    reg_a0 = (u8 *)D_0029EA50;
                                    reg_tmp.h[1] = ((u16 *)g_p2_weapon_level_data)[0];
                                    reg_tmp.h[0] = g_p2_weapon_level_data_lo[0];
                                    reg_a2 = (u8 *) reg_tmp.w;
                                }
                                reg_d7.h[0] = *(u16 *)reg_a2;
                                if (PLAYER(reg_a6)->flags.b[0] & 1) {
                                    reg_d7.h[0] = 6;
                                }
                                reg_d0.h[0] = PLAYER(reg_a6)->power_style.h;
                                reg_d0.h[0] -= 2;
                                reg_d0.h[0] *= 4;
                                if (PLAYER(reg_a6)->flags.b[0] & 1) {
                                    reg_d0.h[0] += 4;
                                }
                                reg_a1 = (u8 *)ship0_shot_lists_3;
                                reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
                                reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                                reg_a1 = (u8 *) reg_tmp.w;
                                reg_d0.h[0] = PLAYER(reg_a6)->shot_power.h;
                                reg_d0.h[0] *= 2;
                                temp_a1_8 = (u8 *)(reg_a6 + 0x20);
                                reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
                                reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                                reg_a1 = (u8 *) reg_tmp.w;
                                if (PLAYER(reg_a6)->power_style.h != 4) {
                                    reg_a0 += 0x2A0;
                                    reg_d7.h[0] *= 2;
                                    reg_d7.h[0] += 1;
                                    if ((g_two_player_game == 0) && ((s32) reg_d7.h[0] > 7)) {
                                        reg_d7.w = 7;
                                    }
loop_222:
                                    temp_a2_5 = (u8 *)(reg_a0);
                                    if ((*(s16 *)temp_a2_5) < 0) {
                                        reg_a0 = temp_a2_5 + 0x30;
                                        tmp_dec = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec;
                                        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                                            goto loop_222;
                                        }
                                            if (PLAYER(reg_a6)->shot_power.h != 8) {
                                                PLAYER(reg_a6)->burst.b.shots = 0U;
                                                PLAYER(reg_a6)->flags.b[1] &= 0xF7;
                                            }
                                    } else {
                                        reg_a4 = temp_a2_5;
loop_227:
                                        reg_a0 += 0x30;
                                        temp_a0_14 = (*(s16 *)reg_a0);
                                        if (temp_a0_14 < 0) {
                                            tmp_dec = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec;
                                            if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                                                goto loop_227;
                                            }
                                            if (PLAYER(reg_a6)->shot_power.h != 8) {
                                                PLAYER(reg_a6)->burst.b.shots = 0U;
                                                PLAYER(reg_a6)->flags.b[1] &= 0xF7;
                                            }
                                        } else {
                                            player_shot_fire_gun_b();
                                            reg_a0 = reg_a4;
                                            player_shot_fire_volley_b_entry();
                                            goto block_240;
                                        }
                                    }
                                } else {
                                    temp_a3_3 = (u8 *)(reg_a0 + 0x1B0);
                                    reg_a0 = temp_a3_3;
                                    reg_d7.h[0] += 2;
                                    if ((g_two_player_game == 0) && ((s32) reg_d7.h[0] > 4)) {
                                        reg_d7.w = 4;
                                    }
loop_235:
                                    temp_a0_16 = (*(s16 *)reg_a0);
                                    if (temp_a0_16 < 0) {
                                        reg_a0 += 0x30;
                                        tmp_dec = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec;
                                        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                                            goto loop_235;
                                        }
                                            if (PLAYER(reg_a6)->shot_power.h != 8) {
                                                PLAYER(reg_a6)->burst.b.shots = 0U;
                                                PLAYER(reg_a6)->flags.b[1] &= 0xF7;
                                            }
                                    } else {
                                        player_shot_fire_volley_b();
block_240:
                                        if (PLAYER(reg_a6)->aux.b.shot_sound_wait == 0) {
                                            PLAYER(reg_a6)->aux.b.shot_sound_wait = 2U;
                                            reg_a0 = (u8 *)sfx_shot_b;
                                            if (PLAYER(reg_a6)->flags.b[0] & 1) {
                                                reg_a0 = (u8 *)sfx_shot_hyper;
                                            }
                                            reg_call_target = (Fn)(reg_a0);
                                            reg_call_target();
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
block_244:
    reg_a0 = (u8 *)player_ship_sprite_tables;
    reg_d0.h[0] = PLAYER(reg_a6)->ship_type.h;
    reg_d0.h[0] *= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = PLAYER(reg_a6)->roll_frame.h;
    PLAYER(reg_a6)->sprite_hi.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    PLAYER(reg_a6)->sprite_lo.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)((u8 *)player_ship_hitbox_tables);
    reg_d1.w = 0;
    reg_d1.h[0] *= 4;
    reg_tmp.h[1] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    PLAYER(reg_a6)->hit_x_plus.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    PLAYER(reg_a6)->hit_x_minus.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    if ((g_players_hidden == 0) && (g_frame_mod2 == 0) && (g_loop == 0) && (g_stage != 2)) {
        reg_d1.h[1] = PLAYER(reg_a6)->y.h;
        reg_d1.h[0] = PLAYER(reg_a6)->x.h;
        reg_d5.h[0] = 0x1C00;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d5.h[0] = 0x1400;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.w += 0xFE00FE00;
        reg_a0 = (u8 *)((u8 *)player_ship_shadow_tables);
        reg_d0.h[0] = PLAYER(reg_a6)->ship_type.h;
        reg_d0.h[0] *= 2;
        temp_a1_9 = reg_d0.h[0];
        reg_tmp.h[1] = (temp_a1_9 != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)temp_a1_9 & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[0] = (((temp_a1_9 & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((temp_a1_9 & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *) reg_tmp.w;
        reg_d0.h[0] = PLAYER(reg_a6)->roll_frame.h;
        reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d2.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.h[0] = 0x210;
        reg_d4.h[0] = 0x18;
        sprite_draw_with_player_shadows();
    }
    if ((g_game_frame_ran != 0) && (D_0028EC4C == 0) && (g_select_screen_active == 0) && !(g_boss_present_b1 & 1) && (g_true_last_boss == 0) && !(PLAYER(reg_a6)->flags.b[1] & 0x40)) {
        if (*(u8 *)(reg_a5 + 6) == 0) {
            if (g_p1_maximum_anim_delay == 0) {
                p0 = &g_p1_score_pending_as_u8;
                p1 = (s32 *)(p0 - 0x34);
                *p1 = g_p1_maximum_value_digits[0];
                bcd_add((void *)p0, (void *)p1);
                if (g_loop != 0) {
                    bcd_add((void *)p0, (void *)p1);
                }
                return;
            }
        } else if (g_p2_maximum_anim_delay == 0) {
            p0 = &g_p2_score_pending_as_u8;
            p1 = (s32 *)(p0 - 0x30);
            *p1 = g_p2_maximum_value_digits[0];
            bcd_add((void *)p0, (void *)p1);
            if (g_loop != 0) {
                bcd_add((void *)p0, (void *)p1);
            }
        }
    }
    return;
L_else:
    reg_tmp.b[0] = PLAYER(reg_a6)->flags.b[0];
    PLAYER(reg_a6)->flags.b[0] |= 4;
    if (!(reg_tmp.b[0] & 4)) {
        reg_d0.w = 0;
        reg_d7.w = 0x2C;
        reg_a0 = (u8 *)((u8 *)g_bomb_entities);
        do {
            *(u16 *)reg_a0 = reg_d0.h[0];
            reg_a0 += 0x30;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        PLAYER(reg_a6)->flags.h &= 0xFF3F;
        PLAYER(reg_a6)->state.b.invincible = 1U;
        reg_d0.w = 0;
        PLAYER(reg_a6)->burst.h = reg_d0.h[0];
        PLAYER(reg_a6)->option_burst.h = (u16) reg_d0.h[0];
    }
    PLAYER(reg_a6)->flags.b[1] &= 0xEF;
    reg_d7.h[0] = 0xE00;
    if (*(u8 *)(reg_a5 + 6) != 0) {
        reg_d7.h[0] = 0x2A00;
    }
    if (g_players_hidden != 0) {
        reg_d2.h[0] = 0xC00;
        PLAYER(reg_a6)->y.h = (u16) reg_d2.h[0];
        PLAYER(reg_a6)->x.h = (u16) reg_d7.h[0];
    }
    goto block_244;
}

s32 p1_stage_counts_reset();
s32 p2_stage_counts_reset();
s32 side_scroll_reset();
s32 item_spawn();
s32 sfx_player_explosion();
s32 hud_p1_hyper_count_put();
s32 hud_p2_hyper_count_put();
s32 p1_hyper_gauge_check_full();
s32 p2_hyper_gauge_check_full();
s32 p1_hyper_gauge_bonus_add();
s32 p2_hyper_gauge_bonus_add();
s32 vibration_start_pad1();
s32 vibration_start_pad2();
extern u8 D_00255EE0[];
extern u16 g_p2_continued;
extern u16 g_p1_continued;
#ifdef DEATH_LABEL
extern u16 D_006E5C14[];
#else
extern s16 D_0068DEDE[];
#endif

void player_destroyed_begin(void) {
#ifndef DDPDOJ_PC
    s32 p1_maximum_level_show();
    s32 p2_maximum_level_show();
#endif
    u32 tmp;
    u16 t1;
    u16 t2;
    u32 saved1;
    u32 saved2;

    side_scroll_reset();
    if (!(PLAYER(reg_a6)->flags.b[1] & 0x40)) {
        bomb_stock_draw_for_task();
    }
    sfx_player_explosion();
    g_slowdown_loop2_allowed = 1;
    if (*(u8 *)(reg_a5 + 6) == 0) {
        vibration_start_pad1(0xC8, 0x28);
        p1_laser_clear();
        g_p1_missed = 1;
        g_p1_past_first_ship = 1;
        g_p1_stage_misses += 2;
        p1_stage_counts_reset();
        p1_hyper_gauge_bonus_add();
        p1_hyper_gauge_check_full();
        g_p1_maximum_level = 0;
        g_p1_maximum_anim_delay = 8;
        g_p1_maximum_anim_delay_reset = 8;
        g_p1_died_in_hyper = g_p1_hyper_active;
        p1_hyper_end();
        reg_d0.h[0] = g_p1_hyper_total;
        reg_d0.h[0] >>= 2;
        t1 = reg_d0.h[0];
        reg_d0.h[0] = g_p1_hyper_items;
        g_p1_hyper_total = t1;
        if (reg_d0.h[0] != 0) {
            g_p1_hyper_items = 0;
            hud_p1_hyper_count_put();
        }
        reg_d1.h[0] = g_p1_lives;
        if (reg_d1.h[0] == 0) {
            p1_hyper_state_clear();
        }
        PLAYER(reg_a6)->shield_anim_frame.sh = 2;
        saved1 = reg_d1.w;
        p1_maximum_level_show();
        reg_d1.w = saved1;
        reg_a1 = (u8 *) &g_p1_continued;
        reg_a3 = (u8 *) &g_p1_death_count;
    } else {
        vibration_start_pad2(0xC8, 0x28);
        p2_laser_clear();
        g_p2_missed = 1;
        g_p2_past_first_ship = 1;
        g_p2_stage_misses += 2;
        p2_stage_counts_reset();
        p2_hyper_gauge_bonus_add();
        p2_hyper_gauge_check_full();
        g_p2_maximum_level = 0;
        g_p2_maximum_anim_delay = 8;
        g_p2_maximum_anim_delay_reset = 8;
        g_p2_died_in_hyper = g_p2_hyper_active;
        p2_hyper_end();
        reg_d0.h[0] = g_p2_hyper_total;
        reg_d0.h[0] >>= 2;
        t2 = reg_d0.h[0];
        reg_d0.h[0] = g_p2_hyper_items;
        g_p2_hyper_total = t2;
        if (reg_d0.h[0] != 0) {
            g_p2_hyper_items = 0;
            hud_p2_hyper_count_put();
        }
        reg_d1.h[0] = g_p2_lives;
        if (reg_d1.h[0] == 0) {
            p2_hyper_state_clear();
        }
        PLAYER(reg_a6)->shield_anim_frame.sh = 3;
        saved2 = reg_d1.w;
        p2_maximum_level_show();
        reg_d1.w = saved2;
        reg_a1 = (u8 *) &g_p2_continued;
        reg_a3 = (u8 *) &g_p2_death_count;
    }
    if (g_simulation_active != 0) goto next_1;
    reg_d0.w = 4;
    reg_d7.w = 0;
    if (reg_d1.h[0] == 0) goto loop_1;
    reg_d0.w = 0;
    reg_d7.w = 2;
    if (*(u16 *) reg_a1 != 0) goto loop_1;
    goto next_3;
next_1:
#ifdef DEATH_LABEL
    reg_d7.w = 2;
    reg_d0.w = 0;
    if (D_006E5C14[0] != 0) {
        reg_d7.w = D_006E5C14[0];
        reg_d7.w -= 2;
        if ((s32) reg_d7.w < 0) goto next_4;
        goto loop_1;
    }
#else
    reg_d0.w = 4;
    reg_d7.w = 0;
    if (reg_d1.h[0] != 0) goto next_2;
    if (D_0068DEDE[0] != 0x14) goto loop_1;
next_2:
    reg_d0.w = 0;
    reg_d7.w = 2;
#endif
next_3:
    reg_d7.h[0] = *(u16 *) reg_a3;
    *(u16 *) reg_a3 += 1;
    reg_tmp7.h[0] = reg_d7.h[0];
    reg_d7.h[0] -= 1;
    if (reg_tmp7.h[0] == 0) goto next_4;
loop_1:
    item_spawn();
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
next_4:
    PLAYER(reg_a6)->flags.h &= 0x2000;
    PLAYER(reg_a6)->flags.b[1] |= 1;
    reg_tmp.w = (u32) D_00255EE0;
    PLAYER(reg_a6)->hit_x_plus.h = (u16) reg_tmp.h[1];
    PLAYER(reg_a6)->hit_x_minus.h = (u16) reg_tmp.h[0];
    PLAYER(reg_a6)->input.sh = 6;
}

s32 player_slot_request_destroyed();
s32 task_stop_self();

void player_destroyed_update(void) {
    u8 *var_a1;
    u8 *var_a2;
    if (!(PLAYER(reg_a6)->flags.b[1] & 4)) {
        reg_tmp.h[1] = PLAYER(reg_a6)->hit_x_plus.h;
        reg_tmp.h[0] = PLAYER(reg_a6)->hit_x_minus.h;
        reg_a0 = (u8 *)(reg_tmp.w);
        reg_a0 += 4;
        var_a2 = (u8 *)(reg_a6 + 0x14);
        if (*(s16 *)reg_a0 >= 0) {
            reg_tmp.w = (u32)reg_a0;
            PLAYER(reg_a6)->hit_x_plus.h = (u16) reg_tmp.h[1];
            PLAYER(reg_a6)->hit_x_minus.h = (u16) reg_tmp.h[0];
            return;
        }
        PLAYER(reg_a6)->shield_anim_delay.h = 0x20U;
        PLAYER(reg_a6)->flags.b[1] |= 4;
        goto block_4;
    }
block_4:
    PLAYER(reg_a6)->shield_anim_delay.h -= 1;
    if ((s16) PLAYER(reg_a6)->shield_anim_delay.h < 0) {
        if (*(u8 *)(reg_a5 + 6) == 0) {
            reg_a4 = (u8 *)(&g_p1_died_in_hyper);
        } else {
            reg_a4 = (u8 *)(&g_p2_died_in_hyper);
        }
        reg_d0.h[0] = PLAYER(reg_a6)->flags.h;
        reg_d2.w = 0;
        reg_d3.w = 0;
        reg_d0.h[0] &= 0x2000;
        reg_d1.h[0] = PLAYER(reg_a6)->power_style.h;
        var_a1 = (u8 *)(reg_a6 + 0x5A);
        if (reg_d1.h[0] & 2) {
            reg_d2.h[0] = PLAYER(reg_a6)->shot_power.h;
            if (reg_d2.h[0] != 0) {
                reg_d2.h[0] -= 2;
            }
        }
        if (reg_d1.h[0] & 4) {
            reg_d3.h[0] = PLAYER(reg_a6)->laser_power.h;
            if (reg_d3.h[0] != 0) {
                reg_d3.h[0] -= 2;
            }
        }
        reg_d4.b[0] = PLAYER(reg_a6)->bombs.b.capacity;
        if (*(u16 *)reg_a4 == 0) {
            reg_d5.h[0] = PLAYER(reg_a6)->power_style.h;
            reg_a0 = (u8 *)D_0028C608;
            reg_d5.h[0] -= 2;
            reg_d5.b[0] = *(reg_a0 + reg_d5.h[0] + ((reg_d5.h[0] & 1) ? -1 : 1));
            reg_d5.b[0] *= 2;
            if ((s32) reg_d5.b[0] > (s32) reg_d4.b[0]) {
                reg_d4.h[0] += 1;
            }
        }
        reg_a0 = (u8 *)((u32) reg_a6);
        reg_d5.w = 0x30;
        reg_d6.w = 0;
        do {
            *(u16 *)reg_a0 = (s16) reg_d6.h[0];
            reg_a0 += 2;
        } while ((s16)(--reg_d5.h[0]) >= 0);
        PLAYER(reg_a6)->flags.h |= reg_d0.h[0];
        PLAYER(reg_a6)->power_style.h = (u16) reg_d1.h[0];
        PLAYER(reg_a6)->shot_power.h = (u16) reg_d2.h[0];
        PLAYER(reg_a6)->laser_power.h = (u16) reg_d3.h[0];
        PLAYER(reg_a6)->bombs.b.capacity = (u8) reg_d4.b[0];
        PLAYER(reg_a6)->flags.h &= 0x7FFF;
        reg_d0.w = 0;
        reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
        player_slot_request_destroyed();
        task_stop_self();
    }
}

void player_shot_fire(void) {
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    reg_d0.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d0.h[0] += *(u16 *) (reg_a6 + 2);
    *(u16 *) reg_a0 = reg_d0.h[0];
    reg_a0 += 2;
    reg_d0.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d0.h[0] += *(u16 *) (reg_a6 + 4);
    *(u16 *) reg_a0 = reg_d0.h[0];
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    reg_tmp.h[1] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a2 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = *(u16 *) (reg_a6 + 0x42);
    *(u16 *) reg_a0 = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a2 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = ((reg_d0.h[0] + 2) != 0) ? *(u16 *) (reg_a2 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u8 *) (reg_a0 + -2) = *(u8 *) (reg_a6 + 0x57);
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = (u16) *(u16 *) (reg_a6 + 0x44);
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = (u16) *(u16 *) (reg_a6 + 0x5A);
    reg_a0 += 2;
    reg_d0.h[0] = *(u16 *) (reg_a6 + 0x20);
    if (*(u8 *) (reg_a6 + 0x5A) & 4) {
        reg_d0.h[0] += 2;
    }
    *(u16 *) reg_a0 = reg_d0.h[0];
    reg_a0 += 2;
}


void player_shot_fire_gun_a(void) {
    player_shot_fire();
    reg_tmp.h[0] = PLAYER(reg_a6)->gun_index.h;
    PLAYER(reg_a6)->gun_index.h -= 4;
    if ((s32) reg_tmp.h[0] < 4) {
        PLAYER(reg_a6)->gun_index.h = 8U;
    }
}

void player_shot_fire_gun_b(void) {
    player_shot_fire();
    reg_tmp.h[0] = PLAYER(reg_a6)->gun_index.h;
    PLAYER(reg_a6)->gun_index.h -= 4;
    if ((s32) reg_tmp.h[0] < 4) {
        PLAYER(reg_a6)->gun_index.h = 8U;
    }
}


void player_shot_fire_volley_a_entry(void) {
    player_shot_fire_volley_a();
}

void player_shot_fire_volley_a(void) {
    player_shot_fire();
    reg_tmp.h[0] = PLAYER(reg_a6)->gun_index.h;
    PLAYER(reg_a6)->gun_index.h -= 4;
    if ((s32) reg_tmp.h[0] < 4) {
        PLAYER(reg_a6)->gun_index.h = 8U;
    }
    reg_tmp.h[0] = PLAYER(reg_a6)->shot_counter.h;
    PLAYER(reg_a6)->shot_counter.h -= 4;
    if ((s32) reg_tmp.h[0] < 4) {
        PLAYER(reg_a6)->shot_counter.h = 4U;
    }
}


void player_shot_fire_volley_b_entry(void) {
    player_shot_fire_volley_b();
}

void player_shot_fire_volley_b(void) {
    player_shot_fire();
    reg_tmp.h[0] = PLAYER(reg_a6)->gun_index.h;
    PLAYER(reg_a6)->gun_index.h -= 4;
    if ((s32) reg_tmp.h[0] < 4) {
        PLAYER(reg_a6)->gun_index.h = 8U;
    }
    reg_tmp.h[0] = PLAYER(reg_a6)->shot_counter.h;
    PLAYER(reg_a6)->shot_counter.h -= 4;
    if ((s32) reg_tmp.h[0] < 4) {
        PLAYER(reg_a6)->shot_counter.h = 4U;
    }
}

void player_roll_recenter(void) {
    u16 temp_v1;

    reg_d0.h[0] = 4;
    temp_v1 = PLAYER(reg_a6)->roll_frame.h;
    if (temp_v1 != 0) {
        if (((s64) ((s64) temp_v1 << 0x30) >> 0x30) >= 0) {
            reg_d0.h[0] = 0xFFFC;
        }
        PLAYER(reg_a6)->roll_frame.h += reg_d0.h[0];
    }
}

extern s32 g_replay_position;
extern s16 g_player1[56];
#ifndef DDPDOJ_PC
extern u8 D_006C68B6[];
#endif

void p1_draw(u8 arg0) {
    u8 var_a0;

    var_a0 = arg0;
    if ((g_stage == 0) && (var_a0 = g_replay_mode, (var_a0 == 2)) && (g_replay_position == 0)) {
        reg_a6 = (u8 *)((u16 *)D_006C68B6);
        reg_d0.h[0] = PLAYER(reg_a6)->flags.h;
        if ((s16) reg_d0.h[0] < 0) {
            player_draw_plain();
        }
    } else {
        reg_a6 = (u8 *)((u16 *)g_player1);
        reg_d0.h[0] = PLAYER(reg_a6)->flags.h;
        if ((s16) reg_d0.h[0] < 0) {
            player_draw();
        }
    }
}

extern s16 g_player2[56];
#ifndef DDPDOJ_PC
extern u8 D_006C6918[];
#endif

void p2_draw(u8 arg0) {
    u8 var_a0;

    var_a0 = arg0;
    if ((g_stage == 0) && (var_a0 = g_replay_mode, (var_a0 == 2)) && (g_replay_position == 0)) {
        reg_a6 = (u8 *)((u16 *)D_006C6918);
        reg_d0.h[0] = PLAYER(reg_a6)->flags.h;
        if ((s16) reg_d0.h[0] < 0) {
            player_draw_plain();
        }
    } else {
        reg_a6 = (u8 *)((u16 *)g_player2);
        reg_d0.h[0] = PLAYER(reg_a6)->flags.h;
        if ((s16) reg_d0.h[0] < 0) {
            player_draw();
        }
    }
}


void p1_draw_while_entering(void) {
#ifndef DDPDOJ_PC
    extern void player_draw_entering(u16);
#endif
    reg_a6 = (u8 *)((u16 *)g_player1);
    reg_d0.h[0] = PLAYER(reg_a6)->flags.h;
    if ((((s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30) >= 0) && (reg_d0.h[0] & 0xFFFF & 0x100)) {
        ARCADE_REGISTER_CALL(player_draw_entering, reg_d0.h[0]);
    }
}

void p2_draw_while_entering(void) {
#ifndef DDPDOJ_PC
    extern void player_draw_entering(u16);
#endif
    reg_a6 = (u8 *)((u16 *)g_player2);
    reg_d0.h[0] = PLAYER(reg_a6)->flags.h;
    if ((((s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30) >= 0) && (reg_d0.h[0] & 0xFFFF & 0x100)) {
        ARCADE_REGISTER_CALL(player_draw_entering, reg_d0.h[0]);
    }
}

s32 player_draw_unused();
s32 ship_afterimage_update();
s32 sprite_draw_with_players();
extern u16 player_shield_start_sprites[];
extern u16 player_draw_table[];
extern u16 player_shield_palettes[];
extern u16 player_shield_sprite_tables[];
extern u16 player_exhaust_sprite_tables[];
extern u16 player_exhaust_slow_sprite_tables[];
extern u16 D_0028C868[];
extern u16 D_0028C880[];
extern u8 D_0028E30C;

void player_draw(void) {
#ifndef DDPDOJ_PC
    s32 entity_draw_with_players();
#endif
    if (g_players_hidden != 0) return;
    if ((s8)reg_d0.b[0] < 0) goto next_30;
    if (PLAYER(reg_a6)->state.b.invincible == 0) goto next_100;
    if (g_frame_mod2 == 0) goto next_100;
    reg_d1.h[1] = PLAYER(reg_a6)->y.h;
    reg_d1.h[0] = PLAYER(reg_a6)->x.h;
    reg_d1.h[0] += 0x7FFF + 0x7B01;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] += 0x7FFF + 0x7301;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_a0 = (u8 *)(player_shield_start_sprites);
    reg_d2.h[0] = PLAYER(reg_a6)->shield_anim_frame.h;
    reg_d2.h[1] = ((reg_d2.h[0]) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0]) & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = 0xA28;
    reg_d4.w = 0;
    reg_d4.b[0] = PLAYER(reg_a6)->who.b.side;
    reg_a0 = (u8 *)(player_draw_table);
    reg_d4.h[0] *= 2;
    reg_d4.h[0] = ((reg_d4.h[0]) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d4.h[0]) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = PLAYER(reg_a6)->shield_anim_frame.h;
    PLAYER(reg_a6)->shield_anim_frame.h -= 4;
    if ((s32)reg_tmp.h[0] >= 4) goto next_60;
    PLAYER(reg_a6)->shield_anim_frame.h = 0x3C;
    goto next_60;
next_30:
    reg_d1.h[1] = PLAYER(reg_a6)->y.h;
    reg_d1.h[0] = PLAYER(reg_a6)->x.h;
    reg_d1.w += 0xF800FA00;
    reg_d2.h[0] = PLAYER(reg_a6)->ship_type.h;
    reg_a0 = (u8 *)(player_shield_sprite_tables);
    reg_d2.h[0] *= 2;
    reg_tmp.h[1] = ((reg_d2.h[0]) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0]) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d2.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d2.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d2.h[0] = PLAYER(reg_a6)->shield_anim_frame.h;
    reg_d2.h[1] = ((reg_d2.h[0]) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0]) & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = 0x830;
    reg_d4.w = 0;
    reg_d4.b[0] = PLAYER(reg_a6)->who.b.side;
    reg_a0 = (u8 *)(player_shield_palettes);
    reg_d4.h[0] *= 2;
    reg_d4.h[0] = ((reg_d4.h[0]) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d4.h[0]) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.b[0] = PLAYER(reg_a6)->shield_anim_delay.b[1];
    PLAYER(reg_a6)->shield_anim_delay.b[1] -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_60;
    PLAYER(reg_a6)->shield_anim_delay.b[1] = PLAYER(reg_a6)->shield_anim_delay.b[0];
    reg_tmp.h[0] = PLAYER(reg_a6)->shield_anim_frame.h;
    PLAYER(reg_a6)->shield_anim_frame.h -= 4;
    if ((s32)reg_tmp.h[0] >= 4) goto next_60;
    PLAYER(reg_a6)->shield_anim_frame.h = 0xC;
next_60:
    sprite_draw_with_players();
next_100:
    if (D_0028E30C != 0) goto next_110;
    entity_draw_with_players();
next_110:
    ship_afterimage_update();
    if (D_0028E30C == 0) goto next_120;
    reg_a0 = reg_a6;
    player_draw_unused();
next_120:
    if (g_frame_mod2 == 0) return;
    reg_d4.h[0] = 0x1A;
    reg_d7.h[0] = PLAYER(reg_a6)->ship_type.h;
    reg_d7.h[0] *= 2;
    reg_d6.h[0] = PLAYER(reg_a6)->roll_frame.h;
    reg_a0 = (u8 *)(player_exhaust_sprite_tables);
    reg_a1 = (u8 *)(D_0028C868);
    if (!(PLAYER(reg_a6)->input.b.raw & 2)) goto next_200;
    if (PLAYER(reg_a6)->ship_type.h == 0) goto next_200;
    reg_a0 = (u8 *)(player_exhaust_slow_sprite_tables);
    reg_a1 = (u8 *)(D_0028C880);
next_200:
    reg_tmp.h[1] = (((s32)reg_d7.h[0]) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((s32)reg_d7.h[0]) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = ((((reg_d7.h[0] & 0xFFFFU)) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((reg_d7.h[0] & 0xFFFFU)) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_tmp.h[1] = ((reg_d6.h[0]) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d6.h[0]) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = ((((u32)(u16)reg_d6.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u32)(u16)reg_d6.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = PLAYER(reg_a6)->exhaust_frame.h;
    reg_d2.h[1] = ((reg_d0.h[0]) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0]) & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[1] = (((s32)reg_d7.h[0]) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((s32)reg_d7.h[0]) & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[0] = ((((reg_d7.h[0] & 0xFFFFU)) + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(((reg_d7.h[0] & 0xFFFFU)) + 2) & ~1)) : *(u16 *)reg_a1;
    reg_a1 = (u8 *) reg_tmp.w;
    reg_d1.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] += PLAYER(reg_a6)->y.h;
    reg_d3.h[0] = PLAYER(reg_a6)->laser_recoil.h;
    reg_d1.h[0] -= reg_d3.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] += PLAYER(reg_a6)->x.h;
    reg_d3.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = PLAYER(reg_a6)->exhaust_frame.h;
    PLAYER(reg_a6)->exhaust_frame.h -= 4;
    if ((s32)reg_tmp.h[0] >= 4) goto next_210;
    PLAYER(reg_a6)->exhaust_frame.h = 4;
next_210:
    sprite_draw_with_players();
}

extern u16 g_frame_mod4;

void player_draw_plain(void) {
#ifndef DDPDOJ_PC
    s32 entity_draw_with_players();
#endif
    u16 save_a;
    u16 save_c;

    save_a = *(u16 *) (reg_a6 + 0xA);
    save_c = *(u16 *) (reg_a6 + 0xC);
    reg_a0 = (u8 *) ((u16 *)player_ship_sprite_tables);
    reg_d0.h[0] = *(u16 *) (reg_a6 + 0x58);
    reg_d0.h[0] *= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *) (reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *) (reg_a0 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = 0;
    *(u16 *) (reg_a6 + 0xA) = (reg_d0.h[0] != 0) ? *(u16 *) (reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a0;
    *(u16 *) (reg_a6 + 0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *) (reg_a0 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    entity_draw_with_players();
    *(u16 *) (reg_a6 + 0xA) = save_a;
    *(u16 *) (reg_a6 + 0xC) = save_c;
    if (g_frame_mod2 == 0) {
        return;
    }
    reg_d4.h[0] = 0x1A;
    reg_d7.h[0] = *(u16 *) (reg_a6 + 0x58);
    reg_d7.h[0] *= 2;
    reg_d6.h[0] = 0;
    reg_a0 = (u8 *) player_exhaust_sprite_tables;
    reg_a1 = (u8 *) D_0028C868;
    reg_tmp.h[1] = (reg_d7.h[0] != 0) ? *(u16 *) (reg_a0 + ((s16) reg_d7.h[0] & ~1)) : *(u16 *) reg_a0;
    reg_tmp.h[0] = (((u16) reg_d7.h[0] + 2) != 0) ? *(u16 *) (reg_a0 + ((s16) ((u16) reg_d7.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_tmp.h[1] = (reg_d6.h[0] != 0) ? *(u16 *) (reg_a0 + ((s16) reg_d6.h[0] & ~1)) : *(u16 *) reg_a0;
    reg_tmp.h[0] = (((u16) reg_d6.h[0] + 2) != 0) ? *(u16 *) (reg_a0 + ((s16) ((u16) reg_d6.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = (g_frame_mod4 / 2) * 4;
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *) (reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a0;
    reg_d2.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *) (reg_a0 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    reg_tmp.h[1] = (reg_d7.h[0]) ? *(u16 *) (reg_a1 + ((s16) reg_d7.h[0] & ~1)) : *(u16 *) reg_a1;
    reg_tmp.h[0] = (((u16) reg_d7.h[0] + 2) != 0) ? *(u16 *) (reg_a1 + ((s16) ((u16) reg_d7.h[0] + 2) & ~1)) : *(u16 *) reg_a1;
    reg_a1 = (u8 *) reg_tmp.w;
    reg_d1.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] += *(u16 *) (reg_a6 + 2);
    reg_d3.h[0] = 0;
    reg_d1.h[0] -= reg_d3.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] += *(u16 *) (reg_a6 + 4);
    reg_d3.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = (g_frame_mod4 / 2) * 4;
    sprite_draw_with_players();
}

void sprite_draw_with_players_keep(void);

void player_draw_entering() {
#ifndef DDPDOJ_PC
    void entity_draw_with_players(void);
#endif
    if (PLAYER(reg_a6)->flags.b[1] & 4) return;
    if (PLAYER(reg_a6)->input.h != 0) {
        PLAYER(reg_a6)->input.h -= 1;
        entity_draw_with_players();
    }
    reg_tmp.h[1] = PLAYER(reg_a6)->hit_x_plus.h;
    reg_tmp.h[0] = PLAYER(reg_a6)->hit_x_minus.h;
    reg_a2 = (u8 *)reg_tmp.w;
    reg_tmp.h[1] = *(u16 *)(reg_a2 + 0);
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 2);
    reg_a2 = (u8 *)reg_tmp.w;
loop_1:
    reg_d2.h[1] = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_d2.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    if ((s32)reg_d2.w < 0) return;
    if (reg_d2.w == 0) {
        PLAYER(reg_a6)->burst.h = *(u16 *)reg_a2;
        reg_a2 += 2;
        PLAYER(reg_a6)->burst_reset.h = *(u16 *)reg_a2;
        reg_a2 += 2;
        PLAYER(reg_a6)->gun_flash_count.h = *(u16 *)reg_a2;
        reg_a2 += 2;
        goto loop_1;
    }
    if (reg_d2.w == 1) goto block_2;
    if (reg_d2.w == 2) goto block_1;
    reg_d1.h[1] = PLAYER(reg_a6)->y.h;
    reg_d1.h[0] = PLAYER(reg_a6)->x.h;
    reg_tmp.h[1] = PLAYER(reg_a6)->burst.h;
    reg_tmp.h[0] = PLAYER(reg_a6)->burst_reset.h;
    reg_d1.w += reg_tmp.w;
    reg_d3.h[0] = PLAYER(reg_a6)->gun_flash_count.h;
    reg_d4.h[0] = PLAYER(reg_a6)->shield_anim_frame.h;
    sprite_draw_with_players_keep();
    goto loop_1;
block_1:
    PLAYER(reg_a6)->x.h = *(u16 *)reg_a2;
    reg_a2 += 2;
    goto loop_1;
block_2:
    reg_d2.h[1] = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_d2.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_d1.h[0] = PLAYER(reg_a6)->y.h;
    reg_d1.h[0] += 0x7FFF + 0x7C01;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d3.h[0] = PLAYER(reg_a6)->x.h;
    reg_tmp3.h[0] = reg_d3.h[0];
    reg_d3.h[0] -= 0x1000;
    if ((s32)reg_tmp3.h[0] >= 0x1000) {
        reg_d1.h[0] = 0;
        reg_d3.h[0] >>= 6;
        reg_d3.h[0] += 0x400;
        reg_d4.h[0] = PLAYER(reg_a6)->shield_anim_frame.h;
        sprite_draw_with_players_keep();
    }
    reg_d4.h[0] = PLAYER(reg_a6)->x.h;
    reg_d4.h[0] += 0x1000;
    if ((s32)reg_d4.h[0] < 0x3800) {
        reg_d1.h[0] = reg_d4.h[0];
        reg_d3.h[0] = 0x3800;
        reg_d3.h[0] -= reg_d4.h[0];
        reg_d3.h[0] >>= 6;
        reg_d3.h[0] += 0x400;
        reg_d4.h[0] = PLAYER(reg_a6)->shield_anim_frame.h;
        sprite_draw_with_players_keep();
    }
    goto loop_1;
}

/* .sbss (the compiler lays these out in reverse) */
u16 g_laser_bomb_impact_frame;
u16 g_p1_option_level_data[2];
u8 g_p1_weapon_level_data[4];
u16 g_p2_option_level_data[2];
u8 g_p2_weapon_level_data[4];
u16 g_p1_maximum_level __attribute__((aligned(4)));
u16 g_p2_maximum_level __attribute__((aligned(4)));
u16 g_p1_maximum_anim_delay __attribute__((aligned(4)));
u16 g_p1_maximum_anim_delay_reset __attribute__((aligned(4)));
u16 g_p2_maximum_anim_delay __attribute__((aligned(4)));
u16 g_p2_maximum_anim_delay_reset;
s32 g_p1_hyper_ready_sprite;
s32 g_p2_hyper_ready_sprite;
u16 g_p1_hyper_ready_anim_delay __attribute__((aligned(4)));
u16 g_p2_hyper_ready_anim_delay __attribute__((aligned(4)));
s16 g_p1_choosing_power_style __attribute__((aligned(4)));
s16 g_p2_choosing_power_style __attribute__((aligned(4)));
u16 g_p1_missed __attribute__((aligned(4)));
u16 g_p2_missed __attribute__((aligned(4)));
u16 g_p1_past_first_ship __attribute__((aligned(4)));
u16 g_p2_past_first_ship __attribute__((aligned(4)));
u16 g_p1_continued __attribute__((aligned(4)));
u16 g_p2_continued __attribute__((aligned(4)));
u16 g_p1_death_count __attribute__((aligned(4)));
u16 g_p2_death_count __attribute__((aligned(4)));
u16 g_p1_stage_misses __attribute__((aligned(4)));
u16 g_p2_stage_misses __attribute__((aligned(4)));
u16 g_p1_bombs_used __attribute__((aligned(4)));
u16 g_p2_bombs_used __attribute__((aligned(4)));
u16 g_p1_stage_bomb_used __attribute__((aligned(4)));
u16 g_p2_stage_bomb_used __attribute__((aligned(4)));
u16 g_p1_loop2_extend_ok __attribute__((aligned(4)));
u16 g_p2_loop2_extend_ok __attribute__((aligned(4)));
u16 g_p1_laser_bomb_active __attribute__((aligned(4)));
u16 g_p2_laser_bomb_active __attribute__((aligned(4)));
u16 g_hyper_bullet_speed __attribute__((aligned(4)));
u16 g_laser_bomb_hit_position;
s32 g_laser_bomb_hit_entity;
u16 g_laser_bomb_pushback __attribute__((aligned(4)));
u16 g_laser_bomb_hit_flag __attribute__((aligned(4)));
u16 g_player_shot_count __attribute__((aligned(4)));
u16 g_player_laser_count __attribute__((aligned(4)));
u16 g_p1_y_delta __attribute__((aligned(4)));
u16 g_p2_y_delta __attribute__((aligned(4)));
u16 g_p1_laser_stop_y __attribute__((aligned(4)));
u16 g_p2_laser_stop_y __attribute__((aligned(4)));
u16 g_laser_bomb_sizzle __attribute__((aligned(4)));
u16 g_laser_bomb_sizzle2 __attribute__((aligned(4)));
u16 g_bomb_afterglow_timer __attribute__((aligned(4)));
u16 g_player_shots_disabled __attribute__((aligned(4)));
u16 g_players_hidden __attribute__((aligned(4)));
u16 g_players_stage_clear __attribute__((aligned(4)));
u16 g_p1_died_in_hyper __attribute__((aligned(4)));
u16 g_p2_died_in_hyper __attribute__((aligned(4)));

/* .bss (the compiler lays these out in reverse) */
s16 g_player1[56];
s16 g_player2[56];
s16 D_0029F1D0[16];
u8 g_p1_options[80];
s16 D_0029F160[16];
u8 g_p2_options[80];
u8 D_0029EA50[1728];
u8 D_0029E390[1728];
u8 D_0029E330[96];
u8 D_0029E2D0[96];
u8 objects_task_buffer_2[48];
u8 g_p1_laser_entities[1296];
u8 D_0029DD30[96];
u8 D_0029DCD0[96];
u8 objects_task_buffer[48];
u8 g_p2_laser_entities[1296];
u8 D_0029D770[32];
u8 D_0029D750[32];
u8 D_0029D730[32];
u8 D_0029D710[32];
u16 g_bomb_entities_1[1056];
u16 g_bomb_entities[24];
s32 g_p1_afterimage_positions[16];
u8 g_p2_afterimage_positions[64];
s32 g_p1_afterimage_sprites[16];
u8 g_p2_afterimage_sprites[64];
u16 g_p2_maximum_value[16];
