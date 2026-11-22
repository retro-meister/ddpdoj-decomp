#include "common.h"

s32 func_00201C60();
s32 func_002021F0();
s32 func_00202500();
s32 func_00202B50();
extern u8 D_002635E0[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001D5670(void) {
    if ((*(u8 *)((u8 *)(reg_a5) + (0x25))) != 0) {
        (*(s16 *)((u8 *)(reg_a6) + (0x1A))) = 0x420;
        func_00201C60();
        return;
    }
    reg_a0 = D_002635E0;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x86)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_002021F0();
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    func_00202500();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = reg_d1.b[0];
    func_00201C60();
    reg_a0 = D_002635E0;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x86)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    func_00202B50();
    if ((s16) reg_d0.h[0] < 0x101) {
        (*(u16 *)((u8 *)(reg_a6) + (0x86))) += 4;
        (*(u16 *)((u8 *)(reg_a6) + (0x86))) &= 0xF;
    }
}
