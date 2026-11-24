#include "common.h"

void func_0014EFF0(void) {
    void func_001713F0(s32);
    func_001713F0(0);
}

s32 func_0014E370();
extern u16 D_0024EBC0_as_u16_a[];
extern u16 D_0024EC80[];
extern u16 D_0024EEF0[];
extern u16 D_0026E740[];

void func_0014F000(void) {
    reg_a0 = (u8 *)(D_0026E740);
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    (*(u16 *)((u8 *)(reg_a6) + (0x1A))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
    reg_d1.w = 0;
    reg_d1.b[0] = (u8) (*(u16 *)((u8 *)(reg_a6) + (0x1A)));
    reg_a0 = (u8 *)(D_0024EEF0);
    reg_d1.b[0] += 1;
    reg_d1.h[0] &= 0xFE;
    reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    (*(u8 *)((u8 *)(reg_a6) + (0x1D))) = (u8) reg_d0.b[0];
    reg_a0 = (u8 *)(D_0024EC80);
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)(D_0024EBC0_as_u16_a);
    (*(u16 *)((u8 *)(reg_a5) + (0x1A))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    (*(s16 *)((u8 *)(reg_a5) + (0x1E))) = 2;
    (*(s16 *)((u8 *)(reg_a5) + (0x20))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x22))) = 2;
}


s32 func_0013A780();
s32 func_0014E290();
s32 func_0019BF80();
s32 func_001D27A0();
s32 func_00201C60();
extern u8 D_0028E855;
extern u16 D_0028E8A0;

#define W(o) (*(u16 *)(reg_a6 + (o)))
#define B(o) (*(u8 *)(reg_a6 + (o)))

void func_0014F1D0(void) {
    if (!(D_0028E855 & 0x40)) goto block_5;
    reg_d1.b[0] = B(1);
    func_001D27A0();
    if (cond_flag != 0) goto block_6;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= B(1);
    if (reg_d1.b[0] == 0) goto next_1;
    reg_d0.b[0] = 0xA3;
    B(1) &= reg_d0.b[0];
    if ((s32) B(0x19) >= 0) goto next_1;
block_5:
    reg_d0.w = 1;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = W(2);
    *(u16 *)(reg_a0 + 4) = W(4);
    *(u8 *)(reg_a0 + 0x1B) = B(0x1B);
    reg_d0.b[0] = B(0x1A);
    reg_d0.b[0] += reg_d0.b[0];
    reg_d0.b[0] += reg_d0.b[0];
    *(u8 *)(reg_a0 + 0x1A) = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x1E) = 0xC;
block_6:
    func_0014E290();
    return;
next_1:
    if (D_0028E8A0 != 0) goto next_2;
    func_00201C60();
    if (!((s16) W(2) < -0x400)) goto next_3;
    func_0014E290();
    return;
next_3:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
    *(u8 *)(reg_a5 + 0x1F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_2;
    *(u8 *)(reg_a5 + 0x1F) = *(u8 *)(reg_a5 + 0x1E);
    *(u16 *)(reg_a0 + 0) = *(u16 *)(reg_a5 + 0x1A);
    *(u16 *)(reg_a0 + 2) = *(u16 *)(reg_a5 + 0x1C);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x20);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0x20) += 4;
    *(u16 *)(reg_a5 + 0x20) &= 0xF;
next_2:
    func_0019BF80();
}

void func_0014F430(void) {
    extern void func_001713F0(s32 flag);
    func_001713F0(1);
}

extern u8 D_0024ED80[];
extern u16 D_0024EEB0[];
extern u8 D_0026E760[];

void func_0014F440(void) {
    reg_a0 = D_0026E760;
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    (*(u16 *)((u8 *)(reg_a6) + (0x1A))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
    (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x24)));
    (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x26)));
    (*(u16 *)((u8 *)(reg_a5) + (0x24))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x1E)));
    reg_d0.h[0] += 0x20;
    (*(u16 *)((u8 *)(reg_a5) + (0x26))) = (u16) reg_d0.h[0];
    (*(u8 *)((u8 *)(reg_a5) + (0x29))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x21)));
    (*(s8 *)((u8 *)(reg_a5) + (0x28))) = 0;
    reg_d1.w = 0;
    reg_d1.b[0] = (u8) (*(u16 *)((u8 *)(reg_a6) + (0x1A)));
    reg_a0 = D_0024ED80;
    reg_a1 = (u8 *)(D_0024EEB0);
    reg_d1.h[0] = (u16) reg_d1.b[0];
    reg_d1.h[0] += 4;
    reg_d1.h[0] = (u16) ((s32) reg_d1.h[0] >> 2);
    reg_d1.h[0] &= 0x3E;
    reg_a1 += reg_d1.h[0];
    reg_d1.h[0] = *(u16 *)reg_a1;
    reg_a0 += reg_d1.h[0];
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_d0.h[0];
    reg_d0.w += 3;
    (*(u16 *)((u8 *)(reg_a5) + (0x1A))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a5) + (0x1E))) = 2U;
    (*(s16 *)((u8 *)(reg_a5) + (0x20))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x22))) = 0;
}

