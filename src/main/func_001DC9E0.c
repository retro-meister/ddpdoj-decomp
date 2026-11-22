#include "common.h"

s32 func_0014E370();
extern u8 D_0026F0A0[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001DC9E0(void) {
    reg_a0 = D_0026F0A0;
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    (*(u16 *)((u8 *)(reg_a6) + (0x1A))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
    (*(s8 *)((u8 *)(reg_a5) + (0x17))) = 0;
    (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 0;
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 0U;
    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) (*(u16 *)((u8 *)(reg_a6) + (0x1A)));
    (*(s16 *)((u8 *)(reg_a5) + (0x1C))) = 0x804;
    (*(s16 *)((u8 *)(reg_a5) + (0x1E))) = 2;
    (*(s16 *)((u8 *)(reg_a5) + (0x20))) = 0;
}
