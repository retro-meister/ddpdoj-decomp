#include "common.h"

s32 func_001A9CF0();
s32 func_001AA850();
s32 func_001AA8A0();
extern u16 D_0028E5CC;
extern u16 D_0028E5F8;
extern s16 D_0028E648_as_s16;
extern u16 D_0028E658;
extern u16 D_0029F212[];
extern u16 D_0029F24A[];

void func_001AA780(void) {
    if (D_0028E648_as_s16 < 0) {
        D_0028E648_as_s16 = 0;
    }
    func_001A9CF0();
    D_0028E658 -= 1;
    if ((s16) D_0028E658 >= 0) {
        func_001AA8A0();
        return;
    }
    reg_d0.w = 1;
    reg_d2.w = 0;
    if (D_0028E5F8 != 0) {
        reg_d0.h[0] += D_0028E5CC;
    } else {
        reg_d2.w = 8;
        reg_d2.h[0] -= (s16) (u16) D_0029F212[0];
        reg_d2.h[0] += 8;
        if (D_0029F24A[0] != 2) {
            reg_d2.h[0] -= 3;
        }
    }
    D_0028E658 = reg_d2.h[0];
    func_001AA850();
}
