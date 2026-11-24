#include "common.h"

typedef void (*Fn)();

extern u8 D_0025F3B0[];
extern u8 D_0025F3C0[];
extern u8 D_0025F400[];
extern u8 D_0025F430[];
extern u8 D_0029F110[];
extern s8 D_0028E408;

s32 func_0013C9A0();
s32 func_0013CAB0();
s32 func_0013F800();
s32 func_0013F850();
s32 func_0013F960();
s32 func_0013F990();
s32 func_0019F410();
s32 func_0019F750();
s32 func_001A0E90();
s32 func_001A1040();
s32 func_001A1360();
s32 func_001A17C0();
s32 func_001A1850();
s32 func_001A18B0();
s32 func_001A19B0();
s32 func_001A1AA0();
s32 func_001A1B60();
s32 func_001A2680();
extern u8 D_0028E370;
extern s32 D_0028ED70;
extern u8 D_0028ED7C;
extern u8 D_0029D710[];
extern u8 D_0029F1F0[];
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_0019FD30(void) {
    u32 temp;
    u8 bits;
    s32 temp2;

    goto next_20;
loop_10:
    reg_a6 = (u8 *)D_0029F110;
    reg_a4 = (u8 *)D_0029F1F0;
    reg_a2 = (u8 *)D_0029D710;
    if ((*(s16 *)((u8 *)(reg_a6) + (0))) < 0) goto next_20;
    return;
next_20:
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0)));
    (*(u8 *)((u8 *)(reg_a6) + (0))) |= 1;
    if (reg_tmp.b[0] & 1) goto next_100;
    reg_a0 = (u8 *)D_0025F3B0;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x5A)));
    reg_d0.h[0] -= 2;
    reg_d0.h[0] *= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_a1 = (u8 *)(reg_a6 + 6);
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
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1C)));
    (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a6) + (0x3C))) = (u8) reg_d0.b[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x57)));
    (*(u8 *)((u8 *)(reg_a2) + (0x1C))) = (u8) reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a2) + (0x1F))) = (u8) reg_d0.b[0];
    (*(s16 *)((u8 *)(reg_a2) + (0x16))) = 0;
next_100:
    (*(u8 *)((u8 *)(reg_a6) + (0x41))) = (*(u8 *)((u8 *)(reg_a4) + (0x19)));
    (*(u8 *)((u8 *)(reg_a6) + (0x40))) = (*(u8 *)((u8 *)(reg_a4) + (0x18)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0)));
    if (reg_d0.h[0] & 0x200) goto block_e;
    if ((*(u8 *)((u8 *)(reg_a4) + (1))) & 1) goto block_d;
    if (!(reg_d0.h[0] & 2)) goto block_c;
    if (!((*(u8 *)((u8 *)(reg_a4) + (1))) & 0x20)) goto next_210;
    (*(u16 *)((u8 *)(reg_a6) + (0x40))) = 0;
next_210:
    if (!((*(u8 *)((u8 *)(reg_a6) + (0x41))) & 0x10)) goto next_400;
    if ((*(u8 *)((u8 *)(reg_a6) + (0x3E))) == 0) goto next_310;
    (*(u8 *)((u8 *)(reg_a6) + (0x3E))) -= 1;
    if ((*(u8 *)((u8 *)(reg_a6) + (0x3E))) != 0) goto next_470;
    (*(u8 *)((u8 *)(reg_a6) + (1))) |= 0x40;
next_310:
    func_0013F960();
    if (!((*(u8 *)((u8 *)(reg_a6) + (0))) & 4)) goto next_320;
    func_001A17C0();
    goto block_b;
next_320:
    if ((*(u8 *)((u8 *)(reg_a6) + (0x1A))) != 0) goto next_330;
    func_001A17C0();
    func_001A18B0();
    if (D_0028E408 == 0) goto block_b;
    (*(u8 *)((u8 *)(reg_a6) + (0))) |= 4;
    (*(s16 *)((u8 *)(reg_a6) + (0x4E))) = 0;
    if ((*(u8 *)((u8 *)(reg_a4) + (0))) & 1) goto next_328;
    if ((*(u8 *)((u8 *)(reg_a4) + (0x5A))) & 4) goto next_326;
    func_001A19B0();
    goto block_b;
next_326:
    reg_a0 = (u8 *)D_0025F400;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x58)));
    if (reg_d0.h[0] == 0) goto next_327;
    reg_d0.w = 0x14;
