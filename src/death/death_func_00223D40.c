#include "common.h"

s32 func_001251C0();
s32 func_001F5630();
extern u16 D_0028E89C;
extern u8 *reg_a4;

void death_func_00223D40(void) {
    if ((*(u16 *)(reg_a4 + 2) != 0) && (D_0028E89C == 0)) {
        *(u16 *)(reg_a4 + 2) -= 1;
        if (*(u16 *)(reg_a4 + 2) == 0) {
            reg_d0.w = 0x1c;
            func_001251C0();
            reg_d0.w = 0x1d;
            func_001251C0();
            func_001F5630();
        }
    }
}
