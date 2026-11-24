#include "common.h"

extern void text_queue_clear(void);
extern void frame_draw_left_panel(s32 level);
extern void text_flush(void);
extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
extern void func_002228D0(s32 x, s32 y);
extern void func_002242B0(s32 x, s32 y);
extern u8 *D_00270870[];
extern u8 *D_002708B0[];
extern u8 *D_002708F0[];
extern u8 *D_00270A00[];
extern u8 *D_00271320[];
extern s8 D_002714F9[];
extern s8 D_002714FA[];
extern u8 *D_00271A20[];
extern u8 *D_00271A50[];
extern u8 *D_00271A70[];
extern u8 *D_00271A90[];
extern u8 *D_00271AB0[];
extern u8 *D_00271AD0[];
extern u8 *D_00271B08[];
extern u8 *D_00271B18[];
extern u8 *D_0028DCE8[2];
extern u8 *D_0028DCF0[2];
extern u8 *D_0028DCFC;
extern u8 *D_0028DD00;
extern u8 *D_0028DD04;
extern u8 *D_0028DD08;
extern u8 *D_0028DD78[2];
extern u8 *D_0028DD80;
extern u8 *D_0028DD8C;
extern u16 D_0028E300;
extern s8 D_0028EAE8;
extern s8 D_0028EB00;
extern s8 D_0028EB04;
extern s8 D_0028EB14;
extern s8 D_0028EB18;
extern s8 D_0028EB1C;
extern s8 D_0028EB20;
extern s8 D_0028EB24;
extern s8 D_0028EB28;
extern s8 D_0028EB50;
extern s8 D_0028EB6C;
extern s8 D_0028EB7C;
extern s8 D_0028EB84;
extern s32 D_0028EB8C;
extern s32 D_0028EB90;
extern u8 D_0028EBE8;
extern s8 D_0028EBEA;
extern s8 D_0028EBF2;
extern s8 D_0028EBFA;
extern s8 D_0028EC02;
extern s8 D_0028EC0A;
extern s8 D_0028EC12;
extern s8 D_0028EC1A;
extern u8 D_0028EC3C_as_u8;
extern s32 D_0028EC7C;
extern s8 D_0068DD01[];
#ifdef DEATH_LABEL
extern u8 *death_D_0028FFDC;
extern u8 *death_D_00290078[2];
extern u8 *death_D_00290080[2];
extern u8 *death_D_002634D0[];
extern s8 death_D_00290C4C;
#endif
extern u8 *reg_a0;

