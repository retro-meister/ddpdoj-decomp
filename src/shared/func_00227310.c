#include "common.h"

typedef struct {
    u8 step;
    s8 state;
    s8 flag;
    s8 pad3;
    s16 value;
    s16 pad6;
} Fade;

extern Fade D_0028EBD8;
extern Fade D_0028EBE0;
extern Fade D_0028EBE8;
extern Fade D_0028EBF0;
extern Fade D_0028EBF8;
extern Fade D_0028EC00;
extern Fade D_0028EC08;
extern Fade D_0028EC10;
extern Fade D_0028EC18;

static void func_00227310(Fade *fade);
s32 func_00227350(Fade *fade, s32 command);
static s32 func_002273B0(Fade *fade, s32 command);
void func_002273E0(void);
static void func_00227440(Fade *fade);
void func_002274C0(Fade *arg0, u8 **arg1, s32 arg2);
void func_002275C0(void);
void func_002275F0(void);
void func_00227640(void);
void func_00227680(void);
void func_002276C0(void);
void func_00227830(void);
void func_002278D0(void);
void func_00227900(void);
void func_00227930(void);
void func_00227960(void);
void func_002279A0(void);
void func_00227AE0(void);
void func_00227B70(void);
void func_00227C90(void);
void func_00227CD0(void);
void func_00227D00(void);
void func_00227D90(void);
void func_00227E00(void);
void func_00227E30(void);
void func_00227E70(void);
void func_00227F00(void);
void func_00227F70(void);
void func_00227FE0(void);
void func_00228060(void);
void func_00228520(void);
void func_00228550(void);
void func_00228580(void);
void func_00228770(void);
void func_002287E0(void);
void func_002288B0(void);
void func_002288E0(void);
void func_00228910(void);
void func_00228B50(void);
void func_00228BC0(void);
void func_00228E20(void);
void func_00228E50(void);
void func_00228E80(void);
void func_002295F0(void);
void func_00229660(void);
void func_00229950(s32 x, s32 y, s32 alpha, s32 mode, s32 kind);
void func_00229DC0(void);
void func_00229DF0(void);
void func_00229E20(void);
void func_0022A040(void);
void func_0022A0B0(void);
void func_0022A260(void);
void func_0022A2B0(void);
void func_0022A2E0(void);
void func_0022A410(void);
void func_0022A480(void);
extern u8 *D_00270850[];

extern s8 D_0028EB04;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s32 D_0028EB90;
extern u16 D_0028E320;
extern u32 D_0057CC70[];
extern s32 D_0057CC74[];
extern s32 D_0057CC78[];
void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
extern s8 D_002714F0[];
extern u8 D_00685010[];
extern u8 *reg_a0;
extern void func_00222260(s32 command);
s32 func_00222340(s32);
extern s8 D_0028EB50;
s8 func_00221120(s32 arg0);
extern s8 D_002714F7[];
extern s8 D_0028EB4C;
extern s8 D_0028EB7C;
extern s8 D_0028EB84;
extern s8 D_0028EC24;
extern s32 D_0028EC7C;
s32 func_002365A0();
extern s16 D_0068DF02[];
s32 printf(const char *format, ...);
extern s16 D_00270822[];
extern s8 D_002714FA[];
extern char D_00289E38[];
extern u8 D_0028E258;
extern u8 D_0028E280;
extern u8 *D_00271480[];
extern s32 D_0028DCF8;
s32 func_002263D0(s32, s8, s32);
extern s8 D_0028EC20;
extern s8 D_0028ED7C;
s32 func_00226260();
s32 func_00227000();
s32 func_002263F0();
extern void *memcpy(void *dst, const void *src, u32 n);
extern s16 D_00270810[];
extern s16 D_00270828[];
extern s16 D_00270838[];
extern s16 D_0068DE90[];
extern s16 D_0068DEA0[];
extern s16 D_0068DEB0[];
extern s16 D_0068DEC8[];
extern s16 D_0068DECA[];
extern s16 D_0068DECC[];
extern s16 D_0068DECE[];
extern s16 D_0068DED0[];
extern s16 D_0068DED2[];
extern s16 D_0068DED8[];
extern s16 D_0068DEDA[];
extern s16 D_0068DEDC[];
extern s16 D_0068DEDE[];
extern s16 D_0068DEE0[];
extern s16 D_0068DEF0[];
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
extern u32 D_0057CC60[];
extern void func_00224BA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 flags);
extern s32 strlen(u8 *s);
extern u8 *D_002708D0[];
extern u8 **D_002709B0[];
extern u16 D_002712C0[];
extern s8 D_002712D8[];
extern s8 D_00271502[];
extern s32 D_0057CC20[];
extern s32 D_0057CC50[];
extern u8 *D_002709D0[];
extern u8 **D_00271290[];
extern u8 *D_0028DCC8;
extern u8 *D_0028DCCC;
extern void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
extern u8 *D_00270AB0[];
extern u8 *D_0028DCE0;
extern s8 D_00271503[];
extern u16 D_00271458[];
extern s8 D_00271468[];
extern u8 *D_002712F0[];
extern u8 **D_00271440[];
s32 func_00222530(s32);
extern void text_queue_clear(void);
extern void text_flush(void);
extern void func_002228D0(s32 x, s32 y);
extern void func_0022AD20(s32 page, s32 sel);
extern u8 *D_002714B0[];
extern s8 D_002714FD[];
extern u8 *D_002716E0[];
extern u8 *D_0028DD98;
extern u8 D_00684CA0[];
extern s32 D_006880A0[];
extern s32 D_006880A4[];

