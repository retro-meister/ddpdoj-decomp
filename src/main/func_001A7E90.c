#include "common.h"

s32 func_0013EA70();                            /* extern */
s32 func_001AA8F0();                            /* extern */
s32 func_001ABB80();                            /* extern */
extern s16 D_0028E58C;
extern u16 D_0028E5C8;
extern u16 D_0028E5D0;
extern u16 D_0028E5F4;
extern u16 D_0028E5FC;

void func_001A7E90(void) {
    if (D_0028E5FC != 0) {
        D_0028E58C = 0x48;
    }
    func_0013EA70();
    reg_d0.w = 0;
    D_0028E5FC = reg_d0.h[0];
    D_0028E5F4 = reg_d0.h[0];
    D_0028E5D0 = reg_d0.h[0];
    D_0028E5C8 = reg_d0.h[0];
    func_001AA8F0();
    func_001ABB80();
}
