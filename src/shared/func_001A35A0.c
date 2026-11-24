#include "common.h"

s32 func_001A34C0();                            /* extern */
extern u8 *reg_a4;

void func_001A35A0(void) {
    u8 *temp_s0;

    temp_s0 = reg_a4;
    func_001A34C0();
    if ((*(u16 *)((u8 *)(reg_a4) + (2))) != 4) {
        (*(s16 *)((u8 *)(reg_a4) + (0))) = 1;
        (*(u16 *)((u8 *)(reg_a4) + (2))) = 4U;
    }
    reg_a4 = temp_s0;
}
