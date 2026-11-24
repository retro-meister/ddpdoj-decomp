#include "common.h"

s32 func_0013AF10();
s32 func_0013AF70();
extern s32 D_0028DF20;
extern s32 D_0028DF24;
extern s32 D_0028DF28;
extern s32 D_0028DF2C;
extern s32 D_0028DF30;
extern s32 D_0028DF34;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_0013C4B0(void) {
loop_1:
    reg_a4 = (u8 *)reg_d0.w;
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0);
    if (reg_tmp.h[0] == 0) goto block_next;
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 8);
    reg_a1 = (u8 *)reg_tmp.w;
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0xA);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xC);
    reg_a2 = (u8 *)reg_tmp.w;
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0xE);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x10);
    reg_a3 = (u8 *)reg_tmp.w;
    reg_d5.h[0] = *(u16 *)(reg_a4 + 4);
    reg_d6.w = 0;
    if (*(u16 *)(reg_a4 + 0x1E) != 0) goto skip_1;
    reg_d6.w = 2;
skip_1:
    if (*(u16 *)(reg_a4 + 0x18) == 0) goto block_next;
    *(u16 *)(reg_a4 + 0x14) -= 1;
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x14);
    if ((s16)reg_tmp.h[0] >= 0) goto block_next;
    *(u16 *)(reg_a4 + 0x14) = *(u16 *)(reg_a4 + 0x16);
    if (*(u16 *)(reg_a4 + 0x20) == 0x20) goto block_next;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x1C);
    *(u16 *)(reg_a4 + 0x20) += reg_d0.h[0];
    if (*(s16 *)(reg_a4 + 0x20) < 0x20) goto skip_2;
    *(u16 *)(reg_a4 + 0x18) = 0;
    *(u16 *)(reg_a4 + 0) = 0;
skip_2:
    reg_a5 = reg_a4 + 0x30;
loop_2:
    reg_d1.h[0] = *(u16 *)reg_a2;
    reg_d2.h[0] = *(u16 *)reg_a3;
    reg_d1.h[0] &= 0x7FFF;
    reg_d2.h[0] &= 0x7FFF;
    if (reg_d2.h[0] == reg_d1.h[0]) goto next_1;
    reg_d1.h[0] = *(u16 *)reg_a3;
    func_0013AF10();
    D_0028DF34 = reg_d2.h[0];
    D_0028DF30 = reg_d3.h[0];
    D_0028DF2C = reg_d4.h[0];
    reg_d1.h[0] = *(u16 *)reg_a2;
    func_0013AF10();
    D_0028DF28 = reg_d2.h[0];
    D_0028DF24 = reg_d3.h[0];
    D_0028DF20 = reg_d4.h[0];
    reg_d2.h[0] -= *(u16 *)&D_0028DF34;
    reg_d3.h[0] -= *(u16 *)&D_0028DF30;
    reg_d4.h[0] -= *(u16 *)&D_0028DF2C;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x1C);
loop_3:
    if (reg_d2.h[0] == 0) goto skip_r;
    if ((s16)reg_d2.h[0] >= 0) goto next_r2;
    if (D_0028DF28 != 0x10) goto skip_r1;
    if (D_0028DF34 == 0xF) goto skip_r;
skip_r1:
    D_0028DF34 -= 1;
    if (D_0028DF34 == 0x10) goto skip_r1;
    if (0 < D_0028DF34) goto skip_r;
    D_0028DF34 = 0;
    goto skip_r;
next_r2:
    if (D_0028DF28 != 0x10) goto next_r3;
    if (D_0028DF34 == 0x11) goto skip_r;
next_r3:
    D_0028DF34 += 1;
    if (D_0028DF34 == 0x10) goto next_r2;
    if ((s16)D_0028DF34 < 0x1F) goto skip_r;
    D_0028DF34 = 0x1F;
skip_r:
    if (reg_d3.h[0] == 0) goto skip_g;
    if ((s16)reg_d3.h[0] >= 0) goto next_g2;
    if (D_0028DF24 != 0x10) goto next_g1;
    if (D_0028DF30 == 0xF) goto skip_g;
next_g1:
    D_0028DF30 -= 1;
    if (D_0028DF30 == 0x10) goto next_g1;
    if (0 < D_0028DF30) goto skip_g;
    D_0028DF30 = 0;
    goto skip_g;
next_g2:
    if (D_0028DF24 != 0x10) goto next_g3;
    if (D_0028DF30 == 0x11) goto skip_g;
next_g3:
    D_0028DF30 += 1;
    if (D_0028DF30 == 0x10) goto next_g2;
    if ((s16)D_0028DF30 < 0x1F) goto skip_g;
    D_0028DF30 = 0x1F;
skip_g:
    if (reg_d4.h[0] == 0) goto skip_b;
    if ((s16)reg_d4.h[0] >= 0) goto next_b2;
    if (D_0028DF20 != 0x10) goto next_b1;
    if (D_0028DF2C == 0xF) goto skip_b;
next_b1:
    D_0028DF2C -= 1;
    if (D_0028DF2C == 0x10) goto next_b1;
    if (0 < D_0028DF2C) goto skip_b;
    D_0028DF2C = 0;
    goto skip_b;
next_b2:
    if (D_0028DF20 != 0x10) goto next_b3;
    if (D_0028DF2C == 0x11) goto skip_b;
next_b3:
    D_0028DF2C += 1;
    if (D_0028DF2C == 0x10) goto next_b2;
    if ((s16)D_0028DF2C < 0x1F) goto skip_b;
    D_0028DF2C = 0x1F;
skip_b:
    reg_d0.h[0] -= 1;
    if (reg_d0.h[0] != 0) goto loop_3;
    reg_d2.h[0] = *(u16 *)&D_0028DF34;
    reg_d3.h[0] = *(u16 *)&D_0028DF30;
    reg_d4.h[0] = *(u16 *)&D_0028DF2C;
    func_0013AF70();
    *(u16 *)reg_a3 = reg_d1.h[0];
    *(u16 *)reg_a1 = 1;
next_1:
    reg_a3 += 2;
    reg_a5 += 2;
    reg_a2 += reg_d6.h[0];
    if ((s16)(--reg_d5.h[0]) >= 0) goto loop_2;
block_next:
    reg_d0.h[1] = *(u16 *)(reg_a4 + 0x2C);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x2E);
    if (reg_d0.w != 0) goto loop_1;
}
