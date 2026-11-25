#include "common.h"

void func_00208710(void);
void func_00208AD0(void);
void func_00208D30(void);

extern u8 D_0028DFA0_as_u8;

void func_00208610(void) {
    s32 func_002093C0();
    reg_d0.w = 5;
    reg_d1.w = 9;
    reg_d2.w = -1U;
    reg_d1.b[0] -= D_0028DFA0_as_u8;
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] += 0x18;
    func_002093C0();
}

void func_00208660(void)
{
    extern void func_002093C0(void);
    reg_d0.w = 5;
    reg_d1.w = 9;
    reg_d2.w = 0;
    reg_d1.b[0] -= D_0028DFA0_as_u8;
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] += 0x18;
    func_002093C0();
}

s32 func_0012FD00();                            /* extern */
extern s32 D_00267F18[];
extern s32 D_00267FF0[];
extern s32 D_00268010_as_s32_a[];
extern s8 D_0028DF9C;
extern s8 D_0028DFA0;
extern s32 *reg_a0_as_s32_p;

void func_002086A0(void) {
    s32 func_00209200();
    func_0012FD00();
    func_00208AD0();
    D_0028DFA0 = 0;
    D_0028DF9C = 0;
    func_00208710();
    reg_d0.h[0] = 0;
    reg_a0 = (u8 *)D_00267F18;
    func_00209200();
    reg_a0 = (u8 *)D_00267FF0;
    func_00209200();
    reg_a0 = (u8 *)D_00268010_as_s32_a;
    func_00209200();
    func_00208660();
    reg_d0.w = 0;
}

extern u8 D_00267F28[];
extern u8 D_00267F38[];
extern u8 D_00267F50[];
extern u8 D_00267F60[];
extern u8 D_00267F70[];
extern u8 D_00267F88[];
extern u8 D_00267F98[];
extern u8 D_00267FB0[];
extern u8 D_00267FC8[];
extern u8 D_00267FD8[];
extern u8 *D_00268050[];

void func_00208710(void) {
    void func_00209200(void);
    u8 **table;

    reg_a0 = (u8 *)D_00267F28;
    reg_d0.h[0] = 0;
    func_00209200();
    reg_a0 = (u8 *)D_00267F38;
    func_00209200();
    reg_a0 = (u8 *)D_00267F50;
    func_00209200();
    reg_a0 = (u8 *)D_00267F60;
    func_00209200();
    reg_a0 = (u8 *)D_00267F70;
    func_00209200();
    reg_a0 = (u8 *)D_00267F88;
    func_00209200();
    reg_a0 = (u8 *)D_00267F98;
    func_00209200();
    reg_a0 = (u8 *)D_00267FB0;
    func_00209200();
    reg_a0 = (u8 *)D_00267FC8;
    func_00209200();
    reg_a0 = (u8 *)D_00267FD8;
    func_00209200();
    table = D_00268050;
    reg_d0.w = 0;
    reg_d0.b[0] = D_0028DFA0;
    table += reg_d0.h[0];
    reg_a0 = *table;
    reg_d0.h[0] = 2;
    func_00209200();
}


s32 input_get_p1_pressed();
s32 sfx_confirm();
s32 sfx_cursor_move();
s32 func_002093F0();
extern u8 D_00268010[];
extern u8 D_00268030[];

void func_00208800(void) {
    s32 func_00209200();
    input_get_p1_pressed();
    if (reg_d0.w & 1) {
        sfx_cursor_move();
        func_00208610();
        D_0028DFA0 -= 1;
        if (0 > D_0028DFA0) {
            D_0028DFA0 = 9;
        }
        func_00208660();
        func_00208710();
        reg_d0.h[0] = 0;
        reg_a0 = (u8 *)D_00268010;
        func_00209200();
        if (D_0028DFA0 == 8) {
            reg_a0 = (u8 *)D_00268030;
            func_00209200();
        }
    }
    input_get_p1_pressed();
    if (reg_d0.w & 2) {
        sfx_cursor_move();
        func_00208610();
        D_0028DFA0 += 1;
        if (D_0028DFA0 > 9) {
            D_0028DFA0 = 0;
        }
        func_00208660();
        func_00208710();
        reg_d0.h[0] = 0;
        reg_a0 = (u8 *)D_00268010;
        func_00209200();
        if (D_0028DFA0 == 8) {
            reg_a0 = (u8 *)D_00268030;
            func_00209200();
        }
    }
    input_get_p1_pressed();
    if (reg_d0.w & 0x10) {
        sfx_confirm();
        if (D_0028DFA0 == 0) {
            reg_d0.w = 1;
            func_002093F0();
        }
        if (D_0028DFA0 == 1) {
            reg_d0.w = 2;
            func_002093F0();
        }
        if (D_0028DFA0 == 2) {
            reg_d0.w = 3;
            func_002093F0();
        }
        if (D_0028DFA0 == 3) {
            reg_d0.w = 4;
            func_002093F0();
        }
        if (D_0028DFA0 == 4) {
            reg_d0.w = 5;
            func_002093F0();
        }
        if (D_0028DFA0 == 5) {
            reg_d0.w = 6;
            func_002093F0();
        }
        if (D_0028DFA0 == 6) {
            reg_d0.w = 7;
            func_002093F0();
        }
        if (D_0028DFA0 == 7) {
            reg_d0.w = 8;
            func_002093F0();
        }
        if (D_0028DFA0 == 8) {
            reg_d0.w = 9;
            func_002093F0();
        }
        if (D_0028DFA0 == 9) {
            cond_flag = 1;
            return;
        }
        goto block_31;
    }
block_31:
    cond_flag = 0;
}

