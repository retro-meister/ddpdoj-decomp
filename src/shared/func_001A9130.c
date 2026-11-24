#include "common.h"

s32 func_001A97F0();                            /* extern */
extern s32 D_0028E71C;
extern s32 D_0028E720_as_s32;
extern s32 *reg_a0_as_s32_p;

void func_001A9130(void) {
    if (reg_d1.w & 0x10) {
        reg_a0_as_s32_p = &D_0028E720_as_s32;
        func_001A97F0();
    }
    if (reg_d1.w & 8) {
        reg_a0_as_s32_p = &D_0028E71C;
        func_001A97F0();
    }
}
