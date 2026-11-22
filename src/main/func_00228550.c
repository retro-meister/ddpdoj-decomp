#include "common.h"

s32 func_002273B0(s32 *, s32);              /* extern */
extern s8 D_0028EB58;
extern s32 D_0028EC10;
extern s8 D_0028EC12;

void func_00228550(void) {
    if (func_002273B0(&D_0028EC10, 8) != 0) {
        D_0028EB58 = D_0028EC12;
    }
}
