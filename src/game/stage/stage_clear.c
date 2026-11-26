#include "common.h"
#include "task.h"
#include "entity.h"
#include "sdk/ps2sdk.h"
void stage_clear_screen_update(void);

s32 sfx_bonus_count();                            /* extern */
extern u16 D_0028E954;

void stage_clear_delay_a_tick(void) {
    if (D_0028E954 != 0) {
        D_0028E954 -= 1;
        return;
    }
    D_0028E954 = 3;
    sfx_bonus_count();
}

extern u16 D_0028E950;

void stage_clear_delay_b_tick(void) {
    if (D_0028E950 != 0) {
        D_0028E950 -= 1;
        return;
    }
    D_0028E950 = 3;
    sfx_bonus_count();
}

extern u16 D_0028E95C;

void stage_clear_running_check(void) {
    if (D_0028E95C != 0) {
        cond_flag = 1;
        return;
    }
    cond_flag = 0;
}

extern s16 g_game_task_handle;
extern s16 stage_clear_state_clear_state;
extern s16 D_0028E958;
extern u16 D_0028E960;
extern u8 D_002BF410[];
extern u8 D_002BF450[];
extern u8 D_002BF490[];
void stage_clear_state_clear(void) {
    s32 var_a1;
    u8 *temp_a2;
    s32 var_a2;
    u8 *temp_a3;
    u8 *temp_t0;
    s32 var_t1;

    var_a1 = 0;
    do {
        temp_a2 = (u8 *)(D_002BF490 + var_a1);
        (*(s8 *)((u8 *)(temp_a2) + (0))) = 0;
        var_a1 += 8;
        (*(s8 *)((u8 *)(temp_a2) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (7))) = 0;
    } while (var_a1 < 0x60);
    g_game_task_handle = 0;
    var_t1 = 0;
    stage_clear_state_clear_state = 0;
    var_a2 = 0;
    D_0028E950 = 0;
    D_0028E954 = 0;
    D_0028E958 = 0;
    D_0028E95C = 0;
    D_0028E960 = 0;
    do {
        temp_a3 = (u8 *)(D_002BF450 + var_a2);
        temp_t0 = (u8 *)(D_002BF410 + var_a2);
        (*(s16 *)((u8 *)(temp_a3) + (0))) = 0;
        var_t1 += 8;
        (*(s16 *)((u8 *)(temp_t0) + (0))) = 0;
        (*(s16 *)((u8 *)(temp_a3) + (2))) = 0;
        var_a2 += 0x10;
        (*(s16 *)((u8 *)(temp_t0) + (2))) = 0;
        (*(s16 *)((u8 *)(temp_a3) + (4))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (4))) = 0;
        (*(s16 *)((u8 *)(temp_a3) + (6))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (6))) = 0;
        (*(s16 *)((u8 *)(temp_a3) + (8))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (8))) = 0;
        (*(s16 *)((u8 *)(temp_a3) + (0xA))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (0xA))) = 0;
        (*(s16 *)((u8 *)(temp_a3) + (0xC))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (0xC))) = 0;
        (*(s16 *)((u8 *)(temp_a3) + (0xE))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (0xE))) = 0;
    } while (var_t1 < 0x20);
}

s32 game_ground_task_stop();
s32 fades_reset();
s32 stage_doors_clear();
s32 stage_clear_colors_reset();
s32 chain_states_clear();
s32 vibration_stop_all(s32, s32);
s32 stage_map_hide();
extern u16 g_players_hidden;
extern u8 g_stage_jump_state;
extern u8 D_0028E961;
extern u8 g_stage_clear_screen_shown;
extern u8 g_replay_buffer_state;
extern s16 g_bullet_limit_raised_1[];
extern s16 g_bullet_limit_raised_2[];
extern u16 g_bullet_limit_raised_3[];
extern u16 g_bullets_clear_request[];

#ifdef DEATH_LABEL
extern u16 g_p2_lives;
extern u16 g_p1_lives;
extern u16 death_D_00290434;
extern u16 death_D_00290438;
#endif

void stage_clear_task_begin(void) {
    *(s8 *)(reg_a5 + 3) = 1;
    *(s8 *)(reg_a5 + 7) = 0;
    *(s8 *)(reg_a5 + 6) = 4;
    g_stage_jump_state = 0xFF;
    vibration_stop_all(4, 1);
    stage_map_hide();
    fades_reset();
    stage_clear_state_clear();
    chain_states_clear();
    D_0028E961 |= 1;
    D_0028E961 |= 8;
    stage_doors_clear();
    g_bullet_limit_raised_1[0] = 0;
    D_0028E95C = 1;
    g_bullet_limit_raised_2[0] = 0;
    D_0028E958 = 1;
    ((s16 *)g_bullet_limit_raised_3)[0] = 0;
    ((s16 *)g_bullets_clear_request)[0] = 0;
    stage_clear_colors_reset();
    game_ground_task_stop();
    g_stage_clear_screen_shown = 0;
    g_players_hidden = 1;
    g_replay_buffer_state = 2;
#ifdef DEATH_LABEL
    death_D_00290434 = g_p1_lives;
    death_D_00290438 = g_p2_lives;
#endif
}

extern u16 D_0028E960;


void stage_clear_task_finish(void) {
    D_0028E960 = 0;
    D_0028E95C = 0;
    task_stop_self();
}

s32 stage_counts_reset();                            /* extern */
s32 fades_reset();                            /* extern */
s32 p1_next_stage_setup();                            /* extern */
s32 p2_next_stage_setup();                            /* extern */
s32 boss_hit_state_clear();                            /* extern */
#ifdef DEATH_LABEL
extern u8 death_D_00290DC0;
extern u16 g_game_completed;
#endif
extern u16 g_score_panel_intro;
extern u8 g_boss_present;

