#include "common.h"
#include "continue_screen.h"
#include "task.h"

#ifdef DDPDOJ_PC
#include "pc_frontend_abi.h"
#endif

void continue_panel_step_countdown();
void continue_panel_step_erase_small();
void continue_panel_step_countdown_wide();
void continue_panel_step_erase_wide();


void (*continue_step_routines[8])(void) = {
    0,
    continue_panel_step_countdown,
    continue_panel_step_erase_small,
    continue_panel_step_countdown_wide,
    continue_panel_step_erase_wide,
    0,
    0,
    0,
};

char continue_text_continue[16] = " CONTINUE     ";

char continue_text_blank[16] = "              ";

u32 continue_title_frames[20] = {
    0xF8F001A, 0x102F001A, 0x107F001A, 0x10CF001A, 0x111F001A, 0x116F001A, 0x11BF001A, 0x120F001A,
    0x125F001A, 0x12AF001A, 0x12FF001A, 0x134F001A, 0x139F001A, 0x13EF001A, 0x143F001A, 0x148F001A,
    0x14DF001A, 0x152F001A, 0x0000, 0x0000,
};

/* The frames of each countdown digit, behind the table that points at them. */
typedef struct {
    /* 0x00 */ u32 *sets[10];
    /* 0x28 */ u32 frames[10][4];
} ContinueDigitFrames;

ContinueDigitFrames continue_digit_frames = {
    {
        continue_digit_frames.frames[0],
        continue_digit_frames.frames[1],
        continue_digit_frames.frames[2],
        continue_digit_frames.frames[3],
        continue_digit_frames.frames[4],
        continue_digit_frames.frames[5],
        continue_digit_frames.frames[6],
        continue_digit_frames.frames[7],
        continue_digit_frames.frames[8],
        continue_digit_frames.frames[9],
    },
    {
        { 0xBCF001A, 0xBD3001A, 0xBD7001A },
        { 0xC2F001A, 0xC33001A, 0xC37001A },
        { 0xC8F001A, 0xC93001A, 0xC97001A },
        { 0xCEF001A, 0xCF3001A, 0xCF7001A },
        { 0xD4F001A, 0xD53001A, 0xD57001A },
        { 0xDAF001A, 0xDB3001A, 0xDB7001A },
        { 0xE0F001A, 0xE13001A, 0xE17001A },
        { 0xE6F001A, 0xE73001A, 0xE77001A },
        { 0xECF001A, 0xED3001A, 0xED7001A },
        { 0xF2F001A, 0xF33001A, 0xF37001A },
    },
};

ContinuePlayer continue_player1 = { 0x36, 1, { 2, 3 }, { 4, 5 }, { 6, 7 }, { 8, 9 } };
ContinuePlayer continue_player2 = { 0x36, 0xF, { 2, 3 }, { 4, 5 }, { 6, 7 }, { 8, 9 } };

void bomb_palette_load(void);
void continue_panel_small_text_erase(void);
void continue_panel_step_done(void);
void continue_task_close_panel(void);

void player_slot_request_destroyed(void) {
#ifndef DDPDOJ_PC
    void player_slot_request(void);
#endif
    *(u16 *)&reg_d1 = 1;
    player_slot_request();
}

void player_slot_request_bomb_display(void) {
#ifndef DDPDOJ_PC
    void player_slot_request(void);
#endif
    *(u16 *)&reg_d1 = 9;
    player_slot_request();
}

extern u16 bomb_palette_load_first_table[];


void bomb_palette_load_first(void) {
    reg_a0 = (u8 *)bomb_palette_load_first_table;
    bomb_palette_load();
}

extern u16 bomb_palette_load_second_table[];


void bomb_palette_load_second(void) {
    reg_a0 = (u8 *)bomb_palette_load_second_table;
    bomb_palette_load();
}

void sprite_palette_load(void);

void bomb_palette_load(void) {
    *(u16 *)&reg_d0 = 6;
    sprite_palette_load();
}

s32 text_palette_load();
extern u16 continue_palette[];
extern u8 g_continue_panels[];

