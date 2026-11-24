#include "common.h"

extern u8 D_0028E1FC_as_u8;
extern u8 D_0028E200_as_u8;
extern u8 D_0028E204;
extern u8 D_0028E208;
extern s8 D_0028E408;

void func_00130110(void) {
    reg_d0.w = 0;
    if (D_0028E208 != 0) {
        D_0028E208 -= 1;
        reg_d0.h[0] |= 1;
    }
    if (D_0028E204 != 0) {
        D_0028E204 -= 1;
        reg_d0.h[0] |= 2;
    }
    if (D_0028E200_as_u8 != 0) {
        D_0028E200_as_u8 -= 1;
        reg_d0.h[0] |= 4;
    }
    if (D_0028E1FC_as_u8 != 0) {
        D_0028E1FC_as_u8 -= 1;
        reg_d0.h[0] |= 8;
    }
    if (reg_d0.h[0] != 0) {
        D_0028E408 = 1;
        return;
    }
    D_0028E408 = 0;
}
