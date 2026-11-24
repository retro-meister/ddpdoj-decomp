#include "common.h"

s32 func_001A34C0();                            /* extern */
extern u8 *reg_a4;

void func_001A35F0(void) {
    u8 *temp_s0;

    temp_s0 = reg_a4;
    func_001A34C0();
    (*(s16 *)((u8 *)(reg_a4) + (0))) = 1;
    (*(s16 *)((u8 *)(reg_a4) + (2))) = 8;
    reg_a4 = temp_s0;
}