next_327:
    reg_a0 = (u8 *)D_0025F400;
    reg_a0 += reg_d0.h[0];
    func_001A1AA0();
    goto block_b;
next_328:
    reg_a0 = (u8 *)D_0025F430;
    func_001A1AA0();
    goto block_b;
next_330:
    if ((*(u16 *)((u8 *)(reg_a6) + (0x10))) != 4) goto next_350;
    if ((*(u8 *)((u8 *)(reg_a6) + (1))) & 4) goto next_340;
    (*(u8 *)((u8 *)(reg_a6) + (1))) |= 8;
    if ((*(u8 *)((u8 *)(reg_a6) + (0x14))) == 0x10) goto next_340;
    if ((*(u8 *)((u8 *)(reg_a6) + (0x14))) != 0x30) goto block_b;
    bits = (*(u8 *)((u8 *)(reg_a6) + (0x1D)));
    if (!(bits & 0x40)) goto next_332;
    (*(u8 *)((u8 *)(reg_a6) + (0x1D))) = bits & 0xBF;
    goto next_334;
next_332:
    (*(u8 *)((u8 *)(reg_a6) + (0x1D))) = bits | 0x40;
next_334:
    bits = (*(u8 *)((u8 *)(reg_a6) + (0x3D)));
    if (!(bits & 0x40)) goto next_336;
    (*(u8 *)((u8 *)(reg_a6) + (0x3D))) = bits & 0xBF;
    goto next_338;
next_336:
    (*(u8 *)((u8 *)(reg_a6) + (0x3D))) = bits | 0x40;
next_338:
    (*(u8 *)((u8 *)(reg_a6) + (0x14))) = 0x10;
    (*(u8 *)((u8 *)(reg_a6) + (0x34))) = 0x30;
next_340:
    (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xF7;
    (*(u8 *)((u8 *)(reg_a6) + (1))) |= 4;
next_350:
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x3F)));
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) -= reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a6) + (0x3A))) += reg_d0.b[0];
    if ((s32) (*(u8 *)((u8 *)(reg_a6) + (0x3A))) < 0x40) goto block_b;
    (*(u8 *)((u8 *)(reg_a6) + (1))) |= 0x10;
    reg_d0.w = 0;
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a6) + (0x3A))) = reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a6) + (0x4B))) = 8;
    (*(u8 *)((u8 *)(reg_a6) + (0x4A))) = 4;
    (*(u16 *)((u8 *)(reg_a6) + (0x16))) = (*(u16 *)((u8 *)(reg_a6) + (0x30)));
    (*(u16 *)((u8 *)(reg_a6) + (0x18))) = (*(u16 *)((u8 *)(reg_a6) + (0x32)));
    func_001A18B0();
    (*(u16 *)((u8 *)(reg_a6) + (0xE))) = 0x418;
    reg_tmp.w = 0xFC00FD00;
    (*(u16 *)((u8 *)(reg_a6) + (6))) = reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (8))) = reg_tmp.h[0];
    (*(u8 *)((u8 *)(reg_a4) + (0x3E))) = 1;
    reg_a0 = (u8 *) func_0013F800;
    if (reg_d7.h[0] != 0) goto next_360;
    reg_a0 = (u8 *) func_0013F850;
next_360:
    jtbl_0028E3F4 = (Fn) reg_a0;
    jtbl_0028E3F4();
    goto block_b;
next_400:
    if ((*(s8 *)((u8 *)(reg_a4) + (0))) >= 0) goto next_410;
    func_001A17C0();
    goto block_b;
next_410:
    func_0013F990();
    func_001A1850();
    (*(u8 *)((u8 *)(reg_a6) + (0x3E))) = 0xA;
    if (!((*(u8 *)((u8 *)(reg_a6) + (1))) & 0x40)) goto block_b;
    reg_d0.w = 0;
    (*(u8 *)((u8 *)(reg_a4) + (0x2B))) = reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (0x2A))) = reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (0x35))) = reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (0x34))) = reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (0x3E))) = reg_d0.b[0];
    if (reg_d7.h[0] == 0) goto next_430;
    func_0013C9A0();
    goto next_440;
next_430:
    func_0013CAB0();
