#include "common.h"

extern s32 func_00222530(s32);
extern volatile s8 D_0028EB04;
extern volatile s8 D_0028EB54;
extern volatile s8 D_0028EB58;
extern volatile s8 D_0028EB60;
extern volatile s32 D_0028EB90;

void func_0021F5B0(void)
{
    if (func_00222530(0x15) != 0) {
        s32 count;
        s32 enabled = 1;

        D_0028EB90 = 0x40;
        count = D_0028EB60;
        D_0028EB58 = 0;
        D_0028EB54 = enabled;
        D_0028EB04 = enabled;
        D_0028EB60 = (s8)(count + 1);
    }
}
