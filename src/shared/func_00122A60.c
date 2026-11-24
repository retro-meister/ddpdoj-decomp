#include "common.h"

s32 func_0013C980();                            /* extern */
s32 func_0013CA90();                            /* extern */
extern s32 D_0028DFF4;
extern s16 D_0028E000;
extern s16 D_0028E004;
extern s8 D_0029CEA0[];
extern u8 D_0029F1F0[];
extern u8 D_0029F260[];
extern u8 *reg_a0;
extern s8 *reg_a6;

void func_00122A60(void) {
    reg_a6 = D_0029CEA0;
    if (*reg_a6 >= 0) {
        reg_a0 = D_0029F260;
        func_0013C980();
        D_0028E004 = 0;
        D_0029F260[0] &= 0xBF;
    } else {
        reg_a0 = D_0029F1F0;
        func_0013CA90();
        D_0028E000 = 0;
        D_0029F1F0[0] &= 0xBF;
    }
    *reg_a0 &= 0x7F;
    reg_d0.w = 0;
    D_0028DFF4 = 0;
}
