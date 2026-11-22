#include "common.h"

s32 func_00124D90();                            /* extern */
s32 func_00124DC0();                            /* extern */
s32 func_001A3020();                            /* extern */
s32 func_001E5BE0();                            /* extern */
extern s32 D_0025FF30[];
extern s32 *reg_a0;

void func_001E5B90(void) {
    reg_d0.h[0] = 0x15;
    reg_a0 = D_0025FF30;
    func_001A3020();
    reg_d0.w = 0;
    func_00124D90();
    reg_d0.w = 0xA;
    func_00124DC0();
    func_001E5BE0();
}