next_440:
    (*(u8 *)((u8 *)(reg_a6) + (0x4B))) = 8;
    (*(u8 *)((u8 *)(reg_a6) + (0x4A))) = 4;
    (*(u16 *)((u8 *)(reg_a6) + (0))) &= 0xDFDB;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
    (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xEF;
    if (!(reg_tmp.b[0] & 0x10)) goto next_470;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (*(u16 *)((u8 *)(reg_a6) + (0x2A)));
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (*(u16 *)((u8 *)(reg_a6) + (0x2C)));
    (*(u16 *)((u8 *)(reg_a6) + (0xE))) = (*(u16 *)((u8 *)(reg_a6) + (0x2E)));
    (*(u16 *)((u8 *)(reg_a6) + (6))) = (*(u16 *)((u8 *)(reg_a6) + (0x26)));
    (*(u16 *)((u8 *)(reg_a6) + (8))) = (*(u16 *)((u8 *)(reg_a6) + (0x28)));
next_470:
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x37)));
    if ((s32) (*(u8 *)((u8 *)(reg_a6) + (0x1A))) < (s32) reg_d0.b[0]) goto next_480;
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a6) + (0x3A))) = (*(u8 *)((u8 *)(reg_a6) + (0x36)));
    (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xB3;
    goto block_b;
next_480:
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) += 2;
    (*(u8 *)((u8 *)(reg_a6) + (0x3A))) -= 2;
    (*(u8 *)((u8 *)(reg_a6) + (0x3A))) &= 0x3F;
block_b:
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (4)));
    (*(u16 *)((u8 *)(reg_a6) + (2))) = reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (4))) = reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = reg_d0.h[0];
    if ((*(u8 *)((u8 *)(reg_a6) + (0x1A))) == 0) goto next_530;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x5A)));
    reg_d0.h[0] -= 2;
    if (D_0028E370 == 0) goto next_520;
    if (D_0028ED7C != 2) goto next_510;
    if (D_0028ED70 == 0) goto next_520;
next_510:
    switch ((s32) reg_d0.h[0] >> 1) {
    case 0:
        func_001A0E90();
        break;
    case 1:
        func_001A1040();
        break;
    case 2:
        func_001A1360();
        break;
    }
next_520:
    reg_a6 += 0x20;
    goto next_540;
next_530:
    func_001A2680();
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1E)));
    (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d0.h[0];
    func_001A1B60();
next_540:
    temp = reg_d7.h[0] - 1;
    reg_d7.h[0] = temp;
    if (((s64) ((s64) (temp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_10;
    return;
block_c:
    if (D_0028E370 == 0) goto block_rts;
    if (D_0028ED7C != 2) goto next_610;
    if (D_0028ED70 == 0) goto block_rts;
next_610:
    (*(u8 *)((u8 *)(reg_a6) + (0x1B))) += 8;
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x58)));
    if (reg_d1.h[0] == 0) goto next_620;
    reg_d1.w = 6;
next_620:
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x5A)));
    reg_d0.h[0] -= 2;
    reg_d0.h[0] += reg_d1.h[0];
    reg_a0 = (u8 *)D_0025F3C0;
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) != reg_d0.b[0]) goto next_630;
    (*(u8 *)((u8 *)(reg_a6) + (0))) = 3;
next_630:
    (*(u8 *)((u8 *)(reg_a6) + (0x3B))) = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
    if ((*(u16 *)((u8 *)(reg_a4) + (0x5A))) == 4) goto next_640;
    func_0019F750();
next_640:
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (4)));
    (*(u16 *)((u8 *)(reg_a6) + (2))) = reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (4))) = reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = reg_d0.h[0];
    func_0019F410();
    func_001A2680();
    reg_a6 += 0x20;
    func_001A2680();
    temp = reg_d7.h[0] - 1;
    reg_d7.h[0] = temp;
    if (((s64) ((s64) (temp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_10;
    return;
block_d:
    reg_d0.w = 0x31;
    reg_d1.w = 0;
    reg_a0 = reg_a6;
loop_710:
    *(u16 *)reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    temp2 = reg_d0.h[0] - 1;
    reg_d0.h[0] = temp2;
    if (((s64) ((s64) (u16) temp2 << 0x30) >> 0x30) >= 0) goto loop_710;
    reg_a6 += 0x20;
    temp = reg_d7.h[0] - 1;
    reg_d7.h[0] = temp;
    if (((s64) ((s64) (temp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_10;
    return;
block_e:
    reg_a6 += 0x20;
    temp = reg_d7.h[0] - 1;
    reg_d7.h[0] = temp;
    if (((s64) ((s64) (temp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_10;
block_rts:
    return;
}
