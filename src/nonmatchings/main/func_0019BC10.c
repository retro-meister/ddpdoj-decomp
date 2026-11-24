#include "common.h"

typedef void (*Fn)(void);

extern u8 D_0025EBF0[];
extern volatile u16 D_0028E46C;
extern u16 D_0028E478;
extern Fn jtbl_0028E3F4;
extern u8 *reg_a0;

void func_0019BC10(void) {
    u32 k;
    u16 t;

    k = 0xFFFF;
    reg_d7.w = reg_d6.w;
    reg_a0 = D_0025EBF0;
    D_0028E478 = reg_d4.h[0];
    reg_d4.h[0] = reg_d3.h[0];
    reg_d4.h[1] = D_0028E478;
    reg_d7.w = (u32) reg_d7.w >> 8;
    reg_d4.h[0] &= 0x1FF;
    reg_d7.h[0] *= (u16)k;
    reg_d4.h[0] >>= 1;
    reg_d7.h[0] += 0x80;
    jtbl_0028E3F4 = *(Fn *)(D_0025EBF0 + (reg_d4.h[0] & ~3));
    jtbl_0028E3F4();
    reg_a0 = D_0025EBF0;
    reg_d4.h[0] = reg_d3.h[0];
    t = reg_d7.h[1];
    D_0028E46C = reg_d7.h[0];
    reg_d7.h[1] = D_0028E46C;
    reg_d7.h[0] = t;
    reg_d4.h[0] &= 0x3E00;
    reg_d7.h[0] *= 0xFFFF;
    reg_d4.h[0] >>= 6;
    reg_d7.h[0] += 0x80;
    jtbl_0028E3F4 = *(Fn *)(D_0025EBF0 + (reg_d4.h[0] & ~3));
    jtbl_0028E3F4();
}
