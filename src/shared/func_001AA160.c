#include "common.h"

s32 func_001AA1C0();                            /* extern */
s32 func_001AA210();                            /* extern */
extern u16 D_0028E650;
extern s16 D_0029CEA0_as_s16_a[];

void func_001AA160(void) {
    reg_d3.w = reg_d0.w;
    if (D_0029CEA0_as_s16_a[0] < 0) {
        func_001AA210();
        return;
    }
    if (D_0028E650 != 0) {
        func_001AA210();
        return;
    }
    func_001AA1C0();
}
