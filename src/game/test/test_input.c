#include "common.h"
#include "test_mode.h"

extern u8 test_input_text_title[15];

void test_input_print_labels(void);
s32 input_get_p1_held();
s32 input_get_p2_held();

extern s32 test_input_text_exit[];
extern s32 test_input_text_service[];
extern s32 test_input_text_test[];
extern s32 test_input_text_players[];
extern s32 test_input_text_coin[];
extern s32 test_input_text_start[];
extern s32 test_input_text_lever_top[];
extern s32 test_input_text_lever_middle[];
extern s32 test_input_text_lever_bottom[];
extern s32 test_input_text_shot[];
extern u8 test_input_lever_marks[];
extern u8 test_input_mark_service[8];
extern u8 test_input_mark_test[8];
extern u8 test_input_mark_coin1[8];
extern u8 test_input_mark_coin2[8];
extern u8 test_input_mark_start1[8];
extern u8 test_input_mark_start2[8];
extern u8 test_input_mark[4];
extern u8 g_arcade_coin_port;

void test_input_begin(void) {
    layers_clear_all();
    test_palettes_load();
    g_test_cursor = 0;
    g_test_redraw = 1;
    test_input_print_labels();
    reg_d0.h[0] = 0;
    reg_a0 = (u8 *)((s32 *)test_input_text_title);
    test_print_lines();
    reg_a0 = (u8 *)test_input_text_exit;
    test_print_lines();
    reg_d0.w = 0;
}

void test_input_print_labels(void) {
    reg_a0 = (u8 *)test_input_text_service;
    reg_d0.h[0] = 0;
    test_print_lines();
    reg_a0 = (u8 *)test_input_text_test;
    test_print_lines();
    reg_a0 = (u8 *)test_input_text_players;
    test_print_lines();
    reg_a0 = (u8 *)test_input_text_coin;
    test_print_lines();
    reg_a0 = (u8 *)test_input_text_start;
    test_print_lines();
    reg_a0 = (u8 *)test_input_text_lever_top;
    test_print_lines();
    reg_a0 = (u8 *)test_input_text_lever_middle;
    test_print_lines();
    reg_a0 = (u8 *)test_input_text_lever_bottom;
    test_print_lines();
    reg_a0 = (u8 *)test_input_text_shot;
    test_print_lines();
}

void test_input_update(void) {
    u8 *mark_p1;
    u8 *mark_p2;
    u32 held;
    u8 column_p1;
    u8 column_p2;

    test_input_print_labels();
    reg_a0 = &g_arcade_coin_port;
    reg_d0.h[0] = *(u16 *)reg_a0;
    if (!(reg_d0.w & 0x20)) {
        reg_d0.h[0] = 2;
        reg_a0 = test_input_mark_service;
        test_print_lines();
    }
    reg_a0 = &g_arcade_coin_port;
    reg_d0.h[0] = *(u16 *)reg_a0;
    if (!(reg_d0.w & 0x10)) {
        reg_d0.h[0] = 2;
        reg_a0 = test_input_mark_test;
        test_print_lines();
    }
    reg_a0 = &g_arcade_coin_port;
    reg_d0.h[0] = *(u16 *)reg_a0;
    if (!(reg_d0.w & 1)) {
        reg_d0.h[0] = 2;
        reg_a0 = test_input_mark_coin1;
        test_print_lines();
    }
    reg_a0 = &g_arcade_coin_port;
    reg_d0.h[0] = *(u16 *)reg_a0;
    if (!(reg_d0.w & 2)) {
        reg_d0.h[0] = 2;
        reg_a0 = test_input_mark_coin2;
        test_print_lines();
    }
    input_get_p1_held();
    if (reg_d0.w & 0x8000) {
        reg_d0.h[0] = 2;
        reg_a0 = test_input_mark_start1;
        test_print_lines();
    }
    input_get_p2_held();
    if (reg_d0.w & 0x8000) {
        reg_d0.h[0] = 2;
        reg_a0 = test_input_mark_start2;
        test_print_lines();
    }
    input_get_p1_held();
    reg_d0.h[0] &= 0xF;
    if (reg_d0.b[0] != 0) {
        reg_d1.w = 0;
        reg_a0 = (u8 *)test_input_lever_marks;
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 += reg_d0.h[0];
        reg_d0.w = 0;
        mark_p1 = (u8 *)(reg_a0);
        reg_d0.b[0] = (*(u8 *)((u8 *)(mark_p1) + (1)));
        reg_d0.b[0] += 0xD;
        column_p1 = (*(u8 *)((u8 *)(mark_p1) + (0)));
        reg_d2.h[0] = 2;
        reg_d1.b[0] = column_p1;
        reg_a0 = test_input_mark;
        reg_d1.b[0] += 0x1E;
        test_print_at();
    }
    input_get_p2_held();
    reg_d0.h[0] &= 0xF;
    if (reg_d0.b[0] != 0) {
        reg_d1.w = 0;
        reg_a0 = (u8 *)test_input_lever_marks;
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 += reg_d0.h[0];
        reg_d0.w = 0;
        mark_p2 = (u8 *)(reg_a0);
        reg_d0.b[0] = (*(u8 *)((u8 *)(mark_p2) + (1)));
        reg_d0.b[0] += 0x15;
        column_p2 = (*(u8 *)((u8 *)(mark_p2) + (0)));
        reg_d1.b[0] = column_p2;
        reg_d2.h[0] = 2;
        reg_a0 = test_input_mark;
        reg_d1.b[0] += 0x1E;
        test_print_at();
    }
    input_get_p1_held();
    reg_d0.h[0] &= 0x70;
    reg_d0.h[0] >>= 4;
    if (reg_d0.b[0] != 0) {
        reg_d7.b[0] = reg_d0.b[0];
        reg_d2.h[0] = 2;
        reg_a0 = test_input_mark;
        reg_d0.w = 0xD;
        reg_d1.w = 0x18;
        if (reg_d7.w & 1) {
            test_print_at();
        }
        reg_d0.h[0] += 1;
        if (reg_d7.w & 2) {
            test_print_at();
        }
        reg_d0.h[0] += 1;
        if (reg_d7.w & 4) {
            test_print_at();
        }
    }
    input_get_p2_held();
    reg_d0.h[0] &= 0x70;
    reg_d0.h[0] >>= 4;
    if (reg_d0.b[0] != 0) {
        reg_d7.b[0] = reg_d0.b[0];
        reg_d2.h[0] = 2;
        reg_a0 = test_input_mark;
        reg_d0.w = 0x15;
        reg_d1.w = 0x18;
        if (reg_d7.w & 1) {
            test_print_at();
        }
        reg_d0.h[0] += 1;
        if (reg_d7.w & 2) {
            test_print_at();
        }
        reg_d0.h[0] += 1;
        if (reg_d7.w & 4) {
            test_print_at();
        }
    }
    input_get_p1_held();
    held = reg_d0.w;
    if ((held & 0x8000) && (held & 0x10)) {
        reg_d0.w = 0;
        test_screen_request();
    }
    reg_d0.w = 0;
}

