#include "common.h"

extern s16 *work_reg_a4;
extern u8 *D_0028E450;

void func_001CA370(void);

void func_001CA350(void) {
    *work_reg_a4 = 0;
    D_0028E450[0x1B] = 8;
    func_001CA370();
}
