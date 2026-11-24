#include "common.h"

s32 func_00201D10();
extern u8 *reg_a2;

void func_00205320(void) {
    reg_d0.h[0] = *(u16 *)reg_a2;
    func_00201D10();
    *(u16 *)(reg_a2 + 4) += reg_d3.h[0];
    reg_d2.h[0] = reg_d5.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a2 + 4);
    reg_d0.h[0] -= reg_d2.h[0];
    if (0 > (s16)(reg_d0.h[0])) {
        reg_d0.h[0] *= 0xFFFF;
    }
    if ((s32) *(u16 *)(reg_a2 + 2) > (s32) reg_d0.h[0]) {
        *(u16 *)reg_a2 >>= 1;
        *(u16 *)(reg_a2 + 2) >>= 1;
        if ((s16) *(u16 *)(reg_a2 + 2) < 0x21) {
            *(u16 *)(reg_a2 + 4) = (u16) reg_d5.h[0];
            *(u16 *)(reg_a2 + 2) = 0U;
        }
    }
}
