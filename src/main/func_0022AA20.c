#include "common.h"

extern void func_00213060(void);
extern void func_00215350(void);
extern void func_0021C0F0(void);
extern void func_0021C100(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern void func_0021C2F0(void);
extern void func_002228D0(s32 x, s32 y);
extern void func_0022AD20(s32 page, s32 sel);
extern void func_0022B1D0(void);
extern s8 D_002714FC[];
extern u8 *D_00271610[];
extern u8 *D_00271640[];
extern u8 *D_002716E0[];
extern u8 *D_0028DD94;
extern s8 D_0028EB34;
extern s32 D_0028EB90;
extern s32 D_0028EB9C;
extern u8 D_00684CA0[];
extern u8 D_00684CD7[];
extern u8 D_00685010[];
extern u16 D_006C58AA[];
extern u16 D_006C58AC[];
extern u16 D_006C58AE[];
extern u8 *reg_a0;

void func_0022AA20(void) {
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
    func_0021C0F0();
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
        func_0021C100(x, y, z, 0, 0x80, alpha, 1);
        if (i == 1) {
            reg_a0 = D_002716E0[page];
            func_0021C100(x, y + 0x38, z, 0, 0x80, alpha, 1);
            reg_a0 = D_00271640[sel];
            func_0021C100(x, y + 0x78, z, 0, 0x80, alpha, 1);
        }
        if (i >= 3 && i < 8) {
            reg_a0 = (u8 *)D_00684CA0 + (i - 3) * 11;
            func_0021C100(x, y + 0x38, z, 0, 0x80, alpha, 1);
        }
        if (i == 9) {
            reg_a0 = (u8 *)D_00684CD7;
            func_0021C100(x, y + 0x38, z, 0, 0x80, alpha, 1);
        }
    }
    func_0021C2F0();
    func_00213060();
    D_0028EB90 = D_0028EB9C;
    reg_a0 = (u8 *)D_0028DD94;
    func_002228D0(x - 10, 0x40);
    func_00215350();
    reg_a0 = save;
}
