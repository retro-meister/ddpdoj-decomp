#include "common.h"

void func_001D5150(void);
void func_001D51C0(void);
void func_001D5230(void);
void func_001D55B0(void);
void func_001D6690(void);
void func_001D66A0(void);
void func_001D66B0(void);
void func_001D66E0(void);
void func_001D6710(void);
void func_001D6790(void);
void func_001D6990(void);
void func_001D6A40(void);
void func_001D6B60(void);

extern void *reg_a6_as_void_p;

void func_001D4620(void) {
    *(s16 *)((u8 *)reg_a6_as_void_p + 0x86) = 1;
}

s32 func_001D4400();
void func_00203400(void);
extern u16 D_0028E8A0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001D4630(void) {
#ifdef DEATH_LABEL
    if ((D_0028E8A0 == 0) && ((*(u16 *)((u8 *)(reg_a5) + (0x1A))) == 0)) {
#else
    if ((D_0028E8A0 == 0) && ((*(u16 *)((u8 *)(reg_a5) + (0x1A))) -= 1, (*(u16 *)((u8 *)(reg_a5) + (0x1A))) == 0)) {
#endif
        func_00203400();
        if (reg_d0.h[0] == 0) {
            (*(u16 *)((u8 *)(reg_a5) + (0x1A))) = 0x78U;
            return;
        }
        (*(s16 *)((u8 *)(reg_a6) + (0x8A))) = 0;
        func_001D4400();
    }
}

s32 func_00128AC0();
extern u16 D_00259870[];
extern u8 *reg_a0;

void func_001D46A0(void) {
    reg_d0.w = 0xFFFC0004;
    reg_d1.h[0] -= 0xC;
    reg_d7.w = 6;
    reg_a0 = (u8 *)(D_00259870);
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] &= 0x3F;
        reg_d3.h[0] *= 4;
        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w += reg_d5.w;
        func_00128AC0();
        reg_d1.b[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

void func_001D61B0();

void func_001713F0(s32);

void func_001D47B0(void) {
    func_001713F0(6);
}

s32 func_0014E300();
s32 func_0014E370();
s32 func_001A3020();
extern u16 D_00260330[];
extern u16 D_00260370[];
extern u16 D_002603B0[];
extern u16 D_00263370[];
extern u16 D_00263390[];
extern s16 D_0028E85C_as_s16;
extern s16 D_0028E884_as_s16;
extern u16 D_002BDA80_as_u16_a[];
extern u16 *reg_a0_as_u16_p;

void func_001D47C0(void) {
    reg_a0_as_u16_p = D_00263390;
    func_0014E370();
    reg_tmp.w = (u32) reg_a0_as_u16_p;
    (*(u16 *)((u8 *)(reg_a5) + (0x44))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x46))) = (u16) reg_tmp.h[0];
    reg_a0_as_u16_p = D_00263370;
    reg_d0.h[0] = 0xE;
    func_0014E300();
    reg_tmp.w = 0xF0001C00;
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_tmp.h[0];
    reg_a0_as_u16_p = D_002BDA80_as_u16_a;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.w = 9;
    do {
        *reg_a0_as_u16_p = reg_d1.h[1];
        reg_a0_as_u16_p += 1;
        *reg_a0_as_u16_p = reg_d1.h[0];
        reg_a0_as_u16_p += 1;
        *reg_a0_as_u16_p = 0;
        reg_a0_as_u16_p += 1;
        *reg_a0_as_u16_p = 0;
        reg_a0_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = 0x12;
    D_0028E85C_as_s16 = 1;
    D_0028E884_as_s16 = 1;
    reg_a0_as_u16_p = D_00260330;
    func_001A3020();
    reg_d0.h[0] = 0x13;
    reg_a0_as_u16_p = D_00260370;
    func_001A3020();
    reg_d0.h[0] = 0xA;
    reg_a0_as_u16_p = D_002603B0;
    func_001A3020();
}

typedef void (*Fn)();

extern u8 D_002635C0[];
extern u8 D_002BDAA8[];
s32 func_0014D220();
s32 func_0014E290();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_00201800();
s32 vibration_start_pad1();
s32 vibration_start_pad2();
extern u16 D_0028E884;
extern u16 D_0029C06C[];
extern u16 D_002BDAA4[];
extern u16 D_002BDAA6[];
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a1;

void func_001D4930(void) {
    u32 saved;
    u32 saved_d1;
    u8 *p;

    if (D_0028E8A0 != 0) goto next_1;
    reg_d7.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d7.h[0] = *(u16 *)(reg_a6 + 4);
    saved = reg_d7.w;
    reg_a0 = (u8 *)D_002635C0;
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
    reg_d0.h[0] *= 4;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)(reg_a0 + 0);
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    jtbl_0028E3F4 = (Fn)(reg_a0);
    jtbl_0028E3F4();
    reg_d7.w = saved;
    if (*(u8 *)(reg_a5 + 0x25) != 0) goto next_3;
    if (*(u16 *)(reg_a5 + 0x2E) == 0) goto next_3;
    if (*(u8 *)(reg_a5 + 0x1E) != 0) goto next_2;
    if ((s16) *(u16 *)(reg_a5 + 0x2E) <= 0x258) goto block_1;
next_2:
    *(u16 *)(reg_a5 + 0x2E) -= 1;
    if (*(u16 *)(reg_a5 + 0x2E) != 0) goto next_3;
    func_001D55B0();
next_3:
    func_001D61B0();
    func_001D66E0();
    func_001D5230();
    if (*(u16 *)(reg_a5 + 0x30) == 0) goto next_1;
    func_0014E290();
    return;
next_1:
    reg_d0.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 4);
    reg_a0 = (u8 *)D_002BDAA8;
    p = (u8 *) D_002BDAA4;
    reg_a1 = p;
    reg_d1.w = 8;
