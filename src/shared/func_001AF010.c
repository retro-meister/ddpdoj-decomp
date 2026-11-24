#include "common.h"

extern u16 D_0028C11C[];
extern u16 D_0028C120[];
extern u8 *reg_a0;

extern s8 D_0028E408;

void func_001AF010(void) {
    u32 save_d0;
    u32 save_d1;
    u32 t;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    if (reg_d6.h[0] != 0xFF) goto next_3;
    if (reg_d5.h[0] != 0) goto next_1;
    reg_d6.h[0] = 0;
    reg_d7.h[0] = 0;
    goto block_set;
next_1:
    reg_d6.h[0] = 1;
    reg_d7.h[0] = 2;
    goto block_set;
next_3:
    reg_d0.w = 1;
loop_4:
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    reg_a0 = (u8 *)D_0028C11C;
    reg_d1.h[0] = (reg_d1.h[0]) ? *(u16 *)(reg_a0 + ((s16) reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    if (reg_d6.h[0] != reg_d1.h[0]) goto next_5;
    reg_d6.h[0] = reg_d0.h[0];
    goto next_6;
next_5:
    t = --reg_d0.h[0];
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_4;
next_6:
    reg_d0.w = 2;
loop_7:
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    reg_a0 = (u8 *)D_0028C120;
    reg_d1.h[0] = (reg_d1.h[0]) ? *(u16 *)(reg_a0 + ((s16) reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    if (reg_d7.h[0] != reg_d1.h[0]) goto next_8;
    reg_d7.h[0] = reg_d0.h[0];
    goto next_9;
next_8:
    t = --reg_d0.h[0];
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_7;
next_9:
    reg_d1.w = save_d1;
    reg_d0.w = save_d0;
    D_0028E408 = 0;
    return;
block_set:
    reg_d1.w = save_d1;
    reg_d0.w = save_d0;
    D_0028E408 = 1;
}
