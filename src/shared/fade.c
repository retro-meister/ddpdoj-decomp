#include "common.h"

void func_0013B3C0(void);
void func_0013B990(void);
void func_0013BEC0(void);
void func_0013C300(void);
void func_0013C4B0(void);

void func_0013AF10(void) {
    reg_d2.h[0] = reg_d1.h[0];
    reg_d0.w = 0xA;
    reg_d4.h[0] = reg_d1.h[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d2.h[0] &= 0x7C00;
    reg_d3.h[0] &= 0x3E0;
    reg_d4.h[0] &= 0x1F;
    reg_d2.h[0] >>= 0xA;
    reg_d3.h[0] >>= 5;
}

void func_0013AF70(void) {
    reg_d1.w = 0;
    reg_d0.w = 0xA;
    reg_d2.h[0] <<= 0xA;
    reg_d3.h[0] <<= 5;
    reg_d4.h[0] &= 0x1F;
    reg_d2.h[0] &= 0x7C00;
    reg_d3.h[0] &= 0x3E0;
    reg_d1.h[0] |= reg_d2.h[0];
    reg_d1.h[0] |= reg_d3.h[0];
    reg_d1.h[0] |= reg_d4.h[0];
}


void func_0013AFF0(void) {
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;

    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    reg_d7.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d0.h[0];
    func_0013AF10();
    reg_d2.h[0] = (s16)reg_d2.h[0] << 8;
    reg_d3.h[0] = (s16)reg_d3.h[0] << 8;
    reg_d4.h[0] = (s16)reg_d4.h[0] << 8;
    reg_d2.h[0] = (s16)reg_d2.h[0] >> 5;
    reg_d3.h[0] = (s16)reg_d3.h[0] >> 5;
    reg_d4.h[0] = (s16)reg_d4.h[0] >> 5;
    reg_d2.h[0] = (s16)reg_d2.h[0] * (s16)reg_d7.h[0];
    reg_d3.h[0] = (s16)reg_d3.h[0] * (s16)reg_d7.h[0];
    reg_d4.h[0] = (s16)reg_d4.h[0] * (s16)reg_d7.h[0];
    reg_d2.h[0] = (s16)reg_d2.h[0] >> 8;
    reg_d3.h[0] = (s16)reg_d3.h[0] >> 8;
    reg_d4.h[0] = (s16)reg_d4.h[0] >> 8;
    reg_d2.h[0] &= 0x7FFF;
    reg_d3.h[0] &= 0x7FFF;
    reg_d4.h[0] &= 0x7FFF;
    if ((s16)reg_d2.h[0] > 0x1F) {
        reg_d2.h[0] = 0x1F;
    }
    if ((s16)reg_d3.h[0] > 0x1F) {
        reg_d3.h[0] = 0x1F;
    }
    if ((s16)reg_d4.h[0] > 0x1F) {
        reg_d4.h[0] = 0x1F;
    }
    func_0013AF70();
    reg_d0.h[0] = reg_d1.h[0];
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
}

extern s32 D_0028DF20;
extern s32 D_0028DF24;
extern s32 D_0028DF28;
extern s32 D_0028DF2C;
extern s32 D_0028DF30;
extern s32 D_0028DF34;
extern s32 D_0028DF38;
extern u8 D_0029C0C0[];
extern u8 D_0029C150[];

void func_0013B190(void) {
    s32 i;

    for (i = 0; i < 0x8C0; i++) {
        D_0029C150[i] = 0;
    }
    for (i = 0; i < 0x90; i++) {
        D_0029C0C0[i] = 0;
    }
    reg_a0 = (u8 *)D_0029C0C0;
    reg_d7.w = 2;
    D_0028DF38 = 0;
    D_0028DF34 = 0;
    D_0028DF30 = 0;
    D_0028DF2C = 0;
    D_0028DF28 = 0;
    D_0028DF24 = 0;
    D_0028DF20 = 0;
    do {
        *(s16 *)reg_a0 = 0;
        *(s16 *)(reg_a0 + 4) = 0;
        *(s16 *)(reg_a0 + 0x2C) = 0;
        *(s16 *)(reg_a0 + 0x2E) = 0;
        reg_a0 += 0x30;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d7.h[0] = 0x13;
    reg_a0 = (u8 *)D_0029C150;
    do {
        *(s16 *)reg_a0 = 0;
        *(s16 *)(reg_a0 + 0x2C) = 0;
        *(s16 *)(reg_a0 + 0x2E) = 0;
        reg_a0 += 0x70;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}


extern u32 reg_save_d7;
extern u32 reg_save_d6;
extern u32 reg_save_d5;
extern u32 reg_save_d4;
extern u32 reg_save_d3;
extern u32 reg_save_d2;
extern u32 reg_save_d1;
extern s32 reg_save_a4;
extern s32 reg_save_a3;
extern s32 reg_save_a2_as_s32;
extern s32 reg_save_a1_as_s32;
extern s32 reg_save_a0;

extern s32 reg_a0_as_s32;
extern s32 reg_a1_as_s32;
extern s32 reg_a2_as_s32;
extern s32 reg_a3_as_s32;
extern s32 reg_a4_as_s32;

void func_0013B2E0(void)
{
    reg_save_d1 = reg_d1.w;
    reg_save_d2 = reg_d2.w;
    reg_save_d3 = reg_d3.w;
    reg_save_d4 = reg_d4.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    reg_save_a0 = reg_a0_as_s32;
    reg_save_a1_as_s32 = reg_a1_as_s32;
    reg_save_a2_as_s32 = reg_a2_as_s32;
    reg_save_a3 = reg_a3_as_s32;
    reg_save_a4 = reg_a4_as_s32;

    reg_d6.h[0] = 1;
    func_0013B3C0();
}

void func_0013B350(void)
{
    reg_save_d1 = reg_d1.w;
    reg_save_d2 = reg_d2.w;
    reg_save_d3 = reg_d3.w;
    reg_save_d4 = reg_d4.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    reg_save_a0 = reg_a0_as_s32;
    reg_save_a1_as_s32 = reg_a1_as_s32;
    reg_save_a2_as_s32 = reg_a2_as_s32;
    reg_save_a3 = reg_a3_as_s32;
    reg_save_a4 = reg_a4_as_s32;
    reg_d6.h[0] = 0;
    func_0013B3C0();
}

extern u8 D_002553F0[];
extern u8 D_002554F0[];
extern u16 *reg_save_a4_as_u16_p;
extern u32 reg_save_a3_as_u32;
extern u8 *reg_save_a2;
extern u8 *reg_save_a1;
extern u16 *reg_save_a0_as_u16_p;

void func_0013B3C0(void) {
    u8 *saved_a0;
    u8 *saved_a1;
    u32 t;
    u16 t5;

    reg_a1 = (u8 *)D_0029C0C0;
    reg_d7.w = 2;
loop_1:
    reg_tmp.h[0] = *(u16 *)(reg_a1 + 0);
    if ((s16) reg_tmp.h[0] < 0) goto next_3;
    *(u16 *)(reg_a1 + 0) = 0x8000;
    *(u16 *)(reg_a1 + 4) = reg_d6.h[0];
    saved_a0 = reg_a0;
    saved_a1 = reg_a1;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d6.h[0] = 0x13;
    reg_a2 = (u8 *)D_0029C150;
loop_2:
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 0);
    if ((s16) reg_tmp.h[0] < 0) goto next_1;
    *(u16 *)(reg_a2 + 0) = 0x8000U;
    *(s16 *)(reg_a2 + 0x20) = 0;
    *(s16 *)(reg_a2 + 0x2C) = 0;
    *(s16 *)(reg_a2 + 0x2E) = 0;
    reg_tmp.w = (u32) reg_a2;
    *(u16 *)(reg_a1 + 0x2C) = reg_tmp.h[1];
    *(u16 *)(reg_a1 + 0x2E) = reg_tmp.h[0];
    reg_a1 = reg_a2;
    *(s16 *)(reg_a2 + 0x1E) = 0;
    *(s16 *)(reg_a2 + 2) = 0;
    *(u16 *)(reg_a2 + 0x12) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.w = (*(u32 *)((u8 *)((D_002554F0 + (reg_d2.h[0] & ~3))) + (4)));
    *(u16 *)(reg_a2 + 6) = reg_tmp.h[1];
    *(u16 *)(reg_a2 + 8) = reg_tmp.h[0];
    reg_a3 = *(u8 **)(D_002554F0 + (reg_d2.h[0] & ~3));
    t5 = *(u16 *)reg_a0;
    reg_a3 += t5;
    reg_a0 += 2;
    reg_tmp.w = (u32)reg_a3;
    *(u16 *)(reg_a2 + 0xE) = reg_tmp.h[1];
    *(u16 *)(reg_a2 + 0x10) = reg_tmp.h[0];
    *(u16 *)(reg_a2 + 0xA) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a2 + 0xC) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a2 + 4) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d3.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a3 = (u8 *)((u32) D_002553F0);
    reg_d3.h[0] &= 0x1F;
    reg_d3.h[0] *= 4;
    reg_a3 += reg_d3.h[0];
    *(u16 *)(reg_a2 + 0x16) = *(u16 *)reg_a3;
    reg_a3 += 2;
    *(u16 *)(reg_a2 + 0x14) = *(u16 *)(reg_a2 + 0x16);
    *(u16 *)(reg_a2 + 0x1C) = *(u16 *)reg_a3;
    reg_tmp.w = 0xFFFF0000;
    *(u16 *)(reg_a2 + 0x18) = reg_tmp.h[1];
    *(u16 *)(reg_a2 + 0x1A) = reg_tmp.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a2 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 8);
    reg_a4 = (u8 *)(reg_tmp.w);
    *(u16 *)reg_a4 = 1;
    reg_tmp.h[1] = *(u16 *)(reg_a2 + 0xE);
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 0x10);
    reg_a4 = (u8 *)(reg_tmp.w);
    reg_d2.h[0] = *(u16 *)(reg_a2 + 4);
    reg_d3.h[0] = *(u16 *)(reg_a2 + 0x12);
    do {
        *(u16 *)reg_a4 = reg_d3.h[0];
        reg_a4 += 2;
    } while ((s16)(--reg_d2.h[0]) >= 0);
    reg_tmp.h[1] = *(u16 *)(reg_a2 + 0xE);
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 0x10);
    reg_a3 = (u8 *)(reg_tmp.w);
    reg_d4.h[0] = *(u16 *)(reg_a2 + 4);
    reg_a4 = (u8 *)(reg_a2 + 0x30);
    do {
        *(u16 *)reg_a4 = *(u16 *)reg_a3;
        reg_a3 += 2;
        reg_a4 += 2;
    } while ((s16)(--reg_d4.h[0]) >= 0);
    reg_d0.h[0] -= 1;
    if (reg_d0.h[0] == 0) goto next_2;
