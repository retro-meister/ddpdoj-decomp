#include "common.h"

s32 func_0019D5C0();
extern u16 D_0028E000;
extern u16 D_0028E004;
extern u16 D_0028E3EC;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_00147250(void) {
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_d0.h[0];
    reg_d0.w = 0;
    switch ((*(u16 *)((u8 *)(reg_a6) + (0x1A)))) { case 0: break; default:
        reg_d0.w = 1;
    }
    if (D_0028E3EC != reg_d0.h[0]) {
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x1E)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x20)));
        reg_a0 = (u8 *)(reg_tmp.w);
        (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
        (*(u16 *)((u8 *)(reg_a6) + (0x24))) -= 4;
        if ((s32) reg_tmp.h[0] < 4) {
            (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x22)));
        }
        if ((*(u16 *)((u8 *)(reg_a6) + (0x1A))) != 0) {
            if (D_0028E004 != 0) {
                return;
            }
            goto block_15;
        }
        if (D_0028E000 == 0) {
block_15:
            func_0019D5C0();
        }
    }
}
