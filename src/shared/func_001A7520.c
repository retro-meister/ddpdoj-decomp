#include "common.h"

s32 func_001A30A0();
s32 func_001A53F0();
s32 func_001A77A0();
extern u8 D_00261C50[];
extern u8 D_00261C90[];
extern u8 D_00261CD0[];
extern u8 D_0026B640[];
extern u8 D_0026B660[];
extern u16 D_0028E3EC;
extern Reg32 D_0028E470_as_Reg32;
extern Reg32 D_0028E480;
extern u8 *reg_a0;

void func_001A7520(void) {
    u32 save_d0;
    u32 save_d6;

    reg_d1.h[1] = 0x4FC0;
    reg_d3.h[0] = 0x610;
    reg_d5.w = 0xCCB;
    if (D_0028E3EC != 0) goto next_0;
    reg_d5.w = 0xCD5;
next_0:
    if (reg_d2.h[0] == 0) goto next_1;
    save_d0 = reg_d0.h[0];
    reg_a0 = (u8 *)D_00261C50;
    reg_d0.h[0] = reg_d4.h[0];
    func_001A30A0();
    reg_d0.h[0] = save_d0;
    goto next_2;
next_1:
    save_d0 = reg_d0.h[0];
    reg_a0 = (u8 *)D_00261C90;
    reg_d0.h[0] = reg_d4.h[0];
    func_001A30A0();
    reg_d0.h[0] = save_d0;
    if (reg_d0.h[0] < 0x100) goto next_2;
    save_d0 = reg_d0.h[0];
    reg_a0 = (u8 *)D_00261CD0;
    reg_d0.h[0] = reg_d4.h[0];
    func_001A30A0();
    reg_d0.h[0] = save_d0;
next_2:
    reg_d7.w = 3;
loop_0:
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] <<= 4;
    reg_d0.h[0] |= (u16)((s32)reg_tmp.h[0] >> 12);
    reg_d2.w = 0xF;
    if ((reg_d2.h[0] &= reg_d0.h[0]) != 0) goto next_3;
    if ((s32)reg_d6.w < 0) goto next_3;
    if ((s16)reg_d1.h[0] > 0x1C00) goto next_7;
    goto next_8;
next_3:
    reg_d6.w |= 0x80000000;
    if (reg_d6.h[0] >= 0xC) goto next_5;
    reg_d5.w = 0;
    save_d6 = reg_d6.w;
loop_1:
    D_0028E470_as_Reg32.w = reg_d6.h[0];
    D_0028E470_as_Reg32.w -= 3;
    reg_d6.h[0] = D_0028E470_as_Reg32.h[0];
    if (D_0028E470_as_Reg32.h[1] != 0) goto next_4;
    reg_d5.h[0] += 4;
    goto loop_1;
next_4:
    reg_d6.w = save_d6;
    reg_a0 = (u8 *)D_0026B660;
    reg_a0 = *(u8 **)(reg_a0 + reg_d5.h[0]);
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    D_0028E480.w = reg_d2.w;
    reg_d2.w = *(u32 *)(reg_a0 + D_0028E480.h[0]);
    goto next_6;
next_5:
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] = *(u16 *)(D_0026B640 + (reg_d2.h[0] & ~1));
    reg_d2.w += reg_d5.w;
next_6:
    func_001A53F0();
next_7:
    reg_d1.h[0] += 0x480;
next_8:
    if ((s16)(reg_d7.h[0] -= 1) >= 0) goto loop_0;
    func_001A77A0();
}
