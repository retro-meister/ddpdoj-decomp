#include "common.h"

void func_00207F40(void);

s32 func_0012FD00();                            /* extern */
s32 sprite_palette_load();                            /* extern */
s32 func_00208AD0();                            /* extern */
extern s32 D_002554B0_as_s32_a[];
extern s32 D_00267990[];
extern s8 D_0028DF9C;
extern s8 D_0028DFA0;
extern s32 *reg_a0_as_s32_p;

void func_00207720(void) {
    s32 func_00209200();
    func_0012FD00();
    func_00208AD0();
    reg_d0.h[0] = 0;
    reg_a0_as_s32_p = D_002554B0_as_s32_a;
    sprite_palette_load();
    D_0028DFA0 = 0;
    D_0028DF9C = 1;
    reg_d0.h[0] = 0;
    reg_a0_as_s32_p = D_00267990;
    func_00209200();
    reg_d0.w = 0;
}

s32 func_0016A8B0();                            /* extern */
s32 func_0019C430();                            /* extern */

void func_00207780(void) {
    s32 func_002093F0(u32);
    u32 temp_a0;

    reg_d2.w = 0xC2F;
    reg_d1.w = 0;
    reg_d3.h[0] = 0x38E0;
    reg_d4.h[0] = 0;
    func_0019C430();
    func_0016A8B0();
    temp_a0 = reg_d0.w;
    if ((temp_a0 & 0x8000) && (temp_a0 & 0x10)) {
        reg_d0.w = 0;
        func_002093F0(temp_a0);
    }
    reg_d0.w = 0;
}

s32 func_002093C0();
extern u16 D_002679B0[];
extern u8 D_0028DFA0_as_u8;
extern u16 *reg_a0_as_u16_p;

void func_002077E0(void) {
    reg_d0.w = 3;
    reg_d1.w = 4;
    reg_a0_as_u16_p = D_002679B0;
    reg_d1.b[0] -= D_0028DFA0_as_u8;
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0_as_u16_p + ((s16)reg_d1.h[0] & ~1)) : *reg_a0_as_u16_p;
    reg_d2.w = -2U;
    func_002093C0();
}

void func_00207860(void) {
    reg_d0.w = 3;
    reg_d1.w = 4;
    reg_a0_as_u16_p = D_002679B0;
    reg_d1.b[0] -= D_0028DFA0_as_u8;
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0_as_u16_p + ((s16)reg_d1.h[0] & ~1)) : *reg_a0_as_u16_p;
    reg_d2.w = 0;
    func_002093C0();
}

extern s32 D_002679C0[];
extern s32 D_00267A60[];
extern s32 D_00267A80[];

void func_002078E0(void) {
    s32 func_00209200();
    func_0012FD00();
    func_00208AD0();
    D_0028DFA0 = 0;
    D_0028DF9C = 1;
    reg_d0.h[0] = 0;
    reg_a0_as_s32_p = D_002679C0;
    func_00209200();
    reg_a0_as_s32_p = D_00267A60;
    func_00209200();
    reg_a0_as_s32_p = D_00267A80;
    func_00209200();
    func_00207860();
    reg_d0.w = 0;
}

extern u8 D_002679E0[];
extern u8 D_002679F8[];
extern u8 D_00267A10[];
extern u8 D_00267A30[];
extern u8 D_00267A50[];
extern u8 *D_00267AA0[];

void func_00207950(void) {
    void func_00209200(void);
    u8 **table;

    reg_a0 = (u8 *)D_002679E0;
    reg_d0.h[0] = 0;
    func_00209200();
    reg_a0 = (u8 *)D_002679F8;
    func_00209200();
    reg_a0 = (u8 *)D_00267A10;
    func_00209200();
    reg_a0 = (u8 *)D_00267A30;
    func_00209200();
    reg_a0 = (u8 *)D_00267A50;
    func_00209200();
    table = D_00267AA0;
    reg_d0.w = 0;
    reg_d0.b[0] = D_0028DFA0;
    table += reg_d0.h[0];
    reg_a0 = *table;
    reg_d0.h[0] = 2;
    func_00209200();
}

extern u8 D_00267AC0[];
extern u8 D_0028E38C;

