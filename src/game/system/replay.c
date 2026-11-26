#include "common.h"
#ifdef DDPDOJ_PC
#include "pc_replay_storage.h"
#endif
#include "task.h"
#include "sdk/ps2sdk.h"
#include "replay.h"

#ifdef DDPDOJ_PC
void enemies_resume(void);
void enemies_stop(void);
void game_screen_teardown(void);
void music_play_bgm2(void);
void replay_header_save(void);
void stage_doors_clear(void);
void stage_doors_open_request(void);
void stage_doors_open_requested_check(void);
void stage_doors_update(void);
void text_layer_clear(void);
void text_palette_load(void);
#endif

void replay_input_playback_begin();

#ifdef DEATH_LABEL
extern void voice_ok(void);
extern u16 g_attract_demo;
extern u16 g_p2_score_digits;
extern u16 g_p1_score_digits;
extern u16 g_two_player_seen;
extern s8 g_menu_pad;
extern u8 g_replay_taken_over;
extern s32 g_replay_position;
extern u8 g_replay_buffer_state;
extern u8 g_replay_mode_begun;
extern u8 g_replay_mode;
extern u8 g_simulation_active;
#ifndef DDPDOJ_PC
extern u16 D_006C58A4[];
extern u16 D_006C58A8[];
extern u8 death_D_002B1ED8[];
extern u8 g_replay_inputs[];
#endif

void replay_filter_input(void) {
    u32 save_d6;
    u32 save_d7;
    u8 swap;
    u16 t0;
    u16 t6;

    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    if (g_simulation_active != 0) {
        return;
    }
    switch (g_attract_demo) {
    case 0:
        break;
    default:
        return;
    }
    reg_d6.h[0] = reg_d0.h[0];
    reg_d7.h[0] = reg_d1.h[0];
    reg_d0.h[0] &= 0xFF;
    reg_d1.h[0] &= 0xFF;
    reg_d6.h[0] &= 0xFF00;
    reg_d7.h[0] &= 0xFF00;
    switch (g_replay_buffer_state) {
    case 0:
        g_replay_position = 0;
        reg_d1.b[0] = 0x80;
        reg_d0.b[0] = 0x80;
        break;
    case 1:
        if ((u32)g_replay_position == 0x1A5E0) {
            g_replay_position = 0x1A5DF;
            printf("replay buffer over!!!\n");
        }
        switch (g_replay_mode) {
        case 0:
            break;
        case 2:
            if ((u32)g_replay_position > 2 && g_replay_taken_over == 0) {
                if (g_menu_pad == 0) {
                    if (reg_d0.b[0] & 0x7F) {
                        g_replay_taken_over = 1;
                    }
                } else if (reg_d1.b[0] & 0x7F) {
                    g_replay_taken_over = 1;
                }
                if (g_replay_taken_over != 0) {
                    voice_ok();
                    printf("override start\n");
                }
            }
            if (g_replay_taken_over != 0) {
                swap = 0;
                if (g_menu_pad == 0) {
                    if (D_006C58A4[0] == 0xFF) {
                        swap = 1;
                    }
                } else if (D_006C58A8[0] == 0xFF) {
                    swap = 1;
                }
                if (swap) {
                    t0 = reg_d0.h[0];
                    reg_d0.h[0] = reg_d1.h[0];
                    reg_d1.h[0] = t0;
                    t6 = reg_d6.h[0];
                    reg_d6.h[0] = reg_d7.h[0];
                    reg_d7.h[0] = t6;
                }
            } else {
                if (g_replay_mode_begun != g_replay_mode) {
                    g_replay_mode = 0;
                }
                if (D_006C58A4[0] != 0xFF) {
                    reg_d0.b[0] = g_replay_inputs[(u32)g_replay_position] ^ death_D_002B1ED8[(u32)g_replay_position & 0x1F];
                } else {
                    reg_d1.b[0] = g_replay_inputs[(u32)g_replay_position] ^ death_D_002B1ED8[(u32)g_replay_position & 0x1F];
                }
                (*(u32 *)&g_replay_position)++;
            }
            break;
        case 1:
            if (g_replay_mode_begun != g_replay_mode) {
                g_replay_mode = 0;
            }
            if (D_006C58A4[0] != 0xFF) {
                g_replay_inputs[(u32)g_replay_position] = reg_d0.b[0];
            } else {
                g_replay_inputs[(u32)g_replay_position] = reg_d1.b[0];
            }
            g_replay_inputs[(u32)g_replay_position] ^= death_D_002B1ED8[(u32)g_replay_position & 0x1F];
            (*(u32 *)&g_replay_position)++;
            if (g_two_player_seen == 3 || g_p1_score_digits != 0 || g_p2_score_digits != 0) {
                g_replay_mode = 0;
            }
            break;
        }
        break;
    case 3:
    case 2:
        break;
    }
    reg_d0.h[0] |= reg_d6.h[0];
    reg_d1.h[0] |= reg_d7.h[0];
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
}
#else
extern void voice_ok(void);
extern u16 g_attract_demo;
extern u16 g_p2_score_digits;
extern u16 g_p1_score_digits;
extern u16 g_two_player_seen;
extern s8 g_menu_pad;
extern u8 g_replay_taken_over;
extern s32 g_replay_position;
extern u8 g_replay_buffer_state;
extern u8 g_replay_mode_begun;
extern u8 g_replay_mode;
extern u8 g_simulation_active;
#ifndef DDPDOJ_PC
extern u16 D_006C58A4[];
extern u16 D_006C58A8[];
extern u8 D_006CB588[];
extern u8 g_replay_inputs[];
#endif

