#include "common.h"

typedef void (*Fn)();

extern u16 D_0026C140[];
extern u16 D_0026C1C0[];
extern u16 D_0028DB08[];
extern u16 D_0028E47C;
extern u16 D_0028E47E;
extern u16 D_0028E480_as_u16;
extern u16 D_0028E482;
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001BF2A0(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts;
    *(u8 *)(reg_a4 + 3) = *(u8 *)(reg_a4 + 2);
    if (*(s16 *)(reg_a4 + 6) >= 0) goto next_1;
    reg_a0 = (u8 *)(D_0026C1C0);
    reg_d1.w = 0;
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x9A);
    reg_d1.b[0] += 1;
    reg_d1.h[0] &= 0x3E;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    D_0028E47E = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    D_0028E47C = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&D_0028E47C;
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    D_0028E482 = *(u16 *)(reg_a6 + 0x82);
    D_0028E480_as_u16 = *(u16 *)(reg_a6 + 0x84);
    reg_d2.w = *(u32 *)&D_0028E480_as_u16;
    goto next_2;
next_1:
    reg_a0 = (u8 *)(D_0026C140);
    reg_d1.w = 0;
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0xBA);
    reg_d1.b[0] += 1;
    reg_d1.h[0] &= 0x3E;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    D_0028E47E = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    D_0028E47C = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&D_0028E47C;
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    reg_d2.h[1] = *(u16 *)(reg_a6 + 0xA2);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0xA4);
next_2:
    reg_a0 = (u8 *)(D_0028DB08);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 4);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_tmp.w = *(u32 *)(reg_a0 + reg_d0.h[0]);
    jtbl_0028E3F4 = *(Fn *)reg_tmp.w;
    jtbl_0028E3F4();
    *(u16 *)(reg_a4 + 6) *= 0xFFFF;
    *(u16 *)(reg_a4 + 8) -= 1;
    if (*(u16 *)(reg_a4 + 8) != 0) goto block_rts;
    *(s16 *)(reg_a4 + 0) = 0;
block_rts:
    return;
}
