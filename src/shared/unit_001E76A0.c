#include "common.h"

s32 func_0012FD00();                            /* extern */
s32 sprite_palette_load();                            /* extern */
s32 func_00208AD0();                            /* extern */
s32 func_00209200();                            /* extern */
extern s32 D_00263F00[];
extern s32 D_00263F10[];
extern s32 D_00263F30[];
extern s32 D_00263F50[];
extern s32 D_00263F90[];
extern s32 D_00263FD0[];
extern s32 D_00264010[];
extern s8 D_0028DF9C;
extern s8 D_0028DFA0;

void func_001E76A0(void) {
    func_0012FD00();
    func_00208AD0();
    D_0028DFA0 = 0;
    D_0028DF9C = 1;
    reg_d0.h[0] = 0;
    reg_a0 = (u8 *)D_00263F00;
    func_00209200();
    reg_a0 = (u8 *)D_00263F10;
    func_00209200();
    reg_a0 = (u8 *)D_00263F30;
    func_00209200();
    reg_d0.h[0] = 0;
    reg_a0 = (u8 *)D_00263F50;
    sprite_palette_load();
    reg_d0.h[0] = 1;
    reg_a0 = (u8 *)D_00263F90;
    sprite_palette_load();
    reg_d0.h[0] = 2;
    reg_a0 = (u8 *)D_00263FD0;
    sprite_palette_load();
    reg_d0.h[0] = 3;
    reg_a0 = (u8 *)D_00264010;
    sprite_palette_load();
    reg_d0.w = 0;
}

s32 input_get_p1_held();
s32 sprite_draw_keep();
s32 func_002093F0();
extern u32 D_00264050[];
void func_001E7770(void) {
    u32 *var_s0;
    u32 *var_s0_2;
    u32 *var_s0_3;
    u32 *var_s0_4;
    u32 temp_a0;

    reg_d6.w = 0x50000E00;
    reg_d4.h[0] = 0;
    var_s0 = (u32 *)(D_00264050);
    reg_d3.h[0] = 0x208;
    reg_d7.w = 0xE;
    do {
        reg_d1.w = reg_d6.w;
        reg_d2.w = *var_s0;
        sprite_draw_keep();
        reg_d1.w += 0xFE000000;
        sprite_draw_keep();
        reg_d1.w += 0xFE000000;
        sprite_draw_keep();
        var_s0 += 1;
        reg_d6.h[0] += 0x200;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    var_s0_2 = (u32 *)(D_00264050);
    reg_d6.w = 0x48000E00;
    reg_d3.h[0] = 0x208;
    reg_d4.h[0] = 1;
    reg_d7.w = 0xE;
    do {
        reg_d1.w = reg_d6.w;
        reg_d2.w = *var_s0_2;
        sprite_draw_keep();
        reg_d1.w += 0xFE000000;
        sprite_draw_keep();
        reg_d1.w += 0xFE000000;
        sprite_draw_keep();
        var_s0_2 += 1;
        reg_d6.h[0] += 0x200;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    var_s0_3 = (u32 *)(D_00264050);
    reg_d6.w = 0x40000E00;
    reg_d3.h[0] = 0x208;
    reg_d4.h[0] = 2;
    reg_d7.w = 0xE;
    do {
        reg_d1.w = reg_d6.w;
        reg_d2.w = *var_s0_3;
        sprite_draw_keep();
        reg_d1.w += 0xFE000000;
        sprite_draw_keep();
        reg_d1.w += 0xFE000000;
        sprite_draw_keep();
        var_s0_3 += 1;
        reg_d6.h[0] += 0x200;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    var_s0_4 = (u32 *)(D_00264050);
    reg_d6.w = 0x38000E00;
    reg_d3.h[0] = 0x208;
    reg_d4.h[0] = 3;
    reg_d7.w = 0xE;
    do {
        reg_d1.w = reg_d6.w;
        reg_d2.w = *var_s0_4;
        sprite_draw_keep();
        reg_d1.w += 0xFE000000;
        sprite_draw_keep();
        reg_d1.w += 0xFE000000;
        sprite_draw_keep();
        var_s0_4 += 1;
        reg_d6.h[0] += 0x200;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    input_get_p1_held();
    temp_a0 = reg_d0.w;
    if ((temp_a0 & 0x8000) && (temp_a0 & 0x10)) {
        reg_d0.w = 0;
        func_002093F0();
    }
    reg_d0.w = 0;
}
