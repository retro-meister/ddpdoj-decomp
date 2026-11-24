#include "common.h"

typedef void (*Fn)();

s32 func_00207070();
s32 func_00207520();
extern u16 D_002678A0[];
extern u16 D_002A04B0_as_u16_a[];
extern u32 jtbl_0028E3F4_as_u32;
extern u8 *reg_a0;
extern u8 *reg_a5;

void func_00206DF0(void) {
    u32 temp_s0;
    u16 *temp_s1;

    func_00207520();
    func_00207070();
    reg_a5 = (u8 *)(D_002A04B0_as_u16_a);
    reg_d0.w = 0x13;
    do {
        temp_s1 = (u16 *)(reg_a5);
        reg_d1.h[0] = *temp_s1;
        if (reg_d1.h[0] != 0) {
            reg_d1.h[0] &= 0xFF;
            reg_d1.h[0] *= 8;
            temp_s0 = reg_d0.w;
            reg_a0 = (u8 *)(D_002678A0);
            reg_tmp.h[1] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_tmp.h[0] = (((reg_d1.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d1.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
            jtbl_0028E3F4_as_u32 = reg_tmp.w;
            ((Fn)jtbl_0028E3F4_as_u32)();
            reg_d0.w = temp_s0;
            reg_a5 = (u8 *)(temp_s1);
        }
        reg_a5 += 0x50;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}
