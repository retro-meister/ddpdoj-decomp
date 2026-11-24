#include "common.h"

s32 func_0014D5D0();                            /* extern */
s32 func_0014DA80();                            /* extern */
extern s32 reg_a5_as_s32;

void func_0014DA50(void) {
    s32 temp_s0;

    temp_s0 = reg_a5_as_s32;
    func_0014D5D0();
    func_0014DA80();
    reg_a5_as_s32 = temp_s0;
}
