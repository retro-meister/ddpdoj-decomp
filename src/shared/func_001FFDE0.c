#include "common.h"

extern s8 D_0028E408;

s32 func_00128970();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0018D560();
s32 func_001A9000();
s32 func_00200420();
s32 func_002004E0();
s32 func_002010A0();
s32 func_002011A0();
s32 func_00201C60();
s32 func_00201D10();
s32 func_00202490();
s32 func_00202500();
extern u16 D_0028E3F0;
extern u16 D_0028E888;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001FFDE0(void) {
    u8 t;
    u8 c;

    func_00201C60();
    *(u16 *)(reg_a5 + 0x1C) -= 1;
    if (*(u16 *)(reg_a5 + 0x1C) == 0) goto block_1;
    if (D_0028E888 == 0) goto block_1;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *)(reg_a6 + 1);
    if (reg_d1.b[0] == 0) goto next_1;
    reg_d0.b[0] = 0xA3;
    *(u8 *)(reg_a6 + 1) &= reg_d0.b[0];
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
    reg_d0.b[0] ^= 0xC;
    *(u8 *)(reg_a6 + 0x1C) = reg_d0.b[0];
    if (*(s16 *)(reg_a6 + 0x18) >= 0) goto next_2;
block_1:
    reg_d0.h[0] = 0x14;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = *(u16 *)(reg_a6 + 4);
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    func_0018D560();
    func_0014E290();
    return;
next_1:
    *(u8 *)(reg_a6 + 0x1C) = 0x13;
next_2:
    t = *(u8 *)(reg_a5 + 0x18);
    if (!(t & 8)) goto next_7;
    if (t & 0x80) goto next_6;
    if (!(0 > *(s16 *)(reg_a6 + 4))) goto next_3;
    *(u8 *)(reg_a6 + 0x1A) += 0x20;
    *(u8 *)(reg_a6 + 0x1A) &= 0x3F;
    *(u8 *)(reg_a5 + 0x18) |= 0x80;
next_3:
    if (*(s16 *)(reg_a6 + 4) <= 0x3800) goto next_4;
    *(u8 *)(reg_a6 + 0x1A) += 0x20;
    *(u8 *)(reg_a6 + 0x1A) &= 0x3F;
    *(u8 *)(reg_a5 + 0x18) |= 0x80;
next_4:
    if (!(*(s16 *)(reg_a6 + 2) < 0x3200)) goto next_6;
    *(u8 *)(reg_a6 + 0x1A) += 0x20;
    *(u8 *)(reg_a6 + 0x1A) &= 0x3F;
    *(u8 *)(reg_a5 + 0x18) |= 0x80;
next_6:
    *(u8 *)(reg_a6 + 0x1B) -= 1;
    if (*(u8 *)(reg_a6 + 0x1B) != 8) goto next_7;
    *(u8 *)(reg_a5 + 0x18) = 4;
    *(s8 *)(reg_a5 + 0x16) = 0;
next_7:
    if (!(*(u8 *)(reg_a5 + 0x18) & 1)) goto next_8;
    *(s8 *)(reg_a5 + 0x16) = 1;
    reg_d0.h[0] = D_0028E3F0;
    reg_d0.h[0] &= 1;
    if (reg_d0.h[0] != 0) goto next_8;
    *(u16 *)(reg_a5 + 0x1A) += 4;
    if ((s16) *(u16 *)(reg_a5 + 0x1A) < 0xC) goto next_8;
    *(u8 *)(reg_a5 + 0x18) &= 0xFE;
    *(u8 *)(reg_a5 + 0x18) |= 2;
    *(u16 *)(reg_a5 + 0x1A) = 0;
    *(u16 *)(reg_a5 + 0x1E) = 8;
next_8:
    if (!(*(u8 *)(reg_a5 + 0x18) & 2)) goto next_11;
    *(s8 *)(reg_a5 + 0x16) = 1;
    if (*(u16 *)(reg_a5 + 0x1E) == 0) goto next_10;
    reg_d0.h[0] = D_0028E3F0;
    reg_d0.h[0] &= 1;
    if (reg_d0.h[0] != 0) goto next_11;
    *(u16 *)(reg_a5 + 0x1E) -= 1;
    if (*(u16 *)(reg_a5 + 0x1A) != 8) goto next_9;
    *(u16 *)(reg_a5 + 0x1A) = 0;
