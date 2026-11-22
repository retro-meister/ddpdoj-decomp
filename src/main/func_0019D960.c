#include "common.h"
extern u16 D_0028E144;
extern u8 *volatile reg_a0;
extern u8 D_002A3F70[];
void func_0019D960(void) {
    s32 step; reg_a0 = D_002A3F70; step = D_0028E144; reg_a0 += step; D_0028E144 = step + 0xC;
}
