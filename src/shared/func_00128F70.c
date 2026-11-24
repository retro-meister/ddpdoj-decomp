#include "common.h"

typedef void (*Fn)();

extern s8 D_0028E408;
extern u8 D_0024E740[];
extern u32 D_0028DEA4;
extern u32 D_0028DEA8;
extern u8 *D_0028DEB0_as_u8_p;
extern u8 *D_0028DEB4_as_u8_p;
extern Reg32 D_0028E47C_as_Reg32;
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a1;

void func_00128F70(void) {
    if (reg_d3.w == 0) {
        goto next_1;
    }
    *(u16 *) (reg_a0 - 0xC) += reg_d3.h[0];
    D_0028E47C_as_Reg32.w = reg_d3.w;
    reg_d3.h[1] = D_0028E47C_as_Reg32.h[0];
    reg_d3.h[0] = D_0028E47C_as_Reg32.h[1];
    *(u16 *) (reg_a0 - 0xE) += reg_d3.h[0];
    D_0028E47C_as_Reg32.w = reg_d3.w;
    reg_d3.h[1] = D_0028E47C_as_Reg32.h[0];
    reg_d3.h[0] = D_0028E47C_as_Reg32.h[1];
next_1:
    if (*(s16 *) reg_a1 == 0) {
        goto next_2;
    }
    reg_a1 = (u8 *)D_0024E740;
    reg_a1 += reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *) reg_a1;
    reg_tmp.h[0] = *(u16 *) (reg_a1 + 2);
    reg_a1 = (u8 *) reg_tmp.w;
    jtbl_0028E3F4 = (Fn) reg_a1;
    jtbl_0028E3F4();
    return;
next_2:
    reg_d0.w = D_0028DEA8;
    reg_d7.w = D_0028DEA4;
    reg_a0 = (u8 *)D_0028DEB4_as_u8_p;
    reg_a1 = (u8 *)D_0028DEB0_as_u8_p;
    D_0028E408 = 0;
}