loop_1:
    reg_a1 -= 4;
    reg_d2.h[1] = *(u16 *)(reg_a1 + 0);
    reg_d2.h[0] = *(u16 *)(reg_a1 + 2);
    reg_d2.h[0] -= D_0029C06C[0];
    reg_a0 -= 4;
    *(u16 *)(reg_a0 + 0) = reg_d2.h[1];
    *(u16 *)(reg_a0 + 2) = reg_d2.h[0];
    if ((s16) --reg_d1.h[0] >= 0) goto loop_1;
    reg_d0.h[0] -= D_0029C06C[0];
    *(u16 *)(reg_a1 + 0) = reg_d0.h[1];
    *(u16 *)(reg_a1 + 2) = reg_d0.h[0];
    reg_d0.h[1] = *(u16 *)p;
    reg_d0.h[0] = D_002BDAA6[0];
    *(u16 *)(reg_a6 + 0x22) = reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x24) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x24) -= 0x1000;
    *(u16 *)(reg_a6 + 0x42) = reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x44) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x44) += 0x1000;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *)(reg_a6 + 1);
    if (reg_d1.b[0] == 0) goto next_6;
    reg_d0.b[0] = 0xA3;
    *(u8 *)(reg_a6 + 1) &= reg_d0.b[0];
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0x1E);
    reg_d0.b[0] ^= reg_d2.b[0];
    *(u8 *)(reg_a6 + 0x1C) = reg_d0.b[0];
    reg_d0.w = 0x7FFF;
    reg_d0.h[0] -= *(u16 *)(reg_a6 + 0x18);
    if (*(u16 *)(reg_a5 + 0x2E) == 0) goto next_4;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x20);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x22);
    reg_tmp.w -= reg_d0.w;
    *(u16 *)(reg_a5 + 0x20) = reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x22) = reg_tmp.h[0];
next_4:
    *(u16 *)(reg_a6 + 0x18) = 0x7FFF;
    if (*(u8 *)(reg_a5 + 0x1E) != 0) goto next_5;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x20);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x22);
    if ((s32) reg_tmp.w > 0x2800) goto next_5;
block_1:
    func_001D5150();
    func_001D51C0();
    *(u8 *)(reg_a5 + 0x1E) = 1;
    goto next_7;
next_5:
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x20);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x22);
    if ((s32) reg_tmp.w >= 0) goto next_7;
    saved_d1 = reg_d1.w;
    reg_d0.w = 0x712;
    func_001A91A0();
    vibration_start_pad1(0xB4, 0x78);
    vibration_start_pad2(0xB4, 0x78);
    reg_d1.w = saved_d1;
    func_00201800();
    *(u16 *)(reg_a6 + 0) = 0x8000;
    *(u8 *)(reg_a5 + 0x25) = 1;
    D_0028E884 = 0;
next_6:
    *(u8 *)(reg_a6 + 0x1C) = *(u8 *)(reg_a6 + 0x1F);
next_7:
    if (*(u8 *)(reg_a5 + 0x1F) != 0) goto next_8;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x20);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x22);
    if ((s32) reg_tmp.w > 0x1000) goto next_8;
    *(u8 *)(reg_a5 + 0x1F) = 1;
next_8:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *)(reg_a6 + 0x21);
    if (reg_d1.b[0] == 0) goto next_10;
    reg_d0.b[0] = 0xA3;
    *(u8 *)(reg_a6 + 0x21) &= reg_d0.b[0];
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3B);
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0x3C);
    reg_d0.b[0] ^= reg_d2.b[0];
    *(u8 *)(reg_a6 + 0x3B) = reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3A);
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0x3E);
    reg_d0.b[0] ^= reg_d2.b[0];
    *(u8 *)(reg_a6 + 0x3A) = reg_d0.b[0];
    if (*(u16 *)(reg_a5 + 0x2E) != 0) goto next_9;
    *(u16 *)(reg_a6 + 0x38) = 0x4000;
next_9:
    if (*(s16 *)(reg_a6 + 0x38) >= 0) goto next_11;
    reg_d0.w = 0x173;
    func_001A91A0();
    func_001D5150();
next_10:
    *(u8 *)(reg_a6 + 0x3B) = *(u8 *)(reg_a6 + 0x3D);
    *(u8 *)(reg_a6 + 0x3A) = *(u8 *)(reg_a6 + 0x3F);
next_11:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *)(reg_a6 + 0x41);
    if (reg_d1.b[0] == 0) goto next_13;
    reg_d0.b[0] = 0xA3;
    *(u8 *)(reg_a6 + 0x41) &= reg_d0.b[0];
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x5B);
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0x5C);
    reg_d0.b[0] ^= reg_d2.b[0];
    *(u8 *)(reg_a6 + 0x5B) = reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x5A);
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0x5E);
    reg_d0.b[0] ^= reg_d2.b[0];
    *(u8 *)(reg_a6 + 0x5A) = reg_d0.b[0];
    if (*(u16 *)(reg_a5 + 0x2E) != 0) goto next_12;
    *(u16 *)(reg_a6 + 0x58) = 0x4000;
next_12:
    if (*(s16 *)(reg_a6 + 0x58) >= 0) goto next_14;
    reg_d0.w = 0x173;
    func_001A91A0();
    func_001D51C0();
next_13:
    *(u8 *)(reg_a6 + 0x5B) = *(u8 *)(reg_a6 + 0x5D);
    *(u8 *)(reg_a6 + 0x5A) = *(u8 *)(reg_a6 + 0x5F);
next_14:
    *(u16 *)(reg_a5 + 0x32) += 4;
    *(u16 *)(reg_a5 + 0x32) &= 0x1F;
    if (*(u16 *)(reg_a5 + 0x2C) == 0) return;
    reg_a0 = reg_a6;
    func_0014D220();
    reg_a0 = reg_a6 + 0x20;
    func_0014D220();
    reg_a0 = reg_a6 + 0x40;
    func_0014D220();
    reg_a0 = reg_a6 + 0x60;
    func_0014D220();
    func_001D6990();
    func_001D6A40();
    func_001D6B60();
}

s32 func_0013A780();

