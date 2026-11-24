#include "common.h"

extern s32 D_0028DDD8;
extern u16 D_0028ED10_as_u16;
extern s32 D_0057CC78[];

extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
extern void func_0022D240(s32);

void func_00233EE0(void)
{
    s32 displayValue = D_0028ED10_as_u16;
    s32 displayData = D_0028DDD8;

    func_0022C5E0(0x168, displayData, 0, 0x14, 0xE, displayValue, 0x64);
    if (D_0057CC78[0] & 0x20) {
        func_0022D240(2);
    }
}