void func_00221550(void) {
    s64 alpha;
    s32 item;
    u8 state;

    switch (D_0028EB04) {
    case 0:
        break;
    case 1:
        D_0028EB90 += 4;
        D_0028EB8C += 4;
        if (D_0028EB90 >= 0x80) {
            D_0028EB04 = 0;
            D_0028EB90 = 0x80;
#ifndef DEATH_LABEL
            D_0028EB8C = 0x80;
#endif
        }
        if (D_0028EB8C >= 0x80) {
            D_0028EB8C = 0x80;
        }
        break;
    case 2:
        D_0028EB90 -= 4;
        if (D_0028EB90 <= 0) {
            D_0028EB90 = 0;
            D_0028EB04 = 0;
        }
        break;
    }
    if (D_0028EB84 == 0xD) {
        return;
    }
    if (D_0028EB90 != 0) {
        text_queue_clear();
        alpha = D_0028EB90;
        if (alpha >= 0x40) {
            alpha = 0x40;
        }
        if (alpha != 0) {
            frame_draw_left_panel(D_0028EB8C);
            gfx_draw_color_box(0xC, 8, 0x40, 0xD0, 0x12C, alpha, 1, 1, 0x40);
        }
        if (D_0028EB84 == 0) {
            reg_a0 = D_00271A20[D_0028EB28];
            if (D_0028EB00 != 3) {
                if (D_0028EB7C != 4 || D_0028EC7C == 0) {
                    func_002228D0(0x36, 8);
                }
            }
        }
        if (D_0028EB84 == 1) {
            reg_a0 = D_00271A50[D_0028EB24];
            func_002228D0(0x36, 8);
        }
        if (D_0028EB84 == 2) {
            reg_a0 = D_00271A70[D_0028EB20];
            func_002228D0(0x36, 8);
        }
        if (D_0028EB84 == 3) {
            item = D_0028EB1C;
            reg_a0 = D_00271A90[item];
            if (item == 1 && !(D_0028E300 & 1)) {
                reg_a0 = (u8 *)D_0028DD80;
            }
            if (item == 2 && !(D_0028E300 & 2)) {
                reg_a0 = (u8 *)D_0028DD80;
            }
            if (item == 4 && !(D_0028E300 & 8)) {
                reg_a0 = (u8 *)D_0028DD80;
            }
            if (item == 5 && !(D_0028E300 & 0x10)) {
                reg_a0 = (u8 *)D_0028DD80;
            }
            func_002228D0(0x36, 8);
        }
        if (D_0028EB84 == 0xE) {
            reg_a0 = D_00271AB0[D_0028EB18];
            if (D_0028EB6C != 4 || D_0028EC7C == 0) {
                func_002228D0(0x36, 8);
            }
        }
        if (D_0028EB84 == 0x15) {
            if (D_0028EB50 != 0) {
                gfx_draw_color_box(0xE0, 0, 0x6E, 0xE0, 0x5A, D_0028EB50, 0xB4, 1, 1);
            }
            reg_a0 = MAIN_OR_DEATH_LABEL(D_00271B08, death_D_00290078)[D_0028EAE8];
            func_002228D0(0x36, 8);
            reg_a0 = MAIN_OR_DEATH_LABEL(D_00271B18, death_D_00290080)[D_0028EAE8];
            func_002228D0(0x136, 8);
            func_002242B0(0xC, 4);
        }
#ifdef DEATH_LABEL
        if (D_0028EB84 == 0x17) {
            reg_a0 = death_D_002634D0[death_D_00290C4C];
            func_002228D0(0x36, 8);
        }
#endif
        if (D_0028EB84 == 0x18) {
            reg_a0 = (u8 *)D_0028DD8C;
            func_002228D0(0x36, 8);
        }
        if (D_0028EB84 == 0xF) {
            reg_a0 = D_00271AD0[D_0028EB14];
            func_002228D0(0x36, 8);
            if (D_0028EB14 == 1) {
                reg_a0 = D_0028DD78[D_0068DD01[0]];
                func_002228D0(0x22, 8);
            }
        }
    }
    if (D_0028EB84 == 7) {
        reg_a0 = D_00270870[D_0028EC1A];
        func_002228D0(0x36, 8);
    }
    if (D_0028EB84 == 8) {
        reg_a0 = D_002708B0[D_0028EC12];
        func_002228D0(0x36, 8);
    }
    if (D_0028EB84 == 0x11) {
        reg_a0 = D_002708F0[D_0028EC0A];
        func_002228D0(0x36, 8);
    }
    if (D_0028EB84 == 0x12) {
        reg_a0 = D_00270A00[D_0028EC02];
        func_002228D0(0x36, 8);
    }
    if (D_0028EB84 == 0x13) {
        reg_a0 = D_00271320[D_0028EBFA];
        func_002228D0(0x36, 8);
    }
    if (D_0028EB84 == 9) {
        reg_a0 = D_0028DCE8[(D_0028EBF2 == D_002714F9[0] - 1) ? 1 : 0];
        func_002228D0(0x36, 8);
    }
    if (D_0028EB84 == 0xA) {
        reg_a0 = D_0028DCF0[(D_0028EBEA == D_002714FA[0] - 1) ? 1 : 0];
        if (D_0028EBE8 >= 3) {
            func_002228D0(0x36, 8);
        }
    }
    if (D_0028EB84 == 0xB) {
        state = D_0028EC3C_as_u8;
        if (state != 0 && (u32)(state - 1) > 1 && (u32)(state - 5) > 1) {
            reg_a0 = (u8 *)MAIN_OR_DEATH_LABEL(D_0028DCFC, death_D_0028FFDC);
            func_002228D0(0x36, 8);
        }
    }
    if (D_0028EB84 == 0x16) {
        reg_a0 = (u8 *)MAIN_OR_DEATH_LABEL(D_0028DD00, death_D_0028FFDC);
        func_002228D0(0x36, 8);
    }
    if (D_0028EB84 == 0x14) {
        state = D_0028EC3C_as_u8;
        if (state != 0 && (u32)(state - 1) > 1 && (u32)(state - 5) > 1) {
            reg_a0 = (u8 *)D_0028DD04;
            func_002228D0(0x36, 8);
        }
    }
    if (D_0028EB84 == 0xD) {
        reg_a0 = (u8 *)D_0028DD08;
        func_002228D0(0x36, 8);
    }
    text_flush();
}
