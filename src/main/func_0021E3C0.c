#include "common.h"
#pragma opt_propagation off

extern s32 func_00222530(s32);
extern s8 D_0028EB04;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s8 D_0028EB74;
extern s32 D_0028EB90;

void func_0021E3C0(void)
{
    if (func_00222530(2) != 0) {
        s32 count = D_0028EB74;

        D_0028EB58 = 1;
        D_0028EB90 = 0x40;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        D_0028EB74 = count + 1;
    }
}
