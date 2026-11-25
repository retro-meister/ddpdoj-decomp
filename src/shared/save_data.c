#include "common.h"
#include "sdk/ps2sdk.h"
#include "pad.h"
#include "cd.h"

void func_00227C90(void);
void func_00227CD0(void);
void func_00227E30(void);
void func_00227FE0(void);
void func_00228060(void);
void func_00229950(s32 x, s32 y, s32 alpha, s32 mode, s32 kind);
void func_0022A8F0();
void func_0022A930();
void func_0022A9A0();
void func_0022AA00();
void func_0022AD20(s32 arg0, s32 arg1);
void func_0022B1D0(void);
s32 func_0022B4B0(void);
s32 func_0022B540(void);
void func_0022B7A0(s32 arg0);
void func_0022BA60(void);
s32 replay_disc_headers_load(void);
s32 replay_disc_file_load(u8 arg0);
void func_0022BFD0();
void func_0022C1E0();
void func_0022C1F0();
void func_0022C450();

extern s8 g_replay_slots_state;
extern s32 g_replay_slots_alpha;

void replay_slots_closing(void) {
    if (g_replay_slots_alpha == 0) {
        g_replay_slots_state = 0;
    }
}

extern s8 D_0028EB04;
extern s32 D_0028EB90;
extern s8 g_replay_slots_fade;

void replay_slots_disc_scan(void) {
    if (replay_disc_headers_load() != 0) {
        g_replay_slots_state = 3;
        g_replay_slots_fade = 1;
        D_0028EB90 = 0x40;
        D_0028EB04 = 1;
    }
}

extern u8 g_replay_slots_state_as_u8;

void replay_slots_disc_ready(void) {
    g_replay_slots_state_as_u8 = 4;
}

s32 sfx_menu_move();
s32 replay_slots_close();
extern u8 g_replay_slots_pad;
extern s8 g_replay_slots_cursor;
extern u8 g_replay_slot_infos[];
void replay_slots_disc_select(void) {
    s32 sfx_menu_confirm();
    s32 temp_a0;
    s32 temp_a0_3;
    u16 temp_a0_2;

    temp_a0 = g_pad_trigger[g_replay_slots_pad];
    if (temp_a0 & 0x40) {
        sfx_menu_confirm();
        replay_slots_close();
    } else if (temp_a0 & 0x20) {
        temp_a0_2 = *(u16 *)(g_replay_slot_infos + (g_replay_slots_cursor << 0xA));
        if ((temp_a0_2 != 0) && (temp_a0_2 != 3)) {
            g_replay_slots_state = 6;
            sfx_menu_confirm();
        }
    }
    temp_a0_3 = g_pad_repeat[g_replay_slots_pad];
    if (temp_a0_3 & 0x1000) {
        sfx_menu_move();
        g_replay_slots_cursor -= 1;
        if (0 > g_replay_slots_cursor) {
            g_replay_slots_cursor = 9;
        }
    } else if (temp_a0_3 & 0x4000) {
        sfx_menu_move();
        g_replay_slots_cursor += 1;
        if (g_replay_slots_cursor >= 0xA) {
            g_replay_slots_cursor = 0;
        }
    }
}

extern s8 g_replay_slot_loaded;
extern u8 g_replay_slots_cursor_as_u8;
extern u8 D_0028ED30;
extern u8 D_0028ED31;
extern u8 D_0028ED32;
extern u8 D_0028ED33;
extern u8 D_0028ED34;
extern u8 D_0028ED35;
extern u8 D_0028ED36;
extern u8 D_0028ED37;
extern u8 g_replay_file_loaded[];
extern u8 g_replay_file[];
extern u8 D_006C58D8[];
extern u8 D_006C58D9[];
extern u8 D_006C58DA[];
extern u8 D_006C58DB[];
extern u8 D_006C58DC[];
extern u8 D_006C58DD[];
extern u8 D_006C58DE[];
extern u8 D_006C58DF[];
extern u8 g_replay_snapshot[];
s32 replay_slots_disc_load(void) {
    s32 delta_encode();
    s32 replay_file_pointers_decode();
    if (replay_disc_file_load(g_replay_slots_cursor_as_u8) != 0) {
        g_replay_slot_loaded = *(s8 *)&g_replay_slots_cursor_as_u8;
        D_0028EB04 = 1;
        D_0028EB90 = 0x40;
        memcpy(g_replay_file, g_replay_file_loaded, 0x202E8);
        delta_encode(g_replay_snapshot);
        replay_file_pointers_decode(g_replay_file);
        D_0028ED30 = D_006C58D8[0];
        D_0028ED31 = D_006C58D9[0];
        D_0028ED32 = D_006C58DA[0];
        D_0028ED33 = D_006C58DB[0];
        D_0028ED34 = D_006C58DC[0];
        D_0028ED35 = D_006C58DD[0];
        D_0028ED36 = D_006C58DE[0];
        D_0028ED37 = D_006C58DF[0];
        return 3;
    }
    return 1;
}

typedef struct {
    u16 status;
    u16 f02;
    u16 f04;
    u16 f06;
    u16 f08;
    u16 f0A;
    u16 f0C;
    u16 f0E;
    u8 pad10[0x28];
    u8 f38;
    u8 f39;
    u8 f3A;
    u8 f3B;
} SaveInfo;

extern s32 sprintf(char *buf, const char *format, ...);
extern char *strcpy(char *dst, const char *src);
extern void frame_draw_column(s32 x, s32 y, s32 alpha);
extern void glyph_queue_clear(void);
extern void glyph_queue_flush(void);
extern char *D_00271D00[];
extern char *D_00271D10[];
extern char *D_0028DDB0[2];
extern s32 D_00289D70[];
extern char D_00289DD8[];
extern char D_00289DE0[];
extern char D_00289DE8[];
extern char D_00289DF8[];
extern char D_00289E08[];
extern char D_00289E18[];
extern char D_00289E20[];
extern char D_00289E28[];

void replay_slot_draw(s32 slot, s32 x, s32 y, s32 alpha, s32 selected, SaveInfo *info) {
    extern void text_queue_clear(void);
    extern void text_flush(void);
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 alpha, s32 attr, s32 wide);
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    char buf[16];
    u32 save_d6;
    u32 save_d7;
    s32 a;
    s32 b;
    s32 fade;

    if (alpha == 0) {
        return;
    }
    save_d0 = reg_d0.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    text_queue_clear();
    frame_draw_column(x, y, alpha);
    if (selected != 0) {
        gfx_draw_color_box(x + 8, y + 8, 0x1A, 0xD0, 0x12C, alpha, 0xFF, 1, 1);
    } else {
        fade = alpha >= 0x40 ? 0x40 : alpha;
        gfx_draw_color_box(x + 8, y + 8, 0x1A, 0xD0, 0x12C, fade, 1, 1, 0x40);
    }
    text_flush();
    glyph_queue_clear();
    reg_a0 = (u8 *)buf;
    a = info->f04;
    if (a != 0xFF) {
        b = info->f02;
    } else {
        b = info->f06;
        a = info->f08;
    }
    sprintf(buf, D_00289DD8, slot + 1);
    glyph_queue_add(x + D_00289D70[0], y + D_00289D70[1], 0x12C, 0, 0x80, alpha, 1);
    switch (info->status) {
    case 0:
        strcpy(buf, D_00289DE0);
        glyph_queue_add(x + D_00289D70[0], y + D_00289D70[1] + 0x60, 0x12C, 0, 0x80, alpha, 1);
        break;
    case 2:
        strcpy(buf, D_00289DE8);
        glyph_queue_add(x + D_00289D70[0], y + D_00289D70[1] + 0x60, 0x12C, 0, 0x80, alpha, 1);
        break;
    case 3:
        strcpy(buf, D_00289DF8);
        glyph_queue_add(x + D_00289D70[0], y + D_00289D70[1] + 0x60, 0x12C, 0, 0x80, alpha, 1);
        break;
    default:
        sprintf(buf, D_00289E08, info->f0C + 1, info->f0E + 1);
        glyph_queue_add(x + D_00289D70[2], y + D_00289D70[3], 0x12C, 0, 0x80, alpha, 0);
        sprintf(buf, D_00289E18, D_00271D10[info->f0A]);
        glyph_queue_add(x + D_00289D70[4], y + D_00289D70[5], 0x12C, 0, 0x80, alpha, 0);
        sprintf(buf, D_00289E18, D_0028DDB0[b / 2]);
        glyph_queue_add(x + D_00289D70[6], y + D_00289D70[7], 0x12C, 0, 0x80, alpha, 0);
        sprintf(buf, D_00289E18, D_00271D00[a / 2]);
        glyph_queue_add(x + D_00289D70[8], y + D_00289D70[9], 0x12C, 0, 0x80, alpha, 0);
        sprintf(buf, D_00289E20, info->f38, info->f39);
        glyph_queue_add(x + D_00289D70[10], y + D_00289D70[11], 0x12C, 0, 0x80, alpha, 0);
        sprintf(buf, D_00289E28, info->f3A, info->f3B);
        glyph_queue_add(x + D_00289D70[12], y + D_00289D70[13], 0x12C, 0, 0x80, alpha, 0);
        break;
    }
    glyph_queue_flush();
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}

extern u8 g_replay_slots_fade_as_u8;
extern u8 g_replay_slot_infos_as_u8_a_a0x400[][0x400];

s32 replay_slots_draw(void) {
    s32 i;
    s32 y;

    if (g_replay_slots_state_as_u8 == 0) {
        return 0;
    }
    switch (g_replay_slots_fade_as_u8) {
    case 0:
        break;
    case 1:
        g_replay_slots_alpha += 4;
        if (g_replay_slots_alpha >= 0x80) {
            g_replay_slots_fade_as_u8 = 0;
            g_replay_slots_alpha = 0x80;
        }
        break;
    case 2:
        g_replay_slots_alpha -= 4;
        if (0 >= g_replay_slots_alpha) {
            g_replay_slots_alpha = 0;
            g_replay_slots_fade_as_u8 = 0;
        }
        break;
    }
    if (0 < g_replay_slots_alpha) {
        y = 0x18A;
        for (i = 0; i < 10; i++) {
            replay_slot_draw(i, y, 0, g_replay_slots_alpha, (i == g_replay_slots_cursor) ? 1 : 0, (SaveInfo *)g_replay_slot_infos_as_u8_a_a0x400[i]);
            y -= 0x22;
        }
    }
    return 1;
}

s32 fade_start_in();
s32 func_00221FF0();
s32 func_00224B50();
extern s8 D_0028EB84;
extern s8 D_0028EBE8_as_s8;
extern u8 D_0068DEC8[];
extern u8 D_0068DED8[];
extern u8 D_0068DEF0[];
void func_00227120(void) {
    u8 sp10[0x16];
    u8 sp30[0xA];
    u8 sp40[0xC];

    memcpy(sp10, D_0068DEF0, 0x16);
    memcpy(sp30, D_0068DED8, 0xA);
    memcpy(sp40, D_0068DEC8, 0xC);
    func_00221FF0();
    func_00224B50();
    memcpy(D_0068DEF0, sp10, 0x16);
    memcpy(D_0068DED8, sp30, 0xA);
    memcpy(D_0068DEC8, sp40, 0xC);
    D_0028EBE8_as_s8 = 0;
    D_0028EB84 = 0xA;
    fade_start_in();
}

extern u8 D_0028EBE0;
extern u8 g_replay_slots_from_disc;
void func_002271D0(void) {
    u8 sp10[0x16];
    u8 sp30[0xA];
    u8 sp40[0xC];

    memcpy(sp10, D_0068DEF0, 0x16);
    memcpy(sp30, D_0068DED8, 0xA);
    memcpy(sp40, D_0068DEC8, 0xC);
    func_00221FF0();
    func_00224B50();
    memcpy(D_0068DEF0, sp10, 0x16);
    memcpy(D_0068DED8, sp30, 0xA);
    memcpy(D_0068DEC8, sp40, 0xC);
    if (g_replay_slots_from_disc == 0) {
        D_0028EBE0 = 0;
        D_0028EB84 = 0xB;
        func_00227C90();
    } else {
        D_0028EBE0 = 0;
        D_0028EB84 = 0x16;
        func_00227E30();
    }
    while (D_0028EBE0 != 2) {
        func_00227CD0();
    }
    fade_start_in();
}

