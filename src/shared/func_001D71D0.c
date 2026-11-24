#include "common.h"

s32 func_00124DC0();                            /* extern */
s32 func_00124F00();                            /* extern */
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001D71D0(void) {
    (*(s16 *)((u8 *)(reg_a6) + (0x106))) = 0;
    reg_d0.w = 0;
    func_00124F00();
    reg_d0.w = 6;
    func_00124DC0();
    (*(s16 *)((u8 *)(reg_a4) + (2))) = 0x202;
}
