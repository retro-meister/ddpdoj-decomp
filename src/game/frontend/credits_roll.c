#include "common.h"
#include "enemy.h"
#include "credits_roll.h"

/*
 * The staff credits: lines of text enter at one edge of the screen one after another and scroll across it.
 * The last script line stops the roll.
 */

#define CREDIT_LINES 50

/* A line on screen; the lines live in the spare entity pool, 0x20 bytes each. */
typedef struct {
    /* 0x00 */ u16 active;
    /* 0x02 */ u16 y;
    /* 0x04 */ u16 x;
    /* 0x06 */ u16 small_font;
    /* 0x08 */ u8 unused_08[8];
    /* 0x10 */ u16 text[2];       /* address of the string, high word first; -1: stop scrolling */
    /* 0x14 */ u8 unused_14[0xC];
} CreditLine;

#define LINE(pointer) ((CreditLine *)(pointer))

/* One entry of the script, 10 bytes. */
typedef struct {
    /* 0x00 */ u16 delay;         /* frames to wait before this line enters; 0xFFFF ends the script */
    /* 0x02 */ u16 x;
    /* 0x04 */ u16 small_font;
    /* 0x06 */ u16 text[2];
} CreditScriptLine;

#define SCRIPT_LINE(pointer) ((CreditScriptLine *)(pointer))

/* (the compiler lays these out in reverse) */
s16 g_ending_started __attribute__((aligned(4)));
CreditsRoll g_credits_roll __attribute__((aligned(4)));


void credits_roll_begin(void)
{
    reg_a6 = (u8 *)g_spare_entities;
    reg_d7.w = CREDIT_LINES - 1;

    do {
        LINE(reg_a6)->active = 0;
        reg_a6 += sizeof(CreditLine);
    } while ((s16)(--reg_d7.h[0]) >= 0);

    g_credits_roll.script_offset = 0;
    g_credits_roll.scroll_speed = 0x20;
    g_credits_roll.wait = 0;
}

#ifndef DEATH_LABEL
s32 sprite_draw_keep();
extern u8 g_credits_script[];
extern u8 g_credits_large_font[];
extern u8 g_credits_small_font[];

void credits_roll_update(void) {
    u32 tmp;

    reg_a4 = (u8 *)g_credits_script;
    reg_a4 += g_credits_roll.script_offset;
    reg_d0.h[0] = SCRIPT_LINE(reg_a4)->delay;
    if ((s16) reg_d0.h[0] == -1) goto move_lines;
    reg_d1.h[0] = g_credits_roll.wait;
    if (reg_d1.h[0] == (reg_d0.h[0] & 0xFFFF)) goto start_line;
    g_credits_roll.wait += 1;
    goto move_lines;
start_line:
    g_credits_roll.wait = 0;
    reg_a6 = (u8 *)g_spare_entities;
    reg_d7.w = CREDIT_LINES - 1;
find_free_line:
    if (LINE(reg_a6)->active != 0) goto try_next_slot;
    LINE(reg_a6)->active = 0x8000;
    LINE(reg_a6)->y = 0xF800;
    LINE(reg_a6)->x = SCRIPT_LINE(reg_a4)->x;
    LINE(reg_a6)->small_font = SCRIPT_LINE(reg_a4)->small_font;
    LINE(reg_a6)->text[0] = SCRIPT_LINE(reg_a4)->text[0];
    LINE(reg_a6)->text[1] = SCRIPT_LINE(reg_a4)->text[1];
    g_credits_roll.script_offset += sizeof(CreditScriptLine);
    goto move_lines;
try_next_slot:
    reg_a6 += sizeof(CreditLine);
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto find_free_line;
move_lines:
    reg_a6 = (u8 *)g_spare_entities;
    reg_d7.w = CREDIT_LINES - 1;
move_line:
    if (LINE(reg_a6)->active == 0) goto next_line;
    reg_d0.h[0] = g_credits_roll.scroll_speed;
    LINE(reg_a6)->y += reg_d0.h[0];
    if ((s16) LINE(reg_a6)->y < 0x7800) goto still_on_screen;
    LINE(reg_a6)->active = 0;
    goto next_line;
still_on_screen:
    reg_d0.h[1] = LINE(reg_a6)->text[0];
    reg_d0.h[0] = LINE(reg_a6)->text[1];
    if (reg_d0.w != 0xFFFFFFFF) goto draw_text;
    g_credits_roll.scroll_speed = 0;
    goto next_line;
draw_text:
    reg_a3 = (u8 *)reg_d0.w;
    reg_d1.h[1] = LINE(reg_a6)->y;
    reg_d1.h[0] = LINE(reg_a6)->x;
    reg_d3.h[0] = 0x208;
    reg_d4.h[0] = 2;
    reg_a2 = (u8 *)g_credits_small_font;
    if (LINE(reg_a6)->small_font != 0) goto draw_character;
    reg_a2 = (u8 *)g_credits_large_font;
    reg_d3.h[0] = 0x210;
draw_character:
    reg_d6.b[0] = *(s8 *)reg_a3;
    reg_a3 += 1;
    if (reg_d6.b[0] == 0) goto next_line;
    reg_d6.h[0] &= 0xFF;
    reg_d6.h[0] -= 0x20;
    reg_d6.h[0] += reg_d6.h[0];
    reg_d6.h[0] += reg_d6.h[0];
    reg_d2.w = *(u32 *)(reg_a2 + reg_d6.h[0]);
    sprite_draw_keep();
    if (LINE(reg_a6)->small_font != 0) goto advance_small;
    reg_d1.h[0] += 0x400;
    goto draw_character;
advance_small:
    reg_d1.h[0] += 0x200;
    goto draw_character;
next_line:
    reg_a6 += sizeof(CreditLine);
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto move_line;
}
#endif
