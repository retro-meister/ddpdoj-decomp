#include "common.h"
#pragma opt_propagation off

extern u8 D_0028E2C0;
extern u16 D_0028E4A2;
extern u16 D_0028E4A6;
extern void *reg_a6;
extern void (*jtbl_0028E3F4)(void);

void func_00171330(void (*callback)(void))
{
    if (D_0028E2C0 == 0) {
        const u16 *state = (const u16 *)reg_a6;

        D_0028E4A6 = state[1];
        reg_d1.h[0] = state[2];
        reg_d3.h[0] = state[10];
        D_0028E4A2 = state[8];
        reg_d2.h[0] = state[9];
        reg_d4.w = 0;
        reg_d4.h[0] = state[6];
        jtbl_0028E3F4 = callback;
        jtbl_0028E3F4();
    }
}
