#include "common.h"

extern s8 D_0028E408;

s32 func_00129280();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0019D620();
s32 func_001A9000();
s32 func_001D27A0();
s32 func_002010A0();
s32 func_00201E20();
s32 func_00203060();
extern u8 D_0028E855;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

#define W(o) (*(u16 *)(reg_a6 + (o)))
#define B(o) (*(u8 *)(reg_a6 + (o)))

void func_0014F5E0(void) {
    u32 count;

    W(0x22) = W(2);
    W(0x24) = W(4);
    if (!(D_0028E855 & 0x40)) goto block_20;
    reg_d1.b[0] = B(1);
    func_001D27A0();
    if (D_0028E408 != 0) goto block_end;
    B(0x1C) = B(0x3D);
    reg_d1.b[0] = B(1);
    reg_d1.b[0] |= B(0x21);
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] == 0) goto next_100;
    reg_d0.b[0] = 0xA3;
    B(1) &= reg_d0.b[0];
    B(0x21) &= reg_d0.b[0];
    reg_d0.b[0] = B(0x1C);
    reg_d2.b[0] = B(0x3C);
    reg_d0.b[0] ^= reg_d2.b[0];
    B(0x1C) = reg_d0.b[0];
    func_001A9000();
    reg_d2.w = 0x7FFF;
    reg_d2.h[0] -= W(0x18);
    reg_d3.w = 0x7FFF;
    reg_d3.h[0] -= W(0x38);
    if ((s32) reg_d2.w >= (s32) reg_d3.w) goto next_10;
    reg_d2.w = reg_d3.w;
next_10:
    reg_tmp.h[1] = W(0x26);
    reg_tmp.h[0] = W(0x28);
    reg_tmp.w -= reg_d2.w;
    W(0x26) = reg_tmp.h[1];
    W(0x28) = reg_tmp.h[0];
    reg_d0.h[0] = 0x7FFF;
    W(0x18) = reg_d0.h[0];
    W(0x38) = reg_d0.h[0];
    reg_tmp.h[1] = W(0x26);
    reg_tmp.h[0] = W(0x28);
    goto next_100;
block_20:
    reg_d2.h[1] = W(2);
    reg_d2.h[0] = W(4);
    reg_d3.w = 0;
    reg_d7.w = 3;
loop_20:
    reg_d1.w = 0;
    reg_d1.b[0] = B(0x1A);
    reg_d1.b[0] += reg_d1.b[0];
    reg_d1.b[0] += reg_d1.b[0];
    func_002010A0();
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a5 + 0x29);
loop_30:
    reg_d1.b[0] += reg_d0.b[0];
    count = reg_d4.h[0] - 1;
    reg_d4.h[0] = count;
    if (((s64) ((s64) (u16) count << 0x30) >> 0x30) >= 0) goto loop_30;
    func_002010A0();
    reg_d0.h[0] = (s8) reg_d0.b[0];
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 1;
    reg_d0.h[0] += 0xFFFA;
    reg_d0.h[0] += *(u16 *)(reg_a5 + 0x24);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 5;
    reg_d3.w = 0;
    reg_d4.w = 0;
    func_00129280();
    count = reg_d7.h[0] - 1;
    reg_d7.h[0] = count;
    if (((s64) ((s64) (count & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_20;
    reg_d0.w = 2;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = W(2);
    *(u16 *)(reg_a0 + 4) = W(4);
    *(u8 *)(reg_a0 + 0x1B) = B(0x1B);
    reg_d0.b[0] = B(0x1A);
    reg_d0.b[0] += reg_d0.b[0];
    reg_d0.b[0] += reg_d0.b[0];
    *(u8 *)(reg_a0 + 0x1A) = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x1E) = 0xC;
block_end:
    func_0014E290();
    return;
next_100:
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = B(0x1B);
    reg_d1.b[0] = B(0x1A);
    func_00201E20();
    W(2) += reg_d2.h[0];
    W(4) += reg_d3.h[0];
    func_00203060();
    if (D_0028E408 == 0) goto next_110;
    func_0014E290();
    return;
next_110:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
    *(u8 *)(reg_a5 + 0x1F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_120;
    *(u8 *)(reg_a5 + 0x1F) = *(u8 *)(reg_a5 + 0x1E);
    *(u16 *)(reg_a5 + 0x20) += 4;
    *(u16 *)(reg_a5 + 0x20) &= 0xF;
    reg_tmp.h[1] = W(0xA);
    reg_tmp.h[0] = W(0xC);
    reg_tmp.w += 1;
    W(0xA) = reg_tmp.h[1];
    W(0xC) = reg_tmp.h[0];
    reg_d0.h[1] = *(u16 *)(reg_a5 + 0x1A);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1C);
    reg_tmp.h[1] = W(0xA);
    reg_tmp.h[0] = W(0xC);
    if (reg_tmp.w != reg_d0.w) goto next_120;
    reg_tmp.h[1] = W(0xA);
    reg_tmp.h[0] = W(0xC);
    reg_tmp.w -= 3;
    W(0xA) = reg_tmp.h[1];
    W(0xC) = reg_tmp.h[0];
next_120:
    reg_a0 = reg_a6;
    func_0014D220();
    reg_a0 = reg_a6 + 0x20;
    func_0014D220();
    func_0019D620();
}
