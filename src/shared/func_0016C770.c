#include "common.h"

extern u8 D_0026B090[];
extern u16 D_0028E7B0;
extern u8 *reg_a0;
extern u8 *reg_a2;
extern u8 *reg_a6;

extern s8 D_0028E408;

void func_0016C770(void) {
    u32 save_d0;
    u32 save_d1;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] |= 0x8000;
    reg_a2 = *(u8 **)(D_0026B090 + (reg_d0.h[0] & ~3));
    *(u16 *)reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_a0 += 2;
    *(u16 *)reg_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    D_0028E408 = 0;
    reg_a2 += 2;
    reg_a0 += 2;
    D_0028E7B0 += 1;
}
