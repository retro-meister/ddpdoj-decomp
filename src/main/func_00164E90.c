#include "common.h"

s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_00164C30();
s32 func_0016D290();
s32 func_00170A60();
s32 func_00170BE0();
s32 func_00170D00();
s32 func_0018D4E0();
s32 func_001289D0();
s32 func_00128930();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_002021F0();
s32 func_00202500();
s32 func_00203060();
extern u16 D_0025A710[];
extern u16 D_0025A790[];
extern u16 D_0025A7B0[];
extern u16 D_0025A830[];
extern u16 D_0025AEE0[];
extern u16 D_0028E3EC;
extern u16 D_0028E3F0;
extern s8 D_0028E408;
extern s16 *D_0028E44C;
extern u16 D_0028E89C;
extern u16 D_0028E8A0;
extern u16 D_0028E8B8;
extern u16 D_0028E8C8;
extern u16 D_0028E8D8;
extern u16 D_0029F1F0[];
extern u16 D_0029F260[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00164E90(void) {
    u8 *ptr;

    func_0014EA50();
    if (enemy_move_end_requested != 0) {
        return;
    }
    func_00203060();
    if (D_0028E408 == 0) goto next_30;
    if (reg_a5[0x17] == 0) goto next_40;
    func_0014E290();
    return;
next_30:
    reg_a5[0x17] = 1;
next_40:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= reg_a6[1];
    if (reg_d1.b[0] != 0) goto next_50;
    reg_d0.b[0] = reg_a5[0x19];
    if (!((s32) *(u16 *)(reg_a6 + 0x18) < 0x50)) goto next_90;
    if (D_0028E8B8 != 0) goto next_90;
    reg_d0.w = 0x19;
    goto next_90;
next_50:
    reg_a6[1] &= 0xA3;
    func_001A9000();
    reg_d0.b[0] = reg_a6[0x1C];
    if (reg_d0.b[0] != 0x19) goto next_60;
    reg_d0.b[0] = reg_a5[0x19];
next_60:
    reg_d2.b[0] = reg_a5[0x18];
    reg_d0.b[0] ^= reg_d2.b[0];
    if (*(s16 *)(reg_a6 + 0x18) < 0) goto block_dead;
next_90:
    reg_a6[0x1C] = reg_d0.b[0];
    reg_tmp.b[0] = reg_a5[0x27];
    reg_a5[0x27] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_120;
    reg_a5[0x27] = reg_a5[0x26];
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x28);
    reg_a0 = (u8 *) D_0025A790;
    *(u16 *)(reg_a5 + 0x20) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0x22) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x28);
    *(u16 *)(reg_a5 + 0x28) -= 4;
    if (!((s32) reg_tmp.h[0] < 4)) goto next_120;
    *(u16 *)(reg_a5 + 0x28) = 0x14;
next_120:
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x2A);
    reg_a0 = (u8 *) D_0025A830;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0x2C) = reg_d0.h[0];
    reg_d0.h[0] += 0xF800;
    *(u16 *)(reg_a6 + 6) = reg_d0.h[0];
    reg_a5[0x2A] += 3;
    if ((s8) reg_a6[0] >= 0) goto next_200;
block_base:
    func_00170A60();
    func_00164C30();
    if (D_0028E3EC == 0) goto next_150;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[1] += 0x100;
    reg_d1.h[0] += 0xFE00;
    reg_d1.h[1] += *(u16 *)(reg_a5 + 0x2C);
    reg_a0 = (u8 *) D_0025AEE0;
    reg_d2.w = 6;
    reg_d2.h[0] &= D_0028E3F0;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = 0x410;
    reg_d4.h[0] = 0x1E;
    func_00170BE0();
next_150:
    reg_a0 = reg_a6;
    func_0014D220();
    return;
