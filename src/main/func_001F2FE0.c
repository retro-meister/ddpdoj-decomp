#include "common.h"

s32 func_00124F50();                            /* extern */
s32 func_001251C0();                            /* extern */
s32 func_001F3010();                            /* extern */

void func_001F2FE0(void) {
    reg_d0.w = 2;
    func_00124F50();
    reg_d0.w = 0;
    func_001251C0();
    func_001F3010();
}
