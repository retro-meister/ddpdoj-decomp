#include "common.h"

extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a6;

void func_0019B6E0(void) {
    u32 temp_a3;
    u32 temp_t0;

    reg_a1 = (u8 *)(reg_a6 + 2);
    reg_d0.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    temp_t0 = reg_d0.h[0] + *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d0.h[0] = temp_t0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    temp_a3 = reg_d0.h[0] + *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d0.h[0] = temp_a3;
    reg_d0.w = (u32) ((s32) reg_d0.w >> 6);
    reg_d0.w &= 0x07FF03FF;
    reg_d0.w |= 0x80008000;
    *(u16 *)reg_a0 = reg_d0.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d0.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
    reg_a0 += 2;
}
