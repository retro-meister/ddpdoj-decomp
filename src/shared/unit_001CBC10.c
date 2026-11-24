#include "common.h"

extern u8 *reg_a6;

void func_001CBC10(void) {
    reg_d0.h[0] = 0x8000;
    (*(u16 *)((u8 *)(reg_a6) + (0x40))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x60))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x80))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0xA0))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0xC0))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0xE0))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x100))) = (u16) reg_d0.h[0];
}

extern u32 reg_a6_as_u32;
extern u32 reg_a0_as_u32;

void func_001CBC70(void) {
    reg_a0_as_u32 = reg_a6_as_u32;
    reg_a0_as_u32 += reg_d0.h[0];
    *(u16 *)reg_a0_as_u32 = 0xA000;
}

void func_001CBCA0(void) {
    reg_a0_as_u32 = reg_a6_as_u32;
    reg_a0_as_u32 += reg_d0.h[0];
    *(u16 *)reg_a0_as_u32 = 0x8000;
}

void func_001CBCD0(void) {
    *(s16 *)(reg_a6 + 0x146) = 1;
}

s32 func_001CB6B0();
void func_00203400(void);
extern u16 D_0028E8A0;
extern u8 *reg_a5;

void func_001CBCE0(void) {
#ifdef DEATH_LABEL
    if ((D_0028E8A0 == 0) && ((*(u16 *)((u8 *)(reg_a5) + (0x1A))) == 0)) {
#else
    if ((D_0028E8A0 == 0) && ((*(u16 *)((u8 *)(reg_a5) + (0x1A))) -= 1, (*(u16 *)((u8 *)(reg_a5) + (0x1A))) == 0)) {
#endif
        func_00203400();
        if (reg_d0.h[0] == 0) {
            (*(u16 *)((u8 *)(reg_a5) + (0x1A))) = 0x78U;
            return;
        }
        (*(s16 *)((u8 *)(reg_a6) + (0x14A))) = 0;
        func_001CB6B0();
    }
}

void func_001713F0(s32);

void func_001CBD50(void) {
    func_001713F0(2);
}

extern s8 D_0028E408;

s32 func_0013B2E0();
s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_0018DAD0();
s32 func_002026F0();
extern u16 D_002590F0[];
extern u8 D_00263000[];
extern u8 D_00263030[];
extern u8 D_002630D0[];
extern s16 D_0028E894_as_s16;
extern u16 D_0028E910;
extern u16 D_0028E91C;
extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a3;

void func_001CBD60(void) {
    reg_a0 = D_00263030;
    func_0014E370();
    reg_tmp.w = (u32) reg_a0;
    (*(u16 *)((u8 *)(reg_a5) + (0x44))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x46))) = (u16) reg_tmp.h[0];
    reg_a0 = D_00263000;
    reg_d0.w = 0x14;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0)));
        reg_d0.h[0] &= 0xE7FF;
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x20)));
        reg_d2.h[0] &= 0xDFFE;
        reg_d0.h[0] |= reg_d2.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x20))) = (u16) reg_d0.h[0];
        reg_a3 = (u8 *)(D_002590F0);
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d0.h[0] += 0xAC0;
        reg_d1.h[0] += 0x780;
        func_002026F0();
        if (D_0028E408 != 0) {
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
            reg_d1.b[0] *= 4;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x2C))) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0xF8;
        reg_d1.h[0] >>= 1;
        (*(u16 *)((u8 *)(reg_a5) + (0x28))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
        (*(u16 *)((u8 *)(reg_a5) + (0x2A))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d0.h[0] += 0xAC0;
        reg_d1.h[0] += 0x7FFF + 0x7881;
        func_002026F0();
        if (D_0028E408 != 0) {
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
            reg_d1.b[0] *= 4;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x32))) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0xF8;
        reg_d1.h[0] >>= 1;
        (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
        (*(u16 *)((u8 *)(reg_a5) + (0x30))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
        reg_d0.b[0] = 0x10;
        reg_d1.b[0] = 2;
        reg_d2.b[0] = 0x18;
        if ((s32) D_0028E91C > 1) {
            reg_d0.b[0] = 0x10;
            reg_d1.b[0] = 2;
            reg_d2.b[0] = 0x18;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x35))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a5) + (0x34))) = (u8) reg_d1.b[0];
        (*(u8 *)((u8 *)(reg_a5) + (0x3D))) = (u8) reg_d2.b[0];
        reg_a0 = D_002630D0;
        func_0013B2E0();
        D_0028E894_as_s16 = 1;
        func_0018DAD0();
        D_00299768[0] = 1;
        if (D_0028E910 != 0) {
            D_0029976A[0] = 1;
        }
    }
}

