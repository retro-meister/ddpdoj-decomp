#include "common.h"

s32 func_001DA7D0(s32, s32);            /* extern */
extern s16 *reg_a4;
extern u8 *reg_a6;

void func_001DAC50(void) {
    if ((*(u8 *)((u8 *)(reg_a6) + (0x9E))) != 0) {
        *reg_a4 = 0;
        return;
    }
    func_001DA7D0(0xA2, -0x1C0);
}
