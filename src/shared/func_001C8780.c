#include "common.h"

s32 func_00124D90();                            /* extern */
s32 func_00124F50();                            /* extern */
s32 func_001C87E0(s32);                     /* extern */
extern u8 *reg_a4;

void func_001C8780(void) {
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0;
    reg_d0.w = 2;
    func_00124D90();
    reg_d0.w = 3;
    func_00124F50();
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x40;
    (*(s16 *)((u8 *)(reg_a4) + (8))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (0xA))) = 2;
    func_001C87E0(0x40);
}
