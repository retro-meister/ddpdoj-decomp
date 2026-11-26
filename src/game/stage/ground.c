#include "common.h"
#include "ground.h"
#include "sdk/ps2sdk.h"

void ground_step(void);
void ground_wait_stage_load(void);
void side_scroll_step(void);


void ground_speeds_request(void) {
    g_ground_state.speeds_requested = 1;
    g_ground_state.speed_request[0] = reg_d0.h[0];
    g_ground_state.speed_request[1] = reg_d1.h[0];
}


void side_scroll_reset(void) {
    g_ground_state.side_move = 0;
    g_ground_state.side_by_push = 1;
}


void side_scroll_follow_at_limit(void) {
    if (g_ground_state.side_at_limit != 0) {
        g_ground_state.side_by_push = 0;
    }
}


void scroll_line_release(void) {
    g_ground_state.line_hold_request = 2;
}

s32 layers_reset();
s32 layer_a_scroll();
s32 layer_b_scroll();
s32 ground_objects_reset();
s32 scroll_events_start();
s32 func_001A3250();
extern u8 stage_background_palettes[];
extern u8 stage_data_tables[];
extern s32 D_0028DF1C;
extern s8 g_slowdown_timer_as_s8;
extern s8 g_pause_lock_timer_as_s8;
extern u16 g_scroll_line;
extern u16 g_scroll_line_offset;
extern u16 g_stage_x4;

void ground_start(void) {
    u8 *temp_a0;
    u32 temp_a1;
    u32 temp_a1_2;
    g_pause_lock_timer_as_s8 = 0x3C;
    g_slowdown_timer_as_s8 = 0;
    D_0028DF1C = 0;
    g_scroll_line = *(u16 *)(reg_a5 + 6);
    memset(&g_ground_state, 0, 0x20);
    reg_d0.w = 0;
    reg_d1.w = 0xE;
    reg_a0 = reg_a5 + 4;
    do {
        *(u16 *)reg_a0 = 0U;
        reg_a0 += 2;
        *(u16 *)reg_a0 = 0U;
        reg_a0 += 2;
    } while ((s16)(--reg_d1.h[0]) >= 0);
    layers_reset();
    *(s16 *)(reg_a5 + 0x1C) = 0x20;
    *(s16 *)(reg_a5 + 0x22) = 0x20;
    reg_d0.w = 0;
    reg_d0.h[0] = g_scroll_line;
    reg_d0.h[0] &= 3;
    reg_d0.h[0] *= 8;
    reg_d0.h[0] <<= 6;
    *(u16 *)(reg_a5 + 0x20) = (u16) reg_d0.h[0];
    reg_d1.w = 0;
    reg_d1.h[0] = 0x800;
    layer_b_scroll();
    reg_d1.w = 0;
    reg_d1.h[0] = 0x800;
    layer_a_scroll();
    *(u16 *)(reg_a5 + 0x1E) = 0U;
    temp_a1 = *(u16 *)(reg_a5 + 0x1E);
    reg_a0 = (u8 *)stage_background_palettes;
    g_scroll_line_offset = temp_a1;
    reg_a0 += g_stage_x4;
    temp_a0 = (u8 *)(reg_a0);
    reg_tmp.h[1] = (*(u16 *)((u8 *)(temp_a0) + (0)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(temp_a0) + (2)));
    reg_d1.w = 0x1F;
    reg_d0.w = 0;
    reg_a0 = (u8 *) reg_tmp.w;
    func_001A3250();
    *(u8 *)(reg_a5 + 3) &= 0xFE;
    reg_a1 = (u8 *)stage_data_tables;
    reg_d0.h[0] = g_stage_x4;
    reg_a1 += reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)reg_a1;
    reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
    reg_d0.h[0] = g_scroll_line;
    reg_a1 = (u8 *) reg_tmp.w;
    reg_d0.h[0] >>= 2;
    reg_d1.h[0] = reg_d0.h[0];
    reg_d0.h[0] <<= 5;
    temp_a1_2 = reg_d0.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    reg_d0.h[0] = temp_a1_2 + reg_d1.h[0];
    reg_a1 += reg_d0.h[0];
    *(s16 *)(reg_a5 + 0xE) = 0;
    reg_tmp.w = (u32) reg_a1;
    *(u16 *)(reg_a5 + 0xA) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0xC) = (u16) reg_tmp.h[0];
    scroll_events_start();
    ground_objects_reset();
    side_scroll_reset();
    *(u8 *)(reg_a5 + 2) |= 4;
}

