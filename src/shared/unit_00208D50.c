#include "common.h"

void func_00208E20(void);
void func_00209200(void);
void func_002093F0();

s32 func_00131420();                            /* extern */
s32 func_0016A8B0();                            /* extern */
s32 func_0016A8D0();                            /* extern */
s32 func_00208D30();                            /* extern */

void func_00208D50(void) {
    u32 temp_a0;

    func_00208D30();
    func_0016A8D0();
    if (reg_d0.w & 0x20) {
        func_00131420();
    }
    func_0016A8B0();
    temp_a0 = reg_d0.w;
    if ((temp_a0 & 0x8000) && (temp_a0 & 0x10)) {
        reg_d0.w = 0;
        func_002093F0(temp_a0);
    }
    reg_d0.w = 0;
}

s32 func_0012FD00();                            /* extern */
s32 func_00208AD0();                            /* extern */
extern s32 D_00268120[];
extern s32 D_00268210[];
extern s8 D_0028DF9C;
extern s8 D_0028DFA0;
extern s32 *reg_a0_as_s32_p;

void func_00208DC0(void) {
    func_0012FD00();
    func_00208AD0();
    D_0028DFA0 = 0;
    D_0028DF9C = 1;
    func_00208E20();
    reg_d0.h[0] = 0;
    reg_a0_as_s32_p = D_00268120;
    func_00209200();
    reg_a0_as_s32_p = D_00268210;
    func_00209200();
    reg_d0.w = 0;
}

extern s32 D_00268130[];
extern s32 D_00268150[];
extern s32 D_00268170[];
extern s32 D_00268190[];
extern s32 D_002681B0[];
extern s32 D_002681D0[];
extern s32 D_002681F0[];

void func_00208E20(void) {
    reg_a0_as_s32_p = D_00268130;
    reg_d0.h[0] = 0;
    func_00209200();
    reg_a0_as_s32_p = D_00268150;
    func_00209200();
    reg_a0_as_s32_p = D_00268170;
    func_00209200();
    reg_a0_as_s32_p = D_00268190;
    func_00209200();
    reg_a0_as_s32_p = D_002681B0;
    func_00209200();
    reg_a0_as_s32_p = D_002681D0;
    func_00209200();
    reg_a0_as_s32_p = D_002681F0;
    func_00209200();
}


void func_00208EB0(void) {
    s32 func_0011C2B0();
    s32 s_d0;
    s32 s_d1;
    s32 s_d2;
    s32 s_d3;
    s32 s_d4;
    s32 s_d5;
    s32 s_d6;
    s32 s_d7;
    s32 i;

    s_d0 = reg_d0.w;
    s_d1 = reg_d1.w;
    s_d2 = reg_d2.w;
    s_d3 = reg_d3.w;
    s_d4 = reg_d4.w;
    s_d5 = reg_d5.w;
    s_d6 = reg_d6.w;
    s_d7 = reg_d7.w;
    reg_d3.w &= 0xFFFF;
    reg_d5.w = reg_d3.w;
    reg_tmp5.h[0] = reg_d5.h[0];
    reg_d5.h[0] = reg_d5.h[1];
    reg_d5.h[1] = reg_tmp5.h[0];
    reg_d6.h[0] = reg_d2.h[0];
    reg_d2.w = 0;
    reg_d3.w = 0;
    reg_d7.w = 3;
loop_1:
    i = 0;
loop_2:
    if (reg_d5.w & 0x80000000) {
        reg_d5.w = reg_d5.w * 2;
        reg_d5.w = reg_d5.w | 1;
    } else {
        reg_d5.w = reg_d5.w * 2;
    }
    i += 1;
    if (i < 4) {
        goto loop_2;
    }
    reg_d4.w = reg_d5.w;
    reg_d4.w &= 0xF;
    if (reg_d4.b[0] < 0xA) goto next_1;
    reg_d4.h[0] += 7;
next_1:
    reg_d4.h[0] += 0x30;
    reg_tmp4.h[0] = reg_d4.h[0];
    reg_d4.h[0] = reg_d4.h[1];
    reg_d4.h[1] = reg_tmp4.h[0];
    reg_d4.h[0] = reg_d6.h[0];
    func_0011C2B0();
    reg_d0.h[0] += 1;
    if ((s16)(--reg_d7.h[0]) >= 0) goto loop_1;
    reg_d0.w = s_d0;
    reg_d1.w = s_d1;
    reg_d2.w = s_d2;
    reg_d3.w = s_d3;
    reg_d4.w = s_d4;
    reg_d5.w = s_d5;
    reg_d6.w = s_d6;
    reg_d7.w = s_d7;
}

typedef void (*Fn)();

s32 func_0016A8B0();
s32 func_0016A8D0();
s32 func_0018DE90();
s32 func_0018DEA0();
s32 func_0018DEE0();
extern u8 D_00268230[];
extern void (*jtbl_0028E3F4)();

