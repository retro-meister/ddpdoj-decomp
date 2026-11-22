#include "common.h"

s32 func_00134260();                            /* extern */
s32 func_002075F0();                            /* extern */
extern u8 *reg_a5;

void func_00134BA0(void) {
    reg_d1.w = 0;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (6)));
    func_00134260();
    func_002075F0();
}