typedef void (*Fn)();

extern u8 D_002590F0_as_u8_a[];
extern u8 D_002594F0_as_u8_a[];
s32 func_00129280();
s32 func_001292C0();
s32 func_00129370();
s32 func_001293C0();
s32 func_00129410();
s32 func_00136980();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_00171400();
s32 func_0018D5C0();
s32 func_0018DDC0();
s32 func_0019BEC0();
s32 func_0019BFC0();
s32 func_0019C470();
s32 func_0019C530();
s32 func_0019C570();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_002010D0();
s32 func_002011A0();
s32 func_00201800();
s32 func_002025E0();
s32 func_002027A0();
s32 vibration_start_pad1(s32, s32);
s32 vibration_start_pad2(s32, s32);
extern u16 D_00259970[];
extern u16 D_00262A50_as_u16_a[];
extern u16 D_00263100[];
extern u16 D_00263120[];
extern u16 D_00263180[];
extern u16 D_00263240[];
extern u16 D_00263270[];
extern u16 D_00263280[];
extern u16 D_00263290[];
extern u8 D_0028E310;
extern u16 D_0028E3EC;
extern u16 D_0028E3F0;
extern s16 *D_0028E44C;
extern Reg32 D_0028E484;
extern u8 D_0028E489;
extern u16 D_0028E894;
extern u16 D_0028E89C;
extern u16 D_0028E8A8;
extern u16 D_0028E8B8;
extern u16 D_0028E8C8;
extern u16 D_0028E8D8;
extern u16 D_0029C068[];
extern u16 D_0029F1F0_as_u16_a[];
extern u16 D_0029F260_as_u16_a[];
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a4;

void func_001CC0A0(void) {
    u32 cnt;
    u16 val;
    u8 bits;
    u8 *ptr;

    if (*(s8 *)reg_a6 < 0) goto skip_1;
    func_0014EA50();
    if (enemy_move_end_requested != 0) return;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0);
    reg_d0.h[0] &= 0xE7FF;
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_d2.h[0] &= 0xDFFE;
    reg_d0.h[0] |= reg_d2.h[0];
    *(u16 *)(reg_a6 + 0x20) = reg_d0.h[0];
    reg_d0.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d0.h[0] += 0x1A00;
    reg_d0.h[0] += D_0029C068[0];
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0x9400;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += D_0028E484.w;
    reg_d0.h[0] += 0x9400;
    if (reg_tmp.h[1] != 0) goto next_20;
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0x7A00;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] += 0xE00;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += D_0028E484.w;
    reg_d0.h[0] += 0x7A00;
    if (reg_tmp.h[1] == 0) goto next_30;
next_20:
    if (*(u8 *)(reg_a5 + 0x17) == 0) goto next_40;
    D_0028E894 = 0;
    func_0018DDC0();
    func_0014E290();
    return;
next_30:
    *(u8 *)(reg_a5 + 0x17) = 1;
next_40:
    if (*(u8 *)(reg_a6 + 0x1F) != 0) goto next_45;
    reg_tmp.w = 0xB000;
    *(u16 *)(reg_a6 + 0x3C) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x3E) = reg_tmp.h[0];
next_45:
    *(u16 *)(reg_a6 + 0x22) = *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a6 + 0x24) = *(u16 *)(reg_a6 + 4);
    reg_d1.b[0] = *(u8 *)(reg_a6 + 1);
    reg_d1.b[0] |= *(u8 *)(reg_a6 + 0x21);
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) goto next_50;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
    reg_d3.b[0] = *(u8 *)(reg_a6 + 0x49);
    reg_d5.b[0] = *(u8 *)(reg_a6 + 0x4B);
    if (!((s32) *(u16 *)(reg_a6 + 0x18) < 0x2C00)) goto next_90;
    if (D_0028E8B8 != 0) goto next_90;
    reg_d0.w = 0x19;
    goto next_90;
