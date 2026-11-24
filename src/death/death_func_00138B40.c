#include "common.h"

#pragma divbyzerocheck on

typedef struct {
    s8 *page;
    s8 *cursor;
    s32 column;
    s32 row;
    s32 picture;
    s32 wait;
    s32 interval;
    s32 fadeTimer;
    s32 fadeLength;
    s32 alpha;
    s32 flashMode;
    s32 flashTimer;
    s32 flashLength;
    u32 frame;
    s32 texturePage;
    s32 glyphWidth;
    s32 glyphHeight;
} TextScript;

typedef struct {
    s16 x0;
    s16 x1;
    s16 pad04[2];
    s16 y0;
    s16 y1;
    s16 pad0C[2];
    s16 u0;
    s16 u1;
    s16 pad14[2];
    s16 v0;
    s16 v1;
    s16 pad1C[2];
    s16 z;
    s16 pad22;
    s32 tex;
    s32 clut;
    s16 flags;
    s16 attr;
    u16 alpha;
    s16 pad32;
} GlyphQuad;

void FlushCache(s32 mode);
void *memset(void *dst, s32 value, u32 size);
s32 sceGsExecLoadImage();
s32 sceGsSetDefLoadImage();
s32 sceGsSyncPath(s32 mode, u32 timeout);
s32 func_001173A8(void);
s32 func_0012FAB0();
s32 func_0019AB20();
s32 func_0019C5B0();
s32 func_001A3020();
s32 func_00213060();
void func_002144D0(s16 x, s16 y, const char *text, u16 texturePage, u16 glyphWidth, u16 glyphHeight, u16 alpha, u16 depth);
s32 func_00215350();
void func_00215DB0(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
void func_0021A170(void);
s32 func_0021C920();
void death_func_00138C50(TextScript *script);
extern s8 death_D_002549A0[];
extern u32 death_D_00254B40[];
extern u16 D_002624F0[];
extern u16 D_00262530[];
extern s32 D_0028EA74;
extern s32 D_0028EA80;
extern u16 D_00295E40[];
extern TextScript death_D_002AB800;
extern u16 D_002B3950[];
extern u8 D_004ECF80[];
extern u8 death_D_0056A800[];
extern u8 D_0057C780[];
extern GlyphQuad D_00592000[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

s32 death_func_00138B40(u8 *digits) {
    return (digits[0] - '0') * 1000 + (digits[1] - '0') * 100 + (digits[2] - '0') * 10 + (digits[3] - '0');
}

s32 death_func_00138BB0(u8 *digits) {
    return (digits[0] - '0') * 10 + (digits[1] - '0');
}

void death_func_00138BE0(u8 *image) {
    D_0028EA74 = 0x2240;
    sceGsSetDefLoadImage(D_0057C780, 0x2240, 8, 0x13, 0, 0, 0x200, 0x100);
    FlushCache(0);
    sceGsExecLoadImage(D_0057C780, image + 0x200);
    sceGsSyncPath(0, 0);
}

void death_func_00138C50(TextScript *script) {
    s32 u;
    s32 shade;
    s32 v;
    u8 alpha;
    u8 color;

    if (script->picture > 6) {
        death_func_00138BE0(D_004ECF80);
        D_0028EA80 = 0;
        shade = 0x60;
        if (script->frame & 1) {
            shade = 0x80;
        }
        D_00592000[0].attr = shade;
        D_00592000[0].z = 1;
        D_00592000[0].tex = 0x2240;
        D_00592000[0].clut = 0x3836;
        D_00592000[0].alpha = 0x80;
        D_00592000[0].flags = 1;
        D_00592000[0].x0 = 0xB0;
        D_00592000[0].x1 = 0x1C0;
        D_00592000[0].y0 = 0;
        D_00592000[0].y1 = 0xE0;
        D_00592000[0].u0 = 0x110;
        D_00592000[0].v0 = 0;
        D_00592000[0].u1 = 0x200;
        D_00592000[0].v1 = 0xE0;
        D_0028EA80 = 1;
        func_0021A170();
        death_func_00138BE0(death_D_0056A800);
        D_0028EA80 = 0;
        shade = (func_001173A8() & 0x1F) + 0x40;
        if (script->frame & 1) {
            shade = 0;
        }
        u = func_001173A8() % 0x110;
        v = func_001173A8() % 0x20;
        D_00592000[0].attr = shade;
        D_00592000[0].z = 1;
        D_00592000[0].tex = 0x2240;
        D_00592000[0].clut = 0x383C;
        D_00592000[0].alpha = 0x80;
        D_00592000[0].flags = 1;
        D_00592000[0].x0 = 0xB0;
        D_00592000[0].x1 = 0x1C0;
        D_00592000[0].y0 = 0;
        D_00592000[0].y1 = 0xE0;
        D_00592000[0].u0 = u;
        D_00592000[0].v0 = v;
        D_00592000[0].u1 = u + 0xF0;
        D_00592000[0].v1 = v + 0xE0;
        D_0028EA80 = 1;
        func_0021A170();
    }
    alpha = (script->flashTimer << 7) / script->flashLength;
    if (script->flashMode & 1) {
        alpha = 0x80 - (s8) alpha;
    }
    color = 1;
    if (script->flashMode & 2) {
        color = 0xFF;
    }
    func_00215DB0(0, 0, 0x1C0, 0xE0, 0, alpha, color, color, color);
}


typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u16 e;
} ListHead;

void death_func_00138ED0(TextScript *script) {
    ListHead *head;

    if (script->picture != 0) {
        if (script->picture < 7) {
            reg_d1.w = 0x38000000;
            reg_d2.w = death_D_00254B40[script->picture];
            reg_d3.h[0] = 0x1CE0;
            reg_d4.h[0] = 1;
            reg_d4.h[0] += D_00295E40[0];
            func_0019C5B0();
            reg_a0 = ((script->frame >> 1) & 1) ? (u8 *) D_002624F0 : (u8 *) D_00262530;
            reg_d0.h[0] = 1;
            func_001A3020();
            func_0019AB20();
            func_0021C920();
            head = (ListHead *) D_002B3950;
            head->e = 0;
            head->d = 0;
            head->c = 0;
            head->b = 0;
            head->a = 0;
        }
        death_func_00138C50(script);
    }
}

s32 death_func_00138FC0(TextScript *script) {
    s8 *text;
    s32 x;
    s32 y;
    s32 flags;
    char glyph[3];

    glyph[2] = 0;
    text = script->page;
    x = script->column << 3;
    y = script->row << 3;
    func_00213060();
    while (text != script->cursor) {
        s8 ch = *text; u8 c = ch;
        if (((c >= 0x81) && (c <= 0x9F)) || ((c >= 0xE0) && (c <= 0xEF))) {
            glyph[0] = text[0];
            glyph[1] = text[1];
            text += 2;
            func_002144D0(x, y, glyph, script->texturePage, script->glyphWidth, script->glyphHeight, script->alpha, 0);
            y += script->glyphHeight;
        } else {
            if (ch == 0xA) {
                x -= 0x20;
                y = script->row << 3;
            } else if (ch == 'c') {
                script->texturePage = death_func_00138BB0((u8 *) text + 1);
                text += 2;
            } else if (ch == 'b') {
                script->glyphWidth = death_func_00138BB0((u8 *) text + 1);
                script->glyphHeight = death_func_00138BB0((u8 *) text + 3);
                text += 4;
            }
            text++;
        }
    }
    func_00215350();
    if (script->flashTimer != 0) {
        script->flashTimer--;
    }
    if (script->fadeTimer != 0) {
        script->fadeTimer--;
        script->alpha = (script->fadeTimer << 7) / script->fadeLength;
    }
    if ((script->fadeTimer != 0) || (script->flashTimer != 0)) {
        return 0;
    }
    if (script->wait != 0) {
        script->wait--;
        return 0;
    }
    switch (*script->cursor) {
    case 'g':
        script->picture = death_func_00138BB0((u8 *) script->cursor + 1);
        script->flashMode = 0;
        script->flashTimer = 0x20;
        script->flashLength = script->flashTimer;
        script->cursor += 3;
        break;
    case 'i':
        script->interval = death_func_00138B40((u8 *) script->cursor + 1);
        script->cursor += 5;
        break;
    case 'f':
        flags = death_func_00138B40((u8 *) script->cursor + 1);
        if (flags & 1) {
            script->fadeTimer = 0x10;
            script->fadeLength = script->fadeTimer;
        }
        if (flags & 2) {
            script->flashMode = 1;
            script->flashTimer = 0x30;
            script->flashLength = script->flashTimer;
        }
        if (flags & 4) {
            script->fadeTimer = 0x80;
            script->fadeLength = script->fadeTimer;
        }
        script->cursor += 5;
        break;
    case 'w':
        script->wait = death_func_00138B40((u8 *) script->cursor + 1);
        script->cursor += 5;
        break;
    case 'p':
        script->column = death_func_00138BB0((u8 *) script->cursor + 1);
        script->row = death_func_00138BB0((u8 *) script->cursor + 3);
        script->cursor += 5;
        break;
    case 'c':
        script->cursor += 3;
        break;
    case 'b':
        script->cursor += 5;
        break;
    case 0xA:
        script->cursor += 1;
        break;
    case 0xC:
        script->cursor += 1;
        script->page = script->cursor;
        script->alpha = 0x80;
        break;
    case 0:
        return 1;
    default:
        script->cursor += 2;
        script->wait = script->interval;
        break;
    }
    return 0;
}

void death_func_00139380(void) {
    switch (*(u16 *)(reg_a6 + 6)) {
    case 0:
        *(u16 *)(reg_a6 + 6) = 1;
        func_0012FAB0();
        *(u16 *)(reg_a6 + 0xC) = 0;
        memset(&death_D_002AB800, 0, sizeof(TextScript));
        death_D_002AB800.cursor = death_D_002549A0;
        death_D_002AB800.alpha = 0x80;
        death_D_002AB800.page = death_D_002AB800.cursor;
    case 1:
        death_func_00138ED0(&death_D_002AB800);
        if (death_func_00138FC0(&death_D_002AB800) != 0) {
            reg_a5[3] = 2;
        }
        death_D_002AB800.frame++;
        break;
    }
}