void continue_panels_clear(void) {
    s32 var_a0;
    u8 *temp_a1;

    var_a0 = 0;
    do {
        temp_a1 = g_continue_panels + var_a0;
        (*(s8 *)((u8 *)(temp_a1) + (0))) = 0;
        var_a0 += 8;
        (*(s8 *)((u8 *)(temp_a1) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (7))) = 0;
    } while (var_a0 < 0x24);
    if (var_a0 < 0x2C) {
        do {
            *(g_continue_panels + var_a0) = 0;
            var_a0 += 1;
        } while (var_a0 < 0x2C);
    }
    reg_a0 = (u8 *)continue_palette;
    reg_d0.h[0] = 0xD;
    text_palette_load();
}

extern u8 g_continue_panel_p2[];

void continue_panel_step_set(void) {
    u32 s_d0;
    u32 s_d1;
    u32 s_d2;
    u32 s_d3;
    u32 s_d4;
    u32 s_d5;
    u32 s_d6;
    u32 s_d7;
    u8 *s_a0;
    u8 *s_a1;
    u8 *s_a2;
    u8 *s_a3;
    u8 *s_a4;
    u8 *s_a5;
    u8 *s_a6;

    s_d0 = reg_d0.w;
    s_d1 = reg_d1.w;
    s_d2 = reg_d2.w;
    s_d3 = reg_d3.w;
    s_d4 = reg_d4.w;
    s_d5 = reg_d5.w;
    s_d6 = reg_d6.w;
    s_d7 = reg_d7.w;
    s_a0 = reg_a0;
    s_a1 = reg_a1;
    s_a2 = reg_a2;
    s_a3 = reg_a3;
    s_a4 = reg_a4;
    s_a5 = reg_a5;
    s_a6 = reg_a6;
    reg_a4 = (u8 *)g_continue_panels;
    if (reg_d1.h[0] == 0) {
        goto next_1;
    }
    reg_a4 = (u8 *)g_continue_panel_p2;
next_1:
    if (*(u16 *) reg_a4 == reg_d0.h[0]) {
        goto next_2;
    }
    *(u16 *) reg_a4 = reg_d0.h[0];
    *(u16 *) (reg_a4 + 2) = 0;
    *(u16 *) (reg_a4 + 4) = reg_d1.h[0];
next_2:
    reg_d0.w = s_d0;
    reg_d1.w = s_d1;
    reg_d2.w = s_d2;
    reg_d3.w = s_d3;
    reg_d4.w = s_d4;
    reg_d5.w = s_d5;
    reg_d6.w = s_d6;
    reg_d7.w = s_d7;
    reg_a0 = s_a0;
    reg_a1 = s_a1;
    reg_a2 = s_a2;
    reg_a3 = s_a3;
    reg_a4 = s_a4;
    reg_a5 = s_a5;
    reg_a6 = s_a6;
}

void continue_panel_close(void) {
    u32 s_d0;
    u32 s_d1;
    u32 s_d2;
    u32 s_d3;
    u32 s_d4;
    u32 s_d5;
    u32 s_d6;
    u32 s_d7;
    u8 *s_a0;
    u8 *s_a1;
    u8 *s_a2;
    u8 *s_a3;
    u8 *s_a4;
    u8 *s_a5;
    u8 *s_a6;

    s_d0 = reg_d0.w;
    s_d1 = reg_d1.w;
    s_d2 = reg_d2.w;
    s_d3 = reg_d3.w;
    s_d4 = reg_d4.w;
    s_d5 = reg_d5.w;
    s_d6 = reg_d6.w;
    s_d7 = reg_d7.w;
    s_a0 = reg_a0;
    s_a1 = reg_a1;
    s_a2 = reg_a2;
    s_a3 = reg_a3;
    s_a4 = reg_a4;
    s_a5 = reg_a5;
    s_a6 = reg_a6;
    reg_a4 = (u8 *)g_continue_panels;
    if (reg_d1.h[0] == 0) {
        goto next_1;
    }
    if (*(u16 *) g_continue_panels == 3) {
        goto next_2;
    }
    reg_a4 = (u8 *)g_continue_panel_p2;
next_1:
    if ((reg_d0.h[0] = *(u16 *) reg_a4) == 0) {
        goto next_4;
    }
    reg_d2.h[0] = 2;
    if (reg_d0.h[0] == 1) {
        goto next_3;
    }
next_2:
    reg_d2.h[0] = 4;
next_3:
    *(u16 *) reg_a4 = reg_d2.h[0];
    *(u16 *) (reg_a4 + 2) = 0;
    *(u16 *) (reg_a4 + 4) = reg_d1.h[0];
next_4:
    reg_d0.w = s_d0;
    reg_d1.w = s_d1;
    reg_d2.w = s_d2;
    reg_d3.w = s_d3;
    reg_d4.w = s_d4;
    reg_d5.w = s_d5;
    reg_d6.w = s_d6;
    reg_d7.w = s_d7;
    reg_a0 = s_a0;
    reg_a1 = s_a1;
    reg_a2 = s_a2;
    reg_a3 = s_a3;
    reg_a4 = s_a4;
    reg_a5 = s_a5;
    reg_a6 = s_a6;
}

