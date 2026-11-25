#include "common.h"
#include "sdk/ps2sdk.h"

void func_001391B0(void);
void func_001394A0(void);
void func_00139930(void);

extern s16 D_0029C076_as_s16_a[];
extern u16 D_0029C078[];
extern u16 D_0029C07A[];

void func_001389D0(void) {
    D_0029C076_as_s16_a[0] = 1;
    D_0029C078[0] = reg_d0.h[0];
    D_0029C07A[0] = reg_d1.h[0];
}

extern s16 D_0029C060_as_s16_a[];
extern s16 D_0029C062[];

void func_00138A00(void) {
    D_0029C060_as_s16_a[0] = 0;
    D_0029C062[0] = 1;
}

extern u16 D_0029C070[];

void func_00138A20(void) {
    if (D_0029C070[0] != 0) {
        D_0029C062[0] = 0;
    }
}

extern s16 D_0029C074_as_s16_a[];

void func_00138A40(void) {
    D_0029C074_as_s16_a[0] = 2;
}

s32 func_0011BEA0();
s32 func_0011BF30();
s32 func_0011C0B0();
s32 func_0014C450();
s32 func_0014C8A0();
s32 func_001A3250();
extern u8 D_00252700[];
extern u8 D_00252720[];
extern s32 D_0028DF1C;
extern s8 D_0028E310_as_s8;
extern s8 g_pause_lock_timer_as_s8;
extern u16 g_scroll_line;
extern u16 D_0028E8AC;
extern u16 g_stage_x4;
extern u8 D_0029C060_as_u8_a[];

void func_00138A50(void) {
    u8 *temp_a0;
    u32 temp_a1;
    u32 temp_a1_2;
    g_pause_lock_timer_as_s8 = 0x3C;
    D_0028E310_as_s8 = 0;
    D_0028DF1C = 0;
    g_scroll_line = *(u16 *)(reg_a5 + 6);
    memset(D_0029C060_as_u8_a, 0, 0x20);
    reg_d0.w = 0;
    reg_d1.w = 0xE;
    reg_a0 = reg_a5 + 4;
    do {
        *(u16 *)reg_a0 = 0U;
        reg_a0 += 2;
        *(u16 *)reg_a0 = 0U;
        reg_a0 += 2;
    } while ((s16)(--reg_d1.h[0]) >= 0);
    func_0011BEA0();
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
    func_0011C0B0();
    reg_d1.w = 0;
    reg_d1.h[0] = 0x800;
    func_0011BF30();
    *(u16 *)(reg_a5 + 0x1E) = 0U;
    temp_a1 = *(u16 *)(reg_a5 + 0x1E);
    reg_a0 = (u8 *)D_00252700;
    D_0028E8AC = temp_a1;
    reg_a0 += g_stage_x4;
    temp_a0 = (u8 *)(reg_a0);
    reg_tmp.h[1] = (*(u16 *)((u8 *)(temp_a0) + (0)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(temp_a0) + (2)));
    reg_d1.w = 0x1F;
    reg_d0.w = 0;
    reg_a0 = (u8 *) reg_tmp.w;
    func_001A3250();
    *(u8 *)(reg_a5 + 3) &= 0xFE;
    reg_a1 = (u8 *)D_00252720;
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
    func_0014C8A0();
    func_0014C450();
    func_00138A00();
    *(u8 *)(reg_a5 + 2) |= 4;
}

s32 func_0011C3C0();

