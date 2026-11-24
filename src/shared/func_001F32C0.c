#include "common.h"

extern s16 *reg_a4;
void func_001F32D0(void);

void func_001F32C0(void) {
    reg_a4[1] = 0x40;
    func_001F32D0();
}
