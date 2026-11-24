#include "common.h"

extern s32 D_0028DFF4;
extern u16 D_0028DFF8;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_00122500(void) {
    reg_a0 = reg_a6;
    reg_a6 += 0x840;
    reg_d1.h[0] = D_0028DFF8;
    if (D_0028DFF4 != 0) goto block_1;
    if (*(u16 *)(reg_a6 + 0x28) == 0) goto block_3;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
    reg_tmp.b[0] = *(u8 *)(reg_a0 + 1);
    *(u8 *)(reg_a0 + 1) |= 0x20;
    if (reg_tmp.b[0] & 0x20) goto block_3;
    goto block_2;
block_1:
    *(u8 *)(reg_a0 + 1) &= 0xDF;
block_2:
    *(u8 *)(reg_a0 + 1) &= 0xBF;
    *(u8 *)(reg_a6 + 1) &= 0xFD;
    *(u16 *)(reg_a6 + 2) = reg_d1.h[0];
    *(u16 *)(reg_a6 + 0x28) = 1;
    goto block_4;
block_3:
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 1);
    *(u8 *)(reg_a6 + 1) |= 2;
    if (reg_tmp.b[0] & 2) goto block_4;
    *(u8 *)(reg_a0 + 0x7E1) &= 0xFD;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d0.h[0] += 0x400;
    if (*(u16 *)(reg_a0 + 0x18) == 0) goto skip_1;
    reg_d0.h[0] -= 0x800;
skip_1:
    *(u16 *)(reg_a0 + 0x7E2) = reg_d0.h[0];
    *(s16 *)(reg_a0 + 0x808) = 0;
    *(u8 *)(reg_a0 + 1) |= 0x40;
block_4:
    reg_a6 -= 0x840;
}
