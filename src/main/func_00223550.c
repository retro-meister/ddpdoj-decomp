#include "common.h"
extern s8 D_0028EBC4;

void func_00223550(void);
void func_00223A60(void);
void func_00223AA0(void);
s32 func_00223BE0(void);
void func_00223D70(void);
void func_00223E80(void);
void func_00224020(s32 x, s32 y);
void func_002242B0(s32 x, s32 y);
typedef struct {
    s32 a;
    s32 b;
} Pair;

extern void func_0018D4B0(void);
extern void func_0018D4C0(void);
extern void func_002035F0(void);
extern void func_00217BB0(s32 a, s32 b);
extern void func_00217C20(s32 a, s32 b);
extern void func_0021B840(s32 a, s32 b);
extern Pair D_00271C60[];
extern s8 D_0028E250;
extern s8 D_0028E254;
extern u8 D_0028E27C;
extern u8 D_0028E28C;
extern u16 D_0028E31C;
extern u16 D_0028E324;
extern u16 D_0028E328;
extern u16 D_0028E32C;
extern u8 D_0028E354;
extern u8 D_0028E358;
extern u8 D_0028E378;
extern u16 D_0028E910;
extern u8 D_0028E9EC;
extern s8 D_0028EAE0;
extern s8 D_0028EAE4;
extern s32 D_0028EB90;
extern s8 D_0028EBBC;
extern s8 D_0028EBD0;
extern u32 D_0057CC60[];
extern u32 D_0057CC70[];
extern s8 D_0068DD02[];
s32 func_0018CAD0();
s32 func_00217D20();
extern s8 D_0028E364;
extern u8 D_0028E36C;
extern u8 D_0028ED74;
s32 func_00224A30();
s32 func_00224A90();
s32 func_00237670();
s32 func_002376F0();
extern s8 D_0028EBC0;
extern u8 D_0028ED7C;
extern u8 D_0028ED80;
s32 func_0018D4D0();
extern void func_00215DB0(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha, s32 r, s32 g, s32 b);
extern s16 D_00271C8C[];
extern s16 D_00271C90[];
extern s16 D_0028EBC8;
extern s8 D_0028EBCC;
extern void func_00213060(void);
extern void func_00214C70(s32 level);
extern void func_00215350(void);
extern void func_002228D0(s32 x, s32 y);
extern u8 *D_00271B30[];
extern u8 *D_00271B60[];
extern u8 *D_00271B90[];
extern s8 D_0028EB04;
extern u8 *reg_a0;
extern s32 func_00117550(char *buf, const char *format, ...);
extern void func_002144D0(s16 x, s16 y, const char *text, u16 texturePage, u16 glyphWidth, u16 glyphHeight, u16 alpha, u16 depth);
extern char *D_0028E9F8;
extern u8 *D_00271BC8[];
extern u8 *D_00271BCC[];
extern u8 *D_00271BD0[];
extern u8 *D_00271BD4[];
extern s8 D_0028EB0C;

