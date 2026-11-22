#include "common.h"

s32 func_002071C0();                            /* extern */
s32 func_00224A90();                            /* extern */
extern u8 *reg_a0;

void func_00131840(void) {
    func_00224A90();
    reg_d0.h[0] = 0x14;
    func_002071C0();
    (*(s8 *)((u8 *)(reg_a0) + (5))) = 1;
}
