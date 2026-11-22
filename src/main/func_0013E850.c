#include "common.h"

s32 func_0013E970();
s32 func_0013FB20();
extern s16 D_0028E010;
extern s16 D_0028E020;
extern u16 D_0028E060;
extern u16 D_0028E064;
extern u16 D_0028E070;
extern s32 D_0029CD84[];
extern s16 D_0029F1F0[];
extern u8 D_0029F1F1[];
void func_0013E850(void) {
    u16 temp_a0;

    if (D_0029F1F0[0] < 0) {
        func_0013FB20();
        D_0028E020 = 0;
        D_0028E010 = 0;
        if (!(D_0029F1F1[0] & 0x40) && (D_0029CD84[0] != 0)) {
            temp_a0 = D_0028E070;
            if (temp_a0 != 8) {
                D_0028E070 = temp_a0 + 4;
                func_0013E970(temp_a0);
                D_0028E060 -= 1;
                D_0028E064 = D_0028E060;
            }
        }
    }
}
