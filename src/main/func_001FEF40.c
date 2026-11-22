#include "common.h"

extern u8 *D_0028E450;

void func_001FEF40(void) {
    if (*(u16 *)(D_0028E450 + 0x28) == 0) {
        *(u16 *)(D_0028E450 + 0x28) = 1;
        *(u16 *)(D_0028E450 + 0x1A) = 0x420;
    }
}
