#include "common.h"

extern u8 *reg_a4;

void func_001C91D0(s32 length);

void func_001C91A0(void) {
    reg_a4[3] = 0;
    *(s16 *)(reg_a4 + 4) = 0x60;
    *(s16 *)(reg_a4 + 6) = 0;
    *(s16 *)(reg_a4 + 8) = 8;
    func_001C91D0(0x60);
}
