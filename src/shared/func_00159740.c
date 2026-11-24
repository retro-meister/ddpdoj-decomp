#include "common.h"

s32 func_001597C0();
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_00159740(void) {
    (*(s8 *)((u8 *)(reg_a6) + (0x47))) = 1;
    reg_d7.w = 5;
    reg_a0 = reg_a6 + 0x66;
    do {
        (*(s16 *)((u8 *)(reg_a0) + (0))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (2))) = 4;
        reg_a0 += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    (*(s16 *)((u8 *)(reg_a6) + (0x48))) = 8;
    (*(s16 *)((u8 *)(reg_a6) + (0x4A))) = 0;
    func_001597C0();
}
