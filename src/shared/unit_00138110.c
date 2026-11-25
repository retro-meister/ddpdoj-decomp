#include "common.h"
#include "entity.h"

extern s32 D_0026A2A0[];
extern u8 D_0028DAB8[];
extern u8 D_0028E38C;
extern u16 D_0028E7F0;
extern s32 D_0028E7F4;

#ifdef DEATH_LABEL
extern u16 D_0028E3C0;
#endif

void func_00138110(void) {
    reg_d0.w = 0;
    reg_d0.b[0] = D_0028E38C;
#ifdef DEATH_LABEL
    if (D_0028E3C0 != 0) {
        reg_d0.b[0] = 1;
    }
#endif
    reg_a0 = D_0028DAB8;
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    D_0028E7F0 = *(u16 *)reg_a0;
    D_0028E7F4 = D_0026A2A0[reg_d0.h[0] >> 1];
}

extern u8 D_0028E2D4;
extern u16 g_p2_hyper_total;
extern u16 g_p1_hyper_total;
extern u16 g_p2_hyper_active;
extern u16 g_p1_hyper_active;
extern u32 D_0028E8BC_as_u32;
extern u8 g_rank_1_16_as_u8;
extern u8 g_rank_2_16_as_u8;
extern u8 g_rank_3_16_as_u8;
extern u8 g_rank_4_16_as_u8;
extern u8 g_rank_5_16_as_u8;
extern u8 g_rank_6_16_as_u8;
extern u8 g_rank_7_16_as_u8;
extern u8 g_rank_8_16_as_u8;
extern u8 g_rank_9_16_as_u8;
extern u8 g_rank_10_16_as_u8;
extern u8 g_rank_11_16_as_u8;
extern u8 g_rank_12_16_as_u8;
extern u8 g_rank_13_16_as_u8;
extern u8 g_rank_14_16_as_u8;
extern u8 g_rank_15_16_as_u8;
extern u16 g_rank;
extern u16 g_loop;
extern u16 g_stage;
extern u8 D_0028ED80;
extern u16 D_006E5C02[];

void func_00138170(void) {
    reg_a0 = (u8 *) D_0028E7F4;
    reg_d2.h[0] = g_stage;
    reg_d1.w = 0;
    reg_d1.b[0] = *(s8 *) (reg_a0 + reg_d2.h[0]);
    reg_d2.w = D_0028E8BC_as_u32;
    reg_d3.w = 8;
    if (D_0028ED80 != 0 && D_006E5C02[0] != 0) {
        reg_d1.b[0] = D_0028E2D4;
    }
    reg_d2.w >>= reg_d3.w;
    reg_d1.h[0] += reg_d2.h[0];
    reg_d2.h[0] = 0xDF;
    reg_d0.h[0] = g_p1_hyper_active;
    if (((reg_d0.h[0] |= g_p2_hyper_active) & 0xFFFF) == 0) {
        goto next_2;
    }
    reg_d0.h[0] = g_p1_hyper_total;
    if ((s32) g_p2_hyper_total <= (s32) reg_d0.h[0]) {
        goto next_1;
    }
    reg_d0.h[0] = g_p2_hyper_total;
next_1:
    reg_d0.h[0] <<= 4;
    reg_d1.h[0] += reg_d0.h[0];
next_2:
    if (g_loop == 0) {
        goto next_3;
    }
    if (D_0028ED80 != 0 && D_006E5C02[0] != 0) {
        goto next_3;
    }
    g_rank = 0xFF;
    reg_d0.h[0] = g_p1_hyper_active;
    reg_d0.h[0] |= g_p2_hyper_active;
    if (reg_d0.h[0] != 0) {
        goto next_5;
    }
    g_rank = 0xF8;
    goto next_5;
next_3:
    g_rank = reg_d1.h[0];
    reg_d0.h[0] = g_p1_hyper_active;
    reg_d0.h[0] |= g_p2_hyper_active;
    if (reg_d0.h[0] != 0) {
        goto next_4;
    }
    if (g_rank <= 0xF0) {
        goto next_5;
    }
    g_rank = 0xF0;
    goto next_5;
next_4:
    if (g_rank <= 0xFF) {
        goto next_5;
    }
    g_rank = 0xFF;
next_5:
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *) &g_rank;
    reg_d7.h[0] = reg_d0.h[0];
    reg_d7.h[0] >>= 4;
    reg_d0.h[0] >>= 1;
    reg_d1.b[0] = reg_d0.b[0];
    reg_d6.b[0] = reg_d0.b[0];
    g_rank_8_16_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    g_rank_9_16_as_u8 = reg_d6.b[0];
    reg_d0.h[0] >>= 1;
    reg_d2.h[0] = reg_d0.h[0];
    reg_d6.b[0] = reg_d0.b[0];
    g_rank_4_16_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    g_rank_5_16_as_u8 = reg_d6.b[0];
    reg_d1.b[0] += reg_d0.b[0];
    reg_d6.b[0] = reg_d1.b[0];
    g_rank_12_16_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    g_rank_13_16_as_u8 = reg_d6.b[0];
    reg_d0.h[0] >>= 1;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d1.b[0] += reg_d0.b[0];
    reg_d6.b[0] = reg_d1.b[0];
    g_rank_14_16_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    g_rank_15_16_as_u8 = reg_d6.b[0];
    reg_d3.b[0] -= reg_d0.b[0];
    reg_d6.b[0] = reg_d3.b[0];
    g_rank_10_16_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    g_rank_11_16_as_u8 = reg_d6.b[0];
    reg_d3.h[0] = reg_d2.h[0];
    reg_d2.b[0] += reg_d0.b[0];
    reg_d6.b[0] = reg_d2.b[0];
    g_rank_6_16_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    g_rank_7_16_as_u8 = reg_d6.b[0];
    reg_d3.b[0] -= reg_d0.b[0];
    reg_d6.b[0] = reg_d3.b[0];
    g_rank_2_16_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    g_rank_3_16_as_u8 = reg_d6.b[0];
    g_rank_1_16_as_u8 = reg_d7.b[0];
}

