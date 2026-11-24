#include "common.h"

s32 func_00134A70();                            /* extern */
s32 func_00134BA0();                            /* extern */
extern u8 *reg_a5;

void func_00134B70(void) {
    (*(s8 *)((u8 *)(reg_a5) + (3))) = 2;
    func_00134A70();
    func_00134BA0();
}
