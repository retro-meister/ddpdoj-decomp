#include "common.h"

s32 func_00206F30();
extern u16 D_0028E0D0;
extern u8 D_002A04B0[];
extern u8 D_002A0AF0[];
extern u8 D_002A1130[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;

void func_00207070(void) {
    u32 tmp;

    if (D_0028E0D0 == 0) goto block_rts;
    reg_a0 = (u8 *)D_002A1130;
loop_1:
    if (*(u16 *)reg_a0 == 0) goto next_4;
    reg_d5.h[0] = *(u16 *)(reg_a0 + 0x4A);
    reg_a1 = (u8 *)D_002A04B0;
    reg_d6.w = 0x13;
loop_2:
    if (*(s16 *)(reg_a1 + 0x4A) > (s16) reg_d5.h[0]) goto next_3;
    reg_a2 = reg_a1 + 0x50;
    reg_a3 = reg_a1;
    reg_d4.w = (u32) reg_a2;
    reg_d3.w = (u32) D_002A0AF0;
    reg_d3.w -= reg_d4.w;
    func_00206F30();
    reg_a2 = reg_a0;
    reg_d2.h[0] = 0x27;
loop_5:
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    tmp = reg_d2.h[0] - 1;
    reg_d2.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_5;
    goto next_4;
next_3:
    reg_a1 += 0x50;
    tmp = reg_d6.h[0] - 1;
    reg_d6.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
next_4:
    reg_a0 += 0x50;
    D_0028E0D0 -= 0x50;
    if (D_0028E0D0 != 0) goto loop_1;
block_rts:
    return;
}
