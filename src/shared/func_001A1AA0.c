#include "common.h"


s32 func_0019F930();
extern u8 D_0029DCD0[];
extern u8 D_0029E2D0[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;

void func_001A1AA0(void) {
    reg_a1 = D_0029E2D0;
    if (reg_d7.h[0] == 0) {
        reg_a1 = D_0029DCD0;
    }
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x22)));
    reg_d0.h[0] += reg_d0.h[0];
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    func_0019F930();
}
