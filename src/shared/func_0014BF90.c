#include "common.h"

s32 func_001353E0();
s32 func_0013B190();
s32 func_002071C0();
s32 func_002075F0();
extern u8 *reg_a5;

void func_0014BF90() {
    (*(u16 *)((u8 *)(reg_a5) + (0x1C))) -= 1;
    if ((*(u16 *)((u8 *)(reg_a5) + (0x1C))) == 0) {
        reg_d0.w = 0;
        reg_d1.h[0] = 6;
        func_001353E0();
        func_0013B190();
        reg_d0.h[0] = 0xC;
        func_002071C0();
        func_002075F0();
    }
}