s32 func_00129280();
s32 func_0014D220();
s32 func_0019D620();
s32 func_001A9000();
s32 func_002010A0();
s32 func_00201E20();
s32 func_00203060();

#define W(o) (*(u16 *)(reg_a6 + (o)))
#define B(o) (*(u8 *)(reg_a6 + (o)))

void func_0014F5E0(void) {
    u32 count;

    W(0x22) = W(2);
    W(0x24) = W(4);
    if (!(D_0028E855 & 0x40)) goto block_20;
    reg_d1.b[0] = B(1);
    func_001D27A0();
    if (cond_flag != 0) goto block_end;
    B(0x1C) = B(0x3D);
    reg_d1.b[0] = B(1);
    reg_d1.b[0] |= B(0x21);
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] == 0) goto next_100;
    reg_d0.b[0] = 0xA3;
    B(1) &= reg_d0.b[0];
    B(0x21) &= reg_d0.b[0];
    reg_d0.b[0] = B(0x1C);
    reg_d2.b[0] = B(0x3C);
    reg_d0.b[0] ^= reg_d2.b[0];
    B(0x1C) = reg_d0.b[0];
    func_001A9000();
    reg_d2.w = 0x7FFF;
    reg_d2.h[0] -= W(0x18);
    reg_d3.w = 0x7FFF;
    reg_d3.h[0] -= W(0x38);
    if ((s32) reg_d2.w >= (s32) reg_d3.w) goto next_10;
    reg_d2.w = reg_d3.w;
next_10:
    reg_tmp.h[1] = W(0x26);
    reg_tmp.h[0] = W(0x28);
    reg_tmp.w -= reg_d2.w;
    W(0x26) = reg_tmp.h[1];
    W(0x28) = reg_tmp.h[0];
    reg_d0.h[0] = 0x7FFF;
    W(0x18) = reg_d0.h[0];
    W(0x38) = reg_d0.h[0];
    reg_tmp.h[1] = W(0x26);
    reg_tmp.h[0] = W(0x28);
    goto next_100;
block_20:
    reg_d2.h[1] = W(2);
    reg_d2.h[0] = W(4);
    reg_d3.w = 0;
    reg_d7.w = 3;
