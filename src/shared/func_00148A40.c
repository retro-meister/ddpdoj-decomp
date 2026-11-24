#include "common.h"

s32 func_001486D0();
s32 func_00148800();
s32 func_0018DA70();
s32 func_00201E20();
s32 func_00209F20();
extern u16 D_00253940[];
extern u16 D_002539B0[];
extern Reg32 D_0028E484;
extern u16 D_0028E928;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_00148A40(void) {
    if (reg_d0.h[0] != 0) goto block_main;
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0);
    *(u8 *)(reg_a6 + 0) |= 0x40;
    if (!(reg_tmp.b[0] & 0x40)) goto block_obj;
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 1);
    *(u8 *)(reg_a6 + 1) |= 1;
    if (reg_tmp.b[0] & 1) goto block_first;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x30);
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0x32);
    *(u16 *)(reg_a6 + 2) += reg_d0.h[0];
    *(u16 *)(reg_a6 + 4) += reg_d1.h[0];
block_obj:
    *(u8 *)(reg_a6 + 0x1D) ^= 0x40;
    func_001486D0();
    return;
block_first:
    *(u16 *)(reg_a6 + 0) |= 8;
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1B);
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x1A);
    func_00201E20();
    *(u16 *)(reg_a6 + 0x2C) = reg_d2.h[0];
    *(u16 *)(reg_a6 + 0x2E) = reg_d3.h[0];
    if (*(s8 *)(reg_a6 + 0) < 0) goto block_touch;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x26);
    reg_a0 = (u8 *)D_00253940;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)reg_tmp.w;
    *(u16 *)(reg_a6 + 6) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0xE) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 2) += reg_d0.h[0];
    *(u8 *)(reg_a6 + 1) &= 0xFE;
    goto block_anim;
block_clr:
    *(u16 *)(reg_a6 + 0) = 0;
    return;
block_anim:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2C);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x2E);
    *(u16 *)(reg_a6 + 2) += reg_d0.h[0];
    if ((s32)*(u16 *)(reg_a6 + 2) >= 0x8000) goto block_clr;
    *(u16 *)(reg_a6 + 4) += reg_d1.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 4);
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0xC000;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x400;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] += 0xC000;
    if ((s32)reg_tmp.h[0] > 0x4000) goto block_clr;
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x1E);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    *(u16 *)(reg_a6 + 0xA) = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if (*(s16 *)(reg_a6 + 0x24) >= 0) goto skip_1;
    *(u16 *)(reg_a6 + 0x24) = 4;
skip_1:
    func_001486D0();
    return;
block_main:
    if (reg_d1.sb[0] >= 0) goto block_anim;
block_touch:
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 1);
    *(u8 *)(reg_a6 + 1) |= 2;
    if (!(reg_tmp.b[0] & 2)) goto block_touch_first;
loop_1:
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x24);
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if ((s32)reg_tmp.h[0] < 4) goto block_clr;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2C);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x2E);
    *(u16 *)(reg_a6 + 2) += reg_d0.h[0];
    *(u16 *)(reg_a6 + 4) += reg_d1.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x1E);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    *(u16 *)(reg_a6 + 0xA) = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    func_001486D0();
    return;
block_touch_first:
    if (D_0028E928 == 0) goto skip_2;
    reg_d0.w = 0x14;
    func_00209F20();
skip_2:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2C);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x2E);
    if (!(*(u8 *)(reg_a6 + 1) & 1)) goto skip_4;
    reg_d3.h[0] = 8;
    if (!(*(u8 *)(reg_a6 + 0x28) & 4)) goto skip_3;
    reg_d3.h[0] = 0xA;
    if (*(u16 *)(reg_a6 + 0x2A) != reg_d3.h[0]) goto skip_4;
skip_3:
    *(u16 *)(reg_a6 + 2) -= 0x200;
skip_4:
    func_00148800();
    *(u16 *)(reg_a6 + 2) += reg_d0.h[0];
    *(u16 *)(reg_a6 + 4) += reg_d2.h[0];
    reg_d0.h[0] = (s16)reg_d0.h[0] >> 2;
    reg_d2.h[0] = (s16)reg_d2.h[0] >> 2;
    *(u16 *)(reg_a6 + 0x2C) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x2E) = reg_d2.h[0];
    func_0018DA70();
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x26);
    reg_a0 = (u8 *)D_002539B0;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)reg_tmp.w;
    *(u16 *)(reg_a6 + 6) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0xE) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x1E) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x20) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x22) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x24) = *(u16 *)reg_a0;
    reg_a0 += 2;
    goto loop_1;
}
