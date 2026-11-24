#include "common.h"

s32 func_00124D90();
s32 func_001A3020();
extern u8 D_0025FA30[];
extern u8 *reg_a0;
extern u8 *reg_a4;

void func_001B9400() {
    (*(u16 *)((u8 *)(reg_a4) + (2))) -= 1;
    if ((s16) (*(u16 *)((u8 *)(reg_a4) + (2))) == 0) {
        reg_d0.w = 0;
        func_00124D90();
        reg_d0.h[0] = 0x13;
        reg_a0 = D_0025FA30;
        func_001A3020();
        (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
    }
}
