#include "common.h"

s32 func_001A53E0();
extern u16 D_0028DAE0[];
extern u16 D_0028E910;
extern u8 *reg_a0;

void func_001A7C60(void) {
    reg_d2.h[0] = D_0028E910;
    reg_a0 = (u8 *) D_0028DAE0;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = *(u8 **) (reg_a0 + reg_d2.h[0]);
    reg_d6.h[0] += reg_d6.h[0];
    reg_d2.w = 0;
    reg_d2.h[0] = (reg_d6.h[0]) ? *(u16 *) (reg_a0 + ((s16) reg_d6.h[0] & ~1)) : *(u16 *) reg_a0;
    reg_d3.h[0] = 0x810;
    reg_d2.w += 0xD7D;
    func_001A53E0();
}
