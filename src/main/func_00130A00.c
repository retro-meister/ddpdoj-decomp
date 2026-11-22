#include "common.h"

extern u16 D_0028E1C4[];
extern u16 D_0028E1CC[];

void func_00130A00(void) {
    reg_d1.w = 0;
    if (D_0028E1CC[0] == 0x80) {
        D_0028E1CC[0] = 0;
        reg_d1.h[0] |= 1;
    }
    if (D_0028E1C4[0] == 0x80) {
        D_0028E1C4[0] = 0;
        reg_d1.h[0] |= 2;
    }
}
