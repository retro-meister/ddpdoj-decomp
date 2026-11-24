#include "common.h"

s32 func_00233DA0();                                /* extern */
extern s8 D_0028EB04;
extern s32 D_0028EB90;
extern s8 D_0028EC3C;
extern s8 D_0028EC44;

void func_00226450(void) {
    if (func_00233DA0() != 0) {
        D_0028EC3C = 3;
        D_0028EC44 = 1;
        D_0028EB90 = 0x40;
        D_0028EB04 = 1;
    }
}
