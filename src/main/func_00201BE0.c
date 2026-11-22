#include "common.h"

extern u16 D_0028E0E4[];
extern u16 D_0028E0E6[];
extern u16 D_0028E8A0;

void func_00201BE0(void) {
    if (D_0028E8A0 == 0) {
        reg_d2.h[0] = D_0028E0E4[0];
        reg_d3.h[0] = D_0028E0E6[0];
        return;
    }
    reg_d2.w = 0;
    reg_d3.w = 0;
}
