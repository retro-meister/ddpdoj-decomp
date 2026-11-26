#include "common.h"
#include "task.h"
#include "sdk/ps2sdk.h"
#include "pad.h"

void func_00168E30(void);
void func_00169B40(void);
void func_00169C60(void);
void func_00169D30(void);
void func_00169DA0(void);
void func_00169E20(void);
void func_00169EA0(void);
void func_00169F50(void);
void func_0016A010(void);
void func_0016A0D0(void);
void func_0016A140(void);
void func_0016A170(void);
void func_0016A220(void);
void func_0016A2D0(void);
void func_0016A2E0(void);
void func_0016A2F0(void);
void func_0016A340(void);
void func_0016A3A0(void);
void func_0016A3E0(void);
void func_0016A420(void);
void func_0016A4A0(void);
void func_0016A550(void);
void func_0016A5C0(void);
void func_0016A630(void);
void func_0016A690(void);

extern u16 D_0028E7BC;

void func_00168BA0() {
    reg_a5[2] = 0;
    D_0028E7BC = reg_d0.h[0];
}

typedef void (*Fn)();

s32 func_0012FB00();
s32 func_001301B0();
s32 func_00130200();
s32 func_00131200();
s32 func_00137C50();
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
extern s8 g_replay_buffer_state_as_s8;
extern s8 g_replay_mode_as_s8;
extern s8 g_simulation_active_as_s8;

void attract_task(void) {
    s32 text_layer_clear();
    s32 func_0013B190();
    s32 text_palette_load();
    s32 task_reset_all();
    s32 task_start();
    s32 replay_header_clear();
#ifndef DEATH_LABEL
    u32 t;
#endif

    if (*(u8 *)(reg_a5 + 3) == 0) {
        func_00168E30();
        return;
    }
#ifndef DEATH_LABEL
    reg_d0.h[0] = D_0028E7BC;
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
    func_00130200();
    reg_d0.h[0] += reg_d1.h[0];
    if (reg_d0.h[0] != 0) goto block_1;
    func_001301B0();
    reg_d0.h[0] += reg_d1.h[0];
    if (reg_d0.h[0] == 0) goto block_2;
block_1:
    D_0028DF84 = 1;
    task_reset_all();
    func_0013B190();
    func_00137C50();
    if (g_attract_demo == 0) goto next_4;
    g_attract_demo = 0;
    replay_header_clear();
    g_simulation_active_as_s8 = 0;
    g_replay_mode_as_s8 = 0;
    g_replay_buffer_state_as_s8 = 0;
    sound_stop_effects();
    sfx_coin();
    menu_settings_restore();
next_4:
    if (D_0028E7BC != 0xC) goto next_5;
    sound_stop_effects();
next_5:
    reg_d0.w = 0;
    reg_a0 = (u8 *)text_palette_0;
    text_palette_load();
    text_layer_clear();
    func_0012FB00();
    reg_d0.h[0] = TASK_ATTRACT;
    task_start();
    *(s16 *)(reg_a0 + 4) = 3;
    return;
block_2:
    if (D_0028E7BC == 0xD) goto block_3;
    if (reg_d0.h[0] == 0x11) goto block_3;
    if (reg_d0.h[0] == 0x12) goto block_3;
    D_0028E7B8 += 1;
    reg_d0.h[0] = D_0028E7B8;
    t = reg_d0.h[0] & 0x10;
    reg_d0.h[0] = t;
    if (!(t & 0xFFFF)) goto next_6;
    func_00169C60();
    goto next_7;
next_6:
    func_00169D30();
next_7:
    func_00131200();
block_3:
#endif
    reg_d0.h[0] = D_0028E7BC;
    ((Fn)*(u32 *)((u8 *)attract_step_routines + (reg_d0.h[0] * 4)))();
}

s32 func_0012FBD0();                            /* extern */
s32 slowdown_reset();                            /* extern */
extern s8 D_0028E7B4_as_s8;
extern s16 D_0028E7B8_as_s16;

void func_00168E30(void) {
    *(s8 *)(reg_a5 + 3) = 1;
    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
    func_00168BA0();
    D_0028E7B4_as_s8 = 0;
    D_0028E7B8_as_s16 = 0;
    func_0012FBD0();
    slowdown_reset();
}

s32 func_0015BBD0();                            /* extern */
extern s16 D_0028E314_as_s16;
extern s16 D_0028E318_as_s16;

void func_00168E80(void) {
    s32 text_layer_clear();
    s32 func_0015BA20();
    if (*(u8 *)(reg_a5 + 2) == 0) {
        *(u8 *)(reg_a5 + 2) = 1U;
        text_layer_clear();
        func_0015BA20();
    }
    func_0015BBD0();
    if (cond_flag == 0) {
        D_0028E318_as_s16 = 1;
        D_0028E314_as_s16 = 1;
        reg_d0.h[0] = 5;
        D_0028DF84 = 0;
        func_00168BA0();
    }
}

