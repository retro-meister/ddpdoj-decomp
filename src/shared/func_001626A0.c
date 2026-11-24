#include "common.h"

s32 func_00161CC0();                            /* extern */
extern s8 D_0025A518[];
extern u16 D_0028E918;
extern s8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001626A0(void) {
    func_00161CC0();
    reg_a0 = D_0025A518;
    reg_d0.h[0] = D_0028E918;
    reg_a0 = &reg_a0[reg_d0.h[0]];
    (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = (s8) *reg_a0;
    (*(s8 *)((u8 *)(reg_a5) + (0x1D))) = (s8) *reg_a0;
    reg_a0 += 1;
    (*(s8 *)((u8 *)(reg_a5) + (0x1C))) = (s8) *reg_a0;
    reg_a0 += 1;
}
