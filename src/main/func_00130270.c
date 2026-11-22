#include "common.h"

extern s32 reg_d3;

void func_00130280(void);

void func_00130270(void) {
    reg_d3 = 1;
    func_00130280();
}
