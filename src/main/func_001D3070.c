#include "common.h"

s32 func_00124D90();                            /* extern */
s32 func_001251C0();                            /* extern */
s32 func_001D30B0();                            /* extern */

void func_001D3070(void) {
    reg_d0.w = 1;
    func_00124D90();
    reg_d0.w = 6;
    func_001251C0();
    reg_d0.w = 7;
    func_001251C0();
    func_001D30B0();
}
