#include "common.h"

extern s32 reg_d7;
extern s32 reg_d6;

void func_001A8520(void);

void func_001A8510(void) {
    reg_d6 = 0;
    reg_d7 = 0;
    func_001A8520();
}