next_1:
    reg_a2 += 0x70;
    t = reg_d6.h[0] - 1;
    reg_d6.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
    reg_d0.w = -1;
next_2:
    reg_a0 = saved_a0;
    reg_a1 = saved_a1;
    if ((s16) reg_d0.h[0] >= 0) goto next_4;
    reg_d0.w = (u32) reg_a1;
    func_0013C300();
    goto next_5;
next_4:
    reg_d0.w = (u32) reg_a1;
    reg_d1.w = reg_save_d1;
    reg_d2.w = reg_save_d2;
    reg_d3.w = reg_save_d3;
    reg_d4.w = reg_save_d4;
    reg_d5.w = reg_save_d5;
    reg_d6.w = reg_save_d6;
    reg_d7.w = reg_save_d7;
    reg_a0 = (u8 *) reg_save_a0_as_u16_p;
    reg_a1 = (u8 *)reg_save_a1;
    reg_a2 = (u8 *)reg_save_a2;
    reg_a3 = (u8 *) reg_save_a3_as_u32;
    reg_a4 = (u8 *) reg_save_a4_as_u16_p;
    return;
next_3:
    reg_a1 += 0x30;
    t = reg_d7.h[0] - 1;
    reg_d7.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
next_5:
    reg_d0.w = -1;
    reg_d1.w = reg_save_d1;
    reg_d2.w = reg_save_d2;
    reg_d3.w = reg_save_d3;
    reg_d4.w = reg_save_d4;
    reg_d5.w = reg_save_d5;
    reg_d6.w = reg_save_d6;
    reg_d7.w = reg_save_d7;
    reg_a0 = (u8 *) reg_save_a0_as_u16_p;
    reg_a1 = (u8 *)reg_save_a1;
    reg_a2 = (u8 *)reg_save_a2;
    reg_a3 = (u8 *) reg_save_a3_as_u32;
    reg_a4 = (u8 *) reg_save_a4_as_u16_p;
}