void func_002079F0(void) {
    extern void func_002092F0(void);
    reg_a0 = D_00267AC0;
    reg_d0.w = 0;
    reg_d0.b[0] = D_0028E38C;
    reg_d0.h[0] <<= 5;
    reg_a0 += reg_d0.h[0];
    reg_d0.h[0] = 7;
    reg_d1.h[0] = 0x2A;
    reg_d2.h[0] = reg_d7.h[0];
    func_002092F0();
}

extern u8 D_00267C20[];
extern u8 D_0028E388;

void func_00207A40(void) {
    extern void func_002092F0(void);
    reg_a0 = D_00267C20;
    reg_d0.w = 0;
    reg_d0.b[0] = D_0028E388;
    reg_d0.h[0] <<= 6;
    reg_a0 += reg_d0.h[0];
    reg_d0.h[0] = 7;
    reg_d1.h[0] = 0x24;
    reg_d2.h[0] = reg_d7.h[0];
    func_002092F0();
    reg_d1.h[0] = 0x23;
    reg_a0 += 0x20;
    func_002092F0();
}

extern u8 D_00267B40[];
extern u8 D_0028E384;


void func_00207AC0(void)
{
    extern void func_002092F0(void);
    reg_d0.w = 0;
    reg_d0.b[0] = D_0028E384;
    reg_d0.h[0] <<= 5;
    reg_a0 = D_00267B40;
    reg_a0 += reg_d0.h[0];
    reg_d0.h[0] = 7;
    reg_d1.h[0] = 0x1E;
    reg_d2.h[0] = reg_d7.h[0];
    func_002092F0();
}

extern u8 D_00267BE0[];
extern u8 D_0028E380;


void func_00207B10(void)
{
    extern void func_002092F0(void);
    u8 selection;
    u8 *entry;

    selection = D_0028E380;
    reg_d0.w = 0;
    reg_a0 = D_00267BE0;
    reg_d0.b[0] = selection;
    reg_d0.h[0] <<= 5;
    entry = reg_a0 + reg_d0.h[0];
    reg_d0.h[0] = 7;
    reg_d1.h[0] = 0x18;
    reg_d2.h[0] = reg_d7.h[0];
    reg_a0 = entry;
    func_002092F0();
}

#pragma push
#pragma opt_propagation off
typedef void (*Fn)(void);

extern u8 *D_00267D20[];
extern Fn jtbl_0028E3F4_as_Fn;

void func_00207B60(void) {
    u8 **table;
    u8 *entry;

    reg_d7.h[0] = 0;
    func_002079F0();
    reg_d7.h[0] = 0;
    func_00207A40();
    reg_d7.h[0] = 0;
    func_00207AC0();
    reg_d7.h[0] = 0;
    func_00207B10();
    table = D_00267D20;
    reg_d0.w = 0;
    reg_d0.b[0] = D_0028DFA0;
    table += reg_d0.h[0];
    entry = *table;
    if (entry == (u8 *)-1) {
        return;
    }
    reg_a0 = entry;
    reg_d7.h[0] = 2;
    jtbl_0028E3F4_as_Fn = (Fn)reg_a0;
    jtbl_0028E3F4_as_Fn();
}
#pragma pop

s32 func_0016A8D0();
s32 func_0018DA30();
s32 func_0018DA50();

