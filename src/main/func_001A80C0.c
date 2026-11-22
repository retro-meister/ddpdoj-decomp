#include "common.h"

extern s32 reg_d7;
extern s32 reg_d6;

void func_001A80D0(void);

void func_001A80C0(void) {
    reg_d6 = 0;
    reg_d7 = 0;
    func_001A80D0();
}
