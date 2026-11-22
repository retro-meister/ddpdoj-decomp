#include "common.h"

extern u16 D_0028E5E4;
extern u8 D_0028ED80;

void func_001ACB00(void)
{
    if (D_0028ED80 != 0) {
        D_0028E5E4 += 0x258;
    } else {
        D_0028E5E4 += 0x258;
    }

    if ((s32)D_0028E5E4 >= 0x95F) {
        D_0028E5E4 = 0x95E;
    }
}
