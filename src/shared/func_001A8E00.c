#include "common.h"

s32 func_0011C4A0();
s32 func_0011C610();
extern u16 D_0026BC00[];
extern u16 D_0028E470;
extern u8 *reg_a1;

void func_001A8E00(void) {
    u32 temp_a1;
    u32 temp_v1_2;
    u16 var_v0_2;
    u32 temp_s0;
    u32 temp_s1;

    reg_d2.w = 2;
    reg_d3.w = 5;
    reg_d4.w = 0x053D000A;
    func_0011C4A0();
    reg_d5.w = 0;
    reg_a1 = (u8 *)(D_0026BC00);
    reg_d7.w = 3;
    reg_d1.h[0] += 0x200;
    do {
        D_0028E470 = reg_d6.h[0];
        reg_d2.w = 0xF;
        reg_d6.h[0] *= 0x10;
        temp_a1 = ((s32) D_0028E470 >> 0xC) & 0xFFFF;
        reg_d6.h[0] |= temp_a1;
        temp_v1_2 = reg_d2.h[0] & reg_d6.h[0];
        reg_d2.h[0] = temp_v1_2;
        if ((temp_v1_2 & 0xFFFF) || (reg_d5.h[0] != 0)) {
            reg_d2.h[0] += reg_d2.h[0];
            reg_d2.h[0] += reg_d2.h[0];
            reg_d4.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a1;
            var_v0_2 = (((u16)reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
            temp_s0 = reg_d2.w;
            temp_s1 = reg_d3.w;
            reg_d4.h[0] = var_v0_2;
            reg_d2.w = 2;
            reg_d5.w = 0xA;
            reg_d3.w = 0;
            func_0011C610();
            reg_d2.w = temp_s0;
            reg_d3.w = temp_s1;
            reg_d5.w = 1;
        }
        reg_d1.h[0] += 0x100;
        reg_a1 += 0x28;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
