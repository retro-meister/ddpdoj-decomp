#include "common.h"

extern s32 D_002BF390_as_s32_a[];
extern s32 D_002BF3B4_as_s32_a[];
extern s32 *reg_a0_as_s32_p;

void func_001353E0(void) {
    reg_a0_as_s32_p = D_002BF390_as_s32_a;
    if (reg_d0.h[0] != 0) {
        reg_a0_as_s32_p = D_002BF3B4_as_s32_a;
    }
    (*(u16 *)((u8 *)(reg_a0_as_s32_p) + (0))) = (u16) reg_d1.h[0];
    (*(s16 *)((u8 *)(reg_a0_as_s32_p) + (2))) = 0;
}