void func_00223550(void) {
    u32 pad;

    if (D_0028EBBC != 0) {
        D_0028EBBC--;
    }
    if (D_0028EBBC == 0 && (D_0057CC70[D_0028E31C] & 0x800)) {
        func_0018D4B0();
        D_0028E36C++;
        return;
    }
    if (func_00223BE0() != 0) {
        return;
    }
    switch (D_0028EBD0) {
    case 1:
        pad = D_0057CC60[D_0028E31C];
        if (pad & 0x8000) {
            func_0018D4C0();
            D_0068DD02[0]--;
            D_0028E354 = D_0068DD02[0];
            if (D_0028E358 == 0) {
                D_0028E354 &= 3;
            } else {
                D_0028E354 &= 1;
            }
            D_0068DD02[0] = D_0028E354;
            D_0028E9EC = 1;
        } else if (pad & 0x2000) {
            func_0018D4C0();
            D_0068DD02[0]++;
            D_0028E354 = D_0068DD02[0];
            if (D_0028E358 == 0) {
                D_0028E354 &= 3;
            } else {
                D_0028E354 &= 1;
            }
            D_0068DD02[0] = D_0028E354;
            D_0028E9EC = 1;
        }
        break;
    case 2:
        if (D_0057CC60[D_0028E31C] & 0xA000) {
            func_0018D4C0();
            D_0028E27C++;
            D_0028E27C &= 1;
            if (D_0028E27C != 0) {
                func_00217BB0(0x78, 0x14);
                func_00217C20(0x78, 0x14);
            }
        }
        break;
    case 3:
        pad = D_0057CC60[D_0028E31C];
        if (pad & 0x8000) {
            func_0018D4C0();
            D_0028E32C--;
            if ((s16)D_0028E32C < 0) {
                D_0028E32C = 5;
            }
            if (D_0028E32C != 5) {
                func_0021B840(D_00271C60[D_0028E32C].a, D_00271C60[D_0028E32C].b);
            }
        } else if (pad & 0x2000) {
            func_0018D4C0();
            D_0028E32C++;
            if (D_0028E32C > 5) {
                D_0028E32C = 0;
            }
            if (D_0028E32C != 5) {
                func_0021B840(D_00271C60[D_0028E32C].a, D_00271C60[D_0028E32C].b);
            }
        }
        break;
    case 4:
        if (D_0057CC60[D_0028E31C] & 0xA000) {
            func_0018D4C0();
            D_0028E28C++;
            D_0028E28C &= 1;
        }
        break;
    case 5:
        if (D_0057CC70[D_0028E31C] & 0x20) {
            func_0018D4B0();
            D_0028EB90 = 0x80;
            D_0028EAE4 = D_0028E254;
            D_0028E36C = 0xB;
            D_0028EAE0 = D_0028E250;
        }
        break;
    case 6:
    case 7:
        if (D_0057CC70[D_0028E31C] & 0x20) {
            func_0018D4B0();
            D_0028EBC4 = 1;
            D_0028E36C = 5;
        }
        break;
    case 8:
        if (D_0057CC60[D_0028E31C] & 0xA000) {
            func_0018D4C0();
            D_0028E324++;
            D_0028E324 &= 1;
        }
        break;
    case 9:
        pad = D_0057CC60[D_0028E31C];
        if (pad & 0x8000) {
            func_0018D4C0();
            D_0028E328--;
            if ((s32)D_0028E328 <= 0) {
                D_0028E328 = 5;
            }
        } else if (pad & 0x2000) {
            func_0018D4C0();
            D_0028E328++;
            if (D_0028E328 > 5) {
                D_0028E328 = 1;
            }
        }
        if (D_0028E378 != 0xFF && (D_0057CC70[D_0028E31C] & 0x20)) {
            reg_d6.h[0] = 1;
            reg_d7.h[0] = D_0028E328;
            if (reg_d7.h[0] == 5) {
                reg_d7.h[0] = 0;
            }
            func_002035F0();
            D_0028E36C = 0;
        }
        break;
    }
    D_0028E910 = D_0028E324;
}

void func_00223A60(void) {
    D_0028E36C = 0;
    func_0018CAD0();
    D_0028E364 = 0x3C;
    func_00217D20();
    if (D_0028ED74 == 3) {
        D_0028ED74 = 1;
    }
}

void func_00223AA0(void) {
    u32 buttons;

    buttons = D_0057CC70[D_0028E31C];
    if (buttons & 0x20) {
        if (D_0028EBC4 == 0) {
            if (D_0028ED80 == 0 && D_0028ED7C != 2) {
                func_00224A30();
            } else {
                func_0018D4B0();
                if (D_0028EBD0 == 7) {
                    func_002376F0();
                } else {
                    func_00224A90();
                    func_00237670();
                }
            }
        } else {
            func_0018D4B0();
            D_0028E36C = 3;
        }
        return;
    }
    if (buttons & 0x40) {
        func_0018D4B0();
        D_0028E36C = 3;
        return;
    }
    if ((buttons & 0x8000) && D_0028EBC4 == 1) {
        func_0018D4C0();
        D_0028EBC0 = 0;
        D_0028EBC4 = 0;
        return;
    }
    if ((buttons & 0x2000) && D_0028EBC4 == 0) {
        func_0018D4C0();
        D_0028EBC0 = 0;
        D_0028EBC4 = 1;
    }
}

