#include "common.h"

s32 func_00125FF0();                            /* extern */
extern u16 D_0028E988;
extern u16 D_0029C06C[];
extern s32 D_002BF4F0[];
extern s32 *reg_a6;

void func_00125FA0(void) {
    reg_d7.h[0] = D_0028E988;
    if (reg_d7.h[0] != 0) {
        reg_a6 = D_002BF4F0;
        reg_d7.w -= 1;
        reg_d6.h[0] = D_0029C06C[0];
        func_00125FF0();
    }
}
