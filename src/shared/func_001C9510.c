#include "common.h"

s32 func_001C9570();
extern u8 D_0026C810[];
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_001C9510(void) {
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0;
    (*(s8 *)((u8 *)(reg_a4) + (2))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x20;
    reg_tmp.w = (u32) D_0026C810;
    (*(u16 *)((u8 *)(reg_a5) + (8))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0xA))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a4) + (0xC))) = 1;
    func_001C9570();
}
