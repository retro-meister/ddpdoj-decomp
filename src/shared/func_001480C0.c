#include "common.h"

s32 func_00146690();                            /* extern */
extern u16 D_0028E000;
extern u16 D_0028E004;
extern u8 *reg_a6;

void func_001480C0(void) {
    if ((*(u16 *)((u8 *)(reg_a6) + (0x1A))) != 0) {
        if (D_0028E004 != 0) {
            return;
        }
        goto block_4;
    }
    if (D_0028E000 == 0) {
block_4:
        func_00146690();
    }
}
