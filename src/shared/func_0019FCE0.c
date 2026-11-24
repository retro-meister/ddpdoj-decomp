#include "common.h"

s32 func_0019FD30();                            /* extern */
extern s32 D_0029D710_as_s32_a[];
extern s16 D_0029F110_as_s16_a[];
extern s32 D_0029F1F0_as_s32_a[];
extern s32 *reg_a2_as_s32_p;
extern s32 *reg_a4_as_s32_p;
extern s16 *reg_a6_as_s16_p;

void func_0019FCE0(void) {
    reg_a6_as_s16_p = D_0029F110_as_s16_a;
    reg_a4_as_s32_p = D_0029F1F0_as_s32_a;
    reg_a2_as_s32_p = D_0029D710_as_s32_a;
    if (*reg_a6_as_s16_p < 0) {
        func_0019FD30();
    }
}
