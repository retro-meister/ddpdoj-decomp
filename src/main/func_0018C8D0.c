#include "common.h"

extern s32 func_0018C600(s32, s32, s32);
extern u8 D_0029CA10[];
extern u8 D_0029CA14[];
extern u8 D_0029CA18[];

void func_0018C8D0(s32 arg0) {
    s32 off;
    s32 *p1;
    s32 *p2;

    off = arg0 * 0x28;
    p1 = (s32 *)(D_0029CA10 + off);
    if (*p1 == 0) {
        p2 = (s32 *)(D_0029CA14 + off);
        if (*p2 == 0) {
            func_0018C600(arg0 | 0x110, 0, 0);
        }
        func_0018C600(arg0 | 0x30, 0, 0);
        func_0018C600(arg0 | 0x10, 0, 0);
        *p1 = 1;
        *p2 = 1;
        *(s32 *)(D_0029CA18 + off) = 0;
    }
}
