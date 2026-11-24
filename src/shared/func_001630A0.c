#include "common.h"

s32 func_00125EF0();
s32 func_00128930();
s32 func_00128A20();
s32 func_001368E0();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_00170A60();
s32 func_00170BE0();
s32 func_00170D00();
s32 func_0018D580();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_002021F0();
s32 func_00202500();
s32 func_00211550();
extern u16 D_002590F0[];
extern u16 D_002594F0[];
extern u16 D_0025A610[];
extern u16 D_0025A620[];
extern s16 *D_0028E44C;
extern Reg32 D_0028E484;
extern u16 D_0028E89C;
extern u16 D_0028E8A0;
extern u16 D_0028E8B8;
extern u16 D_0028E8C8;
extern u16 D_0028E8D8;
extern u16 D_0029C068[];
extern u16 D_0029F1F0_as_u16_a[];
extern u16 D_0029F260_as_u16_a[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001630A0(void) {
    u8 bits;
    u8 *ptr;
    u32 saved;

    func_0014EA50();
    if (enemy_move_end_requested != 0) {
        return;
    }
    if ((*(u16 *)((u8 *)(reg_a6) + (0x2E))) == 0) goto next_90;
    if (!((*(u8 *)((u8 *)(reg_a6) + (1))) & 0x20)) goto next_90;
    reg_a0 = reg_a6 + 0x16;
    if ((*(u16 *)((u8 *)(reg_a6) + (0x30))) == 0) goto next_20;
    reg_a0 = reg_a6 + 0x14;
    reg_d3.h[0] *= 0xFFFF;
next_20:
    if (!((s16) *(u16 *)reg_a0 < 0xC00)) goto next_90;
    *(u16 *)reg_a0 += reg_d3.h[0];
next_90:
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    D_0028E484.w = 0;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x1400;
    reg_d0.h[0] += D_0029C068[0];
    D_0028E484.h[0] = 0xA000;
    reg_tmp.h[0] = reg_d0.h[0];
    saved = reg_tmp.w;
    reg_tmp.w = saved + D_0028E484.w;
    reg_d0.h[0] += 0xA000;
    if (reg_tmp.h[1] != 0) goto next_120;
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0x7800;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    saved = reg_tmp.h[0];
    reg_d0.h[0] += 0xC00;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += D_0028E484.w;
    reg_d0.h[0] += 0x7800;
    reg_d0.h[1] = saved;
    if (reg_tmp.h[1] == 0) goto next_130;
next_120:
    if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) == 0) goto next_140;
    func_0014E290();
    return;
next_130:
    (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1;
next_140:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (1)));
    if (reg_d1.b[0] != 0) goto next_150;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
    if (!((s32) (*(u16 *)((u8 *)(reg_a6) + (0x18))) < 0x4A0)) goto next_190;
    if (D_0028E8B8 != 0) goto next_190;
    reg_d0.w = 0x19;
    goto next_190;
next_150:
    (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xA3;
    func_001A9000();
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
    if (reg_d0.b[0] != 0x19) goto next_160;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
next_160:
    reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1C)));
    reg_d0.b[0] ^= reg_d2.b[0];
    if ((*(s16 *)((u8 *)(reg_a6) + (0x18))) < 0) goto block_d;
next_190:
    (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = reg_d0.b[0];
    func_001368E0();
    if (D_0028E8A0 != 0) goto next_280;
    (*(u16 *)((u8 *)(reg_a6) + (6))) = 0xF400;
    if (!((s32) (*(u8 *)((u8 *)(reg_a6) + (0x1A))) < 0x40)) goto next_280;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x27)));
    (*(u8 *)((u8 *)(reg_a6) + (0x27))) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_280;
    (*(u8 *)((u8 *)(reg_a6) + (0x27))) = (*(u8 *)((u8 *)(reg_a6) + (0x26)));
    (*(u16 *)((u8 *)(reg_a6) + (6))) = 0xF3C0;
    if ((*(u8 *)((u8 *)(reg_a6) + (0x1A))) != 0x10) goto next_250;
    (*(u16 *)((u8 *)(reg_a6) + (0x28))) += 4;
    if ((*(u16 *)((u8 *)(reg_a6) + (0x28))) != 0x10) goto next_260;
    (*(u16 *)((u8 *)(reg_a6) + (0x28))) = 0;
    goto next_260;
