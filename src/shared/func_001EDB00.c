#include "common.h"


s32 func_00129450();
extern u16 D_00259970[];
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001EDB00(void) {
    u16 var_a0;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
    (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        var_a0 = 0xFE000000;
        (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
        reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0x12)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x14)));
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1B)));
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d6.w = 0xFE000000;
        reg_d7.w = 3;
        reg_a1 = (u8 *)(D_00259970);
        reg_d4.w = 0;
        do {
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] += 2;
            reg_d3.h[0] &= 0xFC;
            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
            reg_d3.w += reg_d6.w;
            func_00129450();
            var_a0 = (u32)reg_d1.h[0] + 0x40;
            reg_d1.h[0] = var_a0;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1A)));
        (*(u8 *)((u8 *)(reg_a4) + (0x1B))) += reg_d1.b[0];
    }
}
