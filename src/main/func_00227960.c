#include "common.h"

s32 func_002273B0(s32 *, s32);              /* extern */
extern s8 D_0028EB58;
extern s32 D_0028EBE8;
extern s8 D_0068DF02[];

void func_00227960(void) {
    if (func_002273B0(&D_0028EBE8, 0xA) != 0) {
        D_0028EB58 = D_0068DF02[0] + 1;
    }
}
