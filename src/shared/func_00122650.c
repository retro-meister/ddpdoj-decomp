#include "common.h"

extern u16 D_00241FF0[];
extern s32 D_0028DFF4;
extern u16 D_0028E470;
extern u16 D_0029CED0[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00122650(void) {
    reg_d7.w = 0x28;
    reg_a1 = (u8 *) D_0029CED0;
    reg_d6.h[1] = *(u16 *) (reg_a5 + 2);
    reg_d6.h[0] = *(u16 *) (reg_a5 + 4);
    D_0028E470 = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = D_0028E470;
    reg_d6.h[0] += 0x600;
    reg_d6.h[0] -= *(u16 *) (reg_a5 + 0x30);
    D_0028E470 = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = D_0028E470;
    reg_d5.w = 0;
loop_20:
    if (reg_d5.h[0] == 0) goto next_40;
    *(u16 *) reg_a1 = 0;
    reg_a1 += 0x30;
    if ((s16) --reg_d7.h[0] >= 0) goto loop_20;
    goto next_160;
next_40:
    reg_tmp.h[1] = *(u16 *) (reg_a6 + 0x2C);
    reg_tmp.h[0] = *(u16 *) (reg_a6 + 0x2E);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_a0 += *(u16 *) (reg_a6 + 0x80A);
    reg_a2 = (u8 *) D_00241FF0;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = reg_d6.h[1];
    reg_a1 += 2;
    *(u16 *) reg_a1 = reg_d6.h[0];
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    D_0028E470 = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = D_0028E470;
    reg_d6.h[0] += 0x400;
    if (D_0028DFF4 != 0) goto next_80;
    if (*(u8 *) (reg_a6 + 0x841) & 2) goto next_60;
    if ((s32) *(u16 *) (reg_a6 + 0x842) > (s32) reg_d6.h[0]) goto next_120;
    *(u16 *) (reg_a6 + 0x842) = reg_d6.h[0];
    goto next_100;
next_60:
    if (*(u8 *) (reg_a6 + 0x7E1) & 2) goto next_80;
    reg_d0.h[0] = *(u16 *) (reg_a6 + 0x7E2);
    reg_d0.h[0] += 0x800;
    if ((s32) reg_d0.h[0] > (s32) reg_d6.h[0]) goto next_120;
    goto next_100;
next_80:
    if (reg_d6.h[0] < 0x7800) goto next_120;
next_100:
    reg_d5.w = 1;
next_120:
    D_0028E470 = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = D_0028E470;
    *(u16 *) reg_a1 = *(u16 *) (reg_a0 + 0);
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) (reg_a0 + 2);
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_a1 -= 0x1E;
    *(u16 *) (reg_a6 + 0x80A) += 4;
    if (*(u16 *) (reg_a6 + 0x80A) != 0x20) goto next_140;
    *(u16 *) (reg_a6 + 0x80A) = 0;
next_140:
    reg_a1 += 0x30;
    if ((s16) --reg_d7.h[0] >= 0) goto loop_20;
next_160:
    *(u16 *) (reg_a6 + 0x80A) = 0x1C;
}
