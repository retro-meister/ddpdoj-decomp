#include "common.h"

typedef void (*Fn)();

s32 func_0019C940();
extern u8 D_0026E1B0[];
extern u16 D_0026E1D0[];
extern u16 D_0026E250[];
extern u8 *reg_a0;
extern u8 *reg_a2;
extern u8 *reg_a6;

void func_001B7930(void) {
    u16 temp_a1;
    reg_a2 = (u8 *)(D_0026E250);
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2A)));
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xEC00F400;
    reg_d3.h[0] = 0x1460;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x3C)));
    if ((*(u8 *)((u8 *)(reg_a6) + (0x3E))) == 0) {
        reg_d0.w = 0;
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x4A)));
        reg_a0 = (u8 *)(D_0026E1D0);
        reg_d0.b[0] = (u8) ((s32) reg_d0.b[0] >> 3);
        reg_d0.h[0] = (u16) reg_d0.b[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x46))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a6) + (0x48))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    }
    reg_d6.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x46)));
    reg_d6.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x48)));
    reg_d0.w = 0;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x4A)));
    if (reg_d0.b[0] != 0xC0) {
        reg_d0.b[0] = (u8) ((s32) (reg_d0.b[0] & 0xFF) >> 5);
        reg_d0.h[0] = (u16) reg_d0.b[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        ((Fn)*(u32 *)((u8 *)D_0026E1B0 + (reg_d0.h[0] & ~3)))();
        return;
    }
    func_0019C940();
}
