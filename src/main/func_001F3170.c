#include "common.h"

extern void *work_reg_a4;
void func_001F3190(s32 value);

void func_001F3170(void) {
    ((s16 *)work_reg_a4)[1] = 0x60;
    ((s16 *)work_reg_a4)[2] = 0x40;
    func_001F3190(0x60);
}