void func_0013B8B0(void)
{
    reg_save_d1 = reg_d1.w;
    reg_save_d2 = reg_d2.w;
    reg_save_d3 = reg_d3.w;
    reg_save_d4 = reg_d4.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d6 = reg_d6.w;
    reg_d6.h[0] = 1;
    reg_save_d7 = reg_d7.w;
    reg_save_a0 = reg_a0_as_s32;
    reg_save_a1_as_s32 = reg_a1_as_s32;
    reg_save_a2_as_s32 = reg_a2_as_s32;
    reg_save_a3 = reg_a3_as_s32;
    reg_save_a4 = reg_a4_as_s32;
    func_0013B990();
}

void func_0013B920(void)
{
    reg_save_d1 = reg_d1.w;
    reg_save_d2 = reg_d2.w;
    reg_save_d3 = reg_d3.w;
    reg_save_d4 = reg_d4.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    reg_save_a0 = reg_a0_as_s32;
    reg_save_a1_as_s32 = reg_a1_as_s32;
    reg_save_a2_as_s32 = reg_a2_as_s32;
    reg_save_a3 = reg_a3_as_s32;
    reg_save_a4 = reg_a4_as_s32;
    reg_d6.h[0] = 0;
    func_0013B990();
}

void func_0013B990(void) {
    u8 *saved_a0;
    u8 *saved_a1;
    u32 t;
    u16 t5;

    reg_a1 = (u8 *)D_0029C0C0;
    reg_d7.w = 2;
loop_1:
    reg_tmp.h[0] = *(u16 *)(reg_a1 + 0);
    if ((s16) reg_tmp.h[0] < 0) goto next_3;
    *(u16 *)(reg_a1 + 0) = 0x8000;
    *(u16 *)(reg_a1 + 4) = reg_d6.h[0];
    saved_a0 = reg_a0;
    saved_a1 = reg_a1;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d6.h[0] = 0x13;
    reg_a2 = (u8 *)D_0029C150;
loop_2:
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 0);
    if ((s16) reg_tmp.h[0] < 0) goto next_1;
    *(u16 *)(reg_a2 + 0) = 0x8000U;
    *(s16 *)(reg_a2 + 0x20) = 0;
    *(s16 *)(reg_a2 + 0x2C) = 0;
    *(s16 *)(reg_a2 + 0x2E) = 0;
    reg_tmp.w = (u32) reg_a2;
    *(u16 *)(reg_a1 + 0x2C) = reg_tmp.h[1];
    *(u16 *)(reg_a1 + 0x2E) = reg_tmp.h[0];
    reg_a1 = reg_a2;
    *(s16 *)(reg_a2 + 0x1E) = 0;
    *(s16 *)(reg_a2 + 2) = 0;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.w = (*(u32 *)((u8 *)((D_002554F0 + (reg_d2.h[0] & ~3))) + (4)));
    *(u16 *)(reg_a2 + 6) = reg_tmp.h[1];
    *(u16 *)(reg_a2 + 8) = reg_tmp.h[0];
    reg_a3 = *(u8 **)(D_002554F0 + (reg_d2.h[0] & ~3));
    t5 = *(u16 *)reg_a0;
    reg_a3 += t5;
    reg_a0 += 2;
    reg_tmp.w = (u32)reg_a3;
    *(u16 *)(reg_a2 + 0xE) = reg_tmp.h[1];
    *(u16 *)(reg_a2 + 0x10) = reg_tmp.h[0];
    *(u16 *)(reg_a2 + 0xA) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a2 + 0xC) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a2 + 4) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d3.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a3 = (u8 *)((u32) D_002553F0);
    reg_d3.h[0] &= 0x1F;
    reg_d3.h[0] *= 4;
    reg_a3 += reg_d3.h[0];
    *(u16 *)(reg_a2 + 0x16) = *(u16 *)reg_a3;
    reg_a3 += 2;
    *(u16 *)(reg_a2 + 0x14) = *(u16 *)(reg_a2 + 0x16);
    *(u16 *)(reg_a2 + 0x1C) = *(u16 *)reg_a3;
    reg_tmp.w = 0xFFFF0000;
    *(u16 *)(reg_a2 + 0x18) = reg_tmp.h[1];
    *(u16 *)(reg_a2 + 0x1A) = reg_tmp.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a2 + 0xE);
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 0x10);
    reg_a3 = (u8 *)(reg_tmp.w);
    reg_d4.h[0] = *(u16 *)(reg_a2 + 4);
    reg_a4 = (u8 *)(reg_a2 + 0x30);
    do {
        *(u16 *)reg_a4 = *(u16 *)reg_a3;
        reg_a3 += 2;
        reg_a4 += 2;
    } while ((s16)(--reg_d4.h[0]) >= 0);
    reg_d0.h[0] -= 1;
    if (reg_d0.h[0] == 0) goto next_2;