s32 bg_layer_put();

void ground_rows_fill(void) {
    reg_tmp.h[1] = *(u16 *) (reg_a5 + 0xA);
    reg_tmp.h[0] = *(u16 *) (reg_a5 + 0xC);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d1.w = 0;
    reg_d7.w = 0xE;
loop_1:
    reg_d0.w = 0;
    reg_d6.w = 8;
loop_2:
    reg_d4.w = *(u32 *) reg_a0;
    reg_a0 += 4;
    bg_layer_put();
    reg_d0.h[0] += 1;
    if ((s16)(--reg_d6.h[0]) >= 0) {
        goto loop_2;
    }
    reg_d1.h[0] += 1;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_1;
    }
    reg_tmp.w = (u32) reg_a0;
    *(u16 *) (reg_a5 + 0xA) = reg_tmp.h[1];
    *(u16 *) (reg_a5 + 0xC) = reg_tmp.h[0];
    *(u16 *) (reg_a5 + 0xE) = 0xF;
}

s32 func_00225670();
extern u16 g_sprite_last_boss_used;
extern u16 g_sprite_hyper_display_used;
extern u16 g_sprite_hyper_ready_used;
extern u16 g_sprite_maximum_used;
extern u16 g_sprite_stage_clear2_used;
extern u16 g_sprite_stage_clear1_used;
extern u16 g_sprite_ship_select_used;
extern u16 g_sprite_bombs_used;
extern u16 g_sprite_laser_trail_used;
extern u16 g_sprite_sight_used;
extern u16 g_sprite_score_used;
extern u16 g_sprite_warning_used;
extern u16 g_sprite_bullets2_used;
extern u16 g_sprite_bullets_used;
extern u16 g_sprite_sparks_used;
extern u16 g_sprite_players_used;
extern u16 g_sprite_options_used;
extern u16 g_sprite_player_lasers_used;
extern u16 g_sprite_player_shots_used;
extern u16 g_sprite_debris2_used;
extern u16 g_sprite_debris1_used;
extern u16 g_sprite_player_shadows_used;
extern u16 g_sprite_items_used;
extern u16 g_sprite_items_first_used;
extern u16 g_sprite_special_items_used;
extern u16 g_sprite_layer5_used;
extern u16 g_sprite_layer4_used;
extern u16 g_sprite_layer3_used;
extern u16 g_sprite_layer2_used;
extern u16 g_sprite_layer1_used;
extern u8 g_game_mode;
extern u8 g_ground_no_draw;
extern u8 g_simulation_boss_start;
extern u8 g_stage_load_state;
extern u8 g_game_frame_ran;
extern u16 g_attract_demo;
extern s16 g_loaded_stage;
extern u16 g_stage;
extern u8 g_cd_async_state_as_u8;
extern u8 g_cd_async_busy_as_u8;
extern u8 D_0028EC58_as_u8;
extern u8 g_replay_mode;
extern u8 g_simulation_active;

