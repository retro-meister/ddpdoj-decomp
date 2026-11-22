#include "common.h"

extern s32 D_00268770[];
extern s32 *reg_a0;
extern u16 reg_d7;
extern u16 reg_d2;
void func_002092F0(void);

void func_002099D0(void) {
    reg_a0 = D_00268770;
    reg_d0.h[0] = 7;
    reg_d1.h[0] = 0x29;
    reg_d2 = reg_d7;
    func_002092F0();
}
