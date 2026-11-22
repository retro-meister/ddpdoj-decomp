#include "common.h"

extern u16 *work_reg_a4;

void func_001F3060(void);

void func_001F3050(void) {
    work_reg_a4[1] = 0x60;
    func_001F3060();
}
