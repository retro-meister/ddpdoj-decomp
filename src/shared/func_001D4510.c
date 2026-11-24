#include "common.h"
extern u8 *reg_a6;
void func_001D4510(void) {
    u8 *p = reg_a6 + 0xAF; if (*p == 0) { *p = 1; return; }
}
