#include "common.h"

s32 func_0014E370();
s32 func_002010A0();
extern u8 D_002636F0[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001D6C90(void) {
    reg_a0 = D_002636F0;
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    (*(u16 *)((u8 *)(reg_a6) + (0x1A))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
    func_002010A0();
    reg_d0.b[0] *= 2;
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) += reg_d0.b[0];
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 0x408U;
    (*(u16 *)((u8 *)(reg_a5) + (0x1A))) = 2U;
    (*(s16 *)((u8 *)(reg_a5) + (0x1E))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x20))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x22))) = 0x101;
    (*(s16 *)((u8 *)(reg_a5) + (0x24))) = 0;
    (*(s8 *)((u8 *)(reg_a5) + (0x27))) = 6;
    (*(s8 *)((u8 *)(reg_a5) + (0x17))) = 0;
}
