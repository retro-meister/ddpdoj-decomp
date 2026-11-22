#include "common.h"

s32 func_00122BE0();                            /* extern */
s32 func_00122C20();                            /* extern */
s32 func_00168BA0();                            /* extern */
extern s8 D_0028E2F4;
extern u8 D_0028E39C;
extern s8 D_0028E408;
extern u8 *reg_a5;

void func_00169410(void) {
    if ((*(u8 *)((u8 *)(reg_a5) + (2))) == 0) {
        (*(u8 *)((u8 *)(reg_a5) + (2))) = 1U;
        func_00122BE0();
    }
    func_00122C20();
    if (D_0028E408 == 0) {
        reg_d0.h[0] = 1;
        D_0028E2F4 = 0;
        if (D_0028E39C == 0x12) {
            reg_d0.h[0] = 3;
        }
        func_00168BA0();
    }
}
