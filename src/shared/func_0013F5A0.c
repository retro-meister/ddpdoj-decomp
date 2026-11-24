#include "common.h"

extern s32 reg_a1_as_s32;
extern s32 reg_a0_as_s32;
extern s32 D_0029CDE0[];
extern s32 D_0029CE60[];

void func_0013F5C0(void);

void func_0013F5A0(void) {
    reg_a0_as_s32 = (s32)&D_0029CE60[0];
    reg_a1_as_s32 = (s32)&D_0029CDE0[0];
    func_0013F5C0();
}
