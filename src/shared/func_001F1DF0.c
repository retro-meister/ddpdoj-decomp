#include "common.h"

extern s16 *reg_a4;
extern s16 *reg_a5;
void func_001F1E20(s32 arg0, s32 arg1);

#ifdef DEATH_LABEL
extern s8 death_D_0029085C;
#endif

void func_001F1DF0(void) {
#ifdef DEATH_LABEL
    death_D_0029085C = 1;
#endif
    reg_a4[1] = 1;
    reg_a4[2] = 0x80;
    reg_a5[13] = 0x6270;
    func_001F1E20(0x80, 1);
}
