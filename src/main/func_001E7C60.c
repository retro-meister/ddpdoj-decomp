#include "common.h"

s32 func_001E7C90();                            /* extern */
extern u8 *reg_a6;

void func_001E7C60(void) {
    if ((*(u16 *)((u8 *)(reg_a6) + (0x166))) == 0) {
        func_001E7C90();
    }
}
