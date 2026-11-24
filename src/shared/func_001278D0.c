#include "common.h"

s32 func_002011A0();
extern s8 D_0028E408;
extern u8 *reg_a0;
extern u16 *reg_a3;

void func_001278D0(void) {
    reg_d7.h[0] &= 0xF;
    (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) reg_d7.b[0];
    (*(s8 *)((u8 *)(reg_a0) + (0x1F))) = 0;
    reg_d7.w = reg_d0.w;
    func_002011A0();
    reg_d0.w &= 0xE;
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *reg_a3;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0xA)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0xC)));
    reg_tmp.w += reg_d0.w;
    (*(u16 *)((u8 *)(reg_a0) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0xC))) = (u16) reg_tmp.h[0];
    D_0028E408 = 0;
    reg_d0.w = reg_d7.w;
}
