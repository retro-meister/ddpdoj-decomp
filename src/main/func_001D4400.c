#include "common.h"

s32 func_00124B20();
s32 func_00124D10();
s32 func_00125120();
s32 func_001253B0();
s32 func_0013F3C0();
s32 func_001D4620();
s32 func_00203460();
s32 func_0020ED10();
extern u8 D_0028E855;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001D4400() {
    D_0028E855 |= 0x40;
    D_0028E855 |= 0x80;
    func_0020ED10();
    func_0013F3C0();
    func_00203460();
    func_001D4620();
    func_001253B0();
    func_00124D10();
    reg_d0.w = 2;
    func_00125120();
    reg_d0.w = 3;
    func_00125120();
    (*(u16 *)((u8 *)(reg_a6) + (0xB6))) = 1;
    (*(u16 *)((u8 *)(reg_a6) + (0xB8))) = 1;
    reg_tmp.w = -1U;
    (*(u16 *)((u8 *)(reg_a5) + (0x16))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = (u16) reg_tmp.h[0];
    (*(s8 *)((u8 *)(reg_a6) + (0x1E))) = 1;
    (*(u16 *)((u8 *)(reg_a6) + (0))) = 0x8000;
    (*(u16 *)((u8 *)(reg_a6) + (0x20))) = 0x8000;
    (*(u16 *)((u8 *)(reg_a6) + (0x40))) = 0x8000;
    (*(u16 *)((u8 *)(reg_a6) + (0xC0))) = 0x8000;
    (*(u16 *)((u8 *)(reg_a6) + (0xE0))) = 0x8000;
    (*(s8 *)((u8 *)(reg_a6) + (0x67))) = 0x10;
    (*(s8 *)((u8 *)(reg_a6) + (0x66))) = 0x11;
    (*(s8 *)((u8 *)(reg_a6) + (0x69))) = 0x12;
    reg_d0.w = 1;
    func_00124B20();
}
