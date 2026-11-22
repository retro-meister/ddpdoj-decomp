#include "common.h"

extern s16 *work_reg_a4;
extern s16 *D_0028E450;
extern void func_001E88D0(void);

void func_001E88B0(void) {
    work_reg_a4[1] = 2;
    D_0028E450[0x94] = 0;
    func_001E88D0();
}
