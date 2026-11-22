#include "common.h"

s32 func_00124F50();
s32 func_001251C0();
extern u16 D_0026CB20[];
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001CE070(void) {
    u16 temp_a0;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
        reg_a0 = (u8 *)(D_0026CB20);
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2A)));
        (*(u16 *)((u8 *)(reg_a6) + (0x26))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a6) + (0x28))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x4A)));
        (*(u16 *)((u8 *)(reg_a6) + (0x46))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a6) + (0x48))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a6) + (0x48))) = (u16) -(s16) (*(u16 *)((u8 *)(reg_a6) + (0x48)));
        (*(u16 *)((u8 *)(reg_a6) + (0x2A))) += 4;
        temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x2A)));
        if (temp_a0 == 0x94) {
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
            reg_d0.w = 0;
            func_001251C0();
            reg_d0.w = 3;
            func_00124F50();
        }
        (*(u16 *)((u8 *)(reg_a6) + (0x4A))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x2A)));
    }
}
