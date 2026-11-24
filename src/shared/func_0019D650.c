#include "common.h"

extern s32 reg_a0;
extern s32 reg_a1;
extern void func_0019D5F0(void);
extern void func_0019B6E0(void);

void func_0019D650(void)
{
    s32 saved_a0;
    s32 saved_a1;
    u32 saved_d0;

    saved_d0 = reg_d0.w;
    saved_a0 = reg_a0;
    saved_a1 = reg_a1;

    func_0019D5F0();
    func_0019B6E0();

    reg_d0.w = saved_d0;
    reg_a0 = saved_a0;
    reg_a1 = saved_a1;
}
