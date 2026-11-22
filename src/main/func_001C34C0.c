#include "common.h"

s32 func_001C3520();                            /* extern */
extern u16 D_0028E910;
extern u8 *reg_a4;

void func_001C34C0(void) {
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 4;
    if (D_0028E910 == 0) {
        func_001C3520();
        return;
    }
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 2;
    func_001C3520();
}
