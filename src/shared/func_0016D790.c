#include "common.h"

typedef void (*Fn)();

extern u8 D_0025B1C0[];
extern u8 D_0025B2C0[];
extern u8 D_0025B3C0[];
extern s8 D_0028E408;

s32 func_00128970();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_0016CEA0();
s32 func_0016CF40();
s32 func_0016CFB0();
s32 func_0016D040();
s32 func_0018D4E0();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_00202140();
s32 func_00202500();
extern u8 D_0025B130[];
extern u8 D_0025B140[];
extern u16 D_0028E3EC;
extern u16 D_0028E3F0;
extern Reg32 D_0028E484;
extern u16 D_0028E894;
extern u16 D_0028E8A0;
extern u16 D_0028E8C8;
extern u16 D_0028E8D0;
extern u16 D_0028E91C;
extern u16 D_0029C068[];
extern s8 enemy_move_end_requested;
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0016D790(void) {
    func_0014EA50();
    if (enemy_move_end_requested != 0) goto block_rts;
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    D_0028E484.w = 0;
    reg_d0.h[0] += 0x1200;
    reg_tmp.w = 0;
    reg_d0.h[0] += D_0029C068[0];
    D_0028E484.h[0] = 0xA400;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += D_0028E484.w;
    reg_d0.h[0] += 0xA400;
    if (reg_tmp.h[1] != 0) goto block_a;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    if ((*(u8 *)((u8 *)(reg_a5) + (0x33))) == 0) goto next_1;
    if (!((s32) reg_d0.h[0] < 0x7600)) goto next_1;
    (*(u8 *)((u8 *)(reg_a5) + (0x33))) = 0;
next_1:
    D_0028E484.w = 0;
    reg_tmp.w = 0;
    D_0028E484.h[0] = 0x7C00;
    reg_d0.h[0] += 0xA00;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += D_0028E484.w;
    reg_d0.h[0] += 0x7C00;
    if (reg_tmp.h[1] == 0) goto next_2;
block_a:
    if ((*(u16 *)((u8 *)(reg_a5) + (0x16))) == 0) goto next_3;
    func_0014E290();
    return;
next_2:
    (*(u16 *)((u8 *)(reg_a5) + (0x16))) = 1;
next_3:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (1)));
    switch (reg_d1.b[0]) { case 0: goto next_4; }
    (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xA3;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x34)));
    (*(u8 *)((u8 *)(reg_a6) + (0x1C))) ^= reg_d0.b[0];
    func_001A9000();
    if ((*(s16 *)((u8 *)(reg_a6) + (0x18))) >= 0) goto next_5;
    if ((*(s8 *)((u8 *)(reg_a5) + (0x21))) < 0) goto block_e;
    (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xFD;
    (*(u16 *)((u8 *)(reg_a6) + (0x18))) = (*(u16 *)((u8 *)(reg_a5) + (0x26)));
    reg_d0.w = 8;
    func_001A91A0();
    (*(u8 *)((u8 *)(reg_a5) + (0x21))) |= 0x80;
    reg_d0.w = 3;
    reg_a1 = (u8 *)D_0025B140;
    func_0016CEA0();
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xFE00;
    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
    goto next_5;
next_4:
    (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (*(u8 *)((u8 *)(reg_a5) + (0x35)));
next_5:
    if (D_0028E8A0 != 0) goto next_7;
    reg_d7.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1A)));
    reg_d1.w = 0x3E;
    reg_d1.h[0] &= reg_d7.h[0];
    reg_d1.h[0] *= 4;
    if (reg_d7.h[0] & 0x40) goto next_6;
    if (!(D_0028E3F0 & 4)) goto next_6;
    reg_d1.h[0] += 4;
next_6:
    reg_a0 = (u8 *)D_0025B2C0;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
