#include "common.h"

s32 func_00226410();                            /* extern */
s32 func_00233DA0();                                /* extern */
extern s8 D_0028EC3C;

void func_00226490(void) {
    if (func_00233DA0() == 0) {
        func_00226410();
        return;
    }
    D_0028EC3C = 4;
}
