#include "common.h"

void func_0020EC90(void);
void func_0020ECE0(void);

extern u8 D_0028E218;
extern u8 D_0028E21C;


void func_0020EAA0(void) {
    D_0028E21C = 0;
    D_0028E218 = 0;
    func_0020ECE0();
}

extern u8 D_00269360[];
extern u8 D_00269380[];
extern u8 D_00269398[];
extern u8 D_002693A8[];
extern u16 D_0028DFE4;
extern u16 D_0028DFE8;
extern u8 D_0028E36C;
extern u8 D_0028E378;
extern u16 D_0028E3A0_as_u16;
extern u16 D_0028E3A4_as_u16;
extern u16 D_0028E3A8_as_u16;
extern u16 D_0028E3AC;
extern u16 D_0028E3B0_as_u16;
extern u16 D_0028E3E8;
extern u16 D_0028E5F8;
extern u16 D_0028E5FC;
extern u16 D_0028E7E4;
extern u16 D_0028E910;
extern u16 D_0028E914;
extern u16 D_0028E918;
extern u16 D_00299760[];
extern u16 D_0029976A_as_u16_a[];
void func_0020EAB0(void) {
    u8 *tbl;

    func_0020EC90();
    if (D_0028E36C != 0) return;
    D_0028E21C = 1;
    if (D_0028E3E8 != 0) return;
    if (D_0028E3B0_as_u16 != 0) {
        D_0028E3B0_as_u16 -= 1;
        goto next_20;
    }
    if (D_0028E3A4_as_u16 != 0) return;
    reg_d0.h[0] = D_00299760[0];
    if (D_0028E7E4 == 0) goto next_5;
    if (D_0028E3A8_as_u16 == 0) return;
next_5:
    reg_d0.h[0] += D_0028DFE8;
    reg_d0.h[0] += D_0028DFE4;
    reg_d0.h[0] += D_0028DFE4;
    reg_d1.w = 0;
    tbl = D_00269360;
    if (D_0028E910 == 0) goto next_8;
    tbl = D_00269380;
    if (D_0028E3A0_as_u16 == 0) return;
    reg_d1.h[0] += 0x28;
next_8:
    reg_d2.h[0] = D_0028E914;
    tbl += reg_d2.h[0] & ~1;
    reg_d1.h[0] += *(s16 *) (tbl + 0);
    if (D_0029976A_as_u16_a[0] == 0) goto next_10;
    reg_d1.h[0] += *(s16 *) (tbl + 2);
next_10:
    reg_d2.h[0] = D_0028E5FC;
    reg_d2.h[0] |= D_0028E5F8;
    if (reg_d2.h[0] == 0) goto next_12;
    reg_d1.h[0] += 0x1E;
next_12:
    if (!((s32) reg_d1.h[0] > (s32) reg_d0.h[0])) goto next_15;
    if (D_0028E3AC == 0) return;
    D_0028E3AC -= 1;
    goto next_20;
next_15:
    tbl = D_00269398;
    if (D_0028E910 == 0) goto next_17;
    tbl = D_002693A8;
next_17:
    reg_d2.h[0] = (s32) D_0028E918 >> 1;
    reg_d2.h[0] = ((s16 *) tbl)[reg_d2.h[0]];
    if (!((s32) D_0028E3AC < (s32) reg_d2.h[0])) goto next_20;
    D_0028E3AC += 2;
next_20:
    D_0028E21C = 2;
    if (D_0028E378 == 0xFF) {
        D_0028E21C = 0;
    }
}

s32 func_0011C250();                            /* extern */
s32 func_0011C950();                            /* extern */
s32 func_00130790();                            /* extern */
s32 func_00130A60();                            /* extern */
s32 func_001A2C80();                            /* extern */
s32 func_001AB5C0();                            /* extern */
s32 func_00206CB0();                            /* extern */

void func_0020EC90(void) {
    func_00130790();
    func_00130A60();
    func_001A2C80();
    func_0011C250();
    func_0011C950();
    func_001AB5C0();
    func_00206CB0();
}

extern s16 D_0028E3A0;
extern s16 D_0028E3A4;
extern s16 D_0028E3A8;
extern s16 D_0028E3AC_as_s16;
extern s16 D_0028E3B0;

void func_0020ECE0(void) {
    D_0028E3B0 = 0;
    D_0028E3AC_as_s16 = 0;
    D_0028E3A8 = 0;
    D_0028E3A4 = 0;
    D_0028E3A0 = 0;
}

void func_0020ED00(void) {
    D_0028E3A4 = 0;
    D_0028E3A8 = 1;
}

void func_0020ED10(void) {
    D_0028E3A8 = 0;
    D_0028E3A4 = 1;
}

void func_0020ED20(void) {
    reg_d0.w = 0;
    if (reg_d7.sw == 0) {
        reg_d0.w = 1;
    }
}

