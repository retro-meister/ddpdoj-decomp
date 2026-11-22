#include "common.h"

extern u16 D_0028DFC0;
extern void func_0019DBB0(u32 originalD1);

void func_001AB8D0(void)
{
    u32 originalD1;

    if (D_0028DFC0 == 0) {
        originalD1 = reg_d1.w;
        reg_d1.w = originalD1 + 0xF200F600u;
        reg_d3.h[0] = 0xE50;
        reg_d4.h[0] = 4;
        func_0019DBB0(originalD1);
        return;
    }
}
