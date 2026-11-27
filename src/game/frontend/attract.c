#include "common.h"
#include "task.h"
#include "black_label.h"
#include "sdk/ps2sdk.h"
#include "pad.h"

void attract_step_begin(void);
void attract_start_button_check(void);
void attract_prompt_draw(void);
void attract_prompt_clear(void);
void attract_prompt_press_start(void);
void attract_prompt_insert_coin(void);
void attract_prompt_by_credits(void);
void attract_prompt_coins_missing(void);
void attract_prompt_by_coins(void);
void attract_prompt_one_more_coin(void);
void attract_side_prompts_draw(void);
void attract_side_prompt_p1(void);
void attract_side_prompt_p2(void);
void attract_side_press_start_p1(void);
void attract_side_press_start_p2(void);
void attract_side_two_lines_print(void);
void attract_side_insert_coin(void);
void attract_side_coins_p1(void);
void attract_side_coins_p2(void);
void attract_side_insert_coins(void);
void attract_side_coins_missing(void);
void attract_side_one_coin_p1(void);
void attract_side_one_coin_p2(void);
void attract_side_insert_2_coins(void);
void attract_side_one_more_coin(void);

extern u16 g_attract_step;

void attract_step_set() {
    reg_a5[2] = 0;
    g_attract_step = reg_d0.h[0];
}

#ifndef DDPDOJ_PC
typedef void (*Fn)();
#endif

s32 bg_layer_clear();
s32 p1_credits_get();
s32 p2_credits_get();
s32 credit_status_draw();
s32 attract_demo_state_clear();
s32 sfx_coin();
s32 sound_stop_effects();
s32 menu_settings_restore();
extern u8 text_palette_0[];
extern void (*attract_step_routines[])();
extern s8 D_0028DF84;
extern u8 g_stage_load_state;
extern u8 g_setting_coin_mode;
extern u16 g_attract_demo;
extern u16 D_0028E7B8;
extern s8 g_cd_async_state;
extern u8 g_replay_buffer_state;
extern u8 g_replay_mode;
extern u8 g_simulation_active;

void attract_task(void) {
    void text_layer_clear(void);
    void fades_reset(void);
    void text_palette_load(void);
    void replay_header_clear(void);
#ifndef DEATH_LABEL
    u32 t;
#endif

    if (*(u8 *)(reg_a5 + 3) == 0) {
        attract_step_begin();
        return;
    }
#ifndef DEATH_LABEL
    reg_d0.h[0] = g_attract_step;
    if (g_attract_demo != 0) goto next_1;
    if (g_stage_load_state != 0) goto block_3;
    goto next_2;
next_1:
    if (g_cd_async_state != 0) goto next_3;
next_2:
    if (reg_d0.h[0] == 14) goto block_2;
    if (reg_d0.h[0] == 3) goto block_2;
    if (reg_d0.h[0] == 13) goto block_2;
    if (reg_d0.h[0] == 17) goto block_2;
    if (reg_d0.h[0] == 18) goto block_2;
    if (reg_d0.h[0] == 15) goto block_3;
    if (reg_d0.h[0] == 16) goto block_3;
    if (reg_d0.h[0] == 19) goto block_3;
    if (g_setting_coin_mode != 0x12) goto next_3;
    if (g_stage_load_state != 0) goto next_3;
    if (g_pad_trigger[2] & 0x800) goto block_1;
next_3:
    p2_credits_get();
    reg_d0.h[0] += reg_d1.h[0];
    if (reg_d0.h[0] != 0) goto block_1;
    p1_credits_get();
    reg_d0.h[0] += reg_d1.h[0];
    if (reg_d0.h[0] == 0) goto block_2;
block_1:
    D_0028DF84 = 1;
    task_reset_all();
    fades_reset();
    attract_demo_state_clear();
    if (g_attract_demo == 0) goto next_4;
    g_attract_demo = 0;
    replay_header_clear();
    g_simulation_active = 0;
    g_replay_mode = 0;
    g_replay_buffer_state = 0;
    sound_stop_effects();
    sfx_coin();
    menu_settings_restore();
next_4:
    if (g_attract_step != 0xC) goto next_5;
    sound_stop_effects();
next_5:
    reg_d0.w = 0;
    reg_a0 = (u8 *)text_palette_0;
    text_palette_load();
    text_layer_clear();
    bg_layer_clear();
    reg_d0.h[0] = TASK_ATTRACT;
    task_start();
    *(s16 *)(reg_a0 + 4) = 3;
    return;
block_2:
    if (g_attract_step == 0xD) goto block_3;
    if (reg_d0.h[0] == 0x11) goto block_3;
    if (reg_d0.h[0] == 0x12) goto block_3;
    D_0028E7B8 += 1;
    reg_d0.h[0] = D_0028E7B8;
    t = reg_d0.h[0] & 0x10;
    reg_d0.h[0] = t;
    if (!(t & 0xFFFF)) goto next_6;
    attract_prompt_draw();
    goto next_7;
next_6:
    attract_prompt_clear();
next_7:
    credit_status_draw();
block_3:
#endif
    reg_d0.h[0] = g_attract_step;
    attract_step_routines[reg_d0.h[0]]();
}

s32 screen_clear_unused();                            /* extern */
s32 slowdown_reset();                            /* extern */
extern u8 D_0028E7B4;

void attract_step_begin(void) {
    *(s8 *)(reg_a5 + 3) = 1;
    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
    attract_step_set();
    D_0028E7B4 = 0;
    D_0028E7B8 = 0;
    screen_clear_unused();
    slowdown_reset();
}

s32 settings_notice_update_with_fade_in();                            /* extern */
extern u16 g_p2_continue_count;
extern u16 g_p1_continue_count;

void attract_step_settings_notice(void) {
    void text_layer_clear(void);
    void settings_notice_begin(void);
    if (*(u8 *)(reg_a5 + 2) == 0) {
        *(u8 *)(reg_a5 + 2) = 1U;
        text_layer_clear();
        settings_notice_begin();
    }
    settings_notice_update_with_fade_in();
    if (cond_flag == 0) {
        g_p1_continue_count = 1;
        g_p2_continue_count = 1;
        reg_d0.h[0] = 5;
        D_0028DF84 = 0;
        attract_step_set();
    }
}

s32 ranking_screen_time_reset();
s32 ranking_screen_begin();
s32 ranking_screen_update();
s32 stage_load_step();
s32 disc_notice_begin();
s32 disc_notice_end();
extern u8 g_ranking_opened_from_menu;
extern u8 g_setting_start_round;
extern u8 g_slowdown_timer;
extern u8 g_replay_file_finalized;
extern u8 g_stage_jump_state;
extern s16 g_loaded_stage;
extern u16 g_stage;
extern s8 g_cd_async_busy;