void func_00209050(void) {
    u32 t;

    func_00208E20();
    func_0016A8D0();
    if (!(reg_d0.w & 1)) goto next_1;
    D_0028DFA0 += 1;
    if (D_0028DFA0 < 0x2F) goto next_1;
    D_0028DFA0 = 0x2E;
next_1:
    if (!(reg_d0.w & 2)) goto next_2;
    D_0028DFA0 -= 1;
    if (0 <= D_0028DFA0) goto next_2;
    D_0028DFA0 = 0;
next_2:
    if (!(reg_d0.w & 8)) goto next_3;
    D_0028DFA0 += 0x10;
    if (D_0028DFA0 < 0x2F) goto next_3;
    D_0028DFA0 = 0x2E;
next_3:
    if (!(reg_d0.w & 4)) goto next_4;
    D_0028DFA0 -= 0x10;
    if (0 <= D_0028DFA0) goto next_4;
    D_0028DFA0 = 0;
next_4:
    if (!(reg_d0.w & 0x10)) goto next_5;
    reg_d1.w = 0;
    reg_d1.b[0] = (u8) D_0028DFA0;
    reg_a0 = *(u8 **)((u8 *)D_00268230 + (reg_d1.h[0] * 4));
    jtbl_0028E3F4 = (Fn)(reg_a0);
    jtbl_0028E3F4();
next_5:
    if (!(reg_d0.w & 0x20)) goto next_6;
    func_0018DEE0();
    func_0018DE90();
    func_0018DEA0();
next_6:
    reg_d3.w = 0;
    reg_d0.h[0] = 0x13;
    reg_d2.h[0] = 0;
    reg_d1.h[0] = 0x2A;
    reg_d3.b[0] = (u8) D_0028DFA0;
    func_00208EB0();
    func_0016A8B0();
    t = reg_d0.w;
    if ((t & 0x8000) && (t & 0x10)) {
        reg_d0.w = 0;
        func_002093F0();
        func_0018DEE0();
        func_0018DE90();
        func_0018DEA0();
    }
    reg_d0.w = 0;
}

extern s8 *reg_a0_as_s8_p;

void func_00209200(void) {
    s32 func_0011C2B0(void);
    u32 saved;

    saved = reg_d0.w;
    reg_d3.w = 0;
    reg_d2.w = 0;
    reg_d5.h[0] = reg_d0.h[0];
loop_1:
    reg_d1.w = 0;
    reg_d0.w = 0;
    reg_d0.b[0] = *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    reg_d1.b[0] = *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    reg_a0_as_s8_p += 1;
loop_2:
    reg_d4.w = 0;
    reg_d4.b[0] = *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    if (reg_d4.b[0] == 0x7F) {
        goto loop_1;
    }
    if ((s8) reg_d4.b[0] != -1) {
        reg_d4.h[0] &= 0xFF;
        reg_tmp4.h[0] = reg_d4.h[0];
        reg_d4.h[0] = reg_d5.h[0];
        reg_d4.h[1] = reg_tmp4.h[0];
        func_0011C2B0();
        reg_d0.h[0] += 1;
        goto loop_2;
    }
    reg_d0.w = saved;
}

void func_002092F0(void) {
    s32 func_0011C2B0();
    u8 *a0;
    u32 d0;
    u32 d1;
    u32 d2;

    d2 = reg_d2.w;
    d0 = reg_d0.w;
    d1 = reg_d1.w;
    a0 = reg_a0;
    reg_d3.w = 0;
    reg_d5.h[0] = reg_d2.h[0];
    reg_d2.w = 0;
loop_1:
    reg_d4.w = 0;
    reg_d4.sb[0] = *(s8 *)reg_a0;
    reg_a0 += 1;
    if (reg_d4.sb[0] == -1) goto next_1;
    reg_d4.h[0] = reg_d4.b[0];
    reg_tmp4.h[0] = reg_d4.h[0];
    reg_d4.h[0] = reg_d5.h[0];
    reg_d4.h[1] = reg_tmp4.h[0];
    func_0011C2B0();
    reg_d0.h[0] += 1;
    goto loop_1;
next_1:
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_a0 = a0;
}

void func_002093C0(void) {
    void func_0011C2B0(void);
    s32 value = 0x200002;

    reg_d4.sw = value;
    value = 0;
    if ((s16)value <= (s16)reg_d2.sw) {
        reg_d4.sw = 0x3E0002;
    }
    reg_d3.sw = value;
    reg_d2.sw = 0;
    func_0011C2B0();
}

extern u8 D_0028DFA8;
extern s8 D_0028DFAC;

void func_002093F0() {
    D_0028DFAC = 1;
    D_0028DFA8 = reg_d0.b[0];
}

