#include "common.h"

s32 func_00135100();                            /* extern */
s32 func_00207490();                            /* extern */
extern s32 D_0028E84C;
extern s32 *reg_a0;

void func_00134FB0(void) {
    func_00135100();
    reg_a0 = &D_0028E84C;
    func_00207490();
}