void ground_task(void) {
    u16 save_22;
    u16 save_21;
    u16 save_20;
    u16 save_19;
    u16 save_18;
    u16 save_17;
    u16 save_16;
    u16 save_15;
    u16 save_14;
    u16 save_13;
    u16 save_12;
    u16 save_11;
    u16 save_10;
    u16 save_09;
    u16 save_08;
    u16 save_07;
    u16 save_06;
    u16 save_05;
    u16 save_04;
    u16 save_03;
    u16 save_02;
    u16 save_01;
    u16 save_00;
    s32 more;
    s32 done;
    u16 save_23;
    u16 save_29;
    u16 save_28;
    u16 save_27;
    u16 save_24;
    u16 save_25;
    u16 save_26;
    u8 t;
    u8 *p;

    g_ground_no_draw = 0;
    t = *(u8 *) (reg_a5 + 2);
    p = reg_a5 + 2;
    if (t & 8) {
        ground_step();
        return;
    }
    if (t & 1) {
        *p = t | 1;
        goto next_3;
    }
    *p = t | 1;
    ground_start();
    if (g_simulation_active != 0) {
        goto next_1;
    }
#ifndef DEATH_LABEL
    if (g_attract_demo != 0) {
        goto next_2;
    }
#endif
    if (g_replay_mode != 2) {
        goto next_2;
    }
next_1:
    if (g_loaded_stage != g_stage) {
        func_00225670();
    }
next_2:
    g_stage_load_state = 0;
    g_cd_async_busy_as_u8 = 1;
    g_cd_async_state_as_u8 = 0;
    g_game_frame_ran = 0;
    D_0028EC58_as_u8 = 0;
    return;
next_3:
    t = *(u8 *) (reg_a5 + 2);
    p = reg_a5 + 2;
    if (!(t & 2)) {
        ground_wait_stage_load();
        return;
    }
    *p = t | 8;
    if (g_simulation_active == 0) {
        goto next_4;
    }
    if (g_simulation_boss_start != 0) {
        goto next_5;
    }
next_4:
    if (g_game_mode != 2) {
        return;
    }
next_5:
    more = 1;
    done = 0;
    save_23 = g_sprite_ship_select_used;
    save_29 = g_sprite_stage_clear1_used;
    save_28 = g_sprite_stage_clear2_used;
    save_27 = g_sprite_maximum_used;
    save_24 = g_sprite_hyper_ready_used;
    save_22 = g_sprite_layer1_used;
    save_25 = g_sprite_hyper_display_used;
    save_26 = g_sprite_last_boss_used;
    g_ground_no_draw = 1;
    save_21 = g_sprite_layer2_used;
    save_20 = g_sprite_layer3_used;
    save_19 = g_sprite_layer4_used;
    save_18 = g_sprite_debris1_used;
    save_17 = g_sprite_layer5_used;
    save_16 = g_sprite_debris2_used;
    save_15 = g_sprite_player_shadows_used;
    save_14 = g_sprite_special_items_used;
    save_13 = g_sprite_items_first_used;
    save_12 = g_sprite_items_used;
    save_11 = g_sprite_player_shots_used;
    save_10 = g_sprite_player_lasers_used;
    save_09 = g_sprite_options_used;
    save_08 = g_sprite_players_used;
    save_07 = g_sprite_sparks_used;
    save_06 = g_sprite_bullets_used;
    save_05 = g_sprite_bullets2_used;
    save_04 = g_sprite_warning_used;
    save_03 = g_sprite_score_used;
    save_02 = g_sprite_sight_used;
    save_01 = g_sprite_laser_trail_used;
    save_00 = g_sprite_bombs_used;
loop_6:
    ground_step();
    if (done == 0 && g_stage == 2 && g_scroll_line == 0xE4 && *(u16 *) (reg_a5 + 8) == 1) {
        scroll_line_release();
        done = 1;
    }
    if (g_stage == 4 && g_scroll_line == 0x319) {
        more = 0;
    }
    if (g_stage == 3 && g_scroll_line == MAIN_OR_DEATH_LABEL(0x2C5, 0x2C6)) {
        more = 0;
    }
    if (g_stage == 2 && g_scroll_line == MAIN_OR_DEATH_LABEL(0x19A, 0x199)) {
        more = 0;
    }
    if (g_stage == 1 && g_scroll_line == MAIN_OR_DEATH_LABEL(0x1D5, 0x1D6)) {
        more = 0;
    }
    if (g_stage == 0 && g_scroll_line == 0x1CF) {
        more = 0;
    }
    if (more != 0) {
        goto loop_6;
    }
    g_sprite_ship_select_used = save_23;
    g_sprite_stage_clear1_used = save_29;
    g_sprite_stage_clear2_used = save_28;
    g_sprite_maximum_used = save_27;
    g_sprite_hyper_ready_used = save_24;
    g_sprite_layer1_used = save_22;
    g_sprite_hyper_display_used = save_25;
    g_sprite_last_boss_used = save_26;
    g_sprite_layer2_used = save_21;
    g_sprite_layer3_used = save_20;
    g_sprite_layer4_used = save_19;
    g_sprite_debris1_used = save_18;
    g_sprite_layer5_used = save_17;
    g_sprite_debris2_used = save_16;
    g_sprite_player_shadows_used = save_15;
    g_sprite_special_items_used = save_14;
    g_sprite_items_first_used = save_13;
    g_sprite_items_used = save_12;
    g_sprite_player_shots_used = save_11;
    g_sprite_player_lasers_used = save_10;
    g_sprite_options_used = save_09;
    g_sprite_players_used = save_08;
    g_sprite_sparks_used = save_07;
    g_sprite_bullets_used = save_06;
    g_sprite_bullets2_used = save_05;
    g_sprite_warning_used = save_04;
    g_sprite_score_used = save_03;
    g_sprite_sight_used = save_02;
    g_sprite_laser_trail_used = save_01;
    g_sprite_bombs_used = save_00;
}