s32 func_00223BE0(void) {
    s32 temp_s0;
    s32 temp_v1;
    s32 temp_v1_2;

    if (D_0028ED80 == 0) { temp_s0 = 8; } else { temp_s0 = 8; }
    if (D_0028ED80 == 0) {
        temp_v1 = D_0057CC60[D_0028E31C];
        if (temp_v1 & 0x1000) {
            func_0018D4D0();
            D_0028EBD0 -= 1;
            if (D_0028EBD0 == 6) {
                D_0028EBD0 -= 1;
            }
            if (D_0028EBD0 <= 0) {
                D_0028EBD0 = temp_s0 - 1;
            }
            return 1;
        }
        if (temp_v1 & 0x4000) {
            func_0018D4D0();
            D_0028EBD0 += 1;
            if (D_0028EBD0 == 6) {
                D_0028EBD0 += 1;
            }
            if (D_0028EBD0 >= temp_s0) {
                D_0028EBD0 = 1;
            }
            return 1;
        }
        goto block_21;
    }
    temp_v1_2 = D_0057CC60[D_0028E31C];
    if (temp_v1_2 & 0x1000) {
        func_0018D4D0();
        D_0028EBD0 -= 1;
        if (D_0028EBD0 <= 0) {
            D_0028EBD0 = temp_s0 - 1;
        }
        return 1;
    }
    if (temp_v1_2 & 0x4000) {
        func_0018D4D0();
        D_0028EBD0 += 1;
        if (D_0028EBD0 >= temp_s0) {
            D_0028EBD0 = 1;
        }
        return 1;
    }
block_21:
    return 0;
}

void func_00223D70(void) {
    s32 x;

    switch (D_0028EBCC) {
    case 0:
        break;
    case 1:
        D_0028EBC8 += 4;
        if (D_0028EBC8 >= 0x40) {
            D_0028EBCC = 0;
            D_0028EBC8 = 0x40;
        }
        break;
    case 2:
        D_0028EBC8 -= 4;
        if (D_0028EBC8 <= 0) {
            D_0028EBC8 = 0;
            D_0028EBCC = 0;
        }
        break;
    }
    if (D_0028ED80 == 0 && D_0028EBD0 > 6) {
        x = D_00271C8C[D_0028EBD0 * 2];
    } else {
        x = D_00271C90[D_0028EBD0 * 2];
    }
    if (D_0028EBC8 != 0) {
        func_00215DB0(x - 8, 0, 0x12, 0xE0, 0x5A, D_0028EBC8, 0xB4, 1, 1);
    }
}

void func_00223E80(void) {
    s64 alpha;

    switch (D_0028EB04) {
    case 0:
        break;
    case 1:
        D_0028EB90 += 4;
        if (D_0028EB90 >= 0x80) {
            D_0028EB04 = 0;
            D_0028EB90 = 0x80;
        }
        break;
    case 2:
        D_0028EB90 -= 4;
        if (D_0028EB90 <= 0) {
            D_0028EB90 = 0;
            D_0028EB04 = 0;
        }
        break;
    }
    if (D_0028EB90 != 0) {
        func_00213060();
        alpha = D_0028EB90;
        if (D_0028EB90 >= 0x40) {
            alpha = 0x40;
        }
        if (alpha != 0) {
            func_00214C70(D_0028EB90);
            func_00215DB0(0xC, 8, 0x40, 0xD0, 0x12C, alpha, 1, 1, 0x40);
        }
        if (D_0028E36C != 5) {
            if (D_0028ED7C == 2) {
                reg_a0 = D_00271B90[D_0028EBD0];
            } else if (D_0028ED80 != 0) {
                reg_a0 = D_00271B60[D_0028EBD0];
            } else {
                reg_a0 = D_00271B30[D_0028EBD0];
            }
            func_002228D0(0x36, 8);
        } else {
            func_00224020(0xC, 8);
        }
        func_00215350();
    }
}

