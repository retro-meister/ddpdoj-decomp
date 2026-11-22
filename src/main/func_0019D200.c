#include "common.h"

extern u16 D_0028E180;
extern u8 *volatile reg_a0;
extern u8 D_002A6680[];

void func_0019D200(void) {
    u32 old_value;

    reg_a0 = D_002A6680;
    old_value = D_0028E180;
    reg_a0 += old_value;
    D_0028E180 = old_value + 0xC;
}
