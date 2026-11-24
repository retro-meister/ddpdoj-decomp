#include "common.h"

s32 func_00148700();
s32 func_00148860();
s32 func_0018DA70();
s32 func_00201E20();
s32 func_00209F20();
extern u16 D_0025CAE0[];
extern u16 D_0025CD00[];
extern Reg32 D_0028E484;
extern u16 D_0028E928;
extern u8 *reg_a0;
extern u8 *reg_a6;

#define W(o) (*(u16 *)(reg_a6 + (o)))

void func_00149880(void) {
    if (reg_d0.h[0] != 2) goto next_100;
    reg_tmp.b[0] = reg_a6[0];
    reg_a6[0] |= 0x40;
    if (!(reg_tmp.b[0] & 0x40)) goto next_5;
    reg_a6[1] |= 1;
    goto next_10;
next_5:
    func_00148700();
    return;
next_10:
    W(0) |= 8;
    if (reg_d1.sb[0] < 0) goto block_touch;
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) D_0025CAE0;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    W(6) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0xE) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = reg_a6[0x1B];
    reg_d1.b[0] = reg_a6[0x1A];
    func_00201E20();
    W(0x2C) = reg_d2.h[0];
    W(0x2E) = reg_d3.h[0];
    reg_tmp.h[1] = W(0x1E);
    reg_tmp.h[0] = W(0x20);
    reg_a0 = (u8 *) reg_tmp.w;
    W(0xA) = *(u16 *)reg_a0;
    W(0xC) = *(u16 *)(reg_a0 + 2);
    reg_a6[1] &= 0xFE;
    goto block_anime;
block_clr:
    W(0) = 0;
    goto block_rts;
block_anime:
    reg_a6[1] |= 1;
    reg_d0.h[0] = W(0x2C);
    reg_d1.h[0] = W(0x2E);
    W(2) += reg_d0.h[0];
    if (!((s32) W(2) < 0x7800)) goto block_clr;
    W(4) += reg_d1.h[0];
    reg_d0.h[0] = W(4);
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0xC000;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x400;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] += 0xC000;
    if (!((s32) reg_tmp.h[0] < 0x4001)) goto block_clr;
    func_00148700();
    goto block_rts;
next_100:
    if (reg_d1.sb[0] >= 0) goto block_anime;
block_touch:
    reg_tmp.b[0] = reg_a6[1];
    reg_a6[1] |= 2;
    if (!(reg_tmp.b[0] & 2)) goto next_200;
loop_110:
    reg_tmp.h[0] = W(0x24);
    W(0x24) -= 4;
    if ((s32) reg_tmp.h[0] < 4) goto block_clr;
    reg_tmp.h[1] = W(0x1E);
    reg_tmp.h[0] = W(0x20);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    func_00148700();
    goto block_rts;
next_200:
    if (D_0028E928 == 0) goto next_220;
    reg_d0.w = 0x14;
    func_00209F20();
next_220:
    reg_d0.h[0] = W(0x2C);
    reg_d2.h[0] = W(0x2E);
    func_00148860();
    W(2) += reg_d0.h[0];
    W(4) += reg_d2.h[0];
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 2;
    reg_d2.h[0] = (s16) reg_d2.h[0] >> 2;
    W(0x2C) = reg_d0.h[0];
    W(0x2E) = reg_d2.h[0];
    func_0018DA70();
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) D_0025CD00;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    W(6) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0xE) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x1E) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x20) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x22) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x24) = *(u16 *)reg_a0;
    reg_a0 += 2;
    goto loop_110;
block_rts:
    return;
}
