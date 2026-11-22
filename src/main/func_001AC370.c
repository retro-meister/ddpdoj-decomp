#include "common.h"

extern u16 D_0028E660;
extern u32 D_0028E668;
extern u32 D_0028E66C;
extern u16 D_0028E674;
extern u16 D_0028E688;
extern u32 D_0028E68C;
extern u32 D_0028E690;

void func_001AC370(void) {
    work_reg_0.w = 0;
    D_0028E690 = work_reg_0.w;
    D_0028E68C = work_reg_0.w;
    D_0028E688 = work_reg_0.h[0];
    D_0028E674 = work_reg_0.h[0];
    D_0028E660 = work_reg_0.h[0];
    D_0028E66C = work_reg_0.w;
    D_0028E668 = work_reg_0.w;
}
