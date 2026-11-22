#include "common.h"

s32 enemy_end_task();
s32 func_001D2550();
extern u8 *reg_a6;

void func_001D24D0(void) {
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
    reg_tmp.w += 1;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x10))) -= 1;
    if ((*(u16 *)((u8 *)(reg_a6) + (0x10))) != 0) {
        func_001D2550();
        return;
    }
    enemy_end_task();
}
