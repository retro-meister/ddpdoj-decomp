#include "common.h"

s32 func_00129410();
extern u16 D_0026EBF0[];
extern u8 D_0026EC60[];
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001D7A20(void) {
    u16 t;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        *(u16 *)(reg_a6 + 0xC6) += 1;
        if (*(u16 *)(reg_a6 + 0xC6) == 0x18) {
            *(u16 *)(reg_a6 + 0xC6) = 0U;
        }
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0xC6);
        t = reg_d0.h[0];
        reg_d1.w = 0;
        reg_d1.b[0] = D_0026EC60[t];
        reg_d0.h[0] = t + t;
        reg_a0 = (u8 *)(D_0026EBF0);
        reg_d0.h[0] += reg_d0.h[0];
        reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d3.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.w = 7;
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0xC2);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0xC4);
        func_00129410();
    }
}
