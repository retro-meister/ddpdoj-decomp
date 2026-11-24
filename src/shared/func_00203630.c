#include "common.h"

s32 func_002071C0();                            /* extern */
extern u8 *reg_a0;

void func_00203630(void) {
    reg_d0.h[0] = 6;
    func_002071C0();
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) reg_d7.h[0];
}
