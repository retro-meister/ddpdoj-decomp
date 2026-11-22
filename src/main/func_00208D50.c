#include "common.h"

s32 func_00131420();                            /* extern */
s32 func_0016A8B0();                            /* extern */
s32 func_0016A8D0();                            /* extern */
s32 func_00208D30();                            /* extern */
s32 func_002093F0(u32);                         /* extern */

void func_00208D50(void) {
    u32 temp_a0;

    func_00208D30();
    func_0016A8D0();
    if (reg_d0.w & 0x20) {
        func_00131420();
    }
    func_0016A8B0();
    temp_a0 = reg_d0.w;
    if ((temp_a0 & 0x8000) && (temp_a0 & 0x10)) {
        reg_d0.w = 0;
        func_002093F0(temp_a0);
    }
    reg_d0.w = 0;
}
