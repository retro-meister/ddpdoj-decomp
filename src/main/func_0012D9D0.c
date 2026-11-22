#include "common.h"

extern s32 D_0028E484;
extern s32 D_0028E49C;
extern s32 bcd_result;

extern void func_0012D9F0(void);

void func_0012D9D0(void) {
    D_0028E484 = bcd_result;
    bcd_result = D_0028E49C;
    D_0028E49C = D_0028E484;
    func_0012D9F0();
}
