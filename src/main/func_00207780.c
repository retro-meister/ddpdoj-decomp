#include "common.h"

s32 func_0016A8B0();                            /* extern */
s32 func_0019C430();                            /* extern */
s32 func_002093F0(u32);                         /* extern */

void func_00207780(void) {
    u32 temp_a0;

    reg_d2.w = 0xC2F;
    reg_d1.w = 0;
    reg_d3.h[0] = 0x38E0;
    reg_d4.h[0] = 0;
    func_0019C430();
    func_0016A8B0();
    temp_a0 = reg_d0.w;
    if ((temp_a0 & 0x8000) && (temp_a0 & 0x10)) {
        reg_d0.w = 0;
        func_002093F0(temp_a0);
    }
    reg_d0.w = 0;
}
