#include "common.h"

extern s32 func_00222530(s32);
extern s8 D_0028EB04;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s8 D_0028EB5C;
extern s32 D_0028EB90;

void func_0021F880(void) {
    if (func_00222530(0x18) != 0) {
        D_0028EB58 = 0;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        D_0028EB90 = 0x40;
        D_0028EB5C++;
    }
}
