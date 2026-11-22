#include "common.h"


s32 func_00125310();
s32 func_001CA090();
s32 func_002012F0();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001C9FC0(void) {
    u16 temp_a0;

    reg_d0.w = 2;
    func_00125310();
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 2;
    (*(s16 *)((u8 *)(reg_a4) + (0xC))) = 0;
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.h[0] = temp_a0;
    (*(u16 *)((u8 *)(reg_a4) + (4))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a4) + (6))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (8))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) = (u16) reg_d0.h[0];
    func_002012F0();
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
    (*(u16 *)((u8 *)(reg_a4) + (8))) += reg_d0.h[0];
    func_002012F0();
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) += reg_d0.h[0];
    func_001CA090();
}
