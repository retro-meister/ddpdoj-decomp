#include "common.h"

extern void func_0012D9B0(void);
extern s32 D_0028E484;
extern s32 reg_d3;
extern s32 reg_d2;

void func_0012D990(void) {
    D_0028E484 = reg_d2;
    reg_d2 = reg_d3;
    reg_d3 = D_0028E484;
    func_0012D9B0();
}