next_7:
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x2A)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x2C)));
    reg_a0 = (u8 *) reg_tmp.w;
    jtbl_0028E3F4 = (Fn)(reg_a0);
    jtbl_0028E3F4();
    reg_a0 = reg_a6;
    func_0014D220();
    if ((*(s8 *)((u8 *)(reg_a5) + (0x21))) >= 0) goto block_b;
    if (D_0028E3EC == 0) goto block_rts;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.w += 0xFE00;
    func_0016CFB0();
    goto block_rts;
block_b:
    if (D_0028E8A0 != 0) goto block_c;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x32)));
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
    (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_8;
    (*(u8 *)((u8 *)(reg_a5) + (0x19))) = (*(u8 *)((u8 *)(reg_a5) + (0x18)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.h[0] += 0x200;
    func_00202140();
    if (D_0028E408 != 0) goto block_c;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x32)));
    func_00202500();
    (*(u8 *)((u8 *)(reg_a5) + (0x32))) = reg_d1.b[0];
    reg_a0 = (u8 *)D_0025B3C0;
    reg_d1.b[0] += 1;
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    (*(u16 *)((u8 *)(reg_a5) + (0x22))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    (*(u16 *)((u8 *)(reg_a5) + (0x24))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
next_8:
    if (!((*(u8 *)((u8 *)(reg_a6) + (1))) & 0x20)) goto block_c;
    (*(u8 *)((u8 *)(reg_a5) + (0x29))) -= 1;
    if ((*(u8 *)((u8 *)(reg_a5) + (0x29))) == 0) goto block_d;
block_c:
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.w += 0xFA00FA00;
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x22)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x24)));
    reg_d3.h[0] = 0x830;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x2E)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x30)));
    reg_a0 = (u8 *) reg_tmp.w;
    jtbl_0028E3F4 = (Fn)(reg_a0);
    jtbl_0028E3F4();
    goto block_rts;
block_d:
    reg_d0.w = 0x18;
    reg_d0.h[0] -= D_0028E8C8;
    (*(u8 *)((u8 *)(reg_a5) + (0x29))) = reg_d0.b[0];
    func_0016D040();
    if (D_0028E408 != 0) goto block_c;
    if (D_0028E91C != 1) goto next_9;
    if (D_0028E894 != 0) goto block_c;
next_9:
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.h[0] += 0x200;
    func_00202140();
    if (D_0028E408 != 0) goto block_c;
    reg_d2.h[0] = reg_d1.h[0];
    reg_d0.w = 0x3C;
    reg_d2.b[0] += 2;
    reg_d2.h[0] &= reg_d0.h[0];
    reg_d3.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x32)));
    reg_d3.b[0] += 2;
    reg_d3.h[0] &= reg_d0.h[0];
    if (reg_d3.b[0] == reg_d2.b[0]) goto next_10;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1C)));
    if ((*(u8 *)((u8 *)(reg_a5) + (0x1D))) == reg_d0.b[0]) goto block_c;
next_10:
    (*(u8 *)((u8 *)(reg_a5) + (0x29))) = (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
    (*(u8 *)((u8 *)(reg_a5) + (0x1D))) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_11;
    (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (*(u8 *)((u8 *)(reg_a5) + (0x1C)));
    reg_d0.w = 0x40;
    reg_d0.h[0] -= D_0028E8D0;
    (*(u8 *)((u8 *)(reg_a5) + (0x29))) = reg_d0.b[0];
next_11:
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x32)));
    reg_a0 = (u8 *)D_0025B1C0;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 1;
    reg_d3.h[0] &= 0x3E;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d2.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((u16) reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d2.w += reg_tmp.w;
    reg_d1.b[0] += 2;
    reg_d1.h[0] &= 0x3C;
    reg_d0.w = 0xC;
    reg_d3.w = 0x02000000;
    func_00128970();
    goto block_c;
block_e:
    reg_d0.w = 0x10;
    func_001A91A0();
    reg_d0.w = 4;
    reg_a1 = (u8 *)D_0025B130;
    func_0016CEA0();
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xFE00;
    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
    reg_d0.w = 4;
    func_0016CF40();
    func_0018D4E0();
    func_0014E290();
block_rts:
    return;
}