void replay_filter_input(void) {
    u32 save_d6;
    u32 save_d7;
    u8 swap;
    u16 t0;
    u16 t6;

    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    if (g_simulation_active != 0) {
        return;
    }
    reg_d6.h[0] = reg_d0.h[0];
    reg_d7.h[0] = reg_d1.h[0];
    reg_d0.h[0] &= 0xFF;
    reg_d1.h[0] &= 0xFF;
    reg_d6.h[0] &= 0xFF00;
    reg_d7.h[0] &= 0xFF00;
    switch (g_replay_buffer_state) {
    case 0:
        g_replay_position = 0;
        reg_d1.b[0] = 0x80;
        reg_d0.b[0] = 0x80;
        break;
    case 1:
        if ((u32)g_replay_position == 0x1A5E0) {
            g_replay_position = 0x1A5DF;
            printf((const char *)"replay buffer over!!!\n");
        }
        switch (g_replay_mode) {
        case 0:
            break;
        case 2:
            if ((u32)g_replay_position > 2 && g_replay_taken_over == 0 && g_attract_demo == 0) {
                if (g_menu_pad == 0) {
                    if (reg_d0.b[0] & 0x7F) {
                        g_replay_taken_over = 1;
                    }
                } else if (reg_d1.b[0] & 0x7F) {
                    g_replay_taken_over = 1;
                }
                if (g_replay_taken_over != 0) {
                    voice_ok();
                    printf((const char *)"override start\n");
                }
            }
            if (g_replay_taken_over != 0) {
                swap = 0;
                if (g_menu_pad == 0) {
                    if (D_006C58A4[0] == 0xFF) {
                        swap = 1;
                    }
                } else if (D_006C58A8[0] == 0xFF) {
                    swap = 1;
                }
                if (swap) {
                    t0 = reg_d0.h[0];
                    reg_d0.h[0] = reg_d1.h[0];
                    reg_d1.h[0] = t0;
                    t6 = reg_d6.h[0];
                    reg_d6.h[0] = reg_d7.h[0];
                    reg_d7.h[0] = t6;
                }
            } else {
                if (g_replay_mode_begun != g_replay_mode) {
                    g_replay_mode = 0;
                }
                if (D_006C58A4[0] != 0xFF) {
                    reg_d0.b[0] = g_replay_inputs[(u32)g_replay_position] ^ D_006CB588[(u32)g_replay_position & 0x1F];
                } else {
                    reg_d1.b[0] = g_replay_inputs[(u32)g_replay_position] ^ D_006CB588[(u32)g_replay_position & 0x1F];
                }
                (*(u32 *)&g_replay_position)++;
            }
            break;
        case 1:
            if (g_replay_mode_begun != g_replay_mode) {
                g_replay_mode = 0;
            }
            if (D_006C58A4[0] != 0xFF) {
                g_replay_inputs[(u32)g_replay_position] = reg_d0.b[0];
            } else {
                g_replay_inputs[(u32)g_replay_position] = reg_d1.b[0];
            }
            g_replay_inputs[(u32)g_replay_position] ^= D_006CB588[(u32)g_replay_position & 0x1F];
            (*(u32 *)&g_replay_position)++;
            if (g_two_player_seen == 3 || g_p1_score_digits != 0 || g_p2_score_digits != 0) {
                g_replay_mode = 0;
            }
            break;
        }
        break;
    case 3:
    case 2:
        break;
    }
    reg_d0.h[0] |= reg_d6.h[0];
    reg_d1.h[0] |= reg_d7.h[0];
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
}
#endif


extern void replay_stop_task(void);

void replay_run_start(void);
void replay_result_menu(void);
void replay_exit(void);
void replay_playback_start(void);
void replay_run_end(void);
extern void (*replay_screen_routines[])(void);

void replay_task(void) {
    s32 index = reg_a5[5];

    switch (reg_a5[3]) {
    case 0:
    case 1:
        replay_screen_routines[index]();
        break;
    case 2:
        replay_stop_task();
        break;
    }
}

extern u8 text_palette_0[];
extern s8 D_0028DF84;

