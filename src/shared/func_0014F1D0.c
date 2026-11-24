#include "common.h"

extern s8 D_0028E408;

s32 func_0013A780();
s32 func_0014E290();
s32 func_0019BF80();
s32 func_001D27A0();
s32 func_00201C60();
extern u8 D_0028E855;
extern u16 D_0028E8A0;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

#define W(o) (*(u16 *)(reg_a6 + (o)))
#define B(o) (*(u8 *)(reg_a6 + (o)))

void func_0014F1D0(void) {
    if (!(D_0028E855 & 0x40)) goto block_5;
    reg_d1.b[0] = B(1);
    func_001D27A0();
    if (D_0028E408 != 0) goto block_6;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= B(1);
    if (reg_d1.b[0] == 0) goto next_1;
    reg_d0.b[0] = 0xA3;
    B(1) &= reg_d0.b[0];
    if ((s32) B(0x19) >= 0) goto next_1;
block_5:
    reg_d0.w = 1;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = W(2);
    *(u16 *)(reg_a0 + 4) = W(4);
    *(u8 *)(reg_a0 + 0x1B) = B(0x1B);
    reg_d0.b[0] = B(0x1A);
    reg_d0.b[0] += reg_d0.b[0];
    reg_d0.b[0] += reg_d0.b[0];
    *(u8 *)(reg_a0 + 0x1A) = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x1E) = 0xC;
block_6:
    func_0014E290();
    return;
next_1:
    if (D_0028E8A0 != 0) goto next_2;
    func_00201C60();
    if (!((s16) W(2) < -0x400)) goto next_3;
    func_0014E290();
    return;
next_3:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
    *(u8 *)(reg_a5 + 0x1F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_2;
    *(u8 *)(reg_a5 + 0x1F) = *(u8 *)(reg_a5 + 0x1E);
    *(u16 *)(reg_a0 + 0) = *(u16 *)(reg_a5 + 0x1A);
    *(u16 *)(reg_a0 + 2) = *(u16 *)(reg_a5 + 0x1C);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x20);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0x20) += 4;
    *(u16 *)(reg_a5 + 0x20) &= 0xF;
next_2:
    func_0019BF80();
}
