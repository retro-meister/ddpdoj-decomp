#include "common.h"

s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0018D500();
s32 func_0019BF40();
s32 func_0019D620();
s32 func_001A9000();
s32 func_001A91A0();
extern u8 D_00263A50[];
extern u8 D_0028E2E4;
extern Reg32 D_0028E484;
extern u16 D_0028E894;
extern u16 D_0028E8B8;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001E0DF0(void) {
    if (D_0028E2E4 != 0) {
        goto block_7a;
    }
    if (D_0028E894 == 0) {
        goto block_11;
    }
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *)(reg_a6 + 1);
    if (reg_d1.b[0] != 0) {
        goto block_1;
    }
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x19);
    if (*(u16 *)(reg_a6 + 0x18) >= 0x100) {
        goto block_3;
    }
    if (D_0028E8B8 != 0) {
        goto block_3;
    }
    reg_d0.w = 0x19;
    goto block_3;
block_1:
    *(u8 *)(reg_a6 + 1) &= 0xA3;
    func_001A9000();
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1C);
    if (reg_d0.b[0] != 0x19) {
        goto block_2;
    }
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x19);
block_2:
    reg_d2.b[0] = *(u8 *)(reg_a5 + 0x18);
    reg_d0.b[0] ^= reg_d2.b[0];
    if (*(s16 *)(reg_a6 + 0x18) < 0) {
        goto block_10;
    }
block_3:
    *(u8 *)(reg_a6 + 0x1C) = reg_d0.b[0];
    reg_tmp.b[0] = *(u8 *)reg_a6;
    *(u8 *)reg_a6 |= 0x20;
    if (!(reg_tmp.b[0] & 0x20)) {
        goto block_8;
    }
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1A);
    *(u16 *)(reg_a6 + 2) += reg_d0.h[0];
    if (*(u16 *)(reg_a5 + 0x24) != 0) {
        goto block_4;
    }
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1A);
    *(u16 *)(reg_a5 + 0x1E) += reg_d0.h[0];
    if (*(u16 *)(reg_a5 + 0x1E) < 0x1600) {
        goto block_6;
    }
    *(u16 *)(reg_a5 + 0x24) = 1;
block_4:
    if ((s16)*(u16 *)(reg_a5 + 0x1A) <= -0x200) {
        goto block_4b;
    }
    *(u16 *)(reg_a5 + 0x1A) -= 0x80;
block_4b:
    reg_a0 = (u8 *)D_00263A50;
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x22);
    *(u16 *)(reg_a6 + 0xA) = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0xC) = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x22);
    *(u16 *)(reg_a5 + 0x22) -= 4;
    if ((s32)reg_tmp.h[0] >= 4) {
        goto block_5;
    }
    *(u16 *)(reg_a5 + 0x22) = 0x7C;
block_5:
    if (*(u16 *)(reg_a5 + 0x24) != 1) {
        goto block_5b;
    }
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1A);
    *(u16 *)(reg_a5 + 0x1E) += reg_d0.h[0];
    if (*(u16 *)(reg_a5 + 0x1E) < 0x3000) {
        goto block_6;
    }
    *(u16 *)(reg_a5 + 0x24) = 2;
block_5b:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
    *(u8 *)(reg_a5 + 0x21) -= 1;
    if ((s32)reg_tmp.b[0] > 0) {
        goto block_6;
    }
    *(u8 *)(reg_a5 + 0x21) = *(u8 *)(reg_a5 + 0x20);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1C);
    *(u16 *)(reg_a6 + 4) -= reg_d0.h[0];
block_6:
    if (*(s16 *)(reg_a5 + 0x1A) > -0x200) {
        goto block_8;
    }
    reg_d0.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 4);
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0xB400;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0xA00;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += D_0028E484.w;
    reg_d0.h[0] += 0xB400;
    if (reg_tmp.h[1] != 0) {
        goto block_7;
    }
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] += 0xE00;
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0x7400;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += D_0028E484.sw;
    reg_d0.h[0] += 0x7400;
    if (reg_tmp.h[1] == 0) {
        goto block_7b;
    }
block_7:
    if (*(u8 *)(reg_a5 + 0x17) == 0) {
        goto block_8;
    }
block_7a:
    func_0014E290();
    return;
block_7b:
    *(u8 *)(reg_a5 + 0x17) = 1;
block_8:
    reg_a0 = reg_a6;
    func_0014D220();
    *(u8 *)reg_a6 |= 1;
    if (*(s16 *)(reg_a6 + 2) >= 0) {
        goto block_9;
    }
    *(u8 *)reg_a6 &= 0xFE;
    return;
block_9:
    if (*(s16 *)(reg_a5 + 0x1A) < 0) {
        goto block_9b;
    }
    func_0019BF40();
    return;
block_9b:
    func_0019D620();
    return;
block_10:
    reg_d0.w = 0;
    func_001A91A0();
block_11:
    reg_d0.h[0] = 0x85;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = *(u16 *)(reg_a6 + 4);
    *(s16 *)(reg_a0 + 0x1E) = 0xC;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(s16 *)(reg_a0 + 0x26) = 0;
    *(s16 *)(reg_a0 + 0x28) = 0;
    func_0018D500();
    func_0014E290();
}