s32 fade_start_out();                            /* extern */
extern s8 D_0028EAC8;
extern s8 D_0028EB00;
extern s8 D_0028EB54;
extern s8 D_0028EB88;

void func_002272D0(void) {
    D_0028EB54 = 2;
    D_0028EB00 = 3;
    D_0028EB88 = 2;
    D_0028EB84 = 0;
    fade_start_out();
    D_0028EAC8 = 1;
}

typedef struct {
    u8 step;
    s8 state;
    s8 flag;
    s8 pad3;
    s16 value;
    s16 pad6;
} Fade;

extern Fade D_0028EBD8_as_Fade;
extern Fade D_0028EBE0_as_Fade;
extern Fade D_0028EBE8_as_Fade;
extern Fade D_0028EBF0_as_Fade;
extern Fade D_0028EBF8;
extern Fade D_0028EC00_as_Fade;
extern Fade D_0028EC08_as_Fade;
extern Fade D_0028EC10_as_Fade;
extern Fade D_0028EC18_as_Fade;

extern u8 *D_00270850[];

extern s8 D_0028EB58;
extern u16 D_0028E320_as_u16;
extern s8 D_002714F0[];
extern u8 D_00685010[];
extern void func_00222260(s32 command);
s32 func_00222340(s32);
extern s8 D_0028EB50;
s8 func_00221120(s32 arg0);
extern s8 D_002714F7[];
extern s8 D_0028EB4C;
extern s8 D_0028EB7C;
extern s8 D_0028EC24;
extern s32 D_0028EC7C;
s32 func_002365A0();
extern s16 D_0068DF02[];
extern s16 D_00270822[];
extern s8 D_002714FA[];
extern char D_00289E38[];
extern u8 D_0028E258;
extern u8 D_0028E280;
extern u8 *D_00271480[];
extern s32 D_0028DCF8;
extern s8 D_0028EC20;
extern s8 g_replay_mode_as_s8;
extern s16 D_00270810_as_s16_a[];
extern s16 D_00270828_as_s16_a[];
extern s16 D_00270838_as_s16_a[];
extern s16 D_0068DE90_as_s16_a[];
extern s16 D_0068DEA0_as_s16_a[];
extern s16 D_0068DEB0_as_s16_a[];
extern s16 D_0068DEC8_as_s16_a[];
extern s16 D_0068DECA[];
extern s16 D_0068DECC[];
extern s16 D_0068DECE[];
extern s16 D_0068DED0[];
extern s16 D_0068DED2[];
extern s16 D_0068DED8_as_s16_a[];
extern s16 D_0068DEDA[];
extern s16 D_0068DEDC[];
extern s16 D_0068DEDE[];
extern s16 D_0068DEE0[];
extern s16 D_0068DEF0_as_s16_a[];
extern s16 D_0068DEF2[];
extern s16 D_0068DEF4[];
extern s16 D_0068DEF6[];
extern s16 D_0068DEF8[];
extern s16 D_0068DEFA[];
extern s16 D_0068DEFC[];
extern s16 D_0068DEFE[];
extern s16 D_0068DF00[];
extern s16 D_0068DF04[];
extern u16 D_006C58A2[];
extern u16 D_006C58A4[];
extern u16 D_006C58A6[];
extern u16 D_006C58A8[];
extern u16 D_006C58AA[];
extern u16 D_006C58B0[];
extern u16 D_006C58B2[];
extern u16 D_006C58B4[];
extern u16 D_006C58B6[];
extern u16 D_006C58B8[];
extern u16 D_006C58BA[];
extern u16 D_006C58BC[];
extern u16 D_006C58BE[];
extern u16 D_006C58C0[];
extern u16 D_006C58C2[];
extern u16 D_006C58C6[];
extern u16 D_006C58C8[];
extern u16 D_006C58CA[];
extern u16 D_006C58CC[];
extern u16 D_006C58CE[];
extern u16 D_006C58D0[];
extern u16 D_006C58D2[];
extern u16 D_006C58D4[];
extern s8 D_002714F8[];
extern u8 D_00270890[];
extern s8 D_00271501[];
extern u8 D_0028DCA8[8];
extern s8 D_0028DCB0[8];
extern void func_00224BA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 flags);
extern u8 *D_002708D0[];
extern u8 **D_002709B0[];
extern u16 D_002712C0[];
extern s8 D_002712D8[];
extern s8 D_00271502[];
extern u8 *D_002709D0[];
extern u8 **D_00271290[];
extern u8 *D_0028DCC8;
extern u8 *D_0028DCCC;
extern u8 *D_00270AB0[];
extern u8 *D_0028DCE0;
extern s8 D_00271503[];
extern u16 D_00271458[];
extern s8 D_00271468[];
extern u8 *D_002712F0[];
extern u8 **D_00271440[];
extern u8 *D_002714B0[];
extern s8 D_002714FD[];
extern u8 *D_002716E0[];
extern u8 *D_0028DD98;
extern u8 D_00684CA0[];
extern s32 D_006880A0[];
extern s32 D_006880A4[];

static void func_00227310(Fade *fade) {
    D_0028E320_as_u16 = 0xE10;
    fade->value = 0x40;
    fade->state = 1;
    fade->step += 1;
    fade->flag = 1;
    D_0028EB90 = 0x40;
    D_0028EB04 = 1;
    D_0028EB54 = 0;
    D_0028EB50 = 0;
}

s32 func_00227350(Fade *fade, s32 command) {
    s32 func_00222530(s32);
    if (func_00222530(command) != 0) {
        fade->step += 1;
        D_0028EB58 = 1;
        D_0028EB90 = 0x40;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        return 1;
    }
    return 0;
}

static s32 func_002273B0(Fade *fade, s32 command) {
    fade->step += 1;
    D_0028EB58 = 1;
    D_0028EB90 = 0x40;
    D_0028EB54 = 1;
    D_0028EB04 = 1;
    return 1;
}

