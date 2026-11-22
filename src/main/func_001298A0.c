#include "common.h"

extern s32 D_0028DEA4;
extern u32 D_0028DEA8;
extern s32 D_0028DEB0;
extern s32 D_0028DEB4;
extern s8 D_0028E408;
extern s32 reg_a1;
extern s32 reg_a0;
extern s32 reg_d7;

void func_001298A0(void) {
    D_0028E408 = 0;
    reg_d0.w = D_0028DEA8;
    reg_d7 = D_0028DEA4;
    reg_a0 = D_0028DEB4;
    reg_a1 = D_0028DEB0;
}
