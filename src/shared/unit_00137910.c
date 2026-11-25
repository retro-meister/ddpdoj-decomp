#include "common.h"

s32 func_0011C610();
extern u16 D_00269D60[];

void func_00137910(void) {
    u32 sv_d0;
    u32 sv_d1;
    u32 sv_d2;
    u32 sv_d3;
    u32 sv_d4;
    u32 sv_d5;
    u32 sv_d6;
    u32 sv_d7;
    s8 *sv_a0;
    u8 *sv_a1;
    u8 *sv_a2;
    u8 *sv_a3;
    u8 *sv_a4;
    u8 *sv_a5;
    u8 *sv_a6;
    sv_d0 = reg_d0.w;
    sv_d5 = reg_d5.w;
    sv_d7 = reg_d7.w;
    sv_a0 = (s8 *)reg_a0;
    sv_a1 = reg_a1;
    sv_a2 = reg_a2;
    sv_d1 = reg_d1.w;
    sv_a3 = reg_a3;
    sv_a4 = reg_a4;
    sv_a5 = reg_a5;
    sv_a6 = reg_a6;
    sv_d2 = reg_d2.w;
    reg_d2.h[0] = 0;
    sv_d3 = reg_d3.w;
    reg_d3.w = 0;
    sv_d4 = reg_d4.w;
    sv_d6 = reg_d6.w;
    reg_d5.h[0] = reg_d2.h[0];
    reg_d2.w = 1;
loop_1:
    reg_d4.w = 0;
    reg_d4.b[0] = *(s8 *)reg_a0;
    reg_a0 += 1;
    if (reg_d4.b[0] == 0) goto next_1;
    reg_a1 = (u8 *) D_00269D60;
    reg_d4.h[0] &= 0xFF;
    reg_d4.h[0] -= 0x20;
    reg_d4.h[0] += reg_d4.h[0];
    reg_a1 += reg_d4.h[0];
    reg_d4.h[1] = *(u16 *) reg_a1;
    reg_d4.h[0] = reg_d5.h[0];
    sv_d5 = reg_d5.w;
    reg_d5.h[0] = 0x10;
    func_0011C610();
    reg_d5.w = sv_d5;
    reg_d1.h[0] += 0x100;
    goto loop_1;
next_1:
    reg_d5.w = sv_d5;
    reg_d7.w = sv_d7;
    reg_a0 = (u8 *)sv_a0;
    reg_a1 = sv_a1;
    reg_a2 = sv_a2;
    reg_d0.w = sv_d0;
    reg_a3 = sv_a3;
    reg_a4 = sv_a4;
    reg_a5 = sv_a5;
    reg_a6 = sv_a6;
    reg_d1.w = sv_d1;
    reg_d2.w = sv_d2;
    reg_d3.w = sv_d3;
    reg_d4.w = sv_d4;
    reg_d6.w = sv_d6;
}

s32 text_layer_put();

void text_layer_print(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    s8 *temp_s5;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    temp_s5 = (s8 *)((s8 *)reg_a0);
    reg_d3.w = 0;
    reg_d5.h[0] = reg_d2.h[0];
    reg_d2.w = 0;
loop_1:
    reg_d4.w = 0;
    reg_d4.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    if (reg_d4.b[0] != 0) {
        reg_d4.h[0] = reg_d4.w & 0xFF;
        reg_tmp4.w = reg_d4.w;
        reg_d4.h[1] = reg_d4.h[0];
        reg_d4.h[0] = reg_d5.h[0];
        text_layer_put();
        reg_d0.h[0] += 1;
        goto loop_1;
    }
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_a0 = (u8 *)temp_s5;
}

void func_00137BC0(void) {
}

void func_00137BD0(void) {
}

void func_00137BE0(void) {
}