s32 ground_objects_run();
s32 scroll_map_loop_step();
s32 scroll_events_run();
void func_00170A50(s32, s32, s32);
extern u8 D_0028E284;
extern u8 D_0028E288;
extern s16 g_p2_hyper_effect_flag_as_s16;
extern s16 g_p1_hyper_effect_flag_as_s16;
extern u16 g_enemies_stopped;
extern u16 g_ground_map_row[];
extern u16 g_ground_map_row_offset[];

void ground_step(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    if (g_enemies_stopped == 0) {
        if (D_0028E288 != 0) {
            if ((D_0028E288 & 0xFF) < 0x3D) {
                D_0028E288 -= 1;
            }
            if (D_0028E288 == 0) {
                g_p1_hyper_effect_flag_as_s16 = 0;
            }
        }
        if (D_0028E284 != 0) {
            if ((D_0028E284 & 0xFF) < 0x3D) {
                D_0028E284 -= 1;
            }
            if (D_0028E284 == 0) {
                g_p2_hyper_effect_flag_as_s16 = 0;
            }
        }
        if (g_ground_state.speeds_requested != 0) {
            g_ground_state.speeds_requested = 0;
            *(u16 *)(reg_a5 + 0x1C) = (u16) g_ground_state.speed_request[0];
            *(u16 *)(reg_a5 + 0x22) = (u16) g_ground_state.speed_request[1];
        }
        side_scroll_step();
        scroll_events_run();
        reg_d0.h[0] = g_ground_state.line_hold_request;
        if (reg_d0.h[0] != 0) {
            g_ground_state.line_hold_request = 0;
            if (reg_d0.h[0] != 1) {
                *(u16 *)(reg_a5 + 8) = 0U;
            } else {
                *(u16 *)(reg_a5 + 8) = 1U;
            }
        }
        reg_d6.h[0] = *(u16 *)(reg_a5 + 0x1C);
        temp_a0 = *(u16 *)(reg_a5 + 0x1E);
        reg_d1.w = 0;
        reg_d5.h[0] = temp_a0;
        reg_d1.h[0] = g_ground_state.side_step;
        reg_d0.w = 0;
        reg_d0.h[0] = reg_d6.h[0];
        reg_d5.h[0] += reg_d6.h[0];
        layer_a_scroll();
        if ((s16)(reg_d5.h[0]) >= 0x200) {
            reg_d5.h[0] -= 0x200;
            if (*(u16 *)(reg_a5 + 8) == 0) {
                g_scroll_line += 1;
            }
        }
        *(u16 *)(reg_a5 + 0x1E) = (u16) reg_d5.h[0];
        temp_a0_2 = reg_d5.h[0];
        g_scroll_line_offset = temp_a0_2;
        reg_d5.h[0] = *(u16 *)(reg_a5 + 0x20);
        reg_d5.h[0] += reg_d6.h[0];
        if ((s16)(reg_d5.h[0]) >= 0x800) {
            reg_d5.h[0] -= 0x800;
            scroll_map_loop_step();
            reg_tmp.h[1] = *(u16 *)(reg_a5 + 0xA);
            reg_tmp.h[0] = *(u16 *)(reg_a5 + 0xC);
            reg_a0 = (u8 *)(reg_tmp.w);
            reg_d1.h[0] = *(u16 *)(reg_a5 + 0xE);
            reg_d6.w = 8;
            reg_d0.w = 0;
            do {
                reg_d4.w = *(u32 *)reg_a0;
                reg_a0 += 4;
                bg_layer_put();
                reg_d0.h[0] += 1;
            } while ((s16)(--reg_d6.h[0]) >= 0);
            reg_tmp.w = (u32)reg_a0;
            *(u16 *)(reg_a5 + 0xA) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a5 + 0xC) = (u16) reg_tmp.h[0];
            reg_d1.h[0] += 1;
            reg_d1.h[0] &= 0x3F;
            *(u16 *)(reg_a5 + 0xE) = (u16) reg_d1.h[0];
        }
        *(u16 *)(reg_a5 + 0x20) = (u16) reg_d5.h[0];
        g_ground_map_row[0] = *(u16 *)(reg_a5 + 0xE);
        g_ground_map_row_offset[0] = *(u16 *)(reg_a5 + 0x20);
        reg_d6.h[0] = *(u16 *)(reg_a5 + 0x22);
        reg_d1.w = 0;
        reg_d1.h[0] = g_ground_state.side_step;
        reg_d0.w = 0;
        reg_d0.h[0] = reg_d6.h[0];
        layer_b_scroll();
    }
    ground_objects_run();
    func_00170A50(0, 0, 0);
}

