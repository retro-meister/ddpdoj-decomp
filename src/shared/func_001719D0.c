#include "common.h"

s32 func_00171A30();                            /* extern */
s32 func_00171B90();                            /* extern */
extern u16 D_0028E79C_as_u16;
extern u16 D_0028E7A0_as_u16;
extern s32 D_002BB458[];
extern s32 D_002BB470_as_s32_a[];
extern s32 *reg_a4_as_s32_p;
extern s32 *reg_a6_as_s32_p;

void func_001719D0(void) {
    reg_a6_as_s32_p = D_002BB470_as_s32_a;
    reg_a4_as_s32_p = D_002BB458;
    if (D_0028E79C_as_u16 != 0) {
        func_00171A30();
        return;
    }
    if (D_0028E7A0_as_u16 != 0) {
        func_00171B90();
    }
}
