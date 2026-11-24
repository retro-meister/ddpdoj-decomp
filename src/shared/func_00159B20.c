#include "common.h"

s32 func_001292C0();
s32 func_001599D0();
s32 func_00202590();
s32 func_002026F0();
extern u16 D_0028E4A2;
extern u16 D_0028E4AA;
extern u8 *reg_a6;

void func_00159B20() {
    u16 temp_a0;

    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x27)));
    (*(u8 *)((u8 *)(reg_a6) + (0x27))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a6) + (0x27))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x26)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        func_002026F0();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2F)));
        func_00202590();
        (*(u8 *)((u8 *)(reg_a6) + (0x2F))) = (u8) reg_d0.b[0];
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2F)));
        reg_d4.w = 0;
        reg_d3.w = 0;
        D_0028E4A2 = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2C)));
        temp_a0 = reg_d0.h[0];
        reg_tmp.h[0] = temp_a0;
        reg_d0.h[0] = 7;
        D_0028E4AA = reg_tmp.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x2C))) += 4;
        reg_d3.w = 0x133FFD00;
        func_001292C0();
        reg_d3.w = 0x13400300;
        func_001292C0();
        reg_d3.w = 0x13400640;
        func_001292C0();
        reg_d3.w = 0x133FF9C0;
        func_001292C0();
        (*(u16 *)((u8 *)(reg_a6) + (0x28))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a6) + (0x28))) == 0) {
            func_001599D0();
        }
    }
}
