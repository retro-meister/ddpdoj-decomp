#include "common.h"

s32 func_00129410();
s32 func_00158B40();
extern u16 D_0028E4A2;
extern u8 *reg_a6;

void func_00158CF0() {
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x29)));
    (*(u8 *)((u8 *)(reg_a6) + (0x29))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a6) + (0x29))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x28)));
        reg_d0.w = 0x40007;
        reg_d4.w = 0;
        reg_d3.w = 0;
        D_0028E4A2 = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x30)));
        reg_d3.w = 0xFD000000;
        func_00129410();
        reg_d3.w = 0xFCFFFF00;
        func_00129410();
        reg_d3.w = 0xFD000100;
        func_00129410();
        (*(u8 *)((u8 *)(reg_a6) + (0x30))) += 0x14;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x31)));
        reg_d3.w = 0xF5000000;
        func_00129410();
        reg_d3.w = 0xF4FFFF00;
        func_00129410();
        reg_d3.w = 0xF5000100;
        func_00129410();
        (*(u8 *)((u8 *)(reg_a6) + (0x31))) -= 0x14;
        (*(u16 *)((u8 *)(reg_a6) + (0x2C))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a6) + (0x2C))) == 0) {
            func_00158B40();
        }
    }
}