extern u16 D_0028C108[4];
extern u16 D_0028C110[4];

void func_00138470(void)
{
    reg_a0 = (u8 *)D_0028C108;
    if (reg_d7.h[0] == 0) {
        reg_a0 = (u8 *)D_0028C110;
    }

    reg_d1.w = 2;
    do {
        if (*(u16 *)reg_a0 != reg_d0.h[0]) {
            break;
        }
        reg_a0 += 2;
    } while ((s16)(--reg_d1.h[0]) >= 0);

    reg_d0.h[0] = *(u16 *)reg_a0;
}

extern u8 D_00251A80[];
extern u8 D_00251A90[];

void func_001384E0(void) {
    if (reg_d7.h[0] == 0) {
        goto next_3;
    }
    reg_d0.w = 0;
    reg_a4 = (u8 *)D_00251A80;
    reg_d0.b[0] = *(u8 *) (reg_a5 + 6);
    if (0 > (s64) reg_d0.sb[0]) {
        *(u16 *) (reg_a6 + 4) = 0;
        *(u8 *) (reg_a5 + 7) = *(u8 *) (reg_a6 + 4);
        goto next_5;
    }
    func_00138470();
    *(u16 *) (reg_a6 + 4) = reg_d0.h[0];
    *(u8 *) (reg_a5 + 7) = *(u8 *) (reg_a6 + 4);
    goto next_5;
next_3:
    reg_d0.w = 0;
    reg_a4 = (u8 *)D_00251A90;
    reg_d0.b[0] = *(u8 *) (reg_a5 + 7);
    if (0 > (s64) reg_d0.sb[0]) {
        *(u16 *) (reg_a6 + 4) = 2;
        *(u8 *) (reg_a5 + 6) = *(u8 *) (reg_a6 + 4);
        goto next_5;
    }
    func_00138470();
    *(u16 *) (reg_a6 + 4) = reg_d0.h[0];
    *(u8 *) (reg_a5 + 6) = *(u8 *) (reg_a6 + 4);
next_5:
    *(s16 *) (reg_a6 + 0x16) = 0x60;
    *(s16 *) (reg_a6 + 0x18) = 0xC00;
    *(s16 *) (reg_a6 + 0x1C) = 0x60;
    *(s16 *) (reg_a6 + 0x1E) = 0xC00;
    *(s16 *) (reg_a6 + 0x22) = 0x60;
    *(s16 *) (reg_a6 + 0x24) = 0xC00;
    *(s16 *) (reg_a6 + 0x2A) = 0xB4;
    *(s16 *) (reg_a6 + 0x2E) = 0x599;
    *(s8 *) (reg_a6 + 0x30) = 2;
    *(s8 *) (reg_a6 + 0x31) = 0;
    *(s8 *) reg_a6 = 4;
}

s32 text_layer_print();
extern u16 D_00251AA0[];
extern u16 D_0028C100;

