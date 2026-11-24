#include "common.h"

typedef void (*Fn)();

extern u8 D_00257820[];
extern u16 D_0028DFE8;
extern u16 D_0028E470;
extern u8 D_0028E5F8_as_u8;
extern u8 D_0028E5FC_as_u8;
extern u16 D_0029C06C[];
extern u8 D_0029E390[];
extern u8 D_0029F1F0_as_u8_a[];
extern u8 D_0029F260_as_u8_a[];
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001488C0(void) {
    u8 *saved_a4;
    u8 *saved_a5;
    u32 t;

    reg_a6 = (u8 *)D_0029E390;
    reg_d6.h[0] = D_0029C06C[0];
    D_0028DFE8 = 0;
    saved_a4 = reg_a4;
    saved_a5 = reg_a5;
    reg_a4 = (u8 *)D_0029F260_as_u8_a;
    reg_a5 = &D_0028E5FC_as_u8;
    D_0028E470 = reg_d6.h[0];
    reg_d6.h[0] = 1;
    reg_d6.h[1] = D_0028E470;
loop_1:
    D_0028E470 = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = D_0028E470;
    reg_d7.w = 0x23;
loop_2:
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0);
    if (reg_d1.h[0] == 0) goto next_1;
    D_0028DFE8 += 1;
    *(u16 *)(reg_a6 + 4) -= reg_d6.h[0];
    reg_d0.w = 0xF;
    reg_d0.h[0] &= reg_d1.h[0];
    ((Fn)*(u32 *)((u8 *)D_00257820 + (reg_d0.h[0] * 4)))();
next_1:
    reg_a6 += 0x30;
    t = reg_d7.h[0] - 1;
    reg_d7.h[0] = t;
    if (((s64) ((s64) (u16) t << 0x30) >> 0x30) >= 0) goto loop_2;
    reg_a4 = (u8 *)D_0029F1F0_as_u8_a;
    reg_a5 = &D_0028E5F8_as_u8;
    D_0028E470 = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = D_0028E470;
    t = reg_d6.h[0] - 1;
    reg_d6.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_a4 = saved_a4;
    reg_a5 = saved_a5;
}