next_50:
    reg_d0.h[0] = 0xA3;
    *(u8 *)(reg_a6 + 1) &= reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x21) &= reg_d0.b[0];
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
    reg_d3.b[0] = *(u8 *)(reg_a6 + 0x47);
    reg_d5.b[0] = *(u8 *)(reg_a6 + 0x46);
    if (reg_d0.b[0] != 0x19) goto next_60;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
    reg_d3.b[0] = *(u8 *)(reg_a6 + 0x49);
    reg_d5.b[0] = *(u8 *)(reg_a6 + 0x4B);
next_60:
    reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1C);
    reg_d0.b[0] ^= reg_d2.b[0];
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0x48);
    reg_d3.b[0] ^= reg_d2.b[0];
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0x4A);
    reg_d5.b[0] ^= reg_d2.b[0];
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x18);
    if (!((s16) *(u16 *)(reg_a6 + 0x38) < (s16) reg_d4.h[0])) goto next_80;
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x38);
next_80:
    reg_d6.w = 0x7FFF;
    *(u16 *)(reg_a6 + 0x18) = reg_d6.h[0];
    *(u16 *)(reg_a6 + 0x38) = reg_d6.h[0];
    reg_d6.h[0] -= reg_d4.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x3C);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x3E);
    reg_tmp.w -= reg_d6.w;
    *(u16 *)(reg_a6 + 0x3C) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x3E) = reg_tmp.h[0];
    if ((s32) reg_tmp.w < 0) goto next_700;
next_90:
    *(u8 *)(reg_a6 + 0x1C) = reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x47) = reg_d3.b[0];
    *(u8 *)(reg_a6 + 0x46) = reg_d5.b[0];
    reg_d0.h[1] = *(u16 *)(reg_a6 + 0x3C);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x3E);
    func_00136980();
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x27);
    *(u8 *)(reg_a6 + 0x27) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_120;
    *(u8 *)(reg_a6 + 0x27) = *(u8 *)(reg_a6 + 0x26);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x28);
    reg_a0 = (u8 *) D_00263100;
    switch (reg_d0.h[0]) { case 0: goto block_zero; }
    val = *(u16 *)(reg_a0 + ((s16) reg_d0.h[0] & ~1));
    goto block_join;
block_zero:
    val = *(u16 *)reg_a0;
block_join:
    *(u16 *)(reg_a6 + 0x2A) = val;
    *(u16 *)(reg_a6 + 0x2C) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x28) -= 4;
    if ((s16) *(u16 *)(reg_a6 + 0x28) >= 0) goto next_120;
    *(u16 *)(reg_a6 + 0x28) = 0x1C;
next_120:
    if (D_0028E8A0 != 0) goto next_500;
    if (D_0028E89C != 0) goto next_500;
    if (D_0028E8A0 != 0) goto next_500;
    if (D_0028E89C != 0) goto next_500;
    if (*(u16 *)(reg_a5 + 0x18) != 0) goto next_400;
    if ((s16) *(u16 *)(reg_a6 + 2) < 0x1000) goto next_400;
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1A);
    if (reg_d0.h[0] != 0) goto next_200;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
    *(u8 *)(reg_a5 + 0x1F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_400;
    *(u8 *)(reg_a5 + 0x1F) = *(u8 *)(reg_a5 + 0x35);
    *(u16 *)(reg_a5 + 0x1A) = 1;
    goto next_400;
next_200:
    if ((reg_d0.h[0] & 0xFFFF) != 1) goto next_220;
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x3B);
    *(u8 *)(reg_a6 + 0x3B) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_400;
    *(u8 *)(reg_a6 + 0x3B) = *(u8 *)(reg_a6 + 0x3A);
    *(u16 *)(reg_a6 + 0x2E) += 4;
    if (*(u16 *)(reg_a6 + 0x2E) != 0x5C) goto next_400;
    *(u16 *)(reg_a5 + 0x1A) = 2;
    goto next_400;
