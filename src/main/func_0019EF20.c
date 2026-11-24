#include "common.h"

s32 func_0019DCA0();
s32 func_0019DCE0();
s32 func_0019F270();
extern u8 D_0025EEA0[];
extern u8 D_0028D960;
extern u16 D_0028E07C[];
extern u16 D_0028E07E[];
extern u16 D_0028E084[];
extern u16 D_0028E086[];
extern u16 D_0028E928;
extern u8 D_0029E390[];
extern u8 D_0029EA50[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0019EF20(void) {
    u32 save_d6;
    u32 save_d7;
    u8 *save_a3;
    u8 *save_a5;
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
    reg_d0.h[0] = 0x150;
    if ((*(u16 *)((u8 *)(reg_a4) + (0x58))) == 0) goto next_1;
    reg_d0.h[0] = 0x150;
next_1:
    reg_d4.h[0] = *(u16 *)reg_a1;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x58)));
    reg_d5.h[0] = reg_d0.h[0];
    reg_d0.h[0] *= 4;
    if (!((*(u8 *)((u8 *)(reg_a4) + (0))) & 1)) goto next_2;
    reg_d0.h[0] += 4;
    reg_a1 = &D_0028D960;
    reg_d4.h[0] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a1;
next_2:
    if (D_0028E928 != 0) goto next_3;
    if ((s32)reg_d4.h[0] <= 4) goto next_3;
    reg_d4.w = 4;
next_3:
    reg_d4.h[0] *= 2;
    reg_d4.h[0] += 1;
    reg_a1 = (u8 *)D_0025EEA0;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_a1 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x20)));
    reg_d0.h[0] *= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a1;
    reg_a1 = (u8 *)reg_tmp.w;
    func_0019DCA0();
    func_0019DCE0();
loop_0:
    if (*(s16 *)reg_a0 >= 0) goto next_4;
    reg_a0 += 0x30;
    if ((s16)(reg_d4.h[0] -= 1) >= 0) goto loop_0;
    goto next_5;
next_4:
    reg_a3 = reg_a0;
loop_1:
    reg_a0 += 0x30;
    if (*(s16 *)reg_a0 >= 0) goto next_6;
    if ((s16)(reg_d4.h[0] -= 1) >= 0) goto loop_1;
    goto next_5;
next_6:
    func_0019F270();
next_5:
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a3 = save_a3;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}
