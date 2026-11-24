#include "common.h"

typedef void (*Fn)();

s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_0016CEA0();
s32 func_0016CF40();
s32 func_0016CFB0();
s32 func_0016D040();
s32 func_0018D4E0();
s32 func_00128970();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_00202140();
s32 func_00202500();
extern u16 D_0025B130[];
extern u16 D_0025B140[];
extern u16 D_0025B490_as_u16_a[];
extern u16 D_0025B510_as_u16_a[];
extern u16 D_0025B610_as_u16_a[];
extern u16 D_0028E3EC;
extern u16 D_0028E3F0;
extern s8 D_0028E408;
extern Reg32 D_0028E484;
extern u16 D_0028E7DC_as_u16;
extern u16 D_0028E7E0_as_u16;
extern u16 D_0028E894;
extern u16 D_0028E8A0;
extern u16 D_0028E8A8;
extern u16 D_0028E8CC;
extern u16 D_0028E8EC;
extern u16 D_0028E910;
extern u16 D_0028E91C;
extern u16 D_0029C068[];
extern s8 enemy_move_end_requested;
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u16 *reg_a1_as_u16_p;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0016E2A0(void) {
    u32 swap;

    func_0014EA50();
    if (enemy_move_end_requested != 0) {
        return;
    }
    reg_d0.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d0.h[0] += 0xE00;
    reg_d0.h[0] += D_0029C068[0];
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0xAC00;
    D_0028E484.w += reg_tmp.w;
    reg_d0.h[0] += 0xAC00;
    if (D_0028E484.h[1] != 0) goto next_lim;
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0x8400;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    swap = reg_tmp.h[0];
    reg_d0.h[0] += 0x600;
    reg_tmp.w = 0;
    reg_d0.h[1] = swap;
    reg_tmp.h[0] = reg_d0.h[0];
    D_0028E484.w += reg_tmp.w;
    reg_d0.h[0] += 0x8400;
next_lim:
    if (D_0028E484.h[1] == 0) goto next_40;
    if (*(u16 *)(reg_a5 + 0x16) == 0) goto next_50;
    func_0014E290();
    return;
next_40:
    *(u16 *)(reg_a5 + 0x16) = 1;
next_50:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= reg_a6[1];
    if (reg_d1.b[0] == 0) goto next_100;
    reg_a6[1] &= 0xA3;
    reg_d0.b[0] = reg_a5[0x34];
    reg_a6[0x1C] ^= reg_d0.b[0];
    func_001A9000();
    if (*(s16 *)(reg_a6 + 0x18) >= 0) goto next_110;
    if ((s8) reg_a5[0x21] < 0) goto block_70;
    *(u16 *)(reg_a6 + 0x18) = *(u16 *)(reg_a5 + 0x26);
    reg_d0.w = 8;
    func_001A91A0();
    reg_a5[0x21] |= 0x80;
    if (D_0028E7E0_as_u16 != 0) goto next_110;
    D_0028E7E0_as_u16 = 1;
    reg_d0.w = 3;
    reg_a1_as_u16_p = (u16 *)D_0025B140;
    func_0016CEA0();
    *(u16 *)(reg_a0 + 0x26) = 0xFE00;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0;
    goto next_110;
next_100:
    reg_a6[0x1C] = reg_a5[0x35];
next_110:
    if (D_0028E8A0 != 0) goto next_225;
    reg_d7.h[0] = *(u16 *)(reg_a6 + 0x1A);
    reg_d1.w = 0x3E;
    reg_d1.h[0] &= reg_d7.h[0];
    reg_d1.h[0] <<= 2;
    if (reg_d7.h[0] & 0x40) goto next_220;
    if (!(D_0028E3F0 & 4)) goto next_220;
    reg_d1.h[0] += 4;
next_220:
    reg_a0 = (u8 *) D_0025B510_as_u16_a;
    *(u16 *)(reg_a6 + 0xA) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0xC) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