void func_00207BF0(void) {
    s32 func_002093F0();
    s64 temp_v1;
    s64 temp_v1_2;

    func_0016A8D0();
    if (reg_d0.w & 1) {
        D_0028DF9C = 1;
        func_0018DA50();
        func_002077E0();
        D_0028DFA0 -= 1;
        if (0 > D_0028DFA0) {
            D_0028DFA0 = 4;
        }
        func_00207860();
    }
    func_0016A8D0();
    if (reg_d0.w & 2) {
        D_0028DF9C = 1;
        func_0018DA50();
        func_002077E0();
        D_0028DFA0 += 1;
        if (D_0028DFA0 > 4) {
            D_0028DFA0 = 0;
        }
        func_00207860();
    }
    func_0016A8D0();
    if (reg_d0.w & 4) {
        D_0028DF9C = 1;
        if (D_0028DFA0 != 4) {
            func_0018DA50();
        }
        if (D_0028DFA0 == 0) {
            D_0028E38C -= 1;
            if (0 > (s8) D_0028E38C) {
                D_0028E38C = 3;
            }
        }
        temp_v1 = D_0028DFA0;
        if (temp_v1 == 1) {
            D_0028E388 -= 1;
            if (0 > (s8) D_0028E388) {
                D_0028E388 = 3;
            }
        }
        if (temp_v1 == 2) {
            D_0028E384 -= 1;
            if (0 > (s8) D_0028E384) {
                D_0028E384 = 4;
            }
        }
        if (temp_v1 == 3) {
            D_0028E380 -= 1;
            D_0028E380 &= 1;
        }
    }
    func_0016A8D0();
    if (reg_d0.w & 8) {
        D_0028DF9C = 1;
        if (D_0028DFA0 != 4) {
            func_0018DA50();
        }
        if (D_0028DFA0 == 0) {
            D_0028E38C += 1;
            if ((s8) D_0028E38C >= 4) {
                D_0028E38C = 0;
            }
        }
        temp_v1_2 = D_0028DFA0;
        if (temp_v1_2 == 1) {
            D_0028E388 += 1;
            if ((s8) D_0028E388 >= 4) {
                D_0028E388 = 0;
            }
        }
        if (temp_v1_2 == 2) {
            D_0028E384 += 1;
            if ((s8) D_0028E384 >= 5) {
                D_0028E384 = 0;
            }
        }
        if (temp_v1_2 == 3) {
            D_0028E380 += 1;
            D_0028E380 &= 1;
        }
    }
    func_0016A8D0();
    if ((reg_d0.w & 0x10) && (D_0028DFA0 == 4)) {
        func_0018DA30();
        reg_d0.w = 0;
        func_002093F0();
    } else if (D_0028DF9C != 0) {
        D_0028DF9C = 0;
        func_00207950();
        func_00207B60();
    }
    reg_d0.w = 0;
}

extern s32 D_00267D58[];
extern s32 D_00267E90[];

void func_00207EE0(void) {
    s32 func_00209200();
    func_0012FD00();
    func_00208AD0();
    D_0028DFA0 = 0;
    D_0028DF9C = 1;
    func_00207F40();
    reg_d0.h[0] = 0;
    reg_a0_as_s32_p = D_00267D58;
    func_00209200();
    reg_a0_as_s32_p = D_00267E90;
    func_00209200();
    reg_d0.w = 0;
}

extern s32 D_00267D70[];
extern s32 D_00267D90[];
extern s32 D_00267DB0[];
extern s32 D_00267DD0[];
extern s32 D_00267DF0[];
extern s32 D_00267E10[];
extern s32 D_00267E30[];
extern s32 D_00267E50[];
extern s32 D_00267E70[];

void func_00207F40(void) {
    s32 func_00209200();
    reg_a0_as_s32_p = D_00267D70;
    reg_d0.h[0] = 0;
    func_00209200();
    reg_a0_as_s32_p = D_00267D90;
    func_00209200();
    reg_a0_as_s32_p = D_00267DB0;
    func_00209200();
    reg_a0_as_s32_p = D_00267DD0;
    func_00209200();
    reg_a0_as_s32_p = D_00267DF0;
    func_00209200();
    reg_a0_as_s32_p = D_00267E10;
    func_00209200();
    reg_a0_as_s32_p = D_00267E30;
    func_00209200();
    reg_a0_as_s32_p = D_00267E50;
    func_00209200();
    reg_a0_as_s32_p = D_00267E70;
    func_00209200();
}

s32 func_0016A8B0();
s32 func_0016A8C0();
extern u8 D_00267D40[];
extern u8 D_0028DA60;
extern u8 D_0028DA68;
extern u8 D_0028DA70;
extern u8 D_0028DA78;
extern u8 D_0028DA80;
extern u8 D_0028DA88;
extern u8 D_0028DA90;
extern u8 g_arcade_coin_port;