typedef void (*Fn)();


void continue_panels_update(u16 *arg0) {
    u16 *var_a0;
    u16 temp_v1_2;

    var_a0 = (u16 *)(arg0);
    reg_a4 = (u8 *)(((u16 *)g_continue_panels));
    reg_d7.w = 1;
    do {
        temp_v1_2 = *(u16 *)reg_a4;
        reg_d0.h[0] = temp_v1_2;
        if (temp_v1_2 != 0) {
            ((Fn)*(u32 *)((u8 *)continue_step_routines + (reg_d0.h[0] * 4)))();
        }
        var_a0 = (u16 *)(reg_a4 + 0x16);
        reg_a4 = (u8 *)(var_a0);
    } while ((s16)(--reg_d7.h[0]) >= 0);
}


s32 deferred_text_clear();
s32 text_layer_put_hex_digit();
#ifndef DDPDOJ_PC
s32 stage_clear_running_check();
#endif
#ifndef DDPDOJ_PC
s32 text_layer_print();
#endif
s32 sfx_countdown();
#ifdef DEATH_LABEL
extern u8 credit_label_p1[];
extern u8 credit_label_p2[];
extern u16 D_0028E314;
extern u16 D_0028E318;
#endif

void continue_panel_step_countdown(void) {
    u16 temp_a0;

    stage_clear_running_check();
    if (cond_flag != 0) {
        continue_panel_small_text_erase();
        return;
    }
    if (*(u16 *)(reg_a4 + 2) == 0) {
        reg_d0.h[0] = 1;
        reg_d1.h[0] = 0x33;
        reg_a0 = (u8 *)continue_text_blank;
        reg_d2.h[0] = 2;
        text_layer_print();
        reg_d0.h[0] = 0xF;
        reg_d1.h[0] = 0x33;
        reg_a0 = (u8 *)continue_text_blank;
        reg_d2.h[0] = 2;
        text_layer_print();
        reg_d0.h[0] = 1;
        reg_d1.h[0] = 0x32;
        reg_a0 = (u8 *)continue_text_blank;
        reg_d2.h[0] = 2;
        text_layer_print();
        reg_d0.h[0] = 0xF;
        reg_d1.h[0] = 0x32;
        reg_a0 = (u8 *)continue_text_blank;
        reg_d2.h[0] = 2;
        text_layer_print();
        *(u16 *)(reg_a4 + 2) = 1U;
        *(u8 *)(reg_a4 + 0xD) = 0U;
        reg_d0.h[0] = 0x8C;
        reg_d1.h[0] = 0x400;
        reg_d2.w = 3;
        reg_d3.w = 0x13;
        deferred_text_clear();
        reg_d0.h[0] = 0x74;
        reg_d1.h[0] = 0xC00;
        reg_d2.w = 7;
        reg_d3.w = 3;
        deferred_text_clear();
        reg_d0.h[0] = 1;
        reg_d1.h[0] = 0x33;
        if (*(u16 *)(reg_a4 + 4) != 0) {
            reg_d1.h[0] = 0x33;
            reg_d0.h[0] = 0xF;
        }
        *(u16 *)(reg_a4 + 6) = (u16) reg_d1.h[0];
        *(u16 *)(reg_a4 + 8) = (u16) reg_d0.h[0];
    }
    reg_d1.h[0] = *(u16 *)(reg_a4 + 6);
    temp_a0 = *(u16 *)(reg_a4 + 8);
    reg_d0.h[0] = temp_a0;
    reg_a0 = (u8 *)continue_text_continue;
    reg_d2.h[0] = 2;
    text_layer_print();
    reg_d4.w = 0;
    reg_d4.b[0] = (u8) *(s8 *)(reg_a4 + 0xA);
    if (*(u8 *)(reg_a4 + 0xD) != reg_d4.b[0]) {
        *(u8 *)(reg_a4 + 0xD) = (u8) reg_d4.b[0];
        sfx_countdown();
    }
    reg_d4.w = 0;
    reg_d4.b[0] = (u8) *(s8 *)(reg_a4 + 0xA);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
    reg_d0.h[0] += 0xA;
    reg_d1.h[0] = *(u16 *)(reg_a4 + 6);
    reg_d2.h[0] = 2;
    text_layer_put_hex_digit();
#ifdef DEATH_LABEL
    if (*(u16 *)(reg_a4 + 4) == 0) {
        reg_d0.h[0] = 1;
        reg_d1.h[0] = 0x32;
        reg_a0 = (u8 *)credit_label_p1;
        reg_d2.h[0] = 2;
        text_layer_print();
        reg_d0.h[0] = 1;
        reg_d4.w = 0;
        reg_d1.h[0] = 0x32;
        reg_d2.h[0] = 2;
        reg_d4.h[0] = D_0028E318;
        reg_d0.h[0] += 0xA;
        text_layer_put_hex_digit();
    } else {
        reg_d0.h[0] = 0xF;
        reg_d1.h[0] = 0x32;
        reg_a0 = (u8 *)credit_label_p2;
        reg_d2.h[0] = 2;
        text_layer_print();
        reg_d0.h[0] = 0xF;
        reg_d4.w = 0;
        reg_d1.h[0] = 0x32;
        reg_d2.h[0] = 2;
        reg_d4.h[0] = D_0028E314;
        reg_d0.h[0] += 0xA;
        text_layer_put_hex_digit();
    }
#endif
}


