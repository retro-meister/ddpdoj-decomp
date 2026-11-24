#include "common.h"

extern void func_0020E020(void);
extern u16 D_0028E0A8;
extern u16 D_0028E5A8;
extern u16 D_0028E5AC;
extern s16 *reg_a4_as_s16_p;

void func_0020BD10(void)
{
    D_0028E0A8 = reg_d0.h[0];
    D_0028E5AC = reg_d1.h[0];
    reg_d7.h[0] = 0x2800;
    D_0028E5A8 = reg_d2.h[0];

    if (*reg_a4_as_s16_p < 0) {
        func_0020E020();
    }
}
