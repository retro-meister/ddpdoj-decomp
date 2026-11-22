#include "common.h"

s32 enemy_end_task(u16);                        /* extern */
s32 func_0013A780();                            /* extern */
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001C4F70(void) {
    u16 temp_a0;

    reg_d0.h[0] = 3;
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a0;
    (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
    enemy_end_task(temp_a0);
}
