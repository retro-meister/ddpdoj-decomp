#include "common.h"

s32 func_00227350(s8 *, s32);                   /* extern */
extern s8 D_0028EB58;
extern s8 D_0028EC18;

void func_00227680(void) {
    if (func_00227350(&D_0028EC18, 7) != 0) {
        D_0028EB58 = 1;
        D_0028EC18 = 2;
    }
}
