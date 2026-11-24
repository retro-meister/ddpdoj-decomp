#include "common.h"

extern s16 *reg_a4;
void func_001CE800(void);

void func_001CE7F0(void) {
    reg_a4[1] = 0;
    func_001CE800();
}