s32 func_001A3D20();
s32 func_001A3D30();
s32 func_001A3E70();
s32 stage_load_step();
s32 func_00225630();
s32 func_002256B0();
extern u8 D_0028DF84_as_u8;
extern u8 D_0028E294;
extern u8 D_0028E304;
extern u8 g_slowdown_timer;
extern u8 D_0028E368;
extern u8 D_0028E378;
extern s16 g_loaded_stage;
extern u16 g_stage;
extern u8 g_cd_async_state_as_u8;
extern u8 g_cd_async_busy_as_u8;

void func_00168EF0(void) {
    s32 text_layer_clear();
    s32 text_palette_load();
    s32 slowdown_init();
    if (*(u8 *)(reg_a5 + 2) == 0) {
        *(u8 *)(reg_a5 + 2) = 1U;
        text_layer_clear();
        reg_d0.w = 0;
        reg_a0 = text_palette_0;
        text_palette_load();
        D_0028E304 = 0;
        slowdown_init();
        g_slowdown_timer = 0;
        D_0028E294 = 0;
        func_001A3D30();
        D_0028E368 = 0;
        D_0028E378 = 0xFF;
        D_0028DF84_as_u8 = 0;
        g_cd_async_busy_as_u8 = 1;
        g_stage_load_state = 0;
        g_cd_async_state_as_u8 = 0;
        func_00225630();
    }
    if (*(u8 *)(reg_a5 + 2) == 1) {
        g_stage = 0;
        stage_load_step();
        if (g_loaded_stage == g_stage) {
            *(u8 *)(reg_a5 + 2) = 2U;
            func_002256B0();
            func_001A3D20();
        }
    }
    func_001A3E70();
    if (cond_flag == 0) {
        reg_d0.h[0] = 0xC;
        func_00168BA0();
    }
}

#ifndef DEATH_LABEL
s32 func_0015BBD0();
s32 func_0015BEF0();
s32 music_stop();
s32 fade_reset();
s32 boot_scratch_clear();
s32 stage_map_reset();
extern u8 D_0028E284;
extern u8 D_0028E288;
extern u8 g_game_mode;
extern u8 D_0028E2E4;
extern u8 g_splash_visible;

void func_00168FD0(void) {
    s32 text_layer_clear();
    s32 func_0013B190();
    s32 func_0015BA20();
    s32 func_0015BD00();
    if (reg_a5[2] == 0) {
        reg_a5[2] = 1U;
        text_layer_clear();
        func_0013B190();
        func_0015BA20();
        music_stop();
        D_0028E368 = 0;
        D_0028E378 = 0xFF;
        g_splash_visible = 0;
        fade_reset();
        stage_map_reset();
        boot_scratch_clear();
        g_stage_load_state = 0;
        g_cd_async_busy_as_u8 = 1;
        g_cd_async_state_as_u8 = 0;
        func_00225630();
    }
    if (reg_a5[2] == 1) {
        g_stage = 0;
        stage_load_step();
        if (g_loaded_stage == g_stage) {
            reg_a5[2] = 2U;
            func_002256B0();
        }
    }
    if (g_setting_coin_mode != 0x12) {
        func_0015BD00();
        if (g_stage_load_state == 0) {
            func_00169B40();
        }
    } else {
        if (D_0028DF84 != 0) {
            func_0015BEF0();
        } else {
            func_0015BBD0();
        }
        switch (cond_flag) { case 0: goto block_set; }
        if (g_stage_load_state == 0) {
            func_00169B40();
        }
        return;
    block_set:
        D_0028E318_as_s16 = 1;
        D_0028E314_as_s16 = 1;
        reg_d0.h[0] = 5;
        D_0028E288 = 0;
        D_0028E284 = 0;
        D_0028E378 = 0;
        g_game_mode = 0;
        D_0028E2E4 = 0;
        D_0028DF84 = 0;
        func_00168BA0();
    }
}
#endif

#ifdef DEATH_LABEL
s32 music_stop();
s32 fade_reset();
s32 stage_map_reset();
extern u8 g_splash_visible;
extern s8 g_cd_async_busy;
extern s8 D_0028EB88;

void death_func_00136FF0(void) {
    s32 text_layer_clear();
    s32 func_0013B190();
    s32 text_palette_load();
    if (reg_a5[2] == 0) {
        reg_a5[2] = 1U;
        func_0012FB00();
        text_layer_clear();
        reg_d0.w = 0;
        reg_a0 = text_palette_0;
        text_palette_load();
        func_0013B190();
        music_stop();
        D_0028E368 = 0;
        D_0028E378 = 0xFF;
        g_splash_visible = 0;
        fade_reset();
        stage_map_reset();
        g_stage_load_state = 0;
        g_cd_async_busy = 1;
        g_cd_async_state = 0;
        func_00225630();
    }
    if (reg_a5[2] == 1) {
        g_stage = 0;
        stage_load_step();
        if (g_loaded_stage == g_stage) {
            reg_a5[2] = 2U;
            func_002256B0();
        }
    }
    if (g_stage_load_state == 0) {
        D_0028EB88 = 0;
        reg_d0.h[0] = 0xF;
        func_00168BA0();
    }
}
#endif

