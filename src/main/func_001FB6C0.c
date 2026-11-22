#include "common.h"

extern u8 *D_0028E450;

void func_001FB6C0(void) {
    *(u16 *)(D_0028E450 + 0x86) = 0xFFFF;
    *(u16 *)(D_0028E450 + 0x88) = 0;
}
