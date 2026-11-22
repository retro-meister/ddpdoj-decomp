#include "common.h"

s32 func_00171330(s32 *);
s32 func_001713A0();
s32 func_00201B80();
extern void func_0019C4F0();
extern u8 *reg_a6;

void func_0011D390(void) {
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    if ((s16) reg_d0.h[0] < -0x3BFF) {
        func_001713A0();
        return;
    }
    func_00201B80();
    func_00171330((void *)func_0019C4F0);
}
