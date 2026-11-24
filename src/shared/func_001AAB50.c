#include "common.h"

extern s32 *reg_a1_as_s32_p;
extern s32 *reg_a0_as_s32_p;
extern s32 D_0028E72C_as_s32;
extern s32 D_0028E734;
void func_001AAB90(void);

void func_001AAB50(void) {
    reg_a0_as_s32_p = &D_0028E734;
    reg_a1_as_s32_p = &D_0028E72C_as_s32;
    func_001AAB90();
}
