#include "common.h"

s32 func_001A34C0();                            /* extern */
extern u8 *reg_a4;

void func_001A3520(void) {
    u8 *temp_s0;

    temp_s0 = reg_a4;
    func_001A34C0();
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (2)));
    reg_a4 = temp_s0;
}
