#include "common.h"


s32 func_0012DCD0();
extern u8 D_0024EF30[];
extern u16 D_00299762[];
extern u8 *reg_a1;
extern u8 *reg_a6;

void func_0012DE90(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    func_0012DCD0();
    (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xFE;
    reg_tmp.w = 0x140;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
    (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = 0x1A;
    reg_tmp.w = 0xFE00FF00;
    (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0xE))) = 0x208;
    reg_tmp.w = 0;
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_tmp.h[0];
}
