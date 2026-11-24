#include "common.h"

extern s32 D_0028E77C;
extern s32 D_0028E780;
extern void *reg_a4_as_void_p;

void func_001A34C0(void) {
    reg_a4_as_void_p = &D_0028E780;
    if (reg_d0.b[0] != 0) {
        reg_a4_as_void_p = &D_0028E77C;
    }
}
