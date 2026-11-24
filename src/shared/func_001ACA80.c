#include "common.h"

s32 func_0011C7C0();                            /* extern */
extern s8 D_0028E634;
extern u8 D_0028E635;
extern u8 D_0028E854;

void func_001ACA80(void) {
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0x1400;
    reg_d2.h[0] = 7;
    reg_d3.h[0] = 7;
    if ((D_0028E854 & 1) && (D_0028E634 >= 0)) {
        if (D_0028E635 & 0x10) {
            reg_d0.h[0] = 0xCC;
            reg_d1.h[0] = 0x1600;
            reg_d2.h[0] = 5;
            reg_d3.h[0] = 5;
            goto block_4;
        }
    } else {
block_4:
        func_0011C7C0();
    }
}
