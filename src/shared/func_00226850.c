#include "common.h"

s32 func_0022BC60();                                /* extern */
extern s8 D_0028EB04;
extern s32 D_0028EB90;
extern s8 D_0028EC3C;
extern s8 D_0028EC44;

void func_00226850(void) {
    if (func_0022BC60() != 0) {
        D_0028EC3C = 3;
        D_0028EC44 = 1;
        D_0028EB90 = 0x40;
        D_0028EB04 = 1;
    }
}
