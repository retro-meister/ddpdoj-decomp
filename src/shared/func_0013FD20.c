#include "common.h"

extern u16 D_0028E5B8;
extern u16 D_0028E5C8;
extern u16 D_0028E5D0;
extern u16 D_0028E5DC;
extern u16 D_0028E5E4;
extern u16 D_0028E5EC;
extern u16 D_0028E5FC;
extern s32 D_002BAEF0[];

void func_0013FD20(void) {
    reg_d0.w = 0;
    D_002BAEF0[0] = 0;
    D_0028E5FC = reg_d0.h[0];
    D_0028E5EC = reg_d0.h[0];
    D_0028E5E4 = reg_d0.h[0];
    D_0028E5DC = reg_d0.h[0];
    D_0028E5D0 = reg_d0.h[0];
    D_0028E5C8 = reg_d0.h[0];
    D_0028E5B8 = reg_d0.h[0];
}
