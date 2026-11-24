#include "common.h"

s32 func_00129230(u32);                         /* extern */
s32 func_00129460();                            /* extern */
extern s32 D_0028DE98;
extern u32 D_0028DE9C;
extern u32 D_0028DEA0;
extern u16 D_0028E910;
extern s32 reg_a0_as_s32;

void func_00129370(void) {
    if (D_0028E910 == 0) {
        func_00129460();
        return;
    }
    D_0028DEA0 = reg_d0.w;
    D_0028DE9C = reg_d1.w;
    D_0028DE98 = reg_a0_as_s32;
    func_00129230(reg_d0.w);
}
