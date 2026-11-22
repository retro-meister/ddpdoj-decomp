#include "common.h"

s32 func_0014E290();
s32 func_0014E030();
extern u16 D_0028E894;
extern u16 D_0028E8A0;
extern s16 D_0028E8A8;
extern u8 *reg_a5;

void func_00157DC0() {
    if (D_0028E8A8 >= 0x9C) {
        func_0014E290();
        return;
    }
    if ((D_0028E8A0 == 0) && (D_0028E894 == 0)) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
        (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a5) + (0x19))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x18)));
            reg_d0.w = 0x3F;
            func_0014E030();
        }
    }
}
