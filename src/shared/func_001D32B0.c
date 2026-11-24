#include "common.h"

s32 func_00124F50();                            /* extern */
s32 func_001D32E0();                            /* extern */
extern u8 *reg_a0;

void func_001D32B0(void) {
    reg_d0.w = 4;
    func_00124F50();
    (*(s16 *)((u8 *)(reg_a0) + (2))) = 0x5001;
    func_001D32E0();
}
