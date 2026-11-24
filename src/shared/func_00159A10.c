#include "common.h"

typedef void (*Fn)(void);
extern u8 *jtbl_0028E3F4;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u16 D_002586E0[];
extern u16 D_0028E48A;

void func_00159A10(void) {
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x2C);
    if (*(u16 *)(reg_a5 + 0x2C) != 2) {
        *(u16 *)(reg_a5 + 0x2C) += 1;
    }
    reg_d0.h[0] -= 1;
    reg_d0.h[0] <<= 2;
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x2A);
    reg_a0 = (u8 *)D_002586E0;
    reg_d1.h[0] <<= 3;
    reg_a0 += reg_d1.h[0];
    reg_a0 += reg_d0.h[0];
    D_0028E48A = *(u16 *)reg_a0;
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
    jtbl_0028E3F4 = (u8 *)reg_tmp.w;
    ((Fn)jtbl_0028E3F4)();
}
