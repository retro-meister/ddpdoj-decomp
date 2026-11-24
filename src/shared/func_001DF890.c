#include "common.h"

typedef void (*Fn)();

extern u8 D_00259970[];
extern u8 D_00263940[];
extern u8 D_00263960[];
extern u8 D_002639A0[];
extern u8 D_002639B0[];
extern u8 D_0029F1F0[];
extern u8 D_0029F260[];
s32 func_00129280();
s32 func_00129320();
s32 func_001293C0();
s32 func_001368E0();
s32 func_0013A780();
s32 func_0013B2E0();
s32 func_0014D220();
s32 func_0014E030();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_0016A9B0();
s32 func_00171400();
s32 func_0018D500();
s32 func_0018D520();
s32 func_0018D580();
s32 func_0018D5C0();
s32 func_0019BF80();
s32 func_0019C530();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_001DF2B0();
s32 func_001DF300();
s32 func_001DF350();
s32 func_001E0B30();
s32 func_001E0C20();
s32 func_001E4410();
s32 func_001E4460();
s32 func_001E4490();
s32 func_001E44F0();
s32 func_001E4520();
s32 func_002011A0();
s32 func_00201270();
s32 func_002012F0();
s32 func_00201800();
s32 func_002027A0();
s32 func_00202C50();
s32 vibration_start_pad1();
s32 vibration_start_pad2();
extern u8 *D_0028E44C;
extern Reg32 D_0028E484;
extern u16 D_0028E88C;
extern u16 D_0028E894;
extern u16 D_0028E8A0;
extern u16 D_0028E8A8;
extern u16 D_0028E8B8;
extern u16 D_0028E8DC;
extern u16 D_0029CEA0[];
extern s8 enemy_move_end_requested;
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001DF890(void) {
    s16 saved_x;
    s32 saved_d0;
    u32 temp;

    func_0014EA50();
    if (enemy_move_end_requested != 0) {
        return;
    }
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0x2800;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x3400;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += D_0028E484.w;
    reg_d0.h[0] += 0x2800;
    if (reg_tmp.h[1] == 0) goto next_30;
    if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) == 0) goto next_40;
    D_0028E894 = 0;
    func_0014E290();
    return;
next_30:
    (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1;
next_40:
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d2.h[0] = reg_d1.h[0];
    reg_d0.h[0] += 0xEC00;
    reg_d1.h[0] += 0xEC00;
    reg_d2.h[0] += 0x1400;
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = reg_d1.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x42))) = reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x44))) = reg_d2.h[0];
    if ((*(s8 *)((u8 *)(reg_a6) + (0))) < 0) goto block_b;
    if ((*(u16 *)((u8 *)(reg_a5) + (0x2A))) == 0) goto next_45;
    (*(u16 *)((u8 *)(reg_a5) + (0x2A))) -= 1;
    (*(u16 *)((u8 *)(reg_a6) + (0x18))) = 0x7000;
    (*(u16 *)((u8 *)(reg_a6) + (0x38))) = 0x2200;
    (*(u16 *)((u8 *)(reg_a6) + (0x58))) = 0x2200;
next_45:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (1)));
    if (reg_d1.b[0] != 0) goto next_50;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
    if (!((s32) (*(u16 *)((u8 *)(reg_a6) + (0x18))) < 0x1C00)) goto next_90;
    if (D_0028E8B8 != 0) goto next_90;
    reg_d0.w = 0x19;
    goto next_90;
next_50:
    (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xA3;
    func_001A9000();
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
    if (reg_d0.b[0] != 0x19) goto next_60;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
next_60:
    reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
    reg_d0.b[0] ^= reg_d2.b[0];
    if ((*(s16 *)((u8 *)(reg_a6) + (0x18))) < 0) goto block_c;
next_90:
    (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = reg_d0.b[0];
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x2D)));
    (*(u8 *)((u8 *)(reg_a5) + (0x2D))) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_100;
    (*(u8 *)((u8 *)(reg_a5) + (0x2D))) = 4;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x35)));
    (*(u8 *)((u8 *)(reg_a5) + (0x35))) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_100;
    (*(u8 *)((u8 *)(reg_a5) + (0x35))) = (*(u8 *)((u8 *)(reg_a5) + (0x34)));
    (*(u8 *)((u8 *)(reg_a5) + (0x2D))) = (*(u8 *)((u8 *)(reg_a5) + (0x2C)));
    func_001E0B30();
    func_001E0C20();
next_100:
    if ((*(s8 *)((u8 *)(reg_a6) + (0x20))) >= 0) goto next_130;
    func_001DF2B0();
    goto next_200;