void func_001D5040(arg2)
    u16 *arg2;
{
    u16 *var_a2;
    u16 temp_a1;

    var_a2 = (u16 *)(arg2);
loop_1:
    temp_a1 = *(u16 *)reg_a1;
    reg_d1.h[0] = temp_a1;
    reg_a1 += 2;
    if ((s16) reg_d1.h[0] != -1) {
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        func_0013A780();
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        (*(u8 *)((u8 *)(reg_a0) + (0x1D))) = (u8) reg_d0.b[0];
        (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) *(u16 *)reg_a1;
        var_a2 = (u16 *)(reg_a1 + 2);
        reg_a1 = (u8 *)(var_a2);
        (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) reg_d2.h[1];
        (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) reg_d2.h[0];
        (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
        (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
        (*(u16 *)((u8 *)(reg_a0) + (0x1A))) = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        goto loop_1;
    }
}

s32 func_0018D580();
extern u8 D_00263470[];
extern u16 D_0028E4A2;

void func_001D5150() {
    if ((*(u8 *)((u8 *)(reg_a6) + (0x2F))) == 0) {
        (*(u8 *)((u8 *)(reg_a6) + (0x2F))) = 1U;
        (*(u16 *)((u8 *)(reg_a6) + (0x20))) = 0x8000;
        reg_a1 = D_00263470;
        D_0028E4A2 = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
        func_001D5040();
        func_0018D580();
    }
}

void func_001D51C0() {
    if ((*(u8 *)((u8 *)(reg_a6) + (0x4F))) == 0) {
        (*(u8 *)((u8 *)(reg_a6) + (0x4F))) = 1U;
        (*(u16 *)((u8 *)(reg_a6) + (0x40))) = 0x8000;
        reg_a1 = D_00263470;
        D_0028E4A2 = (*(u16 *)((u8 *)(reg_a6) + (0x42)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
        func_001D5040();
        func_0018D580();
    }
}

extern s8 D_0028E408;

s32 func_00138A40();
s32 func_0013AB50();
s32 func_0013B2E0();
s32 func_0018D500();
s32 func_0018D5C0();
s32 func_002010A0();
extern u16 D_002634F0[];
extern u16 D_00263540[];
extern u8 D_00263590[];

void func_001D5230(void) {
    u16 temp_a0_2;
    u16 temp_a0_3;
    u8 temp_a0;
    u8 *var_a1;

    if ((*(u8 *)((u8 *)(reg_a5) + (0x25))) != 0) {
        temp_a0 = (*(u8 *)((u8 *)(reg_a5) + (0x24)));
        if (temp_a0 == 2) {
            (*(u8 *)((u8 *)(reg_a5) + (0x27))) -= 1;
            if ((*(u8 *)((u8 *)(reg_a5) + (0x27))) == 0) {
                func_00138A40();
                D_0028E85C_as_s16 = 0;
                (*(s16 *)((u8 *)(reg_a5) + (0x30))) = 1;
                goto block_set;
            }
        }
        var_a1 = (u8 *)(reg_a5);
        if ((*(u8 *)((u8 *)(var_a1) + (0x24))) == 1) {
            (*(u8 *)((u8 *)(var_a1) + (0x27))) -= 1;
            if ((*(u8 *)((u8 *)(reg_a5) + (0x27))) == 0) {
                (*(s16 *)((u8 *)(reg_a5) + (0x2C))) = 0;
                reg_a0 = (u8 *)D_00263590;
                func_0013B2E0();
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_a1 = (u8 *)(D_00263540);
                func_001D5040();
                func_002010A0();
                reg_d0.b[0] = (s8) reg_d0.b[0] * 2;
                reg_d1.b[0] = reg_d0.b[0];
                reg_d1.b[0] += 0x40;
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                temp_a0_2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d2.h[0] = temp_a0_2;
                reg_d2.w += 0xF8000800;
                reg_d3.h[0] = 0xC;
                reg_d0.h[0] = 0;
                func_0013AB50();
                func_002010A0();
                reg_d0.b[0] = (s8) reg_d0.b[0] * 2;
                reg_d1.b[0] = reg_d0.b[0];
                reg_d1.b[0] += 0xC0;
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                temp_a0_3 = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d2.h[0] = temp_a0_3;
                reg_d2.w += 0x01FFF800;
                reg_d3.h[0] = 0xC;
                reg_d0.h[0] = 0;
                func_0013AB50();
                func_0018D5C0();
                var_a1 = (u8 *)((void *)0x10);
                (*(u8 *)((u8 *)(reg_a5) + (0x27))) = 0x10U;
                (*(u8 *)((u8 *)(reg_a5) + (0x24))) = 2U;
            }
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (0x24))) == 0) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x27)));
            (*(u8 *)((u8 *)(reg_a5) + (0x27))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x27))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x26)));
                func_0018D500();
                reg_a1 = (u8 *)(D_002634F0);
                reg_a1 += (*(u16 *)((u8 *)(reg_a5) + (0x2A)));
                reg_d1.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                func_0013A780();
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                (*(u8 *)((u8 *)(reg_a0) + (0x1D))) = (u8) reg_d0.b[0];
                (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d1.h[0];
                (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
                (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
                (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
                (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
                (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
                (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
                reg_d0.b[0] *= 4;
                (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
                (*(u16 *)((u8 *)(reg_a5) + (0x2A))) += 0xC;
                if ((*(u16 *)((u8 *)(reg_a5) + (0x2A))) == 0x48) {
                    (*(u16 *)((u8 *)(reg_a5) + (0x2A))) = 0U;
                    (*(u16 *)((u8 *)(reg_a5) + (0x28))) -= 1;
                    if ((*(u16 *)((u8 *)(reg_a5) + (0x28))) == 0) {
                        (*(u16 *)((u8 *)(reg_a5) + (0x26))) = 0x1006;
                        (*(u8 *)((u8 *)(reg_a5) + (0x24))) = 1U;
                    }
                }
            }
        }
        goto block_12;
    }
block_12:
    D_0028E408 = 0;
    return;
block_set:
    D_0028E408 = 1;
}

void func_001D55B0(void) {
    (*(s8 *)((u8 *)(reg_a5) + (0x1B))) = 0;
    if ((*(u16 *)((u8 *)(reg_a5) + (0x2E))) != 0) {
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2F)));
        reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x4F)));
        if (reg_d0.b[0] != 2) {
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
            reg_d0.h[0] += 1;
            (*(u16 *)((u8 *)(reg_a5) + (0x18))) = (u16) reg_d0.h[0];
            (*(u16 *)((u8 *)(reg_a5) + (0x1C))) += 1;
            (*(u16 *)((u8 *)(reg_a5) + (0x1C))) &= 3;
            return;
        }
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
        if (reg_d0.h[0] == 5) {
            (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 2U;
            return;
        }
        (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 5U;
        return;
    }
    D_0028E884_as_s16 = 0;
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 6U;
}

