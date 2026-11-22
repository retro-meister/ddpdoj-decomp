#include "common.h"

s32 func_001E7520();
s32 func_002011A0();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001E7490(void) {
    (*(s16 *)((u8 *)(reg_a4) + (2))) = 0x101;
    func_002011A0();
    reg_d0.h[0] &= 0xF;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0xC6))) = (u16) reg_d0.h[0];
    func_002011A0();
    reg_d0.h[0] &= 0xF;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0xE6))) = (u16) reg_d0.h[0];
    func_001E7520();
}
