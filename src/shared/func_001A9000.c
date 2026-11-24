#include "common.h"

s32 func_001A97F0();
s32 func_001A9D80();
s32 func_001AA0D0();
s32 func_001AA380();
extern u16 D_0028E5F8;
extern u16 D_0028E5FC;
extern u8 D_0028E71C;
extern u8 D_0028E720;
extern u8 D_0028E855;
extern u16 D_0029CEA0[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001A9000(void) {
    if (!((*(u8 *)((u8 *)(reg_a6) + (1))) & 2)) {
        if ((D_0028E855 & 4) && (reg_d2.h[0] = D_0029CEA0[0], ((s16) reg_d2.h[0] < 0)) && (reg_d2.w & 1) && (reg_d0.w = 1, ((s8) reg_d2.b[0] >= 0))) {
            if (reg_d1.w & 0x10) {
                reg_d0.h[0] += D_0028E5FC;
                func_001AA0D0();
                goto block_7;
            }
        } else {
block_7:
            if (reg_d1.w & 0x10) {
                reg_d0.w = 1;
                reg_d0.h[0] += D_0028E5FC;
                if (reg_d1.w & 4) {
                    func_001A9D80();
                } else {
                    reg_a0 = &D_0028E720;
                    func_001A97F0();
                }
            }
        }
        if (reg_d1.w & 8) {
            reg_d0.w = 1;
            reg_d0.h[0] += D_0028E5F8;
            switch (reg_d1.w & 4) { case 0: break; default:
                func_001AA380();
                return;
            }
            reg_a0 = &D_0028E71C;
            func_001A97F0();
        }
    }
}
