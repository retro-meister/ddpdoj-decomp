#include "common.h"

extern s32 *reg_a1;
extern s32 *reg_a0;
extern s32 D_0028E72C;
extern s32 D_0028E734;
void func_001AAB90(void);

void func_001AAB50(void) {
    reg_a0 = &D_0028E734;
    reg_a1 = &D_0028E72C;
    func_001AAB90();
}