next_220:
    if ((reg_d0.h[0] & 0xFFFF) != 2) goto next_300;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
    *(u8 *)(reg_a5 + 0x1F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_400;
    reg_d0.h[0] = 0x10;
    reg_d1.h[0] = D_0028E8C8;
    reg_d1.h[0] >>= 2;
    reg_d0.b[0] -= reg_d1.b[0];
    *(u8 *)(reg_a5 + 0x1F) = reg_d0.b[0];
    reg_a0 = (u8 *) D_0029F260_as_u16_a;
    reg_a1 = (u8 *) D_0029F1F0_as_u16_a;
    if (*(u8 *)(reg_a5 + 2) == 0) goto next_240;
    D_0028E44C = (s16 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) D_0028E44C;
next_240:
    if (*(s16 *)reg_a0 < 0) goto next_260;
    if (*(s16 *)reg_a1 >= 0) goto next_400;
    ptr = reg_a0;
    reg_a0 = reg_a1;
    D_0028E44C = (s16 *) ptr;
    reg_a1 = ptr;
next_260:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d0.h[0] += 0xF800;
    func_002027A0();
    reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d4.w = 0;
    reg_a0 = (u8 *) D_00263240;
    reg_a1 = (u8 *) D_00262A50_as_u16_a;
    reg_d6.h[0] = reg_d1.h[0];
    reg_d7.w = 0xB;
loop_280:
    func_002010D0();
    reg_d1.b[0] = (s8) reg_d1.b[0] * 8;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x3A);
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = 0x13;
    reg_d5.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d5.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a1 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a1 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d3.w += reg_d5.w;
    if (!(reg_d7.h[0] & 1)) goto next_285;
    func_00129370();
    goto next_290;
next_285:
    func_00129280();
next_290:
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (cnt & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_280;
    func_00171400();
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
    *(u8 *)(reg_a5 + 0x21) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_400;
    *(u8 *)(reg_a5 + 0x21) = *(u8 *)(reg_a5 + 0x20);
    reg_d0.h[0] = 0x50;
    reg_d0.h[0] -= D_0028E8D8;
    *(u8 *)(reg_a5 + 0x1F) = reg_d0.b[0];
    *(u16 *)(reg_a5 + 0x1A) = 3;
    goto next_400;
next_300:
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x3B);
    *(u8 *)(reg_a6 + 0x3B) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_400;
    *(u8 *)(reg_a6 + 0x3B) = *(u8 *)(reg_a6 + 0x3A);
    *(u16 *)(reg_a6 + 0x2E) -= 4;
    if (*(u16 *)(reg_a6 + 0x2E) != 0) goto next_400;
    *(u16 *)(reg_a5 + 0x1A) = 0;
    *(u16 *)(reg_a5 + 0x18) = 1;
next_400:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2E);
    reg_a0 = (u8 *) D_00263180;
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x30) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x32) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x34) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x36) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a0 = (u8 *) D_0029F260_as_u16_a;
    reg_a1 = (u8 *) D_0029F1F0_as_u16_a;
    if (*(u8 *)(reg_a5 + 2) == 0) goto next_420;
    D_0028E44C = (s16 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) D_0028E44C;
next_420:
    if (*(s16 *)reg_a0 < 0) goto next_440;
    if (*(s16 *)reg_a1 >= 0) goto next_500;
    ptr = reg_a0;
    reg_a0 = reg_a1;
    D_0028E44C = (s16 *) ptr;
    reg_a1 = ptr;
next_440:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d5.w = 4;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x25);
    if (*(u8 *)(reg_a5 + 0x24) != reg_d0.b[0]) goto next_460;
    reg_d5.w = 1;
