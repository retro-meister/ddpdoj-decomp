#include "common.h"

typedef void (*Fn)(void);

extern u8 D_0025EBF0[];
extern u16 D_0028E46C;
extern u16 D_0028E478;
extern Fn jtbl_0028E3F4_as_Fn;
extern u8 *reg_a0;

void func_0019BC10(void) {
    u16 t;
    Fn *entry;

    reg_a0 = (u8 *)D_0025EBF0;
    reg_d7.w = reg_d6.w;
    reg_d7.w = (u32) reg_d7.w >> 8;
    reg_d7.h[0] *= 0xFFFF;
    reg_d7.h[0] += 0x80;
    D_0028E478 = reg_d4.h[0];
    reg_d4.h[0] = reg_d4.h[1];
    reg_d4.h[1] = D_0028E478;
    reg_d4.h[0] = reg_d3.h[0];
    reg_d4.h[0] &= 0x1FF;
    reg_d4.h[0] >>= 1;
    jtbl_0028E3F4_as_Fn = *(entry = (Fn *)(D_0025EBF0 + (reg_d4.h[0] & ~3)));
    jtbl_0028E3F4_as_Fn();
    D_0028E46C = reg_d7.h[0];
    reg_a0 = (u8 *)D_0025EBF0;
    t = reg_d7.h[1];
    reg_d7.h[1] = D_0028E46C;
    reg_d7.h[0] = t;
    reg_d7.h[0] *= 0xFFFF;
    reg_d7.h[0] += 0x80;
    reg_d4.h[0] = reg_d3.h[0];
    reg_d4.h[0] &= 0x3E00;
    reg_d4.h[0] >>= 6;
    jtbl_0028E3F4_as_Fn = *(entry = (Fn *)(D_0025EBF0 + (reg_d4.h[0] & ~3)));
    jtbl_0028E3F4_as_Fn();
}