s32 func_00201C60();
s32 func_002021F0();
s32 func_00202500();
s32 func_00202B50();
extern u8 D_002635E0[];

void func_001D5670(void) {
    if ((*(u8 *)((u8 *)(reg_a5) + (0x25))) != 0) {
        (*(s16 *)((u8 *)(reg_a6) + (0x1A))) = 0x420;
        func_00201C60();
        return;
    }
    reg_a0 = D_002635E0;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x86)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_002021F0();
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    func_00202500();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = reg_d1.b[0];
    func_00201C60();
    reg_a0 = D_002635E0;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x86)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    func_00202B50();
    if ((s16) reg_d0.h[0] < 0x101) {
        (*(u16 *)((u8 *)(reg_a6) + (0x86))) += 4;
        (*(u16 *)((u8 *)(reg_a6) + (0x86))) &= 0xF;
    }
}

s32 func_0014E030();

void func_001D5780(void) {
    if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 0) {
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x66)));
        (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d0.h[0];
        if ((s16) (*(u16 *)((u8 *)(reg_a6) + (2))) > 0x3C00) {
            (*(u16 *)((u8 *)(reg_a6) + (0x66))) -= 9;
            if (0 >= (s16) (*(u16 *)((u8 *)(reg_a6) + (0x66)))) {
                (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 1U;
                reg_d0.w = 0x14;
                func_0014E030();
                func_001D55B0();
                (*(u16 *)((u8 *)(reg_a6) + (0))) = 0xA001;
                (*(u16 *)((u8 *)(reg_a6) + (0x20))) = 0xA001;
                (*(u16 *)((u8 *)(reg_a6) + (0x40))) = 0xA001;
            }
        }
    }
}

s32 func_00202140();

void func_001D5830(void) {
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
    reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x26)));
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x28)));
    func_00202140();
    if (D_0028E408 != 0) {
        reg_d1.h[0] = 0x20;
    }
    (*(u8 *)((u8 *)(reg_a6) + (0x91))) = (u8) reg_d1.b[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x42)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
    reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x46)));
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x48)));
    func_00202140();
    if (D_0028E408 != 0) {
        reg_d1.h[0] = 0x20;
    }
    (*(u8 *)((u8 *)(reg_a6) + (0x90))) = (u8) reg_d1.b[0];
}

extern u16 D_0028E8C8;

void func_001D58F0(void) {
    s32 var_a1;
    u16 temp_v1;
    u8 temp_a0;
    u8 *var_a0;
    if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 0) {
        var_a1 = 0x404;
        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 1U;
        (*(s16 *)((u8 *)(reg_a6) + (0x88))) = 0x404;
        (*(s16 *)((u8 *)(reg_a6) + (0x8A))) = 0x1020;
        (*(u16 *)((u8 *)(reg_a6) + (0x8C))) = 6U;
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2F)));
        reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x4F)));
        if (reg_d0.b[0] != 0) {
            (*(s16 *)((u8 *)(reg_a6) + (0x8A))) = 0x1008;
            (*(u16 *)((u8 *)(reg_a6) + (0x8C))) = 0x20U;
        }
        (*(s16 *)((u8 *)(reg_a6) + (0x2C))) = 0;
        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 1U;
    }
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2F)));
    reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x4F)));
    if (reg_d0.b[0] != 2) {
        func_001D5670();
        if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 1) {
            temp_v1 = (*(u16 *)((u8 *)(reg_a6) + (0x8E)));
            if (temp_v1 != 0) {
                (*(u16 *)((u8 *)(reg_a6) + (0x8E))) = (u16) (temp_v1 - 1);
            } else {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2D)));
                (*(u8 *)((u8 *)(reg_a6) + (0x2D))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x2D))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x2C)));
                    (*(u16 *)((u8 *)(reg_a6) + (0x4A))) += 4;
                    (*(u16 *)((u8 *)(reg_a6) + (0x2A))) += 4;
                    if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x2A))) >= 0x1C) {
                        (*(u16 *)((u8 *)(reg_a6) + (0x2A))) = 0x1CU;
                        (*(u16 *)((u8 *)(reg_a6) + (0x4A))) = 0x1CU;
                        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 2U;
                        func_001D5830();
                    }
                }
            }
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 2) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x89)));
            (*(u8 *)((u8 *)(reg_a6) + (0x89))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a6) + (0x89))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x88)));
                temp_a0 = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
                if (temp_a0 != 8) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x1B))) = (u8) (temp_a0 + 1);
                }
            }
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x8B)));
            (*(u8 *)((u8 *)(reg_a6) + (0x8B))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                reg_d0.h[0] = 0x20;
                reg_d0.h[0] -= D_0028E8C8;
                (*(u8 *)((u8 *)(reg_a6) + (0x8B))) = (u8) reg_d0.b[0];
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2F)));
                reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x4F)));
                if (reg_d0.b[0] != 0) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x8A))) = 8;
                }
                if ((*(u8 *)((u8 *)(reg_a6) + (0x2F))) == 0) {
                    reg_d1.w = 0;
                    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x91)));
                    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
                    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
                    reg_d5.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x26)));
                    reg_d5.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x28)));
                    reg_d4.w = 0;
                    func_001D46A0();
                }
                if ((*(u8 *)((u8 *)(reg_a6) + (0x4F))) == 0) {
                    reg_d1.w = 0;
                    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x90)));
                    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x42)));
                    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
                    reg_d5.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x46)));
                    reg_d5.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x48)));
                    reg_d4.w = 0;
                    func_001D46A0();
                }
                (*(u16 *)((u8 *)(reg_a6) + (0x8C))) -= 1;
                if ((*(u16 *)((u8 *)(reg_a6) + (0x8C))) == 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 3U;
                    (*(s16 *)((u8 *)(reg_a6) + (0x2C))) = 0x2000;
                }
            }
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 3) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2D)));
            (*(u8 *)((u8 *)(reg_a6) + (0x2D))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a6) + (0x2D))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x2C)));
                (*(u16 *)((u8 *)(reg_a6) + (0x4A))) -= 4;
                (*(u16 *)((u8 *)(reg_a6) + (0x2A))) -= 4;
                var_a0 = (unsigned char *)((reg_a6 + 0x2A));
                if (0 >= (s16) (*(u16 *)((u8 *)(reg_a6) + (0x2A)))) {
                    *(u16 *)var_a0 = 0;
                    (*(u16 *)((u8 *)(reg_a6) + (0x4A))) = 0U;
                    goto block_28;
                }
            }
        }
    } else {
block_28:
        func_001D55B0();
    }
}

