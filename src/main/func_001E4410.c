#include "common.h"

s32 func_0019BF80();                            /* extern */
extern u8 *reg_a5;
extern u32 reg_a6;

void func_001E4410(void) {
    reg_a6 += 0x20;
    func_0019BF80();
    reg_a6 += 0x20;
    func_0019BF80();
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (6)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (8)));
    reg_a6 = reg_tmp.w;
}
