#include "common.h"


s32 func_00124B20();
s32 func_00124D10();
s32 func_001253B0();
s32 func_0013F3C0();
s32 func_001E8580();
s32 func_001E8640();
s32 func_001E8790();
s32 func_00201490();
s32 func_00203460();
s32 func_0020ED10();
extern u8 D_0028E855;
extern u16 D_0028E864;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001E8480(void) {
    D_0028E855 |= 0x40;
    D_0028E864 = 1;
    D_0028E855 |= 0x80;
    func_0020ED10();
    func_0013F3C0();
    func_00203460();
    func_00201490();
    func_001E8790();
    func_001253B0();
    func_00124D10();
    reg_tmp.w = -1U;
    (*(u16 *)((u8 *)(reg_a5) + (0x16))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = (u16) reg_tmp.h[0];
    (*(s8 *)((u8 *)(reg_a6) + (0x3E))) = 1;
    (*(u16 *)((u8 *)(reg_a6) + (0x20))) = 0x8000;
    (*(s8 *)((u8 *)(reg_a6) + (0x147))) = 0x13;
    (*(s8 *)((u8 *)(reg_a6) + (0x146))) = 0x14;
    (*(s8 *)((u8 *)(reg_a6) + (0x149))) = 0x15;
    (*(s8 *)((u8 *)(reg_a6) + (0x148))) = 0x15;
    (*(s8 *)((u8 *)(reg_a6) + (0x14B))) = 0x15;
    (*(s8 *)((u8 *)(reg_a6) + (0x14A))) = 0x14;
    func_001E8580();
    func_001E8640();
    reg_d0.w = 2;
    func_00124B20();
}
