#include "common.h"

s32 func_001340A0();
s32 func_002075F0();
extern u8 D_0028C608[];
extern u16 D_0028DFB4;
extern u16 D_0028DFB8;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00144400(void) {
    u8 *var_a1;
    u8 *var_a2;
    if (!((*(u8 *)((u8 *)(reg_a6) + (1))) & 4)) {
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x14)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x16)));
        reg_a0 = (u8 *)(reg_tmp.w);
        reg_a0 += 4;
        var_a2 = (u8 *)(reg_a6 + 0x14);
        if (*(s16 *)reg_a0 >= 0) {
            reg_tmp.w = (u32)reg_a0;
            (*(u16 *)((u8 *)(reg_a6) + (0x14))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a6) + (0x16))) = (u16) reg_tmp.h[0];
            return;
        }
        (*(u16 *)((u8 *)(reg_a6) + (0x26))) = 0x20U;
        (*(u8 *)((u8 *)(reg_a6) + (1))) |= 4;
        goto block_4;
    }
block_4:
    (*(u16 *)((u8 *)(reg_a6) + (0x26))) -= 1;
    if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x26))) < 0) {
        if ((*(u8 *)((u8 *)(reg_a5) + (6))) == 0) {
            reg_a4 = (u8 *)(&D_0028DFB8);
        } else {
            reg_a4 = (u8 *)(&D_0028DFB4);
        }
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0)));
        reg_d2.w = 0;
        reg_d3.w = 0;
        reg_d0.h[0] &= 0x2000;
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x5A)));
        var_a1 = (u8 *)(reg_a6 + 0x5A);
        if (reg_d1.h[0] & 2) {
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x20)));
            if (reg_d2.h[0] != 0) {
                reg_d2.h[0] -= 2;
            }
        }
        if (reg_d1.h[0] & 4) {
            reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
            if (reg_d3.h[0] != 0) {
                reg_d3.h[0] -= 2;
            }
        }
        reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x24)));
        if (*(u16 *)reg_a4 == 0) {
            reg_d5.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x5A)));
            reg_a0 = (u8 *)D_0028C608;
            reg_d5.h[0] -= 2;
            reg_d5.b[0] = *(reg_a0 + reg_d5.h[0] + ((reg_d5.h[0] & 1) ? -1 : 1));
            reg_d5.b[0] *= 2;
            if ((s32) reg_d5.b[0] > (s32) reg_d4.b[0]) {
                reg_d4.h[0] += 1;
            }
        }
        reg_a0 = (u8 *)((u32) reg_a6);
        reg_d5.w = 0x30;
        reg_d6.w = 0;
        do {
            *(u16 *)reg_a0 = (s16) reg_d6.h[0];
            reg_a0 += 2;
        } while ((s16)(--reg_d5.h[0]) >= 0);
        (*(u16 *)((u8 *)(reg_a6) + (0))) |= reg_d0.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x5A))) = (u16) reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x20))) = (u16) reg_d2.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_d3.h[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x24))) = (u8) reg_d4.b[0];
        (*(u16 *)((u8 *)(reg_a6) + (0))) &= 0x7FFF;
        reg_d0.w = 0;
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (6)));
        func_001340A0();
        func_002075F0();
    }
}
