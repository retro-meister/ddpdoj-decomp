#include "common.h"

s32 func_0012FAB0();                            /* extern */
s32 func_001A2FA0();                            /* extern */
s32 func_00206D70();                            /* extern */
s32 func_002071C0();                            /* extern */
extern s32 D_00269140[];
extern s8 D_0028E290;
extern s32 *reg_a0;

void func_00169900(void) {
    D_0028E290 = 2;
    func_00206D70();
    func_0012FAB0();
    reg_d0.w = 0;
    reg_a0 = D_00269140;
    func_001A2FA0();
    reg_d0.h[0] = 0x15;
    func_002071C0();
}
