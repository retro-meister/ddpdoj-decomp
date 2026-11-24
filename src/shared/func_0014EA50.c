#include "common.h"

typedef void (*Fn)();

extern s8 D_0028E408;

s32 func_00201B80();
s32 func_00201C60();
extern u8 D_0026A350[];
extern u16 D_0028E8A0;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0014EA50(void) {
    u8 *p;
    s8 v;
    u8 c;

    enemy_move_end_requested = 0;
    if (D_0028E8A0 != 0) goto block_7;
    if (*(u8 *)(reg_a5 + 0xC) & 1) {
        func_00201B80();
    }
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x12);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x14);
    reg_a0 = (u8 *)reg_tmp.w;
loop_1:
    p = reg_a0;
    reg_a0 = p + 1;
    v = *(s8 *)p;
    reg_d1.b[0] = v;
    if (v < 0) goto block_5;
    p = reg_a0;
    reg_a0 = p + 1;
    v = *(s8 *)p;
    reg_d0.b[0] = v;
    if ((v & 0xFF) == 0) goto next_2;
    c = *(u8 *)(reg_a5 + 0x11);
    if (c == reg_d0.b[0]) goto block_3;
    *(u8 *)(reg_a5 + 0x11) = c + 1;
next_2:
    reg_d1.h[0] &= 0x7F;
    *(u8 *)(reg_a6 + 0x1A) = reg_d1.b[0];
    if ((s32)reg_d1.h[0] >= 0x40) goto block_2;
    if (*(u8 *)(reg_a5 + 3) & 0x20) goto block_1;
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x40);
    reg_d3.h[0] = *(u16 *)(reg_a5 + 0x42);
    *(u16 *)(reg_a6 + 2) += reg_d2.h[0];
    *(u16 *)(reg_a6 + 4) += reg_d3.h[0];
    D_0028E408 = 0;
    return;
block_1:
    *(u8 *)(reg_a5 + 3) &= 0xDF;
    func_00201C60();
    *(u16 *)(reg_a5 + 0x40) = reg_d2.h[0];
    *(u16 *)(reg_a5 + 0x42) = reg_d3.h[0];
    D_0028E408 = 0;
    return;
block_2:
    reg_d2.w = 0;
    reg_d3.h[0] = reg_d2.h[0];
    D_0028E408 = 0;
    return;
block_3:
    *(u8 *)(reg_a5 + 0x11) = 0;
block_4:
    reg_tmp.w = (u32)reg_a0;
    *(u16 *)(reg_a5 + 0x12) = reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x14) = reg_tmp.h[0];
    *(u8 *)(reg_a5 + 3) |= 0x20;
    goto loop_1;
block_5:
    if ((s32)reg_d1.b[0] < 0xC0) goto block_6;
    *(s8 *)(reg_a6 + 0x1B) = *(s8 *)reg_a0;
    reg_a0 += 1;
    goto block_4;
block_6:
    enemy_move_end_requested = 0;
    reg_d1.h[0] &= 0xF;
    ((Fn) *(u32 *)(D_0026A350 + reg_d1.h[0] * 4))();
    if (enemy_move_end_requested == 0) goto block_4;
    D_0028E408 = 0;
    return;
block_7:
    D_0028E408 = 0;
    reg_d2.w = 0;
    reg_d3.w = 0;
}