void replay_exit_begin(void) {
#ifndef DDPDOJ_PC
    s32 text_layer_clear();
    s32 text_palette_load();
#endif
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;

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
    text_layer_clear();
    reg_d0.w = 0;
    reg_a0 = (u8 *)text_palette_0;
    text_palette_load();
    D_0028DF84 = 0;
    *(s8 *)(reg_a5 + 3) = 1;
    *(s16 *)(reg_a5 + 8) = 0;
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

extern void settings_notice_begin(void);
extern void settings_notice_draw_static(void);
extern void stage_load_step(void);
extern void disc_notice_begin(void);
extern void disc_notice_end(void);
extern void menu_reset_keep_sim_rules(void);
extern void menu_reset_keep_sim_rules_and_page(void);
extern u8 g_stage_load_state;
extern s16 g_loaded_stage;
extern u16 g_stage;
extern s8 g_cd_async_state;
extern s8 g_cd_async_busy;
extern s8 D_0028EC20;

void replay_exit(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    s32 step;

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
    step = *(u16 *)(reg_a5 + 8);
    if (*(u8 *)(reg_a5 + 3) == 0) {
        replay_exit_begin();
        return;
    }
    switch (step) {
    default:
        step++;
        break;
    case 0:
        g_cd_async_busy = 1;
        g_stage_load_state = 0;
        g_cd_async_state = 0;
        disc_notice_begin();
        g_stage = 0;
        step++;
        break;
    case 1:
        stage_load_step();
        if (g_loaded_stage == g_stage) {
            disc_notice_end();
            step++;
        }
        break;
    case 2:
        step++;
        settings_notice_begin();
        settings_notice_draw_static();
        if (D_0028EC20 != 0) {
            menu_reset_keep_sim_rules_and_page();
        } else {
            menu_reset_keep_sim_rules();
        }
        break;
    case 4:
        reg_d0.h[0] = TASK_ATTRACT;
        task_start();
        *(u16 *)(reg_a0 + 4) = 15;
        *(u8 *)(reg_a5 + 3) = 2;
        break;
    }
    *(u16 *)(reg_a5 + 8) = step;
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
}


void replay_start_run(void) {
    u32 temp_s0 = reg_d0.w;
    u8 *temp_s1 = reg_a0;

    g_replay_header = g_replay_header_saved;
    reg_d0.h[0] = TASK_REPLAY;
    task_start();
    *(s8 *)(reg_a0 + 5) = 0;
    reg_d0.w = temp_s0;
    reg_a0 = temp_s1;
}

extern u8 g_replay_mode;
extern u8 g_simulation_active;

void replay_start_result() {
#ifndef DDPDOJ_PC
    s32 game_screen_teardown();
#endif
    u32 temp_s0;
    u8 *temp_s1;
    s32 var_s2;

    temp_s0 = reg_d0.w;
    temp_s1 = (u8 *)(reg_a0);
    var_s2 = 0;
    if (g_simulation_active != 0) {
        var_s2 = 1;
    }
    if (g_replay_mode == 2) {
        var_s2 = 0;
    }
    game_screen_teardown();
    reg_d0.h[0] = TASK_REPLAY;
    task_start();
    if (var_s2 != 0) {
        *(s8 *)(reg_a0 + 5) = 1;
    } else {
        *(s8 *)(reg_a0 + 5) = 2;
    }
    reg_d0.w = temp_s0;
    reg_a0 = temp_s1;
}

#ifndef DDPDOJ_PC
s32 game_screen_teardown();                            /* extern */
#endif
s32 replay_scores_snapshot();                            /* extern */

void replay_start_run_end(void) {
    u32 temp_s0;
    u8 *temp_s1;

    temp_s0 = reg_d0.w;
    temp_s1 = reg_a0;
    replay_scores_snapshot();
    game_screen_teardown();
    reg_d0.h[0] = TASK_REPLAY;
    task_start();
    *(s8 *)(reg_a0 + 5) = 4;
    reg_d0.w = temp_s0;
    reg_a0 = temp_s1;
}

#ifndef DDPDOJ_PC
s32 text_layer_clear();                            /* extern */
#endif
s32 fade_in();                            /* extern */
#ifndef DDPDOJ_PC
s32 text_palette_load();                            /* extern */
#endif
s32 result_menu_reset();                            /* extern */
extern u8 D_0026B580[];
extern u32 g_replay_fade_id;

void replay_result_menu_begin(void) {
    s32 *temp_s0;
    u32 temp_s1;

    temp_s0 = (s32 *)reg_a0;
    temp_s1 = reg_d0.w;
    text_layer_clear();
    reg_d0.w = 0;
    reg_a0 = (u8 *)((s32 *)text_palette_0);
    text_palette_load();
    *(s8 *)(reg_a5 + 3) = 1;
    *(s16 *)(reg_a5 + 6) = 0;
    result_menu_reset();
    reg_a0 = (u8 *)((s32 *)D_0026B580);
    fade_in();
    reg_a0 = (u8 *)temp_s0;
    g_replay_fade_id = reg_d0.w;
    reg_d0.w = temp_s1;
}

extern void fade_to_black(void);
extern void fade_release(void);
extern void fade_is_running(void);
extern void ranking_sprite_draw(void);
extern s32 result_menu_update(void);
extern u8 D_0026B5F0[];
extern s8 D_0028EACC;

void replay_result_menu(void) {
#ifndef DDPDOJ_PC
    extern void game_screen_teardown(void);
#endif
    s32 step;
    s32 done;
    u8 *save_a0;
    u32 save_d0;

    save_a0 = reg_a0;
    save_d0 = reg_d0.w;
    step = *(u16 *)(reg_a5 + 6);
    done = 0;
    if (*(u8 *)(reg_a5 + 3) == 0) {
        replay_result_menu_begin();
        return;
    }
    switch (step) {
    default:
        step++;
        break;
    case 0:
        reg_d0.w = g_replay_fade_id;
        fade_is_running();
        if (cond_flag == 0) {
            fade_release();
            step++;
        }
        break;
    case 1:
        switch (result_menu_update()) {
        case 4:
            step = 200;
            break;
        case 1:
            step = 300;
            break;
        case 2:
            step = 400;
            break;
        }
        break;
    case 200:
    case 300:
    case 400:
        reg_a0 = (u8 *)D_0026B5F0;
        fade_to_black();
        step++;
        g_replay_fade_id = reg_d0.w;
        break;
    case 216:
    case 316:
    case 416:
        reg_d0.w = g_replay_fade_id;
        fade_is_running();
        if (cond_flag == 0) {
            fade_release();
            step++;
        }
        break;
    case 217:
    case 317:
        task_reset_all();
        replay_start_run();
        if (step / 100 == 2) {
            g_replay_mode = 2;
        } else {
            g_replay_mode = 1;
        }
        done = 1;
        break;
    case 417:
        task_reset_all();
        game_screen_teardown();
        reg_d0.h[0] = TASK_REPLAY;
        task_start();
        done = 1;
        *(u8 *)(reg_a0 + 5) = 2;
        break;
    }
    ranking_sprite_draw();
    if (done == 0) {
        *(u16 *)(reg_a5 + 6) = step;
    } else {
        D_0028EACC = 0;
    }
    reg_a0 = save_a0;
    reg_d0.w = save_d0;
}

extern void srand(u32 seed);
extern s32 rand(void);
extern void replay_snapshot_save(u8 *data);
extern u16 g_input_p2_previous;
extern u16 g_input_p2_pressed;
extern u16 g_input_p2_held;
extern u16 g_input_p1_previous;
extern u16 g_input_p1_pressed;
extern u16 g_input_p1_held;
extern u8 D_0028E2BB;
extern u8 D_0028E2BC;
extern u8 D_0028E2E4;
extern u8 g_setting_difficulty;
extern u16 g_scroll_line;
extern u16 g_scroll_line_offset;
extern u16 g_loop;
extern u8 D_0028ED64;
extern s32 g_replay_position;
extern u8 g_replay_buffer_state;
extern u8 g_replay_mode_begun;
#ifndef DDPDOJ_PC
extern u8 g_replay_file[48];
extern u16 D_006C58A2[];
extern u16 D_006C58A4[];
extern u16 D_006C58A6[];
extern u16 D_006C58A8[];
extern u8 g_replay_snapshot[];
extern u8 g_replay_start_state[];
extern u16 D_006CB578[];
extern u16 D_006CB57A[];
extern u16 D_006CB57C[];
extern u16 D_006CB57E[];
extern u16 D_006CB580[];
extern u16 D_006CB582[];
extern u8 g_replay_inputs[];
#endif

void replay_record_begin() {
    s32 i;
    u16 *data;
    u16 *save;

    if (g_simulation_active == 0 && g_replay_buffer_state == 2) {
        data = ((u16 *)g_replay_snapshot);
        save = ((u16 *)g_replay_file);
    g_replay_mode_begun = 1;
    g_replay_buffer_state = 1;
    D_0028ED64 = 0;
    g_replay_position = 0;
    printf((const char *)"replay recording start!!\n");
    memset(save, 0, 0x400);
    memset(g_replay_inputs, 0, 0x1A5E0);
    memset(data, 0, 0x5534);
    replay_snapshot_save((u8 *)data);
    if (g_stage != 0 || g_loop == 0) {
        memset(g_replay_start_state, 0, 0x3A4);
    }
    srand(D_0028E2BC * D_0028E2BB);
    for (i = 0; i < 0x20; i++) {
        ((u8 *)((u16 *)g_replay_file))[0x5CE8 + i] = rand();
    }
    D_006CB57A[0] = g_input_p1_pressed;
    D_006CB578[0] = g_input_p1_held;
    D_006CB57C[0] = g_input_p1_previous;
    D_006CB580[0] = g_input_p2_pressed;
    D_006CB57E[0] = g_input_p2_held;
    D_006C58A2[0] = 0xFF;
    D_006C58A4[0] = 0xFF;
    D_006C58A6[0] = 0xFF;
    D_006C58A8[0] = 0xFF;
    D_006CB582[0] = g_input_p2_previous;
    save[6] = data[0x31BC / 2];
    save[7] = data[0x31B6 / 2];
    save[1] = data[0xC6E / 2];
    save[2] = data[0xC70 / 2];
    if (save[2] == 0) {
        save[2] = 0xFF;
        save[1] = 0xFF;
    }
    save[3] = data[0xCD0 / 2];
    save[4] = data[0xCD2 / 2];
    if (save[4] == 0) {
        save[4] = 0xFF;
        save[3] = 0xFF;
    }
    save[5] = g_setting_difficulty;
    save[18] = D_0028E2E4;
    printf((const char *)"real_l[%d] real_l_scr[%d]\n", g_scroll_line, g_scroll_line_offset);
    }
}

extern u8 g_game_mode;
extern u8 g_replay_begin_pending;

void replay_begin_pending(void) {
    if (g_game_mode == 2) {
        g_replay_buffer_state = 2;
        g_replay_begin_pending = 0;
        g_replay_mode = 0;
    }
    if (g_simulation_active != 0) {
        g_replay_begin_pending = 0;
        return;
    }
    if (g_replay_begin_pending != 0) {
        g_replay_begin_pending = 0;
        switch (g_replay_mode) {                       /* irregular */
        case 1:
            replay_record_begin(g_replay_mode);
            return;
        case 2:
            replay_input_playback_begin(g_replay_mode);
            break;
        }
    }
}

s32 replay_snapshot_load(s32 *);                   /* extern */
extern s32 g_replay_checksum;
#ifndef DDPDOJ_PC
extern s32 g_replay_file_checksum[];
#endif

void replay_input_playback_begin() {
    g_replay_mode_begun = 2;
    replay_snapshot_load(((s32 *)g_replay_snapshot));
    if (g_replay_file_checksum[0] == g_replay_checksum) {
        g_replay_buffer_state = 1;
        g_replay_position = 0;
        g_input_p1_pressed = D_006CB57A[0];
        g_input_p1_held = D_006CB578[0];
        g_input_p1_previous = D_006CB57C[0];
        g_input_p2_pressed = D_006CB580[0];
        g_input_p2_held = D_006CB57E[0];
        g_input_p2_previous = D_006CB582[0];
        return;
    }
    replay_start_result(g_replay_file_checksum[0]);
}

extern void label_draw(s32 a, s32 b, s32 c, s32 d);
extern void replay_start_state_load(u8 *arg);
extern u8 g_default_text_palette[];
extern u16 D_0028E314;
extern u16 D_0028E318;
extern u8 D_0028E368;
extern u8 g_game_frame_ran;
extern u16 g_attract_demo;
extern s8 D_0028E3F8;
extern u8 g_replay_taken_over;
extern u8 D_0028ED5C;
extern ReplayHeader g_replay_file_as_SaveHeader; /* the header at the start of the save buffer */
#ifndef DDPDOJ_PC
extern u16 D_006C8E56[];
extern u16 D_006C8E5C[];
#endif

void replay_playback_begin(void) {
#ifndef DDPDOJ_PC
    extern void text_layer_clear(void);
    extern void stage_doors_clear(void);
    extern void text_palette_load(void);
    extern void replay_header_save(void);
#endif
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;

    g_game_frame_ran = 0;
    D_0028E3F8 = 0;
    g_replay_buffer_state = 0;
    g_replay_position = 0;
    D_0028E368 = 0;
    D_0028ED5C = 1;
    g_replay_taken_over = 0;
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
    g_replay_header = g_replay_file_as_SaveHeader;
    *(u8 *)(reg_a5 + 3) = 1;
    *(u16 *)(reg_a5 + 10) = 0;
    if (D_006C8E56[0] == 0 && D_006C8E5C[0] != 0) {
        replay_start_state_load(g_replay_start_state);
    }
#ifndef DEATH_LABEL
    if (g_attract_demo == 0)
#endif
    {
        if (D_006C58A4[0] != 0xFF) {
            D_0028E314 = 0;
            D_0028E318 = 9;
        } else {
            D_0028E318 = 0;
            D_0028E314 = 9;
        }
    }
    reg_d0.h[0] = TASK_GAME;
    task_start();
    *(u16 *)(reg_a0 + 4) = g_replay_header.stage;
    stage_doors_clear();
    text_layer_clear();
    reg_d0.w = 0;
    reg_a0 = (u8 *)g_default_text_palette;
    text_palette_load();
    label_draw(0, 0, 0, 0);
    replay_header_save();
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

s32 deferred_text_reset();
s32 attract_picture_draw();
s32 ship_palettes_load();
extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
extern void replay_header_apply(void);
s32 replay_text_layer_load();
extern u8 D_0028DEF8;
extern u16 g_players_hidden;
extern u8 D_0028E2EC;
extern u8 D_0028E304;
extern u8 g_setting_ship_stock;
extern u8 g_setting_extend;
extern u16 g_frame_mod16;
extern u16 g_frame_mod8;
extern u16 g_frame_mod4;
extern u16 g_frame_mod3;
extern u16 g_frame_mod2;
extern u16 g_game_frame;
extern u16 g_score_task_active;
extern u16 g_score_panel_intro;
extern s32 g_play_time;
extern u16 g_p2_lives;
extern u16 g_p1_lives;
extern s32 D_0028E998;
extern s32 D_0028E99C;
extern s8 D_0028EC58;
extern s16 g_player2[56];
extern s16 g_player1[56];
#ifndef DDPDOJ_PC
extern u8 D_006C58C4[];
extern u8 g_replay_snapshot[];
extern u8 D_006C68B6[];
extern u8 D_006C6918[];
extern s32 D_006C8E88[];
extern u16 replay_playback_start_buffer[];
extern u16 D_006C8E94[];
extern u16 replay_playback_start_buffer_2[];
extern u8 D_006C91AC[];
extern u8 D_006C91AD[];
extern u8 D_006C91AE[];
extern u8 D_006C91AF[];
extern u8 replay_playback_start_buffer_3[];
#endif

void replay_playback_start(void) {
#ifndef DDPDOJ_PC
    s32 enemies_stop();
    s32 enemies_resume();
    s32 stage_doors_open_request();
    s32 stage_doors_open_requested_check();
    s32 stage_doors_update();
    s32 music_play_bgm2();
#endif
    s32 base;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    s32 step;

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
    step = *(u16 *)(reg_a5 + 10);
    if (*(u8 *)(reg_a5 + 3) == 0) {
        replay_playback_begin();
        gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x50, 0x80, 0xFF, 0xFF, 0xFF);
        D_0028E998 = -1;
        D_0028E99C = -1;
        reg_d0.h[0] = 0;
        reg_d1.h[0] = D_006C58A2[0];
        ship_palettes_load();
        reg_d0.h[0] = 1;
        reg_d1.h[0] = D_006C58A6[0];
        ship_palettes_load();
        replay_text_layer_load(g_replay_snapshot);
        g_score_task_active = 0;
        return;
    }
    if (step < 0xC8) {
        D_0028E368 = 0;
        g_score_task_active = 0;
        if ((D_006C8E56[0] != 0) && (step < 0x65)) {
            deferred_text_reset();
#ifndef DEATH_LABEL
            if (g_attract_demo != 0) {
                attract_picture_draw();
            }
#endif
            g_p2_lives = 0xFFFF;
            g_p1_lives = 0xFFFF;
        }
    }
    stage_doors_update();
    switch (step) {
    case 0x0:
        stage_doors_open_request();
        gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x50, 0x80, 0xFF, 0xFF, 0xFF);
        step += 1;
        break;
    default:
        if (step < 16) {
            step += 1;
        }
        break;
    case 0x10:
        g_setting_difficulty = D_006C91AC[0];
        g_setting_ship_stock = D_006C91AE[0];
        g_setting_extend = D_006C91AD[0];
        D_0028E2EC = D_006C91AF[0];
        D_0028E304 = replay_playback_start_buffer_3[0];
        D_0028E2E4 = D_006C58C4[0];
        replay_header_apply();
        enemies_stop();
        step = 0x64;
        break;
    case 0xC8:
        step += 1;
        D_0028E368 = 1;
    case 0xC9:
        stage_doors_open_requested_check();
        if (cond_flag == 0) {
            *(u8 *)(reg_a5 + 3) = 2;
        }
        break;
    }
    if (D_006C8E56[0] == 0) {
        switch (step) {
        case 0x64:
            if (D_0028EC58 != 0) {
                step += 1;
#ifdef DEATH_LABEL
                if (g_replay_header.stage == 0) {
#else
                if ((g_replay_header.stage == 0) && (g_attract_demo == 0)) {
#endif
                    music_play_bgm2();
                }
                enemies_resume();
                D_0028ED5C = 0;
                if (g_loop == 0) {
                    memcpy(((u16 *)g_player1), D_006C68B6, 0x62);
                    memcpy(((u16 *)g_player2), D_006C6918, 0x62);
                    ((u16 *)g_player1)[0] = 0;
                    ((u16 *)g_player2)[0] = 0;
                } else {
                    g_players_hidden = 1;
                }
            }
            break;
        case 0x65:
            if ((g_loop != 0) && (g_scroll_line == 0x69) && (g_scroll_line_offset == 0x140)) {
                memcpy(((u16 *)g_player1), D_006C68B6, 0x62);
                memcpy(((u16 *)g_player2), D_006C6918, 0x62);
                g_players_hidden = 0;
                D_0028ED5C = 0;
            }
            if (g_scroll_line == 0x38) {
                g_game_frame = 0x11A;
                g_frame_mod4 = 2;
                g_frame_mod8 = 2;
                g_frame_mod2 = 0;
                g_frame_mod16 = 0xA;
                g_frame_mod3 = 0;
                base = replay_playback_start_buffer_2[0] - 0x11A;
                g_play_time = D_006C8E88[0] - base + 1;
            }
            if ((g_scroll_line == replay_playback_start_buffer[0]) && (g_scroll_line_offset == D_006C8E94[0])) {
                g_score_task_active = 1;
                g_replay_begin_pending = 1;
                step = 0xC8;
#ifndef DEATH_LABEL
                D_0028DEF8 = 1;
#endif
                printf((const char *)"replay play start!!\n", g_scroll_line);
            }
            break;
        }
    } else {
        switch (step) {
        case 0x64:
            if (D_0028EC58 != 0) {
                step += 1;
            case 0x65:
                if (g_score_panel_intro == 0) {
                    D_0028ED5C = 0;
                    g_replay_begin_pending = 1;
#ifndef DEATH_LABEL
                    D_0028DEF8 = 1;
#endif
                    enemies_resume();
                    step += 1;
                    printf((const char *)"replay play start!!\n");
                }
            }
            break;
        case 0x66:
            step = 0xC8;
            g_score_task_active = 1;
            break;
        }
    }
    *(u16 *)(reg_a5 + 10) = step;
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
}

extern s8 D_0028E3F8;

void replay_run_begin(void) {
#ifndef DDPDOJ_PC
    s32 text_layer_clear();
    s32 stage_doors_clear();
    s32 text_palette_load();
    s32 replay_header_save();
#endif
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;

    save_d0 = reg_d0.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    g_game_frame_ran = 0;
    save_d1 = reg_d1.w;
    D_0028E3F8 = 0;
    D_0028E368 = 0;
    D_0028ED5C = 1;
    g_simulation_active = 1;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_a5[3] = 1;
    *(s16 *)(reg_a5 + 4) = 0;
    reg_d0.h[0] = TASK_GAME;
    task_start();
    *(u16 *)(reg_a0 + 4) = g_replay_header.stage;
    stage_doors_clear();
    text_layer_clear();
    reg_d0.w = 0;
    reg_a0 = (u8 *)g_default_text_palette;
    text_palette_load();
    replay_header_save();
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

extern void frame_counters_reset(void);
extern u8 g_pad_input_locked;
extern u8 D_0028E2A8;
extern u16 D_0028E2AC;
extern u8 D_0028E2B0;
extern u8 D_0028E2C4;
extern u8 g_simulation_boss_start;
extern u8 D_0028E2D4;

void replay_run_start(void) {
#ifndef DDPDOJ_PC
    extern void enemies_stop(void);
    extern void enemies_resume(void);
    extern void stage_doors_open_request(void);
    extern void stage_doors_open_requested_check(void);
    extern void stage_doors_update(void);
    extern void music_play_bgm2(void);
#endif
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    s32 step;

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
    step = *(u16 *)(reg_a5 + 4);
    if (*(u8 *)(reg_a5 + 3) == 0) {
        replay_run_begin();
        return;
    }
    stage_doors_update();
    switch (step) {
    default:
        step++;
        break;
    case 0:
        stage_doors_open_request();
        step++;
        break;
    case 16:
        g_setting_difficulty = *(u8 *)&g_replay_header.difficulty;
        D_0028E2E4 = *(u8 *)&g_replay_header.bullet;
        g_simulation_boss_start = *(u8 *)&g_replay_header.start;
        D_0028E2C4 = *(u8 *)&g_replay_header.death;
        D_0028E2D4 = *(u8 *)&g_replay_header.rank;
        D_0028E2B0 = *(u8 *)&g_replay_header.unk2A;
        D_0028E2AC = g_replay_header.hyper_gauge;
        D_0028E2A8 = *(u8 *)&g_replay_header.unk2C;
        replay_header_apply();
        enemies_stop();
        step++;
        g_pad_input_locked = 1;
        break;
    case 17:
        if (g_score_panel_intro == 0) {
            D_0028ED5C = 0;
            step++;
        }
        break;
    case 18:
        frame_counters_reset();
        if (g_game_frame_ran != 0) {
            g_pad_input_locked = 0;
            step++;
            g_loop = g_replay_header.round;
            enemies_resume();
            if (g_replay_header.stage == 0) {
                music_play_bgm2();
            }
        }
        break;
    case 19:
        stage_doors_open_requested_check();
        if (cond_flag == 0) {
            *(u8 *)(reg_a5 + 3) = 2;
        }
        break;
    }
    *(u16 *)(reg_a5 + 4) = step;
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
}

extern s32 replay_save_prompt_update(void);
extern u8 g_replay_watch_after_run;

static void replay_run_end_begin(void)
{
    u32 saved_d0;
    u32 saved_d1;
    u32 saved_d2;
    u32 saved_d3;
    u32 saved_d4;
    u32 saved_d5;
    u32 saved_d6;
    u32 saved_d7;

    g_replay_mode = 2;

    saved_d0 = reg_d0.w;
    saved_d1 = reg_d1.w;
    saved_d2 = reg_d2.w;
    saved_d3 = reg_d3.w;
    saved_d4 = reg_d4.w;
    saved_d5 = reg_d5.w;
    saved_d6 = reg_d6.w;
    saved_d7 = reg_d7.w;

    D_0028DF84 = 0;
    D_0028E368 = 0;
    reg_a5[3] = 1;
    *(u16 *)(reg_a5 + 0xC) = 0;

    reg_d0.w = saved_d0;
    reg_d1.w = saved_d1;
    reg_d2.w = saved_d2;
    reg_d3.w = saved_d3;
    reg_d4.w = saved_d4;
    reg_d5.w = saved_d5;
    reg_d6.w = saved_d6;
    reg_d7.w = saved_d7;
}

void replay_run_end(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    s32 step;

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
    step = *(u16 *)(reg_a5 + 12);
    if (*(u8 *)(reg_a5 + 3) == 0) {
        replay_run_end_begin();
        return;
    }
    switch (step) {
    case 0:
        if (g_replay_taken_over != 0) {
            g_replay_watch_after_run = 0;
            replay_start_result();
            return;
        }
        if (replay_save_prompt_update() != 0) {
            if (g_replay_watch_after_run != 0) {
                step++;
            } else {
                replay_start_result();
                return;
            }
        }
        break;
    default:
        gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x50, step * 8, 0xFF, 0xFF, 0xFF);
        step++;
        break;
    case 16:
        gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x50, 0x80, 0xFF, 0xFF, 0xFF);
        D_0028E368 = 1;
        g_replay_mode = 2;
        task_reset_all();
        reg_d0.h[0] = TASK_REPLAY;
        task_start();
        *(u8 *)(reg_a0 + 5) = 3;
        return;
    }
    *(u16 *)(reg_a5 + 12) = step;
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
}