extern s32 g_text_palette[];
extern s32 reg_a1_as_s32;

void func_00208A60(void)
{
    s32 *source = reg_a0_as_s32_p;
    s32 *destination = g_text_palette;
    s32 offset;

    reg_d0.h[0] <<= 5;
    offset = (s32)reg_d0.h[0] >> 2;
    reg_a1_as_s32 = reg_a1_as_s32 + offset;
    reg_d0.w = 7;

    do {
        *destination++ = *source++;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

extern u8 D_00269160[];
extern u8 D_00269180[];
extern u8 D_002691A0[];
extern u8 D_002691C0[];
extern u8 D_002691E0[];

void func_00208AD0(void) {
    reg_a0 = D_00269160;
    reg_d0.w = 0;
    func_00208A60();
    reg_a0 = D_00269180;
    reg_d0.w = 1;
    func_00208A60();
    reg_a0 = D_002691A0;
    reg_d0.w = 2;
    func_00208A60();
    reg_a0 = D_002691C0;
    reg_d0.w = 3;
    func_00208A60();
    reg_a0 = D_002691E0;
    reg_d0.w = 4;
    func_00208A60();
}

s32 func_00209410();                            /* extern */
s32 func_002095E0();                            /* extern */
extern s8 D_0028DFA4;
extern s8 D_0028DFB0;

void func_00208B60(void) {
    D_0028DFB0 = 0x3C;
    D_0028DFA4 = 0;
    func_002095E0();
    if (cond_flag != 0) {
        func_00209410();
    }
}

typedef void (*Fn)();

s32 func_00137C50();
s32 sound_stop_effects();
s32 sound_stop_loops();
s32 music_stop();
extern u8 D_00268080[];
extern s8 D_0028DFA8_as_s8;
extern s8 D_0028DFAC;
extern s16 D_0028E3B8;
extern void (*reg_call_target)();

void func_00208BA0(void) {
    if (*(u8 *)(reg_a5 + 3) != 0) {
        if (D_0028DFAC == 1) {
            reg_d0.w = 0;
            D_0028DFAC = 2;
            reg_d0.b[0] = (u8) D_0028DFA8_as_s8;
            reg_d0.h[0] += reg_d0.h[0];
            reg_a0 = *(u8 **)((u8 *)D_00268080 + (reg_d0.h[0] * 4));
            reg_call_target = (Fn)(reg_a0);
            reg_call_target();
        }
        reg_d0.w = 0;
        reg_d0.b[0] = (u8) D_0028DFA8_as_s8;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += 1;
        reg_a0 = *(u8 **)((u8 *)D_00268080 + (reg_d0.h[0] * 4));
        reg_call_target = (Fn)(reg_a0);
        reg_call_target();
        return;
    }
    D_0028DFA8_as_s8 = 0;
    D_0028DFB0 = 0x3C;
    D_0028DFAC = 1;
    func_00208AD0();
    *(u8 *)(reg_a5 + 3) = 1U;
    music_stop();
    sound_stop_effects();
    sound_stop_loops();
    func_00137C50();
    D_0028E3B8 = 1;
}

extern s32 D_002680D0[];
extern s32 D_00268100[];

void func_00208CD0(void) {
    s32 func_00209200();
    func_0012FD00();
    func_00208AD0();
    D_0028DFA0 = 0;
    D_0028DF9C = 1;
    func_00208D30();
    reg_d0.h[0] = 0;
    reg_a0 = (u8 *)D_002680D0;
    func_00209200();
    reg_a0 = (u8 *)D_00268100;
    func_00209200();
    reg_d0.w = 0;
}

extern s32 D_002680E0[];

void func_00208D30(void) {
    extern void func_00209200(void);
    reg_d0.h[0] = 0;
    reg_a0 = (u8 *)D_002680E0;
    func_00209200();
}