s32 frame_counters_reset();
s32 func_00138110();
s32 stage_load_step();
s32 stage_map_show();
s32 func_002256B0();
extern u8 D_0028E25C;
extern u8 D_0028E280;
extern s8 D_0028E284_as_s8;
extern s8 D_0028E288_as_s8;
extern u8 D_0028E2BD;
extern u8 D_0028E304;
extern s8 D_0028E368_as_s8;
extern s8 D_0028E378_as_s8;
extern u16 g_p2_hyper_items;
extern u16 g_p1_hyper_items;
extern s16 g_p2_hyper_time_as_s16;
extern s16 g_p1_hyper_time_as_s16;
extern u16 g_p2_score_digits;
extern u16 g_p1_score_digits;
extern u16 g_loop;
extern s8 D_0028EC58;
extern s16 g_player2[];
extern s16 g_player1[];

void ground_wait_stage_load(void) {
    stage_load_step();
    D_0028DF1C += 1;
    if (D_0028EC58 == 0) {
        if ((g_loaded_stage == g_stage) && (D_0028DF1C >= 0)) {
            D_0028EC58 = 1;
            frame_counters_reset();
        }
    } else if (g_game_frame_ran != 0) {
        if (g_attract_demo == 0) {
            D_0028E378_as_s8 = 0;
        }
        *(u8 *)(reg_a5 + 2) |= 2;
        D_0028EC58 = 0;
        if (g_attract_demo == 0) {
            D_0028E368_as_s8 = 1;
        }
        ground_rows_fill();
        func_002256B0();
        func_00138110();
        stage_map_show();
#ifdef DEATH_LABEL
        if (g_loop == 0) {
            D_0028E288_as_s8 = 0;
            D_0028E284_as_s8 = 0;
        }
#else
        if (g_simulation_active == 0) {
            if (g_loop == 0) {
                D_0028E288_as_s8 = 0;
                D_0028E284_as_s8 = 0;
            }
        } else if (D_0028E280 != 5) {
            D_0028E288_as_s8 = 0;
            D_0028E284_as_s8 = 0;
        }
#endif
        if ((g_simulation_active == 0) && (g_loop == 1) && (g_stage == 0)) {
            if (g_player1[0] < 0) {
                if (g_p1_hyper_items != 0) {
                    g_p1_hyper_time_as_s16 = 0;
                    D_0028E288_as_s8 = 0x78;
                }
            } else if ((g_player2[0] < 0) && (g_p2_hyper_items != 0)) {
                g_p2_hyper_time_as_s16 = 0;
                D_0028E284_as_s8 = 0x78;
            }
        }
        if ((g_simulation_active == 0) && (g_replay_mode != 2)) {
            if ((g_p1_score_digits == 0) && (g_player1[0] < 0)) {
                D_0028E25C = g_stage + (g_loop * 5);
                if (D_0028E304 != 0) {
                    D_0028E25C = g_stage + 5;
                }
            } else if ((g_p2_score_digits == 0) && (g_player2[0] < 0)) {
                D_0028E25C = g_stage + (g_loop * 5);
                if (D_0028E304 != 0) {
                    D_0028E25C = g_stage + 5;
                }
            }
            D_0028E2BD = D_0028E25C;
        }
    }
}


