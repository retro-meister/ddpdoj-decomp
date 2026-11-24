#include "common.h"

s32 func_001486D0();
s32 func_0018DA70();
s32 func_00201E20();
s32 func_00209F20();
extern u16 D_002549E0[];
extern u16 D_00254A50[];
extern Reg32 D_0028E484;
extern u16 D_0028E928;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

#define W(o) (*(u16 *)(reg_a6 + (o)))

void func_0014A3C0(void) {
    if (reg_d0.h[0] != 4) goto next_100;
    reg_tmp.b[0] = reg_a6[0];
    reg_a6[0] |= 0x40;
    if (!(reg_tmp.b[0] & 0x40)) goto next_5;
    reg_tmp.b[0] = reg_a6[1];
    reg_a6[1] |= 1;
    if (reg_tmp.b[0] & 1) goto next_10;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x30);
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0x32);
    W(2) += reg_d0.h[0];
    W(4) += reg_d1.h[0];
next_5:
    reg_a6[0x1D] ^= 0x40;
    func_001486D0();
    return;
next_10:
    W(0) |= 8;
    if (reg_d1.sb[0] < 0) goto block_touch;
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) D_002549E0;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    W(6) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0xE) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(2) += reg_d0.h[0];
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = reg_a6[0x1B];
    reg_d1.b[0] = reg_a6[0x1A];
    func_00201E20();
    W(0x2C) = reg_d2.h[0];
    W(0x2E) = reg_d3.h[0];
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
    if (!((s32) W(2) < 0x8000)) goto block_clr;
    W(4) += reg_d1.h[0];
    reg_d0.h[0] = W(4);
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0xB000;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0xC00;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] += 0xB000;
    if (!((s32) reg_tmp.h[0] < 0x5001)) goto block_clr;
    reg_tmp.h[1] = W(0x1E);
    reg_tmp.h[0] = W(0x20);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    W(0x24) -= 4;
    if ((s16) W(0x24) >= 0) goto next_60;
    W(0x24) = 4;
next_60:
    func_001486D0();
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
    reg_d0.h[0] = W(0x2C);
    reg_d1.h[0] = W(0x2E);
    W(2) += reg_d0.h[0];
    W(4) += reg_d1.h[0];
    reg_tmp.h[1] = W(0x1E);
    reg_tmp.h[0] = W(0x20);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    func_001486D0();
    goto block_rts;
next_200:
    if (D_0028E928 == 0) goto next_220;
    reg_d0.w = 0x14;
    func_00209F20();
next_220:
    reg_d0.h[0] = W(0x2C);
    reg_d2.h[0] = W(0x2E);
    W(2) += reg_d0.h[0];
    W(4) += reg_d2.h[0];
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 2;
    reg_d2.h[0] = (s16) reg_d2.h[0] >> 2;
    W(0x2C) = reg_d0.h[0];
    W(0x2E) = reg_d2.h[0];
    func_0018DA70();
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) D_00254A50;
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
