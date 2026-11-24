#include "common.h"

typedef void (*Fn)();

extern u8 D_002635C0[];
extern u8 D_002BDAA8[];
s32 func_0014D220();
s32 func_0014E290();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_001D5150();
s32 func_001D51C0();
s32 func_001D5230();
s32 func_001D55B0();
s32 func_001D61B0();
s32 func_001D66E0();
s32 func_001D6990();
s32 func_001D6A40();
s32 func_001D6B60();
s32 func_00201800();
s32 vibration_start_pad1();
s32 vibration_start_pad2();
extern u16 D_0028E884;
extern u16 D_0028E8A0;
extern u16 D_0029C06C[];
extern u16 D_002BDAA4[];
extern u16 D_002BDAA6[];
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001D4930(void) {
    u32 saved;
    u32 saved_d1;
    u8 *p;

    if (D_0028E8A0 != 0) goto next_1;
    reg_d7.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d7.h[0] = *(u16 *)(reg_a6 + 4);
    saved = reg_d7.w;
    reg_a0 = (u8 *)D_002635C0;
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
    reg_d0.h[0] *= 4;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)(reg_a0 + 0);
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    jtbl_0028E3F4 = (Fn)(reg_a0);
    jtbl_0028E3F4();
    reg_d7.w = saved;
    if (*(u8 *)(reg_a5 + 0x25) != 0) goto next_3;
    if (*(u16 *)(reg_a5 + 0x2E) == 0) goto next_3;
    if (*(u8 *)(reg_a5 + 0x1E) != 0) goto next_2;
    if ((s16) *(u16 *)(reg_a5 + 0x2E) <= 0x258) goto block_1;
next_2:
    *(u16 *)(reg_a5 + 0x2E) -= 1;
    if (*(u16 *)(reg_a5 + 0x2E) != 0) goto next_3;
    func_001D55B0();
next_3:
    func_001D61B0();
    func_001D66E0();
    func_001D5230();
    if (*(u16 *)(reg_a5 + 0x30) == 0) goto next_1;
    func_0014E290();
    return;
next_1:
    reg_d0.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 4);
    reg_a0 = (u8 *)D_002BDAA8;
    p = (u8 *) D_002BDAA4;
    reg_a1 = p;
    reg_d1.w = 8;
loop_1:
    reg_a1 -= 4;
    reg_d2.h[1] = *(u16 *)(reg_a1 + 0);
    reg_d2.h[0] = *(u16 *)(reg_a1 + 2);
    reg_d2.h[0] -= D_0029C06C[0];
    reg_a0 -= 4;
    *(u16 *)(reg_a0 + 0) = reg_d2.h[1];
    *(u16 *)(reg_a0 + 2) = reg_d2.h[0];
    if ((s16) --reg_d1.h[0] >= 0) goto loop_1;
    reg_d0.h[0] -= D_0029C06C[0];
    *(u16 *)(reg_a1 + 0) = reg_d0.h[1];
    *(u16 *)(reg_a1 + 2) = reg_d0.h[0];
    reg_d0.h[1] = *(u16 *)p;
    reg_d0.h[0] = D_002BDAA6[0];
    *(u16 *)(reg_a6 + 0x22) = reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x24) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x24) -= 0x1000;
    *(u16 *)(reg_a6 + 0x42) = reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x44) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x44) += 0x1000;
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *)(reg_a6 + 1);
    if (reg_d1.b[0] == 0) goto next_6;
    reg_d0.b[0] = 0xA3;
    *(u8 *)(reg_a6 + 1) &= reg_d0.b[0];
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0x1E);
    reg_d0.b[0] ^= reg_d2.b[0];
    *(u8 *)(reg_a6 + 0x1C) = reg_d0.b[0];
    reg_d0.w = 0x7FFF;
    reg_d0.h[0] -= *(u16 *)(reg_a6 + 0x18);
    if (*(u16 *)(reg_a5 + 0x2E) == 0) goto next_4;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x20);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x22);
    reg_tmp.w -= reg_d0.w;
    *(u16 *)(reg_a5 + 0x20) = reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x22) = reg_tmp.h[0];