void (*replay_screen_routines[])(void) = {
    replay_run_start,
    replay_result_menu,
    replay_exit,
    replay_playback_start,
    replay_run_end,
};

u8 D_0028DE40[4] = {
    0x00, 0x02, 0x00, 0x00,
};

u8 D_0028DE44[4] = {
    0x02, 0x04, 0x06, 0x00,
};

u8 attract_step_game_start_table[8] = {
    0x00, 0x02, 0x04, 0x06, 0x08, 0x00, 0x00, 0x00,
};

/* .sbss (the compiler lays these out in reverse) */
u32 g_replay_fade_id;
u8 g_simulation_active __attribute__((aligned(4)));
u8 g_replay_mode __attribute__((aligned(4)));
u8 g_replay_mode_begun __attribute__((aligned(4)));
u8 g_replay_buffer_state;
s32 g_replay_position;
u8 g_replay_begin_pending __attribute__((aligned(4)));
u8 g_replay_watch_after_run __attribute__((aligned(4)));
u8 D_0028ED64 __attribute__((aligned(4)));
u8 D_0028ED60 __attribute__((aligned(4)));
u8 D_0028ED5C __attribute__((aligned(4)));
u8 g_replay_taken_over __attribute__((aligned(4)));
u16 D_0028ED54;
s32 D_0028ED50;
u16 D_0028ED4C __attribute__((aligned(4)));
u16 D_0028ED48;
s32 D_0028ED44;
u16 D_0028ED40;
s32 g_replay_checksum;

