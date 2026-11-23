#include "common.h"

extern u16 D_0028E484;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a6;

void func_0019B9B0(void) {
    reg_a1 = reg_a6 + 2;
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a1) + (0)));
    reg_a1 += 2;
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a1) + (2)));
    D_0028E484 = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = D_0028E484;
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a1) + (0)));
    reg_a1 += 2;
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a1) + (2)));
    reg_d1.w = (u32) ((s32) reg_d1.w >> 6);
    reg_d1.w &= 0x07FF03FF;
    reg_d1.w |= reg_d6.w;
    *(u16 *)reg_a0 = reg_d1.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    reg_a1 += 4;
    *(u16 *)reg_a0 = (*(u16 *)((u8 *)(reg_a1) + (0)));
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = (*(u16 *)((u8 *)(reg_a1) + (0)));
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = (*(u16 *)((u8 *)(reg_a1) + (0)));
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
    reg_a0 += 2;
}
