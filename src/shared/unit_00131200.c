#include "common.h"
#include "task.h"
#include "entity.h"
#include "sdk/ps2sdk.h"

void func_00132420(void);

#ifndef DEATH_LABEL
s32 func_00130D80();
s32 func_00130DB0();
s32 func_00130DC0();
s32 func_00130E00();
s32 func_00130E70();
s32 func_00130EC0();
s32 func_00130F10();
s32 func_00130FB0();
s32 func_00131050();
s32 func_001310F0();
s32 func_00131150();
s32 func_001311A0();
extern u8 g_setting_chute_type;
extern u8 g_setting_coin_mode;

void func_00131200(void) {
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = g_setting_coin_mode;
    reg_d1.b[0] = g_setting_chute_type;
    if (reg_d0.h[0] == 0x12) {
        if (reg_d1.b[0] != 1) {
            func_00130D80();
            return;
        }
        func_00130DB0();
        func_00130DC0();
        return;
    }
    if (reg_d0.h[0] == 0x11) {
        if (reg_d1.b[0] != 1) {
            func_00130E00();
            return;
        }
        func_00130E70();
        func_00130EC0();
        return;
    }
    if (((s16) reg_d0.h[0] < 0x11) && ((s16) reg_d0.h[0] >= 9)) {
        if (reg_d1.b[0] != 1) {
            func_00130F10();
            return;
        }
        func_00130FB0();
        func_00131050();
        return;
    }
    if (reg_d1.b[0] != 1) {
        func_001310F0();
        return;
    }
    func_00131150();
    func_001311A0();
}
#endif

extern u8 D_0028E1E6[];

void func_00131340(void) {
    reg_d0.b[0] = D_0028E1E6[0];
    if (reg_d0.b[0] != 0) {
        D_0028E1E6[0] -= 1;
    }
}

extern u8 D_0028E1DA[];

void func_00131370(void) {
    reg_d0.b[0] = D_0028E1DA[0];
    if (reg_d0.b[0] != 0) {
        D_0028E1DA[0] -= 1;
    }
}

extern u8 D_0028E1E4[];

void func_001313A0(void) {
    reg_d1.b[0] = D_0028E1E4[0];
    reg_d1.b[0] -= reg_d0.b[0];
    if ((s8) reg_d1.b[0] < 0) {
        reg_d1.w = 0;
    }
    D_0028E1E4[0] = reg_d1.b[0];
}

extern u8 D_0028E1D8[];

void func_001313E0(void) {
    reg_d1.b[0] = D_0028E1D8[0];
    reg_d1.b[0] -= reg_d0.b[0];
    if ((s8) reg_d1.b[0] < 0) {
        reg_d1.w = 0;
    }
    D_0028E1D8[0] = reg_d1.b[0];
}

extern s8 D_0028E1FC;
extern s8 D_0028E200;
extern s8 D_0028E204_as_s8;
extern s8 D_0028E208_as_s8;

void coin_counters_pulse(void) {
    D_0028E208_as_s8 = 1;
    D_0028E204_as_s8 = 1;
    D_0028E200 = 1;
    D_0028E1FC = 1;
}

extern s16 g_frame_mod16_as_s16;
extern s16 g_frame_mod8_as_s16;
extern s16 g_frame_mod4_as_s16;
extern s16 g_frame_mod3_as_s16;
extern s16 g_frame_mod2_as_s16;
extern s16 g_game_frame_as_s16;

void frame_counters_reset(void) {
    g_game_frame_as_s16 = 0;
    g_frame_mod2_as_s16 = 0;
    g_frame_mod3_as_s16 = 0;
    g_frame_mod4_as_s16 = 0;
    g_frame_mod8_as_s16 = 0;
    g_frame_mod16_as_s16 = 0;
    rng_cursor = 0;
}

extern s16 D_0028E22C;
extern s16 g_test_switch_on;

void test_switch_read(void) {
    reg_d0.h[0] = (u16) D_0028E22C;
    g_test_switch_on = 0;
    if (!(reg_d0.w & 0x80)) {
        g_test_switch_on = 1;
    }
}

s32 slowdown_reset();                            /* extern */
s32 replay_header_clear();                            /* extern */
extern s16 g_select_screen_active_as_s16;
extern s16 g_test_mode_entered;
extern s16 g_attract_demo_stage_as_s16;
extern s16 g_attract_demo_as_s16;
extern s16 D_0028E3C4;
extern s16 g_debug_build;
extern s16 g_publicity_build;
extern s16 g_location_test_build;
extern s8 g_replay_mode_as_s8;
extern s8 g_simulation_active_as_s8;