void fade_start_in(void);
void func_0021D570(void);
s32 func_0022BB80(u8 *);
void func_00235890(void);
extern s8 D_0028E25C_as_s8;
extern s8 D_0028E284_as_s8;
extern s8 D_0028E288_as_s8;
extern s8 g_pad_input_locked_as_s8;
extern s8 D_0028E2A0_as_s8;
extern s8 D_0028E2A4_as_s8;
extern u8 D_0028E2B8_as_u8;
extern u8 D_0028E2B9;
extern u8 D_0028E2BA;
extern u8 D_0028E2BB;
extern u8 D_0028E2BC;
extern s8 D_0028E2BD_as_s8;
extern s8 D_0028E2BE;
extern s8 D_0028E2BF;
extern u16 D_0028E2FC;
extern u16 D_0028E300;
extern s8 g_slowdown_timer_as_s8;
extern s8 D_0028E368_as_s8;
extern s8 g_game_frame_ran_as_s8;
extern s8 D_0028E3F8;
extern s8 D_0028EB00;
extern s32 D_0028EB94;

void func_00169140(void) {
    void text_layer_clear(void);
    void func_0013B190(void);
    void func_0015BA20(void);
    void func_0015BD00(void);
    void slowdown_init(void);
    if (*(u8 *)(reg_a5 + 2) == 0) {
        *(u8 *)(reg_a5 + 2) = 1;
        func_0013B190();
        func_0015BA20();
        slowdown_init();
        g_slowdown_timer_as_s8 = 0;
        D_0028E288_as_s8 = 0;
        D_0028E284_as_s8 = 0;
        g_pad_input_locked_as_s8 = 0;
        D_0028E2A4_as_s8 = 0;
        D_0028E2A0_as_s8 = 0;
        D_0028E368_as_s8 = 0;
        text_layer_clear();
#ifdef DEATH_LABEL
        func_00235890();
#else
        if (D_0028DF84 != 0) {
            func_00235890();
        }
#endif
    }
    if (D_0028EB94 == 0) {
        func_0015BD00();
    }
    func_0021D570();
    if (D_0028EB00 >= 10) {
        if (D_0028EB00 == 10) {
            D_0028DF84 = 1;
            reg_d0.h[0] = 3;
            func_00168BA0();
        } else if (D_0028EB00 == 30) {
            D_0028DF84 = 0;
            reg_d0.h[0] = 0x10;
            g_game_frame_ran_as_s8 = 0;
            D_0028E3F8 = 0;
            func_00168BA0();
        } else if (D_0028EB00 == 40) {
#ifdef DEATH_LABEL
            D_0028E2B8_as_u8 = 0;
            D_0028E2B9 = 0;
            D_0028E2BA = 0;
            D_0028E2BB = 0;
            D_0028E2BC = 0;
            D_0028E2BD_as_s8 = 0;
            D_0028E2BE = 0;
            D_0028E2BF = 0;
            reg_a0 = &D_0028E2B8_as_u8;
            if (func_0022BB80(reg_a0) != 0) {
                sceGsSyncV(0);
                if (func_0022BB80(reg_a0) != 0) {
                    D_0028E2B8_as_u8 = 0;
                    D_0028E2B9 = 0;
                    D_0028E2BA = 0;
                    D_0028E2BB = 0;
                    D_0028E2BC = 0;
                }
            }
            printf((const char *)"--date [%d][%d][%d][%d][%d]\n", D_0028E2B8_as_u8, D_0028E2B9, D_0028E2BA, D_0028E2BB, D_0028E2BC);
#endif
            D_0028DF84 = 0;
            reg_d0.h[0] = 0x13;
            g_game_frame_ran_as_s8 = 0;
            D_0028E3F8 = 0;
            func_00168BA0();
        } else {
            D_0028E318_as_s16 = 9;
            D_0028E314_as_s16 = 9;
            D_0028E2FC = D_0028E300;
            D_0028E25C_as_s8 = 0;
            D_0028E2B8_as_u8 = 0;
            D_0028E2B9 = 0;
            D_0028E2BA = 0;
            D_0028E2BB = 0;
            D_0028E2BC = 0;
            D_0028E2BD_as_s8 = 0;
            D_0028E2BE = 0;
            D_0028E2BF = 0;
            reg_a0 = &D_0028E2B8_as_u8;
            if (func_0022BB80(reg_a0) != 0) {
                sceGsSyncV(0);
                if (func_0022BB80(reg_a0) != 0) {
                    D_0028E2B8_as_u8 = 0;
                    D_0028E2B9 = 0;
                    D_0028E2BA = 0;
                    D_0028E2BB = 0;
                    D_0028E2BC = 0;
                }
            }
            printf((const char *)"--date [%d][%d][%d][%d][%d]\n", D_0028E2B8_as_u8, D_0028E2B9, D_0028E2BA, D_0028E2BB, D_0028E2BC);
            reg_d0.h[0] = 0xE;
            func_00168BA0();
        }
        D_0028EB00 = 0;
        fade_start_in();
    }
}

