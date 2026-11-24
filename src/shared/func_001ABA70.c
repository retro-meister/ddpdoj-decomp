#include "common.h"


s32 func_001AB8D0();
extern u8 D_0028E578_as_u8;
extern u8 D_0028E579;
extern u16 D_0028E580;
extern u32 D_0028E590_as_u32;
extern s16 D_0029F1F0[];
extern u16 D_0029F1F2[];
extern u16 D_0029F1F4[];
void func_001ABA70(void) {
    if (D_0028E580 != 0) {
        if (D_0029F1F0[0] < 0) {
            reg_d1.h[1] = D_0029F1F2[0];
            reg_d1.h[0] = D_0029F1F4[0];
            reg_d2.w = D_0028E590_as_u32;
            func_001AB8D0();
        }
        D_0028E579 -= 1;
        if ((s8) D_0028E579 < 0) {
            D_0028E579 = D_0028E578_as_u8;
            D_0028E590_as_u32 += 1;
            if (D_0028E590_as_u32 == 0xA04) {
                D_0028E580 = 0;
            }
        }
    }
}
