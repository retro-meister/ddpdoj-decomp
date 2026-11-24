#include "common.h"

typedef void (*Fn)();

s32 func_00201200();
extern u8 D_00250D00[];
extern u16 *D_0028E530_as_u16_p;
extern u16 D_0029A528[];
extern u8 *reg_a0;
extern u8 *reg_a2;
extern u8 *reg_a6;

void func_0020AAA0(void) {
    u16 *temp_a2;
    u16 *temp_a3;
    u32 temp_a0;
    u32 temp_a0_2;
    u32 temp_a1;

    D_0028E530_as_u16_p = (u16 *)(reg_a2);
    reg_d3.h[0] = reg_d0.h[0];
    reg_d3.h[0] |= 0x8000;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a0 = reg_d3.h[0] + *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_d3.h[0] = temp_a0;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    temp_a0_2 = *(u16 *)reg_a2;
    temp_a1 = reg_d3.h[0];
    reg_d3.h[0] = temp_a1 + temp_a0_2;
    reg_a2 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
    reg_a0 += 4;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    reg_d3.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    if (0 > (s16) reg_d3.h[0]) {
        reg_d3.w = 0;
        reg_d3.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
    }
    func_00201200();
    if (reg_d5.h[0] == 0) {
        reg_d3.h[0] |= 0x2000;
    }
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    temp_a3 = (u16 *)(reg_a2 + 2);
    temp_a2 = (u16 *)(reg_a0 + 2);
    reg_a2 = (u8 *)(temp_a3);
    reg_a0 = (u8 *)(temp_a2);
    D_0029A528[0] += 1;
    ((Fn)*(u32 *)((u8 *)D_00250D00 + (reg_d0.h[0] & ~3)))();
}