next_225:
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x2A);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x2C);
    reg_a0 = (u8 *) reg_tmp.w;
    jtbl_0028E3F4 = (Fn) reg_a0;
    jtbl_0028E3F4();
    reg_a0 = reg_a6;
    func_0014D220();
    if ((s8) reg_a5[0x21] >= 0) goto next_300;
    if (D_0028E3EC == 0) goto block_rts;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.w += 0x100FE00;
    func_0016CFB0();
    return;
next_300:
    if (D_0028E8A0 != 0) goto block_objset;
    reg_d1.b[0] = reg_a5[0x32];
    reg_tmp.b[0] = reg_a5[0x19];
    reg_a5[0x19] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_500;
    reg_a5[0x19] = reg_a5[0x18];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d0.h[0] += 0x200;
    func_00202140();
    if (D_0028E408 != 0) goto block_objset;
    reg_d0.b[0] = reg_a5[0x32];
    func_00202500();
    reg_a5[0x32] = reg_d1.b[0];
    reg_a0 = (u8 *) D_0025B610_as_u16_a;
    reg_d1.b[0] += 1;
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    *(u16 *)(reg_a5 + 0x22) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0x24) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
next_500:
    if (!(reg_a6[1] & 0x20)) goto block_objset;
    reg_a5[0x29] -= 1;
    if (reg_a5[0x29] == 0) goto block_shot;
block_objset:
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.w += 0xFC00FC00;
    reg_d2.h[1] = *(u16 *)(reg_a5 + 0x22);
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x24);
    reg_d3.h[0] = 0x620;
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x2E);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x30);
    reg_a0 = (u8 *) reg_tmp.w;
    jtbl_0028E3F4 = (Fn) reg_a0;
    jtbl_0028E3F4();
block_rts:
    return;
block_shot:
    reg_d0.h[0] = 0xA0;
    reg_d0.h[0] -= D_0028E8EC;
    reg_d0.h[0] += 4;
    if (D_0028E910 != 0) goto next_610;
    if (D_0028E91C != 1) goto next_610;
    if ((s32) D_0028E8A8 < 0x159) goto next_610;
    reg_d0.w = 0x30;
    reg_d0.h[0] -= D_0028E8CC;
    reg_d0.h[0] -= 6;
next_610:
    reg_a5[0x29] = reg_d0.b[0];
    func_0016D040();
    if (D_0028E408 != 0) goto block_objset;
    if (D_0028E91C != 1) goto next_620;
    if (D_0028E894 != 0) goto block_objset;
next_620:
    if (!(reg_a6[1] & 0x20)) goto block_objset;
    reg_d1.b[0] = reg_a5[0x32];
    reg_a0 = (u8 *) D_0025B490_as_u16_a;
    reg_d1.b[0] += 2;
    reg_d1.h[0] &= 0x3C;
    reg_d2.h[0] = reg_d1.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 2);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d2.w += reg_tmp.w;
    reg_d0.w = 0xD;
    if ((s32) D_0028E91C < 3) goto next_630;
    reg_d0.w = 0xFFFC000D;
next_630:
    reg_d3.w = 0x2000000;
    func_00128970();
    goto block_objset;
block_70:
    reg_d0.w = 0x10;
    func_001A91A0();
    reg_d0.w = 7;
    reg_a1_as_u16_p = (u16 *)D_0025B130;
    func_0016CEA0();
    *(u16 *)(reg_a0 + 0x26) = 0xFE00;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0;
    if (D_0028E7E0_as_u16 == 0) goto next_71;
    *(u16 *)(reg_a0 + 0x12) = 0xFFFF;
next_71:
    D_0028E7E0_as_u16 = 1;
    D_0028E7DC_as_u16 += 1;
    if (!(D_0028E7DC_as_u16 & 1)) goto next_72;
    reg_d0.w = 4;
    func_0016CF40();
next_72:
    func_0018D4E0();
    func_0014E290();
}
