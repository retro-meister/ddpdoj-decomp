#include "common.h"

s32 func_00201330();                            /* extern */

void func_00148800(void) {
    func_00201330();
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d0.h[0] += reg_d1.h[0];
    func_00201330();
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d2.h[0] += reg_d1.h[0];
}
