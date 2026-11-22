#include "common.h"

s32 func_001AA730();                            /* extern */
s32 func_001AA780();                            /* extern */
extern u16 D_0028E650;
extern s16 D_0029CEA0[];

void func_001AA6D0(void) {
    reg_d3.w = reg_d0.w;
    if (D_0029CEA0[0] < 0) {
        func_001AA780();
        return;
    }
    if (D_0028E650 != 0) {
        func_001AA780();
        return;
    }
    func_001AA730();
}
