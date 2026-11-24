#include "common.h"

s32 func_00125EB0();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_00170A60();
s32 func_00170D00();
s32 func_0018D4E0();
s32 func_001A91A0();
s32 func_00201B80();
s32 func_00203380();
extern Reg32 D_0028E484;
extern s8 D_0028E855;
extern u16 D_0029C068[];
extern u16 D_0029CEA0[];
extern u16 D_0029F1F4[];
extern u16 D_0029F264[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00164600(void) {
    u32 saved;
    u8 t;

    if (D_0028E855 < 0) goto block_1;
    reg_a0 = reg_a6;
    func_0014D220();
    func_00201B80();
    reg_d0.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d0.h[0] += 0xC00;
    reg_d0.h[0] += D_0029C068[0];
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    saved = reg_tmp.w;
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0xB000;
    reg_tmp.w = saved + D_0028E484.w;
    reg_d0.h[0] += 0xB000;
    if (reg_tmp.h[1] != 0) goto next_1;
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0x8C00;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    saved = reg_tmp.h[0];
    reg_d0.h[0] += 0x400;
    reg_tmp.w = 0;
    reg_d0.h[1] = saved;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += D_0028E484.w;
    reg_d0.h[0] += 0x8C00;
    if (reg_tmp.h[1] == 0) goto next_2;
next_1:
    switch (*(u8 *)(reg_a5 + 0x17)) {
    case 0:
        goto next_3;
    }
block_1:
    func_0014E290();
    return;
next_2:
    *(u8 *)(reg_a5 + 0x17) = 1;
next_3:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *)(reg_a6 + 1);
    if (reg_d1.b[0] == 0) goto next_4;
    *(u8 *)(reg_a6 + 1) &= 0xA3;
    if (*(s16 *)(reg_a6 + 0x18) < 0) goto block_3;
next_4:
    if (D_0029CEA0[0] != 0) goto next_9;
    func_00203380();
    if (reg_d0.h[0] == 0) goto block_rts;
    if (!(reg_d0.h[0] & 1)) goto next_6;
    reg_d2.h[0] = D_0029F264[0];
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[0] -= reg_d2.h[0];
    if ((s16) reg_d1.h[0] >= 0) goto next_5;
    reg_d1.h[0] *= 0xFFFF;
next_5:
    if ((s32) reg_d1.h[0] < 0x240) goto next_8;
    if (!(reg_d0.h[0] & 2)) goto block_rts;
next_6:
    reg_d2.h[0] = D_0029F1F4[0];
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[0] -= reg_d2.h[0];
    if ((s16) reg_d1.h[0] >= 0) goto next_7;
    reg_d1.h[0] *= 0xFFFF;
next_7:
    if ((s32) reg_d1.h[0] > 0x23F) goto block_rts;
next_8:
    *(u16 *)(reg_a5 + 0x18) = 0xF;
next_9:
    *(u16 *)(reg_a5 + 0x18) -= 1;
    t = *(u8 *)(reg_a6 + 0);
    if (!(t & 0x40)) goto next_10;
    *(u8 *)(reg_a6 + 0) = t & 0xBF;
    goto block_2;
next_10:
    *(u8 *)(reg_a6 + 0) = t | 0x40;
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0xA);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xC);
    reg_tmp.w ^= 3;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
    func_00170A60();
block_2:
    return;
block_3:
    reg_d0.w = 1;
    func_001A91A0();
    func_0018D4E0();
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1A);
    reg_d2.b[0] = *(u8 *)(reg_a6 + 0x1E);
    func_00125EB0();
    reg_d0.w = 0xC;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = *(u16 *)(reg_a6 + 4);
    func_00170D00();
    reg_d0.h[0] = 1;
    *(u16 *)(reg_a0 + 0x10) = reg_d0.h[0];
    func_0014E290();
block_rts:
    return;
}
