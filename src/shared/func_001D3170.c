#include "common.h"

s32 func_00124B20();                            /* extern */
s32 func_00125060();                            /* extern */
s32 func_001251C0();                            /* extern */
extern s8 D_0028E408;
extern s16 *reg_a4_as_s16_p;

void func_001D3170(void) {
    reg_d0.w = 4;
    func_00125060();
    if (D_0028E408 == 0) {
        reg_d0.w = 5;
        func_001251C0();
        reg_d0.w = 6;
        func_00124B20();
        *reg_a4_as_s16_p = 0;
    }
}
