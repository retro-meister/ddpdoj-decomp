#include "common.h"
#pragma opt_propagation off

extern s32 func_00222530(s32);
extern s8 D_0028EB04;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s8 D_0028EB78;
extern s32 D_0028EB90;

void func_0021DD90(void)
{
    if (func_00222530(1) != 0) {
        s32 previousCount = D_0028EB78;

        D_0028EB58 = 1;
        D_0028EB90 = 0x40;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        D_0028EB78 = previousCount + 1;
        return;
    }
}
