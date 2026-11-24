#include "common.h"

s32 func_0013F580();
s32 func_0013F5A0();
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0013F400(void) {
    u8 *sv_a0;
    u8 *sv_a1;
    u8 *sv_a2;
    u8 *sv_a3;
    u8 *sv_a4;
    u8 *sv_a5;
    u8 *sv_a6;
    u32 sv_d0;
    u32 sv_d1;
    u32 sv_d2;
    u32 sv_d3;
    u32 sv_d4;
    u32 sv_d5;
    u32 sv_d6;
    u32 sv_d7;

    sv_d0 = reg_d0.w;
    sv_d1 = reg_d1.w;
    sv_d2 = reg_d2.w;
    sv_d3 = reg_d3.w;
    sv_d4 = reg_d4.w;
    sv_d5 = reg_d5.w;
    sv_d6 = reg_d6.w;
    sv_d7 = reg_d7.w;
    sv_a0 = reg_a0;
    sv_a1 = reg_a1;
    sv_a2 = reg_a2;
    sv_a3 = reg_a3;
    sv_a4 = reg_a4;
    sv_a5 = reg_a5;
    sv_a6 = reg_a6;
    if (*(u8 *) (reg_a6 + 0x3E) == 0) goto next_1;
    if (*(u8 *) (reg_a6 + 0x56) != 0) goto next_2;
    func_0013F5A0();
    reg_d0.w = sv_d0;
    reg_d1.w = sv_d1;
    reg_d2.w = sv_d2;
    reg_d3.w = sv_d3;
    reg_d4.w = sv_d4;
    reg_d5.w = sv_d5;
    reg_d6.w = sv_d6;
    reg_d7.w = sv_d7;
    reg_a0 = sv_a0;
    reg_a1 = sv_a1;
    reg_a2 = sv_a2;
    reg_a3 = sv_a3;
    reg_a4 = sv_a4;
    reg_a5 = sv_a5;
    reg_a6 = sv_a6;
    return;
next_2:
    func_0013F580();
next_1:
    reg_d0.w = sv_d0;
    reg_d1.w = sv_d1;
    reg_d2.w = sv_d2;
    reg_d3.w = sv_d3;
    reg_d4.w = sv_d4;
    reg_d5.w = sv_d5;
    reg_d6.w = sv_d6;
    reg_d7.w = sv_d7;
    reg_a0 = sv_a0;
    reg_a1 = sv_a1;
    reg_a2 = sv_a2;
    reg_a3 = sv_a3;
    reg_a4 = sv_a4;
    reg_a5 = sv_a5;
    reg_a6 = sv_a6;
}