void func_002273E0(void) {
    D_0028E320_as_u16 = 0xE10;
    if (g_pad_trigger[2] == 0) {
        D_0028E320_as_u16 -= 1;
        if (D_0028E320_as_u16 == 0) {
            g_pad_trigger[1] = 0x40;
            g_pad_trigger[0] = 0x40;
            g_pad_trigger[2] = 0x40;
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
}

static void func_00227440(Fade *fade) {
    switch (fade->state) {
    case 0:
        break;
    case 1:
        fade->value += 4;
        if (fade->value >= 0x80) {
            fade->value = 0x80;
            fade->state = 0;
        }
        break;
    case 2:
        fade->value -= 4;
        if (0 >= fade->value) {
            fade->value = 0;
            fade->state = 0;
        }
        break;
    }
}

void func_002274C0(Fade *arg0, u8 **arg1, s32 arg2) {
    void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 count;
    s32 i;
    s32 offset;
    s32 index;
    u8 *entry;

    count = D_002714F0[arg2];
    if (arg0->value == 0) {
        return;
    }
    i = 0;
    if (0 < count) {
        offset = 0;
        index = 0;
        do {
            entry = offset + (D_00685010 + arg2 * 0x380);
            if (*(s32 *)(entry + 0x34) != 0) {
                *(s32 *)(entry + 0x2C) = arg0->value;
                reg_a0 = *(u8 **)((u8 *)arg1 + index);
                glyph_queue_add(*(s32 *)entry, *(s32 *)(entry + 4), *(s32 *)(entry + 0x30), 0, 128, arg0->value, 1);
            }
            i++;
            offset += 0x38;
            index += 4;
        } while (i < count);
    }
}

void func_002275C0(void)
{
    s8 saved;

    saved = D_0028EC18_as_Fade.flag;
    func_00227310(&D_0028EC18_as_Fade);
    D_0028EC18_as_Fade.flag = saved;
    func_00222260(7);
}

void func_002275F0(void) {
    s8 value = D_0028EC18_as_Fade.flag;
    if (func_002273B0(&D_0028EC18_as_Fade, 7) != 0) {
        D_0028EB58 = value;
        if (value == 0) {
            D_0028EB58++;
        }
    }
}

void func_00227640(void) {
    func_00227310(&D_0028EC18_as_Fade);
    D_0028EC18_as_Fade.flag = 0;
    D_0028EC18_as_Fade.value = 0;
    D_0028EB50 = 0;
    D_0028EB58 = 0;
    func_00222340(7);
}

void func_00227680(void) {
    if (func_00227350(&D_0028EC18_as_Fade, 7) != 0) {
        D_0028EB58 = 1;
        D_0028EC18_as_Fade.step = 2;
    }
}

void func_002276C0(void) {
    s32 confirm;
    s32 last;
    u32 buttons;

    confirm = 0;
    last = D_002714F7[0] - 1;
    func_002273E0();
    if (func_00221120(7) == 0) {
        buttons = g_pad_trigger[D_0028EC24];
        if (buttons & 0x40) {
            D_0028EB58 = last;
            confirm = 1;
        } else if (buttons & 0x20) {
            confirm = 1;
        }
    }
    D_0028EC18_as_Fade.flag = D_0028EB58;
    if (confirm != 0) {
        sfx_menu_confirm();
        D_0028EC18_as_Fade.step += 1;
        if (last == D_0028EC18_as_Fade.flag) {
            func_00222260(0);
            D_0028EB7C = 3;
            D_0028EB84 = 0;
            D_0028EB90 = 0x40;
            D_0028EB4C = 1;
            D_0028EB04 = 1;
            D_0028EB54 = 2;
            D_0028EC18_as_Fade.state = 2;
        } else {
            D_0028EC18_as_Fade.state = 0;
            D_0028EC18_as_Fade.value = 0;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            switch (D_0028EC18_as_Fade.flag) {
            case 1:
                D_0028EC10_as_Fade.flag = 1;
                D_0028EC10_as_Fade.step = 0;
                D_0028EB84 = 8;
                break;
            case 2:
                D_0028EBE8_as_Fade.step = 0;
                D_0028EB84 = 10;
                break;
            case 3:
                D_0028EBE0_as_Fade.step = 0;
                D_0028EB84 = 11;
                break;
            case 4:
                D_0028EBE0_as_Fade.step = 0;
                D_0028EB84 = 22;
                break;
            }
        }
    }
}

void func_00227830(void) {
    switch (D_0028EC18_as_Fade.step) {
    case 10:
        func_00227640();
        break;
    case 0:
        func_002275C0();
        break;
    case 11:
        func_00227680();
        break;
    case 1:
        func_002275F0();
        break;
    case 2:
        func_002276C0();
        break;
    case 3:
        break;
    }
}

void func_002278D0(void) {
    func_00227440(&D_0028EC18_as_Fade);
    func_002274C0(&D_0028EC18_as_Fade, D_00270850, 7);
}

void func_00227900(void) {
    func_00227310(&D_0028EBE8_as_Fade);
    func_00222260(0xA);
    D_0028EC7C = 0;
}

void func_00227930(void) {
    if (func_002365A0() != 0) {
        D_0028EBE8_as_Fade.step += 1;
    }
}

void func_00227960(void) {
    if (func_002273B0(&D_0028EBE8_as_Fade, 0xA) != 0) {
        D_0028EB58 = D_0068DF02[0] + 1;
    }
}

void func_002279A0(void) {
    s32 confirm;
    s32 last;
    u32 buttons;
    s32 selected;

    confirm = 0;
    last = D_002714FA[0] - 1;
    func_002273E0();
    if (func_00221120(10) == 0) {
        buttons = g_pad_trigger[D_0028EC24];
        if (buttons & 0x40) {
            D_0028EB58 = last;
            confirm = 1;
        } else if (buttons & 0x20) {
            confirm = 1;
        }
    }
    D_0028EBE8_as_Fade.flag = D_0028EB58;
    if (confirm != 0) {
        if (last != D_0028EBE8_as_Fade.flag) {
            selected = D_0028EBE8_as_Fade.flag - 1;
            if (D_0028E258 < selected) {
                sfx_menu_denied();
                return;
            }
#ifndef DEATH_LABEL
            D_0028E280 = selected;
            printf(D_00289E38, D_0028E280);
#endif
            sfx_menu_confirm();
            D_0028EBE8_as_Fade.step += 1;
            D_0068DF02[0] = D_0028EBE8_as_Fade.flag - 1;
            func_002272D0();
        } else {
            sfx_menu_confirm();
            D_0028EC18_as_Fade.flag = 2;
            D_0028EBE8_as_Fade.state = 0;
            D_0028EB84 = 7;
            D_0028EBE8_as_Fade.value = 0;
            D_0028EC18_as_Fade.step = 0;
            D_0068DF02[0] = D_00270822[0];
        }
    }
}

void func_00227AE0(void) {
    switch (D_0028EBE8_as_Fade.step) {
    case 0:
        func_00227900();
        break;
    case 1:
        func_00227930();
        break;
    case 2:
        func_00227960();
        break;
    case 3:
        func_002279A0();
        /* fallthrough */
    case 4:
        break;
    }
}

void func_00227B70(void) {
    void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 count;
    s32 last;
    s32 i;
    s32 offset;
    s32 index;
    s32 alpha;
    u8 *entry;
    s32 x;
    s32 y;
    s32 sprite;
    s16 value;

    count = D_002714FA[0];
    last = count - 1;
    if (D_0028EBE8_as_Fade.step < 3) {
        return;
    }
    func_00227440(&D_0028EBE8_as_Fade);
    if (D_0028EBE8_as_Fade.value == 0) {
        return;
    }
    i = 0;
    if (0 < count) {
        offset = 0;
        index = 0;
        do {
            entry = D_00685010 + offset;
            if (*(s32 *)(entry + 0x2334) != 0) {
                value = D_0028EBE8_as_Fade.value;
                alpha = 128;
                *(s32 *)(entry + 0x232C) = value;
                x = *(s32 *)(entry + 0x2300);
                y = *(s32 *)(entry + 0x2304);
                sprite = *(s32 *)(entry + 0x2330);
                reg_a0 = *(u8 **)((u8 *)D_00271480 + index);
                if ((i > 0) && (i < last) && (D_0028E258 < i - 1)) {
                    alpha = 64;
                    reg_a0 = (u8 *)D_0028DCF8;
                }
                glyph_queue_add(x, y, sprite, 0, alpha, value, 1);
            }
            i++;
            offset += 0x38;
            index += 4;
        } while (i < count);
    }
}

void func_00227C90(void) {
    s32 replay_slots_open(s32, s8, s32);
    func_00227310(&D_0028EBE0_as_Fade);
    func_00222260(0xB);
    D_0028EC20 = 0;
    g_replay_mode_as_s8 = 0;
    replay_slots_open(0, D_0028EC24, 0);
}

void func_00227CD0(void) {
    if (func_002273B0(&D_0028EBE0_as_Fade, 0xB) != 0) {
        D_0028EB54 = 0;
    }
}

void func_00227D00(void) {
    s32 replay_slots_update();
    s32 temp_v0;

    func_002273E0();
    temp_v0 = replay_slots_update();
    switch (temp_v0) {
    case 0:
        D_0028EC18_as_Fade.flag = 3;
        D_0028EB54 = 0;
        D_0028EB84 = 7;
        D_0028EB50 = 0;
        D_0028EBE0_as_Fade.state = 0;
        D_0028EBE0_as_Fade.value = 0;
        D_0028EC18_as_Fade.step = 0;
        return;
    case 3:
        g_replay_mode_as_s8 = 2;
        D_0028EC20 = 1;
        D_0028EBE0_as_Fade.step += 1;
        func_002272D0();
        return;
    }
}

void func_00227D90(void) {
    switch (D_0028EBE0_as_Fade.step) {
    case 0:
        func_00227C90();
        break;
    case 1:
        func_00227CD0();
        break;
    case 2:
        func_00227D00();
        /* fallthrough */
    case 3:
        break;
    }
}

void func_00227E00(void) {
    func_00227440(&D_0028EBE0_as_Fade);
    replay_slots_draw();
}

void func_00227E30(void) {
    s32 replay_slots_open(s32, s8, s32);
    func_00227310(&D_0028EBE0_as_Fade);
    func_00222260(0xB);
    D_0028EC20 = 0;
    g_replay_mode_as_s8 = 0;
    replay_slots_open(0, D_0028EC24, 1);
}

void func_00227E70(void) {
    s32 replay_slots_update();
    s32 temp_v0;

    func_002273E0();
    temp_v0 = replay_slots_update();
    switch (temp_v0) {
    case 0:
        D_0028EC18_as_Fade.flag = 4;
        D_0028EB54 = 0;
        D_0028EB84 = 7;
        D_0028EB50 = 0;
        D_0028EBE0_as_Fade.state = 0;
        D_0028EBE0_as_Fade.value = 0;
        D_0028EC18_as_Fade.step = 0;
        break;
    case 3:
        g_replay_mode_as_s8 = 2;
        D_0028EC20 = 1;
        D_0028EBE0_as_Fade.step += 1;
        func_002272D0();
        break;
    }
}

void func_00227F00(void) {
    switch (D_0028EBE0_as_Fade.step) {
    case 0:
        func_00227E30();
        break;
    case 1:
        func_00227CD0();
        break;
    case 2:
        func_00227E70();
        /* fallthrough */
    case 3:
        break;
    }
}

void func_00227F70(void) {
    switch (D_0028EBE0_as_Fade.step) {
    case 0:
        func_00227C90();
        break;
    case 1:
        func_00227CD0();
        break;
    case 2:
        func_00227FE0();
        /* fallthrough */
    case 3:
        break;
    }
}

void func_00227FE0(void) {
    s32 replay_slots_update();
    s32 temp_v0;

    func_002273E0();
    temp_v0 = replay_slots_update();
    switch (temp_v0) {
    case 0:
        D_0028EB54 = 0;
        D_0028EC10_as_Fade.flag = 4;
        D_0028EB50 = 0;
        D_0028EB84 = 8;
        D_0028EBE0_as_Fade.state = 0;
        D_0028EBE0_as_Fade.value = 0;
        D_0028EC10_as_Fade.step = 0;
        break;
    case 3:
        func_00228060();
        replay_slots_close();
        break;
    }
}

void func_00228060(void) {
    memcpy(D_0068DEF0_as_s16_a, D_00270810_as_s16_a, 0x16);
    memcpy(D_0068DED8_as_s16_a, D_00270828_as_s16_a, 0xA);
    memcpy(D_0068DEC8_as_s16_a, D_00270838_as_s16_a, 0xC);
    D_0068DED8_as_s16_a[0] = D_006C58AA[0];
    D_0068DEDE[0] = D_006C58C6[0];
    D_0068DEE0[0] = D_006C58C8[0];
    if (D_006C58A2[0] == 0xFF) {
        if (D_006C58A6[0] == 0) {
            D_0068DEDA[0] = 0;
        } else {
            D_0068DEDA[0] = 1;
        }
        if (D_006C58A8[0] == 2) {
            D_0068DEDC[0] = 0;
        } else if (D_006C58A8[0] == 4) {
            D_0068DEDC[0] = 1;
        } else {
            D_0068DEDC[0] = 2;
        }
    } else {
        if (D_006C58A2[0] == 0) {
            D_0068DEDA[0] = 0;
        } else {
            D_0068DEDA[0] = 1;
        }
        if (D_006C58A4[0] == 2) {
            D_0068DEDC[0] = 0;
        } else if (D_006C58A4[0] == 4) {
            D_0068DEDC[0] = 1;
        } else {
            D_0068DEDC[0] = 2;
        }
    }
    D_0068DEF0_as_s16_a[0] = D_006C58B8[0];
    D_0068DEF2[0] = D_006C58BA[0];
    D_0068DEF4[0] = D_006C58C0[0];
    D_0068DF04[0] = D_006C58C2[0];
    D_0068DEF6[0] = D_006C58B4[0];
    D_0068DEF8[0] = D_006C58B6[0];
    D_0068DEFA[0] = D_006C58CA[0];
    D_0068DEFE[0] = D_006C58BC[0];
    D_0068DF00[0] = D_006C58BE[0];
    D_0068DEFC[0] = D_006C58CC[0];
    D_0068DEC8_as_s16_a[0] = D_006C58CE[0];
    D_0068DECA[0] = D_006C58D0[0];
    D_0068DECC[0] = D_006C58D2[0];
    D_0068DECE[0] = D_006C58B0[0];
    D_0068DED0[0] = D_006C58B2[0];
    D_0068DED2[0] = D_006C58D4[0];
    if (D_0068DED8_as_s16_a[0] > 3) {
        D_0068DED8_as_s16_a[0] = 1;
    }
    if (D_0068DEDE[0] > 19) {
        D_0068DEDE[0] = 20;
    }
    if (D_0068DEE0[0] > 3) {
        D_0068DEE0[0] = 0;
    }
    if (D_0068DEF0_as_s16_a[0] > 1) {
        D_0068DEF0_as_s16_a[0] = 0;
    }
    if (D_0068DEF2[0] > 1) {
        D_0068DEF2[0] = 0;
    }
    if (D_0068DEF4[0] > 255) {
        D_0068DEF4[0] = 0;
    }
    if (D_0068DF04[0] > 1) {
        D_0068DF04[0] = 0;
    }
    if (D_0068DEF6[0] > 5) {
        D_0068DEF6[0] = 6;
    }
    if (D_0068DEF8[0] > 7) {
        D_0068DEF8[0] = 8;
    }
    if (D_0068DEFA[0] > 1) {
        D_0068DEFA[0] = 0;
    }
    if (D_0068DEFE[0] > 5) {
        D_0068DEFE[0] = 0;
    }
    if (D_0068DF00[0] > 500) {
        D_0068DF00[0] = 0;
    }
    if (D_0068DEFC[0] > 100) {
        D_0068DEFC[0] = 0;
    }
    if (D_0068DEC8_as_s16_a[0] > 2) {
        D_0068DEC8_as_s16_a[0] = 0;
    }
    if (D_0068DECA[0] > 9) {
        D_0068DECA[0] = 0;
    }
    if (D_0068DECC[0] > 15) {
        D_0068DECC[0] = 0;
    }
    if (D_0068DECE[0] > 4) {
        D_0068DECE[0] = 0;
    }
    if (D_0068DED0[0] > 4) {
        D_0068DED0[0] = 0;
    }
    if (D_0068DED2[0] > 10) {
        D_0068DED2[0] = 0;
    }
    memcpy(D_0068DEB0_as_s16_a, D_0068DEF0_as_s16_a, 0x16);
    memcpy(D_0068DE90_as_s16_a, D_0068DED8_as_s16_a, 0xA);
    memcpy(D_0068DEA0_as_s16_a, D_0068DEC8_as_s16_a, 0xC);
}

void func_00228520(void)
{
    s8 saved;

    saved = D_0028EC10_as_Fade.flag;
    func_00227310(&D_0028EC10_as_Fade);
    D_0028EC10_as_Fade.flag = saved;
    func_00222260(8);
}

void func_00228550(void) {
    if (func_002273B0(&D_0028EC10_as_Fade, 8) != 0) {
        D_0028EB58 = D_0028EC10_as_Fade.flag;
    }
}

void func_00228580(void) {
    s32 confirm;
    s32 last;
    u32 buttons;

    confirm = 0;
    last = D_002714F8[0] - 1;
    func_002273E0();
    if (func_00221120(8) == 0) {
        buttons = g_pad_trigger[D_0028EC24];
        if (buttons & 0x40) {
            D_0028EB58 = last;
            confirm = 1;
        } else if (buttons & 0x20) {
            confirm = 1;
        }
    }
    D_0028EC10_as_Fade.flag = D_0028EB58;
    if (confirm != 0) {
        switch (D_0028EB58) {
        case 1:
            sfx_menu_confirm();
            D_0028EC10_as_Fade.state = 0;
            D_0028EB84 = 0x11;
            D_0028EC10_as_Fade.value = 0;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EC08_as_Fade.step = 0;
            D_0028EC10_as_Fade.step += 1;
            break;
        case 2:
            sfx_menu_confirm();
            D_0028EC10_as_Fade.state = 0;
            D_0028EB84 = 0x12;
            D_0028EC10_as_Fade.value = 0;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EC00_as_Fade.step = 0;
            D_0028EC10_as_Fade.step += 1;
            break;
        case 3:
            sfx_menu_confirm();
            D_0028EC10_as_Fade.state = 0;
            D_0028EB84 = 0x13;
            D_0028EC10_as_Fade.value = 0;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EBF8.step = 0;
            D_0028EC10_as_Fade.step += 1;
            break;
        case 4:
            sfx_menu_confirm();
            D_0028EC10_as_Fade.state = 0;
            D_0028EB84 = 0x14;
            D_0028EC10_as_Fade.value = 0;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EBE0_as_Fade.step = 0;
            D_0028EC10_as_Fade.step += 1;
            break;
        case 5:
            sfx_menu_confirm();
            D_0028EC10_as_Fade.state = 0;
            D_0028EC18_as_Fade.flag = 1;
            D_0028EC10_as_Fade.value = 0;
            D_0028EB84 = 7;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EC18_as_Fade.step = 0;
            D_0028EC10_as_Fade.step += 1;
            break;
        }
    }
}

void func_00228770(void) {
    switch (D_0028EC10_as_Fade.step) {
    case 0:
        func_00228520();
        break;
    case 1:
        func_00228550();
        break;
    case 2:
        func_00228580();
        /* fallthrough */
    case 3:
        break;
    }
}

void func_002287E0(void) {
    void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 count;
    s32 i;
    s32 offset;
    s32 tableOffset;
    u8 *entry;

    count = D_002714F8[0];
    func_00227440(&D_0028EC10_as_Fade);
    if (D_0028EC10_as_Fade.value == 0) {
        return;
    }
    i = 0;
    if (0 < count) {
        offset = 0;
        tableOffset = 0;
        do {
            entry = D_00685010 + offset;
            if (*(s32 *)(entry + 0x1C34) != 0) {
                s32 value = D_0028EC10_as_Fade.value;

                *(s32 *)(entry + 0x1C2C) = value;
                reg_a0 = *(u8 **)(D_00270890 + tableOffset);
                glyph_queue_add(*(s32 *)(entry + 0x1C00), *(s32 *)(entry + 0x1C04), *(s32 *)(entry + 0x1C30), 0, 0x80, value, 1);
            }
            i++;
            offset += 0x38;
            tableOffset += 4;
        } while (i < count);
    }
}

void func_002288B0(void) {
    func_00227310(&D_0028EC08_as_Fade);
    func_00222260(0x11);
}

void func_002288E0(void) {
    if (func_002273B0(&D_0028EC08_as_Fade, 0x11) != 0) {
        D_0028EB58 = 1;
    }
}

void func_00228910(void) {
    s32 confirm;
    s32 last;
    s32 dir;
    s32 skip;
    u32 buttons;
    s32 count;
    s32 item;
    s16 *value;

    dir = 0;
    confirm = 0;
    last = D_00271501[0] - 1;
    func_002273E0();
    skip = func_00221120(17);
    if (skip == 0) {
        buttons = g_pad_repeat[D_0028EC24];
        if (buttons & 0x8000) {
            dir = -1;
            skip = 1;
        } else if (buttons & 0x2000) {
            dir = 1;
            skip = 1;
        }
    }
    if (skip == 0) {
        buttons = g_pad_trigger[D_0028EC24];
        if (buttons & 0x40) {
            D_0028EB58 = last;
            confirm = 1;
        } else if (buttons & 0x20) {
            confirm = 1;
        }
    }
    D_0028EC08_as_Fade.flag = D_0028EB58;
    if (confirm != 0) {
        switch (D_0028EB58) {
        case 6:
            sfx_menu_confirm();
            memcpy(D_0068DED8_as_s16_a, D_00270828_as_s16_a, 10);
            break;
        case 7:
            sfx_menu_confirm();
            D_0028EC08_as_Fade.state = 0;
            D_0028EC10_as_Fade.flag = 1;
            D_0028EC08_as_Fade.value = 0;
            D_0028EB84 = 8;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EC10_as_Fade.step = 0;
            D_0028EC08_as_Fade.step += 1;
            break;
        }
    } else if (dir != 0) {
        item = D_0028DCB0[D_0028EB58];
        if (!(0 > item)) {
            value = &D_0068DED8_as_s16_a[item];
            count = D_0028DCA8[item];
            sfx_menu_tick();
            if (item == 2) {
                D_0068DEF6[0] = 6;
                D_0068DEF8[0] = 8;
            }
            if (dir == -1) {
                (*value)--;
                if (0 > *value) {
                    *value = count - 1;
                }
            } else {
                (*value)++;
                if (count <= *value) {
                    *value = 0;
                }
            }
        }
    }
}

void func_00228B50(void) {
    switch (D_0028EC08_as_Fade.step) {
    case 0:
        func_002288B0();
        break;
    case 1:
        func_002288E0();
        break;
    case 2:
        func_00228910();
        /* fallthrough */
    case 3:
        break;
    }
}

void func_00228BC0(void) {
    void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 dbl;
    s32 x;
    s32 y;
    s32 z;
    s32 i;
    s32 count;
    s32 value;
    s32 alpha;
    u8 **entries;
    s8 index;
    u8 *item;

    count = D_00271501[0];
    func_00227440(&D_0028EC08_as_Fade);
    if (D_0028EC08_as_Fade.value == 0) {
        return;
    }
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x3BB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x3BAC) = alpha = D_0028EC08_as_Fade.value;
        x = *(s32 *)(item + 0x3B80);
        y = *(s32 *)(item + 0x3B84);
        z = *(s32 *)(item + 0x3BB0);
        reg_a0 = D_002708D0[i];
        glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        y += strlen((const char *)reg_a0) * 8;
        reg_a0 = 0;
        index = D_0028DCB0[i];
        if (index == -1) {
            continue;
        }
        entries = D_002709B0[index];
        value = D_0068DED8_as_s16_a[index];
        reg_a0 = entries[value];
        if (reg_a0 == 0) {
            continue;
        }
        if (index == 4) {
            dbl = value * 2;
            reg_a0 = entries[dbl];
            if (dbl == 6) {
                glyph_queue_add(x, y, z, 0, 0x80, D_0028EC08_as_Fade.value, 1);
            } else {
                glyph_queue_add(x, y, z, 0, 0x80, D_0028EC08_as_Fade.value, 0);
                reg_a0 = D_002709B0[index][dbl + 1];
                glyph_queue_add(x - 8, y, z, 0, 0x80, D_0028EC08_as_Fade.value, 0);
            }
        } else {
            glyph_queue_add(x, y, z, 0, 0x80, D_0028EC08_as_Fade.value, 1);
        }
        if (i == D_0028EC08_as_Fade.flag) {
            func_00224BA0(x, y, z, 0, 0x80, D_0028EC08_as_Fade.value, 1, 3);
        }
    }
}

