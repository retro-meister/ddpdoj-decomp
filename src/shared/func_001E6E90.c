#include "common.h"

s32 func_001E6EF0();
s32 func_002011D0();
extern u8 *reg_a4;

void func_001E6E90(void) {
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0;
    (*(u8 *)((u8 *)(reg_a4) + (7))) = 1U;
    func_002011D0();
    if (reg_d0.h[0] != 0) {
        func_001E6EF0();
        return;
    }
    (*(u8 *)((u8 *)(reg_a4) + (7))) *= -1;
    func_001E6EF0();
}
