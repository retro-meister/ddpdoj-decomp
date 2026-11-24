#include "common.h"

extern s32 D_0028E484_as_s32;

void func_0012D980(void);

void func_0012D960(void) {
    u32 tmp;

    tmp = reg_d2.sw;
    D_0028E484_as_s32 = tmp;
    reg_d2.sw = reg_d3.sw;
    reg_d3.sw = D_0028E484_as_s32;
    func_0012D980();
}
