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
extern u16 D_0028E5E8;
extern u16 D_0028E5EC;
extern u16 D_0028E5F8;
extern u16 D_0028E5FC;
extern u32 D_0028E8BC_as_u32;
extern u8 D_0028E8C8_as_u8;
extern u8 D_0028E8CC_as_u8;
extern u8 D_0028E8D0_as_u8;
extern u8 D_0028E8D4_as_u8;
extern u8 D_0028E8D8_as_u8;
extern u8 D_0028E8DC_as_u8;
extern u8 D_0028E8E0_as_u8;
extern u8 D_0028E8E4_as_u8;
extern u8 D_0028E8E8_as_u8;
extern u8 D_0028E8EC_as_u8;
extern u8 D_0028E8F0_as_u8;
extern u8 D_0028E8F4_as_u8;
extern u8 D_0028E8F8_as_u8;
extern u8 D_0028E8FC_as_u8;
extern u8 D_0028E900_as_u8;
extern u16 D_0028E904;
extern u16 D_0028E910;
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
    reg_d0.h[0] = D_0028E5FC;
    if (((reg_d0.h[0] |= D_0028E5F8) & 0xFFFF) == 0) {
        goto next_2;
    }
    reg_d0.h[0] = D_0028E5EC;
    if ((s32) D_0028E5E8 <= (s32) reg_d0.h[0]) {
        goto next_1;
    }
    reg_d0.h[0] = D_0028E5E8;
next_1:
    reg_d0.h[0] <<= 4;
    reg_d1.h[0] += reg_d0.h[0];
next_2:
    if (D_0028E910 == 0) {
        goto next_3;
    }
    if (D_0028ED80 != 0 && D_006E5C02[0] != 0) {
        goto next_3;
    }
    D_0028E904 = 0xFF;
    reg_d0.h[0] = D_0028E5FC;
    reg_d0.h[0] |= D_0028E5F8;
    if (reg_d0.h[0] != 0) {
        goto next_5;
    }
    D_0028E904 = 0xF8;
    goto next_5;
next_3:
    D_0028E904 = reg_d1.h[0];
    reg_d0.h[0] = D_0028E5FC;
    reg_d0.h[0] |= D_0028E5F8;
    if (reg_d0.h[0] != 0) {
        goto next_4;
    }
    if (D_0028E904 <= 0xF0) {
        goto next_5;
    }
    D_0028E904 = 0xF0;
    goto next_5;
next_4:
    if (D_0028E904 <= 0xFF) {
        goto next_5;
    }
    D_0028E904 = 0xFF;
next_5:
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *) &D_0028E904;
    reg_d7.h[0] = reg_d0.h[0];
    reg_d7.h[0] >>= 4;
    reg_d0.h[0] >>= 1;
    reg_d1.b[0] = reg_d0.b[0];
    reg_d6.b[0] = reg_d0.b[0];
    D_0028E8E4_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    D_0028E8E8_as_u8 = reg_d6.b[0];
    reg_d0.h[0] >>= 1;
    reg_d2.h[0] = reg_d0.h[0];
    reg_d6.b[0] = reg_d0.b[0];
    D_0028E8D4_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    D_0028E8D8_as_u8 = reg_d6.b[0];
    reg_d1.b[0] += reg_d0.b[0];
    reg_d6.b[0] = reg_d1.b[0];
    D_0028E8F4_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    D_0028E8F8_as_u8 = reg_d6.b[0];
    reg_d0.h[0] >>= 1;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d1.b[0] += reg_d0.b[0];
    reg_d6.b[0] = reg_d1.b[0];
    D_0028E8FC_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    D_0028E900_as_u8 = reg_d6.b[0];
    reg_d3.b[0] -= reg_d0.b[0];
    reg_d6.b[0] = reg_d3.b[0];
    D_0028E8EC_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    D_0028E8F0_as_u8 = reg_d6.b[0];
    reg_d3.h[0] = reg_d2.h[0];
    reg_d2.b[0] += reg_d0.b[0];
    reg_d6.b[0] = reg_d2.b[0];
    D_0028E8DC_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    D_0028E8E0_as_u8 = reg_d6.b[0];
    reg_d3.b[0] -= reg_d0.b[0];
    reg_d6.b[0] = reg_d3.b[0];
    D_0028E8CC_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    D_0028E8D0_as_u8 = reg_d6.b[0];
    D_0028E8C8_as_u8 = reg_d7.b[0];
}

extern u16 D_0028C108[4];
extern u16 D_0028C110[4];
extern u16 *reg_a0_as_u16_p;

void func_00138470(void)
{
    reg_a0_as_u16_p = D_0028C108;
    if (reg_d7.h[0] == 0) {
        reg_a0_as_u16_p = D_0028C110;
    }

    reg_d1.w = 2;
    do {
        if (*reg_a0_as_u16_p != reg_d0.h[0]) {
            break;
        }
        reg_a0_as_u16_p++;
    } while ((s16)(--reg_d1.h[0]) >= 0);

    reg_d0.h[0] = *reg_a0_as_u16_p;
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

s32 func_00137AD0();
extern u16 D_00251AA0[];
extern u16 D_0028C100;

void func_00138650(void) {
    u16 temp_a0;
    if (D_0028E910 == 0) {
        reg_d0.w = 0;
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0x4);
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
    func_00137AD0();
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
        reg_d1.h[0] = *(u16 *)(reg_a6 + 0x4);
        do {
            reg_d1.h[0] -= 1;
            if (0 > (s16) reg_d1.h[0]) {
                reg_d1.h[0] = 2;
            }
        } while ((s8)(var_s0) == reg_d1.b[0]);
        *(u16 *)(reg_a6 + 0x4) = (u16) reg_d1.h[0];
    }
    if (reg_d0.w & 8) {
        func_0018DA50();
        *(s16 *)(reg_a6 + 0x28) = 1;
        reg_d1.h[0] = *(u16 *)(reg_a6 + 0x4);
        do {
            reg_d1.h[0] += 1;
            if ((s16) reg_d1.h[0] > 2) {
                reg_d1.w = 0;
            }
        } while ((s8)(var_s0) == reg_d1.b[0]);
        *(u16 *)(reg_a6 + 0x4) = (u16) reg_d1.h[0];
    }
    if (reg_d7.h[0] != 0) {
        *(s8 *)(reg_a5 + 7) = (s8) *(u8 *)(reg_a6 + 0x4);
    } else {
        *(s8 *)(reg_a5 + 6) = (s8) *(u8 *)(reg_a6 + 0x4);
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
