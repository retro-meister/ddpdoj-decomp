#include "common.h"

extern s32 func_0018C600(s32, s32, s32);
extern void func_0018CF30(s32);
s32 printf();
extern u8 D_00277F88[];
extern u8 D_0029CA10[];

void func_0018CAD0(void) {
    s32 i;
    s32 off;
    s32 *f;
    u8 *p;

    off = 0;
    i = 0;
    do {
        p = D_0029CA10 + off;
        f = (s32 *)(p + 0x24);
        if (*f != 0) {
            printf(D_00277F88);
            *f = 0;
            f = (s32 *)(p + 8);
            if (*f == 4) {
                *f = 3;
                func_0018CF30(i);
            } else {
                func_0018C600(i | 0xE0, 0, 0);
                func_0018C600(i | 0x50, 0, 0);
                *(s32 *)(p + 4) = 0;
                *f = 3;
                func_0018CF30(i);
            }
        }
        i += 1;
        off += 0x28;
    } while (i < 2);
}