void func_00228E20(void) {
    func_00227310(&D_0028EC00_as_Fade);
    func_00222260(0x12);
}

void func_00228E50(void) {
    if (func_002273B0(&D_0028EC00_as_Fade, 0x12) != 0) {
        D_0028EB58 = 1;
    }
}

void func_00228E80(void) {
    s32 confirm;
    s32 last;
    s32 dir;
    s32 moved;
    s32 count;
    s32 idx;
    s32 pad;
    s8 sel;
    s32 limit;
    s16 *value;
    s32 base;
    s32 total;
    s32 extra;

    last = D_00271502[0] - 1;
    dir = 0;
    confirm = 0;
    func_002273E0();
    moved = func_00221120(0x12);
    if (moved == 0) {
        if (D_0028EB58 == 3 || D_0028EB58 == 9 || D_0028EB58 == 7) {
            pad = g_pad_fast_repeat[D_0028EC24];
            if (pad & 0x8000) {
                dir = -1;
                moved = 1;
            } else if (pad & 0x2000) {
                dir = 1;
                moved = dir;
            }
        } else {
            pad = g_pad_repeat[D_0028EC24];
            if (pad & 0x8000) {
                dir = -1;
                moved = 1;
            } else if (pad & 0x2000) {
                dir = 1;
                moved = dir;
            }
        }
    }
    if (moved == 0) {
        pad = g_pad_trigger[D_0028EC24];
        if (pad & 0x40) {
            D_0028EB58 = last;
            confirm = 1;
        } else if (pad & 0x20) {
            confirm = 1;
        }
    }
    sel = D_0028EB58;
    D_0028EC00_as_Fade.flag = sel;
    if (confirm != 0) {
        switch (sel) {
        case 3:
            sfx_menu_confirm();
            D_0068DEF0_as_s16_a[10] += 1;
            D_0068DEF0_as_s16_a[10] &= 1;
            break;
        case 10:
            sfx_menu_confirm();
            memcpy(D_0068DEF0_as_s16_a, D_00270810_as_s16_a, 0x16);
            break;
        case 11:
            sfx_menu_confirm();
            D_0028EC00_as_Fade.state = 0;
            D_0028EC10_as_Fade.flag = 2;
            D_0028EC00_as_Fade.value = 0;
            D_0028EB84 = 8;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EC10_as_Fade.step = 0;
            D_0028EC00_as_Fade.step++;
            break;
        }
    } else if (dir != 0) {
        idx = D_002712D8[sel];
        if (sel == 3 && D_0068DEF0_as_s16_a[10] == 0) {
            idx = -1;
        }
        if (!(0 > idx)) {
        value = &D_0068DEF0_as_s16_a[idx];
        count = D_002712C0[idx];
        if (sel == 3 || sel == 9 || sel == 7) {
            pad = g_pad_fast_repeat_timer[D_0028EC24];
            if (pad == 0 || pad == 0xE) {
                if (!(*value == 0 && dir == -1) && !(*value == count - 1 && dir == 1)) {
                    sfx_menu_tick();
                }
            }
        } else {
            sfx_menu_tick();
        }
        if (idx == 5) {
            if (D_0068DEF0_as_s16_a[5] == 0 && D_0068DEF0_as_s16_a[7] == 0) {
                D_0068DEF0_as_s16_a[7] = 1;
            }
            if (D_0068DEF0_as_s16_a[5] != 0) {
                D_0068DEF0_as_s16_a[7] = 0;
                D_0068DEF0_as_s16_a[8] = 0;
            }
        }
        if (idx == 3) {
            D_0068DEF0_as_s16_a[4] = 8;
        }
        limit = D_0068DEF0_as_s16_a[3] + 1;
        if (limit == 7) {
            if (D_0068DEDC[0] == 0) {
                limit = 3;
            }
            if (D_0068DEDC[0] == 1) {
                limit = 2;
            }
            if (D_0068DEDC[0] == 2) {
                limit = 1;
            }
        }
        if (dir == -1) {
            (*value)--;
            if (idx == 3) {
                if (D_0068DEDC[0] == 0 && *value == 1) {
                    *value = 6;
                }
                if (D_0068DEDC[0] == 1 && *value == 5) {
                    *value = 3;
                }
                if (D_0068DEDC[0] == 1 && *value == 0) {
                    *value = 6;
                }
                if (D_0068DEDC[0] == 2 && *value == 5) {
                    *value = 1;
                }
            }
            if (idx == 4 && *value == 6) {
                *value = limit;
            }
            if (idx == 7 && D_0068DEF0_as_s16_a[5] == 1 && *value == 0) {
                *value = 5;
            }
            if (D_0028EB58 == 3 || D_0028EB58 == 9 || D_0028EB58 == 7) {
                if (0 > *value) {
                    *value = 0;
                }
            } else {
                if (0 > *value) {
                    *value = count - 1;
                }
            }
        } else {
            (*value)++;
            if (idx == 3) {
                if (D_0068DEDC[0] == 0 && *value == 7) {
                    *value = 2;
                }
                if (D_0068DEDC[0] == 1 && *value == 4) {
                    *value = 6;
                }
                if (D_0068DEDC[0] == 1 && *value == 7) {
                    *value = 1;
                }
                if (D_0068DEDC[0] == 2 && *value == 2) {
                    *value = 6;
                }
            }
            if (idx == 4 && *value < 7 && limit < *value) {
                *value = 7;
            }
            if (idx == 7 && D_0068DEF0_as_s16_a[5] == 1 && *value == 6) {
                *value = 1;
            }
            if (D_0028EB58 == 3 || D_0028EB58 == 9 || D_0028EB58 == 7) {
                if (count <= *value) {
                    *value = count - 1;
                }
            } else {
                if (count <= *value) {
                    *value = 0;
                }
            }
#ifdef DEATH_LABEL
            if (D_0068DEF0_as_s16_a[5] == 0) {
                base = D_0068DEF0_as_s16_a[8];
                total = 0;
                if (base != 0) {
                    total = (s16)base / 100;
                }
                extra = D_0068DEF0_as_s16_a[7];
                total += extra;
                if (total > 5) {
                    if (idx == 7) {
                        if ((s16)base >= 100) {
                            D_0068DEF0_as_s16_a[8] -= 100;
                        }
                    } else if (idx == 8) {
                        if (extra > 0) {
                            D_0068DEF0_as_s16_a[7] = extra - 1;
                        }
                    }
                }
            }
#endif
        }
#ifndef DEATH_LABEL
        if (D_0068DEF0_as_s16_a[5] == 0) {
            base = D_0068DEF0_as_s16_a[8];
            total = 0;
            if (base != 0) {
                total = (s16)base / 100;
            }
            extra = D_0068DEF0_as_s16_a[7];
            total += extra;
            if (total > 5) {
                if (idx == 7) {
                    D_0068DEF0_as_s16_a[8] = (5 - extra) * 100 + 99;
                } else if (idx == 8) {
                    D_0068DEF0_as_s16_a[7] = (500 - (s16)base) / 100;
                }
            }
        }
#endif
    }
    }
}

