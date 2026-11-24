#include "common.h"

extern void func_0014E2C0(void);
extern s32 reg_a6;
extern u8 *reg_a5;

void func_0014E260(void) {
    u8 *src = reg_a5;

    reg_tmp.h[1] = *(u16 *)(src + 6);
    reg_tmp.h[0] = *(u16 *)(src + 8);
    reg_d0.w = 0;
    reg_a6 = reg_tmp.sw;
    *(u16 *)&reg_d1 = *(u16 *)(src + 4);
    func_0014E2C0();
}
