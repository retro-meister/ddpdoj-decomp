#include "common.h"

extern s8 D_0028E408;

s32 func_002011D0();
extern u16 D_0024F520[];
extern u8 D_0029BD7C[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;

void func_00136BB0(void) {
    u8 *save;

    save = reg_a0;
    reg_d0.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a3 = (u8 *)D_0024F520;
    reg_a3 = *(u8 **)(reg_a3 + reg_d0.h[0]);
    reg_d0.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
    if (0 <= (s64)*(s16 *)reg_a2) goto next_0;
    reg_d0.w |= 0x80;
next_0:
    *(u16 *)reg_a0 = reg_d0.h[0];
    reg_a0 += 2;
    reg_a1 = (u8 *)reg_d1.w;
    *(u16 *)reg_a0 = *(u16 *)(reg_a1 + 2);
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)(reg_a1 + 4);
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    reg_a0 += 4;
    *(u16 *)reg_a0 = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d1.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d2.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d2.h[0];
    reg_a0 += 2;
    if (0 <= (s64)(s8)reg_d3.b[0]) goto next_2;
    reg_d3.b[0] = ~reg_d3.b[0];
    if (!(reg_d3.w & 0x20)) goto next_1;
    func_002011D0();
    if (reg_d0.b[0] != 0) goto next_1;
    reg_d3.b[0] ^= 0x20;
next_1:
    if (!(reg_d3.h[0] & 0x40)) goto next_2;
    func_002011D0();
    if (reg_d0.b[0] != 0) goto next_2;
    reg_d3.b[0] ^= 0x40;
next_2:
    *(u16 *)reg_a0 = reg_d3.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    reg_a0[-1] = reg_d3.b[0];
    reg_tmp.w = (u32)reg_a2;
    *(u16 *)reg_a0 = reg_tmp.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[0];
    reg_a0 += 2;
    reg_d3.h[1] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d3.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d3.h[0] -= *(u16 *)(D_0029BD7C + 2);
    *(u16 *)reg_a0 = reg_d3.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
    *(u16 *)(D_0029BD7C + 2) -= 4;
    if (0 <= (s64)*(s16 *)(D_0029BD7C + 2)) goto next_3;
    *(u16 *)(D_0029BD7C + 2) = 0xC;
next_3:
    reg_a0 = save;
    D_0028E408 = 0;
}
