#include "common.h"

s32 func_00122070();
s32 func_0019D9C0();
extern u16 D_00241FF0[];
extern s32 D_0028DFF4;
extern u16 D_0028DFF8;
extern u16 D_0029CED0[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a5;
extern u8 *reg_a6;

#define W(o) (*(u16 *)(reg_a6 + (o)))

void func_00121B60(void) {
    reg_tmp.h[0] = W(0x80A);
    W(0x80A) -= 4;
    if ((s32) reg_tmp.h[0] >= 4) goto next_20;
    W(0x80A) = 0x1C;
next_20:
    reg_a3 = reg_a6;
    if (W(0x18) != 0) {
        func_00122070();
        return;
    }
    reg_d0.h[0] = W(0x80A);
    reg_tmp.h[1] = W(0x2C);
    reg_tmp.h[0] = W(0x2E);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d5.w = (u32) reg_a0;
    reg_d4.h[0] = W(0x24);
    reg_a0 += reg_d4.h[0];
    reg_d7.w = 0x28;
    reg_d6.w = 0;
    reg_a6 = (u8 *) D_0029CED0;
    reg_a2 = (u8 *) D_00241FF0;
loop_40:
    if ((s16) W(0) < 0) goto next_100;
    if (reg_d6.h[0] != 0) goto next_190;
    reg_a1 = reg_a6;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_d0.h[1] = *(u16 *)(reg_a5 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
    reg_d0.w += 0x06000000;
    *(u16 *)reg_a1 = reg_d0.h[1];
    reg_a1 += 2;
    *(u16 *)reg_a1 = reg_d0.h[0];
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)(reg_a0 + 0);
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)(reg_a0 + 2);
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = reg_d5.h[1];
    reg_a1 += 2;
    *(u16 *)reg_a1 = reg_d5.h[0];
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_d6.w = 1;
    goto next_180;
next_100:
    reg_tmp.h[1] = W(0x18);
    reg_tmp.h[0] = W(0x1A);
    reg_a1 = (u8 *) reg_tmp.w;
    W(0xA) = (reg_d4.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a1;
    W(0xC) = ((reg_d4.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d0.h[0] = W(2);
    reg_d0.h[0] += 0x200;
    reg_d0.h[0] += *(u16 *)(reg_a5 + 0x30);
    if (D_0028DFF4 == 0) goto next_120;
    if (D_0028DFF8 < reg_d0.h[0]) goto next_140;
next_120:
    if ((s32) reg_d0.h[0] < 0x7800) goto next_160;
next_140:
    W(0) = 0;
    goto next_190;
next_160:
    reg_d0.h[0] += 0x200;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
    W(2) = reg_d0.h[1];
    W(4) = reg_d0.h[0];
next_180:
    func_0019D9C0();
next_190:
    reg_a6 += 0x30;
    if ((s16) --reg_d7.h[0] >= 0) goto loop_40;
    reg_a6 = reg_a3;
}