void attract_step_stage_preload(void) {
    void text_layer_clear(void);
    void text_palette_load(void);
    void slowdown_init(void);
    if (*(u8 *)(reg_a5 + 2) == 0) {
        *(u8 *)(reg_a5 + 2) = 1U;
        text_layer_clear();
        reg_d0.w = 0;
        reg_a0 = text_palette_0;
        text_palette_load();
        g_setting_start_round = 0;
        slowdown_init();
        g_slowdown_timer = 0;
        g_ranking_opened_from_menu = 0;
        ranking_screen_begin();
        g_replay_file_finalized = 0;
        g_stage_jump_state = 0xFF;
        D_0028DF84 = 0;
        g_cd_async_busy = 1;
        g_stage_load_state = 0;
        g_cd_async_state = 0;
        disc_notice_begin();
    }
    if (*(u8 *)(reg_a5 + 2) == 1) {
        g_stage = 0;
        stage_load_step();
        if (g_loaded_stage == g_stage) {
            *(u8 *)(reg_a5 + 2) = 2U;
            disc_notice_end();
            ranking_screen_time_reset();
        }
    }
    ranking_screen_update();
    if (cond_flag == 0) {
        reg_d0.h[0] = 0xC;
        attract_step_set();
    }
}

#ifndef DEATH_LABEL
s32 settings_notice_update_with_fade_in();
s32 settings_notice_update_timed();
s32 music_stop();
s32 fade_reset();
s32 boot_scratch_clear();
s32 stage_map_reset();
extern u8 g_p2_stage_start_timer;
extern u8 g_p1_stage_start_timer;
extern u8 g_game_mode;
extern u8 g_no_enemy_bullets;
extern u8 g_splash_visible;

void attract_step_settings_notice_timed(void) {
    void text_layer_clear(void);
    void fades_reset(void);
    void settings_notice_begin(void);
    void settings_notice_draw_static(void);
    if (reg_a5[2] == 0) {
        reg_a5[2] = 1U;
        text_layer_clear();
        fades_reset();
        settings_notice_begin();
        music_stop();
        g_replay_file_finalized = 0;
        g_stage_jump_state = 0xFF;
        g_splash_visible = 0;
        fade_reset();
        stage_map_reset();
        boot_scratch_clear();
        g_stage_load_state = 0;
        g_cd_async_busy = 1;
        g_cd_async_state = 0;
        disc_notice_begin();
    }
    if (reg_a5[2] == 1) {
#ifdef DDPDOJ_BONUS_FEATURES
        extern u16 g_attract_demo_stage;
#endif
        g_stage = GAME_RULE(0, g_attract_demo_stage);
        stage_load_step();
        if (g_loaded_stage == g_stage) {
            reg_a5[2] = 2U;
            disc_notice_end();
        }
    }
    if (g_setting_coin_mode != 0x12) {
        settings_notice_draw_static();
        if (g_stage_load_state == 0) {
            attract_start_button_check();
        }
    } else {
        if (D_0028DF84 != 0) {
            settings_notice_update_timed();
        } else {
            settings_notice_update_with_fade_in();
        }
        switch (cond_flag) { case 0: goto block_set; }
        if (g_stage_load_state == 0) {
            attract_start_button_check();
        }
        return;
    block_set:
        g_p1_continue_count = 1;
        g_p2_continue_count = 1;
        reg_d0.h[0] = 5;
        g_p1_stage_start_timer = 0;
        g_p2_stage_start_timer = 0;
        g_stage_jump_state = 0;
        g_game_mode = 0;
        g_no_enemy_bullets = 0;
        D_0028DF84 = 0;
        attract_step_set();
    }
}
#endif

#ifdef DEATH_LABEL
s32 music_stop();
s32 fade_reset();
s32 stage_map_reset();
extern u8 g_splash_visible;
extern s8 g_cd_async_busy;
extern s8 g_menu_task_phase;

void attract_step_death_label_notice(void) {
    void text_layer_clear(void);
    void fades_reset(void);
    void text_palette_load(void);
    if (reg_a5[2] == 0) {
        reg_a5[2] = 1U;
        bg_layer_clear();
        text_layer_clear();
        reg_d0.w = 0;
        reg_a0 = text_palette_0;
        text_palette_load();
        fades_reset();
        music_stop();
        g_replay_file_finalized = 0;
        g_stage_jump_state = 0xFF;
        g_splash_visible = 0;
        fade_reset();
        stage_map_reset();
        g_stage_load_state = 0;
        g_cd_async_busy = 1;
        g_cd_async_state = 0;
        disc_notice_begin();
    }
    if (reg_a5[2] == 1) {
        g_stage = 0;
        stage_load_step();
        if (g_loaded_stage == g_stage) {
            reg_a5[2] = 2U;
            disc_notice_end();
        }
    }
    if (g_stage_load_state == 0) {
        g_menu_task_phase = 0;
        reg_d0.h[0] = 0xF;
        attract_step_set();
    }
}
#endif

void fade_start_in(void);
void menu_task_update(void);
s32 clock_read(u8 *);
void save_snapshot_take(void);
extern u8 g_session_stage_reached;
extern u8 g_p2_stage_start_timer;
extern u8 g_p1_stage_start_timer;
extern u8 g_pad_input_locked;
extern u8 g_replay_save_asked;
extern u8 g_stage_clear_wait_timer;
extern u8 g_session_date[8];
extern u8 g_session_date_1;
extern u8 g_session_date_2;
extern u8 g_session_date_3;
extern u8 g_session_date_4;
extern u8 g_session_date_5;
extern s8 g_session_date_6;
extern s8 g_session_date_7;
extern u16 g_unlocked_options_shown;
extern u16 g_unlocked_options;
extern u8 g_game_frame_ran;
extern s8 g_bomb_panel_seen;
extern s8 g_menu_exit_code;
extern s32 g_menu_alpha_b;

