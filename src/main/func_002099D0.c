#include "common.h"

extern s32 D_00268770[];
extern s32 *reg_a0;
void func_002092F0(void);

void func_002099D0(void) {
    reg_a0 = D_00268770;
    reg_d0.h[0] = 7;
    reg_d1.h[0] = 0x29;
    reg_d2.h[0] = reg_d7.h[0];
    func_002092F0();
}
