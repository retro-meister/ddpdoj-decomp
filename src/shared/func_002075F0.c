#include "common.h"

extern s32 reg_a5_as_s32;
extern s32 reg_a0_as_s32;
extern void func_00207490(void);

void func_002075F0(void) {
    reg_a0_as_s32 = reg_a5_as_s32 + 0x4C;
    func_00207490();
}
