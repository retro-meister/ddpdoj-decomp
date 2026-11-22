#include "common.h"

extern u16 D_0028E17C;
extern u8 *D_0028E468;
extern u8 D_002A6630[];

void func_0019D330(void) {
    u32 offset = D_0028E17C;

    D_0028E468 = D_002A6630;
    D_0028E468 += offset;
    D_0028E17C = offset + 0xC;
}
