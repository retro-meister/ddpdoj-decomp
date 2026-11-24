#include "common.h"

s32 func_0013C980();                            /* extern */
s32 func_0013CA90();                            /* extern */
extern s32 D_0028DFF4;
extern s16 D_0028E000_as_s16;
extern s16 D_0028E004_as_s16;
extern s8 D_0029CEA0_as_s8_a[];
extern u8 D_0029F1F0_as_u8_a[];
extern u8 D_0029F260_as_u8_a[];
extern u8 *reg_a0;
extern s8 *reg_a6_as_s8_p;

void func_00122A60(void) {
    reg_a6_as_s8_p = D_0029CEA0_as_s8_a;
    if (*reg_a6_as_s8_p >= 0) {
        reg_a0 = D_0029F260_as_u8_a;
        func_0013C980();
        D_0028E004_as_s16 = 0;
        D_0029F260_as_u8_a[0] &= 0xBF;
    } else {
        reg_a0 = D_0029F1F0_as_u8_a;
        func_0013CA90();
        D_0028E000_as_s16 = 0;
        D_0029F1F0_as_u8_a[0] &= 0xBF;
    }
    *reg_a0 &= 0x7F;
    reg_d0.w = 0;
    D_0028DFF4 = 0;
}
