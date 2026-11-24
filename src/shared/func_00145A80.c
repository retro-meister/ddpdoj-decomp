#include "common.h"

void func_0019D400(void);
void func_0019D460(void);
extern u16 D_0028E47C;
extern u16 D_0028E484_as_u16;
extern u8 *reg_a2;
extern u8 *reg_a6;

void func_00145A80(void) {
    if (*(u8 *)(reg_a6 + 1) & 4) return;
    if (*(u16 *)(reg_a6 + 0x18) != 0) {
        *(u16 *)(reg_a6 + 0x18) -= 1;
        func_0019D400();
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x14);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x16);
    reg_a2 = (u8 *)reg_tmp.w;
    reg_tmp.h[1] = *(u16 *)(reg_a2 + 0);
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 2);
    reg_a2 = (u8 *)reg_tmp.w;
loop_1:
    reg_d2.h[1] = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_d2.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    if ((s32)reg_d2.w < 0) return;
    if (reg_d2.w == 0) {
        *(u16 *)(reg_a6 + 0x2A) = *(u16 *)reg_a2;
        reg_a2 += 2;
        *(u16 *)(reg_a6 + 0x2C) = *(u16 *)reg_a2;
        reg_a2 += 2;
        *(u16 *)(reg_a6 + 0x2E) = *(u16 *)reg_a2;
        reg_a2 += 2;
        goto loop_1;
    }
    if (reg_d2.w == 1) goto block_2;
    if (reg_d2.w == 2) goto block_1;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x2A);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2C);
    reg_d1.w += reg_tmp.w;
    reg_d3.h[0] = *(u16 *)(reg_a6 + 0x2E);
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x28);
    func_0019D460();
    goto loop_1;
block_1:
    *(u16 *)(reg_a6 + 4) = *(u16 *)reg_a2;
    reg_a2 += 2;
    goto loop_1;
block_2:
    reg_d2.h[1] = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_d2.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] += 0x7FFF + 0x7C01;
    D_0028E484_as_u16 = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = D_0028E484_as_u16;
    reg_d3.h[0] = *(u16 *)(reg_a6 + 4);
    D_0028E47C = reg_d3.h[0];
    reg_d3.h[0] -= 0x1000;
    if ((s32)D_0028E47C >= 0x1000) {
        reg_d1.h[0] = 0;
        reg_d3.h[0] >>= 6;
        reg_d3.h[0] += 0x400;
        reg_d4.h[0] = *(u16 *)(reg_a6 + 0x28);
        func_0019D460();
    }
    reg_d4.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d4.h[0] += 0x1000;
    if ((s32)reg_d4.h[0] < 0x3800) {
        reg_d1.h[0] = reg_d4.h[0];
        reg_d3.h[0] = 0x3800;
        reg_d3.h[0] -= reg_d4.h[0];
        reg_d3.h[0] >>= 6;
        reg_d3.h[0] += 0x400;
        reg_d4.h[0] = *(u16 *)(reg_a6 + 0x28);
        func_0019D460();
    }
    goto loop_1;
}
