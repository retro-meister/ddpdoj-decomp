#include "common.h"

void func_00207070(void);
void func_00207520(void);

extern s32 D_0028E0C4_as_s32;
extern s16 D_0028E0C8;
extern s16 D_0028E0CC_as_s16;
extern s16 D_0028E0D0_as_s16;
extern u8 D_002A04B0[];

void func_00206D70(void) {
    D_0028E0C4_as_s32 = 0;
    D_0028E0C8 = 0;
    reg_a0 = D_002A04B0;
    D_0028E0D0_as_s16 = 0;
    reg_d0.w = 0x13;
    D_0028E0CC_as_s16 = 0;
    do {
        (*(s16 *)((u8 *)(reg_a0) + (0))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x4A))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x4C))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x4E))) = 0;
        reg_a0 += 0x50;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

typedef void (*Fn)();

extern u16 D_002678A0[];
extern u16 D_002A04B0_as_u16_a[];
extern u32 jtbl_0028E3F4_as_u32;

void func_00206DF0(void) {
    u32 temp_s0;
    u16 *temp_s1;

    func_00207520();
    func_00207070();
    reg_a5 = (u8 *)(D_002A04B0_as_u16_a);
    reg_d0.w = 0x13;
    do {
        temp_s1 = (u16 *)(reg_a5);
        reg_d1.h[0] = *temp_s1;
        if (reg_d1.h[0] != 0) {
            reg_d1.h[0] &= 0xFF;
            reg_d1.h[0] *= 8;
            temp_s0 = reg_d0.w;
            reg_a0 = (u8 *)(D_002678A0);
            reg_tmp.h[1] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_tmp.h[0] = (((reg_d1.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d1.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
            jtbl_0028E3F4_as_u32 = reg_tmp.w;
            ((Fn)jtbl_0028E3F4_as_u32)();
            reg_d0.w = temp_s0;
            reg_a5 = (u8 *)(temp_s1);
        }
        reg_a5 += 0x50;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}


void func_00206F30(void) {
    u8 *a2;
    u8 *a3;
    s32 d3;
    u32 tmp;

    d3 = reg_d3.w;
    a2 = reg_a2;
    a3 = reg_a3;
    reg_a2 += reg_d3.h[0];
    reg_a3 += reg_d3.h[0];
    reg_d3.w >>= 2;
    reg_d3.w -= 1;
loop_1:
    reg_a3 -= 4;
    reg_a2 -= 4;
    *(u16 *) (reg_a2 + 0) = *(u16 *) (reg_a3 + 0);
    *(u16 *) (reg_a2 + 2) = *(u16 *) (reg_a3 + 2);
    tmp = reg_d3.h[0] - 1;
    reg_d3.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d3.w = d3;
    reg_a2 = a2;
    reg_a3 = a3;
}

extern u16 *reg_a2_as_u16_p;
extern u16 *reg_a3_as_u16_p;

void func_00206FD0(void) {
    u16 *temp_v1;
    u16 *temp_a0;
    u32 temp_a1;

    temp_a1 = reg_d3.w;
    temp_v1 = reg_a2_as_u16_p;
    temp_a0 = reg_a3_as_u16_p;
    reg_d3.w = temp_a1 >> 2;
    reg_d3.w -= 1;
    do {
        *reg_a2_as_u16_p = *reg_a3_as_u16_p;
        reg_a3_as_u16_p += 1;
        reg_a2_as_u16_p += 1;
        *reg_a2_as_u16_p = *reg_a3_as_u16_p;
        reg_a3_as_u16_p += 1;
        reg_a2_as_u16_p += 1;
    } while ((s16)(--reg_d3.h[0]) >= 0);
    reg_d3.w = temp_a1;
    reg_a2_as_u16_p = temp_v1;
    reg_a3_as_u16_p = temp_a0;
}

extern u16 D_0028E0D0;
extern u8 D_002A0AF0[];
extern u8 D_002A1130[];

void func_00207070(void) {
    u32 tmp;

    if (D_0028E0D0 == 0) goto block_rts;
    reg_a0 = (u8 *)D_002A1130;
loop_1:
    if (*(u16 *)reg_a0 == 0) goto next_4;
    reg_d5.h[0] = *(u16 *)(reg_a0 + 0x4A);
    reg_a1 = (u8 *)D_002A04B0;
    reg_d6.w = 0x13;
loop_2:
    if (*(s16 *)(reg_a1 + 0x4A) > (s16) reg_d5.h[0]) goto next_3;
    reg_a2 = reg_a1 + 0x50;
    reg_a3 = reg_a1;
    reg_d4.w = (u32) reg_a2;
    reg_d3.w = (u32) D_002A0AF0;
    reg_d3.w -= reg_d4.w;
    func_00206F30();
    reg_a2 = reg_a0;
    reg_d2.h[0] = 0x27;
loop_5:
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    tmp = reg_d2.h[0] - 1;
    reg_d2.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_5;
    goto next_4;
next_3:
    reg_a1 += 0x50;
    tmp = reg_d6.h[0] - 1;
    reg_d6.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
next_4:
    reg_a0 += 0x50;
    D_0028E0D0 -= 0x50;
    if (D_0028E0D0 != 0) goto loop_1;
block_rts:
    return;
}

extern u8 D_002678A0_as_u8_a[];
extern u32 D_0028E0C4;
extern u8 D_002A1770[];

void func_002071C0(void) {
    u32 save_d1;
    u32 save_d2;
    s32 t1;

    save_d2 = reg_d2.w;
    reg_d2.h[0] = D_0028E0D0;
    save_d1 = reg_d1.w;
    if ((s16) reg_d2.h[0] < 0x640) {
        reg_d1.h[0] = reg_d0.h[0];
        reg_a0 = (u8 *)D_002678A0_as_u8_a;
        reg_d1.h[0] *= 8;
        t1 = reg_d1.h[0] + 4;
        reg_d1.h[0] = (t1 != 0) ? *(u16 *)(reg_a0 + ((s16) t1 & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)D_002A1130;
        reg_a0 += reg_d2.h[0] & 0xFFFF;
        reg_d0.h[0] |= 0x8000;
        *(u16 *)(reg_a0 + 0) = reg_d0.h[0];
        *(s16 *)(reg_a0 + 2) = 0;
        *(u16 *)(reg_a0 + 0x4A) = reg_d1.h[0];
        D_0028E0D0 += 0x50;
        D_0028E0C4 += 1;
        reg_d0.w = D_0028E0C4;
        *(u16 *)(reg_a0 + 0x4C) = reg_d0.h[1];
        *(u16 *)(reg_a0 + 0x4E) = reg_d0.h[0];
        reg_d1.w = save_d1;
        reg_d2.w = save_d2;
        return;
    }
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d0.w = 0;
    reg_a0 = (u8 *)D_002A1770;
}


void func_002072F0(void) {
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 tmp;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    if (save_d0 == 0) goto block_1;
    reg_a0 = (u8 *)D_002A04B0;
    reg_d2.w = 0x13;
loop_2:
    if (*(u16 *)reg_a0 == 0) goto next_3;
    reg_d1.h[1] = *(u16 *)(reg_a0 + 0x4C);
    reg_d1.h[0] = *(u16 *)(reg_a0 + 0x4E);
    if (save_d0 != reg_d1.w) goto next_3;
    reg_a2 = reg_a0;
    reg_a3 = reg_a0 + 0x50;
    reg_d4.w = (u32) reg_a3;
    reg_d3.w = (u32) D_002A0AF0;
    reg_d3.w -= reg_d4.w;
    func_00206FD0();
    reg_a2 += reg_d3.h[0];
    *(s16 *)(reg_a2 + 0) = 0;
    *(s16 *)(reg_a2 + 0x4A) = 0;
    *(s16 *)(reg_a2 + 0x4C) = 0;
    *(s16 *)(reg_a2 + 0x4E) = 0;
    goto block_1;
next_3:
    reg_a0 += 0x50;
    tmp = reg_d2.h[0] - 1;
    reg_d2.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
block_1:
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
}

extern u16 D_0028E0CC;

void func_00207490(void) {
    u8 *a1;
    u8 *a0;
    s32 d1;
    s32 d2;

    d1 = reg_d1.w;
    a0 = reg_a0;
    a1 = reg_a1;
    d2 = reg_d2.w;
    reg_d2.h[0] = D_0028E0CC;
    if ((s16) reg_d2.h[0] < 0x640) {
        reg_a1 = (u8 *)D_002A0AF0;
        reg_a1 += reg_d2.h[0] & 0xFFFF;
        *(u16 *) (reg_a1 + 0) = *(u16 *) (reg_a0 + 0);
        *(u16 *) (reg_a1 + 2) = *(u16 *) (reg_a0 + 2);
        D_0028E0CC += 0x50;
    }
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_a0 = a0;
    reg_a1 = a1;
}

extern u16 D_002A0AF0_as_u16_a[];

void func_00207520(void) {
    if (D_0028E0CC == 0) return;
loop_1:
    D_0028E0CC -= 0x50;
    reg_a1 = (u8 *)D_002A0AF0_as_u16_a;
    reg_d2.h[0] = D_0028E0CC;
    reg_d0.h[1] = (reg_d2.h[0]) ? *(u16 *)(reg_a1 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d0.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)(reg_a1 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    func_002072F0();
    if (D_0028E0CC != 0) goto loop_1;
}

extern s32 reg_a5_as_s32;
extern s32 reg_a0_as_s32;

void func_002075F0(void) {
    reg_a0_as_s32 = reg_a5_as_s32 + 0x4C;
    func_00207490();
}


void func_00207600(void) {
    s32 d0;
    s32 d1;
    s32 d2;
    u32 tmp;

    d1 = reg_d1.w;
    d0 = reg_d0.w;
    d2 = reg_d2.w;
    reg_a0 = (u8 *)D_002A04B0;
    reg_d1.w = 0x13;
loop_1:
    reg_d2.h[1] = *(u16 *) (reg_a0 + 0x4C);
    reg_d2.h[0] = *(u16 *) (reg_a0 + 0x4E);
    if (reg_d2.w == 0) goto next_1;
    if (reg_d2.w != reg_d0.w) goto next_1;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    cond_flag = 0;
    return;
next_1:
    reg_a0 += 0x50;
    tmp = reg_d1.h[0] - 1;
    reg_d1.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_a0 = (u8 *)D_002A1770;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    cond_flag = 1;
}
