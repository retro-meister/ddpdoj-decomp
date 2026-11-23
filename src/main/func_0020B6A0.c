#include "common.h"

extern s16 D_0028E094;
extern u8 *reg_a4;
extern u8 *reg_a6;

extern s8 D_0028E408;

void func_0020B6A0(void) {
    u8 *temp_a2;

    D_0028E408 = 0;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0)));
    reg_a6 += 2;
    if (((s32) reg_d4.h[0] <= (s32) reg_d0.h[0]) && ((s32) reg_d1.h[0] <= (s32) reg_d4.h[0])) {
        reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0)));
        if (((s32) reg_d3.h[0] <= (s32) reg_d4.h[0]) && ((s32) reg_d4.h[0] <= (s32) reg_d2.h[0])) {
            reg_d4.w = 0x51;
            reg_d4.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (-3)));
            temp_a2 = (u8 *)(reg_a6 - 3);
            if (reg_d4.b[0] == 0) {
                reg_d4.w = 0x10;
                *temp_a2 |= reg_d4.b[0];
                (*(u8 *)((u8 *)(reg_a4) + (1))) |= reg_d4.b[0];
                D_0028E094 = 1;
                D_0028E408 = 1;
            }
        }
    }
}
