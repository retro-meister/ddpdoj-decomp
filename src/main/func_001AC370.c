#include "common.h"

extern u16 D_0028E660;
extern u32 D_0028E668;
extern u32 D_0028E66C;
extern u16 D_0028E674;
extern u16 D_0028E688;
extern u32 D_0028E68C;
extern u32 D_0028E690;

void func_001AC370(void) {
    reg_d0.w = 0;
    D_0028E690 = reg_d0.w;
    D_0028E68C = reg_d0.w;
    D_0028E688 = reg_d0.h[0];
    D_0028E674 = reg_d0.h[0];
    D_0028E660 = reg_d0.h[0];
    D_0028E66C = reg_d0.w;
    D_0028E668 = reg_d0.w;
}