extern u8 D_00263610[];

extern u8 *reg_a4;

void func_001D5CA0(void) {
    u32 temp_a0_2;
    u32 temp_a0_4;
    u8 *var_a0;
    u8 *var_a1;
    if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 0) {
        (*(u16 *)((u8 *)(reg_a6) + (0xAA))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0xB0)));
        (*(u8 *)((u8 *)(reg_a6) + (0xB0))) -= 4;
        if ((s8) (*(u16 *)((u8 *)(reg_a6) + (0xB0))) < 0x11) {
            (*(u8 *)((u8 *)(reg_a6) + (0xB0))) = 0x10;
        }
        (*(u16 *)((u8 *)(reg_a6) + (0xAC))) = 8U;
        var_a1 = (u8 *)(reg_a6);
        reg_d0.b[0] = (*(u8 *)((u8 *)(var_a1) + (0x2F)));
        reg_d0.b[0] += (*(u8 *)((u8 *)(var_a1) + (0x4F)));
        if (reg_d0.b[0] != 0) {
            (*(s16 *)((u8 *)(var_a1) + (0x8A))) = 0x1008;
            (*(u16 *)((u8 *)(reg_a6) + (0xAC))) = 0x10U;
            (*(u8 *)((u8 *)(reg_a6) + (0xB0))) = 8;
            (*(u16 *)((u8 *)(reg_a6) + (0xAA))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0xB0)));
        }
        (*(u16 *)((u8 *)(reg_a6) + (0xAE))) = 0U;
        (*(s16 *)((u8 *)(reg_a6) + (0x2C))) = 0;
        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 1U;
    }
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2F)));
    reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x4F)));
    if (reg_d0.b[0] != 2) {
        func_001D5670();
        if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 1) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2D)));
            (*(u8 *)((u8 *)(reg_a6) + (0x2D))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a6) + (0x2D))) = (*(u8 *)((u8 *)(reg_a6) + (0x2C)));
                (*(u16 *)((u8 *)(reg_a6) + (0x4A))) += 4;
                (*(u16 *)((u8 *)(reg_a6) + (0x2A))) += 4;
                if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x2A))) >= 0x1C) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x2A))) = 0x1CU;
                    (*(u16 *)((u8 *)(reg_a6) + (0x4A))) = 0x1CU;
                    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 2U;
                }
            }
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 2) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xAB)));
            (*(u8 *)((u8 *)(reg_a6) + (0xAB))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a6) + (0xAB))) = (*(u8 *)((u8 *)(reg_a6) + (0xAA)));
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2F)));
                reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x4F)));
                if (reg_d0.b[0] != 0) {
                    (*(u8 *)((u8 *)(reg_a6) + (0xAA))) = 8;
                }
                reg_a4 = (u8 *)D_00263610;
                reg_a4 += (*(u16 *)((u8 *)(reg_a6) + (0xAE)));
                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0)));
                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (2)));
                reg_a4 = (u8 *) reg_tmp.w;
                (*(u16 *)((u8 *)(reg_a6) + (0xAE))) += 4;
                (*(u16 *)((u8 *)(reg_a6) + (0xAE))) &= 0x1F;
                if ((*(u8 *)((u8 *)(reg_a6) + (0x2F))) == 0) {
                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
                    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
                    reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x26)));
                    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x28)));
                    func_00202140();
                    if (D_0028E408 != 0) {
                        reg_d1.h[0] = 0x20;
                    }
                    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
                    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
                    reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x26)));
                    temp_a0_2 = (*(u16 *)((u8 *)(reg_a6) + (0x28)));
                    reg_d3.h[0] = temp_a0_2;
                    reg_a0 = reg_a6 + 0x20;
                    jtbl_0028E3F4 = (Fn)(reg_a4);
                    jtbl_0028E3F4();
                }
                if ((*(u8 *)((u8 *)(reg_a6) + (0x4F))) == 0) {
                    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x42)));
                    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
                    reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x46)));
                    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x48)));
                    func_00202140();
                    if (D_0028E408 != 0) {
                        reg_d1.h[0] = 0x20;
                    }
                    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x42)));
                    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
                    reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x46)));
                    temp_a0_4 = (*(u16 *)((u8 *)(reg_a6) + (0x48)));
                    reg_d3.h[0] = temp_a0_4;
                    reg_a0 = reg_a6 + 0x40;
                    jtbl_0028E3F4 = (Fn)(reg_a4);
                    jtbl_0028E3F4();
                }
                (*(u16 *)((u8 *)(reg_a6) + (0xAC))) -= 1;
                if ((*(u16 *)((u8 *)(reg_a6) + (0xAC))) == 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 3U;
                    (*(s16 *)((u8 *)(reg_a6) + (0x2C))) = 0x2000;
                }
            }
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 3) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2D)));
            (*(u8 *)((u8 *)(reg_a6) + (0x2D))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a6) + (0x2D))) = (*(u8 *)((u8 *)(reg_a6) + (0x2C)));
                (*(u16 *)((u8 *)(reg_a6) + (0x4A))) -= 4;
                (*(u16 *)((u8 *)(reg_a6) + (0x2A))) -= 4;
                var_a0 = (unsigned char *)((reg_a6 + 0x2A));
                if (0 >= (s16) (*(u16 *)((u8 *)(reg_a6) + (0x2A)))) {
                    *(u16 *)var_a0 = 0;
                    (*(u16 *)((u8 *)(reg_a6) + (0x4A))) = 0U;
                    goto block_29;
                }
            }
        }
    } else {
block_29:
        func_001D55B0();
    }
}

extern void func_00129280(void);
extern u32 D_00259970_as_u32_a[];

