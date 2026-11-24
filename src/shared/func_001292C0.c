#include "common.h"

s32 func_00129450();                            /* extern */
s32 func_00129460();                            /* extern */
extern u16 D_0028E910;

void func_001292C0(void) {
    if (D_0028E910 == 0) {
        func_00129460();
        return;
    }
    reg_d0.w += 0x40000;
    func_00129450();
    reg_d0.w += 0xFFFC0000;
}
