#include "common.h"
#include "black_label.h"
#include "layers.h"

void layer_a_set_type(void);
void layer_b_set_type(void);

void deferred_text_reset(void);

void layers_reset(void) {
    reg_d0.w = 0;
    layer_a_set_type();
    g_layer_a_position[0] = 0;
    reg_d0.w = 1;
    g_layer_a_position[1] = 0;
    g_layer_a_fraction[0] = 0;
    g_layer_a_fraction[1] = 0;
    g_layer_a_step_fraction[0] = 0;
    g_layer_a_step_fraction[1] = 0;
    layer_b_set_type();
    g_layer_b_position[0] = 0;
    g_layer_b_position[1] = 0;
    g_layer_b_fraction[0] = 0;
    g_layer_b_fraction[1] = 0;
    g_layer_b_step_fraction[0] = 0;
    g_layer_b_step_fraction[1] = 0;
#ifdef DDPDOJ_BONUS_FEATURES
    if (g_black_label_active) g_boss_shake_y = g_boss_shake_x = 0;
#endif
    deferred_text_reset();
}


void layer_a_scroll(void) {
    u32 sv_d0;
    u32 sv_d1;

    sv_d0 = reg_d0.w;
    sv_d1 = reg_d1.w;
    g_layer_a_fraction[0] += reg_d0.w;
    reg_d2.w = g_layer_a_fraction[0];
    reg_d2.w &= ~0x3F;
    g_layer_a_position[0] += reg_d2.w;
    g_layer_a_fraction[0] &= 0x3F;
    g_layer_a_fraction[1] += (s16) reg_d1.h[0];
    reg_d2.w = g_layer_a_fraction[1];
    reg_d2.w &= ~0x3F;
    g_layer_a_position[1] += reg_d2.w;
    g_layer_a_fraction[1] &= 0x3F;
    g_layer_a_step_fraction[0] += reg_d0.h[0];
    reg_d0.h[0] = g_layer_a_step_fraction[0];
    reg_d0.h[0] &= 0xFFC0 & 0xFFFF;
    reg_d0.h[0] *= 0xFFFF & 0xFFFF;
    g_layer_a_shift[0] = reg_d0.h[0];
    g_layer_a_step_fraction[0] &= 0x3F;
    g_layer_a_step_fraction[1] += reg_d1.h[0];
    reg_d1.h[0] = g_layer_a_step_fraction[1];
    reg_d1.h[0] &= 0xFFC0;
    reg_d1.h[0] *= 0xFFFF;
    g_layer_a_shift[1] = reg_d1.h[0];
    g_layer_a_step_fraction[1] &= 0x3F;
    reg_d1.w = sv_d1;
    reg_d0.w = sv_d0;
}


void layer_b_scroll(void) {
    u32 sv_d0;
    u32 sv_d1;

    sv_d0 = reg_d0.w;
    sv_d1 = reg_d1.w;
    g_layer_b_fraction[0] += reg_d0.w;
    reg_d2.w = g_layer_b_fraction[0];
    reg_d2.w &= ~0x3F;
    g_layer_b_position[0] += reg_d2.w;
    g_layer_b_fraction[0] &= 0x3F;
    g_layer_b_fraction[1] += (s16) reg_d1.h[0];
    reg_d2.w = g_layer_b_fraction[1];
    reg_d2.w &= ~0x3F;
    g_layer_b_position[1] += reg_d2.w;
    g_layer_b_fraction[1] &= 0x3F;
    g_layer_b_step_fraction[0] += reg_d0.h[0];
    reg_d0.h[0] = g_layer_b_step_fraction[0];
    reg_d0.h[0] &= 0xFFC0 & 0xFFFF;
    reg_d0.h[0] *= 0xFFFF & 0xFFFF;
    g_layer_b_shift[0] = reg_d0.h[0];
    g_layer_b_step_fraction[0] &= 0x3F;
    g_layer_b_step_fraction[1] += reg_d1.h[0];
    reg_d1.h[0] = g_layer_b_step_fraction[1];
    reg_d1.h[0] &= 0xFFC0;
    reg_d1.h[0] *= 0xFFFF;
    g_layer_b_shift[1] = reg_d1.h[0];
    g_layer_b_step_fraction[1] &= 0x3F;
    reg_d1.w = sv_d1;
    reg_d0.w = sv_d0;
}


void layer_a_set_type(void) {
    g_layer_a_type = reg_d0.h[0];
}


void layer_b_set_type(void) {
    g_layer_b_type = reg_d0.h[0];
}

extern s16 g_bg_scroll_y;
extern s16 g_bg_scroll_x;

