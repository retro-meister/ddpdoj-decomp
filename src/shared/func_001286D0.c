#include "common.h"

s32 func_00128710();
extern Reg32 D_0028E484;
extern u32 reg_a0_as_u32;
extern u8 *reg_a5;

void func_001286D0(void) {
    D_0028E484.w = reg_d1.w;
    reg_d1.h[1] = D_0028E484.h[0];
    reg_d1.h[0] = D_0028E484.h[1];
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (6)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (8)));
    reg_a0_as_u32 = reg_tmp.w;
    func_00128710();
}
