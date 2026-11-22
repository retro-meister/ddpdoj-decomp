#include "common.h"

s32 func_00124D90();
s32 func_001C9750();
s32 func_001C9B60();
s32 func_00201C60();
s32 func_002021F0();
s32 func_00202B50();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001CA1F0(void) {
    if ((*(u8 *)((u8 *)(reg_a4) + (2))) == 0) {
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
        reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        func_002021F0();
        (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
        reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
        func_00202B50();
        reg_d1.h[0] = reg_d0.h[0];
        reg_d1.h[0] >>= 7;
        if ((s16)(reg_d1.b[0]) < 3) {
            reg_d1.w = 2;
        }
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) reg_d1.b[0];
        if ((s16) reg_d0.h[0] < 0x201) {
            (*(u8 *)((u8 *)(reg_a4) + (2))) = 1U;
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 2U;
            (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x101;
        }
    }
    if (((*(u8 *)((u8 *)(reg_a4) + (2))) == 1) && ((*(s8 *)((u8 *)(reg_a6) + (0x1B))) < 3)) {
        (*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 2;
        reg_d0.w = 5;
        func_00124D90();
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
        func_001C9B60();
    }
    func_00201C60();
    func_001C9750();
}
