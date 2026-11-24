#include "common.h"

extern s16 *reg_a4;

void func_001E6DF0(void);

void func_001E6DD0(void) {
    reg_a4[1] = 3;
    reg_a4[2] = 0;
    func_001E6DF0();
}
