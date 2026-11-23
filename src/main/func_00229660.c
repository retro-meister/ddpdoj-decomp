#include "common.h"

extern void func_0021C100(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern void func_00224BA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 flags);
extern void func_00227440(u8 *state);
extern void func_00229950(s32 x, s32 y, s32 alpha, s32 bright, s32 kind);
extern s32 strlen(u8 *s);
extern u8 *D_002709D0[];
extern u8 **D_00271290[];
extern s8 D_002712D8[];
extern s8 D_00271502[];
extern u8 *D_0028DCC8;
extern u8 *D_0028DCCC;
extern u8 D_0028EC00;
extern s8 D_0028EC02;
extern s16 D_0028EC04;
extern u8 D_00685010[];
extern s16 D_0068DEF0[];
extern s16 D_0068DEFA[];
extern s16 D_0068DF04[];
extern u8 *reg_a0;

void func_00229660(void) {
    s32 x;
    s32 y;
    s32 z;
    s32 bright;
    s32 i;
    s32 count;
    s32 flag;
    s32 alpha;
    s8 index;
    u8 *item;

    count = D_00271502[0];
    func_00227440(&D_0028EC00);
    if (D_0028EC04 == 0) {
        return;
    }
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x3F34) == 0) {
            continue;
        }
        *(s32 *)(item + 0x3F2C) = alpha = D_0028EC04;
        x = *(s32 *)(item + 0x3F00);
        y = *(s32 *)(item + 0x3F04);
        z = *(s32 *)(item + 0x3F30);
        bright = 0x80;
        if (D_0068DEFA[0] == 0 && i == 7) {
            bright = 0x40;
        }
        reg_a0 = D_002709D0[i];
        func_0021C100(x, y, z, 0, bright, alpha, 1);
        y += strlen(reg_a0) * 8;
        reg_a0 = 0;
        index = D_002712D8[i];
        if (index == -1) {
            continue;
        }
        if (i == 3) {
            reg_a0 = (u8 *)D_0028DCC8;
        } else if (i == 9 || i == 7) {
            reg_a0 = (u8 *)D_0028DCCC;
        } else {
            reg_a0 = D_00271290[index][D_0068DEF0[index]];
        }
        if (reg_a0 == 0) {
            continue;
        }
        flag = 1;
        if (i == 3) {
            if (D_0068DF04[0] == 1) {
                func_00229950(x, y, D_0028EC04, bright, 2);
            } else {
                func_0021C100(x, y, z, 0, bright, D_0028EC04, flag);
                flag = 0;
            }
        } else if (i == 9) {
            func_00229950(x, y, D_0028EC04, bright, 8);
        } else if (i == 7) {
            func_00229950(x, y, D_0028EC04, bright, 6);
        } else {
            func_0021C100(x, y, z, 0, bright, D_0028EC04, flag);
        }
        if (i == D_0028EC02 && flag != 0) {
            func_00224BA0(x, y, z, 0, bright, D_0028EC04, 1, 3);
        }
    }
}
