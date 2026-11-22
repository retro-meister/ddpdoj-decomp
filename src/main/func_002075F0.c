#include "common.h"

extern s32 reg_a5;
extern s32 reg_a0;
extern void func_00207490(void);

void func_002075F0(void) {
    reg_a0 = reg_a5 + 0x4C;
    func_00207490();
}