next_460:
    reg_a3 = (u8 *)D_002590F0_as_u8_a;
    bits = *(u8 *)reg_a6;
    if (bits & 0x40) {
        *(u8 *)reg_a6 = bits & 0xBF;
        goto next_480;
    }
    *(u8 *)reg_a6 = bits | 0x40;
    reg_d0.h[0] += 0xAC0;
    reg_d1.h[0] += 0x780;
    func_002027A0();
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x2C);
    func_002025E0();
    *(u16 *)(reg_a5 + 0x2C) = reg_d1.h[0];
    reg_d1.b[0] += 4;
    reg_d1.h[0] &= 0xF8;
    reg_d1.h[0] >>= 1;
    *(u16 *)(reg_a5 + 0x28) = (reg_d1.h[0] != 0) ? *(u16 *)(reg_a3 + ((s16) reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
    *(u16 *)(reg_a5 + 0x2A) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a3 + ((s16) (reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
    goto next_500;
next_480:
    reg_d0.h[0] += 0xAC0;
    reg_d1.h[0] += 0xF880;
    func_002027A0();
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x32);
    func_002025E0();
    *(u16 *)(reg_a5 + 0x32) = reg_d1.h[0];
    reg_d1.h[0] += 4;
    reg_d1.h[0] &= 0xF8;
    reg_d1.h[0] >>= 1;
    *(u16 *)(reg_a5 + 0x2E) = (reg_d1.h[0] != 0) ? *(u16 *)(reg_a3 + ((s16) reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
    *(u16 *)(reg_a5 + 0x30) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a3 + ((s16) (reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
next_500:
    reg_a2 = (u8 *) func_0019BFC0;
    reg_a3 = (u8 *) func_0019C570;
    reg_a4 = (u8 *) func_0019C530;
    if (!((s32) D_0028E8A8 < 0x11E)) goto next_510;
    reg_a2 = (u8 *) func_0019BEC0;
    reg_a3 = (u8 *) func_0019C470;
    reg_a4 = (u8 *) func_0019C470;
next_510:
    jtbl_0028E3F4 = (Fn) reg_a2;
    jtbl_0028E3F4();
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[0] += 0xF200;
    reg_d1.h[1] += 0xE400;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2E);
    reg_a0 = (u8 *) D_00263120;
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = 0x1670;
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x46);
    jtbl_0028E3F4 = (Fn) reg_a3;
    jtbl_0028E3F4();
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[0] += 0x480;
    reg_d1.h[1] += 0x6C0;
    reg_d2.h[1] = *(u16 *)(reg_a5 + 0x28);
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x2A);
    reg_d3.h[0] = 0x418;
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
    jtbl_0028E3F4 = (Fn) reg_a3;
    jtbl_0028E3F4();
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[0] += 0xF580;
    reg_d2.h[1] = *(u16 *)(reg_a5 + 0x2E);
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x30);
    jtbl_0028E3F4 = (Fn) reg_a3;
    jtbl_0028E3F4();
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[0] += 0xEE00;
    reg_d1.h[1] += 0xF900;
    reg_d2.h[1] = *(u16 *)(reg_a6 + 0x2A);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x2C);
    reg_d3.h[0] = 0x1290;
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x47);
    jtbl_0028E3F4 = (Fn) reg_a3;
    jtbl_0028E3F4();
    if (D_0028E910 != 0) goto next_540;
    if (D_0028E3EC == 0) goto next_540;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[1] += 0xD600;
    reg_d2.w = 0x1B9F;
    reg_d3.h[0] = 0xC48;
    reg_d4.h[0] = 0x18;
    if (!(D_0028E3F0 & 2)) goto next_520;
    reg_d4.h[0] |= 0x4000;
next_520:
    jtbl_0028E3F4 = (Fn) reg_a4;
    jtbl_0028E3F4();
next_540:
    reg_a0 = reg_a6;
    func_0014D220();
    reg_a0 = reg_a6 + 0x20;
    func_0014D220();
    if (D_0028E8A0 != 0) goto block_rts;
    if (D_0028E89C != 0) goto block_rts;
    if ((s16) *(u16 *)(reg_a6 + 2) < 0x1000) goto block_rts;
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (reg_d0.h[0] == 0) goto block_rts;
    if (reg_d0.h[0] != 1) goto next_800;
    D_0028E484.w = 0;
    reg_tmp.w = 0;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
    reg_tmp.h[0] -= 1;
    *(u8 *)(reg_a5 + 0x23) -= 1;
    if (D_0028E489 != 0) goto next_600;
block_rts:
    return;
next_600:
    *(u8 *)(reg_a5 + 0x23) = *(u8 *)(reg_a5 + 0x34);
    reg_a4 = (u8 *)D_002594F0_as_u8_a;
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x2C);
    reg_d0.h[0] = reg_d1.h[0];
    reg_d0.h[0] += 4;
    reg_d0.h[0] &= 0xF8;
    reg_d0.h[0] >>= 1;
    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a4 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a4 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] += 0x780;
    reg_d3.h[1] += 0xAC0;
    reg_d4.w = (u32) reg_a6;
    reg_d0.w = 0x180007;
    reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
    func_001293C0();
    reg_d6.b[0] = *(u8 *)(reg_a5 + 0x25);
    reg_d6.b[0] += reg_d6.b[0];
    reg_d6.b[0] += *(u8 *)(reg_a5 + 0x3C);
    reg_d1.b[0] -= reg_d6.b[0];
    func_001292C0();
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x32);
    reg_d4.h[0] = reg_d1.h[0];
    reg_d4.h[0] += 4;
    reg_d4.h[0] &= 0xF8;
    reg_d4.h[0] >>= 1;
    reg_d3.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)(reg_a4 + ((s16) reg_d4.h[0] & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] = (((u16) reg_d4.h[0] + 2) != 0) ? *(u16 *)(reg_a4 + ((s16) ((u16) reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] += 0xF880;
    reg_d3.h[1] += 0xAC0;
    func_001293C0();
    reg_d6.b[0] = *(u8 *)(reg_a5 + 0x25);
    reg_d6.b[0] += reg_d6.b[0];
    reg_d6.b[0] += *(u8 *)(reg_a5 + 0x3C);
    reg_d1.b[0] += reg_d6.b[0];
    func_001292C0();
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x25);
    *(u8 *)(reg_a5 + 0x25) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_650;
    *(u8 *)(reg_a5 + 0x24) += 6;
    *(u8 *)(reg_a5 + 0x25) = *(u8 *)(reg_a5 + 0x24);
    *(u8 *)(reg_a5 + 0x23) = *(u8 *)(reg_a5 + 0x22);
    func_00171400();
    *(u16 *)(reg_a5 + 0x18) = 2;
    *(u8 *)(reg_a5 + 0x3C) -= 2;
    if ((s32) *(u8 *)(reg_a5 + 0x3C) >= 5) goto next_650;
    *(u8 *)(reg_a5 + 0x3C) = 5;
next_650:
    return;
next_800:
    reg_tmp.w = 0;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x37);
    reg_tmp.h[0] -= 1;
    *(u8 *)(reg_a5 + 0x37) -= 1;
    if (D_0028E489 != 0) goto next_820;
    return;
next_820:
    *(u8 *)(reg_a5 + 0x37) = *(u8 *)(reg_a5 + 0x3D);
    if (!(*(u8 *)(reg_a5 + 0x38) & 4)) goto next_830;
    func_002011A0();
    reg_d1.h[0] = reg_d0.h[0];
    goto next_870;
next_830:
    reg_a0 = (u8 *) D_0029F260_as_u16_a;
    reg_a1 = (u8 *) D_0029F1F0_as_u16_a;
    if (*(u8 *)(reg_a5 + 2) == 0) goto next_840;
    D_0028E44C = (s16 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) D_0028E44C;
next_840:
    if (*(s16 *)reg_a0 < 0) goto next_860;
    if (*(s16 *)reg_a1 >= 0) goto next_900;
    ptr = reg_a0;
    reg_a0 = reg_a1;
    D_0028E44C = (s16 *) ptr;
    reg_a1 = ptr;
next_860:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d0.h[0] += 0xF940;
    func_002027A0();
next_870:
    reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d4.h[0] = *(u16 *)(reg_a5 + 0x38);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x3E);
    reg_d0.h[0] = reg_d0.h[0] - reg_d4.h[0];
    reg_d0.h[0] >>= 1;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = 3;
    if (!(*(u8 *)(reg_a5 + 0x38) & 4)) goto next_875;
    reg_d0.h[0] = 3;