s32 func_0018DD40();
s32 func_001A35A0();
s32 func_00206520();
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_0020ED40(void) {
    reg_d0.w = 0;
    func_00206520();
    reg_d0.w = 1;
    func_00206520();
    if (D_0028E910 == 0) {
        func_0018DD40();
    }
    (*(s16 *)((u8 *)(reg_a6) + (0x32))) = 0;
    (*(s16 *)((u8 *)(reg_a6) + (0x5A))) = 0;
    (*(s16 *)((u8 *)(reg_a6) + (0x5E))) = 0;
    (*(s16 *)((u8 *)(reg_a6) + (0x60))) = 0;
    (*(s8 *)((u8 *)(reg_a6) + (0))) = 7;
    func_0020ED20();
    func_001A35A0();
    if (reg_d7.h[0] != 0) {
        reg_a0 = (u8 *)(reg_a6 + 0x70);
    } else {
        reg_a0 = (u8 *)(reg_a6 - 0x70);
    }
    if ((D_0028E910 != 0) || ((*(u8 *)((u8 *)(reg_a0) + (1))) == 0)) {
        func_0020ED20();
        reg_d0.h[0] += 1;
        reg_d0.h[0] &= 1;
        func_001A35A0();
    }
}

s32 func_00136010();
s32 func_00136600();
s32 func_0018D190();
s32 func_001A3020();
s32 func_001B04D0();
s32 func_001B07E0();
s32 func_00203850();
s32 func_002039B0();
s32 func_002041C0();
s32 func_002046F0();
s32 func_00204A20();
s32 func_00205D20();
s32 func_00206080();
extern u16 D_002523E0[];
extern u8 D_002610B0[];
extern u16 D_0028DF14_as_u16;
extern u16 D_0028DF18_as_u16;
extern u8 D_0028E27C;
extern u16 D_0028E340;
extern u16 D_0028E344;
extern u16 D_0028E348;
extern u16 D_0028E34C;
extern u8 D_0028E35C;
extern u8 D_0028E360;
extern s32 D_0028E998;
extern s32 D_0028E99C;
extern u8 *reg_a1;
extern u8 *reg_a5;

#define W(o) (*(u16 *)(reg_a6 + (o)))

