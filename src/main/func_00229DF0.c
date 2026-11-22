#include "common.h"

s32 func_002273B0(s32 *, s32);              /* extern */
extern s8 D_0028EB58;
extern s32 D_0028EBF8;

void func_00229DF0(void) {
    if (func_002273B0(&D_0028EBF8, 0x13) != 0) {
        D_0028EB58 = 1;
    }
}
