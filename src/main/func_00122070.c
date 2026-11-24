#include "common.h"

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

void func_00122070(void) {
    u32 base;

    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x2C)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2E)));
    reg_a0 = (u8 *)reg_tmp.w;
    base = (u32)(reg_a0 + (*(u16 *)((u8 *)(reg_a6) + (0x80A))));
    reg_d7.w = 0x28;
    reg_a6 = (u8 *)D_0029CED0;
    reg_a0 = (u8 *)base;
    reg_a2 = (u8 *)D_00241FF0;
    reg_d6.w = 0;
loop_0:
    if ((s16)(*(u16 *)((u8 *)(reg_a6) + (0))) < 0) goto next_0;
    if (reg_d6.h[0] != 0) goto next_6;
    reg_a1 = reg_a6;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a5) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (4)));
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
    *(u16 *)reg_a1 = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_a1 += 2;
    *(u16 *)reg_a1 = (*(u16 *)((u8 *)(reg_a0) + (2)));
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
    reg_a1 += 4;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_d6.w = 1;
    reg_a2 += 2;
    reg_a1 += 2;
    goto next_5;
next_0:
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d0.h[0] += 0x200;
    reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a5) + (0x30)));
    if (D_0028DFF4 != 0) goto next_1;
    if ((*(u16 *)((u8 *)(reg_a3) + (0x868))) == 0) goto next_2;
    if ((*(u8 *)((u8 *)(reg_a3) + (1))) & 0x40) goto next_2;
    if ((s32)(*(u16 *)((u8 *)(reg_a3) + (0x842))) < (s32)reg_d0.h[0]) goto next_3;
    goto next_2;
next_1:
    if ((s32)D_0028DFF8 < (s32)reg_d0.h[0]) goto next_3;
next_2:
    if ((s32)reg_d0.h[0] < 0x7800) goto next_4;
next_3:
    (*(u16 *)((u8 *)(reg_a6) + (0))) = 0;
    goto next_6;
next_4:
    reg_d0.h[0] += 0x200;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (4)));
    (*(u16 *)((u8 *)(reg_a6) + (2))) = reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (4))) = reg_d0.h[0];
next_5:
    func_0019D9C0();
next_6:
    reg_a6 += 0x30;
    if ((s16)(reg_d7.h[0] -= 1) >= 0) goto loop_0;
    reg_a6 = reg_a3;
}