next_1:
    reg_a2 += 0x70;
    t = reg_d6.h[0] - 1;
    reg_d6.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
    reg_d0.w = -1;
next_2:
    reg_a0 = saved_a0;
    reg_a1 = saved_a1;
    if ((s16) reg_d0.h[0] >= 0) goto next_4;
    reg_d0.w = (u32) reg_a1;
    func_0013C300();
    goto next_5;
next_4:
    reg_d0.w = (u32) reg_a1;
    reg_d1.w = reg_save_d1;
    reg_d2.w = reg_save_d2;
    reg_d3.w = reg_save_d3;
    reg_d4.w = reg_save_d4;
    reg_d5.w = reg_save_d5;
    reg_d6.w = reg_save_d6;
    reg_d7.w = reg_save_d7;
    reg_a0 = (u8 *) reg_save_a0_as_u16_p;
    reg_a1 = (u8 *)reg_save_a1;
    reg_a2 = (u8 *)reg_save_a2;
    reg_a3 = (u8 *) reg_save_a3_as_u32;
    reg_a4 = (u8 *) reg_save_a4_as_u16_p;
    return;
next_3:
    reg_a1 += 0x30;
    t = reg_d7.h[0] - 1;
    reg_d7.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
next_5:
    reg_d0.w = -1;
    reg_d1.w = reg_save_d1;
    reg_d2.w = reg_save_d2;
    reg_d3.w = reg_save_d3;
    reg_d4.w = reg_save_d4;
    reg_d5.w = reg_save_d5;
    reg_d6.w = reg_save_d6;
    reg_d7.w = reg_save_d7;
    reg_a0 = (u8 *) reg_save_a0_as_u16_p;
    reg_a1 = (u8 *)reg_save_a1;
    reg_a2 = (u8 *)reg_save_a2;
    reg_a3 = (u8 *) reg_save_a3_as_u32;
    reg_a4 = (u8 *) reg_save_a4_as_u16_p;
}




