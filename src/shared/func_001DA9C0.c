#include "common.h"

s32 func_001DAA00();
extern u8 *reg_a4;

void func_001DA9C0(void) {
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x303;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0x606;
    (*(s8 *)((u8 *)(reg_a4) + (0x11))) = 0;
    (*(s8 *)((u8 *)(reg_a4) + (0x10))) = 0;
    func_001DAA00();
}
