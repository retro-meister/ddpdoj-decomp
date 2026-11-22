#include "common.h"

extern u8 D_0028E1E4[];
extern u8 D_0028E1EC;
extern u8 D_0028E39C;

void func_0012FFE0(void) {
    reg_d0.b[0] = D_0028E39C;
    if (reg_d0.b[0] == 0x12) {
        reg_d0.w = 0;
        reg_d1.w = 0;
    } else if (reg_d0.b[0] == 0x11) {
        reg_d0.w = 0;
        reg_d1.w = 0;
        reg_d0.b[0] = D_0028E1E4[1];
        reg_d1.b[0] = D_0028E1E4[0];
    } else {
        reg_d0.w = 0;
        reg_d1.w = 0;
        reg_d0.b[0] = D_0028E1EC;
        reg_d1.b[0] = D_0028E1E4[0];
    }
}
