#include "common.h"

extern s32 reg_d2;
extern volatile s32 D_0028E484;
extern s32 reg_d3;

void func_0012D980(void);

void func_0012D960(void) {
    s32 tmp;

    tmp = reg_d2;
    D_0028E484 = tmp;
    reg_d2 = reg_d3;
    reg_d3 = D_0028E484;
    func_0012D980();
}