void attract_step_menu(void) {
    void text_layer_clear(void);
    void fades_reset(void);
    void settings_notice_begin(void);
    void settings_notice_draw_static(void);
    void slowdown_init(void);
    if (*(u8 *)(reg_a5 + 2) == 0) {
        *(u8 *)(reg_a5 + 2) = 1;
        fades_reset();
        settings_notice_begin();
        slowdown_init();
        g_slowdown_timer = 0;
        g_p1_stage_start_timer = 0;
        g_p2_stage_start_timer = 0;
        g_pad_input_locked = 0;
        g_stage_clear_wait_timer = 0;
        g_replay_save_asked = 0;
        g_replay_file_finalized = 0;
        text_layer_clear();
#ifdef DEATH_LABEL
        save_snapshot_take();
#else
        if (D_0028DF84 != 0) {
            save_snapshot_take();
        }
#endif
    }
    if (g_menu_alpha_b == 0) {
        settings_notice_draw_static();
    }
    menu_task_update();
    if (g_menu_exit_code >= 10) {
        if (g_menu_exit_code == 10) {
            D_0028DF84 = 1;
            reg_d0.h[0] = 3;
            attract_step_set();
        } else if (g_menu_exit_code == 30) {
            D_0028DF84 = 0;
            reg_d0.h[0] = 0x10;
            g_game_frame_ran = 0;
            g_bomb_panel_seen = 0;
            attract_step_set();
        } else if (g_menu_exit_code == 40) {
#ifdef DEATH_LABEL
            (*(u8 *)g_session_date) = 0;
            g_session_date_1 = 0;
            g_session_date_2 = 0;
            g_session_date_3 = 0;
            g_session_date_4 = 0;
            g_session_date_5 = 0;
            g_session_date_6 = 0;
            g_session_date_7 = 0;
            reg_a0 = &(*(u8 *)g_session_date);
            if (clock_read(reg_a0) != 0) {
                sceGsSyncV(0);
                if (clock_read(reg_a0) != 0) {
                    (*(u8 *)g_session_date) = 0;
                    g_session_date_1 = 0;
                    g_session_date_2 = 0;
                    g_session_date_3 = 0;
                    g_session_date_4 = 0;
                }
            }
            printf((const char *)"--date [%d][%d][%d][%d][%d]\n", (*(u8 *)g_session_date), g_session_date_1, g_session_date_2, g_session_date_3, g_session_date_4);
#endif
            D_0028DF84 = 0;
            reg_d0.h[0] = 0x13;
            g_game_frame_ran = 0;
            g_bomb_panel_seen = 0;
            attract_step_set();
        } else {
            g_p1_continue_count = 9;
            g_p2_continue_count = 9;
            g_unlocked_options_shown = g_unlocked_options;
            g_session_stage_reached = 0;
            (*(u8 *)g_session_date) = 0;
            g_session_date_1 = 0;
            g_session_date_2 = 0;
            g_session_date_3 = 0;
            g_session_date_4 = 0;
            g_session_date_5 = 0;
            g_session_date_6 = 0;
            g_session_date_7 = 0;
            reg_a0 = &(*(u8 *)g_session_date);
            if (clock_read(reg_a0) != 0) {
                sceGsSyncV(0);
                if (clock_read(reg_a0) != 0) {
                    (*(u8 *)g_session_date) = 0;
                    g_session_date_1 = 0;
                    g_session_date_2 = 0;
                    g_session_date_3 = 0;
                    g_session_date_4 = 0;
                }
            }
            printf((const char *)"--date [%d][%d][%d][%d][%d]\n", (*(u8 *)g_session_date), g_session_date_1, g_session_date_2, g_session_date_3, g_session_date_4);
            reg_d0.h[0] = 0xE;
            attract_step_set();
        }
        g_menu_exit_code = 0;
        fade_start_in();
    }
}

void attract_step_unused_4(void) {

}

s32 attract_demo_state_clear();                            /* extern */
s32 attract_demo_begin();                            /* extern */
s32 attract_demo_start();                            /* extern */
s32 sound_stop_effects();                            /* extern */
s32 stage_map_reset();                            /* extern */
extern u8 g_default_text_palette[];

void attract_step_demo_start(void) {
    void text_layer_clear(void);
    void fades_reset(void);
    void text_palette_load(void);
    if (*(u8 *)(reg_a5 + 2) == 0) {
        *(u8 *)(reg_a5 + 2) = 1U;
        attract_demo_begin();
        text_layer_clear();
        *(s16 *)(reg_a5 + 4) = 0;
        reg_a0 = (u8 *)((s32 *)g_default_text_palette);
        reg_d0.w = 0;
        text_palette_load();
    }
    attract_demo_start();
    if (cond_flag == 0) {
        printf((const char *)"demo end\n");
        task_reset_all();
        fades_reset();
        attract_demo_state_clear();
        stage_map_reset();
        text_layer_clear();
        reg_d0.h[0] = TASK_ATTRACT;
        task_start();
        (*(s16 *)((u8 *)((s32 *)reg_a0) + (4))) = 2;
        sound_stop_effects();
    }
}

void attract_step_unused_6(void) {

}

void attract_step_unused_7(void) {

}

void attract_step_unused_8(void) {

}

s32 splash_begin();                            /* extern */
s32 splash_update();                            /* extern */
extern u8 g_splash_visible;

void attract_step_splash(void) {
    if (*(u8 *)(reg_a5 + 2) == 0) {
        *(u8 *)(reg_a5 + 2) = 1U;
        splash_begin();
    }
    splash_update();
    if (cond_flag == 0) {
        reg_d0.h[0] = 1;
        g_splash_visible = 0;
        if (g_setting_coin_mode == 0x12) {
            reg_d0.h[0] = 3;
        }
        attract_step_set();
    }
}

void attract_step_unused_10(void) {

}

void attract_step_unused_11(void) {

}

s32 logo_screen_begin();                            /* extern */
s32 logo_screen_update();                            /* extern */

void attract_step_logo(void) {
    if (*(u8 *)(reg_a5 + 2) == 0) {
        *(u8 *)(reg_a5 + 2) = 1U;
        logo_screen_begin();
    }
    logo_screen_update();
    if (cond_flag == 0) {
        reg_d0.h[0] = 9;
        attract_step_set();
    }
}

s32 layers_reset();
s32 text_layer_print_wide();
extern u8 g_default_text_palette[];
extern u8 attract_step_caution_text_table[];

void attract_step_caution_text() {
    void text_layer_clear(void);
    void text_palette_load(void);
    u16 temp_v1;
    u16 temp_v1_2;

    if (*(u8 *)(reg_a5 + 2) == 0) {
        D_0028DF84 = 0;
        *(u8 *)(reg_a5 + 2) = 1U;
        text_layer_clear();
        reg_d0.w = 0;
        reg_a0 = g_default_text_palette;
        text_palette_load();
        *(u16 *)(reg_a5 + 6) = 0U;
        *(u16 *)(reg_a5 + 8) = 0xB8U;
        *(u16 *)(reg_a5 + 0xA) = 1U;
        *(u16 *)(reg_a5 + 4) = 0x12CU;
        layers_reset();
        return;
    }
    if ((*(u16 *)(reg_a5 + 6) != 0x1C0) && ((temp_v1 = *(u16 *)(reg_a5 + 0xA), (temp_v1 == 0)) || (*(u16 *)(reg_a5 + 0xA) = (u16) (temp_v1 - 1), (*(u16 *)(reg_a5 + 0xA) == 0)))) {
        reg_a0 = attract_step_caution_text_table;
        reg_a0 += *(u16 *)(reg_a5 + 6);
#ifdef DDPDOJ_BONUS_FEATURES
        if (g_black_label_active && *(u16 *)(reg_a5 + 6) == 13 * 32) {
            reg_a0 = (u8 *)"    2002.10.07.BLACK VER    ";
        }
#endif
        reg_d0.h[0] = *(u16 *)(reg_a5 + 8);
        reg_d1.h[0] = 0;
        reg_d2.h[0] = 0;
        text_layer_print_wide();
        *(u16 *)(reg_a5 + 8) -= 0xC;
        *(u16 *)(reg_a5 + 6) += 0x20;
    }
    temp_v1_2 = *(u16 *)(reg_a5 + 4);
    if (temp_v1_2 != 0) {
        *(u16 *)(reg_a5 + 4) = (u16) (temp_v1_2 - 1);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 4);
        if (*(u16 *)(reg_a5 + 4) == 0) {
            reg_d0.h[0] = 2;
            attract_step_set();
            text_layer_clear();
        }
    }
}

extern u8 D_0028E7B4;

