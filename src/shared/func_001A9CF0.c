#include "common.h"

s32 func_001AC160();
extern u16 D_0028E5E0;
extern u16 D_0028E5F8;
extern u16 D_0028E608;
extern u8 D_0028ED80;

void func_001A9CF0(void) {
    D_0028E608 -= 1;
    if ((s16) D_0028E608 < 0) {
        reg_d2.w = 4;
        if (D_0028E5F8 != 0) {
            reg_d2.w = 0x30;
        }
        if (D_0028ED80 != 0) {
            D_0028E5E0 += reg_d2.h[0];
        } else {
            D_0028E5E0 += reg_d2.h[0];
        }
        func_001AC160();
        reg_d2.w = 8;
        D_0028E608 = reg_d2.h[0];
    }
}