void layer_a_apply_scroll(void) {
    reg_a1 = (u8 *)&g_bg_scroll_y;
    reg_a2 = (u8 *)&g_bg_scroll_x;
    reg_d0.w = g_layer_a_position[0];
    reg_d1.w = g_layer_a_position[1];
    reg_d0.w = (u32) reg_d0.w >> 6;
    reg_d1.w = (u32) reg_d1.w >> 6;
#ifdef DDPDOJ_BONUS_FEATURES
    if (g_black_label_active) {
        reg_d0.h[0] -= g_boss_shake_y;
        reg_d1.h[0] -= g_boss_shake_x;
    }
#endif
    *(u16 *)reg_a2 = reg_d0.h[0];
    *(u16 *)reg_a1 = reg_d1.h[0];
}

extern u8 g_text_layer[];

void text_layer_put(void) {
    u8 *a0;
    u32 d0;
    u32 d1;
    u32 d2;
    u32 d3;
    u32 d4;
    u32 d5;
    u32 d6;
    u32 d7;
    u32 t;
    s32 t2;

    d0 = reg_d0.w;
    d1 = reg_d1.w;
    d2 = reg_d2.w;
    d3 = reg_d3.w;
    d4 = reg_d4.w;
    d5 = reg_d5.w;
    d6 = reg_d6.w;
    d7 = reg_d7.w;
    a0 = reg_a0;
    reg_a0 = (u8 *)g_text_layer;
    reg_d4.h[0] = (s16) reg_d4.h[0] * 2;
next_row:
    reg_d6.h[0] = reg_d0.h[0];
    reg_d7.h[0] = reg_d2.h[0];
next_cell:
    reg_d5.h[0] = reg_d6.h[0];
    reg_d5.h[0] <<= 6;
    reg_d5.h[0] += reg_d1.h[0];
    *(u32 *)(reg_a0 + reg_d5.h[0] * 4) = reg_d4.w;
    reg_d4.w += 0x10000;
    reg_d6.h[0] += 1;
    t2 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t2;
    if (((s64) ((s64) (u16) t2 << 0x30) >> 0x30) >= 0) goto next_cell;
    reg_d1.h[0] -= 1;
    t = reg_d3.h[0] - 1;
    reg_d3.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto next_row;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_d3.w = d3;
    reg_d4.w = d4;
    reg_d5.w = d5;
    reg_d6.w = d6;
    reg_d7.w = d7;
    reg_a0 = a0;
}

extern u8 g_bg_layer[];

void bg_layer_put(void) {
    u8 *a0 = reg_a0;
    u32 d0 = reg_d0.w;
    u32 d1 = reg_d1.w;
    u32 d2 = reg_d2.w;
    u32 d3 = reg_d3.w;
    u32 d4 = reg_d4.w;

    reg_d0.h[0] <<= 6;
    reg_a0 = g_bg_layer;
    reg_d0.h[0] += reg_d1.h[0];
    reg_d0.h[0] <<= 2;
    reg_a0 += reg_d0.h[0];
    *(u32 *)reg_a0 = reg_d4.w;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_d3.w = d3;
    reg_d4.w = d4;
    reg_a0 = a0;
}

void bg_layer_cell_address(void) {
    u32 d0 = reg_d0.w;

    reg_d0.h[0] <<= 6;
    reg_a0 = g_bg_layer;
    reg_d0.h[0] += reg_d1.h[0];
    reg_d0.h[0] <<= 2;
    reg_a0 += reg_d0.h[0];
    reg_d0.w = d0;
    reg_d1.w = (u32)reg_d1.w;
}


void deferred_text_put(void) {
    u8 *a0;
    u32 d0;
    u32 d1;
    u32 d2;
    u32 d3;
    u32 d4;
    u32 d5;
    u32 d6;
    u32 d7;
    u32 t;
    s32 t2;

    d0 = reg_d0.w;
    d1 = reg_d1.w;
    d2 = reg_d2.w;
    d3 = reg_d3.w;
    d4 = reg_d4.w;
    d5 = reg_d5.w;
    d6 = reg_d6.w;
    d7 = reg_d7.w;
    a0 = reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, g_deferred_text_next[0]);
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a0);
    if (reg_tmp.w == ARCADE_ADDRESS_ENCODE(g_deferred_text + DEFERRED_TEXT_CELLS * 2)) goto queue_full;
    reg_d5.w = 0;
next_row:
    reg_d6.h[0] = reg_d1.h[0];
    reg_d7.h[0] = reg_d3.h[0];
next_cell:
#ifdef DDPDOJ_PC
    if (reg_a0 == (u8 *)(g_deferred_text + DEFERRED_TEXT_CELLS * 2)) {
        goto finish_queue;
    }
