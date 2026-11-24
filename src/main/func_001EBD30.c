#include "common.h"

s32 func_00129450();
extern u8 *reg_a3;
extern u8 *reg_a4;

void func_001EBD30(void) {
    reg_d3.h[1] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d3.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] += *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d5.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d4.w = 0;
    reg_d1.h[0] += reg_d5.h[0];
    func_00129450();
    reg_d4.h[0] = reg_d5.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d4.h[0] = (s16) reg_d4.h[0] >> 1;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d5.h[0] += reg_d4.h[0];
    reg_d4.h[0] = (s16) reg_d4.h[0] >> 2;
    reg_d5.h[0] += reg_d4.h[0];
    reg_d1.h[0] -= reg_d5.h[0];
    reg_d0.h[0] += *(u16 *)(reg_a4 + 0xE);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x10);
    reg_d4.w = 0;
    func_00129450();
}