u8 test_input_lever_marks[24] = {
    0xFF, 0xFF, 0x00, 0x01, 0xFE, 0x01, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFE, 0x00, 0xFF, 0xFF,
    0xFF, 0x02, 0x00, 0x02, 0xFE, 0xFE, 0x00, 0x00,
};

u8 test_input_text_title[15] = {
    0x0A, 0x32, 0x00, 0x49, 0x4E, 0x50, 0x55, 0x54, 0x20, 0x54, 0x45, 0x53, 0x54, 0x20, 0xFF,
};

s32 test_input_text_service[8] = {
    0x53002C04, 0x49565245, 0x20204543, 0x202D2020, 0x0000FF20, 0x00000000, 0x00000000, 0x00000000,
};

s32 test_input_text_test[8] = {
    0x54002A04, 0x20545345, 0x20202020, 0x202D2020, 0x0000FF20, 0x00000000, 0x00000000, 0x00000000,
};

s32 test_input_text_players[8] = {
    0x20002604, 0x20202020, 0x20202020, 0x20503120, 0x20202020, 0xFF503220, 0x00000000, 0x00000000,
};

s32 test_input_text_coin[8] = {
    0x43002404, 0x204E494F, 0x20202020, 0x202D2020, 0x20202020, 0xFF2D2020, 0x00000000, 0x00000000,
};

s32 test_input_text_start[8] = {
    0x53002204, 0x54524154, 0x20202020, 0x202D2020, 0x20202020, 0xFF2D2020, 0x00000000, 0x00000000,
};

s32 test_input_text_lever_top[8] = {
    0x4C001E04, 0x52455645, 0x20202020, 0x202D2D2D, 0x20202020, 0xFF2D2D2D, 0x00000000, 0x00000000,
};

s32 test_input_text_lever_middle[8] = {
    0x20001D04, 0x20202020, 0x20202020, 0x202D202D, 0x20202020, 0xFF2D202D, 0x00000000, 0x00000000,
};

s32 test_input_text_lever_bottom[8] = {
    0x20001C04, 0x20202020, 0x20202020, 0x202D2D2D, 0x20202020, 0xFF2D2D2D, 0x00000000, 0x00000000,
};

s32 test_input_text_shot[8] = {
    0x53001804, 0x20544F48, 0x20202020, 0x202D2D2D, 0x20202020, 0xFF2D2D2D, 0x00000000, 0x00000000,
};

s32 test_input_text_exit[8] = {
    0x45000803, 0x20544958, 0x5031203D, 0x41545320, 0x26205452, 0x4F485320, 0xFF203154, 0x00000000,
};

u8 test_input_mark_service[8] = { 0x0F, 0x2C, 0x00, 0x2F, 0xFF, 0x00, 0x00, 0x00 };

u8 test_input_mark_test[8] = { 0x0F, 0x2A, 0x00, 0x2F, 0xFF, 0x00, 0x00, 0x00 };

u8 test_input_mark_coin1[8] = { 0x0F, 0x24, 0x00, 0x2F, 0xFF, 0x00, 0x00, 0x00 };

u8 test_input_mark_coin2[8] = { 0x17, 0x24, 0x00, 0x2F, 0xFF, 0x00, 0x00, 0x00 };

u8 test_input_mark_start1[8] = { 0x0F, 0x22, 0x00, 0x2F, 0xFF, 0x00, 0x00, 0x00 };

u8 test_input_mark_start2[8] = { 0x17, 0x22, 0x00, 0x2F, 0xFF, 0x00, 0x00, 0x00 };

u8 test_input_mark[4] = { 0x2F, 0xFF, 0x00, 0x00 };
