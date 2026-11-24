#include "common.h"

s32 func_0014D220(void);
s32 func_0019C530(void);
s32 func_0019C570(void);
extern u8 D_00257880[];
extern u16 D_0028E3EC;
extern u16 D_0028E484;
extern u16 D_0028E910;
extern u16 D_0028E91C;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001507E0(void) {
    u32 offset;

    reg_a0 = reg_a6;
    func_0014D220();
    if (D_0028E3EC != 0) {
        reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
        reg_d1.h[0] += 0x7FFF + 0x7901;
        D_0028E484 = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = D_0028E484;
        reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
        reg_d3.h[0] = 0x828;
        reg_d1.h[0] += 0x7FFF + 0x7B01;
        reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
        reg_d2.h[0] = *(u16 *)(reg_a5 + 0x20);
        reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)(D_00257880 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)D_00257880;
        offset = reg_d2.h[0] + 2;
        reg_d2.h[0] = (offset != 0) ? *(u16 *)(D_00257880 + ((s16)offset & ~1)) : *(u16 *)D_00257880;
        func_0019C570();
        *(u16 *)(reg_a5 + 0x20) += 4;
        *(u16 *)(reg_a5 + 0x20) &= 0xF;
    block_rts:
        return;
    }
    if (D_0028E910 != 0) {
        goto block_rts;
    }
    switch (D_0028E91C) {
    case 2:
        return;
    }
    reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] += 0x7FFF + 0x6C01;
    D_0028E484 = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = D_0028E484;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[0] += 0x400;
    reg_d2.h[1] = *(u16 *)(reg_a5 + 0x2C);
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x2E);
    reg_d3.h[0] = 0x410;
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
    reg_d4.b[0] = 0x18;
    func_0019C530();
}
