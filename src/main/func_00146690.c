#include "common.h"

s32 func_0019D5C0();
extern u16 D_0028E3EC;
extern u16 D_0028E928;
extern u8 *reg_a6;

void func_00146690(u16 arg0) {
    u16 var_a0;

    var_a0 = arg0;
    if (D_0028E928 == 0) {
        reg_d2.w = 0;
        if ((*(u16 *)((u8 *)(reg_a6) + (0x1A))) != 0) {
            reg_d2.w = 1;
        }
        var_a0 = D_0028E3EC;
        if (var_a0 != reg_d2.h[0]) {
            goto block_4;
        }
    } else {
block_4:
        func_0019D5C0();
    }
}
