#include "common.h"

extern s32 D_0028E484;

extern void func_0012D9F0(void);

void func_0012D9D0(void) {
    D_0028E484 = reg_d2.sw;
    reg_d2.sw = reg_d3.sw;
    reg_d3.sw = D_0028E484;
    func_0012D9F0();
}
