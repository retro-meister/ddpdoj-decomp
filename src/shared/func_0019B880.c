#include "common.h"

typedef void (*Fn)(void);

extern u8 D_0025EAF0[];
extern u16 D_0028E484_as_u16;
extern Fn jtbl_0028E3F4_as_Fn;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_0019B880(void) {
    u32 k;
    u16 t;

    k = 0xFFFF;
    reg_a0 = (u8 *)D_0025EAF0;
    reg_d1.w = reg_d6.w;
    reg_d1.w = (u32) reg_d1.w >> 8;
    reg_d1.h[0] *= (u16)k;
    reg_d1.h[0] += 0x80;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0xE);
    reg_d0.h[0] &= 0x1FF;
    reg_d0.h[0] >>= 1;
    jtbl_0028E3F4_as_Fn = *(Fn *)(D_0025EAF0 + (reg_d0.h[0] & ~3));
    jtbl_0028E3F4_as_Fn();
    D_0028E484_as_u16 = reg_d1.h[0];
    reg_a0 = (u8 *)D_0025EAF0;
    reg_d0.w = 0x3E;
    t = reg_d1.h[1];
    reg_d1.h[1] = D_0028E484_as_u16;
    reg_d1.h[0] = t;
    reg_d1.h[0] *= 0xFFFF;
    reg_d1.h[0] += 0x80;
    reg_d0.b[0] &= *(u8 *)(reg_a6 + 0xF);
    reg_d0.h[0] *= 4;
    jtbl_0028E3F4_as_Fn = *(Fn *)(D_0025EAF0 + (reg_d0.h[0] & ~3));
    jtbl_0028E3F4_as_Fn();
}
