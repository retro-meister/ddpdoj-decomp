#include "common.h"

typedef void (*Fn)();

s32 func_00139ED0();
s32 func_001B82F0();
s32 func_00201B80();
s32 func_00201E20();
extern u16 D_0024F570[];
extern u16 D_0024F680[];
extern u8 D_00250760[];
extern u16 D_0028E3F0;
extern Reg32 D_0028E484;
extern u8 D_0029AA40[];
extern u16 D_0029BBF8[];
extern u16 D_0029C06C[];
extern u8 D_0029CEA0_as_u8_a[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a6;

void func_0013A020(void) {
    u16 x_save;
    u16 hi_save;

    D_0029BBF8[0] = 0;
    reg_d7.h[0] = 0x4F;
    reg_a6 = (u8 *)D_0029AA40;
loop_1:
    if (*(u16 *)(reg_a6 + 0) == 0) goto next_1;
    if (*(u16 *)(reg_a6 + 0x18) == 0) goto block_main;
    *(u16 *)(reg_a6 + 0x18) -= 1;
    goto next_1;
block_main:
    D_0029BBF8[0] += 1;
    if (!(*(u8 *)(reg_a6 + 1) & 0x40)) goto block_first;
    *(u8 *)(reg_a6 + 1) |= 0x40;
    goto block_fire;
block_first:
    *(u8 *)(reg_a6 + 1) |= 0x40;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0);
    reg_a1 = (u8 *)D_0024F570;
    reg_d1.h[0] = reg_d1.b[0];
    reg_tmp.w = reg_d1.w;
    if (!(reg_tmp.w & 0x80)) goto skip_1;
    reg_d1.w &= ~0x80;
    reg_a1 = (u8 *)D_0024F680;
skip_1:
    reg_d1.h[0] *= 8;
    reg_tmp.h[1] = ((reg_d1.h[0] + 4) != 0) ? *(u16 *)(reg_a1 + ((s16)(reg_d1.h[0] + 4) & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[0] = ((reg_d1.h[0] + 6) != 0) ? *(u16 *)(reg_a1 + ((s16)(reg_d1.h[0] + 6) & ~1)) : *(u16 *)reg_a1;
    reg_a2 = (u8 *)reg_tmp.w;
    *(u16 *)(reg_a6 + 0x32) = *(u16 *)reg_a2;
    reg_a2 += 2;
    *(u16 *)(reg_a6 + 0x32) += 1;
    reg_tmp.w = (u32)reg_a2;
    *(u16 *)(reg_a6 + 0x2E) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x30) = reg_tmp.h[0];
    *(u16 *)(reg_a6 + 0x2A) = (reg_d1.h[0] != 0) ? *(u16 *)(reg_a1 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a1;
    *(u16 *)(reg_a6 + 0x2C) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a1 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    func_00139ED0();
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x2A);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2C);
    reg_a2 = (u8 *)reg_tmp.w;
    *(u16 *)(reg_a6 + 0xA) = *(u16 *)reg_a2;
    reg_a2 += 2;
    *(u16 *)(reg_a6 + 0xC) = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_tmp.w = (u32)reg_a2;
    *(u16 *)(reg_a6 + 0x2A) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x2C) = reg_tmp.h[0];
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x26);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x28);
    reg_d1.w += reg_tmp.w;
    *(u16 *)(reg_a6 + 2) = reg_d1.h[1];
    *(u16 *)(reg_a6 + 4) = reg_d1.h[0];
block_fire:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x12);
    if (0 > (s16)reg_d0.h[0]) goto block_debris;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x1E);
    reg_d1.h[0] <<= 8;
    reg_d0.h[0] |= reg_d1.h[0];
    x_save = *(u16 *)(reg_a6 + 0x1C);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x14);
    *(u8 *)(reg_a6 + 0x1C) = *(u8 *)(reg_a6 + 0x17);
    func_001B82F0();
    *(u16 *)(reg_a6 + 0x1C) = x_save;
    *(u16 *)(reg_a6 + 0x12) = 0xFFFF;
block_debris:
    reg_d0.h[0] = D_0029C06C[0];
    *(u16 *)(reg_a6 + 4) -= reg_d0.h[0];
    if (*(u16 *)(reg_a6 + 0x10) == 0) goto block_shift;
    func_00201B80();
block_shift:
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1B);
    if (reg_d0.b[0] == 0) goto block_speed;
    reg_d1.w = 0;
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x1A);
    func_00201E20();
    *(u16 *)(reg_a6 + 0x34) = reg_d2.h[0];
    *(u16 *)(reg_a6 + 0x36) = reg_d3.h[0];
    *(u8 *)(reg_a6 + 0x1B) = 0;
block_speed:
    reg_d0.h[1] = *(u16 *)(reg_a6 + 0x22);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    if (reg_d0.w == 0) goto block_move;
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x21);
    *(u8 *)(reg_a6 + 0x21) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto block_move;
    *(u8 *)(reg_a6 + 0x21) = *(u8 *)(reg_a6 + 0x20);
    *(u16 *)(reg_a6 + 0x36) -= reg_d0.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x34) -= reg_d0.h[0];
block_move:
    reg_d0.h[1] = *(u16 *)(reg_a6 + 0x34);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x36);
    *(u16 *)(reg_a6 + 4) += reg_d0.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 2) += reg_d0.h[0];
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0xA800;
    D_0028E484.w = 0;
    reg_d1.h[0] += 0x1000;
    D_0028E484.h[0] = reg_d1.h[0];
    reg_d1.h[0] += 0xA800;
    D_0028E484.w += reg_tmp.w;
    if (D_0028E484.h[1] != 0) goto block_end;
    D_0028E484.w = 0;
    reg_tmp.w = reg_d1.w;
    hi_save = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0x1000;
    reg_d1.h[0] += 0x1000;
    D_0028E484.h[0] = reg_d1.h[0];
    reg_d1.h[0] += 0x7000;
    D_0028E484.w += reg_tmp.w;
    reg_d1.h[1] = hi_save;
    if (D_0028E484.h[1] != 0) goto block_end;
    *(u16 *)(reg_a6 + 0x32) -= 1;
    if (!(0 > *(s16 *)(reg_a6 + 0x32))) goto block_disp;
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x2E);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x30);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    if ((s16)reg_d0.h[0] != -1) goto block_anim;
block_end:
    *(u16 *)(reg_a6 + 0) = 0;
    goto next_1;
block_anim:
    *(u16 *)(reg_a6 + 0x32) = reg_d0.h[0];
    reg_tmp.w = (u32)reg_a0;
    *(u16 *)(reg_a6 + 0x2E) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x30) = reg_tmp.h[0];
    func_00139ED0();
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x2A);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2C);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0xA) = reg_d0.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_d0.h[0];
    reg_tmp.w = (u32)reg_a0;
    *(u16 *)(reg_a6 + 0x2A) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x2C) = reg_tmp.h[0];
block_disp:
    reg_a0 = (u8 *)D_0029CEA0_as_u8_a;
    if (!(0 > *(s16 *)reg_a0)) goto block_draw;
    reg_d0.h[0] = D_0028E3F0;
    reg_d0.h[0] &= 1;
    if ((s16)reg_d0.h[0] == 0) goto next_1;
block_draw:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x1E);
    reg_d0.h[0] >>= 2;
    ((Fn)*(u32 *)(D_00250760 + reg_d0.h[0] * 4))();
next_1:
    reg_a6 += 0x38;
    if ((s16)(--reg_d7.h[0]) >= 0) goto loop_1;
}
