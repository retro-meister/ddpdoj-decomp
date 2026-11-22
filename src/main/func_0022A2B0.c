#include "common.h"

s32 func_00222530(s32);                         /* extern */
extern u8 D_0028EBD8;

void func_0022A2B0(void) {
    if (func_00222530(0xD) != 0) {
        D_0028EBD8 += 1;
    }
}
