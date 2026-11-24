#include "common.h"


s32 func_0019C670();
extern u16 D_00264890[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001F0620(void) {
    u32 temp_a0;

    reg_d0.h[0] = 0xA00;
    reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x1FA)));
    (*(u16 *)((u8 *)(reg_a6) + (0x70))) = (u16) reg_d0.h[0];
    reg_d0.h[0] = 0x600;
    reg_d0.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (0x1FA)));
    (*(u16 *)((u8 *)(reg_a6) + (0x72))) = (u16) reg_d0.h[0];
    reg_a0 = (u8 *)(D_00264890);
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x7A)));
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x62)));
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x1FA)));
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x64)));
    temp_a0 = reg_d1.w;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x66)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x68)));
    reg_d1.w = temp_a0 + reg_tmp.w;
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x6E)));
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x7C)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xE8)));
    func_0019C670();
}
