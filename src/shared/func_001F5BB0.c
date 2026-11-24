#include "common.h"

s32 func_00124B20();
s32 func_00124D10();
s32 func_00124F00();
s32 func_001253B0();
s32 func_0013F3C0();
s32 func_0018DEE0();
s32 func_001F57D0();
s32 func_002016D0();
s32 func_0020ED10();
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001F5BB0(void) {
    func_0018DEE0();
    func_0020ED10();
    (*(u16 *)((u8 *)(reg_a5) + (0x1A))) = 0x6270;
    func_0013F3C0();
    func_002016D0();
    func_001F57D0();
    func_001253B0();
    func_00124D10();
    reg_tmp.w = -1U;
    (*(u16 *)((u8 *)(reg_a5) + (0x16))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = (u16) reg_tmp.h[0];
    (*(s8 *)((u8 *)(reg_a6) + (0x15F))) = 1;
    (*(u16 *)((u8 *)(reg_a6) + (0x140))) = 0x8000;
    (*(u16 *)((u8 *)(reg_a6) + (0x160))) = 0x8000;
    (*(s8 *)((u8 *)(reg_a6) + (0xE7))) = 0x10;
    (*(s8 *)((u8 *)(reg_a6) + (0xE6))) = 0x11;
    (*(s8 *)((u8 *)(reg_a6) + (0xE9))) = 0x12;
    reg_d0.w = 0xE;
    func_00124F00(0x12, 0x11, 0x10, 0x8000);
    reg_d0.w = 0xA;
    func_00124F00();
    reg_d0.w = 3;
    func_00124B20();
}
