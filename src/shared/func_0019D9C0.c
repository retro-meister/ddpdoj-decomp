#include "common.h"

extern s32 reg_a0_as_s32;
extern s32 reg_a1_as_s32;

extern void func_0019D960(void);
extern void func_0019B6E0(void);

void func_0019D9C0(void)
{
    s32 saved_a0;
    s32 saved_a1;
    u32 saved_d0;

    saved_d0 = reg_d0.w;
    saved_a0 = reg_a0_as_s32;
    saved_a1 = reg_a1_as_s32;
    func_0019D960();
    func_0019B6E0();
    reg_d0.w = saved_d0;
    reg_a0_as_s32 = saved_a0;
    reg_a1_as_s32 = saved_a1;
}
