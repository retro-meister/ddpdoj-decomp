#include "common.h"

s32 func_00124D90();                            /* extern */
s32 func_001251C0();                            /* extern */
s32 func_001D3270();                            /* extern */

void func_001D3230(void) {
    reg_d0.w = 3;
    func_00124D90();
    reg_d0.w = 3;
    func_001251C0();
    reg_d0.w = 4;
    func_001251C0();
    func_001D3270();
}
