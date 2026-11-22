#include "common.h"

extern u8 *reg_a6;

void func_00144CB0(void) {
    u16 temp_v1;

    reg_d0.h[0] = 4;
    temp_v1 = (*(u16 *)((u8 *)(reg_a6) + (0x4E)));
    if (temp_v1 != 0) {
        if (((s64) ((s64) temp_v1 << 0x30) >> 0x30) >= 0) {
            reg_d0.h[0] = 0xFFFC;
        }
        (*(u16 *)((u8 *)(reg_a6) + (0x4E))) += reg_d0.h[0];
    }
}
