#include "common.h"

s32 func_00124B20();
s32 func_00124D80();
extern u8 *reg_a4;

void func_001C9480() {
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
        func_00124D80();
        if (reg_d0.h[0] == 5) {
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 1U;
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 1) {
        (*(u16 *)((u8 *)(reg_a4) + (4))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a4) + (4))) == 0) {
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
            reg_d0.w = 3;
            func_00124B20();
        }
    }
}
