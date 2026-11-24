#include "common.h"

s32 func_00144690();
extern u8 *reg_a6;

void func_00144AD0(void) {
    func_00144690();
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x42)));
    (*(u16 *)((u8 *)(reg_a6) + (0x42))) -= 4;
    if ((s32) reg_tmp.h[0] < 4) {
        (*(u16 *)((u8 *)(reg_a6) + (0x42))) = 8U;
    }
}
