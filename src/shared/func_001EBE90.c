#include "common.h"

extern u16 D_002643C0[];
extern u32 D_0028D9E8;
extern u16 *reg_a0;
extern u16 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001EBE90(void) {
    reg_a0 = D_002643C0;
    reg_a1 = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9E8 >> 1) - 1;
    do {
        *reg_a1 = *reg_a0;
        reg_a0 += 1;
        reg_a1 += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1EC)));
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) += reg_d0.h[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1EB)));
    (*(u8 *)((u8 *)(reg_a4) + (8))) -= reg_d0.b[0];
}
