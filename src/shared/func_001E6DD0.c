#include "common.h"

extern s16 *reg_a4_as_s16_p;

void func_001E6DF0(void);

void func_001E6DD0(void) {
    reg_a4_as_s16_p[1] = 3;
    reg_a4_as_s16_p[2] = 0;
    func_001E6DF0();
}
