#include "common.h"

s32 func_00136A30();
s32 func_00136A40();
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001368E0(void) {
loop_1:
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x44)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x46)));
    reg_a1 = (u8 *)(reg_tmp.w);
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    if (0 > (s16) reg_d0.h[0]) {
        func_00136A30();
        return;
    }
    if ((s16) reg_d0.h[0] < (s32) (*(u16 *)((u8 *)(reg_a6) + (0x18)))) {
        func_00136A30();
        return;
    }
    func_00136A40();
    goto loop_1;
}
