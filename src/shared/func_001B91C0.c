#include "common.h"


s32 func_00201270();
extern u8 D_00250CD0[];
extern u8 *reg_a0;
extern u8 *reg_a1;

void func_001B91C0(void) {
    func_00201270();
    reg_a1 = D_00250CD0;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a1 += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (0x14))) = (u16) (*(u16 *)((u8 *)(reg_a1) + (0)));
    (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) (*(u16 *)((u8 *)(reg_a1) + (2)));
    func_00201270();
    reg_d0.h[0] += 1;
    reg_d0.h[0] <<= 5;
    reg_d0.h[0] -= 4;
    (*(u16 *)((u8 *)(reg_a0) + (0x10))) -= reg_d0.h[0];
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0x14)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0x16)));
    reg_a1 = (u8 *) reg_tmp.w;
    (*(u16 *)((u8 *)(reg_a0) + (0xA))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a1) + (0)));
    (*(u16 *)((u8 *)(reg_a0) + (0xC))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
}
