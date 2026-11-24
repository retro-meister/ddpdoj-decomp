#include "common.h"

s32 func_0019C470();                            /* extern */
s32 func_0019C530();                            /* extern */
extern u8 *reg_a5;

void func_001FDBD0(void) {
    if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 0) {
        func_0019C470();
        return;
    }
    func_0019C530();
}
