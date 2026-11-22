#include "common.h"

extern s16 D_0028E320;
extern s8 D_0028EB14;
extern s8 D_0028EB38;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s8 D_0028EB68;

void func_0021F180(void)
{
    if (D_0028EB38 == 0) {
        s8 savedState = *(volatile s8 *)&D_0028EB14;

        *(volatile s8 *)&D_0028EB68 = 2;
        *(volatile s8 *)&D_0028EB54 = 1;
        *(volatile s16 *)&D_0028E320 = 0xE10;
        *(volatile s8 *)&D_0028EB58 = savedState;
        return;
    }
}
