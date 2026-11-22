#include "common.h"

extern u16 D_0028E5E0;
extern u8 D_0028ED80;

void func_001ACB50(void)
{
    if (D_0028ED80 != 0) {
        D_0028E5E0 += 0x258;
    } else {
        D_0028E5E0 += 0x258;
    }

    if ((s32)D_0028E5E0 >= 0x95F) {
        D_0028E5E0 = 0x95E;
    }
}
