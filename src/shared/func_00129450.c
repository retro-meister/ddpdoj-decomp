#include "common.h"

void func_00129460(void);
#ifdef DEATH_LABEL
extern u8 death_D_00290854;
extern u8 death_D_0029085C;
extern s32 death_D_0029040C;
extern s32 death_D_00290410;
extern u8 death_D_006901D0[];
extern u8 *reg_a6;
#endif

void func_00129450(void) {
#ifdef DEATH_LABEL
    if (death_D_0029085C == 2) {
        if (death_D_00290854 != 0) {
            if (reg_a6 == death_D_006901D0) {
                death_D_0029040C += 1;
                if (death_D_0029040C & 1) {
                    return;
                }
            } else {
                death_D_00290410 += 1;
                if (!(death_D_00290410 & 1)) {
                    return;
                }
            }
        }
    } else {
        death_D_00290410 = 0;
        death_D_0029040C = 0;
    }
#endif
    func_00129460();
}
