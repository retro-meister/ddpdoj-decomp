#include "common.h"

s32 func_0014E370();                            /* extern */
extern s32 D_0026E7A0[];
extern s32 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0014FAB0(void) {
    reg_a0 = D_0026E7A0;
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    (*(u16 *)((u8 *)(reg_a6) + (0x1A))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
    (*(u16 *)((u8 *)(reg_a5) + (0x24))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x1E)));
    (*(s16 *)((u8 *)(reg_a5) + (0x26))) = 0;
    (*(u16 *)((u8 *)(reg_a5) + (0x1E))) = 0x101U;
    (*(s16 *)((u8 *)(reg_a5) + (0x20))) = 0;
}
