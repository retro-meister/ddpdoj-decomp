#include "common.h"

s32 func_0014E290();                           /* extern */
s32 func_00203060();                            /* extern */
extern s8 D_0028E408;
extern u8 *reg_a5;

void func_00171430(void) {
    func_00203060();
    if (D_0028E408 != 0) {
        if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
            func_0014E290();
            D_0028E408 = 1;
            return;
        }
        goto block_4;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_4:
    D_0028E408 = 0;
}
