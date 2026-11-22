#include "common.h"

extern s8 D_0028E408;
extern u16 D_0028E95C;

void func_00131610(void) {
    if (D_0028E95C != 0) {
        D_0028E408 = 1;
        return;
    }
    D_0028E408 = 0;
}