void func_0020EE20(void) {
    u8 bits;
    u8 *stack_a0;
    s32 keep_9c;
    s32 keep_98;

    func_001B07E0();
    if (reg_d7.h[0] == 0) goto next_2;
    reg_a0 = reg_a6 + 0x70;
    goto next_3;
next_2:
    reg_a0 = reg_a6 - 0x70;
next_3:
    if (D_0028E910 != 0) goto next_5;
    if (reg_a0[1] == 0) goto next_6;
    if (reg_a0[0] != 7) goto block_100;
    if (W(0x5E) != 0) goto next_6;
    W(0x5E) = 1;
next_5:
    func_0020ED20();
    reg_d0.h[0] += 1;
    reg_d0.h[0] &= 1;
    func_001A35A0();
next_6:
    if (D_0028DF14_as_u16 != 0) goto next_7;
    D_0028DF14_as_u16 = 1;
    func_0018D190();
next_7:
    W(0x32) += 1;
    if (!((s32) W(0x36) < 0x3800)) goto next_11;
    W(0x3A) += 9;
    reg_d0.h[0] = W(0x3A);
    W(0x36) += reg_d0.h[0];
next_11:
    if (!((s32) W(0x38) < 0x1C00)) goto next_20;
    W(0x3C) += 4;
    reg_d0.h[0] = W(0x3C);
    W(0x38) += reg_d0.h[0];
next_20:
    if (!((s32) W(0x3E) < 0x7000)) goto next_30;
    W(0x3E) += 0x200;
next_30:
    if (!((s32) W(0x40) < 0x14C0)) goto next_31;
    if (!((s32) W(0x48) < 0x3800)) goto next_31;
    W(0x48) += 0x33;
next_31:
    if ((s32) W(0x48) < 0x300) goto next_40;
    if (!((s32) W(0x46) < 0x7000)) goto next_40;
    W(0x46) += 0x33;
    bits = reg_a5[0xB];
    if (bits & 1) {
        reg_a5[0xB] = bits | 1;
        goto next_40;
    }
    reg_a5[0xB] = bits | 1;
    stack_a0 = reg_a0;
    reg_a0 = (u8 *)D_002610B0;
    reg_d0.w = 0x1A;
    func_001A3020();
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d2.w = 0;
    reg_d3.w = 0;
    reg_d4.w = 0;
    reg_d0.b[0] = reg_a5[9];
    reg_d1.b[0] = reg_a5[5];
    reg_d2.b[0] = reg_a5[8];
    reg_d3.b[0] = reg_a5[4];
    keep_9c = D_0028E99C;
    keep_98 = D_0028E998;
    func_00136600();
    D_0028E99C = keep_9c;
    D_0028E998 = keep_98;
    func_001B04D0();
    reg_a0 = stack_a0;
next_40:
    if (W(0x42) == 0) goto next_41;
    W(0x44) = 0x40;
    W(0x42) -= 1;
    if (W(0x42) != 0) goto next_41;
    W(0x44) = 0;
next_41:
    if (W(0x40) == 0) goto next_50;
    W(0x40) -= 0x26;
    if (W(0x40) == 0) goto next_42;
    if (0 > (s16) W(0x40)) goto next_45;
    goto next_50;
next_45:
next_42:
    if (D_0028E27C == 0) goto next_46;
    if (reg_d7.h[0] == 0) goto next_44;
    D_0028E360 = 1;
    D_0028E344 = 0xA0;
    D_0028E34C = 0x14;
    goto next_46;
next_44:
    D_0028E35C = 1;
    D_0028E340 = 0xA0;
    D_0028E348 = 0x14;
next_46:
    W(0x42) = 3;
    W(0x40) = 0;
next_50:
    if ((s32) W(0x32) < 0xF0) goto next_60;
    reg_a6[0x34] = 1;
    if (!((s32) W(0x4C) < 0x80)) goto next_51;
    if (!((s32) W(0x4A) < 0x1800)) goto next_52;
    W(0x4C) += 1;
    reg_d0.h[0] = W(0x4C);
    W(0x4A) += reg_d0.h[0];
    goto next_60;
next_51:
    if (!((s32) W(0x4A) < 0x1800)) goto next_52;
    reg_d0.h[0] = W(0x4C);
    W(0x4A) += reg_d0.h[0];
    goto next_60;
next_52:
    if (W(0x5A) != 0) goto block_end;
    W(0x54) = 1;
    if (W(0x4C) == 0) goto next_60;
    reg_d0.h[0] = W(0x4C);
    W(0x4A) += reg_d0.h[0];
    W(0x4C) -= 2;
    if (W(0x4C) == 0) goto next_53;
    if (0 > (s16) W(0x4C)) goto next_57;
    goto next_60;
next_57:
next_53:
    W(0x4C) = 0;
    W(0x5A) = 1;
    reg_d0.h[1] = W(0x56);
    reg_d0.h[0] = W(0x58);
    reg_d1.h[1] = *(u16 *)(reg_a0 + 0x56);
    reg_d1.h[0] = *(u16 *)(reg_a0 + 0x58);
    if (reg_d7.h[0] != 0) goto next_54;
    reg_tmp.w = reg_d0.w;
    reg_d0.w = reg_d1.w;
    reg_d1.w = reg_tmp.w;
next_54:
    if (D_0028DF18_as_u16 != 0) goto next_60;
    D_0028DF18_as_u16 = 1;
    func_00136010();
    goto next_60;
block_end:
    reg_a6[0] = 8;
    reg_a0[0] = 8;
next_60:
    if ((s32) W(0x32) < 0xAA) goto next_700;
    W(0x64) = 0;
    if (W(0x62) == 0x2600) goto next_700;
    W(0x62) += 0x80;
    if ((s16) W(0x62) < 0x2600) goto next_700;
    W(0x62) = 0x2600;
next_700:
    if ((s32) W(0x32) <= 0) goto next_80;
    if (W(0x6C) == 0) goto next_75;
    W(0x6C) -= 1;
    if (W(0x6C) != 0) goto next_80;
next_75:
    reg_tmp.b[0] = reg_a6[0x6B];
    reg_a6[0x6B] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_80;
    reg_a6[0x6B] = reg_a6[0x6A];
    if (W(0x60) == 0x3C) goto next_80;
    W(0x60) += 4;
next_80:
    if ((s32) W(0x32) < 0xF0) goto block_100;
    if (!((s32) W(0x4E) < 0x3800)) goto next_61;
    reg_a1 = (u8 *) D_002523E0;
    reg_d1.h[0] = W(0x52);
    W(0x52) += 2;
    reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a1;
    if (reg_d0.h[0] != 0xFFFF) goto next_62;
    W(0x52) -= 2;
    reg_d0.h[0] = ((reg_d1.h[0] - 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d1.h[0] - 2) & ~1)) : *(u16 *)reg_a1;
next_62:
    W(0x4E) += reg_d0.h[0];
next_61:
    if (!((s32) W(0x50) < 0x1C00)) goto block_100;
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 1;
    W(0x50) += reg_d0.h[0];
block_100:
    bits = reg_a5[2];
    if (bits & 1) {
        reg_a5[2] = bits | 1;
        goto next_110;
    }
    reg_a5[2] = bits | 1;
    func_00203850();
    func_002039B0();
next_110:
    func_002041C0();
    bits = reg_a5[2];
    if (bits & 2) {
        reg_a5[2] = bits | 2;
        goto next_120;
    }
    reg_a5[2] = bits | 2;
    func_002046F0();
next_120:
    func_00204A20();
    func_00205D20();
    func_00206080();
}
