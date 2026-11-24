#include "common.h"
#include "sdk/ps2sdk.h"

void func_0014BE20(void);
void func_0014CAE0(void);

s32 func_0019D530();                            /* extern */
extern s32 reg_a0_as_s32;
extern s32 reg_a6_as_s32;

void func_001486D0(void) {
    reg_a0_as_s32 = reg_a6_as_s32;
    func_0014BE20();
    func_0019D530();
}

void func_00148700(void) {
    reg_a0_as_s32 = reg_a6_as_s32;
    func_0014BE20();
    func_0019D530();
}

s32 func_0019D560();
extern u16 D_00257800[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_00148730(void) {
    u32 temp_s0;

    temp_s0 = reg_d6.w;
    reg_d6.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2A)));
    reg_a0 = (u8 *)(D_00257800);
    reg_d6.h[0] *= 2;
    reg_d6.h[1] = (reg_d6.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d6.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d6.h[0] = ((reg_d6.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d6.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    func_0019D560();
    reg_d6.w = temp_s0;
    reg_a0 = (u8 *)(reg_a6);
    func_0014BE20();
}

s32 func_00201330();                            /* extern */

void func_00148800(void) {
    func_00201330();
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d0.h[0] += reg_d1.h[0];
    func_00201330();
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d2.h[0] += reg_d1.h[0];
}

s32 func_00201330();

void func_00148860() {
    func_00201330();
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 2);
    (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d1.h[0];
    func_00201330();
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 2);
    (*(u16 *)((u8 *)(reg_a6) + (4))) += reg_d1.h[0];
}

typedef void (*Fn)();

extern u8 D_00257820[];
extern u16 D_0028DFE8;
extern u16 D_0028E470;
extern u8 D_0028E5F8_as_u8;
extern u8 D_0028E5FC_as_u8;
extern u16 D_0029C06C[];
extern u8 D_0029E390[];
extern u8 D_0029F1F0_as_u8_a[];
extern u8 D_0029F260_as_u8_a[];
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_001488C0(void) {
    u8 *saved_a4;
    u8 *saved_a5;
    u32 t;

    reg_a6 = (u8 *)D_0029E390;
    reg_d6.h[0] = D_0029C06C[0];
    D_0028DFE8 = 0;
    saved_a4 = reg_a4;
    saved_a5 = reg_a5;
    reg_a4 = (u8 *)D_0029F260_as_u8_a;
    reg_a5 = &D_0028E5FC_as_u8;
    D_0028E470 = reg_d6.h[0];
    reg_d6.h[0] = 1;
    reg_d6.h[1] = D_0028E470;
loop_1:
    D_0028E470 = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = D_0028E470;
    reg_d7.w = 0x23;
loop_2:
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0);
    if (reg_d1.h[0] == 0) goto next_1;
    D_0028DFE8 += 1;
    *(u16 *)(reg_a6 + 4) -= reg_d6.h[0];
    reg_d0.w = 0xF;
    reg_d0.h[0] &= reg_d1.h[0];
    ((Fn)*(u32 *)((u8 *)D_00257820 + (reg_d0.h[0] * 4)))();
next_1:
    reg_a6 += 0x30;
    t = reg_d7.h[0] - 1;
    reg_d7.h[0] = t;
    if (((s64) ((s64) (u16) t << 0x30) >> 0x30) >= 0) goto loop_2;
    reg_a4 = (u8 *)D_0029F1F0_as_u8_a;
    reg_a5 = &D_0028E5F8_as_u8;
    D_0028E470 = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = D_0028E470;
    t = reg_d6.h[0] - 1;
    reg_d6.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_a4 = saved_a4;
    reg_a5 = saved_a5;
}

s32 func_0018DA70();
s32 func_00201E20();
s32 func_00209F20();
extern u16 D_00253940[];
extern u16 D_002539B0[];
extern Reg32 D_0028E484;
extern u16 D_0028E928;

void func_00148A40(void) {
    if (reg_d0.h[0] != 0) goto block_main;
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0);
    *(u8 *)(reg_a6 + 0) |= 0x40;
    if (!(reg_tmp.b[0] & 0x40)) goto block_obj;
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 1);
    *(u8 *)(reg_a6 + 1) |= 1;
    if (reg_tmp.b[0] & 1) goto block_first;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x30);
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0x32);
    *(u16 *)(reg_a6 + 2) += reg_d0.h[0];
    *(u16 *)(reg_a6 + 4) += reg_d1.h[0];
