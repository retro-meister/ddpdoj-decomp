#include "common.h"

extern volatile s32 D_0028E484;

void func_0012D980(void);

void func_0012D960(void) {
    s32 tmp;

    tmp = reg_d2.sw;
    D_0028E484 = tmp;
    reg_d2.sw = reg_d3.sw;
    reg_d3.sw = D_0028E484;
    func_0012D980();
}