void func_002295F0(void) {
    switch (D_0028EC00_as_Fade.step) {
    case 0:
        func_00228E20();
        break;
    case 1:
        func_00228E50();
        break;
    case 2:
        func_00228E80();
        /* fallthrough */
    case 3:
        break;
    }
}

void func_00229660(void) {
    void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 x;
    s32 y;
    s32 z;
    s32 bright;
    s32 i;
    s32 count;
    s32 flag;
    s32 alpha;
    s8 index;
    u8 *item;

    count = D_00271502[0];
    func_00227440(&D_0028EC00_as_Fade);
    if (D_0028EC00_as_Fade.value == 0) {
        return;
    }
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x3F34) == 0) {
            continue;
        }
        *(s32 *)(item + 0x3F2C) = alpha = D_0028EC00_as_Fade.value;
        x = *(s32 *)(item + 0x3F00);
        y = *(s32 *)(item + 0x3F04);
        z = *(s32 *)(item + 0x3F30);
        bright = 0x80;
        if (D_0068DEFA[0] == 0 && i == 7) {
            bright = 0x40;
        }
        reg_a0 = D_002709D0[i];
        glyph_queue_add(x, y, z, 0, bright, alpha, 1);
        y += strlen((const char *)reg_a0) * 8;
        reg_a0 = 0;
        index = D_002712D8[i];
        if (index == -1) {
            continue;
        }
        if (i == 3) {
            reg_a0 = (u8 *)D_0028DCC8;
        } else if (i == 9 || i == 7) {
            reg_a0 = (u8 *)D_0028DCCC;
        } else {
            reg_a0 = D_00271290[index][D_0068DEF0_as_s16_a[index]];
        }
        if (reg_a0 == 0) {
            continue;
        }
        flag = 1;
        if (i == 3) {
            if (D_0068DF04[0] == 1) {
                func_00229950(x, y, D_0028EC00_as_Fade.value, bright, 2);
            } else {
                glyph_queue_add(x, y, z, 0, bright, D_0028EC00_as_Fade.value, flag);
                flag = 0;
            }
        } else if (i == 9) {
            func_00229950(x, y, D_0028EC00_as_Fade.value, bright, 8);
        } else if (i == 7) {
            func_00229950(x, y, D_0028EC00_as_Fade.value, bright, 6);
        } else {
            glyph_queue_add(x, y, z, 0, bright, D_0028EC00_as_Fade.value, flag);
        }
        if (i == D_0028EC00_as_Fade.flag && flag != 0) {
            func_00224BA0(x, y, z, 0, bright, D_0028EC00_as_Fade.value, 1, 3);
        }
    }
}

void func_00229950(s32 x, s32 y, s32 alpha, s32 mode, s32 kind) {
    void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    u8 *saved;
    s32 c;
    s32 level;
    s32 h;

    saved = reg_a0;
    level = D_0068DEF0_as_s16_a[kind];
    if (kind == 2) {
        h = level * 60000 / 255000;
    } else if (kind == 8) {
        h = level * 60000 / 500000;
    } else if (kind == 6) {
        h = level * 60000 / 100000;
    }
    c = 0xC8;
    if (mode != 0x80) {
        c = 0x40;
    }
    gfx_draw_color_box(x - 8, y, 0x10, 0x40, 0xC8, alpha, 0x14, 0x14, 0x14);
    if (h != 0) {
        if (h == 0x3C) {
            gfx_draw_color_box(x - 6, y + 2, 0xE, h + 1, 0xC8, alpha, c, 0, 0);
        } else {
            gfx_draw_color_box(x - 6, y + 2, 0xE, h + 1, 0xC8, alpha, 0, 0, c);
        }
        if (kind == 8 && level >= 100) {
            if (level >= 100 && level < 200) {
                h = 12;
            }
            if (level >= 200 && level < 300) {
                h = 24;
            }
            if (level >= 300 && level < 400) {
                h = 36;
            }
            if (level >= 400 && level < 500) {
                h = 48;
            }
            gfx_draw_color_box(x - 6, y + 2, 0xE, h + 1, 0xC8, alpha, c, 0, 0);
        }
    }
    gfx_draw_color_box(x - 7, y, 0xE, 1, 0xC8, alpha, c, c, c);
    gfx_draw_color_box(x - 8, y + 1, 0x10, 1, 0xC8, alpha, c, c, c);
    gfx_draw_color_box(x - 8, y + 0x3E, 0x10, 1, 0xC8, alpha, c, c, c);
    gfx_draw_color_box(x - 7, y + 0x3F, 0xE, 1, 0xC8, alpha, c, c, c);
    if (kind == 8) {
        gfx_draw_color_box(x - 8, y + 0xE, 0x10, 1, 0xC8, alpha, c, c, c);
        gfx_draw_color_box(x - 8, y + 0x1A, 0x10, 1, 0xC8, alpha, c, c, c);
        gfx_draw_color_box(x - 8, y + 0x26, 0x10, 1, 0xC8, alpha, c, c, c);
        gfx_draw_color_box(x - 8, y + 0x32, 0x10, 1, 0xC8, alpha, c, c, c);
    }
    gfx_draw_color_box(x - 8, y + 1, 2, 0x3E, 0xC8, alpha, c, c, c);
    gfx_draw_color_box(x + 6, y + 1, 2, 0x3E, 0xC8, alpha, c, c, c);
    if (kind != 2) {
        reg_a0 = D_00270AB0[level];
        glyph_queue_add(x - 4, y + 0x42, 0xC8, 0, c, alpha, 0);
        reg_a0 = (u8 *)D_0028DCE0;
        glyph_queue_add(x - 4, y + 0x5A, 0xC8, 0, c, alpha, 0);
    }
    reg_a0 = saved;
}

void func_00229DC0(void) {
    func_00227310(&D_0028EBF8);
    func_00222260(0x13);
}

void func_00229DF0(void) {
    if (func_002273B0(&D_0028EBF8, 0x13) != 0) {
        D_0028EB58 = 1;
    }
}

void func_00229E20(void) {
    s32 confirm;
    s32 last;
    s32 dir;
    s32 skip;
    u32 buttons;
    s32 count;
    s32 item;
    s16 *value;

    dir = 0;
    confirm = 0;
    last = D_00271503[0] - 1;
    func_002273E0();
    skip = func_00221120(19);
    if (skip == 0) {
        buttons = g_pad_repeat[D_0028EC24];
        if (buttons & 0x8000) {
            dir = -1;
            skip = 1;
        } else if (buttons & 0x2000) {
            dir = 1;
            skip = 1;
        }
    }
    if (skip == 0) {
        buttons = g_pad_trigger[D_0028EC24];
        if (buttons & 0x40) {
            D_0028EB58 = last;
            confirm = 1;
        } else if (buttons & 0x20) {
            confirm = 1;
        }
    }
    D_0028EBF8.flag = D_0028EB58;
    if (confirm != 0) {
        switch (D_0028EB58) {
        case 7:
            sfx_menu_confirm();
            memcpy(D_0068DEC8_as_s16_a, D_00270838_as_s16_a, 12);
            break;
        case 8:
            sfx_menu_confirm();
            D_0028EBF8.state = 0;
            D_0028EC10_as_Fade.flag = 3;
            D_0028EBF8.value = 0;
            D_0028EB84 = 8;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EC10_as_Fade.step = 0;
            D_0028EBF8.step += 1;
            break;
        }
    } else if (dir != 0) {
        item = D_00271468[D_0028EB58];
        if (!(0 > item)) {
            value = &D_0068DEC8_as_s16_a[item];
            count = D_00271458[item];
            sfx_menu_tick();
            if (dir == -1) {
                (*value)--;
                if (0 > *value) {
                    *value = count - 1;
                }
            } else {
                (*value)++;
                if (count <= *value) {
                    *value = 0;
                }
            }
        }
    }
}

void func_0022A040(void) {
    switch (D_0028EBF8.step) {
    case 0:
        func_00229DC0();
        break;
    case 1:
        func_00229DF0();
        break;
    case 2:
        func_00229E20();
        /* fallthrough */
    case 3:
        break;
    }
}

void func_0022A0B0(void) {
    void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    s32 x;
    s32 y;
    s32 z;
    s32 i;
    s32 count;
    s8 index;
    s32 alpha;
    u8 *item;

    count = D_00271503[0];
    func_00227440(&D_0028EBF8);
    if (D_0028EBF8.value == 0) {
        return;
    }
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x42B4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x42AC) = alpha = D_0028EBF8.value;
        y = *(s32 *)(item + 0x4284);
        z = *(s32 *)(item + 0x42B0);
        x = *(s32 *)(item + 0x4280);
        reg_a0 = D_002712F0[i];
        glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        y += strlen((const char *)reg_a0) * 8;
        reg_a0 = 0;
        index = D_00271468[i];
        if (index == -1) {
            continue;
        }
        reg_a0 = D_00271440[index][D_0068DEC8_as_s16_a[index]];
        if (reg_a0 == 0) {
            continue;
        }
        glyph_queue_add(x, y, z, 0, 0x80, D_0028EBF8.value, 1);
        if (i == D_0028EBF8.flag) {
            func_00224BA0(x, y, z, 0, 0x80, D_0028EBF8.value, 1, 3);
        }
    }
}