block_obj:
    *(u8 *)(reg_a6 + 0x1D) ^= 0x40;
    func_001486D0();
    return;
block_first:
    *(u16 *)(reg_a6 + 0) |= 8;
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1B);
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x1A);
    func_00201E20();
    *(u16 *)(reg_a6 + 0x2C) = reg_d2.h[0];
    *(u16 *)(reg_a6 + 0x2E) = reg_d3.h[0];
    if (*(s8 *)(reg_a6 + 0) < 0) goto block_touch;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x26);
    reg_a0 = (u8 *)D_00253940;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)reg_tmp.w;
    *(u16 *)(reg_a6 + 6) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0xE) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 2) += reg_d0.h[0];
    *(u8 *)(reg_a6 + 1) &= 0xFE;
    goto block_anim;
block_clr:
    *(u16 *)(reg_a6 + 0) = 0;
    return;
block_anim:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2C);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x2E);
    *(u16 *)(reg_a6 + 2) += reg_d0.h[0];
    if ((s32)*(u16 *)(reg_a6 + 2) >= 0x8000) goto block_clr;
    *(u16 *)(reg_a6 + 4) += reg_d1.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 4);
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0xC000;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x400;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] += 0xC000;
    if ((s32)reg_tmp.h[0] > 0x4000) goto block_clr;
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x1E);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    *(u16 *)(reg_a6 + 0xA) = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if (*(s16 *)(reg_a6 + 0x24) >= 0) goto skip_1;
    *(u16 *)(reg_a6 + 0x24) = 4;
skip_1:
    func_001486D0();
    return;
block_main:
    if (reg_d1.sb[0] >= 0) goto block_anim;
block_touch:
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 1);
    *(u8 *)(reg_a6 + 1) |= 2;
    if (!(reg_tmp.b[0] & 2)) goto block_touch_first;
loop_1:
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x24);
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if ((s32)reg_tmp.h[0] < 4) goto block_clr;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2C);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x2E);
    *(u16 *)(reg_a6 + 2) += reg_d0.h[0];
    *(u16 *)(reg_a6 + 4) += reg_d1.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x1E);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    *(u16 *)(reg_a6 + 0xA) = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    func_001486D0();
    return;
block_touch_first:
    if (D_0028E928 == 0) goto skip_2;
    reg_d0.w = 0x14;
    func_00209F20();
skip_2:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2C);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x2E);
    if (!(*(u8 *)(reg_a6 + 1) & 1)) goto skip_4;
    reg_d3.h[0] = 8;
    if (!(*(u8 *)(reg_a6 + 0x28) & 4)) goto skip_3;
    reg_d3.h[0] = 0xA;
    if (*(u16 *)(reg_a6 + 0x2A) != reg_d3.h[0]) goto skip_4;
skip_3:
    *(u16 *)(reg_a6 + 2) -= 0x200;
skip_4:
    func_00148800();
    *(u16 *)(reg_a6 + 2) += reg_d0.h[0];
    *(u16 *)(reg_a6 + 4) += reg_d2.h[0];
    reg_d0.h[0] = (s16)reg_d0.h[0] >> 2;
    reg_d2.h[0] = (s16)reg_d2.h[0] >> 2;
    *(u16 *)(reg_a6 + 0x2C) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x2E) = reg_d2.h[0];
    func_0018DA70();
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x26);
    reg_a0 = (u8 *)D_002539B0;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)reg_tmp.w;
    *(u16 *)(reg_a6 + 6) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0xE) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x1E) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x20) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x22) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x24) = *(u16 *)reg_a0;
    reg_a0 += 2;
    goto loop_1;
}

extern u16 D_002541A0[];
extern u16 D_00254210[];

#define W(o) (*(u16 *)(reg_a6 + (o)))

void func_00149160(void) {
    if (reg_d0.h[0] != 1) goto next_100;
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
    reg_a0 = (u8 *) D_002541A0;
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
    reg_d0.h[0] = W(0x2C);
    reg_d1.h[0] = W(0x2E);
    W(2) += reg_d0.h[0];
    if (!((s32) W(2) < 0x7800)) goto block_clr;
    W(4) += reg_d1.h[0];
    reg_d0.h[0] = W(4);
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0xB800;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x800;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] += 0xB800;
    if (!((s32) reg_tmp.h[0] < 0x4801)) goto block_clr;
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
    func_00148730();
    goto block_rts;
