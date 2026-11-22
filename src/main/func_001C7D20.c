#include "common.h"

s32 func_00124D90();                            /* extern */
s32 func_001C7DA0(s32);                     /* extern */
s32 func_001CBBD0();                            /* extern */
s32 func_001CBC70();                            /* extern */
s32 func_001CBCA0();                            /* extern */
extern u8 *reg_a4;

void func_001C7D20(void) {
    reg_d0.w = 3;
    func_00124D90();
    reg_d0.h[0] = 0x100;
    func_001CBCA0();
    reg_d0.h[0] = 0;
    func_001CBC70();
    reg_d0.h[0] = 0x20;
    func_001CBC70();
    func_001CBBD0();
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x10;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 4;
    (*(s16 *)((u8 *)(reg_a4) + (8))) = 0;
    func_001C7DA0(0x10);
}
