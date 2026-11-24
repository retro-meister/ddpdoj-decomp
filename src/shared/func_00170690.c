#include "common.h"

extern u8 D_0025B870[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00170690(void) {
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1A);
    reg_a0 = D_0025B870;
    reg_a0 += reg_d0.h[0];
    *(u16 *)(reg_a6 + 0xA) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0xC) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a5 + 0x18) = *(u16 *)reg_a0;
    reg_a0 += 2;
}
