#include "common.h"

s32 func_0014E370();                            /* extern */
extern s32 D_0026C5F0[];
extern s32 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001C4FD0(void) {
    reg_a0 = D_0026C5F0;
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    (*(s8 *)((u8 *)(reg_a5) + (0x17))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x1E))) = 0x202;
    (*(s16 *)((u8 *)(reg_a5) + (0x20))) = 0;
}
