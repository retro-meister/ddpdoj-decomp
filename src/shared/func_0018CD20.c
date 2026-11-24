#include "common.h"

#pragma divbyzerocheck on

extern s32 func_0018C600(s32, s32, s32);
extern u8 D_0029CA10[];
extern u8 D_0029CA14[];
extern u8 D_0029CA18[];
extern u8 D_0029CA1C[];
extern u8 D_0029CA20[];
extern u8 D_0029CA24[];
extern u8 D_0029CA28[];
extern u8 D_0029CA2C[];
extern u8 D_0029CA30[];

void func_0018CD20(s32 arg0) {
    s32 off;
    s32 *p;
    s32 *q;
    s32 *r;
    s32 n;
    s32 v;

    off = arg0 * 0x28;
    if (*(s32 *)(D_0029CA10 + off) == 1) return;
    if (*(s32 *)(D_0029CA14 + off) == 1) return;
    v = func_0018C600(arg0 | 0x80B0, 0, 0) & ~0xFFF;
    if (!(v & 0x1000)) return;
    p = (s32 *)(D_0029CA1C + off);
    *(s32 *)(D_0029CA20 + off) = *p;
    *(s32 *)(D_0029CA24 + off) = 0;
    *(q = (s32 *)(D_0029CA30 + off)) = 0x78;
    n = *p;
    if (n == 0) {
        n = 1;
    }
    v = n * 100;
    *(s32 *)(D_0029CA28 + off) = v;
    *(s32 *)(D_0029CA2C + off) = v / *q;
    r = (s32 *)(D_0029CA18 + off);
    if (*r != 4) {
        *r = 2;
    }
}