void attract_step_ship_select(void) {
    task_reset_all();
    reg_d0.h[0] = TASK_SHIP_SELECT;
    task_start();
    *(u8 *)(reg_a0 + 5) = (u8) D_0028E7B4;
}

extern u8 D_0028DE40[];
extern u8 D_0028DE44[];
extern u8 attract_step_game_start_table[];
extern u8 g_game_mode;
extern s8 g_menu_pad;
extern u8 g_replay_mode;
extern u8 g_sim_rules_page_a[];
extern s16 D_0068DECA[];
extern s16 D_0068DECC[];
extern s16 D_0068DECE[];
extern s16 D_0068DED0[];
extern s16 D_0068DED2[];
extern u8 g_sim_rules_page_b[];
extern s16 D_0068DEDA[];
extern s16 g_sim_rules_loaded_kind[];
extern s16 D_0068DEDE[];
extern s16 D_0068DEE0[];
extern u8 D_0068DEF0[];
extern s16 D_0068DEF2[];
extern s16 D_0068DEF4[];
extern s16 D_0068DEF6[];
extern s16 D_0068DEF8[];
extern s16 D_0068DEFA[];
extern s16 D_0068DEFC[];
extern s16 D_0068DEFE[];
extern s16 D_0068DF00[];
extern s16 D_0068DF02[];
extern s16 D_0068DF04[];
extern s16 D_006E5BE2[];
extern s16 D_006E5BE4[];
extern s16 D_006E5BE6[];
extern s16 D_006E5BE8[];
extern s16 D_006E5BEA_as_s16_a[];
extern s16 D_006E5BEC_as_s16_a[];
extern s16 D_006E5BEE_as_s16_a[];
extern u16 D_006E5BF0[];
extern u16 D_006E5BF2[];
extern u16 D_006E5BF4[];
extern u16 D_006E5BF6[];
extern s16 D_006E5BF8_as_s16_a[];
extern s16 D_006E5BFA_as_s16_a[];
extern u16 D_006E5BFC[];
extern s16 D_006E5BFE_as_s16_a[];
extern s16 D_006E5C00_as_s16_a[];
extern u16 D_006E5C02[];
extern s16 D_006E5C04_as_s16_a[];
extern u16 D_006E5C06[];
extern u8 D_006E5C08[];
extern s16 D_006E5C0A_as_s16_a[];
extern s16 D_006E5C0C_as_s16_a[];
extern u16 D_006E5C0E[];
extern u16 D_006E5C10[];
extern u16 D_006E5C12[];
extern u16 D_006E5C14[];

void attract_step_game_start(void) {
    void text_layer_clear(void);
    void text_palette_load(void);
    void replay_header_clear(void);
    s32 a;
    s32 b;

    g_game_mode = 0;
    task_reset_all();
    text_layer_clear();
    reg_d0.w = 0;
    reg_a0 = (u8 *)g_default_text_palette;
    text_palette_load();
    replay_header_clear();
    a = D_0068DEDA[0];
    b = g_sim_rules_loaded_kind[0];
    if (g_menu_pad == 0) {
        D_006E5BE2[0] = D_0028DE40[a];
        D_006E5BE4[0] = D_0028DE44[b];
    } else {
        D_006E5BE6[0] = D_0028DE40[a];
        D_006E5BE8[0] = D_0028DE44[b];
    }
    D_006E5C04_as_s16_a[0] = 0;
    D_006E5BEA_as_s16_a[0] = ((s16 *)g_sim_rules_page_b)[0];
    D_006E5BEC_as_s16_a[0] = D_0068DF02[0] / 5;
    D_006E5BFE_as_s16_a[0] = D_0068DF00[0];
    ((s16 *)D_006E5BFC)[0] = D_0068DEFE[0];
    ((s16 *)D_006E5BF4)[0] = D_0068DEF6[0];
    ((s16 *)D_006E5BF6)[0] = D_0068DEF8[0];
    D_006E5BF8_as_s16_a[0] = ((s16 *)D_0068DEF0)[0];
    D_006E5BFA_as_s16_a[0] = D_0068DEF2[0];
    D_006E5C00_as_s16_a[0] = D_0068DEF4[0];
    ((s16 *)D_006E5C02)[0] = D_0068DF04[0];
    ((s16 *)D_006E5C06)[0] = D_0068DEDE[0];
    ((s16 *)D_006E5C08)[0] = D_0068DEE0[0];
    D_006E5C0A_as_s16_a[0] = D_0068DEFA[0];
    D_006E5C0C_as_s16_a[0] = D_0068DEFC[0];
    ((s16 *)D_006E5C0E)[0] = ((s16 *)g_sim_rules_page_a)[0];
    ((s16 *)D_006E5C10)[0] = D_0068DECA[0];
    ((s16 *)D_006E5C12)[0] = D_0068DECC[0];
    D_006E5BEE_as_s16_a[0] = D_0068DF02[0] % 5;
    ((s16 *)D_006E5BF0)[0] = attract_step_game_start_table[D_0068DECE[0]];
    ((s16 *)D_006E5BF2)[0] = attract_step_game_start_table[D_0068DED0[0]];
    ((s16 *)D_006E5C14)[0] = D_0068DED2[0];
    reg_d0.h[0] = TASK_REPLAY;
    task_start();
    if (g_replay_mode == 2) {
        *(s8 *)(reg_a0 + 5) = 3;
        return;
    }
    *(s8 *)(reg_a0 + 5) = 0;
}

#ifdef DEATH_LABEL
extern u8 D_0028E7B4;
extern u8 death_D_00290DC0;
#endif

void attract_step_mode2_start(void) {
    void text_layer_clear(void);
    void text_palette_load(void);
    g_game_mode = 2;
#ifdef DEATH_LABEL
    death_D_00290DC0 = 0;
#endif
    task_reset_all();
    text_layer_clear();
    reg_d0.w = 0;
    reg_a0 = (u8 *)((s32 *)g_default_text_palette);
    text_palette_load();
    reg_d0.h[0] = MAIN_OR_DEATH_LABEL(0x15, 9);
    task_start();
#ifdef DEATH_LABEL
    *((u8 *)((s32 *)reg_a0) + 5) = D_0028E7B4;
#endif
}

s32 mc_autoload_update();
s32 mc_startup_load_begin();
s32 save_block_to_settings();
extern u8 g_mc_startup_flags;
extern s32 g_mc_operation_done;
extern s32 D_006A0E40[];

void attract_step_card_load(void) {
    u8 temp_a0;
    u8 *temp_a1;

    temp_a1 = (u8 *)(reg_a5 + 2);
    temp_a0 = *(u8 *)(reg_a5 + 2);
    switch (temp_a0) {                              /* irregular */
    case 0:
        g_mc_operation_done = 0;
        *(u8 *)(reg_a5 + 2) = 1U;
        break;
    case 1:
        mc_startup_load_begin(temp_a0, temp_a1);
        if (g_mc_operation_done != 0) {
            g_mc_operation_done = 0;
            printf((const char *)"-----[%d]---\n", g_mc_startup_flags);
            if (g_mc_startup_flags & 0xC) {
                *(u8 *)(reg_a5 + 2) = 2U;
                break;
            }
            *(u8 *)(reg_a5 + 2) = 3U;
            break;
        }
        break;
    case 2:
        mc_autoload_update(temp_a0, temp_a1);
        if (g_mc_operation_done != 0) {
            *(u8 *)(reg_a5 + 2) = 3U;
            if (D_006A0E40[0] != 0) {
                save_block_to_settings(3);
            }
            g_mc_operation_done = 0;
            break;
        }
        break;
    case 3:
        reg_d0.h[0] = MAIN_OR_DEATH_LABEL(0xD, 0x3);
        attract_step_set();
        break;
    }
}

