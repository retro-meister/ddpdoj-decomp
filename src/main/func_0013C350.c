#include "common.h"

extern u8 *reg_a0;

extern s8 D_0028E408;

void func_0013C350(void) {
    u32 temp_d0;
    u32 temp_d1;
    u8 *temp_a0;

    temp_d0 = reg_d0.w;
    temp_d1 = reg_d1.w;
    temp_a0 = reg_a0;
    reg_a0 = (u8 *)reg_d0.w;
    reg_d1.w = 0;
    reg_d0.h[1] = (*(u16 *)(reg_a0 + 0x2C));
    reg_d0.h[0] = (*(u16 *)(reg_a0 + 0x2E));
    if (reg_d0.w != 0) {
        do {
            reg_a0 = (u8 *)reg_d0.w;
            reg_d1.h[0] += (*(u16 *)(reg_a0 + 0x18));
            reg_d0.h[1] = (*(u16 *)(reg_a0 + 0x2C));
            reg_d0.h[0] = (*(u16 *)(reg_a0 + 0x2E));
        } while (reg_d0.w != 0);
        reg_d0.h[0] = reg_d1.h[0];
    }
    if (reg_d0.h[0] != 0) {
        D_0028E408 = 1;
    } else {
        D_0028E408 = 0;
    }
    reg_d0.w = temp_d0;
    reg_d1.w = temp_d1;
    reg_a0 = temp_a0;
}