next_4:
    *(u16 *)(reg_a6 + 0x18) = 0x7FFF;
    if (*(u8 *)(reg_a5 + 0x1E) != 0) goto next_5;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x20);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x22);
    if ((s32) reg_tmp.w > 0x2800) goto next_5;
block_1:
    func_001D5150();
    func_001D51C0();
    *(u8 *)(reg_a5 + 0x1E) = 1;
    goto next_7;
next_5:
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x20);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x22);
    if ((s32) reg_tmp.w >= 0) goto next_7;
    saved_d1 = reg_d1.w;
    reg_d0.w = 0x712;
    func_001A91A0();
    vibration_start_pad1(0xB4, 0x78);
    vibration_start_pad2(0xB4, 0x78);
    reg_d1.w = saved_d1;
    func_00201800();
    *(u16 *)(reg_a6 + 0) = 0x8000;
    *(u8 *)(reg_a5 + 0x25) = 1;
    D_0028E884 = 0;
next_6:
    *(u8 *)(reg_a6 + 0x1C) = *(u8 *)(reg_a6 + 0x1F);
next_7:
    if (*(u8 *)(reg_a5 + 0x1F) != 0) goto next_8;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x20);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x22);
    if ((s32) reg_tmp.w > 0x1000) goto next_8;
    *(u8 *)(reg_a5 + 0x1F) = 1;
next_8:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *)(reg_a6 + 0x21);
    if (reg_d1.b[0] == 0) goto next_10;
    reg_d0.b[0] = 0xA3;
    *(u8 *)(reg_a6 + 0x21) &= reg_d0.b[0];
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3B);
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0x3C);
    reg_d0.b[0] ^= reg_d2.b[0];
    *(u8 *)(reg_a6 + 0x3B) = reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3A);
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0x3E);
    reg_d0.b[0] ^= reg_d2.b[0];
    *(u8 *)(reg_a6 + 0x3A) = reg_d0.b[0];
    if (*(u16 *)(reg_a5 + 0x2E) != 0) goto next_9;
    *(u16 *)(reg_a6 + 0x38) = 0x4000;
next_9:
    if (*(s16 *)(reg_a6 + 0x38) >= 0) goto next_11;
    reg_d0.w = 0x173;
    func_001A91A0();
    func_001D5150();
next_10:
    *(u8 *)(reg_a6 + 0x3B) = *(u8 *)(reg_a6 + 0x3D);
    *(u8 *)(reg_a6 + 0x3A) = *(u8 *)(reg_a6 + 0x3F);
next_11:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *)(reg_a6 + 0x41);
    if (reg_d1.b[0] == 0) goto next_13;
    reg_d0.b[0] = 0xA3;
    *(u8 *)(reg_a6 + 0x41) &= reg_d0.b[0];
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x5B);
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0x5C);
    reg_d0.b[0] ^= reg_d2.b[0];
    *(u8 *)(reg_a6 + 0x5B) = reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x5A);
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0x5E);
    reg_d0.b[0] ^= reg_d2.b[0];
    *(u8 *)(reg_a6 + 0x5A) = reg_d0.b[0];
    if (*(u16 *)(reg_a5 + 0x2E) != 0) goto next_12;
    *(u16 *)(reg_a6 + 0x58) = 0x4000;
next_12:
    if (*(s16 *)(reg_a6 + 0x58) >= 0) goto next_14;
    reg_d0.w = 0x173;
    func_001A91A0();
    func_001D51C0();
next_13:
    *(u8 *)(reg_a6 + 0x5B) = *(u8 *)(reg_a6 + 0x5D);
    *(u8 *)(reg_a6 + 0x5A) = *(u8 *)(reg_a6 + 0x5F);
next_14:
    *(u16 *)(reg_a5 + 0x32) += 4;
    *(u16 *)(reg_a5 + 0x32) &= 0x1F;
    if (*(u16 *)(reg_a5 + 0x2C) == 0) return;
    reg_a0 = reg_a6;
    func_0014D220();
    reg_a0 = reg_a6 + 0x20;
    func_0014D220();
    reg_a0 = reg_a6 + 0x40;
    func_0014D220();
    reg_a0 = reg_a6 + 0x60;
    func_0014D220();
    func_001D6990();
    func_001D6A40();
    func_001D6B60();
}
