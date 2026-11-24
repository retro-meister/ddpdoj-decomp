#include "common.h"

s32 func_002010A0();
extern u16 D_0029C06C[];
extern u8 *reg_a6;

void func_0016C410() {
    s16 temp_a0;

    reg_d1.h[0] = D_0029C06C[0];
    temp_a0 = (*(s16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = (s16) reg_d1.h[0] + temp_a0;
    (*(s8 *)((u8 *)(reg_a6) + (0x1A))) = 0x30;
    if ((s32) reg_d1.h[0] < 0x1C00) {
        (*(s8 *)((u8 *)(reg_a6) + (0x1A))) = 0x10;
    }
    func_002010A0();
    if (((s64) ((s64) reg_d0.b[0] << 0x38) >> 0x38) < 0) {
        reg_d0.b[0] *= -1;
    }
    reg_d0.h[0] &= 6;
    reg_d0.h[0] += 7;
    (*(u8 *)((u8 *)(reg_a6) + (0x1B))) = (u8) reg_d0.b[0];
}