void continue_panel_step_erase_small(void) {
    if (*(u16 *)(reg_a4 + 2) != 0) {
        continue_panel_step_done();
        return;
    }
    *(u16 *)(reg_a4 + 2) = 1U;
    continue_panel_small_text_erase();
}


void continue_panel_small_text_erase() {
    reg_d0.h[0] = 1;
    reg_d1.h[0] = 0x33;
    if (*(u16 *)(reg_a4 + 4) != 0) {
        reg_d1.h[0] = 0x33;
        reg_d0.h[0] = 0xF;
    }
    *(u16 *)(reg_a4 + 6) = (u16) reg_d1.h[0];
    *(u16 *)(reg_a4 + 8) = (u16) reg_d0.h[0];
    reg_a0 = (u8 *)continue_text_blank;
    reg_d2.h[0] = 2;
    text_layer_print();
    continue_panel_step_done();
    if (*(u16 *)(reg_a4 + 4) == 0) {
        reg_d0.h[0] = 1;
        reg_d1.h[0] = 0x32;
        reg_a0 = (u8 *)continue_text_blank;
        reg_d2.h[0] = 2;
        text_layer_print();
        return;
    }
    reg_d0.h[0] = 0xF;
    reg_d1.h[0] = 0x32;
    reg_a0 = (u8 *)continue_text_blank;
    reg_d2.h[0] = 2;
    text_layer_print();
}


void continue_panel_step_done(void) {
    *(*(s16 **)&reg_a4) = 0;
}

s32 deferred_text_put();
s32 deferred_text_put_sheet();
#ifdef DEATH_LABEL
s32 text_layer_put_hex_digit();
extern u8 credit_label_p1[];
extern u8 credit_label_p2[];
extern u16 D_0028E314;
extern u16 D_0028E318;
#endif

