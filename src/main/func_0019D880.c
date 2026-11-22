#include "common.h"

extern u16 D_0028E148;
extern u8 *D_0028E468;
extern u8 D_002A3CB0[];

void func_0019D880(void) {
    u32 temp;

    D_0028E468 = D_002A3CB0;
    temp = D_0028E148;
    D_0028E468 += temp;
    D_0028E148 = temp + 0xC;
}
