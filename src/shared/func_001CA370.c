#include "common.h"

s32 func_001C9750();
s32 func_001C9B10();
s32 func_00201C60();
s32 func_002021F0(void *);
s32 func_00202500();
s32 func_00202B50();
extern u8 D_0026C8A0[];
extern u8 *reg_a0;
extern u16 *reg_a4_as_u16_p;
extern u8 *reg_a6;

void func_001CA370(void) {
    reg_a0 = D_0026C8A0;
    reg_a0 += *reg_a4_as_u16_p;
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_002021F0(reg_a6);
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    func_00202500();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
    func_00201C60();
    reg_a0 = D_0026C8A0;
    reg_a0 += *reg_a4_as_u16_p;
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    func_00202B50();
    if ((s16) reg_d0.h[0] < 0x201) {
        func_001C9B10();
    }
    func_001C9750();
}