void continue_panel_step_countdown_wide(void) {
    s32 temp_a3;
    u32 temp_a2;
    u32 temp_a3_2;
    u8 temp_a0;

    if (*(u16 *)(reg_a4 + 2) == 0) {
        *(u16 *)(reg_a4 + 2) = 1U;
        *(u8 *)(reg_a4 + 0xD) = 0U;
        *(u16 *)(reg_a4 + 0x10) = 0U;
        *(s16 *)(reg_a4 + 0xE) = 3;
        *(u16 *)(reg_a4 + 0x14) = 0U;
        *(s16 *)(reg_a4 + 0x12) = 1;
        reg_d0.h[0] = 1;
        reg_d1.h[0] = 0x33;
        reg_a0 = (u8 *)continue_text_blank;
        reg_d2.h[0] = 2;
        text_layer_print();
        reg_d0.h[0] = 0xF;
        reg_d1.h[0] = 0x33;
        reg_a0 = (u8 *)continue_text_blank;
        reg_d2.h[0] = 2;
        text_layer_print();
        ((s16 *)g_continue_panel_p2)[0] = 0;
    }
#ifdef DEATH_LABEL
    reg_d0.h[0] = 1;
    reg_d1.h[0] = 0x32;
    reg_a0 = (u8 *)credit_label_p1;
    reg_d2.h[0] = 2;
    text_layer_print();
    reg_d0.h[0] = 1;
    reg_d4.w = 0;
    reg_d1.h[0] = 0x32;
    reg_d2.h[0] = 2;
    reg_d4.h[0] = D_0028E318;
    reg_d0.h[0] += 0xA;
    text_layer_put_hex_digit();
    reg_d0.h[0] = 0xF;
    reg_d1.h[0] = 0x32;
    reg_a0 = (u8 *)credit_label_p2;
    reg_d2.h[0] = 2;
    text_layer_print();
    reg_d0.h[0] = 0xF;
    reg_d4.w = 0;
    reg_d1.h[0] = 0x32;
    reg_d2.h[0] = 2;
    reg_d4.h[0] = D_0028E314;
    reg_d0.h[0] += 0xA;
    text_layer_put_hex_digit();
#endif
    *(u8 *)(reg_a4 + 0xF) -= 1;
    if ((s8) *(u8 *)(reg_a4 + 0xF) < 0) {
        *(u8 *)(reg_a4 + 0xF) = *(u8 *)(reg_a4 + 0xE);
        reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x10);
        temp_a3 = reg_tmp.h[0] & ~3;
        temp_a2 = *(u32 *)((u8 *)continue_title_frames + temp_a3);
        reg_d4.w = temp_a2;
        reg_d0.h[0] = 0x8C;
        reg_d1.h[0] = 0x400;
        reg_d2.w = 3;
        reg_d3.w = 0x13;
        deferred_text_put();
        *(u16 *)(reg_a4 + 0x10) += 4;
        if (*(u16 *)(reg_a4 + 0x10) == 0x44) {
            *(u16 *)(reg_a4 + 0x10) = 0U;
        }
    }
    reg_d4.w = 0;
    reg_d4.b[0] = (u8) *(s8 *)(reg_a4 + 0xA);
    reg_a0 = *(u8 **)((u8 *)continue_digit_frames.sets + (reg_d4.h[0] * 4));
    reg_a0 += *(u16 *)(reg_a4 + 0x14);
    temp_a3_2 = *(u32 *)reg_a0;
    reg_d4.w = temp_a3_2;
    reg_d0.h[0] = 0x74;
    reg_d1.h[0] = 0xC00;
    reg_d2.w = 7;
    reg_d3.w = 3;
    reg_d5.h[0] = 0xC;
    deferred_text_put_sheet();
    *(u8 *)(reg_a4 + 0x13) -= 1;
    if ((s8) *(u8 *)(reg_a4 + 0x13) < 0) {
        *(u8 *)(reg_a4 + 0x13) = *(u8 *)(reg_a4 + 0x12);
        *(u16 *)(reg_a4 + 0x14) += 4;
        if ((s16) *(u16 *)(reg_a4 + 0x14) >= 0xC) {
            *(u16 *)(reg_a4 + 0x14) = 0U;
        }
    }
    reg_d4.w = 0;
    reg_d4.b[0] = (u8) *(s8 *)(reg_a4 + 0xA);
    temp_a0 = *(u8 *)(reg_a4 + 0xD);
    if (temp_a0 != reg_d4.b[0]) {
        *(u8 *)(reg_a4 + 0xD) = (u8) reg_d4.b[0];
        sfx_countdown();
    }
}

