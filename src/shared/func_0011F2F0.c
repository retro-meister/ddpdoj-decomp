#include "common.h"

s32 func_00171330(s32 *);
s32 func_001713A0();
s32 func_00201B80();
extern u8 D_0028E290;
extern u8 D_0028E2C8;
extern u8 D_0028ED80;
extern void func_0019C4B0();
extern u8 *reg_a6;

void func_0011F2F0(void) {
    if (((D_0028ED80 != 0) && (D_0028E2C8 != 0)) || (D_0028E290 == 2)) {
        func_001713A0();
        return;
    }
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    if ((s16) reg_d0.h[0] < -0x2400) {
        func_001713A0();
        return;
    }
    func_00201B80();
    func_00171330((void *)func_0019C4B0);
}
