#include "common.h"

s32 func_001A9BE0();
s32 func_001AA2E0();
s32 func_001AA330();
extern u16 D_0028E5D0;
extern u16 D_0028E5FC;
extern s16 D_0028E648_as_s16;
extern u16 D_0028E698;
extern u16 D_0029F282[];
extern u16 D_0029F2BA[];

void func_001AA210(void) {
    if (D_0028E648_as_s16 < 0) {
        D_0028E648_as_s16 = 0;
    }
    func_001A9BE0();
    D_0028E698 -= 1;
    if ((s16) D_0028E698 >= 0) {
        func_001AA330();
        return;
    }
    reg_d0.w = 1;
    reg_d2.w = 0;
    if (D_0028E5FC != 0) {
        reg_d0.h[0] += D_0028E5D0;
    } else {
        reg_d2.w = 8;
        reg_d2.h[0] -= (s16) (u16) D_0029F282[0];
        reg_d2.h[0] += 8;
        if (D_0029F2BA[0] != 2) {
            reg_d2.h[0] -= 3;
        }
    }
    D_0028E698 = reg_d2.h[0];
    func_001AA2E0();
}
