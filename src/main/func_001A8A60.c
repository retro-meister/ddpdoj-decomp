#include "common.h"

s32 func_0011C4A0();
s32 func_0011C610();
extern u8 D_0026BB60[];
extern u8 D_0026BB70[];
extern u8 D_0026BBA0[];
extern u8 D_0026BBD0[];
extern Reg32 D_0028E470;
extern Reg32 D_0028E478;
extern u8 *reg_a0;

void func_001A8A60(void) {
    u32 save_d5;

    if (reg_d6.h[0] >= 0x10) goto next_1;
    reg_d6.h[0] += reg_d6.h[0];
    reg_d6.h[0] += reg_d6.h[0];
    reg_a0 = (u8 *)D_0026BB70;
    reg_d4.h[1] = (reg_d6.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d6.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d4.h[0] = (((reg_d6.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d6.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = 2;
    reg_d3.w = 2;
    func_0011C4A0();
    reg_d1.h[0] += 0x300;
next_0:
    reg_d4.h[0] = reg_d5.h[0];
    reg_a0 = (u8 *)D_0026BB60;
    D_0028E478.w = reg_d4.w;
    reg_d4.h[1] = (D_0028E478.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)D_0028E478.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d4.h[0] = (((D_0028E478.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((D_0028E478.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = 2;
    reg_d3.w = 2;
    reg_d5.w = 9;
    func_0011C610();
    return;
next_1:
    save_d5 = reg_d5.h[0];
    reg_d5.w = 0xC;
    D_0028E470.h[0] = reg_d6.h[0];
    reg_d6.h[0] <<= reg_d5.h[0];
    reg_d6.h[0] |= (u16)((s32)D_0028E470.h[0] >> (0x10 - reg_d5.h[0]));
    reg_d5.w = 0xF;
    reg_d5.h[0] &= reg_d6.h[0];
    reg_d5.h[0] += reg_d5.h[0];
    reg_d5.h[0] += reg_d5.h[0];
    reg_a0 = (u8 *)D_0026BBA0;
    reg_d4.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d4.h[0] = (((u16)reg_d5.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d5.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = 2;
    reg_d3.w = 1;
    func_0011C4A0();
    reg_d1.h[0] += 0x200;
    D_0028E470.h[0] = reg_d6.h[0];
    reg_d6.h[0] <<= 4;
    reg_d6.h[0] |= (u16)((s32)D_0028E470.h[0] >> 12);
    reg_d5.w = 0xF;
    reg_d5.h[0] &= reg_d6.h[0];
    reg_d5.h[0] += reg_d5.h[0];
    reg_d5.h[0] += reg_d5.h[0];
    reg_a0 = (u8 *)D_0026BBD0;
    reg_d4.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d4.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = 2;
    reg_d3.w = 0;
    reg_d5.w = 3;
    func_0011C610();
    reg_d1.h[0] += 0x100;
    reg_d5.h[0] = save_d5;
    goto next_0;
}