void next_stage_begin(void) {
    fades_reset();
    task_reset_all();
    stage_clear_state_clear();
    stage_counts_reset();
    boss_hit_state_clear();
    (*(s16 *)&g_boss_present) = 0;
    p1_next_stage_setup();
    p2_next_stage_setup();
    g_score_panel_intro = 0;
#ifdef DEATH_LABEL
    if (death_D_00290DC0 == 0) {
        reg_d0.h[0] = 7;
    } else {
        g_game_completed = 1;
        reg_d0.h[0] = 0xE;
    }
#else
    reg_d0.h[0] = 7;
#endif
    task_start();
}

s32 game_screen_teardown();                            /* extern */

void stage_clear_to_replay(void) {
    game_screen_teardown();
    reg_d0.h[0] = TASK_REPLAY;
    task_start();
    *(s8 *)(reg_a0 + 5) = 1;
}

s32 stage_counts_reset();
s32 game_stage_set();
s32 game_stage_objects_clear();
s32 color_at_brightness();
s32 fade_in_and_release();
s32 fade_release();
s32 fade_is_running();
s32 p1_next_stage_setup();
s32 p2_next_stage_setup();
s32 stage_doors_close_request();
s32 stage_doors_open_request();
s32 stage_doors_open_requested_check();
s32 stage_doors_update();
s32 stage_clear_colors_update();
s32 stage_clear_colors_stop();
s32 stage_clear_colors_apply();
s32 sprite_palette_load();
s32 boss_hit_state_clear();
s32 replay_start_run_end();
extern u16 D_00269840[];
extern u16 g_players_stage_clear;
extern u16 g_player_shots_disabled;
extern u8 g_game_frame_ran;
extern u16 g_p2_score_digits;
extern u16 g_p1_score_digits;
extern u16 g_p2_score_billions;
extern u16 g_p1_score_billions;
extern u32 g_p2_score;
extern u32 g_p1_score;
extern s8 g_stage_load_finished;
extern u8 g_replay_begin_pending;
extern u8 g_replay_mode;
extern u8 g_simulation_active;
extern s16 g_sprite_palette[1024];
#ifdef DEATH_LABEL
s32 fade_out();
s32 music_fade_out();
extern u8 D_00269920[];
extern u8 D_002698B0[];
extern u8 g_game_mode;
extern u16 g_p2_lives;
extern u16 g_p1_lives;
extern u16 death_D_00290434;
extern u16 death_D_00290438;
extern u8 death_D_00290568;
#endif