void func_0013BDE0(void)
{
    reg_save_d1 = reg_d1.w;
    reg_save_d2 = reg_d2.w;
    reg_save_d3 = reg_d3.w;
    reg_save_d4 = reg_d4.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    reg_save_a0 = reg_a0_as_s32;
    reg_save_a1_as_s32 = reg_a1_as_s32;
    reg_save_a2_as_s32 = reg_a2_as_s32;
    reg_save_a3 = reg_a3_as_s32;
    reg_save_a4 = reg_a4_as_s32;
    reg_d6.h[0] = 1;
    func_0013BEC0();
}

void func_0013BE50(void)
{
    reg_save_d1 = reg_d1.w;
    reg_save_d2 = reg_d2.w;
    reg_save_d3 = reg_d3.w;
    reg_save_d4 = reg_d4.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    reg_save_a0 = reg_a0_as_s32;
    reg_save_a1_as_s32 = reg_a1_as_s32;
    reg_save_a2_as_s32 = reg_a2_as_s32;
    reg_save_a3 = reg_a3_as_s32;
    reg_save_a4 = reg_a4_as_s32;
    reg_d6.h[0] = 0;
    func_0013BEC0();
}

extern u8 D_00255470_as_u8_a[];

void func_0013BEC0(void) {
    u8 *saved_a0;
    u8 *saved_a1;
    u32 t;
    u16 t5;

    reg_a1 = (u8 *)D_0029C0C0;
    reg_d7.w = 2;
loop_1:
    reg_tmp.h[0] = *(u16 *)(reg_a1 + 0);
    if ((s16) reg_tmp.h[0] < 0) goto next_3;
    *(u16 *)(reg_a1 + 0) = 0x8000;
    *(u16 *)(reg_a1 + 4) = reg_d6.h[0];
    saved_a0 = reg_a0;
    saved_a1 = reg_a1;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d6.h[0] = 0x13;
    reg_a2 = (u8 *)D_0029C150;
loop_2:
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 0);
    if ((s16) reg_tmp.h[0] < 0) goto next_1;
    *(u16 *)(reg_a2 + 0) = 0x8000U;
    *(s16 *)(reg_a2 + 0x20) = 0;
    *(s16 *)(reg_a2 + 0x2C) = 0;
    *(s16 *)(reg_a2 + 0x2E) = 0;
    reg_tmp.w = (u32) reg_a2;
    *(u16 *)(reg_a1 + 0x2C) = reg_tmp.h[1];
    *(u16 *)(reg_a1 + 0x2E) = reg_tmp.h[0];
    reg_a1 = reg_a2;
    *(s16 *)(reg_a2 + 2) = 0;
    *(s16 *)(reg_a2 + 0x1E) = 1;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.w = (*(u32 *)((u8 *)((D_002554F0 + (reg_d2.h[0] & ~3))) + (4)));
    *(u16 *)(reg_a2 + 6) = reg_tmp.h[1];
    *(u16 *)(reg_a2 + 8) = reg_tmp.h[0];
    reg_a3 = *(u8 **)(D_002554F0 + (reg_d2.h[0] & ~3));
    t5 = *(u16 *)reg_a0;
    reg_a3 += t5;
    reg_a0 += 2;
    reg_tmp.w = (u32)reg_a3;
    *(u16 *)(reg_a2 + 0xE) = reg_tmp.h[1];
    *(u16 *)(reg_a2 + 0x10) = reg_tmp.h[0];
    reg_tmp.w = (u32) D_00255470_as_u8_a;
    *(u16 *)(reg_a2 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a2 + 0xC) = reg_tmp.h[0];
    *(u16 *)(reg_a2 + 4) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d3.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a3 = (u8 *)((u32) D_002553F0);
    reg_d3.h[0] &= 0x1F;
    reg_d3.h[0] *= 4;
    reg_a3 += reg_d3.h[0];
    *(u16 *)(reg_a2 + 0x16) = *(u16 *)reg_a3;
    reg_a3 += 2;
    *(u16 *)(reg_a2 + 0x14) = *(u16 *)(reg_a2 + 0x16);
    *(u16 *)(reg_a2 + 0x1C) = *(u16 *)reg_a3;
    reg_tmp.w = 0xFFFF0000;
    *(u16 *)(reg_a2 + 0x18) = reg_tmp.h[1];
    *(u16 *)(reg_a2 + 0x1A) = reg_tmp.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a2 + 0xE);
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 0x10);
    reg_a3 = (u8 *)(reg_tmp.w);
    reg_d4.h[0] = *(u16 *)(reg_a2 + 4);
    reg_a4 = (u8 *)(reg_a2 + 0x30);
    do {
        *(u16 *)reg_a4 = *(u16 *)reg_a3;
        reg_a3 += 2;
        reg_a4 += 2;
    } while ((s16)(--reg_d4.h[0]) >= 0);
    reg_d0.h[0] -= 1;
    if (reg_d0.h[0] == 0) goto next_2;