void func_00224020(s32 x, s32 y) {
    s32 shrink;
    s32 w;
    s32 h;
    s32 px;
    s32 py;

    if (D_0028EBC0 < 4) {
        D_0028EBC0 += 2;
    }
    px = x + 40;
    py = y + 10;
    shrink = 0;
    if (D_0028EBC0 != 0) {
        shrink = (s32)(s8)D_0028EBC0 / 2;
    }
    w = (s32)(s8)D_0028EBC0 + 20;
    h = (s32)(s8)D_0028EBC0 + 16;
    if (D_0028EBD0 == 6) {
        reg_a0 = D_00271BD0[0];
    } else if (D_0028ED7C == 2) {
        reg_a0 = D_00271BCC[0];
    } else if (D_0028ED80 != 0) {
        reg_a0 = D_00271BD4[0];
    } else {
        reg_a0 = D_00271BC8[0];
    }
    func_002228D0(x + 42, y);
    if (D_0028EBC4 == 0) {
        func_00117550(D_0028E9F8, "\x82\xCD\x82\xA2");
        func_002144D0(py - shrink, px - shrink, D_0028E9F8, 4, w, h, 128, 300);
        func_00117550(D_0028E9F8, "\x81\x5E");
        func_002144D0(py, px + 50, D_0028E9F8, 0, 20, 16, 128, 300);
        func_00117550(D_0028E9F8, "\x82\xA2\x82\xA2\x82\xA6");
        func_002144D0(py, px + 75, D_0028E9F8, 0, 20, 16, 128, 300);
    } else {
        func_00117550(D_0028E9F8, "\x82\xCD\x82\xA2");
        func_002144D0(py, px, D_0028E9F8, 0, 20, 16, 128, 300);
        func_00117550(D_0028E9F8, "\x81\x5E");
        func_002144D0(py, px + 50, D_0028E9F8, 0, 20, 16, 128, 300);
        func_00117550(D_0028E9F8, "\x82\xA2\x82\xA2\x82\xA6");
        func_002144D0(py - shrink, px + 75 - shrink, D_0028E9F8, 4, w, h, 128, 300);
    }
}

void func_002242B0(s32 x, s32 y) {
    s32 shrink;
    s32 w;
    s32 h;
    s32 px;
    s32 py;

    if (D_0028EBC0 < 4) {
        D_0028EBC0 += 2;
    }
    px = x + 40;
    py = y + 10;
    shrink = 0;
    if (D_0028EBC0 != 0) {
        shrink = (s32)(s8)D_0028EBC0 / 2;
    }
    w = (s32)(s8)D_0028EBC0 + 20;
    h = (s32)(s8)D_0028EBC0 + 16;
    if (D_0028EB0C == 1) {
        func_00117550(D_0028E9F8, "\x82\xCD\x82\xA2");
        func_002144D0(py - shrink, px - shrink, D_0028E9F8, 4, w, h, 128, 300);
        func_00117550(D_0028E9F8, "\x81\x5E");
        func_002144D0(py, px + 50, D_0028E9F8, 0, 20, 16, 128, 300);
        func_00117550(D_0028E9F8, "\x82\xA2\x82\xA2\x82\xA6");
        func_002144D0(py, px + 75, D_0028E9F8, 0, 20, 16, 128, 300);
    } else {
        func_00117550(D_0028E9F8, "\x82\xCD\x82\xA2");
        func_002144D0(py, px, D_0028E9F8, 0, 20, 16, 128, 300);
        func_00117550(D_0028E9F8, "\x81\x5E");
        func_002144D0(py, px + 50, D_0028E9F8, 0, 20, 16, 128, 300);
        func_00117550(D_0028E9F8, "\x82\xA2\x82\xA2\x82\xA6");
        func_002144D0(py - shrink, px + 75 - shrink, D_0028E9F8, 4, w, h, 128, 300);
    }
}
