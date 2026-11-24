#include "common.h"

s32 func_00129410();
s32 func_002026F0();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001DA7D0(s32 arg0, s32 arg1) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts;
    *(u8 *)(reg_a4 + 5) = *(u8 *)(reg_a4 + 4);
    reg_d0.h[0] = (arg0 != 0) ? *(u16 *)(reg_a6 + ((s16) arg0 & ~1)) : *(u16 *)reg_a6;
    reg_d1.h[0] = ((arg0 + 2) != 0) ? *(u16 *)(reg_a6 + ((s16) (arg0 + 2) & ~1)) : *(u16 *)reg_a6;
    reg_d0.h[0] += 0xF940;
    reg_d1.h[0] += arg1;
    func_002026F0();
    reg_d2.h[1] = (arg0 != 0) ? *(u16 *)(reg_a6 + ((s16) arg0 & ~1)) : *(u16 *)reg_a6;
    reg_d2.h[0] = ((arg0 + 2) != 0) ? *(u16 *)(reg_a6 + ((s16) (arg0 + 2) & ~1)) : *(u16 *)reg_a6;
    reg_d3.w = arg1 + 0xF9400000;
    reg_d4.w = 0;
    reg_d0.w = 4;
    func_00129410();
    reg_d1.b[0] += 6;
    func_00129410();
    reg_d1.b[0] += 6;
    func_00129410();
    reg_d1.b[0] -= 0x12;
    func_00129410();
    reg_d1.b[0] -= 6;
    func_00129410();
    *(u8 *)(reg_a4 + 7) -= 1;
    if (*(s8 *)(reg_a4 + 7) != 0) goto block_rts;
    *(u8 *)(reg_a4 + 7) = *(u8 *)(reg_a4 + 6);
    *(u8 *)(reg_a4 + 5) = 0x40;
block_rts:
    return;
}
