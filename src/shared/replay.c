#include "common.h"
#include "sdk/ps2sdk.h"
#include "replay.h"

void func_00237D50();

#ifdef DEATH_LABEL
extern void voice_ok(void);
extern char death_D_00277690[];
extern char death_D_002776B0[];
extern u16 g_attract_demo;
extern u16 g_p2_score_digits;
extern u16 g_p1_score_digits;
extern u16 g_two_player_seen;
extern s8 D_0028EC24;
extern u8 D_0028ED58;
extern u32 D_0028ED70_as_u32;
extern u8 D_0028ED74;
extern u8 D_0028ED78;
extern u8 D_0028ED7C;
extern u8 g_simulation_active;
extern u16 D_006C58A4[];
extern u16 D_006C58A8[];
extern u8 death_D_002B1ED8[];
extern u8 D_006CB5A8[];

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
    switch (D_0028ED74) {
    case 0:
        D_0028ED70_as_u32 = 0;
        reg_d1.b[0] = 0x80;
        reg_d0.b[0] = 0x80;
        break;
    case 1:
        if (D_0028ED70_as_u32 == 0x1A5E0) {
            D_0028ED70_as_u32 = 0x1A5DF;
            printf(death_D_00277690);
        }
        switch (D_0028ED7C) {
        case 0:
            break;
        case 2:
            if (D_0028ED70_as_u32 > 2 && D_0028ED58 == 0) {
                if (D_0028EC24 == 0) {
                    if (reg_d0.b[0] & 0x7F) {
                        D_0028ED58 = 1;
                    }
                } else if (reg_d1.b[0] & 0x7F) {
                    D_0028ED58 = 1;
                }
                if (D_0028ED58 != 0) {
                    voice_ok();
                    printf(death_D_002776B0);
                }
            }
            if (D_0028ED58 != 0) {
                swap = 0;
                if (D_0028EC24 == 0) {
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
                if (D_0028ED78 != D_0028ED7C) {
                    D_0028ED7C = 0;
                }
                if (D_006C58A4[0] != 0xFF) {
                    reg_d0.b[0] = D_006CB5A8[D_0028ED70_as_u32] ^ death_D_002B1ED8[D_0028ED70_as_u32 & 0x1F];
                } else {
                    reg_d1.b[0] = D_006CB5A8[D_0028ED70_as_u32] ^ death_D_002B1ED8[D_0028ED70_as_u32 & 0x1F];
                }
                D_0028ED70_as_u32++;
            }
            break;
        case 1:
            if (D_0028ED78 != D_0028ED7C) {
                D_0028ED7C = 0;
            }
            if (D_006C58A4[0] != 0xFF) {
                D_006CB5A8[D_0028ED70_as_u32] = reg_d0.b[0];
            } else {
                D_006CB5A8[D_0028ED70_as_u32] = reg_d1.b[0];
            }
            D_006CB5A8[D_0028ED70_as_u32] ^= death_D_002B1ED8[D_0028ED70_as_u32 & 0x1F];
            D_0028ED70_as_u32++;
            if (g_two_player_seen == 3 || g_p1_score_digits != 0 || g_p2_score_digits != 0) {
                D_0028ED7C = 0;
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
extern char D_0028BEB0[];
extern char D_0028BED0[];
extern u16 g_attract_demo;
extern u16 g_p2_score_digits;
extern u16 g_p1_score_digits;
extern u16 g_two_player_seen;
extern s8 D_0028EC24;
extern u8 D_0028ED58;
extern u32 D_0028ED70_as_u32;
extern u8 D_0028ED74;
extern u8 D_0028ED78;
extern u8 D_0028ED7C;
extern u8 g_simulation_active;
extern u16 D_006C58A4[];
extern u16 D_006C58A8[];
extern u8 D_006CB588[];
extern u8 D_006CB5A8[];

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
    switch (D_0028ED74) {
    case 0:
        D_0028ED70_as_u32 = 0;
        reg_d1.b[0] = 0x80;
        reg_d0.b[0] = 0x80;
        break;
    case 1:
        if (D_0028ED70_as_u32 == 0x1A5E0) {
            D_0028ED70_as_u32 = 0x1A5DF;
            printf((const char *)D_0028BEB0);
        }
        switch (D_0028ED7C) {
        case 0:
            break;
        case 2:
            if (D_0028ED70_as_u32 > 2 && D_0028ED58 == 0 && g_attract_demo == 0) {
                if (D_0028EC24 == 0) {
                    if (reg_d0.b[0] & 0x7F) {
                        D_0028ED58 = 1;
                    }
                } else if (reg_d1.b[0] & 0x7F) {
                    D_0028ED58 = 1;
                }
                if (D_0028ED58 != 0) {
                    voice_ok();
                    printf((const char *)D_0028BED0);
                }
            }
            if (D_0028ED58 != 0) {
                swap = 0;
                if (D_0028EC24 == 0) {
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
                if (D_0028ED78 != D_0028ED7C) {
                    D_0028ED7C = 0;
                }
                if (D_006C58A4[0] != 0xFF) {
                    reg_d0.b[0] = D_006CB5A8[D_0028ED70_as_u32] ^ D_006CB588[D_0028ED70_as_u32 & 0x1F];
                } else {
                    reg_d1.b[0] = D_006CB5A8[D_0028ED70_as_u32] ^ D_006CB588[D_0028ED70_as_u32 & 0x1F];
                }
                D_0028ED70_as_u32++;
            }
            break;
        case 1:
            if (D_0028ED78 != D_0028ED7C) {
                D_0028ED7C = 0;
            }
            if (D_006C58A4[0] != 0xFF) {
                D_006CB5A8[D_0028ED70_as_u32] = reg_d0.b[0];
            } else {
                D_006CB5A8[D_0028ED70_as_u32] = reg_d1.b[0];
            }
            D_006CB5A8[D_0028ED70_as_u32] ^= D_006CB588[D_0028ED70_as_u32 & 0x1F];
            D_0028ED70_as_u32++;
            if (g_two_player_seen == 3 || g_p1_score_digits != 0 || g_p2_score_digits != 0) {
                D_0028ED7C = 0;
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
extern void (*D_00272110[])(void);

void func_002372C0(void) {
    s32 index = reg_a5[5];

    switch (reg_a5[3]) {
    case 0:
    case 1:
        D_00272110[index]();
        break;
    case 2:
        replay_stop_task();
        break;
    }
}

extern u8 test_palette_0[];
extern s8 D_0028DF84;

void func_00237330(void) {
    s32 text_layer_clear();
    s32 text_palette_load();
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
    reg_a0 = (u8 *)test_palette_0;
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

extern void func_0015BA20(void);
extern void func_0015BD00(void);
extern void stage_load_step(void);
extern void func_00225630(void);
extern void func_002256B0(void);
extern void func_00227120(void);
extern void func_002271D0(void);
extern u8 g_stage_load_state;
extern s16 g_loaded_stage;
extern u16 g_stage;
extern u8 g_cd_async_state_as_u8;
extern u8 g_cd_async_busy_as_u8;
extern s8 D_0028EC20;

void func_00237470(void) {
    extern void task_start(void);
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
        func_00237330();
        return;
    }
    switch (step) {
    default:
        step++;
        break;
    case 0:
        g_cd_async_busy_as_u8 = 1;
        g_stage_load_state = 0;
        g_cd_async_state_as_u8 = 0;
        func_00225630();
        g_stage = 0;
        step++;
        break;
    case 1:
        stage_load_step();
        if (g_loaded_stage == g_stage) {
            func_002256B0();
            step++;
        }
        break;
    case 2:
        step++;
        func_0015BA20();
        func_0015BD00();
        if (D_0028EC20 != 0) {
            func_002271D0();
        } else {
            func_00227120();
        }
        break;
    case 4:
        reg_d0.h[0] = 8;
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


void func_00237670(void) {
    s32 task_start();
    u32 temp_s0 = reg_d0.w;
    u8 *temp_s1 = reg_a0;

    g_replay_header = g_replay_header_saved;
    reg_d0.h[0] = 0x14;
    task_start();
    *(s8 *)(reg_a0 + 5) = 0;
    reg_d0.w = temp_s0;
    reg_a0 = temp_s1;
}

extern u8 D_0028ED7C;
extern u8 g_simulation_active;

void func_002376F0() {
    s32 task_start();
    s32 func_00224A90();
    u32 temp_s0;
    u8 *temp_s1;
    s32 var_s2;

    temp_s0 = reg_d0.w;
    temp_s1 = (u8 *)(reg_a0);
    var_s2 = 0;
    if (g_simulation_active != 0) {
        var_s2 = 1;
    }
    if (D_0028ED7C == 2) {
        var_s2 = 0;
    }
    func_00224A90();
    reg_d0.h[0] = 0x14;
    task_start();
    if (var_s2 != 0) {
        *(s8 *)(reg_a0 + 5) = 1;
    } else {
        *(s8 *)(reg_a0 + 5) = 2;
    }
    reg_d0.w = temp_s0;
    reg_a0 = temp_s1;
}

s32 task_start();                            /* extern */
s32 func_00224A90();                            /* extern */
s32 func_0022B620();                            /* extern */

void func_00237790(void) {
    u32 temp_s0;
    u8 *temp_s1;

    temp_s0 = reg_d0.w;
    temp_s1 = reg_a0;
    func_0022B620();
    func_00224A90();
    reg_d0.h[0] = 0x14;
    task_start();
    *(s8 *)(reg_a0 + 5) = 4;
    reg_d0.w = temp_s0;
    reg_a0 = temp_s1;
}

s32 text_layer_clear();                            /* extern */
s32 func_0013B350();                            /* extern */
s32 text_palette_load();                            /* extern */
s32 func_00225B70();                            /* extern */
extern s32 test_palette_0_as_s32_a[];
extern s32 D_0026B580_as_s32_a[];
extern u32 D_0028ED84;

void func_002377F0(void) {
    s32 *temp_s0;
    u32 temp_s1;

    temp_s0 = (s32 *)reg_a0;
    temp_s1 = reg_d0.w;
    text_layer_clear();
    reg_d0.w = 0;
    reg_a0 = (u8 *)test_palette_0_as_s32_a;
    text_palette_load();
    *(s8 *)(reg_a5 + 3) = 1;
    *(s16 *)(reg_a5 + 6) = 0;
    func_00225B70();
    reg_a0 = (u8 *)D_0026B580_as_s32_a;
    func_0013B350();
    reg_a0 = (u8 *)temp_s0;
    D_0028ED84 = reg_d0.w;
    reg_d0.w = temp_s1;
}

extern void func_0013BE50(void);
extern void func_0013C300(void);
extern void func_0013C350(void);
extern void func_001A42A0(void);
extern void task_reset_all(void);
extern s32 func_00225CD0(void);
extern u8 D_0026B5F0[];
extern s8 D_0028EACC;

void func_00237870(void) {
    extern void task_start(void);
    extern void func_00224A90(void);
    s32 step;
    s32 done;
    u8 *save_a0;
    u32 save_d0;

    save_a0 = reg_a0;
    save_d0 = reg_d0.w;
    step = *(u16 *)(reg_a5 + 6);
    done = 0;
    if (*(u8 *)(reg_a5 + 3) == 0) {
        func_002377F0();
        return;
    }
    switch (step) {
    default:
        step++;
        break;
    case 0:
        reg_d0.w = D_0028ED84;
        func_0013C350();
        if (cond_flag == 0) {
            func_0013C300();
            step++;
        }
        break;
    case 1:
        switch (func_00225CD0()) {
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
        func_0013BE50();
        step++;
        D_0028ED84 = reg_d0.w;
        break;
    case 216:
    case 316:
    case 416:
        reg_d0.w = D_0028ED84;
        func_0013C350();
        if (cond_flag == 0) {
            func_0013C300();
            step++;
        }
        break;
    case 217:
    case 317:
        task_reset_all();
        func_00237670();
        if (step / 100 == 2) {
            D_0028ED7C = 2;
        } else {
            D_0028ED7C = 1;
        }
        done = 1;
        break;
    case 417:
        task_reset_all();
        func_00224A90();
        reg_d0.h[0] = 20;
        task_start();
        done = 1;
        *(u8 *)(reg_a0 + 5) = 2;
        break;
    }
    func_001A42A0();
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
extern void func_00238B90(u8 *data);
extern char D_0028BEE0[];
extern char D_0028BF00[];
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
extern u16 D_0028E8AC;
extern u16 g_loop;
extern u8 D_0028ED64;
extern s32 D_0028ED70;
extern u8 D_0028ED74;
extern u8 D_0028ED78;
extern u16 D_006C58A0_as_u16_a[];
extern u16 D_006C58A2[];
extern u16 D_006C58A4[];
extern u16 D_006C58A6[];
extern u16 D_006C58A8[];
extern u16 D_006C5CA0_as_u16_a[];
extern u8 D_006CB1D4[];
extern u16 D_006CB578[];
extern u16 D_006CB57A[];
extern u16 D_006CB57C[];
extern u16 D_006CB57E[];
extern u16 D_006CB580[];
extern u16 D_006CB582[];
extern u8 D_006CB5A8[];

void func_00237AC0() {
    s32 i;
    u16 *data;
    u16 *save;

    if (g_simulation_active == 0 && D_0028ED74 == 2) {
        data = D_006C5CA0_as_u16_a;
        save = D_006C58A0_as_u16_a;
    D_0028ED78 = 1;
    D_0028ED74 = 1;
    D_0028ED64 = 0;
    D_0028ED70 = 0;
    printf((const char *)D_0028BEE0);
    memset(save, 0, 0x400);
    memset(D_006CB5A8, 0, 0x1A5E0);
    memset(data, 0, 0x5534);
    func_00238B90((u8 *)data);
    if (g_stage != 0 || g_loop == 0) {
        memset(D_006CB1D4, 0, 0x3A4);
    }
    srand(D_0028E2BC * D_0028E2BB);
    for (i = 0; i < 0x20; i++) {
        ((u8 *)D_006C58A0_as_u16_a)[0x5CE8 + i] = rand();
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
    printf((const char *)D_0028BF00, g_scroll_line, D_0028E8AC);
    }
}

extern u8 g_game_mode;
extern u8 D_0028ED6C;
extern s8 D_0028ED74_as_s8;

void func_00237CC0(void) {
    if (g_game_mode == 2) {
        D_0028ED74_as_s8 = 2;
        D_0028ED6C = 0;
        D_0028ED7C = 0;
    }
    if (g_simulation_active != 0) {
        D_0028ED6C = 0;
        return;
    }
    if (D_0028ED6C != 0) {
        D_0028ED6C = 0;
        switch (D_0028ED7C) {                       /* irregular */
        case 1:
            func_00237AC0(D_0028ED7C);
            return;
        case 2:
            func_00237D50(D_0028ED7C);
            break;
        }
    }
}

s32 func_0023A490(s32 *);                   /* extern */
extern s32 D_0028ED3C;
extern s8 D_0028ED78_as_s8;
extern s32 D_006C5CA0_as_s32_a[];
extern s32 D_006CB584[];

void func_00237D50() {
    D_0028ED78_as_s8 = 2;
    func_0023A490(D_006C5CA0_as_s32_a);
    if (D_006CB584[0] == D_0028ED3C) {
        D_0028ED74_as_s8 = 1;
        D_0028ED70 = 0;
        g_input_p1_pressed = D_006CB57A[0];
        g_input_p1_held = D_006CB578[0];
        g_input_p1_previous = D_006CB57C[0];
        g_input_p2_pressed = D_006CB580[0];
        g_input_p2_held = D_006CB57E[0];
        g_input_p2_previous = D_006CB582[0];
        return;
    }
    func_002376F0(D_006CB584[0]);
}

extern void label_draw(s32 a, s32 b, s32 c, s32 d);
extern void func_0023B720(u8 *arg);
extern u8 g_default_text_palette[];
extern u16 D_0028E314;
extern u16 D_0028E318;
extern u8 D_0028E368;
extern u8 g_game_frame_ran;
extern u16 g_attract_demo;
extern u8 D_0028E3F8_as_u8;
extern u8 D_0028ED58;
extern u8 D_0028ED5C;
extern ReplayHeader D_006C58A0_as_SaveHeader; /* the header at the start of the save buffer */
extern u16 D_006C8E56[];
extern u16 D_006C8E5C[];

void func_00237DF0(void) {
    extern void text_layer_clear(void);
    extern void func_00171910(void);
    extern void text_palette_load(void);
    extern void task_start(void);
    extern void replay_header_save(void);
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
    D_0028E3F8_as_u8 = 0;
    D_0028ED74 = 0;
    D_0028ED70 = 0;
    D_0028E368 = 0;
    D_0028ED5C = 1;
    D_0028ED58 = 0;
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
    g_replay_header = D_006C58A0_as_SaveHeader;
    *(u8 *)(reg_a5 + 3) = 1;
    *(u16 *)(reg_a5 + 10) = 0;
    if (D_006C8E56[0] == 0 && D_006C8E5C[0] != 0) {
        func_0023B720(D_006CB1D4);
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
    reg_d0.h[0] = 10;
    task_start();
    *(u16 *)(reg_a0 + 4) = g_replay_header.stage;
    func_00171910();
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
s32 func_00137CC0();
s32 func_001A33C0();
extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
extern void replay_header_apply(void);
s32 func_0023B6B0();
extern char D_0028BF20[];
extern u8 D_0028DEF8;
extern u16 D_0028DFC0;
extern u8 D_0028E2EC;
extern u8 D_0028E304;
extern u8 g_setting_ship_stock;
extern u8 g_setting_extend;
extern u16 D_0028E3DC;
extern u16 D_0028E3E0;
extern u16 D_0028E3E4;
extern u16 D_0028E3E8;
extern u16 D_0028E3EC;
extern u16 g_game_frame;
extern u16 g_score_task_active;
extern u16 g_score_panel_intro;
extern s32 D_0028E8BC;
extern u16 g_p2_lives;
extern u16 g_p1_lives;
extern s32 D_0028E998;
extern s32 D_0028E99C;
extern s8 D_0028EC58;
extern u16 g_player2_as_u16_a[];
extern u16 g_player1_as_u16_a[];
extern u8 D_006C58C4[];
extern u8 D_006C5CA0[];
extern u8 D_006C68B6[];
extern u8 D_006C6918[];
extern s32 D_006C8E88[];
extern u16 D_006C8E90[];
extern u16 D_006C8E94[];
extern u16 D_006C91A0[];
extern u8 D_006C91AC[];
extern u8 D_006C91AD[];
extern u8 D_006C91AE[];
extern u8 D_006C91AF[];
extern u8 D_006C91B0[];

void func_00238010(void) {
    s32 func_00135100();
    s32 func_00135110();
    s32 func_001719A0();
    s32 func_001719B0();
    s32 func_001719D0();
    s32 music_play_bgm2();
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
        func_00237DF0();
        gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x50, 0x80, 0xFF, 0xFF, 0xFF);
        D_0028E998 = -1;
        D_0028E99C = -1;
        reg_d0.h[0] = 0;
        reg_d1.h[0] = D_006C58A2[0];
        func_001A33C0();
        reg_d0.h[0] = 1;
        reg_d1.h[0] = D_006C58A6[0];
        func_001A33C0();
        func_0023B6B0(D_006C5CA0);
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
                func_00137CC0();
            }
#endif
            g_p2_lives = 0xFFFF;
            g_p1_lives = 0xFFFF;
        }
    }
    func_001719D0();
    switch (step) {
    case 0x0:
        func_001719A0();
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
        D_0028E304 = D_006C91B0[0];
        D_0028E2E4 = D_006C58C4[0];
        replay_header_apply();
        func_00135100();
        step = 0x64;
        break;
    case 0xC8:
        step += 1;
        D_0028E368 = 1;
    case 0xC9:
        func_001719B0();
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
                func_00135110();
                D_0028ED5C = 0;
                if (g_loop == 0) {
                    memcpy(g_player1_as_u16_a, D_006C68B6, 0x62);
                    memcpy(g_player2_as_u16_a, D_006C6918, 0x62);
                    g_player1_as_u16_a[0] = 0;
                    g_player2_as_u16_a[0] = 0;
                } else {
                    D_0028DFC0 = 1;
                }
            }
            break;
        case 0x65:
            if ((g_loop != 0) && (g_scroll_line == 0x69) && (D_0028E8AC == 0x140)) {
                memcpy(g_player1_as_u16_a, D_006C68B6, 0x62);
                memcpy(g_player2_as_u16_a, D_006C6918, 0x62);
                D_0028DFC0 = 0;
                D_0028ED5C = 0;
            }
            if (g_scroll_line == 0x38) {
                g_game_frame = 0x11A;
                D_0028E3E4 = 2;
                D_0028E3E0 = 2;
                D_0028E3EC = 0;
                D_0028E3DC = 0xA;
                D_0028E3E8 = 0;
                base = D_006C91A0[0] - 0x11A;
                D_0028E8BC = D_006C8E88[0] - base + 1;
            }
            if ((g_scroll_line == D_006C8E90[0]) && (D_0028E8AC == D_006C8E94[0])) {
                g_score_task_active = 1;
                D_0028ED6C = 1;
                step = 0xC8;
#ifndef DEATH_LABEL
                D_0028DEF8 = 1;
#endif
                printf((const char *)D_0028BF20, g_scroll_line);
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
                    D_0028ED6C = 1;
#ifndef DEATH_LABEL
                    D_0028DEF8 = 1;
#endif
                    func_00135110();
                    step += 1;
                    printf((const char *)D_0028BF20);
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

extern s8 D_0028E368_as_s8;
extern s8 g_game_frame_ran_as_s8;
extern s8 D_0028E3F8;
extern s8 D_0028ED5C_as_s8;
extern s8 g_simulation_active_as_s8;

void func_00238520(void) {
    s32 text_layer_clear();
    s32 func_00171910();
    s32 text_palette_load();
    s32 task_start();
    s32 replay_header_save();
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
    g_game_frame_ran_as_s8 = 0;
    save_d1 = reg_d1.w;
    D_0028E3F8 = 0;
    D_0028E368_as_s8 = 0;
    D_0028ED5C_as_s8 = 1;
    g_simulation_active_as_s8 = 1;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_a5[3] = 1;
    *(s16 *)(reg_a5 + 4) = 0;
    reg_d0.h[0] = 0xA;
    task_start();
    *(u16 *)(reg_a0 + 4) = g_replay_header.stage;
    func_00171910();
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

extern void func_00131440(void);
extern s8 g_pad_input_locked_as_s8;
extern u8 D_0028E2A8;
extern u16 D_0028E2AC;
extern u8 D_0028E2B0;
extern u8 D_0028E2C4;
extern u8 g_simulation_boss_start;
extern u8 D_0028E2D4;

void func_00238690(void) {
    extern void func_00135100(void);
    extern void func_00135110(void);
    extern void func_001719A0(void);
    extern void func_001719B0(void);
    extern void func_001719D0(void);
    extern void music_play_bgm2(void);
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
        func_00238520();
        return;
    }
    func_001719D0();
    switch (step) {
    default:
        step++;
        break;
    case 0:
        func_001719A0();
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
        func_00135100();
        step++;
        g_pad_input_locked_as_s8 = 1;
        break;
    case 17:
        if (g_score_panel_intro == 0) {
            D_0028ED5C_as_s8 = 0;
            step++;
        }
        break;
    case 18:
        func_00131440();
        if (g_game_frame_ran != 0) {
            g_pad_input_locked_as_s8 = 0;
            step++;
            g_loop = g_replay_header.round;
            func_00135110();
            if (g_replay_header.stage == 0) {
                music_play_bgm2();
            }
        }
        break;
    case 19:
        func_001719B0();
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

extern s8 D_0028ED7C_as_s8;
extern s32 func_0022B2F0(void);
extern u8 D_0028ED68;

static void func_00238910(void)
{
    u32 saved_d0;
    u32 saved_d1;
    u32 saved_d2;
    u32 saved_d3;
    u32 saved_d4;
    u32 saved_d5;
    u32 saved_d6;
    u32 saved_d7;

    D_0028ED7C_as_s8 = 2;

    saved_d0 = reg_d0.w;
    saved_d1 = reg_d1.w;
    saved_d2 = reg_d2.w;
    saved_d3 = reg_d3.w;
    saved_d4 = reg_d4.w;
    saved_d5 = reg_d5.w;
    saved_d6 = reg_d6.w;
    saved_d7 = reg_d7.w;

    D_0028DF84 = 0;
    D_0028E368_as_s8 = 0;
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

void func_00238980(void) {
    extern void task_start(void);
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
        func_00238910();
        return;
    }
    switch (step) {
    case 0:
        if (D_0028ED58 != 0) {
            D_0028ED68 = 0;
            func_002376F0();
            return;
        }
        if (func_0022B2F0() != 0) {
            if (D_0028ED68 != 0) {
                step++;
            } else {
                func_002376F0();
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
        D_0028E368_as_s8 = 1;
        D_0028ED7C_as_s8 = 2;
        task_reset_all();
        reg_d0.h[0] = 20;
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
