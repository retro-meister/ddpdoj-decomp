#include "common.h"

extern u16 D_0028E1A0;
extern u16 D_002AF860[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;

extern s8 D_0028E408;

void func_0019B510(void) {
    D_0028E408 = 0;
    reg_d0.h[0] = *(u16 *)reg_a1;
    switch (reg_d0.h[0]) {
    case 0:
        goto block_rts;
    default:
        reg_a2 = (u8 *)D_002AF860;
        reg_a2 += D_0028E1A0;
loop_1:
        *(u16 *)reg_a2 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a2 += 2;
        *(u16 *)reg_a2 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a2 += 2;
        *(u16 *)reg_a2 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a2 += 2;
        *(u16 *)reg_a2 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a2 += 2;
        *(u16 *)reg_a2 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a2 += 2;
        *(u16 *)reg_a2 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a2 += 2;
        *(u16 *)reg_a2 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a2 += 2;
        *(u16 *)reg_a2 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a2 += 2;
        D_0028E1A0 += 0xC;
        if (D_0028E1A0 != 0x1758) {
            reg_d0.h[0] -= 0xC;
            if (reg_d0.h[0] != 0) goto loop_1;
            *(u16 *)reg_a1 = reg_d0.h[0];
block_rts:
            return;
        } else {
            *(u16 *)reg_a1 = 0;
            D_0028E408 = 1;
        }
        break;
    }
}
