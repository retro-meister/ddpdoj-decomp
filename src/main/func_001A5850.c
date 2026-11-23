#include "common.h"

extern void func_0011C4A0(void);
extern u16 D_0028DB00[];
extern u16 D_0029F248[];
extern u8 *reg_a0;

void func_001A5850(void) {
    if ((s16)reg_d7.h[0] >= 0) {
        reg_d2.h[0] = 1;
        reg_a0 = (u8 *)D_0028DB00;
        reg_d4.h[0] = D_0029F248[0];
        reg_d4.h[0] += reg_d4.h[0];
        reg_d3.h[0] = 0;
        reg_d4.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d4.h[0] = ((reg_d4.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)(reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d5.h[0] = reg_d1.h[0];
        do {
            func_0011C4A0();
            reg_d1.h[0] -= 0x100;
        } while ((s16)--reg_d7.h[0] >= 0);
        reg_d1.h[0] = reg_d5.h[0];
    }
}
