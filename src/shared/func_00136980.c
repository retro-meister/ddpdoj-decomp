#include "common.h"

s32 func_00136A30();
s32 func_00136A40();
extern u8 *reg_a1;
extern u8 *reg_a5;

void func_00136980(void) {
    u32 temp_s0;

loop_1:
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x44)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x46)));
    reg_a1 = (u8 *)(reg_tmp.w);
    reg_d1.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    if (0 > (s32) reg_d1.w) {
        func_00136A30();
        return;
    }
    temp_s0 = reg_d0.w;
    if ((s32) reg_d1.w < (s32) temp_s0) {
        func_00136A30();
        return;
    }
    func_00136A40();
    reg_d0.w = temp_s0;
    goto loop_1;
}
