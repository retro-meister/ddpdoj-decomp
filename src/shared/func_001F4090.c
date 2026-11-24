#include "common.h"

s32 func_001F3A10();
s32 func_002010A0();
s32 func_00201C60();
s32 func_002024C0();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001F4090(void) {
    func_00201C60();
    if ((*(u8 *)((u8 *)(reg_a4) + (0))) != 0) {
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (1)));
        func_002024C0();
        if ((*(u8 *)((u8 *)(reg_a4) + (1))) == reg_d1.b[0]) {
            (*(u8 *)((u8 *)(reg_a4) + (0))) = 0U;
        }
    }
    func_002010A0();
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < MAIN_OR_DEATH_LABEL(0x3600, 0x4800)) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= MAIN_OR_DEATH_LABEL(0x5200, 0x5600)) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x5E00) {
        if ((s32) reg_d1.h[0] >= 0x6200) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        (*(u8 *)((u8 *)(reg_a4) + (1))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a4) + (0))) = 1U;
    }
    func_001F3A10();
}