next_1:
    reg_a2 += 0x70;
    t = reg_d6.h[0] - 1;
    reg_d6.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
    reg_d0.w = -1;
next_2:
    reg_a0 = saved_a0;
    reg_a1 = saved_a1;
    if ((s16) reg_d0.h[0] >= 0) goto next_4;
    reg_d0.w = (u32) reg_a1;
    func_0013C300();
    goto next_5;
next_4:
    reg_d0.w = (u32) reg_a1;
    reg_d1.w = reg_save_d1;
    reg_d2.w = reg_save_d2;
    reg_d3.w = reg_save_d3;
    reg_d4.w = reg_save_d4;
    reg_d5.w = reg_save_d5;
    reg_d6.w = reg_save_d6;
    reg_d7.w = reg_save_d7;
    reg_a0 = (u8 *) reg_save_a0_as_u16_p;
    reg_a1 = (u8 *)reg_save_a1;
    reg_a2 = (u8 *)reg_save_a2;
    reg_a3 = (u8 *) reg_save_a3_as_u32;
    reg_a4 = (u8 *) reg_save_a4_as_u16_p;
    return;
next_3:
    reg_a1 += 0x30;
    t = reg_d7.h[0] - 1;
    reg_d7.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
next_5:
    reg_d0.w = -1;
    reg_d1.w = reg_save_d1;
    reg_d2.w = reg_save_d2;
    reg_d3.w = reg_save_d3;
    reg_d4.w = reg_save_d4;
    reg_d5.w = reg_save_d5;
    reg_d6.w = reg_save_d6;
    reg_d7.w = reg_save_d7;
    reg_a0 = (u8 *) reg_save_a0_as_u16_p;
    reg_a1 = (u8 *)reg_save_a1;
    reg_a2 = (u8 *)reg_save_a2;
    reg_a3 = (u8 *) reg_save_a3_as_u32;
    reg_a4 = (u8 *) reg_save_a4_as_u16_p;
}

