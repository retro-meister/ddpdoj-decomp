#include "common.h"

s32 func_001A8520();                            /* extern */
extern s16 D_0028E8C0_as_s16;

void func_001A59B0(void) {
    if (D_0028E8C0_as_s16 >= 0) {
        reg_d6.w = 0x12;
        reg_d6.h[0] -= 0x32;
        reg_d6.h[0] <<= 7;
        func_001A8520();
    }
}
