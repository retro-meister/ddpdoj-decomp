#include "common.h"

extern void *reg_a0_as_void_p;
extern u8 D_0028E720;

void func_001A97F0(void);

void func_001A9180(void) {
    reg_a0_as_void_p = &D_0028E720;
    func_001A97F0();
}
