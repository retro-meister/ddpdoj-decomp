#include "common.h"

s32 func_001FB6E0();
s32 func_002027A0();
s32 func_00202B70();
s32 func_002032A0();
extern u16 D_00265DE0[];
extern s8 D_0028E408;
extern u8 *reg_a0;
extern u16 *reg_a4;
extern u8 *reg_a6;

void func_001FB010(u16 arg0) {
    u16 var_a0;
    u32 temp_s0;
    u32 temp_s1;

    var_a0 = arg0;
    if ((*(u16 *)((u8 *)(reg_a6) + (0x68))) == 0) {
        (*(u16 *)((u8 *)(reg_a6) + (0x68))) = 1U;
    }
    if ((*(u16 *)((u8 *)(reg_a6) + (0x68))) == 1) {
        func_002032A0();
        if (D_0028E408 == 0) {
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
            var_a0 = (*(u16 *)((u8 *)(reg_a0) + (4)));
            reg_d2.h[0] += 0x1E00;
            reg_d3.h[0] = var_a0;
            (*(u16 *)((u8 *)(reg_a6) + (0x6C))) = (u16) reg_d2.h[0];
            (*(u16 *)((u8 *)(reg_a6) + (0x6E))) = (u16) reg_d3.h[0];
            goto block_5;
        }
        goto block_9;
    }
block_5:
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x6C)));
    temp_s0 = reg_d2.w;
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x6E)));
    temp_s1 = reg_d3.w;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_002027A0();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
    reg_d2.w = temp_s0;
    reg_d3.w = temp_s1;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_00202B70();
    if ((s16) reg_d0.h[0] < 0x601) {
        (*(u16 *)((u8 *)(reg_a6) + (0x68))) = 2U;
    }
    if ((s16) reg_d0.h[0] < 0x101) {
block_9:
        reg_d0.w = 1;
        func_001FB6E0();
        (*(u16 *)((u8 *)(reg_a6) + (0x6C))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
        (*(s16 *)((u8 *)(reg_a6) + (0x70))) = 0x50;
        (*(u8 *)((u8 *)(reg_a6) + (0x1B))) = 0U;
        (*(u16 *)((u8 *)(reg_a6) + (0x6E))) = 0U;
        if ((s16) (*(u16 *)((u8 *)(reg_a6) + (4))) < 0x1C01) {
            (*(u16 *)((u8 *)(reg_a6) + (0x6E))) = 0x3800U;
        }
    }
    (*(u8 *)((u8 *)(reg_a6) + (0x1B))) = 0x32U;
    reg_a4 = D_00265DE0;
loop_12:
    reg_d1.h[0] = *reg_a4;
    reg_a4 += 1;
    if ((s16) reg_d1.h[0] != -1) {
        reg_d2.h[0] = *reg_a4;
        reg_a4 += 1;
        if ((s16) reg_d1.h[0] >= (s16) reg_d0.h[0]) {
            (*(u8 *)((u8 *)(reg_a6) + (0x1B))) = (u8) reg_d2.b[0];
        } else {
            goto loop_12;
        }
    }
}
