#include "common.h"

typedef void (*Fn)(void);

extern u8 D_0028C5D8[8];
extern u32 D_0028E40C;
extern u32 D_0028E410;
extern u32 D_0028E414;
extern u32 D_0028E428;
extern u8 *D_0028E42C;
extern u8 *D_0028E43C;
extern u8 *D_0028E440;
extern u8 *D_0028E444_as_u8_p;
extern u16 D_0028E5FC;
extern u8 D_0029D730[];
extern u8 D_0029D770[];
extern u8 D_0029DD90[];
extern u8 D_0029F180[];
extern u16 D_0029F2B8[];
extern Fn jtbl_0028E3F4_as_Fn;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a6;

void func_0013CBA0(void);
void func_0018DE10(void);

void func_0013C9A0(void) {
    D_0028E428 = reg_d0.w;
    D_0028E414 = reg_d5.w;
    D_0028E410 = reg_d6.w;
    D_0028E40C = reg_d7.w;
    D_0028E444_as_u8_p = reg_a0;
    D_0028E440 = reg_a1;
    D_0028E43C = reg_a2;
    D_0028E42C = reg_a6;
    reg_d0.h[0] = D_0029F2B8[0];
    reg_d0.h[0] <<= 1;
    reg_a0 = *(u8 **)(D_0028C5D8 + (reg_d0.h[0] & ~3));
    if (D_0028E5FC != 0) {
        reg_a0 = (u8 *)func_0018DE10;
    }
    jtbl_0028E3F4_as_Fn = (Fn)reg_a0;
    jtbl_0028E3F4_as_Fn();
    reg_a6 = (u8 *)D_0029DD90;
    reg_a0 = (u8 *)D_0029D770;
    reg_a1 = (u8 *)D_0029D730;
    reg_a2 = (u8 *)D_0029F180;
    func_0013CBA0();
}
