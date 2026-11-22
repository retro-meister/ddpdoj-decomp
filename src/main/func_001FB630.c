#include "common.h"

extern u8 *D_0028E450;

void func_001FB630(void) {
    u8 *object = D_0028E450;

    if (*(u16 *)(object + 0x68) == 0) {
        *(u16 *)(object + 0x1A) = 0x480;
    }
}