void continue_panel_step_erase_wide() {
    if (*(u16 *)(reg_a4 + 2) == 0) {
        *(u16 *)(reg_a4 + 2) = 1U;
        reg_d0.h[0] = 0x8C;
        reg_d1.h[0] = 0x400;
        reg_d2.w = 3;
        reg_d3.w = 0x13;
        deferred_text_clear();
        reg_d0.h[0] = 0x74;
        reg_d1.h[0] = 0xC00;
        reg_d2.w = 7;
        reg_d3.w = 3;
        deferred_text_clear();
        reg_d0.h[0] = 1;
        reg_d1.h[0] = 0x32;
        reg_a0 = (u8 *)continue_text_blank;
        reg_d2.h[0] = 2;
        text_layer_print();
        reg_d0.h[0] = 0xF;
        reg_d1.h[0] = 0x32;
        reg_a0 = (u8 *)continue_text_blank;
        reg_d2.h[0] = 2;
        text_layer_print();
    }
    *(s16 *)reg_a4 = 0;
}


void continue_count_store(void)
{
    *(u16 *)(reg_a5 + 4) = 0x93C;
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0x10);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x12);
    (*(u32 *)&reg_a0) = reg_tmp.w;
    reg_d0.b[0] = reg_a5[5];
    *(u8 *)(*(u32 *)&reg_a0) = reg_d0.b[0];
}

#ifndef DDPDOJ_PC
s32 player_panel_show();
#endif
s32 hud_p1_caption_clear_shifted();
s32 hud_p2_caption_clear_shifted();

void continue_task_begin() {
    *(s8 *)(reg_a5 + 3) = 1;
    reg_a4 = (u8 *)&continue_player1;
    if (*(u8 *)(reg_a5 + 6) != 0) {
        reg_a4 = (u8 *)&continue_player2;
    }
    reg_tmp.w = (u32) reg_a4;
    *(u16 *)(reg_a5 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0xA) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a5 + 0x14) = 1;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    player_panel_show();
    if (*(u8 *)(reg_a5 + 6) == 0) {
        hud_p1_caption_clear_shifted();
    } else {
        hud_p2_caption_clear_shifted();
    }
    continue_count_store();
}


void continue_task_finish(void) {
    *(s8 *)(reg_a5 + 3) = 2;
    continue_count_store();
    continue_task_close_panel();
}


void continue_task_close_panel(void) {
    reg_d1.w = 0;
    reg_d1.b[0] = *(u8 *)(reg_a5 + 6);
    continue_panel_close();
    task_stop_self();
}

s32 fades_reset();                            /* extern */
s32 sound_stop_effects();                            /* extern */
#ifndef DDPDOJ_PC
s32 music_stop();                            /* extern */
#endif
extern u16 g_loop;
extern u16 g_stage;
extern u8 D_0028ED64;

void continue_to_game_over(void) {
    music_stop();
    sound_stop_effects();
    fades_reset();
    task_reset_all();
    reg_d0.h[0] = TASK_GAME_OVER;
    task_start();
    if (g_loop != 1) {
        if ((s32) 0 < g_stage) {
            goto block_3;
        }
    } else {
block_3:
        D_0028ED64 = 1;
    }
}

s32 bee_counts_reset();
s32 credit_display_changed_check();
s32 enemies_stop();
s32 game_both_players_out_check();
extern u8 g_setting_continue;
extern u8 g_simulation_active;
extern u8 D_002BF3EA[];
extern u8 *reg_call_target_as_u8_p;

