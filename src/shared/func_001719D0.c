#include "common.h"

s32 func_00171A30();                            /* extern */
s32 func_00171B90();                            /* extern */
extern u16 D_0028E79C;
extern u16 D_0028E7A0;
extern s32 D_002BB458[];
extern s32 D_002BB470[];
extern s32 *reg_a4;
extern s32 *reg_a6;

void func_001719D0(void) {
    reg_a6 = D_002BB470;
    reg_a4 = D_002BB458;
    if (D_0028E79C != 0) {
        func_00171A30();
        return;
    }
    if (D_0028E7A0 != 0) {
        func_00171B90();
    }
}
