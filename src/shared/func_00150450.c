#include "common.h"

s32 func_00137C10();                            /* extern */
s32 func_0016A8E0();                            /* extern */
s32 func_0019BE80();                            /* extern */
s32 func_001B82F0();                            /* extern */
s32 func_00203670();                            /* extern */
extern u8 *reg_a5;

void func_00150450(void) {
    s64 temp_v0_2;
    u16 temp_v0;

    func_00203670();
    temp_v0 = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    if (temp_v0 != 0) {
        (*(u16 *)((u8 *)(reg_a5) + (0x18))) = (u16) (temp_v0 - 1);
    } else {
        func_0016A8E0();
        if (reg_d0.w != 6) {
            func_00137C10();
            temp_v0_2 = (s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30;
            if ((temp_v0_2 < 5) && (temp_v0_2 >= 0)) {
                reg_d0.h[0] *= 4;
                reg_d0.h[0] <<= 8;
                reg_d0.w = (u32) reg_d0.h[0];
                reg_d0.w |= 0x20000;
                func_001B82F0();
            }
        }
    }
    func_0019BE80();
}
