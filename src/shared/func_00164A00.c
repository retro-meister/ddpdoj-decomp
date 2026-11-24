#include "common.h"

s32 func_00125EB0();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_00170D00();
s32 func_0018D4E0();
s32 func_001A91A0();
s32 func_00201B80();
extern Reg32 D_0028E484;
extern s8 D_0028E855_as_s8;
extern u16 D_0028E8A8;
extern u16 D_0028E91C;
extern u16 D_0029C068[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00164A00(void) {
    u32 saved;

    if (D_0028E855_as_s8 < 0) goto block_1;
    reg_a0 = reg_a6;
    func_0014D220();
    func_00201B80();
    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
    D_0028E484.w = 0;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x400;
    reg_tmp.h[0] = reg_d0.h[0];
    D_0028E484.h[0] = 0x8C00;
    saved = reg_tmp.w;
    reg_tmp.w = saved + D_0028E484.w;
    reg_d0.h[0] += 0x8C00;
    if (reg_tmp.h[1] != 0) goto next_1;
    reg_d0.h[0] = D_0029C068[0];
    reg_d0.h[0] = (s16) reg_d0.h[0] + 0x800;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[0] += 0x400;
    D_0028E484.w = 0;
    reg_tmp.w = 0;
    D_0028E484.h[0] = 0xC000;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += D_0028E484.w;
    reg_d1.h[0] += reg_d0.h[0];
    reg_d1.h[0] += 0xC000;
    if (reg_tmp.h[1] == 0) goto next_2;
next_1:
    if (*(u8 *)(reg_a5 + 0x17) == 0) goto next_3;
block_1:
    func_0014E290();
    return;
next_2:
    *(u8 *)(reg_a5 + 0x17) = 1;
next_3:
    if (D_0028E91C != 1) goto next_4;
    if ((s16) D_0028E8A8 < 4) goto next_4;
    *(u8 *)(reg_a6 + 1) |= 0x20;
next_4:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *)(reg_a6 + 1);
    if (reg_d1.b[0] == 0) goto next_5;
    *(u8 *)(reg_a6 + 1) &= 0xA3;
    if (*(s16 *)(reg_a6 + 0x18) < 0) goto block_2;
next_5:
    return;
block_2:
    reg_d0.w = 1;
    func_001A91A0();
    func_0018D4E0();
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0x1E);
    func_00125EB0();
    reg_d0.w = 1;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = *(u16 *)(reg_a6 + 4);
    func_00170D00();
    reg_d0.h[0] = 1;
    *(u16 *)(reg_a0 + 0x10) = reg_d0.h[0];
    func_0014E290();
}
