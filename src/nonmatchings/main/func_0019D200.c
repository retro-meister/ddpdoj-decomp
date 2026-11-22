#include "common.h"

extern u16 D_0028E180;
extern u8 *volatile D_0028E468;
extern u8 D_002A6680[];

void func_0019D200(void) {
    u32 old_value;

    old_value = D_0028E180;
    D_0028E468 = D_002A6680;
    D_0028E468 += old_value;
    D_0028E180 = old_value + 0xC;
}
