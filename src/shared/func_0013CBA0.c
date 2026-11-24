#include "common.h"

extern u32 D_0028E40C;
extern u32 D_0028E410;
extern u32 D_0028E414;
extern u32 D_0028E428;
extern u8 *D_0028E42C;
extern u8 *D_0028E43C;
extern u8 *D_0028E440;
extern u16 *D_0028E444_as_u16_p;
extern u16 *reg_a0_as_u16_p;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a6;

void func_0013CBA0(void) {
    *reg_a2 &= 0x7F;
    reg_d0.w = 0;
    *reg_a0_as_u16_p = reg_d0.h[0];
    (*(u16 *)(reg_a1 + 0)) = reg_d0.h[0];
    (*(u16 *)(reg_a1 + 0x16)) = reg_d0.h[0];
    reg_d7.h[0] = 0x1F;
    do {
        *(u16 *)reg_a6 = reg_d0.h[0];
        reg_a6 += 0x30;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.w = D_0028E428;
    reg_d5.w = D_0028E414;
    reg_d6.w = D_0028E410;
    reg_d7.w = D_0028E40C;
    reg_a0_as_u16_p = D_0028E444_as_u16_p;
    reg_a1 = D_0028E440;
    reg_a2 = D_0028E43C;
    reg_a6 = D_0028E42C;
}
