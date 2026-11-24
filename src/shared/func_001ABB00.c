#include "common.h"

s32 func_001AB8D0();
extern u8 D_0026B8D0[];
extern u16 D_0028E588;
extern u32 D_0028E590;
extern s16 D_0029F1F0[];
extern u16 D_0029F1F2[];
extern u16 D_0029F1F4[];
extern u8 *reg_a0;

void func_001ABB00(void) {
    if (D_0028E588 != 0) {
        reg_d0.h[0] = D_0028E588;
        reg_a0 = D_0026B8D0;
        D_0028E590 = *(u32 *)(reg_a0 + reg_d0.h[0]);
        if (D_0029F1F0[0] < 0) {
            reg_d1.h[1] = D_0029F1F2[0];
            reg_d1.h[0] = D_0029F1F4[0];
            reg_d2.w = D_0028E590;
            func_001AB8D0();
        }
        D_0028E588 -= 4;
    }
}
