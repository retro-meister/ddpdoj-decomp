#include "common.h"

extern u8 *reg_a0;
extern u8 *reg_a6;

extern s8 D_0028E408;

void func_001A18B0(void) {
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x16)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x18)));
    reg_a0 = (u8 *)(reg_tmp.w);
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a6) + (0x5C))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a6) + (0x5E))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a6) + (0x1E))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x12))) >= 0) {
        reg_tmp.w = (u32)reg_a0;
        (*(u16 *)((u8 *)(reg_a6) + (0x16))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0x18))) = (u16) reg_tmp.h[0];
        D_0028E408 = 0;
        return;
    }
    D_0028E408 = 1;
}