loop_20:
    reg_d1.w = 0;
    reg_d1.b[0] = B(0x1A);
    reg_d1.b[0] += reg_d1.b[0];
    reg_d1.b[0] += reg_d1.b[0];
    func_002010A0();
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a5 + 0x29);
loop_30:
    reg_d1.b[0] += reg_d0.b[0];
    count = reg_d4.h[0] - 1;
    reg_d4.h[0] = count;
    if (((s64) ((s64) (u16) count << 0x30) >> 0x30) >= 0) goto loop_30;
    func_002010A0();
    reg_d0.h[0] = (s8) reg_d0.b[0];
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 1;
    reg_d0.h[0] += 0xFFFA;
    reg_d0.h[0] += *(u16 *)(reg_a5 + 0x24);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 5;
    reg_d3.w = 0;
    reg_d4.w = 0;
    func_00129280();
    count = reg_d7.h[0] - 1;
    reg_d7.h[0] = count;
    if (((s64) ((s64) (count & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_20;
    reg_d0.w = 2;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = W(2);
    *(u16 *)(reg_a0 + 4) = W(4);
    *(u8 *)(reg_a0 + 0x1B) = B(0x1B);
    reg_d0.b[0] = B(0x1A);
    reg_d0.b[0] += reg_d0.b[0];
    reg_d0.b[0] += reg_d0.b[0];
    *(u8 *)(reg_a0 + 0x1A) = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x1E) = 0xC;
block_end:
    func_0014E290();
    return;
next_100:
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = B(0x1B);
    reg_d1.b[0] = B(0x1A);
    func_00201E20();
    W(2) += reg_d2.h[0];
    W(4) += reg_d3.h[0];
    func_00203060();
    if (cond_flag == 0) goto next_110;
    func_0014E290();
    return;
next_110:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
    *(u8 *)(reg_a5 + 0x1F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_120;
    *(u8 *)(reg_a5 + 0x1F) = *(u8 *)(reg_a5 + 0x1E);
    *(u16 *)(reg_a5 + 0x20) += 4;
    *(u16 *)(reg_a5 + 0x20) &= 0xF;
    reg_tmp.h[1] = W(0xA);
    reg_tmp.h[0] = W(0xC);
    reg_tmp.w += 1;
    W(0xA) = reg_tmp.h[1];
    W(0xC) = reg_tmp.h[0];
    reg_d0.h[1] = *(u16 *)(reg_a5 + 0x1A);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1C);
    reg_tmp.h[1] = W(0xA);
    reg_tmp.h[0] = W(0xC);
    if (reg_tmp.w != reg_d0.w) goto next_120;
    reg_tmp.h[1] = W(0xA);
    reg_tmp.h[0] = W(0xC);
    reg_tmp.w -= 3;
    W(0xA) = reg_tmp.h[1];
    W(0xC) = reg_tmp.h[0];
next_120:
    reg_a0 = reg_a6;
    func_0014D220();
    reg_a0 = reg_a6 + 0x20;
    func_0014D220();
    func_0019D620();
}

void func_0014FAA0(void) {
    void func_001713F0(s32);
    func_001713F0(0);
}

s32 func_0014E370();                            /* extern */
extern s32 D_0026E7A0[];
extern s32 *reg_a0_as_s32_p;

void func_0014FAB0(void) {
    reg_a0_as_s32_p = D_0026E7A0;
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    (*(u16 *)((u8 *)(reg_a6) + (0x1A))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
    (*(u16 *)((u8 *)(reg_a5) + (0x24))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x1E)));
    (*(s16 *)((u8 *)(reg_a5) + (0x26))) = 0;
    (*(u16 *)((u8 *)(reg_a5) + (0x1E))) = 0x101U;
    (*(s16 *)((u8 *)(reg_a5) + (0x20))) = 0;
}

s32 func_00128930();
s32 func_0019D6A0();
s32 func_002011A0();
extern u16 D_00259770[];
extern u16 D_00259870[];
extern u16 D_00259970[];
extern u32 D_0026E7C0[];
extern u16 D_0028E89C;

#define W(o) (*(u16 *)(reg_a6 + (o)))
#define TW(o) (*(u16 *)(reg_a5 + (o)))
#define AW(o) (*(u16 *)(reg_a0 + (o)))
#define LOOKUP(d) (((d) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(d) & ~1)) : *(u16 *)reg_a0)

void func_0014FB30(void) {
    if (D_0028E855 & 0x40) goto next_1;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= reg_a6[1];
    if (reg_d1.b[0] == 0) goto next_2;
    reg_d0.b[0] = 0xA3;
    reg_a6[1] &= reg_d0.b[0];
    W(0x18) = 0x7FFF;
    goto next_2;
next_1:
    reg_d0.w = 1;
    func_0013A780();
    AW(2) = W(2);
    AW(4) = W(4);
    reg_a0[0x1B] = reg_a6[0x1B];
    reg_d0.b[0] = reg_a6[0x1A];
    reg_d0.b[0] += reg_d0.b[0];
    reg_d0.b[0] += reg_d0.b[0];
    reg_a0[0x1A] = reg_d0.b[0];
    AW(0x1E) = 0x10;
    func_0014E290();
    return;
next_2:
    func_00201C60();
    reg_tmp.b[0] = reg_a5[0x27];
    reg_a5[0x27] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_3;
    reg_a5[0x27] = reg_a5[0x26];
    reg_a6[0x1B] -= 1;
next_3:
    if (reg_a6[0x1B] != 0) goto block_saku;
    reg_d0.w = 1;
    func_0013A780();
    AW(2) = W(2);
    AW(4) = W(4);
    reg_a0[0x1B] = reg_a6[0x1B];
    reg_d0.b[0] = reg_a6[0x1A];
    reg_d0.b[0] += reg_d0.b[0];
    reg_d0.b[0] += reg_d0.b[0];
    reg_a0[0x1A] = reg_d0.b[0];
    AW(0x1E) = 0x10;
    func_002011A0();
    reg_d0.h[0] &= 0x3F;
    reg_d1.h[0] = reg_d0.h[0];
    reg_d2.h[1] = W(2);
    reg_d2.h[0] = W(4);
    reg_d3.w = 0;
    reg_d4.w = 0;
    reg_d0.h[0] = 0;
    reg_d0.h[0] = reg_d0.sb[0];
    reg_d0.h[0] += TW(0x1C);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 3;
    if (D_0028E8A0 != 0) goto block_end;
    if (D_0028E89C != 0) goto block_end;
    reg_d7.w = 0xF;
    reg_a0 = (u8 *) D_00259970;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] &= 0x3F;
        reg_d3.h[0] += reg_d3.h[0];
        reg_d3.h[0] += reg_d3.h[0];
        reg_d3.h[1] = LOOKUP(reg_d3.h[0]);
        reg_d3.h[0] = LOOKUP((u16) reg_d3.h[0] + 2);
        func_00128930();
        reg_d1.b[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.w -= 0x50000;
    reg_d0.h[0] = 4;
    reg_d1.b[0] += 2;
    reg_d7.w = 0xF;
    reg_a0 = (u8 *) D_00259870;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] &= 0x3F;
        reg_d3.h[0] += reg_d3.h[0];
        reg_d3.h[0] += reg_d3.h[0];
        reg_d3.h[1] = LOOKUP(reg_d3.h[0]);
        reg_d3.h[0] = LOOKUP((u16) reg_d3.h[0] + 2);
        func_00128930();
        reg_d1.b[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.w -= 0x50000;
    reg_d0.h[0] = 5;
    reg_d1.b[0] += 2;
    reg_d7.w = 0xF;
    reg_a0 = (u8 *) D_00259770;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] &= 0x3F;
        reg_d3.h[0] += reg_d3.h[0];
        reg_d3.h[0] += reg_d3.h[0];
        reg_d3.h[1] = LOOKUP(reg_d3.h[0]);
        reg_d3.h[0] = LOOKUP((u16) reg_d3.h[0] + 2);
        func_00128930();
        reg_d1.b[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
block_end:
    func_0014E290();
    return;
block_saku:
    reg_tmp.b[0] = reg_a5[0x1F];
    reg_a5[0x1F] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_4;
    reg_a5[0x1F] = reg_a5[0x1E];
    TW(0x20) += 4;
    TW(0x20) &= 0x3F;
next_4:
    reg_a0 = (u8 *) D_0026E7C0;
    reg_a0 += TW(0x20);
    reg_d2.h[1] = AW(0);
    reg_d2.h[0] = AW(2);
    reg_d1.h[1] = W(2);
    reg_d1.h[0] = W(4);
    reg_d1.w += 0xFA00FD00;
    reg_d3.h[0] = 0x618;
    reg_d4.w = 0x11;
    func_0019D6A0();
}

void func_00150130(void) {
    void func_001713F0(s32 mode);
    func_001713F0(0);
}

s32 func_0014E7E0();
s32 func_001A3020();
extern u8 D_0025FB30[];
extern u8 D_0026E800[];
extern s8 enemy_move_end_requested;

void func_00150140(void) {
    reg_a0 = D_0026E800;
    func_0014E370();
    reg_d0.h[0] = 0x13;
    reg_a0 = D_0025FB30;
    func_001A3020();
    (*(s16 *)((u8 *)(reg_a5) + (0x18))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x1A))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x1C))) = 0x120;
    (*(s16 *)((u8 *)(reg_a5) + (0x1E))) = 0;
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        (*(u16 *)((u8 *)(reg_a6) + (2))) += 0x200;
    }
}

