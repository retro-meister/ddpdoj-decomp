#include "common.h"

s32 func_00124D90(s32, s32);            /* extern */
s32 func_001F34A0();                            /* extern */
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001F3450(void) {
    (*(s16 *)((u8 *)(reg_a4) + (2))) = 0x60;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x40;
    reg_d0.w = 7;
    func_00124D90(0x40, 0x60);
    (*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 0xC;
    func_001F34A0();
}
