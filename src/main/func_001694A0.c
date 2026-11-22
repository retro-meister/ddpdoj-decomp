#include "common.h"

s32 func_0012F6A0();                            /* extern */
s32 func_0012F7D0();                            /* extern */
s32 func_00168BA0();                            /* extern */
extern s8 D_0028E408;
extern u8 *reg_a5;

void func_001694A0(void) {
    if ((*(u8 *)((u8 *)(reg_a5) + (2))) == 0) {
        (*(u8 *)((u8 *)(reg_a5) + (2))) = 1U;
        func_0012F6A0();
    }
    func_0012F7D0();
    if (D_0028E408 == 0) {
        reg_d0.h[0] = 9;
        func_00168BA0();
    }
}
