#include "common.h"

extern u16 D_002647A0[];
extern u32 D_0028DA10;
extern u16 *reg_a0_as_u16_p;
extern u16 *reg_a1_as_u16_p;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001EF9A0(void) {
    reg_a0_as_u16_p = D_002647A0;
    reg_a1_as_u16_p = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028DA10 >> 1) - 1;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x13E)));
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (0x12))) += reg_d0.h[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1D7)));
    (*(u8 *)((u8 *)(reg_a4) + (7))) += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (6))) += reg_d0.b[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1D6)));
    (*(u8 *)((u8 *)(reg_a4) + (8))) -= reg_d0.b[0];
#ifndef DEATH_LABEL
    (*(u8 *)((u8 *)(reg_a4) + (3))) += 2;
#endif
}
