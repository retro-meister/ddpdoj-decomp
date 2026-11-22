#include "common.h"

s32 func_0019FD30();                            /* extern */
extern s32 D_0029D710[];
extern s16 D_0029F110[];
extern s32 D_0029F1F0[];
extern s32 *reg_a2;
extern s32 *reg_a4;
extern s16 *reg_a6;

void func_0019FCE0(void) {
    reg_a6 = D_0029F110;
    reg_a4 = D_0029F1F0;
    reg_a2 = D_0029D710;
    if (*reg_a6 < 0) {
        func_0019FD30();
    }
}
