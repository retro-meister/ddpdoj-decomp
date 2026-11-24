#include "common.h"

s32 func_00201D10();
extern u16 D_0028E3E0;
extern Reg32 D_0028E480;
extern u16 D_0028E8A0;
extern u8 *reg_a6;

void func_00125930(void) {
    if (D_0028E3E0 == 0) {
        if (D_0028E8A0 == 0) {
            *(u8 *)(reg_a6 + 0x1B) += 1;
        }
        reg_d0.w = 0;
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1B);
        reg_d1.w = 0x3F;
        reg_d1.b[0] &= *(u8 *)(reg_a6 + 0x1A);
        func_00201D10();
        *(u16 *)(reg_a6 + 0x20) = reg_d2.h[0];
        *(u16 *)(reg_a6 + 0x22) = reg_d3.h[0];
    }
    reg_d2.h[1] = *(u16 *)(reg_a6 + 0x20);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x22);
    *(u16 *)(reg_a6 + 4) += reg_d2.h[0];
    D_0028E480.w = reg_d2.w;
    reg_d2.h[1] = reg_d2.h[0];
    reg_d2.h[0] = D_0028E480.h[1];
    *(u16 *)(reg_a6 + 2) += reg_d2.h[0];
}
