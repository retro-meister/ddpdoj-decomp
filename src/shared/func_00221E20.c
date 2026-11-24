#include "common.h"

extern void func_00213060(void);
extern void func_00214DE0(s32 level);
extern void func_00215350(void);
extern void func_00215DB0(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
extern s32 func_0021C100(s32 x, s32 y, s32 z, s32 page, s32 alpha, s32 attr, s32 wide);
extern void func_00222C30(s32 x, s32 y, s32 alpha);
extern char *D_0028DD90;
extern s32 D_0028EAEC;
extern s32 D_0028EAF0;
extern s8 D_0028EB58;
extern char D_002BB060[];
extern char D_002BB100[];
extern char *reg_a0;

void func_00221E20(void) {
    char buf[2];
    s32 alpha;
    s32 i;
    char *p;
    s32 y;

    switch (D_0028EAF0) {
    case 0:
    case 3:
        break;
    case 1:
        D_0028EAEC += 4;
        if (D_0028EAEC >= 0x80) {
            D_0028EAEC = 0x80;
            D_0028EAF0 = 3;
        }
        break;
    case 2:
        D_0028EAEC -= 4;
        if (D_0028EAEC <= 0) {
            D_0028EAEC = 0;
            D_0028EAF0 = 0;
        }
        break;
    }
    if (D_0028EAEC != 0) {
        func_00213060();
        alpha = D_0028EAEC;
        if (D_0028EAEC >= 0x60) {
            alpha = 0x60;
        }
        if (alpha != 0) {
            func_00214DE0(D_0028EAEC);
            func_00215DB0(0xEC, 8, 0x40, 0xD0, 0x12C, alpha, 1, 1, 0x40);
        }
        reg_a0 = (char *)D_0028DD90;
        func_00222C30(0x116, 8, D_0028EAEC);
        buf[1] = 0;
        i = 0;
        y = 0;
        p = MAIN_OR_DEATH_LABEL(D_002BB100, D_002BB060) + D_0028EB58 * 0x1E;
        do {
            reg_a0 = buf;
            *reg_a0 = *p++;
            func_0021C100(0x106, y + 0xE + (i / 5) * 5, 0x136, 0, 0x80, D_0028EAEC, 1);
            i++;
            y += 9;
        } while (i < 0x14);
    }
    func_00215350();
}
