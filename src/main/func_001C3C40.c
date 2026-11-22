#include "common.h"

s32 func_00171400();                            /* extern */
s32 func_001C3C80();                            /* extern */
extern u8 *reg_a4;

void func_001C3C40(void) {
    func_00171400();
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0;
    func_001C3C80();
}