void stage_clear_task(void) {
    s8 var_a0;
    u16 temp_a0_3;
    u16 temp_v1_3;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_v1;
    u8 temp_v1_2;

    temp_v1 = *(u8 *)(reg_a5 + 3);
    if (temp_v1 == 0) {
        stage_clear_task_begin();
        return;
    }
    if (temp_v1 == 2) {
        stage_clear_task_finish();
        return;
    }
    stage_clear_colors_apply();
    temp_a0 = *(u8 *)(reg_a5 + 7);
    if (temp_a0 == 4) {
        stage_doors_open_requested_check();
        if (cond_flag == 0) {
            *(u8 *)(reg_a5 + 3) = 2U;
        }
    }
    temp_a0_2 = *(u8 *)(reg_a5 + 7);
    if (temp_a0_2 == 3) {
        if ((g_replay_mode == 2) && (g_stage_clear_screen_shown == 0)) {
            replay_start_run_end(temp_a0_2);
            *(u8 *)(reg_a5 + 3) = 2U;
            return;
        }
        printf((const char *)"end sco1up  [%x]\n", (s32)g_p1_score);
        printf((const char *)"end sco1cnt [%x]\n", (s32) g_p1_score_digits);
        printf((const char *)"end sco1oku [%x]\n", (s32) g_p1_score_billions);
        printf((const char *)"end sco2up  [%x]\n", (s32)g_p2_score);
        printf((const char *)"end sco2cnt [%x]\n", (s32) g_p2_score_digits);
        printf((const char *)"end sco2oku [%x]\n", (s32) g_p2_score_billions);
        g_game_frame_ran = 0;
        game_stage_objects_clear();
        *(s8 *)(reg_a5 + 7) = 0x1E;
        goto block_after;
    }
    if (temp_a0_2 == 0x1E) {
        if (g_stage_load_finished != 0) {
            if (g_replay_mode == 1) {
                g_replay_begin_pending = 1;
            }
            g_players_stage_clear = 0;
            D_0028E961 &= 0xFC;
        }
        if (g_game_frame_ran != 0) {
            printf((const char *)"begin sco1up  [%x]\n", (s32)g_p1_score);
            printf((const char *)"begin sco1cnt [%x]\n", (s32) g_p1_score_digits);
            printf((const char *)"begin sco1oku [%x]\n", (s32) g_p1_score_billions);
            printf((const char *)"begin sco2up  [%x]\n", (s32)g_p2_score);
            printf((const char *)"begin sco2cnt [%x]\n", (s32) g_p2_score_digits);
            printf((const char *)"begin sco2oku [%x]\n", (s32) g_p2_score_billions);
            *(s8 *)(reg_a5 + 7) = 4;
        }
    }
block_after:
    if (*(u8 *)(reg_a5 + 7) == 2) {
        if ((g_replay_mode == 2) && (g_stage_clear_screen_shown == 0)) {
            *(u8 *)(reg_a5 + 7) = 3U;
            return;
        }
        reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
        game_stage_set();
        stage_counts_reset();
        D_0028E958 = 0;
        stage_clear_colors_stop();
        g_game_frame_ran = 0;
        stage_doors_open_request();
        boss_hit_state_clear();
        g_players_hidden = 0;
        *(u8 *)(reg_a5 + 7) = 3U;
        goto block_25;
    }
block_25:
    temp_v1_2 = *(u8 *)(reg_a5 + 7);
#ifdef DEATH_LABEL
    if (temp_v1_2 == 0x16) {
        reg_a6 = D_002BF490;
        stage_clear_screen_update();
        if ((g_game_mode == 2) && ((s8)death_D_00290568 == 1)) {
            death_D_00290568 = 0;
            g_p1_lives = death_D_00290434;
            g_p2_lives = death_D_00290438;
            if ((g_simulation_active != 0) || (g_replay_mode == 2)) {
                reg_a0 = (u8 *)D_00269920;
            } else {
                reg_a0 = (u8 *)D_002698B0;
            }
            *(u8 *)(reg_a5 + 7) = 0xB;
            fade_out();
            *(u16 *)(reg_a5 + 8) = reg_d0.h[1];
            *(u16 *)(reg_a5 + 0xA) = reg_d0.h[0];
            reg_d1.w = 0;
            music_fade_out();
        }
        return;
    }
#endif
    if (temp_v1_2 == 0x15) {
        reg_a6 = D_002BF490;
        stage_clear_screen_update();
        return;
    }
    if (temp_v1_2 == 0xB) {
        reg_a6 = D_002BF490;
        stage_clear_screen_update();
        reg_d0.h[1] = *(u16 *)(reg_a5 + 8);
        reg_d0.h[0] = *(u16 *)(reg_a5 + 0xA);
        fade_is_running();
        if (cond_flag == 0) {
            reg_d0.h[1] = *(u16 *)(reg_a5 + 8);
            reg_d0.h[0] = *(u16 *)(reg_a5 + 0xA);
            if (g_simulation_active != 0) {
                stage_clear_to_replay();
                *(u8 *)(reg_a5 + 3) = 2U;
                return;
            }
            fade_release();
            p1_next_stage_setup();
            p2_next_stage_setup();
            (*(s16 *)&g_boss_present) = 0;
            g_player_shots_disabled = 0;
            D_0028E961 &= 0xF7;
            *(u8 *)(reg_a5 + 7) = 2U;
            return;
        }
    }
    if (*(u8 *)(reg_a5 + 7) == 1) {
        reg_a6 = D_002BF490;
        stage_clear_screen_update();
    }
    if (*(u8 *)(reg_a5 + 7) == 0xA) {
        reg_a6 = D_002BF490;
        stage_clear_screen_update();
        *(u8 *)(reg_a5 + 6) -= 1;
        if (*(u8 *)(reg_a5 + 6) == 0) {
            stage_doors_close_request();
            reg_a0 = (u8 *)(D_00269840);
            fade_in_and_release();
            *(u8 *)(reg_a5 + 7) = 1U;
            reg_a0 = (u8 *)(((u16 *)g_sprite_palette));
            reg_a1 = (u8 *)(((u16 *)D_002BF450));
            reg_a0 += 0x5C0;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 = (u8 *)(((u16 *)D_002BF450));
            reg_a1 = (u8 *)(((u16 *)D_002BF410));
            reg_d7.w = 0x1F;
            do {
                temp_a0_3 = *(u16 *)reg_a0;
                reg_d0.h[0] = temp_a0_3;
                reg_a0 += 2;
                reg_d1.h[0] = 0x10;
                color_at_brightness();
                *(u16 *)reg_a1 = reg_d0.h[0];
                reg_a1 += 2;
            } while ((s16)(reg_d7.h[0]--) >= 0);
            reg_a0 = (u8 *)(((u16 *)D_002BF410));
            reg_d0.h[0] = 0x17;
            sprite_palette_load();
        }
    }
    if (*(u8 *)(reg_a5 + 7) == 0) {
        stage_clear_colors_update();
        if (cond_flag == 0) {
            *(u8 *)(reg_a5 + 7) = 0xAU;
        }
    }
    stage_doors_update();
}

extern void sprite_draw_layer1(void);

void tally_digit_draw(void)
{
    reg_d2.h[0] = (s16)reg_d7.h[0] & 0xF;
    reg_d2.w = ((u32 *)(*(s32 *)&reg_a1))[reg_d2.h[0]];
    reg_d1.h[0] -= 0x200;
    sprite_draw_layer1();
}

extern u16 tally_bonus_sprite_draw_table[];
extern u8 D_00269ADE[];
extern u16 tally_bonus_sprite_draw_table_2[];
extern u16 tally_bonus_sprite_draw_table_3[];
extern u16 tally_bonus_sprite_draw_table_4[];

void tally_bonus_sprite_draw(void) {
    if (*(s16 *)(reg_a6 + 0x3E) >= 0) {
        reg_d1.w = 0;
        reg_a0 = (u8 *)(tally_bonus_sprite_draw_table);
        reg_d1.h[0] = *(u16 *)(reg_a6 + 0x3E);
        reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0x4C) += reg_d0.h[0];
        reg_a1 = (u8 *)(tally_bonus_sprite_draw_table_2);
        reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a1;
        *(u16 *)(reg_a6 + 0x4E) += reg_d0.h[0];
        reg_a1 = (u8 *)(tally_bonus_sprite_draw_table_3);
        reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a1;
        *(u16 *)(reg_a6 + 0x50) += reg_d0.h[0];
        reg_a1 = (u8 *)(tally_bonus_sprite_draw_table_4);
        reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a1;
        *(u16 *)(reg_a6 + 0x52) += reg_d0.h[0];
        *(u16 *)(reg_a6 + 0x3E) += 2;
        reg_a0 += reg_d1.w;
        if (D_00269ADE == reg_a0) {
            *(u16 *)(reg_a6 + 0x3E) = 0xFFFF;
        }
    }
}

