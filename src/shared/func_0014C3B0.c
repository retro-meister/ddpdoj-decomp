#include "common.h"


extern u16 D_00252740[];
extern u16 D_0028E914;
extern u8 *reg_a0;

void func_0014C3B0(void) {
    reg_a0 = (u8 *)(D_00252740);
    reg_d0.h[0] = D_0028E914;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
}
