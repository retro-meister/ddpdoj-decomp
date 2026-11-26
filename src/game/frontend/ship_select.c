#include "common.h"
#include "player.h"
#include "task.h"
#include "entity.h"

s32 color_at_brightness();
s32 sprite_palette_load();
s32 velocity_from_dir256();
extern u8 D_0028DF0C;
extern u8 D_0028DF10;
extern u16 D_0029BD80[];
extern u16 D_0029BDC0[];
extern u8 D_0029BE00[];

void ship_select_palette_pulse(void) {
    u8 *s_a0;
    u8 *s_a1;
    u8 *s_a2;
    u8 *s_a3;
    u8 *s_a4;
    u8 *s_a5;
    u8 *s_a6;
    u32 s_d0;
    u32 s_d1;
    u32 s_d2;
    u32 s_d3;
    u32 s_d4;
    u32 s_d5;
    u32 s_d6;
    u32 s_d7;
    u32 t;

    s_d0 = reg_d0.w;
    s_d1 = reg_d1.w;
    s_d2 = reg_d2.w;
    s_d3 = reg_d3.w;
    s_d4 = reg_d4.w;
    s_d5 = reg_d5.w;
    s_d6 = reg_d6.w;
    s_d7 = reg_d7.w;
    s_a0 = reg_a0;
    s_a1 = reg_a1;
    s_a2 = reg_a2;
    s_a3 = reg_a3;
    s_a4 = reg_a4;
    s_a5 = reg_a5;
    s_a6 = reg_a6;
    if (D_0028DF0C != 0) goto block_exit;
    reg_a6 = (u8 *)D_0029BE00;
    if (ENTITY(reg_a6)->flags.sb[0] >= 6) goto block_set;
    if (*(s8 *)(reg_a6 + 0x70) < 6) goto next_1;
block_set:
    D_0028DF0C = 1;
    goto block_exit;
next_1:
    reg_a0 = (u8 *)D_0029BDC0;
    reg_d1.w = 0;
    reg_a1 = (u8 *)D_0029BD80;
    reg_d0.h[0] = 0x50;
    D_0028DF10 += 6;
    reg_d1.b[0] = D_0028DF10;
    velocity_from_dir256();
    reg_d6.h[0] = 0x800;
    reg_d6.h[0] -= reg_d2.h[0];
    reg_d7.w = 0x1F;
    reg_d6.h[0] >>= 6;
loop_2:
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] = reg_d6.h[0];
    color_at_brightness();
    *(u16 *)reg_a1 = reg_d0.h[0];
    reg_a1 += 2;
    t = reg_d7.h[0] - 1;
    reg_d7.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
    reg_a0 = (u8 *)D_0029BD80;
    reg_d0.h[0] = 0xB;
    sprite_palette_load();
block_exit:
    reg_d0.w = s_d0;
    reg_d1.w = s_d1;
    reg_d2.w = s_d2;
    reg_d3.w = s_d3;
    reg_d4.w = s_d4;
    reg_d5.w = s_d5;
    reg_d6.w = s_d6;
    reg_d7.w = s_d7;
    reg_a0 = s_a0;
    reg_a1 = s_a1;
    reg_a2 = s_a2;
    reg_a3 = s_a3;
    reg_a4 = s_a4;
    reg_a5 = s_a5;
    reg_a6 = s_a6;
}

s32 text_layer_clear();
s32 attract_demo_state_clear();
s32 music_play_bgm1();
s32 voice_select();
s32 text_palette_load();
s32 join_select_objects_clear();
s32 slowdown_reset();
s32 replay_header_clear();
extern u8 D_0025F770[];
extern u8 D_00260930[];
extern u8 D_00260970[];
extern u8 D_002609B0[];
extern u8 D_002609F0[];
extern u8 D_00260A30[];
extern u8 D_00260CB0[];
extern u8 D_00260CF0[];
extern u8 D_00260D30[];
extern u8 D_00260D70[];
extern u8 D_00260DB0[];
extern u8 D_00260DF0[];
extern u8 D_00260E30[];
extern u8 D_00260E70[];
extern u8 g_default_text_palette[];
extern s16 D_0028DF14;
extern s16 D_0028DF18;
extern u16 g_attract_demo;
extern u8 g_replay_buffer_state;
extern u8 g_replay_mode;
extern u8 g_simulation_active;

