#include "common.h"

s32 func_00124D90();
s32 func_001E5C60(s32, s32);
s32 func_001E8700();
s32 func_001E8760();
extern u8 *reg_a4;

void func_001E5BF0(void) {
    func_001E8700();
    reg_d0.h[0] = 0x40;
    func_001E8760();
    reg_d0.h[0] = 0x60;
    func_001E8760();
    reg_d0.w = 2;
    func_00124D90();
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0;
    (*(u16 *)((u8 *)(reg_a4) + (4))) = 1;
    (*(u16 *)((u8 *)(reg_a4) + (6))) = 0xFF02;
    (*(u16 *)((u8 *)(reg_a4) + (8))) = 0xFF04;
    func_001E5C60(0xFF02, 1);
}
