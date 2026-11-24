#include "common.h"

s32 func_00128930();
s32 func_0013A780();
s32 func_0014E290();
s32 func_0019D6A0();
s32 func_002011A0();
s32 func_00201C60();
extern u16 D_00259770[];
extern u16 D_00259870[];
extern u16 D_00259970[];
extern u32 D_0026E7C0[];
extern u8 D_0028E855;
extern u16 D_0028E89C;
extern u16 D_0028E8A0;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

#define W(o) (*(u16 *)(reg_a6 + (o)))
#define TW(o) (*(u16 *)(reg_a5 + (o)))
#define AW(o) (*(u16 *)(reg_a0 + (o)))
#define LOOKUP(d) (((d) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(d) & ~1)) : *(u16 *)reg_a0)

void func_0014FB30(void) {
    if (D_0028E855 & 0x40) goto next_1;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= reg_a6[1];
    if (reg_d1.b[0] == 0) goto next_2;
    reg_d0.b[0] = 0xA3;
    reg_a6[1] &= reg_d0.b[0];
    W(0x18) = 0x7FFF;
    goto next_2;
next_1:
    reg_d0.w = 1;
    func_0013A780();
    AW(2) = W(2);
    AW(4) = W(4);
    reg_a0[0x1B] = reg_a6[0x1B];
    reg_d0.b[0] = reg_a6[0x1A];
    reg_d0.b[0] += reg_d0.b[0];
    reg_d0.b[0] += reg_d0.b[0];
    reg_a0[0x1A] = reg_d0.b[0];
    AW(0x1E) = 0x10;
    func_0014E290();
    return;
next_2:
    func_00201C60();
    reg_tmp.b[0] = reg_a5[0x27];
    reg_a5[0x27] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_3;
    reg_a5[0x27] = reg_a5[0x26];
    reg_a6[0x1B] -= 1;
next_3:
    if (reg_a6[0x1B] != 0) goto block_saku;
    reg_d0.w = 1;
    func_0013A780();
    AW(2) = W(2);
    AW(4) = W(4);
    reg_a0[0x1B] = reg_a6[0x1B];
    reg_d0.b[0] = reg_a6[0x1A];
    reg_d0.b[0] += reg_d0.b[0];
    reg_d0.b[0] += reg_d0.b[0];
    reg_a0[0x1A] = reg_d0.b[0];
    AW(0x1E) = 0x10;
    func_002011A0();
    reg_d0.h[0] &= 0x3F;
    reg_d1.h[0] = reg_d0.h[0];
    reg_d2.h[1] = W(2);
    reg_d2.h[0] = W(4);
    reg_d3.w = 0;
    reg_d4.w = 0;
    reg_d0.h[0] = 0;
    reg_d0.h[0] = reg_d0.sb[0];
    reg_d0.h[0] += TW(0x1C);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 3;
    if (D_0028E8A0 != 0) goto block_end;
    if (D_0028E89C != 0) goto block_end;
    reg_d7.w = 0xF;
    reg_a0 = (u8 *) D_00259970;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] &= 0x3F;
        reg_d3.h[0] += reg_d3.h[0];
        reg_d3.h[0] += reg_d3.h[0];
        reg_d3.h[1] = LOOKUP(reg_d3.h[0]);
        reg_d3.h[0] = LOOKUP((u16) reg_d3.h[0] + 2);
        func_00128930();
        reg_d1.b[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.w -= 0x50000;
    reg_d0.h[0] = 4;
    reg_d1.b[0] += 2;
    reg_d7.w = 0xF;
    reg_a0 = (u8 *) D_00259870;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] &= 0x3F;
        reg_d3.h[0] += reg_d3.h[0];
        reg_d3.h[0] += reg_d3.h[0];
        reg_d3.h[1] = LOOKUP(reg_d3.h[0]);
        reg_d3.h[0] = LOOKUP((u16) reg_d3.h[0] + 2);
        func_00128930();
        reg_d1.b[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.w -= 0x50000;
    reg_d0.h[0] = 5;
    reg_d1.b[0] += 2;
    reg_d7.w = 0xF;
    reg_a0 = (u8 *) D_00259770;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] &= 0x3F;
        reg_d3.h[0] += reg_d3.h[0];
        reg_d3.h[0] += reg_d3.h[0];
        reg_d3.h[1] = LOOKUP(reg_d3.h[0]);
        reg_d3.h[0] = LOOKUP((u16) reg_d3.h[0] + 2);
        func_00128930();
        reg_d1.b[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
block_end:
    func_0014E290();
    return;
block_saku:
    reg_tmp.b[0] = reg_a5[0x1F];
    reg_a5[0x1F] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_4;
    reg_a5[0x1F] = reg_a5[0x1E];
    TW(0x20) += 4;
    TW(0x20) &= 0x3F;
next_4:
    reg_a0 = (u8 *) D_0026E7C0;
    reg_a0 += TW(0x20);
    reg_d2.h[1] = AW(0);
    reg_d2.h[0] = AW(2);
    reg_d1.h[1] = W(2);
    reg_d1.h[0] = W(4);
    reg_d1.w += 0xFA00FD00;
    reg_d3.h[0] = 0x618;
    reg_d4.w = 0x11;
    func_0019D6A0();
}
