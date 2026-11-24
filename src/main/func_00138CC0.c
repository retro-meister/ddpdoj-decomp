#include "common.h"

s32 func_0011C3C0();
extern u8 *reg_a0;
extern u8 *reg_a5;

void func_00138CC0(void) {
    reg_tmp.h[1] = *(u16 *) (reg_a5 + 0xA);
    reg_tmp.h[0] = *(u16 *) (reg_a5 + 0xC);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d1.w = 0;
    reg_d7.w = 0xE;
loop_1:
    reg_d0.w = 0;
    reg_d6.w = 8;
loop_2:
    reg_d4.w = *(u32 *) reg_a0;
    reg_a0 += 4;
    func_0011C3C0();
    reg_d0.h[0] += 1;
    if ((s16)(--reg_d6.h[0]) >= 0) {
        goto loop_2;
    }
    reg_d1.h[0] += 1;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_1;
    }
    reg_tmp.w = (u32) reg_a0;
    *(u16 *) (reg_a5 + 0xA) = reg_tmp.h[1];
    *(u16 *) (reg_a5 + 0xC) = reg_tmp.h[0];
    *(u16 *) (reg_a5 + 0xE) = 0xF;
}