void func_00131490(void) {
    D_0028E3C4 = 0;
    g_game_frame_as_s16 = 0;
    g_frame_mod2_as_s16 = 0;
    g_frame_mod3_as_s16 = 0;
    g_frame_mod4_as_s16 = 0;
    g_frame_mod8_as_s16 = 0;
    g_frame_mod16_as_s16 = 0;
    rng_cursor = 0;
    g_location_test_build = 0;
    g_select_screen_active_as_s16 = 0;
    slowdown_reset();
    g_publicity_build = 0;
    g_debug_build = 0;
    g_simulation_active_as_s8 = 0;
    g_replay_mode_as_s8 = 0;
    replay_header_clear();
    g_attract_demo_as_s16 = 0;
    g_attract_demo_stage_as_s16 = 0;
    g_test_mode_entered = 0;
    test_switch_read();
}

extern u16 g_frame_mod16;
extern u16 g_frame_mod8;
extern u16 g_frame_mod4;
extern u16 g_frame_mod3;
extern u16 g_frame_mod2;
extern u16 g_game_frame;

void frame_counters_advance(void) {
    g_game_frame += 1;
    if (g_frame_mod2 & 1) {
        g_frame_mod2 &= 0xFFFE;
    } else {
        g_frame_mod2 |= 1;
    }
    g_frame_mod3 += 1;
    if (g_frame_mod3 == 3) {
        g_frame_mod3 = 0;
    }
    g_frame_mod4 = g_game_frame;
    g_frame_mod8 = g_game_frame;
    g_frame_mod16 = g_game_frame;
    g_frame_mod4 &= 3;
    g_frame_mod8 &= 7;
    g_frame_mod16 &= 0xF;
}

s32 sfx_bonus_count();                            /* extern */
extern u16 D_0028E954;

void func_00131590(void) {
    if (D_0028E954 != 0) {
        D_0028E954 -= 1;
        return;
    }
    D_0028E954 = 3;
    sfx_bonus_count();
}

extern u16 D_0028E950;

void func_001315D0(void) {
    if (D_0028E950 != 0) {
        D_0028E950 -= 1;
        return;
    }
    D_0028E950 = 3;
    sfx_bonus_count();
}

extern u16 D_0028E95C;

void func_00131610(void) {
    if (D_0028E95C != 0) {
        cond_flag = 1;
        return;
    }
    cond_flag = 0;
}

