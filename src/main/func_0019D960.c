#include "common.h"
extern u16 D_0028E144;
extern u8 *volatile D_0028E468;
extern u8 D_002A3F70[];
void func_0019D960(void) {
    s32 step; D_0028E468 = D_002A3F70; step = D_0028E144; D_0028E468 += step; D_0028E144 = step + 0xC;
}