next_200:
    if (D_0028E928 == 0) goto next_220;
    reg_d0.w = 0x14;
    func_00209F20();
next_220:
    reg_d0.h[0] = W(0x2C);
    reg_d2.h[0] = W(0x2E);
    if (!(reg_a6[1] & 1)) goto next_240;
    reg_d3.h[0] = 8;
    if (!(reg_a6[0x28] & 4)) goto next_230;
    reg_d3.h[0] = 0xA;
    if (W(0x2A) != reg_d3.h[0]) goto next_240;
next_230:
    W(2) += 0x300;
next_240:
    func_00148800();
    W(2) += reg_d0.h[0];
    W(4) += reg_d2.h[0];
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 2;
    reg_d2.h[0] = (s16) reg_d2.h[0] >> 2;
    W(0x2C) = reg_d0.h[0];
    W(0x2E) = reg_d2.h[0];
    func_0018DA70();
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) D_00254210;
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

extern u16 D_0025CAE0[];
extern u16 D_0025CD00[];

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

extern u16 D_0025D470[];
extern u16 D_0025D690[];

#define W(o) (*(u16 *)(reg_a6 + (o)))

void func_00149E20(void) {
    if (reg_d0.h[0] != 3) goto next_100;
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
    reg_a0 = (u8 *) D_0025D470;
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
    if (!((s32) W(2) < 0x7400)) goto block_clr;
    W(4) += reg_d1.h[0];
    reg_d0.h[0] = W(4);
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0xBC00;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x600;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] += 0xBC00;
    if (!((s32) reg_tmp.h[0] < 0x4401)) goto block_clr;
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
    reg_a0 = (u8 *) D_0025D690;
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

extern u16 D_002549E0[];
extern u16 D_00254A50[];

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

extern u16 D_00255180[];
extern u16 D_002551F0[];

#define W(o) (*(u16 *)(reg_a6 + (o)))

void func_0014AAA0(void) {
    if (reg_d0.h[0] != 5) goto next_100;
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
    reg_a0 = (u8 *) D_00255180;
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
    reg_a0 = (u8 *) D_002551F0;
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

extern u16 D_0025DE10[];
extern u16 D_0025E010[];

#define W(o) (*(u16 *)(reg_a6 + (o)))

void func_0014B180(void) {
    if (reg_d0.h[0] != 6) goto next_100;
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
    reg_a0 = (u8 *) D_0025DE10;
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
    D_0028E484.h[0] = 0xB400;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0xA00;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] += 0xB400;
    if (!((s32) reg_tmp.h[0] < 0x4C01)) goto block_clr;
    reg_tmp.h[1] = W(0x1E);
    reg_tmp.h[0] = W(0x20);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    W(0x24) -= 4;
    if ((s16) W(0x24) >= 0) goto next_60;
    W(0x24) = 8;
next_60:
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
    func_00148700();
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
    reg_a0 = (u8 *) D_0025E010;
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

extern u16 D_0025E790[];
extern u16 D_0025E990[];

#define W(o) (*(u16 *)(reg_a6 + (o)))

void func_0014B7D0(void) {
    if (reg_d0.h[0] != 7) goto next_100;
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
    reg_a0 = (u8 *) D_0025E790;
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
    D_0028E484.h[0] = 0xB400;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0xA00;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] += 0xB400;
    if (!((s32) reg_tmp.h[0] < 0x4C01)) goto block_clr;
    reg_tmp.h[1] = W(0x1E);
    reg_tmp.h[0] = W(0x20);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    W(0x24) -= 4;
    if ((s16) W(0x24) >= 0) goto next_60;
    W(0x24) = 8;
next_60:
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
    func_00148700();
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
    reg_a0 = (u8 *) D_0025E990;
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

void func_0014BE20(void) {
}

s32 func_001A5A80();
s32 func_001AEA80();
s32 func_002075F0();
extern u8 D_0028E370;
extern s16 D_0028E598_as_s16;
extern u16 g_stage;
extern u8 D_0028ED7C;

void func_0014BE30(void) {
    switch (reg_a5[3]) {
    case 0:
        goto block_1;
    }
    if (reg_a5[3] == 2) goto block_2;
    func_001AEA80();
    if (D_0028ED7C != 2) goto next_1;
    if (g_stage != 0) goto next_1;
    if (D_0028E370 == 0) return;
next_1:
    func_001A5A80();
    return;
block_1:
    reg_a5[3] = 1;
    D_0028E598_as_s16 = 1;
    return;
block_2:
    D_0028E598_as_s16 = 0;
    func_002075F0();
}

s32 func_0012FA80();
s32 func_0012FAB0();
s32 func_0012FB00();
s32 func_0013B2E0(s32, s32, s32, s32);
s32 stage_map_reset();
extern u8 D_0026A3F0[];
extern u8 D_0028E368;
extern u8 D_0028E378;
extern u8 D_0028ED74;

void func_0014BEC0(void) {
    D_0028ED74 = 2;
    D_0028E378 = 0xFF;
    D_0028E368 = 0;
    func_0012FA80();
    func_0012FAB0();
    func_0012FB00();
    stage_map_reset();
    (*(s8 *)((u8 *)(reg_a5) + (3))) = 1;
    (*(s16 *)((u8 *)(reg_a5) + (8))) = 0x4400;
    (*(s16 *)((u8 *)(reg_a5) + (0xA))) = 0x1C00;
    (*(s16 *)((u8 *)(reg_a5) + (0x14))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x12))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x10))) = 0;
    (*(s8 *)((u8 *)(reg_a5) + (0x17))) = 1;
    (*(s8 *)((u8 *)(reg_a5) + (0x16))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x18))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (4))) = 0x1E0;
    reg_a0 = D_0026A3F0;
    func_0013B2E0(0x1E0, 0x1C00, 0x4400, 1);
    (*(s16 *)((u8 *)(reg_a5) + (0x1A))) = 0x20;
    (*(s16 *)((u8 *)(reg_a5) + (0x1C))) = 0x20;
}

