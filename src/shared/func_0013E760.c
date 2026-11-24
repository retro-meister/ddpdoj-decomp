#include "common.h"

s32 func_001AC3A0(u16);
extern s16 D_0028E8C4_as_s16;

void func_0013E760(void) {
    u16 temp_a0;

    temp_a0 = D_0028E8C4_as_s16;
    if (temp_a0 != 0x14) {
        D_0028E8C4_as_s16 = temp_a0 + 1;
        func_001AC3A0(temp_a0);
    }
}
