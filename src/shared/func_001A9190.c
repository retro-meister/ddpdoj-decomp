#include "common.h"

extern void *reg_a0_as_void_p;
extern s32 D_0028E71C;

void func_001A97F0(void);

void func_001A9190(void) {
    reg_a0_as_void_p = &D_0028E71C;
    func_001A97F0();
}