s32 music_stop();
s32 menu_notice_update();
s32 autosave_update();
s32 unlock_notice_reset();
extern s32 g_menu_notice_step;
extern s32 g_autosave_unread_flag;
extern s32 g_autosave_step;

void attract_step_autosave(void) {
    void text_layer_clear(void);
    u8 temp_a0;

    temp_a0 = *(u8 *)(reg_a5 + 2);
    switch (temp_a0) {                              /* irregular */
    case 0:
        text_layer_clear();
        bg_layer_clear();
        music_stop();
        *(u8 *)(reg_a5 + 2) = 1U;
        g_autosave_step = 0;
        g_menu_notice_step = 0;
        menu_settings_restore();
        break;
    case 1:
        if (menu_notice_update(temp_a0) != 0) {
            *(u8 *)(reg_a5 + 2) = 2U;
            break;
        }
        break;
    case 2:
        if (autosave_update(temp_a0) != 0) {
            *(u8 *)(reg_a5 + 2) = 3U;
            g_autosave_unread_flag = 0;
            break;
        }
        break;
    case 3:
        if (unlock_notice_reset(temp_a0) != 0) {
            reg_d0.h[0] = MAIN_OR_DEATH_LABEL(2, 3);
            attract_step_set();
        }
        break;
    }
}

#ifndef DEATH_LABEL
s32 sfx_confirm();                            /* extern */
extern u8 g_credit_display_last_coins[];
extern s8 g_menu_task_phase;

void attract_start_button_check(void) {
    if (g_pad_trigger[2] & 0x800) {
        if (g_setting_coin_mode == 0x12) {
            g_menu_task_phase = 0;
            reg_d0.h[0] = 0xF;
            attract_step_set();
            sfx_confirm();
            return;
        }
        if (g_credit_display_last_coins[0] != 0) {
            g_menu_task_phase = 0;
            reg_d0.h[0] = 0xF;
            attract_step_set();
        }
    }
}
#endif

s32 p1_credit_spend_one();
s32 p2_credit_spend_one();
void start_buttons_take_credits(void) {
    D_0028E7B4 = 0;
    if (g_pad_trigger[0] & 0x20) {
        p1_credit_spend_one();
        if (cond_flag == 0) {
            D_0028E7B4 |= 1;
        }
    }
    if (g_pad_trigger[1] & 0x20) {
        p2_credit_spend_one();
        if ((cond_flag == 0) && ((g_setting_start_round == 0) || (D_0028E7B4 == 0))) {
            D_0028E7B4 |= 2;
        }
    }    if (D_0028E7B4 != 0) { return; }
}

#ifndef DEATH_LABEL
extern u8 g_setting_chute_type;

void attract_prompt_draw(void) {
    reg_d0.b[0] = g_setting_chute_type;
    if (reg_d0.b[0] == 1) {
        attract_side_prompts_draw();
        return;
    }
    p1_credits_get();
    if (reg_d0.h[0] != 0) {
        attract_prompt_press_start();
        return;
    }
    reg_d0.b[0] = g_setting_coin_mode;
    if (reg_d0.b[0] == 0x12) {
        attract_prompt_press_start();
        return;
    }
    if (reg_d0.b[0] == 0x11) {
        attract_prompt_by_coins();
        return;
    }
    if ((s8)(reg_d0.b[0]) >= 9) {
        attract_prompt_by_credits();
        return;
    }
    attract_prompt_insert_coin();
}
#endif

#ifndef DEATH_LABEL
s32 text_layer_print();
extern u8 attract_text_blank[];

void attract_prompt_clear(void) {
    reg_a0 = attract_text_blank;
    reg_d0.h[0] = 0;
    reg_d1.h[0] = 0x13;
    reg_d2.h[0] = 0;
    text_layer_print();
    reg_a0 += 0x20;
    reg_d1.h[0] -= 1;
    text_layer_print();
    reg_a0 += 0x20;
    reg_d1.h[0] -= 1;
    text_layer_print();
}
#endif

#ifndef DEATH_LABEL
extern u8 attract_text_press_start[];

void attract_prompt_press_start(void) {
    if (g_stage_load_state == 0) {
        reg_d0.h[0] = 0;
        reg_d2.h[0] = 0;
        reg_a0 = attract_text_press_start;
        reg_d1.h[0] = 0x13;
        text_layer_print();
        reg_a0 += 0x20;
        reg_d1.h[0] -= 1;
        text_layer_print();
        reg_a0 += 0x20;
        reg_d1.h[0] -= 1;
        text_layer_print();
    }
}
#endif

#ifndef DEATH_LABEL
extern u8 attract_text_insert_coin[];

void attract_prompt_insert_coin(void) {
    if (g_stage_load_state == 0) {
        reg_d0.h[0] = 0;
        reg_d2.h[0] = 0;
        reg_a0 = attract_text_insert_coin;
        reg_d1.h[0] = 0x13;
        text_layer_print();
        reg_a0 += 0x20;
        reg_d1.h[0] -= 1;
        text_layer_print();
        reg_a0 += 0x20;
        reg_d1.h[0] -= 1;
        text_layer_print();
    }
}
#endif

#ifndef DEATH_LABEL
s32 credits_get();
s32 text_layer_put_hex_digit();
extern u8 attract_text_insert_coins[];

void attract_prompt_by_credits(void) {
    credits_get();
    if (reg_d1.h[0] != 0) {
        attract_prompt_coins_missing();
        return;
    }
    reg_d2.h[0] = 0;
    reg_a0 = attract_text_insert_coins;
    reg_d1.h[0] = 0x13;
    reg_d4.h[0] = reg_d0.h[0];
    reg_d0.h[0] = 0;
    text_layer_print();
    reg_a0 += 0x20;
    reg_d1.h[0] -= 1;
    text_layer_print();
    reg_a0 += 0x20;
    reg_d1.h[0] -= 1;
    text_layer_print();
    reg_d1.h[0] += 2;
    reg_d0.h[0] = 0xE;
    text_layer_put_hex_digit();
}
#endif

#ifndef DEATH_LABEL
extern u8 attract_text_insert_more_coins[];

