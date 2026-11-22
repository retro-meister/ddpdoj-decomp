#include "common.h"

extern u8 *work_reg_a4;
void func_001F3700(void);

void func_001F36F0(void) {
    *(s16 *)(work_reg_a4 + 2) = 0x60;
    func_001F3700();
}
