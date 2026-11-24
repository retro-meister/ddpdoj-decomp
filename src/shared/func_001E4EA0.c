#include "common.h"

s32 func_00124D90();                            /* extern */
s32 func_001E4EF0();                            /* extern */
extern u8 *reg_a4;

void func_001E4EA0(void) {
    reg_d0.w = 4;
    func_00124D90();
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 1;
    (*(s8 *)((u8 *)(reg_a4) + (2))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0;
    func_001E4EF0();
}
