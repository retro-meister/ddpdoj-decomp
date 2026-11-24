#include "common.h"

extern s8 D_0028E408;
extern u16 D_0028E7A0;

void func_001719B0(void) {
    if (D_0028E7A0 != 0) {
        D_0028E408 = 1;
        return;
    }
    D_0028E408 = 0;
}