void ship_select_task_begin(void) {
    *(s8 *)(reg_a5 + 3) = 1;
    join_select_objects_clear();
    attract_demo_state_clear();
    g_attract_demo = 0;
    g_simulation_active = 0;
    replay_header_clear();
    g_replay_mode = 1;
    g_replay_buffer_state = 2;
    slowdown_reset();
    D_0028DF14 = 0;
    D_0028DF0C = 0;
    reg_a0 = (u8 *)D_0029BE00;
    reg_d0.h[0] = 0x6F;
    do {
        *(u16 *)reg_a0 = 0U;
        reg_a0 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *)D_0029BE00;
    reg_d0.w = 1;
    do {
        *(s8 *)(reg_a0 + 1) = 0;
        *(u8 *)reg_a0 = 0;
        reg_tmp.w = -1U;
        *(u16 *)(reg_a0 + 0x56) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a0 + 0x58) = (u16) reg_tmp.h[0];
        *(s16 *)(reg_a0 + 0x60) = 0;
        *(s16 *)(reg_a0 + 0x62) = 0;
        *(s16 *)(reg_a0 + 0x64) = 1;
        *(s16 *)(reg_a0 + 0x66) = 0;
        *(s16 *)(reg_a0 + 0x68) = 0;
        *(s16 *)(reg_a0 + 0x6A) = 2;
        *(s16 *)(reg_a0 + 0x6C) = 0x140;
        reg_a0 += 0x70;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    D_0028DF18 = 0;
    reg_a0 = (u8 *)D_0029BE00;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 5);
    if (reg_d0.b[0] == 3) {
        *(s8 *)(reg_a0 + 1) = 1;
        *(s8 *)(reg_a0 + 0x71) = 1;
    }
    if (reg_d0.b[0] == 2) {
        *(s8 *)(reg_a0 + 0x71) = 1;
    }
    if (reg_d0.b[0] == 1) {
        *(s8 *)(reg_a0 + 1) = 1;
    }
    *(s8 *)(reg_a5 + 2) = 0;
    *(u8 *)(reg_a5 + 5) = 0xFFU;
    *(u8 *)(reg_a5 + 4) = 0xFFU;
    *(u8 *)(reg_a5 + 7) = 0xFFU;
    *(u8 *)(reg_a5 + 6) = 0xFFU;
    *(u8 *)(reg_a5 + 9) = 0xFFU;
    *(u8 *)(reg_a5 + 8) = 0xFFU;
    *(s16 *)(reg_a5 + 0xA) = 0;
    text_layer_clear();
    reg_a0 = (u8 *)g_default_text_palette;
    reg_d0.w = 0;
    text_palette_load();
    reg_a0 = (u8 *)D_0025F770;
    reg_d0.w = 2;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260930;
    reg_d0.w = 0x18;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260970;
    reg_d0.w = 0x19;
    sprite_palette_load();
    reg_a0 = (u8 *)D_002609B0;
    reg_d0.w = 0x1B;
    sprite_palette_load();
    reg_a0 = (u8 *)D_002609F0;
    reg_d0.w = 0x1A;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260A30;
    reg_d0.w = 0x1C;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260CB0;
    reg_d0.w = 0x12;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260D70;
    reg_d0.w = 0x13;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260E70;
    reg_d0.w = 0x14;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260DB0;
    reg_d0.w = 0x10;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260CF0;
    reg_d0.w = 0x15;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260E30;
    reg_d0.w = 0x16;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260DF0;
    reg_d0.w = 0x17;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260D30;
    reg_d0.w = 0x11;
    sprite_palette_load();
    reg_d0.h[0] = TASK_GAME;
    task_start();
    *(s16 *)(reg_a0 + 4) = 0;
    music_play_bgm1();
    voice_select();
    reg_a0 = (u8 *)D_00260CB0;
    reg_a1 = (u8 *)(D_0029BDC0);
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
    reg_a0 += 2;
    reg_a1 += 2;
}