s32 bg_layer_clear();
s32 replay_save_wanted_check();
s32 tally_frame_animate();
s32 tally_players_draw();
s32 fade_out();
s32 input_get_p1_pressed();
s32 input_get_p2_pressed();
s32 music_fade_out();
s32 score_add_masked();
s32 binary_to_bcd();
s32 stage_load_step();
s32 replay_file_finalize();
extern u16 D_00261F30[];
extern u16 stage_clear_screen_update_table[];
extern u16 stage_clear_screen_update_table_2[];
extern u16 stage_clear_screen_update_table_3[];
extern u16 stage_clear_screen_update_table_4[];
extern u16 stage_clear_screen_update_table_5[];
extern u8 D_002698B0[];
extern u8 D_00269920[];
extern u16 stage_clear_screen_update_table_6[];
extern u16 stage_clear_screen_update_table_7[];
extern u8 D_00269AAE[];
extern u8 g_replay_save_asked;
extern u8 g_stage_clear_wait_timer;
extern s16 g_loaded_stage;
extern u16 g_boss_hits;
extern u8 g_boss_present;
extern u16 g_stage;
extern u16 g_p2_stage_stars_small;
extern u16 g_p2_stage_stars_large;
extern u16 g_p1_stage_stars_small;
extern u16 g_p1_stage_stars_large;
extern s8 g_menu_pad;
extern u16 g_side_scroll_x[];
extern u16 g_side_scroll_step[];
extern s16 g_player2[];
extern s16 g_player1[];

#ifdef DEATH_LABEL
s32 hyper_ready_displays_reset();
s32 p1_hyper_end();
s32 p2_hyper_end();
s32 p1_hyper_state_clear();
s32 p2_hyper_state_clear();
s32 p1_bomb_stock_draw();
s32 p2_bomb_stock_draw();
extern s16 g_player2[];
extern s16 g_player1[];
extern u8 g_game_mode;
extern u8 death_D_00290568;
#endif

void stage_clear_screen_update(void) {
    u32 t1;
    u32 t2;
    u32 t3;
    u32 t4;
    u32 t5;
    u32 t6;
    u32 t7;
    u32 t8;
    u32 t9;
    u32 t10;
    u32 t11;
    u32 t12;
    u32 t13;
    u32 t14;
    u32 t15;
    u8 v1;
    u8 v2;
    u8 *t16;
    u8 *v3;
    u8 *v4;

    v1 = *(u8 *)(reg_a6 + 3);
    v4 = (u8 *)(reg_a6 + 3);
    if (!(v1 & 1)) {
        *(u8 *)(reg_a6 + 3) = (u8) (v1 | 1);
        D_0028E961 |= 2;
        reg_d0.w = 0;
        t5 = reg_d0.h[0];
        g_side_scroll_x[0] = t5;
        g_side_scroll_step[0] = t5;
        reg_a0 = (u8 *)(D_00261F30);
        reg_d0.h[0] = 0x11;
        sprite_palette_load();
        reg_a0 = (u8 *)(stage_clear_screen_update_table);
        reg_d0.h[0] = 0x12;
        sprite_palette_load();
        reg_a0 = (u8 *)(stage_clear_screen_update_table_2);
        reg_d0.h[0] = 0x13;
        sprite_palette_load();
        reg_a0 = (u8 *)(stage_clear_screen_update_table_3);
        reg_d0.h[0] = 0x14;
        sprite_palette_load();
        reg_a0 = (u8 *)(stage_clear_screen_update_table_4);
        reg_d0.h[0] = 0x15;
        sprite_palette_load();
        reg_a0 = (u8 *)(stage_clear_screen_update_table_5);
        reg_d0.h[0] = 0x16;
        sprite_palette_load();
        reg_a0 = (u8 *)(stage_clear_screen_update_table);
        reg_d0.h[0] = 0x10;
        sprite_palette_load();
        return;
    }
    if (!(v1 & 4)) {
        *(u8 *)(reg_a6 + 3) = (u8) (v1 | 4);
        *(u16 *)(reg_a6 + 4) = 1U;
        bg_layer_clear();
        return;
    }
    t8 = *(u16 *)(reg_a6 + 4);
    t16 = (u8 *)(reg_a6 + 4);
    if (t8 != 0) {
        *(u16 *)(reg_a6 + 4) = (u16) (t8 - 1);
        if (*(u16 *)(reg_a6 + 4) != 0) goto next_290;
        {
            reg_a0 = (u8 *)(stage_clear_screen_update_table_6);
            reg_a1 = (u8 *)(reg_a6 + 6);
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_tmp.w = 0xA0000;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)(reg_a6 + 0x3A) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a6 + 0x3C) = (u16) reg_tmp.h[0];
            reg_tmp.w = 0x4D001C00;
            *(u16 *)(reg_a6 + 0x40) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a6 + 0x42) = (u16) reg_tmp.h[0];
            reg_tmp.w = 0x2D001C00;
            *(u16 *)(reg_a6 + 0x44) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a6 + 0x46) = (u16) reg_tmp.h[0];
            reg_tmp.w = 0x0E001C00;
            *(u16 *)(reg_a6 + 0x48) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a6 + 0x4A) = (u16) reg_tmp.h[0];
            *(s16 *)(reg_a6 + 0x4C) = 0;
            *(s16 *)(reg_a6 + 0x4E) = 0;
            *(s16 *)(reg_a6 + 0x50) = 0;
            *(s16 *)(reg_a6 + 0x52) = 0;
            reg_tmp.w = 0xBCF;
            *(u16 *)(reg_a6 + 0x54) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a6 + 0x56) = (u16) reg_tmp.h[0];
            reg_tmp.w = 0xC0F;
            *(u16 *)(reg_a6 + 0x58) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a6 + 0x5A) = (u16) reg_tmp.h[0];
        }
