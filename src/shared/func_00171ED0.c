#include "common.h"

s32 func_002011A0();
extern s8 D_0026B210[];
extern u16 D_0028E3F0;
extern s8 D_002BB430[];
extern s8 *reg_a0_as_s8_p;
extern s8 *reg_a3_as_s8_p;
extern s8 *reg_a4_as_s8_p;

void func_00171ED0(void) {
    reg_d6.w = 0;
    reg_a4_as_s8_p = (s8 *)D_002BB430;
    reg_d7.w = 4;
    do {
loop_1:
        func_002011A0();
        reg_a0_as_s8_p = (s8 *)D_0026B210;
        reg_d0.h[0] += D_0028E3F0;
        reg_d0.h[0] &= 0x1F;
        reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
        reg_d0.w = 0;
        reg_d0.b[0] = *reg_a0_as_s8_p;
        if ((1 << reg_d0.b[0]) & reg_d6.w) goto loop_1;
        reg_d6.w = reg_d6.w | (1 << reg_d0.w);
        reg_a4_as_s8_p[7] = reg_d0.b[0];
        reg_a4_as_s8_p += 8;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d7.w = 4;
    reg_a4_as_s8_p = (s8 *)D_002BB430;
    do {
        reg_a3_as_s8_p = reg_a4_as_s8_p;
        reg_a3_as_s8_p += 7;
        reg_d5.b[0] = *reg_a3_as_s8_p;
        reg_d6.w = 4;
        do {
            reg_a3_as_s8_p -= 1;
            reg_d5.b[0] -= 1;
            if (0 > (s8) reg_d5.b[0]) {
                reg_d5.b[0] = 4;
            }
            *reg_a3_as_s8_p = reg_d5.b[0];
        } while ((s16)(--reg_d6.h[0]) >= 0);
        reg_a4_as_s8_p += 8;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
