#include "common.h"

extern u16 D_0028E8A0;
extern u16 *reg_a6;
extern u16 D_0028E0E4[];
void func_001257B0(void) {
    if (D_0028E8A0 == 0) {
        reg_d0.h[0] = D_0028E0E4[0];
        reg_a6[1] += reg_d0.h[0];
    }
}
