#include "common.h"

s32 func_002365A0();                                /* extern */
extern u8 D_0028EBE8;

void func_00227930(void) {
    if (func_002365A0() != 0) {
        D_0028EBE8 += 1;
    }
}
