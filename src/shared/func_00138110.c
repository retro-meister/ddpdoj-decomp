#include "common.h"

extern s32 D_0026A2A0[];
extern u8 D_0028DAB8[];
extern u8 D_0028E38C;
extern u16 D_0028E7F0;
extern s32 D_0028E7F4;
extern u8 *reg_a0;

#ifdef DEATH_LABEL
extern u16 D_0028E3C0;
#endif

void func_00138110(void) {
    reg_d0.w = 0;
    reg_d0.b[0] = D_0028E38C;
#ifdef DEATH_LABEL
    if (D_0028E3C0 != 0) {
        reg_d0.b[0] = 1;
    }
#endif
    reg_a0 = D_0028DAB8;
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    D_0028E7F0 = *(u16 *)reg_a0;
    D_0028E7F4 = D_0026A2A0[reg_d0.h[0] >> 1];
}
