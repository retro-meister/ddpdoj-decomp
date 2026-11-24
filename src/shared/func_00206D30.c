#include "common.h"

extern void func_00206910(void);
extern u16 D_0028E220;

void func_00206D30(void) {
    u32 previous_value = D_0028E220;

    reg_d0.h[0] = 1;
    reg_d0.h[0] = ~(s16) reg_d0.h[0];
    D_0028E220 = (u16) (previous_value & (u16) reg_d0.h[0]);
    func_00206910();
}
