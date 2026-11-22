#include "common.h"

extern u8 *D_0028E450;

void func_001D4510(void) {
    u8 *flagPtr = D_0028E450 + 0xAF;

    if (*flagPtr == 0) {
        *flagPtr = 1;
    }
}
