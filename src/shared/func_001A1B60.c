#include "common.h"

extern u16 D_0025F490[];
extern u16 D_0025F4B0[];
extern u16 D_0025F550[];
extern u16 D_0028D968_as_u16;
extern u16 D_0028D970_as_u16;
extern u16 D_0028D978_as_u16;
extern u16 D_0028DFD4;
extern u16 D_0028DFD8;
extern u8 D_0029D710[];
extern u8 D_0029D730[];
extern u8 D_0029D750[];
extern u8 D_0029D770[];
extern u8 D_0029D790[];
extern u8 D_0029DD90[];
extern u16 D_0029F220[];
extern u16 D_0029F290[];

s32 func_0019D4D0();
s32 func_0019F620();
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001A1B60(void) {
    u32 cnt;

    switch (reg_a6[1] & 0x20) {
    case 0:
        goto next_100;
    }
    reg_a0 = (u8 *)&D_0028DFD8;
    reg_a1 = (u8 *)D_0029DD90;
    reg_a2 = (u8 *)D_0029D730;
    reg_a3 = (u8 *)D_0029D770;
    reg_d4.h[0] = D_0029F290[0];
    if (reg_d7.h[0] != 0) goto next_10;
    reg_a0 = (u8 *)&D_0028DFD4;
    reg_a1 = (u8 *)D_0029D790;
    reg_a2 = (u8 *)D_0029D710;
    reg_a3 = (u8 *)D_0029D750;
    reg_d4.h[0] = D_0029F220[0];
next_10:
    reg_d4.h[0] += 0x300;
    reg_d0.h[1] = *(u16 *)(reg_a4 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 4);
    reg_d0.w += 0x8000000;
    *(u16 *)(reg_a3 + 2) = reg_d0.h[1];
    *(u16 *)(reg_a3 + 4) = reg_d0.h[0];
    if (reg_a3[1] & 0x10) goto next_30;
    if (*(u16 *)(reg_a3 + 0xC) != 0) goto next_40;
    if (*(u16 *)(reg_a2 + 0x16) == 0) goto next_20;
    *(u16 *)(reg_a2 + 0x16) -= 1;
    if (*(u16 *)(reg_a2 + 0x16) != 0) goto next_60;
next_20:
    *(u16 *)(reg_a3 + 6) += 0x800;
    reg_tmp.b[0] = reg_a6[0];
    reg_a6[0] |= 0x80;
    if (!(reg_tmp.b[0] & 0x80)) goto block_sen;
    goto next_60;
next_30:
    *(u16 *)(reg_a6 + 0x4E) = 0;
    *(u16 *)(reg_a3 + 0xE) = *(u16 *)(reg_a3 + 0x1C);
    *(u16 *)(reg_a3 + 0xC) = 0;
next_40:
    reg_a6[0] &= 0x7F;
    reg_d0.h[0] = *(u16 *)(reg_a3 + 0x10);
    reg_d1.h[0] = reg_d0.h[0];
    *(u16 *)reg_a0 = reg_d1.h[0];
    *(u16 *)(reg_a3 + 0x12) = reg_d1.h[0];
    reg_d0.h[0] -= *(u16 *)(reg_a3 + 2);
    if ((s16)reg_d0.h[0] >= 0) goto next_50;
    reg_d0.w = 0;
next_50:
    *(u16 *)(reg_a3 + 6) = reg_d0.h[0];
next_60:
    reg_d0.w = 0x1D;
    if (reg_a4[0] & 1) {
        reg_a0 = (u8 *)D_0025F4B0;
        goto next_64;
    }
    reg_a0 = (u8 *)D_0025F490;
    if (reg_a4[0x5A] & 4) goto next_64;
    reg_d3.h[0] = *(u16 *)(reg_a4 + 0x58);
    reg_a0 = (u8 *)&D_0028D968_as_u16;
    reg_d3.h[0] += reg_d3.h[0];
    reg_tmp.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)reg_tmp.w;
next_64:
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0x22);
    reg_d2.h[0] = reg_d1.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    reg_tmp.h[1] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)reg_tmp.w;
loop_70:
    if (*(s16 *)reg_a1 >= 0) goto next_80;
    reg_a1 += 0x30;
    cnt = reg_d0.h[0] - 1;
    reg_d0.h[0] = cnt;
    if (((s64) ((s64) (cnt & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_70;
    goto next_100;
next_80:
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)(reg_a6 + 2);
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)(reg_a6 + 4);
    reg_a1 += 2;
    *(u16 *)(reg_a1 - 4) -= reg_d4.h[0];
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a2 = (u8 *)reg_tmp.w;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x50);
    *(u16 *)reg_a1 = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 0xA;
    *(u16 *)reg_a1 = reg_d7.h[0];
    reg_a1 += 2;
    reg_a1[1] = 0;
    reg_a1[0] = reg_a4[0x57];
    reg_a1 += 2;
    reg_d1.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x50) += 4;
    if (*(u16 *)(reg_a6 + 0x50) != reg_d1.h[0]) goto next_100;
    *(u16 *)(reg_a6 + 0x50) = 0;
next_100:
    if ((s8)reg_a4[0] < 0) return;
    func_0019F620();
    func_0019D4D0();
    return;
block_sen:
    reg_a2 = reg_a1;
    reg_a1 += 0x510;
    reg_d3.h[0] = *(u16 *)(reg_a4 + 0x58);
    reg_a0 = (u8 *)&D_0028D970_as_u16;
    reg_d3.h[0] += reg_d3.h[0];
    if (reg_a4[0x5A] & 4) {
        reg_a0 = (u8 *)&D_0028D978_as_u16;
    }
    reg_tmp.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0x22);
    reg_d2.h[0] = reg_d1.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    if (reg_a4[0] & 1) {
        reg_a0 = (u8 *)D_0025F550;
    }
    reg_tmp.h[1] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)reg_tmp.w;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)(reg_a6 + 2);
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)(reg_a6 + 4);
    reg_a1 += 2;
    *(u16 *)(reg_a1 - 4) -= 0x600;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = reg_d7.h[0];
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1[-2] = reg_a4[0x57];
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_d1.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.b[0] = reg_a3[0];
    reg_a3[0] |= 1;
    if (!(reg_tmp.b[0] & 1)) goto next_sen10;
    reg_a1[-0x28] |= 0x80;
    reg_d0.h[0] = *(u16 *)(reg_a3 + 0x12);
    reg_d0.h[0] += reg_d1.h[0];
    reg_d0.h[0] += 0x400;
    *(u16 *)(reg_a1 - 0x26) = reg_d0.h[0];
    reg_a1 = reg_a2;
    goto next_60;
next_sen10:
    *(u16 *)(reg_a6 + 0x4E) = 2;
    func_0019F620();
    func_0019D4D0();
}
