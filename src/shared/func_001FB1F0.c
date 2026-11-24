#include "common.h"

s32 func_001FB6C0();
s32 func_001FB6E0();
s32 func_00202590();
s32 func_002027A0();
s32 func_00202B70();
extern u16 D_00265E50[];
extern u16 D_0028E3F0;
extern u16 D_0029C068[];
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001FB1F0(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a0_4;
    u16 temp_a0_5;
    u16 temp_a0_6;

    if ((*(u16 *)((u8 *)(reg_a6) + (0x68))) == 0) {
        (*(u8 *)((u8 *)(reg_a6) + (0x1B))) = 0U;
        (*(u16 *)((u8 *)(reg_a6) + (0x70))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a6) + (0x70))) == 0) {
            (*(u16 *)((u8 *)(reg_a6) + (0x6A))) = 2U;
            (*(u16 *)((u8 *)(reg_a6) + (0x68))) = 1U;
        }
    }
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x68)));
    if (temp_a0 == 1) {
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x6C)));
        reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x6E)));
        reg_d3.h[0] -= D_0029C068[0];
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        func_002027A0();
        (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x6C)));
        reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x6E)));
        temp_a0_2 = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d0.h[0] = temp_a0_2;
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d3.h[0] -= D_0029C068[0];
        func_00202B70();
        if ((s16) reg_d0.h[0] < 0x81) {
            (*(u16 *)((u8 *)(reg_a6) + (0x68))) = 2U;
            (*(u16 *)((u8 *)(reg_a6) + (0x6C))) += 0x100;
            if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x6C))) >= 0x5A00) {
                (*(u16 *)((u8 *)(reg_a6) + (0x6C))) = 0x5A00U;
            }
        }
        (*(u8 *)((u8 *)(reg_a6) + (0x73))) = 0x12U;
        reg_a4 = (u8 *)(D_00265E50);
loop_8:
        reg_d1.h[0] = *(u16 *)reg_a4;
        reg_a4 += 2;
        if ((s16) reg_d1.h[0] != -1) {
            reg_d2.h[0] = *(u16 *)reg_a4;
            reg_a4 += 2;
            if ((s16) reg_d1.h[0] >= (s16) reg_d0.h[0]) {
                (*(u8 *)((u8 *)(reg_a6) + (0x73))) = (u8) reg_d2.b[0];
            } else {
                goto loop_8;
            }
        }
    }
    temp_a0_3 = (*(u16 *)((u8 *)(reg_a6) + (0x68)));
    if (temp_a0_3 == 2) {
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x6C)));
        reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x6E)));
        reg_d3.h[0] -= D_0029C068[0];
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        func_002027A0();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        func_00202590();
        (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x6C)));
        reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x6E)));
        temp_a0_4 = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d0.h[0] = temp_a0_4;
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d3.h[0] -= D_0029C068[0];
        func_00202B70();
        (*(u8 *)((u8 *)(reg_a6) + (0x73))) = 4U;
        if (((*(u8 *)((u8 *)(reg_a6) + (0x1B))) == 4) && ((s16) reg_d0.h[0] < 0x1001)) {
            (*(u16 *)((u8 *)(reg_a6) + (0x6C))) += 0x1C00;
            (*(u16 *)((u8 *)(reg_a6) + (0x68))) = 1U;
            (*(u16 *)((u8 *)(reg_a6) + (0x6A))) -= 1;
            if ((*(u16 *)((u8 *)(reg_a6) + (0x6A))) == 0) {
                (*(u16 *)((u8 *)(reg_a6) + (0x6E))) = 0x1C00U;
                (*(u16 *)((u8 *)(reg_a6) + (0x68))) = 3U;
            } else {
                (*(u16 *)((u8 *)(reg_a6) + (0x6E))) = 0U;
                if ((s16) (*(u16 *)((u8 *)(reg_a6) + (4))) < 0x1C01) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x6E))) = 0x3800U;
                }
            }
        }
    }
    temp_a0_5 = (*(u16 *)((u8 *)(reg_a6) + (0x68)));
    if (temp_a0_5 == 3) {
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x6C)));
        reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x6E)));
        reg_d3.h[0] -= D_0029C068[0];
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        func_002027A0();
        (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x6C)));
        reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x6E)));
        temp_a0_6 = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d0.h[0] = temp_a0_6;
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d3.h[0] -= D_0029C068[0];
        func_00202B70();
        (*(u8 *)((u8 *)(reg_a6) + (0x73))) = 0xAU;
        if ((s16) reg_d0.h[0] < 0x1001) {
            func_001FB6C0();
            (*(u8 *)((u8 *)(reg_a6) + (0x73))) = 2U;
            if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) == 2) {
                (*(s8 *)((u8 *)(reg_a6) + (0x9E))) = 1;
                reg_d0.w = 0;
                func_001FB6E0();
            }
        }
    }
    reg_d0.h[0] = D_0028E3F0;
    reg_d0.h[0] &= 3;
    if (reg_d0.h[0] == 0) {
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
}