s32 func_001353E0();
s32 func_0013B190();
s32 func_002071C0();

void func_0014BF90() {
    (*(u16 *)((u8 *)(reg_a5) + (0x1C))) -= 1;
    if ((*(u16 *)((u8 *)(reg_a5) + (0x1C))) == 0) {
        reg_d0.w = 0;
        reg_d1.h[0] = 6;
        func_001353E0();
        func_0013B190();
        reg_d0.h[0] = 0xC;
        func_002071C0();
        func_002075F0();
    }
}

s32 func_00133070();
s32 func_0018D410();
s32 func_0019C470();
s32 func_00201160();
s32 func_0022B660();
s32 func_002376F0();
extern u16 D_0026A380[];
extern u16 D_0026A3A0[];
extern u16 D_0026A3C0[];
extern u8 D_0028ED64;
extern u8 D_0028ED80;

void func_0014BFF0(void) {
    u16 t;
    u8 st;

    st = *(u8 *)(reg_a5 + 3);
    if (st == 0) {
        func_0014BEC0();
        return;
    }
    if (st == 2) {
        if ((D_0028ED64 != 0) && (func_00133070(reg_a5) != 0)) {
            if (func_0022B660() == 0) {
                return;
            }
            goto block_1;
        }
        if ((D_0028ED7C == 2) || (D_0028ED80 != 0)) {
            func_002376F0();
            return;
        }
block_1:
        D_0028ED7C = 0;
        func_0014BF90();
        return;
    }
    t = *(u16 *)(reg_a5 + 0x1A);
    if (t == 0) goto next_1;
    *(u16 *)(reg_a5 + 0x1A) = t - 1;
    if (*(u16 *)(reg_a5 + 0x1A) != 0) goto next_1;
    func_0018D410();
next_1:
    *(u16 *)(reg_a5 + 4) -= 1;
    if ((s16) *(u16 *)(reg_a5 + 4) >= 0) goto next_2;
    *(u8 *)(reg_a5 + 3) = 2;
next_2:
    if (*(u16 *)(reg_a5 + 0x10) != 0) goto next_6;
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x12);
    *(u8 *)(reg_a5 + 0x15) -= 1;
    if ((s8) *(u8 *)(reg_a5 + 0x15) >= 0) goto next_3;
    *(u8 *)(reg_a5 + 0x15) = *(u8 *)(reg_a5 + 0x14);
    *(u16 *)(reg_a5 + 0x12) += 4;
    if (reg_d1.h[0] != 0x1C) goto next_3;
    *(u16 *)(reg_a5 + 0x12) = 0;
    *(u16 *)(reg_a5 + 0x18) += 1;
    if (*(u16 *)(reg_a5 + 0x18) == 0x14) goto next_5;
    func_00201160();
    reg_d0.h[0] >>= 3;
    st = reg_d0.b[0];
    *(u8 *)(reg_a5 + 0x17) = st;
    if (st != 0) goto next_3;
    *(u8 *)(reg_a5 + 0x16) += 1;
    if ((s32) *(u8 *)(reg_a5 + 0x16) < 3) goto next_3;
    *(u8 *)(reg_a5 + 0x17) = 1;
