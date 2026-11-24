#include "common.h"

extern s32 func_0018C600(s32, s32, s32);
extern u8 D_0029CA10[];
extern s32 D_0029CA14[];
extern s32 D_0029CA18[];
extern s32 D_0029CA3C[];
extern s32 D_0029CA40[];

void func_0018CBB0(void) {
    s32 v[2];
    s32 i;

    v[0] = func_0018C600(0x80B0, 0, 0) & ~0xFFF;
    v[1] = func_0018C600(0x80B1, 0, 0) & ~0xFFF;
    func_0018C600(0x520, 0, 0);
    for (i = 0; i < 2; i++) {
        if (v[i] & 0x1000) {
            func_0018C600(i | 0x60, 0, 0);
            *(s32 *)(D_0029CA10 + i * 0x28 + 4) = 1;
            *(s32 *)(D_0029CA10 + i * 0x28 + 8) = 0;
        }
    }
    D_0029CA18[0] = 0;
    D_0029CA14[0] = 1;
    D_0029CA3C[0] = 1;
    D_0029CA40[0] = 0;
}
