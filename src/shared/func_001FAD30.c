#include "common.h"

s32 func_001FADE0();                            /* extern */
s32 func_001FB010();                            /* extern */
s32 func_001FB1F0();                            /* extern */
s32 func_001FB630();                            /* extern */
s32 func_001FB650();                            /* extern */
s32 func_00201F20();                            /* extern */
extern u8 *reg_a6;

void func_001FAD30(void) {
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x66)));
    switch (reg_d0.h[0]) {                          /* irregular */
    case 0:
        func_001FADE0();
        break;
    case 1:
        func_001FB010();
        break;
    case 2:
        func_001FB1F0();
        break;
    case 3:
        func_001FB630();
        break;
    case 4:
        func_001FB650();
        break;
    }
    func_00201F20();
}
