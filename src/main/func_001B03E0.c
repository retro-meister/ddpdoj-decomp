#include "common.h"

extern u16 D_0028C138[];
extern u16 *reg_a0;
extern u8 *reg_a1;

void func_001B03E0(void) {
    reg_a0 = D_0028C138;
    (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) *reg_a0;
    reg_a0 += 1;
    (*(u16 *)((u8 *)(reg_a1) + (0x10))) = (u16) *reg_a0;
    reg_a0 += 1;
    reg_d0.h[0] = *reg_a0;
    reg_a0 += 1;
    (*(u16 *)((u8 *)(reg_a1) + (0x14))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a1) + (0x16))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a1) + (0x18))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a1) + (0x1A))) = (u16) reg_d0.h[0];
}
