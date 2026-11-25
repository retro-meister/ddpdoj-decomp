#include "common.h"

void func_0012FE80(void);
void func_0012FEE0(void);
void func_0012FF50(u8 arg0);
void func_0012FFC0();
void func_0012FFD0();
void func_00130250(void);
void func_00130260(void);
void func_00130280(void);
void func_001303B0(void);
void func_001305C0(void);
void func_001305D0(void);
void func_00130720(void);
void func_00130DE0(void);

extern void sprite_draw(void);
void func_0012F9F0(void) {
    reg_d1.w = 0x20000E00;
    reg_d4.sh[0] = 0;
    reg_d2.sw = 0x155D;
    reg_d3.sh[0] = 0x1870;
    sprite_draw();
}

extern s16 D_0028E23C;
extern s16 D_0028E240;
extern s16 *reg_a0_as_s16_p;

void func_0012FA20(void) {
    reg_a0_as_s16_p = &D_0028E23C;
    *reg_a0_as_s16_p = 0;
    reg_a0_as_s16_p = &D_0028E240;
    *reg_a0_as_s16_p = 1;
}

extern s16 g_bg_scroll_y;
extern s16 g_bg_scroll_x;

void func_0012FA50(void) {
    reg_a0_as_s16_p = &g_bg_scroll_y;
    *reg_a0_as_s16_p = 0;
    reg_a0_as_s16_p = &g_bg_scroll_x;
    *reg_a0_as_s16_p = 0;
}


void func_0012FA80(void) {
    func_0012FA20();
    func_0012FA50();
}

extern s32 g_text_layer_as_s32_a[];
extern s32 *reg_a0_as_s32_p;

void text_layer_clear(void) {
    reg_a0_as_s32_p = g_text_layer_as_s32_a;
    reg_d0.h[0] = 0x7FF;
    do {
        *reg_a0_as_s32_p = 0;
        reg_a0_as_s32_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

extern s32 g_bg_layer_as_s32_a[];

void func_0012FB00(void) {
    reg_a0_as_s32_p = g_bg_layer_as_s32_a;
    reg_d0.h[0] = 0xFFF;
    do {
        *reg_a0_as_s32_p = 0;
        reg_a0_as_s32_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}


void func_0012FB50(void) {
    text_layer_clear();
    func_0012FB00();
}

extern s32 g_arcade_sprites_as_s32_a[];

void func_0012FB80(void) {
    reg_a0_as_s32_p = g_arcade_sprites_as_s32_a;
    reg_d0.h[0] = MAIN_OR_DEATH_LABEL(0x4FF, 0xBB7);
    do {
        *reg_a0_as_s32_p = 0;
        reg_a0_as_s32_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

void func_0012FBD0(void) {
}

extern s32 g_text_palette[];

void func_0012FBE0(void) {
    reg_a0_as_s32_p = g_text_palette;
    reg_d0.h[0] = 0x7F;
    do {
        *reg_a0_as_s32_p = 0;
        reg_a0_as_s32_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

extern s32 g_bg_palette_as_s32_a[];

void func_0012FC30(void) {
    reg_a0_as_s32_p = g_bg_palette_as_s32_a;
    reg_d0.h[0] = 0x1FF;
    do {
        *reg_a0_as_s32_p = 0;
        reg_a0_as_s32_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

extern s32 g_sprite_palette_as_s32_a[];

void func_0012FC80(void) {
    reg_a0_as_s32_p = g_sprite_palette_as_s32_a;
    reg_d0.h[0] = 0x1FF;
    do {
        *reg_a0_as_s32_p = 0;
        reg_a0_as_s32_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}


void func_0012FCD0(void) {
    func_0012FBE0();
    func_0012FC30();
    func_0012FC80();
}


void layers_clear_all(void) {
    func_0012FA80();
    func_0012FB50();
    func_0012FB80();
    func_0012FBD0();
    func_0012FCD0();
}