void func_0022A260(void) {
    func_00227310(&D_0028EBD8_as_Fade);
    func_00222340(0xD);
    D_0028EBD8_as_Fade.flag = 0;
    D_0028EB58 = 1;
    D_0028EB54 = 0;
    D_0028EB90 = 0x40;
    D_0028EB04 = 2;
}

void func_0022A2B0(void) {
    s32 func_00222530(s32);
    if (func_00222530(0xD) != 0) {
        D_0028EBD8_as_Fade.step += 1;
    }
}

void func_0022A2E0(void) {
    s32 temp_a0;
    s32 var_a1;
    s32 var_s0;

    var_s0 = 0;
    func_002273E0();
    temp_a0 = g_pad_repeat[D_0028EC24];
    var_a1 = 0;
    if (temp_a0 & 0x8000) {
        sfx_menu_tick();
        D_0028EBD8_as_Fade.flag -= 1;
        if (D_0028EBD8_as_Fade.flag < 0) {
            D_0028EBD8_as_Fade.flag = 9;
        }
        var_a1 = 1;
    } else if (temp_a0 & 0x2000) {
        sfx_menu_tick();
        D_0028EBD8_as_Fade.flag += 1;
        if (D_0028EBD8_as_Fade.flag > 9) {
            D_0028EBD8_as_Fade.flag = 0;
        }
        var_a1 = 1;
    }
    if ((var_a1 == 0) && (g_pad_trigger[D_0028EC24] & 0x40)) {
        var_s0 = 1;
    }
    if (var_s0 != 0) {
        sfx_menu_confirm();
        D_0028EBD8_as_Fade.state = 0;
        D_0028EB04 = 1;
        D_0028EBD8_as_Fade.value = 0;
        D_0028EC18_as_Fade.flag = 4;
        D_0028EB54 = 0;
        D_0028EB84 = 7;
        D_0028EB50 = 0;
        D_0028EB90 = 0;
        D_0028EC18_as_Fade.step = 0;
        D_0028EBD8_as_Fade.step += 1;
    }
}

void func_0022A410(void) {
    switch (D_0028EBD8_as_Fade.step) {
    case 0:
        func_0022A260();
        break;
    case 1:
        func_0022A2B0();
        break;
    case 2:
        func_0022A2E0();
        /* fallthrough */
    case 3:
        break;
    }
}

void func_0022A480(void) {
    void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
    extern void text_queue_clear(void);
    extern void text_flush(void);
    extern void func_002228D0(s32 x, s32 y);
    s32 i;
    s32 x;
    s32 y;
    s32 z;
    s32 alpha;
    s32 count;
    u8 *item;

    func_00227440(&D_0028EBD8_as_Fade);
    if (D_0028EBD8_as_Fade.value == 0) {
        return;
    }
    count = D_002714FD[0];
    text_queue_clear();
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x2DB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x2DAC) = D_0028EBD8_as_Fade.value;
        reg_a0 = D_002714B0[i];
        x = *(s32 *)(item + 0x2D80);
        alpha = *(s32 *)(item + 0x2DAC);
        y = *(s32 *)(item + 0x2D84);
        z = *(s32 *)(item + 0x2DB0);
        if (alpha == 0) {
            continue;
        }
        if (i == 1) {
            func_00224BA0(x, y, z, 0, 0x80, alpha, 1, 3);
        }
        glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        if (i == 1) {
            reg_a0 = D_002716E0[D_0028EBD8_as_Fade.flag];
            glyph_queue_add(x, y + 0x70, z, 0, 0x80, alpha, 1);
        }
    }
    func_0022AD20(D_0028EBD8_as_Fade.flag, 0);
    for (i = 3; i < 8; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x2DB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x2DAC) = D_0028EBD8_as_Fade.value;
        reg_a0 = (u8 *)D_00684CA0 + (i - 3) * 11;
        y = *(s32 *)(item + 0x2D84) + 16;
        x = *(s32 *)(item + 0x2D80);
        z = *(s32 *)(item + 0x2DB0);
        alpha = *(s32 *)(item + 0x2DAC);
        if (alpha != 0) {
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        }
    }
    func_0022AD20(D_0028EBD8_as_Fade.flag, 1);
    for (i = 3; i < 8; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x2DB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x2DAC) = D_0028EBD8_as_Fade.value;
        reg_a0 = (u8 *)D_00684CA0 + (i - 3) * 11;
        y = *(s32 *)(item + 0x2D84) + 0x80;
        x = *(s32 *)(item + 0x2D80);
        z = *(s32 *)(item + 0x2DB0);
        alpha = *(s32 *)(item + 0x2DAC);
        if (alpha != 0) {
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        }
    }
    func_0022AD20(D_0028EBD8_as_Fade.flag, 2);
    for (i = 9; i < 14; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x2DB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x2DAC) = D_0028EBD8_as_Fade.value;
        reg_a0 = (u8 *)D_00684CA0 + (i - 9) * 11;
        y = *(s32 *)(item + 0x2D84) + 16;
        x = *(s32 *)(item + 0x2D80);
        z = *(s32 *)(item + 0x2DB0);
        alpha = *(s32 *)(item + 0x2DAC);
        if (alpha != 0) {
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        }
    }
    func_0022AD20(D_0028EBD8_as_Fade.flag, 3);
    for (i = 9; i < 14; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x2DB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x2DAC) = D_0028EBD8_as_Fade.value;
        reg_a0 = (u8 *)D_00684CA0 + (i - 9) * 11;
        y = *(s32 *)(item + 0x2D84) + 0x80;
        x = *(s32 *)(item + 0x2D80);
        z = *(s32 *)(item + 0x2DB0);
        alpha = *(s32 *)(item + 0x2DAC);
        if (alpha != 0) {
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        }
    }
    D_0028EB90 = D_0028EBD8_as_Fade.value;
    reg_a0 = (u8 *)D_0028DD98;
    func_002228D0(D_006880A0[0] - 10, D_006880A4[0] + 0x58);
    text_flush();
}

extern s8 D_0028EB64;

void func_0022A870(void) {
    switch (D_0028EB64) {                           /* irregular */
    case 0:
        func_0022A8F0(D_0028EB64);
        break;
    case 1:
        func_0022A930(D_0028EB64);
        break;
    case 2:
        func_0022A9A0(D_0028EB64);
        break;
    case 3:
        func_0022AA00(D_0028EB64);
        break;
    }
}

s32 func_00222340(s32);                     /* extern */
extern s8 D_0028EB10;
extern s8 D_0028EB34;
extern s32 D_0028EB9C;

void func_0022A8F0() {
    D_0028EB9C = 0;
    D_0028EB64 += 1;
    func_00222340(0xC);
    D_0028EB10 = 0;
    D_0028EB34 = 1;
}

extern s8 D_0028EADC;

void func_0022A930() {
    s32 func_00222530();
    if (func_00222530(0xC) != 0) {
        D_0028EB64 += 1;
        if ((0 <= D_0028EADC) && (D_0028EADC < 5)) {
            D_0028EB58 = D_0028EADC + 3;
            D_0028EB54 = 1;
        } else {
            D_0028EB58 = -1;
            D_0028EB54 = 1;
        }
    }
}

void func_0022A9A0()
{
    extern void sfx_menu_confirm(void);
    if (g_pad_trigger[D_0028EC24] & 0x60) {
        sfx_menu_confirm();
        D_0028EB54 = 2;
        D_0028EB34 = 2;
        D_0028EB64 = D_0028EB64 + 1;
    }
}

extern s8 D_0028EACC;

void func_0022AA00() {
    if (D_0028EB34 == 0) {
        D_0028EACC = 0x51;
    }
}

extern s8 D_002714FC[];
extern u8 *D_00271610[];
extern u8 *D_00271640[];
extern u8 *D_0028DD94;
extern u8 D_00684CD7[];
extern u16 D_006C58AC[];
extern u16 D_006C58AE[];

void func_0022AA20(void) {
    extern void text_queue_clear(void);
    extern void text_flush(void);
    extern void glyph_queue_add(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
    extern void func_002228D0(s32 x, s32 y);
    s32 count;
    u8 *save;
    s32 page;
    s32 sel;
    s32 i;
    s32 x;
    s32 y;
    s32 z;
    s32 alpha;
    u8 *item;

    save = reg_a0;
    count = D_002714FC[0];
    switch (D_0028EB34) {
    case 0:
        break;
    case 1:
        D_0028EB9C += 4;
        if (D_0028EB9C >= 0x80) {
            D_0028EB34 = 0;
            D_0028EB9C = 0x80;
        }
        break;
    case 2:
        D_0028EB9C -= 4;
        if (D_0028EB9C <= 0) {
            D_0028EB9C = 0;
            D_0028EB34 = 0;
        }
        break;
    }
    page = D_006C58AE[0] + D_006C58AC[0] * 5;
    sel = D_006C58AA[0];
    func_0022AD20(page, sel);
    func_0022B1D0();
    glyph_queue_clear();
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x2A34) == 0) {
            continue;
        }
        *(s32 *)(item + 0x2A2C) = D_0028EB9C;
        reg_a0 = D_00271610[i];
        alpha = *(s32 *)(item + 0x2A2C);
        x = *(s32 *)(item + 0x2A00);
        y = *(s32 *)(item + 0x2A04);
        z = *(s32 *)(item + 0x2A30);
        if (alpha == 0) {
            continue;
        }
        glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        if (i == 1) {
            reg_a0 = D_002716E0[page];
            glyph_queue_add(x, y + 0x38, z, 0, 0x80, alpha, 1);
            reg_a0 = D_00271640[sel];
            glyph_queue_add(x, y + 0x78, z, 0, 0x80, alpha, 1);
        }
        if (i >= 3 && i < 8) {
            reg_a0 = (u8 *)D_00684CA0 + (i - 3) * 11;
            glyph_queue_add(x, y + 0x38, z, 0, 0x80, alpha, 1);
        }
        if (i == 9) {
            reg_a0 = (u8 *)D_00684CD7;
            glyph_queue_add(x, y + 0x38, z, 0, 0x80, alpha, 1);
        }
    }
    glyph_queue_flush();
    text_queue_clear();
    D_0028EB90 = D_0028EB9C;
    reg_a0 = (u8 *)D_0028DD94;
    func_002228D0(x - 10, 0x40);
    text_flush();
    reg_a0 = save;
}

extern s32 D_0028EAD8;
extern char D_00684CA0_as_char_a6_a11[6][11];
extern s32 D_00684CF0_as_s32_a_a4_a5[][4][5];

void func_0022AD20(s32 arg0, s32 arg1) {
    s32 i;
    s32 j;
    s32 v;
    s32 lead;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 11; j++) {
            D_00684CA0_as_char_a6_a11[i][j] = ' ';
        }
        D_00684CA0_as_char_a6_a11[i][10] = 0;
    }
    for (i = 0; i < 6; i++) {
        if (i == 5) {
            v = D_0028EAD8;
        } else {
            v = D_00684CF0_as_s32_a_a4_a5[arg0][arg1][i];
        }
        lead = 0;
        if (v >= 100000000) {
            D_00684CA0_as_char_a6_a11[i][0] = v / 100000000 + '0';
            v %= 100000000;
            lead = 1;
        }
        if (v >= 10000000) {
            D_00684CA0_as_char_a6_a11[i][1] = v / 10000000 + '0';
            v %= 10000000;
            lead = 1;
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][1] = '0';
        }
        if (v >= 1000000) {
            D_00684CA0_as_char_a6_a11[i][2] = v / 1000000 + '0';
            v %= 1000000;
            lead = 1;
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][2] = '0';
        }
        if (v >= 100000) {
            D_00684CA0_as_char_a6_a11[i][3] = v / 100000 + '0';
            v %= 100000;
            lead = 1;
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][3] = '0';
        }
        if (v >= 10000) {
            D_00684CA0_as_char_a6_a11[i][4] = v / 10000 + '0';
            v %= 10000;
            lead = 1;
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][4] = '0';
        }
        if (v >= 1000) {
            D_00684CA0_as_char_a6_a11[i][5] = v / 1000 + '0';
            v %= 1000;
            lead = 1;
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][5] = '0';
        }
        if (v >= 100) {
            D_00684CA0_as_char_a6_a11[i][6] = v / 100 + '0';
            v %= 100;
            lead = 1;
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][6] = '0';
        }
        if (v >= 10) {
            D_00684CA0_as_char_a6_a11[i][7] = v / 10 + '0';
            v %= 10;
            lead = 1;
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][7] = '0';
        }
        if (v > 0) {
            D_00684CA0_as_char_a6_a11[i][8] = v + '0';
        } else if (lead) {
            D_00684CA0_as_char_a6_a11[i][8] = '0';
        }
        D_00684CA0_as_char_a6_a11[i][9] = '0';
    }
}

