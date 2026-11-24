#include "common.h"

#pragma divbyzerocheck on

extern u8 D_0029CA1C[];
extern u8 D_0029CA20[];
extern u8 D_0029CA24[];
extern u8 D_0029CA28[];
extern u8 D_0029CA2C[];
extern u8 D_0029CA30[];

void func_0018CE60(s32 arg0) {
    s32 off;
    s32 *p;
    s32 *q;
    s32 n;
    s32 v;

    off = arg0 * 0x28;
    p = (s32 *)(D_0029CA1C + off);
    *(s32 *)(D_0029CA20 + off) = *p;
    if (*p == 0) {
        *(s32 *)(D_0029CA24 + off) = 0;
    } else {
        *(s32 *)(D_0029CA24 + off) = 0;
    }
    *(q = (s32 *)(D_0029CA30 + off)) = 0x1E;
    n = *p;
    if (n == 0) {
        n = 1;
    }
    v = n * 100;
    *(s32 *)(D_0029CA28 + off) = v;
    *(s32 *)(D_0029CA2C + off) = v / *q;
}
