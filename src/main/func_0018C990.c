#include "common.h"

extern s32 func_0018C600(s32, s32, s32);
extern void func_0018CE60(s32);
s32 printf();
extern u8 D_00277F78[];
extern u8 D_0029CA10[];

void func_0018C990(void) {
    s32 v[2];
    s32 i;
    s32 o4;
    s32 o28;
    u8 *p;
    s32 *f;
    s32 t;

    v[0] = func_0018C600(0x80B0, 0, 0) & ~0xFFF;
    v[1] = func_0018C600(0x80B1, 0, 0) & ~0xFFF;
    func_0018C600(0x520, 0, 0);
    i = 0;
    o4 = 0;
    o28 = 0;
    do {
        if (*(s32 *)((u8 *)v + o4) & 0x1000) {
            printf(D_00277F78);
            p = D_0029CA10 + o28;
            f = (s32 *)(p + 8);
            t = *f;
            if (t == 2) {
                func_0018C600(i | 0x60, 0, 0);
                *(s32 *)(p + 4) = 1;
                *f = 0;
                *(s32 *)(p + 0x24) = 0;
            } else {
                if (t == 3) {
                    *(s32 *)(p + 0xC) = *(s32 *)(p + 0x14);
                }
                *f = 4;
                *(s32 *)(p + 0x24) = 1;
                func_0018CE60(i);
            }
        }
        i += 1;
        o4 += 4;
        o28 += 0x28;
    } while (i < 2);
}
