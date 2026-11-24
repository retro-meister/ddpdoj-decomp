#include "common.h"

s32 func_00206D70();                            /* extern */
s32 func_002071C0();                            /* extern */
extern u8 D_0028E7B4;
extern u8 *reg_a0;

void func_00169640(void) {
    func_00206D70();
    reg_d0.h[0] = 9;
    func_002071C0();
    (*(u8 *)((u8 *)(reg_a0) + (5))) = (u8) D_0028E7B4;
}
