#include "common.h"

extern u8 D_0028E1C0[];
extern u8 D_0028E1C8[];
extern u8 *reg_a0;

void func_00130720(void) {
    reg_a0 = D_0028E1C8;
    reg_d0.w = 1;
    do {
        (*(s8 *)((u8 *)(reg_a0) + (1))) = 0;
        (*(s8 *)((u8 *)(reg_a0) + (0))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (2))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (4))) = 0;
        reg_a0 = D_0028E1C0;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}
