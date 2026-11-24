#include "common.h"

s32 func_0013EA90();                            /* extern */
s32 func_001AAA20();                            /* extern */
s32 func_001ABD80();                            /* extern */
extern s16 D_0028E588_as_s16;
extern u16 D_0028E5C4;
extern u16 D_0028E5CC;
extern u16 D_0028E5F0;
extern u16 D_0028E5F8;

void func_001A8070(void) {
    if (D_0028E5F8 != 0) {
        D_0028E588_as_s16 = 0x48;
    }
    func_0013EA90();
    reg_d0.w = 0;
    D_0028E5F8 = reg_d0.h[0];
    D_0028E5F0 = reg_d0.h[0];
    D_0028E5CC = reg_d0.h[0];
    D_0028E5C4 = reg_d0.h[0];
    func_001AAA20();
    func_001ABD80();
}