next_3:
    reg_a0 = (u8 *)(D_0026A380);
    if (*(u8 *)(reg_a5 + 0x17) != 0) goto next_4;
    reg_a0 = (u8 *)(D_0026A3A0);
next_4:
    *(u16 *)(reg_a5 + 0xC) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0xE) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    goto next_8;
next_5:
    *(u16 *)(reg_a5 + 0x10) = 1;
    *(u16 *)(reg_a5 + 0x14) = 0;
next_6:
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x12);
    *(u8 *)(reg_a5 + 0x15) -= 1;
    if ((s8) *(u8 *)(reg_a5 + 0x15) >= 0) goto next_8;
    *(u8 *)(reg_a5 + 0x15) = *(u8 *)(reg_a5 + 0x14);
    *(u16 *)(reg_a5 + 0x12) += 4;
    if (reg_d0.h[0] != 0x1C) goto next_7;
    *(u16 *)(reg_a5 + 0x12) = 0;
    *(u8 *)(reg_a5 + 3) = 2;
next_7:
    reg_a0 = (u8 *)(D_0026A3C0);
    *(u16 *)(reg_a5 + 0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0xE) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
next_8:
    reg_d1.h[1] = *(u16 *)(reg_a5 + 8);
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0xA);
    reg_d1.w += 0xE600E400;
    reg_d2.h[1] = *(u16 *)(reg_a5 + 0xC);
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0xE);
    reg_d3.h[0] = 0x1AE0;
    reg_d4.h[0] = 2;
    func_0019C470();
}

extern u16 D_00252740[];
extern u16 D_0028E914;

void func_0014C3B0(void) {
    reg_a0 = (u8 *)(D_00252740);
    reg_d0.h[0] = D_0028E914;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
}

extern u8 D_002526B0[];
extern u8 D_0029BF50[];
extern s32 D_0029C050_as_s32_a[];

void func_0014C450(void) {
    memset(D_0029BF50, 0, 0x104);
    reg_a0 = D_002526B0;
    reg_a0 += D_0028E914;
    D_0029C050_as_s32_a[0] = *(s32 *)reg_a0;
}

extern u8 D_0028E2C0;
extern u8 *jtbl_0028E3F4_as_u8_p;
extern u8 *reg_a1;

void func_0014C4B0(void) {
    u32 temp_s0;

    if ((D_0028ED80 == 0) || (D_0028E2C0 == 0) || (g_stage != 2)) {
        reg_a6 = D_0029BF50;
        reg_d7.w = 7;
        do {
            if ((*(u8 *)((u8 *)(reg_a6) + (1))) != 0) {
                reg_d0.h[0] = D_0029C06C[0];
                (*(u16 *)((u8 *)(reg_a6) + (4))) -= reg_d0.h[0];
                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (8)));
                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
                reg_a1 = (u8 *)reg_tmp.w;
                jtbl_0028E3F4_as_u8_p = reg_a1;
                temp_s0 = reg_d7.w;
                ((Fn)jtbl_0028E3F4_as_u8_p)();
                reg_d7.w = temp_s0;
            }
            reg_a6 += 0x20;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
}

typedef void (*Fn)(void);

extern u8 *D_0029C050[];
extern Fn jtbl_0028E3F4_as_Fn;
extern u8 *reg_a2;
extern u8 *reg_a3;