void func_00169310(void) {

}

s32 func_00137C50();                            /* extern */
s32 func_00137C90();                            /* extern */
s32 func_00137E00();                            /* extern */
s32 sound_stop_effects();                            /* extern */
s32 stage_map_reset();                            /* extern */
extern s32 g_default_text_palette_as_s32_a[];

void func_00169320(void) {
    s32 text_layer_clear();
    s32 func_0013B190();
    s32 text_palette_load();
    s32 task_reset_all();
    s32 task_start();
    if (*(u8 *)(reg_a5 + 2) == 0) {
        *(u8 *)(reg_a5 + 2) = 1U;
        func_00137C90();
        text_layer_clear();
        *(s16 *)(reg_a5 + 4) = 0;
        reg_a0 = (u8 *)g_default_text_palette_as_s32_a;
        reg_d0.w = 0;
        text_palette_load();
    }
    func_00137E00();
    if (cond_flag == 0) {
        printf((const char *)"demo end\n");
        task_reset_all();
        func_0013B190();
        func_00137C50();
        stage_map_reset();
        text_layer_clear();
        reg_d0.h[0] = TASK_ATTRACT;
        task_start();
        (*(s16 *)((u8 *)((s32 *)reg_a0) + (4))) = 2;
        sound_stop_effects();
    }
}

void func_001693E0(void) {

}

void func_001693F0(void) {

}

void func_00169400(void) {

}

s32 splash_begin();                            /* extern */
s32 splash_update();                            /* extern */
extern u8 g_splash_visible;

void func_00169410(void) {
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
        func_00168BA0();
    }
}

void func_00169480(void) {

}

void func_00169490(void) {

}

s32 func_0012F6A0();                            /* extern */
s32 func_0012F7D0();                            /* extern */

void func_001694A0(void) {
    if (*(u8 *)(reg_a5 + 2) == 0) {
        *(u8 *)(reg_a5 + 2) = 1U;
        func_0012F6A0();
    }
    func_0012F7D0();
    if (cond_flag == 0) {
        reg_d0.h[0] = 9;
        func_00168BA0();
    }
}

s32 layers_reset();
s32 text_layer_print_wide();
extern u8 g_default_text_palette[];
extern u8 D_0026A880[];

void func_001694F0() {
    s32 text_layer_clear();
    s32 text_palette_load();
    u16 temp_v1;
    u16 temp_v1_2;

    if (*(u8 *)(reg_a5 + 2) == 0) {
        D_0028DF84_as_u8 = 0;
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
        reg_a0 = D_0026A880;
        reg_a0 += *(u16 *)(reg_a5 + 6);
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
            func_00168BA0();
            text_layer_clear();
        }
    }
}

extern u8 D_0028E7B4;

void func_00169640(void) {
    s32 task_reset_all();
    s32 task_start();
    task_reset_all();
    reg_d0.h[0] = TASK_SHIP_SELECT;
    task_start();
    *(u8 *)(reg_a0 + 5) = (u8) D_0028E7B4;
}

extern u8 D_0028DE40[];
extern u8 D_0028DE44[];
extern u8 D_0028DE48[];
extern s8 g_game_mode_as_s8;
extern s8 g_menu_pad;
extern u8 g_replay_mode;
extern s16 D_0068DEC8_as_s16_a[];
extern s16 D_0068DECA[];
extern s16 D_0068DECC[];
extern s16 D_0068DECE[];
extern s16 D_0068DED0[];
extern s16 D_0068DED2[];
extern s16 D_0068DED8_as_s16_a[];
extern s16 D_0068DEDA[];
extern s16 D_0068DEDC[];
extern s16 D_0068DEDE[];
extern s16 D_0068DEE0[];
extern s16 D_0068DEF0_as_s16_a[];
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
extern s16 D_006E5BF0_as_s16_a[];
extern s16 D_006E5BF2_as_s16_a[];
extern s16 D_006E5BF4_as_s16_a[];
extern s16 D_006E5BF6_as_s16_a[];
extern s16 D_006E5BF8_as_s16_a[];
extern s16 D_006E5BFA_as_s16_a[];
extern s16 D_006E5BFC_as_s16_a[];
extern s16 D_006E5BFE_as_s16_a[];
extern s16 D_006E5C00_as_s16_a[];
extern s16 D_006E5C02_as_s16_a[];
extern s16 D_006E5C04_as_s16_a[];
extern s16 D_006E5C06_as_s16_a[];
extern s16 D_006E5C08_as_s16_a[];
extern s16 D_006E5C0A_as_s16_a[];
extern s16 D_006E5C0C_as_s16_a[];
extern s16 D_006E5C0E_as_s16_a[];
extern s16 D_006E5C10_as_s16_a[];
extern s16 D_006E5C12_as_s16_a[];
extern s16 D_006E5C14_as_s16_a[];