next_130:
    if ((*(u8 *)((u8 *)(reg_a5) + (0x2D))) != 0) goto next_140;
    saved_x = (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) += 0xE880;
    func_00202C50();
    (*(s16 *)((u8 *)(reg_a6) + (4))) = saved_x;
    if (!((s32) reg_d0.h[0] < 0xC00)) goto next_140;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x3A)));
    reg_d0.w = 0x6000B;
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d3.w = 0xE100E880;
    reg_d4.w = 0;
    func_001293C0();
next_140:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (0x21)));
    if (reg_d1.b[0] != 0) goto next_150;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
    if (!((s32) (*(u16 *)((u8 *)(reg_a6) + (0x38))) < 0x880)) goto next_190;
    if (D_0028E8B8 != 0) goto next_190;
    reg_d0.w = 0x19;
    goto next_190;
next_150:
    (*(u8 *)((u8 *)(reg_a6) + (0x21))) &= 0xA3;
    func_001A9000();
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x3C)));
    if (reg_d0.b[0] != 0x19) goto next_160;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
next_160:
    reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
    reg_d0.b[0] ^= reg_d2.b[0];
    if ((*(s16 *)((u8 *)(reg_a6) + (0x38))) >= 0) goto next_190;
    func_001E4460();
    goto next_200;
next_190:
    (*(u8 *)((u8 *)(reg_a6) + (0x3C))) = reg_d0.b[0];
next_200:
    if ((*(s8 *)((u8 *)(reg_a6) + (0x40))) >= 0) goto next_230;
    func_001DF300();
    goto next_300;
next_230:
    if ((*(u8 *)((u8 *)(reg_a5) + (0x2D))) != 0) goto next_240;
    saved_x = (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) += 0x1780;
    func_00202C50();
    (*(s16 *)((u8 *)(reg_a6) + (4))) = saved_x;
    if (!((s32) reg_d0.h[0] < 0xC00)) goto next_240;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x5A)));
    reg_d0.w = 0x6000B;
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d3.w = 0xE1001780;
    reg_d4.w = 0;
    func_001293C0();
next_240:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (0x41)));
    if (reg_d1.b[0] != 0) goto next_250;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
    if (!((s32) (*(u16 *)((u8 *)(reg_a6) + (0x58))) < 0x880)) goto next_290;
    if (D_0028E8B8 != 0) goto next_290;
    reg_d0.w = 0x19;
    goto next_290;
next_250:
    (*(u8 *)((u8 *)(reg_a6) + (0x41))) &= 0xA3;
    func_001A9000();
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x5C)));
    if (reg_d0.b[0] != 0x19) goto next_260;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
next_260:
    reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
    reg_d0.b[0] ^= reg_d2.b[0];
    if ((*(s16 *)((u8 *)(reg_a6) + (0x58))) >= 0) goto next_290;
    func_001E44F0();
    goto next_300;
next_290:
    (*(u8 *)((u8 *)(reg_a6) + (0x5C))) = reg_d0.b[0];
next_300:
    func_001368E0();
    if (D_0028E8A0 != 0) goto block_e;
    if ((s32) D_0028E8A8 < 0x228) goto next_350;
    D_0028E88C = 0;
next_350:
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    if (reg_d0.h[0] != 0) goto next_400;
    if (!((s32) D_0028E8A8 < 0x21C)) goto block_e;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
    (*(u8 *)((u8 *)(reg_a5) + (0x1D))) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_e;
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 1;
    goto block_e;
next_400:
    if ((reg_d0.h[0] & 0xFFFF) != 1) goto next_500;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x29)));
    (*(u8 *)((u8 *)(reg_a5) + (0x29))) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_d;
    (*(u8 *)((u8 *)(reg_a5) + (0x29))) = (*(u8 *)((u8 *)(reg_a5) + (0x28)));
    (*(u16 *)((u8 *)(reg_a5) + (0x20))) += 4;
    if ((*(u16 *)((u8 *)(reg_a5) + (0x20))) != 0x24) goto block_d;
    reg_a0 = (u8 *)D_0029F260;
    reg_a1 = (u8 *)D_0029F1F0;
    if ((*(u8 *)((u8 *)(reg_a5) + (2))) == 0) goto next_440;
    D_0028E44C = reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *)D_0028E44C;
next_440:
    if ((*(s16 *)reg_a0) < 0) goto next_460;
    if ((*(s16 *)reg_a1) >= 0) goto next_490;
    D_0028E44C = reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *)D_0028E44C;
next_460:
    reg_a4 = reg_a0;
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.h[0] += 0xD600;
    func_002027A0();
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d4.w = 0;
    reg_a0 = (u8 *)D_00259970;
    if ((*(u8 *)((u8 *)(reg_a5) + (0x1F))) == 0) goto next_475;
    reg_d5.h[0] = reg_d1.h[0];
    reg_d5.h[0] -= 0xC;
    reg_d6.h[0] = 0x74;
    reg_d7.w = 6;
