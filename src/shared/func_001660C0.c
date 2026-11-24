#include "common.h"

extern s8 D_0028E408;

s32 func_00125EB0();
s32 func_00128930();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_0016D290();
s32 func_00170A60();
s32 func_00170CA0();
s32 func_00170D00();
s32 func_00170D70();
s32 func_00170DE0();
s32 func_0018D4E0();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_002021F0();
s32 func_00202500();
s32 func_00203060();
s32 func_002114C0();
extern u16 D_00259270[];
extern u16 D_00259570[];
extern s16 *D_0028E44C;
extern u16 D_0028E89C;
extern u16 D_0028E8A0;
extern u16 D_0028E8A8;
extern u16 D_0028E8B8;
extern u16 D_0028E8D4;
extern u16 D_0028E91C;
extern u16 D_0029F1F0_as_u16_a[];
extern u16 D_0029F260_as_u16_a[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001660C0(void) {
    u8 *swp;

    func_0014EA50();
    if (enemy_move_end_requested != 0) goto block_rts;
    func_00203060();
    switch (D_0028E408) {
    case 0:
        goto next_1;
    }
    if (reg_a5[0x17] == 0) goto next_2;
    func_0014E290();
    return;
next_1:
    reg_a5[0x17] = 1;
next_2:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= reg_a6[1];
    if (reg_d1.b[0] != 0) goto next_3;
    reg_d0.b[0] = reg_a5[0x19];
    if ((s32) *(u16 *)(reg_a6 + 0x18) >= 0xC0) goto next_5;
    if (D_0028E8B8 != 0) goto next_5;
    reg_d0.w = 0x19;
    goto next_5;
next_3:
    reg_a6[1] &= 0xA3;
    func_001A9000();
    reg_d0.b[0] = reg_a6[0x1C];
    if (reg_d0.b[0] != 0x19) goto next_4;
    reg_d0.b[0] = reg_a5[0x19];
next_4:
    reg_d2.b[0] = reg_a5[0x18];
    reg_d0.b[0] ^= reg_d2.b[0];
    if (*(s16 *)(reg_a6 + 0x18) < 0) goto next_20;
next_5:
    reg_a6[0x1C] = reg_d0.b[0];
    if (*(s8 *)reg_a6 >= 0) goto next_6;
    func_00170A60();
    reg_a0 = reg_a6;
    func_0014D220();
    return;
next_6:
    if (D_0028E8A0 != 0) goto next_21;
    if (D_0028E89C != 0) goto next_21;
    reg_tmp.b[0] = reg_a5[0x1F];
    reg_a5[0x1F] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_21;
    reg_a5[0x1F] = reg_a5[0x1E];
    reg_a0 = (u8 *) D_0029F260_as_u16_a;
    reg_a1 = (u8 *) D_0029F1F0_as_u16_a;
    if (reg_a5[2] == 0) goto next_7;
    D_0028E44C = (s16 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) D_0028E44C;
next_7:
    if (*(s16 *)reg_a0 < 0) goto next_8;
    if (*(s16 *)reg_a1 >= 0) goto next_21;
    swp = reg_a0;
    reg_a0 = reg_a1;
    D_0028E44C = (s16 *) swp;
    reg_a1 = swp;
next_8:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    func_002021F0();
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x20);
    func_00202500();
    *(u16 *)(reg_a5 + 0x20) = reg_d1.h[0];
    reg_a3 = (u8 *) D_00259270;
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    *(u16 *)(reg_a6 + 0xA) = (reg_d1.h[0] != 0) ? *(u16 *)(reg_a3 + ((s16) reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
    *(u16 *)(reg_a6 + 0xC) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a3 + ((s16) (reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
next_21:
    func_00170A60();
    reg_a0 = reg_a6;
    func_0014D220();
    if (D_0028E8A0 != 0) goto block_rts;
    if (D_0028E89C != 0) goto block_rts;
    if (*(s16 *)(reg_a6 + 2) < 0x1000) goto block_rts;
    reg_tmp.b[0] = reg_a5[0x1B];
    reg_a5[0x1B] -= 1;
    switch (reg_tmp.b[0]) {
    case 0:
        goto next_9;
    }
    goto block_rts;
next_9:
    reg_a5[0x1B] = reg_a5[0x16];
    func_0016D290();
    if (D_0028E408 != 0) goto block_rts;
    if (D_0028E91C != 3) goto next_10;
    if (D_0028E8A8 < 0x2E) goto block_rts;
next_10:
    reg_a4 = (u8 *) D_00259570;
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x20);
    reg_d0.h[0] = reg_d1.h[0];
    reg_d0.h[0] &= 0x3E;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a4 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] = ((u16) reg_d0.h[0] + 2 != 0) ? *(u16 *)(reg_a4 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
    reg_d1.h[0] += 2;
    reg_d1.h[0] &= 0x3C;
    reg_d4.w = (u32) reg_a6;
    reg_d0.w = 0xD;
    reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
    func_00128930();
    reg_tmp.b[0] = reg_a5[0x1D];
    reg_a5[0x1D] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_12;
    reg_a5[0x1D] = reg_a5[0x1C];
    reg_d0.h[0] = 0x40;
    reg_d0.h[0] -= D_0028E8D4;
    reg_d0.h[0] += 4;
    reg_a5[0x1B] = reg_d0.b[0];
next_12:
    return;
next_20:
    reg_tmp.b[0] = reg_a6[0];
    reg_a6[0] |= 0x80;
    if (reg_tmp.b[0] & 0x80) goto next_11;
    reg_d0.w = 8;
    func_001A91A0();
    reg_d0.h[0] = 0x84;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = *(u16 *)(reg_a6 + 4);
    func_00170D70();
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(u16 *)(reg_a0 + 0x26) = 0xFE00;
    *(u16 *)(reg_a0 + 0x28) = 0xFE00;
    *(s16 *)(reg_a0 + 0x10) = 1;
    reg_a6[1] &= 0xFD;
    reg_tmp.w = 0x1626;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
    *(u16 *)(reg_a6 + 0x18) = 0x300;
    goto next_21;
next_11:
    func_0018D4E0();
    reg_d0.w = 8;
    func_001A91A0();
    func_00170CA0();
    reg_d0.w = 8;
    func_002114C0();
    reg_d0.w = 8;
    func_00170DE0();
    func_00125EB0();
    reg_d0.w = 0xC;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = *(u16 *)(reg_a6 + 4);
    func_00170D00();
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(u16 *)(reg_a0 + 0x26) = 0xFC00;
    *(u16 *)(reg_a0 + 0x28) = 0xFE00;
    *(s16 *)(reg_a0 + 0x10) = 1;
    func_0014E290();
block_rts:
    return;
}
