#include "common.h"

s32 func_00124D90();
s32 func_001BA820();
s32 func_001BAF40();
s32 func_00201C60();
s32 func_002021F0();
s32 func_00202B50();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001BB0D0() {
    reg_d2.h[0] = 0x6A00;
    reg_d3.h[0] = 0x1C00;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_002021F0();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
    reg_d2.h[0] = 0x6A00;
    reg_d3.h[0] = 0x1C00;
    func_00202B50();
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] = (u16) ((s32) reg_d1.h[0] >> 7);
    (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) reg_d1.b[0];
    if ((s16) reg_d0.h[0] < 0x101) {
        reg_d0.w = 4;
        func_00124D90();
    }
    func_001BAF40();
    func_00201C60();
    func_001BA820();
}
