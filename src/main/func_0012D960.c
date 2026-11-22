#include "common.h"

extern s32 bcd_result;
extern volatile s32 D_0028E484;
extern s32 D_0028E49C;

void func_0012D980(void);

void func_0012D960(void) {
    s32 tmp;

    tmp = bcd_result;
    D_0028E484 = tmp;
    bcd_result = D_0028E49C;
    D_0028E49C = D_0028E484;
    func_0012D980();
}