void func_00207FF0(void) {
    s32 func_00209200();
    s32 func_002092F0();
    s32 func_002093F0();
    u8 *temp_a1;
    u8 *temp_a1_2;
    u32 temp_a0_3;
    u8 temp_a0;
    u8 temp_a0_2;

    func_00207F40();
    reg_a0 = &g_arcade_coin_port;
    reg_d0.h[0] = *(u16 *)reg_a0;
    if (!(reg_d0.w & 0x20)) {
        reg_d0.h[0] = 2;
        reg_a0 = &D_0028DA60;
        func_00209200();
    }
    reg_a0 = &g_arcade_coin_port;
    reg_d0.h[0] = *(u16 *)reg_a0;
    if (!(reg_d0.w & 0x10)) {
        reg_d0.h[0] = 2;
        reg_a0 = &D_0028DA68;
        func_00209200();
    }
    reg_a0 = &g_arcade_coin_port;
    reg_d0.h[0] = *(u16 *)reg_a0;
    if (!(reg_d0.w & 1)) {
        reg_d0.h[0] = 2;
        reg_a0 = &D_0028DA70;
        func_00209200();
    }
    reg_a0 = &g_arcade_coin_port;
    reg_d0.h[0] = *(u16 *)reg_a0;
    if (!(reg_d0.w & 2)) {
        reg_d0.h[0] = 2;
        reg_a0 = &D_0028DA78;
        func_00209200();
    }
    func_0016A8B0();
    if (reg_d0.w & 0x8000) {
        reg_d0.h[0] = 2;
        reg_a0 = &D_0028DA80;
        func_00209200();
    }
    func_0016A8C0();
    if (reg_d0.w & 0x8000) {
        reg_d0.h[0] = 2;
        reg_a0 = &D_0028DA88;
        func_00209200();
    }
    func_0016A8B0();
    reg_d0.h[0] &= 0xF;
    if (reg_d0.b[0] != 0) {
        reg_d1.w = 0;
        reg_a0 = (u8 *)D_00267D40;
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 += reg_d0.h[0];
        reg_d0.w = 0;
        temp_a1 = (u8 *)(reg_a0);
        reg_d0.b[0] = (*(u8 *)((u8 *)(temp_a1) + (1)));
        reg_d0.b[0] += 0xD;
        temp_a0 = (*(u8 *)((u8 *)(temp_a1) + (0)));
        reg_d2.h[0] = 2;
        reg_d1.b[0] = temp_a0;
        reg_a0 = &D_0028DA90;
        reg_d1.b[0] += 0x1E;
        func_002092F0();
    }
    func_0016A8C0();
    reg_d0.h[0] &= 0xF;
    if (reg_d0.b[0] != 0) {
        reg_d1.w = 0;
        reg_a0 = (u8 *)D_00267D40;
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 += reg_d0.h[0];
        reg_d0.w = 0;
        temp_a1_2 = (u8 *)(reg_a0);
        reg_d0.b[0] = (*(u8 *)((u8 *)(temp_a1_2) + (1)));
        reg_d0.b[0] += 0x15;
        temp_a0_2 = (*(u8 *)((u8 *)(temp_a1_2) + (0)));
        reg_d1.b[0] = temp_a0_2;
        reg_d2.h[0] = 2;
        reg_a0 = &D_0028DA90;
        reg_d1.b[0] += 0x1E;
        func_002092F0();
    }
    func_0016A8B0();
    reg_d0.h[0] &= 0x70;
    reg_d0.h[0] >>= 4;
    if (reg_d0.b[0] != 0) {
        reg_d7.b[0] = reg_d0.b[0];
        reg_d2.h[0] = 2;
        reg_a0 = &D_0028DA90;
        reg_d0.w = 0xD;
        reg_d1.w = 0x18;
        if (reg_d7.w & 1) {
            func_002092F0();
        }
        reg_d0.h[0] += 1;
        if (reg_d7.w & 2) {
            func_002092F0();
        }
        reg_d0.h[0] += 1;
        if (reg_d7.w & 4) {
            func_002092F0();
        }
    }
    func_0016A8C0();
    reg_d0.h[0] &= 0x70;
    reg_d0.h[0] >>= 4;
    if (reg_d0.b[0] != 0) {
        reg_d7.b[0] = reg_d0.b[0];
        reg_d2.h[0] = 2;
        reg_a0 = &D_0028DA90;
        reg_d0.w = 0x15;
        reg_d1.w = 0x18;
        if (reg_d7.w & 1) {
            func_002092F0();
        }
        reg_d0.h[0] += 1;
        if (reg_d7.w & 2) {
            func_002092F0();
        }
        reg_d0.h[0] += 1;
        if (reg_d7.w & 4) {
            func_002092F0();
        }
    }
    func_0016A8B0();
    temp_a0_3 = reg_d0.w;
    if ((temp_a0_3 & 0x8000) && (temp_a0_3 & 0x10)) {
        reg_d0.w = 0;
        func_002093F0();
    }
    reg_d0.w = 0;
}
