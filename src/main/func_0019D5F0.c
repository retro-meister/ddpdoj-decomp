#include "common.h"

extern u16 D_0028E15C;
extern u8 *D_0028E468;
extern u8 D_002A5050[];

void func_0019D5F0(void) {
    u32 offset;

    D_0028E468 = D_002A5050;
    offset = D_0028E15C;
    D_0028E468 += offset;
    D_0028E15C = offset + 0xC;
}