next_250:
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x28)));
    (*(u16 *)((u8 *)(reg_a6) + (0x28))) -= 4;
    if (!((s32) reg_tmp.h[0] < 4)) goto next_260;
    (*(u16 *)((u8 *)(reg_a6) + (0x28))) = 0xC;
next_260:
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x28)));
    reg_a0 = (u8 *) D_0025A610;
    (*(u16 *)((u8 *)(reg_a6) + (0x2A))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
    (*(u16 *)((u8 *)(reg_a6) + (0x2C))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
next_280:
    if (D_0028E8A0 != 0) goto block_b;
    if (D_0028E89C != 0) goto block_b;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x23)));
    (*(u8 *)((u8 *)(reg_a5) + (0x23))) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_b;
    (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (*(u8 *)((u8 *)(reg_a5) + (0x22)));
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x21)));
    if ((*(u8 *)((u8 *)(reg_a5) + (0x20))) != reg_d0.b[0]) goto block_b;
    reg_a0 = (u8 *) D_0029F260_as_u16_a;
    reg_a1 = (u8 *) D_0029F1F0_as_u16_a;
    if ((*(u8 *)((u8 *)(reg_a5) + (2))) == 0) goto next_320;
    D_0028E44C = (s16 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) D_0028E44C;
next_320:
    ptr = reg_a0;
    if ((*(s16 *)ptr) < 0) goto next_340;
    if ((*(s16 *)reg_a1) >= 0) goto block_b;
    reg_a0 = reg_a1;
    D_0028E44C = (s16 *) ptr;
    reg_a1 = ptr;
next_340:
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_a3 = (u8 *) D_002590F0;
    bits = (*(u8 *)((u8 *)(reg_a6) + (0)));
    if (!(bits & 0x40)) goto next_350;
    (*(u8 *)((u8 *)(reg_a6) + (0))) = bits & 0xBF;
    goto next_380;
next_350:
    (*(u8 *)((u8 *)(reg_a6) + (0))) = bits | 0x40;
    reg_d0.h[0] += 0x300;
    reg_d1.h[0] += 0x5C0;
    func_002021F0();
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x28)));
    func_00202500();
    (*(u16 *)((u8 *)(reg_a5) + (0x28))) = reg_d1.h[0];
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    (*(u16 *)((u8 *)(reg_a5) + (0x24))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
    (*(u16 *)((u8 *)(reg_a5) + (0x26))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
    goto block_b;
next_380:
    reg_d0.h[0] += 0x300;
    reg_d1.h[0] += 0xF9C0;
    func_002021F0();
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x2E)));
    func_00202500();
    (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = reg_d1.h[0];
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    (*(u16 *)((u8 *)(reg_a5) + (0x2A))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
    (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
block_b:
    func_00170A60();
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] += 0xF500;
    reg_d1.h[1] += 0xF200;
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x2A)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2C)));
    reg_d3.h[0] = 0x458;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
    func_00170BE0();
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] += 0x2C0;
    reg_d1.h[1] += 0xFF00;
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x24)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x26)));
    reg_d3.h[0] = 0x418;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
    func_00170BE0();
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] += 0xF6C0;
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x2A)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x2C)));
    func_00170BE0();
    reg_a0 = reg_a6;
    func_0014D220();
    if (D_0028E8A0 != 0) goto block_rts;
    if (D_0028E89C != 0) goto block_rts;
    if ((*(s16 *)((u8 *)(reg_a6) + (2))) < 0x1000) goto block_rts;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= 1;
    switch (reg_tmp.b[0]) {
    case 0:
        goto block_c;
    }
block_rts:
    return;
