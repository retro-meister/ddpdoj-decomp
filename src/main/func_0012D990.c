#include "common.h"

extern void func_0012D9B0(void);
extern s32 D_0028E484;
extern s32 D_0028E49C;
extern s32 bcd_result;

void func_0012D990(void) {
    D_0028E484 = bcd_result;
    bcd_result = D_0028E49C;
    D_0028E49C = D_0028E484;
    func_0012D9B0();
}
