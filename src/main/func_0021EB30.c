#include "common.h"

extern s32 func_00222530(s32);
extern volatile s8 D_0028EB04;
extern volatile s8 D_0028EB54;
extern volatile s8 D_0028EB58;
extern volatile s8 D_0028EB6C;
extern volatile s32 D_0028EB90;

void func_0021EB30(void)
{
    if (func_00222530(0xE) != 0) {
        s32 previousCount = D_0028EB6C;

        D_0028EB58 = 1;
        D_0028EB90 = 0x40;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        D_0028EB6C = previousCount + 1;
        return;
    }
}
