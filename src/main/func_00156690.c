#include "common.h"

extern s32 D_0028E490;
extern u16 D_0028E910;

void func_00156690(void) {
    D_0028E490 = 0;
    if (D_0028E910 != 0) {
        D_0028E490 = 0x20000;
    }
}
