#include "common.h"

s32 func_00124D90();                            /* extern */
s32 func_00124F50();                            /* extern */
s32 func_001D28B0();                            /* extern */

void func_001D2880(void) {
    reg_d0.w = 0;
    func_00124D90();
    reg_d0.w = 7;
    func_00124F50();
    func_001D28B0();
}