void func_0014C590(void) {
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u32 t1;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    reg_a6 = (u8 *)D_0029BF50;
    reg_d7.w = 7;
loop_1:
    if (*(u8 *)(reg_a6 + 1) != 0) goto next_1;
    *(u8 *)(reg_a6 + 1) = 0x80;
    *(u16 *)(reg_a6 + 2) = reg_d1.h[1];
    *(u16 *)(reg_a6 + 4) = reg_d1.h[0];
    reg_a1 = D_0029C050[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a1 += reg_d0.h[0];
    reg_a1 = *(u8 **)reg_a1;
    jtbl_0028E3F4_as_Fn = (Fn)reg_a1;
    jtbl_0028E3F4_as_Fn();
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
    return;
next_1:
    reg_a6 += 0x20;
    t1 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t1;
    if (((s64)((s64)(u16)t1 << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}

extern u16 D_0028E8A8;
extern u8 D_0029C082[];

void func_0014C7B0(void) {
    reg_a0 = (u8 *)D_0029C082;
    reg_a1 = reg_a5 + 0xA;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0xC)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0xE)));
    reg_a2 = (u8 *)reg_tmp.w;
    if (reg_a2 == 0) return;
    (*(u16 *)((u8 *)(reg_a0) + (0x16))) -= 1;
    if (0 >= (s16) (*(u16 *)((u8 *)(reg_a0) + (0x16)))) {
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0x10)));
        if ((s16) reg_d0.h[0] != -1) {
            (*(u16 *)((u8 *)(reg_a0) + (0x10))) -= 1;
            if (0 >= (s16) (*(u16 *)((u8 *)(reg_a0) + (0x10)))) {
                (*(u16 *)((u8 *)(reg_a0) + (0xC))) = 0U;
                (*(u16 *)((u8 *)(reg_a0) + (0xE))) = 0U;
                (*(s16 *)((u8 *)(reg_a5) + (8))) = 0;
                D_0028E8A8 = (*(u16 *)((u8 *)(reg_a0) + (0x18)));
                return;
            }
        }
        (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) (*(u16 *)((u8 *)(reg_a0) + (0x14)));
        reg_tmp.w = (u32)reg_a2;
        (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) reg_tmp.h[0];
    }
}

extern s16 D_0029C080_as_s16_a[];
extern s16 D_0029C08E[];
extern s16 D_0029C090[];
extern u8 D_0029C09E[];
extern s16 D_0029C0AA[];
extern s16 D_0029C0AC[];

void func_0014C8A0(void) {
    u8 *var_a0;
    u32 temp_s0;
    u32 temp_s1;

    func_0014C3B0();
    memset(D_0029C080_as_s16_a, 0, 0x40);
    reg_a1 = (u8 *)D_0029C082;
    reg_d1.w = 1;
    var_a0 = (u8 *)(D_0029C09E);
    do {
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_tmp.h[0] = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a2 = (u8 *)(reg_tmp.w);
        (*(u16 *)((u8 *)(reg_a1) + (4))) = *(u16 *)reg_a2;
        reg_a2 += 2;
        (*(u16 *)((u8 *)(reg_a1) + (6))) = *(u16 *)reg_a2;
        reg_a2 += 2;
        (*(u16 *)((u8 *)(reg_a1) + (8))) = *(u16 *)reg_a2;
        reg_a2 += 2;
        (*(u16 *)((u8 *)(reg_a1) + (0xA))) = *(u16 *)reg_a2;
        reg_a2 += 2;
        reg_tmp.w = (u32)reg_a2;
        (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) reg_tmp.h[0];
        reg_a1 = (u8 *)D_0029C09E;
    } while ((s16)(--reg_d1.h[0]) >= 0);
    if (D_0028E8A8 != 0) {
        D_0029C080_as_s16_a[0] = 1;
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x10)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x12)));
        reg_a3 = (u8 *)reg_tmp.w;
        temp_s0 = (u32)reg_a3;
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0xA)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0xC)));
        reg_d7.w = 0;
        reg_a4 = (u8 *)reg_tmp.w;
        temp_s1 = (u32)reg_a4;
        do {
            func_0014CAE0();
            var_a0 = (u8 *) D_0028E8A8;
            reg_d7.h[0] += 1;
        } while ((u32)var_a0 != reg_d7.h[0]);
        reg_tmp.w = temp_s0;
        reg_a4 = (u8 *)temp_s1;
        reg_a3 = (u8 *)temp_s0;
        (*(u16 *)((u8 *)(reg_a5) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a5) + (0x12))) = (u16) reg_tmp.h[0];
        reg_tmp.w = (u32)reg_a4;
        (*(u16 *)((u8 *)(reg_a5) + (0xA))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a5) + (0xC))) = (u16) reg_tmp.h[0];
        reg_d0.w = 0;
        (*(s16 *)((u8 *)(reg_a5) + (8))) = 0;
        D_0029C08E[0] = 0;
        D_0029C090[0] = 0;
        D_0029C0AA[0] = 0;
        D_0029C0AC[0] = 0;
    }
    D_0029C080_as_s16_a[0] = 0;
}


