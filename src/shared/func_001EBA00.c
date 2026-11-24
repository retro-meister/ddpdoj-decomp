#include "common.h"

extern u16 D_00264390[];
extern u32 D_0028D9E4;
extern u16 *reg_a0_as_u16_p;
extern u16 *reg_a1_as_u16_p;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001EBA00(void) {
    reg_a0_as_u16_p = D_00264390;
    reg_a1_as_u16_p = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9E4 >> 1) - 1;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1E8)));
    (*(u16 *)((u8 *)(reg_a4) + (8))) += reg_d0.h[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1E7)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (4))) += reg_d0.b[0];
}
