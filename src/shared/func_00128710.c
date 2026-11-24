#include "common.h"

s32 func_00128B00();                            /* extern */
extern s32 D_0028DE98;
extern u32 D_0028DE9C;
extern u32 D_0028DEA0;
extern s32 reg_a0_as_s32;

void func_00128710(void) {
    func_00128B00();
    reg_d0.w += 0x60000;
    func_00128B00();
    reg_d0.w = D_0028DEA0;
    reg_d1.w = D_0028DE9C;
    reg_a0_as_s32 = D_0028DE98;
}
