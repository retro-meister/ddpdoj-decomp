#include "common.h"

typedef void (*Fn)();

extern u8 D_0025B490[];
extern u8 D_0025B510[];
extern u8 D_0025B610[];
extern s8 D_0028E408;

s32 func_00128970();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0014EA50();
s32 func_0016D040();
s32 func_0018D4E0();
s32 func_0019C4B0();
s32 func_001A9000();
s32 func_001A9130();
s32 func_001A91A0();
s32 func_00202140();
s32 func_00202500();
s32 func_002031E0();
s32 func_002114C0();
extern u16 D_0028E3EC;
extern u16 D_0028E3F0;
extern u16 D_0028E8A0;
extern u16 D_0028E8EC;
extern s8 enemy_move_end_requested;
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0015B210(void) {
    func_0014EA50();
    if (enemy_move_end_requested != 0) return;
    func_002031E0();
    switch (D_0028E408) { case 0: goto skip_1; }
    if (*(u16 *)(reg_a5 + 0x16) == 0) goto block_touch;
    func_0014E290();
    return;
skip_1:
    *(u16 *)(reg_a5 + 0x16) = 1;
block_touch:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *)(reg_a6 + 1);
    if (reg_d1.b[0] == 0) goto block_pal;
    *(u8 *)(reg_a6 + 1) &= 0xA3;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x34);
    *(u8 *)(reg_a6 + 0x1C) ^= reg_d0.b[0];
    func_001A9000();
    if (*(s16 *)(reg_a6 + 0x18) >= 0) goto block_body;
    if (*(s8 *)(reg_a5 + 0x21) < 0) goto block_dead;
    *(u16 *)(reg_a6 + 0x18) = *(u16 *)(reg_a5 + 0x26);
    reg_d0.w = 8;
    func_001A9130();
    *(u8 *)(reg_a5 + 0x21) |= 0x80;
    reg_d0.w = 3;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = *(u16 *)(reg_a6 + 4);
    *(u16 *)(reg_a0 + 0x1E) = 8;
    *(u16 *)(reg_a0 + 0x10) = 2;
    *(u16 *)(reg_a0 + 0x26) = 0xFE00;
    goto block_body;
block_pal:
    *(u8 *)(reg_a6 + 0x1C) = *(u8 *)(reg_a5 + 0x35);
block_body:
    if (D_0028E8A0 != 0) goto block_obj;
    reg_d7.h[0] = *(u16 *)(reg_a6 + 0x1A);
    reg_d1.w = 0x3E;
    reg_d1.h[0] &= reg_d7.h[0];
    reg_d1.h[0] *= 4;
    if (reg_d7.h[0] & 0x40) goto skip_2;
    if (!(D_0028E3F0 & 4)) goto skip_2;
    reg_d1.h[0] += 4;
skip_2:
    reg_a0 = (u8 *)D_0025B510;
    *(u16 *)(reg_a6 + 0xA) = (reg_d1.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0xC) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
block_obj:
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x2A);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x2C);
    reg_a0 = (u8 *)reg_tmp.w;
    jtbl_0028E3F4 = (Fn)reg_a0;
    jtbl_0028E3F4();
    reg_a0 = reg_a6;
    func_0014D220();
    if (*(s8 *)(reg_a5 + 0x21) >= 0) goto block_turret;
    if (D_0028E3EC == 0) return;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d2.w = 0;
    reg_d1.w += 0x0100FE00;
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x1E);
    reg_d2.h[0] += 1;
    if (reg_d2.h[0] != 4) goto skip_3;
    reg_d2.w = 0;
skip_3:
    *(u16 *)(reg_a5 + 0x1E) = reg_d2.h[0];
    reg_d3.h[0] = 0x410;
    reg_d4.h[0] = 0x1E;
    reg_d2.w += 0x13D8;
    func_0019C4B0();
    return;
block_turret:
    if (D_0028E8A0 != 0) goto block_turret_obj;
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x32);
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x19);
    *(u8 *)(reg_a5 + 0x19) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto block_shotint;
    *(u8 *)(reg_a5 + 0x19) = *(u8 *)(reg_a5 + 0x18);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d0.h[0] += 0x200;
    func_00202140();
    if (D_0028E408 != 0) goto block_turret_obj;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x32);
    func_00202500();
    *(u8 *)(reg_a5 + 0x32) = reg_d1.b[0];
    reg_a0 = (u8 *)D_0025B610;
    reg_d1.b[0] += 1;
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    *(u16 *)(reg_a5 + 0x22) = (reg_d1.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0x24) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
block_shotint:
    *(u8 *)(reg_a5 + 0x29) -= 1;
    if (*(u8 *)(reg_a5 + 0x29) == 0) goto block_shot;
block_turret_obj:
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.w += 0xFC00FC00;
    reg_d2.h[1] = *(u16 *)(reg_a5 + 0x22);
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x24);
    reg_d3.h[0] = 0x620;
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x2E);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x30);
    reg_a0 = (u8 *)reg_tmp.w;
    jtbl_0028E3F4 = (Fn)reg_a0;
    jtbl_0028E3F4();
    return;
block_shot:
    reg_d0.h[0] = 0xA0;
    reg_d0.h[0] -= D_0028E8EC;
    reg_d0.h[0] += 4;
    *(u8 *)(reg_a5 + 0x29) = reg_d0.b[0];
    func_0016D040();
    if (D_0028E408 != 0) goto block_turret_obj;
    if (!(*(u8 *)(reg_a6 + 1) & 0x20)) goto block_turret_obj;
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x32);
    reg_a0 = (u8 *)D_0025B490;
    reg_d1.b[0] += 2;
    reg_d1.h[0] &= 0x3C;
    reg_d2.h[0] = reg_d1.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 2);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d2.w += reg_tmp.w;
    reg_d0.w = 0xD;
    reg_d3.w = 0x02000000;
    func_00128970();
    goto block_turret_obj;
block_dead:
    reg_d0.w = 0x10;
    func_001A91A0();
    reg_d0.w = 7;
    func_0013A780();
    *(u16 *)(reg_a0 + 2) = *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = *(u16 *)(reg_a6 + 4);
    *(u16 *)(reg_a0 + 0x1E) = 8;
    *(u16 *)(reg_a0 + 0x10) = 2;
    *(u16 *)(reg_a0 + 0x26) = 0xFE00;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0;
    reg_d0.w = 4;
    reg_d1.h[0] = 4;
    func_002114C0();
    func_0018D4E0();
    func_0014E290();
}
