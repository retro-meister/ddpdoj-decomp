#include "common.h"

s32 func_0018DEE0();
extern s16 D_0028DFC4_as_s16;
extern s16 D_0029F1F0[];
extern u8 D_0029F22F[];
extern s16 D_0029F260[];
extern u8 D_0029F29F[];
void func_00203460(void) {
    func_0018DEE0();
    D_0028DFC4_as_s16 = 1;
    if (D_0029F260[0] < 0) {
        D_0029F29F[0] = 0xFF;
    }
    if (D_0029F1F0[0] < 0) {
        D_0029F22F[0] = 0xFF;
    }
}
