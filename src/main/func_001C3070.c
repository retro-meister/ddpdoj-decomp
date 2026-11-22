#include "common.h"

extern u8 *reg_a4;

void stage2_boss_attack11_update(void);

void func_001C3070(void) {
    reg_a4[3] = 0;
    stage2_boss_attack11_update();
}
