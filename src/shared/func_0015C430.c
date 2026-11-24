#include "common.h"

#ifdef DEATH_LABEL
void func_00137AD0(void);
extern u8 D_0028E380;
extern u8 death_D_002901F0[];
extern u8 *reg_a0;
#endif

void func_0015C430(void) {
#ifdef DEATH_LABEL
    reg_d0.w = 0;
    reg_a0 = death_D_002901F0;
    reg_d0.b[0] = D_0028E380;
    reg_d0.w += reg_d0.w;
    reg_d0.w += reg_d0.w;
    reg_a0 = *(u8 **)(reg_a0 + reg_d0.h[0]);
    reg_d1.h[0] = 0xC;
    reg_d0.h[0] = 0;
    reg_d2.h[0] = 0;
    func_00137AD0();
#endif
}
