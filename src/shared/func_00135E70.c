#include "common.h"

s32 func_0013F2A0();                            /* extern */
s32 func_0013F310();                            /* extern */
extern u8 *reg_a6;

void func_00135E70(void) {
    if ((*(u8 *)((u8 *)(reg_a6) + (0x16))) == 0) {
        func_0013F2A0();
    } else {
        func_0013F310();
    }
    (*(s16 *)((u8 *)(reg_a6) + (0))) = 0;
    (*(s16 *)((u8 *)(reg_a6) + (2))) = 0;
}
