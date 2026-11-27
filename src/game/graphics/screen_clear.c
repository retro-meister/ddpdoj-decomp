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
void logo_sprite_draw(void) {
    reg_d1.w = 0x20000E00;
    reg_d4.sh[0] = 0;
    reg_d2.sw = 0x155D;
    reg_d3.sh[0] = 0x1870;
    sprite_draw();
}

extern s16 scroll_shadow_reset_state;
extern s16 scroll_shadow_reset_state_2;

void scroll_shadow_reset(void) {
    (*(s16 **)&reg_a0) = &scroll_shadow_reset_state;
    *(*(s16 **)&reg_a0) = 0;
    (*(s16 **)&reg_a0) = &scroll_shadow_reset_state_2;
    *(*(s16 **)&reg_a0) = 1;
}

extern s16 g_bg_scroll_y;
extern s16 g_bg_scroll_x;

void bg_scroll_reset(void) {
    (*(s16 **)&reg_a0) = &g_bg_scroll_y;
    *(*(s16 **)&reg_a0) = 0;
    (*(s16 **)&reg_a0) = &g_bg_scroll_x;
    *(*(s16 **)&reg_a0) = 0;
}


void scroll_state_reset(void) {
    scroll_shadow_reset();
    bg_scroll_reset();
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

void bg_layer_clear(void) {
    (*(s32 **)&reg_a0) = ((s32 *)g_bg_layer);
    reg_d0.h[0] = 0xFFF;
    do {
        *(*(s32 **)&reg_a0) = 0;
        (*(s32 **)&reg_a0) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}


void text_and_bg_layers_clear(void) {
    text_layer_clear();
    bg_layer_clear();
}

extern s32 g_arcade_sprites_as_s32_a[];

void arcade_sprites_clear(void) {
    (*(s32 **)&reg_a0) = g_arcade_sprites_as_s32_a;
    reg_d0.h[0] = MAIN_OR_DEATH_LABEL(0x4FF, 0xBB7);
    do {
        *(*(s32 **)&reg_a0) = 0;
        (*(s32 **)&reg_a0) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

void screen_clear_unused(void) {
}

extern s32 g_text_palette[];

void text_palette_clear(void) {
    (*(s32 **)&reg_a0) = g_text_palette;
    reg_d0.h[0] = 0x7F;
    do {
        *(*(s32 **)&reg_a0) = 0;
        (*(s32 **)&reg_a0) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

extern s16 g_bg_palette[1024];

void bg_palette_clear(void) {
    (*(s32 **)&reg_a0) = ((s32 *)g_bg_palette);
    reg_d0.h[0] = 0x1FF;
    do {
        *(*(s32 **)&reg_a0) = 0;
        (*(s32 **)&reg_a0) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

extern s16 g_sprite_palette[1024];

void sprite_palette_clear(void) {
    (*(s32 **)&reg_a0) = ((s32 *)g_sprite_palette);
    reg_d0.h[0] = 0x1FF;
    do {
        *(*(s32 **)&reg_a0) = 0;
        (*(s32 **)&reg_a0) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}


void palettes_clear(void) {
    text_palette_clear();
    bg_palette_clear();
    sprite_palette_clear();
}


void layers_clear_all(void) {
    scroll_state_reset();
    text_and_bg_layers_clear();
    arcade_sprites_clear();
    screen_clear_unused();
    palettes_clear();
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

#ifdef DDPDOJ_PC
#include "pc_data_alias.h"

PC_DATA_ALIAS(D_002B4E28, g_text_layer, 0xd8);
PC_DATA_ALIAS(D_002B5728, g_text_layer, 0x9d8);
PC_DATA_ALIAS(D_002B5F28, g_text_layer, 0x11d8);
PC_DATA_ALIAS(D_002B6828, g_text_layer, 0x1ad8);

PC_DATA_ALIAS(D_002B6DF4, g_bg_layer, 0xa4);
PC_DATA_ALIAS(D_002B6E0C, g_bg_layer, 0xbc);

PC_DATA_ALIAS(g_arcade_sprites_as_s32_a, g_arcade_sprites, 0x0);
#endif

#ifdef DDPDOJ_PC
#include "pc_frame_regions.h"

const PcFrameRegion pc_screen_regions[] = {
    PC_FRAME_REGION(g_bg_layer),
    PC_FRAME_REGION(g_text_layer),
    PC_FRAME_REGION(g_arcade_sprites),
    PC_FRAME_REGION(g_sprite_palette),
    PC_FRAME_REGION(g_bg_palette),
    PC_FRAME_REGION(g_text_palette),
    { NULL, 0 },
};
#endif
