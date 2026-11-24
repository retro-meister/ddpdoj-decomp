#include "common.h"

s32 func_0014E370();
extern u16 D_0024EBC0_as_u16_a[];
extern u16 D_0024EC80[];
extern u16 D_0024EEF0[];
extern u16 D_0026C590[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001C4830(void) {
    reg_a0 = (u8 *)(D_0026C590);
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    (*(u16 *)((u8 *)(reg_a6) + (0x1A))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
    reg_d1.w = 0;
    reg_d1.b[0] = (u8) (*(u16 *)((u8 *)(reg_a6) + (0x1A)));
    reg_a0 = (u8 *)(D_0024EEF0);
    reg_d1.b[0] += 2;
    reg_d1.b[0] = (u8) ((s8) reg_d1.b[0] >> 2);
    reg_d1.h[0] &= 0x3E;
    reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    (*(u8 *)((u8 *)(reg_a6) + (0x1D))) = (u8) reg_d0.b[0];
    reg_a0 = (u8 *)(D_0024EC80);
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)(D_0024EBC0_as_u16_a);
    (*(u16 *)((u8 *)(reg_a5) + (0x1A))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    (*(s16 *)((u8 *)(reg_a5) + (0x1E))) = 2;
    (*(s16 *)((u8 *)(reg_a5) + (0x20))) = 0;
    (*(s8 *)((u8 *)(reg_a5) + (0x17))) = 0;
}