void attract_prompt_coins_missing(void) {
    u16 temp_a0;

    reg_d0.h[0] -= reg_d1.h[0];
    reg_d4.h[0] = reg_d0.h[0];
    if (reg_d4.h[0] == 1) {
        attract_prompt_one_more_coin();
        return;
    }
    reg_d0.h[0] = 0;
    reg_d2.h[0] = 0;
    reg_a0 = attract_text_insert_more_coins;
    reg_d1.h[0] = 0x13;
    text_layer_print();
    reg_a0 += 0x20;
    reg_d1.h[0] -= 1;
    text_layer_print();
    reg_a0 += 0x20;
    reg_d1.h[0] -= 1;
    text_layer_print();
    reg_d1.h[0] += 2;
    reg_d0.h[0] = 0xC;
    text_layer_put_hex_digit();
}
#endif

#ifndef DEATH_LABEL
extern u8 attract_text_insert_2_coins[];

void attract_prompt_by_coins(void) {
    p2_credits_get();
    if (reg_d0.h[0] == 1) {
        attract_prompt_one_more_coin();
        return;
    }
    if ((s16)(reg_d0.h[0]) >= 2) {
        attract_prompt_press_start();
        return;
    }
    reg_d0.h[0] = 0;
    reg_d2.h[0] = 0;
    reg_a0 = attract_text_insert_2_coins;
    reg_d1.h[0] = 0x13;
    text_layer_print();
    reg_a0 += 0x20;
    reg_d1.h[0] -= 1;
    text_layer_print();
    reg_a0 += 0x20;
    reg_d1.h[0] -= 1;
    text_layer_print();
}
#endif

#ifndef DEATH_LABEL
extern u8 attract_text_insert_1_more_coin[];

void attract_prompt_one_more_coin(void) {
    reg_a0 = attract_text_insert_1_more_coin;
    reg_d0.h[0] = 0;
    reg_d1.h[0] = 0x13;
    reg_d2.h[0] = 0;
    text_layer_print();
    reg_a0 += 0x20;
    reg_d1.h[0] -= 1;
    text_layer_print();
    reg_a0 += 0x20;
    reg_d1.h[0] -= 1;
    text_layer_print();
}
#endif

#ifndef DEATH_LABEL

void attract_side_prompts_draw(void) {
    reg_d6.w = 0xA;
    attract_side_prompt_p1();
    attract_side_prompt_p2();
}
#endif

#ifndef DEATH_LABEL

void attract_side_prompt_p1(void) {
    reg_d7.w = 0;
    p1_credits_get();
    if (reg_d0.h[0] != 0) {
        attract_side_press_start_p1();
        return;
    }
    reg_d0.b[0] = g_setting_coin_mode;
    if (reg_d0.b[0] == 0x12) {
        attract_side_press_start_p1();
        return;
    }
    if (reg_d0.b[0] == 0x11) {
        attract_side_one_coin_p1();
        return;
    }
    if ((s8)(reg_d0.b[0]) >= 9) {
        attract_side_coins_p1();
        return;
    }
    attract_side_insert_coin();
}
#endif

#ifndef DEATH_LABEL

void attract_side_prompt_p2(void) {
    reg_d7.w = 0xE;
    p1_credits_get();
    if (reg_d1.h[0] != 0) {
        attract_side_press_start_p2();
        return;
    }
    reg_d0.b[0] = g_setting_coin_mode;
    if (reg_d0.b[0] == 0x12) {
        attract_side_press_start_p2();
        return;
    }
    if (reg_d0.b[0] == 0x11) {
        attract_side_one_coin_p2();
        return;
    }
    if ((s8)(reg_d0.b[0]) >= 9) {
        attract_side_coins_p2();
        return;
    }
    attract_side_insert_coin();
}
#endif

#ifndef DEATH_LABEL
extern char attract_text_press_start_p1[2][16];

void attract_side_press_start_p1(void) {
    reg_a0 = (u8 *)attract_text_press_start_p1;
    attract_side_two_lines_print();
}
#endif

#ifndef DEATH_LABEL
extern char attract_text_press_start_p2[2][16];


void attract_side_press_start_p2(void) {
    reg_a0 = (u8 *)attract_text_press_start_p2;
    attract_side_two_lines_print();
}
#endif

#ifndef DEATH_LABEL
s32 text_layer_print();                            /* extern */

void attract_side_two_lines_print(void) {
    reg_d2.h[0] = 0;
    reg_d0.h[0] = reg_d7.h[0];
    reg_d1.h[0] = reg_d6.h[0];
    text_layer_print();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    text_layer_print();
}
#endif

#ifndef DEATH_LABEL
extern u8 attract_side_text_insert_coin[];

void attract_side_insert_coin(void) {
    reg_a0 = attract_side_text_insert_coin;
    reg_d2.h[0] = 0;
    reg_d0.h[0] = reg_d7.h[0];
    reg_d1.h[0] = reg_d6.h[0];
    text_layer_print();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    text_layer_print();
}
#endif

#ifndef DEATH_LABEL
s32 credits_get();                            /* extern */

void attract_side_coins_p1(void) {
    credits_get();
    if (reg_d1.h[0] != 0) {
        attract_side_coins_missing();
        return;
    }
    attract_side_insert_coins();
}
#endif

#ifndef DEATH_LABEL
s32 coins_get();                            /* extern */

void attract_side_coins_p2(void) {
    coins_get();
    if (reg_d1.h[0] != 0) {
        attract_side_coins_missing();
        return;
    }
    attract_side_insert_coins();
}
#endif

#ifndef DEATH_LABEL
extern u8 attract_side_text_insert_2_coins[];

void attract_side_insert_coins(void) {
    u16 temp_a0;

    reg_a0 = attract_side_text_insert_2_coins;
    temp_a0 = reg_d0.h[0];
    reg_d2.h[0] = 0;
    reg_d4.h[0] = temp_a0;
    reg_d0.h[0] = reg_d7.h[0];
    reg_d1.h[0] = reg_d6.h[0];
    text_layer_print(temp_a0);
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    text_layer_print();
    reg_d0.h[0] = 3;
    reg_d0.h[0] += reg_d7.h[0];
    text_layer_put_hex_digit();
}
#endif

#ifndef DEATH_LABEL
extern u8 attract_side_text_insert_more_coins[];

void attract_side_coins_missing(void) {
    u16 temp_a0;

    reg_d0.h[0] -= reg_d1.h[0];
    reg_d4.h[0] = reg_d0.h[0];
    if (reg_d4.h[0] == 1) {
        attract_side_one_more_coin();
        return;
    }
    reg_d2.h[0] = 0;
    reg_a0 = attract_side_text_insert_more_coins;
    reg_d0.h[0] = reg_d7.h[0];
    reg_d1.h[0] = reg_d6.h[0];
    text_layer_print();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    text_layer_print();
    reg_d0.h[0] = 2;
    reg_d0.h[0] += reg_d7.h[0];
    text_layer_put_hex_digit();
}
#endif

#ifndef DEATH_LABEL

void attract_side_one_coin_p1(void) {
    p2_credits_get();
    if (reg_d0.h[0] == 1) {
        attract_side_one_more_coin();
        return;
    }
    if ((s16)(reg_d0.h[0]) >= 2) {
        attract_side_press_start_p1();
        return;
    }
    attract_side_insert_2_coins();
}
#endif

