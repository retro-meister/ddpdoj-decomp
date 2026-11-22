#include "common.h"

extern u16 D_0028E144;
extern u8 *D_0028E468;
extern u8 D_002A3F70[];

void func_0019D960(void) {
    u16 currentOffset;

    D_0028E468 = D_002A3F70;
    currentOffset = D_0028E144;
    D_0028E144 = currentOffset + 0xC;
    D_0028E468 += currentOffset;
}
