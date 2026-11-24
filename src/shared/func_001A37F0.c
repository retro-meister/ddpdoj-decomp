#include "common.h"

s32 func_001A34E0();
extern u8 *reg_a5;

void func_001A37F0() {
    if ((*(u8 *)((u8 *)(reg_a5) + (2))) == 0) {
        (*(u8 *)((u8 *)(reg_a5) + (2))) = 1U;
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (6)));
        func_001A34E0();
    }
}