extern s16 D_00271760[];
extern s16 D_00271784[];

void func_0022B1D0(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
    s32 x;

    switch (D_0028EB54) {
    case 0:
        break;
    case 1:
        D_0028EB50 += 4;
        if (D_0028EB50 >= 0x40) {
            D_0028EB54 = 0;
            D_0028EB50 = 0x40;
        }
        break;
    case 2:
        D_0028EB50 -= 4;
        if (D_0028EB50 <= 0) {
            D_0028EB50 = 0;
            D_0028EB54 = 0;
        }
        break;
    }
    if (D_0028EB58 != -1) {
        x = D_00271760[D_0028EB58 * 2];
        if (D_0028EB50 != 0) {
            gfx_draw_color_box(x - 8, 0, 0x12, 0xE0, 0x5A, D_0028EB50, 0xB4, 1, 1);
        }
    }
    if (D_0028EB50 != 0) {
        gfx_draw_color_box(D_00271784[0] - 8, 0, 0x12, 0xE0, 0x5A, D_0028EB50, 0xB4, 1, 1);
    }
}


void func_0022B2F0(void) {
    if (g_replay_slots_from_disc == 0) {
        func_0022B4B0();
        return;
    }
    func_0022B540();
}

extern char D_00289E50[];
extern char D_00289E70[];
extern char D_00289E90[];
extern char D_00289EB0[];
extern char D_00289ED0[];
extern char D_00289EF0[];
extern u8 D_0028ED30_as_u8_a8[8];
extern u16 D_0028ED40;
extern s32 D_0028ED44;
extern u16 D_0028ED48;
extern u16 D_0028ED4C;
extern s32 D_0028ED50;
extern u16 D_0028ED54;
extern u8 g_replay_watch_after_run;
extern u8 D_006A4C00[];

typedef struct {
    u8 pad0000[0x327C];
    s32 score1;
    s32 score2;
    u8 pad3284[4];
    u16 stage1;
    u16 stage2;
    u16 pad328C;
    u16 count1;
    u16 pad3290;
    u16 count2;
} SaveBody;

void func_0022B330(void) {
    extern void delta_encode(u8 *buf);
    extern void replay_file_pointers_decode(void *data);
    s32 count;
    s32 i;
    SaveBody *data;

    count = 0;
    for (i = 0; i < 6; i++) {
        if (D_0028ED30_as_u8_a8[i] == g_replay_file_loaded[0x38 + i]) {
            count++;
        }
    }
    if (count == 6) {
        data = (SaveBody *)D_006A4C00;
        delta_encode((u8 *)data);
        replay_file_pointers_decode(g_replay_file_loaded);
        printf(D_00289E50, D_0028ED50, data->score1);
        printf(D_00289E70, D_0028ED54, data->count1);
        printf(D_00289E90, D_0028ED4C, data->stage1);
        printf(D_00289EB0, D_0028ED44, data->score2);
        printf(D_00289ED0, D_0028ED48, data->count2);
        printf(D_00289EF0, D_0028ED40, data->stage2);
        if (D_0028ED54 == data->count1 && D_0028ED50 == data->score1 &&
            D_0028ED4C == data->stage1 && D_0028ED48 == data->count2 &&
            D_0028ED44 == data->score2 && D_0028ED40 == data->stage2) {
            memcpy(g_replay_file, g_replay_file_loaded, 0x202E8);
            g_replay_watch_after_run = 1;
        }
    }
}

s32 func_0022C780();
extern u8 D_0028E378;
extern u8 D_0028EC4C;
extern s32 D_0028EC50;
extern s32 D_0028ECC4;
extern s32 D_0028ED0C;

s32 func_0022B4B0(void) {
    switch (D_0028EC50) {                           /* irregular */
    case 0:
        D_0028EC4C = 1;
        D_0028ED0C = 0;
        D_0028EC50 += 1;
        g_replay_watch_after_run = 0;
        D_0028E378 = 0xFF;
        /* fallthrough */
    case 1:
        func_0022C780();
        if (D_0028ED0C != 0) {
            D_0028ED0C = 0;
            D_0028EC50 = 0;
            D_0028EC4C = 0;
            if (D_0028ECC4 != 0) {
                func_0022B330();
            }
            return 1;
        }
    default:
        return 0;
    }
}

u8 func_00231840();
extern u8 D_0028EAB8;

s32 func_0022B540(void) {
    switch (D_0028EC50) {
    case 0:
        D_0028EC4C = 1;
        g_replay_watch_after_run = 0;
        D_0028EC50 += 1;
        D_0028E378 = 0xFF;
        /* fallthrough */
    case 1:
        D_0028EAB8 = func_00231840();
        if (D_0028EAB8 == 0xFF) {
            D_0028EC50 = 3;
        } else {
            D_0028EAB8 -= 1;
            D_0028EC50 += 1;
        }
        break;
    case 2:
        if (replay_disc_file_load(D_0028EAB8) != 0) {
            D_0028EC50 += 1;
            func_0022B330();
        }
        break;
    case 3:
        D_0028EC50 = 0;
        D_0028EC4C = 0;
        return 1;
    }
    return 0;
}

extern u16 g_p2_score_digits;
extern u16 g_p1_score_digits;
extern u16 g_p2_score_billions;
extern u16 g_p1_score_billions;
extern s32 g_p2_score_as_s32;
extern s32 g_p1_score_as_s32;

void func_0022B620(void) {
    D_0028ED54 = g_p1_score_digits;
    D_0028ED50 = g_p1_score_as_s32;
    D_0028ED4C = g_p1_score_billions;
    D_0028ED48 = g_p2_score_digits;
    D_0028ED44 = g_p2_score_as_s32;
    D_0028ED40 = g_p2_score_billions;
}

extern void replay_slots_reset(void);
extern void replay_file_pointers_encode(void *data);
extern u8 D_0028E2B8[8];
extern u8 D_0028E368;
extern s32 D_0028EB8C;

s32 func_0022B660(void) {
    extern s32 replay_slots_update(void);
    extern void replay_slots_open(s32 a, s32 b, s32 c);
    u8 *save = g_replay_file;
    s32 state;

    switch (state = D_0028EC50) {
    default:
        D_0028EC50 = state + 1;
        break;
    case 0:
        save[0x38] = D_0028E2B8[0];
        save[0x39] = D_0028E2B8[1];
        save[0x3A] = D_0028E2B8[2];
        save[0x3B] = D_0028E2B8[3];
        save[0x3C] = D_0028E2B8[4];
        save[0x3D] = D_0028E2B8[5];
        save[0x3E] = D_0028E2B8[6];
        save[0x3F] = D_0028E2B8[7];
        D_0028E378 = 0xFF;
        D_0028EC4C = 1;
        D_0028E368 = 0;
        memcpy(g_replay_file_loaded, save, 0x202E8);
        replay_file_pointers_encode(g_replay_file_loaded);
        func_0022B7A0((s32)D_006A4C00);
        replay_slots_reset();
        replay_slots_open(1, 2, 0);
        D_0028EB90 = 0;
        D_0028EB04 = 1;
        D_0028EB8C = 0;
        D_0028EC50++;
        break;
    case 1:
        if (replay_slots_update() == 0) {
            D_0028EC50++;
            D_0028EB04 = 2;
        }
        break;
    case 0x11:
        D_0028EC50 = 0;
        D_0028E368 = 1;
        D_0028EC4C = 0;
        return 1;
    }
    return 0;
}

void func_0022B7A0(s32 arg0) {
    s32 var_v1;
    s8 *temp_a1;
    s8 *temp_t0_2;
    u8 temp_a3;
    u8 temp_t0;

    var_v1 = 1;
    do {
        temp_a1 = (s8 *)(arg0 + var_v1);
        temp_t0 = (*(s8 *)((u8 *)(temp_a1) + (0)));
        var_v1 += 8;
        (*(s8 *)((u8 *)(temp_a1) + (0))) = temp_t0 + (*(s8 *)((u8 *)(temp_a1) + (-1)));
        (*(s8 *)((u8 *)(temp_a1) + (1))) += (*(s8 *)((u8 *)(temp_a1) + (0)));
        (*(s8 *)((u8 *)(temp_a1) + (2))) += (*(s8 *)((u8 *)(temp_a1) + (1)));
        (*(s8 *)((u8 *)(temp_a1) + (3))) += (*(s8 *)((u8 *)(temp_a1) + (2)));
        (*(s8 *)((u8 *)(temp_a1) + (4))) += (*(s8 *)((u8 *)(temp_a1) + (3)));
        (*(s8 *)((u8 *)(temp_a1) + (5))) += (*(s8 *)((u8 *)(temp_a1) + (4)));
        (*(s8 *)((u8 *)(temp_a1) + (6))) += (*(s8 *)((u8 *)(temp_a1) + (5)));
        (*(s8 *)((u8 *)(temp_a1) + (7))) += (*(s8 *)((u8 *)(temp_a1) + (6)));
    } while (var_v1 < 0x552B);
    if (var_v1 < 0x5533) {
        do {
            temp_t0_2 = (s8 *)(arg0 + var_v1);
            temp_a3 = (*(s8 *)((u8 *)(temp_t0_2) + (0)));
            var_v1 += 1;
            (*(s8 *)((u8 *)(temp_t0_2) + (0))) = temp_a3 + (*(s8 *)((u8 *)(temp_t0_2) + (-1)));
        } while (var_v1 < 0x5533);
    }
}

extern u8 g_replay_mode;

void func_0022B870(void) {
    extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;

    if (D_0028EC50 != 0) {
        save_d0 = reg_d0.w;
        save_d1 = reg_d1.w;
        save_d2 = reg_d2.w;
        save_d3 = reg_d3.w;
        save_d4 = reg_d4.w;
        save_d5 = reg_d5.w;
        save_d6 = reg_d6.w;
        save_d7 = reg_d7.w;
        save_a0 = reg_a0;
        save_a1 = reg_a1;
        save_a2 = reg_a2;
        save_a3 = reg_a3;
        save_a4 = reg_a4;
        save_a5 = reg_a5;
        save_a6 = reg_a6;
        glyph_queue_clear();
        switch (D_0028EB04) {
        case 0:
            break;
        case 1:
            D_0028EB90 += 8;
            if (D_0028EB90 >= 0x80) {
                D_0028EB04 = 0;
                D_0028EB90 = 0x80;
            }
            break;
        case 2:
            D_0028EB90 -= 8;
            if (D_0028EB90 <= 0) {
                D_0028EB90 = 0;
                D_0028EB04 = 0;
            }
            break;
        }
        gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x50, D_0028EB90 / 2, 1, 1, 1);
        if (g_replay_mode == 1) {
            func_0022BA60();
            replay_slots_draw();
        }
        glyph_queue_flush();
        reg_d0.w = save_d0;
        reg_d1.w = save_d1;
        reg_d2.w = save_d2;
        reg_d3.w = save_d3;
        reg_d4.w = save_d4;
        reg_d5.w = save_d5;
        reg_d6.w = save_d6;
        reg_d7.w = save_d7;
        reg_a0 = save_a0;
        reg_a1 = save_a1;
        reg_a2 = save_a2;
        reg_a3 = save_a3;
        reg_a4 = save_a4;
        reg_a5 = save_a5;
        reg_a6 = save_a6;
    }
}

