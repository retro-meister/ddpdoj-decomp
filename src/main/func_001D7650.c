#include "common.h"

extern s16 *work_reg_a4;

void func_001D7660(void);

void func_001D7650(void) {
    work_reg_a4[1] = 1;
    func_001D7660();
}
