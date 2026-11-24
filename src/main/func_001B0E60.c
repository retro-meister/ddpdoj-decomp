#include "common.h"

s32 func_0013AFF0();
s32 func_001A3020();
s32 func_00201E20();
extern u8 D_0028DF0C;
extern u8 D_0028DF10;
extern u16 D_0029BD80[];
extern u16 D_0029BDC0[];
extern u8 D_0029BE00[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001B0E60(void) {
    u8 *s_a0;
    u8 *s_a1;
    u8 *s_a2;
    u8 *s_a3;
    u8 *s_a4;
    u8 *s_a5;
    u8 *s_a6;
    u32 s_d0;
    u32 s_d1;
    u32 s_d2;
    u32 s_d3;
    u32 s_d4;
    u32 s_d5;
    u32 s_d6;
    u32 s_d7;
    u32 t;

    s_d0 = reg_d0.w;
    s_d1 = reg_d1.w;
    s_d2 = reg_d2.w;
    s_d3 = reg_d3.w;
    s_d4 = reg_d4.w;
    s_d5 = reg_d5.w;
    s_d6 = reg_d6.w;
    s_d7 = reg_d7.w;
    s_a0 = reg_a0;
    s_a1 = reg_a1;
    s_a2 = reg_a2;
    s_a3 = reg_a3;
    s_a4 = reg_a4;
    s_a5 = reg_a5;
    s_a6 = reg_a6;
    if (D_0028DF0C != 0) goto block_exit;
    reg_a6 = (u8 *)D_0029BE00;
    if (*(s8 *)(reg_a6 + 0) >= 6) goto block_set;
    if (*(s8 *)(reg_a6 + 0x70) < 6) goto next_1;
block_set:
    D_0028DF0C = 1;
    goto block_exit;
next_1:
    reg_a0 = (u8 *)D_0029BDC0;
    reg_d1.w = 0;
    reg_a1 = (u8 *)D_0029BD80;
    reg_d0.h[0] = 0x50;
    D_0028DF10 += 6;
    reg_d1.b[0] = D_0028DF10;
    func_00201E20();
    reg_d6.h[0] = 0x800;
    reg_d6.h[0] -= reg_d2.h[0];
    reg_d7.w = 0x1F;
    reg_d6.h[0] >>= 6;
loop_2:
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] = reg_d6.h[0];
    func_0013AFF0();
    *(u16 *)reg_a1 = reg_d0.h[0];
    reg_a1 += 2;
    t = reg_d7.h[0] - 1;
    reg_d7.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
    reg_a0 = (u8 *)D_0029BD80;
    reg_d0.h[0] = 0xB;
    func_001A3020();
block_exit:
    reg_d0.w = s_d0;
    reg_d1.w = s_d1;
    reg_d2.w = s_d2;
    reg_d3.w = s_d3;
    reg_d4.w = s_d4;
    reg_d5.w = s_d5;
    reg_d6.w = s_d6;
    reg_d7.w = s_d7;
    reg_a0 = s_a0;
    reg_a1 = s_a1;
    reg_a2 = s_a2;
    reg_a3 = s_a3;
    reg_a4 = s_a4;
    reg_a5 = s_a5;
    reg_a6 = s_a6;
}
