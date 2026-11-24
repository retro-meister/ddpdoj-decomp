#include "common.h"

extern s32 func_0018C600(s32, s32, s32);
extern void func_0018CCA0(s32);
s32 printf();
extern u8 D_00277FB0[];
extern u8 D_00277FC8[];
extern s8 D_0028DF94;
extern u8 D_0029CA10[];
extern u8 D_0029CA18[];

void func_0018E0B0(void) {
    s32 i;
    s32 off;
    u8 *p;
    s32 *f;
    s32 *c;
    s32 *tg;
    s32 t;
    s32 v;
    s32 hi;

    off = 0;
    i = 0;
    do {
        p = D_0029CA10 + off;
        f = (s32 *)(p + 8);
        if (*f != 0) {
            *(s32 *)(p + 0x20) -= 1;
            if (*(s32 *)(p + 0x20) <= 0) {
                *(s32 *)(p + 0xC) = *(s32 *)(p + 0x14);
                printf(D_00277FB0, *(s32 *)(p + 0xC));
                t = *f;
                if (t == 3) {
                    D_0028DF94 = 0;
                }
                if (t == 2) {
                    func_0018CCA0(i);
                    *(s32 *)(D_0029CA18 + i * 0x28) = 0;
                    printf(D_00277FC8);
                    return;
                }
                if (t == 4) {
                    func_0018C600(i | 0x60, 0, 0);
                    *(s32 *)(D_0029CA18 + i * 0x28) = 0;
                    return;
                }
                *f = 0;
            }
            c = (s32 *)(p + 0xC);
            tg = (s32 *)(p + 0x14);
            if (*c != *tg) {
                if (*c < *tg) {
                    *(s32 *)(p + 0x18) += *(s32 *)(p + 0x1C);
                    *c = *(s32 *)(p + 0x18) / 100;
                    if (*tg < *c) {
                        *c = *tg;
                    }
                } else {
                    *(s32 *)(p + 0x18) -= *(s32 *)(p + 0x1C);
                    *c = *(s32 *)(p + 0x18) / 100;
                    if (*c < *tg) {
                        *c = *tg;
                    }
                }
            }
            v = *c;
            if (v != 0) {
                v = v * 0x7FFF / 100;
            }
            hi = v << 16;
            hi |= v;
            func_0018C600(i | 0x80, hi, 0);
        }
        i += 1;
        off += 0x28;
    } while (i < 2);
}