s32 stage_map_reset();
s32 func_0021D500();
s32 func_0021DF60();
s32 func_0021E2D0();
s32 func_0021F440();
s32 func_00235890();
extern s8 D_0028C0F9[];
extern s8 D_0028C0FA[];
extern s8 D_0028C0FB[];
extern s8 D_0028C0FC[];
extern s8 D_0028C0FD[];
extern s8 D_0028C0FE[];
extern s8 D_0028C0FF[];
extern u8 g_display_offset_y_as_u8;
extern u8 g_display_offset_x_as_u8;
extern u8 D_0028E258;
extern u8 D_0028E25C;
extern u8 D_0028E260;
extern u8 D_0028E264;
extern u8 D_0028E268;
extern u8 g_p1_btn_map_a_as_u8;
extern u8 g_p1_btn_map_b;
extern u8 g_p1_btn_map_c;
extern u8 D_0028E273;
extern u8 g_p2_btn_map_a;
extern u8 g_p2_btn_map_b;
extern u8 g_p2_btn_map_c;
extern u8 D_0028E277;
extern u8 D_0028E278;
extern u8 g_pad_vib_enabled;
extern u8 D_0028E284;
extern u8 D_0028E288;
extern u8 g_stage_map_enabled;
extern u8 D_0028E294;
extern u8 g_pad_input_locked;
extern s16 D_0028E29C_as_s16;
extern u8 D_0028E2A0;
extern u8 D_0028E2A4;
extern u8 D_0028E2A8;
extern s16 D_0028E2AC_as_s16;
extern u8 D_0028E2B0;
extern u8 D_0028E2C4;
extern u8 D_0028E2C8;
extern u8 D_0028E2CC;
extern u8 D_0028E2D0;
extern u8 D_0028E2D4;
extern u8 D_0028E2D8;
extern u8 g_screen_wide;
extern u8 D_0028E2E0;
extern u8 D_0028E2E4;
extern u8 D_0028E2EC;
extern u8 g_splash_visible;
extern u8 g_pad_tate_rotate;
extern s16 D_0028E2FC_as_s16;
extern s16 D_0028E300_as_s16;
extern u8 D_0028E304;
extern u8 D_0028E308;
extern u8 D_0028E30C;
extern u8 D_0028E310;
extern s16 D_0028E324_as_s16;
extern s16 D_0028E328_as_s16;
extern s16 D_0028E32C_as_s16;
extern u8 D_0028E354;
extern u8 D_0028E368;
extern u8 g_paused;
extern u8 D_0028E370;
extern u8 D_0028E374;
extern u8 D_0028E378;
extern u8 D_0028E37C;
extern u8 D_0028E380;
extern u8 D_0028E384;
extern u8 D_0028E388;
extern u8 D_0028E38C;
extern u8 D_0028E390;
extern u8 D_0028E394;
extern u8 D_0028E398;
extern u8 D_0028E39C;
extern s32 D_0028EAF8;
extern s32 D_0028EAFC;
extern u8 D_0028EC54;
extern s32 D_0028EC78;
extern u8 D_0028ED30;
extern u8 D_0028ED31;
extern u8 D_0028ED32;
extern u8 D_0028ED33;
extern u8 D_0028ED34;
extern u8 D_0028ED35;
extern u8 D_0028ED36;
extern u8 D_0028ED37;

#ifdef DEATH_LABEL
extern u8 death_D_00290854;
extern u8 death_D_00290858;
#endif

