#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
s32 func_001A3020();
extern u8 D_0025FF30[];
extern u8 D_002659F0[];
extern u8 D_00265A00[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001F93D0(void) {
    reg_a0 = D_00265A00;
    func_0014E370();
    reg_a0 = D_002659F0;
    reg_d0.w = 4;
    func_0014E300();
    reg_tmp.w = 0x38001C00;
    *(u16 *)(reg_a6 + 2) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 4) = reg_tmp.h[0];
    reg_d0.h[0] = 0x15;
    reg_a0 = D_0025FF30;
    func_001A3020();
}