void continue_task(void) {
#ifndef DDPDOJ_PC
    s32 player_slot_request();
#endif
    reg_tmp.h[1] = *(u16 *) (reg_a5 + 8);
    reg_tmp.h[0] = *(u16 *) (reg_a5 + 0xA);
    reg_a4 = (u8 *) reg_tmp.w;
    if (reg_a5[3] == 0) {
        continue_task_begin();
        return;
    }
    if (reg_a5[3] == 2) {
        continue_task_close_panel();
        return;
    }
    if (reg_a5[3] == 3) {
        continue_task_finish();
        return;
    }
    if (reg_a5[3] == 4) {
        continue_to_game_over();
        return;
    }
    if (g_loop != 0) {
        goto next_8;
    }
    if (g_setting_continue == 0) {
        goto next_8;
    }
    if (g_simulation_active != 0) {
        goto next_8;
    }
    game_both_players_out_check();
    if (cond_flag == 0) {
        goto next_2;
    }
    if (reg_a5[2] != 0) {
        goto next_1;
    }
    reg_a5[2] = 1;
    bee_counts_reset();
    continue_count_store();
next_1:
    reg_d0.w = 3;
    reg_d1.w = 0;
    continue_panel_step_set();
    enemies_stop();
    goto next_4;
next_2:
    if (reg_a5[2] == 0) {
        goto next_3;
    }
    reg_a5[2] = 0;
    reg_d1.w = 0;
    reg_d1.b[0] = reg_a5[6];
    continue_panel_close();
    continue_count_store();
next_3:
    reg_d0.w = 1;
    reg_d1.w = 0;
    reg_d1.b[0] = reg_a5[6];
    continue_panel_step_set();
next_4:
    stage_clear_running_check();
    if (cond_flag != 0) {
        return;
    }
    reg_tmp.h[1] = *(u16 *) (reg_a4 + 0xC);
    reg_tmp.h[0] = *(u16 *) (reg_a4 + 0xE);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_call_target_as_u8_p = reg_a0;
    ((Fn) reg_call_target_as_u8_p)();
    if (((reg_d0.h[0] &= 0x70) & 0xFFFF) == 0) {
        goto next_6;
    }
    game_both_players_out_check();
    if (cond_flag == 0) {
        goto next_5;
    }
    reg_d0.w = 0;
    reg_d0.b[0] = reg_a5[6];
    reg_d1.h[0] = 8;
    player_slot_request();
    goto next_6;
next_5:
    reg_a5[4] = 0;
next_6:
    reg_a5[4] -= 1;
    if ((s8) reg_a5[4] >= 0) {
        goto next_10;
    }
    reg_a5[4] = 60;
    reg_a5[5] -= 1;
    if ((s8) reg_a5[5] >= 0) {
        goto next_10;
    }
next_8:
    reg_tmp.h[1] = *(u16 *) (reg_a4 + 4);
    reg_tmp.h[0] = *(u16 *) (reg_a4 + 6);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_call_target_as_u8_p = reg_a0;
    ((Fn) reg_call_target_as_u8_p)();
    if (g_simulation_active != 0) {
        goto next_9;
    }
    if (g_loop != 0) {
        goto next_9;
    }
    game_both_players_out_check();
    if (cond_flag == 0) {
        goto next_11;
    }
next_9:
    reg_a5[3] = 4;
    continue_to_game_over();
    return;
next_11:
    reg_a5[3] = 3;
    continue_task_finish();
    return;
next_10:
    reg_d0.w = 0;
    reg_d0.b[0] = reg_a5[6];
    credit_display_changed_check();
    if (cond_flag == 0) {
        goto next_12;
    }
    continue_count_store();
next_12:
    game_both_players_out_check();
    if (cond_flag == 0) {
        goto next_13;
    }
    reg_d0.b[0] = reg_a5[5];
    D_002BF3EA[0] = reg_d0.b[0];
    return;
next_13:
    reg_tmp.h[1] = *(u16 *) (reg_a4 + 0x10);
    reg_tmp.h[0] = *(u16 *) (reg_a4 + 0x12);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.b[0] = reg_a5[5];
    *reg_a0 = reg_d0.b[0];
}

/* .bss (the compiler lays these out in reverse) */
u8 g_continue_panels[32];

#ifdef DDPDOJ_PC
#include "pc_data_alias.h"

PC_DATA_ALIAS(D_002BF3EA, g_continue_panels, 0xa);
PC_DATA_ALIAS(g_continue_panel_p2, g_continue_panels, 0x16);
#endif
