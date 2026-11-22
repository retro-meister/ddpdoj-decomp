#include "common.h"

extern s16 *work_reg_a4;
extern s16 *D_0028E454;
void func_001F1E20(s32 arg0, s32 arg1);

void func_001F1DF0(void) {
    work_reg_a4[1] = 1;
    work_reg_a4[2] = 0x80;
    D_0028E454[13] = 0x6270;
    func_001F1E20(0x80, 1);
}
