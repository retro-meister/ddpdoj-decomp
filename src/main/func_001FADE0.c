#include "common.h"

s32 func_002011A0();
s32 func_002027A0();
s32 func_00202B70();
extern u8 D_00265D40[];
extern u16 D_00265D70[];
extern u16 D_0029C068[];
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001FADE0(void) {
    if ((*(u16 *)((u8 *)(reg_a6) + (0x68))) == 0) {
        func_002011A0();
        reg_d0.h[0] &= 7;
        reg_d0.h[0] *= 4;
        (*(u16 *)((u8 *)(reg_a6) + (0x6A))) = (u16) reg_d0.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x68))) = 1U;
    }
    reg_a0 = (u8 *)D_00265D40;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x6A)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d3.h[0] -= D_0029C068[0];
    func_002027A0();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
    reg_a0 = (u8 *)D_00265D40;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x6A)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d3.h[0] -= D_0029C068[0];
    func_00202B70();
    if ((s16) reg_d0.h[0] < 0x81) {
        (*(u16 *)((u8 *)(reg_a6) + (0x6A))) += 4;
        if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x6A))) >= 0x24) {
            (*(u16 *)((u8 *)(reg_a6) + (0x6A))) = 0U;
        }
    }
    (*(u8 *)((u8 *)(reg_a6) + (0x73))) = 5U;
    reg_a4 = (u8 *)(D_00265D70);
loop_6:
    reg_d1.h[0] = *(u16 *)reg_a4;
    reg_a4 += 2;
    if ((s16) reg_d1.h[0] != -1) {
        reg_d2.h[0] = *(u16 *)reg_a4;
        reg_a4 += 2;
        if ((s16) reg_d1.h[0] >= (s16) reg_d0.h[0]) {
            (*(u8 *)((u8 *)(reg_a6) + (0x73))) = (u8) reg_d2.b[0];
        } else {
            goto loop_6;
        }
    }
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
    reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x73)));
    if (reg_d1.b[0] != reg_d2.b[0]) {
        if ((s8)(reg_d1.b[0]) >= (s8)(reg_d2.b[0])) {
            (*(u8 *)((u8 *)(reg_a6) + (0x1B))) -= 1;
        } else {
            (*(u8 *)((u8 *)(reg_a6) + (0x1B))) += 1;
        }
    }
}
