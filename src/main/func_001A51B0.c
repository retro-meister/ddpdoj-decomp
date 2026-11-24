#include "common.h"

s32 func_0014E050();
s32 func_0014E290();
s32 func_00201B80();
extern Reg32 D_0028E484;
extern u16 D_0028E8A0;
extern u16 D_0029C068[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001A51B0(void) {
    if ((*(u16 *)((u8 *)(reg_a6) + (8))) != 0) goto next_0;
    func_00201B80();
next_0:
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    D_0028E484.w = 0;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x1C00;
    reg_d0.h[0] += D_0029C068[0];
    D_0028E484.h[0] = 0x9000;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += D_0028E484.w;
    reg_d0.h[0] += 0x9000;
    if (reg_tmp.h[1] != 0) goto next_1;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_d0.h[0];
    D_0028E484.w = (s16)reg_d1.h[0];
    reg_d1.w = D_0028E484.w;
    reg_d1.w += 0x4000;
    if ((s32)reg_d1.w <= 0x3800) goto next_1;
    if ((s32)reg_d1.w < 0xB800) goto next_3;
next_1:
    if ((*(u16 *)((u8 *)(reg_a6) + (6))) == 0) goto next_4;
next_2:
    func_0014E290();
    return;
next_3:
    (*(u16 *)((u8 *)(reg_a6) + (6))) = 1;
next_4:
    if (D_0028E8A0 != 0) return;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
    if ((s32)reg_tmp.b[0] > 0) return;
    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    reg_d1.w = 0;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0xC)));
    func_0014E050();
    (*(u16 *)((u8 *)(reg_a0) + (0x12))) = (*(u16 *)((u8 *)(reg_a5) + (0x12)));
    (*(u16 *)((u8 *)(reg_a0) + (0x14))) = (*(u16 *)((u8 *)(reg_a5) + (0x14)));
    (*(u16 *)((u8 *)(reg_a0) + (0x48))) = (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a0) + (0x4A))) = (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(u8 *)((u8 *)(reg_a0) + (3))) |= 0x40;
    if ((*(u16 *)((u8 *)(reg_a5) + (0x18))) == 0) return;
    (*(u8 *)((u8 *)(reg_a5) + (0x18))) -= 1;
    if ((*(u8 *)((u8 *)(reg_a5) + (0x18))) == 0) goto next_2;
}
