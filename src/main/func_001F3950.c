#include "common.h"

s32 func_001251C0();
s32 func_001F5630();
extern u16 D_0028E89C;
extern u8 *reg_a4;

void func_001F3950() {
    u16 temp_a0;

    temp_a0 = (*(u16 *)((u8 *)(reg_a4) + (2)));
    if ((temp_a0 != 0) && (D_0028E89C == 0)) {
        (*(u16 *)((u8 *)(reg_a4) + (2))) = (u16) (temp_a0 - 1);
        if ((*(u16 *)((u8 *)(reg_a4) + (2))) == 0) {
            reg_d0.w = 0xD;
            func_001251C0();
            func_001F5630();
        }
    }
}
