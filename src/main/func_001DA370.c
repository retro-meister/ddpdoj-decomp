#include "common.h"

s32 func_001DA3C0();
extern u8 *reg_a4;

void func_001DA370(void) {
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x404;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0x1040;
    (*(s16 *)((u8 *)(reg_a4) + (8))) = 0x10;
    (*(s16 *)((u8 *)(reg_a4) + (0xA))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (0xC))) = 5;
    (*(s8 *)((u8 *)(reg_a4) + (0x1F))) = 0;
    func_001DA3C0();
}
