#include "common.h"

s32 func_001A53E0();
s32 func_001A53F0();
s32 func_00200EE0();
extern u8 D_0026B760[];
extern u8 D_0026B800[];
extern u8 D_0026B870[];
extern u8 D_0028DAD0[];
extern u16 D_0028E3F0;
extern u16 D_0028E470;
extern u16 D_0028E644;
extern u16 D_0028E648;
extern u16 D_0028E64C;
extern u8 *reg_a0;

void func_001A7840(void) {
    u32 save_d6;

    reg_d0.h[0] = D_0028E648;
    if ((s16)reg_d0.h[0] >= 0) goto next_0;
    reg_d0.w = 0;
next_0:
    func_00200EE0();
    reg_d0.w = reg_d2.w;
    reg_d1.w = 0x5BBFFE00;
    reg_d1.h[0] += 0x440;
    reg_d4.h[0] = D_0028E644;
    reg_d6.w = 0;
    reg_d6.h[0] = D_0028E64C;
    reg_d7.w = 7;
loop_0:
    reg_tmp.w = reg_d0.w;
    reg_d0.w <<= 4;
    reg_d0.w |= reg_tmp.w >> 28;
    reg_d2.w = 0xF;
    reg_d2.h[0] &= reg_d0.h[0];
    if (reg_d2.h[0] != 0) goto next_1;
    if ((s32)reg_d6.w >= 0) goto next_5;
next_1:
    reg_d6.w |= 0x80000000;
    if (reg_d6.h[0] >= 0xC) goto next_3;
    reg_d5.w = 0;
    save_d6 = reg_d6.w;
loop_1:
    D_0028E470 = reg_d6.h[0];
    reg_d6.h[0] -= 3;
    if ((s32)D_0028E470 < 3) goto next_2;
    reg_d5.h[0] += 4;
    goto loop_1;
next_2:
    reg_d6.w = save_d6;
    reg_a0 = (u8 *)D_0026B760;
    reg_a0 = *(u8 **)(D_0026B760 + (reg_d5.h[0] & ~3));
    reg_d2.h[0] *= 4;
    reg_a0 += reg_d2.h[0];
    reg_d2.w = *(u32 *)reg_a0;
    goto next_4;
next_3:
    reg_d5.h[0] = reg_d2.h[0];
    reg_d2.w = 6;
    reg_d2.h[0] &= D_0028E3F0;
    reg_a0 = (u8 *)D_0028DAD0;
    reg_d2.h[0] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)D_0026B870;
    reg_d5.h[0] += reg_d5.h[0];
    reg_d5.h[0] += reg_d5.h[0];
    reg_a0 += reg_d5.h[0];
    reg_d2.w += *(u32 *)reg_a0;
next_4:
    reg_d3.h[0] = 0x610;
    func_001A53F0();
next_5:
    reg_d1.h[0] += 0x440;
    if ((s16)(reg_d7.h[0] -= 1) >= 0) goto loop_0;
    reg_d1.h[0] += 0xFE00;
    reg_d1.w -= 0x2000000;
    reg_d2.w = 0xE37;
    reg_d6.h[0] -= 0x1B;
    if ((s16)reg_d6.h[0] >= 0) goto next_6;
    reg_d6.h[0] *= 0xFFFF;
    reg_d6.h[0] &= 0xFFFE;
    reg_d6.h[0] += reg_d6.h[0];
    reg_d2.w = *(u32 *)(D_0026B800 + (reg_d6.h[0] & ~3));
next_6:
    reg_d3.h[0] = 0x420;
    func_001A53E0();
}
