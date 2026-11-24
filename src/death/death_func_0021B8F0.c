#include "common.h"

s32 func_002011A0();
extern u16 D_00264550[];
extern u32 D_0028D9F4;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void death_func_0021B8F0(void) {
    s32 sum;

    reg_a0 = (u8 *) D_00264550;
    reg_a1 = reg_a4 + 2;
    reg_d0.w = ((u32) D_0028D9F4 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x10);
    sum = *(u8 *)(reg_a4 + 5) + reg_d0.b[0];
    if (sum >= 0xFF) {
        *(u8 *)(reg_a4 + 5) = 0xFF;
        *(u8 *)(reg_a4 + 4) = 0xFF;
    } else {
        *(u8 *)(reg_a4 + 5) = sum;
        *(u8 *)(reg_a4 + 4) += reg_d0.b[0];
    }
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x12);
    *(u16 *)(reg_a4 + 8) += reg_d0.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x14);
    *(u16 *)(reg_a4 + 0xC) += reg_d0.h[0];
    func_002011A0();
    *(u8 *)(reg_a4 + 0x10) = reg_d0.b[0];
    if (*(u8 *)(reg_a6 + 0x11) == 0) {
        *(u8 *)(reg_a4 + 0x11) *= -1;
    }
}