s32 frame_draw_left_panel();
extern s32 D_0028DDA8_as_s32;

void func_0022BA60(void) {
    s32 text_queue_clear();
    s32 text_flush();
    void gfx_draw_color_box(s32 a, s32 b, s32 c, s32 d, s32 e, s32 alpha, s32 g, s32 h, s32 i);
    s32 func_002228D0();
    s32 var_s0;

    if (D_0028EB90 != 0) {
        text_queue_clear();
        var_s0 = D_0028EB90;
        if (D_0028EB90 >= 0x40) {
            var_s0 = 0x40;
        }
        if (var_s0 != 0) {
            frame_draw_left_panel(D_0028EB90);
            gfx_draw_color_box(0xC, 8, 0x40, 0xD0, 0x12C, var_s0, 1, 1, 0x40);
        }
        if ((g_replay_slots_state_as_u8 != 0) && ((u32) (g_replay_slots_state_as_u8 - 1) > 1U) && ((u32) (g_replay_slots_state_as_u8 - 5) > 1U)) {
            reg_a0 = (u8 *)D_0028DDA8_as_s32;
            func_002228D0(0x36, 8);
        }
        text_flush();
    }
}

s32 replay_snapshot_checksum(const u8 *data)
{
    s32 checksum = 0;
    s32 offset = 0;
    const u8 *block;

    do {
        block = data + offset;
        offset += 8;
        checksum += block[0] + block[1] + block[2] + block[3]
                  + block[4] + block[5] + block[6] + block[7];
    } while (offset < 0x5530);

    return checksum;
}

typedef struct {
    u8 stat;
    u8 second;
    u8 minute;
    u8 hour;
    u8 pad;
    u8 day;
    u8 month;
    u8 year;
} CdClock;

s32 sceCdReadClock(CdClock *clock);

#define FROM_BCD(x) (((x) & 0xF) + ((x) >> 4) * 10)

s32 func_0022BB80(u8 *out)
{
    CdClock clock;

    if (sceCdReadClock(&clock) != 0) {
        out[0] = FROM_BCD(clock.month);
        out[1] = FROM_BCD(clock.day);
        out[2] = FROM_BCD(clock.hour);
        out[3] = FROM_BCD(clock.minute);
        out[4] = FROM_BCD(clock.second);
        return 0;
    }
    return clock.stat;
}

typedef struct {
    s16 h[33];
} Row;

extern void func_00236900(void);
extern Row g_replay_file_headers_as_Row_a[];
extern s16 g_replay_slot_infos_as_s16_a_a512[][512];

s32 replay_disc_headers_load(void) {
    s32 i;

    func_00236900();
    for (i = 0; i < 10; i++) {
        *(Row *)g_replay_slot_infos_as_s16_a_a512[i] = g_replay_file_headers_as_Row_a[i];
    }
    return 1;
}

s32 music_stop();
extern char D_00289F10[];
extern char D_00289F30[];
extern s8 g_cd_async_state;
extern s8 g_cd_async_busy;
extern u8 *g_replay_disc_load_buf;
extern u8 g_replay_disc_load_slot;
extern u8 g_replay_disc_load_step;
extern u8 g_load_buf[];
s32 replay_disc_file_load(u8 arg0) {
    u32 state;

    state = g_replay_disc_load_step;
    switch (state) {
    case 0:
        g_replay_disc_load_slot = arg0;
        g_replay_disc_load_step = state + 1;
        g_replay_disc_load_buf = g_load_buf;
        music_stop();
        printf(D_00289F10);
        break;
    case 1:
        if (g_cd_async_busy != 0) {
            g_cd_async_busy = 1;
            g_replay_disc_load_step = state + 1;
            g_cd_async_state = 0;
        }
        break;
    case 2:
        cd_read_async(g_replay_disc_load_buf, g_replay_files[g_replay_disc_load_slot].size, g_replay_files[g_replay_disc_load_slot].lba);
        if (g_cd_async_busy == 0) {
#ifndef DEATH_LABEL
            g_cd_async_busy = 1;
            g_cd_async_state = 0;
#endif
            g_replay_disc_load_step = 0;
            memcpy(g_replay_file_loaded, g_replay_disc_load_buf, 0x202E8);
            printf(D_00289F30);
            return 1;
        }
        break;
    }
    return 0;
}


void func_0022BF60(void) {
    u8 temp_a0;

    temp_a0 = *(u8 *)(reg_a5 + 3);
    switch (temp_a0) {                              /* irregular */
    case 0:
        func_0022BFD0(temp_a0);
        break;
    case 1:
        func_0022C1F0(temp_a0);
        break;
    case 2:
        func_0022C1E0(temp_a0);
        break;
    }
}

extern void text_layer_clear(void);
extern void func_00171910(void);
extern void text_palette_load(void);
extern void task_start(void);
extern u8 g_default_text_palette[];
extern u8 D_0028DE40[];
extern u8 D_0028DE44[];
extern u8 g_game_mode;
extern u8 g_game_frame_ran;
extern u8 D_0028E3F8_as_u8;
extern u8 D_0028E7B4;
extern u16 D_00684C80[];
#ifdef DEATH_LABEL
extern u8 death_D_00290DC0;
extern u8 death_D_00290DBC;
extern u8 death_D_0029085C;
extern u8 death_D_00290850;
extern u32 death_D_00290DB8;
extern u32 death_D_00290DB4;
extern u16 g_p1_max_hits;
extern u16 g_p2_max_hits;
extern u16 g_loop;
#endif

void func_0022BFD0() {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
#ifdef DEATH_LABEL
    g_game_mode = 2;
    g_loop = 0;
    D_00684C80[6] = 0;
    D_00684C80[4] = 3;
    D_00684C80[5] = 1;
    D_00684C80[7] = 0;
    D_00684C80[8] = 3;
    if (death_D_00290DC0 == 0) {
        if (D_00684C80[9] == 2) {
            D_00684C80[7] = 3;
        }
        if (D_00684C80[9] == 4) {
            D_00684C80[7] = 0;
        }
        if (D_00684C80[9] == 6) {
            D_00684C80[7] = 1;
        }
    } else {
        D_00684C80[7] = 3;
    }
    D_00684C80[10] = 0;
    death_D_0029085C = 0;
    death_D_00290850 = 0;
    death_D_00290DBC = 0;
    g_game_frame_ran = 0;
    D_0028E3F8_as_u8 = 0;
    D_0028E368 = 0;
    if (death_D_00290DC0 != 0) {
        func_0022B620();
        reg_d0.h[0] = 10;
        death_D_00290DB8 = g_p1_max_hits;
        death_D_00290DB4 = g_p2_max_hits;
        task_start();
        *(u16 *)(reg_a0 + 4) = D_00684C80[6];
    }
    func_00171910();
    printf("death round[%d]\n", death_D_00290DC0);
#else
    g_game_mode = 2;
    D_00684C80[0] = 0xFF;
    D_00684C80[1] = 0xFF;
    D_00684C80[2] = 0xFF;
    D_00684C80[3] = 0xFF;
    if (D_0028E7B4 & 1) {
        D_00684C80[0] = D_0028DE40[0];
        D_00684C80[1] = D_0028DE44[0];
    } else {
        D_00684C80[2] = D_0028DE40[0];
        D_00684C80[3] = D_0028DE44[0];
    }
    D_00684C80[6] = 0;
    D_00684C80[4] = 3;
    g_game_frame_ran = 0;
    D_0028E3F8_as_u8 = 0;
    D_00684C80[5] = 1;
    D_00684C80[8] = 3;
    reg_d0.h[0] = 10;
    D_00684C80[7] = 0;
    D_0028E368 = 0;
    D_00684C80[10] = 0;
    task_start();
    *(u16 *)(reg_a0 + 4) = D_00684C80[6];
    func_00171910();
#endif
    text_layer_clear();
    reg_d0.w = 0;
    reg_a0 = (u8 *)g_default_text_palette;
    text_palette_load();
    *(u8 *)(reg_a5 + 3) = 1;
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}

extern void task_stop_self(void);

void func_0022C1E0() {
    task_stop_self();
}


s32 frame_counters_reset();
s32 func_00135110();
s32 func_001719A0();
s32 func_001719B0();
s32 func_001719D0();
s32 music_play_bgm2();
extern u8 g_pad_input_locked;
extern u8 D_0028E2C4;
extern u8 g_simulation_boss_start;
extern u8 D_0028E2D4;
extern u8 D_0028E2E4;
extern u8 g_setting_ship_stock;
extern u8 g_setting_extend;
extern u8 g_setting_difficulty;
extern u16 g_score_panel_intro;
extern u16 g_loop;
extern u8 D_00684C88[];
extern u16 D_00684C8A[];
extern u16 D_00684C8C[];
extern u8 D_00684C8E[];
extern u8 D_00684C90[];
extern u16 D_00684C94[];
#ifdef DEATH_LABEL
s32 fade_reset();
extern u8 death_D_00290DC0;
extern u8 death_D_00290DBC;
extern u16 death_D_00290DB8_as_u16;
extern u16 death_D_00290DB4_as_u16;
extern u16 g_p1_max_hits;
extern u16 g_p2_max_hits;
#endif

void func_0022C1F0() {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    func_001719D0();
    switch (D_00684C94[0]) {                           /* irregular */
    default:
        D_00684C94[0] += 1;
        break;
    case 0:
        func_001719A0();
        D_00684C94[0] += 1;
        break;
#ifdef DEATH_LABEL
    case 2:
        fade_reset();
        D_00684C94[0] += 1;
        break;
#endif
    case 16:
        g_simulation_boss_start = 1;
        D_0028E2E4 = 0;
        D_0028E2D4 = 0xFF;
        D_0028E2C4 = 0;
        g_setting_difficulty = D_00684C88[0];
        g_setting_extend = D_00684C90[0];
        g_setting_ship_stock = D_00684C8E[0];
        func_0022C450(D_00684C88[0]);
        g_pad_input_locked = 1;
#ifdef DEATH_LABEL
        if (death_D_00290DC0 != 0) {
            death_D_00290DBC = 1;
            g_p1_max_hits = death_D_00290DB8_as_u16;
            g_p2_max_hits = death_D_00290DB4_as_u16;
        }
#endif
        D_00684C94[0] += 1;
        break;
#ifdef DEATH_LABEL
    case 17:
        death_D_00290DBC = 0;
        D_00684C94[0] += 1;
        break;
#endif
    case MAIN_OR_DEATH_LABEL(17, 18):
        if (g_score_panel_intro == 0) {
            D_00684C94[0] += 1;
        }
        break;
    case MAIN_OR_DEATH_LABEL(18, 19):
        frame_counters_reset();
        if (g_game_frame_ran != 0) {
            g_pad_input_locked = 0;
            D_00684C94[0] += 1;
            g_loop = D_00684C8A[0];
            func_00135110();
#ifdef DEATH_LABEL
            fade_reset();
#endif
            if (D_00684C8C[0] == 0) {
                music_play_bgm2();
            }
        }
        break;
    case MAIN_OR_DEATH_LABEL(19, 20):
        func_001719B0();
        if (cond_flag == 0) {
            *(s8 *)(reg_a5 + 3) = 2;
        }
        break;
    }
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
}

extern void ship_select_apply(void);

void func_0022C450() {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;

    save_d0 = reg_d0.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_d1 = reg_d1.w;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_d2 = reg_d2.w;
    save_a4 = reg_a4;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_a5 = reg_a5;
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.h[0] = D_00684C80[0];
    reg_d1.h[0] = D_00684C80[1];
    reg_d2.w = 0;
    g_game_frame_ran = 0;
    reg_d3.w = 0;
    reg_d4.w = 1;
    reg_d2.h[0] = D_00684C80[2];
    reg_d3.h[0] = D_00684C80[3];
    ship_select_apply();
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
}
