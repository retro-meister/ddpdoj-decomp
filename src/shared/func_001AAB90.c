#include "common.h"

extern s32 D_0026C010[];
extern u8 D_0028E388;
extern u8 D_0028ED80;
extern u8 D_006E5C08[];
extern s32 *reg_a0;
extern u16 *reg_a1;
extern u8 *reg_a2;

void func_001AAB90(void)
{
    reg_d0.w = 0;
    reg_d0.b[0] = D_0028E388;
    if (D_0028ED80 != 0) {
        reg_d0.b[0] = D_006E5C08[0];
    }

    reg_a2 = (u8 *)D_0026C010;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    *reg_a0 = *(s32 *)(reg_a2 + reg_d0.h[0]);
    *reg_a1 = reg_d0.h[0];
}