extern u8 D_0028E304;
extern u16 g_loop;

void ship_select_task_finish(void) {
    task_stop_self();
    if ((D_0028E304 != 0) && (g_loop == 0)) {
        g_loop = 1;
    }
}


s32 p1_credit_spend_one();
s32 p2_credit_spend_one();
s32 doll_select_start();
s32 doll_select_confirm();
s32 doll_select_input();
s32 ship_select_ship_begin();
s32 ship_select_ship_confirm();
s32 ship_select_ship_update();
s32 input_get_p1_held();
s32 input_get_p2_held();
s32 select_side_begin();
s32 select_palettes_load_both();
s32 select_side_draw();
#ifdef DEATH_LABEL
s32 text_layer_clear();
s32 voice_ok();
s32 music_stop();
s32 text_palette_load();
s32 fade_white_start();
s32 fade_reset();
extern u8 g_default_text_palette[];
extern u8 g_game_mode;
extern u8 D_0028E7B4;
extern u16 D_00684C80[];
#endif

void ship_select_task(void) {
    u8 t1;

    t1 = *(u8 *)(reg_a5 + 3);
    if (t1 == 0) {
        ship_select_task_begin();
        return;
    }
    if (t1 == 2) {
        ship_select_task_finish();
        return;
    }
    *(s8 *)(reg_a5 + 2) = 0;
    reg_a6 = (u8 *)D_0029BE00;
    reg_d7.w = 1;
    do {
        if (ENTITY(reg_a6)->flags.b[1] != 0) {
            if (ENTITY(reg_a6)->flags.b[0] == 3) {
                doll_select_start();
            }
            if (ENTITY(reg_a6)->flags.b[0] == 4) {
                doll_select_input();
            }
#ifdef DEATH_LABEL
            if (ENTITY(reg_a6)->flags.b[0] == 5) {
                doll_select_confirm();
                fade_reset();
                fade_white_start();
                g_game_mode = 2;
                text_layer_clear();
                reg_d0.w = 0;
                reg_a0 = (u8 *)g_default_text_palette;
                text_palette_load();
                D_00684C80[0] = 0xFF;
                D_00684C80[1] = 0xFF;
                D_00684C80[2] = 0xFF;
                D_00684C80[3] = 0xFF;
                D_00684C80[9] = 0xFF;
                if (D_0028E7B4 & 1) {
                    D_00684C80[0] = *(u8 *)(reg_a5 + 9);
                    D_00684C80[1] = *(u8 *)(reg_a5 + 5);
                    D_00684C80[9] = D_00684C80[1];
                } else {
                    D_00684C80[2] = *(u8 *)(reg_a5 + 8);
                    D_00684C80[3] = *(u8 *)(reg_a5 + 4);
                    D_00684C80[9] = D_00684C80[3];
                }
                task_stop_self();
                voice_ok();
                music_stop();
                reg_d0.h[0] = 0x15;
                task_start();
                return;
            }
#else
            if (ENTITY(reg_a6)->flags.b[0] == 5) {
                doll_select_confirm();
            }
            if (ENTITY(reg_a6)->flags.b[0] == 6) {
                select_palettes_load_both();
            }
            if (ENTITY(reg_a6)->flags.b[0] == 7) {
                select_side_draw();
            }
#endif
            if (ENTITY(reg_a6)->flags.b[0] == 0) {
                ship_select_ship_begin();
            }
            if (ENTITY(reg_a6)->flags.b[0] == 1) {
                ship_select_ship_update();
            }
            if (ENTITY(reg_a6)->flags.b[0] == 2) {
                ship_select_ship_confirm();
            }
            if ((s32) ENTITY(reg_a6)->flags.b[0] < 7) {
                *(u8 *)(reg_a6 + 0x30) -= 1;
                if (*(u8 *)(reg_a6 + 0x30) == 0) {
                    *(u8 *)(reg_a6 + 0x30) = 2U;
                    if (*(u16 *)(reg_a6 + 0x2E) == 0) {
                        *(s8 *)(reg_a6 + 0x31) = 1;
                    } else {
                        reg_d0.w = 1;
                        reg_d1.b[0] = *(u8 *)(reg_a6 + 0x2E);
                        if (reg_d1.b[0] == 0) {
                            reg_d1.b[0] = 0x99;
                        } else if (reg_d1.b[0] & 0xF) {
                            reg_d1.b[0] = reg_d1.b[0] - 1;
                        } else {
                            reg_d1.b[0] = (reg_d1.b[0] - 0x10) & 0xF0;
                            reg_d1.b[0] |= 9;
                        }
                        if (reg_d1.b[0] == 0x99) {
                            *(u8 *)(reg_a6 + 0x2F) -= 1;
                        }
                        *(u8 *)(reg_a6 + 0x2E) = (u8) reg_d1.b[0];
                    }
                }
            }
        } else if ((reg_d7.h[0] != 0) && (D_0028E304 == 0)) {
            input_get_p1_held();
            if ((reg_d0.w & 0x8000) && ((reg_a0 = (u8 *)D_0029BE00, (*(u8 *)(reg_a0 + 0x71) == 0)) || ((s32) *(u8 *)(reg_a0 + 0x70) < 6))) {
                p1_credit_spend_one();
                if (cond_flag == 0) {
                    ENTITY(reg_a6)->flags.sb[1] = 1;
                }
            }
        } else if (D_0028E304 == 0) {
            input_get_p2_held();
            if ((reg_d0.w & 0x8000) && ((reg_a0 = (u8 *)D_0029BE00, (*(u8 *)(reg_a0 + 1) == 0)) || ((s32) *(u8 *)reg_a0 < 6))) {
                p2_credit_spend_one();
                if (cond_flag == 0) {
                    ENTITY(reg_a6)->flags.sb[1] = 1;
                }
            }
        }
        select_side_begin();
        reg_a6 += 0x70;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.w = 3;
    reg_a6 = (u8 *)D_0029BE00;
    if (ENTITY(reg_a6)->flags.b[1] != 0) {
        reg_d0.h[0] &= 0xFFFE;
        if (ENTITY(reg_a6)->flags.b[0] == 8) {
            reg_d0.h[0] |= 1;
        }
    }
    if (*(u8 *)(reg_a6 + 0x71) != 0) {
        reg_d0.h[0] &= 0xFFFD;
        if (*(u8 *)(reg_a6 + 0x70) == 8) {
            reg_d0.h[0] |= 2;
        }
    }
    if (reg_d0.h[0] == 3) {
        *(u8 *)(reg_a5 + 3) = 2U;
    }
    ship_select_palette_pulse();
}

s32 ship_palettes_load();
s32 player_panel_show_unless_step_4();
s32 replay_start_state_save();
extern u16 g_select_screen_active;
extern u16 g_p2_ship_type;
extern u16 g_p1_ship_type;
extern s16 g_player2[];
extern s16 g_player1[];
extern u8 g_replay_start_state[];

void select_step2_task_begin(void) {
    *(s8 *)(reg_a5 + 3) = 1;
    join_select_objects_clear();
    D_0028DF14 = 0;
    g_select_screen_active = 1;
    reg_a0 = (u8 *)D_0029BE00;
    reg_d0.h[0] = 0x6F;
    do {
        *(s16 *)reg_a0 = 0;
        reg_a0 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *)D_0029BE00;
    reg_d0.w = 1;
    do {
        *(s8 *)(reg_a0 + 1) = 0;
        *(u8 *)reg_a0 = 0;
        reg_tmp.w = -1U;
        *(u16 *)(reg_a0 + 0x56) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a0 + 0x58) = (u16) reg_tmp.h[0];
        *(s16 *)(reg_a0 + 0x60) = 0;
        *(s16 *)(reg_a0 + 0x62) = 0;
        *(s16 *)(reg_a0 + 0x64) = 1;
        *(s16 *)(reg_a0 + 0x66) = 0;
        *(s16 *)(reg_a0 + 0x68) = 0;
        *(s16 *)(reg_a0 + 0x6A) = 2;
        *(s16 *)(reg_a0 + 0x6C) = 0x140;
        reg_a0 += 0x70;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    D_0028DF18 = 0;
    *(s8 *)(reg_a5 + 2) = 0;
    *(u8 *)(reg_a5 + 5) = 0xFFU;
    *(u8 *)(reg_a5 + 4) = 0xFFU;
    *(u8 *)(reg_a5 + 7) = 0xFFU;
    *(u8 *)(reg_a5 + 6) = 0xFFU;
    *(u8 *)(reg_a5 + 9) = 0xFFU;
    *(u8 *)(reg_a5 + 8) = 0xFFU;
    *(s16 *)(reg_a5 + 0xA) = 0;
    reg_a0 = (u8 *)D_0029BE00;
    reg_d0.w = 0;
    if (0 > g_player1[0]) {
        reg_d0.h[0] = 1;
    } else if (0 > g_player2[0]) {
        reg_d0.h[0] = 2;
    }
    reg_a6 = (u8 *)D_0029BE00;
    if (reg_d0.b[0] == 2) {
        *(s8 *)(reg_a0 + 0x71) = 1;
        reg_d1.h[0] = PLAYER(g_player2)->ship_type.h;
        *(u8 *)(reg_a5 + 8) = (u8) reg_d1.b[0];
        reg_d1.h[0] = PLAYER(g_player2)->power_style.h;
        *(u8 *)(reg_a5 + 4) = (u8) reg_d1.b[0];
        *(u8 *)(reg_a5 + 6) = (u8) reg_d1.b[0];
        *(s8 *)(reg_a6 + 0x70) = 3;
        reg_d1.w = 0;
        if (g_p2_ship_type != 0) {
            reg_d1.w = 1;
        }
        *(u16 *)(reg_a6 + 0x72) = (u16) reg_d1.h[0];
        reg_d0.w = 1;
        ship_palettes_load();
        reg_d0.w = 1;
        player_panel_show_unless_step_4();
    } else if (reg_d0.b[0] == 1) {
        *(s8 *)(reg_a0 + 1) = 1;
        reg_d1.h[0] = PLAYER(g_player1)->ship_type.h;
        *(u8 *)(reg_a5 + 9) = (u8) reg_d1.b[0];
        reg_d1.h[0] = PLAYER(g_player1)->power_style.h;
        *(u8 *)(reg_a5 + 5) = (u8) reg_d1.b[0];
        *(u8 *)(reg_a5 + 7) = (u8) reg_d1.b[0];
        ENTITY(reg_a6)->flags.sb[0] = 3;
        reg_d1.w = 0;
        if (g_p1_ship_type != 0) {
            reg_d1.w = 1;
        }
        ENTITY(reg_a6)->y.h = (u16) reg_d1.h[0];
        reg_d0.w = 0;
        ship_palettes_load();
        reg_d0.w = 0;
        player_panel_show_unless_step_4();
    }
    text_layer_clear();
    reg_a0 = (u8 *)g_default_text_palette;
    reg_d0.w = 0;
    text_palette_load();
    reg_a0 = (u8 *)D_0025F770;
    reg_d0.w = 2;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260930;
    reg_d0.w = 0x18;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260970;
    reg_d0.w = 0x19;
    sprite_palette_load();
    reg_a0 = (u8 *)D_002609B0;
    reg_d0.w = 0x1B;
    sprite_palette_load();
    reg_a0 = (u8 *)D_002609F0;
    reg_d0.w = 0x1A;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260A30;
    reg_d0.w = 0x1C;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260CB0;
    reg_d0.w = 0x12;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260D70;
    reg_d0.w = 0x13;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260E70;
    reg_d0.w = 0x14;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260DB0;
    reg_d0.w = 0x10;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260CF0;
    reg_d0.w = 0x15;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260E30;
    reg_d0.w = 0x16;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260DF0;
    reg_d0.w = 0x17;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260D30;
    reg_d0.w = 0x11;
    sprite_palette_load();
    if (g_replay_mode == 1) {
        replay_start_state_save(g_replay_start_state);
    }
    reg_d0.h[0] = TASK_GAME;
    task_start();
    *(s16 *)(reg_a0 + 4) = 0;
}

void select_step2_task_finish(void) {
    g_select_screen_active = 0;
    task_stop_self();
}


void select_step2_task(void) {
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;
    u8 temp_a0_4;
    u8 temp_a0_5;

    temp_a0 = *(u8 *)(reg_a5 + 3);
    if (temp_a0 == 0) {
        select_step2_task_begin();
        return;
    }
    if (temp_a0 == 2) {
        select_step2_task_finish();
        return;
    }
    *(s8 *)(reg_a5 + 2) = 0;
    reg_a6 = D_0029BE00;
    reg_d7.w = 1;
    do {
        if (ENTITY(reg_a6)->flags.b[1] != 0) {
            temp_a0_2 = ENTITY(reg_a6)->flags.b[0];
            if (temp_a0_2 == 3) {
                doll_select_start();
                ENTITY(reg_a6)->flags.b[0] = 5U;
            }
            temp_a0_3 = ENTITY(reg_a6)->flags.b[0];
            if (temp_a0_3 == 5) {
                doll_select_confirm();
            }
            temp_a0_4 = ENTITY(reg_a6)->flags.b[0];
            if (temp_a0_4 == 6) {
                select_palettes_load_both();
            }
            temp_a0_5 = ENTITY(reg_a6)->flags.b[0];
            if (temp_a0_5 == 7) {
                select_side_draw();
            }
        }
        reg_a6 += 0x70;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.w = 3;
    reg_a6 = D_0029BE00;
    if (ENTITY(reg_a6)->flags.b[1] != 0) {
        reg_d0.h[0] &= 0xFFFE;
        if (ENTITY(reg_a6)->flags.b[0] == 8) {
            reg_d0.h[0] |= 1;
        }
    }
    if (*(u8 *)(reg_a6 + 0x71) != 0) {
        reg_d0.h[0] &= 0xFFFD;
        if (*(u8 *)(reg_a6 + 0x70) == 8) {
            reg_d0.h[0] |= 2;
        }
    }
    if (reg_d0.h[0] == 3) {
        *(u8 *)(reg_a5 + 3) = 2U;
    }
}

/* .sbss (the compiler lays these out in reverse) */
#ifdef DEATH_LABEL
s32 death_D_0029048C;
#endif
s16 D_0028DF18 __attribute__((aligned(4)));
s16 D_0028DF14 __attribute__((aligned(4)));
u8 D_0028DF10 __attribute__((aligned(4)));
u8 D_0028DF0C __attribute__((aligned(4)));

/* .bss (the compiler lays these out in reverse) */
u8 D_0029BE00[224];
u16 D_0029BDC0[32];
u16 D_0029BD80[32];