void func_0014CAD0(void) {
    reg_d7.h[0] = D_0028E8A8;
    func_0014CAE0();
}

extern u8 D_002526D0[];
extern u16 D_0029C0BA[];
extern u16 D_0029C0BC[];
extern u16 D_0029C0BE[];
extern void (*jtbl_0028E3F4)();

void func_0014CAE0(void) {
    u16 temp_a0;
    reg_a6 = (u8 *)D_0029C082;
    reg_d6.w = 1;
    do {
loop_1:
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_a1 = (u8 *)(reg_tmp.w);
        reg_d1.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        if (((s16)(reg_d1.h[0]) != -1) && ((reg_d1.h[0] & 0xFFFF) == reg_d7.h[0])) {
            reg_a1 += 2;
            temp_a0 = *(u16 *)reg_a1;
            reg_d2.h[0] = temp_a0;
            reg_a1 += 2;
            reg_a2 = (u8 *)D_002526D0;
            reg_a2 += reg_d2.h[0];
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a2) + (0)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a2) + (2)));
            reg_a2 = (u8 *) reg_tmp.w;
            jtbl_0028E3F4 = (Fn)(reg_a2);
            jtbl_0028E3F4();
            reg_tmp.w = (u32)reg_a1;
            (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[0];
            goto loop_1;
        }
        reg_a6 = (u8 *)D_0029C09E;
    } while ((s16)(--reg_d6.h[0]) >= 0);
    reg_d0.h[1] = D_0029C0BC[0];
    reg_d0.h[0] = D_0029C0BE[0];
    if (reg_d0.w != 0) {
        D_0029C0BA[0] -= 1;
        if (0 > (s16) D_0029C0BA[0]) {
            reg_a0 = (u8 *)reg_d0.w;
            jtbl_0028E3F4 = (Fn)((u8 *) reg_a0);
            jtbl_0028E3F4();
            *(u32 *)D_0029C0BC = 0;
        }
    }
}

s32 func_001A3020();

void func_0014CC90(void) {
    u16 temp_a1;

    reg_d2.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (6)));
    reg_a2 = (u8 *)(reg_tmp.w);
loop_1:
    reg_tmp.h[1] = *(u16 *)reg_a2;
    reg_a2 += 2;
    temp_a1 = *(u16 *)reg_a2;
    reg_tmp.h[0] = temp_a1;
    reg_a2 += 2;
    reg_a0 = (u8 *)reg_tmp.w;
    if ((u32)reg_a0 != -1U) {
        reg_d0.h[0] = *(u16 *)reg_a2;
        reg_a2 += 2;
        func_001A3020();
        reg_d2.h[0] -= 1;
        if (reg_d2.h[0] == 0) {
            reg_tmp.w = (u32)reg_a2;
            (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) reg_tmp.h[0];
        } else {
            goto loop_1;
        }
    }
}

void func_0014CD70(void) {
    reg_a2 = reg_a5 + 0x10;
    if (reg_d6.h[0] != 0) {
        reg_a2 = reg_a5 + 0xA;
    }
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a2) + (0)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a2) + (2)));
    reg_a3 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] = reg_d0.h[0];
    reg_d2.h[0] = reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[0] = (s16) reg_d1.h[0] << 5;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[0] += reg_d0.h[0];
    reg_a3 += (s16) reg_d1.h[0];
    reg_tmp.w = (u32)reg_a3;
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xE))) = (u16) reg_tmp.h[0];
    reg_tmp.w = (u32)reg_a3;
    (*(u16 *)((u8 *)(reg_a2) + (0))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a2) + (2))) = (u16) reg_tmp.h[0];
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    (*(u16 *)((u8 *)(reg_a6) + (0x14))) = (u16) reg_d0.h[0];
    reg_d0.h[0] += 1;
    (*(u16 *)((u8 *)(reg_a6) + (0x16))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
}