next_200:
    if (D_0028E8A0 != 0) goto block_objset;
    if (D_0028E89C != 0) goto block_objset;
    reg_tmp.b[0] = reg_a5[0x1F];
    reg_a5[0x1F] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_objset;
    reg_a5[0x1F] = reg_a5[0x1E];
    reg_d0.b[0] = reg_a5[0x1D];
    if (reg_a5[0x1C] != reg_d0.b[0]) goto block_objset;
    reg_a0 = (u8 *) D_0029F260;
    reg_a1 = (u8 *) D_0029F1F0;
    if (reg_a5[2] == 0) goto next_220;
    D_0028E44C = (s16 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) D_0028E44C;
next_220:
    ptr = reg_a0;
    if ((*(s16 *)ptr) < 0) goto next_240;
    if ((*(s16 *)reg_a1) >= 0) goto block_objset;
    reg_a0 = reg_a1;
    D_0028E44C = (s16 *) ptr;
    reg_a1 = ptr;
next_240:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    func_002021F0();
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x24);
    func_00202500();
    *(u16 *)(reg_a5 + 0x24) = reg_d1.h[0];
    reg_a0 = (u8 *) D_0025A710;
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    *(u16 *)(reg_a6 + 0xA) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0xC) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
block_objset:
    func_00170A60();
    func_00164C30();
    reg_a0 = reg_a6;
    func_0014D220();
    if (D_0028E8A0 != 0) goto block_rts;
    if (D_0028E89C != 0) goto block_rts;
    if ((*(s16 *)(reg_a6 + 2)) < 0x1000) goto block_rts;
    reg_tmp.b[0] = reg_a5[0x1B];
    reg_a5[0x1B] -= 1;
    switch (reg_tmp.b[0]) {
    case 0:
        goto block_fire;
    }
block_rts:
    return;
block_fire:
    reg_d0.h[0] = 8;
    reg_d1.h[0] = D_0028E8C8;
    reg_d1.h[0] >>= 2;
    reg_d0.h[0] -= reg_d1.h[0];
    reg_a5[0x1B] = reg_d0.b[0];
    func_0016D290();
    if (D_0028E408 != 0) goto block_rts;
    reg_a4 = (u8 *) D_0025A7B0;
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x24);
    reg_d0.h[0] = reg_d1.h[0];
    reg_d0.h[0] &= 0x3E;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
    reg_d4.w = (u32) reg_a6;
    reg_d0.w = 0xC;
    reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
    if (reg_a5[0x1D] != 2) goto next_620;
    func_001289D0();
    goto next_630;
next_620:
    func_00128930();
next_630:
    reg_tmp.b[0] = reg_a5[0x1D];
    reg_a5[0x1D] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_650;
    reg_a5[0x1D] = reg_a5[0x1C];
    reg_d0.h[0] = 0x50;
    reg_d0.h[0] -= D_0028E8D8;
    reg_d0.h[0] += 4;
    reg_a5[0x1B] = reg_d0.b[0];
next_650:
    return;
block_dead:
    reg_tmp.b[0] = reg_a6[0];
    reg_a6[0] |= 0x80;
    if (reg_tmp.b[0] & 0x80) goto block_dead2;
    reg_d0.w = 0x11;
    func_001A91A0();
    reg_d0.w = 0xB;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = *(u16 *)(reg_a6 + 4);
    func_00170D00();
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(s16 *)(reg_a0 + 0x26) = 0;
    *(s16 *)(reg_a0 + 0x28) = 0;
    *(s16 *)(reg_a0 + 0x10) = 2;
    reg_a6[1] &= 0xFD;
    reg_tmp.w = 0x1957;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
    *(u16 *)(reg_a6 + 0x18) = 0x140;
    goto block_base;
block_dead2:
    func_0018D4E0();
    reg_d0.w = 8;
    func_001A91A0();
    reg_d0.h[0] = 0xC;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = *(u16 *)(reg_a6 + 4);
    func_00170D00();
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(u16 *)(reg_a0 + 0x26) = 0xFC00;
    *(s16 *)(reg_a0 + 0x28) = 0;
    *(s16 *)(reg_a0 + 0x10) = 1;
    func_0014E290();
}