s32 func_0019C470();
s32 func_00201B80();
extern u8 D_0026E820[];

void func_001501C0(void) {
    u16 temp_a0;
    u16 temp_a1;

    if (D_0028E8A0 == 0) {
        func_00201B80();
        func_00201C60();
        if ((*(u16 *)((u8 *)(reg_a5) + (0x1E))) == 0) {
            (*(u16 *)((u8 *)(reg_a5) + (0x1C))) -= 1;
            if ((*(u16 *)((u8 *)(reg_a5) + (0x1C))) == 0) {
                (*(s16 *)((u8 *)(reg_a6) + (0x1A))) = 0x537;
                (*(u16 *)((u8 *)(reg_a5) + (0x1E))) = 1U;
                (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = 0x808U;
            }
        }
        if ((*(u16 *)((u8 *)(reg_a5) + (0x1E))) == 1) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
            (*(u8 *)((u8 *)(reg_a5) + (0x1D))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
                (*(u8 *)((u8 *)(reg_a6) + (0x1B))) += 1;
            }
        }
        if ((*(s16 *)((u8 *)(reg_a6) + (4))) < -0x21FF) {
            func_0014E290();
            return;
        }
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
            (*(u16 *)((u8 *)(reg_a5) + (0x18))) += 4;
            if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0x1B))) >= 0x10) {
                (*(u16 *)((u8 *)(reg_a5) + (0x18))) += 4;
                (*(u16 *)((u8 *)(reg_a5) + (0x18))) += 4;
            }
            (*(u16 *)((u8 *)(reg_a5) + (0x18))) &= 0x3F;
        }
        goto block_13;
    }
block_13:
    reg_d2.w = 0x1A3A;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a0;
    reg_d3.h[0] = 0x1488;
    reg_d4.w = 0x13;
    func_0019C470();
    reg_a0 = (u8 *)D_0026E820;
    reg_a0 += (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFDC00080;
    reg_d3.h[0] = 0x1488;
    reg_d4.w = 0x13;
    func_0019C470();
}
