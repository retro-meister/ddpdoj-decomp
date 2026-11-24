#include "common.h"

s32 func_001AA1C0();                            /* extern */
s32 func_001AA210();                            /* extern */
s32 func_001AA2E0();                            /* extern */
extern u16 D_0028E5D0;
extern u16 D_0028E5FC;
extern u16 D_0028E61C;
extern u16 D_0028E650;

void func_001AA0D0(void) {
    reg_d3.w = reg_d0.w;
    if (D_0028E650 == 0) {
        func_001AA1C0();
        return;
    }
    if (D_0028E61C == 0) {
        func_001AA210();
        return;
    }
    reg_d0.w = 1;
    if (D_0028E5FC == 0) {
        func_001AA2E0();
        return;
    }
    reg_d0.h[0] += D_0028E5D0;
    func_001AA2E0();
}