extern u32 reg_a0_as_u32;

void func_0013C300(void)
{
    u32 saved_data_register = reg_d0.w;
    u32 saved_address_register = reg_a0_as_u32;
    u16 *entry;

    do {
        reg_a0_as_u32 = reg_d0.w;
        ((u16 *)reg_a0_as_u32)[0] = 0;
        ((u16 *)reg_a0_as_u32)[2] = 0;
        entry = (u16 *)reg_a0_as_u32;
        reg_d0.h[1] = entry[0x16];
        reg_d0.h[0] = entry[0x17];
    } while (reg_d0.w != 0);

    reg_a0_as_u32 = saved_address_register;
    reg_d0.w = saved_data_register;
}


void func_0013C350(void) {
    u32 temp_d0;
    u32 temp_d1;
    u8 *temp_a0;

    temp_d0 = reg_d0.w;
    temp_d1 = reg_d1.w;
    temp_a0 = reg_a0;
    reg_a0 = (u8 *)reg_d0.w;
    reg_d1.w = 0;
    reg_d0.h[1] = (*(u16 *)(reg_a0 + 0x2C));
    reg_d0.h[0] = (*(u16 *)(reg_a0 + 0x2E));
    if (reg_d0.w != 0) {
        do {
            reg_a0 = (u8 *)reg_d0.w;
            reg_d1.h[0] += (*(u16 *)(reg_a0 + 0x18));
            reg_d0.h[1] = (*(u16 *)(reg_a0 + 0x2C));
            reg_d0.h[0] = (*(u16 *)(reg_a0 + 0x2E));
        } while (reg_d0.w != 0);
        reg_d0.h[0] = reg_d1.h[0];
    }
    if (reg_d0.h[0] != 0) {
        cond_flag = 1;
    } else {
        cond_flag = 0;
    }
    reg_d0.w = temp_d0;
    reg_d1.w = temp_d1;
    reg_a0 = temp_a0;
}


void func_0013C3F0(void) {
    u16 temp_a0;
    reg_d7.w = 2;
    reg_a0 = D_0029C0C0;
    do {
        reg_tmp.h[0] = *(u16 *)reg_a0;
        if ((s16) reg_tmp.h[0] < 0) {
            reg_d0.h[1] = *(u16 *)(reg_a0 + 0x2C);
            reg_d0.h[0] = *(u16 *)(reg_a0 + 0x2E);
            func_0013C4B0();
            temp_a0 = *(u16 *)(reg_a0 + 4);
            if ((temp_a0 != 0) && (temp_a0 == 1)) {
                reg_d0.w = (u32) reg_a0;
                func_0013C350();
                if (cond_flag == 0) {
                    reg_d0.w = (u32) reg_a0;
                    func_0013C300();
                }
            }
        }
        reg_a0 += 0x30;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}


void func_0013C4B0(void) {
loop_1:
    reg_a4 = (u8 *)reg_d0.w;
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0);
    if (reg_tmp.h[0] == 0) goto block_next;
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 8);
    reg_a1 = (u8 *)reg_tmp.w;
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0xA);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xC);
    reg_a2 = (u8 *)reg_tmp.w;
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0xE);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x10);
    reg_a3 = (u8 *)reg_tmp.w;
    reg_d5.h[0] = *(u16 *)(reg_a4 + 4);
    reg_d6.w = 0;
    if (*(u16 *)(reg_a4 + 0x1E) != 0) goto skip_1;
    reg_d6.w = 2;
skip_1:
    if (*(u16 *)(reg_a4 + 0x18) == 0) goto block_next;
    *(u16 *)(reg_a4 + 0x14) -= 1;
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x14);
    if ((s16)reg_tmp.h[0] >= 0) goto block_next;
    *(u16 *)(reg_a4 + 0x14) = *(u16 *)(reg_a4 + 0x16);
    if (*(u16 *)(reg_a4 + 0x20) == 0x20) goto block_next;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x1C);
    *(u16 *)(reg_a4 + 0x20) += reg_d0.h[0];
    if (*(s16 *)(reg_a4 + 0x20) < 0x20) goto skip_2;
    *(u16 *)(reg_a4 + 0x18) = 0;
    *(u16 *)(reg_a4 + 0) = 0;
skip_2:
    reg_a5 = reg_a4 + 0x30;
