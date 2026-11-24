#include "common.h"

s32 func_0012DB30();
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a6;

void func_0012DCD0(void) {
    u32 temp_a1;

    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    reg_d0.b[0] += 4;
    reg_d0.h[0] &= 0xF8;
    temp_a1 = reg_d0.h[0];
    reg_d2.h[0] = temp_a1;
    reg_d2.h[0] >>= 1;
    reg_d0.h[0] = temp_a1 + reg_d2.h[0];
    reg_a1 += reg_d0.h[0];
    reg_a0 = reg_a6 + 6;
    reg_d0.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
    (*(u16 *)((u8 *)(reg_a0) + (0))) += reg_d0.h[0];
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d0.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
    (*(u16 *)((u8 *)(reg_a0) + (0))) += reg_d0.h[0];
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a6) + (4))) += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_tmp.w += reg_d1.w;
    (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) reg_tmp.h[0];
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    (*(u16 *)((u8 *)(reg_a6) + (0x1C))) |= reg_d0.h[0];
    func_0012DB30();
}