extern s16 g_game_task_handle;
extern s16 D_0028E94C;
extern s16 D_0028E950_as_s16;
extern s16 D_0028E954_as_s16;
extern s16 D_0028E958;
extern s16 D_0028E95C_as_s16;
extern s16 D_0028E960_as_s16;
extern u8 D_002BF410[];
extern u8 D_002BF450[];
extern u8 D_002BF490[];
void func_00131630(void) {
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
    D_0028E94C = 0;
    var_a2 = 0;
    D_0028E950_as_s16 = 0;
    D_0028E954_as_s16 = 0;
    D_0028E958 = 0;
    D_0028E95C_as_s16 = 0;
    D_0028E960_as_s16 = 0;
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

s32 func_00134FB0();
s32 func_0013B190();
s32 func_00171910();
s32 func_00172060();
s32 func_001AD690();
s32 vibration_stop_all(s32, s32);
s32 stage_map_hide();
extern s16 g_players_hidden_as_s16;
extern u8 D_0028E378;
extern u8 D_0028E961;
extern u8 D_0028ED60;
extern u8 g_replay_buffer_state;
extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s16 D_0029976C_as_s16_a[];
extern s16 D_0029976E_as_s16_a[];

#ifdef DEATH_LABEL
extern u16 g_p2_lives;
extern u16 g_p1_lives;
extern u16 death_D_00290434;
extern u16 death_D_00290438;
#endif

void func_00131700(void) {
    *(s8 *)(reg_a5 + 3) = 1;
    *(s8 *)(reg_a5 + 7) = 0;
    *(s8 *)(reg_a5 + 6) = 4;
    D_0028E378 = 0xFF;
    vibration_stop_all(4, 1);
    stage_map_hide();
    func_0013B190();
    func_00131630();
    func_001AD690();
    D_0028E961 |= 1;
    D_0028E961 |= 8;
    func_00171910();
    D_00299768[0] = 0;
    D_0028E95C_as_s16 = 1;
    D_0029976A[0] = 0;
    D_0028E958 = 1;
    D_0029976C_as_s16_a[0] = 0;
    D_0029976E_as_s16_a[0] = 0;
    func_00172060();
    func_00134FB0();
    D_0028ED60 = 0;
    g_players_hidden_as_s16 = 1;
    g_replay_buffer_state = 2;
#ifdef DEATH_LABEL
    death_D_00290434 = g_p1_lives;
    death_D_00290438 = g_p2_lives;
#endif
}

extern u16 D_0028E960;


void func_001317D0(void) {
    D_0028E960 = 0;
    D_0028E95C = 0;
    task_stop_self();
}

s32 stage_counts_reset();                            /* extern */
s32 func_0013B190();                            /* extern */
s32 p1_next_stage_setup();                            /* extern */
s32 p2_next_stage_setup();                            /* extern */
s32 func_001AD720();                            /* extern */
#ifdef DEATH_LABEL
extern u8 death_D_00290DC0;
extern u16 g_game_completed;
#endif
extern s16 g_score_panel_intro_as_s16;
extern s16 g_boss_present_as_s16;

void func_001317E0(void) {
    func_0013B190();
    task_reset_all();
    func_00131630();
    stage_counts_reset();
    func_001AD720();
    g_boss_present_as_s16 = 0;
    p1_next_stage_setup();
    p2_next_stage_setup();
    g_score_panel_intro_as_s16 = 0;
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

s32 func_00224A90();                            /* extern */

void func_00131840(void) {
    func_00224A90();
    reg_d0.h[0] = TASK_REPLAY;
    task_start();
    *(s8 *)(reg_a0 + 5) = 1;
}

s32 stage_counts_reset();
s32 func_00134FE0();
s32 func_00135070();
s32 func_0013AFF0();
s32 func_0013B2E0();
s32 func_0013C300();
s32 func_0013C350();
s32 p1_next_stage_setup();
s32 p2_next_stage_setup();
s32 func_00171990();
s32 func_001719A0();
s32 func_001719B0();
s32 func_001719D0();
s32 func_001720E0();
s32 func_00172250();
s32 func_00172260();
s32 sprite_palette_load();
s32 func_001AD720();
s32 replay_start_run_end();
extern u16 D_00269840[];
extern s16 g_players_stage_clear_as_s16;
extern s16 g_player_shots_disabled_as_s16;
extern u8 g_game_frame_ran;
extern u16 g_p2_score_digits;
extern u16 g_p1_score_digits;
extern u16 g_p2_score_billions;
extern u16 g_p1_score_billions;
extern s32 g_p2_score_as_s32;
extern s32 g_p1_score_as_s32;
extern s8 D_0028EC58;
extern s8 g_replay_begin_pending_as_s8;
extern u8 g_replay_mode;
extern u8 g_simulation_active;
extern u16 g_sprite_palette_as_u16_a[];
extern u16 D_002BF410_as_u16_a[];
extern u16 D_002BF450_as_u16_a[];
#ifdef DEATH_LABEL
s32 func_0013B920();
s32 music_fade_out();
extern u8 D_00269920[];
extern u8 D_002698B0[];
extern u8 g_game_mode;
extern u16 g_p2_lives;
extern u16 g_p1_lives;
extern u16 death_D_00290434;
extern u16 death_D_00290438;
extern s8 death_D_00290568_as_s8;
#endif

void func_00131880(void) {
    s8 var_a0;
    u16 temp_a0_3;
    u16 temp_v1_3;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_v1;
    u8 temp_v1_2;

    temp_v1 = *(u8 *)(reg_a5 + 3);
    if (temp_v1 == 0) {
        func_00131700();
        return;
    }
    if (temp_v1 == 2) {
        func_001317D0();
        return;
    }
    func_00172260();
    temp_a0 = *(u8 *)(reg_a5 + 7);
    if (temp_a0 == 4) {
        func_001719B0();
        if (cond_flag == 0) {
            *(u8 *)(reg_a5 + 3) = 2U;
        }
    }
    temp_a0_2 = *(u8 *)(reg_a5 + 7);
    if (temp_a0_2 == 3) {
        if ((g_replay_mode == 2) && (D_0028ED60 == 0)) {
            replay_start_run_end(temp_a0_2);
            *(u8 *)(reg_a5 + 3) = 2U;
            return;
        }
        printf((const char *)"end sco1up  [%x]\n", g_p1_score_as_s32);
        printf((const char *)"end sco1cnt [%x]\n", (s32) g_p1_score_digits);
        printf((const char *)"end sco1oku [%x]\n", (s32) g_p1_score_billions);
        printf((const char *)"end sco2up  [%x]\n", g_p2_score_as_s32);
        printf((const char *)"end sco2cnt [%x]\n", (s32) g_p2_score_digits);
        printf((const char *)"end sco2oku [%x]\n", (s32) g_p2_score_billions);
        g_game_frame_ran = 0;
        func_00135070();
        *(s8 *)(reg_a5 + 7) = 0x1E;
        goto block_after;
    }
    if (temp_a0_2 == 0x1E) {
        if (D_0028EC58 != 0) {
            if (g_replay_mode == 1) {
                g_replay_begin_pending_as_s8 = 1;
            }
            g_players_stage_clear_as_s16 = 0;
            D_0028E961 &= 0xFC;
        }
        if (g_game_frame_ran != 0) {
            printf((const char *)"begin sco1up  [%x]\n", g_p1_score_as_s32);
            printf((const char *)"begin sco1cnt [%x]\n", (s32) g_p1_score_digits);
            printf((const char *)"begin sco1oku [%x]\n", (s32) g_p1_score_billions);
            printf((const char *)"begin sco2up  [%x]\n", g_p2_score_as_s32);
            printf((const char *)"begin sco2cnt [%x]\n", (s32) g_p2_score_digits);
            printf((const char *)"begin sco2oku [%x]\n", (s32) g_p2_score_billions);
            *(s8 *)(reg_a5 + 7) = 4;
        }
    }
block_after:
    if (*(u8 *)(reg_a5 + 7) == 2) {
        if ((g_replay_mode == 2) && (D_0028ED60 == 0)) {
            *(u8 *)(reg_a5 + 7) = 3U;
            return;
        }
        reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
        func_00134FE0();
        stage_counts_reset();
        D_0028E958 = 0;
        func_00172250();
        g_game_frame_ran = 0;
        func_001719A0();
        func_001AD720();
        g_players_hidden_as_s16 = 0;
        *(u8 *)(reg_a5 + 7) = 3U;
        goto block_25;
    }
block_25:
    temp_v1_2 = *(u8 *)(reg_a5 + 7);
#ifdef DEATH_LABEL
    if (temp_v1_2 == 0x16) {
        reg_a6 = D_002BF490;
        func_00132420();
        if ((g_game_mode == 2) && (death_D_00290568_as_s8 == 1)) {
            death_D_00290568_as_s8 = 0;
            g_p1_lives = death_D_00290434;
            g_p2_lives = death_D_00290438;
            if ((g_simulation_active != 0) || (g_replay_mode == 2)) {
                reg_a0 = (u8 *)D_00269920;
            } else {
                reg_a0 = (u8 *)D_002698B0;
            }
            *(u8 *)(reg_a5 + 7) = 0xB;
            func_0013B920();
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
        func_00132420();
        return;
    }
    if (temp_v1_2 == 0xB) {
        reg_a6 = D_002BF490;
        func_00132420();
        reg_d0.h[1] = *(u16 *)(reg_a5 + 8);
        reg_d0.h[0] = *(u16 *)(reg_a5 + 0xA);
        func_0013C350();
        if (cond_flag == 0) {
            reg_d0.h[1] = *(u16 *)(reg_a5 + 8);
            reg_d0.h[0] = *(u16 *)(reg_a5 + 0xA);
            if (g_simulation_active != 0) {
                func_00131840();
                *(u8 *)(reg_a5 + 3) = 2U;
                return;
            }
            func_0013C300();
            p1_next_stage_setup();
            p2_next_stage_setup();
            g_boss_present_as_s16 = 0;
            g_player_shots_disabled_as_s16 = 0;
            D_0028E961 &= 0xF7;
            *(u8 *)(reg_a5 + 7) = 2U;
            return;
        }
    }
    if (*(u8 *)(reg_a5 + 7) == 1) {
        reg_a6 = D_002BF490;
        func_00132420();
    }
    if (*(u8 *)(reg_a5 + 7) == 0xA) {
        reg_a6 = D_002BF490;
        func_00132420();
        *(u8 *)(reg_a5 + 6) -= 1;
        if (*(u8 *)(reg_a5 + 6) == 0) {
            func_00171990();
            reg_a0 = (u8 *)(D_00269840);
            func_0013B2E0();
            *(u8 *)(reg_a5 + 7) = 1U;
            reg_a0 = (u8 *)(g_sprite_palette_as_u16_a);
            reg_a1 = (u8 *)(D_002BF450_as_u16_a);
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
            reg_a0 = (u8 *)(D_002BF450_as_u16_a);
            reg_a1 = (u8 *)(D_002BF410_as_u16_a);
            reg_d7.w = 0x1F;
            do {
                temp_a0_3 = *(u16 *)reg_a0;
                reg_d0.h[0] = temp_a0_3;
                reg_a0 += 2;
                reg_d1.h[0] = 0x10;
                func_0013AFF0();
                *(u16 *)reg_a1 = reg_d0.h[0];
                reg_a1 += 2;
            } while ((s16)(reg_d7.h[0]--) >= 0);
            reg_a0 = (u8 *)(D_002BF410_as_u16_a);
            reg_d0.h[0] = 0x17;
            sprite_palette_load();
        }
    }
    if (*(u8 *)(reg_a5 + 7) == 0) {
        func_001720E0();
        if (cond_flag == 0) {
            *(u8 *)(reg_a5 + 7) = 0xAU;
        }
    }
    func_001719D0();
}

extern s32 reg_a1_as_s32;
extern void sprite_draw_layer1(void);

void func_00132210(void)
{
    reg_d2.h[0] = (s16)reg_d7.h[0] & 0xF;
    reg_d2.w = ((u32 *)reg_a1_as_s32)[reg_d2.h[0]];
    reg_d1.h[0] -= 0x200;
    sprite_draw_layer1();
}

extern u16 D_00269AB0[];
extern u8 D_00269ADE[];
extern u16 D_00269AE0[];
extern u16 D_00269B10[];
extern u16 D_00269B40[];

void func_00132250(void) {
    if (*(s16 *)(reg_a6 + 0x3E) >= 0) {
        reg_d1.w = 0;
        reg_a0 = (u8 *)(D_00269AB0);
        reg_d1.h[0] = *(u16 *)(reg_a6 + 0x3E);
        reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0x4C) += reg_d0.h[0];
        reg_a1 = (u8 *)(D_00269AE0);
        reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a1;
        *(u16 *)(reg_a6 + 0x4E) += reg_d0.h[0];
        reg_a1 = (u8 *)(D_00269B10);
        reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a1;
        *(u16 *)(reg_a6 + 0x50) += reg_d0.h[0];
        reg_a1 = (u8 *)(D_00269B40);
        reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a1;
        *(u16 *)(reg_a6 + 0x52) += reg_d0.h[0];
        *(u16 *)(reg_a6 + 0x3E) += 2;
        reg_a0 += reg_d1.w;
        if (D_00269ADE == reg_a0) {
            *(u16 *)(reg_a6 + 0x3E) = 0xFFFF;
        }
    }
}

s32 func_0012FB00();
s32 func_00133070();
s32 func_001330F0();
s32 func_00133840();
s32 func_0013B920();
s32 input_get_p1_pressed();
s32 input_get_p2_pressed();
s32 music_fade_out();
s32 score_add_masked();
s32 func_00200EE0();
s32 stage_load_step();
s32 func_0022B660();
extern u16 D_00261F30[];
extern u16 D_00261FF0[];
extern u16 D_00262030[];
extern u16 D_00262070[];
extern u16 D_002620B0[];
extern u16 D_002622B0[];
extern u16 D_002698B0_as_u16_a[];
extern u16 D_00269920_as_u16_a[];
extern u16 D_00269A10[];
extern u16 D_00269A60[];
extern u8 D_00269AAE[];
extern u8 D_0028E2A0;
extern u8 D_0028E2A4;
extern s16 g_loaded_stage;
extern u16 g_boss_hits;
extern u8 g_boss_present;
extern u16 g_stage;
extern u16 g_p2_stage_stars_small;
extern u16 g_p2_stage_stars_large;
extern u16 g_p1_stage_stars_small;
extern u16 g_p1_stage_stars_large;
extern s8 D_0028EC24;
extern s8 D_0028ED60_as_s8;
extern u16 g_side_scroll_x[];
extern u16 g_side_scroll_step[];
extern s16 g_player2[];
extern s16 g_player1[];

#ifdef DEATH_LABEL
s32 func_00141640();
s32 func_001A7E90();
s32 func_001A8070();
s32 func_0013FCA0();
s32 func_0013FCE0();
s32 p1_bomb_stock_draw();
s32 p2_bomb_stock_draw();
extern s16 g_player2[];
extern s16 g_player1[];
extern u8 g_game_mode;
extern u8 death_D_00290568;
#endif

void func_00132420(void) {
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
        reg_a0 = (u8 *)(D_00261FF0);
        reg_d0.h[0] = 0x12;
        sprite_palette_load();
        reg_a0 = (u8 *)(D_00262030);
        reg_d0.h[0] = 0x13;
        sprite_palette_load();
        reg_a0 = (u8 *)(D_00262070);
        reg_d0.h[0] = 0x14;
        sprite_palette_load();
        reg_a0 = (u8 *)(D_002620B0);
        reg_d0.h[0] = 0x15;
        sprite_palette_load();
        reg_a0 = (u8 *)(D_002622B0);
        reg_d0.h[0] = 0x16;
        sprite_palette_load();
        reg_a0 = (u8 *)(D_00261FF0);
        reg_d0.h[0] = 0x10;
        sprite_palette_load();
        return;
    }
    if (!(v1 & 4)) {
        *(u8 *)(reg_a6 + 3) = (u8) (v1 | 4);
        *(u16 *)(reg_a6 + 4) = 1U;
        func_0012FB00();
        return;
    }
    t8 = *(u16 *)(reg_a6 + 4);
    t16 = (u8 *)(reg_a6 + 4);
    if (t8 != 0) {
        *(u16 *)(reg_a6 + 4) = (u16) (t8 - 1);
        if (*(u16 *)(reg_a6 + 4) != 0) goto next_290;
        {
            reg_a0 = (u8 *)(D_00269A10);
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
            reg_a0 = (u8 *)(D_00269A60);
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
            func_001330F0();
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
                    func_00200EE0();
                    *(u16 *)(reg_a6 + 0x18) = (u16) reg_d2.h[0];
                    t1 = reg_d5.h[0];
                    reg_d5.h[0] = t1 * 0xA;
                    *(u16 *)(reg_a6 + 0x1A) = (u16) reg_d5.h[0];
                    reg_d0.h[0] = g_p1_stage_stars_large;
                    reg_d5.h[0] = reg_d0.h[0];
                    func_00200EE0();
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
                    func_00200EE0();
                    *(u16 *)(reg_a6 + 0x22) = (u16) reg_d2.h[0];
                    t2 = reg_d5.h[0];
                    reg_d5.h[0] = t2 * 0xA;
                    *(u16 *)(reg_a6 + 0x24) = (u16) reg_d5.h[0];
                    reg_d0.h[0] = g_p2_stage_stars_large;
                    reg_d5.h[0] = reg_d0.h[0];
                    func_00200EE0();
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
        func_001330F0();
        func_00133840();
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
                if ((g_replay_mode == 2) && (D_0028EC24 == 1)) {
                    input_get_p2_pressed();
                }
                t12 = reg_d0.h[0] & 0x70;
                reg_d0.h[0] = t12;
                if (t12 & 0xFFFF) {
                    reg_d0.h[0] = reg_d6.h[0];
                    func_00200EE0();
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
                    func_00131590();
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
                        func_00131590();
                    }
                }
            }
            reg_d6.h[0] = *(u16 *)(reg_a6 + 0x24);
            reg_d6.h[0] += *(u16 *)(reg_a6 + 0x28);
            if (reg_d6.h[0] != 0) {
                input_get_p2_pressed();
                if ((g_replay_mode == 2) && (D_0028EC24 == 0)) {
                    input_get_p1_pressed();
                }
                t15 = reg_d0.h[0] & 0x70;
                reg_d0.h[0] = t15;
                if (t15 & 0xFFFF) {
                    reg_d0.h[0] = reg_d6.h[0];
                    func_00200EE0();
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
                    func_001315D0();
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
                        func_001315D0();
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
                func_00132250();
                if (*(s16 *)(reg_a6 + 0x3E) < 0) {
                    g_boss_present |= 4;
                }
            }
#ifdef DEATH_LABEL
            if ((g_boss_present & 2) && (v2 = *(u8 *)(reg_a5 + 7), (v2 != 0xB)) && (v2 != 0x15) && (v2 != 0x16)) {
                if (*(u16 *)(reg_a5 + 4) != 0) {
                    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
                    func_00134FE0();
                } else {
                    reg_d0.h[0] = 0;
                    func_00134FE0();
                }
                if ((*(u16 *)(reg_a5 + 4) == 0) && (g_simulation_active != 1)) {
                    reg_a0 = (u8 *)(D_00269920_as_u16_a);
                    *(u8 *)(reg_a5 + 7) = 0x15U;
                    D_0028ED60_as_s8 = 1;
                    func_00141640();
                    if (g_player1[0] < 0) {
                        func_001A7E90();
                        func_0013FCA0();
                        p1_bomb_stock_draw();
                    }
                    if (g_player2[0] < 0) {
                        func_001A8070();
                        func_0013FCE0();
                        p2_bomb_stock_draw();
                    }
                    reg_d0.h[0] = 0x13;
                    task_start();
                } else if (g_game_mode == 2) {
                    death_D_00290568 = 0;
                    reg_a0 = (u8 *)(D_00269920_as_u16_a);
                    *(u8 *)(reg_a5 + 7) = 0x16U;
                    func_00141640();
                    if (g_player1[0] < 0) {
                        func_001A7E90();
                        func_0013FCA0();
                        p1_bomb_stock_draw();
                    }
                    if (g_player2[0] < 0) {
                        func_001A8070();
                        func_0013FCE0();
                        p2_bomb_stock_draw();
                    }
                    reg_d0.h[0] = 0x13;
                    task_start();
                } else {
                    if ((g_simulation_active != 0) || (g_replay_mode == 2)) {
                        reg_a0 = (u8 *)D_00269920_as_u16_a;
                    } else {
                        reg_a0 = (u8 *)D_002698B0_as_u16_a;
                    }
                    *(u8 *)(reg_a5 + 7) = 0xBU;
                    func_0013B920();
                    *(u16 *)(reg_a5 + 8) = (u16) reg_d0.h[1];
                    *(u16 *)(reg_a5 + 0xA) = (u16) reg_d0.h[0];
                }
                reg_d1.w = 0;
                music_fade_out();
            }
#else
            if ((g_boss_present & 2) && (v2 = *(u8 *)(reg_a5 + 7), (v2 != 0xB)) && (v2 != 0x15)) {
                if ((g_simulation_active != 0) || (v2 = g_replay_mode, (v2 == 2))) {
                    if (D_0028E2A4 != 0) {
                        D_0028E2A4 -= 1;
                        return;
                    }
                    D_0028E2A4 = 0;
                    D_0028E2A0 = 0;
                    goto block_77;
                }
block_77:
                t4 = *(u16 *)(reg_a5 + 4);
                if (t4 != 0) {
                    if ((g_simulation_active != 0) || (g_replay_mode == 2)) {
                        D_0028E2A4 = 0;
                        D_0028E2A0 = 0;
                    } else {
                        reg_d0.h[0] = t4;
                        func_00134FE0();
                        if (D_0028E2A4 != 0) {
                            D_0028E2A4 -= 1;
                        }
                        if ((g_loaded_stage != g_stage) && (D_0028E2A4 == 0)) {
                            stage_load_step(g_loaded_stage);
                        }
                    }
                    if ((D_0028E2A0 == 0) && (func_00133070() != 0)) {
                        if (func_0022B660() != 0) {
                            D_0028E2A0 = 1;
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
                        reg_a0 = (u8 *)(D_00269920_as_u16_a);
                        *(u8 *)(reg_a5 + 7) = 0x15U;
                        D_0028ED60_as_s8 = 1;
                        reg_d0.h[0] = 0x13;
                        task_start();
                    } else {
                        if ((g_simulation_active != 0) || (g_replay_mode == 2)) {
                            reg_a0 = (u8 *)D_00269920_as_u16_a;
                        } else {
                            reg_a0 = (u8 *)D_002698B0_as_u16_a;
                        }
                        *(u8 *)(reg_a5 + 7) = 0xBU;
                        func_0013B920();
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
