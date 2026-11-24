#include "common.h"

extern s8 D_0028E408;
extern u16 D_0028E850;
extern s16 D_0028E924_as_s16;

void func_001351F0(void) {
    if ((D_0028E850 == 0) && (D_0028E924_as_s16 == -1)) {
        D_0028E408 = 1;
        return;
    }
    D_0028E408 = 0;
}
