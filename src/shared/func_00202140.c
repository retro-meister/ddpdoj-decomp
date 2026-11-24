#include "common.h"

s32 func_002021F0();                            /* extern */
s32 func_002032A0();                            /* extern */
extern s8 D_0028E408;
extern u8 *reg_a0;

void func_00202140(void) {
    func_002032A0();
    if (D_0028E408 == 0) {
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
        func_002021F0();
    }
}
