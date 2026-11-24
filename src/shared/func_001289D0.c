#include "common.h"

s32 func_00128710(u32);                         /* extern */
s32 func_00128B10();                            /* extern */
extern s32 D_0028DE98;
extern u32 D_0028DE9C;
extern u32 D_0028DEA0;
extern u16 D_0028E910;
extern s32 reg_a0;

void func_001289D0(void) {
    if (D_0028E910 == 0) {
        func_00128B10();
        return;
    }
    D_0028DEA0 = reg_d0.w;
    D_0028DE9C = reg_d1.w;
    D_0028DE98 = reg_a0;
    func_00128710(reg_d0.w);
}
