#include "common.h"

s32 func_002273B0(s32 *, s32);              /* extern */
extern s8 D_0028EB58;
extern s32 D_0028EC00;

void func_00228E50(void) {
    if (func_002273B0(&D_0028EC00, 0x12) != 0) {
        D_0028EB58 = 1;
    }
}
