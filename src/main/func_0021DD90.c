#include "common.h"

extern s32 func_00222530(s32);
extern s8 D_0028EB04;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s8 D_0028EB78;
extern s32 D_0028EB90;

void func_0021DD90(void)
{
    if (func_00222530(1) != 0) {
        s32 previousCount = *(volatile s8 *)&D_0028EB78;

        *(volatile s8 *)&D_0028EB58 = 1;
        *(volatile s32 *)&D_0028EB90 = 0x40;
        *(volatile s8 *)&D_0028EB54 = 1;
        *(volatile s8 *)&D_0028EB04 = 1;
        *(volatile s8 *)&D_0028EB78 = previousCount + 1;
        return;
    }
}
