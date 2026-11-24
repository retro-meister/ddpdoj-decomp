#include "common.h"

extern s16 *reg_a4_as_s16_p;
extern s16 *reg_a5_as_s16_p;
void func_001F1E20(s32 arg0, s32 arg1);

#ifdef DEATH_LABEL
extern s8 death_D_0029085C_as_s8;
#endif

void func_001F1DF0(void) {
#ifdef DEATH_LABEL
    death_D_0029085C_as_s8 = 1;
#endif
    reg_a4_as_s16_p[1] = 1;
    reg_a4_as_s16_p[2] = 0x80;
    reg_a5_as_s16_p[13] = 0x6270;
    func_001F1E20(0x80, 1);
}