void func_00138650(void) {
    u16 temp_a0;
    if (g_loop == 0) {
        reg_d0.w = 0;
        reg_d0.b[0] = *(u8 *)(reg_a6 + 4);
        reg_a0 = (u8 *)(&D_0028C100);
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        if (reg_d7.h[0] != 0) {
            *(u8 *)(reg_a5 + 5) = (u8) reg_d0.b[0];
        } else {
            *(u8 *)(reg_a5 + 4) = (u8) reg_d0.b[0];
        }
    }
    temp_a0 = *(u16 *)(reg_a4 + 0xA);
    reg_d1.h[0] = temp_a0;
    reg_d0.h[0] = 8;
    reg_a0 = (u8 *)(D_00251AA0);
    reg_d2.h[0] = 0;
    reg_d1.h[0] >>= 6;
    reg_d1.h[0] >>= 3;
    reg_d1.h[0] += 8;
    text_layer_print();
    *(s8 *)reg_a6 = 6;
}

typedef void (*Fn)();

s32 func_0018DA30();
s32 func_0018DA50();
s32 func_00203850();
s32 func_002039B0();
s32 func_002046F0();
s32 func_00204A20();
s32 func_002053F0();
s32 func_00205D20();
s32 func_00206080();
extern u8 *jtbl_0028E3F4_as_u8_p;

void func_00138750(void) {
    u8 *temp_s0;
    s8 var_s0;
    u8 temp_v1;
    u8 temp_v1_2;

    if (reg_d7.h[0] != 0) {
        reg_a4 = (u8 *)D_00251A80;
        reg_a3 = reg_a5 + 7;
        var_s0 = *(s8 *)(reg_a5 + 6);
    } else {
        reg_a4 = (u8 *)D_00251A90;
        reg_a3 = reg_a5 + 6;
        var_s0 = *(s8 *)(reg_a5 + 7);
    }
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 8);
    reg_a0 = (u8 *)reg_tmp.w;
    jtbl_0028E3F4_as_u8_p = reg_a0;
    ((Fn)jtbl_0028E3F4_as_u8_p)();
    if (reg_d0.w & 4) {
        func_0018DA50();
        *(s16 *)(reg_a6 + 0x28) = 1;
        reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
        do {
            reg_d1.h[0] -= 1;
            if (0 > (s16) reg_d1.h[0]) {
                reg_d1.h[0] = 2;
            }
        } while ((s8)(var_s0) == reg_d1.b[0]);
        *(u16 *)(reg_a6 + 4) = (u16) reg_d1.h[0];
    }
    if (reg_d0.w & 8) {
        func_0018DA50();
        *(s16 *)(reg_a6 + 0x28) = 1;
        reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
        do {
            reg_d1.h[0] += 1;
            if ((s16) reg_d1.h[0] > 2) {
                reg_d1.w = 0;
            }
        } while ((s8)(var_s0) == reg_d1.b[0]);
        *(u16 *)(reg_a6 + 4) = (u16) reg_d1.h[0];
    }
    if (reg_d7.h[0] != 0) {
        *(s8 *)(reg_a5 + 7) = (s8) *(u8 *)(reg_a6 + 4);
    } else {
        *(s8 *)(reg_a5 + 6) = (s8) *(u8 *)(reg_a6 + 4);
    }
    if ((*(u8 *)(reg_a6 + 0x31) != 0) || (reg_d0.h[0] &= 0x70, (reg_d0.h[0] != 0))) {
        func_0018DA30();
        *(s8 *)reg_a6 = 5;
        *(s16 *)(reg_a6 + 0x2E) = 0;
    }
    temp_v1 = *(u8 *)(reg_a5 + 2);
    temp_s0 = (u8 *)(reg_a4);
    if (temp_v1 & 1) {
        *(u8 *)(reg_a5 + 2) = (u8) (temp_v1 | 1);
    } else {
        *(u8 *)(reg_a5 + 2) = (u8) (temp_v1 | 1);
        func_00203850();
        func_002039B0();
    }
    temp_v1_2 = *(u8 *)(reg_a5 + 2);
    if (temp_v1_2 & 2) {
        *(u8 *)(reg_a5 + 2) = (u8) (temp_v1_2 | 2);
    } else {
        *(u8 *)(reg_a5 + 2) = (u8) (temp_v1_2 | 2);
        func_002046F0();
    }
    func_00204A20();
    func_002053F0();
    func_00205D20();
    func_00206080();
    reg_a4 = temp_s0;
}
