#include "common.h"

extern u8 *D_0028E450;

void func_001F4050(s32 value);

void func_001F4030(void) {
    D_0028E450[0x1B] = 3;
    D_0028E450[0x1A] = 0x20;
    func_001F4050(3);
}
