#include "common.h"

typedef void (*Fn)(void);
extern u8 *jtbl_0028E3F4;
extern u8 *reg_a0;
extern u8 *reg_a6;
extern u16 D_0025AE70[];
extern u16 D_0028E48A;

void func_00170BE0(void) {
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x1E);
    reg_a0 = (u8 *)D_0025AE70;
    reg_d0.h[0] <<= 2;
    D_0028E48A = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)reg_tmp.w;
    jtbl_0028E3F4 = reg_a0;
    ((Fn)jtbl_0028E3F4)();
}
