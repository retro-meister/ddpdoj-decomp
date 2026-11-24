#include "common.h"

extern s32 D_002BF390[];
extern s32 D_002BF3B4[];
extern s32 *reg_a0;

void func_001353E0(void) {
    reg_a0 = D_002BF390;
    if (reg_d0.h[0] != 0) {
        reg_a0 = D_002BF3B4;
    }
    (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) reg_d1.h[0];
    (*(s16 *)((u8 *)(reg_a0) + (2))) = 0;
}