/* .bss (the compiler lays these out in reverse) */
ReplayHeader g_replay_header;
ReplayHeader g_replay_header_saved;
#ifndef DDPDOJ_PC
u16 D_006CB580[54024];
u8 replay_playback_start_buffer_3[9168];
u16 replay_playback_start_buffer_2[8];
u16 replay_playback_start_buffer[392];
u8 g_replay_snapshot[12784];
u16 D_006C58D0[488];
u8 g_replay_file[48];
#endif

#ifdef DDPDOJ_PC
#include "pc_data_alias.h"

PC_DATA_ALIAS(D_006E5BE2, g_replay_header, 0x2);
PC_DATA_ALIAS(D_006E5BE4, g_replay_header, 0x4);
PC_DATA_ALIAS(D_006E5BE6, g_replay_header, 0x6);
PC_DATA_ALIAS(D_006E5BE8, g_replay_header, 0x8);
PC_DATA_ALIAS(D_006E5BEA_as_s16_a, g_replay_header, 0xa);
PC_DATA_ALIAS(D_006E5BEC_as_s16_a, g_replay_header, 0xc);
PC_DATA_ALIAS(D_006E5BEE_as_s16_a, g_replay_header, 0xe);
PC_DATA_ALIAS(D_006E5BF0, g_replay_header, 0x10);
PC_DATA_ALIAS(D_006E5BF2, g_replay_header, 0x12);
PC_DATA_ALIAS(D_006E5BF4, g_replay_header, 0x14);
PC_DATA_ALIAS(D_006E5BF6, g_replay_header, 0x16);
PC_DATA_ALIAS(D_006E5BF8_as_s16_a, g_replay_header, 0x18);
PC_DATA_ALIAS(D_006E5BFA_as_s16_a, g_replay_header, 0x1a);
PC_DATA_ALIAS(D_006E5BFC, g_replay_header, 0x1c);
PC_DATA_ALIAS(D_006E5BFE_as_s16_a, g_replay_header, 0x1e);
PC_DATA_ALIAS(D_006E5C00_as_s16_a, g_replay_header, 0x20);
PC_DATA_ALIAS(D_006E5C02, g_replay_header, 0x22);
PC_DATA_ALIAS(D_006E5C04_as_s16_a, g_replay_header, 0x24);
PC_DATA_ALIAS(D_006E5C06, g_replay_header, 0x26);
PC_DATA_ALIAS(D_006E5C08, g_replay_header, 0x28);
PC_DATA_ALIAS(D_006E5C0A_as_s16_a, g_replay_header, 0x2a);
PC_DATA_ALIAS(D_006E5C0C_as_s16_a, g_replay_header, 0x2c);
PC_DATA_ALIAS(D_006E5C0E, g_replay_header, 0x2e);
PC_DATA_ALIAS(D_006E5C10, g_replay_header, 0x30);
PC_DATA_ALIAS(D_006E5C12, g_replay_header, 0x32);
PC_DATA_ALIAS(D_006E5C14, g_replay_header, 0x34);
#endif
