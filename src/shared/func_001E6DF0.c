#include "common.h"

extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

extern u8 D_0026C0A0[];

void func_001E6DF0(void) {
    reg_tmp.b[0] = (*(u8 *)(reg_a4 + 3));
    (*(u8 *)(reg_a4 + 3)) -= 1;
    if ((s32)reg_tmp.b[0] <= 0) {
        (*(u8 *)(reg_a4 + 3)) = (*(u8 *)(reg_a4 + 2));
        reg_a0 = D_0026C0A0;
        reg_a0 += (*(u16 *)(reg_a4 + 4));
        (*(u16 *)(reg_a6 + 6)) = *(u16 *)reg_a0;
        (*(u16 *)(reg_a4 + 4)) += 2;
        if ((*(u16 *)(reg_a4 + 4)) == 0xC) {
            (*(u16 *)(reg_a4 + 4)) = 0;
        }
    }
}
