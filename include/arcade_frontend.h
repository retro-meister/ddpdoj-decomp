#ifndef DDPDOJ_ARCADE_FRONTEND_H
#define DDPDOJ_ARCADE_FRONTEND_H

#include "types.h"

/* Arcade routines without C arguments use the shared reg_a and reg_d registers. */
void fade_is_running(void);
void fade_release(void);
void fade_start_out(void);
void fade_to_black(void);
void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 alpha, s32 attr, s32 wide);
void glyph_queue_clear(void);
void glyph_queue_flush(void);
void music_stop(void);
void player_panel_show(void);
void player_slot_request(void);
void replay_file_pointers_decode(void *data);
void sfx_menu_confirm(void);
void sfx_menu_denied(void);
void sfx_menu_move(void);
void sfx_menu_tick(void);
void sprite_draw_keep(void);
void sprite_palette_load(void);
void stage_clear_running_check(void);
void start_buttons_take_credits(void);
void text_flush(void);
void text_layer_print(void);
void text_queue_clear(void);
void text_queue_glyph(s32 x, s32 y, s32 texture, s32 page, s32 width, s32 height, s32 alpha, s32 depth);

#endif