#ifndef DEATH_LABEL
void attract_side_one_coin_p2(void) {
    p2_credits_get();
    reg_d0.h[0] = reg_d1.h[0];
    if (reg_d0.h[0] == 1) {
        attract_side_one_more_coin();
        return;
    }
    if ((s16)(reg_d0.h[0]) >= 2) {
        attract_side_press_start_p2();
        return;
    }
    attract_side_insert_2_coins();
}
#endif

#ifndef DEATH_LABEL
void attract_side_insert_2_coins(void) {
    reg_a0 = attract_side_text_insert_2_coins;
    reg_d2.h[0] = 0;
    reg_d0.h[0] = reg_d7.h[0];
    reg_d1.h[0] = reg_d6.h[0];
    text_layer_print();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    text_layer_print();
}
#endif

#ifndef DEATH_LABEL
extern u8 attract_side_text_insert_1_more_coin[];

void attract_side_one_more_coin(void) {
    reg_a0 = attract_side_text_insert_1_more_coin;
    reg_d2.h[0] = 0;
    reg_d0.h[0] = reg_d7.h[0];
    reg_d1.h[0] = reg_d6.h[0];
    text_layer_print();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    text_layer_print();
}
#endif

#ifdef DEATH_LABEL
void attract_step_death_label_notice();
void attract_step_begin();
void attract_step_settings_notice();
void attract_step_stage_preload();
void attract_step_menu();
void attract_step_unused_4();
void attract_step_demo_start();
void attract_step_unused_6();
void attract_step_unused_7();
void attract_step_unused_8();
void attract_step_splash();
void attract_step_unused_10();
void attract_step_unused_11();
void attract_step_logo();
void attract_step_caution_text();
void attract_step_ship_select();
void attract_step_game_start();
void attract_step_mode2_start();
void attract_step_card_load();
void attract_step_autosave();


void (*attract_step_routines[20])() = {
    attract_step_begin,
    attract_step_settings_notice,
    attract_step_stage_preload,
    attract_step_death_label_notice,
    attract_step_unused_4,
    attract_step_demo_start,
    attract_step_unused_6,
    attract_step_unused_7,
    attract_step_unused_8,
    attract_step_splash,
    attract_step_unused_10,
    attract_step_unused_11,
    attract_step_logo,
    attract_step_caution_text,
    attract_step_ship_select,
    attract_step_menu,
    attract_step_game_start,
    attract_step_card_load,
    attract_step_autosave,
    attract_step_mode2_start,
};

u8 attract_step_caution_text_table[448] = {
    0x20, 0x20, 0x54, 0x48, 0x49, 0x53, 0x20, 0x47, 0x41, 0x4D, 0x45, 0x20, 0x49, 0x53, 0x20, 0x46,
    0x4F, 0x52, 0x20, 0x55, 0x53, 0x45, 0x20, 0x49, 0x4E, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x4A, 0x41, 0x50, 0x41, 0x4E,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x4F, 0x4E, 0x4C, 0x59, 0x2E, 0x20, 0x53, 0x41, 0x4C, 0x45, 0x53, 0x2C, 0x20, 0x45,
    0x58, 0x50, 0x4F, 0x52, 0x54, 0x2C, 0x20, 0x4F, 0x52, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x4F, 0x50, 0x45, 0x52, 0x41, 0x54, 0x49, 0x4F, 0x4E, 0x20, 0x4F, 0x55, 0x54, 0x53,
    0x49, 0x44, 0x45, 0x20, 0x54, 0x48, 0x49, 0x53, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x43, 0x4F, 0x55, 0x4E, 0x54, 0x52, 0x59, 0x20, 0x4D, 0x41, 0x59, 0x20, 0x42, 0x45,
    0x20, 0x43, 0x4F, 0x4E, 0x53, 0x54, 0x52, 0x55, 0x45, 0x44, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x41, 0x53, 0x20, 0x43, 0x4F, 0x50, 0x59, 0x52, 0x49, 0x47, 0x48, 0x54, 0x20, 0x41,
    0x4E, 0x44, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x54, 0x52, 0x41, 0x44, 0x45, 0x4D, 0x41, 0x52, 0x4B, 0x20, 0x49, 0x4E, 0x46, 0x52,
    0x49, 0x4E, 0x47, 0x45, 0x4D, 0x45, 0x4E, 0x54, 0x2E, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x56, 0x49, 0x4F, 0x4C, 0x41, 0x54, 0x4F, 0x52, 0x53, 0x20, 0x41, 0x52, 0x45, 0x20,
    0x53, 0x55, 0x42, 0x4A, 0x45, 0x43, 0x54, 0x20, 0x54, 0x4F, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x53, 0x45, 0x56, 0x45, 0x52, 0x45, 0x20, 0x50, 0x45, 0x4E, 0x41, 0x4C, 0x54, 0x49,
    0x45, 0x53, 0x20, 0x41, 0x4E, 0x44, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x57, 0x49, 0x4C, 0x4C, 0x20, 0x42, 0x45, 0x20, 0x50, 0x52, 0x4F, 0x53, 0x45, 0x43,
    0x55, 0x54, 0x45, 0x44, 0x20, 0x54, 0x4F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x54, 0x48, 0x45, 0x20, 0x46, 0x55, 0x4C, 0x4C, 0x20, 0x45, 0x58, 0x54, 0x45, 0x4E,
    0x54, 0x20, 0x4F, 0x46, 0x20, 0x54, 0x48, 0x45, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x4C, 0x41, 0x57, 0x2E, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x53, 0x43, 0x45, 0x4C, 0x49, 0x42, 0x20, 0x32, 0x2E, 0x36, 0x20, 0x20, 0x20, 0x30, 0x31,
    0x2F, 0x31, 0x30, 0x20, 0x44, 0x56, 0x44, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x32, 0x30, 0x30, 0x32, 0x2E, 0x30, 0x34, 0x2E, 0x30, 0x35, 0x2E, 0x4D,
    0x41, 0x53, 0x54, 0x45, 0x52, 0x20, 0x56, 0x45, 0x52, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
};
#else
void attract_step_begin();
void attract_step_settings_notice();
void attract_step_stage_preload();
void attract_step_settings_notice_timed();
void attract_step_menu();
void attract_step_unused_4();
void attract_step_demo_start();
void attract_step_unused_6();
void attract_step_unused_7();
void attract_step_unused_8();
void attract_step_splash();
void attract_step_unused_10();
void attract_step_unused_11();
void attract_step_logo();
void attract_step_caution_text();
void attract_step_ship_select();
void attract_step_game_start();
void attract_step_mode2_start();
void attract_step_card_load();
void attract_step_autosave();


void (*attract_step_routines[20])() = {
    attract_step_begin,
    attract_step_settings_notice,
    attract_step_stage_preload,
    attract_step_settings_notice_timed,
    attract_step_unused_4,
    attract_step_demo_start,
    attract_step_unused_6,
    attract_step_unused_7,
    attract_step_unused_8,
    attract_step_splash,
    attract_step_unused_10,
    attract_step_unused_11,
    attract_step_logo,
    attract_step_caution_text,
    attract_step_ship_select,
    attract_step_menu,
    attract_step_game_start,
    attract_step_card_load,
    attract_step_autosave,
    attract_step_mode2_start,
};

