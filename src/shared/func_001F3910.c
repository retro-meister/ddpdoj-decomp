#include "common.h"

s32 func_00124D90(s32);                     /* extern */
s32 func_001F3950();                            /* extern */
extern u8 *reg_a4;

void func_001F3910(void) {
    (*(s16 *)((u8 *)(reg_a4) + (2))) = 0x60;
    reg_d0.w = MAIN_OR_DEATH_LABEL(0xB, 0x10);
    func_00124D90(0x60);
    func_001F3950();
}
