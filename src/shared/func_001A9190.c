#include "common.h"

extern void *reg_a0;
extern s32 D_0028E71C;

void func_001A97F0(void);

void func_001A9190(void) {
    reg_a0 = &D_0028E71C;
    func_001A97F0();
}
