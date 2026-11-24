#include "common.h"

extern s16 *reg_a4_as_s16_p;

void func_001D7660(void);

void func_001D7650(void) {
    reg_a4_as_s16_p[1] = 1;
    func_001D7660();
}
