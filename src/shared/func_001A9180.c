#include "common.h"

extern void *reg_a0;
extern u8 D_0028E720;

void func_001A97F0(void);

void func_001A9180(void) {
    reg_a0 = &D_0028E720;
    func_001A97F0();
}
