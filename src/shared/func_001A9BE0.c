#include "common.h"

s32 func_001ABF90();
extern u16 D_0028E5E4;
extern u16 D_0028E5FC;
extern u16 D_0028E60C;
extern u8 D_0028ED80;

void func_001A9BE0(void) {
    D_0028E60C -= 1;
    if ((s16) D_0028E60C < 0) {
        reg_d2.w = 4;
        if (D_0028E5FC != 0) {
            reg_d2.w = 0x30;
        }
        if (D_0028ED80 != 0) {
            D_0028E5E4 += reg_d2.h[0];
        } else {
            D_0028E5E4 += reg_d2.h[0];
        }
        func_001ABF90();
        reg_d2.w = 8;
        D_0028E60C = reg_d2.h[0];
    }
}
