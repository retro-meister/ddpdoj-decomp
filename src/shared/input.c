#include "common.h"

/*
 * The players' controls. Each word has one player's stick and buttons, a set bit meaning held.
 * "pressed" has the bits that were not held on the frame before.
 */

/* (the compiler lays these out in reverse) */
u16 g_input_p1_held __attribute__((aligned(4)));
u16 g_input_p1_pressed __attribute__((aligned(4)));
u16 g_input_p1_previous __attribute__((aligned(4)));
u16 g_input_p2_held __attribute__((aligned(4)));
u16 g_input_p2_pressed __attribute__((aligned(4)));
u16 g_input_p2_previous __attribute__((aligned(4)));


void input_clear(void) {
    g_input_p1_held = 0;
    g_input_p1_pressed = 0;
    g_input_p1_previous = 0;
    g_input_p2_held = 0;
    g_input_p2_pressed = 0;
    g_input_p2_previous = 0;
}

s32 replay_filter_input();
s32 scripted_input_apply();
extern s8 g_arcade_input_port[];
extern u8 g_paused;

void input_read(void) {
    u32 port;
    u32 p2_bits;

    if (g_paused != 0) return;
    reg_a0 = (u8 *)g_arcade_input_port;
    reg_d0.h[0] = *(u16 *)reg_a0;
    port = reg_d0.h[0];
    reg_d1.h[0] = port;
    reg_d1.h[0] = (s32) reg_d1.h[0] >> 8;
    if (port & 1) {
        reg_d0.h[0] = (s32) port >> 1;
        reg_d0.h[0] |= 0x8000;
    } else {
        reg_d0.h[0] = (s32) port >> 1;
    }
    p2_bits = reg_d1.h[0];
    if (p2_bits & 1) {
        reg_d1.h[0] = (s32) (p2_bits & 0xFFFF) >> 1;
        reg_d1.h[0] |= 0x8000;
    } else {
        reg_d1.h[0] = (s32) (p2_bits & 0xFFFF) >> 1;
    }
    /* the port is active low */
    reg_d0.h[0] = ~reg_d0.sh[0];
    reg_d1.h[0] = ~reg_d1.sh[0];
#ifdef DEATH_LABEL
    scripted_input_apply();
#endif
    replay_filter_input();
    g_input_p1_held = reg_d0.h[0];
    g_input_p2_held = reg_d1.h[0];
}


void input_update_pressed(void) {
    s32 sd0 = reg_d0.w;
    s32 sd1 = reg_d1.w;
    s32 sd2 = reg_d2.w;
    s32 sd3 = reg_d3.w;
    s32 sd4 = reg_d4.w;
    s32 sd5 = reg_d5.w;
    s32 sd6 = reg_d6.w;
    s32 sd7 = reg_d7.w;

    reg_d0.h[0] = g_input_p1_held;
    reg_d1.h[0] = g_input_p2_held;
    reg_d2.h[0] = g_input_p1_previous;
    reg_d3.h[0] = g_input_p2_previous;
    reg_d2.h[0] = ~reg_d2.h[0];
    reg_d3.h[0] = ~reg_d3.h[0];
    g_input_p1_previous = reg_d0.h[0];
    g_input_p2_previous = reg_d1.h[0];
    reg_d2.h[0] &= reg_d0.h[0];
    reg_d3.h[0] &= reg_d1.h[0];
    g_input_p1_pressed = reg_d2.h[0];
    g_input_p2_pressed = reg_d3.h[0];
    reg_d0.w = sd0;
    reg_d1.w = sd1;
    reg_d2.w = sd2;
    reg_d3.w = sd3;
    reg_d4.w = sd4;
    reg_d5.w = sd5;
    reg_d6.w = sd6;
    reg_d7.w = sd7;
}

void input_get_p1_held(void) {
    *(u16 *)&reg_d0 = g_input_p1_held;
}

void input_get_p2_held(void) {
    *(u16 *)&reg_d0 = g_input_p2_held;
}

void input_get_p1_pressed(void) {
    *(u16 *)&reg_d0 = g_input_p1_pressed;
}

void input_get_p2_pressed(void) {
    *(u16 *)&reg_d0 = g_input_p2_pressed;
}
