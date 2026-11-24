#include "common.h"

s32 func_0012DCC0();
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_0012DB30(void) {
    reg_a1 = (u8 *)(reg_a6 + 2);
    reg_d0.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] += *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] += *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d0.w = (u32) ((s32) reg_d0.w >> 6);
    reg_d0.w &= 0x07FF03FF;
    reg_d0.w |= 0x80008000;
    *(u16 *)reg_a4 = reg_d0.h[1];
    reg_a4 += 2;
    *(u16 *)reg_a4 = reg_d0.h[0];
    reg_a4 += 2;
    *(u16 *)reg_a4 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a4 += 2;
    *(u16 *)reg_a4 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a4 += 2;
    *(u16 *)reg_a4 = *(u16 *)reg_a1;
    reg_a4 += 2;
    *(u16 *)reg_a4 = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
    reg_a4 += 2;
    func_0012DCC0();
}