loop_470:
    reg_d0.w = 0xFFF60004;
    reg_d1.h[0] = reg_d5.h[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += 0xD6000000;
    func_00129320();
    if (reg_d7.h[0] == 0) goto next_474;
    reg_d0.w += 0x40000;
    reg_d1.b[0] += 2;
    func_00129280();
    reg_d0.w += 0x40000;
    reg_d1.b[0] -= 2;
    func_00129320();
    reg_d0.w += 0x40000;
    reg_d1.b[0] += 2;
    func_00129280();
    goto next_476;
next_474:
    reg_d0.w += 0x80000;
    func_00129320();
next_476:
    reg_d5.h[0] += 4;
    temp = reg_d7.h[0] - 1;
    reg_d7.h[0] = temp;
    if (((s64) ((s64) (temp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_470;
    goto next_490;
next_475:
    reg_d5.h[0] = reg_d1.h[0];
    reg_d7.w = 0x1C;
    reg_d5.h[0] -= 0x38;
    reg_d6.h[0] = 0x48;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d0.h[0] += 0xD600;
    if ((*(s16 *)((u8 *)(reg_a4) + (2))) <= (s16) reg_d0.h[0]) goto loop_480;
    reg_d6.h[0] = 0xFFC8;
loop_480:
    reg_d0.w = 0xFFF80004;
    reg_d1.h[0] = reg_d5.h[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += 0xD6000000;
    reg_d0.h[0] = 3;
    reg_d0.h[1] += 4;
    reg_d1.h[0] = reg_d6.h[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += 0xD6000000;
    if ((reg_d7.h[0] & 1) == 0) goto next_484;
    reg_d0.w += 0x20000;
    func_00129280();
    reg_d0.w += 0xFFFE0000;
    goto next_485;
next_484:
    func_00129320();
next_485:
    reg_d5.h[0] += 4;
    reg_d6.h[0] += 4;
    temp = reg_d7.h[0] - 1;
    reg_d7.h[0] = temp;
    if (((s64) ((s64) (temp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_480;
next_490:
    func_00171400();
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 2;
    goto block_d;
next_500:
    if ((reg_d0.h[0] & 0xFFFF) != 2) goto block_d;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x29)));
    (*(u8 *)((u8 *)(reg_a5) + (0x29))) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_d;
    (*(u8 *)((u8 *)(reg_a5) + (0x29))) = (*(u8 *)((u8 *)(reg_a5) + (0x28)));
    (*(u16 *)((u8 *)(reg_a5) + (0x22))) -= 4;
    (*(u16 *)((u8 *)(reg_a5) + (0x20))) += 4;
    if ((*(u16 *)((u8 *)(reg_a5) + (0x20))) != 0x28) goto next_520;
    reg_d0.h[0] = 0x9E;
    func_0014E030();
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.h[1] += 0x1E00;
    (*(u16 *)((u8 *)(reg_a0) + (0x16))) = reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x18))) = reg_d0.h[0];
next_520:
    if ((*(u16 *)((u8 *)(reg_a5) + (0x20))) != 0x40) goto block_d;
    (*(u16 *)((u8 *)(reg_a5) + (0x20))) = 0;
    (*(u16 *)((u8 *)(reg_a5) + (0x22))) = 0xC;
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 1;
    (*(u16 *)((u8 *)(reg_a5) + (0x28))) = 0;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_d;
    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (*(u8 *)((u8 *)(reg_a5) + (0x1E)));
    reg_d0.h[0] = 0xA0;
    reg_d0.h[0] -= D_0028E8DC;
    (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = reg_d0.b[0];
    reg_d0.b[0] = 1;
    (*(u8 *)((u8 *)(reg_a5) + (0x29))) = reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a5) + (0x28))) = reg_d0.b[0];
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 0;
block_d:
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x20)));
    reg_a0 = (u8 *)D_00263960;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
block_e:
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (6)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (8)));
    reg_a6 = (u8 *) reg_tmp.w;
    reg_a0 = reg_a6;
    func_0014D220();
    reg_a0 = reg_a6 + 0x20;
    func_0014D220();
    reg_a0 = reg_a6 + 0x40;
    func_0014D220();
    func_001E4410();
    func_0019BF80();
    if ((*(s8 *)((u8 *)(reg_a6) + (0))) < 0) goto block_rts;
    if ((*(u16 *)((u8 *)(reg_a5) + (0x18))) != 2) goto block_rts;
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x22)));
    if ((s16) reg_d2.h[0] < 0) goto block_rts;
    reg_a0 = (u8 *)D_002639A0;
    reg_d2.h[1] = (reg_d2.h[0]) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[1] += 0xB800;
    reg_d1.h[0] += 0xF200;
    reg_d3.h[0] = 0x2470;
    reg_d4.h[0] = 0x11;
    func_0019C530();
