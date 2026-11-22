#include "common.h"

s32 func_002024F0();                            /* extern */
extern u8 *reg_a6;

void func_002024C0(void) {
    func_002024F0();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
}
