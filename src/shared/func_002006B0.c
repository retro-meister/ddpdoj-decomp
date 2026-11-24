#include "common.h"

s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0018D560();
s32 func_0019C570();
s32 func_001A9000();
s32 func_002009C0();
extern u8 D_00266480[];
extern u16 D_0028E3F0;
extern u16 D_0028E888;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_002006B0(void) {
    if (*(s16 *)(reg_a6 + 2) > -0x400) goto next_1;
    func_0014E290();
    return;
next_1:
    reg_d0.h[1] = *(u16 *)(reg_a5 + 0x1E);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x20);
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 2);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 4);
    reg_tmp.w += reg_d0.w;
    *(u16 *)(reg_a6 + 2) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 4) = reg_tmp.h[0];
    *(u16 *)(reg_a5 + 0x1E) -= 2;
    if (D_0028E888 == 0) goto block_1;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *)(reg_a6 + 1);
    if (reg_d1.b[0] == 0) goto next_2;
    reg_d0.b[0] = 0xA3;
    *(u8 *)(reg_a6 + 1) &= reg_d0.b[0];
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
    reg_d0.b[0] ^= 0xC;
    *(u8 *)(reg_a6 + 0x1C) = reg_d0.b[0];
    if (*(s16 *)(reg_a6 + 0x18) >= 0) goto next_3;
block_1:
    reg_d0.h[0] = 0x14;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = *(u16 *)(reg_a6 + 4);
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    func_0018D560();
    func_0014E290();
    return;
next_2:
    *(u8 *)(reg_a6 + 0x1C) = 0x13;
next_3:
    reg_d0.w = 3;
    reg_d0.h[0] &= D_0028E3F0;
    if (reg_d0.h[0] != 0) goto next_4;
    *(u16 *)(reg_a5 + 0x1A) += 4;
    *(u16 *)(reg_a5 + 0x1A) &= 0x1F;
next_4:
    if (*(u16 *)(reg_a5 + 0x24) == 0) goto next_5;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
    *(u8 *)(reg_a5 + 0x23) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_5;
    *(u8 *)(reg_a5 + 0x23) = *(u8 *)(reg_a5 + 0x22);
    *(u8 *)(reg_a5 + 0x1D) += 3;
    *(u8 *)(reg_a5 + 0x1D) &= 0x3F;
    reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x1D);
    reg_d0.w = 0xFFFC0007;
    reg_d4.w = 0;
    reg_d3.w = 0;
    func_002009C0();
    reg_d1.b[0] += 0x15;
    reg_d1.b[0] &= 0x3F;
    func_002009C0();
    reg_d1.b[0] += 0x15;
    reg_d1.b[0] &= 0x3F;
    func_002009C0();
    *(u16 *)(reg_a5 + 0x24) -= 1;
next_5:
    reg_a0 = (u8 *)D_00266480;
    reg_a0 += *(u16 *)(reg_a5 + 0x1A);
    reg_d2.h[1] = *(u16 *)(reg_a0 + 0);
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.w += 0xFA00FC00;
    reg_d3.h[0] = 0x620;
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x1C);
    func_0019C570();
    reg_a0 = reg_a6;
    func_0014D220();
}
