#include "common.h"

void func_001713F0(s32);

void func_001A4FA0(void) {
    func_001713F0(0);
}

s32 func_0014E370();
extern u8 D_0025F690[];
extern s8 *reg_a0_as_s8_p;

void func_001A4FB0(void) {
    s8 temp_a1;
    s8 temp_a3;
    u32 temp_a2;

    reg_a0_as_s8_p = (s8 *)D_0025F690;
    func_0014E370();
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x12);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x14);
    reg_a0_as_s8_p = (s8 *) reg_tmp.w;
    reg_tmp.b[1] = *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    reg_tmp.b[0] = (u8) *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    *(u16 *)(reg_a6 + 2) = (u16) reg_tmp.h[0];
    reg_tmp.b[1] = *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    reg_tmp.b[0] = (u8) *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    *(u16 *)(reg_a6 + 4) = (u16) reg_tmp.h[0];
    reg_d0.h[0] = 0xFF;
    temp_a2 = reg_d0.h[0];
    reg_d1.h[0] = temp_a2;
    reg_d2.h[0] = temp_a2;
    temp_a1 = *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    reg_tmp.b[1] = temp_a1;
    reg_tmp.b[0] = (u8) *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    reg_d0.h[0] = temp_a2 & reg_tmp.h[0];
    if (reg_d0.h[0] == 2) {
        *(s16 *)(reg_a6 + 8) = 1;
        reg_d0.h[0] = 0xFF;
        reg_tmp.b[1] = *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        reg_tmp.b[0] = (u8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        reg_d0.h[0] = temp_a2 & reg_tmp.h[0];
    }
    reg_tmp.b[1] = *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    reg_tmp.b[0] = (u8) *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    reg_d1.h[0] &= reg_tmp.h[0];
    temp_a3 = *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    reg_tmp.b[1] = temp_a3;
    reg_tmp.b[0] = (u8) *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    reg_d2.h[0] &= reg_tmp.h[0];
    *(u16 *)(reg_a5 + 0x16) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a5 + 0x18) = (u16) reg_d1.h[0];
    *(u16 *)(reg_a5 + 0x1A) = (u16) reg_d2.h[0];
    reg_tmp.w = (u32) reg_a0_as_s8_p;
    *(u16 *)(reg_a5 + 0x12) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x14) = (u16) reg_tmp.h[0];
}

s32 func_0014E050();
s32 func_0014E290();
s32 func_00201B80();
extern u16 D_0028E8A0;
extern u16 D_0029C068[];

void func_001A51B0(void) {
    if (*(u16 *)(reg_a6 + 8) != 0) goto next_0;
    func_00201B80();
next_0:
    reg_d0.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 4);
    reg_tmp1.w = 0;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x1C00;
    reg_d0.h[0] += D_0029C068[0];
    reg_tmp1.h[0] = 0x9000;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x9000;
    if (reg_tmp.h[1] != 0) goto next_1;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_d0.h[0];
    reg_tmp1.w = (s16)reg_d1.h[0];
    reg_d1.w = reg_tmp1.w;
    reg_d1.w += 0x4000;
    if ((s32)reg_d1.w <= 0x3800) goto next_1;
    if ((s32)reg_d1.w < 0xB800) goto next_3;
next_1:
    if (*(u16 *)(reg_a6 + 6) == 0) goto next_4;
next_2:
    func_0014E290();
    return;
next_3:
    *(u16 *)(reg_a6 + 6) = 1;
next_4:
    if (D_0028E8A0 != 0) return;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
    *(u8 *)(reg_a5 + 0x1B) -= 1;
    if ((s32)reg_tmp.b[0] > 0) return;
    *(u8 *)(reg_a5 + 0x1B) = *(u8 *)(reg_a5 + 0x1A);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x16);
    reg_d1.w = 0;
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0xC);
    func_0014E050();
    *(u16 *)(reg_a0 + 0x12) = *(u16 *)(reg_a5 + 0x12);
    *(u16 *)(reg_a0 + 0x14) = *(u16 *)(reg_a5 + 0x14);
    *(u16 *)(reg_a0 + 0x48) = *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 0x4A) = *(u16 *)(reg_a6 + 4);
    *(u8 *)(reg_a0 + 3) |= 0x40;
    if (*(u16 *)(reg_a5 + 0x18) == 0) return;
    *(u8 *)(reg_a5 + 0x18) -= 1;
    if (*(u8 *)(reg_a5 + 0x18) == 0) goto next_2;
}