void func_00209410(void) {
    D_0028E39C = 0x12;
#ifndef DEATH_LABEL
    D_0028EC54 = 0;
#endif
    g_screen_wide = 0;
    D_0028E354 = 0;
    D_0028E398 = D_0028C0F9[0];
    D_0028E394 = D_0028C0FA[0];
    D_0028E390 = D_0028C0FB[0];
    D_0028E38C = D_0028C0FC[0];
    D_0028E388 = D_0028C0FD[0];
    D_0028E384 = D_0028C0FE[0];
    D_0028E380 = D_0028C0FF[0];
    func_0021E2D0(D_0028C0FC[0], D_0028C0FB[0], D_0028C0FA[0], D_0028C0F9[0]);
    func_0021F440();
    func_0021DF60();
    D_0028E2D4 = 2;
    D_0028E2D0 = 3;
    g_p1_btn_map_a_as_u8 = 7;
    g_p2_btn_map_a = 7;
    g_p1_btn_map_b = 6;
    g_p2_btn_map_b = 6;
    g_p1_btn_map_c = 5;
    D_0028E273 = 1;
    g_p2_btn_map_c = 5;
    D_0028E32C_as_s16 = 5;
    D_0028E277 = 1;
    D_0028E37C = 1;
    D_0028E378 = 0xFF;
    D_0028E300_as_s16 = 0xFF;
    D_0028E328_as_s16 = 1;
    g_stage_map_enabled = 1;
    D_0028E264 = 1;
    D_0028E278 = 0;
    g_pad_vib_enabled = 0;
    D_0028E2D8 = 0;
    D_0028E2E0 = 0;
    D_0028E2C8 = 0;
    D_0028E2C4 = 0;
    D_0028E2CC = 0;
    D_0028E2B0 = 0;
    D_0028E2AC_as_s16 = 0;
    D_0028E2A8 = 0;
    g_splash_visible = 0;
    D_0028E370 = 0;
    D_0028E374 = 0;
    g_paused = 0;
    D_0028E368 = 0;
    D_0028E324_as_s16 = 0;
    D_0028E2EC = 0;
    D_0028E2E4 = 0;
    D_0028E310 = 0;
    g_display_offset_x_as_u8 = 0;
    g_display_offset_y_as_u8 = 0;
    g_pad_tate_rotate = 0;
    D_0028E30C = 0;
    D_0028E308 = 0;
    D_0028E304 = 0;
    D_0028E2FC_as_s16 = 0;
    D_0028E268 = 0;
    D_0028E260 = 0;
    D_0028E25C = 0;
    D_0028E258 = 0;
    D_0028EC78 = 0;
    D_0028E2A4 = 0;
    D_0028E29C_as_s16 = 0;
    D_0028E2A0 = 0;
    func_00235890(5, 6, 7);
    stage_map_reset();
    func_0021D500();
    D_0028ED30 = 0;
    D_0028E258 = 0xA;
    D_0028ED31 = 0;
    D_0028EAFC = 0xFF;
    D_0028ED32 = 0;
#ifdef DEATH_LABEL
    death_D_00290858 = 0x2A;
#endif
    D_0028ED33 = 0;
#ifdef DEATH_LABEL
    death_D_00290854 = 1;
#endif
    D_0028ED34 = 0;
    D_0028ED35 = 0;
    D_0028ED36 = 0;
    D_0028ED37 = 0;
    g_pad_input_locked = 0;
    D_0028E294 = 0;
    D_0028E288 = 0;
    D_0028E284 = 0;
    D_0028EAF8 = 0;
}


void func_002095E0(void) {
    reg_d0.b[0] = D_0028E39C;
    if ((s8) reg_d0.b[0] > 0x12) goto next_1;
    if (0 > (s8) reg_d0.b[0]) goto next_1;
    reg_d0.b[0] = D_0028E398;
    if ((s8) reg_d0.b[0] > 0x1) goto next_1;
    if (0 > (s8) reg_d0.b[0]) goto next_1;
    reg_d0.b[0] = D_0028E394;
    if ((s8) reg_d0.b[0] > 0x1) goto next_1;
    if (0 > (s8) reg_d0.b[0]) goto next_1;
    reg_d0.b[0] = D_0028E390;
    if ((s8) reg_d0.b[0] > 0x2) goto next_1;
    if (0 > (s8) reg_d0.b[0]) goto next_1;
    reg_d0.b[0] = D_0028E38C;
    if ((s8) reg_d0.b[0] > 0x3) goto next_1;
    if (0 > (s8) reg_d0.b[0]) goto next_1;
    reg_d0.b[0] = D_0028E388;
    if ((s8) reg_d0.b[0] > 0x3) goto next_1;
    if (0 > (s16) reg_d0.b[0]) goto next_1;
    reg_d0.b[0] = D_0028E384;
    if ((s8) reg_d0.b[0] > 0x4) goto next_1;
    if (0 > (s8) reg_d0.b[0]) goto next_1;
    reg_d0.b[0] = D_0028E380;
    if ((s8) reg_d0.b[0] > 0x1) goto next_1;
    if (0 > (s8) reg_d0.b[0]) goto next_1;
    cond_flag = 0;
    return;
next_1:
    cond_flag = 1;
}

extern u16 D_00268350[];
extern u8 D_0028DFA0_as_u8;
extern u16 *reg_a0_as_u16_p;

void func_00209710(void) {
    reg_d0.w = 3;
    reg_d1.w = 4;
    reg_a0_as_u16_p = D_00268350;
    reg_d1.b[0] -= D_0028DFA0_as_u8;
    reg_d1.h[0] += reg_d1.h[0];
    reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0_as_u16_p + ((s16)reg_d1.h[0] & ~1)) : *reg_a0_as_u16_p;
    reg_d2.w = -2U;
    func_002093C0();
}

void func_00209790(void) {
    reg_d0.w = 3;
    reg_d1.w = 4;
    reg_a0_as_u16_p = D_00268350;
    reg_d1.b[0] -= D_0028DFA0_as_u8;
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0_as_u16_p + ((s16)reg_d1.h[0] & ~1)) : *reg_a0_as_u16_p;
    reg_d2.w = 0;
    func_002093C0();
}
