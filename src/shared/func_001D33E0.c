#include "common.h"

s32 func_00124D90(s32);                     /* extern */
s32 func_001D3420();                            /* extern */
extern u8 *reg_a4;

void func_001D33E0(void) {
    (*(s16 *)((u8 *)(reg_a4) + (2))) = 0x80;
    reg_d0.w = 1;
    func_00124D90(0x80);
    func_001D3420();
}
