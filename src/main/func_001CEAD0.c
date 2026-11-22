#include "common.h"


s32 func_00171400();
s32 func_001CE980();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001CEAD0(void) {
    u16 var_a0;

    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x17)));
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        var_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d2.h[0] = var_a0;
        reg_d3.w = 0xE2000000;
        reg_d7.w = 3;
        reg_d4.w = 0;
        do {
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (8)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
            func_001CE980();
            var_a0 = (u32)reg_d1.h[0] + 0x40;
            reg_d1.h[0] = var_a0;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x16)));
        (*(u8 *)((u8 *)(reg_a4) + (0x17))) += reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a4) + (0x19))) -= 1;
        if ((*(u8 *)((u8 *)(reg_a4) + (0x19))) == 0) {
            (*(u8 *)((u8 *)(reg_a4) + (0x19))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0x18)));
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 0x12U;
        }
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if (reg_tmp.b[0] == 0) {
            (*(u8 *)((u8 *)(reg_a4) + (0x16))) *= -1;
            func_00171400();
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
        }
    }
}