void func_001D60F0(void)
{
    reg_d0.w = 0x80004;
    reg_d4.w = 0;
    reg_d7.w = 0xF;
    reg_a0 = (u8 *)D_00259970_as_u32_a;

    do {
        func_00129280();
        reg_d1.b[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

extern void func_00129320(void);

void func_001D6160(void)
{
    reg_d1.b[0] *= 4;
    reg_d0.w = 0x80003;
    reg_d4.w = 0;
    reg_d1.b[0] -= 2;
    func_00129320();
    reg_d1.b[0] += 4;
    func_00129320();
}

s32 func_00202730();

void func_001D61B0(arg1, arg2)
    s32 arg1;
    s32 arg2;
{
    s32 var_a1;
    s32 var_a2;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;

    var_a1 = arg1;
    var_a2 = arg2;
    if ((*(u8 *)((u8 *)(reg_a6) + (0xC7))) == 0) {
        var_a2 = 0x1010;
        (*(u8 *)((u8 *)(reg_a6) + (0xC7))) = 1U;
        var_a1 = 0x505;
        (*(s16 *)((u8 *)(reg_a6) + (0xCA))) = 0x1010;
        (*(s16 *)((u8 *)(reg_a6) + (0xCC))) = 0x505;
        (*(u16 *)((u8 *)(reg_a6) + (0xDA))) = 0x60U;
    }
    if ((*(u16 *)((u8 *)(reg_a5) + (0x2E))) != 0) {
        temp_a0 = (*(u8 *)((u8 *)(reg_a6) + (0xC7)));
        if (temp_a0 == 1) {
            func_001D66B0();
            if (D_0028E408 == 0) {
                (*(u16 *)((u8 *)(reg_a6) + (0xDA))) -= 1;
                if ((*(u16 *)((u8 *)(reg_a6) + (0xDA))) == 0) {
                    func_001D6690();
                    (*(u8 *)((u8 *)(reg_a6) + (0xC7))) = 2U;
                }
            }
        }
        temp_a0_2 = (*(u8 *)((u8 *)(reg_a6) + (0xC7)));
        if (temp_a0_2 == 2) {
            func_001D66B0();
            if ((D_0028E408 == 0) && ((*(u8 *)((u8 *)(reg_a5) + (0x25))) == 0)) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xCB)));
                (*(u8 *)((u8 *)(reg_a6) + (0xCB))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a6) + (0xCB))) = (*(u8 *)((u8 *)(reg_a6) + (0xCA)));
                    reg_d1.h[0] = 0x80;
                    func_00202730();
                    reg_d7.b[0] = reg_d1.b[0];
                    reg_d0.w = 0x13;
                    func_0014E030();
                    (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
                    (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
                    (*(u16 *)((u8 *)(reg_a0) + (0x16))) -= 0x800;
                    (*(s8 *)((u8 *)(reg_a0) + (0x1B))) = 0;
                    func_002010A0();
                    reg_d0.b[0] += reg_d7.b[0];
                    (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
                    (*(u8 *)((u8 *)(reg_a6) + (0xCD))) -= 1;
                    if ((*(u8 *)((u8 *)(reg_a6) + (0xCD))) == 0) {
                        (*(u8 *)((u8 *)(reg_a6) + (0xC7))) = 3U;
                        (*(u16 *)((u8 *)(reg_a6) + (0xDA))) = 0x40U;
                    }
                }
            }
        }
    }
    temp_a0_3 = (*(u8 *)((u8 *)(reg_a6) + (0xC7)));
    if (temp_a0_3 == 3) {
        (*(u16 *)((u8 *)(reg_a6) + (0xDA))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a6) + (0xDA))) == 0) {
            func_001D66A0();
            (*(u16 *)((u8 *)(reg_a6) + (0xDA))) = 0x60U;
            (*(u8 *)((u8 *)(reg_a6) + (0xC7))) = 1U;
            (*(u8 *)((u8 *)(reg_a6) + (0xCD))) = (*(u8 *)((u8 *)(reg_a6) + (0xCC)));
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2F)));
            reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x4F)));
            if (reg_d0.b[0] != 0) {
                (*(u8 *)((u8 *)(reg_a6) + (0xCD))) = 0xAU;
            }
        }
    }
}

s32 func_00129410();
extern u16 D_00259970[];

void func_001D6410(void) {
    u8 t1;

    if (*(u8 *)(reg_a5 + 0x1B) == 0) {
        *(u8 *)(reg_a5 + 0x1B) = 1U;
        *(s16 *)(reg_a6 + 0xCE) = 0x810;
        *(s16 *)(reg_a6 + 0xD0) = 0x20;
        *(u8 *)(reg_a6 + 0xD7) = 1U;
        *(u8 *)(reg_a6 + 0xD9) = 0U;
        *(s8 *)(reg_a6 + 0xD5) = 0;
        *(s16 *)(reg_a6 + 0xC) = 0x3001;
        func_001D6690();
    }
    func_001D5670();
    if (*(u8 *)(reg_a5 + 0x25) == 0) {
        reg_tmp.b[0] = *(u8 *)(reg_a6 + 0xCF);
        *(u8 *)(reg_a6 + 0xCF) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            reg_d0.h[0] = 0x10;
            reg_d1.h[0] = D_0028E8C8;
            reg_d1.h[0] >>= 2;
            reg_d0.b[0] -= reg_d1.b[0];
            *(u8 *)(reg_a6 + 0xCF) = (u8) reg_d0.b[0];
            func_00202730();
            if (D_0028E408 == 0) {
                reg_d0.w = 0x70004;
                t1 = 0xF6000000;
                reg_d1.h[0] -= 0x20;
                reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
                reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
                reg_d5.w = 0xF6000000;
                reg_d7.w = 8;
                reg_a0 = (u8 *)(D_00259970);
                reg_d4.w = 0;
                do {
                    reg_d3.h[0] = reg_d1.h[0];
                    reg_d3.h[0] += 2;
                    reg_d3.h[0] &= 0xFC;
                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d3.w += reg_d5.w;
                    func_00129410();
                    reg_d1.b[0] += 8;
                } while ((s16)(--reg_d7.h[0]) >= 0);
                reg_d0.b[0] = *(u8 *)(reg_a6 + 0xD7);
                *(u8 *)(reg_a6 + 0xD9) += reg_d0.b[0];
                if ((s8) reg_d0.b[0] < 0) {
                    if (*(s8 *)(reg_a6 + 0xD9) < -4) {
                        *(u8 *)(reg_a6 + 0xD7) *= -1;
                    }
                } else if (*(s8 *)(reg_a6 + 0xD9) > 4) {
                    *(u8 *)(reg_a6 + 0xD7) *= -1;
                }
            }
        }
    }
}