#endif
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(g_text_layer);
    *(u32 *)reg_a0 = ARCADE_ADDRESS_ENCODE(g_text_layer);
    reg_d5.h[0] = reg_d6.h[0];
    reg_d5.h[0] += reg_d0.h[0];
    reg_tmp.w += reg_d5.w;
    *(u32 *)reg_a0 = reg_tmp.w;
    reg_a0 += 4;
    *(u32 *)reg_a0 = reg_d4.w;
    reg_a0 += 4;
    reg_d4.w += 0x10000;
    reg_d6.h[0] += 0x100;
    t2 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t2;
    if (((s64) ((s64) (u16) t2 << 0x30) >> 0x30) >= 0) goto next_cell;
    reg_d0.h[0] -= 4;
    t = reg_d2.h[0] - 1;
    reg_d2.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto next_row;
#ifdef DDPDOJ_PC
finish_queue:
#endif
    *(u32 *)reg_a0 = -1;
    g_deferred_text_next[0] = ARCADE_ADDRESS_ENCODE(reg_a0);
queue_full:
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_d3.w = d3;
    reg_d4.w = d4;
    reg_d5.w = d5;
    reg_d6.w = d6;
    reg_d7.w = d7;
    reg_a0 = a0;
}


void deferred_text_put_sheet(void) {
    u8 *a0;
    u32 d0;
    u32 d1;
    u32 d2;
    u32 d3;
    u32 d4;
    u32 d5;
    u32 d6;
    u32 d7;
    u32 t;
    s32 t2;

    d0 = reg_d0.w;
    d1 = reg_d1.w;
    d2 = reg_d2.w;
    d3 = reg_d3.w;
    d4 = reg_d4.w;
    d5 = reg_d5.w;
    d6 = reg_d6.w;
    d7 = reg_d7.w;
    a0 = reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, g_deferred_text_next[0]);
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a0);
    if (reg_tmp.w == ARCADE_ADDRESS_ENCODE(g_deferred_text + DEFERRED_TEXT_CELLS * 2)) goto queue_full;
    reg_d5.h[0] -= reg_d3.h[0];
    reg_d5.h[0] -= 1;
    reg_tmp5.h[0] = reg_d5.h[0];
    reg_d5.h[0] = reg_d5.h[1];
    reg_d5.h[1] = reg_tmp5.h[0];
    reg_d5.h[0] = 0;
    g_deferred_text_row_skip = reg_d5.w;
    reg_d5.w = 0;
next_row:
    reg_d6.h[0] = reg_d1.h[0];
    reg_d7.h[0] = reg_d3.h[0];
next_cell:
#ifdef DDPDOJ_PC
    if (reg_a0 == (u8 *)(g_deferred_text + DEFERRED_TEXT_CELLS * 2)) {
        goto finish_queue;
    }
#endif
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(g_text_layer);
    *(u32 *)reg_a0 = ARCADE_ADDRESS_ENCODE(g_text_layer);
    reg_d5.h[0] = reg_d6.h[0];
    reg_d5.h[0] += reg_d0.h[0];
    reg_tmp.w += reg_d5.w;
    *(u32 *)reg_a0 = reg_tmp.w;
    reg_a0 += 4;
    *(u32 *)reg_a0 = reg_d4.w;
    reg_a0 += 4;
    reg_d4.w += 0x10000;
    reg_d6.h[0] += 0x100;
    t2 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t2;
    if (((s64) ((s64) (u16) t2 << 0x30) >> 0x30) >= 0) goto next_cell;
    reg_d4.w += g_deferred_text_row_skip;
    reg_d0.h[0] -= 4;
    t = reg_d2.h[0] - 1;
    reg_d2.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto next_row;
#ifdef DDPDOJ_PC
finish_queue:
#endif
    *(u32 *)reg_a0 = -1;
    g_deferred_text_next[0] = ARCADE_ADDRESS_ENCODE(reg_a0);
queue_full:
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_d3.w = d3;
    reg_d4.w = d4;
    reg_d5.w = d5;
    reg_d6.w = d6;
    reg_d7.w = d7;
    reg_a0 = a0;
}


void deferred_text_clear(void) {
    u8 *a0;
    u32 d0;
    u32 d1;
    u32 d2;
    u32 d3;
    u32 d4;
    u32 d5;
    u32 d6;
    u32 d7;
    u32 t;
    s32 t2;

    d0 = reg_d0.w;
    d1 = reg_d1.w;
    d2 = reg_d2.w;
    d3 = reg_d3.w;
    d4 = reg_d4.w;
    d5 = reg_d5.w;
    d6 = reg_d6.w;
    d7 = reg_d7.w;
    a0 = reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, g_deferred_text_next[0]);
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a0);
    if (reg_tmp.w == ARCADE_ADDRESS_ENCODE(g_deferred_text + DEFERRED_TEXT_CELLS * 2)) goto queue_full;
    reg_d4.w = 0;
    reg_d5.w = 0;
