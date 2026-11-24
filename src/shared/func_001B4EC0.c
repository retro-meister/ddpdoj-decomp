#include "common.h"


s32 func_001713B0();
s32 func_002010A0();
extern u16 D_0026E0B0[];
extern u8 *reg_a0;
extern u8 *reg_a4;

void func_001B4EC0(void) {
    u32 temp_a0;
    (*(s8 *)((u8 *)(reg_a4) + (4))) = 0;
    (*(s8 *)((u8 *)(reg_a4) + (7))) = 0;
    func_001713B0();
    reg_a0 = (u8 *)(D_0026E0B0);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    temp_a0 = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
    (*(u16 *)((u8 *)(reg_a4) + (0xC))) = (u16) (temp_a0 + reg_d0.h[0]);
    (*(u8 *)((u8 *)(reg_a4) + (9))) = 0x20U;
    (*(u8 *)((u8 *)(reg_a4) + (8))) = 0x20U;
    (*(u8 *)((u8 *)(reg_a4) + (0xB))) = 0x20U;
    (*(u8 *)((u8 *)(reg_a4) + (0xA))) = 0x20U;
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (9))) += reg_d0.b[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (8))) += reg_d0.b[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0xB))) += reg_d0.b[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0xA))) += reg_d0.b[0];
}