extern u16 *reg_a1_as_u16_p;
extern u16 *reg_a2_as_u16_p;
extern s32 reg_a5_as_s32;

void func_0014CEA0(void) {
    reg_a2_as_u16_p = (u16 *)(reg_a5_as_s32 + 0x22);
    if (reg_d6.h[0] != 0) {
        reg_a2_as_u16_p = (u16 *)(reg_a5_as_s32 + 0x1C);
    }
    *reg_a2_as_u16_p = *reg_a1_as_u16_p;
    reg_a1_as_u16_p += 1;
}

extern u16 *reg_a6_as_u16_p;
extern u16 *reg_a5_as_u16_p;

void func_0014CEE0(void) {
    reg_a5_as_u16_p[4] = 1;
    reg_d0.h[0] = D_0028E8A8;
    reg_d0.h[0] += 4;
    reg_a6_as_u16_p[12] = (u16) reg_d0.h[0];
}

extern u16 D_0029C066[];
extern u16 D_0029C080[];

void func_0014CF10(void) {
    u16 *temp_a0;
    u16 temp_a1;

    reg_d0.h[0] = *reg_a1_as_u16_p;
    reg_a1_as_u16_p += 1;
    reg_d1.h[1] = *reg_a1_as_u16_p;
    reg_a1_as_u16_p += 1;
    temp_a1 = *reg_a1_as_u16_p;
    temp_a0 = reg_a1_as_u16_p + 1;
    reg_d1.h[0] = temp_a1;
    reg_a1_as_u16_p = temp_a0;
    if (D_0029C080[0] == 0) {
        reg_d1.h[0] -= 0x800;
        reg_d1.h[0] -= D_0029C066[0];
        func_0014C590();
    }
}

extern u8 D_002526F0[];

void func_0014CF90(void) {
    u32 temp_a1;
    reg_d2.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (8)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
    reg_a2 = (u8 *)(reg_tmp.w);
loop_1:
    reg_d0.h[0] = *(u16 *)reg_a2;
    temp_a1 = reg_d0.h[0];
    reg_a2 += 2;
    if ((s16)(temp_a1) != -1) {
        reg_a3 = (u8 *)D_002526F0;
        reg_d0.h[0] = temp_a1 + temp_a1;
        reg_d0.h[0] += reg_d0.h[0];
        reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
        reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a3;
        reg_a3 = (u8 *) reg_tmp.w;
        jtbl_0028E3F4 = (Fn)(reg_a3);
        jtbl_0028E3F4();
        reg_d2.h[0] -= 1;
        if (reg_d2.h[0] == 0) {
            reg_tmp.w = (u32)reg_a2;
            (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[0];
        } else {
            goto loop_1;
        }
    }
}

void func_0014D0F0(void) {
    D_0029C0BA[0] = *reg_a2_as_u16_p;
    reg_a2_as_u16_p += 1;
    D_0029C0BC[0] = *reg_a2_as_u16_p;
    reg_a2_as_u16_p += 1;
    D_0029C0BE[0] = *reg_a2_as_u16_p;
    reg_a2_as_u16_p += 1;
}

void func_0018DEE0(void);

void func_0014D140(void) {
    func_0018DEE0();
}

extern void func_0018DED0(void);

void func_0014D150(void) {
    reg_d1.h[0] = *reg_a2_as_u16_p;
    reg_a2_as_u16_p++;
    func_0018DED0();
}

extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s16 D_0029976C_as_s16_a[];
extern s16 D_0029976E_as_s16_a[];

void func_0014D170(void) {
    reg_d0.h[0] = *reg_a1_as_u16_p;
    reg_a1_as_u16_p += 1;
    if (reg_d0.h[0] == 1) {
        D_00299768[0] = 1;
    }
    if (reg_d0.h[0] == 2) {
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
    }
    if (reg_d0.h[0] == 3) {
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
        D_0029976C_as_s16_a[0] = 1;
    }
    if (reg_d0.h[0] == 4) {
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
        D_0029976C_as_s16_a[0] = 1;
        D_0029976E_as_s16_a[0] = 1;
    }
}
