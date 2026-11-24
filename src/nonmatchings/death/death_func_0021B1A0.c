#include "common.h"

s32 func_00129410();
s32 func_00129450();
extern u16 D_00259770[];
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

#define LOOKUP(d) (((d) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(d) & ~1)) : *(u16 *)reg_a1)

void death_func_0021B1A0(void) {
    reg_d0.h[1] = *(u16 *)(reg_a4 + 0xA);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d6.b[0] = 0x10;
    reg_d7.w = 1;
    reg_d5.w = 0;
    reg_d4.w = 0;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_d3.h[1] = LOOKUP(reg_d3.h[0]);
        reg_d3.h[0] = LOOKUP(reg_d3.h[0] + 2);
        reg_d3.w += reg_d5.w;
        func_00129410();
        reg_d1.b[0] += reg_d6.b[0];
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