loop_2:
    reg_d1.h[0] = *(u16 *)reg_a2;
    reg_d2.h[0] = *(u16 *)reg_a3;
    reg_d1.h[0] &= 0x7FFF;
    reg_d2.h[0] &= 0x7FFF;
    if (reg_d2.h[0] == reg_d1.h[0]) goto next_1;
    reg_d1.h[0] = *(u16 *)reg_a3;
    func_0013AF10();
    D_0028DF34 = reg_d2.h[0];
    D_0028DF30 = reg_d3.h[0];
    D_0028DF2C = reg_d4.h[0];
    reg_d1.h[0] = *(u16 *)reg_a2;
    func_0013AF10();
    D_0028DF28 = reg_d2.h[0];
    D_0028DF24 = reg_d3.h[0];
    D_0028DF20 = reg_d4.h[0];
    reg_d2.h[0] -= *(u16 *)&D_0028DF34;
    reg_d3.h[0] -= *(u16 *)&D_0028DF30;
    reg_d4.h[0] -= *(u16 *)&D_0028DF2C;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x1C);
loop_3:
    if (reg_d2.h[0] == 0) goto skip_r;
    if ((s16)reg_d2.h[0] >= 0) goto next_r2;
    if (D_0028DF28 != 0x10) goto skip_r1;
    if (D_0028DF34 == 0xF) goto skip_r;
skip_r1:
    D_0028DF34 -= 1;
    if (D_0028DF34 == 0x10) goto skip_r1;
    if (0 < D_0028DF34) goto skip_r;
    D_0028DF34 = 0;
    goto skip_r;
next_r2:
    if (D_0028DF28 != 0x10) goto next_r3;
    if (D_0028DF34 == 0x11) goto skip_r;
next_r3:
    D_0028DF34 += 1;
    if (D_0028DF34 == 0x10) goto next_r2;
    if ((s16)D_0028DF34 < 0x1F) goto skip_r;
    D_0028DF34 = 0x1F;
skip_r:
    if (reg_d3.h[0] == 0) goto skip_g;
    if ((s16)reg_d3.h[0] >= 0) goto next_g2;
    if (D_0028DF24 != 0x10) goto next_g1;
    if (D_0028DF30 == 0xF) goto skip_g;
next_g1:
    D_0028DF30 -= 1;
    if (D_0028DF30 == 0x10) goto next_g1;
    if (0 < D_0028DF30) goto skip_g;
    D_0028DF30 = 0;
    goto skip_g;
next_g2:
    if (D_0028DF24 != 0x10) goto next_g3;
    if (D_0028DF30 == 0x11) goto skip_g;
next_g3:
    D_0028DF30 += 1;
    if (D_0028DF30 == 0x10) goto next_g2;
    if ((s16)D_0028DF30 < 0x1F) goto skip_g;
    D_0028DF30 = 0x1F;
skip_g:
    if (reg_d4.h[0] == 0) goto skip_b;
    if ((s16)reg_d4.h[0] >= 0) goto next_b2;
    if (D_0028DF20 != 0x10) goto next_b1;
    if (D_0028DF2C == 0xF) goto skip_b;
next_b1:
    D_0028DF2C -= 1;
    if (D_0028DF2C == 0x10) goto next_b1;
    if (0 < D_0028DF2C) goto skip_b;
    D_0028DF2C = 0;
    goto skip_b;
next_b2:
    if (D_0028DF20 != 0x10) goto next_b3;
    if (D_0028DF2C == 0x11) goto skip_b;
next_b3:
    D_0028DF2C += 1;
    if (D_0028DF2C == 0x10) goto next_b2;
    if ((s16)D_0028DF2C < 0x1F) goto skip_b;
    D_0028DF2C = 0x1F;
skip_b:
    reg_d0.h[0] -= 1;
    if (reg_d0.h[0] != 0) goto loop_3;
    reg_d2.h[0] = *(u16 *)&D_0028DF34;
    reg_d3.h[0] = *(u16 *)&D_0028DF30;
    reg_d4.h[0] = *(u16 *)&D_0028DF2C;
    func_0013AF70();
    *(u16 *)reg_a3 = reg_d1.h[0];
    *(u16 *)reg_a1 = 1;
next_1:
    reg_a3 += 2;
    reg_a5 += 2;
    reg_a2 += reg_d6.h[0];
    if ((s16)(--reg_d5.h[0]) >= 0) goto loop_2;
block_next:
    reg_d0.h[1] = *(u16 *)(reg_a4 + 0x2C);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x2E);
    if (reg_d0.w != 0) goto loop_1;
}