void func_001D6690(void) {
    reg_a6[0x69] = 1;
}

void func_001D66A0(void) {
    reg_a6[0x69] = 2;
}

void func_001D66B0(void) {
    if (reg_a6[0x69] == 0) {
        D_0028E408 = 0;
        return;
    }
    D_0028E408 = 1;
}


void func_001D66E0(void) {
    func_001D6710();
    func_001D6790();
}

void func_001D6710(void) {
    if ((*(u8 *)((u8 *)(reg_a6) + (0x69))) == 1) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x6B)));
        (*(u8 *)((u8 *)(reg_a6) + (0x6B))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a6) + (0x6B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x6A)));
            (*(u16 *)((u8 *)(reg_a6) + (0xA))) += 4;
            if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0xA))) >= 0x1C) {
                (*(u16 *)((u8 *)(reg_a6) + (0xA))) = 0x1CU;
                (*(u8 *)((u8 *)(reg_a6) + (0x69))) = 0U;
            }
        }
    }
}

void func_001D6790(void) {
    if ((*(u8 *)((u8 *)(reg_a6) + (0x69))) == 2) {
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2F)));
        reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x4F)));
        if (reg_d0.b[0] != 2) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x6B)));
            (*(u8 *)((u8 *)(reg_a6) + (0x6B))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a6) + (0x6B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x6A)));
                (*(u16 *)((u8 *)(reg_a6) + (0xA))) -= 4;
                if (0 >= (s16) (*(u16 *)((u8 *)(reg_a6) + (0xA)))) {
                    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = 0U;
                    goto block_5;
                }
            }
        } else {
block_5:
            (*(u8 *)((u8 *)(reg_a6) + (0x69))) = 0U;
        }
    }
}

void func_001D6830(s32 arg0) {
    s16 temp_v0;
    s32 var_a0;

    var_a0 = arg0;
    if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 0) {
        func_001D66A0();
        var_a0 = 0x600;
        (*(s16 *)((u8 *)(reg_a6) + (0x1A))) = 0x600;
        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 1U;
    }
    if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 1) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2D)));
        (*(u8 *)((u8 *)(reg_a6) + (0x2D))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a6) + (0x2D))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x2C)));
            (*(u16 *)((u8 *)(reg_a6) + (0x4A))) -= 4;
            (*(u16 *)((u8 *)(reg_a6) + (0x2A))) -= 4;
            if (0 >= (s16) (*(u16 *)((u8 *)(reg_a6) + (0x2A)))) {
                (*(u16 *)((u8 *)(reg_a6) + (0x2A))) = 0U;
                (*(u16 *)((u8 *)(reg_a6) + (0x4A))) = 0U;
                (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 2U;
            }
        }
    }
    if (((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 2) && ((*(s16 *)((u8 *)(reg_a6) + (2))) >= 0x6A00)) {
        func_00138A40();
        D_0028E85C_as_s16 = 0;
        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = 3U;
    }
    if ((*(u8 *)((u8 *)(reg_a5) + (0x1B))) == 3) {
        temp_v0 = (*(s16 *)((u8 *)(reg_a6) + (2)));
        if ((temp_v0 < -0x63FF) && (temp_v0 > -0x6800)) {
            (*(s16 *)((u8 *)(reg_a5) + (0x30))) = 1;
        }
    }
    func_00201C60();
}

s32 func_0019C530();
extern u8 D_00263630[];
extern u8 D_00263650[];

void func_001D6990(void) {
    u16 temp_a0;

    reg_a0 = D_00263650;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0xA)));
    (*(u16 *)((u8 *)(reg_a6) + (0x14))) = (u16) (*(u16 *)((u8 *)(reg_a0) + (0)));
    (*(u16 *)((u8 *)(reg_a6) + (0x16))) = (u16) (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_a0 = D_00263630;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0xA)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF200F100;
    reg_d3.h[0] = 0xE78;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
    func_0019C530();
}

extern u8 D_00263670[];
extern u8 D_00263690[];

void func_001D6A40(void) {
    u16 temp_a0;
    u16 temp_a1;

    if ((*(u8 *)((u8 *)(reg_a6) + (0x2F))) == 0) {
        reg_a0 = (u8 *)D_00263670;
        reg_a0 += (*(u16 *)((u8 *)(reg_a5) + (0x32)));
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
        temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
        reg_d1.h[0] = temp_a0;
        reg_d1.w += 0xF000F900;
        reg_d3.h[0] = 0x1038;
        reg_d4.w = 0;
        reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x3B)));
        func_0019C530();
        reg_a0 = (u8 *)D_00263690;
        reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x2A)));
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
        temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xEC000200;
        reg_d4.w = 0;
        reg_d1.w += 0xF200F900;
        reg_d3.h[0] = 0xE38;
        reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x3A)));
        func_0019C530();
    }
}

extern u8 D_002636B0[];
extern u8 D_002636D0[];

void func_001D6B60(void) {
    u16 temp_a0;
    u16 temp_a1;

    if ((*(u8 *)((u8 *)(reg_a6) + (0x4F))) == 0) {
        reg_a0 = (u8 *)D_002636B0;
        reg_a0 += (*(u16 *)((u8 *)(reg_a5) + (0x32)));
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x42)));
        temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
        reg_d1.h[0] = temp_a0;
        reg_d1.w += 0xF000F900;
        reg_d3.h[0] = 0x1038;
        reg_d4.w = 0;
        reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x5B)));
        func_0019C530();
        reg_a0 = (u8 *)D_002636D0;
        reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x4A)));
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x42)));
        temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xF200F900;
        reg_d4.w = 0;
        reg_d1.w += 0xEBFFFE00;
        reg_d3.h[0] = 0xE38;
        reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x5A)));
        func_0019C530();
    }
}

void func_001D6C80(void) {
    func_001713F0(0);
}

extern u8 D_002636F0[];