next_9:
    *(u16 *)(reg_a5 + 0x1A) += 4;
    goto next_11;
next_10:
    *(u8 *)(reg_a5 + 0x18) &= 0xFD;
    *(u16 *)(reg_a5 + 0x1A) = 0;
    *(s8 *)(reg_a5 + 0x16) = 0;
next_11:
    if (!(*(u8 *)(reg_a5 + 0x18) & 4)) goto next_14;
    reg_d6.w = 0;
    reg_d7.b[0] = *(u8 *)(reg_a6 + 0x1A);
    func_00202490();
    if (D_0028E408 != 0) goto next_12;
    reg_d6.w = 1;
    reg_d7.b[0] -= reg_d1.b[0];
    if (reg_d7.b[0] == 0) goto next_12;
    goto next_14;
next_12:
    if (reg_d6.b[0] != 0) goto next_13;
    *(u8 *)(reg_a5 + 0x21) = 1;
next_13:
    *(u8 *)(reg_a5 + 0x18) = 0x10;
    *(u16 *)(reg_a5 + 0x22) = 4;
    *(u8 *)(reg_a5 + 0x25) = 0x10;
next_14:
    if (!(*(u8 *)(reg_a5 + 0x18) & 0x10)) goto next_17;
    c = *(u8 *)(reg_a5 + 0x25);
    if (c == 0) goto next_15;
    *(u8 *)(reg_a5 + 0x25) = c - 1;
    goto next_17;
next_15:
    if (*(u16 *)(reg_a5 + 0x22) == 0) goto next_16;
    if (*(u8 *)(reg_a5 + 0x21) != 0) goto block_2;
    reg_d0.h[0] = D_0028E3F0;
    reg_d0.b[0] &= 7;
    if (reg_d0.b[0] != 0) goto next_17;
    reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x1A);
    reg_d0.w = 0x80007;
    reg_d3.w = 0;
    reg_d1.b[0] += 1;
    func_00128970();
    reg_d1.b[0] -= 2;
    func_00128970();
    reg_d1.b[0] += 0x20;
    reg_d1.b[0] &= 0x3F;
    reg_d0.w = 0x30;
    func_00201D10();
    *(u16 *)(reg_a6 + 2) += reg_d2.h[0];
    *(u16 *)(reg_a6 + 4) += reg_d3.h[0];
block_2:
    *(u16 *)(reg_a5 + 0x22) -= 1;
    goto next_17;
next_16:
    *(u8 *)(reg_a5 + 0x18) = 0x20;
    func_002010A0();
    *(u8 *)(reg_a5 + 0x27) = *(u8 *)(reg_a6 + 0x1A);
    *(u8 *)(reg_a5 + 0x27) += reg_d0.b[0];
    *(u8 *)(reg_a5 + 0x27) &= 0x3F;
    *(u8 *)(reg_a5 + 0x25) = 0x10;
    *(u8 *)(reg_a5 + 0x21) = 0;
next_17:
    if (!(*(u8 *)(reg_a5 + 0x18) & 0x20)) goto next_19;
    c = *(u8 *)(reg_a5 + 0x25);
    if (c == 0) goto next_18;
    *(u8 *)(reg_a5 + 0x25) = c - 1;
    goto next_19;
next_18:
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1A);
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x27);
    func_00202500();
    *(u8 *)(reg_a6 + 0x1A) = reg_d1.b[0];
    reg_d1.b[0] -= *(u8 *)(reg_a5 + 0x27);
    if (reg_d1.b[0] != 0) goto next_19;
    *(u8 *)(reg_a5 + 0x18) = 0x40;
    *(u8 *)(reg_a5 + 0x25) = 0x10;
next_19:
    if (!(*(u8 *)(reg_a5 + 0x18) & 0x40)) goto next_20;
    *(u8 *)(reg_a5 + 0x25) -= 1;
    if (*(u8 *)(reg_a5 + 0x25) != 0) goto next_20;
    *(u8 *)(reg_a5 + 0x18) = 9;
    *(u8 *)(reg_a6 + 0x1B) = 0x20;
    func_002011A0();
    reg_d0.b[0] &= 7;
    *(u8 *)(reg_a6 + 0x1B) += reg_d0.b[0];
next_20:
    func_00200420();
    func_002004E0();
    reg_a0 = reg_a6;
    func_0014D220();
}