next_875:
    reg_a0 = (u8 *) D_00263270;
    reg_d5.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d4.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d5.h[0] = (((u16) reg_d4.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) ((u16) reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) D_00263280;
    reg_d6.h[0] = (reg_d4.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d4.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d7.h[0] = (((u16) reg_d4.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) ((u16) reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d4.w = 0;
    reg_a0 = (u8 *) D_00259970;
loop_880:
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += reg_d5.w;
    func_00129410();
    if (!(reg_d7.h[0] & 1)) goto next_890;
    reg_d0.w -= 0x60000;
    reg_d0.h[0] += 1;
    func_00129280();
    reg_d0.w += 0x60000;
    reg_d0.h[0] -= 1;
next_890:
    reg_d1.h[0] += reg_d6.h[0];
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (cnt & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_880;
    *(u16 *)(reg_a5 + 0x38) -= 4;
    if ((s16) *(u16 *)(reg_a5 + 0x38) >= 0) goto next_900;
    *(u16 *)(reg_a5 + 0x3E) += 8;
    *(u16 *)(reg_a5 + 0x38) = 0xC;
    *(u8 *)(reg_a5 + 0x37) = *(u8 *)(reg_a5 + 0x36);
    func_00171400();
    *(u16 *)(reg_a5 + 0x18) = 0;
next_900:
    return;
next_700:
    func_0018DDC0();
    func_0018D5C0();
    *(u16 *)(reg_a6 + 0x4E) = reg_d1.h[0];
    reg_d0.w = 0x457;
    func_001A91A0();
    vibration_start_pad1(0xB4, 0x3C);
    vibration_start_pad2(0xB4, 0x3C);
    D_0028E310 = 0x3C;
    reg_a0 = (u8 *) D_00263290;
    func_0013B2E0();
    reg_d0.h[0] = 0x8080;
    (*(s16 *)((u8 *)(reg_a6) + (0))) = (s16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x20))) = (u16) reg_d0.h[0];
    reg_d0.w = 0xD;
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    val = (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(u16 *)((u8 *)(reg_a0) + (4))) = val;
    (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
    (*(s16 *)((u8 *)(reg_a0) + (0x26))) = 0x400;
    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x400;
    reg_d0.h[0] = 0x84;
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
    (*(s16 *)((u8 *)(reg_a0) + (0x26))) = 0x400;
    (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0x200;
    (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0x44C;
    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
    (*(s16 *)((u8 *)(reg_a0) + (0x18))) = 1;
    reg_d0.h[0] = 0x84;
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
    (*(s16 *)((u8 *)(reg_a0) + (0x26))) = 0x400;
    (*(u16 *)((u8 *)(reg_a0) + (0x28))) = 0xFE00;
    (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0x4B4;
    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x400;
    (*(s8 *)((u8 *)(reg_a0) + (0x1D))) = 0x40;
    (*(s16 *)((u8 *)(reg_a0) + (0x18))) = 2;
    reg_d0.w = 0xD;
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xFA00;
    (*(u16 *)((u8 *)(reg_a0) + (0x28))) = 0xFE00;
    (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0x6A8;
    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
    (*(s16 *)((u8 *)(reg_a0) + (0x18))) = 2;
    reg_d0.h[0] = 0x85;
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xFC00;
    (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0x100;
    (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0x858;
    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
    (*(s16 *)((u8 *)(reg_a0) + (0x18))) = 4;
    reg_d0.h[0] = 0x85;
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xF400;
    (*(u16 *)((u8 *)(reg_a0) + (0x28))) = 0xFE00;
    (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0xA88;
    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x400;
    (*(s16 *)((u8 *)(reg_a0) + (0x18))) = 6;
    reg_d0.w = 0xD;
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xF400;
    (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0x400;
    (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0xA78;
    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x400;
    (*(s16 *)((u8 *)(reg_a0) + (0x18))) = 4;
    reg_d0.h[0] = 0xD;
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
    (*(s16 *)((u8 *)(reg_a0) + (0x26))) = 0;
    (*(u16 *)((u8 *)(reg_a0) + (0x28))) = 0xF200;
    (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0x4A0;
    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x400;
    (*(s16 *)((u8 *)(reg_a0) + (0x18))) = 8;
    reg_d0.h[0] = 0xD;
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
    (*(s16 *)((u8 *)(reg_a0) + (0x26))) = 0;
    (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0xE00;
    (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0x460;
    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x400;
    (*(s16 *)((u8 *)(reg_a0) + (0x18))) = 8;
    reg_d0.h[0] = 0x85;
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xEA00;
    (*(u16 *)((u8 *)(reg_a0) + (0x28))) = 0xF600;
    (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0xA90;
    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x400;
    (*(s16 *)((u8 *)(reg_a0) + (0x18))) = 0xA;
    reg_d0.h[0] = 0x85;
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xEA00;
    (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0xA00;
    (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0xA70;
    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x400;
    (*(s16 *)((u8 *)(reg_a0) + (0x18))) = 0xA;
    reg_d0.h[0] = 0x85;
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xE400;
    (*(s16 *)((u8 *)(reg_a0) + (0x28))) = 0x200;
    (*(s16 *)((u8 *)(reg_a0) + (0x1A))) = 0x588;
    (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
    (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0x400;
    (*(s16 *)((u8 *)(reg_a0) + (0x18))) = 8;
skip_1:
    if (*(u16 *)(reg_a6 + 0x4C) == 0x30) {
        D_0028E894 = 0;
    }
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x4E);
    func_00201800();
    *(u16 *)(reg_a6 + 0x4C) -= 1;
    if (*(u16 *)(reg_a6 + 0x4C) == 0) {
        func_0018DDC0();
        func_0014E290();
    }
}
