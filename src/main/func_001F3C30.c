#include "common.h"

s32 func_001F3CC0();
s32 func_002011A0();
extern u16 D_0029C068[];
extern u8 *reg_a6;

void func_001F3C30() {
    (*(u16 *)((u8 *)(reg_a6) + (2))) = 0xB000;
    (*(u16 *)((u8 *)(reg_a6) + (4))) = 0x1C00U;
    reg_d0.h[0] = D_0029C068[0];
    (*(u16 *)((u8 *)(reg_a6) + (4))) -= reg_d0.h[0];
    func_002011A0();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d0.b[0];
    reg_d0.b[0] += 0x10;
    (*(u8 *)((u8 *)(reg_a6) + (0x130))) = (u8) reg_d0.b[0];
    reg_d0.b[0] += 0x30;
    (*(u8 *)((u8 *)(reg_a6) + (0x13C))) = (u8) reg_d0.b[0];
    func_001F3CC0();
}
