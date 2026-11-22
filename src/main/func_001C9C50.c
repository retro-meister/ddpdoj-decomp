#include "common.h"

s32 func_001C9750();
s32 func_002011D0();
s32 func_00201C60();
s32 func_002021F0();
s32 func_00202500();
s32 func_00202B50();
extern u8 D_0026C860[];
extern u8 *reg_a0;
extern u16 *reg_a4;
extern u8 *reg_a6;

void func_001C9C50() {
    reg_a0 = D_0026C860;
    reg_a0 += *reg_a4;
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_002021F0();
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    func_00202500();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
    func_00201C60();
    reg_a0 = D_0026C860;
    reg_a0 += *reg_a4;
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    func_00202B50();
    if ((s16) reg_d0.h[0] < 0x101) {
        *reg_a4 += 4;
        *reg_a4 &= 0x3F;
        (*(u8 *)((u8 *)(reg_a6) + (0x1B))) = 4U;
        func_002011D0();
        (*(u8 *)((u8 *)(reg_a6) + (0x1B))) -= reg_d0.b[0];
    }
    func_001C9750();
}
