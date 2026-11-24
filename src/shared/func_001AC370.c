#include "common.h"

extern u16 D_0028E660;
extern u32 D_0028E668_as_u32;
extern u32 D_0028E66C_as_u32;
extern u16 D_0028E674;
extern u16 D_0028E688;
extern u32 D_0028E68C_as_u32;
extern u32 D_0028E690_as_u32;

void func_001AC370(void) {
    reg_d0.w = 0;
    D_0028E690_as_u32 = reg_d0.w;
    D_0028E68C_as_u32 = reg_d0.w;
    D_0028E688 = reg_d0.h[0];
    D_0028E674 = reg_d0.h[0];
    D_0028E660 = reg_d0.h[0];
    D_0028E66C_as_u32 = reg_d0.w;
    D_0028E668_as_u32 = reg_d0.w;
}
