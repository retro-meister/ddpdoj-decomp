#include "common.h"

s32 func_001DB060();
extern s16 D_0028E85C_as_s16;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001DB000(void) {
    (*(s16 *)((u8 *)(reg_a4) + (2))) = 0x820;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0xC;
    (*(s8 *)((u8 *)(reg_a4) + (9))) = 3;
    (*(s8 *)((u8 *)(reg_a4) + (8))) = 0x48;
    D_0028E85C_as_s16 = 0;
    (*(s16 *)((u8 *)(reg_a4) + (0x10))) = 0x50;
    (*(s16 *)((u8 *)(reg_a6) + (0x19E))) = 0;
    func_001DB060();
}
