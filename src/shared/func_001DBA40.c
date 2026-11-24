#include "common.h"

s32 func_00129410();
s32 func_002026F0();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001DBA40(void) {
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x102)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x104)));
        func_002026F0();
        (*(u8 *)((u8 *)(reg_a4) + (6))) = (u8) reg_d1.b[0];
        reg_d0.w = 0x4000C;
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x102)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x104)));
        reg_d3.w = 0;
        reg_d4.w = 0;
        func_00129410();
        reg_d0.w = 0x4000C;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (6)));
        reg_d6.w = 7;
        do {
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (7)));
            func_00129410();
        } while ((s16)(--reg_d6.h[0]) >= 0);
        reg_d0.w = 0x4000C;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (6)));
        reg_d6.w = 7;
        do {
            reg_d1.b[0] -= (*(u8 *)((u8 *)(reg_a4) + (7)));
            func_00129410();
        } while ((s16)(--reg_d6.h[0]) >= 0);
    }
}