next_290:
        return;
    } else {
        if (*(s16 *)(reg_a6 + 6) >= 0) {
            reg_a0 = (u8 *)(stage_clear_screen_update_table_7);
            reg_d1.w = 0;
            reg_d1.h[0] = *(u16 *)(reg_a6 + 6);
            reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
            *(u16 *)(reg_a6 + 8) -= reg_d0.h[0];
            *(u16 *)(reg_a6 + 0xC) += reg_d0.h[0];
            *(u16 *)(reg_a6 + 6) += 2;
            reg_a0 += reg_d1.w;
            t9 = *(u16 *)(reg_a6 + 0x16);
            if (t9 != 0) {
                *(u16 *)(reg_a6 + 0x16) = (u16) (t9 - reg_d0.h[0]);
                t10 = *(u16 *)(reg_a6 + 0x16);
                v3 = (u8 *)(reg_a6 + 0x16);
                if ((t10 != 0) && ((s16)(t10) < 0)) {
                    reg_d0.h[0] = t10;
                    reg_d0.h[0] *= 0xFFFF;
                    *(u16 *)(reg_a6 + 0x16) = 0U;
                    goto block_15;
                }
            } else {
block_15:
                *(u16 *)(reg_a6 + 0xA) -= reg_d0.h[0];
                v4 = (u8 *)(reg_a6);
                v3 = (u8 *)((void *) (*(u16 *)((u8 *)(v4) + (0xE))));
                (*(u16 *)((u8 *)(v4) + (0xE))) = (u16) (v3 + reg_d0.h[0]);
                if (D_00269AAE == reg_a0) {
                    *(u16 *)(reg_a6 + 6) = 0xFFFF;
                }
            }
            if (g_player1[0] >= 0) {
                *(u16 *)(reg_a6 + 8) = 0U;
                *(u16 *)(reg_a6 + 0xA) = 0U;
            }
            if (g_player2[0] >= 0) {
                *(u16 *)(reg_a6 + 0xC) = 0x40U;
                *(u16 *)(reg_a6 + 0xE) = 0x40U;
            }
            if (*(s16 *)(reg_a6 + 6) < 0) {
                g_boss_present |= 8;
            }
            tally_frame_animate();
            return;
        }
        if (v1 & 2) {
            *(u8 *)(reg_a6 + 3) = (u8) (v1 | 2);
        } else {
            *(u8 *)(reg_a6 + 3) = (u8) (v1 | 2);
            *(u16 *)(reg_a6 + 0x2C) = 0x18U;
            reg_d7.w = 0;
            if (g_player1[0] < 0) {
                reg_d0.h[0] = g_p1_stage_stars_large;
                reg_d0.h[0] += g_p1_stage_stars_small;
                if (reg_d0.h[0] != 0) {
                    reg_d0.h[0] = g_p1_stage_stars_small;
                    reg_d7.w = 1;
                    reg_d5.h[0] = reg_d0.h[0];
                    binary_to_bcd();
                    *(u16 *)(reg_a6 + 0x18) = (u16) reg_d2.h[0];
                    t1 = reg_d5.h[0];
                    reg_d5.h[0] = t1 * 0xA;
                    *(u16 *)(reg_a6 + 0x1A) = (u16) reg_d5.h[0];
                    reg_d0.h[0] = g_p1_stage_stars_large;
                    reg_d5.h[0] = reg_d0.h[0];
                    binary_to_bcd();
                    *(u16 *)(reg_a6 + 0x1C) = (u16) reg_d2.h[0];
                    t3 = reg_d5.h[0];
                    reg_d5.h[0] = t3 * 0x14;
                    *(u16 *)(reg_a6 + 0x1E) = (u16) reg_d5.h[0];
                }
            }
            if (g_player2[0] < 0) {
                reg_d0.h[1] = g_p2_stage_stars_large;
                reg_d0.h[0] = g_p2_stage_stars_small;
                if (reg_d0.w != 0) {
                    reg_d0.h[0] = g_p2_stage_stars_small;
                    reg_d7.w = 1;
                    reg_d5.h[0] = reg_d0.h[0];
                    binary_to_bcd();
                    *(u16 *)(reg_a6 + 0x22) = (u16) reg_d2.h[0];
                    t2 = reg_d5.h[0];
                    reg_d5.h[0] = t2 * 0xA;
                    *(u16 *)(reg_a6 + 0x24) = (u16) reg_d5.h[0];
                    reg_d0.h[0] = g_p2_stage_stars_large;
                    reg_d5.h[0] = reg_d0.h[0];
                    binary_to_bcd();
                    *(u16 *)(reg_a6 + 0x26) = (u16) reg_d2.h[0];
                    t3 = reg_d5.h[0];
                    reg_d5.h[0] = t3 * 0x14;
                    *(u16 *)(reg_a6 + 0x28) = (u16) reg_d5.h[0];
                }
            }
            if (reg_d7.h[0] == 0) {
                *(u16 *)(reg_a6 + 0x2C) = 4U;
            }
        }
        tally_frame_animate();
        tally_players_draw();
        t11 = *(u16 *)(reg_a6 + 0x2C);
        if (t11 != 0) {
            *(u16 *)(reg_a6 + 0x2C) = (u16) (t11 - 1);
            return;
        }
        if (!(*(u8 *)(reg_a6 + 3) & 8)) {
            reg_d7.w = 0;
            reg_d6.h[0] = *(u16 *)(reg_a6 + 0x1A);
            reg_d6.h[0] += *(u16 *)(reg_a6 + 0x1E);
            if (reg_d6.h[0] != 0) {
                input_get_p1_pressed();
                if ((g_replay_mode == 2) && (g_menu_pad == 1)) {
                    input_get_p2_pressed();
                }
                t12 = reg_d0.h[0] & 0x70;
                reg_d0.h[0] = t12;
                if (t12 & 0xFFFF) {
                    reg_d0.h[0] = reg_d6.h[0];
                    binary_to_bcd();
                    reg_d0.w = reg_d2.w;
                    reg_d0.w *= 0x10;
                    *(u16 *)(reg_a6 + 0x1A) = 0U;
                    *(u16 *)(reg_a6 + 0x1E) = 0U;
                    goto block_48;
                }
                reg_d6.w = 0;
                t13 = *(u16 *)(reg_a6 + 0x1A);
                if (t13 != 0) {
                    *(u16 *)(reg_a6 + 0x1A) = (u16) (t13 - 5);
                    reg_d0.w = 0x50;
                    reg_d7.h[0] = 1;
                    reg_d1.w = 0x10;
                    score_add_masked();
                    stage_clear_delay_a_tick();
                    reg_d6.w = 1;
                }
                t14 = *(u16 *)(reg_a6 + 0x1E);
                if (t14 != 0) {
                    *(u16 *)(reg_a6 + 0x1E) = (u16) (t14 - 5);
                    reg_d0.w = 0x50;
block_48:
                    reg_d7.h[0] = 1;
                    reg_d1.w = 0x10;
                    score_add_masked();
                    if (reg_d6.h[0] == 0) {
                        stage_clear_delay_a_tick();
                    }
                }
            }
            reg_d6.h[0] = *(u16 *)(reg_a6 + 0x24);
            reg_d6.h[0] += *(u16 *)(reg_a6 + 0x28);
            if (reg_d6.h[0] != 0) {
                input_get_p2_pressed();
                if ((g_replay_mode == 2) && (g_menu_pad == 0)) {
                    input_get_p1_pressed();
                }
                t15 = reg_d0.h[0] & 0x70;
                reg_d0.h[0] = t15;
                if (t15 & 0xFFFF) {
                    reg_d0.h[0] = reg_d6.h[0];
                    binary_to_bcd();
                    reg_d0.w = reg_d2.w;
                    reg_d0.w *= 0x10;
                    *(u16 *)(reg_a6 + 0x24) = 0U;
                    *(u16 *)(reg_a6 + 0x28) = 0U;
                    goto block_60;
                }
                reg_d6.w = 0;
                t6 = *(u16 *)(reg_a6 + 0x24);
                switch (t6) { case 0: break; default:
                    *(u16 *)(reg_a6 + 0x24) = (u16) (t6 - 5);
                    reg_d0.w = 0x50;
                    reg_d7.h[0] = 1;
                    reg_d1.w = 8;
                    score_add_masked();
                    stage_clear_delay_b_tick();
                    reg_d6.w = 1;
                }
                t7 = *(u16 *)(reg_a6 + 0x28);
                if (t7 != 0) {
                    *(u16 *)(reg_a6 + 0x28) = (u16) (t7 - 5);
                    reg_d0.w = 0x50;
block_60:
                    reg_d7.h[0] = 1;
                    reg_d1.w = 8;
                    score_add_masked();
                    if (reg_d6.h[0] == 0) {
                        stage_clear_delay_b_tick();
                    }
                }
            }
            if (reg_d7.h[0] != 0) goto next_499;
            {
                *(u8 *)(reg_a6 + 3) |= 8;
                reg_d0.h[0] = 8;
                if (g_boss_hits == 0) {
                    reg_d0.h[0] = 1;
                }
                *(u16 *)(reg_a6 + 0x2C) = (u16) reg_d0.h[0];
            }
next_499:
            return;
        } else {
            if (*(s16 *)(reg_a6 + 0x3E) >= 0) {
                tally_bonus_sprite_draw();
                if (*(s16 *)(reg_a6 + 0x3E) < 0) {
                    g_boss_present |= 4;
                }
            }
#ifdef DEATH_LABEL
            if ((g_boss_present & 2) && (v2 = *(u8 *)(reg_a5 + 7), (v2 != 0xB)) && (v2 != 0x15) && (v2 != 0x16)) {
                if (*(u16 *)(reg_a5 + 4) != 0) {
                    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
                    game_stage_set();
                } else {
                    reg_d0.h[0] = 0;
                    game_stage_set();
                }
                if ((*(u16 *)(reg_a5 + 4) == 0) && (g_simulation_active != 1)) {
                    reg_a0 = (u8 *)(((u16 *)D_00269920));
                    *(u8 *)(reg_a5 + 7) = 0x15U;
                    g_stage_clear_screen_shown = 1;
                    hyper_ready_displays_reset();
                    if (g_player1[0] < 0) {
                        p1_hyper_end();
                        p1_hyper_state_clear();
                        p1_bomb_stock_draw();
                    }
                    if (g_player2[0] < 0) {
                        p2_hyper_end();
                        p2_hyper_state_clear();
                        p2_bomb_stock_draw();
                    }
                    reg_d0.h[0] = 0x13;
                    task_start();
                } else if (g_game_mode == 2) {
                    death_D_00290568 = 0;
                    reg_a0 = (u8 *)(((u16 *)D_00269920));
                    *(u8 *)(reg_a5 + 7) = 0x16U;
                    hyper_ready_displays_reset();
                    if (g_player1[0] < 0) {
                        p1_hyper_end();
                        p1_hyper_state_clear();
                        p1_bomb_stock_draw();
                    }
                    if (g_player2[0] < 0) {
                        p2_hyper_end();
                        p2_hyper_state_clear();
                        p2_bomb_stock_draw();
                    }
                    reg_d0.h[0] = 0x13;
                    task_start();
                } else {
                    if ((g_simulation_active != 0) || (g_replay_mode == 2)) {
                        reg_a0 = (u8 *)((u16 *)D_00269920);
                    } else {
                        reg_a0 = (u8 *)((u16 *)D_002698B0);
                    }
                    *(u8 *)(reg_a5 + 7) = 0xBU;
                    fade_out();
                    *(u16 *)(reg_a5 + 8) = (u16) reg_d0.h[1];
                    *(u16 *)(reg_a5 + 0xA) = (u16) reg_d0.h[0];
                }
                reg_d1.w = 0;
                music_fade_out();
            }
#else
            if ((g_boss_present & 2) && (v2 = *(u8 *)(reg_a5 + 7), (v2 != 0xB)) && (v2 != 0x15)) {
                if ((g_simulation_active != 0) || (v2 = g_replay_mode, (v2 == 2))) {
                    if (g_stage_clear_wait_timer != 0) {
                        g_stage_clear_wait_timer -= 1;
                        return;
                    }
                    g_stage_clear_wait_timer = 0;
                    g_replay_save_asked = 0;
                    goto block_77;
                }
block_77:
                t4 = *(u16 *)(reg_a5 + 4);
                if (t4 != 0) {
                    if ((g_simulation_active != 0) || (g_replay_mode == 2)) {
                        g_stage_clear_wait_timer = 0;
                        g_replay_save_asked = 0;
                    } else {
                        reg_d0.h[0] = t4;
                        game_stage_set();
                        if (g_stage_clear_wait_timer != 0) {
                            g_stage_clear_wait_timer -= 1;
                        }
                        if ((g_loaded_stage != g_stage) && (g_stage_clear_wait_timer == 0)) {
                            stage_load_step(g_loaded_stage);
                        }
                    }
                    if ((g_replay_save_asked == 0) && (replay_save_wanted_check() != 0)) {
                        if (replay_file_finalize() != 0) {
                            g_replay_save_asked = 1;
                            goto block_90;
                        }
                    } else {
block_90:
                        if (g_loaded_stage == g_stage) {
                            goto block_91;
                        }
                    }
                } else {
block_91:
                    if ((*(u16 *)(reg_a5 + 4) == 0) && (v2 = 1, (g_simulation_active != 1))) {
                        reg_a0 = (u8 *)(((u16 *)D_00269920));
                        *(u8 *)(reg_a5 + 7) = 0x15U;
                        g_stage_clear_screen_shown = 1;
                        reg_d0.h[0] = 0x13;
                        task_start();
                    } else {
                        if ((g_simulation_active != 0) || (g_replay_mode == 2)) {
                            reg_a0 = (u8 *)((u16 *)D_00269920);
                        } else {
                            reg_a0 = (u8 *)((u16 *)D_002698B0);
                        }
                        *(u8 *)(reg_a5 + 7) = 0xBU;
                        fade_out();
                        *(u16 *)(reg_a5 + 8) = (u16) reg_d0.h[1];
                        *(u16 *)(reg_a5 + 0xA) = (u16) reg_d0.h[0];
                    }
                    reg_d1.w = 0;
                    music_fade_out();
                }
            }
#endif
        }
    }
}

