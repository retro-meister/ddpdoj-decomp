#include "common.h"

extern s32 func_0023D4E0(u8 *entry, u16 *mem, s32 op);
extern u16 D_00269530[];
extern u16 D_00272128[];
extern u16 D_00272138[];
extern u16 D_00272148[];
extern u16 D_00272160[];
extern u16 D_002726A0[];
extern u16 D_00272750[];
extern u16 D_00272770[];
extern u16 D_00272820[];
extern u16 D_00272870[];
extern u16 D_002728B0[];
extern u16 D_00272990[];
extern u16 D_0028DE50[4];
extern u16 D_0028DE58[4];
extern u16 D_002B4D50_as_u16_a[];
extern u16 D_002BD440[];

void func_0023D6A0(u8 *base) {
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
        func_0023D4E0(p + 0x24, D_0028DE50, 0x80);
        func_0023D4E0(p + 0x28, D_00269530, 0x80);
    }
    func_0023D4E0(base + 0xCF0, D_00272128, 0x80);
    func_0023D4E0(base + 0xD0A, D_00272128, 0x80);
    func_0023D4E0(base + 0xD20, D_00272138, 0x80);
    func_0023D4E0(base + 0xD32, D_00272148, 0x80);
    func_0023D4E0(base + 0xD54, D_00272128, 0x80);
    func_0023D4E0(base + 0xD6E, D_00272128, 0x80);
    func_0023D4E0(base + 0xD84, D_00272138, 0x80);
    func_0023D4E0(base + 0xD96, D_00272148, 0x80);
    for (off = 0; off < 0xD80; off += 0x30) {
        func_0023D4E0(base + off + 0xDC0, D_00272160, 0x80);
    }
    for (j = 0; j < 0x510; j += 0x30) {
        q = base + j;
        func_0023D4E0(q + 0x1B40, D_002726A0, 0x80);
        func_0023D4E0(q + 0x1B4A, D_00272750, 0x80);
        func_0023D4E0(q + 0x1B4E, D_00272770, 0x81);
        func_0023D4E0(q + 0x2140, D_002726A0, 0x80);
        func_0023D4E0(q + 0x214A, D_00272750, 0x80);
        func_0023D4E0(q + 0x214E, D_00272770, 0x81);
    }
    q = base + j;
    func_0023D4E0(q + 0x1B40, D_002726A0, 0x80);
    func_0023D4E0(q + 0x1B4A, D_00272750, 0x80);
    func_0023D4E0(q + 0x1B4E, D_00272770, 0x81);
    func_0023D4E0(q + 0x2140, D_002726A0, 0x80);
    func_0023D4E0(q + 0x214A, D_00272750, 0x80);
    func_0023D4E0(q + 0x214E, D_00272770, 0x81);
    for (k = 0x540; k < 0x5A0; k += 0x30) {
        r = base + k;
        func_0023D4E0(r + 0x1B40, D_00272770, 0x81);
        func_0023D4E0(r + 0x1B4A, D_00272750, 0x80);
        func_0023D4E0(r + 0x1B4E, D_00272770, 0x81);
        func_0023D4E0(r + 0x2140, D_00272770, 0x81);
        func_0023D4E0(r + 0x214A, D_00272750, 0x80);
        func_0023D4E0(r + 0x214E, D_00272770, 0x81);
    }
    r = base + k;
    func_0023D4E0(r + 0x1B40, D_002726A0, 0x80);
    func_0023D4E0(r + 0x1B4A, D_00272750, 0x80);
    func_0023D4E0(r + 0x1B4E, D_00272770, 0x81);
    func_0023D4E0(r + 0x2140, D_002726A0, 0x80);
    func_0023D4E0(r + 0x214A, D_00272750, 0x80);
    func_0023D4E0(r + 0x214E, D_00272770, 0x81);
    r = base + (k + 0x30);
    func_0023D4E0(r + 0x1B40, D_002726A0, 0x80);
    func_0023D4E0(r + 0x1B4C, D_00272820, 0x80);
    func_0023D4E0(r + 0x2140, D_002726A0, 0x80);
    func_0023D4E0(r + 0x214C, D_00272820, 0x80);
    for (m = 0; m < 0x7E0; m += 0x30) {
        t = base + m + 0x27C0;
        func_0023D4E0(t, D_002728B0, 0x80);
        func_0023D4E0(t, D_00272870, 0x81);
    }
    for (off = 0x7E0; off < 0x870; off += 0x30) {
        func_0023D4E0(base + off + 0x27C0, D_002728B0, 0x80);
    }
    func_0023D4E0(base + 0x301C, D_00272990, 0x81);
    func_0023D4E0(base + 0x3020, D_00272990, 0x81);
    func_0023D4E0(base + 0x3024, D_00272990, 0x81);
    func_0023D4E0(base + 0x3028, D_00272990, 0x81);
    func_0023D4E0(base + 0x318C, D_002BD440, 0x83);
    func_0023D4E0(base + 0x3226, D_0028DE58, 0x80);
    func_0023D4E0(base + 0x324A, D_0028DE58, 0x80);
    for (n = 0; n < 0x5A; n += 10) {
        func_0023D4E0(&((u8 (*)[10])(base + 0x32B6))[0][n], D_002B4D50_as_u16_a, 0x82);
        func_0023D4E0(&((u8 (*)[10])(base + 0x3310))[0][n], D_002B4D50_as_u16_a, 0x82);
    }
}
