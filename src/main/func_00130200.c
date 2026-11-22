#include "common.h"

extern u8 D_0028E1D8[];
extern u8 D_0028E1E4[];
extern u8 D_0028E39C;

void func_00130200(void) {
    reg_d0.b[0] = D_0028E39C;
    if (reg_d0.b[0] == 0x12) {
        reg_d0.w = 0;
        reg_d1.w = 0;
        return;
    }
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = D_0028E1E4[0];
    reg_d1.b[0] = D_0028E1D8[0];
}
