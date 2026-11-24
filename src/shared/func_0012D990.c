#include "common.h"

extern void func_0012D9B0(void);
extern s32 D_0028E484;

void func_0012D990(void) {
    D_0028E484 = reg_d2.sw;
    reg_d2.sw = reg_d3.sw;
    reg_d3.sw = D_0028E484;
    func_0012D9B0();
}