void side_scroll_apply(void) {
    g_ground_state.side_at_limit = 0;
    reg_d2.h[0] = 0x800;
    reg_d0.h[0] = g_ground_state.side_move;
    g_ground_state.side_move = 0;
    reg_d0.h[0] += *(u16 *)(reg_a5 + 0x2A);
    reg_d1.h[0] = reg_d0.h[0];
    if ((s16)(reg_d1.h[0]) < 0) {
        reg_d1.h[0] *= 0xFFFF & 0xFFFF;
        reg_d2.h[0] *= 0xFFFF;
    }
    if ((s32) reg_d1.h[0] > 0x800) {
        reg_d0.h[0] = reg_d2.h[0];
        g_ground_state.side_at_limit = 1;
    }
    *(u16 *)(reg_a5 + 0x2A) = (u16) reg_d0.h[0];
    reg_d0.h[0] &= 0xFFC0;
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x28);
    *(u16 *)(reg_a5 + 0x28) = (u16) reg_d0.h[0];
    reg_d2.h[0] = reg_d0.h[0];
    reg_d0.h[0] -= reg_d1.h[0];
}


void side_scroll_edge_check(void) {
    u8 *entry = (void *)reg_a1;

    if (0 <= (s64)*(s16 *)entry) {
        return;
    }

    reg_d2.h[0] = *(u16 *)(entry + 4);
    reg_d3.w = 7;

    if ((s32)reg_d2.h[0] > 0x300) {
        reg_d3.w = 6;
        if ((s32)reg_d2.h[0] < 0x3500) {
            return;
        }
    }

    ((u8 *)((void *)reg_a5))[0x31] |= (u8)(1 << (s8)reg_d3.b[0]);
}

