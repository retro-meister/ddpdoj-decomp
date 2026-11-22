#include "common.h"

s32 func_00124B20();
s32 func_00124D10();
s32 func_00124F00();
s32 func_001253B0();
s32 func_0013F3C0();
s32 func_001F57D0();
s32 func_002016D0();
s32 func_00203460();
s32 func_0020ED10();
extern u8 D_0028E855;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001F6080() {
    D_0028E855 |= 0x40;
    D_0028E855 |= 0x80;
    func_0020ED10();
    func_0013F3C0();
    func_00203460();
    func_002016D0();
    func_001F57D0();
    func_001253B0();
    func_00124D10();
    reg_tmp.w = -1U;
    (*(u16 *)((u8 *)(reg_a5) + (0x16))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = (u16) reg_tmp.h[0];
    (*(s8 *)((u8 *)(reg_a6) + (0x15E))) = 1;
    (*(u16 *)((u8 *)(reg_a6) + (0x180))) = 0x8000;
    (*(s8 *)((u8 *)(reg_a6) + (0xEC))) = 0x17;
    reg_d0.w = 0x12;
    func_00124F00();
    reg_d0.w = 5;
    func_00124B20();
}
