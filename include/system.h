#ifndef DDPDOJ_SYSTEM_H
#define DDPDOJ_SYSTEM_H

#include "common.h"
#include "sdk/ps2sdk.h"

extern sceGsDBuffDc g_gs_dbuff;
extern s32 g_frame_counter;
extern s8 g_display_reset_pending; /* set by the options screen; sys_begin_frame then calls display_reset */
extern s16 g_fade_alpha;
extern s16 g_fade_step;
extern s8 g_fade_state;
#ifdef DEATH_LABEL
extern s8 g_fade_white; /* fade to white instead of black */
#endif
extern u8 g_pad_act_direct[6];
extern u8 g_pad_act_align[6];
extern void *g_pad_dma_buf;
extern u8 g_pad_dma_area[0x100];
extern u8 g_pad_dma_buf_0[0x100];
extern u8 g_pad_dma_buf_1[0x100];

void iop_reboot_and_load_modules(void);
void sys_reset_gs_path(void);
void sys_init_display(void);
void sys_start(void);
void sys_init(void);
void sys_begin_frame(void);
void sys_end_frame(void);
void sys_draw_replay_label(void);
void pause_check_start_button(void);
void vram_clear_all(void);
void fade_reset(void);
void fade_start_in(void);
void fade_start_out(void);
void fade_update_and_draw(void);
void vibration_stop_all(void);
void vibration_stop_pad1(void);
void vibration_stop_pad2(void);
void vibration_start_pad1(s16 power, s16 frames);
void vibration_start_pad2(s16 power, s16 frames);
void vibration_start_active_pad(s16 power, s16 frames);
void vibration_suspend(void);
void vibration_resume(void);
void vibration_update(void);

void gfx_draw_shaded_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha);
void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);

#endif