void side_scroll_player_push(void) {
    if (0 <= (s64) *(s16 *) reg_a1) {
        goto block_rts;
    }
    reg_d5.h[0] = *(u16 *) (reg_a1 + 0x5C);
    *(u16 *) (reg_a1 + 0x5C) = 0;
    reg_d5.h[0] = (s16) reg_d5.h[0] >> 2;
    if (reg_d5.h[0] == 0) {
        goto block_rts;
    }
    reg_d4.w = 6;
    reg_d0.h[0] = reg_d5.h[0];
    reg_d5.h[0] = (s16) reg_d5.h[0] >> 1;
    reg_d0.h[0] += reg_d5.h[0];
    if (0 > (s64) (s16) reg_d0.h[0]) {
        goto next_1;
    }
    reg_d4.w = 7;
next_1:
    if ((1U << reg_d4.b[0]) & ((u8 *) ((void *)reg_a5))[0x31]) {
        goto block_rts;
    }
    reg_d1.h[0] = g_ground_state.side_move;
    if (reg_d1.h[0] == 0) {
        goto next_4;
    }
    if (0 > (s64) (s16) reg_d1.h[0]) {
        goto next_2;
    }
    if (!((s32) reg_d1.h[0] < (reg_d0.h[0] & 0xFFFF))) {
        goto block_rts;
    }
    if (0 > (s64) (s16) reg_d0.h[0]) {
        goto next_4;
    }
    goto next_3;
next_2:
    if (!((reg_d0.h[0] & 0xFFFF) < (s32) reg_d1.h[0])) {
        goto block_rts;
    }
    if (!(0 > (s64) (s16) reg_d0.h[0])) {
        goto next_4;
    }
next_3:
    reg_d1.w = 0;
next_4:
    reg_d1.h[0] += reg_d0.h[0];
    g_ground_state.side_move = reg_d1.h[0];
block_rts:;
}

extern u16 g_side_scroll_x_prev[];
extern u16 g_side_scroll_x[];
extern u16 g_side_scroll_pixels[];
extern u16 g_side_scroll_step[];
extern u16 g_player2_as_u16_a[];
extern u16 g_player1_as_u16_a[];

void side_scroll_step(void) {
    if (g_ground_state.side_by_push != 0) {
        goto next_1;
    }
    reg_d0.h[0] = g_player1_as_u16_a[0];
    reg_d1.h[0] = g_player2_as_u16_a[0];
    reg_d1.h[0] ^= reg_d0.h[0];
    if (0 > (s64) (s16) reg_d1.h[0]) {
        goto next_2;
    }
next_1:
    reg_a5[0x31] &= 0x3F;
    reg_a1 = (u8 *) g_player1_as_u16_a;
    side_scroll_edge_check();
    reg_a1 = (u8 *) g_player2_as_u16_a;
    side_scroll_edge_check();
    reg_a1 = (u8 *) g_player1_as_u16_a;
    side_scroll_player_push();
    reg_a1 = (u8 *) g_player2_as_u16_a;
    side_scroll_player_push();
    goto next_4;
next_2:
    reg_a6 = (u8 *) g_player1_as_u16_a;
    if (0 > (s64) (s16) g_player1_as_u16_a[0]) {
        goto next_3;
    }
    reg_a6 = (u8 *) g_player2_as_u16_a;
next_3:
    reg_d0.w = 0;
    reg_d0.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d0.w -= 0x1C00;
    reg_d0.w = (s32) reg_d0.w / 200;
    reg_d0.h[0] <<= 6;
    reg_d0.h[0] -= *(u16 *) (reg_a5 + 0x28);
    g_ground_state.side_move = reg_d0.h[0];
next_4:
    side_scroll_apply();
    g_ground_state.side_step = reg_d0.h[0];
    reg_d1.h[0] = *(u16 *) (reg_a5 + 0x28);
    reg_d1.h[0] >>= 6;
    reg_d2.h[0] = reg_d1.h[0];
    reg_d1.h[0] <<= 6;
    g_side_scroll_x_prev[0] = g_side_scroll_x[0];
    g_side_scroll_x[0] = reg_d1.h[0];
    reg_d0.h[0] = g_side_scroll_pixels[0];
    g_side_scroll_pixels[0] = reg_d2.h[0];
    reg_d2.h[0] -= reg_d0.h[0];
    reg_d2.h[0] <<= 6;
    g_side_scroll_step[0] = reg_d2.h[0];
    g_ground_state.side_total -= reg_d2.h[0];
}

/* .sbss (the compiler lays these out in reverse) */
s32 D_0028DF1C;
