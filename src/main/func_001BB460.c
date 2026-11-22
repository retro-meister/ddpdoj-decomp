#include "common.h"

extern s16 *work_reg_a4;
extern u8 *D_0028E450;
extern void func_001BAEC0(void);

void func_001BB460(void) {
    u8 value;

    *work_reg_a4 = 0;
    value = D_0028E450[0x1B];
    ((u8 *)work_reg_a4)[3] = value;
    func_001BAEC0();
}
