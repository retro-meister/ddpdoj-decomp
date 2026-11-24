#include "common.h"


s32 func_0012D7C0();
s32 func_0012DCD0();
extern u8 D_0024ED80[];
extern u8 D_0024EF30[];
extern u16 D_00299762[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a6;

void func_0012E2B0(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    func_0012DCD0();
    (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = 0x1A;
    reg_tmp.w = 3;
    (*(u16 *)((u8 *)(reg_a6) + (0x14))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x16))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0x18))) = 0x101;
    reg_tmp.w = 7;
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_tmp.h[0];
    reg_a0 = D_0024ED80;
    func_0012D7C0();
}
