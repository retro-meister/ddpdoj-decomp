#include "common.h"

s32 func_001A34C0();                            /* extern */
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_001A36E0(void) {
    (*(s8 *)((u8 *)(reg_a5) + (3))) = 1;
    (*(s8 *)((u8 *)(reg_a5) + (2))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (4))) = 0;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (6)));
    func_001A34C0();
    (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (2))) = 0;
}
