#include "common.h"

extern void func_0021C100(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern void func_00224BA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 flags);
extern void func_00227440(u8 *state);
extern s32 strlen(u8 *s);
extern u8 *D_002708D0[];
extern u8 **D_002709B0[];
extern s8 D_00271501[];
extern s8 D_0028DCB0[8];
extern u8 D_0028EC08;
extern s8 D_0028EC0A;
extern s16 D_0028EC0C;
extern u8 D_00685010[];
extern s16 D_0068DED8[];
extern u8 *reg_a0;

void func_00228BC0(void) {
    s32 dbl;
    s32 x;
    s32 y;
    s32 z;
    s32 i;
    s32 count;
    s32 value;
    s32 alpha;
    u8 **entries;
    s8 index;
    u8 *item;

    count = D_00271501[0];
    func_00227440(&D_0028EC08);
    if (D_0028EC0C == 0) {
        return;
    }
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x3BB4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x3BAC) = alpha = D_0028EC0C;
        x = *(s32 *)(item + 0x3B80);
        y = *(s32 *)(item + 0x3B84);
        z = *(s32 *)(item + 0x3BB0);
        reg_a0 = D_002708D0[i];
        func_0021C100(x, y, z, 0, 0x80, alpha, 1);
        y += strlen(reg_a0) * 8;
        reg_a0 = 0;
        index = D_0028DCB0[i];
        if (index == -1) {
            continue;
        }
        entries = D_002709B0[index];
        value = D_0068DED8[index];
        reg_a0 = entries[value];
        if (reg_a0 == 0) {
            continue;
        }
        if (index == 4) {
            dbl = value * 2;
            reg_a0 = entries[dbl];
            if (dbl == 6) {
                func_0021C100(x, y, z, 0, 0x80, D_0028EC0C, 1);
            } else {
                func_0021C100(x, y, z, 0, 0x80, D_0028EC0C, 0);
                reg_a0 = D_002709B0[index][dbl + 1];
                func_0021C100(x - 8, y, z, 0, 0x80, D_0028EC0C, 0);
            }
        } else {
            func_0021C100(x, y, z, 0, 0x80, D_0028EC0C, 1);
        }
        if (i == D_0028EC0A) {
            func_00224BA0(x, y, z, 0, 0x80, D_0028EC0C, 1, 3);
        }
    }
}