void func_00138CC0(void) {
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
    func_0011C3C0();
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
extern u16 D_0028E128;
extern u16 D_0028E12C;
extern u16 D_0028E130;
extern u16 D_0028E134;
extern u16 D_0028E138;
extern u16 D_0028E13C;
extern u16 D_0028E140;
extern u16 D_0028E144;
extern u16 D_0028E148;
extern u16 D_0028E14C;
extern u16 D_0028E150;
extern u16 D_0028E154;
extern u16 D_0028E158;
extern u16 D_0028E15C;
extern u16 D_0028E160;
extern u16 D_0028E164;
extern u16 D_0028E168;
extern u16 D_0028E16C;
extern u16 D_0028E170;
extern u16 D_0028E174;
extern u16 D_0028E178;
extern u16 D_0028E17C;
extern u16 D_0028E180;
extern u16 D_0028E184;
extern u16 D_0028E188;
extern u16 g_sprite_layer5_used;
extern u16 g_sprite_layer4_used;
extern u16 g_sprite_layer3_used;
extern u16 g_sprite_layer2_used;
extern u16 g_sprite_layer1_used;
extern u8 D_0028E290;
extern u8 D_0028E2C0;
extern u8 D_0028E2C8;
extern u8 g_stage_load_state;
extern u8 D_0028E370;
extern u16 D_0028E3C0;
extern s16 g_loaded_stage;
extern u16 g_stage;
extern u8 g_cd_async_state_as_u8;
extern u8 g_cd_async_busy_as_u8;
extern u8 D_0028EC58_as_u8;
extern u8 D_0028ED7C;
extern u8 D_0028ED80;

void func_00138DA0(void) {
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

    D_0028E2C0 = 0;
    t = *(u8 *) (reg_a5 + 2);
    p = reg_a5 + 2;
    if (t & 8) {
        func_001391B0();
        return;
    }
    if (t & 1) {
        *p = t | 1;
        goto next_3;
    }
    *p = t | 1;
    func_00138A50();
    if (D_0028ED80 != 0) {
        goto next_1;
    }
#ifndef DEATH_LABEL
    if (D_0028E3C0 != 0) {
        goto next_2;
    }
#endif
    if (D_0028ED7C != 2) {
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
    D_0028E370 = 0;
    D_0028EC58_as_u8 = 0;
    return;
next_3:
    t = *(u8 *) (reg_a5 + 2);
    p = reg_a5 + 2;
    if (!(t & 2)) {
        func_001394A0();
        return;
    }
    *p = t | 8;
    if (D_0028ED80 == 0) {
        goto next_4;
    }
    if (D_0028E2C8 != 0) {
        goto next_5;
    }
next_4:
    if (D_0028E290 != 2) {
        return;
    }
next_5:
    more = 1;
    done = 0;
    save_23 = D_0028E140;
    save_29 = D_0028E13C;
    save_28 = D_0028E138;
    save_27 = D_0028E134;
    save_24 = D_0028E130;
    save_22 = g_sprite_layer1_used;
    save_25 = D_0028E12C;
    save_26 = D_0028E128;
    D_0028E2C0 = 1;
    save_21 = g_sprite_layer2_used;
    save_20 = g_sprite_layer3_used;
    save_19 = g_sprite_layer4_used;
    save_18 = D_0028E178;
    save_17 = g_sprite_layer5_used;
    save_16 = D_0028E174;
    save_15 = D_0028E17C;
    save_14 = D_0028E188;
    save_13 = D_0028E184;
    save_12 = D_0028E180;
    save_11 = D_0028E170;
    save_10 = D_0028E16C;
    save_09 = D_0028E168;
    save_08 = D_0028E164;
    save_07 = D_0028E160;
    save_06 = D_0028E15C;
    save_05 = D_0028E158;
    save_04 = D_0028E154;
    save_03 = D_0028E150;
    save_02 = D_0028E14C;
    save_01 = D_0028E148;
    save_00 = D_0028E144;
loop_6:
    func_001391B0();
    if (done == 0 && g_stage == 2 && g_scroll_line == 0xE4 && *(u16 *) (reg_a5 + 8) == 1) {
        func_00138A40();
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
    D_0028E140 = save_23;
    D_0028E13C = save_29;
    D_0028E138 = save_28;
    D_0028E134 = save_27;
    D_0028E130 = save_24;
    g_sprite_layer1_used = save_22;
    D_0028E12C = save_25;
    D_0028E128 = save_26;
    g_sprite_layer2_used = save_21;
    g_sprite_layer3_used = save_20;
    g_sprite_layer4_used = save_19;
    D_0028E178 = save_18;
    g_sprite_layer5_used = save_17;
    D_0028E174 = save_16;
    D_0028E17C = save_15;
    D_0028E188 = save_14;
    D_0028E184 = save_13;
    D_0028E180 = save_12;
    D_0028E170 = save_11;
    D_0028E16C = save_10;
    D_0028E168 = save_09;
    D_0028E164 = save_08;
    D_0028E160 = save_07;
    D_0028E15C = save_06;
    D_0028E158 = save_05;
    D_0028E154 = save_04;
    D_0028E150 = save_03;
    D_0028E14C = save_02;
    D_0028E148 = save_01;
    D_0028E144 = save_00;
}

s32 func_0014C4B0();
s32 func_0014C7B0();
s32 func_0014CAD0();
void func_00170A50(s32, s32, s32);
extern u8 D_0028E284;
extern u8 D_0028E288;
extern s16 g_p2_hyper_effect_flag_as_s16;
extern s16 g_p1_hyper_effect_flag_as_s16;
extern u16 g_enemies_stopped;
extern u16 D_0029C064[];
extern u16 D_0029C074[];
extern u16 D_0029C076[];
extern u16 D_0029C07C[];
extern u16 D_0029C07E[];

void func_001391B0(void) {
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
        if (D_0029C076[0] != 0) {
            D_0029C076[0] = 0;
            *(u16 *)(reg_a5 + 0x1C) = (u16) D_0029C078[0];
            *(u16 *)(reg_a5 + 0x22) = (u16) D_0029C07A[0];
        }
        func_00139930();
        func_0014CAD0();
        reg_d0.h[0] = D_0029C074[0];
        if (reg_d0.h[0] != 0) {
            D_0029C074[0] = 0;
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
        reg_d1.h[0] = D_0029C064[0];
        reg_d0.w = 0;
        reg_d0.h[0] = reg_d6.h[0];
        reg_d5.h[0] += reg_d6.h[0];
        func_0011BF30();
        if ((s16)(reg_d5.h[0]) >= 0x200) {
            reg_d5.h[0] -= 0x200;
            if (*(u16 *)(reg_a5 + 8) == 0) {
                g_scroll_line += 1;
            }
        }
        *(u16 *)(reg_a5 + 0x1E) = (u16) reg_d5.h[0];
        temp_a0_2 = reg_d5.h[0];
        D_0028E8AC = temp_a0_2;
        reg_d5.h[0] = *(u16 *)(reg_a5 + 0x20);
        reg_d5.h[0] += reg_d6.h[0];
        if ((s16)(reg_d5.h[0]) >= 0x800) {
            reg_d5.h[0] -= 0x800;
            func_0014C7B0();
            reg_tmp.h[1] = *(u16 *)(reg_a5 + 0xA);
            reg_tmp.h[0] = *(u16 *)(reg_a5 + 0xC);
            reg_a0 = (u8 *)(reg_tmp.w);
            reg_d1.h[0] = *(u16 *)(reg_a5 + 0xE);
            reg_d6.w = 8;
            reg_d0.w = 0;
            do {
                reg_d4.w = *(u32 *)reg_a0;
                reg_a0 += 4;
                func_0011C3C0();
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
        D_0029C07C[0] = *(u16 *)(reg_a5 + 0xE);
        D_0029C07E[0] = *(u16 *)(reg_a5 + 0x20);
        reg_d6.h[0] = *(u16 *)(reg_a5 + 0x22);
        reg_d1.w = 0;
        reg_d1.h[0] = D_0029C064[0];
        reg_d0.w = 0;
        reg_d0.h[0] = reg_d6.h[0];
        func_0011C0B0();
    }
    func_0014C4B0();
    func_00170A50(0, 0, 0);
}

s32 func_00131440();
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
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];

void func_001394A0(void) {
    stage_load_step();
    D_0028DF1C += 1;
    if (D_0028EC58 == 0) {
        if ((g_loaded_stage == g_stage) && (D_0028DF1C >= 0)) {
            D_0028EC58 = 1;
            func_00131440();
        }
    } else if (D_0028E370 != 0) {
        if (D_0028E3C0 == 0) {
            D_0028E378_as_s8 = 0;
        }
        *(u8 *)(reg_a5 + 2) |= 2;
        D_0028EC58 = 0;
        if (D_0028E3C0 == 0) {
            D_0028E368_as_s8 = 1;
        }
        func_00138CC0();
        func_002256B0();
        func_00138110();
        stage_map_show();
#ifdef DEATH_LABEL
        if (g_loop == 0) {
            D_0028E288_as_s8 = 0;
            D_0028E284_as_s8 = 0;
        }
#else
        if (D_0028ED80 == 0) {
            if (g_loop == 0) {
                D_0028E288_as_s8 = 0;
                D_0028E284_as_s8 = 0;
            }
        } else if (D_0028E280 != 5) {
            D_0028E288_as_s8 = 0;
            D_0028E284_as_s8 = 0;
        }
#endif
        if ((D_0028ED80 == 0) && (g_loop == 1) && (g_stage == 0)) {
            if (D_0029F260[0] < 0) {
                if (g_p1_hyper_items != 0) {
                    g_p1_hyper_time_as_s16 = 0;
                    D_0028E288_as_s8 = 0x78;
                }
            } else if ((D_0029F1F0[0] < 0) && (g_p2_hyper_items != 0)) {
                g_p2_hyper_time_as_s16 = 0;
                D_0028E284_as_s8 = 0x78;
            }
        }
        if ((D_0028ED80 == 0) && (D_0028ED7C != 2)) {
            if ((g_p1_score_digits == 0) && (D_0029F260[0] < 0)) {
                D_0028E25C = g_stage + (g_loop * 5);
                if (D_0028E304 != 0) {
                    D_0028E25C = g_stage + 5;
                }
            } else if ((g_p2_score_digits == 0) && (D_0029F1F0[0] < 0)) {
                D_0028E25C = g_stage + (g_loop * 5);
                if (D_0028E304 != 0) {
                    D_0028E25C = g_stage + 5;
                }
            }
            D_0028E2BD = D_0028E25C;
        }
    }
}

extern u16 D_0029C060[];

void func_001396B0(void) {
    D_0029C070[0] = 0;
    reg_d2.h[0] = 0x800;
    reg_d0.h[0] = D_0029C060[0];
    D_0029C060[0] = 0;
    reg_d0.h[0] += *(u16 *)(reg_a5 + 0x2A);
    reg_d1.h[0] = reg_d0.h[0];
    if ((s16)(reg_d1.h[0]) < 0) {
        reg_d1.h[0] *= 0xFFFF & 0xFFFF;
        reg_d2.h[0] *= 0xFFFF;
    }
    if ((s32) reg_d1.h[0] > 0x800) {
        reg_d0.h[0] = reg_d2.h[0];
        D_0029C070[0] = 1;
    }
    *(u16 *)(reg_a5 + 0x2A) = (u16) reg_d0.h[0];
    reg_d0.h[0] &= 0xFFC0;
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x28);
    *(u16 *)(reg_a5 + 0x28) = (u16) reg_d0.h[0];
    reg_d2.h[0] = reg_d0.h[0];
    reg_d0.h[0] -= reg_d1.h[0];
}


void func_00139790(void) {
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

void func_00139800(void) {
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
    reg_d1.h[0] = D_0029C060[0];
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
    D_0029C060[0] = reg_d1.h[0];
block_rts:;
}

extern u16 D_0029C062_as_u16_a[];
extern u16 D_0029C066[];
extern u16 D_0029C068[];
extern u16 D_0029C06A[];
extern u16 D_0029C06C[];
extern u16 D_0029C06E[];
extern u16 D_0029F1F0_as_u16_a[];
extern u16 D_0029F260_as_u16_a[];

void func_00139930(void) {
    if (D_0029C062_as_u16_a[0] != 0) {
        goto next_1;
    }
    reg_d0.h[0] = D_0029F260_as_u16_a[0];
    reg_d1.h[0] = D_0029F1F0_as_u16_a[0];
    reg_d1.h[0] ^= reg_d0.h[0];
    if (0 > (s64) (s16) reg_d1.h[0]) {
        goto next_2;
    }
next_1:
    reg_a5[0x31] &= 0x3F;
    reg_a1 = (u8 *) D_0029F260_as_u16_a;
    func_00139790();
    reg_a1 = (u8 *) D_0029F1F0_as_u16_a;
    func_00139790();
    reg_a1 = (u8 *) D_0029F260_as_u16_a;
    func_00139800();
    reg_a1 = (u8 *) D_0029F1F0_as_u16_a;
    func_00139800();
    goto next_4;
next_2:
    reg_a6 = (u8 *) D_0029F260_as_u16_a;
    if (0 > (s64) (s16) D_0029F260_as_u16_a[0]) {
        goto next_3;
    }
    reg_a6 = (u8 *) D_0029F1F0_as_u16_a;
next_3:
    reg_d0.w = 0;
    reg_d0.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d0.w -= 0x1C00;
    reg_d0.w = (s32) reg_d0.w / 200;
    reg_d0.h[0] <<= 6;
    reg_d0.h[0] -= *(u16 *) (reg_a5 + 0x28);
    D_0029C060[0] = reg_d0.h[0];
next_4:
    func_001396B0();
    D_0029C064[0] = reg_d0.h[0];
    reg_d1.h[0] = *(u16 *) (reg_a5 + 0x28);
    reg_d1.h[0] >>= 6;
    reg_d2.h[0] = reg_d1.h[0];
    reg_d1.h[0] <<= 6;
    D_0029C066[0] = D_0029C068[0];
    D_0029C068[0] = reg_d1.h[0];
    reg_d0.h[0] = D_0029C06A[0];
    D_0029C06A[0] = reg_d2.h[0];
    reg_d2.h[0] -= reg_d0.h[0];
    reg_d2.h[0] <<= 6;
    D_0029C06C[0] = reg_d2.h[0];
    D_0029C06E[0] -= reg_d2.h[0];
}
