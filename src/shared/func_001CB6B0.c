#include "common.h"

s32 func_00124B20();
s32 func_00124D10();
s32 func_00125120(s32, s32, s32, s32);
s32 func_001253B0();
s32 func_0013F3C0();
s32 func_001CBCD0();
s32 func_00203460();
s32 func_0020ED10();
extern u8 D_0028E855;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001CB6B0(void) {
    D_0028E855 |= 0x40;
    D_0028E855 |= 0x80;
    func_0020ED10();
    func_0013F3C0();
    func_00203460();
    func_001CBCD0();
    func_001253B0();
    func_00124D10();
    reg_tmp.w = -1U;
    (*(u16 *)((u8 *)(reg_a5) + (0x16))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = (u16) reg_tmp.h[0];
    (*(s8 *)((u8 *)(reg_a6) + (0x1E))) = 1;
    (*(u16 *)((u8 *)(reg_a6) + (0))) = 0x8000;
    (*(u16 *)((u8 *)(reg_a6) + (0x20))) = 0x8000;
    (*(u16 *)((u8 *)(reg_a6) + (0xC0))) = 0x8000;
    (*(u16 *)((u8 *)(reg_a6) + (0xE0))) = 0x8000;
    (*(s8 *)((u8 *)(reg_a6) + (0x126))) = 0x10;
    (*(s8 *)((u8 *)(reg_a6) + (0x127))) = 0x12;
    (*(s8 *)((u8 *)(reg_a6) + (0x129))) = 0x17;
    (*(s8 *)((u8 *)(reg_a6) + (0x12E))) = 0x11;
    (*(s8 *)((u8 *)(reg_a6) + (0x131))) = 0x13;
    (*(s8 *)((u8 *)(reg_a6) + (0x12C))) = 0x13;
    (*(s8 *)((u8 *)(reg_a6) + (0x12F))) = 0xD;
    (*(s8 *)((u8 *)(reg_a6) + (0x128))) = 0x11;
    (*(s8 *)((u8 *)(reg_a6) + (0x12B))) = 0x11;
    (*(s8 *)((u8 *)(reg_a6) + (0x12A))) = 0x12;
    (*(s8 *)((u8 *)(reg_a6) + (0x12D))) = 0x12;
    reg_d0.w = 0xD;
    func_00125120(0x13, 0x11, 0x17, 0x12);
    reg_d0.w = 2;
    func_00124B20();
}
