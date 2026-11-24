#include "common.h"

extern u16 *reg_a4_as_u16_p;
extern u16 *reg_a6_as_u16_p;
void func_001CE070(s32 value);

void func_001CE040(void) {
    u16 flag = 0x8001;
    reg_a4_as_u16_p[1] = flag;
    reg_d0.w = 4;
    reg_a6_as_u16_p[21] = (u16) reg_d0.h[0];
    reg_a6_as_u16_p[37] = (u16) reg_d0.h[0];
    func_001CE070(flag);
}
