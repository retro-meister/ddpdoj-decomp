#include "common.h"

s32 func_00202D00();
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a1;

void func_00202C50(void) {
    s16 *temp_s0;

    reg_d0.h[0] = 0x7FFF;
    reg_a0 = (u8 *)(D_0029F260);
    reg_d1.h[0] = reg_d0.h[0];
    if (*(s16 *)reg_a0 < 0) {
        func_00202D00();
    }
    temp_s0 = (s16 *)(reg_a0);
    reg_a0 = (u8 *)(D_0029F1F0);
    if (*(s16 *)reg_a0 < 0) {
        reg_d1.h[0] = reg_d0.h[0];
        func_00202D00();
        reg_a1 = (u8 *)(reg_a0);
    }
    reg_a0 = (u8 *)(temp_s0);
    if ((s32) reg_d0.h[0] > (s32) reg_d1.h[0]) {
        reg_d0.h[0] = reg_d1.h[0];
        reg_a0 = (u8 *)(reg_a1);
    }
}
