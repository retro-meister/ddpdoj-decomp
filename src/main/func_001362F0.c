#include "common.h"

s32 func_00136260();                            /* extern */
s32 func_00207490();                            /* extern */
extern s32 D_0028E848;
extern s32 D_0028E84C;
extern u16 D_0028E940;
extern s32 *reg_a0;

void func_001362F0(void) {
    reg_a0 = &D_0028E848;
    func_00207490();
    reg_a0 = &D_0028E84C;
    func_00207490();
    if (D_0028E940 != 0) {
        func_00136260();
    }
}