void func_00169680(void) {
    void text_layer_clear(void);
    void text_palette_load(void);
    void task_reset_all(void);
    void task_start(void);
    void replay_header_clear(void);
    s32 a;
    s32 b;

    g_game_mode_as_s8 = 0;
    task_reset_all();
    text_layer_clear();
    reg_d0.w = 0;
    reg_a0 = (u8 *)g_default_text_palette;
    text_palette_load();
    replay_header_clear();
    a = D_0068DEDA[0];
    b = D_0068DEDC[0];
    if (g_menu_pad == 0) {
        D_006E5BE2[0] = D_0028DE40[a];
        D_006E5BE4[0] = D_0028DE44[b];
    } else {
        D_006E5BE6[0] = D_0028DE40[a];
        D_006E5BE8[0] = D_0028DE44[b];
    }
    D_006E5C04_as_s16_a[0] = 0;
    D_006E5BEA_as_s16_a[0] = D_0068DED8_as_s16_a[0];
    D_006E5BEC_as_s16_a[0] = D_0068DF02[0] / 5;
    D_006E5BFE_as_s16_a[0] = D_0068DF00[0];
    D_006E5BFC_as_s16_a[0] = D_0068DEFE[0];
    D_006E5BF4_as_s16_a[0] = D_0068DEF6[0];
    D_006E5BF6_as_s16_a[0] = D_0068DEF8[0];
    D_006E5BF8_as_s16_a[0] = D_0068DEF0_as_s16_a[0];
    D_006E5BFA_as_s16_a[0] = D_0068DEF2[0];
    D_006E5C00_as_s16_a[0] = D_0068DEF4[0];
    D_006E5C02_as_s16_a[0] = D_0068DF04[0];
    D_006E5C06_as_s16_a[0] = D_0068DEDE[0];
    D_006E5C08_as_s16_a[0] = D_0068DEE0[0];
    D_006E5C0A_as_s16_a[0] = D_0068DEFA[0];
    D_006E5C0C_as_s16_a[0] = D_0068DEFC[0];
    D_006E5C0E_as_s16_a[0] = D_0068DEC8_as_s16_a[0];
    D_006E5C10_as_s16_a[0] = D_0068DECA[0];
    D_006E5C12_as_s16_a[0] = D_0068DECC[0];
    D_006E5BEE_as_s16_a[0] = D_0068DF02[0] % 5;
    D_006E5BF0_as_s16_a[0] = D_0028DE48[D_0068DECE[0]];
    D_006E5BF2_as_s16_a[0] = D_0028DE48[D_0068DED0[0]];
    D_006E5C14_as_s16_a[0] = D_0068DED2[0];
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

void func_00169900(void) {
    s32 text_layer_clear();
    s32 text_palette_load();
    s32 task_reset_all();
    s32 task_start();
    g_game_mode_as_s8 = 2;
#ifdef DEATH_LABEL
    death_D_00290DC0 = 0;
#endif
    task_reset_all();
    text_layer_clear();
    reg_d0.w = 0;
    reg_a0 = (u8 *)g_default_text_palette_as_s32_a;
    text_palette_load();
    reg_d0.h[0] = MAIN_OR_DEATH_LABEL(0x15, 9);
    task_start();
#ifdef DEATH_LABEL
    *((u8 *)((s32 *)reg_a0) + 5) = D_0028E7B4;
#endif
}

s32 mc_autoload_update();
s32 func_0022C710();
s32 func_00234EF0();
extern u8 D_0028ECF4;
extern s32 D_0028ED0C;
extern s32 D_006A0E40[];

void func_00169950(void) {
    u8 temp_a0;
    u8 *temp_a1;

    temp_a1 = (u8 *)(reg_a5 + 2);
    temp_a0 = *(u8 *)(reg_a5 + 2);
    switch (temp_a0) {                              /* irregular */
    case 0:
        D_0028ED0C = 0;
        *(u8 *)(reg_a5 + 2) = 1U;
        break;
    case 1:
        func_0022C710(temp_a0, temp_a1);
        if (D_0028ED0C != 0) {
            D_0028ED0C = 0;
            printf((const char *)"-----[%d]---\n", D_0028ECF4);
            if (D_0028ECF4 & 0xC) {
                *(u8 *)(reg_a5 + 2) = 2U;
                break;
            }
            *(u8 *)(reg_a5 + 2) = 3U;
            break;
        }
        break;
    case 2:
        mc_autoload_update(temp_a0, temp_a1);
        if (D_0028ED0C != 0) {
            *(u8 *)(reg_a5 + 2) = 3U;
            if (D_006A0E40[0] != 0) {
                func_00234EF0(3);
            }
            D_0028ED0C = 0;
            break;
        }
        break;
    case 3:
        reg_d0.h[0] = MAIN_OR_DEATH_LABEL(0xD, 0x3);
        func_00168BA0();
        break;
    }
}

s32 music_stop();
s32 func_00221C20();
s32 func_002365A0();
s32 func_002368E0();
extern s32 D_0028EAF8;
extern s32 D_0028EC78;
extern s32 D_0028EC7C;

void func_00169A50(void) {
    s32 text_layer_clear();
    u8 temp_a0;

    temp_a0 = *(u8 *)(reg_a5 + 2);
    switch (temp_a0) {                              /* irregular */
    case 0:
        text_layer_clear();
        func_0012FB00();
        music_stop();
        *(u8 *)(reg_a5 + 2) = 1U;
        D_0028EC7C = 0;
        D_0028EAF8 = 0;
        menu_settings_restore();
        break;
    case 1:
        if (func_00221C20(temp_a0) != 0) {
            *(u8 *)(reg_a5 + 2) = 2U;
            break;
        }
        break;
    case 2:
        if (func_002365A0(temp_a0) != 0) {
            *(u8 *)(reg_a5 + 2) = 3U;
            D_0028EC78 = 0;
            break;
        }
        break;
    case 3:
        if (func_002368E0(temp_a0) != 0) {
            reg_d0.h[0] = MAIN_OR_DEATH_LABEL(2, 3);
            func_00168BA0();
        }
        break;
    }
}

#ifndef DEATH_LABEL
s32 sfx_confirm();                            /* extern */
extern u8 D_0028E1E6[];
extern s8 D_0028EB88;

void func_00169B40(void) {
    if (g_pad_trigger[2] & 0x800) {
        if (g_setting_coin_mode == 0x12) {
            D_0028EB88 = 0;
            reg_d0.h[0] = 0xF;
            func_00168BA0(g_setting_coin_mode);
            sfx_confirm();
            return;
        }
        if (D_0028E1E6[0] != 0) {
            D_0028EB88 = 0;
            reg_d0.h[0] = 0xF;
            func_00168BA0(g_setting_coin_mode);
        }
    }
}
#endif

s32 func_00130270();
s32 func_001303A0();
void func_00169BC0(void) {
    D_0028E7B4 = 0;
    if (g_pad_trigger[0] & 0x20) {
        func_00130270();
        if (cond_flag == 0) {
            D_0028E7B4 |= 1;
        }
    }
    if (g_pad_trigger[1] & 0x20) {
        func_001303A0();
        if ((cond_flag == 0) && ((D_0028E304 == 0) || (D_0028E7B4 == 0))) {
            D_0028E7B4 |= 2;
        }
    }    if (D_0028E7B4 != 0) { return; }
}

#ifndef DEATH_LABEL
extern u8 g_setting_chute_type;

void func_00169C60(void) {
    reg_d0.b[0] = g_setting_chute_type;
    if (reg_d0.b[0] == 1) {
        func_0016A140();
        return;
    }
    func_001301B0();
    if (reg_d0.h[0] != 0) {
        func_00169DA0();
        return;
    }
    reg_d0.b[0] = g_setting_coin_mode;
    if (reg_d0.b[0] == 0x12) {
        func_00169DA0();
        return;
    }
    if (reg_d0.b[0] == 0x11) {
        func_0016A010();
        return;
    }
    if ((s8)(reg_d0.b[0]) >= 9) {
        func_00169EA0();
        return;
    }
    func_00169E20();
}
#endif

#ifndef DEATH_LABEL
s32 text_layer_print();
extern u8 D_0026AA40[];

void func_00169D30(void) {
    reg_a0 = D_0026AA40;
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
extern u8 D_0026AAA0[];

void func_00169DA0(void) {
    if (g_stage_load_state == 0) {
        reg_d0.h[0] = 0;
        reg_d2.h[0] = 0;
        reg_a0 = D_0026AAA0;
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
extern u8 D_0026AC80[];

void func_00169E20(void) {
    if (g_stage_load_state == 0) {
        reg_d0.h[0] = 0;
        reg_d2.h[0] = 0;
        reg_a0 = D_0026AC80;
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
s32 func_0012FFE0();
s32 text_layer_put_hex_digit();
extern u8 D_0026ABC0[];

void func_00169EA0(void) {
    func_0012FFE0();
    if (reg_d1.h[0] != 0) {
        func_00169F50();
        return;
    }
    reg_d2.h[0] = 0;
    reg_a0 = D_0026ABC0;
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
extern u8 D_0026AC20[];

void func_00169F50(void) {
    u16 temp_a0;

    reg_d0.h[0] -= reg_d1.h[0];
    reg_d4.h[0] = reg_d0.h[0];
    if (reg_d4.h[0] == 1) {
        func_0016A0D0();
        return;
    }
    reg_d0.h[0] = 0;
    reg_d2.h[0] = 0;
    reg_a0 = D_0026AC20;
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
extern u8 D_0026AB00[];

void func_0016A010(void) {
    func_00130200();
    if (reg_d0.h[0] == 1) {
        func_0016A0D0();
        return;
    }
    if ((s16)(reg_d0.h[0]) >= 2) {
        func_00169DA0();
        return;
    }
    reg_d0.h[0] = 0;
    reg_d2.h[0] = 0;
    reg_a0 = D_0026AB00;
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
extern u8 D_0026AB60[];

void func_0016A0D0(void) {
    reg_a0 = D_0026AB60;
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

void func_0016A140(void) {
    reg_d6.w = 0xA;
    func_0016A170();
    func_0016A220();
}
#endif

#ifndef DEATH_LABEL

void func_0016A170(void) {
    reg_d7.w = 0;
    func_001301B0();
    if (reg_d0.h[0] != 0) {
        func_0016A2D0();
        return;
    }
    reg_d0.b[0] = g_setting_coin_mode;
    if (reg_d0.b[0] == 0x12) {
        func_0016A2D0();
        return;
    }
    if (reg_d0.b[0] == 0x11) {
        func_0016A550();
        return;
    }
    if ((s8)(reg_d0.b[0]) >= 9) {
        func_0016A3A0();
        return;
    }
    func_0016A340();
}
#endif

#ifndef DEATH_LABEL

void func_0016A220(void) {
    reg_d7.w = 0xE;
    func_001301B0();
    if (reg_d1.h[0] != 0) {
        func_0016A2E0();
        return;
    }
    reg_d0.b[0] = g_setting_coin_mode;
    if (reg_d0.b[0] == 0x12) {
        func_0016A2E0();
        return;
    }
    if (reg_d0.b[0] == 0x11) {
        func_0016A5C0();
        return;
    }
    if ((s8)(reg_d0.b[0]) >= 9) {
        func_0016A3E0();
        return;
    }
    func_0016A340();
}
#endif

#ifndef DEATH_LABEL
extern char attract_text_press_start_p1[2][16];

void func_0016A2D0(void) {
    reg_a0 = (u8 *)attract_text_press_start_p1;
    func_0016A2F0();
}
#endif

#ifndef DEATH_LABEL
extern char attract_text_press_start_p2[2][16];


void func_0016A2E0(void) {
    reg_a0 = (u8 *)attract_text_press_start_p2;
    func_0016A2F0();
}
#endif

#ifndef DEATH_LABEL
s32 text_layer_print();                            /* extern */

void func_0016A2F0(void) {
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
extern u8 D_0026AD60[];

void func_0016A340(void) {
    reg_a0 = D_0026AD60;
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
s32 func_0012FFE0();                            /* extern */

void func_0016A3A0(void) {
    func_0012FFE0();
    if (reg_d1.h[0] != 0) {
        func_0016A4A0();
        return;
    }
    func_0016A420();
}
#endif

#ifndef DEATH_LABEL
s32 func_00130050();                            /* extern */

void func_0016A3E0(void) {
    func_00130050();
    if (reg_d1.h[0] != 0) {
        func_0016A4A0();
        return;
    }
    func_0016A420();
}
#endif

#ifndef DEATH_LABEL
extern u8 D_0026AD20[];

void func_0016A420(void) {
    u16 temp_a0;

    reg_a0 = D_0026AD20;
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
extern u8 D_0026AD80[];

void func_0016A4A0(void) {
    u16 temp_a0;

    reg_d0.h[0] -= reg_d1.h[0];
    reg_d4.h[0] = reg_d0.h[0];
    if (reg_d4.h[0] == 1) {
        func_0016A690();
        return;
    }
    reg_d2.h[0] = 0;
    reg_a0 = D_0026AD80;
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

void func_0016A550(void) {
    func_00130200();
    if (reg_d0.h[0] == 1) {
        func_0016A690();
        return;
    }
    if ((s16)(reg_d0.h[0]) >= 2) {
        func_0016A2D0();
        return;
    }
    func_0016A630();
}
#endif

#ifndef DEATH_LABEL
void func_0016A5C0(void) {
    func_00130200();
    reg_d0.h[0] = reg_d1.h[0];
    if (reg_d0.h[0] == 1) {
        func_0016A690();
        return;
    }
    if ((s16)(reg_d0.h[0]) >= 2) {
        func_0016A2E0();
        return;
    }
    func_0016A630();
}
#endif

#ifndef DEATH_LABEL
void func_0016A630(void) {
    reg_a0 = D_0026AD20;
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
extern u8 D_0026AD40[];

void func_0016A690(void) {
    reg_a0 = D_0026AD40;
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
void death_func_00136FF0();
void func_00168E30();
void func_00168E80();
void func_00168EF0();
void func_00169140();
void func_00169310();
void func_00169320();
void func_001693E0();
void func_001693F0();
void func_00169400();
void func_00169410();
void func_00169480();
void func_00169490();
void func_001694A0();
void func_001694F0();
void func_00169640();
void func_00169680();
void func_00169900();
void func_00169950();
void func_00169A50();


void (*attract_step_routines[20])() = {
    func_00168E30,
    func_00168E80,
    func_00168EF0,
    death_func_00136FF0,
    func_00169310,
    func_00169320,
    func_001693E0,
    func_001693F0,
    func_00169400,
    func_00169410,
    func_00169480,
    func_00169490,
    func_001694A0,
    func_001694F0,
    func_00169640,
    func_00169140,
    func_00169680,
    func_00169950,
    func_00169A50,
    func_00169900,
};

u8 D_0026A880[448] = {
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
void func_00168E30();
void func_00168E80();
void func_00168EF0();
void func_00168FD0();
void func_00169140();
void func_00169310();
void func_00169320();
void func_001693E0();
void func_001693F0();
void func_00169400();
void func_00169410();
void func_00169480();
void func_00169490();
void func_001694A0();
void func_001694F0();
void func_00169640();
void func_00169680();
void func_00169900();
void func_00169950();
void func_00169A50();


void (*attract_step_routines[20])() = {
    func_00168E30,
    func_00168E80,
    func_00168EF0,
    func_00168FD0,
    func_00169310,
    func_00169320,
    func_001693E0,
    func_001693F0,
    func_00169400,
    func_00169410,
    func_00169480,
    func_00169490,
    func_001694A0,
    func_001694F0,
    func_00169640,
    func_00169140,
    func_00169680,
    func_00169950,
    func_00169A50,
    func_00169900,
};

u8 D_0026A880[448] = {
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

u8 D_0026AA40[96] = {
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 D_0026AAA0[96] = {
    0x20, 0x20, 0x20, 0x20, 0x50, 0x52, 0x45, 0x53, 0x53, 0x20, 0x31, 0x50, 0x20, 0x4F, 0x52, 0x20,
    0x32, 0x50, 0x20, 0x53, 0x54, 0x41, 0x52, 0x54, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
};

u8 D_0026AB00[96] = {
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x49, 0x4E, 0x53, 0x45, 0x52, 0x54, 0x20, 0x32, 0x20,
    0x43, 0x4F, 0x49, 0x4E, 0x53, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x43, 0x4F, 0x4E, 0x54, 0x49, 0x4E, 0x55, 0x45, 0x20, 0x52,
    0x45, 0x51, 0x55, 0x49, 0x52, 0x45, 0x53, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x4F, 0x4E, 0x4C, 0x59, 0x20, 0x31, 0x20,
    0x43, 0x4F, 0x49, 0x4E, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
};

u8 D_0026AB60[96] = {
    0x20, 0x20, 0x20, 0x20, 0x20, 0x49, 0x4E, 0x53, 0x45, 0x52, 0x54, 0x20, 0x31, 0x20, 0x4D, 0x4F,
    0x52, 0x45, 0x20, 0x43, 0x4F, 0x49, 0x4E, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
};

u8 D_0026ABC0[96] = {
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x49, 0x4E, 0x53, 0x45, 0x52, 0x54, 0x20, 0x20, 0x20,
    0x43, 0x4F, 0x49, 0x4E, 0x53, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
};

u8 D_0026AC20[96] = {
    0x20, 0x20, 0x20, 0x20, 0x20, 0x49, 0x4E, 0x53, 0x45, 0x52, 0x54, 0x20, 0x20, 0x20, 0x4D, 0x4F,
    0x52, 0x45, 0x20, 0x43, 0x4F, 0x49, 0x4E, 0x53, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
};

u8 D_0026AC80[96] = {
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

u8 D_0026AD20[32] = {
    0x20, 0x20, 0x20, 0x49, 0x4E, 0x53, 0x45, 0x52, 0x54, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x32, 0x20, 0x43, 0x4F, 0x49, 0x4E, 0x53, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
};

u8 D_0026AD40[32] = {
    0x20, 0x20, 0x49, 0x4E, 0x53, 0x45, 0x52, 0x54, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
    0x20, 0x20, 0x31, 0x20, 0x4D, 0x4F, 0x52, 0x45, 0x20, 0x43, 0x4F, 0x49, 0x4E, 0x20, 0x00, 0x00,
};

u8 D_0026AD60[32] = {
    0x20, 0x20, 0x49, 0x4E, 0x53, 0x45, 0x52, 0x54, 0x20, 0x43, 0x4F, 0x49, 0x4E, 0x20, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
};

u8 D_0026AD80[32] = {
    0x20, 0x20, 0x49, 0x4E, 0x53, 0x45, 0x52, 0x54, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
    0x20, 0x20, 0x20, 0x20, 0x4D, 0x4F, 0x52, 0x45, 0x20, 0x43, 0x4F, 0x49, 0x4E, 0x53, 0x00, 0x00,
};
#endif

/* .sbss (the compiler lays these out in reverse) */
s8 D_0028DF84 __attribute__((aligned(4)));
