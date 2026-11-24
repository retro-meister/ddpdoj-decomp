#include "common.h"

extern u8 *reg_a4;
void func_001D74B0(void);

void func_001D74A0(void) {
    *(s16 *)(reg_a4 + 2) = 1;
    func_001D74B0();
}
