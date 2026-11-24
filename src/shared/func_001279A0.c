#include "common.h"

s32 func_001273D0();
s32 func_002011A0();
extern u16 D_002695A0[];
extern Reg32 D_0028E484;
extern u8 *reg_a0;
extern u8 *reg_a3;

void func_001279A0(void) {
    u16 temp_a1;
    temp_a1 = reg_d0.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = temp_a1;
    reg_d7.w = reg_d1.w;
    reg_d0.h[0] = reg_tmp.h[1];
    (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0x420;
    func_002011A0();
    reg_a3 = (u8 *)(D_002695A0);
    reg_d0.h[0] &= 0xE;
    reg_d1.w = 0;
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
    D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0xA)));
    D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0xC)));
    D_0028E484.w = (s32) ((s32) D_0028E484.w + reg_d1.w);
    (*(u16 *)((u8 *)(reg_a0) + (0xA))) = (u16) D_0028E484.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0xC))) = D_0028E484.h[0];
    func_001273D0();
    (*(u16 *)((u8 *)(reg_a0) + (0))) &= 0xFF83;
    (*(u16 *)((u8 *)(reg_a0) + (0))) |= 0x14;
}
