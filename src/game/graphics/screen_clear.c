#include "common.h"

void credit_display_changed_check_coins(void);
void credit_display_changed_check_side(void);
void credit_display_changed_check_side_coins(u8 arg0);
void credit_display_changed();
void credit_display_unchanged();
void p1_continue_discount_reset(void);
void p2_continue_discount_reset(void);
void p1_credit_spend(void);
void p2_credit_spend(void);
void credit_spend_accept(void);
void credit_spend_refuse(void);
void coin_slots_clear(void);
void free_play_text_print_at(void);

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

void func_0012FA20(void) {
    (*(s16 **)&reg_a0) = &D_0028E23C;
    *(*(s16 **)&reg_a0) = 0;
    (*(s16 **)&reg_a0) = &D_0028E240;
    *(*(s16 **)&reg_a0) = 1;
}

extern s16 g_bg_scroll_y;
extern s16 g_bg_scroll_x;

void func_0012FA50(void) {
    (*(s16 **)&reg_a0) = &g_bg_scroll_y;
    *(*(s16 **)&reg_a0) = 0;
    (*(s16 **)&reg_a0) = &g_bg_scroll_x;
    *(*(s16 **)&reg_a0) = 0;
}


void func_0012FA80(void) {
    func_0012FA20();
    func_0012FA50();
}

extern u8 g_text_layer[8192];

void text_layer_clear(void) {
    (*(s32 **)&reg_a0) = ((s32 *)g_text_layer);
    reg_d0.h[0] = 0x7FF;
    do {
        *(*(s32 **)&reg_a0) = 0;
        (*(s32 **)&reg_a0) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

extern u8 g_bg_layer[16384];

void func_0012FB00(void) {
    (*(s32 **)&reg_a0) = ((s32 *)g_bg_layer);
    reg_d0.h[0] = 0xFFF;
    do {
        *(*(s32 **)&reg_a0) = 0;
        (*(s32 **)&reg_a0) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}


void func_0012FB50(void) {
    text_layer_clear();
    func_0012FB00();
}

extern s32 g_arcade_sprites_as_s32_a[];

void func_0012FB80(void) {
    (*(s32 **)&reg_a0) = g_arcade_sprites_as_s32_a;
    reg_d0.h[0] = MAIN_OR_DEATH_LABEL(0x4FF, 0xBB7);
    do {
        *(*(s32 **)&reg_a0) = 0;
        (*(s32 **)&reg_a0) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

void func_0012FBD0(void) {
}

extern s32 g_text_palette[];

void func_0012FBE0(void) {
    (*(s32 **)&reg_a0) = g_text_palette;
    reg_d0.h[0] = 0x7F;
    do {
        *(*(s32 **)&reg_a0) = 0;
        (*(s32 **)&reg_a0) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

extern s16 g_bg_palette[1024];

void func_0012FC30(void) {
    (*(s32 **)&reg_a0) = ((s32 *)g_bg_palette);
    reg_d0.h[0] = 0x1FF;
    do {
        *(*(s32 **)&reg_a0) = 0;
        (*(s32 **)&reg_a0) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

extern s16 g_sprite_palette[1024];

void func_0012FC80(void) {
    (*(s32 **)&reg_a0) = ((s32 *)g_sprite_palette);
    reg_d0.h[0] = 0x1FF;
    do {
        *(*(s32 **)&reg_a0) = 0;
        (*(s32 **)&reg_a0) += 1;
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

/* .bss (the compiler lays these out in reverse) */
u8 g_bg_layer[16384];
u8 g_text_layer[8192];
#ifdef DEATH_LABEL
u8 g_arcade_sprites[12000];
#else
u8 g_arcade_sprites[5120];
#endif
s16 g_sprite_palette[1024];
s16 g_bg_palette[1024];
s32 g_text_palette[128];
