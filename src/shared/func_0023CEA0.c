#include "common.h"

extern s32 func_0023CC30(u8 *entry, u16 *table, s32 count);
extern s32 func_0023CCD0(u8 *entry, u16 *starts, s32 *sizes, s32 count);
extern s32 func_0023CDA0(u8 *entry, u16 *table, s32 count, s32 stride);
extern s32 func_0023CE20(u8 *entry, u16 *table, s32 count, s32 stride);
extern u16 D_00269530[];
extern u16 D_00272128[];
extern u16 D_00272138[];
extern u16 D_00272148[];
extern u16 D_00272160[];
extern u16 D_002726A0[];
extern u16 D_00272750[];
extern u16 D_00272770[];
extern s32 D_002727D0[];
extern u16 D_00272820[];
extern u16 D_00272870[];
extern s32 D_00272890[];
extern u16 D_002728B0[];
extern u16 D_00272990[];
extern s32 D_002729C0[];
extern u16 D_0028DE50[4];
extern u16 D_0028DE58[4];
extern s32 D_0028ED88;
extern u16 D_002B4D50_as_u16_a[];
extern u16 D_002BD440[];

void func_0023CEA0(u8 *base) {
    s32 off;
    u8 *p;
    u8 *q;
    s32 j;
    u8 *r;
    s32 k;
    u8 *t;
    s32 m;
    s32 n;

    for (off = 0; off < 0xC08; off += 0x2C) {
        p = base + off;
        func_0023CC30(p + 0x24, D_0028DE50, 2);
        func_0023CC30(p + 0x28, D_00269530, 6);
    }
    func_0023CC30(base + 0xCF0, D_00272128, 3);
    func_0023CC30(base + 0xD0A, D_00272128, 3);
    func_0023CC30(base + 0xD20, D_00272138, 3);
    func_0023CC30(base + 0xD32, D_00272148, 3);
    func_0023CC30(base + 0xD54, D_00272128, 3);
    func_0023CC30(base + 0xD6E, D_00272128, 3);
    func_0023CC30(base + 0xD84, D_00272138, 3);
    func_0023CC30(base + 0xD96, D_00272148, 3);
    for (off = 0; off < 0xD80; off += 0x30) {
        func_0023CC30(base + off + 0xDC0, D_00272160, 0x150);
    }
    for (j = 0; j < 0x510; j += 0x30) {
        q = base + j;
        func_0023CC30(q + 0x1B40, D_002726A0, 0x2C);
        func_0023CC30(q + 0x1B4A, D_00272750, 5);
        func_0023CCD0(q + 0x1B4E, D_00272770, D_002727D0, 0x18);
        func_0023CC30(q + 0x2140, D_002726A0, 0x2C);
        func_0023CC30(q + 0x214A, D_00272750, 5);
        func_0023CCD0(q + 0x214E, D_00272770, D_002727D0, 0x18);
    }
    q = base + j;
    func_0023CC30(q + 0x1B40, D_002726A0, 0x2C);
    func_0023CC30(q + 0x1B4A, D_00272750, 5);
    func_0023CCD0(q + 0x1B4E, D_00272770, D_002727D0, 0x18);
    func_0023CC30(q + 0x2140, D_002726A0, 0x2C);
    func_0023CC30(q + 0x214A, D_00272750, 5);
    func_0023CCD0(q + 0x214E, D_00272770, D_002727D0, 0x18);
    for (k = 0x540; k < 0x5A0; k += 0x30) {
        r = base + k;
        func_0023CCD0(r + 0x1B40, D_00272770, D_002727D0, 0x18);
        func_0023CC30(r + 0x1B4A, D_00272750, 5);
        func_0023CCD0(r + 0x1B4E, D_00272770, D_002727D0, 0x18);
        func_0023CCD0(r + 0x2140, D_00272770, D_002727D0, 0x18);
        func_0023CC30(r + 0x214A, D_00272750, 5);
        func_0023CCD0(r + 0x214E, D_00272770, D_002727D0, 0x18);
    }
    r = base + k;
    func_0023CC30(r + 0x1B40, D_002726A0, 0x2C);
    func_0023CC30(r + 0x1B4A, D_00272750, 5);
    func_0023CCD0(r + 0x1B4E, D_00272770, D_002727D0, 0x18);
    func_0023CC30(r + 0x2140, D_002726A0, 0x2C);
    func_0023CC30(r + 0x214A, D_00272750, 5);
    func_0023CCD0(r + 0x214E, D_00272770, D_002727D0, 0x18);
    r = base + (k + 0x30);
    func_0023CC30(r + 0x1B40, D_002726A0, 0x2C);
    func_0023CC30(r + 0x1B4C, D_00272820, 0x14);
    func_0023CC30(r + 0x2140, D_002726A0, 0x2C);
    func_0023CC30(r + 0x214C, D_00272820, 0x14);
    for (m = 0; m < 0x7E0; m += 0x30) {
        t = base + m + 0x27C0;
        if (func_0023CC30(t, D_002728B0, 0x36) == 0 && func_0023CCD0(t, D_00272870, D_00272890, 6) != 0) {
            D_0028ED88 = 0;
        }
    }
    for (off = 0x7E0; off < 0x870; off += 0x30) {
        func_0023CC30(base + off + 0x27C0, D_002728B0, 0x36);
    }
    func_0023CCD0(base + 0x301C, D_00272990, D_002729C0, 0xC);
    func_0023CCD0(base + 0x3020, D_00272990, D_002729C0, 0xC);
    func_0023CCD0(base + 0x3024, D_00272990, D_002729C0, 0xC);
    func_0023CCD0(base + 0x3028, D_00272990, D_002729C0, 0xC);
    func_0023CE20(base + 0x318C, D_002BD440, 0x32, 0x20);
    func_0023CC30(base + 0x3226, D_0028DE58, 2);
    func_0023CC30(base + 0x324A, D_0028DE58, 2);
    for (n = 0; n < 0x5A; n += 10) {
        func_0023CDA0(&((u8 (*)[10])(base + 0x32B6))[0][n], D_002B4D50_as_u16_a, 0x800, 4);
        func_0023CDA0(&((u8 (*)[10])(base + 0x3310))[0][n], D_002B4D50_as_u16_a, 0x800, 4);
    }
}
