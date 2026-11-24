#include "common.h"

s32 func_00129450();
s32 death_func_0021B5F0();
s32 death_func_0021B770();
extern u16 D_00259870[];
extern s16 D_0028E890_as_s16;
extern s16 D_0028E894_as_s16;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void death_func_0021C500(void) {
    u8 *p;
    u8 t;

    death_func_0021B5F0();
    p = reg_a4 + 0x1C;
    switch (*(u16 *)p) { case 0: goto next_0; }
    *(u16 *)p -= 1;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if ((u32)reg_tmp.w >= 0x1F800U) goto next_2;
next_0:
    death_func_0021B770();
    p = reg_a4 + 0x1E;
    if (*(u16 *)p == 0) goto next_1;
    *(u16 *)p -= 1;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if ((u32)reg_tmp.w >= 0x1C000U) goto next_9;
next_1:
    reg_tmp.b[0] = reg_a4[5];
    reg_a4[5] -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_2;
    reg_a4[5] = reg_a4[4];
    reg_d0.h[1] = *(u16 *)(reg_a4 + 0xE);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x10);
    reg_d1.b[0] = reg_a4[0x19];
    reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
    D_0028E894_as_s16 = 0;
    D_0028E890_as_s16 = 0;
    reg_d4.h[0] = 0x101;
    reg_tmp.w = reg_d4.w;
    reg_d4.h[1] = reg_tmp.h[0];
    reg_d4.h[0] = reg_tmp.h[1];
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1e);
    reg_d5.w = 0x01010001;
    reg_d6.w = 0xFE000000;
    reg_d7.w = 9;
    reg_a1 = (u8 *)D_00259870;
loop_0:
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d3.w += reg_d6.w;
    func_00129450();
    reg_d1.h[0] += 0x19;
    if ((s16)(reg_d7.h[0] -= 1) >= 0) goto loop_0;
    reg_d1.b[0] = reg_a4[0x18];
    reg_a4[0x19] += reg_d1.b[0];
next_2:
    reg_tmp.b[0] = reg_a6[0x1C];
    reg_a6[0x1C] -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_9;
    reg_a6[0x1C] = 8;
    if (reg_a6[0x1D] & 1) goto next_4;
    if ((s8)reg_a4[0x18] == -6) goto next_3;
    reg_a4[0x18] -= 1;
    goto next_7;
next_3:
    if (*(u16 *)(reg_a6 + 0x1e) == 5) goto next_8;
    *(u16 *)(reg_a6 + 0x1e) += 1;
    goto next_7;
next_4:
    if (reg_a4[0x18] == 6) goto next_5;
    reg_a4[0x18] += 1;
    goto next_7;
next_5:
    if ((s16)*(u16 *)(reg_a6 + 0x1e) == -5) goto next_8;
    *(u16 *)(reg_a6 + 0x1e) -= 1;
next_7:
    return;
next_8:
    reg_tmp.b[0] = reg_a4[9];
    reg_a4[9] -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_9;
    reg_a4[9] = reg_a4[8];
    t = reg_a6[0x1D];
    if (t & 1) {
        reg_a6[0x1D] = t & 0xFE;
        goto next_9;
    }
    reg_a6[0x1D] = t | 1;
next_9:
    return;
}
