#include "common.h"

s32 func_00129410();
s32 func_00129450();
extern u16 D_00259970[];
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

#define LOOKUP(d) (((d) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(d) & ~1)) : *(u16 *)reg_a1)

void death_func_0021B770(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
    *(u8 *)(reg_a4 + 7) -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        return;
    }
    *(u8 *)(reg_a4 + 7) = *(u8 *)(reg_a4 + 6);
    reg_d0.h[1] = *(u16 *)(reg_a4 + 0x12);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x14);
    reg_d1.b[0] = *(u8 *)(reg_a4 + 0x1B);
    reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d4.w = 0;
    reg_d6.w = 0xFE000000;
    reg_d7.w = 3;
    reg_a1 = (u8 *) D_00259970;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_d3.h[1] = LOOKUP(reg_d3.h[0]);
        reg_d3.h[0] = LOOKUP(reg_d3.h[0] + 2);
        reg_d3.w += reg_d6.w;
        func_00129450();
        reg_d1.h[0] += 0x40;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d1.b[0] = *(u8 *)(reg_a4 + 0x1A);
    *(u8 *)(reg_a4 + 0x1B) += reg_d1.b[0];
}