block_c:
    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (*(u8 *)((u8 *)(reg_a5) + (0x30)));
    reg_a4 = (u8 *) D_002594F0;
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x28)));
    reg_d0.h[0] = reg_d1.h[0];
    reg_d0.h[0] &= 0x3E;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] += 0x5C0;
    reg_d3.h[1] += 0x300;
    reg_d4.w = 0;
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.w = 0x30004;
    bits = (*(u8 *)((u8 *)(reg_a5) + (0x33)));
    if (bits != 0) goto next_610;
    reg_d1.h[0] += 3;
    goto next_620;
next_610:
    if ((bits & 0xFF) != 1) goto next_620;
    reg_d1.h[0] += 5;
next_620:
    func_00128A20();
    reg_d1.h[0] -= 5;
    func_00128930();
    reg_d1.h[0] -= 5;
    func_00128A20();
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x2E)));
    reg_d4.h[0] = reg_d1.h[0];
    reg_d4.h[0] &= 0x3E;
    reg_d4.h[0] += reg_d4.h[0];
    reg_d3.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] = (((u16)reg_d4.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((u16)reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] += 0xF9C0;
    reg_d3.h[1] += 0x300;
    reg_d4.w = 0;
    reg_d0.w = 0x30004;
    bits = (*(u8 *)((u8 *)(reg_a5) + (0x33)));
    if (bits != 0) goto next_640;
    reg_d1.h[0] -= 3;
    goto next_650;
next_640:
    if ((bits & 0xFF) != 1) goto next_650;
    reg_d1.h[0] -= 5;
next_650:
    func_00128A20();
    reg_d1.h[0] += 5;
    func_00128930();
    reg_d1.h[0] += 5;
    func_00128A20();
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x21)));
    (*(u8 *)((u8 *)(reg_a5) + (0x21))) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_690;
    (*(u8 *)((u8 *)(reg_a5) + (0x21))) = (*(u8 *)((u8 *)(reg_a5) + (0x20)));
    reg_d0.h[0] = 0xA;
    reg_d1.h[0] = D_0028E8C8;
    reg_d1.h[0] >>= 2;
    reg_d0.h[0] -= reg_d1.h[0];
    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = reg_d0.b[0];
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x33)));
    (*(u8 *)((u8 *)(reg_a5) + (0x33))) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_690;
    (*(u8 *)((u8 *)(reg_a5) + (0x33))) = (*(u8 *)((u8 *)(reg_a5) + (0x32)));
    reg_d0.h[0] = 0x60;
    reg_d0.h[0] -= D_0028E8D8;
    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = reg_d0.b[0];
next_690:
    return;
block_d:
    reg_d0.w = 0x115;
    func_001A91A0();
    func_0018D580();
    reg_d1.h[0] = 0;
    reg_d2.w = -0x600U;
    reg_d0.w = 0xC;
    func_00211550();
    reg_d2.w = 0x600;
    func_00211550();
    reg_d0.w = 8;
    reg_a4 = (u8 *)(D_0025A620);
    reg_d6.w = 6;
    do {
        reg_d1.h[1] = *(u16 *)reg_a4;
        reg_a4 += 2;
        reg_d1.h[0] = *(u16 *)reg_a4;
        reg_a4 += 2;
        func_00125EF0();
    } while ((s16)(--reg_d6.h[0]) >= 0);
    reg_d0.w = 0xD;
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_00170D00();
    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x400;
    (*(s16 *)((u8 *)(reg_a0) + (0x26))) = 0x200;
    (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0;
    (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 1;
    reg_d0.w = 0xC;
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_00170D00();
    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xFE00;
    (*(u16 *)((u8 *)(reg_a0) + (0x28))) = 0xFA00;
    (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0x5C0;
    (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 1;
    reg_d0.w = 0xC;
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_00170D00();
    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x400;
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xFC00;
    (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0x200;
    (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0x440;
    (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 1;
    reg_d0.h[0] = 0x85;
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_00170D00();
    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 1;
    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xFE00;
    (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0;
    (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0x380;
    (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 1;
    func_0014E290();
}