u16 D_00269840[56] = {
    0x0007, 0x7FFF, 0x0000, 0x0440, 0x0004, 0x0005, 0x001F, 0x0003,
    0x7FFF, 0x0000, 0x0480, 0x000B, 0x000C, 0x001F, 0x0003, 0x7FFF,
    0x0000, 0x04C0, 0x0012, 0x0013, 0x001F, 0x0003, 0x7FFF, 0x0000,
    0x0500, 0x0019, 0x001A, 0x001F, 0x0003, 0x7FFF, 0x0000, 0x0540,
    0x0020, 0x0021, 0x001F, 0x0003, 0x7FFF, 0x0000, 0x0580, 0x0027,
    0x0028, 0x001F, 0x0003, 0x7FFF, 0x0000, 0x0700, 0x002E, 0x002F,
    0x001F, 0x0003, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u8 D_002698B0[112] = {
    0x08, 0x00, 0x00, 0x00, 0xC0, 0x05, 0x03, 0x00, 0x04, 0x00, 0x1F, 0x00, 0x03, 0x00, 0x00, 0x00,
    0x80, 0x04, 0x09, 0x00, 0x0A, 0x00, 0x1F, 0x00, 0x03, 0x00, 0x00, 0x00, 0xC0, 0x04, 0x0F, 0x00,
    0x10, 0x00, 0x1F, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x05, 0x15, 0x00, 0x16, 0x00, 0x1F, 0x00,
    0x03, 0x00, 0x00, 0x00, 0x40, 0x05, 0x1B, 0x00, 0x1C, 0x00, 0x1F, 0x00, 0x03, 0x00, 0x00, 0x00,
    0x80, 0x05, 0x21, 0x00, 0x22, 0x00, 0x1F, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x04, 0x27, 0x00,
    0x28, 0x00, 0x1F, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x07, 0x2D, 0x00, 0x2E, 0x00, 0x1F, 0x00,
    0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 D_00269920[240] = {
    0x13, 0x00, 0x00, 0x00, 0xC0, 0x05, 0x03, 0x00, 0x04, 0x00, 0x1F, 0x00, 0x03, 0x00, 0x00, 0x00,
    0x80, 0x04, 0x09, 0x00, 0x0A, 0x00, 0x1F, 0x00, 0x03, 0x00, 0x00, 0x00, 0xC0, 0x04, 0x0F, 0x00,
    0x10, 0x00, 0x1F, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x05, 0x15, 0x00, 0x16, 0x00, 0x1F, 0x00,
    0x03, 0x00, 0x00, 0x00, 0x40, 0x05, 0x1B, 0x00, 0x1C, 0x00, 0x1F, 0x00, 0x03, 0x00, 0x00, 0x00,
    0x80, 0x05, 0x21, 0x00, 0x22, 0x00, 0x1F, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x04, 0x27, 0x00,
    0x28, 0x00, 0x1F, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x07, 0x2D, 0x00, 0x2E, 0x00, 0x1F, 0x00,
    0x03, 0x00, 0x00, 0x00, 0xC0, 0x01, 0x33, 0x00, 0x34, 0x00, 0x1F, 0x00, 0x03, 0x00, 0x00, 0x00,
    0x00, 0x02, 0x39, 0x00, 0x3A, 0x00, 0x1F, 0x00, 0x03, 0x00, 0x00, 0x00, 0x40, 0x02, 0x3F, 0x00,
    0x40, 0x00, 0x1F, 0x00, 0x03, 0x00, 0x10, 0x00, 0xA0, 0x00, 0x45, 0x00, 0x46, 0x00, 0x0F, 0x00,
    0x03, 0x00, 0x10, 0x00, 0xC0, 0x00, 0x4B, 0x00, 0x4C, 0x00, 0x0F, 0x00, 0x03, 0x00, 0x10, 0x00,
    0xE0, 0x00, 0x51, 0x00, 0x52, 0x00, 0x0F, 0x00, 0x03, 0x00, 0x10, 0x00, 0x00, 0x01, 0x57, 0x00,
    0x58, 0x00, 0x0F, 0x00, 0x03, 0x00, 0x10, 0x00, 0x20, 0x01, 0x5D, 0x00, 0x5E, 0x00, 0x0F, 0x00,
    0x03, 0x00, 0x10, 0x00, 0x40, 0x01, 0x63, 0x00, 0x64, 0x00, 0x0F, 0x00, 0x03, 0x00, 0x10, 0x00,
    0x60, 0x01, 0x69, 0x00, 0x6A, 0x00, 0x0F, 0x00, 0x03, 0x00, 0x10, 0x00, 0x00, 0x00, 0x6F, 0x00,
    0x70, 0x00, 0x0F, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u16 stage_clear_screen_update_table_6[16] = {
    0x0000, 0x0000, 0x0000, 0x0040, 0x0040, 0x0101, 0x0101, 0xC090,
    0x1180, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 tally_players_draw_table[24] = {
    0x152B, 0x0000, 0x152C, 0x0000, 0x152D, 0x0000, 0x152E, 0x0000,
    0x152F, 0x0000, 0x1530, 0x0000, 0x1531, 0x0000, 0x1532, 0x0000,
    0x1533, 0x0000, 0x1534, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 stage_clear_screen_update_table_7[40] = {
    0x0080, 0x0080, 0x0080, 0x0080, 0x0080, 0x0080, 0x0080, 0x0080,
    0x0080, 0x0080, 0x0080, 0x0080, 0x0100, 0x0100, 0x0100, 0x0100,
    0x0100, 0x0100, 0x0100, 0x0100, 0x0100, 0x0100, 0x0200, 0x0200,
    0x0200, 0x0200, 0x0200, 0x0200, 0x0200, 0x0200, 0x0200, 0x0200,
    0x0080, 0x0040, 0x0040, 0x0000, 0xFFC0, 0x0000, 0x0000, 0x0040,
};

u16 tally_bonus_sprite_draw_table[24] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0040, 0x0040, 0x0040, 0x0040, 0x0080, 0x0080,
    0x0080, 0x0100, 0x0100, 0x0000, 0xFFC0, 0x0000, 0x0000, 0x0040,
};

u16 tally_bonus_sprite_draw_table_2[24] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0040, 0x0040, 0x0040, 0x0080, 0x0080, 0x0080,
    0x00C0, 0x0100, 0x0100, 0x0000, 0xFFC0, 0x0000, 0x0000, 0x0080,
};

u16 tally_bonus_sprite_draw_table_3[24] = {
    0x0040, 0x0040, 0x0040, 0x0040, 0x0080, 0x0080, 0x0080, 0x0100,
    0x0100, 0x0000, 0xFFC0, 0x0000, 0x0000, 0x0040, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 tally_bonus_sprite_draw_table_4[24] = {
    0x0040, 0x0040, 0x0040, 0x0040, 0x0080, 0x0080, 0x0080, 0x0100,
    0x0100, 0x0000, 0xFFC0, 0x0000, 0x0000, 0x0040, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

/* .sbss (the compiler lays these out in reverse) */
#ifdef DEATH_LABEL
u16 death_D_00290438 __attribute__((aligned(4)));
u16 death_D_00290434 __attribute__((aligned(4)));
#endif

#ifdef DDPDOJ_PC
#include "pc_data_alias.h"

PC_DATA_ALIAS(D_00269AAE, stage_clear_screen_update_table_7, 0x4e);
PC_DATA_ALIAS(D_00269ADE, tally_bonus_sprite_draw_table, 0x2e);
#endif
