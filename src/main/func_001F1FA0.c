#include "common.h"

s32 func_00124D90(s32, s32);            /* extern */
s32 func_001F1FE0();                            /* extern */
extern u8 *reg_a4;

void func_001F1FA0(void) {
    (*(s16 *)((u8 *)(reg_a4) + (2))) = 0xC0;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x303;
    reg_d0.w = 3;
    func_00124D90(0x303, 0xC0);
    func_001F1FE0();
}
