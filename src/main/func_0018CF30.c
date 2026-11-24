#include "common.h"

#pragma divbyzerocheck on

extern u8 D_0029CA18[];
extern u8 D_0029CA1C[];
extern u8 D_0029CA20[];
extern u8 D_0029CA24[];
extern u8 D_0029CA28[];
extern u8 D_0029CA2C[];
extern u8 D_0029CA30[];

void func_0018CF30(s32 arg0) {
    s32 off;
    s32 d;
    s32 *q;
    s32 base;

    off = arg0 * 0x28;
    *(s32 *)(D_0029CA24 + off) = *(s32 *)(D_0029CA20 + off);
    *(q = (s32 *)(D_0029CA30 + off)) = 0x1E;
    base = *(s32 *)(D_0029CA1C + off);
    d = *(s32 *)(D_0029CA24 + off) - base;
    if (d < 0) {
        d = -d;
    }
    if (d == 0) {
        d = 1;
    }
    *(s32 *)(D_0029CA28 + off) = base * 100;
    *(s32 *)(D_0029CA2C + off) = d * 100 / *q;
    *(s32 *)(D_0029CA18 + off) = 3;
}
