#include "common.h"

s32 func_0019FCE0();                            /* extern */
s32 func_0019FD30();                            /* extern */
extern s32 D_0029D730[];
extern s16 D_0029F180[];
extern s32 D_0029F260[];
extern s32 *reg_a2;
extern s32 *reg_a4;
extern s16 *reg_a6;

void func_0019FC70(void) {
    reg_a6 = D_0029F180;
    reg_a4 = D_0029F260;
    reg_a2 = D_0029D730;
    reg_d7.w = 1;
    if (*reg_a6 < 0) {
        func_0019FD30();
        return;
    }
    reg_d7.w = 0;
    func_0019FCE0();
}
