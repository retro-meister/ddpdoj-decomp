#include "common.h"

s32 func_00206FD0();
extern u8 D_002A04B0[];
extern u8 D_002A0AF0[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;

void func_002072F0(void) {
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 tmp;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    if (save_d0 == 0) goto block_1;
    reg_a0 = (u8 *)D_002A04B0;
    reg_d2.w = 0x13;
loop_2:
    if (*(u16 *)reg_a0 == 0) goto next_3;
    reg_d1.h[1] = *(u16 *)(reg_a0 + 0x4C);
    reg_d1.h[0] = *(u16 *)(reg_a0 + 0x4E);
    if (save_d0 != reg_d1.w) goto next_3;
    reg_a2 = reg_a0;
    reg_a3 = reg_a0 + 0x50;
    reg_d4.w = (u32) reg_a3;
    reg_d3.w = (u32) D_002A0AF0;
    reg_d3.w -= reg_d4.w;
    func_00206FD0();
    reg_a2 += reg_d3.h[0];
    *(s16 *)(reg_a2 + 0) = 0;
    *(s16 *)(reg_a2 + 0x4A) = 0;
    *(s16 *)(reg_a2 + 0x4C) = 0;
    *(s16 *)(reg_a2 + 0x4E) = 0;
    goto block_1;
next_3:
    reg_a0 += 0x50;
    tmp = reg_d2.h[0] - 1;
    reg_d2.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
block_1:
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
}
