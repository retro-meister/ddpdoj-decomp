#include "common.h"

s32 func_00124B20();                            /* extern */
s32 func_00125060();                            /* extern */
s32 func_00125250();                            /* extern */
extern s8 D_0028E408;
extern s16 *reg_a4;

void func_001D31D0(void) {
    reg_d0.w = 5;
    func_00125250();
    if (D_0028E408 == 0) {
        reg_d0.w = 5;
        func_00125060();
        if (D_0028E408 == 0) {
            reg_d0.w = 4;
            func_00124B20();
            *reg_a4 = 0;
        }
    }
}
