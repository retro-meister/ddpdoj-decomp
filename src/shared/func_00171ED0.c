#include "common.h"

s32 func_002011A0();
extern s8 D_0026B210[];
extern u16 D_0028E3F0;
extern s8 D_002BB430[];
extern s8 *reg_a0;
extern s8 *reg_a3;
extern s8 *reg_a4;

void func_00171ED0(void) {
    reg_d6.w = 0;
    reg_a4 = (s8 *)D_002BB430;
    reg_d7.w = 4;
    do {
loop_1:
        func_002011A0();
        reg_a0 = (s8 *)D_0026B210;
        reg_d0.h[0] += D_0028E3F0;
        reg_d0.h[0] &= 0x1F;
        reg_a0 = &reg_a0[reg_d0.h[0]];
        reg_d0.w = 0;
        reg_d0.b[0] = *reg_a0;
        if ((1 << reg_d0.b[0]) & reg_d6.w) goto loop_1;
        reg_d6.w = reg_d6.w | (1 << reg_d0.w);
        reg_a4[7] = reg_d0.b[0];
        reg_a4 += 8;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d7.w = 4;
    reg_a4 = (s8 *)D_002BB430;
    do {
        reg_a3 = reg_a4;
        reg_a3 += 7;
        reg_d5.b[0] = *reg_a3;
        reg_d6.w = 4;
        do {
            reg_a3 -= 1;
            reg_d5.b[0] -= 1;
            if (0 > (s8) reg_d5.b[0]) {
                reg_d5.b[0] = 4;
            }
            *reg_a3 = reg_d5.b[0];
        } while ((s16)(--reg_d6.h[0]) >= 0);
        reg_a4 += 8;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