u8 attract_step_caution_text_table[448] = {
    0x20, 0x20, 0x54, 0x48, 0x49, 0x53, 0x20, 0x47, 0x41, 0x4D, 0x45, 0x20, 0x49, 0x53, 0x20, 0x46,
    0x4F, 0x52, 0x20, 0x55, 0x53, 0x45, 0x20, 0x49, 0x4E, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x4A, 0x41, 0x50, 0x41, 0x4E,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x4F, 0x4E, 0x4C, 0x59, 0x2E, 0x20, 0x53, 0x41, 0x4C, 0x45, 0x53, 0x2C, 0x20, 0x45,
    0x58, 0x50, 0x4F, 0x52, 0x54, 0x2C, 0x20, 0x4F, 0x52, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x4F, 0x50, 0x45, 0x52, 0x41, 0x54, 0x49, 0x4F, 0x4E, 0x20, 0x4F, 0x55, 0x54, 0x53,
    0x49, 0x44, 0x45, 0x20, 0x54, 0x48, 0x49, 0x53, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x43, 0x4F, 0x55, 0x4E, 0x54, 0x52, 0x59, 0x20, 0x4D, 0x41, 0x59, 0x20, 0x42, 0x45,
    0x20, 0x43, 0x4F, 0x4E, 0x53, 0x54, 0x52, 0x55, 0x45, 0x44, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x41, 0x53, 0x20, 0x43, 0x4F, 0x50, 0x59, 0x52, 0x49, 0x47, 0x48, 0x54, 0x20, 0x41,
    0x4E, 0x44, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x54, 0x52, 0x41, 0x44, 0x45, 0x4D, 0x41, 0x52, 0x4B, 0x20, 0x49, 0x4E, 0x46, 0x52,
    0x49, 0x4E, 0x47, 0x45, 0x4D, 0x45, 0x4E, 0x54, 0x2E, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x56, 0x49, 0x4F, 0x4C, 0x41, 0x54, 0x4F, 0x52, 0x53, 0x20, 0x41, 0x52, 0x45, 0x20,
    0x53, 0x55, 0x42, 0x4A, 0x45, 0x43, 0x54, 0x20, 0x54, 0x4F, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x53, 0x45, 0x56, 0x45, 0x52, 0x45, 0x20, 0x50, 0x45, 0x4E, 0x41, 0x4C, 0x54, 0x49,
    0x45, 0x53, 0x20, 0x41, 0x4E, 0x44, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x57, 0x49, 0x4C, 0x4C, 0x20, 0x42, 0x45, 0x20, 0x50, 0x52, 0x4F, 0x53, 0x45, 0x43,
    0x55, 0x54, 0x45, 0x44, 0x20, 0x54, 0x4F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x54, 0x48, 0x45, 0x20, 0x46, 0x55, 0x4C, 0x4C, 0x20, 0x45, 0x58, 0x54, 0x45, 0x4E,
    0x54, 0x20, 0x4F, 0x46, 0x20, 0x54, 0x48, 0x45, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x4C, 0x41, 0x57, 0x2E, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x32, 0x30, 0x30, 0x32, 0x2E, 0x30, 0x34, 0x2E, 0x30, 0x35, 0x2E, 0x4D,
    0x41, 0x53, 0x54, 0x45, 0x52, 0x20, 0x56, 0x45, 0x52, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
};

u8 attract_text_blank[96] = {
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 attract_text_press_start[96] = {
    0x20, 0x20, 0x20, 0x20, 0x50, 0x52, 0x45, 0x53, 0x53, 0x20, 0x31, 0x50, 0x20, 0x4F, 0x52, 0x20,
    0x32, 0x50, 0x20, 0x53, 0x54, 0x41, 0x52, 0x54, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
};

u8 attract_text_insert_2_coins[96] = {
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x49, 0x4E, 0x53, 0x45, 0x52, 0x54, 0x20, 0x32, 0x20,
    0x43, 0x4F, 0x49, 0x4E, 0x53, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x43, 0x4F, 0x4E, 0x54, 0x49, 0x4E, 0x55, 0x45, 0x20, 0x52,
    0x45, 0x51, 0x55, 0x49, 0x52, 0x45, 0x53, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x4F, 0x4E, 0x4C, 0x59, 0x20, 0x31, 0x20,
    0x43, 0x4F, 0x49, 0x4E, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
};

u8 attract_text_insert_1_more_coin[96] = {
    0x20, 0x20, 0x20, 0x20, 0x20, 0x49, 0x4E, 0x53, 0x45, 0x52, 0x54, 0x20, 0x31, 0x20, 0x4D, 0x4F,
    0x52, 0x45, 0x20, 0x43, 0x4F, 0x49, 0x4E, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
};

u8 attract_text_insert_coins[96] = {
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x49, 0x4E, 0x53, 0x45, 0x52, 0x54, 0x20, 0x20, 0x20,
    0x43, 0x4F, 0x49, 0x4E, 0x53, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
};

u8 attract_text_insert_more_coins[96] = {
    0x20, 0x20, 0x20, 0x20, 0x20, 0x49, 0x4E, 0x53, 0x45, 0x52, 0x54, 0x20, 0x20, 0x20, 0x4D, 0x4F,
    0x52, 0x45, 0x20, 0x43, 0x4F, 0x49, 0x4E, 0x53, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
};

u8 attract_text_insert_coin[96] = {
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x49, 0x4E, 0x53, 0x45, 0x52, 0x54, 0x20,
    0x43, 0x4F, 0x49, 0x4E, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
};

char attract_text_press_start_p1[2][16] = {
    "   PRESS      ",
    "   1P START   ",
};

char attract_text_press_start_p2[2][16] = {
    "   PRESS      ",
    "   2P START   ",
};

u8 attract_side_text_insert_2_coins[32] = {
    0x20, 0x20, 0x20, 0x49, 0x4E, 0x53, 0x45, 0x52, 0x54, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x32, 0x20, 0x43, 0x4F, 0x49, 0x4E, 0x53, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
};

u8 attract_side_text_insert_1_more_coin[32] = {
    0x20, 0x20, 0x49, 0x4E, 0x53, 0x45, 0x52, 0x54, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
    0x20, 0x20, 0x31, 0x20, 0x4D, 0x4F, 0x52, 0x45, 0x20, 0x43, 0x4F, 0x49, 0x4E, 0x20, 0x00, 0x00,
};

u8 attract_side_text_insert_coin[32] = {
    0x20, 0x20, 0x49, 0x4E, 0x53, 0x45, 0x52, 0x54, 0x20, 0x43, 0x4F, 0x49, 0x4E, 0x20, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
};

u8 attract_side_text_insert_more_coins[32] = {
    0x20, 0x20, 0x49, 0x4E, 0x53, 0x45, 0x52, 0x54, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x4D, 0x4F, 0x52, 0x45, 0x20, 0x43, 0x4F, 0x49, 0x4E, 0x53, 0x00, 0x00,
};
#endif

/* .sbss (the compiler lays these out in reverse) */
s8 D_0028DF84 __attribute__((aligned(4)));
