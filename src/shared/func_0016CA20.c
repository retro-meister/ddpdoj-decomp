#include "common.h"

extern u8 D_0026B090[];
extern u16 D_0028E7AC;
extern u16 D_0028E7B0;
extern u8 *reg_a0;
extern u8 *reg_a2;

void func_0016CA20(void) {
    reg_a2 = (u8 *)D_0026B090;
    reg_d1.h[0] = reg_d0.h[0];
    reg_a2 = *(u8 **)(D_0026B090 + (reg_d0.h[0] & ~3));
    reg_d1.h[0] |= 0x8000;
    *(u16 *)reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d6.h[0];
    reg_a0 += 2;
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
    *(u16 *)reg_a0 = 0xFFFF;
    reg_a0 += 2;
    reg_a2 += 2;
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
    *(u16 *)reg_a0 = (u16) D_0028E7AC;
    reg_a0 += 2;
    D_0028E7B0 += 1;
    D_0028E7AC += 0xC;
    if (D_0028E7AC == 0x9C) {
        D_0028E7AC = 0;
    } else if (D_0028E7AC == 0xA2) {
        D_0028E7AC = 6;
    }
}
