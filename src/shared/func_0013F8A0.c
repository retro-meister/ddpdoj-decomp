#include "common.h"

extern u32 D_0028E428;
extern void *D_0028E43C_as_void_p;
extern u16 *D_0028E440_as_u16_p;
extern u16 *D_0028E444_as_u16_p;
extern u16 *reg_a0_as_u16_p;
extern u16 *reg_a1_as_u16_p;
extern u8 *reg_a2;

void func_0013F8A0(void) {
    reg_d0.w = 0xF;
    do {
        *reg_a0_as_u16_p = (*(u16 *)((u8 *)(reg_a2) + (2)));
        reg_a0_as_u16_p += 1;
        *reg_a0_as_u16_p = (*(u16 *)((u8 *)(reg_a2) + (4)));
        reg_a0_as_u16_p += 1;
        *reg_a1_as_u16_p = (*(u16 *)((u8 *)(reg_a2) + (0xA)));
        reg_a1_as_u16_p += 1;
        *reg_a1_as_u16_p = (*(u16 *)((u8 *)(reg_a2) + (0xC)));
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.w = D_0028E428;
    reg_a0_as_u16_p = D_0028E444_as_u16_p;
    reg_a1_as_u16_p = D_0028E440_as_u16_p;
    reg_a2 = D_0028E43C_as_void_p;
}
