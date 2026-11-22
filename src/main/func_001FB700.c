#include "common.h"

s32 func_001FB770(s64, u16);                    /* extern */
s32 func_001FBD90(s64, u16);                    /* extern */
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001FB700(void) {
    s64 temp_a0;

    reg_a4 = reg_a6 + 0x8A;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x86)));
    temp_a0 = (s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30;
    if (temp_a0 != -1) {
        if (!(reg_d0.h[0] & 0xFFFF)) {
            func_001FB770(temp_a0, reg_d0.h[0]);
            return;
        }
        func_001FBD90(temp_a0, reg_d0.h[0]);
    }
}
