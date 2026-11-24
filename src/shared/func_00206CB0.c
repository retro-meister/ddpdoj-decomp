#include "common.h"

s32 func_00206910();                            /* extern */
extern u16 D_0028E220;

void func_00206CB0(void) {
    reg_d0.h[0] = 8;
    reg_d0.h[0] = ~(s16) reg_d0.h[0];
    D_0028E220 &= reg_d0.h[0];
    func_00206910();
    reg_d0.h[0] = 8;
    D_0028E220 |= reg_d0.h[0];
    func_00206910();
}
