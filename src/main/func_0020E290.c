#include "common.h"

s32 func_0020E6F0();
extern u16 D_0028E098;
extern u16 D_0028E0A8;
extern Reg32 D_0028E478;
extern u16 D_0028E5A8;
extern u16 D_0028E5AC;
extern u16 D_0028E928;
extern u16 D_00299764[];
extern u8 D_002BC7C0[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;

void func_0020E290(void) {
    *(u8 *) (reg_a1 + 1) &= 0xEF;
    *(u16 *) (reg_a1 + 0x10) = 0x7400;
    *(u16 *) (reg_a1 + 0x10) += reg_d6.h[0];
    reg_a0 = reg_a1 + 2;
    reg_d0.h[0] = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_d2.h[0] = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_d0.h[0] += reg_d6.h[0];
    reg_d1.h[0] = reg_d0.h[0];
    reg_d0.h[0] += 0x400;
    reg_d0.h[0] += *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_d2.h[0] += reg_d6.h[0];
    reg_d3.h[0] = reg_d2.h[0];
    reg_d2.h[0] += *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_d3.h[0] -= *(u16 *) reg_a0;
    reg_a0 += 2;
    if (D_0028E5AC == 0) goto next_30;
    if (D_00299764[0] != 0) goto next_30;
    reg_d5.h[0] = *(u16 *) (reg_a1 + 0x1C);
    reg_d4.h[0] = reg_d5.h[0];
    reg_d4.h[0] >>= 2;
    reg_d7.h[0] = D_0028E5A8;
    reg_d7.h[0] -= 1;
loop_20:
    reg_d5.h[0] += reg_d4.h[0];
    if ((s16) --reg_d7.h[0] >= 0) goto loop_20;
    *(u16 *) (reg_a1 + 0xE) = reg_d5.h[0];
next_30:
    reg_a5 = (u8 *)D_002BC7C0;
    reg_d7.h[0] = 0x63;
    goto loop_10;
skip_2:
    reg_a5 += 0x20;
    if ((s16) --reg_d7.h[0] < 0) goto next_70;
loop_10:
    reg_d4.b[0] = *(u8 *) (reg_a5 + 1);
    if ((s8) reg_d4.b[0] >= 0) goto skip_2;
    reg_d4.h[1] = *(u16 *) (reg_a5 + 2);
    reg_d4.h[0] = *(u16 *) (reg_a5 + 4);
    reg_d4.h[0] += reg_d6.h[0];
    reg_d5.h[0] = reg_d4.h[0];
    reg_d4.h[0] += *(u16 *) (reg_a5 + 0x14);
    if ((s32) reg_d3.h[0] > (s32) reg_d4.h[0]) goto skip_2;
    reg_d5.h[0] -= *(u16 *) (reg_a5 + 0x16);
    if ((s32) reg_d5.h[0] > (s32) reg_d2.h[0]) goto skip_2;
    D_0028E478.h[0] = reg_d4.h[0];
    reg_d4.h[0] = reg_d4.h[1];
    reg_d4.h[1] = D_0028E478.h[0];
    reg_d4.h[0] += reg_d6.h[0];
    reg_d5.h[0] = reg_d4.h[0];
    reg_d4.h[0] -= *(u16 *) (reg_a5 + 0x12);
    if ((s32) reg_d4.h[0] > (s32) reg_d0.h[0]) goto skip_2;
    reg_d5.h[0] += *(u16 *) (reg_a5 + 0x10);
    if ((s32) reg_d1.h[0] > (s32) reg_d5.h[0]) goto skip_2;
    if (reg_d4.h[0] >= 0x9800) goto skip_2;
    D_0028E478.h[0] = reg_d4.h[0];
    reg_d4.h[0] = reg_d4.h[1];
    reg_d4.h[1] = D_0028E478.h[0];
    if (!(*(u8 *) (reg_a5 + 1) & 0x20)) goto skip_2;
    if (*(s16 *) (reg_a5 + 0x18) < 0) goto next_60;
    reg_d5.h[0] = *(u16 *) (reg_a1 + 0xE);
    if (D_0028E5AC == 0) goto next_13;
    if (D_00299764[0] != 0) goto next_20;
next_13:
    if (*(u16 *) (reg_a1 + 0x1A) == 0) goto next_20;
    if (!(*(u8 *) (reg_a5 + 1) & 2)) goto next_20;
    reg_d5.h[0] += reg_d5.h[0];
    goto next_40;
next_20:
    D_0028E478.h[0] = reg_d4.h[0];
    reg_d4.h[0] = reg_d4.h[1];
    reg_d4.h[1] = D_0028E478.h[0];
    if (!((s32) *(u16 *) (reg_a1 + 0x10) > (s32) reg_d4.h[0])) goto next_60;
    *(u16 *) (reg_a1 + 0) |= 0x1001;
    *(u16 *) (reg_a1 + 0xC) = 0;
    if (!((s32) reg_d1.h[0] > (s32) reg_d4.h[0])) goto next_35;
    reg_d4.h[0] = reg_d1.h[0];
    reg_d4.h[0] += 0x400;
next_35:
    *(u16 *) (reg_a1 + 0x10) = reg_d4.h[0];
    reg_d0.h[0] = reg_d4.h[0];
next_40:
    if (D_0028E098 != 0) goto next_60;
    if (D_0028E928 != 0) goto next_50;
    reg_d4.h[0] = reg_d5.h[0];
    reg_d4.h[0] >>= 2;
    reg_d5.h[0] -= reg_d4.h[0];
next_50:
    reg_d4.h[0] = D_0028E0A8;
    reg_d4.h[0] |= 0x400;
    *(u16 *) (reg_a5 + 0) |= reg_d4.h[0];
    if (*(u16 *) (reg_a5 + 2) >= 0x6F00) goto next_60;
    *(u16 *) (reg_a5 + 0x18) -= reg_d5.h[0];
next_60:
    reg_a5 += 0x20;
    if ((s16) --reg_d7.h[0] >= 0) goto loop_10;
next_70:
    func_0020E6F0();
}
