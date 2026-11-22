#include "common.h"

s32 func_00124D90();                            /* extern */
extern u8 *reg_a4;

void func_001C9440(void) {
    reg_d0.w = 4;
    func_00124D90();
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x20;
}