void func_001D6C90(void) {
    reg_a0 = D_002636F0;
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    (*(u16 *)((u8 *)(reg_a6) + (0x1A))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
    func_002010A0();
    reg_d0.b[0] *= 2;
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) += reg_d0.b[0];
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 0x408U;
    (*(u16 *)((u8 *)(reg_a5) + (0x1A))) = 2U;
    (*(s16 *)((u8 *)(reg_a5) + (0x1E))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x20))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x22))) = 0x101;
    (*(s16 *)((u8 *)(reg_a5) + (0x24))) = 0;
    (*(s8 *)((u8 *)(reg_a5) + (0x27))) = 6;
    (*(s8 *)((u8 *)(reg_a5) + (0x17))) = 0;
}

s32 func_0018D4E0();
s32 func_0019C3E0();
s32 func_00201F20();
s32 func_00203060();
extern u8 D_00263710[];
extern u8 D_00263750[];
extern u8 D_0028E2E4;
extern u16 D_0028E85C;

void func_001D6D60(void) {
    if (D_0028E2E4 != 0) {
        goto next_1;
    }
    if (D_0028E884 == 0) {
        goto next_2;
    }
    if (D_0028E85C == 0) {
        goto next_2;
    }
    if (D_0028E85C == 2) {
        goto next_2;
    }
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *) (reg_a6 + 1);
    if (reg_d1.b[0] == 0) {
        goto next_3;
    }
    reg_d0.b[0] = 0xA3;
    *(u8 *) (reg_a6 + 1) &= reg_d0.b[0];
    func_001A9000();
    reg_d0.b[0] = *(u8 *) (reg_a6 + 0x1C);
    reg_d2.b[0] = 0x15;
    reg_d0.b[0] ^= reg_d2.b[0];
    *(u8 *) (reg_a6 + 0x1C) = reg_d0.b[0];
    if (*(s16 *) (reg_a6 + 0x18) >= 0) {
        goto next_4;
    }
next_2:
    reg_d0.w = 2;
    func_0013A780();
    *(u16 *) (reg_a0 + 2) = *(u16 *) (reg_a6 + 2);
    *(u16 *) (reg_a0 + 4) = *(u16 *) (reg_a6 + 4);
    *(u16 *) (reg_a0 + 0x1A) = *(u16 *) (reg_a6 + 0x1A);
    *(u16 *) (reg_a0 + 0x1E) = 0x10;
    func_0018D4E0();
next_1:
    func_0014E290();
    return;
next_3:
    *(u8 *) (reg_a6 + 0x1C) = 0xA;
next_4:
    func_00203060();
    if (D_0028E408 == 0) {
        goto next_5;
    }
    if (*(u8 *) (reg_a5 + 0x17) == 0) {
        goto next_6;
    }
    func_0014E290();
    return;
next_5:
    *(u8 *) (reg_a5 + 0x17) = 1;
next_6:
    if (D_0028E8A0 != 0) {
        goto next_15;
    }
    func_00201F20();
    reg_tmp.b[0] = *(u8 *) (reg_a5 + 0x1B);
    *(u8 *) (reg_a5 + 0x1B) -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto next_8;
    }
    *(u8 *) (reg_a5 + 0x1B) = *(u8 *) (reg_a5 + 0x1A);
    if (*(u8 *) (reg_a5 + 0x27) == 0) {
        goto next_7;
    }
    if (*(u8 *) (reg_a6 + 0x1B) == 4) {
        goto next_8;
    }
next_7:
    *(u8 *) (reg_a6 + 0x1B) += 1;
next_8:
    if (*(s16 *) (reg_a6 + 2) <= 0x600) {
        goto next_9;
    }
    if (*(u8 *) (reg_a5 + 0x27) == 0) {
        goto next_10;
    }
    if (*(s8 *) (reg_a6 + 0x1B) < 4) {
        goto next_10;
    }
    reg_tmp.b[0] = *(u8 *) (reg_a5 + 0x19);
    *(u8 *) (reg_a5 + 0x19) -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto next_10;
    }
    *(u8 *) (reg_a5 + 0x19) = *(u8 *) (reg_a5 + 0x18);
    func_00202730();
    if (D_0028E408 != 0) {
        goto next_10;
    }
    func_002010A0();
    reg_d0.b[0] = (s8) reg_d0.b[0] >> 1;
    reg_d1.b[0] += reg_d0.b[0];
    reg_d0.w = 0x16;
    reg_d2.h[1] = *(u16 *) (reg_a6 + 2);
    reg_d2.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d4.w = 0;
    reg_d3.w = 0;
    func_00129410();
next_9:
    *(u8 *) (reg_a5 + 0x27) -= 1;
next_10:
    reg_tmp.b[0] = *(u8 *) (reg_a5 + 0x1F);
    *(u8 *) (reg_a5 + 0x1F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto next_11;
    }
    *(u8 *) (reg_a5 + 0x1F) = *(u8 *) (reg_a5 + 0x1E);
    reg_a0 = (u8 *)D_00263710;
    reg_d0.h[0] = *(u16 *) (reg_a5 + 0x20);
    *(u16 *) (reg_a6 + 0xA) = (reg_d0.h[0] != 0) ? *(u16 *) (reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a0;
    *(u16 *) (reg_a6 + 0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *) (reg_a0 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    *(u16 *) (reg_a5 + 0x20) += 4;
    *(u16 *) (reg_a5 + 0x20) &= 0x3F;
next_11:
    reg_tmp.b[0] = *(u8 *) (reg_a5 + 0x23);
    *(u8 *) (reg_a5 + 0x23) -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto next_15;
    }
    *(u8 *) (reg_a5 + 0x23) = *(u8 *) (reg_a5 + 0x22);
    if (*(u16 *) (reg_a5 + 0x24) == 0x5C) {
        goto next_15;
    }
    *(u16 *) (reg_a5 + 0x24) += 4;
    *(u16 *) (reg_a6 + 0x10) += 0x40;
    *(u16 *) (reg_a6 + 0x12) += 0x40;
    *(u16 *) (reg_a6 + 0x14) += 0x20;
    *(u16 *) (reg_a6 + 0x16) += 0x20;
next_15:
    reg_a0 = reg_a6;
    func_0014D220();
    reg_a0 = (u8 *)D_00263750;
    reg_a0 += *(u16 *) (reg_a5 + 0x24);
    reg_d6.h[1] = *(u16 *) reg_a0;
    reg_d6.h[0] = *(u16 *) (reg_a0 + 2);
    func_0019C3E0();
}
