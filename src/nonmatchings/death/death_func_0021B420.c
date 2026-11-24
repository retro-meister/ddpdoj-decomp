#include "common.h"

s32 func_00129410();
s32 func_00129450();
extern u16 D_00259770[];
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

#define LOOKUP(d) (((d) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(d) & ~1)) : *(u16 *)reg_a1)

void death_func_0021B420(void) {
    reg_d0.h[1] = *(u16 *)(reg_a4 + 8);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xA);
    reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d3.w = 0xFA000000;
    reg_d4.w = 0;
    func_00129450();
    reg_d0.h[0] += 1;
    reg_d1.b[0] -= reg_d6.b[0];
    reg_d0.w += 0x30000;
    func_00129450();
    reg_d0.h[0] += 1;
    reg_d1.b[0] -= reg_d6.b[0];
    reg_d0.w += 0x30000;
    func_00129450();
    reg_d0.h[0] += 1;
    reg_d1.b[0] -= reg_d6.b[0];
    reg_d0.w += 0x30000;
    func_00129450();
    reg_d0.h[0] -= 1;
    reg_d1.b[0] -= reg_d6.b[0];
    reg_d0.w += 0x30000;
    func_00129450();
    reg_d0.h[0] -= 1;
    reg_d1.b[0] -= reg_d6.b[0];
    reg_d0.w += 0x30000;
    func_00129450();
    reg_d0.h[0] -= 1;
    reg_d1.b[0] -= reg_d6.b[0];
    reg_d0.w += 0x30000;
    func_00129450();
    reg_d0.h[0] += 1;
    reg_d1.b[0] -= reg_d6.b[0];
    reg_d0.w += 0x30000;
    func_00129450();
    reg_d0.h[0] += 1;
    reg_d1.b[0] -= reg_d6.b[0];
    reg_d0.w += 0x30000;
    func_00129450();
}
