#include "common.h"

extern s8 D_0028E408;
extern u16 D_0028E7B0;
extern u8 *reg_a6;

void func_0016C260(void) {
    reg_d0.w = 0;
    (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d0.h[0];
    D_0028E408 = 1;
    D_0028E7B0 -= 1;
}
