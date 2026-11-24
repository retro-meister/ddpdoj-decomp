#include "common.h"

s32 func_002119A0();
extern u8 D_00251700[];
extern u32 D_0028E9A0;
extern u8 *reg_a0;
extern u8 *reg_a2;
extern u8 *reg_a6;

void func_00211E90(void) {
    D_0028E9A0 = reg_d0.w;
    (*(s8 *)((u8 *)(reg_a0) + (0x1E))) = 0x1F;
    reg_d3.h[0] = reg_d0.h[0];
    reg_d3.h[0] &= 0x3C;
    reg_a2 = *(u8 **)(D_00251700 + (reg_d3.h[0] & ~3));
    (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d3.w += reg_d2.w;
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) reg_d3.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) reg_d3.h[0];
    func_002119A0();
}