block_rts:
    return;
block_c:
    (*(u16 *)((u8 *)(reg_a5) + (0x32))) = reg_d1.h[0];
    reg_d0.w = 0x683;
    func_001A91A0();
    func_0018D580();
    D_0028E894 = 0;
    (*(u16 *)((u8 *)(reg_a6) + (0))) = 0x8080;
    (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x32)));
    func_00201800();
    if ((*(s8 *)((u8 *)(reg_a6) + (0x20))) < 0) goto next_720;
    func_001E4490();
    (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = 0;
next_720:
    if ((*(s8 *)((u8 *)(reg_a6) + (0x40))) < 0) goto next_740;
    func_001E4520();
    (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = 0;
next_740:
    if (*(s16 *)D_0029CEA0 == 0) goto block_e;
    (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = 0;
    goto block_e;
block_b:
    if ((*(s8 *)((u8 *)(reg_a6) + (0x20))) >= 0) goto next_620;
    func_001DF2B0();
next_620:
    if ((*(s8 *)((u8 *)(reg_a6) + (0x40))) >= 0) goto next_640;
    func_001DF300();
next_640:
    if ((*(u16 *)((u8 *)(reg_a5) + (0x24))) != 0) goto next_6200;
    if ((*(u16 *)((u8 *)(reg_a6) + (0x1E))) != 0) goto next_680;
    if ((*(u16 *)((u8 *)(reg_a5) + (0x30))) == 0) goto next_650;
    (*(u16 *)((u8 *)(reg_a5) + (0x30))) -= 1;
    if ((*(u16 *)((u8 *)(reg_a5) + (0x30))) != 0) goto next_650;
    D_0028E88C = 0;
next_650:
    if ((*(u16 *)((u8 *)(reg_a5) + (0x2E))) == 0) {
        func_001E4410();
        return;
    }
    (*(u16 *)((u8 *)(reg_a5) + (0x2E))) -= 1;
    if ((*(u16 *)((u8 *)(reg_a5) + (0x2E))) != 0) {
        func_001E4410();
        return;
    }
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    saved_d0 = reg_d0.w;
    if ((s16) reg_d0.h[0] >= 0x1000) goto next_660;
    (*(u16 *)((u8 *)(reg_a6) + (2))) = 0x1000;
next_660:
    reg_d0.h[0] = 0x10;
    func_0016A9B0();
    reg_tmp.w = saved_d0;
    (*(u16 *)((u8 *)(reg_a6) + (2))) = reg_tmp.h[0];
    func_001E4410();
    return;
next_680:
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x32)));
    func_00201800();
    (*(u16 *)((u8 *)(reg_a6) + (0x1E))) -= 1;
    goto block_e;
next_6200:
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x32)));
    func_00201800();
    (*(u16 *)((u8 *)(reg_a5) + (0x24))) -= 1;
    if ((*(u16 *)((u8 *)(reg_a5) + (0x24))) != 0) goto next_6240;
    func_001DF350();
    reg_a0 = (u8 *)D_002639B0;
    func_0013B2E0();
    vibration_start_pad1(0xB4, 0x64);
    vibration_start_pad2(0xB4, 0x64);
    func_0018D5C0();
    goto block_e;
next_6240:
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x27)));
    (*(u8 *)((u8 *)(reg_a5) + (0x27))) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_e;
    (*(u8 *)((u8 *)(reg_a5) + (0x27))) = (*(u8 *)((u8 *)(reg_a5) + (0x26)));
    reg_a0 = (u8 *) func_0018D500;
    func_002011A0();
    if ((s8) reg_d0.b[0] >= 0) goto next_6260;
    reg_a0 = (u8 *) func_0018D520;
next_6260:
    jtbl_0028E3F4 = (Fn) reg_a0;
    jtbl_0028E3F4();
    func_002011A0();
    reg_d0.h[0] &= 7;
    reg_a1 = (u8 *)D_00263940;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : (u16) *(u16 *)reg_a1;
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x800;
    func_00201270();
    reg_d0.b[0] += 3;
    (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = reg_d0.b[0];
    func_002011A0();
    (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = reg_d0.b[0];
    func_002012F0();
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d0.h[0] += reg_d1.h[0];
    reg_d0.h[0] += 0xF800;
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = reg_d0.h[0];
    func_002012F0();
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
    (*(u16 *)((u8 *)(reg_a0) + (0x28))) = reg_d0.h[0];
    goto block_e;
}
