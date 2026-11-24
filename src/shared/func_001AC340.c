#include "common.h"

extern u16 D_0028E6A0;
extern u32 D_0028E6A8;
extern u32 D_0028E6AC;
extern u16 D_0028E6B4;
extern u16 D_0028E6C8;
extern u32 D_0028E6CC;
extern u32 D_0028E6D0;

void func_001AC340(void) {
    reg_d0.w = 0;
    D_0028E6D0 = reg_d0.w;
    D_0028E6CC = reg_d0.w;
    D_0028E6C8 = reg_d0.h[0];
    D_0028E6B4 = reg_d0.h[0];
    D_0028E6A0 = reg_d0.h[0];
    D_0028E6AC = reg_d0.w;
    D_0028E6A8 = reg_d0.w;
}
