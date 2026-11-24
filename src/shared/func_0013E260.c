#include "common.h"

extern void func_00200EE0(void);
extern u16 D_0029CD90[];
extern u32 D_0029CD94_as_u32_a[];
extern u32 D_0029CD98[];
extern u16 D_0029CD9C[];
extern u16 D_0029CD9E[];

void func_0013E260(void)
{
    reg_d0.h[0] = D_0029CD90[0];
    reg_d5.h[0] = reg_d0.h[0];
    func_00200EE0();

    D_0029CD94_as_u32_a[0] = reg_d2.w;
    reg_d5.h[0] >>= 1;
    reg_d0.h[0] = reg_d5.h[0];
    func_00200EE0();

    D_0029CD98[0] = reg_d2.w;
    reg_d0.h[0] = D_0029CD9C[0];
    func_00200EE0();

    D_0029CD9E[0] = reg_d2.h[0];
}
