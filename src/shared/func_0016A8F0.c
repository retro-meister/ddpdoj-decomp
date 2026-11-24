#include "common.h"

extern u8 D_002BB4B0[];
extern u8 D_002BB6B0[];
extern u8 D_002BB730[];
extern u8 D_002BB7B0[];
extern u8 D_002BB930[];
extern u8 D_002BBAB0[];
extern u8 *reg_a0;

void func_0016A8F0(void) {
    if (reg_d0.h[0] == 0) {
        reg_a0 = (u8 *)D_002BB4B0;
        reg_d2.h[0] = 7;
        return;
    }
    if (reg_d0.h[0] == 4) {
        reg_a0 = (u8 *)D_002BB6B0;
        reg_d2.h[0] = 1;
        return;
    }
    if (reg_d0.h[0] == 8) {
        reg_a0 = (u8 *)D_002BB730;
        reg_d2.h[0] = 1;
        return;
    }
    if (reg_d0.h[0] == 12) {
        reg_a0 = (u8 *)D_002BB7B0;
        reg_d2.h[0] = 5;
        return;
    }
    if (reg_d0.h[0] == 20) {
        reg_a0 = (u8 *)D_002BB930;
        reg_d2.h[0] = 5;
        return;
    }
    reg_d2.h[0] = 0;
    reg_a0 = (u8 *)D_002BBAB0;
}
