#include "common.h"

s32 func_001AC5F0(u16);
extern s16 D_0028E8C0;

void func_0013E790(void) {
    u16 temp_a0;

    temp_a0 = D_0028E8C0;
    if (temp_a0 != 0x14) {
        D_0028E8C0 = temp_a0 + 1;
        func_001AC5F0(temp_a0);
    }
}
