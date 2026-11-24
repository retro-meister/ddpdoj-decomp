#include "common.h"

s32 func_0014E370();                            /* extern */
extern s32 D_0026C570[];
extern s32 *reg_a0_as_s32_p;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001C45B0(void) {
    reg_a0_as_s32_p = D_0026C570;
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    (*(u16 *)((u8 *)(reg_a6) + (0x1A))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
    (*(s8 *)((u8 *)(reg_a5) + (0x17))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x1E))) = 2;
    (*(s16 *)((u8 *)(reg_a5) + (0x20))) = 0;
    (*(s8 *)((u8 *)(reg_a5) + (0x23))) = 0;
    (*(s8 *)((u8 *)(reg_a5) + (0x22))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x24))) = 2;
    (*(s16 *)((u8 *)(reg_a5) + (0x26))) = 0x505;
    (*(s8 *)((u8 *)(reg_a5) + (0x2B))) = 0;
}
