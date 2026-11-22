#include "common.h"

extern u16 D_0028E6A0;
extern u32 D_0028E6A8;
extern u32 D_0028E6AC;
extern u16 D_0028E6B4;
extern u16 D_0028E6C8;
extern u32 D_0028E6CC;
extern u32 D_0028E6D0;

void func_001AC340(void) {
    work_reg_0.w = 0;
    D_0028E6D0 = work_reg_0.w;
    D_0028E6CC = work_reg_0.w;
    D_0028E6C8 = work_reg_0.h[0];
    D_0028E6B4 = work_reg_0.h[0];
    D_0028E6A0 = work_reg_0.h[0];
    D_0028E6AC = work_reg_0.w;
    D_0028E6A8 = work_reg_0.w;
}
