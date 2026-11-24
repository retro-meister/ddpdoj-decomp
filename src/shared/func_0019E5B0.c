#include "common.h"

s32 func_0019DC60();
s32 func_0019DCE0();
s32 func_0019E980();
extern u8 D_0025EE10[];
extern u8 D_0028D960;
extern u16 D_0028E07C[];
extern u16 D_0028E07E[];
extern u16 D_0028E084[];
extern u16 D_0028E086[];
extern u8 *D_0028E44C;
extern u16 D_0028E928;
extern u8 D_0029E390[];
extern u8 D_0029EA50[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0019E5B0(void) {
    u8 *save_a3;
    u8 *save_a5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a6;

    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a3 = reg_a3;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    reg_a0 = (u8 *)D_0029E390;
    reg_tmp.h[1] = D_0028E084[0];
    reg_tmp.h[0] = D_0028E086[0];
    reg_a1 = (u8 *)reg_tmp.w;
    if (reg_d7.h[0] != 0) goto next_0;
    reg_a0 = (u8 *)D_0029EA50;
    reg_tmp.h[1] = D_0028E07C[0];
    reg_tmp.h[0] = D_0028E07E[0];
    reg_a1 = (u8 *)reg_tmp.w;
next_0:
    reg_d0.h[0] = 0x450;
    if ((*(u16 *)((u8 *)(reg_a4) + (0x58))) == 0) goto next_1;
    reg_d0.h[0] = 0x450;
next_1:
    reg_a3 = reg_a0;
    reg_a3 += reg_d0.h[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x14)));
    reg_d0.b[0] += 0x10;
    reg_d0.b[0] &= 0x3F;
    if ((s32)reg_d0.b[0] >= 0x20) goto next_2;
    D_0028E44C = reg_a0;
    reg_a0 = reg_a3;
    reg_a3 = (u8 *)D_0028E44C;
next_2:
    reg_d4.h[0] = *(u16 *)reg_a1;
    reg_d4.h[0] += 2;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x58)));
    reg_d5.h[0] = reg_d0.h[0];
    reg_d0.h[0] *= 4;
    if (!((*(u8 *)((u8 *)(reg_a4) + (0))) & 1)) goto next_3;
    reg_a1 = &D_0028D960;
    reg_d0.h[0] += 4;
    reg_d4.h[0] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d4.h[0] += 2;
next_3:
    if (D_0028E928 != 0) goto next_4;
    if ((s32)reg_d4.h[0] <= 4) goto next_4;
    reg_d4.w = 4;
next_4:
    reg_d5.h[0] = reg_d4.h[0];
    reg_a1 = (u8 *)D_0025EE10;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_a1 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x20)));
    reg_d0.h[0] *= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a1;
    reg_a1 = (u8 *)reg_tmp.w;
loop_0:
    if (*(s16 *)reg_a0 >= 0) goto loop_1;
    reg_a0 += 0x30;
    if ((s16)(reg_d4.h[0] -= 1) >= 0) goto loop_0;
    goto next_5;
loop_1:
    if (*(s16 *)reg_a3 >= 0) goto next_6;
    reg_a3 += 0x30;
    if ((s16)(reg_d5.h[0] -= 1) >= 0) goto loop_1;
    goto next_5;
next_6:
    func_0019DC60();
    func_0019DCE0();
    func_0019E980();
    reg_a0 = reg_a3;
    func_0019DC60();
    func_0019DCE0();
    reg_a6 += 0x20;
    func_0019E980();
next_5:
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a3 = save_a3;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}