next_row:
    reg_d6.h[0] = reg_d1.h[0];
    reg_d7.h[0] = reg_d3.h[0];
next_cell:
#ifdef DDPDOJ_PC
    if (reg_a0 == (u8 *)(g_deferred_text + DEFERRED_TEXT_CELLS * 2)) {
        goto finish_queue;
    }
#endif
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(g_text_layer);
    *(u32 *)reg_a0 = ARCADE_ADDRESS_ENCODE(g_text_layer);
    reg_d5.h[0] = reg_d6.h[0];
    reg_d5.h[0] += reg_d0.h[0];
    reg_tmp.w += reg_d5.w;
    *(u32 *)reg_a0 = reg_tmp.w;
    reg_a0 += 4;
    *(u32 *)reg_a0 = reg_d4.w;
    reg_a0 += 4;
    reg_d6.h[0] += 0x100;
    t2 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t2;
    if (((s64) ((s64) (u16) t2 << 0x30) >> 0x30) >= 0) goto next_cell;
    reg_d0.h[0] -= 4;
    t = reg_d2.h[0] - 1;
    reg_d2.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto next_row;
#ifdef DDPDOJ_PC
finish_queue:
#endif
    *(u32 *)reg_a0 = -1;
    g_deferred_text_next[0] = ARCADE_ADDRESS_ENCODE(reg_a0);
queue_full:
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_d3.w = d3;
    reg_d4.w = d4;
    reg_d5.w = d5;
    reg_d6.w = d6;
    reg_d7.w = d7;
    reg_a0 = a0;
}


void deferred_text_reset(void) {
    g_deferred_text[0] = -1;
    reg_d0.w = 0;
    g_deferred_text_row_skip = 0;
    g_deferred_text_next[0] = ARCADE_ADDRESS_ENCODE(g_deferred_text);
}


void deferred_text_flush(void) {
    reg_a0 = (u8 *)g_deferred_text;
    reg_d0.h[0] = DEFERRED_TEXT_CELLS - 1;
next_pair:
    reg_tmp.w = *(u32 *)reg_a0;
    reg_a0 += 4;
    if (reg_tmp.w != -1U) {
        reg_a1 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
        *(u32 *)reg_a1 = *(u32 *)reg_a0;
        reg_a0 += 4;
        goto next_pair;
    }
    deferred_text_reset();
}

/* (the compiler lays these out in reverse) */
u16 g_layer_a_type __attribute__((aligned(4)));
u32 g_layer_a_position[2];
u16 g_layer_a_shift[2];
u16 g_layer_a_step_fraction[2];
u32 g_layer_a_fraction[2];
u16 g_layer_unused[2];
u16 g_layer_b_type __attribute__((aligned(4)));
u32 g_layer_b_position[2];
u16 g_layer_b_shift[2];
u16 g_layer_b_step_fraction[2];
u32 g_layer_b_fraction[2];
u32 g_deferred_text_row_skip;

/* .bss (the compiler lays these out in reverse) */
#ifdef DDPDOJ_PC
u32 g_deferred_text[DEFERRED_TEXT_CELLS * 2 + 1]; /* Final sentinel has its own word. */
#else
u32 g_deferred_text[1568];
#endif
u32 g_deferred_text_next[784];

#ifdef DDPDOJ_PC
#include "pc_frame_regions.h"

const PcFrameRegion pc_layer_regions[] = {
    PC_FRAME_REGION(g_layer_a_type),
    PC_FRAME_REGION(g_layer_a_position),
    PC_FRAME_REGION(g_layer_a_shift),
    PC_FRAME_REGION(g_layer_a_step_fraction),
    PC_FRAME_REGION(g_layer_a_fraction),
    PC_FRAME_REGION(g_layer_unused),
    PC_FRAME_REGION(g_layer_b_type),
    PC_FRAME_REGION(g_layer_b_position),
    PC_FRAME_REGION(g_layer_b_shift),
    PC_FRAME_REGION(g_layer_b_step_fraction),
    PC_FRAME_REGION(g_layer_b_fraction),
    PC_FRAME_REGION(g_deferred_text_row_skip),
    PC_FRAME_REGION(g_deferred_text),
    PC_FRAME_REGION(g_deferred_text_next),
    { NULL, 0 },
};
#endif