static void func_00227310(Fade *fade) {
    D_0028E320 = 0xE10;
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
    D_0028E320 = 0xE10;
    if (D_0057CC78[0] == 0) {
        D_0028E320 -= 1;
        if (D_0028E320 == 0) {
            D_0057CC74[0] = 0x40;
            D_0057CC70[0] = 0x40;
            D_0057CC78[0] = 0x40;
        }
    } else {
        D_0028E320 = 0xE10;
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

    saved = D_0028EC18.flag;
    func_00227310(&D_0028EC18);
    D_0028EC18.flag = saved;
    func_00222260(7);
}

void func_002275F0(void) {
    s8 value = D_0028EC18.flag;
    if (func_002273B0(&D_0028EC18, 7) != 0) {
        D_0028EB58 = value;
        if (value == 0) {
            D_0028EB58++;
        }
    }
}

void func_00227640(void) {
    func_00227310(&D_0028EC18);
    D_0028EC18.flag = 0;
    D_0028EC18.value = 0;
    D_0028EB50 = 0;
    D_0028EB58 = 0;
    func_00222340(7);
}

void func_00227680(void) {
    if (func_00227350(&D_0028EC18, 7) != 0) {
        D_0028EB58 = 1;
        D_0028EC18.step = 2;
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
        buttons = D_0057CC70[D_0028EC24];
        if (buttons & 0x40) {
            D_0028EB58 = last;
            confirm = 1;
        } else if (buttons & 0x20) {
            confirm = 1;
        }
    }
    D_0028EC18.flag = D_0028EB58;
    if (confirm != 0) {
        func_0018D4B0();
        D_0028EC18.step += 1;
        if (last == D_0028EC18.flag) {
            func_00222260(0);
            D_0028EB7C = 3;
            D_0028EB84 = 0;
            D_0028EB90 = 0x40;
            D_0028EB4C = 1;
            D_0028EB04 = 1;
            D_0028EB54 = 2;
            D_0028EC18.state = 2;
        } else {
            D_0028EC18.state = 0;
            D_0028EC18.value = 0;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            switch (D_0028EC18.flag) {
            case 1:
                D_0028EC10.flag = 1;
                D_0028EC10.step = 0;
                D_0028EB84 = 8;
                break;
            case 2:
                D_0028EBE8.step = 0;
                D_0028EB84 = 10;
                break;
            case 3:
                D_0028EBE0.step = 0;
                D_0028EB84 = 11;
                break;
            case 4:
                D_0028EBE0.step = 0;
                D_0028EB84 = 22;
                break;
            }
        }
    }
}

void func_00227830(void) {
    switch (D_0028EC18.step) {
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
    func_00227440(&D_0028EC18);
    func_002274C0(&D_0028EC18, D_00270850, 7);
}

void func_00227900(void) {
    func_00227310(&D_0028EBE8);
    func_00222260(0xA);
    D_0028EC7C = 0;
}

void func_00227930(void) {
    if (func_002365A0() != 0) {
        D_0028EBE8.step += 1;
    }
}

void func_00227960(void) {
    if (func_002273B0(&D_0028EBE8, 0xA) != 0) {
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
        buttons = D_0057CC70[D_0028EC24];
        if (buttons & 0x40) {
            D_0028EB58 = last;
            confirm = 1;
        } else if (buttons & 0x20) {
            confirm = 1;
        }
    }
    D_0028EBE8.flag = D_0028EB58;
    if (confirm != 0) {
        if (last != D_0028EBE8.flag) {
            selected = D_0028EBE8.flag - 1;
            if (D_0028E258 < selected) {
                func_0018D490();
                return;
            }
#ifndef DEATH_LABEL
            D_0028E280 = selected;
            printf(D_00289E38, D_0028E280);
#endif
            func_0018D4B0();
            D_0028EBE8.step += 1;
            D_0068DF02[0] = D_0028EBE8.flag - 1;
            func_002272D0();
        } else {
            func_0018D4B0();
            D_0028EC18.flag = 2;
            D_0028EBE8.state = 0;
            D_0028EB84 = 7;
            D_0028EBE8.value = 0;
            D_0028EC18.step = 0;
            D_0068DF02[0] = D_00270822[0];
        }
    }
}

void func_00227AE0(void) {
    switch (D_0028EBE8.step) {
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
    if (D_0028EBE8.step < 3) {
        return;
    }
    func_00227440(&D_0028EBE8);
    if (D_0028EBE8.value == 0) {
        return;
    }
    i = 0;
    if (0 < count) {
        offset = 0;
        index = 0;
        do {
            entry = D_00685010 + offset;
            if (*(s32 *)(entry + 0x2334) != 0) {
                value = D_0028EBE8.value;
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
    func_00227310(&D_0028EBE0);
    func_00222260(0xB);
    D_0028EC20 = 0;
    D_0028ED7C = 0;
    func_002263D0(0, D_0028EC24, 0);
}

void func_00227CD0(void) {
    if (func_002273B0(&D_0028EBE0, 0xB) != 0) {
        D_0028EB54 = 0;
    }
}

void func_00227D00(void) {
    s32 temp_v0;

    func_002273E0();
    temp_v0 = func_00226260();
    switch (temp_v0) {
    case 0:
        D_0028EC18.flag = 3;
        D_0028EB54 = 0;
        D_0028EB84 = 7;
        D_0028EB50 = 0;
        D_0028EBE0.state = 0;
        D_0028EBE0.value = 0;
        D_0028EC18.step = 0;
        return;
    case 3:
        D_0028ED7C = 2;
        D_0028EC20 = 1;
        D_0028EBE0.step += 1;
        func_002272D0();
        return;
    }
}

void func_00227D90(void) {
    switch (D_0028EBE0.step) {
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
    func_00227440(&D_0028EBE0);
    func_00227000();
}

void func_00227E30(void) {
    func_00227310(&D_0028EBE0);
    func_00222260(0xB);
    D_0028EC20 = 0;
    D_0028ED7C = 0;
    func_002263D0(0, D_0028EC24, 1);
}

void func_00227E70(void) {
    s32 temp_v0;

    func_002273E0();
    temp_v0 = func_00226260();
    switch (temp_v0) {
    case 0:
        D_0028EC18.flag = 4;
        D_0028EB54 = 0;
        D_0028EB84 = 7;
        D_0028EB50 = 0;
        D_0028EBE0.state = 0;
        D_0028EBE0.value = 0;
        D_0028EC18.step = 0;
        break;
    case 3:
        D_0028ED7C = 2;
        D_0028EC20 = 1;
        D_0028EBE0.step += 1;
        func_002272D0();
        break;
    }
}

void func_00227F00(void) {
    switch (D_0028EBE0.step) {
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
    switch (D_0028EBE0.step) {
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
    s32 temp_v0;

    func_002273E0();
    temp_v0 = func_00226260();
    switch (temp_v0) {
    case 0:
        D_0028EB54 = 0;
        D_0028EC10.flag = 4;
        D_0028EB50 = 0;
        D_0028EB84 = 8;
        D_0028EBE0.state = 0;
        D_0028EBE0.value = 0;
        D_0028EC10.step = 0;
        break;
    case 3:
        func_00228060();
        func_002263F0();
        break;
    }
}

void func_00228060(void) {
    memcpy(D_0068DEF0, D_00270810, 0x16);
    memcpy(D_0068DED8, D_00270828, 0xA);
    memcpy(D_0068DEC8, D_00270838, 0xC);
    D_0068DED8[0] = D_006C58AA[0];
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
    D_0068DEF0[0] = D_006C58B8[0];
    D_0068DEF2[0] = D_006C58BA[0];
    D_0068DEF4[0] = D_006C58C0[0];
    D_0068DF04[0] = D_006C58C2[0];
    D_0068DEF6[0] = D_006C58B4[0];
    D_0068DEF8[0] = D_006C58B6[0];
    D_0068DEFA[0] = D_006C58CA[0];
    D_0068DEFE[0] = D_006C58BC[0];
    D_0068DF00[0] = D_006C58BE[0];
    D_0068DEFC[0] = D_006C58CC[0];
    D_0068DEC8[0] = D_006C58CE[0];
    D_0068DECA[0] = D_006C58D0[0];
    D_0068DECC[0] = D_006C58D2[0];
    D_0068DECE[0] = D_006C58B0[0];
    D_0068DED0[0] = D_006C58B2[0];
    D_0068DED2[0] = D_006C58D4[0];
    if (D_0068DED8[0] > 3) {
        D_0068DED8[0] = 1;
    }
    if (D_0068DEDE[0] > 19) {
        D_0068DEDE[0] = 20;
    }
    if (D_0068DEE0[0] > 3) {
        D_0068DEE0[0] = 0;
    }
    if (D_0068DEF0[0] > 1) {
        D_0068DEF0[0] = 0;
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
    if (D_0068DEC8[0] > 2) {
        D_0068DEC8[0] = 0;
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
    memcpy(D_0068DEB0, D_0068DEF0, 0x16);
    memcpy(D_0068DE90, D_0068DED8, 0xA);
    memcpy(D_0068DEA0, D_0068DEC8, 0xC);
}

void func_00228520(void)
{
    s8 saved;

    saved = D_0028EC10.flag;
    func_00227310(&D_0028EC10);
    D_0028EC10.flag = saved;
    func_00222260(8);
}

void func_00228550(void) {
    if (func_002273B0(&D_0028EC10, 8) != 0) {
        D_0028EB58 = D_0028EC10.flag;
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
        buttons = D_0057CC70[D_0028EC24];
        if (buttons & 0x40) {
            D_0028EB58 = last;
            confirm = 1;
        } else if (buttons & 0x20) {
            confirm = 1;
        }
    }
    D_0028EC10.flag = D_0028EB58;
    if (confirm != 0) {
        switch (D_0028EB58) {
        case 1:
            func_0018D4B0();
            D_0028EC10.state = 0;
            D_0028EB84 = 0x11;
            D_0028EC10.value = 0;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EC08.step = 0;
            D_0028EC10.step += 1;
            break;
        case 2:
            func_0018D4B0();
            D_0028EC10.state = 0;
            D_0028EB84 = 0x12;
            D_0028EC10.value = 0;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EC00.step = 0;
            D_0028EC10.step += 1;
            break;
        case 3:
            func_0018D4B0();
            D_0028EC10.state = 0;
            D_0028EB84 = 0x13;
            D_0028EC10.value = 0;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EBF8.step = 0;
            D_0028EC10.step += 1;
            break;
        case 4:
            func_0018D4B0();
            D_0028EC10.state = 0;
            D_0028EB84 = 0x14;
            D_0028EC10.value = 0;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EBE0.step = 0;
            D_0028EC10.step += 1;
            break;
        case 5:
            func_0018D4B0();
            D_0028EC10.state = 0;
            D_0028EC18.flag = 1;
            D_0028EC10.value = 0;
            D_0028EB84 = 7;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EC18.step = 0;
            D_0028EC10.step += 1;
            break;
        }
    }
}

void func_00228770(void) {
    switch (D_0028EC10.step) {
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
    s32 count;
    s32 i;
    s32 offset;
    s32 tableOffset;
    u8 *entry;

    count = D_002714F8[0];
    func_00227440(&D_0028EC10);
    if (D_0028EC10.value == 0) {
        return;
    }
    i = 0;
    if (0 < count) {
        offset = 0;
        tableOffset = 0;
        do {
            entry = D_00685010 + offset;
            if (*(s32 *)(entry + 0x1C34) != 0) {
                s32 value = D_0028EC10.value;

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
    func_00227310(&D_0028EC08);
    func_00222260(0x11);
}

void func_002288E0(void) {
    if (func_002273B0(&D_0028EC08, 0x11) != 0) {
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
        buttons = D_0057CC60[D_0028EC24];
        if (buttons & 0x8000) {
            dir = -1;
            skip = 1;
        } else if (buttons & 0x2000) {
            dir = 1;
            skip = 1;
        }
    }
    if (skip == 0) {
        buttons = D_0057CC70[D_0028EC24];
        if (buttons & 0x40) {
            D_0028EB58 = last;
            confirm = 1;
        } else if (buttons & 0x20) {
            confirm = 1;
        }
    }
    D_0028EC08.flag = D_0028EB58;
    if (confirm != 0) {
        switch (D_0028EB58) {
        case 6:
            func_0018D4B0();
            memcpy(D_0068DED8, D_00270828, 10);
            break;
        case 7:
            func_0018D4B0();
            D_0028EC08.state = 0;
            D_0028EC10.flag = 1;
            D_0028EC08.value = 0;
            D_0028EB84 = 8;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EC10.step = 0;
            D_0028EC08.step += 1;
            break;
        }
    } else if (dir != 0) {
        item = D_0028DCB0[D_0028EB58];
        if (!(0 > item)) {
            value = &D_0068DED8[item];
            count = D_0028DCA8[item];
            func_0018D4C0();
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
    switch (D_0028EC08.step) {
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
    func_00227440(&D_0028EC08);
    if (D_0028EC08.value == 0) {
        return;
    }
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x3BB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x3BAC) = alpha = D_0028EC08.value;
        x = *(s32 *)(item + 0x3B80);
        y = *(s32 *)(item + 0x3B84);
        z = *(s32 *)(item + 0x3BB0);
        reg_a0 = D_002708D0[i];
        glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        y += strlen(reg_a0) * 8;
        reg_a0 = 0;
        index = D_0028DCB0[i];
        if (index == -1) {
            continue;
        }
        entries = D_002709B0[index];
        value = D_0068DED8[index];
        reg_a0 = entries[value];
        if (reg_a0 == 0) {
            continue;
        }
        if (index == 4) {
            dbl = value * 2;
            reg_a0 = entries[dbl];
            if (dbl == 6) {
                glyph_queue_add(x, y, z, 0, 0x80, D_0028EC08.value, 1);
            } else {
                glyph_queue_add(x, y, z, 0, 0x80, D_0028EC08.value, 0);
                reg_a0 = D_002709B0[index][dbl + 1];
                glyph_queue_add(x - 8, y, z, 0, 0x80, D_0028EC08.value, 0);
            }
        } else {
            glyph_queue_add(x, y, z, 0, 0x80, D_0028EC08.value, 1);
        }
        if (i == D_0028EC08.flag) {
            func_00224BA0(x, y, z, 0, 0x80, D_0028EC08.value, 1, 3);
        }
    }
}

void func_00228E20(void) {
    func_00227310(&D_0028EC00);
    func_00222260(0x12);
}

void func_00228E50(void) {
    if (func_002273B0(&D_0028EC00, 0x12) != 0) {
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
            pad = D_0057CC50[D_0028EC24];
            if (pad & 0x8000) {
                dir = -1;
                moved = 1;
            } else if (pad & 0x2000) {
                dir = 1;
                moved = dir;
            }
        } else {
            pad = D_0057CC60[D_0028EC24];
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
        pad = D_0057CC70[D_0028EC24];
        if (pad & 0x40) {
            D_0028EB58 = last;
            confirm = 1;
        } else if (pad & 0x20) {
            confirm = 1;
        }
    }
    sel = D_0028EB58;
    D_0028EC00.flag = sel;
    if (confirm != 0) {
        switch (sel) {
        case 3:
            func_0018D4B0();
            D_0068DEF0[10] += 1;
            D_0068DEF0[10] &= 1;
            break;
        case 10:
            func_0018D4B0();
            memcpy(D_0068DEF0, D_00270810, 0x16);
            break;
        case 11:
            func_0018D4B0();
            D_0028EC00.state = 0;
            D_0028EC10.flag = 2;
            D_0028EC00.value = 0;
            D_0028EB84 = 8;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EC10.step = 0;
            D_0028EC00.step++;
            break;
        }
    } else if (dir != 0) {
        idx = D_002712D8[sel];
        if (sel == 3 && D_0068DEF0[10] == 0) {
            idx = -1;
        }
        if (!(0 > idx)) {
        value = &D_0068DEF0[idx];
        count = D_002712C0[idx];
        if (sel == 3 || sel == 9 || sel == 7) {
            pad = D_0057CC20[D_0028EC24];
            if (pad == 0 || pad == 0xE) {
                if (!(*value == 0 && dir == -1) && !(*value == count - 1 && dir == 1)) {
                    func_0018D4C0();
                }
            }
        } else {
            func_0018D4C0();
        }
        if (idx == 5) {
            if (D_0068DEF0[5] == 0 && D_0068DEF0[7] == 0) {
                D_0068DEF0[7] = 1;
            }
            if (D_0068DEF0[5] != 0) {
                D_0068DEF0[7] = 0;
                D_0068DEF0[8] = 0;
            }
        }
        if (idx == 3) {
            D_0068DEF0[4] = 8;
        }
        limit = D_0068DEF0[3] + 1;
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
            if (idx == 7 && D_0068DEF0[5] == 1 && *value == 0) {
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
            if (idx == 7 && D_0068DEF0[5] == 1 && *value == 6) {
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
            if (D_0068DEF0[5] == 0) {
                base = D_0068DEF0[8];
                total = 0;
                if (base != 0) {
                    total = (s16)base / 100;
                }
                extra = D_0068DEF0[7];
                total += extra;
                if (total > 5) {
                    if (idx == 7) {
                        if ((s16)base >= 100) {
                            D_0068DEF0[8] -= 100;
                        }
                    } else if (idx == 8) {
                        if (extra > 0) {
                            D_0068DEF0[7] = extra - 1;
                        }
                    }
                }
            }
#endif
        }
#ifndef DEATH_LABEL
        if (D_0068DEF0[5] == 0) {
            base = D_0068DEF0[8];
            total = 0;
            if (base != 0) {
                total = (s16)base / 100;
            }
            extra = D_0068DEF0[7];
            total += extra;
            if (total > 5) {
                if (idx == 7) {
                    D_0068DEF0[8] = (5 - extra) * 100 + 99;
                } else if (idx == 8) {
                    D_0068DEF0[7] = (500 - (s16)base) / 100;
                }
            }
        }
#endif
    }
    }
}

void func_002295F0(void) {
    switch (D_0028EC00.step) {
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
    func_00227440(&D_0028EC00);
    if (D_0028EC00.value == 0) {
        return;
    }
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x3F34) == 0) {
            continue;
        }
        *(s32 *)(item + 0x3F2C) = alpha = D_0028EC00.value;
        x = *(s32 *)(item + 0x3F00);
        y = *(s32 *)(item + 0x3F04);
        z = *(s32 *)(item + 0x3F30);
        bright = 0x80;
        if (D_0068DEFA[0] == 0 && i == 7) {
            bright = 0x40;
        }
        reg_a0 = D_002709D0[i];
        glyph_queue_add(x, y, z, 0, bright, alpha, 1);
        y += strlen(reg_a0) * 8;
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
            reg_a0 = D_00271290[index][D_0068DEF0[index]];
        }
        if (reg_a0 == 0) {
            continue;
        }
        flag = 1;
        if (i == 3) {
            if (D_0068DF04[0] == 1) {
                func_00229950(x, y, D_0028EC00.value, bright, 2);
            } else {
                glyph_queue_add(x, y, z, 0, bright, D_0028EC00.value, flag);
                flag = 0;
            }
        } else if (i == 9) {
            func_00229950(x, y, D_0028EC00.value, bright, 8);
        } else if (i == 7) {
            func_00229950(x, y, D_0028EC00.value, bright, 6);
        } else {
            glyph_queue_add(x, y, z, 0, bright, D_0028EC00.value, flag);
        }
        if (i == D_0028EC00.flag && flag != 0) {
            func_00224BA0(x, y, z, 0, bright, D_0028EC00.value, 1, 3);
        }
    }
}

void func_00229950(s32 x, s32 y, s32 alpha, s32 mode, s32 kind) {
    u8 *saved;
    s32 c;
    s32 level;
    s32 h;

    saved = reg_a0;
    level = D_0068DEF0[kind];
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
        buttons = D_0057CC60[D_0028EC24];
        if (buttons & 0x8000) {
            dir = -1;
            skip = 1;
        } else if (buttons & 0x2000) {
            dir = 1;
            skip = 1;
        }
    }
    if (skip == 0) {
        buttons = D_0057CC70[D_0028EC24];
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
            func_0018D4B0();
            memcpy(D_0068DEC8, D_00270838, 12);
            break;
        case 8:
            func_0018D4B0();
            D_0028EBF8.state = 0;
            D_0028EC10.flag = 3;
            D_0028EBF8.value = 0;
            D_0028EB84 = 8;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EC10.step = 0;
            D_0028EBF8.step += 1;
            break;
        }
    } else if (dir != 0) {
        item = D_00271468[D_0028EB58];
        if (!(0 > item)) {
            value = &D_0068DEC8[item];
            count = D_00271458[item];
            func_0018D4C0();
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
        y += strlen(reg_a0) * 8;
        reg_a0 = 0;
        index = D_00271468[i];
        if (index == -1) {
            continue;
        }
        reg_a0 = D_00271440[index][D_0068DEC8[index]];
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
    func_00227310(&D_0028EBD8);
    func_00222340(0xD);
    D_0028EBD8.flag = 0;
    D_0028EB58 = 1;
    D_0028EB54 = 0;
    D_0028EB90 = 0x40;
    D_0028EB04 = 2;
}

void func_0022A2B0(void) {
    if (func_00222530(0xD) != 0) {
        D_0028EBD8.step += 1;
    }
}

void func_0022A2E0(void) {
    s32 temp_a0;
    s32 var_a1;
    s32 var_s0;

    var_s0 = 0;
    func_002273E0();
    temp_a0 = D_0057CC60[D_0028EC24];
    var_a1 = 0;
    if (temp_a0 & 0x8000) {
        func_0018D4C0();
        D_0028EBD8.flag -= 1;
        if (D_0028EBD8.flag < 0) {
            D_0028EBD8.flag = 9;
        }
        var_a1 = 1;
    } else if (temp_a0 & 0x2000) {
        func_0018D4C0();
        D_0028EBD8.flag += 1;
        if (D_0028EBD8.flag > 9) {
            D_0028EBD8.flag = 0;
        }
        var_a1 = 1;
    }
    if ((var_a1 == 0) && (D_0057CC70[D_0028EC24] & 0x40)) {
        var_s0 = 1;
    }
    if (var_s0 != 0) {
        func_0018D4B0();
        D_0028EBD8.state = 0;
        D_0028EB04 = 1;
        D_0028EBD8.value = 0;
        D_0028EC18.flag = 4;
        D_0028EB54 = 0;
        D_0028EB84 = 7;
        D_0028EB50 = 0;
        D_0028EB90 = 0;
        D_0028EC18.step = 0;
        D_0028EBD8.step += 1;
    }
}

void func_0022A410(void) {
    switch (D_0028EBD8.step) {
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
    s32 i;
    s32 x;
    s32 y;
    s32 z;
    s32 alpha;
    s32 count;
    u8 *item;

    func_00227440(&D_0028EBD8);
    if (D_0028EBD8.value == 0) {
        return;
    }
    count = D_002714FD[0];
    text_queue_clear();
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x2DB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x2DAC) = D_0028EBD8.value;
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
            reg_a0 = D_002716E0[D_0028EBD8.flag];
            glyph_queue_add(x, y + 0x70, z, 0, 0x80, alpha, 1);
        }
    }
    func_0022AD20(D_0028EBD8.flag, 0);
    for (i = 3; i < 8; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x2DB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x2DAC) = D_0028EBD8.value;
        reg_a0 = (u8 *)D_00684CA0 + (i - 3) * 11;
        y = *(s32 *)(item + 0x2D84) + 16;
        x = *(s32 *)(item + 0x2D80);
        z = *(s32 *)(item + 0x2DB0);
        alpha = *(s32 *)(item + 0x2DAC);
        if (alpha != 0) {
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        }
    }
    func_0022AD20(D_0028EBD8.flag, 1);
    for (i = 3; i < 8; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x2DB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x2DAC) = D_0028EBD8.value;
        reg_a0 = (u8 *)D_00684CA0 + (i - 3) * 11;
        y = *(s32 *)(item + 0x2D84) + 0x80;
        x = *(s32 *)(item + 0x2D80);
        z = *(s32 *)(item + 0x2DB0);
        alpha = *(s32 *)(item + 0x2DAC);
        if (alpha != 0) {
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        }
    }
    func_0022AD20(D_0028EBD8.flag, 2);
    for (i = 9; i < 14; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x2DB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x2DAC) = D_0028EBD8.value;
        reg_a0 = (u8 *)D_00684CA0 + (i - 9) * 11;
        y = *(s32 *)(item + 0x2D84) + 16;
        x = *(s32 *)(item + 0x2D80);
        z = *(s32 *)(item + 0x2DB0);
        alpha = *(s32 *)(item + 0x2DAC);
        if (alpha != 0) {
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        }
    }
    func_0022AD20(D_0028EBD8.flag, 3);
    for (i = 9; i < 14; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x2DB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x2DAC) = D_0028EBD8.value;
        reg_a0 = (u8 *)D_00684CA0 + (i - 9) * 11;
        y = *(s32 *)(item + 0x2D84) + 0x80;
        x = *(s32 *)(item + 0x2D80);
        z = *(s32 *)(item + 0x2DB0);
        alpha = *(s32 *)(item + 0x2DAC);
        if (alpha != 0) {
            glyph_queue_add(x, y, z, 0, 0x80, alpha, 1);
        }
    }
    D_0028EB90 = D_0028EBD8.value;
    reg_a0 = (u8 *)D_0028DD98;
    func_002228D0(D_006880A0[0] - 10, D_006880A4[0] + 0x58);
    text_flush();
}
