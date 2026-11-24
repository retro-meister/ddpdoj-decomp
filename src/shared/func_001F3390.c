#include "common.h"

s32 func_00124D90(s32);                     /* extern */
s32 func_001F33D0();                            /* extern */
extern u8 *reg_a4;

void func_001F3390(void) {
    (*(s16 *)((u8 *)(reg_a4) + (2))) = 0x50;
    reg_d0.w = 6;
    func_00124D90(0x50);
    func_001F33D0();
}
