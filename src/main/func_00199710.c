#include "common.h"

extern u8 D_0025BE50[];
extern u8 D_0025BE70[];
extern u8 D_002BAE82[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *volatile reg_a4;

void func_00199710(void) {
    reg_tmp.w = (u32)reg_a0;
    (*(u16 *)((u8 *)(reg_a4) + (0x30))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a4) + (0x32))) = (u16) reg_tmp.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (0xC))) = (u16) *(u16 *)reg_a1;
    (*(u16 *)((u8 *)(reg_a4) + (0xE))) = (u16) *(u16 *)(reg_a1 + 2);
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) = (u16) reg_d2.h[0];
    reg_tmp.w = reg_d2.w;
    reg_d2.h[1] = reg_tmp.h[0];
    reg_d2.h[0] = reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a4) + (0x10))) = (u16) reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (0x38))) = (u16) reg_d1.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (0x3A))) = (u16) reg_d3.h[0];
    reg_tmp.w = reg_d3.w;
    reg_d3.h[1] = reg_tmp.h[0];
    reg_d3.h[0] = reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a4) + (0x3C))) = (u16) reg_d3.h[0];
    reg_d0.w = 1;
    reg_a0 = (u8 *)((u32) D_0025BE50);
    if ((*(u16 *)((u8 *)(reg_a4) + (0x2C))) != 0) {
        reg_d0.w = 2;
        reg_a0 = (u8 *)((u32) D_0025BE70);
    }
    D_002BAE82[0] |= (1 << (s8) reg_d0.b[0]) & 0xFF;
    (*(u16 *)((u8 *)(reg_a4) + (6))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a4) + (8))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a4) + (0x14))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a4) + (0x16))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a4) + (0x18))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a4) + (0x1E))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a4) + (0x20))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a4) + (0x22))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a4) + (0x24))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a4) + (0x26))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a4) + (0x28))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a4) + (0x2A))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
}
